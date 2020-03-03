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
* @file      lin_diagnostic_service.h
*
* @author    FPT Software
*
* @brief     diagnostic service
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20090407     v1.0    First version
 *
 *****************************************************************************/

#ifndef _LIN_DIAGNOSTIC_SERVICE_H
#define _LIN_DIAGNOSTIC_SERVICE_H

#include "lin.h"
#if LIN_MODE == _SLAVE_MODE_
/* Unuse for GPIO */
#if (_LIN_GPIO_ == 0) && !defined(_MC9S08SC4_H)&& !defined(MCU_SKEAZN84)
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_diagservice_read_by_identifier ( void )
* @brief process read by identifier request, and also prepare its response data
*
*
* @return #void
*
* @SDD_ID LIN_SDD_360
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>id</I>
*   -# <B>#l_u16</B> <I>supid</I>
*   -# <B>#l_u16</B> <I>fid</I>
*
* @static_global_var
*   -# <B>#tl_current_rx_pdu_ptr</B>
*   -# <B>#product_id</B>
*   -# <B>#tl_slaveresp_cnt</B>
*
* @details
*   This function to process read by identifier request, and also prepare its response data<BR>
*   This function is only for Slave Node<BR>
*   Required: Mandatory<BR>
*   For LIN 2.1 and 2.0 <BR>
*
* @see  #lin_tl_make_slaveres_pdu
*//*END*----------------------------------------------------------------------*/
void lin_diagservice_read_by_identifier(void);

#if LIN_PROTOCOL == PROTOCOL_21

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_diagservice_assign_frame_id_range ( void )
* @brief process assign frame id range request, and also prepare its response data
*
*
* @return #void
*
* @SDD_ID LIN_SDD_359
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>start_index</I>
*   -# <B>#l_s8</B> <I>i</I>
*   -# <B>#l_s8</B> <I>j</I>
*
* @static_global_var
*   -# <B>#tl_current_rx_pdu_ptr</B>
*   -# <B>#lin_configuration_RAM</B>
*
* @details
*   This function to process assign frame id range request, and also prepare its response data.
*   This function is only for Slave Node.
*   Required: Mandatory.
*   For LIN 2.1
*
* @see  #lin_tl_make_slaveres_pdu
* @see  #lin_process_parity
*//*END*----------------------------------------------------------------------*/
void lin_diagservice_assign_frame_id_range(void);


/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_diagsrv_functional_service ( void )
* @brief process functional request
*
*
* @return #void
*
* @SDD_ID LIN_SDD_
* @endif
*
* @local_var
*   -# <B>#l_u16</B> <I>length</I>
*   -# <B>#l_u8</B> <I>data[]</I>
*
* @static_global_var
*
* @details
*   This function to process functional request. Slave do not response when receive a functional request
* @see  #ld_receive_message
*//*END*----------------------------------------------------------------------*/
void lin_diagsrv_functional_service(void);
#endif /* End (LIN_PROTOCOL == PROTOCOL_21) */

#if LIN_PROTOCOL != PROTOCOL_J2602
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_condittional_change_nad ( void )
* @brief process functional request
*
*
* @return #void
*
* @SDD_ID LIN_SDD_
* @endif
*
* @local_var
*   -# <B>#l_u16</B> <I>length</I>
*   -# <B>#l_u8</B> <I>data[]</I>
*
* @static_global_var
*
* @details
*   This function to process functional request. Slave do not response when receive a functional request
* @see  #ld_receive_message
*//*END*----------------------------------------------------------------------*/
void lin_condittional_change_nad(void);
#else
/*FUNCTION*--------------------------------------------------------------*//**
* @fn l_bool ld_assign_NAD_j2602(l_u8 dnn)
* @brief This function assigns NAD of a J2602 slave device based on input dnn
*
*
* @return #l_bool
*
* @SDD_ID LIN_SDD_
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>ret_val</I>
*
* @static_global_var
*
* @details
*   This function assigns NAD of a J2602 slave device based on input dnn
* @see  #ld_assign_NAD_j2602
*//*END*----------------------------------------------------------------------*/
l_bool ld_assign_NAD_j2602(l_u8 dnn);
/*FUNCTION*--------------------------------------------------------------*//**
* @fn l_bool ld_reconfig_msg_ID(l_u8 dnn)
* @brief This function reconfigures frame identifiersof a J2602 slave device
*        based on input dnn
*
* @return #l_bool
*
* @SDD_ID LIN_SDD_
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>ret_val</I>
*
* @static_global_var
*
* @details
*   This function reconfigures frame identifiers of a J2602 slave node
*   based on input dnn. This function is for slave nodes only.
* @see  #ld_reconfig_msg_ID
*//*END*----------------------------------------------------------------------*/
l_bool ld_reconfig_msg_ID(l_u8 dnn);
#endif /* End LIN_PROTOCOL != PROTOCOL_J2602 */

