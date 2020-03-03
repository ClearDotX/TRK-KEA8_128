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
* @date      Wed Feb 27 13:21:46 ICT 2019
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
#define LIN_FRAME_BUF_SIZE          9
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
#define LIN_NUM_OF_SIGS  9
/* List of signals */
typedef enum {

   /* Interface_name = LI0 */

   LI0_Cluster1Potentiometer1

   , LI0_Cluster1LightSensor1
  
   , LI0_Cluster1Potentiometer2
  
   , LI0_Cluster2PotentiometerA
  
   , LI0_Cluster2LightSensorA
  
   , LI0_Cluster2PotentiometerB
  
   , LI0_Cluster2PotentiometerC
  
   , LI0_GatewayError
  
   , LI0_ClusterIdentifier
  
} l_signal_handle;
/**********************************************************************/
/*****************               Frame             ********************/
/**********************************************************************/
/* Number of frames */
#define LIN_NUM_OF_FRMS  6
/* List of frames */
typedef enum {
/* All frames for master node */

   /* Interface_name = LI0 */

   LI0_GatewayControl

   , LI0_PotentiometerInfo
  
   , LI0_LightSensorInfo
  
   , LI0_MasterReq
  
   , LI0_SlaveResp
  
   , LI0_SporadicControlFrame
  
} l_frame_handle;
/**********************************************************************/
/***************        schedule table       *******************/
/**********************************************************************/
/* Number of schedule tables */
#define  LIN_NUM_OF_SCHD_TBL   5
/* List of schedules */
typedef enum {

   /* Interface_name = LI0 */

   LI0_LIN_NULL_SCHEDULE

   ,LI0_GOTO_SLEEP_SCHEDULE
   
   ,LI0_MasterReqTable
   
   ,LI0_SlaveRespTable
   
   ,LI0_NormalTable
   
}l_schedule_handle;/**********************************************************************/
/***************             Configuration          *******************/
/**********************************************************************/

/* Size of configuration in ROM and RAM used for interface: LI0 */
#define LI0_LIN_SIZE_OF_CFG  8

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



#define LIN_BYTE_OFFSET_LI0_Cluster1Potentiometer1    1U
#define LIN_BIT_OFFSET_LI0_Cluster1Potentiometer1    0U
#define LIN_SIGNAL_SIZE_LI0_Cluster1Potentiometer1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Potentiometer1    1U
#define LIN_FLAG_BIT_OFFSET_LI0_Cluster1Potentiometer1    0U


#define LIN_BYTE_OFFSET_LI0_Cluster1LightSensor1    6U
#define LIN_BIT_OFFSET_LI0_Cluster1LightSensor1    0U
#define LIN_SIGNAL_SIZE_LI0_Cluster1LightSensor1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Cluster1LightSensor1    2U
#define LIN_FLAG_BIT_OFFSET_LI0_Cluster1LightSensor1    0U


#define LIN_BYTE_OFFSET_LI0_Cluster1Potentiometer2    2U
#define LIN_BIT_OFFSET_LI0_Cluster1Potentiometer2    0U
#define LIN_SIGNAL_SIZE_LI0_Cluster1Potentiometer2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Potentiometer2    1U
#define LIN_FLAG_BIT_OFFSET_LI0_Cluster1Potentiometer2    1U


#define LIN_BYTE_OFFSET_LI0_Cluster2PotentiometerA    3U
#define LIN_BIT_OFFSET_LI0_Cluster2PotentiometerA    0U
#define LIN_SIGNAL_SIZE_LI0_Cluster2PotentiometerA    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Cluster2PotentiometerA    1U
#define LIN_FLAG_BIT_OFFSET_LI0_Cluster2PotentiometerA    2U


#define LIN_BYTE_OFFSET_LI0_Cluster2LightSensorA    7U
#define LIN_BIT_OFFSET_LI0_Cluster2LightSensorA    0U
#define LIN_SIGNAL_SIZE_LI0_Cluster2LightSensorA    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Cluster2LightSensorA    2U
#define LIN_FLAG_BIT_OFFSET_LI0_Cluster2LightSensorA    1U


#define LIN_BYTE_OFFSET_LI0_Cluster2PotentiometerB    4U
#define LIN_BIT_OFFSET_LI0_Cluster2PotentiometerB    0U
#define LIN_SIGNAL_SIZE_LI0_Cluster2PotentiometerB    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Cluster2PotentiometerB    1U
#define LIN_FLAG_BIT_OFFSET_LI0_Cluster2PotentiometerB    3U


