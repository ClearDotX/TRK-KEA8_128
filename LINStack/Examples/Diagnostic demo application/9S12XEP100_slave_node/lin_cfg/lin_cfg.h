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
* @date      Thu Mar 07 09:54:52 ICT 2019
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

 #define SCI_ADDR        SCI1_ADDR    /* For slave */

#define LIN_BAUD_RATE    9600         /*For slave*/
/**********************************************************************/
/***************          Diagnostic class selection  *****************/
/**********************************************************************/
#define _DIAG_CLASS_I_          0
#define _DIAG_CLASS_II_         1
#define _DIAG_CLASS_III_        2

#define _DIAG_CLASS_SUPPORT_    _DIAG_CLASS_II_

#define MAX_LENGTH_SERVICE 21

#define MAX_QUEUE_SIZE 4


#define _DIAG_NUMBER_OF_SERVICES_    4

#define DIAGSRV_READ_BY_IDENTIFIER_ORDER    0

#define DIAGSRV_WRITE_DATA_BY_IDENTIFIER_ORDER    1

#define DIAGSRV_ASSIGN_FRAME_ID_RANGE_ORDER    2

#define DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER    3


/**************** FRAME SUPPORT DEFINITION ******************/
#define _TL_SINGLE_FRAME_       0
#define _TL_MULTI_FRAME_        1

#define _TL_FRAME_SUPPORT_      _TL_MULTI_FRAME_

/* frame buffer size */
#define LIN_FRAME_BUF_SIZE          5
#define LIN_FLAG_BUF_SIZE           4

/**********************************************************************/
/***************               Interfaces           *******************/
/**********************************************************************/
typedef enum {
   LI1
}l_ifc_handle;

/**********************************************************************/
/***************               Signals              *******************/
/**********************************************************************/
/* Number of signals */
#define LIN_NUM_OF_SIGS  4
/* List of signals */
typedef enum {

   /* Interface_name = LI1 */

   LI1_RearLeftDoorSignal

   , LI1_RearLeftDoorErrSig
  
   , LI1_MasterToRear
  
   , LI1_RearToMasterSignal
  
} l_signal_handle;
/**********************************************************************/
/*****************               Frame             ********************/
/**********************************************************************/
/* Number of frames */
#define LIN_NUM_OF_FRMS  7
/* List of frames */
typedef enum {
/* All frames for master node */

   /* Interface_name = LI1 */

   LI1_RearLeftDoorMessage

   , LI1_MasterToRearControl
  
   , LI1_RearLeftDoorErrEvent
  
   , LI1_RearToMasterMessage
  
   , LI1_ETF_MotorStates
  
   , LI1_MasterReq
  
   , LI1_SlaveResp
  
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



#define LIN_BYTE_OFFSET_LI1_RearLeftDoorSignal    0U
#define LIN_BIT_OFFSET_LI1_RearLeftDoorSignal    0U
#define LIN_SIGNAL_SIZE_LI1_RearLeftDoorSignal    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_RearLeftDoorSignal    0U
#define LIN_FLAG_BIT_OFFSET_LI1_RearLeftDoorSignal    0U


#define LIN_BYTE_OFFSET_LI1_RearLeftDoorErrSig    3U
#define LIN_BIT_OFFSET_LI1_RearLeftDoorErrSig    0U
#define LIN_SIGNAL_SIZE_LI1_RearLeftDoorErrSig    1U
#define LIN_FLAG_BYTE_OFFSET_LI1_RearLeftDoorErrSig    2U
#define LIN_FLAG_BIT_OFFSET_LI1_RearLeftDoorErrSig    0U


#define LIN_BYTE_OFFSET_LI1_MasterToRear    1U
#define LIN_BIT_OFFSET_LI1_MasterToRear    0U
#define LIN_SIGNAL_SIZE_LI1_MasterToRear    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_MasterToRear    1U
#define LIN_FLAG_BIT_OFFSET_LI1_MasterToRear    0U


#define LIN_BYTE_OFFSET_LI1_RearToMasterSignal    4U
#define LIN_BIT_OFFSET_LI1_RearToMasterSignal    0U
#define LIN_SIGNAL_SIZE_LI1_RearToMasterSignal    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_RearToMasterSignal    3U
#define LIN_FLAG_BIT_OFFSET_LI1_RearToMasterSignal    0U




#define LIN_FLAG_BYTE_OFFSET_LI1_RearLeftDoorMessage             0
#define LIN_FLAG_BIT_OFFSET_LI1_RearLeftDoorMessage              0

#define LIN_FLAG_BYTE_OFFSET_LI1_MasterToRearControl             1
#define LIN_FLAG_BIT_OFFSET_LI1_MasterToRearControl              0

#define LIN_FLAG_BYTE_OFFSET_LI1_RearLeftDoorErrEvent             2
#define LIN_FLAG_BIT_OFFSET_LI1_RearLeftDoorErrEvent              0

#define LIN_FLAG_BYTE_OFFSET_LI1_RearToMasterMessage             3
#define LIN_FLAG_BIT_OFFSET_LI1_RearToMasterMessage              0


/**********************************************************************/
/***************        Static API Functions        *******************/
/**********************************************************************/
/*
 * the static signal access macros
 */


 
/* static access macros for signal LI1_RearLeftDoorSignal */
 
#define l_u8_rd_LI1_RearLeftDoorSignal() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_RearLeftDoorSignal]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_RearLeftDoorSignal(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_RearLeftDoorSignal] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_RearLeftDoorSignal] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_RearLeftDoorSignal],\
         LIN_FLAG_BIT_OFFSET_LI1_RearLeftDoorSignal); \
    }


