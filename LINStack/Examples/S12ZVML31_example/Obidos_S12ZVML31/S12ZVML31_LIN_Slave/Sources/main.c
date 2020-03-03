#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "lin.h"


#define MOTOR_SELECTION_INCREASE 1
#define MOTOR_SELECTION_DECREASE 2
#define MOTOR_SELECTION_STOP   3

#define LED1_ENABLE     (DDRS_DDRS4 = 1)            /*Enable PS4*/
#define LED1_DISABLE    (DDRS_DDRS4 = 0)            /*Disable PS4*/
#define LED1_ON         (PTS_PTS4 = 1)              /*Set PS4*/
#define LED1_OFF        (PTS_PTS4 = 0)              /*Clear PS4*/
#define LED1_TOGGLE     (PTS_PTS4 = ~ PTS_PTS4)     /*Toggle PS4*/

#define LED2_ENABLE     (DDRS_DDRS5 = 1)            /*Enable PS5*/
#define LED2_DISABLE    (DDRS_DDRS5 = 0)            /*Disable PS5*/
#define LED2_ON         (PTS_PTS5 = 1)              /*Set PS5*/
#define LED2_OFF        (PTS_PTS5 = 0)              /*Clear PS5*/
#define LED2_TOGGLE     (PTS_PTS5 = ~ PTS_PTS5)     /*Toggle PS5*/

/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0;
l_u8 Motor1_temp = 30;
l_u8 Motor1_Selection;

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

    MODRR0 = (MODRR0_S0L0RR_MASK && 0b000) | (MODRR0_SCI1RR_MASK);
}

/*Init LIN physical */
void Init_LIN(void){
    LP0CR_LPE = 1;       // Enable LIN Phy
    LP0CR_LPPUE = 1;     // Pull up to strong signal
    LP0SLRM = 0x01;
}
/***********************************************************************************************
*
* @brief    GPIO_Init - Initialize the pins for input/output
* @param    none
* @return   none
*
************************************************************************************************/
void GPIO_Init()
{
    LED1_ENABLE; /* Enable LED1 */
    LED2_ENABLE; /* Enable LED2 */
    LED1_OFF;   /* Turn-off LED1 */
    LED2_OFF;   /* Turn-off LED2 */
}



void Timer0_channel1_Init(void){
    /*Configure the timer*/
    TIM0TIOS_IOS1 = 1;      /* Enable Channel 3 as Output Compare */
    TIM0TIE_C1I = 1;        /* Enable Channel 3 interrupt */
    TIM0TC1 = 20000;        /* Set counter as 2.5ms timing */
}



void main(void) {
    int count=0;
    int i=0;
  EnableInterrupts;
  /* include your code here */
  Init_CPMU();
  Init_PIM();
  GPIO_Init();
  Init_LIN();
  l_sys_init();
  l_ifc_init(LI0);
  Timer0_channel1_Init();
    for(;;) {
    __RESET_WATCHDOG(); /* feeds the dog */
    /* Add source code here */
    /* .... */
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

     }

     if (Motor1_Selection == MOTOR_SELECTION_INCREASE) {
          /*---------- add code here to stop motor ------------*/
         /* Turn-on LED2 */
         LED2_ON;
     }
     if (Motor1_Selection == MOTOR_SELECTION_DECREASE) {
          /*---------- add code here to stop motor ------------*/
         /* Turn-off LED2 */
         LED2_OFF;
     }


  }

  } /* loop forever */
  /* please make sure that you never leave main */

}


/* Interrupt routine for LIN application for every 2.5ms */

interrupt VectorNumber_Vtim0ch1 void TIMER0_CHANNEL1_ISR() {
      if (LED_counter>=50){
          /* Toggle LED1 for every 125ms */
        LED1_TOGGLE;
        /* Reset LED counter */
        LED_counter = 0;
        if (Motor1_Selection == MOTOR_SELECTION_INCREASE){
            /* Increase Motor1 temperature by one */
            Motor1_temp++;
        }
        else if (Motor1_Selection == MOTOR_SELECTION_DECREASE){
            /* Decrease Motor1 temperature by one */
            Motor1_temp--;
        }
      }
      LED_counter++;
    /* Clear timer 0 channel 1 interrupt flag */
    TIM0TFLG1 = TIM0TFLG1_C1F_MASK;
    TIM0TC1   = (TIM0TC1 + 20000) & 0xFFFF;
}

