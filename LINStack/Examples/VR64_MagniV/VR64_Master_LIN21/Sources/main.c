#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "MCU_init.h"
#include "lin.h"

#define MOTOR_SELECTION_INCREASE  1
#define MOTOR_SELECTION_DECREASE  2
#define MOTOR_SELECTION_STOP      3

#define MOTOR1_OVER_TEMP   200
#define MOTOR1_MAX_TEMP   100
#define MOTOR1_MIN_TEMP   20

/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0;
l_u8 Motor1_temp =0, ret;

/* Enable LIN_PHY module */
void LIN_Phy(void){
    LPCR_LPE = 1;       /* Enable LIN Phy  */
    LPCR_LPPUE = 1;     /* Pull up to strong signal  */
    LPSLRM = 0x01;      /* LIN Slew Rate selection */
                        /* With the LIN baudrate selected as 9600bps,
                        the Slew Rate is set as 01 which is optimized for 9600Bit/s*/
}

void main(void) {
  l_u16 i;
	l_u8 j;

  /* Enable MCU and periferals */
	MCU_init();
	/* Enable LIN_PHY */
	LIN_Phy();
	/* Initialize the LIN interface */
	ret = l_sys_init();
	/* Initialize the interface */
	ret = l_ifc_init(LI0);
	/* Set active schedule table,  */
	l_sch_set(LI0,LI0_NormalTable, 0);

  /* Initialize TIM timer channel 2 for master application*/
  TIM_channel2_init();

  DDRT_DDRT0 = 1; /* Set port PT0 as output */

	EnableInterrupts;

	for(;;) {
	    if (l_flg_tst_LI0_Motor1Temp_flag()){
        /* Clear this flag... */
        l_flg_clr_LI0_Motor1Temp_flag();
        /* Store temperature data */
        Motor1_temp = l_u8_rd_LI0_Motor1Temp();
        /* The application will change Motor selection in case
           the temperature is greater than maximum value to release motor power */
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
   }
}

#pragma CODE_SEG __NEAR_SEG NON_BANKED
interrupt VectorNumber_Vtimch2 void TIM_TIMER2_ISR(void) {

  if (LIN_counter>=2){
    /* Activate LIN frame transfer for every 5ms */
   ret = l_sch_tick(LI0);
    /* Reset counter */
    LIN_counter = 0;
  }
  if (LED_counter>=50){
    PTT_PTT0 =~ PTT_PTT0;
    /* Reset counter */
    LED_counter = 0;
  }
  LIN_counter++;
  LED_counter++;
  /* Clear timer flag */
  TFLG1 = TFLG1_C2F_MASK;
  /* Reset timer counter */
  TC2   = (TC2 + 20000) &0xFFFF;
}
#pragma CODE_SEG DEFAULT /* Return to default code segment */