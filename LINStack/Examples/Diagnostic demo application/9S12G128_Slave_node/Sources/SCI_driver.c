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
* @file      SCI_driver.c
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Jan-12-2011 
* 
* @brief     Demo application for classIII
*
******************************************************************************/

#include "SCI_driver.h"
#include "MCU_init.h"

extern unsigned char byte_cnt;
extern unsigned char data_arr[3];
extern unsigned char data_arr_loop_back[3];
volatile _tSCI   *pSCI = (_tSCI*)SCI1_ADDR;

void SCI_config(void) 
{
	volatile unsigned int tmp;
	/*** Set baudrate ***/
  pSCI->SCISR2.Byte = 0x00;
	tmp = BUSCLK_FREQ_HZ / SCI_BAUDRATE / 16;
/*	
	pSCI->SCIBD.Overlap_STR.SCI1BDHSTR.Bits = (unsigned char)((tmp>>8)&0x1F);
	pSCI->SCIBD.Overlap_STR.SCI1BDLSTR.Bits = (unsigned char)(tmp & 0xFF);		
*/
	pSCI->SCIBD.Word = tmp & 0x1FFF;
  /*Disable SCI in wait mode and enable bit count after stop bit & enable single wire mode */
  pSCI->SCICR1.Byte = (SCI1CR1_ILT_MASK | SCI1CR1_SCISWAI_MASK | SCI1CR1_LOOPS_MASK | SCI1CR1_RSRC_MASK );
  /* Enable use of 13bit breaks & set TxD is output */
  pSCI->SCISR2.Byte  = (SCI1SR2_AMAP_MASK | SCI1SR2_BRK13_MASK | SCI1SR2_TXDIR_MASK);  
  /*** Enable break detection circuit ***/   
  pSCI->SCIACR2.Byte |= SCI1ACR2_BKDFE_MASK;  
  /*** Enable break detection interrupt ***/   
  pSCI->SCIBD.Overlap_STR.SCI1ACR1STR.Byte |= SCI1ACR1_BKDIE_MASK;    
	/*** Enable receiver interrupt ***/
	pSCI->SCICR2.Byte = SCI1CR2_TE_MASK ; // | SCI1CR2_RIE_MASK;		
	/*** Clear SCI Status ***/
}

void SCI_send(unsigned char data)
{
	volatile unsigned char Tx_status = E_Tx_FULL;
	/* wait until transmitter idle */
	while (Tx_status == E_Tx_FULL){
			Tx_status = Get_Tx_Status();	
	}  
  pSCI->SCIDRL.Byte = data;
}

void SCI_send_break(void)
{
	volatile unsigned char Tx_status = E_Tx_FULL;
	/* wait until transmitter idle */
	while (Tx_status == E_Tx_FULL){
			Tx_status = Get_Tx_Status();	
	}  
	/*** Send break character ***/
  pSCI->SCICR2.Byte |= SCI1CR2_SBK_MASK;
	pSCI->SCICR2.Byte &= (unsigned char)(~SCI1CR2_SBK_MASK);	                                       		
}

unsigned char Get_Tx_Status(void)
{
	if (pSCI->SCISR1.Byte & SCI1SR1_TC_MASK)
	{
		  /* If transmitter's idle */ 
		  return E_Tx_EMPTY;
	}				
	/* If transmitter isn't idle*/
	return E_Tx_FULL;
}

void SCI_receiver(void)
{
  unsigned char _LED_value;
  if (pSCI->SCISR1.Byte & SCI1SR1_RDRF_MASK)
	{
		 (void)(pSCI->SCISR1.Byte == 0x00);	
		 _LED_value = pSCI->SCIDRL.Byte;
//		 PTT = (~LED_value << 4) ;
	}
}