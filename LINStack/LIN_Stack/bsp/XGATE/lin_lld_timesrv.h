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
* @file      bsp/XGATE/lin_lld_timesrv.h
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

#ifndef __LIN_LLD_TIMESRV
#define __LIN_LLD_TIMESRV

/* MODULE LIN_LLD_TIMESRV. */

#include "lin_cfg.h"
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_timer_S12X_init ( )
* @brief Timer interrupt service routine
*
*
* @return #void
*
* @SDD_ID LIN_SDD_179
* @endif
*
* @details
*   Timer interrupt service routine
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_timer_S12X_init(void);

#endif
/**
* @}
*/
