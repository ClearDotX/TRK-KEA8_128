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
* @date      Wed Feb 27 13:22:05 ICT 2019
*
* @brief     Hardware configuration file
*
******************************************************************************/
#ifndef      _LIN_HW_CFG_H
#define      _LIN_HW_CFG_H
#include <MC9S12XEP100.h>

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


/* MCU type definition */
#define _S08_   0
#define _S12_   1
#define _S12X_  2
#define _K_     3

#define SCI_V2  0
#define SCI_V4  1
#define SCI_V5  2
#define SCI_V6  3

/* SCI version */
#define SCI_VERSION SCI_V5

/* Type of MCU */
#define _MCU_  _S12X_

/* Resynchronization support */
#define __RESYN_EN   0

/* Interface type that MCU uses */
#define XGATE_SUPPORT 0
#define _LIN_XGATE_   0
#define _LIN_SCI_     1
#define _LIN_UART_    0
#define _LIN_SLIC_    0
#define _LIN_GPIO_    0
/***********  SCI HARDWARE SECTION  *********/
#define NUM_OF_SCI_CHANNEL    6

/* SCI Base Register definition */
#define SCI0_ADDR  0x00C8
#define SCI1_ADDR  0x00D0
#define SCI2_ADDR  0x00B8
#define SCI3_ADDR  0x00C0
#define SCI4_ADDR  0x0130
#define SCI5_ADDR  0x0138

/* Use SCI Channel  */
#define _SCI0_   0
#define _SCI1_   1
#define _SCI2_   0
#define _SCI3_   1
#define _SCI4_   0
#define _SCI5_   1



/* MCU bus frequency */
#define MCU_BUS_FREQ       8000000

/* Default interrupt period of the timer for LIN is TIME_BASE_PERIOD micro seconds */
#define TIME_BASE_PERIOD   500

/* max idle timeout for all networks = idle_timeout_value*1000000/time_base_period */
#define _MAX_IDLE_TIMEOUT_    10000      /* idle_timeout_value = 5s */
#endif