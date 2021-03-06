#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "lin.h"

#define MOTOR_SELECTION_INCREASE  1
#define MOTOR_SELECTION_DECREASE  2
#define MOTOR_SELECTION_STOP      3

#define MOTOR1_OVER_TEMP   200
#define MOTOR1_MAX_TEMP   100
#define MOTOR1_MIN_TEMP   20

/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0;
l_u8 Motor1_temp;

void Timer0_channel3_Init(void)
{
    /*Configure the timer*/
    TIM0TIOS_IOS3 = 1;      /* Enable Channel 3 as Output Compare */
    TIM0TIE_C3I = 1;        /* Enable Channel 3 interrupt */
    TIM0TC3 = 20000;        /* Set counter as 2.5ms timing */
}

void Init_CPMU()
{
    // Wait for stable supply after power up
    while (GDUF_GLVLSF)
    {
        GDUF_GLVLSF = 1;
    }

    CPMUREFDIV_REFDIV = 0;
    CPMUREFDIV_REFFRQ = 0;
    CPMUSYNR_SYNDIV = 15;
    CPMUSYNR_VCOFRQ = 0;
    CPMUPOSTDIV_POSTDIV = 1;

    while (CPMUIFLG_LOCK == 0)
    {}

    //Clear PORF and LVRF
    CPMURFLG  = 0x60;
}
void Init_PIM(void){

    MODRR0 = (MODRR0_S0LRR_MASK && 0b000) | (MODRR0_SCI1RR_MASK);
}

/*Init LIN physical */
void Init_LIN(void){
    LP0CR_LPE = 1;      /* Enable LIN Phy  */
    LP0CR_LPPUE = 1;    /* Pull up to strong signal  */
    LP0SLRM = 0x01;     /* LIN Slew Rate selection */
                        /* With the LIN baudrate selected as 9600bps,
                           the Slew Rate is set as 01 which is optimized for 9600Bit/s*/
}

void main(void) {
  l_u16 i;
  EnableInterrupts;
  /* include your code here */
  Init_CPMU();
  Init_PIM();
  Init_LIN();
  l_sys_init();
  l_ifc_init(LI0);
  l_sch_set(LI0, LI0_NormalTable,0);
  Timer0_channel3_Init();
  for(;;) {
    __RESET_WATCHDOG(); /* feeds the dog */
    /* Add source code here */
    /* .... */

    if (l_flg_tst_LI0_Motor1Temp_flag()){
        /* Clear this flag... */
        l_flg_clr_LI0_Motor1Temp_flag();
        /* Store temperature data */
        Motor1_temp = l_u8_rd_LI0_Motor1Temp();
        /* The application will change Motor selection in case
           the temperature is greater than maximum value to release motor power
           This will be transfered by sporadic frame type in LIN bus */
        if (MOTOR1_OVER_TEMP<Motor1_temp) {
          /* Request stop motor by power off */
           l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_STOP);
        } else if ((MOTOR1_MAX_TEMP<Motor1_temp)&(MOTOR1_OVER_TEMP > Motor1_temp)){
          /* Request to reduce motor speed */
          l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_DECREASE);
        } else {
          /* Request to increase motor speed if user request */
          l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_INCREASE);
        }
    }

  } /* loop forever */
  /* please make sure that you never leave main */

}

/* Interrupt routine for LIN application for every 2.5ms */
interrupt VectorNumber_Vtim0ch3 void TIMER0_CHANNEL3_ISR() {
    if (LIN_counter>=2){
        /* Activate LIN frame transfer for every 5ms */
        l_sch_tick(LI0);
        /* Reset counter */
        LIN_counter = 0;
      }
      if (LED_counter>=50){
        /* Reset counter */
        LED_counter = 0;
      }
      LIN_counter++;
      LED_counter++;
    /* Clear Timer 0 Channel 3 interrupt flag*/
    TIM0TFLG1 = TIM0TFLG1_C3F_MASK;
    TIM0TC3   = (TIM0TC3 + 20000) & 0xFFFF;
}   /*TIM0 chan3*/
