/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup diagnostic_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      lin_diagnostic_service.c
*
* @author    FPT Software
*
* @brief     Diagnostic Service slave functions
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20090718     v1.0    First version
 * 20111005     v1.1    Updated diagnostics service
 *
 *****************************************************************************/

#include "lin_commontl_proto.h"
#include "lin_diagnostic_service.h"

/* Define functionality */
#ifndef MULTI_PDU_SUPPORT
#define MULTI_PDU_SUPPORT 0                         /**< multi PDU support */
#endif /* End MULTI_PDU_SUPPORT */

#if LIN_MODE == _MASTER_MODE_
#if LIN_PROTOCOL == PROTOCOL_J2602
static l_bool ld_change_msg_id(l_ifc_handle iii, l_u8 dnn, l_u8 frame_id_change);
#endif /* End of LIN_PROTOCOL == PROTOCOL_J2602 */
#endif /* End of LLIN_MODE == _MASTER_MODE_ */


/********------------- Code supports SINGLE interface ----------------**********/
#if LIN_MODE == _SLAVE_MODE_
#if LIN_PROTOCOL == PROTOCOL_J2602
static l_bool ld_change_msg_id(l_u8 dnn, l_u8 frame_id_change);
#endif /* End of LIN_PROTOCOL == PROTOCOL_J2602 */


/*************************** FUNCTIONS *******************/
/* Unuse for GPIO */
#if ( _LIN_GPIO_ == 0 ) && !defined(_MC9S08SC4_H) && !defined(MCU_SKEAZN84)

void lin_diagservice_read_by_identifier()
{
    l_u8 id;
    l_u16 supid, fid;
    lin_tl_pdu_data *lin_tl_pdu;

    /* Multi frame support */
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
    l_u16 length;
    l_u8 data[10];
    /* get pdu from rx queue */
    ld_receive_message(&length, data+2);
    lin_tl_pdu = (lin_tl_pdu_data *)data;
#else /* Single frame support */
    lin_tl_pdu = tl_current_rx_pdu_ptr;
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */

    /* Get supplier and function indentification in request */
    supid = (l_u16)(((*lin_tl_pdu)[5]) << 8);
    supid = supid |(l_u16)((*lin_tl_pdu)[4]);

    fid = (l_u16)(((*lin_tl_pdu)[7]) << 8);
    fid = fid |(l_u16)((*lin_tl_pdu)[6]);


    /* Check Supplier ID and Function ID */
    if (((supid != product_id.supplier_id) && (supid != LD_ANY_SUPPLIER)) || \
            ((fid != product_id.function_id) && (fid != LD_ANY_FUNCTION)))
    {
        tl_slaveresp_cnt = 0;
    #if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
        tl_service_status = LD_SERVICE_IDLE;
    #endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
        return;
    }
    id = (*lin_tl_pdu)[3];

    switch (id)
    {
        case LIN_PRODUCT_IDENT:
            lin_tl_make_slaveres_pdu(SERVICE_READ_BY_IDENTIFY, POSITIVE, 0);
            break;
        case SERIAL_NUMBER:
            lin_tl_make_slaveres_pdu(SERVICE_READ_BY_IDENTIFY, NEGATIVE, SUBFUNCTION_NOT_SUPPORTED);
            break;
         default:
            if (id >= LIN_READ_USR_DEF_MIN && id <= LIN_READ_USR_DEF_MAX)
            {
                l_u8 data_callout[5] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
                l_u8 i;
                l_u8 retval = ld_read_by_id_callout(id, data_callout);
                /*If the User ID is supported, make positive response*/
                if (retval == LD_POSITIVE_RESPONSE)
                {
                    for (i =0; i <5; i++)
                    {
                        if (data_callout[i] != 0xFF)
                        {
                            lin_tl_make_slaveres_pdu(SERVICE_READ_BY_IDENTIFY, POSITIVE, id);
                            break;
                        }
                        /* If all data_callout is 0xFF, then make negative response*/
                        if (i == 4)
                        {
                            /* Make a negative slave response PDU */
                            lin_tl_make_slaveres_pdu(SERVICE_READ_BY_IDENTIFY, NEGATIVE, SUBFUNCTION_NOT_SUPPORTED);
                        }

                    }
                }
                else if (retval == LD_NEGATIVE_RESPONSE)
                /*If the User ID is not supported, make negative response*/
                {
                    /* Make a negative slave response PDU */
                    lin_tl_make_slaveres_pdu(SERVICE_READ_BY_IDENTIFY, NEGATIVE, SUBFUNCTION_NOT_SUPPORTED);
                }
                else if (retval == LD_ID_NO_RESPONSE)
                {
                    /*Do not answer*/
                    tl_slaveresp_cnt = 0;
                    #if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
                    tl_service_status = LD_SERVICE_IDLE;
                    #endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
                }

            }
            else
            {
                /* Make a negative slave response PDU */
                lin_tl_make_slaveres_pdu(SERVICE_READ_BY_IDENTIFY, NEGATIVE, SUBFUNCTION_NOT_SUPPORTED);
            }
            break;
    } /* End of switch */
}
#if LIN_PROTOCOL == PROTOCOL_21

