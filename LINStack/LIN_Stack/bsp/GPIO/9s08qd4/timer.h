/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup 9s08qd4_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      timer.h
*
* @author    FPT Software
*
* @brief     Timer for GPIO interface
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 *
 * 20090422     v1.0    First version
 *
 *****************************************************************************/

#ifndef _TIMER_H_
#define _TIMER_H_
#include "MC9S08QD4.h"

/**
* @enum gpio_time_out
* GPIO timeout
*/
typedef enum {
    NONE,         /**< None */
    CHECK_SYNC,   /**< Check synchronize */
    CHECK_IDLE    /**< Check idle */
} gpio_time_out;

#define ADJUSTMENT_TIME 38 /* us */
#define reset_timer()     TPMCNTH = 0
#define timer_init()      TPMSC = 0x09
#define stop_timer()      TPMSC_CLKSx = 0x00
#define timer_dis_int()   TPMSC_TOIE = 0
#define timer_ena_int()   TPMSC_TOIE = 1
#define set_counter(value)  TPMMOD = value;\
                            TPMCNTH = 0;    /* Reset timer */\
                            TPMSC_TOF = 0
#define timer2_init() TPM2SC = 0x00;\
                      TPM2MOD = 0x09C3; /*Enable interrupt*/\
                      TPM2SC_TOIE = 1

#define stop_timer2()  TPM2SC = 0x00
#define COUNTER_OVER_FLOW   TPMSC_TOF   /*The bit says counter is over-flow */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void start_timer2 ( )
* @brief start timer 2
*
* @return #void
*
* @SDD_ID LIN_SDD_167
* @endif
*
*
* @details
*   Start timer 2
*
*//*END*----------------------------------------------------------------------*/
void start_timer2(void);

#endif
/** @} */
