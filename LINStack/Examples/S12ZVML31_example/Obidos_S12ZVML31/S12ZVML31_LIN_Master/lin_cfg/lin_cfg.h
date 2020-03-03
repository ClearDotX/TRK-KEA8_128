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
* @date      Thu Mar 07 09:56:27 ICT 2019
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
#define LIN_FRAME_BUF_SIZE          28
#define LIN_FLAG_BUF_SIZE           7

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
#define LIN_NUM_OF_SIGS  14
/* List of signals */
typedef enum {

   /* Interface_name = LI0 */

   LI0_Motor1ErrorCode

   , LI0_Motor1ErrorValue
  
   , LI0_Motor1LinError
  
   , LI0_Motor1Selection
  
   , LI0_Motor1Temp
  
   , LI0_Motor2ErrorCode
  
   , LI0_Motor2ErrorValue
  
   , LI0_Motor2LinError
  
   , LI0_Motor2Selection
  
   , LI0_Motor2Temp
  
   , LI0_MotorDirection
  
   , LI0_MotorSpeed
  
   , LI0_Motor1Position
  
   , LI0_Motor2Position
  
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

   LI0_Motor1Control

   , LI0_Motor1State_Cycl
  
   , LI0_Motor1State_Event
  
   , LI0_Motor2Control
  
   , LI0_Motor2State_Cycl
  
   , LI0_Motor2State_Event
  
   , LI0_MotorsControl
  
   , LI0_ETF_MotorStates
  
   , LI0_MasterReq
  
   , LI0_SlaveResp
  
   , LI0_SporadicControlFrame
  
} l_frame_handle;
/**********************************************************************/
/***************        schedule table       *******************/
/**********************************************************************/
/* Number of schedule tables */
#define  LIN_NUM_OF_SCHD_TBL   7
/* List of schedules */
typedef enum {

   /* Interface_name = LI0 */

   LI0_LIN_NULL_SCHEDULE

   ,LI0_GOTO_SLEEP_SCHEDULE
   
   ,LI0_MasterReqTable
   
   ,LI0_SlaveRespTable
   
   ,LI0_NormalTable
   
   ,LI0_ETFCollisionResolving
   
   ,LI0_InitTable
   
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



#define LIN_BYTE_OFFSET_LI0_Motor1ErrorCode    8U
#define LIN_BIT_OFFSET_LI0_Motor1ErrorCode    0U
#define LIN_SIGNAL_SIZE_LI0_Motor1ErrorCode    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Motor1ErrorCode    2U
#define LIN_FLAG_BIT_OFFSET_LI0_Motor1ErrorCode    0U


#define LIN_BYTE_OFFSET_LI0_Motor1ErrorValue    9U
#define LIN_BIT_OFFSET_LI0_Motor1ErrorValue    0U
#define LIN_SIGNAL_SIZE_LI0_Motor1ErrorValue    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Motor1ErrorValue    2U
#define LIN_FLAG_BIT_OFFSET_LI0_Motor1ErrorValue    1U


#define LIN_BYTE_OFFSET_LI0_Motor1LinError    6U
#define LIN_BIT_OFFSET_LI0_Motor1LinError    0U
#define LIN_SIGNAL_SIZE_LI0_Motor1LinError    1U
#define LIN_FLAG_BYTE_OFFSET_LI0_Motor1LinError    1U
#define LIN_FLAG_BIT_OFFSET_LI0_Motor1LinError    2U


#define LIN_BYTE_OFFSET_LI0_Motor1Selection    0U
#define LIN_BIT_OFFSET_LI0_Motor1Selection    0U
#define LIN_SIGNAL_SIZE_LI0_Motor1Selection    2U
#define LIN_FLAG_BYTE_OFFSET_LI0_Motor1Selection    0U
#define LIN_FLAG_BIT_OFFSET_LI0_Motor1Selection    0U


#define LIN_BYTE_OFFSET_LI0_Motor1Temp    1U
#define LIN_BIT_OFFSET_LI0_Motor1Temp    0U
#define LIN_SIGNAL_SIZE_LI0_Motor1Temp    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Motor1Temp    1U
#define LIN_FLAG_BIT_OFFSET_LI0_Motor1Temp    0U


#define LIN_BYTE_OFFSET_LI0_Motor2ErrorCode    18U
#define LIN_BIT_OFFSET_LI0_Motor2ErrorCode    0U
#define LIN_SIGNAL_SIZE_LI0_Motor2ErrorCode    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Motor2ErrorCode    5U
#define LIN_FLAG_BIT_OFFSET_LI0_Motor2ErrorCode    0U


#define LIN_BYTE_OFFSET_LI0_Motor2ErrorValue    19U
#define LIN_BIT_OFFSET_LI0_Motor2ErrorValue    0U
#define LIN_SIGNAL_SIZE_LI0_Motor2ErrorValue    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Motor2ErrorValue    5U
#define LIN_FLAG_BIT_OFFSET_LI0_Motor2ErrorValue    1U


#define LIN_BYTE_OFFSET_LI0_Motor2LinError    16U
#define LIN_BIT_OFFSET_LI0_Motor2LinError    0U
#define LIN_SIGNAL_SIZE_LI0_Motor2LinError    1U
#define LIN_FLAG_BYTE_OFFSET_LI0_Motor2LinError    4U
#define LIN_FLAG_BIT_OFFSET_LI0_Motor2LinError    2U


#define LIN_BYTE_OFFSET_LI0_Motor2Selection    10U
#define LIN_BIT_OFFSET_LI0_Motor2Selection    0U
#define LIN_SIGNAL_SIZE_LI0_Motor2Selection    2U
#define LIN_FLAG_BYTE_OFFSET_LI0_Motor2Selection    3U
#define LIN_FLAG_BIT_OFFSET_LI0_Motor2Selection    0U


#define LIN_BYTE_OFFSET_LI0_Motor2Temp    11U
#define LIN_BIT_OFFSET_LI0_Motor2Temp    0U
#define LIN_SIGNAL_SIZE_LI0_Motor2Temp    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Motor2Temp    4U
#define LIN_FLAG_BIT_OFFSET_LI0_Motor2Temp    0U


#define LIN_BYTE_OFFSET_LI0_MotorDirection    20U
#define LIN_BIT_OFFSET_LI0_MotorDirection    0U
#define LIN_SIGNAL_SIZE_LI0_MotorDirection    2U
#define LIN_FLAG_BYTE_OFFSET_LI0_MotorDirection    6U
#define LIN_FLAG_BIT_OFFSET_LI0_MotorDirection    0U


#define LIN_BYTE_OFFSET_LI0_MotorSpeed    20U
#define LIN_BIT_OFFSET_LI0_MotorSpeed    2U
#define LIN_SIGNAL_SIZE_LI0_MotorSpeed    10U
#define LIN_FLAG_BYTE_OFFSET_LI0_MotorSpeed    6U
#define LIN_FLAG_BIT_OFFSET_LI0_MotorSpeed    1U


#define LIN_BYTE_OFFSET_LI0_Motor1Position    2U
#define LIN_BIT_OFFSET_LI0_Motor1Position    0U
#define LIN_SIGNAL_SIZE_LI0_Motor1Position    32U
#define LIN_FLAG_BYTE_OFFSET_LI0_Motor1Position    1U
#define LIN_FLAG_BIT_OFFSET_LI0_Motor1Position    1U


#define LIN_BYTE_OFFSET_LI0_Motor2Position    12U
#define LIN_BIT_OFFSET_LI0_Motor2Position    0U
#define LIN_SIGNAL_SIZE_LI0_Motor2Position    32U
#define LIN_FLAG_BYTE_OFFSET_LI0_Motor2Position    4U
#define LIN_FLAG_BIT_OFFSET_LI0_Motor2Position    1U




#define LIN_FLAG_BYTE_OFFSET_LI0_Motor1Control             0
#define LIN_FLAG_BIT_OFFSET_LI0_Motor1Control              0

#define LIN_FLAG_BYTE_OFFSET_LI0_Motor1State_Cycl             1
#define LIN_FLAG_BIT_OFFSET_LI0_Motor1State_Cycl              0

#define LIN_FLAG_BYTE_OFFSET_LI0_Motor1State_Event             2
#define LIN_FLAG_BIT_OFFSET_LI0_Motor1State_Event              0

#define LIN_FLAG_BYTE_OFFSET_LI0_Motor2Control             3
#define LIN_FLAG_BIT_OFFSET_LI0_Motor2Control              0

#define LIN_FLAG_BYTE_OFFSET_LI0_Motor2State_Cycl             4
#define LIN_FLAG_BIT_OFFSET_LI0_Motor2State_Cycl              0

#define LIN_FLAG_BYTE_OFFSET_LI0_Motor2State_Event             5
#define LIN_FLAG_BIT_OFFSET_LI0_Motor2State_Event              0

#define LIN_FLAG_BYTE_OFFSET_LI0_MotorsControl             6
#define LIN_FLAG_BIT_OFFSET_LI0_MotorsControl              0


/**********************************************************************/
/***************        Static API Functions        *******************/
/**********************************************************************/
/*
 * the static signal access macros
 */


 
/* static access macros for signal LI0_Motor1ErrorCode */
 
#define l_u8_rd_LI0_Motor1ErrorCode() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1ErrorCode]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Motor1ErrorCode(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1ErrorCode] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1ErrorCode] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1ErrorCode],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1ErrorCode); \
    }


 
