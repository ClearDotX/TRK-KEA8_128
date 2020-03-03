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
* @file      mcu_init.h
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Dec-24-2009 
*
* @brief     initialization function for HY64 MCU
*
******************************************************************************/

#ifndef _mcu_init
#define _mcu_init

#include "lin.h"

#define SW1						PT1AD_PT1AD4
#define SW2						PT1AD_PT1AD5

#define LED1					PTR_PTR0
#define LED2					PTR_PTR1
#define LED3					PTR_PTR2
#define LED4					PTR_PTR3

#define ON            0x01
#define OFF           0x00

#define ALL_FULL_DRIVE		0x00   
#define ALL_REDUCED_DRIVE	0xFF
#define ALL_PULLS_OFF		  0x00
#define ALL_PULLS_ON			0xFF
#define ALL_PULLED_UP		  0x00   
#define ALL_PULLED_DOWN		0xFF
#define ALL_INPUTS			  0x00
#define ALL_OUTPUTS			  0xFF	
#define ALL_LOW				    0x00
#define ALL_HIGH				  0xFF

typedef unsigned char   tU08;   /**< unsigned 8 bit definition */

/**
* @var typedef unsigned char tU16
* unsigned 16 bits definition
*/
typedef unsigned short    tU16;   /**< unsigned 16 bit definition */

void port_config(void);
void clk_init(void);
void kbi_isr_func(void);
void TIM1_init(void);
void state_machine(void);
void byte_disp(l_u8 order, l_u8 data);
void dec_disp(l_u8 order, l_u16 data);
void HEX_disp(l_u8 order, l_u8 data);
void delay(unsigned int ms);

#endif
/**
* @}
*/