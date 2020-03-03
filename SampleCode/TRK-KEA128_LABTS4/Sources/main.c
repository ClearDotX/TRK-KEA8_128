/******************************************************************************
*    LAB4 -Keyboard Interrupt (KBI) Module                                    *
*                                                                             *
*       This lab demonstrates how to use the KBI module to read button        *
*    presses without polling. It uses interrupts to detect button presses on  *
*    SW1 and SW2. Each button toggles an LED when pressed.                    *
*       Press buttons SW1 or SW2 to toggle its corresponding LED              *
******************************************************************************/


/**********************************************************************************************
* External objects
**********************************************************************************************/
#include "derivative.h" /* include peripheral declarations */
#include "CLK.h"
#include "GPIO.h"
#include "KBI.h"
/**********************************************************************************************
* Global variables
**********************************************************************************************/


/**********************************************************************************************
* Constants and macros
**********************************************************************************************/
#define LED0_TOGGLE		OUTPUT_TOGGLE(PTC,PTC0)
#define LED1_TOGGLE		OUTPUT_TOGGLE(PTC,PTC1)
#define LED2_TOGGLE		OUTPUT_TOGGLE(PTC,PTC2)
#define LED3_TOGGLE		OUTPUT_TOGGLE(PTC,PTC3)

#define LED0_OFF		OUTPUT_CLEAR(PTC,PTC0);
#define LED1_OFF		OUTPUT_CLEAR(PTC,PTC1);
#define LED2_OFF		OUTPUT_CLEAR(PTC,PTC2);
#define LED3_OFF		OUTPUT_CLEAR(PTC,PTC3);

#define LED0_ON			OUTPUT_SET(PTC,PTC0);
#define LED1_ON			OUTPUT_SET(PTC,PTC1);
#define LED2_ON			OUTPUT_SET(PTC,PTC2);
#define LED3_ON			OUTPUT_SET(PTC,PTC3);


/**********************************************************************************************
* Local types
**********************************************************************************************/


/**********************************************************************************************
* Local function prototypes
*********************************************************************************************/
void KBI_Interrupt(UINT8 ch);
void Enable_Interrupt(UINT8 vector_number);

/**********************************************************************************************
* Local variables
**********************************************************************************************/


/**********************************************************************************************
* Local functions
**********************************************************************************************/


/**********************************************************************************************
* Global functions
**********************************************************************************************/
/***********************************************************************************************
*
* @brief    GPIO_Init - Initialize the LEDs as outputs
* @param    none
* @return   none
*
************************************************************************************************/
void GPIO_Init()
{
	CONFIG_PIN_AS_GPIO(PTC,PTC0,OUTPUT); /* Configure LED 0 (PTC0) as an output */
	CONFIG_PIN_AS_GPIO(PTC,PTC1,OUTPUT); /* Configure LED 1 (PTC1) as an output */
	CONFIG_PIN_AS_GPIO(PTC,PTC2,OUTPUT); /* Configure LED 2 (PTC2) as an output */
	CONFIG_PIN_AS_GPIO(PTC,PTC3,OUTPUT); /* Configure LED 3 (PTC3) as an output */

	CONFIG_PIN_AS_GPIO(PTD,PTD0,INPUT); /* Configure SW1 (PTD0) as an input */
	CONFIG_PIN_AS_GPIO(PTD,PTD0,INPUT); /* Configure SW2 (PTD1) as an input */
	ENABLE_INPUT(PTD,PTD0);			 /* Enable input SW1*/
	ENABLE_INPUT(PTD,PTD1);			/*  Enable input SW2*/


	LED0_OFF;							/* Turn off LED0 */
	LED1_OFF;							/* Turn off LED1 */
	LED2_OFF;							/* Turn off LED2 */
	LED3_OFF;							/* Turn off LED3 */
}


/***********************************************************************************************
*
* @brief    main() - Program entry function
* @param    none
* @return   none
*
************************************************************************************************/
void main(void)
{
	int counter = 0;

	Clk_Init();						/* Configure clocks to run at 20 Mhz*/
	GPIO_Init();					/* Configure button pins as inputs and LED pins as outputs */
	KBI_Init();						/* Initialize KBI module */
	KBI_SetCallback(KBI_Interrupt);	/* Set the KBI callback function to be called on each button press */
	Enable_Interrupt(INT_KBI0); 	/* Enable KBI0 Interrupts */

	for(;;) {
	   	counter++;
	}
}

/***********************************************************************************************
*
* @brief    KBI_Interrupt(UINT8 ch). Callback function called by the KBI module on each interrupt
* @param    KBI channel
* @return   none
*
************************************************************************************************/
void KBI_Interrupt(UINT8 ch)
{
		switch(ch)
		{
		case 0:
			LED0_TOGGLE;
		break;
		case 1:
			LED1_TOGGLE;
		break;
		}
}

/***********************************************************************************************
*
* @brief    Enable_Interrupt(UINT8 vector_number). Enable interrupts from desired module.
* @param    Module interrupt number from the interrupts vector table
* @return   none
*
************************************************************************************************/
void Enable_Interrupt(UINT8 vector_number)
{

	vector_number= vector_number-16;


	/* Set the ICPR and ISER registers accordingly */
	NVIC_ICPR |= 1 << (vector_number%32);
	NVIC_ISER |= 1 << (vector_number%32);

}