#if ((LIN_PROTOCOL == PROTOCOL_20) || (LIN_PROTOCOL == PROTOCOL_J2602))
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_diagservice_assign_frame_identifier ( void )
* @brief process functional request
*
*
* @return #void
*
* @SDD_ID LIN_SDD_
* @endif
*
* @local_var
*   -# <B>#l_u16</B> <I>length</I>
*   -# <B>#l_u8</B> <I>data[]</I>
*
* @static_global_var
*
* @details
*   If the id in master request frame has already exist for another frame(which have different message ID)
*   in master request frame, the slave doesn't send response.
*   This function to process functional request. Slave does not response when receive a functional request
* @see  #lin_diagservice_assign_frame_identifier
*//*END*----------------------------------------------------------------------*/
void lin_diagservice_assign_frame_identifier(void);
#endif /* End of LIN_PROTOCOL == PROTOCOL_20 or LIN_PROTOCOL == PROTOCOL_J2602 */


#if LIN_PROTOCOL == PROTOCOL_J2602

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_diagservice_target_reset ( void )
* @brief process read by identifier request, and also prepare its response data
*
*
* @return #void
*
* @SDD_ID LIN_SDD_361
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>*signal_data_ptr</I>
*   -# <B>#l_u8</B> <I>nad</I>
*
* @static_global_var
*   -# <B>#tl_current_rx_pdu_ptr</B>
*   -# <B>#tl_slaveresp_cnt</B>
*
* @details
*   This function to process read by identifier request, and also prepare its response data<BR>
*   and Reset the Slave Node <BR>
*   This function is only for Slave Node<BR>
*   Required: Mandatory<BR>
*   For J2602
*
* @see  #lin_tl_make_slaveres_pdu
*//*END*----------------------------------------------------------------------*/
void lin_diagservice_target_reset(void);
#endif /* End (LIN_PROTOCOL == PROTOCOL_J2602) */
#endif /* End (_LIN_GPIO_ == 0) && !defined(_MC9S08SC4_H) */

#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
/* get diagnostic flag */
/*FUNCTION*--------------------------------------------------------------*//**
 * @fn l_u8 diag_get_flag(l_u8 flag_order)
 * @brief Get flag status of diagnostic service
 *
 * @param flag_order <B>[IN]</B> Order of service flag
 *
 * @return #l_u8
 *
 * @local_var
 *   -# <B>#lin_configuration</B> <I>*conf</I>
 *
 * @SDD_ID LIN_SDD_
* @endif
 *
 *
 * @static_global_var
 *   -# <B>#lin_ifc_configuration</B>
 *
 * @details
 * This function will return flag of diagnostic service, if lin node receive master request or slave response
 *//*END*----------------------------------------------------------------------*/
l_u8 diag_get_flag(l_u8 flag_order);
/*FUNCTION*--------------------------------------------------------------*//**
 * @fn void diag_clear_flag(l_u8 flag_order)
 * @brief Clear flag status of diagnostic service
 *
 * @param flag_order <B>[IN]</B> Order of service flag
 *
 * @return #void
 *
 * @local_var
 *   -# <B>#lin_configuration</B> <I>*conf</I>
 *
 * @SDD_ID LIN_SDD_
* @endif
 *
 *
 * @static_global_var
 *   -# <B>#lin_ifc_configuration</B>
 *
 * @details
 * This function will clear flag of diagnostic service, if lin node receive master request or slave response
 *//*END*----------------------------------------------------------------------*/
void diag_clear_flag(l_u8 flag_order);
#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)*/
#endif /* LIN_MODE == _SLAVE_MODE_ */

