/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup LIN21_core_api_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      lin_lin21_proto.c
*
* @author    FPT Software
*
* @brief     Common LIN 2.1 protocol functions
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20090408     v1.0    First version
 * 20111005     v1.1    Updated word status
 *
 *****************************************************************************/

#include "lin_lin21_proto.h"
#include "lin_common_proto.h"
#include "lin.h"


/* ---------------------------- For 1 interface ----------------------------------- */
#if (LIN_MODE == _SLAVE_MODE_)
#if ((LIN_PROTOCOL == PROTOCOL_21) || (LIN_PROTOCOL == PROTOCOL_20))
#if !defined(MCU_SKEAZN84) /* Not cover for KEA8 platform */
extern l_u8 frame_index;


void lin_update_word_status_lin21
(
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
                            (overrun << 2)|
                            (lin_goto_sleep_flg << 3) |
                            (lin_save_configuration_flg << 6));
    if(pid != 0xff)
    {
        lin_word_status.word = (lin_word_status.word & 0x00FF) | (pid << 8);
        /* Set bus activity */
        lin_word_status.word |= 1 << 4;
    }

    lin_successful_transfer = 0;
}



void lin_update_err_signal
(
    /* [IN] index of frame */
    l_u8 frm_id
)
{
    l_u8 i;
    l_u16 byte_offset_temp;
    l_u8 bit_offset_temp;
    /* Set error signal equal to error in response */
    if (LIN_FRM_EVNT != lin_frame_tbl[frm_id].frm_type)
    {
        for (i = 0; i < num_frame_have_esignal; i++)
        {
            byte_offset_temp = lin_response_error_byte_offset[i];
            bit_offset_temp = lin_response_error_bit_offset[i];
            lin_pFrameBuf[byte_offset_temp] = (l_u8)((lin_pFrameBuf[byte_offset_temp] & (~(1U << (bit_offset_temp)))) |
                                                    (lin_error_in_response << (bit_offset_temp)));
        }
    }
}
void lin_make_res_evnt_frame
(
    /* [IN] PID of frame */
    l_u8 pid
)
{
    /* Create response */
    lin_process_uncd_frame(pid, MAKE_UNCONDITIONAL_FRAME);
    lin_lld_response_buffer[1] = lin_process_parity(pid, MAKE_PARITY);
}

#endif /* End (LIN_PROTOCOL == PROTOCOL_21) */
#endif /* #if    !defined(MCU_SKEAZN84) */

#endif /* End of (LIN_MODE == _SLAVE_MODE_) */

/* ------------------------ FOR MULTI-INTERFACE -------------------------- */
#if (LIN_MODE == _MASTER_MODE_)

void lin_collision_resolve
(
    /* [IN] interface name */
    l_ifc_handle iii,
    /* [IN] PID of frame */
    l_u8 pid
)
{
    lin_associate_frame_struct *ptr;
    l_u8 frame_index;
    const lin_configuration *conf;
    l_u8 *_active_schedule_id;

    conf = &(lin_ifc_configuration[iii]);
    frame_index = lin_get_frame_index(iii, pid);
    /* Check MASTER function */
    if (_MASTER_ == conf->function)
    {
        /* Find collision resolver table */
        /* Swap schedule table */
        /* Get active_schedule_id */
        _active_schedule_id = conf->active_schedule_id;
        *(conf->previous_schedule_id) = *_active_schedule_id ;

        /* Set collision resolver table to active schedule */
        ptr = (lin_associate_frame_struct*)conf->frame_tbl[frame_index].frame_data;

        *_active_schedule_id = ptr->coll_resolver_id;

        conf->schedule_start_entry[*_active_schedule_id] = 0;
    }
}

