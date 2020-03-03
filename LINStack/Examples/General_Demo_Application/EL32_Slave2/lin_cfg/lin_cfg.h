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
* @date      Wed Feb 27 13:21:50 ICT 2019
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

#define LIN_BAUD_RATE    19200         /*For slave*/
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
#define LIN_FRAME_BUF_SIZE          4
#define LIN_FLAG_BUF_SIZE           3

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

   LI0_Cluster1Potentiometer2

   , LI0_Cluster1Slave2Error
  
   , LI0_SlaveIdentifier
  
   , LI0_ResetSignal
  
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

   LI0_LedControl

   , LI0_ResetFrame
  
   , LI0_Cluster1Slave2Info
  
   , LI0_LedControlFrame
  
   , LI0_ResetControlFrame
  
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



#define LIN_BYTE_OFFSET_LI0_Cluster1Potentiometer2    2U
#define LIN_BIT_OFFSET_LI0_Cluster1Potentiometer2    0U
#define LIN_SIGNAL_SIZE_LI0_Cluster1Potentiometer2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Potentiometer2    2U
#define LIN_FLAG_BIT_OFFSET_LI0_Cluster1Potentiometer2    0U


#define LIN_BYTE_OFFSET_LI0_Cluster1Slave2Error    3U
#define LIN_BIT_OFFSET_LI0_Cluster1Slave2Error    0U
#define LIN_SIGNAL_SIZE_LI0_Cluster1Slave2Error    1U
#define LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Slave2Error    2U
#define LIN_FLAG_BIT_OFFSET_LI0_Cluster1Slave2Error    1U


#define LIN_BYTE_OFFSET_LI0_SlaveIdentifier    0U
#define LIN_BIT_OFFSET_LI0_SlaveIdentifier    0U
#define LIN_SIGNAL_SIZE_LI0_SlaveIdentifier    2U
#define LIN_FLAG_BYTE_OFFSET_LI0_SlaveIdentifier    0U
#define LIN_FLAG_BIT_OFFSET_LI0_SlaveIdentifier    0U


#define LIN_BYTE_OFFSET_LI0_ResetSignal    1U
#define LIN_BIT_OFFSET_LI0_ResetSignal    0U
#define LIN_SIGNAL_SIZE_LI0_ResetSignal    2U
#define LIN_FLAG_BYTE_OFFSET_LI0_ResetSignal    1U
#define LIN_FLAG_BIT_OFFSET_LI0_ResetSignal    0U




#define LIN_FLAG_BYTE_OFFSET_LI0_LedControl             0
#define LIN_FLAG_BIT_OFFSET_LI0_LedControl              0

#define LIN_FLAG_BYTE_OFFSET_LI0_ResetFrame             1
#define LIN_FLAG_BIT_OFFSET_LI0_ResetFrame              0

#define LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Slave2Info             2
#define LIN_FLAG_BIT_OFFSET_LI0_Cluster1Slave2Info              0


/**********************************************************************/
/***************        Static API Functions        *******************/
/**********************************************************************/
/*
 * the static signal access macros
 */


 
/* static access macros for signal LI0_Cluster1Potentiometer2 */
 
#define l_u8_rd_LI0_Cluster1Potentiometer2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster1Potentiometer2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Cluster1Potentiometer2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster1Potentiometer2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster1Potentiometer2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Potentiometer2],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1Potentiometer2); \
    }


/* static access macros for signal LI0_Cluster1Slave2Error */

 
#define l_bool_rd_LI0_Cluster1Slave2Error() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster1Slave2Error], \
    LIN_BIT_OFFSET_LI0_Cluster1Slave2Error))

#define l_bool_wr_LI0_Cluster1Slave2Error(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster1Slave2Error], \
    LIN_BIT_OFFSET_LI0_Cluster1Slave2Error)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster1Slave2Error], \
    LIN_BIT_OFFSET_LI0_Cluster1Slave2Error));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Slave2Error],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1Slave2Error);}
 
/* static access macros for signal LI0_SlaveIdentifier */
 
#define l_u8_rd_LI0_SlaveIdentifier() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SlaveIdentifier]) >> 0U) & 0x03U))


#define l_u8_wr_LI0_SlaveIdentifier(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SlaveIdentifier] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SlaveIdentifier] & 0xfcU) | \
    (((A) << 0U) & 0x03U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SlaveIdentifier],\
         LIN_FLAG_BIT_OFFSET_LI0_SlaveIdentifier); \
    }


 
/* static access macros for signal LI0_ResetSignal */
 
#define l_u8_rd_LI0_ResetSignal() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_ResetSignal]) >> 0U) & 0x03U))


#define l_u8_wr_LI0_ResetSignal(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_ResetSignal] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_ResetSignal] & 0xfcU) | \
    (((A) << 0U) & 0x03U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_ResetSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_ResetSignal); \
    }




/* Signal flag APIs */

#define l_flg_tst_LI0_Cluster1Potentiometer2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Potentiometer2],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1Potentiometer2)
#define l_flg_clr_LI0_Cluster1Potentiometer2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Potentiometer2],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1Potentiometer2)

#define l_flg_tst_LI0_Cluster1Slave2Error_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Slave2Error],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1Slave2Error)
#define l_flg_clr_LI0_Cluster1Slave2Error_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Slave2Error],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1Slave2Error)

#define l_flg_tst_LI0_SlaveIdentifier_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SlaveIdentifier],\
         LIN_FLAG_BIT_OFFSET_LI0_SlaveIdentifier)
#define l_flg_clr_LI0_SlaveIdentifier_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SlaveIdentifier],\
         LIN_FLAG_BIT_OFFSET_LI0_SlaveIdentifier)

#define l_flg_tst_LI0_ResetSignal_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_ResetSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_ResetSignal)
#define l_flg_clr_LI0_ResetSignal_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_ResetSignal],\
         LIN_FLAG_BIT_OFFSET_LI0_ResetSignal)



/* Frame flag APIs */

   /* Interface_name = LI0 */

 #define l_flg_tst_LI0_LedControl_flag() \
          lin_frame_flag_tbl[LI0_LedControl]
 #define l_flg_clr_LI0_LedControl_flag() \
          lin_frame_flag_tbl[LI0_LedControl] = 0

 #define l_flg_tst_LI0_ResetFrame_flag() \
          lin_frame_flag_tbl[LI0_ResetFrame]
 #define l_flg_clr_LI0_ResetFrame_flag() \
          lin_frame_flag_tbl[LI0_ResetFrame] = 0

 #define l_flg_tst_LI0_Cluster1Slave2Info_flag() \
          lin_frame_flag_tbl[LI0_Cluster1Slave2Info]
 #define l_flg_clr_LI0_Cluster1Slave2Info_flag() \
          lin_frame_flag_tbl[LI0_Cluster1Slave2Info] = 0

 #define l_flg_tst_LI0_LedControlFrame_flag() \
          lin_frame_flag_tbl[LI0_LedControlFrame]
 #define l_flg_clr_LI0_LedControlFrame_flag() \
          lin_frame_flag_tbl[LI0_LedControlFrame] = 0

 #define l_flg_tst_LI0_ResetControlFrame_flag() \
          lin_frame_flag_tbl[LI0_ResetControlFrame]
 #define l_flg_clr_LI0_ResetControlFrame_flag() \
          lin_frame_flag_tbl[LI0_ResetControlFrame] = 0

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