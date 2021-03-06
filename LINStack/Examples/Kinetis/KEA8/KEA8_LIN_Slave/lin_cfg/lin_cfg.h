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
* @date      Fri May 24 16:43:48 ICT 2019
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

#define UART_ADDR        UART0_ADDR    /* For slave */


#define LIN_BAUD_RATE    9600    	 /*For slave*/
/**********************************************************************/
/***************          Diagnostic class selection  *****************/
/**********************************************************************/
#define _DIAG_CLASS_I_          0
#define _DIAG_CLASS_II_         1
#define _DIAG_CLASS_III_        2

#define _DIAG_CLASS_SUPPORT_    _DIAG_CLASS_I_

#define MAX_LENGTH_SERVICE 6

#define MAX_QUEUE_SIZE 1


#define _DIAG_NUMBER_OF_SERVICES_    2

#define DIAGSRV_READ_BY_IDENTIFIER_ORDER    0

#define DIAGSRV_ASSIGN_FRAME_ID_RANGE_ORDER    1


/**************** FRAME SUPPORT DEFINITION ******************/
#define _TL_SINGLE_FRAME_       0
#define _TL_MULTI_FRAME_        1

#define _TL_FRAME_SUPPORT_      _TL_SINGLE_FRAME_

/* frame buffer size */
#define LIN_FRAME_BUF_SIZE			24
#define LIN_FLAG_BUF_SIZE			4

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
#define LIN_NUM_OF_SIGS  5
/* List of signals */
typedef enum {

   /* Interface_name = LI0 */

   LI0_MotorLinError

   , LI0_MotorTemp
  
   , LI0_sigMotorState1
  
   , LI0_signal1
  
   , LI0_sig_MotorQuery1
  
} l_signal_handle;
/**********************************************************************/
/*****************               Frame             ********************/
/**********************************************************************/
/* Number of frames */
#define LIN_NUM_OF_FRMS  8
/* List of frames */
typedef enum {
/* All frames for master node */

   /* Interface_name = LI0 */

   LI0_MotorControl

   , LI0_MotorQuery
  
   , LI0_MotorState_Cycl
  
   , LI0_MotorState_Event
  
   , LI0_ETF_MotorState_Event
  
   , LI0_ETF_MotorState_Cycl
  
   , LI0_MasterReq
  
   , LI0_SlaveResp
  
} l_frame_handle;
/**********************************************************************/
/***************             Configuration          *******************/
/**********************************************************************/
/* Size of configuration in ROM and RAM used for interface: LI1 */
#define LIN_SIZE_OF_CFG  10
#define LIN_CFG_FRAME_NUM  6
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



#define LIN_BYTE_OFFSET_LI0_MotorLinError    18U
#define LIN_BIT_OFFSET_LI0_MotorLinError    0U
#define LIN_SIGNAL_SIZE_LI0_MotorLinError    1U
#define LIN_FLAG_BYTE_OFFSET_LI0_MotorLinError    2U
#define LIN_FLAG_BIT_OFFSET_LI0_MotorLinError    1U


#define LIN_BYTE_OFFSET_LI0_MotorTemp    14U
#define LIN_BIT_OFFSET_LI0_MotorTemp    0U
#define LIN_SIGNAL_SIZE_LI0_MotorTemp    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_MotorTemp    2U
#define LIN_FLAG_BIT_OFFSET_LI0_MotorTemp    0U


#define LIN_BYTE_OFFSET_LI0_sigMotorState1    22U
#define LIN_BIT_OFFSET_LI0_sigMotorState1    0U
#define LIN_SIGNAL_SIZE_LI0_sigMotorState1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_sigMotorState1    3U
#define LIN_FLAG_BIT_OFFSET_LI0_sigMotorState1    0U


#define LIN_BYTE_OFFSET_LI0_signal1    2U
#define LIN_BIT_OFFSET_LI0_signal1    0U
#define LIN_SIGNAL_SIZE_LI0_signal1    16U
#define LIN_FLAG_BYTE_OFFSET_LI0_signal1    0U
#define LIN_FLAG_BIT_OFFSET_LI0_signal1    0U