void lin_diagservice_assign_frame_id_range()
{
    l_u8 start_index;
    l_s8 j, i = 7;
    lin_tl_pdu_data *lin_tl_pdu;
    /* Multi frame support */
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
    l_u16 length;
    l_u8 data[10];
    /* get pdu from rx queue */
    ld_receive_message(&length, data+2);
    lin_tl_pdu = (lin_tl_pdu_data *)data;
#else /* Single frame support */
    lin_tl_pdu = tl_current_rx_pdu_ptr;
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
    /* Get start index in request */
    start_index = (*lin_tl_pdu)[3];

    for (i = 7, j = start_index+4; j > start_index; i--, j-- )
    {
        if ((0xFF != (*lin_tl_pdu)[i]) && (j > LIN_CFG_FRAME_NUM))
        {
            lin_tl_make_slaveres_pdu(SERVICE_ASSIGN_FRAME_ID_RANGE, NEGATIVE, GENERAL_REJECT);
            return;
        }
    }

    /* Store PIDs */
    for (i = 4, j = start_index + 1; i < 8; i++, j++)
    {
        switch ((*lin_tl_pdu)[i])
        {
            case 0x00:
                /* Unassign frame */
                lin_configuration_RAM[j] = 0xFF;
                break;

            case 0xFF:
                /* keep the previous assigned value of this frame */
                break;

            default:
                /* Calculate frame ID & Assign ID to frame */
                lin_configuration_RAM[j] = lin_process_parity((*lin_tl_pdu)[i], CHECK_PARITY);
                break;
        }
    } /* End of for statement */

    lin_tl_make_slaveres_pdu(SERVICE_ASSIGN_FRAME_ID_RANGE, POSITIVE, 0);
}

#endif /* End (LIN_PROTOCOL == PROTOCOL_21) */

#if LIN_PROTOCOL != PROTOCOL_J2602
void lin_condittional_change_nad()
{
    l_u8 id, byte, mask, invert;
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
    id      = lin_tl_rx_queue.tl_pdu[lin_tl_rx_queue.queue_header][3];
    byte    = lin_tl_rx_queue.tl_pdu[lin_tl_rx_queue.queue_header][4];
    mask    = lin_tl_rx_queue.tl_pdu[lin_tl_rx_queue.queue_header][5];
    invert  = lin_tl_rx_queue.tl_pdu[lin_tl_rx_queue.queue_header][6];
#else /* Single frame support */
    id      = (*tl_current_rx_pdu_ptr)[3];
    byte    = (*tl_current_rx_pdu_ptr)[4];
    mask    = (*tl_current_rx_pdu_ptr)[5];
    invert  = (*tl_current_rx_pdu_ptr)[6];
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */

    /* Possible positive ID */
    if (id == 0)
    {
        if(byte>0 && byte<6)
        {
            /*Byte 1: Supplier ID LSB; Byte 2: Supplier ID MSB*/
            if(byte>0 && byte<3)
            {
                byte = product_id.supplier_id >> ((byte-1)*8);
            }
            /*Byte 3: Function ID LSB; Byte 4: Function ID MSB*/
            else if(byte>2 && byte<5)
            {
                byte = product_id.function_id >> ((byte-3)*8);
            }
            /* Byte 5: Variant */
            else
            {
                byte = product_id.variant;
            }
            /* Do a bitwise XOR with Invert and Do a bitwise AND with Mask */
            byte = (byte^invert)&mask;
            /* If the final result is zero, then give positive response*/
            if (byte == 0)
            {
                lin_tl_make_slaveres_pdu(SERVICE_CONDITIONAL_CHANGE_NAD, POSITIVE, 0);
                /* If the final result is zero then change the NAD to New NAD */
            #if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
                lin_configured_NAD = lin_tl_rx_queue.tl_pdu[lin_tl_rx_queue.queue_header][7];
            #else/* Single frame support */
                lin_configured_NAD = (*tl_current_rx_pdu_ptr)[7];
            #endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
            }
        }
    }
}
#else

/*FUNCTION**********************************************************************
 *
 * Function Name : ld_assign_NAD_j2602
 * Description   : This function assigns NAD of a J2602 slave device based on input
 *                 dnn. NAD is (0x60 + dnn).
 *
 *END**************************************************************************/
