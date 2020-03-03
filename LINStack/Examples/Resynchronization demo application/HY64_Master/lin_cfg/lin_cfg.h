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
* @date      Thu Mar 07 09:55:32 ICT 2019
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
#define LIN_MODE   _MASTER_MODE_
/* Define protocol version */
#define PROTOCOL_21       0
#define PROTOCOL_J2602    1
#define PROTOCOL_20       2
#define LIN_PROTOCOL    PROTOCOL_21
#define LIN_NUM_OF_IFCS  1     /* For master */
/**********************************************************************/
/***************          Diagnostic class selection  *****************/
/**********************************************************************/
#define _DIAG_CLASS_I_          0
#define _DIAG_CLASS_II_         1
#define _DIAG_CLASS_III_        2

#define _DIAG_CLASS_SUPPORT_    _DIAG_CLASS_I_

#define MAX_LENGTH_SERVICE 6

#define MAX_QUEUE_SIZE 1


#define _LI0_DIAG_NUMBER_OF_SERVICES_    5

#define LI0_DIAGSRV_READ_BY_IDENTIFIER_ORDER    0

#define LI0_DIAGSRV_ASSIGN_FRAME_ID_RANGE_ORDER    1

#define LI0_DIAGSRV_ASSIGN_NAD_ORDER    2

#define LI0_DIAGSRV_CONDITIONAL_CHANGE_NAD_ORDER    3

#define LI0_DIAGSRV_SAVE_CONFIGURATION_ORDER    4


/**************** FRAME SUPPORT DEFINITION ******************/
#define _TL_SINGLE_FRAME_       0
#define _TL_MULTI_FRAME_        1

#define _TL_FRAME_SUPPORT_      _TL_SINGLE_FRAME_

/* frame buffer size */
#define LIN_FRAME_BUF_SIZE          10
#define LIN_FLAG_BUF_SIZE           8

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
#define LIN_NUM_OF_SIGS  8
/* List of signals */
typedef enum {

   /* Interface_name = LI0 */

   LI0_FrontLeftDoorSignal

   , LI0_FrontLeftDoorErrSig
  
   , LI0_RearLeftDoorSignal
  
   , LI0_RearLeftDoorErrSig
  
   , LI0_MasterToRear
  
   , LI0_MasterToFront
  
   , LI0_RearToMasterSignal
  
   , LI0_FrontToMasterSignal
  
} l_signal_handle;
/**********************************************************************/
/*****************               Frame             ********************/
/**********************************************************************/
/* Number of frames */
#define LIN_NUM_OF_FRMS  11
/* List of frames */
typedef enum {
/* All frames for master node */

   /* Interface_name = LI0 */

   LI0_FrontLeftDoorMessage

   , LI0_FrontLeftDoorErrEvent
  
   , LI0_RearLeftDoorMessage
  
   , LI0_RearLeftDoorErrEvent
  
   , LI0_MasterToRearControl
  
   , LI0_MasterToFrontControl
  
   , LI0_RearToMasterMessage
  
   , LI0_FrontToMasterMessage
  
   , LI0_ETF_MotorStates
  
   , LI0_MasterReq
  
   , LI0_SlaveResp
  
} l_frame_handle;
/**********************************************************************/
/***************        schedule table       *******************/
/**********************************************************************/
/* Number of schedule tables */
#define  LIN_NUM_OF_SCHD_TBL   8
/* List of schedules */
typedef enum {

   /* Interface_name = LI0 */

   LI0_LIN_NULL_SCHEDULE

   ,LI0_GOTO_SLEEP_SCHEDULE
   
   ,LI0_MasterReq_Table
   
   ,LI0_SlaveResp_Table
   
   ,LI0_Diagnostic
   
   ,LI0_ETFCollisionResolving
   
   ,LI0_InitTable
   
   ,LI0_NormalTable
   
}l_schedule_handle;/**********************************************************************/
/***************             Configuration          *******************/
/**********************************************************************/

/* Size of configuration in ROM and RAM used for interface: LI0 */
#define LI0_LIN_SIZE_OF_CFG  13

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


#define LIN_BYTE_OFFSET_LI0_FrontLeftDoorErrSig    2U
#define LIN_BIT_OFFSET_LI0_FrontLeftDoorErrSig    0U
#define LIN_SIGNAL_SIZE_LI0_FrontLeftDoorErrSig    1U
#define LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorErrSig    1U
#define LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorErrSig    0U


#define LIN_BYTE_OFFSET_LI0_RearLeftDoorSignal    3U
#define LIN_BIT_OFFSET_LI0_RearLeftDoorSignal    0U
#define LIN_SIGNAL_SIZE_LI0_RearLeftDoorSignal    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_RearLeftDoorSignal    2U
#define LIN_FLAG_BIT_OFFSET_LI0_RearLeftDoorSignal    0U


