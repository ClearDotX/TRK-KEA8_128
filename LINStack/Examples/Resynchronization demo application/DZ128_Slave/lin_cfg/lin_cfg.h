/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2016 Freescale Semiconductor, Inc.
* Copyright 2016-2019 NXP
* ALL RIGHTS RESERVED.
*
****************************************************************************//*!
*
* @file      lin_cfg.h
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Thu Mar 07 09:55:29 ICT 2019
*
* @brief     Hardware configuration file
*
******************************************************************************/
#ifndef    _LIN_CFG_H_
#define    _LIN_CFG_H_
#include "lin_hw_cfg.h"
/* Define operating mode */
#define _MASTER_MODE_     0
#define _SLAVE_MODE_      1
#define LIN_MODE   _SLAVE_MODE_
/* Define protocol version */
#define PROTOCOL_21       0
#define PROTOCOL_J2602    1
#define PROTOCOL_20       2
#define LIN_PROTOCOL    PROTOCOL_21

#define SCI_ADDR        SCI0_ADDR    /* For slave */

#define LIN_BAUD_RATE    9600         /*For slave*/
/* RESYNCHRONIZE */
/*
LIN_PRESCALER = [Fbus/Baudrate/16]
RESYN_TIMER_PRESCALER >= [LIN_PRESCALER/2] (if [LIN_PRESCALER/2] > 128,please define RESYN_TIMER_PRESCALER = 128)
The value of RESYN_TIMER_PRESCALER must be one of the [ 1,2,4,8,16,32,64,128 ])
*/
#define LIN_PRESCALER 104
#define RESYN_TIMER_PRESCALER 64
/**********************************************************************/
/***************          Diagnostic class selection  *****************/
/**********************************************************************/
#define _DIAG_CLASS_I_          0
#define _DIAG_CLASS_II_         1
#define _DIAG_CLASS_III_        2

#define _DIAG_CLASS_SUPPORT_    _DIAG_CLASS_I_

#define MAX_LENGTH_SERVICE 6

#define MAX_QUEUE_SIZE 1


#define _DIAG_NUMBER_OF_SERVICES_    5

#define DIAGSRV_READ_BY_IDENTIFIER_ORDER    0

#define DIAGSRV_ASSIGN_FRAME_ID_RANGE_ORDER    1

#define DIAGSRV_ASSIGN_NAD_ORDER    2

#define DIAGSRV_CONDITIONAL_CHANGE_NAD_ORDER    3

#define DIAGSRV_SAVE_CONFIGURATION_ORDER    4


/**************** FRAME SUPPORT DEFINITION ******************/
#define _TL_SINGLE_FRAME_       0
#define _TL_MULTI_FRAME_        1

#define _TL_FRAME_SUPPORT_      _TL_SINGLE_FRAME_

/* frame buffer size */
#define LIN_FRAME_BUF_SIZE          5
#define LIN_FLAG_BUF_SIZE           4

/**********************************************************************/
/***************               Interfaces           *******************/
/**********************************************************************/
typedef enum {
   LI0
}l_ifc_handle;

/**********************************************************************/
/***************               Signals              *******************/
/**********************************************************************/
/* Number of signals */
#define LIN_NUM_OF_SIGS  4
/* List of signals */
typedef enum {

   /* Interface_name = LI0 */

   LI0_FrontLeftDoorSignal

   , LI0_FrontLeftDoorErrSig
  
   , LI0_MasterToFront
  
   , LI0_FrontToMasterSignal
  
} l_signal_handle;
/**********************************************************************/
/*****************               Frame             ********************/
/**********************************************************************/
/* Number of frames */
#define LIN_NUM_OF_FRMS  7
/* List of frames */
typedef enum {
/* All frames for master node */

   /* Interface_name = LI0 */

   LI0_FrontLeftDoorMessage

   , LI0_MasterToFrontControl
  
   , LI0_FrontLeftDoorErrEvent
  
   , LI0_FrontToMasterMessage
  
   , LI0_ETF_MotorStates
  
   , LI0_MasterReq
  
   , LI0_SlaveResp
  
} l_frame_handle;
/**********************************************************************/
/***************             Configuration          *******************/
/**********************************************************************/
/* Size of configuration in ROM and RAM used for interface: LI1 */
#define LIN_SIZE_OF_CFG  9
#define LIN_CFG_FRAME_NUM  5
/*********************************************************************
 * global macros
 *********************************************************************/
