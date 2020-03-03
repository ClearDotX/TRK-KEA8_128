/******************************************************************************								
*    LAB3 - Analog-To-Digital Converter (ADC) Module                          *								
*                                                                             *								
*       This lab demonstrates how to use the ADC module to read the analog    *								
*    value of the on-board light sensor. The application reads the            *								
*    light sensor,adc channel 3, value and sets it to the LEDs in its binary  *								
*    representation.                                                          *								
*   Add or remove light to the sensor to see the LEDs change the read value.  *								
******************************************************************************/	



/**********************************************************************************************
* External objects
**********************************************************************************************/
#include "derivative.h" /* include peripheral declarations */
#include "CLK.h"
#include "GPIO.h"
#include "ADC.h"
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
	CONFIG_PIN_AS_GPIO(PTD,PTD1,INPUT); /* Configure SW2 (PTD1) as an input */
	ENABLE_INPUT(PTD,PTD0);			 /* Enable input SW1*/	
	ENABLE_INPUT(PTD,PTD1);			 /*  Enable input SW2*/
	
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


int main(void)
{
	UINT32 counter = 0;
	UINT8 adc_value = 0;
	
	Clk_Init();			    /* Configure clocks to run at 20 Mhz */
	GPIO_Init();			/* Configure button pins as inputs and LED pins as outputs */
	ADC_Init(3,EIGHT_BIT);	/* Configure ADC channel 3 in 8-bit resolution mode */
	
	for(;;) {	   
	   	counter++;
	   	
	    adc_value=ADC_Read(3); /* Read ADC value from channel 3 */
	    
	    /* Display ADC value in LED0, LED1, LED2 and LED3*/
	   	adc_value = adc_value >> 4;
	   	GPIOA_PSOR |=adc_value <<16;
	   	adc_value = (char)~adc_value ^ 0xF0;
	   	GPIOA_PCOR |= (adc_value) << 16; 
	}
}