#define LIN_BYTE_OFFSET_LI0_sig_MotorQuery1    8U
#define LIN_BIT_OFFSET_LI0_sig_MotorQuery1    0U
#define LIN_SIGNAL_SIZE_LI0_sig_MotorQuery1    40U
#define LIN_FLAG_BYTE_OFFSET_LI0_sig_MotorQuery1    1U
#define LIN_FLAG_BIT_OFFSET_LI0_sig_MotorQuery1    0U




#define LIN_FLAG_BYTE_OFFSET_LI0_MotorControl             0
#define LIN_FLAG_BIT_OFFSET_LI0_MotorControl              0

#define LIN_FLAG_BYTE_OFFSET_LI0_MotorQuery             1
#define LIN_FLAG_BIT_OFFSET_LI0_MotorQuery              0

#define LIN_FLAG_BYTE_OFFSET_LI0_MotorState_Cycl             2
#define LIN_FLAG_BIT_OFFSET_LI0_MotorState_Cycl              0

#define LIN_FLAG_BYTE_OFFSET_LI0_MotorState_Event             3
#define LIN_FLAG_BIT_OFFSET_LI0_MotorState_Event              0


/**********************************************************************/
/***************        Static API Functions        *******************/
/**********************************************************************/
/*
 * the static signal access macros
 */


/* static access macros for signal LI0_MotorLinError */

 
#define l_bool_rd_LI0_MotorLinError() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorLinError], \
    LIN_BIT_OFFSET_LI0_MotorLinError))

#define l_bool_wr_LI0_MotorLinError(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorLinError], \
    LIN_BIT_OFFSET_LI0_MotorLinError)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorLinError], \
    LIN_BIT_OFFSET_LI0_MotorLinError));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MotorLinError],\
         LIN_FLAG_BIT_OFFSET_LI0_MotorLinError);}
 
/* static access macros for signal LI0_MotorTemp */
 
#define l_u8_rd_LI0_MotorTemp() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorTemp]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_MotorTemp(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorTemp] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_MotorTemp] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MotorTemp],\
         LIN_FLAG_BIT_OFFSET_LI0_MotorTemp); \
    }


 
/* static access macros for signal LI0_sigMotorState1 */
 
#define l_u8_rd_LI0_sigMotorState1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_sigMotorState1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_sigMotorState1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_sigMotorState1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_sigMotorState1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_sigMotorState1],\
         LIN_FLAG_BIT_OFFSET_LI0_sigMotorState1); \
    }


 
/* static access macros for signal LI0_signal1 */
 
#define l_u16_rd_LI0_signal1() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_signal1] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_signal1 + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI0_signal1(A) \
    { \
    buffer_backup_data[2U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_signal1]; \
    lin_frame_updating_flag_tbl[LI0_MotorControl] |= (1U << 2); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_signal1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_signal1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[2U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_signal1 + 1U]; \
    lin_frame_updating_flag_tbl[LI0_MotorControl] |= (1U << (2 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_signal1 + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_signal1 + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI0_MotorControl] &= (~(0x03 << 2)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_signal1],\
         LIN_FLAG_BIT_OFFSET_LI0_signal1); \
    }


/* static access macros for signal LI0_sig_MotorQuery1 */
 
#define l_bytes_rd_LI0_sig_MotorQuery1(start, count, data) \
    {l_u8       i; \
     for (i = 0; i < (count); ++i)  (data)[i] = lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_sig_MotorQuery1 + i + (start)];}

