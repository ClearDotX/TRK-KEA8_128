/******************************************************************************
* 
* Freescale Semiconductor Inc.
* (c) Copyright $from_year$-2016 Freescale Semiconductor, Inc.
* Copyright 2016-$to_year$ NXP
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
* @date      $date$
*
* @brief     Common LIN configuration, data structure
*
******************************************************************************/
#include "lin_cfg.h"
#include "lin.h"
/* Mapping interface with hardware */
$if(is_master_mode)$
  $if(is_xgate_support)$
#include "xlin_sci.h"
#pragma DATA_SEG SHARED_DATA
  $endif$
const lin_hardware_name lin_virtual_ifc[LIN_NUM_OF_IFCS] = {$list_hardware_handle; separator=", "$};
  $if(is_multi_timer)$
    $if(is_xgate_support)$
    $else$
      $if(diagnotic_class_2)$
/* N_As and N_Cr timeout */
const l_u16 max_tl_timeout_counter[LIN_NUM_OF_IFCS] = {$list_tl_max_timeout; separator=", "$};
      $endif$
      $if(diagnotic_class_3)$
/* N_As and N_Cr timeout */
const l_u16 max_tl_timeout_counter[LIN_NUM_OF_IFCS] = {$list_tl_max_timeout; separator=", "$};
      $endif$

/* Timer period values */
const l_u16 time_base_period[LIN_NUM_OF_IFCS] = {$list_timer_period; separator=", "$};

/* Max timeout counter values */
const l_u16 max_idle_timeout[LIN_NUM_OF_IFCS] = {$list_maxtimeout_counter; separator=", "$};
    $endif$
  $endif$
/* Low level response buffer */
l_u8 lin_lld_response_buffer[LIN_NUM_OF_IFCS][10];
  $if(is_xgate_support)$
#pragma DATA_SEG DEFAULT
  $endif$
 /* Successful transfer flags */
l_u8 lin_successful_transfer[LIN_NUM_OF_IFCS];
/* Error in response */
l_u8 lin_error_in_response[LIN_NUM_OF_IFCS];
/* Goto sleep flag */
l_u8 lin_goto_sleep_flg[LIN_NUM_OF_IFCS];
/* Save configuration flag */
l_u8 lin_save_configuration_flg[LIN_NUM_OF_IFCS] = {$list_intf_zero_data; separator=", "$};
 /* Next transmit tick */
l_u8 lin_next_transmit[LIN_NUM_OF_IFCS];
 /* lin word status */
lin_word_status_str lin_word_status[LIN_NUM_OF_IFCS];
/* current pid */
l_u8 lin_current_pid[LIN_NUM_OF_IFCS];
$else$
  $if(is_xgate_support)$
#pragma DATA_SEG SHARED_DATA
  $endif$
const lin_hardware_name lin_virtual_ifc = $first(list_hardware_handle):{$it$}$;
l_u8 lin_lld_response_buffer[10];
  $if(is_xgate_support)$
#pragma DATA_SEG DEFAULT
  $endif$
l_u8 lin_successful_transfer;
l_u8 lin_error_in_response;
l_u8 lin_goto_sleep_flg;
/* Save configuration flag */
l_u8 lin_save_configuration_flg = 0;
lin_word_status_str lin_word_status;
l_u8 lin_current_pid;
$endif$

$list_error_response_signal: { error_signal_item |
const l_signal_handle $error_signal_item.("inf_name")$_response_error_signal = $error_signal_item.("inf_name")$_$error_signal_item.("signal_name")$;
}$
volatile l_u8 buffer_backup_data[8];

/* definition and initialization of signal array */
l_u8    lin_pFrameBuf[LIN_FRAME_BUF_SIZE] =
{
$first(list_signal_definition): { signal_def |
$first(signal_def.lstItem): { map_item |
  $map_item.mapItem.("hex_init_value")$ /* $map_item.mapItem.("signal_index")$ : $map_item.mapItem.("bin_init_value")$ */ /* start of frame $signal_def.key$ */}$
$rest(signal_def.lstItem): { map_item |
  ,$map_item.mapItem.("hex_init_value")$ /* $map_item.mapItem.("signal_index")$ : $map_item.mapItem.("bin_init_value")$ */}$}$
$rest(list_signal_definition): { signal_def |
$first(signal_def.lstItem): { map_item |
  ,$map_item.mapItem.("hex_init_value")$ /* $map_item.mapItem.("signal_index")$ : $map_item.mapItem.("bin_init_value")$ */ /* start of frame $signal_def.key$ */}$
$rest(signal_def.lstItem): { map_item |
  ,$map_item.mapItem.("hex_init_value")$ /* $map_item.mapItem.("signal_index")$ : $map_item.mapItem.("bin_init_value")$ */
  }$}$
};

/* definition and initialization of signal array */
l_u8    lin_flag_handle_tbl[LIN_FLAG_BUF_SIZE] =
{
$first(list_flag_buffer): { flag_item |
$first(flag_item.lstItem): { map_item |
  0xFF /* $map_item.mapItem.("flag_index")$: start of flag frame $flag_item.key$ */}$
$rest(flag_item.lstItem): { map_item |
  ,0xFF /* $map_item.mapItem.("flag_index")$: */}$}$
$rest(list_flag_buffer): { flag_item |
$first(flag_item.lstItem): { map_item |
  ,0xFF /* $map_item.mapItem.("flag_index")$: start of flag frame $flag_item.key$ */}$
$rest(flag_item.lstItem): { map_item |
  ,0xFF /* $map_item.mapItem.("flag_index")$: */
  }$}$
};

/*************************** Flag set when signal is updated ******************/
/* Diagnostic signal */
$if(is_master_mode)$
l_u8 lin_diag_signal_tbl[LIN_NUM_OF_IFCS][16];
$else$
l_u8 lin_diag_signal_tbl[16];
$endif$

/*****************************event trigger frame*****************************/
$if(is_master_mode)$
/* all event trigger frames for master node */
$list_event_trig_frame_initial_items:{ frm_initial |
const l_u8 $frm_initial.("interface_name")$_$frm_initial.("event_trig_frm_name")$_info_data[$frm_initial.("number_associated_frame")$] = {
 $first(frm_initial.("associated_frames")): { acc_frame |
  $frm_initial.("interface_name")$_$acc_frame$
 }$
 $rest(frm_initial.("associated_frames")): { acc_frame |
  ,$frm_initial.("interface_name")$_$acc_frame$
 }$
};
}$
$list_event_trig_frame_initial_items:{ frm_initial |
const lin_associate_frame_struct $frm_initial.("interface_name")$_$frm_initial.("event_trig_frm_name")$_info = {
   $frm_initial.("number_associated_frame")$  /* Number of associated unconditional frame ID*/
   ,&$frm_initial.("interface_name")$_$frm_initial.("event_trig_frm_name")$_info_data[0]   /* Associated unconditional frame ID */
  $if(frm_initial.("is_master_node"))$
   ,$frm_initial.("interface_name")$_$frm_initial.("collision_resolving_schedule_table")$  /* Collision resolver index in the schedule table, used in event trigger frame case*/
  $else$
   ,0xFF  /*this element is not use for slave node*/
  $endif$
};
}$
$else$
$list_event_trig_frame_initial_items:{ frm_initial |
const l_u8 $frm_initial.("interface_name")$_$frm_initial.("event_trig_frm_name")$_info_data = $first(frm_initial.("associated_frames")): { acc_frame |$frm_initial.("interface_name")$_$acc_frame$ }$;  /* frame data */
}$
$endif$