/* static access macros for signal LI0_Motor1ErrorValue */
 
#define l_u8_rd_LI0_Motor1ErrorValue() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1ErrorValue]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Motor1ErrorValue(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1ErrorValue] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1ErrorValue] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1ErrorValue],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1ErrorValue); \
    }


/* static access macros for signal LI0_Motor1LinError */

 
#define l_bool_rd_LI0_Motor1LinError() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1LinError], \
    LIN_BIT_OFFSET_LI0_Motor1LinError))

#define l_bool_wr_LI0_Motor1LinError(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1LinError], \
    LIN_BIT_OFFSET_LI0_Motor1LinError)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1LinError], \
    LIN_BIT_OFFSET_LI0_Motor1LinError));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1LinError],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1LinError);}
 
/* static access macros for signal LI0_Motor1Selection */
 
#define l_u8_rd_LI0_Motor1Selection() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1Selection]) >> 0U) & 0x03U))


#define l_u8_wr_LI0_Motor1Selection(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1Selection] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1Selection] & 0xfcU) | \
    (((A) << 0U) & 0x03U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1Selection],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1Selection); \
    }


 
/* static access macros for signal LI0_Motor1Temp */
 
#define l_u8_rd_LI0_Motor1Temp() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1Temp]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Motor1Temp(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1Temp] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1Temp] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1Temp],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1Temp); \
    }


 
