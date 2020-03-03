#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "lin.h"

#define MOTOR_SELECTION_INCREASE  1
#define MOTOR_SELECTION_DECREASE  2
#define MOTOR_SELECTION_STOP      3

#define MOTOR1_OVER_TEMP   200
#define MOTOR1_MAX_TEMP   100
#define MOTOR1_MIN_TEMP   20

/* Note that LED2 is PWMLED2 on S12ZVMA Validation Board */
#define LED2_ENABLE     (DDRP_DDRP2 = 1)            /*Enable PP0*/
#define LED2_DISABLE    (DDRP_DDRP2 = 0)            /*Disable PP0*/
#define LED2_ON         (PTP_PTP2 = 1)              /*Set PP0*/
#define LED2_OFF        (PTP_PTP2 = 0)              /*Clear PP0*/
#define LED2_TOGGLE     (PTP_PTP2 = ~ PTP_PTP2)     /*Toggle PP0*/

/* Global variables */
l_u8 Motor1_temp = 30;
l_u8 Motor1_Selection;
l_u8 LIN_Counter = 0;

void CPMU_Init(void);
void Timer1_Channel1_Init(void);
void TIMER1_CHANNEL1_ISR(void);
void main(void) {
  LED2_ENABLE;
  CPMU_Init();
  EnableInterrupts;
  l_sys_init();
  l_ifc_init(LI0);
  l_sch_set(LI0, LI0_NormalTable,0);
  Timer1_Channel1_Init();

  for(;;) {
    if (l_flg_tst_LI0_Motor1Temp_flag())
    {
        /* Clear this flag... */
        l_flg_clr_LI0_Motor1Temp_flag();
        /* Store temperature data */
        Motor1_temp = l_u8_rd_LI0_Motor1Temp();
        /* The application will change Motor selection in case
           the temperature is greater than maximum value to release motor power */
        if (MOTOR1_OVER_TEMP<Motor1_temp)
        {
           /* Request stop motor by power off */
           l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_STOP);
        }
        else if ((MOTOR1_MAX_TEMP<Motor1_temp)&(MOTOR1_OVER_TEMP > Motor1_temp))
        {
           /* Request to reduce motor speed */
           l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_DECREASE);
           LED2_OFF;
        }
        else
        {
           /* Request to increase motor speed if user request */
           l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_INCREASE);
           LED2_ON;
        }
    }
  } /* loop forever */
  /* please make sure that you never leave main */
}


 void CPMU_Init(void)
 {
    /* Set input of PLL is 1Mhz */
    /* Choose internal clock for PLL */
    CPMUOSC_OSCE = 0;

    /* Set reference divider is 4 */
    CPMUREFDIV_REFDIV = 0x03;
    /* REFCLK Frequency in ranges of 1-2Mhz */
    CPMUREFDIV_REFFRQ = 0x00;

    /* Set output clock of PLL is 48Mhz */
    /* VCOCLK Frequency in range of 32-48Mhz */
    CPMUSYNR_VCOFRQ =   0x00;
    /* fVCO = 2 * fREF * (SYNDIV + 1) */
    CPMUSYNR_SYNDIV =  0x17;
    /* Core clock = PLL clock devide by one */
    CPMUPOSTDIV = 0x00;
    /* Wait for PLL stable */
    while(!CPMUFLG_LOCK );
    /* Clear all flag */
    CPMUFLG = 0xFF;
 }
 void Timer1_Channel1_Init(void)
 {
    /*Configure the timer*/
    /* Enable Channel 1 as Output Compare */
    TIM1TIOS_IOS1 = 1;
    /* Enable interupt of timer1 chanel 1*/
    TIM1TIE_C1I = 1;
    /* Set counter as 625us timing */
    TIM1TC1 = (MCU_BUS_FREQ/8000)*5;
 }

 #pragma CODE_SEG __NEAR_SEG NON_BANKED
 interrupt VectorNumber_Vtim1ch1 void TIMER1_CHANNEL1_ISR()
 {
    /* Clear flag */
    TIM1TFLG1_C1F = 1;
    TIM1TC1 = (TIM1TC1 + (MCU_BUS_FREQ/8000)*5) & 0xFFFF;
    if(LIN_Counter == 8)
    {
       LIN_Counter = 0;
       l_sch_tick(LI0);
    }
    LIN_Counter++;
 }
 #pragma CODE_SEG DEFAULT /* Return to default code segment */