$if(is_master_mode)$
/*****************************sporadic frame*****************************/
/*all sporadic frames for master node*/
$list_sporadic_frame_initial_items:{ frm_initial |
const l_u8 $frm_initial.("interface_name")$_$frm_initial.("sporadic_frm_name")$_info_data[$frm_initial.("number_associated_frame")$] ={
 $first(frm_initial.("associated_frames")): { acc_frame |
  $frm_initial.("interface_name")$_$acc_frame$
 }$
 $rest(frm_initial.("associated_frames")): { acc_frame |
  ,$frm_initial.("interface_name")$_$acc_frame$
 }$
};
const lin_associate_frame_struct $frm_initial.("interface_name")$_$frm_initial.("sporadic_frm_name")$_info ={
   $frm_initial.("number_associated_frame")$
   ,&$frm_initial.("interface_name")$_$frm_initial.("sporadic_frm_name")$_info_data[0]   $! ++++++ !$
   ,0xFF
};
}$
$endif$

/**********************************  Frame table **********************************/
const lin_frame_struct lin_frame_tbl[LIN_NUM_OF_FRMS] ={
 $first(list_frame_table_initial_items): { frame_table |
   { $frame_table.mapItem.("frame_type")$, $frame_table.mapItem.("frame_size")$, $frame_table.mapItem.("frame_respond")$, $frame_table.mapItem.("frame_offset")$, $frame_table.mapItem.("flag_offset")$, $frame_table.mapItem.("flag_size")$ $if(frame_table.mapItem.("is_frame_address"))$ , (l_u8*)&$frame_table.mapItem.("interface_name")$_$frame_table.mapItem.("frame_name")$_$frame_table.mapItem.("ref_type")$  $else$  , (l_u8*)0 $endif$}}$
 $rest(list_frame_table_initial_items): { frame_table |
  ,{ $frame_table.mapItem.("frame_type")$, $frame_table.mapItem.("frame_size")$, $frame_table.mapItem.("frame_respond")$, $frame_table.mapItem.("frame_offset")$, $frame_table.mapItem.("flag_offset")$, $frame_table.mapItem.("flag_size")$ $if(frame_table.mapItem.("is_frame_address"))$, (l_u8*)&$frame_table.mapItem.("interface_name")$_$frame_table.mapItem.("frame_name")$_$frame_table.mapItem.("ref_type")$ $else$, (l_u8*)0 $endif$}
 }$
};

/*********************************** Frame flag Initialization **********************/
/*************************** Frame flag for send/receive successfully ***************/
l_bool lin_frame_flag_tbl[LIN_NUM_OF_FRMS] = {$list_frame_flag_table; separator=", "$};
/*************************** Frame flag for updating signal in frame ****************/
volatile l_u8 lin_frame_updating_flag_tbl[LIN_NUM_OF_FRMS] = {$list_frame_flag_table; separator=", "$};


$if (is_serial_connect)$
/**************************** Lin configuration Initialization ***********************/
/* max_response_frame_timeout = round((1.4x(10+Nx10)xTbit)/Tbase_period) + 3 */
$endif$

$if(is_master_mode)$
  $if(is_xgate_support)$
#pragma DATA_SEG SHARED_DATA
  $endif$
  $if(is_xgate_support)$
   const l_u16 lin_max_frame_res_timeout_val[LIN_NUM_OF_IFCS][8]= {
 $first(list_lin_max_frame_res_timeout_items_xgate): { frame_res_timeout_xgate |
  {$frame_res_timeout_xgate.lstItem; separator=", "$ }
 }$
 $rest(list_lin_max_frame_res_timeout_items_xgate): {frame_res_timeout_xgate |
  ,{$frame_res_timeout_xgate.lstItem; separator=", "$}
 }$
};
  $else$
const l_u16 lin_max_frame_res_timeout_val[LIN_NUM_OF_IFCS][8]= {
 $first(list_lin_max_frame_res_timeout_items): { frame_res_timeout |
  {$frame_res_timeout.lstItem; separator=", "$ }
 }$
 $rest(list_lin_max_frame_res_timeout_items): {frame_res_timeout |
  ,{$frame_res_timeout.lstItem; separator=", "$}
 }$
};

  $endif$
  $if(is_xgate_support)$

#pragma DATA_SEG DEFAULT
  $endif$
$list_intf_configuration_ram_items: { cfg_ram |
l_u8 $cfg_ram.key$_lin_configuration_RAM[$cfg_ram.key$_LIN_SIZE_OF_CFG]= {0x00, $cfg_ram.lstItem; separator=", "$ ,0xFF};
}$
$list_intf_configuration_rom_items: { cfg_rom |
const l_u16  $cfg_rom.key$_lin_configuration_ROM[$cfg_rom.key$_LIN_SIZE_OF_CFG]= {0x0000, $cfg_rom.lstItem; separator=", "$ ,0xFFFF};
}$
$else$
  $if(is_xgate_support)$
#pragma DATA_SEG SHARED_DATA
  $endif$
  $if (is_xgate_support)$

const l_u16 lin_max_frame_res_timeout_val[8]={
$first(list_lin_max_frame_res_timeout_items_xgate): { frame_res_timeout_xgate |
$frame_res_timeout_xgate.lstItem; separator=", "$
}$
};

  $else$
    $if (is_serial_connect)$

const l_u16 lin_max_frame_res_timeout_val[8]={
$first(list_lin_max_frame_res_timeout_items): { frame_res_timeout |
$frame_res_timeout.lstItem; separator=", "$
}$
};
    $endif$
  $endif$

  $if(is_xgate_support)$

#pragma DATA_SEG DEFAULT

  $endif$
$first(list_intf_configuration_ram_items): { cfg_ram |
l_u8 lin_configuration_RAM[LIN_SIZE_OF_CFG]= {0x00, $cfg_ram.lstItem; separator=", "$ ,0xFF};
}$
$first(list_intf_configuration_rom_items): { cfg_rom |
const l_u16  lin_configuration_ROM[LIN_SIZE_OF_CFG]= {0x00, $cfg_rom.lstItem; separator=", "$ ,0xFFFF};
}$
$endif$

