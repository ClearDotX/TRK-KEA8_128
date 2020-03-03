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
* @file      SCI_driver.h
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Jan-12-2010 
*
* @brief     Demo application for classIII
*
******************************************************************************/

#ifndef __SCI_driver
#define __SCI_driver

#include "MCU_init.h"
#define SCI_BAUDRATE			19200
#define E_Tx_EMPTY				0x00
#define E_Tx_FULL	  			0x01

typedef struct				/*sci datastructure	*/
{
  volatile SCI1BDSTR	  SCIBD;	  /*WORD - sci baud rate register(s) */
  volatile SCI1ACR2STR	SCIACR2;	/* SCI Alternative Control Register 2 */
  volatile SCI1CR2STR   SCICR2;	  /* SCI Control Register 2 */
  volatile SCI1SR1STR   SCISR1;	  /* SCI Status Register 1	*/    
  volatile SCI1SR2STR   SCISR2;	  /* SCI Status Register 2	*/
  volatile SCI1DRHSTR   SCIDRH;	  /* SCI Data Register High */
  volatile SCI1DRLSTR 	SCIDRL;  	/* SCI Data Register Low	*/
}_tSCI;

#define SCICR1 SCIACR2		  /**< SCI alternate control register 2 */

void SCI_config(void);
void SCI_send(unsigned char data);
void SCI_send_break(void);
void SCI_receiver(void);
unsigned char Get_Tx_Status(void);

#endif
