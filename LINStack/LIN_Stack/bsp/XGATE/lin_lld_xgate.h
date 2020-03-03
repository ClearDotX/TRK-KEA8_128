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
* @file      bsp/XGATE/lin_lld_xgate.h
*
* @author    FPT Software
*
* @brief     XGATE low level header file
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20090407     v1.0    First version
 *
 *****************************************************************************/

#ifndef _LIN_LLD_XGATE_H
#define _LIN_LLD_XGATE_H

#include "lin.h"
#include "lin_cfg.h"
#include "lin_hw_cfg.h"
#include "reg_s12x.h"
#include "xgate.h"

/**
* @var typedef l_u16 sci_channel_name
* name of sci channel
*/
typedef l_u16 sci_channel_name;

/*** Vector interrupt ***/

#define SOFTWARETRIGGER0_VEC  0x72  /**< Software trigger , vector address= 2 * channel id */


#define SCI0_VEC  0xD6              /**< SCI0 interrupt vector vector address= $xxD6 */

#define SCI1_VEC  0xD4      /**< SCI1 interrupt vector */

#define SCI2_VEC  0x8A      /**< SCI2 interrupt vector */

#define SCI3_VEC  0x88      /**< SCI3 interrupt vector */

#define SCI4_VEC  0x86      /**< SCI4 interrupt vector */

#define SCI5_VEC  0x84      /**< SCI5 interrupt vector */



#define PIT0_VEC  0x7A      /**< PIT0 interrupt vector */

/*** Macros ***/
/** @def ROUTE_INTERRUPT(vec_adr, cfdata)
* route interrupt
*/
#define ROUTE_INTERRUPT(vec_adr, cfdata)                \
  INT_CFADDR= (vec_adr) & 0xF0;                         \
  INT_CFDATA_ARR[((vec_adr) & 0x0F) >> 1]= (cfdata)

/** @def XLIN_REQ(channel, req)
* xlin request
*/
#define XLIN_REQ(channel, req)              \
      lin_request.channel = (lin_hardware_name)channel;        \
      lin_request.task_request = (xtask_request)req


/*** Low level API ***/

