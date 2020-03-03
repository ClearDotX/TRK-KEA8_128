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
* @date      Wed Feb 27 13:21:59 ICT 2019
*
* @brief     Hardware configuration file
*
******************************************************************************/
#ifndef      _LIN_HW_CFG_H
#define      _LIN_HW_CFG_H
#include <MC9S08QD4.h>

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

#define TX_PIN_DATA PTAD_PTAD1
#define TX_PIN_DIRECT PTADD_PTADD1
#define RX_PIN_DATA PTAD_PTAD2
#define RX_PIN_DIRECT PTADD_PTADD2

/* Interface type that MCU uses */
#define XGATE_SUPPORT 0
#define _LIN_XGATE_   0
#define _LIN_SCI_     0
#define _LIN_UART_    0
#define _LIN_SLIC_    0
#define _LIN_GPIO_    1
#endif