$if(is_master_mode)$
$list_intf_node_attr_initial_items :{ node_attr |

static l_u16 $node_attr.mapItem.("interface_name")$_lin_response_error_byte_offset[$node_attr.mapItem.("num_frame_have_err_signal")$] = {$node_attr.mapItem.("response_error_byte_offset"); separator=", "$};

static l_u8 $node_attr.mapItem.("interface_name")$_lin_response_error_bit_offset[$node_attr.mapItem.("num_frame_have_err_signal")$] = {$node_attr.mapItem.("response_error_bit_offset"); separator=", "$};
}$

/**************** Node attributes Initialization  ****************************/

$list_intf_node_attr_initial_items :{ node_attr |
$if (node_attr.mapItem.("is_list_faut_state_signal_address"))$
const l_signal_handle $node_attr.mapItem.("interface_name")$_list_faut_state_signals[] = {$first(node_attr.mapItem.("list_faut_state_signal_address")): {node_attr_item| $node_attr.mapItem.("interface_name")$_$first(node_attr.mapItem.("list_faut_state_signal_address"))$}$ $first(rest(node_attr.mapItem.("list_faut_state_signal_address"))): {node_attr_item| , $node_attr.mapItem.("interface_name")$_$first(rest(node_attr.mapItem.("list_faut_state_signal_address")))$}$  $first(rest(rest(node_attr.mapItem.("list_faut_state_signal_address")))): {node_attr_item| , $node_attr.mapItem.("interface_name")$_$first(rest(rest(node_attr.mapItem.("list_faut_state_signal_address"))))$}$ $first(rest(rest(rest(node_attr.mapItem.("list_faut_state_signal_address"))))): {node_attr_item| , $node_attr.mapItem.("interface_name")$_$first(rest(rest(rest(node_attr.mapItem.("list_faut_state_signal_address")))))$}$ $first(rest(rest(rest(rest(node_attr.mapItem.("list_faut_state_signal_address")))))): {node_attr_item| , $node_attr.mapItem.("interface_name")$_$first(rest(rest(rest(rest(node_attr.mapItem.("list_faut_state_signal_address"))))))$}$ }; /*<list_faut_state_signals>*/
$endif$

lin_node_attribute  $node_attr.mapItem.("interface_name")$_node_attribute = {
   LIN_$node_attr.mapItem.("lin_protocol_version")$,    /*lin_protocol_version*/
   $node_attr.mapItem.("configured_nad")$,    /*configured_NAD*/
   $node_attr.mapItem.("initial_nad")$,    /*initial_NAD*/
   { $node_attr.mapItem.("supplier_id")$, $node_attr.mapItem.("product_id")$, $node_attr.mapItem.("variant")$ },   /*{<supplier_id>,<function_id>,<variant>}*/
   $node_attr.mapItem.("interface_name")$_$node_attr.mapItem.("response_error")$,    /*<interface_name>_< response_error>*/
   $node_attr.mapItem.("num_frame_have_err_signal")$,                                 /*number of frame contain error signal*/
   $node_attr.mapItem.("interface_name")$_lin_response_error_byte_offset,                  /*<interface_name>_< response_error>*/
   $node_attr.mapItem.("interface_name")$_lin_response_error_bit_offset,                  /*<interface_name>_< response_error>*/
   $node_attr.mapItem.("num_faut_state_signal")$,    /*<num_faut_state_signal>*/
   $if (node_attr.mapItem.("is_list_faut_state_signal_address"))$
   $node_attr.mapItem.("interface_name")$_list_faut_state_signals,
   $else$
   (const l_signal_handle*)0,
   $endif$
   $node_attr.mapItem.("p2_min")$,    /*<P2_min>*/
   $node_attr.mapItem.("st_min")$,    /*<ST_min>*/
   $node_attr.mapItem.("n_as_timeout")$,   /*< N_As_timeout >*/
   $node_attr.mapItem.("n_cr_timeout")$  /*<N_Cr_timeout >*/
};
}$
$else$
/***************************************** Node Attribute*****************************************/
$list_intf_node_attr_initial_items :{ node_attr |
l_u8 lin_configured_NAD = $node_attr.mapItem.("configured_nad")$;    /*<configured_NAD>*/
const l_u8 lin_initial_NAD    =$node_attr.mapItem.("initial_nad")$;    /*<initial_NAD>*/
const lin_product_id product_id = {$node_attr.mapItem.("supplier_id")$, $node_attr.mapItem.("product_id")$, $node_attr.mapItem.("variant")$ };  /* {<supplier_id>,<function_id>,<variant>} */
const l_signal_handle response_error =  $node_attr.mapItem.("interface_name")$_$node_attr.mapItem.("response_error")$;
const l_u8 num_frame_have_esignal = $node_attr.mapItem.("num_frame_have_err_signal")$;                                 /*number of frame contain error signal*/
const l_u16 lin_response_error_byte_offset[$node_attr.mapItem.("num_frame_have_err_signal")$] = {$node_attr.mapItem.("response_error_byte_offset"); separator=", "$};                  /*<interface_name>_< response_error>*/
const l_u8 lin_response_error_bit_offset[$node_attr.mapItem.("num_frame_have_err_signal")$] = {$node_attr.mapItem.("response_error_bit_offset"); separator=", "$};                  /*<interface_name>_< response_error>*/
}$
$endif$

$if(is_master_mode)$
$else$
  $if(diagnotic_class_2)$
/************************** TL Layer and Diagnostic: SINGLE interface **************************/
/* QUEUE information */
lin_tl_pdu_data tl_tx_queue_data[MAX_QUEUE_SIZE];    /*transmit queue data */
lin_tl_pdu_data tl_rx_queue_data[MAX_QUEUE_SIZE];    /*receive queue data */

lin_transport_layer_queue lin_tl_tx_queue = {
0,                                                /* the first element of queue */
0,                                                /* the last element of queue */
LD_QUEUE_EMPTY,                                   /* status of queue */
0,                                                /* curernt size of queue */
MAX_QUEUE_SIZE,                                   /* size of queue */
tl_tx_queue_data,                                 /* data of queue */
};
lin_transport_layer_queue lin_tl_rx_queue = {
0,                                                /* the first element of queue */
0,                                                /* the last element of queue */
LD_QUEUE_EMPTY,                                   /* status of queue */
0,                                                /* curernt size of queue */
MAX_QUEUE_SIZE,                                   /* size of queue */
tl_rx_queue_data,                                 /* data of queue */
};
/* message information in transmit queue */
l_u16 tl_rx_msg_index;                                /* index of message in queue */
l_u16 tl_rx_msg_size;                                 /* Size of message in queue */
/* message information in receive queue */
l_u16 tl_tx_msg_index;                                /* index of message in queue */
l_u16 tl_tx_msg_size;                                 /* Size of message in queue */
lin_last_cfg_result tl_last_cfg_result;               /* Status of the last configuration service in LIN 2.0, J2602 */
l_u8 tl_last_RSID;                                    /* RSID of the last node configuration service */
l_u8 tl_ld_error_code;                                /* Error code in case of positive response */
l_u8 tl_no_of_pdu;                                    /* number of received pdu */
l_u8 tl_frame_counter;                                /* frame counter in received message */
lin_message_timeout_type tl_check_timeout_type;       /* timeout type */
l_u16 tl_check_timeout;                               /* timeout counter*/
l_u8 *tl_ident_data;                                  /* To store address of RAM area contain response */
    $if(is_xgate_support)$