#if LIN_MODE == _MASTER_MODE_
#if LIN_PROTOCOL == PROTOCOL_21
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_diagservice_assign_frame_id_range ( l_ifc_handle iii )
* @brief process assign frame id range request, and also prepare its response data
*
* @param iii <B>[IN]</B> interface name
*
* @return #void
*
* @SDD_ID LIN_SDD_356
* @endif
*
* @local_var
*   -# <B>#const lin_configuration</B> <I>conf</I>
*   -# <B>#lin_tl_descriptor</B> <I>tl_conf</I>
*   -# <B>#l_s8</B> <I>i</I>
*   -# <B>#l_s8</B> <I>j</I>
*   -# <B>#l_u8</B> <I>start_index</I>
*   -# <B>#l_u8</B> <I>cfg_frame_num</I>
*   -# <B>#lin_tl_pdu_data</B> <I>*lin_tl_pdu</I>
*
* @static_global_var
*   -# <B>#lin_ifc_configuration</B>
*
* @details
*   This function to process assign frame id range request, and also prepare its response data
*   This function is only for Slave Node
*   Required: Mandatory
*   For LIN 2.1
*
* @see  #lin_tl_make_slaveres_pdu
* @see  #lin_process_parity
*//*END*----------------------------------------------------------------------*/
void lin_diagservice_assign_frame_id_range(l_ifc_handle iii);
#endif /* end of LIN_PROTOCOL == PROTOCOL_21*/

#if LIN_PROTOCOL != PROTOCOL_J2602
/*!
 * @brief Process Conditional Change NAD request
 *
 * @param iii Interface name
 * @return void
 */
void lin_condittional_change_nad(l_ifc_handle iii);
#endif /* End LIN_PROTOCOL != PROTOCOL_J2602 */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_diagservice_read_by_identifier ( l_ifc_handle iii )
* @brief process assign frame id range request, and also prepare its response data
*
* @param iii <B>[IN]</B> interface name
*
* @return #void
*
* @SDD_ID LIN_SDD_357
* @endif
*
* @local_var
*   -# <B>#const lin_configuration</B> <I>*conf</I>
*   -# <B>#const lin_node_attribute</B> <I>*node_conf</I>
*   -# <B>#lin_product_id</B> <I>node_conf</I>
*   -# <B>#lin_tl_descriptor</B> <I>*tl_conf</I>
*   -# <B>#lin_tl_pdu_data</B> <I>*lin_tl_pdu</I>
*   -# <B>#l_u8</B> <I>id</I>
*   -# <B>#l_u16</B> <I>supid</I>
*   -# <B>#l_u16</B> <I>fid</I>
*
* @static_global_var
*   -# <B>#lin_ifc_configuration</B>
*
* @details
*   This function to process read by identifier request, and also prepare its response data
*   This function is only for Slave Node
*   Required: Mandatory
*   For LIN 2.1 and 2.0
*
* @see  #lin_tl_make_slaveres_pdu
*//*END*----------------------------------------------------------------------*/
void lin_diagservice_read_by_identifier(l_ifc_handle iii);