/* static access macros for signal LI1_RearLeftDoorErrSig */

 
#define l_bool_rd_LI1_RearLeftDoorErrSig() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_RearLeftDoorErrSig], \
    LIN_BIT_OFFSET_LI1_RearLeftDoorErrSig))

#define l_bool_wr_LI1_RearLeftDoorErrSig(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_RearLeftDoorErrSig], \
    LIN_BIT_OFFSET_LI1_RearLeftDoorErrSig)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_RearLeftDoorErrSig], \
    LIN_BIT_OFFSET_LI1_RearLeftDoorErrSig));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_RearLeftDoorErrSig],\
         LIN_FLAG_BIT_OFFSET_LI1_RearLeftDoorErrSig);}
 
/* static access macros for signal LI1_MasterToRear */
 
#define l_u8_rd_LI1_MasterToRear() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_MasterToRear]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_MasterToRear(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_MasterToRear] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_MasterToRear] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_MasterToRear],\
         LIN_FLAG_BIT_OFFSET_LI1_MasterToRear); \
    }


 
/* static access macros for signal LI1_RearToMasterSignal */
 
#define l_u8_rd_LI1_RearToMasterSignal() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_RearToMasterSignal]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_RearToMasterSignal(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_RearToMasterSignal] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_RearToMasterSignal] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_RearToMasterSignal],\
         LIN_FLAG_BIT_OFFSET_LI1_RearToMasterSignal); \
    }




/* Signal flag APIs */

#define l_flg_tst_LI1_RearLeftDoorSignal_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_RearLeftDoorSignal],\
         LIN_FLAG_BIT_OFFSET_LI1_RearLeftDoorSignal)
#define l_flg_clr_LI1_RearLeftDoorSignal_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_RearLeftDoorSignal],\
         LIN_FLAG_BIT_OFFSET_LI1_RearLeftDoorSignal)

#define l_flg_tst_LI1_RearLeftDoorErrSig_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_RearLeftDoorErrSig],\
         LIN_FLAG_BIT_OFFSET_LI1_RearLeftDoorErrSig)
#define l_flg_clr_LI1_RearLeftDoorErrSig_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_RearLeftDoorErrSig],\
         LIN_FLAG_BIT_OFFSET_LI1_RearLeftDoorErrSig)

#define l_flg_tst_LI1_MasterToRear_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_MasterToRear],\
         LIN_FLAG_BIT_OFFSET_LI1_MasterToRear)
#define l_flg_clr_LI1_MasterToRear_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_MasterToRear],\
         LIN_FLAG_BIT_OFFSET_LI1_MasterToRear)

#define l_flg_tst_LI1_RearToMasterSignal_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_RearToMasterSignal],\
         LIN_FLAG_BIT_OFFSET_LI1_RearToMasterSignal)
#define l_flg_clr_LI1_RearToMasterSignal_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_RearToMasterSignal],\
         LIN_FLAG_BIT_OFFSET_LI1_RearToMasterSignal)



/* Frame flag APIs */

   /* Interface_name = LI1 */

 #define l_flg_tst_LI1_RearLeftDoorMessage_flag() \
          lin_frame_flag_tbl[LI1_RearLeftDoorMessage]
 #define l_flg_clr_LI1_RearLeftDoorMessage_flag() \
          lin_frame_flag_tbl[LI1_RearLeftDoorMessage] = 0

 #define l_flg_tst_LI1_MasterToRearControl_flag() \
          lin_frame_flag_tbl[LI1_MasterToRearControl]
 #define l_flg_clr_LI1_MasterToRearControl_flag() \
          lin_frame_flag_tbl[LI1_MasterToRearControl] = 0

 #define l_flg_tst_LI1_RearLeftDoorErrEvent_flag() \
          lin_frame_flag_tbl[LI1_RearLeftDoorErrEvent]
 #define l_flg_clr_LI1_RearLeftDoorErrEvent_flag() \
          lin_frame_flag_tbl[LI1_RearLeftDoorErrEvent] = 0

 #define l_flg_tst_LI1_RearToMasterMessage_flag() \
          lin_frame_flag_tbl[LI1_RearToMasterMessage]
 #define l_flg_clr_LI1_RearToMasterMessage_flag() \
          lin_frame_flag_tbl[LI1_RearToMasterMessage] = 0

 #define l_flg_tst_LI1_ETF_MotorStates_flag() \
          lin_frame_flag_tbl[LI1_ETF_MotorStates]
 #define l_flg_clr_LI1_ETF_MotorStates_flag() \
          lin_frame_flag_tbl[LI1_ETF_MotorStates] = 0

 #define l_flg_tst_LI1_MasterReq_flag() \
          lin_frame_flag_tbl[LI1_MasterReq]
 #define l_flg_clr_LI1_MasterReq_flag() \
          lin_frame_flag_tbl[LI1_MasterReq] = 0

 #define l_flg_tst_LI1_SlaveResp_flag() \
          lin_frame_flag_tbl[LI1_SlaveResp]
 #define l_flg_clr_LI1_SlaveResp_flag() \
          lin_frame_flag_tbl[LI1_SlaveResp] = 0



/* INTERFACE MANAGEMENT */

#define l_ifc_init_LI1() l_ifc_init(LI1)



#define l_ifc_wake_up_LI1() l_ifc_wake_up(LI1)



#define l_ifc_rx_LI1() l_ifc_rx(LI1)



#define l_ifc_tx_LI1() l_ifc_tx(LI1)



#define l_ifc_aux_LI1() l_ifc_aux(LI1)



#define l_ifc_read_status_LI1() l_ifc_read_status(LI1)


#endif    /* _LIN_CFG_H_ */