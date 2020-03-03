#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "lin.h"

#define MOTOR_SELECTION_INCREASE 1
#define MOTOR_SELECTION_DECREASE 2
#define MOTOR_SELECTION_STOP   3

/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0, Temp_counter =0;
l_u8 Motor1_temp;
l_u8 Motor1_Selection;

void Timer1_channel3_Init(void){
    /*Configure the timer*/
    TIM1TIOS_IOS3 = 1;      /* Enable Channel 3 as Output Compare */
    TIM1TIE_C3I = 1;        /* Enable Channel 3 interrupt */
    TIM1TC3 = 20000;        /* Set counter as 2.5ms timing */
}

void PLL_init_8M() {
    CPMUCLKS_PLLSEL = 1;                //FBUS = FPLL/2.   FBUS = 8MHz,
    CPMUREFDIV_REFFRQ = 1;              //Reference clock between 2MHZ and 6MHZ.
    CPMUREFDIV_REFDIV = 0x1;            //FREF=4/(1+1) = 2MHZ
    CPMUSYNR_VCOFRQ = 0x1;              //FVCO is between 48MHZ and 80MHZ
    CPMUSYNR_SYNDIV = 0x3;              //FVCO = 2xFREFx(SYNDIV+1)   =   FVCO = 2x2x(3+1) = 16MHZ
    CPMUPOSTDIV_POSTDIV = 0x0;          //FPLL = FVCO/(POSTDIV+1).  FPLL = 40MHZ/(0+1)    FPLL = 16MHz
    CPMUOSC_OSCE = 1;                   //External oscillator enable. 4MHZ.        FREF=FOSC/(REFDIV+1)
    while(!CPMUIFLG_LOCK){}             // Wait for LOCK.
    CPMUIFLG = 0xFF;                    // clear CMPMU int flags - not needed but good practice
}

//inits GPIO
void GPIO_init() {
    DDRP = 0xFF;            /* LEDs as outputs */
    PTP_PTP6 = 1;
    PTP_PTP5 = 1;
    PTP_PTP4 = 1;
    PTP_PTP0 = 1;
}


void main(void) {
    l_u16 i;
  EnableInterrupts;
  PLL_init_8M();        /* Enable BUS clock to 8Mhz */
  GPIO_init();          /* Initialize LEDs */
  l_sys_init();         /* LIN system initilization */
  l_ifc_init(LI0);      /* LIN interface initilization */
  Timer1_channel3_Init();   /* Initialize timer channel 3 for temperature change */
  for(;;) {
      /* Application is here... */
      /* Check if temp signal is updated */
      if (l_flg_tst_LI0_Motor1Selection_flag()){
         /* Clear this flag... */
         l_flg_clr_LI0_Motor1Selection_flag();
         /* Store selection data */
         Motor1_Selection = l_u8_rd_LI0_Motor1Selection();
         /* The application will change Motor selection in case
         the temperature is greater than maximum value to release motor power
         This will be transfered by sporadic frame type in LIN bus */
         l_u8_wr_LI0_Motor1Temp(Motor1_temp);
         /* Check if power off motor due to high temperature */
         if (Motor1_Selection == MOTOR_SELECTION_STOP) {
         /*---------- add code here to stop motor ------------*/
         Motor1_temp = 25; /* Ambiance temperature */
         }
       }
              /* Specify whether Driver is sleep */
  } /* loop forever */
  /* please make sure that you never leave main */

}
/* Interrupt routine for LIN application for every 2.5ms */
interrupt VectorNumber_Vtim1ch3 void TIMER1_CHANNEL3_ISR() {
    if (LIN_counter>=2){
            /* Reset counter */
            LIN_counter = 0;
            Temp_counter++;
            if (10000<Temp_counter) {
                Temp_counter = 0;
            }
          }
          if (LED_counter>=100){
              if (Motor1_Selection == MOTOR_SELECTION_INCREASE){
                  Motor1_temp++;
                  PTP_PTP6 = 0;
                  PTP_PTP5 = 1;
              } else if (Motor1_Selection == MOTOR_SELECTION_DECREASE){
                Motor1_temp--;
                PTP_PTP6 = 1;
                PTP_PTP5 = 0;
              }
              /* Reset counter */
             LED_counter = 0;
          }
         LIN_counter++;
         LED_counter++;
    /* Clear Timer 1 channel 3 interrupt flag*/
    TIM1TFLG1 = TIM1TFLG1_C3F_MASK;
    TIM1TC3   = (TIM1TC3 + 20000) & 0xFFFF;
}   /*TIM1 chan3*/