#if (LIN_MODE == _SLAVE_MODE_)

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_setup_xgate ( )
* @brief This function performs setup of the XGATE module
*
* @return #void
*
* @SDD_ID LIN_SDD_190
* @endif
*
* @static_global_var
*   -# <B>#XGATE_VectorTable</B>
*
* @details
*   This function performs setup of the XGATE module
*
* @see  #ROUTE_INTERRUPT
*//*END*----------------------------------------------------------------------*/
void lin_lld_setup_xgate(void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_init (l_ifc_handle iii)
* @brief This function performs the initialization of SCI channel in the XGATE module
*
* @param iii <B>[IN]</B> LIN interface name
*
* @return #void
*
* @SDD_ID LIN_SDD_191
* @endif
*
* @local_var
*   -# <B>#l_u16</B> <I>tmp</I>
*
* @static_global_var
*   -# <B>#lin_request</B>
*   -# <B>#lin_interrupt</B>
*   -# <B>#ifc</B>
*   -# <B>#tbit</B>
*   -# <B>#pSCI</B>
*   -# <B>#response_buffer</B>
*   -# <B>#lin_lld_response_buffer</B>
*
* @details
*   This function performs the initialization of SCI channel in the XGATE module
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_init (l_ifc_handle iii);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_deinit ( )
* @brief This function performs the deinitialization of the XGATE module
*
* @return #void
*
* @SDD_ID LIN_SDD_192
* @endif
*
* @static_global_var
*   -# <B>#state</B>
*
* @details
*   This function performs the deinitialization of the XGATE module
*
* @see  #lin_lld_xgate_int_disable
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_deinit (void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_tx_wake_up ( )
* @brief This function sets SLIC module to low power mode
*
* @return #void
*
* @SDD_ID LIN_SDD_193
* @endif
*
* @static_global_var
*   -# <B>#state</B>
*   -# <B>#pSCI</B>
*   -# <B>#lin_request</B>
*   -# <B>#lin_hardware_name</B>
*
* @details
*   This function performs the following tasks: <BR>
*   Set task_request = XLIN_REQ_TX_HEADER <BR>
*   Write to XGSWT register to trigger software interrupt to XGATE
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_tx_wake_up (void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_int_enable ( )
* @brief This function enables SCI Interrupt with XGATE support
*
* @return #void
*
* @SDD_ID LIN_SDD_194
* @endif
*
* @static_global_var
*   -# <B>#state</B>
*   -# <B>#pSCI</B>
*
* @details
*   This function enables SCI Interrupt with XGATE support
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_int_enable (void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_int_disable ( )
* @brief This function disables SCI Interrupt with XGATE support
*
* @return #void
*
* @SDD_ID LIN_SDD_195
* @endif
*
* @static_global_var
*   -# <B>#state</B>
*   -# <B>#pSCI</B>
* @details
*   This function disables SCI Interrupt with XGATE support
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_int_disable (void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_ignore_response ( )
* @brief Set low level ignore flag lin_lld_ignore_flag
*
* @return #void
*
* @SDD_ID LIN_SDD_196
* @endif
*
* @static_global_var
*   -# <B>#lin_request</B>
*   -# <B>#lin_hardware_name</B>
* @details
*   Set low level ignore flag lin_lld_ignore_flag
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_ignore_response (void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_set_low_power_mode ( )
* @brief Request to enter low power mode in SCI Driver
*
* @return #void
*
* @SDD_ID LIN_SDD_197
* @endif
*
* @static_global_var
*   -# <B>#state</B>
* @details
*   Request to enter low power mode in SCI Driver
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_set_low_power_mode (void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_tx_response ( )
* @brief This function requests to send first data and set lin_lld_state to SEND_DATA
*
* @return #void
*
* @SDD_ID LIN_SDD_199
* @endif
*
* @static_global_var
*   -# <B>#lin_lld_response_buffer</B>
*   -# <B>#pid</B>
*   -# <B>#cnt_byte</B>
*   -# <B>#pSCI</B>
*   -# <B>#state</B>
* @details
*   This function requests to send first data and set lin_lld_state to SEND_DATA
*
* @see #lin_checksum
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_tx_response (void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_rx_response (l_u8  msg_length)
* @brief This function requests to receive response data of LIN frame via SCI channel
*
* @param msg_length <B>[IN]</B> Length of response data expect to wait
*
* @return #void
*
* @SDD_ID LIN_SDD_198
* @endif
*
* @static_global_var
*   -# <B>#lin_lld_response_buffer</B>
*   -# <B>#cnt_byte</B>
*   -# <B>#byte_rec</B>
*   -# <B>#state</B>
* @details
*   This function requests to receive response data of LIN frame via SCI channel
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_rx_response (l_u8 msg_length);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn l_u8 lin_lld_xgate_get_status ( )
* @brief Return the lin status of lin driver (ref lin_status struct)
*
* @return #l_u8
*
* @SDD_ID LIN_SDD_200
* @endif
*
* @static_global_var
*   -# <B>#l_status</B>
* @details
*   Return the lin status of lin driver (ref lin_status struct)
*
*//*END*----------------------------------------------------------------------*/
l_u8 lin_lld_xgate_get_status (void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn l_u8 lin_lld_xgate_get_state ( )
* @brief Return the lin state of lin driver
*
* @return #l_u8
*
* @SDD_ID LIN_SDD_201
* @endif
*
* @static_global_var
*   -# <B>#state</B>
* @details
*   Return the lin state of lin driver
*
*//*END*----------------------------------------------------------------------*/
l_u8 lin_lld_xgate_get_state(void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_timeout ( )
* @brief ISR for Outgoing timeout interrupt
*
* @return #void
*
* @SDD_ID LIN_SDD_202
* @endif
*
* @local_var
*   -# <B>#xlin_interrupt</B> <I>*lint_p</I>
*
* @static_global_var
*   -# <B>#lin_interrupt</B>
*   -# <B>#lin_lld_event_id</B>
* @details
*   ISR for Outgoing timeout interrupt
*
* @see #lin_pid_response_callback_handler
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_timeout(void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_isr ( )
* @brief ISR for Outgoing interrupt from XGATE
*
* @return #void
*
* @SDD_ID LIN_SDD_203
* @endif
*
* @local_var
*   -# <B>#xlin_interrupt</B> <I>*lint_p</I>
*   -# <B>#l_u16</B> <I>sem_mask</I>
*
* @static_global_var
*   -# <B>#lin_interrupt</B>
*   -# <B>#lin_lld_response_buffer</B>
*   -# <B>#response_buffer</B>
* @details
*   ISR for Outgoing interrupt from XGATE
*
* @see #lin_pid_response_callback_handler
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_isr (void);

#endif /* End (LIN_MODE == _SLAVE_MODE_) */

#if LIN_MODE == _MASTER_MODE_

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_setup_xgate ( )
* @brief This function performs setup of the XGATE module
*
* @return #void
*
* @SDD_ID LIN_SDD_118
* @endif
*
* @static_global_var
*   -# <B>#XGATE_VectorTable</B>
*
* @details
*   This function performs setup of the XGATE module
*
* @see  #ROUTE_INTERRUPT
*//*END*----------------------------------------------------------------------*/
void lin_lld_setup_xgate(void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_init (sci_channel_name  channel, l_ifc_handle iii)
* @brief This function performs the initialization of SCI channel in the XGATE module
*
* @param channel <B>[IN]</B> sci channel name
* @param iii <B>[IN]</B> LIN interface name
*
* @return #void
*
* @SDD_ID LIN_SDD_119
* @endif
*
* @local_var
*   -# <B>#l_u16</B> <I>tmp</I>
*   -# <B>#const lin_configuration</B> <I>*lconf_p</I>
*   -# <B>#register lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_ifc_configuration</B>
*   -# <B>#lin_request</B>
*   -# <B>#lin_interrupt</B>
*   -# <B>#lin_node_descrs</B>
*   -# <B>#lin_lld_response_buffer</B>
*
* @details
*   This function performs the initialization of SCI channel in the XGATE module
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_init (sci_channel_name  channel, l_ifc_handle iii);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_deinit (sci_channel_name  channel)
* @brief This function performs the deinitialization of the XGATE module
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_120
* @endif
*
* @local_var
*   -# <B>#register lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*
* @details
*   This function performs the deinitialization of the XGATE module
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_deinit (sci_channel_name  channel);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_tx_header (sci_channel_name  channel, l_u8  msg_id)
* @brief function performs the following tasks
*
* @param channel <B>[IN]</B> sci channel name
* @param msg_id <B>[IN]</B> pid to send out
*
* @return #void
*
* @SDD_ID LIN_SDD_121
* @endif
*
* @local_var
*   -# <B>#lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*
* @details
*   This function performs the following tasks:
*   Set task_request = XLIN_REQ_TX_HEADER
*   Set PID = msg_id
*   Write to XGSWT register to trigger software interrupt to XGATE
*
* @see  #lin_process_parity
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_tx_header (sci_channel_name  channel, l_u8  msg_id);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_tx_wake_up (sci_channel_name  channel )
* @brief function performs the following tasks
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_122
* @endif
*
* @local_var
*   -# <B>#lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*
* @details
*   This function performs the following tasks:
*   Set task_request = XLIN_REQ_SEND_WAKEUP
*   Write to XGSWT register to trigger software interrupt to XGATE
*
* @see  #XLIN_REQ
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_tx_wake_up (sci_channel_name  channel);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_int_enable (sci_channel_name  channel )
* @brief This function enables SCI Interrupt
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_123
* @endif
*
* @local_var
*   -# <B>#lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*
* @details
*   This function enables SCI Interrupt
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_int_enable (sci_channel_name  channel);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_int_disable (sci_channel_name  channel )
* @brief This function diables SCI Interrupt
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_124
* @endif
*
* @local_var
*   -# <B>#lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*
* @details
*   This function diables SCI Interrupt
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_int_disable (sci_channel_name  channel);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_ignore_response (sci_channel_name  channel )
* @brief Set lin_lld_xgate_task = LIN_LLD_XGATE_IGNORE_RESPONSE
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_125
* @endif
*
* @details
*   Set lin_lld_xgate_task = LIN_LLD_XGATE_IGNORE_RESPONSE
*   Write to XGSWT register to trigger software interrupt to XGATE
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_ignore_response (sci_channel_name  channel);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_set_low_power_mode (sci_channel_name  channel )
* @brief Request to enter low power mode in SCI Driver
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_126
* @endif
*
* @local_var
*   -# <B>#lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*
* @details
*   Request to enter low power mode in SCI Driver
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_set_low_power_mode (sci_channel_name  channel);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_tx_response (sci_channel_name  channel )
* @brief This function requests to send first data and set lin_lld_state to SEND_DATA
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_127
* @endif
*
* @local_var
*   -# <B>#lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*   -# <B>#lin_lld_response_buffer</B>
*
* @details
*   This function requests to send first data and set lin_lld_state to SEND_DATA
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_tx_response (sci_channel_name  channel);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_rx_response (sci_channel_name  channel, l_u8 msg_length)
* @brief This function requests to receive response data of LIN frame via SCI channel
*
* @param channel <B>[IN]</B> sci channel name
* @param msg_length <B>[IN]</B> length of message
*
* @return #void
*
* @SDD_ID LIN_SDD_128
* @endif
*
* @local_var
*   -# <B>#register lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*   -# <B>#lin_lld_response_buffer</B>
*   -# <B>#byte_rec</B>
*
* @details
*   This function requests to receive response data of LIN frame via SCI channel
*
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_rx_response (sci_channel_name  channel, l_u8 msg_length);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_get_status (sci_channel_name  channel )
* @brief Return the lin status of lin driver (ref lin_status struct)
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_129
* @endif
*
* @local_var
*   -# <B>#lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*
* @details
*   Return the lin status of lin driver (ref lin_status struct)
*
*//*END*----------------------------------------------------------------------*/
l_u8 lin_lld_xgate_get_status (sci_channel_name  channel);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_get_state (sci_channel_name  channel )
* @brief Return the lin state of lin driver
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_130
* @endif
*
* @local_var
*   -# <B>#lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*
* @details
*   Return the lin state of lin driver
*
*//*END*----------------------------------------------------------------------*/
l_u8 lin_lld_xgate_get_state(sci_channel_name  channel);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_timeout (  )
* @brief ISR for Outgoing timeout interrupt
*
* @return #void
*
* @SDD_ID LIN_SDD_131
* @endif
*
* @local_var
*   -# <B>#lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_interrupt</B>
*
* @details
*   ISR for Outgoing timeout interrupt
*
* @see #lin_pid_response_callback_handler
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_timeout(void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_xgate_isr (sci_channel_name  channel )
* @brief ISR for Outgoing interrupt from XGATE
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_132
* @endif
*
* @local_var
*   -# <B>#xlin_interrupt</B> <I>*lint_p</I>
*   -# <B>#l_u16</B> <I>sem_mask</I>
*
* @static_global_var
*   -# <B>#lin_interrupt</B>
*   -# <B>#l_ifc_handle</B>
*
* @details
*   ISR for Outgoing interrupt from XGATE
*
* @see #lin_pid_response_callback_handler
*//*END*----------------------------------------------------------------------*/
void lin_lld_xgate_isr (sci_channel_name  channel);

#endif /* End (LIN_MODE == _MASTER_MODE_) */

#endif  /* _LIN_LLD_XGATE_H */
/**
* @}
*/
