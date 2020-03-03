#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "lin.h"

#define MOTOR_SELECTION_INCREASE 1
#define MOTOR_SELECTION_DECREASE 2
#define MOTOR_SELECTION_STOP   3

#define SW1 PTP_PTP1

#define LED1_ENABLE		(DDRT_DDRT0 = 1)  			/*Enable PT0*/
#define LED1_DISABLE	(DDRT_DDRT0 = 0) 			/*Disable PT0*/
#define LED1_ON			(PTT_PTT0 = 1)      		/*Set PT0*/
#define LED1_OFF		(PTT_PTT0 = 0)     			/*Clear PT0*/
#define LED1_TOGGLE     (PTT_PTT0 = ~ PTT_PTT0)		/*Toggle PT0*/

/* Global variables */
l_u8 Motor1_temp = 30;
l_u8 Motor1_Selection;

void Init_CPMU()
{
	/* Procedure proposed by to setup PLL and Oscillator */
	/* example for OSC = 4 MHz and Bus Clock = 25MHz, That is VCOCLK = 50MHz */
	/* Initialize */
	/* PLL Clock = 50 MHz, divide by one */
	CPMUPOSTDIV = 0x00;
	/* Generally: Whenever changing PLL reference clock (REFCLK) frequency to a higher value */
	/* it is recommended to write CPMUSYNR = 0x00 in order to stay within specified */
	/* maximum frequency of the MCU */
	CPMUSYNR = 0x00;
	/* configure PLL reference clock (REFCLK) for usage with Oscillator */
	/* OSC=8MHz divide by 8 / (7+1) = 1MHz, REFCLK range 1MHz to 2 MHz (REFFRQ[1:0] = 00) */
	CPMUREFDIV = 0x07;
	/* enable external Oscillator, switch PLL reference clock (REFCLK) to OSC */
	CPMUOSC = 0x80;
	/* multiply REFCLK = 1MHz by 2*(24+1)*1MHz = 50MHz */
	/* VCO range 48 to 80 MHz (VCOFRQ[1:0] = 01) */
	CPMUSYNR = 0x58;
	/* clear all flags, especially LOCKIF and OSCIF */
	CPMUIFLG = 0xFF;
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
	LED1_ENABLE;  /* Enable LED1 */
	LED1_OFF;	  /* Turn-off LED1 */
}

void main(void)
{

  /* include your code here */
  Init_CPMU();
  GPIO_Init();

  EnableInterrupts;

  l_sys_init();
  l_ifc_init(LI0);

  for(;;)
  {
		__RESET_WATCHDOG();	/* feeds the dog */
		/* Add source code here */
		/* .... */
		/* Check if temp signal is updated */
		if (l_flg_tst_LI0_Motor1Selection_flag())
		{
			/* Clear this flag... */
			l_flg_clr_LI0_Motor1Selection_flag();
			/* Store selection data */
			Motor1_Selection = l_u8_rd_LI0_Motor1Selection();
			/* The application will change Motor selection in case
			the temperature is greater than maximum value to release motor power */
			l_u8_wr_LI0_Motor1Temp(Motor1_temp);
			/* Check if power off motor due to high temperature */
			if (Motor1_Selection == MOTOR_SELECTION_STOP)
			{
				/*---------- add code here to stop motor ------------*/

			}
			if (Motor1_Selection == MOTOR_SELECTION_INCREASE)
			{
				 Motor1_temp++;
				 LED1_ON;

			}
			if (Motor1_Selection == MOTOR_SELECTION_DECREASE)
			{
				 Motor1_temp--;
				 LED1_OFF;
			}
		}
  } /* loop forever */
  /* please make sure that you never leave main */
}
