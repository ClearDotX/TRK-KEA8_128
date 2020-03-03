/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2009 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup Porting VR64
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
* @date      Jan-12-2010 
*
* @brief     MCU initialization for VR64
*
******************************************************************************/

#ifndef _MCU_INIT_H
#define _MCU_INIT_H

#include "derivative.h"      /* derivative-specific definitions */

#define setReg8(RegName, val)                                    (RegName = (byte)(val))
#define clrReg8Bits(RegName, ClrMask)                            (RegName &= (byte)(~(byte)(ClrMask)))
#define setReg8Bits(RegName, SetMask)                            (RegName |= (byte)(SetMask))

#define BUSCLK_FREQ_HZ		8000000L  /* "L" postfix evaluated as a long value */


void MCU_init(void);
void TIM_channel2_init(void);

#endif /* END _MCU_INIT_H */ 