#define LIN_BYTE_OFFSET_LI0_Cluster2PotentiometerC    5U
#define LIN_BIT_OFFSET_LI0_Cluster2PotentiometerC    0U
#define LIN_SIGNAL_SIZE_LI0_Cluster2PotentiometerC    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_Cluster2PotentiometerC    1U
#define LIN_FLAG_BIT_OFFSET_LI0_Cluster2PotentiometerC    4U


#define LIN_BYTE_OFFSET_LI0_GatewayError    8U
#define LIN_BIT_OFFSET_LI0_GatewayError    0U
#define LIN_SIGNAL_SIZE_LI0_GatewayError    1U
#define LIN_FLAG_BYTE_OFFSET_LI0_GatewayError    2U
#define LIN_FLAG_BIT_OFFSET_LI0_GatewayError    2U


#define LIN_BYTE_OFFSET_LI0_ClusterIdentifier    0U
#define LIN_BIT_OFFSET_LI0_ClusterIdentifier    0U
#define LIN_SIGNAL_SIZE_LI0_ClusterIdentifier    2U
#define LIN_FLAG_BYTE_OFFSET_LI0_ClusterIdentifier    0U
#define LIN_FLAG_BIT_OFFSET_LI0_ClusterIdentifier    0U




#define LIN_FLAG_BYTE_OFFSET_LI0_GatewayControl             0
#define LIN_FLAG_BIT_OFFSET_LI0_GatewayControl              0

#define LIN_FLAG_BYTE_OFFSET_LI0_PotentiometerInfo             1
#define LIN_FLAG_BIT_OFFSET_LI0_PotentiometerInfo              0

#define LIN_FLAG_BYTE_OFFSET_LI0_LightSensorInfo             2
#define LIN_FLAG_BIT_OFFSET_LI0_LightSensorInfo              0


/**********************************************************************/
/***************        Static API Functions        *******************/
/**********************************************************************/
/*
 * the static signal access macros
 */


 
/* static access macros for signal LI0_Cluster1Potentiometer1 */
 
#define l_u8_rd_LI0_Cluster1Potentiometer1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster1Potentiometer1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Cluster1Potentiometer1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster1Potentiometer1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster1Potentiometer1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Potentiometer1],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1Potentiometer1); \
    }


 
/* static access macros for signal LI0_Cluster1LightSensor1 */
 
#define l_u8_rd_LI0_Cluster1LightSensor1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster1LightSensor1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Cluster1LightSensor1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster1LightSensor1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster1LightSensor1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1LightSensor1],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1LightSensor1); \
    }


 
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


 
/* static access macros for signal LI0_Cluster2PotentiometerA */
 
#define l_u8_rd_LI0_Cluster2PotentiometerA() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster2PotentiometerA]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Cluster2PotentiometerA(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster2PotentiometerA] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster2PotentiometerA] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster2PotentiometerA],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster2PotentiometerA); \
    }


 
/* static access macros for signal LI0_Cluster2LightSensorA */
 
#define l_u8_rd_LI0_Cluster2LightSensorA() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster2LightSensorA]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Cluster2LightSensorA(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster2LightSensorA] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster2LightSensorA] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster2LightSensorA],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster2LightSensorA); \
    }


 
/* static access macros for signal LI0_Cluster2PotentiometerB */
 
#define l_u8_rd_LI0_Cluster2PotentiometerB() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster2PotentiometerB]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Cluster2PotentiometerB(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster2PotentiometerB] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster2PotentiometerB] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster2PotentiometerB],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster2PotentiometerB); \
    }


 
/* static access macros for signal LI0_Cluster2PotentiometerC */
 
#define l_u8_rd_LI0_Cluster2PotentiometerC() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster2PotentiometerC]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_Cluster2PotentiometerC(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster2PotentiometerC] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_Cluster2PotentiometerC] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster2PotentiometerC],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster2PotentiometerC); \
    }


/* static access macros for signal LI0_GatewayError */

 
#define l_bool_rd_LI0_GatewayError() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_GatewayError], \
    LIN_BIT_OFFSET_LI0_GatewayError))