#define l_bool_rd(SIGNAL) l_bool_rd_##SIGNAL()
#define l_bool_wr(SIGNAL, A) l_bool_wr_##SIGNAL(A)
#define l_u8_rd(SIGNAL) l_u8_rd_##SIGNAL()
#define l_u8_wr(SIGNAL, A) l_u8_wr_##SIGNAL(A)
#define l_u16_rd(SIGNAL) l_u16_rd_##SIGNAL()
#define l_u16_wr(SIGNAL, A) l_u16_wr_##SIGNAL(A)
#define l_bytes_rd(SIGNAL, start, count, data)  l_bytes_rd_##SIGNAL(start, count, data)
#define l_bytes_wr(SIGNAL, start, count, data) l_bytes_wr_##SIGNAL(start, count, data)
#define l_flg_tst(FLAG) l_flg_tst_##FLAG()
#define l_flg_clr(FLAG) l_flg_clr_##FLAG()
#define LIN_TEST_BIT(A,B) ((l_bool)((((A) & (1U << (B))) != 0U) ? 1U : 0U))
#define LIN_SET_BIT(A,B)                      ((A) |= (l_u8) (1U << (B)))
#define LIN_CLEAR_BIT(A,B)               ((A) &= ((l_u8) (~(1U << (B)))))
#define LIN_BYTE_MASK  ((l_u16)(((l_u16)((l_u16)1 << CHAR_BIT)) - (l_u16)1))
#define LIN_FRAME_LEN_MAX                                             10U

/* Returns the low byte of the 32-bit value    */
#define BYTE_0(n)                              ((l_u8)((n) & (l_u8)0xFF))
/* Returns the second byte of the 32-bit value */
#define BYTE_1(n)                        ((l_u8)(BYTE_0((n) >> (l_u8)8)))
/* Returns the third byte of the 32-bit value  */
#define BYTE_2(n)                       ((l_u8)(BYTE_0((n) >> (l_u8)16)))
/* Returns high byte of the 32-bit value       */
#define BYTE_3(n)                       ((l_u8)(BYTE_0((n) >> (l_u8)24)))

/*
 * defines for signal access
 */



#define LIN_BYTE_OFFSET_LI0_FrontLeftDoorSignal    0U
#define LIN_BIT_OFFSET_LI0_FrontLeftDoorSignal    0U
#define LIN_SIGNAL_SIZE_LI0_FrontLeftDoorSignal    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorSignal    0U
#define LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorSignal    0U


#define LIN_BYTE_OFFSET_LI0_FrontLeftDoorErrSig    3U
#define LIN_BIT_OFFSET_LI0_FrontLeftDoorErrSig    0U
#define LIN_SIGNAL_SIZE_LI0_FrontLeftDoorErrSig    1U
#define LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorErrSig    2U
#define LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorErrSig    0U


#define LIN_BYTE_OFFSET_LI0_MasterToFront    1U
#define LIN_BIT_OFFSET_LI0_MasterToFront    0U
#define LIN_SIGNAL_SIZE_LI0_MasterToFront    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_MasterToFront    1U
#define LIN_FLAG_BIT_OFFSET_LI0_MasterToFront    0U


#define LIN_BYTE_OFFSET_LI0_FrontToMasterSignal    4U
#define LIN_BIT_OFFSET_LI0_FrontToMasterSignal    0U
#define LIN_SIGNAL_SIZE_LI0_FrontToMasterSignal    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_FrontToMasterSignal    3U
#define LIN_FLAG_BIT_OFFSET_LI0_FrontToMasterSignal    0U




#define LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorMessage             0
#define LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorMessage              0

#define LIN_FLAG_BYTE_OFFSET_LI0_MasterToFrontControl             1
#define LIN_FLAG_BIT_OFFSET_LI0_MasterToFrontControl              0

#define LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorErrEvent             2
#define LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorErrEvent              0

#define LIN_FLAG_BYTE_OFFSET_LI0_FrontToMasterMessage             3
#define LIN_FLAG_BIT_OFFSET_LI0_FrontToMasterMessage              0


/**********************************************************************/
/***************        Static API Functions        *******************/
/**********************************************************************/
/*
 * the static signal access macros
 */


 
/* static access macros for signal LI0_FrontLeftDoorSignal */
 
#define l_u8_rd_LI0_FrontLeftDoorSignal() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_FrontLeftDoorSignal]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_FrontLeftDoorSignal(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_FrontLeftDoorSignal] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_FrontLeftDoorSignal] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorSignal); \
    }


/* static access macros for signal LI0_FrontLeftDoorErrSig */

 
#define l_bool_rd_LI0_FrontLeftDoorErrSig() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_FrontLeftDoorErrSig], \
    LIN_BIT_OFFSET_LI0_FrontLeftDoorErrSig))