#define LIN_BYTE_OFFSET_LI0_RearLeftDoorErrSig    5U
#define LIN_BIT_OFFSET_LI0_RearLeftDoorErrSig    0U
#define LIN_SIGNAL_SIZE_LI0_RearLeftDoorErrSig    1U
#define LIN_FLAG_BYTE_OFFSET_LI0_RearLeftDoorErrSig    3U
#define LIN_FLAG_BIT_OFFSET_LI0_RearLeftDoorErrSig    0U


#define LIN_BYTE_OFFSET_LI0_MasterToRear    6U
#define LIN_BIT_OFFSET_LI0_MasterToRear    0U
#define LIN_SIGNAL_SIZE_LI0_MasterToRear    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_MasterToRear    4U
#define LIN_FLAG_BIT_OFFSET_LI0_MasterToRear    0U


#define LIN_BYTE_OFFSET_LI0_MasterToFront    7U
#define LIN_BIT_OFFSET_LI0_MasterToFront    0U
#define LIN_SIGNAL_SIZE_LI0_MasterToFront    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_MasterToFront    5U
#define LIN_FLAG_BIT_OFFSET_LI0_MasterToFront    0U


#define LIN_BYTE_OFFSET_LI0_RearToMasterSignal    8U
#define LIN_BIT_OFFSET_LI0_RearToMasterSignal    0U
#define LIN_SIGNAL_SIZE_LI0_RearToMasterSignal    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_RearToMasterSignal    6U
#define LIN_FLAG_BIT_OFFSET_LI0_RearToMasterSignal    0U


#define LIN_BYTE_OFFSET_LI0_FrontToMasterSignal    9U
#define LIN_BIT_OFFSET_LI0_FrontToMasterSignal    0U
#define LIN_SIGNAL_SIZE_LI0_FrontToMasterSignal    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_FrontToMasterSignal    7U
#define LIN_FLAG_BIT_OFFSET_LI0_FrontToMasterSignal    0U




#define LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorMessage             0
#define LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorMessage              0

#define LIN_FLAG_BYTE_OFFSET_LI0_FrontLeftDoorErrEvent             1
#define LIN_FLAG_BIT_OFFSET_LI0_FrontLeftDoorErrEvent              0

#define LIN_FLAG_BYTE_OFFSET_LI0_RearLeftDoorMessage             2
#define LIN_FLAG_BIT_OFFSET_LI0_RearLeftDoorMessage              0

#define LIN_FLAG_BYTE_OFFSET_LI0_RearLeftDoorErrEvent             3
#define LIN_FLAG_BIT_OFFSET_LI0_RearLeftDoorErrEvent              0

#define LIN_FLAG_BYTE_OFFSET_LI0_MasterToRearControl             4
#define LIN_FLAG_BIT_OFFSET_LI0_MasterToRearControl              0

#define LIN_FLAG_BYTE_OFFSET_LI0_MasterToFrontControl             5
#define LIN_FLAG_BIT_OFFSET_LI0_MasterToFrontControl              0

#define LIN_FLAG_BYTE_OFFSET_LI0_RearToMasterMessage             6
#define LIN_FLAG_BIT_OFFSET_LI0_RearToMasterMessage              0

#define LIN_FLAG_BYTE_OFFSET_LI0_FrontToMasterMessage             7
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
 
/* static access macros for signal LI0_RearLeftDoorSignal */
 
#define l_u8_rd_LI0_RearLeftDoorSignal() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_RearLeftDoorSignal]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_RearLeftDoorSignal(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_RearLeftDoorSignal] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_RearLeftDoorSignal] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_RearLeftDoorSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_RearLeftDoorSignal); \
    }


/* static access macros for signal LI0_RearLeftDoorErrSig */

 
#define l_bool_rd_LI0_RearLeftDoorErrSig() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_RearLeftDoorErrSig], \
    LIN_BIT_OFFSET_LI0_RearLeftDoorErrSig))

#define l_bool_wr_LI0_RearLeftDoorErrSig(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_RearLeftDoorErrSig], \
    LIN_BIT_OFFSET_LI0_RearLeftDoorErrSig)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_RearLeftDoorErrSig], \
    LIN_BIT_OFFSET_LI0_RearLeftDoorErrSig));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_RearLeftDoorErrSig],\
         LIN_FLAG_BIT_OFFSET_LI0_RearLeftDoorErrSig);}
 
/* static access macros for signal LI0_MasterToRear */
 
#define l_u8_rd_LI0_MasterToRear() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MasterToRear]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_MasterToRear(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MasterToRear] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MasterToRear] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MasterToRear],\
         LIN_FLAG_BIT_OFFSET_LI0_MasterToRear); \
    }


 
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


 
/* static access macros for signal LI0_RearToMasterSignal */
 
