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
* @file      periphral_init.h
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Dec-24-2009 
*
* @brief     
*
******************************************************************************/
#ifndef _PERIPHRAL_INIT
#define _PERIPHRAL_INIT

#include "mc9s12xep100.h"     /* derivative information */
#define NUM_COLS            10
void PeriphInit(void);
void init_timer_tim7(void);
void disp_hex_value(unsigned char value);
#endif

/**
* @}
*/