#if ((LIN_PROTOCOL == PROTOCOL_20) || (LIN_PROTOCOL == PROTOCOL_J2602))
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_diagservice_assign_frame_identifier ( void )
* @brief process functional request
*
*
* @return #void
*
* @SDD_ID LIN_SDD_
* @endif
*
* @local_var
*   -# <B>#l_u16</B> <I>length</I>
*   -# <B>#l_u8</B> <I>data[]</I>
*
* @static_global_var
*
* @details
*   If the id in master request frame has already exist for another frame(which have different message ID)
*   in master request frame, the slave doesn't send response.
*   This function to process functional request. Slave does not response when receive a functional request
* @see  #ld_receive_message
*//*END*----------------------------------------------------------------------*/
void lin_diagservice_assign_frame_identifier(l_ifc_handle iii);
#endif /* End of LIN_PROTOCOL == PROTOCOL_20 or LIN_PROTOCOL == PROTOCOL_J2602 */
/* J2602 */
#if LIN_PROTOCOL == PROTOCOL_J2602

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_diagservice_target_reset ( l_ifc_handle iii )
* @brief process read by identifier request, and also prepare its response data
*
* @param iii <B>[IN]</B> interface name
*
* @return #void
*
* @SDD_ID LIN_SDD_358
* @endif
*
* @local_var
*   -# <B>#const lin_configuration</B> <I>*conf</I>
*   -# <B>#lin_tl_descriptor1</B> <I>*tl_conf</I>
*   -# <B>#lin_tl_pdu_data</B> <I>*pdu</I>
*   -# <B>#l_u8</B> <I>*signal_data_ptr</I>
*   -# <B>#l_u8</B> <I>*nad</I>
*
* @static_global_var
*   -# <B>#lin_ifc_configuration</B>
*   -# <B>#lin_tl_pdu</B>
*
* @details
*   This function to process read by identifier request, and also prepare its response data
*   and Reset the Slave Node
*   This function is only for Slave Node
*   Required: Mandatory
*   For J2602
*
* @see  #lin_tl_make_slaveres_pdu
*//*END*----------------------------------------------------------------------*/
void lin_diagservice_target_reset(l_ifc_handle iii);
/*FUNCTION*--------------------------------------------------------------*//**
* @fn l_bool ld_assign_NAD_j2602(l_ifc_handle iii, l_u8 dnn)
* @brief This function assigns NAD of a J2602 slave device based on input dnn
*
*
* @return #l_bool
*
* @SDD_ID LIN_SDD_
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>ret_val</I>
*
* @static_global_var
*
* @details
*   This function assigns NAD of a J2602 slave device based on input dnn
* @see  #ld_assign_NAD_j2602
*//*END*----------------------------------------------------------------------*/
l_bool ld_assign_NAD_j2602(l_ifc_handle iii, l_u8 dnn);
/*FUNCTION*--------------------------------------------------------------*//**
* @fn l_bool ld_reconfig_msg_ID(l_ifc_handle iii, l_u8 dnn)
* @brief This function reconfigures frame identifiersof a J2602 slave device
*        based on input dnn
*
* @return #l_bool
*
* @SDD_ID LIN_SDD_
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>ret_val</I>
*
* @static_global_var
*
* @details
*   This function reconfigures frame identifiers of a J2602 slave node
*   based on input dnn. This function is for slave nodes only.
* @see  #ld_reconfig_msg_ID
*//*END*----------------------------------------------------------------------*/
l_bool ld_reconfig_msg_ID(l_ifc_handle iii, l_u8 dnn);
#endif /* end of LIN_PROTOCOL == PROTOCOL_J2602*/

#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)
/* get diagnostic flag */
/*FUNCTION*--------------------------------------------------------------*//**
 * @fn l_u8 diag_get_flag(l_ifc_handle iii, l_u8 flag_order)
 * @brief Get flag status of diagnostic service
 *
 * @param iii <B>[IN]</B> lin interface handle
 * @param flag_order <B>[IN]</B> Order of service flag
 *
 * @return #l_u8
 *
 * @local_var
 *   -# <B>#lin_configuration</B> <I>*conf</I>
 *
 * @SDD_ID LIN_SDD_
* @endif
 *
 *
 * @static_global_var
 *   -# <B>#lin_ifc_configuration</B>
 *
 * @details
 * This function will return flag of diagnostic service, if lin node receive master request or slave response
 *//*END*----------------------------------------------------------------------*/
l_u8 diag_get_flag(l_ifc_handle iii,l_u8 flag_order);
/*FUNCTION*--------------------------------------------------------------*//**
 * @fn void diag_clear_flag(l_ifc_handle iii, l_u8 flag_order)
 * @brief Clear flag status of diagnostic service
 *
 * @param iii <B>[IN]</B> lin interface handle
 * @param flag_order <B>[IN]</B> Order of service flag
 *
 * @return #void
 *
 * @local_var
 *   -# <B>#lin_configuration</B> <I>*conf</I>
 *
 * @SDD_ID LIN_SDD_
* @endif
 *
 *
 * @static_global_var
 *   -# <B>#lin_ifc_configuration</B>
 *
 * @details
 * This function will clear flag of diagnostic service, if lin node receive master request or slave response
 *//*END*----------------------------------------------------------------------*/
void diag_clear_flag(l_ifc_handle iii,l_u8 flag_order);

#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */

#endif /* End (LIN_MODE == _MASTER_MODE_) */

#endif /* _LIN_DIAGNOSTIC_SERVICE_H */
/* End of definition if _LIN_DIAGNOSTIC_SERVICE_H */
/** @} */