#define l_bool_wr_LI0_FrontLeftDoorErrSig(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_FrontLeftDoorErrSig], \
    LIN_BIT_OFFSET_LI0_FrontLeftDoorErrSig)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_FrontLeftDoorErrSig], \
    LIN_BIT_OFFSET_LI0_FrontLeftDoorErrSig));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorErrSig],\
         LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorErrSig);}
 
/* static access macros for signal LI0_MasterToFront */
 
#define l_u8_rd_LI0_MasterToFront() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MasterToFront]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_MasterToFront(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MasterToFront] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MasterToFront] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MasterToFront],\
         LIN_FLAG_BIT_OFFSET_LI0_MasterToFront); \
    }


 
/* static access macros for signal LI0_FrontToMasterSignal */
 
#define l_u8_rd_LI0_FrontToMasterSignal() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_FrontToMasterSignal]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_FrontToMasterSignal(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_FrontToMasterSignal] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_FrontToMasterSignal] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_FrontToMasterSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_FrontToMasterSignal); \
    }




/* Signal flag APIs */

#define l_flg_tst_LI0_FrontLeftDoorSignal_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorSignal)
#define l_flg_clr_LI0_FrontLeftDoorSignal_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorSignal)

#define l_flg_tst_LI0_FrontLeftDoorErrSig_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorErrSig],\
         LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorErrSig)
#define l_flg_clr_LI0_FrontLeftDoorErrSig_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorErrSig],\
         LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorErrSig)

#define l_flg_tst_LI0_MasterToFront_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MasterToFront],\
         LIN_FLAG_BIT_OFFSET_LI0_MasterToFront)
#define l_flg_clr_LI0_MasterToFront_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MasterToFront],\
         LIN_FLAG_BIT_OFFSET_LI0_MasterToFront)

#define l_flg_tst_LI0_FrontToMasterSignal_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_FrontToMasterSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_FrontToMasterSignal)
#define l_flg_clr_LI0_FrontToMasterSignal_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_FrontToMasterSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_FrontToMasterSignal)



/* Frame flag APIs */

   /* Interface_name = LI0 */

 #define l_flg_tst_LI0_FrontLeftDoorMessage_flag() \
          lin_frame_flag_tbl[LI0_FrontLeftDoorMessage]
 #define l_flg_clr_LI0_FrontLeftDoorMessage_flag() \
          lin_frame_flag_tbl[LI0_FrontLeftDoorMessage] = 0

 #define l_flg_tst_LI0_MasterToFrontControl_flag() \
          lin_frame_flag_tbl[LI0_MasterToFrontControl]
 #define l_flg_clr_LI0_MasterToFrontControl_flag() \
          lin_frame_flag_tbl[LI0_MasterToFrontControl] = 0

 #define l_flg_tst_LI0_FrontLeftDoorErrEvent_flag() \
          lin_frame_flag_tbl[LI0_FrontLeftDoorErrEvent]
 #define l_flg_clr_LI0_FrontLeftDoorErrEvent_flag() \
          lin_frame_flag_tbl[LI0_FrontLeftDoorErrEvent] = 0

 #define l_flg_tst_LI0_FrontToMasterMessage_flag() \
          lin_frame_flag_tbl[LI0_FrontToMasterMessage]
 #define l_flg_clr_LI0_FrontToMasterMessage_flag() \
          lin_frame_flag_tbl[LI0_FrontToMasterMessage] = 0

 #define l_flg_tst_LI0_ETF_MotorStates_flag() \
          lin_frame_flag_tbl[LI0_ETF_MotorStates]
 #define l_flg_clr_LI0_ETF_MotorStates_flag() \
          lin_frame_flag_tbl[LI0_ETF_MotorStates] = 0

 #define l_flg_tst_LI0_MasterReq_flag() \
          lin_frame_flag_tbl[LI0_MasterReq]
 #define l_flg_clr_LI0_MasterReq_flag() \
          lin_frame_flag_tbl[LI0_MasterReq] = 0

 #define l_flg_tst_LI0_SlaveResp_flag() \
          lin_frame_flag_tbl[LI0_SlaveResp]
 #define l_flg_clr_LI0_SlaveResp_flag() \
          lin_frame_flag_tbl[LI0_SlaveResp] = 0



/* INTERFACE MANAGEMENT */

#define l_ifc_init_LI0() l_ifc_init(LI0)



#define l_ifc_wake_up_LI0() l_ifc_wake_up(LI0)



#define l_ifc_rx_LI0() l_ifc_rx(LI0)



#define l_ifc_tx_LI0() l_ifc_tx(LI0)



#define l_ifc_aux_LI0() l_ifc_aux(LI0)



#define l_ifc_read_status_LI0() l_ifc_read_status(LI0)


#endif    /* _LIN_CFG_H_ */