#pragma DATA_SEG SHARED_DATA
    $endif$

lin_diagnostic_state tl_diag_state = LD_DIAG_IDLE;
lin_service_status tl_service_status =  LD_SERVICE_IDLE ; /* service status */
lin_message_status tl_receive_msg_status;             /* receive message status */
lin_message_status tl_rx_msg_status;                  /* cooked rx status */
lin_message_status tl_tx_msg_status;                  /* cooked tx status */
    $if(is_xgate_support)$
#pragma DATA_SEG DEFAULT
    $endif$
  $endif$
$endif$


$if(is_master_mode)$
$else$
  $if(diagnotic_class_3)$
/************************** TL Layer and Diagnostic: SINGLE interface **************************/
/* QUEUE information */
lin_tl_pdu_data tl_tx_queue_data[MAX_QUEUE_SIZE];    /*transmit queue data */
lin_tl_pdu_data tl_rx_queue_data[MAX_QUEUE_SIZE];    /*receive queue data */

lin_transport_layer_queue lin_tl_tx_queue = {
0,                                                /* the first element of queue */
0,                                                /* the last element of queue */
LD_QUEUE_EMPTY,                                   /* status of queue */
0,                                                /* curernt size of queue */
MAX_QUEUE_SIZE,                                   /* size of queue */
tl_tx_queue_data,                                 /* data of queue */
};

lin_transport_layer_queue lin_tl_rx_queue = {
0,                                                /* the first element of queue */
0,                                                /* the last element of queue */
LD_QUEUE_EMPTY,                                   /* status of queue */
0,                                                /* curernt size of queue */
MAX_QUEUE_SIZE,                                   /* size of queue */
tl_rx_queue_data,                                 /* data of queue */
};
/* message information in transmit queue */
l_u16 tl_rx_msg_index;                                /* index of message in queue */
l_u16 tl_rx_msg_size;                                 /* Size of message in queue */
/* message information in receive queue */
l_u16 tl_tx_msg_index;                                /* index of message in queue */
l_u16 tl_tx_msg_size;                                 /* Size of message in queue */
lin_last_cfg_result tl_last_cfg_result;               /* Status of the last configuration service in LIN 2.0, J2602 */
l_u8 tl_last_RSID;                                    /* RSID of the last node configuration service */
l_u8 tl_ld_error_code;                                /* Error code in case of positive response */
l_u8 tl_no_of_pdu;                                    /* number of received pdu */
l_u8 tl_frame_counter;                                /* frame counter in received message */
lin_message_timeout_type tl_check_timeout_type;       /* timeout type */
l_u16 tl_check_timeout;                               /* timeout counter*/
l_u8 *tl_ident_data;                                  /* To store address of RAM area contain response */
    $if(is_xgate_support)$
#pragma DATA_SEG SHARED_DATA
    $endif$
lin_diagnostic_state tl_diag_state   =  LD_DIAG_IDLE;
lin_service_status tl_service_status =  LD_SERVICE_IDLE ; /* service status */
lin_message_status tl_receive_msg_status;             /* receive message status */
lin_message_status tl_rx_msg_status;                  /* cooked rx status */
lin_message_status tl_tx_msg_status;                  /* cooked tx status */
    $if(is_xgate_support)$
#pragma DATA_SEG DEFAULT
    $endif$
  $endif$
$endif$


$if(is_master_mode)$
$else$
  $if(diagnotic_class_1)$
/************************** TL Layer and Diagnostic: SINGLE interface **************************/
lin_tl_pdu_data tx_single_pdu_data = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
lin_tl_pdu_data rx_single_pdu_data = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  $endif$
$endif$

$list_go_to_sleep_initial_map: { go_to_sleep_initial |
/********************** Go to sleep Initialization *************************/
/* Delay of this schedule table is: (1.4*(34+10*(8+1))*1000/LIN_speed+jitter) ms */
/* then rounded up to a value is multiple of time base */
const lin_schedule_data $go_to_sleep_initial.("interface_name")$_lin_gotosleep_data[1] = {
   {$go_to_sleep_initial.("interface_name")$_$go_to_sleep_initial.("master_req_frame_index")$, $go_to_sleep_initial.("gotosleep_timebase")$, {0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}}
};
}$
$list_schedule_data_map: { sch_data |
/******************** Schedule table Initialization ************************/
const lin_schedule_data $sch_data.("interface_name")$_$sch_data.("schedule_table_name")$_data[$sch_data.("number_command")$] = {
 $first(sch_data.("schedule_data_map_items")):{ sch_data_item |
  {$sch_data.("interface_name")$_$sch_data_item.mapItem.("command_name")$, $sch_data_item.mapItem.("frame_time")$, $sch_data_item.mapItem.("command_data")$}
 }$
 $rest(sch_data.("schedule_data_map_items")):{ sch_data_item |
  , {$sch_data.("interface_name")$_$sch_data_item.mapItem.("command_name")$, $sch_data_item.mapItem.("frame_time")$, $sch_data_item.mapItem.("command_data")$}
 }$
};
}$

$list_schedule_data_map1: { sch_data |
/******************** Schedule table Initialization ************************/
/* If not specify by users, then by default delay of this schedule table is: */
/* (1.4*(34+10*(8+1))*1000/LIN_speed+jitter) ms, then rounded up to a value */
/* that is multiple of time base */
const lin_schedule_data $sch_data.("interface_name")$_$sch_data.("schedule_table_name")$_data[$sch_data.("number_command")$] = {
 $first(sch_data.("schedule_data_map_items")):{ sch_data_item |
  {$sch_data.("interface_name")$_$sch_data_item.mapItem.("command_name")$, $sch_data_item.mapItem.("frame_time")$, $sch_data_item.mapItem.("command_data")$}
 }$
 $rest(sch_data.("schedule_data_map_items")):{ sch_data_item |
  , {$sch_data.("interface_name")$_$sch_data_item.mapItem.("command_name")$, $sch_data_item.mapItem.("frame_time")$, $sch_data_item.mapItem.("command_data")$}
 }$
};
}$


