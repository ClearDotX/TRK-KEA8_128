#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "MCU_init.h"
#include "lin.h"

#define MOTOR_SELECTION_INCREASE 1
#define MOTOR_SELECTION_DECREASE 2
#define MOTOR_SELECTION_STOP   3

/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0;
l_u8 Motor1_temp = 30;
l_u8 Motor1_Selection;

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
	l_u8 ret,j;

  /* Enable MCU and periferals */
	MCU_init();
	/* Enable LIN_PHY */
	LIN_Phy();
	/* Initialize the LIN interface */
	ret = l_sys_init();
	/* Initialize the interface */
	ret = l_ifc_init(LI0);

  /* Initialize TIM timer channel 2 for master application*/
  TIM_channel2_init();

  DDRT_DDRT0 = 1; /* Set port PT0 as output */

	EnableInterrupts;

	for(;;) {
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

      }
	}
}

#pragma CODE_SEG __NEAR_SEG NON_BANKED
interrupt VectorNumber_Vtimch2 void TIM_TIMER3_ISR(void) {
  if (LED_counter>=50){
      /* Reset counter */
      LED_counter = 0;
      if (Motor1_Selection == MOTOR_SELECTION_INCREASE){
        Motor1_temp++;
        PTT_PTT0 =~ PTT_PTT0;
      } else if (Motor1_Selection == MOTOR_SELECTION_DECREASE){
        Motor1_temp--;
    }
  }
  LED_counter++;
  /* Clear timer flag */
  TFLG1 = TFLG1_C2F_MASK;
  /* Reset timer counter */
  TC2   = (TC2 + 20000) &0xFFFF;
}
#pragma CODE_SEG DEFAULT /* Return to default code segment */