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
* @date      Fri May 24 16:43:48 ICT 2019
*
* @brief     Hardware configuration file
*
******************************************************************************/
#ifndef      _LIN_HW_CFG_H
#define      _LIN_HW_CFG_H
#include <SKEAZN84.h>

typedef enum {
   LINUART0,
   LINUART1,
   LINUART2
} lin_hardware_name;


/* Type of MCU */
#define _MCU_  _K_

/* Resynchronization support */
#define __RESYN_EN   0

/* Autobaud support */
#define AUTOBAUD     1

/* Interface type that MCU uses */
#define XGATE_SUPPORT 0
#define _LIN_XGATE_   0
#define _LIN_SCI_     0
#define _LIN_UART_    1
#define _LIN_SLIC_    0
#define _LIN_GPIO_    0
/***********  SCI HARDWARE SECTION  *********/
#define NUM_OF_UART_CHANNEL    1
/* UART Base Register definition */
#define UART0_ADDR  0x4006A000

/* Use UART Channel  */
#define _UART0_   1
#define _UART1_   0
#define _UART2_   0
/* MCU bus frequency */
#define MCU_BUS_FREQ       20000000

/* Default interrupt period of the timer for LIN is TIME_BASE_PERIOD micro seconds */
#define TIME_BASE_PERIOD   500

/* max idle timeout for all networks = idle_timeout_value*1000000/time_base_period */
#define _MAX_IDLE_TIMEOUT_    10000      /* idle_timeout_value = 5s */
#endif