/* static access macros for signal LI0_Motor2ErrorCode */
 
#define l_u8_rd_LI0_Motor2ErrorCode() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2ErrorCode]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Motor2ErrorCode(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2ErrorCode] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2ErrorCode] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2ErrorCode],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2ErrorCode); \
    }


 
/* static access macros for signal LI0_Motor2ErrorValue */
 
#define l_u8_rd_LI0_Motor2ErrorValue() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2ErrorValue]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Motor2ErrorValue(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2ErrorValue] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2ErrorValue] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2ErrorValue],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2ErrorValue); \
    }


/* static access macros for signal LI0_Motor2LinError */

 
#define l_bool_rd_LI0_Motor2LinError() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2LinError], \
    LIN_BIT_OFFSET_LI0_Motor2LinError))

#define l_bool_wr_LI0_Motor2LinError(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2LinError], \
    LIN_BIT_OFFSET_LI0_Motor2LinError)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2LinError], \
    LIN_BIT_OFFSET_LI0_Motor2LinError));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2LinError],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2LinError);}
 
/* static access macros for signal LI0_Motor2Selection */
 
#define l_u8_rd_LI0_Motor2Selection() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2Selection]) >> 0U) & 0x03U))


#define l_u8_wr_LI0_Motor2Selection(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2Selection] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2Selection] & 0xfcU) | \
    (((A) << 0U) & 0x03U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2Selection],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2Selection); \
    }


 
/* static access macros for signal LI0_Motor2Temp */
 
#define l_u8_rd_LI0_Motor2Temp() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2Temp]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Motor2Temp(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2Temp] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2Temp] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2Temp],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2Temp); \
    }


 
/* static access macros for signal LI0_MotorDirection */
 
#define l_u8_rd_LI0_MotorDirection() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorDirection]) >> 0U) & 0x03U))


