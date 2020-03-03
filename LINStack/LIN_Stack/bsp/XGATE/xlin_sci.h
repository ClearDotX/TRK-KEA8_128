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
* @file      bsp/XGATE/xlin_sci.h
*
* @author    FPT Software
*
* @brief     LIN SCI header functions in XGATE
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20090408     v1.0    First version
 *
 *****************************************************************************/

/* MODULE LIN_SCI IN XGATE. */
#ifndef _XLIN_SCI_H
#define _XLIN_SCI_H

#include "lin.h"
#include "reg_s12x.h"
#include "lin_cfg.h"
#include "lin_hw_cfg.h"

/* sci low level state */

#define IDLE                0x00        /**< Idle*/

#define SEND_BREAK          0x01        /**< Send break field */

#define SEND_PID            0x02        /**< Send PID */

#define RECV_SYN            0x03        /**< Receive synchronize */

#define RECV_PID            0x04        /**< Receive PIT */

#define IGNORE_DATA         0x05        /**< Ignore data */

#define RECV_DATA           0x06        /**< Receive data */

#define SEND_DATA           0x07        /**< Send data */

#define SEND_DATA_COMPLETED 0x08        /**< Send data completed */

#define PROC_CALLBACK       0x09        /**< Proc callback */

#define SLEEP_MODE          0x0A        /**< Sleep mode */

#define UNINIT              0xFF        /**< Uninit */

/**
* @enum xtask_request
* xgate tast request
*/
typedef enum {
    XLIN_REQ_GOTO_IDLE    /**< request goto idle */
} xtask_request;
#pragma DATA_SEG SHARED_DATA /* Define a share segment between XGATE and H12_CPU to store the code*/

/**
* @struct xlin_request
* xlin request
*/
typedef struct {
    lin_hardware_name channel;        /**< channel id */
    xtask_request task_request;       /**< request id */
    l_ifc_handle iii;                 /**< lin interface that mount to lin phy*/
} xlin_request;

/* lin_status struct */
/**
* @union lin_status
* lin status data structure
*/
typedef union {
    l_u8 byte;                        /**< the byte of union */
    struct
    {
        /* LIN 2.1 */
        l_u8 successful_transfer:1;     /**< Transfer flag */
        l_u8 error_in_response:1;       /**< Error response */
        l_u8 bus_activity:1;              /**< Bus activity timeout */
        /* J2602 */
        l_u8 framing_error:1;           /**< frame error flag */
        l_u8 checksum_error:1;          /**< checksum error flag */
        l_u8 readback_error:1;          /**< readback error in J2602 to be called Data Error */
        l_u8 parity_error:1;            /**< frame error flag */
        l_u8 reset:1;                   /**< reset flag (not implemented) */
    } bit;                            /**< 8 bits of union */
} lin_status;

/* lin status bit mask */
#define LIN_STA_SUCC_TRANSFER           1   /**< LIN status bit mask: success transfer */

#define LIN_STA_ERROR_RESP              2   /**< LIN status bit mask: error response */

#define LIN_STA_BUS_ACTIVITY            4   /**< LIN status bit mask: bus activity */

#define LIN_STA_FRAME_ERR               8   /**< LIN status bit mask: frame error */

#define LIN_STA_CHECKSUM_ERR            16  /**< LIN status bit mask: check sum error */

#define LIN_STA_READBACK_ERR            32  /**< LIN status bit mask: read back error */

#define LIN_STA_PARITY_ERR              64  /**< LIN status bit mask: parity error */

#define LIN_STA_RESET                   128 /**< LIN status bit mask: reset */


/* lin_node struct */
/**
* @struct lin_node
* lin node data structure
*/
#pragma align on
typedef struct {
    tSCI* pSCI;                 /**< pointer to the SCI peripheral */

    l_bool func;                /**< LIN Function : Master=0 or Slave=1 */
    l_u8 ifc;                   /**< LIN core interface number */

    l_u8 state;                 /**< LIN-SCI operational state */
    lin_status l_status;        /**< LIN status */

    l_u8 cnt_byte;              /**< Byte counter used when either transmit and receive data */
    l_u8 current_id;            /**< Current ID */

    l_u8 *ptr;                  /**< pointer to Data out/in */
    l_u8 *response_buffer;      /**< Frame data pointer */

    l_u16 pid;                   /**< PID to send out */
    l_u16 tbit;                  /**< Tbit */
    l_u16 frame_timeout_cnt;     /**< Frame timeout counter */
    l_u16 res_frame_timeout_cnt; /**< ResponseFrame timeout counter */
    l_u16 idle_timeout_cnt;     /**< Idle timeout counter */
} lin_node;
#pragma align off
#if (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_)

