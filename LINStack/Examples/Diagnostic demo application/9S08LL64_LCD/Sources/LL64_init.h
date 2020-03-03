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
* @file      LL64_init.c
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Jan-21-2011 
*
* @brief     Common initialization for LL64
*
******************************************************************************/
#ifndef __LL64_INIT
#define __LL64_INIT

#include <MC9S08LL64.h>
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "LCD_GD5360P.h"        

void MCU_init(void);
void SCI2_init(void);
void LED_init(void);
void cpu_init(void);

#endif