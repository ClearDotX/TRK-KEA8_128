#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "lin.h"
#include "LCD.h"

#define MOTOR_SELECTION_INCREASE  1
#define MOTOR_SELECTION_DECREASE  2
#define MOTOR_SELECTION_STOP      3

#define MOTOR1_OVER_TEMP   200
#define MOTOR1_MAX_TEMP   100
#define MOTOR1_MIN_TEMP   20

#define SW1 PTT_PTT3
/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0;
l_u8 Motor1_temp;

void GPIO_Init (void)
{
    DDRP_DDRP0 = 1; /* Configure LED D9 */
    DDRP_DDRP1 = 1; /* Configure LED D8 */
    DDRP_DDRP2 = 1; /* Configure LED D7 */
    DDRP_DDRP3 = 1; /* Configure LED D6 */

}


void Timer0_channel3_Init(void){
    /*Configure the timer*/
    TIM0TIOS_IOS3 = 1;      /* Enable Channel 3 as Output Compare */
    TIM0TIE_C3I = 1;        /* Enable Channel 3 interrupt */
    TIM0TC3 = 20000;        /* Set counter as 2.5ms timing */
}

void Init_CPMU()
{
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

void main(void) {
    l_u8 ret;
    l_u8 j;
    l_u16 i;
    Init_CPMU();
    EnableInterrupts;

    ret = l_sys_init();
    ret = l_ifc_init(LI0);
    l_sch_set(LI0,LI0_NormalTable, 0);
    LCD_Init();             /* Configures the LCD controller for 4x40 operation */
    Timer0_channel3_Init();
    setTempMode();
    SetOdo(0);
    GPIO_Init();
    for (;;) {
        /* Application is here... */
        if (l_flg_tst_LI0_Motor1Temp_flag()){
        /* Clear this flag... */
        l_flg_clr_LI0_Motor1Temp_flag();
        /* Store temperature data */
        Motor1_temp = l_u8_rd_LI0_Motor1Temp();
        /* The application will change Motor selection in case
           the temperature is greater than maximum value to release motor power
           This will be transfered by sporadic frame type in LIN bus */
        SetOdo(Motor1_temp);
        if (MOTOR1_OVER_TEMP<Motor1_temp) {
          /* Request stop motor by power off */
           l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_STOP);
           SetG(MOTOR_SELECTION_STOP);
           PTP_PTP0 = 1;
           PTP_PTP1 = 0;
           PTP_PTP2 = 0;
        } else if ((MOTOR1_MAX_TEMP<Motor1_temp)&(MOTOR1_OVER_TEMP > Motor1_temp)){
          /* Request to reduce motor speed */
          l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_DECREASE);
          SetG(MOTOR_SELECTION_DECREASE);
          PTP_PTP0 = 0;
          PTP_PTP1 = 1;
          PTP_PTP2 = 0;
        } else {
          /* Request to increase motor speed if user request */
          l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_INCREASE);
          SetG(MOTOR_SELECTION_INCREASE);
          PTP_PTP0 = 0;
          PTP_PTP1 = 0;
          PTP_PTP2 = 1;
        }
      }
             /* Check if Motor speed signal has been changed. */
    }
}
/* Interrupt routine for LIN application for every 2.5ms */
interrupt VectorNumber_Vtim0ch3 void TIMER0_CHANNEL3_ISR() {
     if (LIN_counter>=2){
        /* Activate LIN frame transfer for every 5ms */
        l_sch_tick(LI0);
        /* Reset counter */
        PTP_PTP3 = ~PTP_PTP3;
        LIN_counter = 0;
      }
      if (LED_counter>=50){
        /* Reset counter */
        LED_counter = 0;
      }
      LIN_counter++;
      LED_counter++;
      /* Clear timer flag */
    TIM0TFLG1 = TIM0TFLG1_C3F_MASK;
    TIM0TC3   = (TIM0TC3 + 20000) & 0xFFFF;
}   /*TIM0 chan3*/
