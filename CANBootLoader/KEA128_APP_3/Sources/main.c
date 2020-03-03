/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

/**********************************************************************************************
* External objects
**********************************************************************************************/
#include "derivative.h" /* include peripheral declarations */
#include "CLK.h"
#include "GPIO.h"
#include "FTM.h"
#include "typedefs.h"

/**********************************************************************************************
* Global variables
**********************************************************************************************/
  typedef unsigned char   UINT8;      /* unsigned 8 bit definition */
  typedef unsigned short  UINT16;     /* unsigned 16 bit definition */
  typedef unsigned long   UINT32;     /* unsigned 32 bit definition */
  typedef signed char     INT8;       /* signed 8 bit definition */
  typedef short           INT16;      /* signed 16 bit definition */
  typedef long int        INT32;      /* signed 32 bit definition */  
  typedef void(*pt2Func)(void);		  /* Pointer to Functions, void argument */
  typedef void(*pt2FuncU8)(UINT8);	  /* Pointer to Functions, UINT8 argument */

/**********************************************************************************************
* Constants and macros
**********************************************************************************************/
#define LED0_TOGGLE		OUTPUT_TOGGLE(PORT_C,16)
#define LED1_TOGGLE		OUTPUT_TOGGLE(PORT_C,17)
#define LED2_TOGGLE		OUTPUT_TOGGLE(PORT_C,18)
#define LED3_TOGGLE		OUTPUT_TOGGLE(PORT_C,19)

#define LED0_OFF		OUTPUT_CLEAR(PORT_C,16);
#define LED1_OFF		OUTPUT_CLEAR(PORT_C,17);
#define LED2_OFF		OUTPUT_CLEAR(PORT_C,18);
#define LED3_OFF		OUTPUT_CLEAR(PORT_C,19);

#define LED0_ON			OUTPUT_SET(PORT_C,16);
#define LED1_ON			OUTPUT_SET(PORT_C,17);
#define LED2_ON			OUTPUT_SET(PORT_C,18);
#define LED3_ON			OUTPUT_SET(PORT_C,19);


/**********************************************************************************************
* Local types
**********************************************************************************************/


/**********************************************************************************************
* Local function prototypes
*********************************************************************************************/
void FTM_Interrupt(UINT8 ch);
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
	CONFIG_PIN_AS_GPIO(PORT_C,16,OUTPUT); /* Configure LED 0 (PTC0) as an output */
	CONFIG_PIN_AS_GPIO(PORT_C,17,OUTPUT); /* Configure LED 1 (PTC1) as an output */
	CONFIG_PIN_AS_GPIO(PORT_C,18,OUTPUT); /* Configure LED 2 (PTC2) as an output */
	CONFIG_PIN_AS_GPIO(PORT_C,19,OUTPUT); /* Configure LED 3 (PTC3) as an output */
	
	CONFIG_PIN_AS_GPIO(PORT_D,24,INPUT); /* Configure BTN0 (PTD0) as an input */	
	CONFIG_PIN_AS_GPIO(PORT_D,25,INPUT); /* Configure BTN1 (PTD1) as an input */
	ENABLE_INPUT(PORT_D,24);			 /* Enable input SW1*/	
	ENABLE_INPUT(PORT_D,25);			/*  Enable input SW2*/
	
	LED0_OFF;							/* Turn off LED0 */
	LED1_OFF;							/* Turn off LED1 */
	LED2_OFF;							/* Turn off LED2 */
	LED3_OFF;							/* Turn off LED3 */

}

void Clk_Init()

{
	
	ICS_C1|=ICS_C1_IRCLKEN_MASK; 		/* Enable the internal reference clock*/ 
	ICS_C3= 0x90;						/* Reference clock frequency = 31.25 KHz*/		
	while(!(ICS_S & ICS_S_LOCK_MASK));   /* Wait for PLL lock, now running at 40 MHz (1280 * 31.25Khz) */		
    ICS_C2|=ICS_C2_BDIV(1)  ; 			/*BDIV=2, Bus clock = 20 MHz*/
	ICS_S |= ICS_S_LOCK_MASK ; 			/* Clear Loss of lock sticky bit */	
		

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
	
	Clk_Init(); 					/* Configure clocks to run at 20 Mhz */
	GPIO_Init();					/* Configure button pins as inputs and LED pins as outputs */
	
	FTM_Init();						/* Initialize the FTM module */
	FTM_SetPeriod(0, 15400);		/* Interrupt every 15400 counts,  equal to every 100 ms */					
	FTM_SetPeriod(1, 30800);		/* Interrupt every 30800 counts,  equal to every 200 ms */			
	FTM_SetPeriod(2, 46200);		/* Interrupt every 46200 counts,  equal to every 300 ms */				
	FTM_SetPeriod(3, 61600);		/* Interrupt every 61600 counts, equal to every  400 ms */ 	

	FTM_SetCallback(FTM_Interrupt); /* Set the callback function to be called */
	Enable_Interrupt(INT_FTM2);  	/* Enable FTM2 interrupt */


	for(;;) {	   
	   	counter++;
	}
	
	return 0;
}

/***********************************************************************************************
*
* @brief    FTM_Interrupt(UINT8 ch). Function callback called by the FTM module on each timer interrupt.
* @param    none
* @return   none
*
************************************************************************************************/  
void FTM_Interrupt(UINT8 ch)
{
		switch(ch)
		{
		case 0:
			LED0_TOGGLE;	
		break;
		
		case 1:
			LED1_TOGGLE;	
		break;
			
		case 2:
			LED2_TOGGLE;	
		break;
		case 3:
			LED3_TOGGLE;	
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
