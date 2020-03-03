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
* @file      lin_lld_slic.c
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

#include "lin_lld_slic.h"
#include "slic_isr.h"
#include "MC9S08EL32.h"

extern l_u8 lin_current_pid;
/* Global variables */
/**
* @var lin_driver_status lin_slic_status
* slic status
 */
lin_driver_status lin_slic_status;
extern l_u16 lin_idle_timeout;

void lin_lld_slic_init()
{
    /* Requesting initialization */
    SLCC1_INITREQ = 0;

    /* Check SLIC module is in reset state */
    for (; SLCS_INITACK; );

    /* Set wait clock mode */
    SLCC2_SLCWCM = 0;

    /* Set receive filter prescaler */
    SLCC2_RXFP = 5;

    /* Set state of driver is IDLE */
    lin_slic_status = LIN_LLD_IDLE;
    lin_idle_timeout = LIN_IDLE_TIMEOUT;

    /* Enable SLIC module */
    SLCC1_BEDD = 0;
    SLCC2_BTM = 0;
    SLCS_SLCF = 1;
    SLCC1_SLCIE = 1;
    SLCC2_SLCE = 1;
}

void lin_lld_slic_set_low_power_mode
(
)
{
    lin_slic_status = LIN_LLD_LOW_POWER_MODE;
}


void lin_lld_slic_rx_response
(
    /* [IN] response length */
    l_u8 response_length
)
{
    SLCDLC_DLC = response_length - 1;
    /* Set check sum mode */
    if ((0x3C == lin_current_pid) || (0x3D == lin_current_pid))
    {
        SLCDLC_CHKMOD = 1;
    }
    else
    {
        SLCDLC_CHKMOD = 0;
    }
    SLCDLC_TXGO = 0;
}

void lin_lld_slic_tx_response
(
    /* [IN] data will be copy to SLIC buffer */
    l_u8 *data
)
{
    l_u8 i, *buffer_ptr = (l_u8*)&(SLCD0);

    clear_slic_int_flag();
    for (i = 0; i < data[0]; i++)
    {
        *buffer_ptr = data[i+1];
        buffer_ptr++;
    }
    /* Set check sum mode */
    if ((0x3C == lin_current_pid) || (0x3D == lin_current_pid))
    {
        SLCDLC_CHKMOD = 1;
    }
    else
    {
        SLCDLC_CHKMOD = 0;
    }
    SLCDLC = ((data[0]-1) | SLCDLC_TXGO_MASK);
}


l_u8 lin_lld_slic_get_state
(
)
{
    return (l_u8)lin_slic_status;
}
/**
 * @}
 */
