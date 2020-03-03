/******************************************************************************
* 
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2016 Freescale Semiconductor, Inc.
* Copyright 2016-2019 NXP
* ALL RIGHTS RESERVED.
* 
****************************************************************************//*!
*
* @file      lin_cfg.c
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Wed Feb 27 13:22:05 ICT 2019
*
* @brief     Common LIN configuration, data structure
*
******************************************************************************/
#include "lin_cfg.h"
#include "lin.h"
/* Mapping interface with hardware */
const lin_hardware_name lin_virtual_ifc[LIN_NUM_OF_IFCS] = {SCI1, SCI3, SCI5};
/* Low level response buffer */
l_u8 lin_lld_response_buffer[LIN_NUM_OF_IFCS][10];
 /* Successful transfer flags */
l_u8 lin_successful_transfer[LIN_NUM_OF_IFCS];
/* Error in response */
l_u8 lin_error_in_response[LIN_NUM_OF_IFCS];
/* Goto sleep flag */
l_u8 lin_goto_sleep_flg[LIN_NUM_OF_IFCS];
/* Save configuration flag */
l_u8 lin_save_configuration_flg[LIN_NUM_OF_IFCS] = {0, 0, 0};
 /* Next transmit tick */
l_u8 lin_next_transmit[LIN_NUM_OF_IFCS];
 /* lin word status */
lin_word_status_str lin_word_status[LIN_NUM_OF_IFCS];
/* current pid */
l_u8 lin_current_pid[LIN_NUM_OF_IFCS];

const l_signal_handle LI0_response_error_signal = LI0_GatewayError;

volatile l_u8 buffer_backup_data[8];

/* definition and initialization of signal array */
l_u8    lin_pFrameBuf[LIN_FRAME_BUF_SIZE] =
{


  0xfc /* 0 : 11111100 */ /* start of frame LI0_GatewayControl */



  ,0x00 /* 1 : 00000000 */ /* start of frame LI0_PotentiometerInfo */

  ,0x00 /* 2 : 00000000 */
  
  ,0x00 /* 3 : 00000000 */
  
  ,0x00 /* 4 : 00000000 */
  
  ,0x00 /* 5 : 00000000 */
  

  ,0x00 /* 6 : 00000000 */ /* start of frame LI0_LightSensorInfo */

  ,0x00 /* 7 : 00000000 */
  
  ,0xfe /* 8 : 11111110 */
  

  ,0xfc /* 9 : 11111100 */ /* start of frame LI1_ResetFrame */


  ,0xfc /* 10 : 11111100 */ /* start of frame LI1_LedControl */


  ,0x00 /* 11 : 00000000 */ /* start of frame LI1_Cluster1Slave1Info */

  ,0x00 /* 12 : 00000000 */
  
  ,0xfe /* 13 : 11111110 */
  

  ,0x00 /* 14 : 00000000 */ /* start of frame LI1_Cluster1Slave2Info */

  ,0xfe /* 15 : 11111110 */
  

  ,0xfc /* 16 : 11111100 */ /* start of frame LI2_ResetFrame */


  ,0xfc /* 17 : 11111100 */ /* start of frame LI2_LedControl */


  ,0x00 /* 18 : 00000000 */ /* start of frame LI2_Cluster2SlaveAInfo */

  ,0x00 /* 19 : 00000000 */
  
  ,0xfe /* 20 : 11111110 */
  

  ,0x00 /* 21 : 00000000 */ /* start of frame LI2_Cluster2SlaveBInfo */

  ,0xfe /* 22 : 11111110 */
  

  ,0x00 /* 23 : 00000000 */ /* start of frame LI2_Cluster2SlaveCInfo */

  ,0xfe /* 24 : 11111110 */
  
};