$if(is_master_mode)$
/********************* Schedule table structure Initialization ***************/
const lin_schedule_struct lin_schedule_tbl[LIN_NUM_OF_SCHD_TBL] ={
 $first(list_schedule_struct_map): { sch_struct |
  /*interface_name = $sch_struct.mapItem.("interface_name")$ */
  {$sch_struct.mapItem.("number_of_command")$, $sch_struct.mapItem.("schedule_table_type")$ $if(sch_struct.mapItem.("is_null_address"))$ ,$sch_struct.mapItem.("schedule_table_name")$ $else$,$sch_struct.mapItem.("interface_name")$_$sch_struct.mapItem.("schedule_table_name")$ $endif$}
 }$
 $rest(list_schedule_struct_map): {sch_struct |
  ,{$sch_struct.mapItem.("number_of_command")$, $sch_struct.mapItem.("schedule_table_type")$ $if(sch_struct.mapItem.("is_null_address"))$ , $sch_struct.mapItem.("schedule_table_name")$ $else$ , &$sch_struct.mapItem.("interface_name")$_$sch_struct.mapItem.("schedule_table_name")$_data[0] $endif$}
 }$
};
/********************** Schedule table status Initialization ******************/
l_u8 lin_schedule_start_entry[LIN_NUM_OF_SCHD_TBL] = {$list_schd_table_zero_data; separator=", "$};
l_u8 lin_active_schedule_id[LIN_NUM_OF_IFCS] = {$list_intf_zero_data; separator=", "$};
l_u8 lin_previous_schedule_id[LIN_NUM_OF_IFCS] = {$list_intf_zero_data; separator=", "$};
$else$
$endif$


$if(is_master_mode)$
  $if(diagnotic_class_1)$
