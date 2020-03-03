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
* @date      Wed Feb 27 13:21:59 ICT 2019
*
* @brief     Common LIN configuration, data structure
*
******************************************************************************/
#include "lin_cfg.h"
#include "lin.h"
/* Mapping interface with hardware */
const lin_hardware_name lin_virtual_ifc = GPIO;
l_u8 lin_lld_response_buffer[10];
l_u8 lin_successful_transfer;
l_u8 lin_error_in_response;
l_u8 lin_goto_sleep_flg;
/* Save configuration flag */
l_u8 lin_save_configuration_flg = 0;
lin_word_status_str lin_word_status;
l_u8 lin_current_pid;

const l_signal_handle LI0_response_error_signal = LI0_Cluster2SlaveBError;

volatile l_u8 buffer_backup_data[8];

/* definition and initialization of signal array */
l_u8    lin_pFrameBuf[LIN_FRAME_BUF_SIZE] =
{


  0xfc /* 0 : 11111100 */ /* start of frame LI0_LedControl */



  ,0xfc /* 1 : 11111100 */ /* start of frame LI0_ResetFrame */


  ,0x00 /* 2 : 00000000 */ /* start of frame LI0_Cluster2SlaveBInfo */

  ,0xfe /* 3 : 11111110 */
  
};

/* definition and initialization of signal array */
l_u8    lin_flag_handle_tbl[LIN_FLAG_BUF_SIZE] =
{


  0xFF /* 0: start of flag frame LI0_LedControl */



  ,0xFF /* 1: start of flag frame LI0_ResetFrame */


  ,0xFF /* 2: start of flag frame LI0_Cluster2SlaveBInfo */

};

/*************************** Flag set when signal is updated ******************/
/* Diagnostic signal */
l_u8 lin_diag_signal_tbl[16];
/*****************************event trigger frame*****************************/

/**********************************  Frame table **********************************/
const lin_frame_struct lin_frame_tbl[LIN_NUM_OF_FRMS] ={

    { LIN_FRM_UNCD, 1, LIN_RES_SUB, 0, 0, 1   , (l_u8*)0 }

   ,{ LIN_FRM_UNCD, 1, LIN_RES_SUB, 1, 1, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 2, LIN_RES_PUB, 2, 2, 1 , (l_u8*)&LI0_response_error_signal }
  
   ,{ LIN_FRM_SPRDC, 1, LIN_RES_SUB, 0, 0, 0 , (l_u8*)0 }
  
   ,{ LIN_FRM_SPRDC, 1, LIN_RES_SUB, 0, 0, 0 , (l_u8*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_SUB, 0, 0, 0 , (l_u8*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_PUB, 0, 0, 0 , (l_u8*)0 }
  
};

/*********************************** Frame flag Initialization **********************/
/*************************** Frame flag for send/receive successfully ***************/
l_bool lin_frame_flag_tbl[LIN_NUM_OF_FRMS] = {0, 0, 0, 0, 0};
/*************************** Frame flag for updating signal in frame ****************/
volatile l_u8 lin_frame_updating_flag_tbl[LIN_NUM_OF_FRMS] = {0, 0, 0, 0, 0};




l_u8 lin_configuration_RAM[LIN_SIZE_OF_CFG]= {0x00, 0x09, 0x08, 0x0C, 0x3C, 0x3D ,0xFF};


const l_u16  lin_configuration_ROM[LIN_SIZE_OF_CFG]= {0x00, 0x09, 0x08, 0x0C, 0x3C, 0x3D ,0xFFFF};

/***************************************** Node Attribute*****************************************/

l_u8 lin_configured_NAD = 0x05;    /*<configured_NAD>*/
const l_u8 lin_initial_NAD    =0x0E;    /*<initial_NAD>*/
const lin_product_id product_id = {0x0022, 0x0005, 0x0004 };  /* {<supplier_id>,<function_id>,<variant>} */
const l_signal_handle response_error =  LI0_Cluster2SlaveBError;
const l_u8 num_frame_have_esignal = 1;                                 /*number of frame contain error signal*/
const l_u16 lin_response_error_byte_offset[1] = {LIN_BYTE_OFFSET_LI0_Cluster2SlaveBError};                  /*<interface_name>_< response_error>*/
const l_u8 lin_response_error_bit_offset[1] = {LIN_BIT_OFFSET_LI0_Cluster2SlaveBError};                  /*<interface_name>_< response_error>*/



/************************** TL Layer and Diagnostic: SINGLE interface **************************/
lin_tl_pdu_data tx_single_pdu_data = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
lin_tl_pdu_data rx_single_pdu_data = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};








lin_tl_pdu_data *tl_current_tx_pdu_ptr;
lin_tl_pdu_data *tl_current_rx_pdu_ptr;
l_u8 tl_slaveresp_cnt = 0;
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
l_u8 ld_read_by_id_callout(l_u8 id, l_u8 *data)
{
    l_u8 retval = LD_NEGATIVE_RESPONSE;
    /* Following code is an example - Real implementation is application-dependent */
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
    return retval;
}