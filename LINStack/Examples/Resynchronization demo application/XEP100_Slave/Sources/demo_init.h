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
* @file      demo_init.h
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Feb-23-2011 
*
* @brief     
*
******************************************************************************/
#ifndef _DEMO_INIT
#define _DEMO_INIT

#include "mc9s12xep100.h"     /* derivative information */

#define NUM_COLS            10

void PeriphInit(void);
void init_timer_tim7(void);
void disp_hex_value(unsigned char value);
void slave_task(void);

#endif
/**
* @}
*/