void lin_update_word_status_lin21
(
    /* [IN] interface name */
    l_ifc_handle iii,
    /* [IN] event of Low-level driver */
    lin_lld_event_id event_id,
    /* [IN] PID of frame */
    l_u8 pid
)
{

    l_u8 err_in_res, suc_in_tras, frame_index, save_config;
    lin_word_status_str *word_status_ptr;
    const lin_configuration *conf;

    conf = &(lin_ifc_configuration[iii]);
    err_in_res = *(conf->error_in_response);
    suc_in_tras = *(conf->successful_transfer);
    save_config = lin_save_configuration_flg[iii];

    word_status_ptr = conf->word_status;
    if((word_status_ptr->word & 0x03) > 0)
    {
        word_status_ptr->bit.overrun |= err_in_res | suc_in_tras;
    }
    word_status_ptr->bit.error_in_res |= err_in_res;
    word_status_ptr->bit.successful_transfer |= suc_in_tras;
    if(pid != 0xff)
    {
        word_status_ptr->bit.last_pid = pid;
    }
    if(LIN_LLD_BUS_ACTIVITY_TIMEOUT != event_id)
    {
        /* Set bus activity timeout */
        word_status_ptr->bit.bus_activity = 1U;
    }

    if (_MASTER_ == conf->function)
    {
        /* For Master node */
        word_status_ptr->bit.gotosleep = *(conf->goto_sleep_flg);
        /* If is Master node, value always equal 0 */
        word_status_ptr->bit.save_conf = 0;

        frame_index = lin_get_frame_index(iii, pid);
        if (0xFF == frame_index) /* This PID doesn't belong to this node */
        {
            /* Error */
            return;
        }

        /* PID belongs to this node, then check type of frame */
        if (LIN_SCH_TBL_COLL == conf->schedule_tbl->sch_tbl_type)
        {
            word_status_ptr->bit.etf_collision = 1;
        }
        else
        {
            word_status_ptr->bit.etf_collision = 0;
        }
    }
    else
    {
        /* For Slave node */
        word_status_ptr->bit.gotosleep = *(conf->goto_sleep_flg);
        word_status_ptr->bit.etf_collision = 0;
        /* Updated save configuration value to word status */
        word_status_ptr->bit.save_conf = save_config;
        word_status_ptr->bit.dummy = 0;
    }
}


void lin_update_err_signal
(
    /* [IN] interface name */
    l_ifc_handle iii,
    l_u8 frm_id
)
{
    const lin_configuration *conf;
    l_u8 i;
    l_u16* byte_offset_temp_ptr;
    l_u8* bit_offset_temp_ptr;
    l_u8 err_in_res;
    lin_node_attribute *node_att_ptr;

    conf = &(lin_ifc_configuration[iii]);
    node_att_ptr = conf->node_attribute;
    err_in_res = *(conf->error_in_response);
    /* Set error signal equal to error in response */
    if (LIN_FRM_EVNT != conf->frame_tbl[frm_id].frm_type)
    {
        for (i = 0; i < node_att_ptr->num_frame_have_esignal; i++)
        {
            byte_offset_temp_ptr = &node_att_ptr->response_error_byte_offset_ptr[i];
            bit_offset_temp_ptr = &node_att_ptr->response_error_bit_offset_ptr[i];
            lin_pFrameBuf[*byte_offset_temp_ptr] = (l_u8)((lin_pFrameBuf[*byte_offset_temp_ptr] & (~(1U << (*bit_offset_temp_ptr)))) |
                                                    (err_in_res << (*bit_offset_temp_ptr)));
        }
    }
}

void lin_update_rx_evnt_frame
(
    /* [IN] interface name */
    l_ifc_handle iii,
    /* [IN] PID of frame */
    l_u8 pid
)
{
    lin_associate_frame_struct *ptr;
    l_u8 frame_index, i, ass_pid;
    const lin_configuration *conf;

    conf = &(lin_ifc_configuration[iii]);
    /* Get frame index of the eventrigger frame */
    frame_index = lin_get_frame_index(iii, pid);

    if (0xFF != frame_index) /* This PID doesn't belong to this node */
    {

        /* calculate PID that associated with ETF */
        ass_pid = lin_process_parity(conf->response_buffer[1], CHECK_PARITY);
        ptr = (lin_associate_frame_struct*)(conf->frame_tbl[frame_index].frame_data);

        for (i = 0; i < ptr->num_asct_uncn_pid; i++ )
        {
            /* First byte of response for event trigger is the PID of the associate frame */
            if (conf->configuration_RAM[ptr->act_uncn_frm[i] - conf->frame_start + 1] == ass_pid )
            {
                /* Update unconditional frame */
                lin_process_uncd_frame(iii, ass_pid, UPDATE_UNCONDITIONAL_FRAME);
                /* break; */
                i = ptr->num_asct_uncn_pid;
            }
        }
    }
    /* error */
    return;
}

void lin_make_res_evnt_frame
(
    /* [IN] interface name */
    l_ifc_handle iii,
    /* [IN] PID of frame */
    l_u8 pid
)
{
    /* Create response */
    lin_process_uncd_frame(iii, pid, MAKE_UNCONDITIONAL_FRAME);
    /* Set associate PID */
    lin_ifc_configuration[iii].response_buffer[1] = lin_process_parity(pid, MAKE_PARITY);
}
#endif /* End of (LIN_MODE == _MASTER_MODE_) */
/**
 * @}
 */
