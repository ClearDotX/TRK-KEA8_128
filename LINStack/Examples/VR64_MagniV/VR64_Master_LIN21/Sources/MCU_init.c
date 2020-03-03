/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2009 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup demo_application_for_diagnostic
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      MCU_init.c
*
* @author    FPT Software
*
* @version   1.0
*
* @date      June-20-2011 
* 
* @brief     MCU initialization
*
******************************************************************************/
#include "MCU_init.h"
#include "lin.h"

/**********************************************************************
* Procedure : MCU_init
* Description : Initilize MCU clock to 8Mhz
* In parameters : None
* Out parameters : None
* Return value : void */

void MCU_init(void) {
   /* Fvco = 48Mhz */	
	CPMUSYNR_SYNDIV = 0x17U; 
	CPMUSYNR_VCOFRQ = 0x01U;
   /* Fpll = 16Mhz*/	                         
	CPMUPOSTDIV_POSTDIV = 0x02U;
	/* Internal clock*/
	CPMUOSC_OSCE = 0x00U;
   /* Wait until stable clock */
 	while(!CPMUFLG_LOCK ) ;/* Wait for PLL stable */
   CPMUFLG = 0xFF;			/* clear CMPMU int flags - not needed but good practice   */ 
}

/**********************************************************************
* Procedure : TIM_channel2_init
* Description : Initilize TIM timer module for channel 2
* In parameters : None
* Out parameters : None
* Return value : void */

void TIM_channel2_init(void){
   TIOS |= TIOS_IOS2_MASK;
   CFORC |= CFORC_FOC2_MASK;
    
   TTOV |= TTOV_TOV2_MASK;
   TIE  |= TIE_C2I_MASK; 
   /* Set counter as 2.5ms timing */
   TC2   = 20000;  
}

  