l_bool ld_assign_NAD_j2602(l_u8 dnn)
{
    l_bool ret_val = 1U;

    if (dnn <= 0xFU)
    {
        lin_configured_NAD = (l_u8)(0x60U + dnn);
        ret_val = 0U;
    }

    return ret_val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : ld_reconfig_msg_ID
 * Description   : This function reconfigures frame identifiers of a J2602 slave node
 *                 based on input dnn. This function is for slave nodes only.
 *
 *END**************************************************************************/
l_bool ld_reconfig_msg_ID(l_u8 dnn)
{
    l_bool ret_val = 1U;
    l_u8 i = 0;
    /* Get number of configurable_frames not calculate id 0x3C and 0x3D */
    l_u8 number_of_configurable_frames = LIN_NUM_OF_FRMS - 2;

    for(i = LIN_NUM_OF_FRMS - 3; i >= 0; i--)
    {
        if(lin_frame_tbl[i].frm_type == LIN_FRM_UNCD)
        {
            break;
        }
        else
        {
            number_of_configurable_frames--;
        }
    }

    if (dnn <= 0xDU)
    {
        /* number of configurable frames greater than 16 */
        if (number_of_configurable_frames > 16U)
        {
            /* Only 0x60 is valid NAD */
            /* Do nothing */
        }
        /* number of configurable frames is from 9 - 16 */
        else if (number_of_configurable_frames > 8U)
        {
            /* Only NAD 0x60, 0x64, 0x68 are valid, 0x6C and 0x6D not valid */
            if ((dnn == 0U) || (dnn == 4U) || (dnn == 8U))
            {
                ret_val = ld_change_msg_id(dnn, 16U);
            }
        }
        /* number of configurable frames is from 5 - 8 */
        else if (number_of_configurable_frames > 4U)
        {
            /* Check to verify if dnn is 0x60, 0x62, 0x64, 0x66, 0x68, 0x6A, 0x6C */
            if ((dnn % 2U) == 0U)
            {
                ret_val = ld_change_msg_id(dnn, 8U);
            }
        }
        /* number of configurable frames is from 1 - 4 */
        else
        {
            ret_val = ld_change_msg_id(dnn, 4U);
        }
    }

    return ret_val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : ld_change_msg_id
 * Description   : This function reconfigures frame identifiers of a J2602 slave node
 *                 based on input dnn and frame_id_change.
 *
 *END**************************************************************************/
static l_bool ld_change_msg_id(l_u8 dnn,
                               l_u8 frame_id_change)
{
    l_u8 i;
    l_u8 id_origin;
    /* If new DNN is greater than current DNN */
    for (i = LIN_NUM_OF_FRMS; i > 0U; i--)
    {
        /* For non-broadcast frame identifiers  less than or equal to 0x37 */
        if (lin_configuration_RAM[i] <= 0x37U)
        {
            /* get id with dnn equal 0 */
            id_origin = (l_u8)(lin_configuration_RAM[i] % frame_id_change);
            lin_configuration_RAM[i] = (l_u8)(id_origin + (l_u8)(dnn << 2));
        }
        /* For broad cast message ID */
        else if ((lin_configuration_RAM[i] <= 0x3BU) && (lin_configuration_RAM[i] >= 0x38U))
        {
            if ((dnn  >= 8U) &&
                ((lin_configuration_RAM[i] == 0x38U) || (lin_configuration_RAM[i] == 0x3AU)))
            {
                lin_configuration_RAM[i] += 1U;
            }
            else if ((dnn  < 8U) &&
                     ((lin_configuration_RAM[i] == 0x39U) || (lin_configuration_RAM[i] == 0x3BU)))
            {
                lin_configuration_RAM[i] -= 1U;
            }
        }
    }

    return (l_bool)0U;
}
#endif /* End LIN_PROTOCOL != PROTOCOL_J2602 */

#if ((LIN_PROTOCOL == PROTOCOL_20) || (LIN_PROTOCOL == PROTOCOL_J2602))

void lin_diagservice_assign_frame_identifier()
{
	l_u8 id, pid , i;
	l_u16 supid, messageid;
	lin_tl_pdu_data *lin_tl_pdu;

	/* Multi frame support */
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
	l_u16 length;
	l_u8 data[10];
	/* get pdu from rx queue */
	ld_receive_message(&length, data+2);
	lin_tl_pdu = (lin_tl_pdu_data *)data;
#else /* Single frame support */
	lin_tl_pdu = tl_current_rx_pdu_ptr;
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */

	/* Get supplier and function indentification in request */
	supid = (l_u16)(((*lin_tl_pdu)[4]) << 8);
	supid = supid |(l_u16)((*lin_tl_pdu)[3]);
	messageid = (l_u16)(((*lin_tl_pdu)[6]) << 8);
	messageid = messageid |(l_u16)((*lin_tl_pdu)[5]);
	pid = (*lin_tl_pdu)[7];
	id = lin_process_parity(pid,CHECK_PARITY);

	/* Check if id is already assign for the other frame */
	i = 1;
	while(lin_configuration_ROM[i] != 0xFFFF)
	{
		if((id == lin_configuration_RAM[i]) && (lin_configuration_ROM[i] != messageid))
		{
			id = 0xFF;
			break;
		}
		i++;
	}

	/* Check Supplier ID and Function ID */
	if (((supid != product_id.supplier_id) && (supid != LD_ANY_SUPPLIER)) || (id == 0xFF))
	{
		tl_slaveresp_cnt = 0;
	#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
		tl_service_status = LD_SERVICE_IDLE;
	#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
		return;
	}
	/* Check if exist message id */
	i = 1;
	while(lin_configuration_ROM[i] != 0xFFFF)
	{
		if(lin_configuration_ROM[i] == messageid)
		{
			lin_configuration_RAM[i] = id;
			/* Send positive response */
			lin_tl_make_slaveres_pdu(SERVICE_ASSIGN_FRAME_ID, POSITIVE, 0);
			break;
		}
		i++;
	}
}

#endif /* end of LIN_PROTOCOL == PROTOCOL_20 or LIN_PROTOCOL == PROTOCOL_J2602 */
#endif /* End ( _LIN_GPIO_ == 0 ) && !defined(_MC9S08SC4_H) */


#if LIN_PROTOCOL == PROTOCOL_21
/* Multi frame support */
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
void lin_diagsrv_functional_service(void)
{
    l_u16 length;
    l_u8 data[10];
    /* get pdu from rx queue */
    ld_receive_message(&length, data);

    /* do something here */
}
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
#endif /* End (LIN_PROTOCOL == PROTOCOL_21) */

#if LIN_PROTOCOL == PROTOCOL_J2602
void lin_diagservice_target_reset()
{
    l_u8 *signal_data_ptr;
    l_u8 nad;
    l_u16 byte_offset_temp;
    l_u8 bit_offset_temp, i;
    lin_tl_pdu_data *lin_tl_pdu;
    /* Multi frame support */
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
    lin_tl_pdu = (lin_tl_pdu_data *)&lin_lld_response_buffer[1];
#else /* Single frame support */
    lin_tl_pdu = tl_current_rx_pdu_ptr;
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
    /* Set the reset flag within the J2602 Status Byte */
    /* Set error signal equal to error in response */
    for (i = 0; i < num_frame_have_esignal; i++)
    {
        /* Get pointer to Byte and bit offset values in each frame that contains the error signal */
        byte_offset_temp = lin_response_error_byte_offset[i];
        bit_offset_temp = lin_response_error_bit_offset[i];
        /* Set error signal to 0x01 means "Reset" */
        lin_pFrameBuf[byte_offset_temp] = (l_u8)((lin_pFrameBuf[byte_offset_temp] & (~(0x07U << bit_offset_temp))) |
                                                    (0x01U << bit_offset_temp));
    }

    /* Create positive response */

    /* Get NAD of node */
    nad = (*lin_tl_pdu)[0];

    if (LD_BROADCAST != nad)
    {
        lin_tl_make_slaveres_pdu(SERVICE_TARGET_RESET, POSITIVE, 0);
    }
    else
    {
        tl_slaveresp_cnt = 0;
    }
}
#endif /* End (LIN_PROTOCOL == PROTOCOL_J2602) */

#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
/* get diagnostic flag */
l_u8 diag_get_flag(l_u8 flag_order)
{
    if (flag_order >= _DIAG_NUMBER_OF_SERVICES_)
    {
        return 0;
    }
    else
    {
        return (l_u8) lin_diag_services_flag[flag_order];
    }

}

void diag_clear_flag(l_u8 flag_order)
{
    if (flag_order < _DIAG_NUMBER_OF_SERVICES_)
    {
        lin_diag_services_flag[flag_order] = 0;
    }
}
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */

#endif /* End (LIN_MODE == _SLAVE_MODE_) */
/********------------ End of code for SINGLE Interface --------------**********/


/********------------- Code supports Multi interface ----------------**********/
#if LIN_MODE == _MASTER_MODE_
/*************************** FUNCTIONS *******************/
void lin_diagservice_read_by_identifier
(
    /* [IN] interface name */
    l_ifc_handle iii
)
{
    const lin_configuration* conf;
    const lin_node_attribute* node_conf;
    lin_product_id  ident;
    lin_tl_descriptor *tl_conf;
    lin_tl_pdu_data *lin_tl_pdu;
    l_u8 id;
    l_u16 supid, fid;
    /* Multi frame support */
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
    lin_tl_pdu_data pdu_data;
    l_u16 length;
    l_u8 NAD, data[10];
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */

    /* Get current configuration */
    conf = &lin_ifc_configuration[iii];

    /* Get TL description */
    tl_conf = conf->tl_desc;

    /* Do actions only for slave nodes */
    if (conf->function == _SLAVE_)
    {
        /* Multi frame support */
    #if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
        lin_tl_pdu = (lin_tl_pdu_data *)&pdu_data;
        /* receive message data */
        ld_receive_message(iii, &length, &NAD, data+2);

        lin_tl_pdu = (lin_tl_pdu_data *)data;
    #else /* Single frame support */
        lin_tl_pdu = (lin_tl_pdu_data *)&conf->response_buffer[1];
    #endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */

        /* Get the node attribute */
        node_conf = conf->node_attribute;

        /* Get the product identification */
        ident = node_conf->product_id;

        /* Get supplier and function indentification in request */
        supid = (l_u16)(((*lin_tl_pdu)[5]) << 8);
        supid = supid |(l_u16)((*lin_tl_pdu)[4]);

        fid = (l_u16)(((*lin_tl_pdu)[7]) << 8);
        fid = fid |(l_u16)((*lin_tl_pdu)[6]);


        /* Check Supplier ID and Function ID */
        if (((supid != ident.supplier_id) && (supid != LD_ANY_SUPPLIER)) || \
                ((fid != ident.function_id) && (fid != LD_ANY_FUNCTION)))
        {
            tl_conf->tl_slaveresp_cnt = 0;
            return;
        }

        /* Get the identifier of request */
        id = (*lin_tl_pdu)[3];

        switch (id)
        {
            case LIN_PRODUCT_IDENT:
                lin_tl_make_slaveres_pdu(iii, SERVICE_READ_BY_IDENTIFY, POSITIVE, 0);
                break;
            case SERIAL_NUMBER:
            lin_tl_make_slaveres_pdu(iii, SERVICE_READ_BY_IDENTIFY, NEGATIVE, SUBFUNCTION_NOT_SUPPORTED);
            break;

            default:
                if (id >= LIN_READ_USR_DEF_MIN && id <= LIN_READ_USR_DEF_MAX)
                {
                    l_u8 data_callout[5] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
                    l_u8 i;
                    l_u8 retval = ld_read_by_id_callout(iii,id, data_callout);
                    /*If the User ID is supported, make positive response*/
                    if (retval == LD_POSITIVE_RESPONSE)
                    {
                        for (i =0; i <5; i++)
                        {
                            if (data_callout[i] != 0xFF)
                            {
                                lin_tl_make_slaveres_pdu(iii,SERVICE_READ_BY_IDENTIFY, POSITIVE, id);
                                break;
                            }
                            /* If all data_callout is 0xFF, then make negative response*/
                            if (i == 4)
                            {
                                /* Make a negative slave response PDU */
                                lin_tl_make_slaveres_pdu(iii,SERVICE_READ_BY_IDENTIFY, NEGATIVE, SUBFUNCTION_NOT_SUPPORTED);
                            }

                        }
                    }
                    else if (retval == LD_NEGATIVE_RESPONSE)
                    /*If the User ID is not supported, make negative response*/
                    {
                        /* Make a negative slave response PDU */
                        lin_tl_make_slaveres_pdu(iii,SERVICE_READ_BY_IDENTIFY, NEGATIVE, SUBFUNCTION_NOT_SUPPORTED);
                    }
                    else if (retval == LD_ID_NO_RESPONSE)
                    {
                        /*Do not answer*/
                        tl_conf->tl_slaveresp_cnt = 0;
                        #if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
                        *conf->tl_service_status = LD_SERVICE_IDLE;
                        #endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
                    }
                }
                else
                {
                    /* Make a negative slave response PDU */
                    lin_tl_make_slaveres_pdu(iii, SERVICE_READ_BY_IDENTIFY, NEGATIVE, SUBFUNCTION_NOT_SUPPORTED);
                }
                break;
        } /* end of switch */
    }
}

#if ((LIN_PROTOCOL == PROTOCOL_20) || (LIN_PROTOCOL == PROTOCOL_J2602))

void lin_diagservice_assign_frame_identifier
(
    /* [IN] interface name */
    l_ifc_handle iii
)
{
	const lin_configuration* conf;
	const lin_node_attribute* node_conf;
	lin_product_id  ident;
	lin_tl_descriptor *tl_conf;
	lin_tl_pdu_data *lin_tl_pdu;
	l_u8 id, pid, i;
	l_u16 supid, messageid;
	/* Multi frame support */
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
	lin_tl_pdu_data pdu_data;
	l_u16 length;
	l_u8 NAD, data[10];
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */

	/* Get current configuration */
	conf = &lin_ifc_configuration[iii];

	/* Get TL description */
	tl_conf = conf->tl_desc;

	/* Do actions only for slave nodes */
	if (conf->function == _SLAVE_)
	{
		/* Multi frame support */
	#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
		lin_tl_pdu = (lin_tl_pdu_data *)&pdu_data;
		/* receive message data */
		ld_receive_message(iii, &length, &NAD, data+2);

		lin_tl_pdu = (lin_tl_pdu_data *)data;
	#else /* Single frame support */
		lin_tl_pdu = (lin_tl_pdu_data *)&conf->response_buffer[1];
	#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */

		/* Get the node attribute */
		node_conf = conf->node_attribute;

		/* Get the product identification */
		ident = node_conf->product_id;

		/* Get supplier and function indentification in request */
		supid = (l_u16)(((*lin_tl_pdu)[4]) << 8);
		supid = supid |(l_u16)((*lin_tl_pdu)[3]);

		messageid = (l_u16)(((*lin_tl_pdu)[6]) << 8);
		messageid = messageid |(l_u16)((*lin_tl_pdu)[5]);
		pid = (l_u16)((*lin_tl_pdu)[7]);
		id = lin_process_parity(pid,CHECK_PARITY);

		/* Check if id is already assign for the other frame*/
		i = 1;
		while (0xFFFF != (conf->configuration_ROM)[i])
		{
			if((id == (conf->configuration_RAM)[i]) && ((conf->configuration_ROM)[i] != messageid))
			{
				id = 0xFF;
				break;
			}
			i++;
		}

		/* Check Supplier ID and Function ID */
		if (((supid != ident.supplier_id) && (supid != LD_ANY_SUPPLIER)) || (id == 0xFF))
		{
			tl_conf->tl_slaveresp_cnt = 0;
			return;
		}

		/* Check if exist message id */
		i = 1;
		while (0xFFFF != (conf->configuration_ROM)[i])
		{
			if((conf->configuration_ROM)[i] == messageid)
			{
				(conf->configuration_RAM)[i] = id;
				/* Send positive response */
				lin_tl_make_slaveres_pdu(iii,SERVICE_ASSIGN_FRAME_ID, POSITIVE, 0);
				break;
			}
			i++;
		}
	}
}
#endif /* end of LIN_PROTOCOL == PROTOCOL_20 or LIN_PROTOCOL == PROTOCOL_J2602 */


#if LIN_PROTOCOL == PROTOCOL_21

void lin_diagservice_assign_frame_id_range
(
    /* [IN] interface name */
    l_ifc_handle iii
)
{
    const lin_configuration* conf;
    l_s8 j, i = 0;
    l_u8 start_index;
    l_u8 cfg_frame_num = 0;
    lin_tl_pdu_data *lin_tl_pdu;
    /* Multi frame support */
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
    l_u16 length;
    l_u8 NAD, data[10];
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
    /* Get current configuration */
    conf = &lin_ifc_configuration[iii];
    /* Do actions only for slave nodes */
    if (conf->function == _SLAVE_)
    {
        /* Multi frame support */
    #if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
        /* receive message data */
        ld_receive_message(iii, &length, &NAD, data+2);

        lin_tl_pdu = (lin_tl_pdu_data *)data;
    #else /* Single frame support */
        /* Get current PDU pointer of RX queue */
        lin_tl_pdu = (lin_tl_pdu_data *)&conf->response_buffer[1];
    #endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */

        /* Get start index in request */
        start_index = (*lin_tl_pdu)[3];

        /* Find the number of configurable frame */
        i = 1;
        while (0xFFFF != (conf->configuration_ROM)[i])
        {
            i++;
            cfg_frame_num++;
        }
        /* Check request validity */
        for (i = 7, j = start_index+4; j > start_index; i--, j-- )
        {
            if ((0xFF != (*lin_tl_pdu)[i]) && (j > cfg_frame_num))
            {
                lin_tl_make_slaveres_pdu(iii, SERVICE_ASSIGN_FRAME_ID_RANGE, NEGATIVE, GENERAL_REJECT);
                return;
            }
        }

        /* Store PIDs */
        for (i = 4, j = 1; i < 8; i++, j++)
        {
            switch ((*lin_tl_pdu)[i])
            {
                case 0x00:
                    /* Unassign frame */
                    (conf->configuration_RAM)[start_index + j] = 0xFF;
                    break;

                case 0xFF:
                    /* keep the previous assigned value of this frame */
                    break;

                default:
                    /* Calculate frame ID and Assign ID to frame */
                    (conf->configuration_RAM)[start_index + j] = lin_process_parity((*lin_tl_pdu)[i], CHECK_PARITY);
                    break;
            }
        } /* End of for statement */
        lin_tl_make_slaveres_pdu(iii, SERVICE_ASSIGN_FRAME_ID_RANGE, POSITIVE, 0);
    }
}
#endif /* End (LIN_PROTOCOL == PROTOCOL_21) */

#if LIN_PROTOCOL != PROTOCOL_J2602
/*FUNCTION**********************************************************************
 *
 * Function Name : lin_condittional_change_nad
 * Description   :
 *
 *END**************************************************************************/
void lin_condittional_change_nad(l_ifc_handle iii)
{
    l_u8 id, byte, mask, invert;
    const lin_configuration* conf;
    lin_node_attribute* node_conf;
    lin_tl_descriptor *tl_conf;
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
    lin_transport_layer_queue *rx_queue;
#else /* Single frame support */
    lin_tl_pdu_data *lin_tl_pdu;
#endif
    /* Get current configuration */
    conf = &lin_ifc_configuration[iii];

    /* Do actions only for slave nodes */
    if (conf->function == _SLAVE_)
    {
        /* Get TL description */
        tl_conf = conf->tl_desc;
        /* Get the node attribute */
        node_conf = conf->node_attribute;

    #if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
        /* Get receive queue */
        rx_queue = tl_conf->tl_rx_queue;
        id = rx_queue->tl_pdu[rx_queue->queue_header][3];
        byte = rx_queue->tl_pdu[rx_queue->queue_header][4];
        mask = rx_queue->tl_pdu[rx_queue->queue_header][5];
        invert = rx_queue->tl_pdu[rx_queue->queue_header][6];
    #else /* Single frame support */
        /* Get current PDU pointer of RX buffer */
        lin_tl_pdu = tl_conf->tl_current_rx_pdu_ptr;
        id         = (*lin_tl_pdu)[3];
        byte     = (*lin_tl_pdu)[4];
        mask      = (*lin_tl_pdu)[5];
        invert     = (*lin_tl_pdu)[6];
    #endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */

        /* Possible positive ID */
        /* Support only identifier 0 for LIN Product Identification */
        if (id == 0)
        {
            if(byte>0 && byte<6)
            {
                /*Byte 1: Supplier ID LSB; Byte 2: Supplier ID MSB*/
                if(byte>0 && byte<3)
                {
                    byte = (node_conf->product_id).supplier_id >> ((byte-1)*8);
                }
                /*Byte 3: Function ID LSB; Byte 4: Function ID MSB*/
                else if(byte>2 && byte<5)
                {
                    byte = (node_conf->product_id).function_id >> ((byte-3)*8);
                }
                /* Byte 5: Variant */
                else
                {
                    byte = (node_conf->product_id).variant;
                }
                /* Do a bitwise XOR with Invert and Do a bitwise AND with Mask */
                byte = (byte^invert)&mask;
                /* If the final result is zero, then give positive response*/
                if (byte == 0)
                {
                    lin_tl_make_slaveres_pdu(iii,SERVICE_CONDITIONAL_CHANGE_NAD, POSITIVE, 0);
                    /* If the final result is zero then change the NAD to New NAD */
                    #if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
                        node_conf->configured_NAD = rx_queue->tl_pdu[rx_queue->queue_header][7];
                    #else/* Single frame support */
                        node_conf->configured_NAD = (*lin_tl_pdu)[7];
                    #endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
                }
            }
        }
    }
}
#endif /* End LIN_PROTOCOL != PROTOCOL_J2602 */

#if LIN_PROTOCOL == PROTOCOL_J2602
void lin_diagservice_target_reset
(
    /* [IN] interface name */
    l_ifc_handle iii
)
{
    const lin_configuration *conf;
    lin_tl_descriptor *tl_conf;
    lin_tl_pdu_data *pdu;
    l_u8 i;
    l_u16 *byte_offset_temp_ptr;
    l_u8 *bit_offset_temp_ptr;
    lin_node_attribute *node_att_ptr;
    l_u8 nad;

    /* Get current configuration */
    conf = &lin_ifc_configuration[iii];
    node_att_ptr = conf->node_attribute;

    /* Get TL configuration */
    tl_conf = conf->tl_desc;

    /* Get PDU from RX queue */

    /* Get current PDU pointer of RX queue */
    pdu = (lin_tl_pdu_data *)&conf->response_buffer[1];

    for (i = 0; i < node_att_ptr->num_frame_have_esignal; i++)
    {
        /* Set the reset flag within the J2602 Status Byte */
        byte_offset_temp_ptr = node_att_ptr->response_error_byte_offset_ptr + i;
        bit_offset_temp_ptr = node_att_ptr->response_error_bit_offset_ptr + i;
        /* Set error signal to 0x01 means "Reset" */
        lin_pFrameBuf[*byte_offset_temp_ptr] = (l_u8)((lin_pFrameBuf[*byte_offset_temp_ptr] & (~(0x07U << (*bit_offset_temp_ptr)))) |
                                                    (0x01U << (*bit_offset_temp_ptr)));
    }
    /* Create positive response */

    /* Get NAD of node */
    nad = (*pdu)[0];

    if (LD_BROADCAST != nad)
    {
        lin_tl_make_slaveres_pdu(iii, SERVICE_TARGET_RESET, POSITIVE, 0);
    }
    else
    {
        tl_conf->tl_slaveresp_cnt = 0;
    }
}



/*FUNCTION**********************************************************************
 *
 * Function Name : ld_assign_NAD_j2602
 * Description   : This function assigns NAD of a J2602 slave device based on input
 *                 dnn. NAD is (0x60 + dnn).
 *
 * Implements    : ld_assign_NAD_j2602_Activity
 *END**************************************************************************/
l_bool ld_assign_NAD_j2602(l_ifc_handle iii,
                           l_u8 dnn)
{
    const lin_configuration *conf;
    lin_node_attribute *node_att_ptr;
    l_bool ret_val = 1U;

    /* Get current configuration */
    conf = &lin_ifc_configuration[iii];
    node_att_ptr = conf->node_attribute;

    if ((conf->function == (l_bool)_SLAVE_) && (conf->lin_protocol_version == LIN_PROTOCOL_J2602))
    {
        node_att_ptr = conf->node_attribute;
        if (dnn <= 0xFU)
        {
            node_att_ptr->configured_NAD = (l_u8)(0x60U + dnn);
            ret_val = 0U;
        }
    }

    return ret_val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : ld_reconfig_msg_ID
 * Description   : This function reconfigures frame identifiers of a J2602 slave node
 *                 based on input dnn. This function is for slave nodes only.
 *
 * Implements    : ld_reconfig_msg_ID_Activity
 *END**************************************************************************/
l_bool ld_reconfig_msg_ID(l_ifc_handle iii,
                          l_u8 dnn)
{
    const lin_configuration *conf;
    l_u8 number_of_configurable_frames;
    l_u8 i;
    l_bool ret_val = 1U;

    /* Get current configuration */
    conf = &lin_ifc_configuration[iii];
    /* Get number of configurable_frames not calculate id 0x3C and 0x3D */
    number_of_configurable_frames = (l_u8)(conf->num_of_frames - 2);
    i = number_of_configurable_frames - 1;

    for(; i >= 0; i--)
    {
        if(conf->frame_tbl[i].frm_type == LIN_FRM_UNCD)
        {
            break;
        }
        else
        {
            number_of_configurable_frames--;
        }
    }

    /* Check if this interface is a LIN Slave and the protocol is J2602 */
    if ((conf->function == _SLAVE_) && (conf->lin_protocol_version == LIN_PROTOCOL_J2602))
    {
        if (dnn <= 0xDU)
        {
            /* number of configurable frames greater than 16 */
            if (number_of_configurable_frames > 16U)
            {
                /* Only 0x60 is valid NAD */
                /* Do nothing */
            }
            /* number of configurable frames is from 9 - 16 */
            else if (number_of_configurable_frames > 8U)
            {
                /* Only NAD 0x60, 0x64, 0x68 are valid, 0x6C and 0x6D not valid */
                if ((dnn == 0U) || (dnn == 4U) || (dnn == 8U))
                {
                    ret_val = ld_change_msg_id(iii, dnn, 16U);
                }
            }
            /* number of configurable frames is from 5 - 8 */
            else if (number_of_configurable_frames > 4U)
            {
                /* Check to verify if dnn is 0x60, 0x62, 0x64, 0x66, 0x68, 0x6A, 0x6C */
                if ((dnn % 2U) == 0U)
                {
                    ret_val = ld_change_msg_id(iii, dnn, 8U);
                }
            }
            /* number of configurable frames is from 1 - 4 */
            else
            {
                ret_val = ld_change_msg_id(iii, dnn, 4U);
            }
        }
    }

    return ret_val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : ld_change_msg_id
 * Description   : This function reconfigures frame identifiers of a J2602 slave node
 *                 based on input dnn and frame_id_change.
 *
 * Implements    : ld_change_msg_id_Activity
 *END**************************************************************************/
static l_bool ld_change_msg_id(l_ifc_handle iii,
                               l_u8 dnn,
                               l_u8 frame_id_change)
{
    const lin_configuration *conf;
    l_u8 number_of_configurable_frames;
    l_u8 i;
    l_u8 id_origin;

    /* Get current configuration */
    conf = &lin_ifc_configuration[iii];
    number_of_configurable_frames = conf->num_of_frames;
    /* If new DNN is greater than current DNN */
    for (i = number_of_configurable_frames; i > 0U; i--)
    {
        /* For non-broadcast frame identifiers  less than or equal to 0x37 */
        if (conf->configuration_RAM[i] <= 0x37U)
        {
            /* get id with dnn equal 0 */
            id_origin = (l_u8)(conf->configuration_RAM[i] % frame_id_change);
            conf->configuration_RAM[i] = (l_u8)(id_origin + (l_u8)(dnn << 2));
        }
        /* For broad cast message ID */
        if ((conf->configuration_RAM[i] <= 0x3BU) && (conf->configuration_RAM[i] >= 0x38U))
        {
            if ((dnn  >= 8U) &&
                ((conf->configuration_RAM[i] == 0x38U) || (conf->configuration_RAM[i] == 0x3AU)))
            {
                conf->configuration_RAM[i] += 1U;
            }
            else if ((dnn  < 8U) &&
                     ((conf->configuration_RAM[i] == 0x39U) || (conf->configuration_RAM[i] == 0x3BU)))
            {
                conf->configuration_RAM[i] -= 1U;
            }
        }
    }

    return (l_bool)0U;
}
#endif /* End (LIN_PROTOCOL == PROTOCOL_J2602) */
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
l_u8 diag_get_flag(
    /* [IN] interface name */
    l_ifc_handle iii,
    /* [IN] flag order */
    l_u8 flag_order)
{
    lin_configuration *conf;
    lin_tl_descriptor *tl_conf;
    l_u8              *service_flag;

    /* Get current configuration */
    conf = (lin_configuration *) &lin_ifc_configuration[iii];
    /* Get TL configuration */
    tl_conf = conf->tl_desc;
    service_flag = tl_conf->tl_service_flags;

    if (flag_order >= tl_conf->number_support_sid)
    {
        return 0;
    }
    else
    {
        return (l_u8) service_flag[flag_order];
    }

}

void diag_clear_flag(l_ifc_handle iii, l_u8 flag_order)
{
    lin_configuration *conf;
    lin_tl_descriptor *tl_conf;
    l_u8              *service_flag;

    /* Get current configuration */
    conf = (lin_configuration *) &lin_ifc_configuration[iii];
    /* Get TL configuration */
    tl_conf = conf->tl_desc;
    service_flag = tl_conf->tl_service_flags;

    if (flag_order < tl_conf->number_support_sid)
    {
        service_flag[flag_order] = 0;
    }
}
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */

#endif  /* End (LIN_MODE == _MASTER_MODE_) */
/* ---------------- End of code for Multi Interface ----------------- */
/**
 * @}
 */
