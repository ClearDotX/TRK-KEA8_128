#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "MCU_init.h"
#include "lin.h"

#define MOTOR_SELECTION_INCREASE 1
#define MOTOR_SELECTION_DECREASE 2
#define MOTOR_SELECTION_STOP   3

#define OUTPUT1_HIGH    PTS_PTS2=1
#define OUTPUT1_LOW     PTS_PTS2=0
#define OUTPUT1_TOGGLE  PTS_PTS2=~PTS_PTS2

#define OUTPUT2_HIGH    PTS_PTS3=1
#define OUTPUT2_LOW     PTS_PTS3=0
#define OUTPUT2_TOGGLE  PTS_PTS3=~PTS_PTS3

/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0;
l_u8 Motor1_temp = 30;
l_u8 Motor1_Selection;

/* Enable LIN_PHY module */
void LIN_Phy(void){
    LPCR_LPE = 1;       /* Enable LIN Phy  */
    LPCR_LPPUE = 1;     /* Pull up to strong signal  */
    LPSLRM = 0x00;      /* LIN Slew Rate selection */
                        /* With the LIN baudrate selected as 19200bps,
                        the Slew Rate is set as 00 which is optimized for 19200Bit/s*/
}
/* Enable GPIO pins */
void GPIO_init()
{
  DDRS_DDRS2 = 1; /* Set pin PS2 as output */
  DDRS_DDRS3 = 1; /* Set pin PS3 as output */
  OUTPUT1_LOW;    /* Clear pin PS2 */
  OUTPUT2_LOW;    /* Clear pin PS3 */
}

void main(void) {
  l_u16 i;
	l_u8 ret,j;

  /* Enable MCU and periferals */
	MCU_init();
	/* Enable GPIO pins */
	GPIO_init();
	/* Enable LIN_PHY */
	LIN_Phy();
	/* Initialize the LIN interface */
	ret = l_sys_init();
	/* Initialize the interface */
	ret = l_ifc_init(LI0);

  /* Initialize TIM timer channel 2 for master application*/
  TIM_channel2_init();

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
         if (Motor1_Selection == MOTOR_SELECTION_INCREASE) {
         /*---------- add code here to increase motor speed ------------*/
             /* Set pin PS3 */
             OUTPUT2_HIGH;
         }
         if (Motor1_Selection == MOTOR_SELECTION_DECREASE) {
         /*---------- add code here to decrease motor speed ------------*/
             /* Clear pin PS3 */
             OUTPUT2_LOW;
         }
      }
	}
}

#pragma CODE_SEG __NEAR_SEG NON_BANKED
interrupt VectorNumber_Vtimch2 void TIM_TIMER3_ISR(void) {
  if (LED_counter>=50){
      /* Toggle output1 for every 125ms */
      /* Reset counter */
      LED_counter = 0;
      if (Motor1_Selection == MOTOR_SELECTION_INCREASE)
      {
        Motor1_temp++;
      }
      else if (Motor1_Selection == MOTOR_SELECTION_DECREASE)
      {
        Motor1_temp--;
      }
      /* Toggle pin PS2 */
      OUTPUT1_TOGGLE;
  }
  LED_counter++;
  /* Clear timer flag */
  TFLG1 = TFLG1_C2F_MASK;
  /* Reset timer counter */
  TC2   = (TC2 + 20000) &0xFFFF;
}
#pragma CODE_SEG DEFAULT /* Return to default code segment */