#define l_bool_wr_LI0_GatewayError(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_GatewayError], \
    LIN_BIT_OFFSET_LI0_GatewayError)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_GatewayError], \
    LIN_BIT_OFFSET_LI0_GatewayError));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_GatewayError],\
         LIN_FLAG_BIT_OFFSET_LI0_GatewayError);}
 
/* static access macros for signal LI0_ClusterIdentifier */
 
#define l_u8_rd_LI0_ClusterIdentifier() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_ClusterIdentifier]) >> 0U) & 0x03U))


#define l_u8_wr_LI0_ClusterIdentifier(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_ClusterIdentifier] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_ClusterIdentifier] & 0xfcU) | \
    (((A) << 0U) & 0x03U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_ClusterIdentifier],\
         LIN_FLAG_BIT_OFFSET_LI0_ClusterIdentifier); \
    }




/* Signal flag APIs */

#define l_flg_tst_LI0_Cluster1Potentiometer1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Potentiometer1],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1Potentiometer1)
#define l_flg_clr_LI0_Cluster1Potentiometer1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Potentiometer1],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1Potentiometer1)

#define l_flg_tst_LI0_Cluster1LightSensor1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1LightSensor1],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1LightSensor1)
#define l_flg_clr_LI0_Cluster1LightSensor1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1LightSensor1],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1LightSensor1)

#define l_flg_tst_LI0_Cluster1Potentiometer2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Potentiometer2],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1Potentiometer2)
#define l_flg_clr_LI0_Cluster1Potentiometer2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster1Potentiometer2],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster1Potentiometer2)

#define l_flg_tst_LI0_Cluster2PotentiometerA_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster2PotentiometerA],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster2PotentiometerA)
#define l_flg_clr_LI0_Cluster2PotentiometerA_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster2PotentiometerA],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster2PotentiometerA)

#define l_flg_tst_LI0_Cluster2LightSensorA_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster2LightSensorA],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster2LightSensorA)
#define l_flg_clr_LI0_Cluster2LightSensorA_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster2LightSensorA],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster2LightSensorA)

#define l_flg_tst_LI0_Cluster2PotentiometerB_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster2PotentiometerB],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster2PotentiometerB)
#define l_flg_clr_LI0_Cluster2PotentiometerB_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster2PotentiometerB],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster2PotentiometerB)

#define l_flg_tst_LI0_Cluster2PotentiometerC_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster2PotentiometerC],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster2PotentiometerC)
#define l_flg_clr_LI0_Cluster2PotentiometerC_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_Cluster2PotentiometerC],\
         LIN_FLAG_BIT_OFFSET_LI0_Cluster2PotentiometerC)

#define l_flg_tst_LI0_GatewayError_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_GatewayError],\
         LIN_FLAG_BIT_OFFSET_LI0_GatewayError)
#define l_flg_clr_LI0_GatewayError_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_GatewayError],\
         LIN_FLAG_BIT_OFFSET_LI0_GatewayError)

#define l_flg_tst_LI0_ClusterIdentifier_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_ClusterIdentifier],\
         LIN_FLAG_BIT_OFFSET_LI0_ClusterIdentifier)
#define l_flg_clr_LI0_ClusterIdentifier_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_ClusterIdentifier],\
         LIN_FLAG_BIT_OFFSET_LI0_ClusterIdentifier)



/* Frame flag APIs */

   /* Interface_name = LI0 */

 #define l_flg_tst_LI0_GatewayControl_flag() \
          lin_frame_flag_tbl[LI0_GatewayControl]
 #define l_flg_clr_LI0_GatewayControl_flag() \
          lin_frame_flag_tbl[LI0_GatewayControl] = 0

 #define l_flg_tst_LI0_PotentiometerInfo_flag() \
          lin_frame_flag_tbl[LI0_PotentiometerInfo]
 #define l_flg_clr_LI0_PotentiometerInfo_flag() \
          lin_frame_flag_tbl[LI0_PotentiometerInfo] = 0

 #define l_flg_tst_LI0_LightSensorInfo_flag() \
          lin_frame_flag_tbl[LI0_LightSensorInfo]
 #define l_flg_clr_LI0_LightSensorInfo_flag() \
          lin_frame_flag_tbl[LI0_LightSensorInfo] = 0

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