#define l_u8_wr_LI0_MotorDirection(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorDirection] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorDirection] & 0xfcU) | \
    (((A) << 0U) & 0x03U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MotorDirection],\
         LIN_FLAG_BIT_OFFSET_LI0_MotorDirection); \
    }


 
/* static access macros for signal LI0_MotorSpeed */
 
#define l_u16_rd_LI0_MotorSpeed() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorSpeed] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorSpeed + 1U] << 8U)) >> 2U) & 0x3ffU))


#define l_u16_wr_LI0_MotorSpeed(A) \
    { \
    buffer_backup_data[0U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorSpeed]; \
    lin_frame_updating_flag_tbl[LI0_MotorsControl] |= (1U << 0); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorSpeed] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorSpeed] & 0x03U) | \
    (((A) << 2U) & 0xfcU)); \
    buffer_backup_data[0U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorSpeed + 1U]; \
    lin_frame_updating_flag_tbl[LI0_MotorsControl] |= (1U << (0 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorSpeed + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorSpeed + 1U] & 0xf0U) | \
    (((A) >> 6U) & 0x0fU)); \
    lin_frame_updating_flag_tbl[LI0_MotorsControl] &= (~(0x03 << 0)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MotorSpeed],\
         LIN_FLAG_BIT_OFFSET_LI0_MotorSpeed); \
    }


/* static access macros for signal LI0_Motor1Position */
 
#define l_bytes_rd_LI0_Motor1Position(start, count, data) \
    {l_u8       i; \
     for (i = 0; i < (count); ++i)  (data)[i] = lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1Position + i + (start)];}

#define l_bytes_wr_LI0_Motor1Position(start, count, data) \
    {l_u8       i; \
     for (i = 0; i < (count); ++i) \
     { \
        buffer_backup_data[i + (start) + 1] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1Position + i + (start)]; \
        lin_frame_updating_flag_tbl[LI0_Motor1State_Cycl] |= (1 << (i + (start) + 1)); \
        lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor1Position + i + (start)]  = (data)[i]; \
     } \
     lin_frame_updating_flag_tbl[LI0_Motor1State_Cycl] &= (~(((1 << count) -1) << (start + 1))); \
     LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1Position],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1Position);}
/* static access macros for signal LI0_Motor2Position */
 
#define l_bytes_rd_LI0_Motor2Position(start, count, data) \
    {l_u8       i; \
     for (i = 0; i < (count); ++i)  (data)[i] = lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2Position + i + (start)];}

#define l_bytes_wr_LI0_Motor2Position(start, count, data) \
    {l_u8       i; \
     for (i = 0; i < (count); ++i) \
     { \
        buffer_backup_data[i + (start) + 1] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2Position + i + (start)]; \
        lin_frame_updating_flag_tbl[LI0_Motor2State_Cycl] |= (1 << (i + (start) + 1)); \
        lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Motor2Position + i + (start)]  = (data)[i]; \
     } \
     lin_frame_updating_flag_tbl[LI0_Motor2State_Cycl] &= (~(((1 << count) -1) << (start + 1))); \
     LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2Position],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2Position);}


/* Signal flag APIs */

#define l_flg_tst_LI0_Motor1ErrorCode_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1ErrorCode],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1ErrorCode)
#define l_flg_clr_LI0_Motor1ErrorCode_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1ErrorCode],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1ErrorCode)

#define l_flg_tst_LI0_Motor1ErrorValue_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1ErrorValue],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1ErrorValue)
#define l_flg_clr_LI0_Motor1ErrorValue_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1ErrorValue],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1ErrorValue)

#define l_flg_tst_LI0_Motor1LinError_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1LinError],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1LinError)
#define l_flg_clr_LI0_Motor1LinError_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1LinError],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1LinError)

#define l_flg_tst_LI0_Motor1Selection_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1Selection],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1Selection)
#define l_flg_clr_LI0_Motor1Selection_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1Selection],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1Selection)

#define l_flg_tst_LI0_Motor1Temp_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1Temp],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1Temp)
#define l_flg_clr_LI0_Motor1Temp_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1Temp],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1Temp)

#define l_flg_tst_LI0_Motor2ErrorCode_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2ErrorCode],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2ErrorCode)
#define l_flg_clr_LI0_Motor2ErrorCode_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2ErrorCode],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2ErrorCode)

