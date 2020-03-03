/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup J2602_core_api_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      lin_j2602_proto.c
*
* @author    FPT Software
*
* @brief     J2602 LIN protocol functions
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20090408     v1.0    First version
 *
 *****************************************************************************/

#include "lin_j2602_proto.h"

/* ---------------------------- For 1 interface -----------------------------------*/
#if LIN_MODE == _SLAVE_MODE_
#if LIN_PROTOCOL != PROTOCOL_21

void lin_update_word_status_j2602
(
    /* [IN] event of Low-level driver */
    lin_lld_event_id event_id,
    /* [IN] PID of frame */
    l_u8 pid
)
{
    l_u8 overrun = 0;
    if((lin_word_status.word & 0x03) > 0)
    {
        overrun |= lin_successful_transfer | lin_error_in_response;
    }
    lin_word_status.word |= ((lin_error_in_response) | (lin_successful_transfer << 1) |
                            (overrun << 2) | (lin_goto_sleep_flg << 3));
    lin_word_status.word = (lin_word_status.word & 0x00FF) | (pid << 8);

    lin_successful_transfer = 0;
}

void lin_update_status_byte
(
    /* [IN] interface name */
    lin_lld_event_id event_id
)
{
	l_u8 i;
    l_u8 signal_data;
    l_u16 byte_offset_temp;
    l_u8 bit_offset_temp;
    l_bool set_error_signal = 0;
    switch (event_id)
    {
        /* Parity error */
        case LIN_LLD_PID_ERR:
            /* Set ID Parity Error 0x07 */
            signal_data = 0x07;
            set_error_signal = 1;
            break;
        /* Byte Field Framing Error*/
        case LIN_LLD_FRAME_ERR:
            /* Set Byte Field Framing Error 0x06 */
            signal_data = 0x06;
            set_error_signal = 1;
            break;
        /* Checksum error */
        case LIN_LLD_CHECKSUM_ERR:
            /* Set Checksum error 0x05 */
            signal_data = 0x05;
            set_error_signal = 1;
            break;
        /* Data error */
        case LIN_LLD_READBACK_ERR:
            /* Set Data error 0x04 */
            signal_data = 0x04;
            set_error_signal = 1;
            break;
        default:
            break;
    }

    if (set_error_signal == 1)
    {
        for (i = 0; i < num_frame_have_esignal; i++)
        {
            /* Get pointer to Byte and bit offset values in each frame that contains the error signal */
            byte_offset_temp = lin_response_error_byte_offset[i];
            bit_offset_temp = lin_response_error_bit_offset[i];
            /* Set error signal equal to error in response */
            lin_pFrameBuf[byte_offset_temp] = (l_u8)((lin_pFrameBuf[byte_offset_temp] & (~(0x07U << bit_offset_temp))) |
                                                        (signal_data << bit_offset_temp));
        }
    }
}
#endif /* End (LIN_PROTOCOL != PROTOCOL_21) */
#endif /* End of (LIN_MODE == _SLAVE_MODE_)*/

/*-----------------------------------------------------------------------*/
#if LIN_MODE == _MASTER_MODE_

void lin_update_word_status_j2602
(
    /* [IN] interface name */
    l_ifc_handle iii,
    /* [IN] event of Low-level driver */
    lin_lld_event_id event_id,
    /* [IN] PID of frame */
    l_u8 pid
)
{
    l_u8 err_in_res, suc_in_tras;
    lin_word_status_str *word_status;
    lin_configuration const *conf;

    conf = &(lin_ifc_configuration[iii]);
    err_in_res = *(conf->error_in_response);
    suc_in_tras = *(conf->successful_transfer);

    word_status = conf->word_status;
    word_status->bit.error_in_res = err_in_res;
    if((word_status->word & 0x03) > 0)
    {
        word_status->bit.overrun |= (err_in_res | suc_in_tras);
    }
    word_status->bit.successful_transfer = suc_in_tras;
    word_status->bit.last_pid = pid;
    word_status->bit.gotosleep = *(conf->goto_sleep_flg);

    *(conf->successful_transfer) = 0;
}

void lin_update_status_byte
(
    /* [IN] interface name */
    l_ifc_handle iii,
    /* [IN] interface name */
    lin_lld_event_id event_id
)
{
	l_u8 i;
    l_u8 signal_data;
    l_u16* byte_offset_temp_ptr;
    l_u8* bit_offset_temp_ptr;
    lin_node_attribute *node_att_ptr;
    l_bool set_error_signal = 0;
    lin_configuration const *conf;

    conf = &(lin_ifc_configuration[iii]);
    switch (event_id)
    {
        /* Parity error */
        case LIN_LLD_PID_ERR:
            /* Set ID Parity Error 0x07 */
            signal_data= 0x07;
            set_error_signal = 1;
            break;
        /* Byte Field Framing Error*/
        case LIN_LLD_FRAME_ERR:
            /* Set Byte Field Framing Error 0x06 */
            signal_data = 0x06;
            set_error_signal = 1;
            break;
        /* Checksum error */
        case LIN_LLD_CHECKSUM_ERR:
            /* Set Checksum error 0x05 */
            signal_data = 0x05;
            set_error_signal = 1;
            break;
        /* Data error */
        case LIN_LLD_READBACK_ERR:
            /* Set Data error 0x04 */
            signal_data = 0x04;
            set_error_signal = 1;
            break;
        default:
            break;
    }

    if (set_error_signal == 1)
    {
        node_att_ptr = conf->node_attribute;
        for (i = 0; i < node_att_ptr->num_frame_have_esignal; i++)
        {
            /* Get pointer to Byte and bit offset values in each frame that contains the error signal */
            byte_offset_temp_ptr = node_att_ptr->response_error_byte_offset_ptr + i;
            bit_offset_temp_ptr = node_att_ptr->response_error_bit_offset_ptr + i;
            /* Set error signal equal to error in response */
            lin_pFrameBuf[*byte_offset_temp_ptr] = (l_u8)((lin_pFrameBuf[*byte_offset_temp_ptr] & (~(0x07U << (*bit_offset_temp_ptr)))) |
                                                        (signal_data << (*bit_offset_temp_ptr)));
        }
    }
}
#endif /* End of (LIN_MODE == _SLAVE_MODE_)*/
/**
* @}
*/
