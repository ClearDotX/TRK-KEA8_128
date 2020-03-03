/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup 9s08el32_group
* @details This MCU supports one SLIC interface.
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      lin_lld_slic.h
*
* @author    FPT Software
*
* @brief     Low level functions and data for SLIC
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20090407     v1.0    First version
 *
 *****************************************************************************/

#ifndef _LIN_LLD_SLIC_H
#define _LIN_LLD_SLIC_H
#include "lin_cfg.h"
#include "lin.h"
#include "MC9S08EL32.h"

/* Macro */
#define LIN_IDLE_TIMEOUT 10u
//#define LIN_IDLE_TIMEOUT 50u
/**
* @enum lin_driver_status
* lin driver status
*/
typedef enum {
    LIN_LLD_UNINIT,        /**< uninit */
    LIN_LLD_OPERATIONAL,   /**< operational */
    LIN_LLD_IDLE,          /**< idle */
    LIN_LLD_LOW_POWER_MODE /**< low power mode */
} lin_driver_status;

#define lin_lld_slic_deinit()           SLCC2_SLCE    = 0; /**< Deinitialization module */

#define lin_lld_slic_tx_wake_up()       SLCC1_WAKETX  = 1; /**< Transmits wakeup signal*/

#define lin_lld_slic_int_enable()       SLCC1_SLCIE   = 1; /**< Enable interrupt */

#define lin_lld_slic_int_disable()      SLCC1_SLCIE   = 0; /**< Disable interrupt */

#define lin_lld_slic_ignore_response()  SLCC1_IMSG    = 1; /**< Ignore message*/

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_slic_init ( )
* @brief This function performs the initialization of the SLIC hardware
*
*
* @return #void
*
* @SDD_ID LIN_SDD_142
* @endif
*
*
* @static_global_var
*   -# <B>#lin_slic_status</B>
*   -# <B>#lin_idle_timeout</B>
*
* @details
*   This function performs the initialization of the SLIC hardware
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_slic_init(void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_slic_set_low_power_mode ( )
* @brief  This function sets SLIC module to low power mode
*
*
* @return #void
*
* @SDD_ID LIN_SDD_143
* @endif
*
* @static_global_var
*   -# <B>#lin_slic_status</B>
*
* @details
*    This function sets SLIC module to low power mode
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_slic_set_low_power_mode(void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_slic_rx_response (l_u8 response_length)
* @brief This function sets SLIC module to low power mode
*
* @param response_length <B>[IN]</B> response length
*
* @return #void
*
* @SDD_ID LIN_SDD_144
* @endif
*
* @static_global_var
*   -# <B>#lin_current_pid</B>
*
* @details
*   This function sets SLIC module to low power mode
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_slic_rx_response(l_u8 response_length);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_slic_tx_response (l_u8 *data)
* @brief This function sets SLIC module to low power mode
*
* @param data <B>[IN]</B> data will be copy to SLIC buffer
*
* @return #void
*
* @SDD_ID LIN_SDD_145
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>i</I>
*   -# <B>#l_u8</B> <I>*buffer_ptr</I>
*
* @static_global_var
*   -# <B>#lin_current_pid</B>
*
* @details
*   This function sets SLIC module to low power mode
*
* @see  #clear_slic_int_flag
*//*END*----------------------------------------------------------------------*/
void lin_lld_slic_tx_response(l_u8* data);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_slic_get_state ( )
* @brief This function get state of Low Level Driver
*
* @return #void
*
* @SDD_ID LIN_SDD_146
* @endif
*
* @static_global_var
*   -# <B>#lin_slic_status</B>
*
* @details
*   This function get state of Low Level Driver
*
*//*END*----------------------------------------------------------------------*/
l_u8 lin_lld_slic_get_state(void);

#endif  /* _LIN_LLD_SLIC_H */
/**
* @}
*/
