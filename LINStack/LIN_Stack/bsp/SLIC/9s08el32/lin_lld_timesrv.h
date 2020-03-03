/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup SCI_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      bsp/SCI/lin_lld_timesrv.h
*
* @author    FPT Software
*
* @brief     Timer and time interrupt for S08
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20101027     v1.0    First version
 *
 *****************************************************************************/
#ifndef __LIN_LLD_TIMESRV
#define __LIN_LLD_TIMESRV

/* MODULE LIN_LLD_TIMESRV. */
#include "lin_cfg.h"

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_timer_S08_init ( )
* @brief Timer interrupt service routine
*
* @return #void
*
* @SDD_ID LIN_SDD_114
* @endif
*
* @details
*   Initialize TPM Timer
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_timer_S08_init(void);


/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_timer_isr()
* @brief Timer interrupt service routine
*
* @return #void
*
* @SDD_ID LIN_SDD_113
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>i</I>
*
* @see #lin_lld_sci_timeout
*
* @details
*   Timer interrupt service routine
*//*END*----------------------------------------------------------------------*/
void lin_lld_timer_isr(void);

#endif /* __LIN_LLD_TIMESRV */

/**
* @}
*/
