/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2016 Freescale Semiconductor, Inc.
* Copyright 2016-2017 NXP
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
* @brief     Timer and time interrupt for S08, S12, S12X
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 *
 * 20090407     v1.0    First version
 * 20111005     v1.1    Updated hardware support
 *
 *****************************************************************************/

#ifndef __LIN_LLD_TIMESRV
#define __LIN_LLD_TIMESRV

/* MODULE LIN_LLD_TIMESRV. */
#include "lin_cfg.h"
#include "lin.h"

#if defined(_MC9S08MP16_H) /* If using MC9S08MP16 then replace TPM timer by FTM timer */
#define TPM1SC                FTM1SC
#define TPM1C0SC              FTM1C0SC
#define TPM1C0V               FTM1C0V
#define TPM1MOD               FTM1MOD
#define TPM1CNTH              FTM1CNTH
#define TPM1CNTL              FTM1CNTL
#define TPM1C0SC_CH0F_MASK    FTM1C0SC_CH0F_MASK
#define VectorNumber_Vtpm1ch0 VectorNumber_Vftm1ch0
#endif /* End MC9S08MP16 */

#if (_MCU_ == _S12X_)
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_timer_S12X_init()
* @brief Initialize TPM Timer and Configures the PIT (Periodic Interrupt Timer) to generate a periodic interrupt of 500us.
*
* @return #void
*
* @SDD_ID LIN_SDD_114
* @endif
*
* @details
*   Initialize TPM Timer and Configures the PIT (Periodic Interrupt Timer) to generate a periodic interrupt of 500us.
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_timer_S12X_init(void);
#endif /* End (_MCU_ == _S12X_) */

#if (_MCU_ == _S12_)
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_timer_S12_init()
* @brief Initialize TIM1 timer
*
*
* @SDD_ID LIN_SDD_114
* @endif
*
* @return #void
*
* @details
*   Initialize TIM1 timer
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_timer_S12_init(void);
#endif /* End (_MCU_ == _S12_) */

#if (_MCU_ == _S08_)
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
#endif /* End (_MCU_ == _S08_) */


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
#ifdef MULTI_TIMER_MODE
void lin_lld_timer_isr(l_u8 index);
#else
void lin_lld_timer_isr(void);
#endif /* End MULTI_TIMER_MODE */

#endif /* __LIN_LLD_TIMESRV */

/**
* @}
*/
