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
* @file      bsp/SCI/lin_lld_timesrv.c
*
* @author    FPT Software
*
* @brief     Timer and timer interrupt for S08
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20101027     v1.0    First version
 *
 *****************************************************************************/

#include "lin_lld_timesrv.h"
#include "lin_lld_slic.h"
#include "lin_common_proto.h"
#include "lin_hw_cfg.h"

#include "lin_cfg.h"
void lin_lld_timer_S08_init
(
    void
)
{
    /* Configures the TPM to generate a periodic interrupt of 500us */
    /* (Interrupt on channel 0) */

    /* clear prescaler and disable the timer */
    TPM1SC = 0x00;

    /* clear interrupt flag and disable interrupt channel;
      channel performs output compare with not using pin */

    TPM1C0SC = 0x50;

    /* set maximum modulo value */
    TPM1C0V = TPM1MOD = (MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD;

    TPM1CNTH = 0x00;

    /* enable timer and select the TPM clock source */
    TPM1SC = 0x08;
}


void lin_lld_timer_isr(void)
{
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
    if (LD_CHECK_N_CR_TIMEOUT == tl_check_timeout_type)
    {
        if (0 == --tl_check_timeout)
        {
            /* update status of transport layer */
            tl_service_status = LD_SERVICE_ERROR;
            tl_receive_msg_status = LD_N_CR_TIMEOUT;
            tl_rx_msg_status = LD_N_CR_TIMEOUT;
            tl_check_timeout_type = LD_NO_CHECK_TIMEOUT;
            tl_diag_state = LD_DIAG_IDLE;
        }
    }

    if (LD_CHECK_N_AS_TIMEOUT == tl_check_timeout_type)
    {
        if (0 == --tl_check_timeout)
        {
            /* update status of transport layer */
            tl_service_status = LD_SERVICE_ERROR;
            tl_tx_msg_status = LD_N_AS_TIMEOUT;
            tl_check_timeout_type = LD_NO_CHECK_TIMEOUT;
            tl_diag_state = LD_DIAG_IDLE;
        }
    }
#else /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
/* Single Frame */
    if (LD_CHECK_N_AS_TIMEOUT == tl_check_timeout_type)
    {
        if(0 == --tl_check_timeout)
        {   /* update status of transport layer */
            tl_service_status = LD_SERVICE_ERROR;
            tl_check_timeout_type = LD_NO_CHECK_TIMEOUT;
        }
    }
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
}

/**
 * @}
 */