#define l_u8_rd_LI0_RearToMasterSignal() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_RearToMasterSignal]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_RearToMasterSignal(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_RearToMasterSignal] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_RearToMasterSignal] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_RearToMasterSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_RearToMasterSignal); \
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

#define l_flg_tst_LI0_RearLeftDoorSignal_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_RearLeftDoorSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_RearLeftDoorSignal)
#define l_flg_clr_LI0_RearLeftDoorSignal_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_RearLeftDoorSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_RearLeftDoorSignal)

#define l_flg_tst_LI0_RearLeftDoorErrSig_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_RearLeftDoorErrSig],\
         LIN_FLAG_BIT_OFFSET_LI0_RearLeftDoorErrSig)
#define l_flg_clr_LI0_RearLeftDoorErrSig_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_RearLeftDoorErrSig],\
         LIN_FLAG_BIT_OFFSET_LI0_RearLeftDoorErrSig)

#define l_flg_tst_LI0_MasterToRear_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MasterToRear],\
         LIN_FLAG_BIT_OFFSET_LI0_MasterToRear)
#define l_flg_clr_LI0_MasterToRear_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MasterToRear],\
         LIN_FLAG_BIT_OFFSET_LI0_MasterToRear)

#define l_flg_tst_LI0_MasterToFront_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MasterToFront],\
         LIN_FLAG_BIT_OFFSET_LI0_MasterToFront)
#define l_flg_clr_LI0_MasterToFront_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MasterToFront],\
         LIN_FLAG_BIT_OFFSET_LI0_MasterToFront)

#define l_flg_tst_LI0_RearToMasterSignal_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_RearToMasterSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_RearToMasterSignal)
#define l_flg_clr_LI0_RearToMasterSignal_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_RearToMasterSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_RearToMasterSignal)

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

 #define l_flg_tst_LI0_FrontLeftDoorErrEvent_flag() \
          lin_frame_flag_tbl[LI0_FrontLeftDoorErrEvent]
 #define l_flg_clr_LI0_FrontLeftDoorErrEvent_flag() \
          lin_frame_flag_tbl[LI0_FrontLeftDoorErrEvent] = 0

 #define l_flg_tst_LI0_RearLeftDoorMessage_flag() \
          lin_frame_flag_tbl[LI0_RearLeftDoorMessage]
 #define l_flg_clr_LI0_RearLeftDoorMessage_flag() \
          lin_frame_flag_tbl[LI0_RearLeftDoorMessage] = 0

 #define l_flg_tst_LI0_RearLeftDoorErrEvent_flag() \
          lin_frame_flag_tbl[LI0_RearLeftDoorErrEvent]
 #define l_flg_clr_LI0_RearLeftDoorErrEvent_flag() \
          lin_frame_flag_tbl[LI0_RearLeftDoorErrEvent] = 0

 #define l_flg_tst_LI0_MasterToRearControl_flag() \
          lin_frame_flag_tbl[LI0_MasterToRearControl]
 #define l_flg_clr_LI0_MasterToRearControl_flag() \
          lin_frame_flag_tbl[LI0_MasterToRearControl] = 0

 #define l_flg_tst_LI0_MasterToFrontControl_flag() \
          lin_frame_flag_tbl[LI0_MasterToFrontControl]
 #define l_flg_clr_LI0_MasterToFrontControl_flag() \
          lin_frame_flag_tbl[LI0_MasterToFrontControl] = 0

 #define l_flg_tst_LI0_RearToMasterMessage_flag() \
          lin_frame_flag_tbl[LI0_RearToMasterMessage]
 #define l_flg_clr_LI0_RearToMasterMessage_flag() \
          lin_frame_flag_tbl[LI0_RearToMasterMessage] = 0

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



/* SCHEDULE MANAGEMENT */

#define l_sch_tick_LI0() l_sch_tick(LI0)



#define l_sch_set_LI0(schedule, entry) l_sch_set(LI0, schedule, entry)

/* INTERFACE MANAGEMENT */

#define l_ifc_init_LI0() l_ifc_init(LI0)



#define l_ifc_goto_sleep_LI0() l_ifc_goto_sleep(LI0)


#define l_ifc_wake_up_LI0() l_ifc_wake_up(LI0)



#define l_ifc_rx_LI0() l_ifc_rx(LI0)



#define l_ifc_tx_LI0() l_ifc_tx(LI0)



#define l_ifc_aux_LI0() l_ifc_aux(LI0)



#define l_ifc_read_status_LI0() l_ifc_read_status(LI0)


#endif    /* _LIN_CFG_H_ */