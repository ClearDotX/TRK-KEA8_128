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
* @file      MCU_init.h
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Feb-9-2011 
*
* @brief     Initialization for G128 
*
******************************************************************************/

#ifndef __MCU_INIT_H
#define __MCU_INIT_H
#include <mc9s12g128.h>


#define SW_MASK    0xF0
#define SW1_MASK   0x10
#define SW2_MASK   0x20
#define SW3_MASK   0x40
#define SW4_MASK   0x80

#define BUSCLK_FREQ_HZ		8000000L  /* "L" postfix evaluated as a long value */
#define OSCCLK_FREQ_HZ		32768L	  /* "L" postfix evaluated as a long value */

/*** SCI Base Register definition ****/
#define SCI0_ADDR 0x00C8
#define SCI1_ADDR 0x00D0
#define SCI2_ADDR 0x00E8  

void MCU_init(void);
byte update_POT_value(void);
void update_LED_value(void);
void delay(int ms);
void init_demo(void);
#endif