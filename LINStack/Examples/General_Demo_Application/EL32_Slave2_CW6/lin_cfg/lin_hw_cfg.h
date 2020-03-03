/******************************************************************************
* 
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2016 Freescale Semiconductor, Inc.
* Copyright 2016-2019 NXP
* ALL RIGHTS RESERVED.
* 
****************************************************************************//*!
*
* @file      lin_hw_cfg.h
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Wed Feb 27 13:21:52 ICT 2019
*
* @brief     Hardware configuration file
*
******************************************************************************/
#ifndef      _LIN_HW_CFG_H
#define      _LIN_HW_CFG_H
#include <MC9S08EL32.h>

typedef enum {
   SCI0,
   SCI1,
   SCI2,
   SCI3,
   SCI4,
   SCI5,
   GPIO,
   SLIC
} lin_hardware_name;

#define XGATE_SUPPORT 0
#define _LIN_XGATE_   0
#define _LIN_SCI_     0
#define _LIN_UART_    0
#define _LIN_SLIC_    1
#define _LIN_GPIO_    0

/* MCU bus frequency */
#define MCU_BUS_FREQ       16000000
#define TIME_BASE_PERIOD   500
#endif