/* definition and initialization of signal array */
l_u8    lin_flag_handle_tbl[LIN_FLAG_BUF_SIZE] =
{


  0xFF /* 0: start of flag frame LI0_GatewayControl */



  ,0xFF /* 1: start of flag frame LI0_PotentiometerInfo */


  ,0xFF /* 2: start of flag frame LI0_LightSensorInfo */


  ,0xFF /* 3: start of flag frame LI1_ResetFrame */


  ,0xFF /* 4: start of flag frame LI1_LedControl */


  ,0xFF /* 5: start of flag frame LI1_Cluster1Slave1Info */


  ,0xFF /* 6: start of flag frame LI1_Cluster1Slave2Info */


  ,0xFF /* 7: start of flag frame LI2_ResetFrame */


  ,0xFF /* 8: start of flag frame LI2_LedControl */


  ,0xFF /* 9: start of flag frame LI2_Cluster2SlaveAInfo */


  ,0xFF /* 10: start of flag frame LI2_Cluster2SlaveBInfo */


  ,0xFF /* 11: start of flag frame LI2_Cluster2SlaveCInfo */

};

/*************************** Flag set when signal is updated ******************/
/* Diagnostic signal */
l_u8 lin_diag_signal_tbl[LIN_NUM_OF_IFCS][16];
/*****************************event trigger frame*****************************/
/* all event trigger frames for master node */


/*****************************sporadic frame*****************************/
/*all sporadic frames for master node*/

const l_u8 LI1_LedControlFrame_info_data[1] ={

   LI1_LedControl
  
};
const lin_associate_frame_struct LI1_LedControlFrame_info ={
   1
   ,&LI1_LedControlFrame_info_data[0]   
   ,0xFF
};

const l_u8 LI1_ResetControlFrame_info_data[1] ={

   LI1_ResetFrame
  
};
const lin_associate_frame_struct LI1_ResetControlFrame_info ={
   1
   ,&LI1_ResetControlFrame_info_data[0]   
   ,0xFF
};

const l_u8 LI2_LedControlFrame_info_data[1] ={

   LI2_LedControl
  
};
const lin_associate_frame_struct LI2_LedControlFrame_info ={
   1
   ,&LI2_LedControlFrame_info_data[0]   
   ,0xFF
};

const l_u8 LI2_ResetControlFrame_info_data[1] ={

   LI2_ResetFrame
  
};
const lin_associate_frame_struct LI2_ResetControlFrame_info ={
   1
   ,&LI2_ResetControlFrame_info_data[0]   
   ,0xFF
};

