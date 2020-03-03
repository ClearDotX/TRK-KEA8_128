/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup XGATE_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      bsp/XGATE/lin_lld_timesrv.c
*
* @author    FPT Software
*
* @brief     Timer Handler routines
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20090408     v1.0    First version
 *
 *****************************************************************************/

#include "lin_lld_timesrv.h"
#include "xlin_sci.h"
#include "lin_hw_cfg.h"



void lin_lld_timer_S12X_init
(
    void
)
{
    /* Configures the PIT (Periodic Interrupt Timer) to generate a periodic interrupt of 500us */

    PITTF = 0x00;
    PITCE = 0x00;
    PITINTE = 0x00;

    /* USING PIT Channel 0 for Timeout management */
    PITTF_PTF0 = 1;
    PITCE_PCE0 = 1;
    /* Interrupt on channel 0 */
    PITINTE_PINTE0 = 1;

    /* Period 500us */
    PITLD0 = MCU_BUS_FREQ/2000;    /* 500us */
    PITMTLD0 = 0x00;
    /* Enable PIT Module */
    PITCFLMT = 0xA0;
}
/**
 * @}
 */