#endif /* End (_TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_) */
#pragma DATA_SEG SHARED_DATA /* Define a specific segment in XGATE memory map to store the code*/
/* xlin_interrupt */
/**
* @struct xlin_interrupt
* lin interrupt structure
*/
typedef struct {
    l_u8 ifc;                         /**< Lin core interface number */
    l_u8 current_pid;                 /**< Current PID */
    lin_lld_event_id event_id;        /**< Lin event identifier */
    l_u8 semaphore_id;                /**< Semaphore ID */
    lin_status l_status;              /**< Lin status */
} xlin_interrupt;
#pragma DATA_SEG DEFAULT /* Return to default data segment */

#if LIN_MODE == _SLAVE_MODE_
#pragma CODE_SEG XGATE_CODE /* Define a specific segment in XGATE memory map to store the data */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_outgoing_request (xlin_request* __restrict lreq_p)
* @brief receive request from s12x
*
* @param lreq_p <B>[IN]</B> request pointer
*
* @return #void
*
* @SDD_ID LIN_SDD_138
* @endif
*
* @details
*   receive request from s12x
*
* @see  #xlin_goto_idle_state
*//*END*----------------------------------------------------------------------*/
interrupt void lin_outgoing_request(xlin_request* __restrict lreq_p);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void ErrorHandler (int dataptr)
* @brief interrupt handler for all others
*
* @param dataptr <B>[IN]</B> data pointer
*
* @return #void
*
* @SDD_ID LIN_SDD_138
* @endif
*
* @local_var
*   -# <B>#int</B> <I>chanNum</I>
*
* @details
*   interrupt handler for all others
*
*//*END*----------------------------------------------------------------------*/
interrupt void ErrorHandler(int dataptr);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void xlin_sci_handler ( )
* @brief sci interrupt handler that control LIN communction
*
* @return #void
*
* @SDD_ID LIN_SDD_211
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>sci_flag_sr1</I>
*   -# <B>#l_u8</B> <I>tmp_byte</I>
*   -# <B>#l_u16</B> <I>t</I>
*   -# <B>#xlin_interrupt</B> <I>*lint_p</I>
*
* @static_global_var
*   -# <B>#lin_interrupt</B>
*   -# <B>#response_buffer</B>
*   -# <B>#lin_lld_response_buffer</B>
*   -# <B>#pSCI</B>
*   -# <B>#l_status</B>
*   -# <B>#frame_timeout_cnt</B>
*   -# <B>#lin_max_frame_res_timeout_val</B>
*   -# <B>#current_id</B>
*   -# <B>#cnt_byte</B>
*
* @details
*   sci interrupt handler that control LIN communction
*
* @see  #xlin_goto_idle_state
* @see  #xlin_process_parity
* @see  #_ssem
*//*END*----------------------------------------------------------------------*/
interrupt void xlin_sci_handler();

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void xlin_timer_handler ( )
* @brief timer interrupt handler that control LIN communction
*
* @return #void
*
* @SDD_ID LIN_SDD_212
* @endif
*
* @static_global_var
*   -# <B>#lin_virtual_ifc</B>
*
* @details
*   timer interrupt handler that control LIN communction
*
* @see  #xlin_sci_timeout
*//*END*----------------------------------------------------------------------*/
interrupt void xlin_timer_handler(void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void xlin_sci_timeout (l_u8 channel)
* @brief This function is called in period Tbit in order to check timeout for IDLE and MAXFRAME
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_205
* @endif
*
* @local_var
*   -# <B>#xlin_interrupt</B> <I>*lint_p</I>
*
* @static_global_var
*   -# <B>#lin_interrupt</B>
*   -# <B>#idle_timeout_cnt</B>
*   -# <B>#lin_channel</B>
*   -# <B>#l_status</B>
*   -# <B>#current_id</B>
*   -# <B>#frame_timeout_cnt</B>
*   -# <B>#current_id</B>
*   -# <B>#res_frame_timeout_cnt</B>
*
* @details
*   This function is called in period Tbit in order to check timeout for IDLE and MAXFRAME
*
* @see  #xlin_goto_idle_state
*//*END*----------------------------------------------------------------------*/
void xlin_sci_timeout(l_u8 channel);

/*XGATE FUNCTION*--------------------------------------------------------------*//**
* @fn void xlin_goto_idle_state ( )
* @brief Enter IDLE state
*
* @return #void
*
* @SDD_ID LIN_SDD_206
* @endif
*
* @static_global_var
*   -# <B>#idle_timeout_cnt</B>
*   -# <B>#state</B>
*
* @details
*   Enter IDLE state
*
*//*END*----------------------------------------------------------------------*/
void xlin_goto_idle_state(void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn l_u8 xlin_process_parity (l_u8 pid, l_u8 type)
* @brief Check parity and generate PID
*
* @param pid <B>[IN]</B> PID need to be send
* @param type <B>[IN]</B> check or generate
*
* @return #l_u8
*   <BR>pid if xlin_process_parity ok, otherwise return 0xFF
*
* @SDD_ID LIN_SDD_207
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>parity</I>
*   -# <B>#l_u8</B> <I>ret</I>
*
* @details
*   Check parity and generate PID
*    XGATE Module not use this routine
*
*//*END*----------------------------------------------------------------------*/
l_u8 xlin_process_parity(l_u8 pid, l_u8 type);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn l_u8 xlin_checksum (l_u8 *buffer, l_u8 raw_pid)
* @brief Calculate checksum byte
*
* @param *buffer <B>[IN]</B> pointer to buffer
* @param raw_pid <B>[IN]</B> pid
*
* @return #l_u8
*
* @SDD_ID LIN_SDD_208
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>length</I>
*   -# <B>#l_u16</B> <I>check_sum</I>
*
* @details
*   Calculate checksum byte
*
*//*END*----------------------------------------------------------------------*/
l_u8 xlin_checksum(l_u8 *buffer, l_u8 raw_pid);
#pragma CODE_SEG DEFAULT /* Return to default data segment */
#endif /* End (LIN_MODE == _SLAVE_MODE_) */

#if LIN_MODE == _MASTER_MODE_

#pragma CODE_SEG XGATE_CODE /* Define a specific segment in XGATE memory map to store the data */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_outgoing_request (xlin_request* __restrict lreq_p)
* @brief receive request from s12x
*
* @param lreq_p <B>[IN]</B> request pointer
*
* @return #void
*
* @SDD_ID LIN_SDD_138
* @endif
*
* @details
*   receive request from s12x
*
* @see  #xlin_sci_goto_idle_req
*//*END*----------------------------------------------------------------------*/
interrupt void lin_outgoing_request(xlin_request* __restrict lreq_p);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void ErrorHandler (int dataptr)
* @brief interrupt handler for all others
*
* @param dataptr <B>[IN]</B>  data pointer
*
* @return #void
*
* @SDD_ID LIN_SDD_138
* @endif
*
* @local_var
*   -# <B>#int</B> <I>chanNum</I>
*
* @details
*   interrupt handler for all others
*
*//*END*----------------------------------------------------------------------*/
interrupt void ErrorHandler(int dataptr);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void xlin_sci_handler (l_u8 channel)
* @brief sci interrupt handler that control LIN communction
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_140
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>sci_flag_sr1</I>
*   -# <B>#l_u8</B> <I>tmp_ifc</I>
*   -# <B>#l_u8</B> <I>tmp_byte</I>
*   -# <B>#l_u16</B> <I>t</I>
*   -# <B>#xlin_interrupt</B> <I>*lint_p</I>
*   -# <B>#register lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*   -# <B>#lin_interrupt</B>
*   -# <B>#lin_max_frame_res_timeout_val</B>
*   -# <B>#current_id</B>
*   -# <B>#lin_lld_response_buffer</B>
*
* @details
*   sci interrupt handler that control LIN communction
*
* @see  #xlin_goto_idle_state
* @see  #xlin_checksum
*//*END*----------------------------------------------------------------------*/
interrupt void xlin_sci_handler(l_u8 channel);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void xlin_timer_handler ( )
* @brief timer interrupt handler that control LIN communction
*
* @return #void
*
* @SDD_ID LIN_SDD_141
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>i</I>
*
* @static_global_var
*   -# <B>#lin_virtual_ifc</B>
*
* @details
*   timer interrupt handler that control LIN communction
*
* @see  #xlin_sci_timeout
*//*END*----------------------------------------------------------------------*/
interrupt void xlin_timer_handler(void);

/*XGATE FUNCTION*--------------------------------------------------------------*//**
* @fn void xlin_sci_goto_idle_req (xlin_request* lreq_p)
* @brief This function performs the initialization of SCI channel in the XGATE module
*
* @param lreq_p <B>[IN]</B>  request
*
* @return #void
*
* @SDD_ID LIN_SDD_133
* @endif
*
* @details
*   This function performs the initialization of SCI channel in the XGATE module
*
* @see #xlin_goto_idle_state
*//*END*----------------------------------------------------------------------*/
void xlin_sci_goto_idle_req(xlin_request* lreq_p);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void xlin_sci_timeout (l_u8  channel )
* @brief This function performs a request to go to IDLE state
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_134
* @endif
*
* @local_var
*   -# <B>#lin_node</B> <I>*lnode_p</I>
*   -# <B>#xlin_interrupt</B> <I>*lint_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*   -# <B>#lin_channel</B>
*   -# <B>#current_id</B>
*   -# <B>#idle_timeout_cnt</B>
*
* @details
*   This function performs a request to go to IDLE state
*
* @see  #xlin_goto_idle_state
*//*END*----------------------------------------------------------------------*/
void xlin_sci_timeout(l_u8  channel);

/*XGATE FUNCTION*--------------------------------------------------------------*//**
* @fn void xlin_goto_idle_state (l_u8  channel)
* @brief This function sets SLIC module to low power mode
*
* @param channel <B>[IN]</B> sci channel name
*
* @return #void
*
* @SDD_ID LIN_SDD_135
* @endif
*
* @local_var
*   -# <B>#lin_node</B> <I>*lnode_p</I>
*
* @static_global_var
*   -# <B>#lin_node_descrs</B>
*
* @details
*    Enter IDLE state
*
* @see  #clear_slic_int_flag
*//*END*----------------------------------------------------------------------*/
void xlin_goto_idle_state(l_u8 channel);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn l_u8 xlin_process_parity (l_u8 pid, l_u8 type)
* @brief Check parity and generate PID
*
* @param pid <B>[IN]</B> PID need to be send
* @param type <B>[IN]</B> check or generate
*
* @return #l_u8
*   <BR>pid if xlin_process_parity ok, otherwise return 0xFF
*
* @SDD_ID LIN_SDD_136
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>parity</I>
*   -# <B>#l_u8</B> <I>type</I>
*
* @details
*   Check parity and generate PID
*    XGATE Module not use this routine
*
*//*END*----------------------------------------------------------------------*/
l_u8 xlin_process_parity(l_u8 pid, l_u8 type);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void xlin_checksum (l_u8 *buffer, l_u8 raw_pid)
* @brief Calculate checksum byte
*
* @param buffer <B>[IN]</B> pointer to buffer
* @param raw_pid <B>[IN]</B> pid
*
* @return #void
*
* @SDD_ID LIN_SDD_137
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>length</I>
*   -# <B>#l_u16</B> <I>check_sum</I>
*
* @details
*   Calculate checksum byte
*
*//*END*----------------------------------------------------------------------*/
l_u8 xlin_checksum(l_u8 *buffer, l_u8 raw_pid);
#pragma CODE_SEG DEFAULT /* Return to default data segment */

#endif /* End (LIN_MODE == _SLAVE_MODE_) */

#endif
/**
* @}
*/