l_u8 lin_diag_frame_to_send[LIN_NUM_OF_IFCS] = {$list_intf_zero_data; separator=", "$};
/********************** PDU data Initialization *******************************/
lin_tl_pdu_data tx_single_pdu_data[LIN_NUM_OF_IFCS] = {
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
$rest(list_intf_zero_data):{
,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
}$
};
lin_tl_pdu_data rx_single_pdu_data[LIN_NUM_OF_IFCS] = {
 {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
$rest(list_intf_zero_data):{
,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
}$
};
  $endif$
$endif$


$if(is_master_mode)$
$else$
  $if(diagnotic_class_3)$
  $else$
  $endif$
$endif$

$if(is_master_mode)$
  $if(diagnotic_class_1)$
  $endif$
$else$
$list_intf_node_item: { intf_node |
  $if(intf_node.mapItem.("is_master_node"))$
lin_tl_pdu_data $intf_node.key$_tl_tx_queue_data[MAX_QUEUE_SIZE];
lin_tl_pdu_data $intf_node.key$_tl_rx_queue_data[MAX_QUEUE_SIZE];
  $endif$
}$
$endif$


$if(is_master_mode)$
  $if(diagnotic_class_1)$
  $else$
lin_diagnostic_state diagnostic_state[LIN_NUM_OF_IFCS] = {
   LD_DIAG_IDLE $rest(list_intf_zero_data):{, LD_DIAG_IDLE }$
};
l_u8 lin_diag_frame_to_send[LIN_NUM_OF_IFCS] = {$list_intf_zero_data; separator=", "$};
    $if(is_xgate_support)$
#pragma DATA_SEG SHARED_DATA
    $endif$

lin_service_status   service_status[LIN_NUM_OF_IFCS]   = {
   LD_SERVICE_IDLE $rest(list_intf_zero_data):{, LD_SERVICE_IDLE }$
};
l_diagnostic_mode diag_mode[LIN_NUM_OF_IFCS] = {$list_string_DIAG_NONE; separator=", "$};
    $if(is_xgate_support)$
#pragma DATA_SEG DEFAULT
    $endif$

$first(list_intf_node_item): { intf_node |

lin_tl_pdu_data $intf_node.key$_tl_tx_queue_data[MAX_QUEUE_SIZE];
lin_tl_pdu_data $intf_node.key$_tl_rx_queue_data[MAX_QUEUE_SIZE];

}$
$rest(list_intf_node_item): { intf_node |

lin_tl_pdu_data $intf_node.key$_tl_tx_queue_data[MAX_QUEUE_SIZE];
lin_tl_pdu_data $intf_node.key$_tl_rx_queue_data[MAX_QUEUE_SIZE];

}$

lin_transport_layer_queue lin_tl_tx_queue[LIN_NUM_OF_IFCS] = {
$first(list_intf_node_item): { intf_node |
    $if(intf_node.mapItem.("is_master_node"))$
   { 0, 0, LD_QUEUE_EMPTY, 0, MAX_QUEUE_SIZE, $intf_node.key$_tl_tx_queue_data }
    $else$
   { 0, 0, LD_QUEUE_EMPTY, 0,MAX_QUEUE_SIZE, $intf_node.key$_tl_tx_queue_data }
    $endif$
}$
$rest(list_intf_node_item): { intf_node |
    $if(intf_node.mapItem.("is_master_node"))$
   ,{ 0, 0, LD_QUEUE_EMPTY, 0, MAX_QUEUE_SIZE, $intf_node.key$_tl_tx_queue_data }
    $else$
   ,{ 0, 0, LD_QUEUE_EMPTY, 0,MAX_QUEUE_SIZE, $intf_node.key$_tl_tx_queue_data }
    $endif$
}$
};
lin_transport_layer_queue lin_tl_rx_queue[LIN_NUM_OF_IFCS] = {
$first(list_intf_names): { intf_name |
   { 0, 0, LD_QUEUE_EMPTY, 0, MAX_QUEUE_SIZE, $intf_name$_tl_rx_queue_data }
}$
$rest(list_intf_names): { intf_name |
   ,{ 0, 0, LD_QUEUE_EMPTY, 0, MAX_QUEUE_SIZE, $intf_name$_tl_rx_queue_data }
}$
};
  $endif$
$endif$

$if(is_master_mode)$
  $if(diagnotic_class_2)$
/* diagnostic interleaved mode */
diag_interleaved_state lin_diag_interleaved_state[LIN_NUM_OF_IFCS] = { $list_string_DIAG_NOT_START; separator=", "$ };
  $endif$
  $if(diagnotic_class_3)$
/* diagnostic interleaved mode */
diag_interleaved_state lin_diag_interleaved_state[LIN_NUM_OF_IFCS] = {$list_string_DIAG_NOT_START; separator=", "$};

  $endif$
$endif$

$if(is_using_gpio)$
$else$
/****************************Support SID Initialization ***********************/
$if(is_master_mode)$
$list_support_sid: { support_sid |
const l_u8 $support_sid.("interface_name")$_lin_diag_services_supported[_$support_sid.("interface_name")$_DIAG_NUMBER_OF_SERVICES_] = {$support_sid.("list_sid_number")$};
l_u8 $support_sid.("interface_name")$_lin_diag_services_flag[_$support_sid.("interface_name")$_DIAG_NUMBER_OF_SERVICES_] = {$support_sid.("list_service_flag")$};
}$
$else$
$list_support_sid: { support_sid |
const l_u8 lin_diag_services_supported[_DIAG_NUMBER_OF_SERVICES_] = {$support_sid.("list_sid_number")$};
l_u8 lin_diag_services_flag[_DIAG_NUMBER_OF_SERVICES_] = {$support_sid.("list_service_flag")$};
}$
$endif$
$endif$

$if(is_master_mode)$

/****************************Transport Layer Initialization ***********************/
  $if(diagnotic_class_1)$
  $else$
    $if(is_xgate_support)$
#pragma DATA_SEG SHARED_DATA
    $endif$
  $endif$

lin_tl_descriptor lin_tl_desc[LIN_NUM_OF_IFCS] = {
$first(list_intf_names): { intf_name |
   /* interface_name = $intf_name$ */
   {
  $if(diagnotic_class_1)$
   &tx_single_pdu_data[$intf_name$],          /* *pointer to transmit queue on TL */
   &rx_single_pdu_data[$intf_name$],          /* *pointer to receive queue on TL */
  $else$
   &lin_tl_tx_queue[$intf_name$],          /* *pointer to transmit queue on TL */
   &lin_tl_rx_queue[$intf_name$],          /* *pointer to receive queue on TL */
  $endif$
  $if(diagnotic_class_1)$
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
   _$intf_name$_DIAG_NUMBER_OF_SERVICES_,
   (l_u8*) &$intf_name$_lin_diag_services_supported,
   (l_u8*) &$intf_name$_lin_diag_services_flag,           /* diagnostic services flags*/
   0, /* tl_slaveresp_cnt */
   /* End of declaration only for Slave interface */
  $endif$

  $if(diagnotic_class_1)$
  $else$
   /* Declaration only for Master interface */
   /* message in transmit queue */
   LD_COMPLETED,           /* status of message in transmit queue */
   0,                /* index of message in queue */
   0,                /* Size of message in queue */
   /* message in receive queue */
   LD_NO_MSG,            /* status of receiving message */
   LD_COMPLETED,           /* status of message in transmit queue */
   0,                /* index of message in queue */
   0,                /* Size of message in queue */
   LD_SUCCESS,           /* Status of the last configuration service in LIN 2.0, J2602 */
   0,                /* RSID of the last node configuration service */
   0,                /* Error code in case of positive response */
   0,                /* number of received pdu */
   0,                /* frame counter in received message */
   LD_NO_CHECK_TIMEOUT,            /* timeout type */
   0,
   /* Declaration only for Slave interface */
   (l_u8*)0,
   0,                   /* Slave Response data counter */
   _$intf_name$_DIAG_NUMBER_OF_SERVICES_,
   (l_u8*) &$intf_name$_lin_diag_services_supported,
   (l_u8*) &$intf_name$_lin_diag_services_flag,           /* diagnostic services flags*/
   0           /* Interleaved time out counter */
  $endif$
   }
}$
$rest(list_intf_names): { intf_name |
   /*interface_name = $intf_name$*/
   ,{
  $if(diagnotic_class_1)$
   &tx_single_pdu_data[$intf_name$],          /* *pointer to transmit queue on TL */
   &rx_single_pdu_data[$intf_name$],          /* *pointer to receive queue on TL */
  $else$
   &lin_tl_tx_queue[$intf_name$],          /* *pointer to transmit queue on TL */
   &lin_tl_rx_queue[$intf_name$],          /* *pointer to receive queue on TL */
  $endif$
  $if(diagnotic_class_1)$
   (lin_tl_pdu_data*)0,          /* *tl_current_tx_pdu_ptr */
   (lin_tl_pdu_data*)0,          /* *tl_current_rx_pdu_ptr */
   /* Declaration only for Master interface */
   0,      /* tl_cnt_to_send */
   LD_SERVICE_IDLE,    /* tl_service_status */
   LD_SUCCESS,   /* tl_last_cfg_result */
   0,    /* last_RSID */
   0,    /* ld_error_code */
   (l_u8*)0,   /* *tl_ident_data */
   _$intf_name$_DIAG_NUMBER_OF_SERVICES_,
   (l_u8*) &$intf_name$_lin_diag_services_supported,
   (l_u8*) &$intf_name$_lin_diag_services_flag,           /* diagnostic services flags*/
   0 /* tl_slaveresp_cnt */
   /* End of declaration for only Master interface */
  $endif$
  $if(diagnotic_class_1)$
  $else$
   /* Declaration only for Master interface */
   /* message in transmit queue */
   LD_COMPLETED,           /* status of message in transmit queue */
   0,                /* index of message in queue */
   0,                /* Size of message in queue */
   /* message in receive queue */
   LD_NO_MSG,            /* status of receiving message */
   LD_COMPLETED,           /* status of message in transmit queue */
   0,                /* index of message in queue */
   0,                /* Size of message in queue */
   LD_SUCCESS,           /* Status of the last configuration service in LIN 2.0, J2602 */
   0,                /* RSID of the last node configuration service */
   0,                /* Error code in case of positive response */
   0,                /* number of received pdu */
   0,                /* frame counter in received message */
   LD_NO_CHECK_TIMEOUT,    /* timeout type */
   0,
   /* Declaration only for Slave interface */
   (l_u8*)0,
   0,                 /* Slave Response data counter */
   _$intf_name$_DIAG_NUMBER_OF_SERVICES_,
   (l_u8*) &$intf_name$_lin_diag_services_supported,
   (l_u8*) &$intf_name$_lin_diag_services_flag,           /* diagnostic services flags*/
   0           /* Interleaved time out counter */
  $endif$
   }
}$
};
  $if(diagnotic_class_1)$
  $else$
    $if(is_xgate_support)$
#pragma DATA_SEG DEFAULT
    $endif$
  $endif$
$else$
  $if(diagnotic_class_1)$
lin_tl_pdu_data *tl_current_tx_pdu_ptr;
lin_tl_pdu_data *tl_current_rx_pdu_ptr;
  $endif$
l_u8 tl_slaveresp_cnt = 0;
$endif$

$if(is_master_mode)$
/****************************LIN interface configuration ****************************/
const lin_configuration lin_ifc_configuration[LIN_NUM_OF_IFCS] = {
$first(list_ifc_cfg_map): { ifc_cfg |
   /* Interface_name = $ifc_cfg.mapItem.("interface_name")$ */
   {
   $ifc_cfg.mapItem.("lin_protocol_version")$,         /*lin_protocol_version */
   $ifc_cfg.mapItem.("lin_protocol_version")$,         /*lin_language_version */
   $ifc_cfg.mapItem.("lin_baud_rate")$,            /*  baud_rate */
  $if(ifc_cfg.mapItem.("is_lin_master_node"))$
   _MASTER_,                 /*  function _SLAVE_ | _MASTER_*/
   0,                        /*  node attribute is only used for slave node*/
  $else$
   _SLAVE_,                  /*  function _SLAVE_ | _MASTER_*/
   &$ifc_cfg.mapItem.("interface_name")$_node_attribute,             /*  node attribute */
  $endif$
   /* LIN data pointer */
   &lin_lld_response_buffer[$ifc_cfg.mapItem.("interface_name")$][0],        /*  *response_buffer */
   &lin_successful_transfer[$ifc_cfg.mapItem.("interface_name")$],           /*  *lin_successful_transfer */
   &lin_error_in_response[$ifc_cfg.mapItem.("interface_name")$],             /*  *lin_error_in_response */
   &lin_goto_sleep_flg[$ifc_cfg.mapItem.("interface_name")$],              /*  *goto_sleep_flg */
   &lin_current_pid[$ifc_cfg.mapItem.("interface_name")$],                 /*  *current_pid */
   &lin_word_status[$ifc_cfg.mapItem.("interface_name")$],                 /*  *word_status */
   /* Protocol */
  $if(ifc_cfg.mapItem.("is_lin_master_node"))$
   $ifc_cfg.mapItem.("time_base")$,                          /*  time_base */
  $else$
   0,        /* timebase is not used in Slave node*/
  $endif$
   &lin_diag_signal_tbl[$ifc_cfg.mapItem.("interface_name")$][0],          /*  *diag_signal_tbl */
   $ifc_cfg.mapItem.("num_of_frames")$,                            /*  num_of_frames */
   $ifc_cfg.mapItem.("frame_start")$,                              /*  frame_start */
   &lin_frame_tbl[0],                                          /*  frame_tbl */
   &lin_frame_flag_tbl[0],                                       /*  *frame_flg */

  $if(ifc_cfg.mapItem.("is_lin_master_node"))$
   $ifc_cfg.mapItem.("num_of_schedules")$,                     /*  num_of_schedules */
   $ifc_cfg.mapItem.("schedule_start")$,                       /*  schedule_start */
   &lin_schedule_tbl[0],                                   /*  schedule_tbl */
   &lin_schedule_start_entry[0],                             /*  schedule_start_entry */
   &lin_next_transmit[$ifc_cfg.mapItem.("interface_name")$],             /*  next_transmit_tick */
   &lin_active_schedule_id[$ifc_cfg.mapItem.("interface_name")$],          /*  active_schedule_id */
   &lin_previous_schedule_id[$ifc_cfg.mapItem.("interface_name")$],        /*  previous_schedule_id */
   &lin_diag_frame_to_send[$ifc_cfg.mapItem.("interface_name")$],          /*  *diagnostic_frame_to_send */
  $else$
   0,                                  /*  num_of_schedules */
   0,                                  /*  schedule_start */
   (const lin_schedule_struct *)0,             /* schedule_tbl */
   (l_u8*)0,        /*  *schedule_start_entry */
   (l_u8*)0,        /*  *next_transmit_tick */
   (l_u8*)0,        /*  *active_schedule_id */
   (l_u8*)0,        /*  *previous_schedule_id */
   (l_u8*)0,        /*  *diagnostic_frame_to_send */
  $endif$
  $if(diagnotic_class_2)$
   &diag_mode[$ifc_cfg.mapItem.("interface_name")$],                   /*  diagnostic_mode */
   &$ifc_cfg.mapItem.("interface_name")$_lin_configuration_RAM[0],       /*  *configuration_RAM */
   &$ifc_cfg.mapItem.("interface_name")$_lin_configuration_ROM[0],       /*  *configuration_ROM */
   &lin_tl_desc[$ifc_cfg.mapItem.("interface_name")$],
   &diagnostic_state[$ifc_cfg.mapItem.("interface_name")$],
   &service_status[$ifc_cfg.mapItem.("interface_name")$],
   &lin_diag_interleaved_state[$ifc_cfg.mapItem.("interface_name")$]
  $endif$
  $if(diagnotic_class_1)$
   DIAG_NONE,    /*  diagnostic_mode */
   &$ifc_cfg.mapItem.("interface_name")$_lin_configuration_RAM[0],   /*  *configuration_RAM */
   &$ifc_cfg.mapItem.("interface_name")$_lin_configuration_ROM[0],   /*  *configuration_ROM */
   &lin_tl_desc[$ifc_cfg.mapItem.("interface_name")$]
  $endif$
  $if(diagnotic_class_3)$
   &diag_mode[$ifc_cfg.mapItem.("interface_name")$],   /*  diagnostic_mode */
   &$ifc_cfg.mapItem.("interface_name")$_lin_configuration_RAM[0],   /*  *configuration_RAM */
   &$ifc_cfg.mapItem.("interface_name")$_lin_configuration_ROM[0],   /*  *configuration_ROM */
   &lin_tl_desc[$ifc_cfg.mapItem.("interface_name")$],
   &diagnostic_state[$ifc_cfg.mapItem.("interface_name")$],
   &service_status[$ifc_cfg.mapItem.("interface_name")$],
   &lin_diag_interleaved_state[$ifc_cfg.mapItem.("interface_name")$]
  $endif$
   }
}$
$rest(list_ifc_cfg_map): { ifc_cfg |
   ,{
   /* interface_name = $ifc_cfg.mapItem.("interface_name")$ */
   $ifc_cfg.mapItem.("lin_protocol_version")$,           /*lin_protocol_version */
   $ifc_cfg.mapItem.("lin_protocol_version")$,           /*lin_language_version */
   $ifc_cfg.mapItem.("lin_baud_rate")$,                /*  baud_rate */
  $if(ifc_cfg.mapItem.("is_lin_master_node"))$
   _MASTER_,                           /*  function _SLAVE_ | _MASTER_*/
   (lin_node_attribute*)0,                   /*  node attribute is only used for slave node*/
  $else$
   _SLAVE_,                              /*  function _SLAVE_ | _MASTER_*/
   &$ifc_cfg.mapItem.("interface_name")$_node_attribute,   /*  node attribute */
  $endif$

   /* LIN data pointer */
   &lin_lld_response_buffer[$ifc_cfg.mapItem.("interface_name")$][0],      /*  *response_buffer */
   &lin_successful_transfer[$ifc_cfg.mapItem.("interface_name")$],         /*  *lin_successful_transfer */
   &lin_error_in_response[$ifc_cfg.mapItem.("interface_name")$],           /*  *lin_error_in_response */
   &lin_goto_sleep_flg[$ifc_cfg.mapItem.("interface_name")$],            /*  *goto_sleep_flg */
   &lin_current_pid[$ifc_cfg.mapItem.("interface_name")$],               /*  *current_pid */
   &lin_word_status[$ifc_cfg.mapItem.("interface_name")$],               /*  *word_status */
   /* Protocol */
  $if(ifc_cfg.mapItem.("is_lin_master_node"))$
   $ifc_cfg.mapItem.("time_base")$,                      /*  time_base */
  $else$
   0,                                    /* timebase is not used in Slave node*/
  $endif$

   &lin_diag_signal_tbl[$ifc_cfg.mapItem.("interface_name")$][0],       /*  diag_signal_tbl */
   $ifc_cfg.mapItem.("num_of_frames")$,      /*  num_of_frames */
   $ifc_cfg.mapItem.("frame_start")$,        /*  frame_start */
   &lin_frame_tbl[0],                /* frame_tbl */
   &lin_frame_flag_tbl[0],             /*frame_flg */

  $if(ifc_cfg.mapItem.("is_lin_master_node"))$
   $ifc_cfg.mapItem.("num_of_schedules")$,       /*  num_of_schedules */
   $ifc_cfg.mapItem.("schedule_start")$,         /*  schedule_start */
   &lin_schedule_tbl[0],                 /*schedule_tbl */
   &lin_schedule_start_entry[0],             /*schedule_start_entry */
   &lin_next_transmit[$ifc_cfg.mapItem.("interface_name")$],             /* next_transmit_tick */
   &lin_active_schedule_id[$ifc_cfg.mapItem.("interface_name")$],        /*  active_schedule_id */
   &lin_previous_schedule_id[$ifc_cfg.mapItem.("interface_name")$],      /*  previous_schedule_id */
   &lin_diag_frame_to_send[$ifc_cfg.mapItem.("interface_name")$],        /*  diagnostic_frame_to_send */
  $else$
   0,      /*  num_of_schedules */
   0,      /*  schedule_start */
   (const lin_schedule_struct *)0,      /*  *schedule_tbl */
   (l_u8*)0,        /*  *schedule_start_entry */
   (l_u8*)0,        /*  *next_transmit_tick */
   (l_u8*)0,        /*  *active_schedule_id */
   (l_u8*)0,        /*  *previous_schedule_id */
   (l_u8*)0,        /*  *diagnostic_frame_to_send */
  $endif$
    $if(diagnotic_class_2)$
   &diag_mode[$ifc_cfg.mapItem.("interface_name")$ ],                  /*  diagnostic_mode */
   &$ifc_cfg.mapItem.("interface_name")$_lin_configuration_RAM[0],       /*  *configuration_RAM */
   &$ifc_cfg.mapItem.("interface_name")$_lin_configuration_ROM[0],       /*  *configuration_ROM */
   &lin_tl_desc[$ifc_cfg.mapItem.("interface_name")$ ],
   &diagnostic_state[$ifc_cfg.mapItem.("interface_name")$ ],
   &service_status[$ifc_cfg.mapItem.("interface_name")$ ],
   &lin_diag_interleaved_state[$ifc_cfg.mapItem.("interface_name")$ ]
  $endif$
  $if(diagnotic_class_1)$
   DIAG_NONE,    /*  diagnostic_mode */
   &$ifc_cfg.mapItem.("interface_name")$_lin_configuration_RAM[0],   /*  *configuration_RAM */
   &$ifc_cfg.mapItem.("interface_name")$_lin_configuration_ROM[0],   /*  *configuration_ROM */
   &lin_tl_desc[$ifc_cfg.mapItem.("interface_name")$]
  $endif$
  $if(diagnotic_class_3)$
   &diag_mode[$ifc_cfg.mapItem.("interface_name")$ ],    /*  diagnostic_mode */
   &$ifc_cfg.mapItem.("interface_name")$_lin_configuration_RAM[0],   /*  *configuration_RAM */
   &$ifc_cfg.mapItem.("interface_name")$_lin_configuration_ROM[0],   /*  *configuration_ROM */
   &lin_tl_desc[$ifc_cfg.mapItem.("interface_name")$] ,
   &diagnostic_state[$ifc_cfg.mapItem.("interface_name")$],
   &service_status[$ifc_cfg.mapItem.("interface_name")$],
   &lin_diag_interleaved_state[$ifc_cfg.mapItem.("interface_name")$]
  $endif$
  }
 }$
};
$endif$

$if (is_master_mode)$
  $if(is_xgate_support)$
#pragma DATA_SEG SHARED_DATA
  $endif$
/*************************** Node hardware configuration definition *************************/
/* Node hardware configuration */
  $if(is_xgate_support)$
    $if(is_using_sci)$
lin_node lin_node_descrs[NUM_OF_SCI_CHANNEL]={
        $if(number1)$
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT, 0, 0, 0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number2)$
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0, 0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0, 0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number3)$
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI2_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number4)$
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI2_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI3_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number5)$
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI2_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI3_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI4_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number6)$
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI2_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI3_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI4_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI5_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
};
    $else$