#define l_flg_tst_LI0_Motor2ErrorValue_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2ErrorValue],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2ErrorValue)
#define l_flg_clr_LI0_Motor2ErrorValue_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2ErrorValue],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2ErrorValue)

#define l_flg_tst_LI0_Motor2LinError_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2LinError],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2LinError)
#define l_flg_clr_LI0_Motor2LinError_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2LinError],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2LinError)

#define l_flg_tst_LI0_Motor2Selection_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2Selection],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2Selection)
#define l_flg_clr_LI0_Motor2Selection_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2Selection],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2Selection)

#define l_flg_tst_LI0_Motor2Temp_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2Temp],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2Temp)
#define l_flg_clr_LI0_Motor2Temp_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2Temp],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2Temp)

#define l_flg_tst_LI0_MotorDirection_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MotorDirection],\
         LIN_FLAG_BIT_OFFSET_LI0_MotorDirection)
#define l_flg_clr_LI0_MotorDirection_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MotorDirection],\
         LIN_FLAG_BIT_OFFSET_LI0_MotorDirection)

#define l_flg_tst_LI0_MotorSpeed_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MotorSpeed],\
         LIN_FLAG_BIT_OFFSET_LI0_MotorSpeed)
#define l_flg_clr_LI0_MotorSpeed_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MotorSpeed],\
         LIN_FLAG_BIT_OFFSET_LI0_MotorSpeed)

#define l_flg_tst_LI0_Motor1Position_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1Position],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1Position)
#define l_flg_clr_LI0_Motor1Position_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor1Position],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor1Position)

#define l_flg_tst_LI0_Motor2Position_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2Position],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2Position)
#define l_flg_clr_LI0_Motor2Position_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Motor2Position],\
         LIN_FLAG_BIT_OFFSET_LI0_Motor2Position)



/* Frame flag APIs */

   /* Interface_name = LI0 */

 #define l_flg_tst_LI0_Motor1Control_flag() \
          lin_frame_flag_tbl[LI0_Motor1Control]
 #define l_flg_clr_LI0_Motor1Control_flag() \
          lin_frame_flag_tbl[LI0_Motor1Control] = 0

 #define l_flg_tst_LI0_Motor1State_Cycl_flag() \
          lin_frame_flag_tbl[LI0_Motor1State_Cycl]
 #define l_flg_clr_LI0_Motor1State_Cycl_flag() \
          lin_frame_flag_tbl[LI0_Motor1State_Cycl] = 0

 #define l_flg_tst_LI0_Motor1State_Event_flag() \
          lin_frame_flag_tbl[LI0_Motor1State_Event]
 #define l_flg_clr_LI0_Motor1State_Event_flag() \
          lin_frame_flag_tbl[LI0_Motor1State_Event] = 0

 #define l_flg_tst_LI0_Motor2Control_flag() \
          lin_frame_flag_tbl[LI0_Motor2Control]
 #define l_flg_clr_LI0_Motor2Control_flag() \
          lin_frame_flag_tbl[LI0_Motor2Control] = 0

 #define l_flg_tst_LI0_Motor2State_Cycl_flag() \
          lin_frame_flag_tbl[LI0_Motor2State_Cycl]
 #define l_flg_clr_LI0_Motor2State_Cycl_flag() \
          lin_frame_flag_tbl[LI0_Motor2State_Cycl] = 0

 #define l_flg_tst_LI0_Motor2State_Event_flag() \
          lin_frame_flag_tbl[LI0_Motor2State_Event]
 #define l_flg_clr_LI0_Motor2State_Event_flag() \
          lin_frame_flag_tbl[LI0_Motor2State_Event] = 0

 #define l_flg_tst_LI0_MotorsControl_flag() \
          lin_frame_flag_tbl[LI0_MotorsControl]
 #define l_flg_clr_LI0_MotorsControl_flag() \
          lin_frame_flag_tbl[LI0_MotorsControl] = 0

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

 #define l_flg_tst_LI0_SporadicControlFrame_flag() \
          lin_frame_flag_tbl[LI0_SporadicControlFrame]
 #define l_flg_clr_LI0_SporadicControlFrame_flag() \
          lin_frame_flag_tbl[LI0_SporadicControlFrame] = 0



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