#define l_bytes_wr_LI0_sig_MotorQuery1(start, count, data) \
    {l_u8       i; \
     for (i = 0; i < (count); ++i) \
     { \
        buffer_backup_data[i + (start) + 0] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_sig_MotorQuery1 + i + (start)]; \
        lin_frame_updating_flag_tbl[LI0_MotorQuery] |= (1 << (i + (start) + 0)); \
        lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_sig_MotorQuery1 + i + (start)]  = (data)[i]; \
     } \
     lin_frame_updating_flag_tbl[LI0_MotorQuery] &= (~(((1 << count) -1) << (start + 0))); \
     LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_sig_MotorQuery1],\
         LIN_FLAG_BIT_OFFSET_LI0_sig_MotorQuery1);}


/* Signal flag APIs */

#define l_flg_tst_LI0_MotorLinError_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MotorLinError],\
         LIN_FLAG_BIT_OFFSET_LI0_MotorLinError)
#define l_flg_clr_LI0_MotorLinError_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MotorLinError],\
         LIN_FLAG_BIT_OFFSET_LI0_MotorLinError)

#define l_flg_tst_LI0_MotorTemp_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MotorTemp],\
         LIN_FLAG_BIT_OFFSET_LI0_MotorTemp)
#define l_flg_clr_LI0_MotorTemp_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_MotorTemp],\
         LIN_FLAG_BIT_OFFSET_LI0_MotorTemp)

#define l_flg_tst_LI0_sigMotorState1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_sigMotorState1],\
         LIN_FLAG_BIT_OFFSET_LI0_sigMotorState1)
#define l_flg_clr_LI0_sigMotorState1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_sigMotorState1],\
         LIN_FLAG_BIT_OFFSET_LI0_sigMotorState1)

#define l_flg_tst_LI0_signal1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_signal1],\
         LIN_FLAG_BIT_OFFSET_LI0_signal1)
#define l_flg_clr_LI0_signal1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_signal1],\
         LIN_FLAG_BIT_OFFSET_LI0_signal1)

#define l_flg_tst_LI0_sig_MotorQuery1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_sig_MotorQuery1],\
         LIN_FLAG_BIT_OFFSET_LI0_sig_MotorQuery1)
#define l_flg_clr_LI0_sig_MotorQuery1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_sig_MotorQuery1],\
         LIN_FLAG_BIT_OFFSET_LI0_sig_MotorQuery1)



/* Frame flag APIs */

   /* Interface_name = LI0 */

 #define l_flg_tst_LI0_MotorControl_flag() \
          lin_frame_flag_tbl[LI0_MotorControl]
 #define l_flg_clr_LI0_MotorControl_flag() \
          lin_frame_flag_tbl[LI0_MotorControl] = 0

 #define l_flg_tst_LI0_MotorQuery_flag() \
          lin_frame_flag_tbl[LI0_MotorQuery]
 #define l_flg_clr_LI0_MotorQuery_flag() \
          lin_frame_flag_tbl[LI0_MotorQuery] = 0

 #define l_flg_tst_LI0_MotorState_Cycl_flag() \
          lin_frame_flag_tbl[LI0_MotorState_Cycl]
 #define l_flg_clr_LI0_MotorState_Cycl_flag() \
          lin_frame_flag_tbl[LI0_MotorState_Cycl] = 0

 #define l_flg_tst_LI0_MotorState_Event_flag() \
          lin_frame_flag_tbl[LI0_MotorState_Event]
 #define l_flg_clr_LI0_MotorState_Event_flag() \
          lin_frame_flag_tbl[LI0_MotorState_Event] = 0

 #define l_flg_tst_LI0_ETF_MotorState_Event_flag() \
          lin_frame_flag_tbl[LI0_ETF_MotorState_Event]
 #define l_flg_clr_LI0_ETF_MotorState_Event_flag() \
          lin_frame_flag_tbl[LI0_ETF_MotorState_Event] = 0

 #define l_flg_tst_LI0_ETF_MotorState_Cycl_flag() \
          lin_frame_flag_tbl[LI0_ETF_MotorState_Cycl]
 #define l_flg_clr_LI0_ETF_MotorState_Cycl_flag() \
          lin_frame_flag_tbl[LI0_ETF_MotorState_Cycl] = 0

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