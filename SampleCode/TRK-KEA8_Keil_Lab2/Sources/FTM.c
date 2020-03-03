/*
 * FTM.c
 *
 *  Created on: Sep 24, 2013
 *      Author: B46911
 */

#include "FTM.h"

/**********************************************************************************************
* External objects
**********************************************************************************************/


/**********************************************************************************************
* Global variables
**********************************************************************************************/


/**********************************************************************************************
* Constants and macros
**********************************************************************************************/


/**********************************************************************************************
* Local types
**********************************************************************************************/


/**********************************************************************************************
* Local function prototypes
*********************************************************************************************/


/**********************************************************************************************
* Local variables
**********************************************************************************************/
UINT16 period[4] = {0, 0, 0, 0};
pt2FuncU8 FTM_Callback;


/**********************************************************************************************
* Local functions
**********************************************************************************************/
void FTM2_IRQHandler(void);

/**********************************************************************************************
* Global functions
**********************************************************************************************/
/***********************************************************************************************
*
* @brief    FTM_Init - Initialize the FTM counter and enable 4 interrupts (CH0 to CH3)
* @param    none
* @return   none
*
************************************************************************************************/
void FTM_Init()
{

	
	SIM->SCGC |= SIM_SCGC_FTM2_MASK; /* Enable Clock for FTM2 */
	
	
	FTM2->SC |= FTM_SC_PS(7);	/* Select Preescaler in this case 128. 20 Mhz /128 =156.25 Khz. */ 
								/* Counter increase by one every 6.4 us */
	
	/* Enable Channle 0*/
	FTM2->CONTROLS[0].CnSC |= FTM_CnSC_CHIE_MASK; /* Enable channel 0 interrupt */
	FTM2->CONTROLS[0].CnSC |= FTM_CnSC_MSA_MASK;  /* Channel as Output compare mode */
	
	/*Enable Channel 1*/
	FTM2->CONTROLS[1].CnSC |= FTM_CnSC_CHIE_MASK; /* Enable channel 1 interrupt */
	FTM2->CONTROLS[1].CnSC |= FTM_CnSC_MSA_MASK;  /* Channel as Output compare mode */
	

	/*Enable Channel 2*/
	FTM2->CONTROLS[2].CnSC |= FTM_CnSC_CHIE_MASK; /* Enable channel 2 interrupt */
	FTM2->CONTROLS[2].CnSC |= FTM_CnSC_MSA_MASK;  /* Channel as Output compare mode */

	/*Enable Channel 3*/
	FTM2->CONTROLS[3].CnSC |= FTM_CnSC_CHIE_MASK; /* Enable channel 3 interrupt */
	FTM2->CONTROLS[3].CnSC |= FTM_CnSC_MSA_MASK;  /* Channel as Output compare mode */	
	
	/*Select interrupt frequency*/
	FTM2->CONTROLS[0].CnV = FTM_CnV_VAL(period[0]) ;	 
	FTM2->CONTROLS[1].CnV = FTM_CnV_VAL(period[1]) ;	 
	FTM2->CONTROLS[2].CnV = FTM_CnV_VAL(period[2]) ;	 
	FTM2->CONTROLS[3].CnV = FTM_CnV_VAL(period[3]);  	

	FTM2->SC |= FTM_SC_CLKS(1); /*FTM2 use system clock*/		
	 
	 
	

	 
}

/***********************************************************************************************
*
* @brief    FTM_SetPeriod - Set the period of the periodic interrupt
* @param    ch - channel to configure, per - period to set
* @return   none
*
************************************************************************************************/
void FTM_SetPeriod(UINT8 ch, UINT16 per)
{
	period[ch] = per;
	
	FTM2->CONTROLS[0].CnV = FTM_CnV_VAL(period[0]) ;
	FTM2->CONTROLS[1].CnV = FTM_CnV_VAL(period[1]) ;	
	FTM2->CONTROLS[2].CnV = FTM_CnV_VAL(period[2]) ;
	FTM2->CONTROLS[3].CnV = FTM_CnV_VAL(period[3]);
	
}

/***********************************************************************************************
*
* @brief    FTM_SetCallback - Set the callback function to call on successful matches from any channel 
* @param    pointer to function with an UINT8 argument
* @return   none
*
************************************************************************************************/  

void FTM_SetCallback(pt2FuncU8 ptr)
{
	FTM_Callback = ptr;	
}



/***********************************************************************************************
*
* @brief    FTM2_IRQHandler - Interrupt for FTM channels, clear flag, set new tiemout and execute callback 
* @param    none
* @return   none
*
************************************************************************************************/
void FTM2_IRQHandler()
{
	
	
	if (1==((FTM2->CONTROLS[0].CnSC & FTM_CnSC_CHF_MASK)>>FTM_CnSC_CHF_SHIFT) )  /* If the CHF of the channel is equal to 0 */
	{
		(void)FTM2->CONTROLS[0].CnSC;  							/* Read to clear flag */
		FTM2->CONTROLS[0].CnSC ^= FTM_CnSC_CHF_MASK;  			/* Clear flag */
		FTM2->CONTROLS[0].CnV = FTM2->CONTROLS[0].CnV + FTM_CnV_VAL(period[0]) ; /* Refresh interrupt period */
		FTM_Callback(0);
	}
	
	
	if (1==((FTM2->CONTROLS[1].CnSC & FTM_CnSC_CHF_MASK)>>FTM_CnSC_CHF_SHIFT) )  /* If the CHF of the channel is equal to 1 */
	{
		(void)FTM2->CONTROLS[1].CnSC;  							/* Read to clear flag */
		FTM2->CONTROLS[1].CnSC ^= FTM_CnSC_CHF_MASK;  			/* Clear flag */
		FTM2->CONTROLS[1].CnV = FTM2->CONTROLS[1].CnV + FTM_CnV_VAL(period[1]) ; /* Refresh interrupt period */
		FTM_Callback(1);
	}


	if (1==((FTM2->CONTROLS[2].CnSC & FTM_CnSC_CHF_MASK)>>FTM_CnSC_CHF_SHIFT) )  /* If the CHF of the channel is equal to 2 */
	{
		(void)FTM2->CONTROLS[2].CnSC;  							/* Read to clear flag */
		FTM2->CONTROLS[2].CnSC ^= FTM_CnSC_CHF_MASK;  			/* Clear flag */
		FTM2->CONTROLS[2].CnV = FTM2->CONTROLS[2].CnV + FTM_CnV_VAL(period[2]) ; /* Refresh interrupt period */
		FTM_Callback(2);
	}

	if (1==((FTM2->CONTROLS[3].CnSC & FTM_CnSC_CHF_MASK)>>FTM_CnSC_CHF_SHIFT) )  /* If the CHF of the channel is equal to 3 */
	{
		(void)FTM2->CONTROLS[3].CnSC;  							/* Read to clear flag */
		FTM2->CONTROLS[3].CnSC ^= FTM_CnSC_CHF_MASK;  			/* Clear flag */
		FTM2->CONTROLS[3].CnV = FTM2->CONTROLS[3].CnV + FTM_CnV_VAL(period[3]) ; /* Refresh interrupt period */
		FTM_Callback(3);
	}

	
}