lin_node lin_node_descrs[NUM_OF_SCI_CHANNEL]={
        $if(number1)$
   {(tUART*)UART0_ADDR, 0, 0xFF, UNINIT, 0, 0, 0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number2)$
   {(tUART*)UART0_ADDR, 0, 0xFF, UNINIT,  0, 0, 0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tUART*)UART1_ADDR, 0, 0xFF, UNINIT,  0, 0, 0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number3)$
   {(tUART*)UART0_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tUART*)UART1_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tUART*)UART2_ADDR, 0, 0xFF, UNINIT,  0, 0,0x00, (l_u8*)0, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
    $endif$
  $else$
    $if(is_using_sci)$
lin_node lin_node_descrs[NUM_OF_SCI_CHANNEL]={
        $if(number1)$
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number2)$
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number3)$
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI2_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number4)$
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI2_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI3_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number5)$
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI2_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI3_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI4_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number6)$
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI2_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI3_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI4_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI5_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
    $else$
lin_node lin_node_descrs[NUM_OF_UART_CHANNEL]={
        $if(number1)$
   {(tUART*)UART0_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number2)$
   {(tUART*)UART0_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tUART*)UART1_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
        $if(number3)$
   {(tUART*)UART0_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tUART*)UART1_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tUART*)UART2_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 }
        $endif$
    $endif$
};
  $endif$

  $if(is_xgate_support)$
#pragma DATA_SEG DEFAULT
  $endif$
$endif$

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
$if(is_slave_mode)$
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
$else$
  $if(all_master)$
l_u8 ld_read_by_id_callout(l_ifc_handle iii, l_u8 id, l_u8 *data){
    (void) iii;
    (void) id;
    (void) data;
    return LD_NEGATIVE_RESPONSE;
}
  $else$
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
  $endif$
$endif$