/**********************************  Frame table **********************************/
const lin_frame_struct lin_frame_tbl[LIN_NUM_OF_FRMS] ={

    { LIN_FRM_UNCD, 1, LIN_RES_SUB, 0, 0, 1   , (l_u8*)0 }

   ,{ LIN_FRM_UNCD, 5, LIN_RES_PUB, 1, 1, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 3, LIN_RES_PUB, 6, 2, 1 , (l_u8*)&LI0_response_error_signal }
  
   ,{ LIN_FRM_SPRDC, 1, LIN_RES_SUB, 0, 0, 0 , (l_u8*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_SUB, 0, 0, 0 , (l_u8*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_PUB, 0, 0, 0 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 1, LIN_RES_PUB, 9, 3, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 1, LIN_RES_PUB, 10, 4, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 3, LIN_RES_SUB, 11, 5, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 2, LIN_RES_SUB, 14, 6, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_SPRDC, 1, LIN_RES_PUB, 0, 0, 0 , (l_u8*)&LI1_LedControlFrame_info }
  
   ,{ LIN_FRM_SPRDC, 1, LIN_RES_PUB, 0, 0, 0 , (l_u8*)&LI1_ResetControlFrame_info }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_PUB, 0, 0, 0 , (l_u8*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_SUB, 0, 0, 0 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 1, LIN_RES_PUB, 16, 7, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 1, LIN_RES_PUB, 17, 8, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 3, LIN_RES_SUB, 18, 9, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 2, LIN_RES_SUB, 21, 10, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 2, LIN_RES_SUB, 23, 11, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_SPRDC, 1, LIN_RES_PUB, 0, 0, 0 , (l_u8*)&LI2_LedControlFrame_info }
  
   ,{ LIN_FRM_SPRDC, 1, LIN_RES_PUB, 0, 0, 0 , (l_u8*)&LI2_ResetControlFrame_info }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_PUB, 0, 0, 0 , (l_u8*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_SUB, 0, 0, 0 , (l_u8*)0 }
  
};

/*********************************** Frame flag Initialization **********************/
/*************************** Frame flag for send/receive successfully ***************/
l_bool lin_frame_flag_tbl[LIN_NUM_OF_FRMS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
/*************************** Frame flag for updating signal in frame ****************/
volatile l_u8 lin_frame_updating_flag_tbl[LIN_NUM_OF_FRMS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


/**************************** Lin configuration Initialization ***********************/
/* max_response_frame_timeout = round((1.4x(10+Nx10)xTbit)/Tbase_period) + 3 */
const l_u16 lin_max_frame_res_timeout_val[LIN_NUM_OF_IFCS][8]= {

   {6, 7, 9, 10, 12, 13, 15, 16 }
  

   ,{6, 7, 9, 10, 12, 13, 15, 16}
  
   ,{9, 12, 15, 18, 21, 23, 26, 29}
  
};


l_u8 LI0_lin_configuration_RAM[LI0_LIN_SIZE_OF_CFG]= {0x00, 0x01, 0x02, 0x03, 0x3C, 0x3D ,0xFF};

l_u8 LI1_lin_configuration_RAM[LI1_LIN_SIZE_OF_CFG]= {0x00, 0x04, 0x05, 0x06, 0x07, 0x3C, 0x3D, 0xFF, 0xFF ,0xFF};

l_u8 LI2_lin_configuration_RAM[LI2_LIN_SIZE_OF_CFG]= {0x00, 0x08, 0x09, 0x0B, 0x0C, 0x0D, 0x3C, 0x3D, 0xFF, 0xFF ,0xFF};


const l_u16  LI0_lin_configuration_ROM[LI0_LIN_SIZE_OF_CFG]= {0x0000, 0x01, 0x02, 0x03, 0x3C, 0x3D ,0xFFFF};

const l_u16  LI1_lin_configuration_ROM[LI1_LIN_SIZE_OF_CFG]= {0x0000, 0x04, 0x05, 0x06, 0x07, 0x3C, 0x3D, 0xFF, 0xFF ,0xFFFF};

const l_u16  LI2_lin_configuration_ROM[LI2_LIN_SIZE_OF_CFG]= {0x0000, 0x08, 0x09, 0x0B, 0x0C, 0x0D, 0x3C, 0x3D, 0xFF, 0xFF ,0xFFFF};



static l_u16 LI0_lin_response_error_byte_offset[1] = {LIN_BYTE_OFFSET_LI0_GatewayError};

static l_u8 LI0_lin_response_error_bit_offset[1] = {LIN_BIT_OFFSET_LI0_GatewayError};


/**************** Node attributes Initialization  ****************************/


lin_node_attribute  LI0_node_attribute = {
   LIN_PROTOCOL_21,    /*lin_protocol_version*/
   0x01,    /*configured_NAD*/
   0x0A,    /*initial_NAD*/
   { 0x001E, 0x0001, 0x0000 },   /*{<supplier_id>,<function_id>,<variant>}*/
   LI0_GatewayError,    /*<interface_name>_< response_error>*/
   1,                                 /*number of frame contain error signal*/
   LI0_lin_response_error_byte_offset,                  /*<interface_name>_< response_error>*/
   LI0_lin_response_error_bit_offset,                  /*<interface_name>_< response_error>*/
   0,    /*<num_faut_state_signal>*/
   (const l_signal_handle*)0,
   100,    /*<P2_min>*/
   20,    /*<ST_min>*/
   1000,   /*< N_As_timeout >*/
   1000  /*<N_Cr_timeout >*/
};




/********************** Go to sleep Initialization *************************/
/* Delay of this schedule table is: (1.4*(34+10*(8+1))*1000/LIN_speed+jitter) ms */
/* then rounded up to a value is multiple of time base */
const lin_schedule_data LI1_lin_gotosleep_data[1] = {
   {LI1_MasterReq, 2, {0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}}
};

/********************** Go to sleep Initialization *************************/
/* Delay of this schedule table is: (1.4*(34+10*(8+1))*1000/LIN_speed+jitter) ms */
/* then rounded up to a value is multiple of time base */
const lin_schedule_data LI2_lin_gotosleep_data[1] = {
   {LI2_MasterReq, 4, {0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}}
};


/******************** Schedule table Initialization ************************/
const lin_schedule_data LI1_NormalTable_data[4] = {

   {LI1_Cluster1Slave1Info, 10, 0}
  

   , {LI1_Cluster1Slave2Info, 10, 0}
  
   , {LI1_LedControlFrame, 4, 0}
  
   , {LI1_ResetControlFrame, 4, 0}
  
};

/******************** Schedule table Initialization ************************/
const lin_schedule_data LI1_ResetTable_data[1] = {

   {LI1_ResetControlFrame, 10, 0}
  
};

/******************** Schedule table Initialization ************************/
const lin_schedule_data LI1_PeriodicalWakeupTable_data[4] = {

   {LI1_Cluster1Slave1Info, 10, 0}
  

   , {LI1_Cluster1Slave2Info, 10, 0}
  
   , {LI1_LedControlFrame, 4, 0}
  
   , {LI1_ResetControlFrame, 4, 0}
  
};

/******************** Schedule table Initialization ************************/
const lin_schedule_data LI2_NormalTable_data[5] = {

   {LI2_Cluster2SlaveAInfo, 20, 0}
  

   , {LI2_Cluster2SlaveBInfo, 20, 0}
  
   , {LI2_Cluster2SlaveCInfo, 20, 0}
  
   , {LI2_LedControlFrame, 10, 0}
  
   , {LI2_ResetControlFrame, 10, 0}
  
};

/******************** Schedule table Initialization ************************/
const lin_schedule_data LI2_ResetTable_data[1] = {

   {LI2_ResetControlFrame, 10, 0}
  
};

/******************** Schedule table Initialization ************************/
const lin_schedule_data LI2_PeriodicalWakeupTable_data[5] = {

   {LI2_Cluster2SlaveAInfo, 20, 0}
  

   , {LI2_Cluster2SlaveBInfo, 20, 0}
  
   , {LI2_Cluster2SlaveCInfo, 20, 0}
  
   , {LI2_LedControlFrame, 10, 0}
  
   , {LI2_ResetControlFrame, 10, 0}
  
};



/******************** Schedule table Initialization ************************/
/* If not specify by users, then by default delay of this schedule table is: */
/* (1.4*(34+10*(8+1))*1000/LIN_speed+jitter) ms, then rounded up to a value */
/* that is multiple of time base */
const lin_schedule_data LI1_MasterReqTable_data[1] = {

   {LI1_MasterReq, 6, 0}
  
};

/******************** Schedule table Initialization ************************/
/* If not specify by users, then by default delay of this schedule table is: */
/* (1.4*(34+10*(8+1))*1000/LIN_speed+jitter) ms, then rounded up to a value */
/* that is multiple of time base */
const lin_schedule_data LI1_SlaveRespTable_data[1] = {

   {LI1_SlaveResp, 6, 0}
  
};

/******************** Schedule table Initialization ************************/
/* If not specify by users, then by default delay of this schedule table is: */
/* (1.4*(34+10*(8+1))*1000/LIN_speed+jitter) ms, then rounded up to a value */
/* that is multiple of time base */
const lin_schedule_data LI2_MasterReqTable_data[1] = {

   {LI2_MasterReq, 7, 0}
  
};

/******************** Schedule table Initialization ************************/
/* If not specify by users, then by default delay of this schedule table is: */
/* (1.4*(34+10*(8+1))*1000/LIN_speed+jitter) ms, then rounded up to a value */
/* that is multiple of time base */
const lin_schedule_data LI2_SlaveRespTable_data[1] = {

   {LI2_SlaveResp, 7, 0}
  
};



/********************* Schedule table structure Initialization ***************/
const lin_schedule_struct lin_schedule_tbl[LIN_NUM_OF_SCHD_TBL] ={

   /*interface_name = LI1 */
   {0, LIN_SCH_TBL_NULL  ,(lin_schedule_data*)0 }
  

   ,{1, LIN_SCH_TBL_GOTO  , &LI1_lin_gotosleep_data[0] }
  
   ,{1, LIN_SCH_TBL_DIAG  , &LI1_MasterReqTable_data[0] }
  
   ,{1, LIN_SCH_TBL_DIAG  , &LI1_SlaveRespTable_data[0] }
  
   ,{4, LIN_SCH_TBL_NORM  , &LI1_NormalTable_data[0] }
  
   ,{1, LIN_SCH_TBL_NORM  , &LI1_ResetTable_data[0] }
  
   ,{4, LIN_SCH_TBL_NORM  , &LI1_PeriodicalWakeupTable_data[0] }
  
   ,{0, LIN_SCH_TBL_NULL  , (lin_schedule_data*)0 }
  
   ,{1, LIN_SCH_TBL_GOTO  , &LI2_lin_gotosleep_data[0] }
  
   ,{1, LIN_SCH_TBL_DIAG  , &LI2_MasterReqTable_data[0] }
  
   ,{1, LIN_SCH_TBL_DIAG  , &LI2_SlaveRespTable_data[0] }
  
   ,{5, LIN_SCH_TBL_NORM  , &LI2_NormalTable_data[0] }
  
   ,{1, LIN_SCH_TBL_NORM  , &LI2_ResetTable_data[0] }
  
   ,{5, LIN_SCH_TBL_NORM  , &LI2_PeriodicalWakeupTable_data[0] }
  
};
/********************** Schedule table status Initialization ******************/
l_u8 lin_schedule_start_entry[LIN_NUM_OF_SCHD_TBL] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
l_u8 lin_active_schedule_id[LIN_NUM_OF_IFCS] = {0, 0, 0};
l_u8 lin_previous_schedule_id[LIN_NUM_OF_IFCS] = {0, 0, 0};

l_u8 lin_diag_frame_to_send[LIN_NUM_OF_IFCS] = {0, 0, 0};
/********************** PDU data Initialization *******************************/
lin_tl_pdu_data tx_single_pdu_data[LIN_NUM_OF_IFCS] = {
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

};
lin_tl_pdu_data rx_single_pdu_data[LIN_NUM_OF_IFCS] = {
 {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

};


/****************************Support SID Initialization ***********************/

const l_u8 LI0_lin_diag_services_supported[_LI0_DIAG_NUMBER_OF_SERVICES_] = {0xB2,0xB7,0xB0,0xB3,0xB6};
l_u8 LI0_lin_diag_services_flag[_LI0_DIAG_NUMBER_OF_SERVICES_] = {0,0,0,0,0};

const l_u8 LI1_lin_diag_services_supported[_LI1_DIAG_NUMBER_OF_SERVICES_] = {0xB2,0xB7,0xB0,0xB3,0xB6};
l_u8 LI1_lin_diag_services_flag[_LI1_DIAG_NUMBER_OF_SERVICES_] = {0,0,0,0,0};

const l_u8 LI2_lin_diag_services_supported[_LI2_DIAG_NUMBER_OF_SERVICES_] = {0xB2,0xB7,0xB0,0xB3,0xB6};
l_u8 LI2_lin_diag_services_flag[_LI2_DIAG_NUMBER_OF_SERVICES_] = {0,0,0,0,0};


/****************************Transport Layer Initialization ***********************/

lin_tl_descriptor lin_tl_desc[LIN_NUM_OF_IFCS] = {

   /* interface_name = LI0 */
   {
   &tx_single_pdu_data[LI0],          /* *pointer to transmit queue on TL */
   &rx_single_pdu_data[LI0],          /* *pointer to receive queue on TL */
   (lin_tl_pdu_data*)0,          /* tl_current_tx_pdu_ptr */
   (lin_tl_pdu_data*)0,          /* tl_current_rx_pdu_ptr */
   /* Declaration only for Master interface */
   0,      /* tl_cnt_to_send */
   LD_SERVICE_IDLE,    /* tl_service_status */
   LD_SUCCESS,   /* tl_last_cfg_result */
   0,    /* last_RSID */
   0,    /* ld_error_code */
   (l_u8*)0,   /* *tl_ident_data */
   /* End of declaration for only Master interface */
   /* Declaration only for Slave interface */
   _LI0_DIAG_NUMBER_OF_SERVICES_,
   (l_u8*) &LI0_lin_diag_services_supported,
   (l_u8*) &LI0_lin_diag_services_flag,           /* diagnostic services flags*/
   0, /* tl_slaveresp_cnt */
   /* End of declaration only for Slave interface */

   }


   /*interface_name = LI1*/
   ,{
   &tx_single_pdu_data[LI1],          /* *pointer to transmit queue on TL */
   &rx_single_pdu_data[LI1],          /* *pointer to receive queue on TL */
   (lin_tl_pdu_data*)0,          /* *tl_current_tx_pdu_ptr */
   (lin_tl_pdu_data*)0,          /* *tl_current_rx_pdu_ptr */
   /* Declaration only for Master interface */
   0,      /* tl_cnt_to_send */
   LD_SERVICE_IDLE,    /* tl_service_status */
   LD_SUCCESS,   /* tl_last_cfg_result */
   0,    /* last_RSID */
   0,    /* ld_error_code */
   (l_u8*)0,   /* *tl_ident_data */
   _LI1_DIAG_NUMBER_OF_SERVICES_,
   (l_u8*) &LI1_lin_diag_services_supported,
   (l_u8*) &LI1_lin_diag_services_flag,           /* diagnostic services flags*/
   0 /* tl_slaveresp_cnt */
   /* End of declaration for only Master interface */
   }

   /*interface_name = LI2*/
   ,{
   &tx_single_pdu_data[LI2],          /* *pointer to transmit queue on TL */
   &rx_single_pdu_data[LI2],          /* *pointer to receive queue on TL */
   (lin_tl_pdu_data*)0,          /* *tl_current_tx_pdu_ptr */
   (lin_tl_pdu_data*)0,          /* *tl_current_rx_pdu_ptr */
   /* Declaration only for Master interface */
   0,      /* tl_cnt_to_send */
   LD_SERVICE_IDLE,    /* tl_service_status */
   LD_SUCCESS,   /* tl_last_cfg_result */
   0,    /* last_RSID */
   0,    /* ld_error_code */
   (l_u8*)0,   /* *tl_ident_data */
   _LI2_DIAG_NUMBER_OF_SERVICES_,
   (l_u8*) &LI2_lin_diag_services_supported,
   (l_u8*) &LI2_lin_diag_services_flag,           /* diagnostic services flags*/
   0 /* tl_slaveresp_cnt */
   /* End of declaration for only Master interface */
   }

};

/****************************LIN interface configuration ****************************/
const lin_configuration lin_ifc_configuration[LIN_NUM_OF_IFCS] = {

   /* Interface_name = LI0 */
   {
   LIN_PROTOCOL_21,         /*lin_protocol_version */
   LIN_PROTOCOL_21,         /*lin_language_version */
   19200,            /*  baud_rate */
   _SLAVE_,                  /*  function _SLAVE_ | _MASTER_*/
   &LI0_node_attribute,             /*  node attribute */
   /* LIN data pointer */
   &lin_lld_response_buffer[LI0][0],        /*  *response_buffer */
   &lin_successful_transfer[LI0],           /*  *lin_successful_transfer */
   &lin_error_in_response[LI0],             /*  *lin_error_in_response */
   &lin_goto_sleep_flg[LI0],              /*  *goto_sleep_flg */
   &lin_current_pid[LI0],                 /*  *current_pid */
   &lin_word_status[LI0],                 /*  *word_status */
   /* Protocol */
   0,        /* timebase is not used in Slave node*/
   &lin_diag_signal_tbl[LI0][0],          /*  *diag_signal_tbl */
   5,                            /*  num_of_frames */
   0,                              /*  frame_start */
   &lin_frame_tbl[0],                                          /*  frame_tbl */
   &lin_frame_flag_tbl[0],                                       /*  *frame_flg */

   0,                                  /*  num_of_schedules */
   0,                                  /*  schedule_start */
   (const lin_schedule_struct *)0,             /* schedule_tbl */
   (l_u8*)0,        /*  *schedule_start_entry */
   (l_u8*)0,        /*  *next_transmit_tick */
   (l_u8*)0,        /*  *active_schedule_id */
   (l_u8*)0,        /*  *previous_schedule_id */
   (l_u8*)0,        /*  *diagnostic_frame_to_send */
   DIAG_NONE,    /*  diagnostic_mode */
   &LI0_lin_configuration_RAM[0],   /*  *configuration_RAM */
   &LI0_lin_configuration_ROM[0],   /*  *configuration_ROM */
   &lin_tl_desc[LI0]
   }


   ,{
   /* interface_name = LI1 */
   LIN_PROTOCOL_21,           /*lin_protocol_version */
   LIN_PROTOCOL_21,           /*lin_language_version */
   19200,                /*  baud_rate */
   _MASTER_,                           /*  function _SLAVE_ | _MASTER_*/
   (lin_node_attribute*)0,                   /*  node attribute is only used for slave node*/

   /* LIN data pointer */
   &lin_lld_response_buffer[LI1][0],      /*  *response_buffer */
   &lin_successful_transfer[LI1],         /*  *lin_successful_transfer */
   &lin_error_in_response[LI1],           /*  *lin_error_in_response */
   &lin_goto_sleep_flg[LI1],            /*  *goto_sleep_flg */
   &lin_current_pid[LI1],               /*  *current_pid */
   &lin_word_status[LI1],               /*  *word_status */
   /* Protocol */
   5,                      /*  time_base */

   &lin_diag_signal_tbl[LI1][0],       /*  diag_signal_tbl */
   8,      /*  num_of_frames */
   5,        /*  frame_start */
   &lin_frame_tbl[0],                /* frame_tbl */
   &lin_frame_flag_tbl[0],             /*frame_flg */

   7,       /*  num_of_schedules */
   0,         /*  schedule_start */
   &lin_schedule_tbl[0],                 /*schedule_tbl */
   &lin_schedule_start_entry[0],             /*schedule_start_entry */
   &lin_next_transmit[LI1],             /* next_transmit_tick */
   &lin_active_schedule_id[LI1],        /*  active_schedule_id */
   &lin_previous_schedule_id[LI1],      /*  previous_schedule_id */
   &lin_diag_frame_to_send[LI1],        /*  diagnostic_frame_to_send */
   DIAG_NONE,    /*  diagnostic_mode */
   &LI1_lin_configuration_RAM[0],   /*  *configuration_RAM */
   &LI1_lin_configuration_ROM[0],   /*  *configuration_ROM */
   &lin_tl_desc[LI1]
  }
 
   ,{
   /* interface_name = LI2 */
   LIN_PROTOCOL_21,           /*lin_protocol_version */
   LIN_PROTOCOL_21,           /*lin_language_version */
   9600,                /*  baud_rate */
   _MASTER_,                           /*  function _SLAVE_ | _MASTER_*/
   (lin_node_attribute*)0,                   /*  node attribute is only used for slave node*/

   /* LIN data pointer */
   &lin_lld_response_buffer[LI2][0],      /*  *response_buffer */
   &lin_successful_transfer[LI2],         /*  *lin_successful_transfer */
   &lin_error_in_response[LI2],           /*  *lin_error_in_response */
   &lin_goto_sleep_flg[LI2],            /*  *goto_sleep_flg */
   &lin_current_pid[LI2],               /*  *current_pid */
   &lin_word_status[LI2],               /*  *word_status */
   /* Protocol */
   5,                      /*  time_base */

   &lin_diag_signal_tbl[LI2][0],       /*  diag_signal_tbl */
   9,      /*  num_of_frames */
   13,        /*  frame_start */
   &lin_frame_tbl[0],                /* frame_tbl */
   &lin_frame_flag_tbl[0],             /*frame_flg */

   7,       /*  num_of_schedules */
   7,         /*  schedule_start */
   &lin_schedule_tbl[0],                 /*schedule_tbl */
   &lin_schedule_start_entry[0],             /*schedule_start_entry */
   &lin_next_transmit[LI2],             /* next_transmit_tick */
   &lin_active_schedule_id[LI2],        /*  active_schedule_id */
   &lin_previous_schedule_id[LI2],      /*  previous_schedule_id */
   &lin_diag_frame_to_send[LI2],        /*  diagnostic_frame_to_send */
   DIAG_NONE,    /*  diagnostic_mode */
   &LI2_lin_configuration_RAM[0],   /*  *configuration_RAM */
   &LI2_lin_configuration_ROM[0],   /*  *configuration_ROM */
   &lin_tl_desc[LI2]
  }
 
};
/*************************** Node hardware configuration definition *************************/
/* Node hardware configuration */
lin_node lin_node_descrs[NUM_OF_SCI_CHANNEL]={
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI2_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI3_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI4_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI5_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 }
};


/*This ld_read_by_id_callout() function is used when the master node transmits a read by
 identifier request with an identifier in the user defined area (id from 32 to 63).
 The driver will call this function when such request is received.
 * id: the identifier in the user defined area (32 to 63)
 * data: pointer points to a data area with 5 bytes, used to give the positive response.
  Driver uses 0xFF "do not care value" for unassigned data values.
  Data length in PCI is (1 + number of assigned meaningful data values).
  Driver will take as data for all data before and including the last value in the frame that is different from 0xFF.
  PCI is 0x02-0x06, so data should have at least one value different from 0xFF.
  For example, a response frame, (NAD) (PCI) (0xF2) (0xFF) (0x00) (0xFF) (0xFF) (0xFF),
  PCI will be 0x03, since in this case driver takes all data before 0x00 and 0x00 as meaningful data,
  and values after 0x00 are do not care value.
 * return: LD_NEGATIVE_RESPONSE Respond with a negative response.
           LD_POSTIVE_RESPONSE Respond with a positive response.
           LD_ID_NO_RESPONSE The slave node will not answer.
 */
l_u8 ld_read_by_id_callout(l_ifc_handle iii, l_u8 id, l_u8 *data)
{
   l_u8 retval = LD_NEGATIVE_RESPONSE;
    const lin_configuration * conf;

    /* Get the current configuration */
    conf = (lin_configuration *)&lin_ifc_configuration[iii];

    if (conf->function == _SLAVE_)
    {
        /* Following code is an example - Real implementation is application-dependent */
        /* the handling does essentially depend on the id of the requested identifier */
        /* This example implement with ID = 32 - LIN_READ_USR_DEF_MIN */
        if (id == LIN_READ_USR_DEF_MIN)
        {
            /* id received is user defined 32 */
            data[0] = (l_u8) (id + 1);    /* Data user define */
            data[1] = (l_u8) (id + 2);    /* Data user define */
            data[2] = (l_u8) (id + 3);    /* Data user define */
            data[3] = (l_u8) (id + 4);    /* Data user define */
            data[4] = (l_u8) (id + 5);    /* Data user define */
            retval = LD_POSITIVE_RESPONSE;
        }
        else
        {
            /* other identifiers, respond with negative response by default*/
        }
    } /* End (conf->function == _SLAVE_) */
   return retval;
}