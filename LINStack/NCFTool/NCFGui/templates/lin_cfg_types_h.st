/****************************************************************************** 
* 
* Freescale Semiconductor Inc. 
* (c) Copyright $from_year$-$to_year$ Freescale Semiconductor, Inc. 
* ALL RIGHTS RESERVED. 
* 
****************************************************************************//*! 
* 
* @file      lin_cfg_types.h 
* 
* @author    FPT Software
*  
* @version   1.0 
*  
* @date      $date$
*  
* @brief     configuration file for LIN 2.1 driver
* 
******************************************************************************/

/** \file lin_cfg_types.h
 */

#ifndef LIN_CFG_TYPES_H
#define LIN_CFG_TYPES_H


#define LIN_CFG_TYPES_H_MAJOR_VERSION          0
#define LIN_CFG_TYPES_H_MINOR_VERSION          9
#define LIN_CFG_TYPES_H_PATCH_VERSION          2

#define LIN_CFG_TYPES_H_STM

#ifdef LIN_VERSION_CONTROL_H
  #error "lin_version_control.h shall not be included in h-files and shall be the last file to be included in a c-file!"
#endif /* LIN_VERSION_CONTROL_H */

/*
 * definition of the interfaces used
 */
$list_sci_name: { sci_itf |
#define $sci_itf$_USED
}$
/*
 * important defines for array size definitions
 */
#define LIN_FLAG_DATA_LEN               ((LIN_FLAG_NR_MAX+CHAR_BIT-1) / CHAR_BIT)
#define LIN_FRAME_BUF_SIZE              $frame_buf_size$
#define LIN_TRANSMIT_FLAG_DATA_SIZE     $transmit_flag_data_size$
#define LIN_CHANGED_FLAG_DATA_SIZE      $changed_flag_data_size$
$if(include_evt_trig_count)$
#define LIN_EVENT_TRIGGERED_COUNT       $evt_trig_count$
$endif$

$if(is_master_node)$
$if(is_lin_version21)$
#define SCHEDULE_TABLE_COUNT            $schedule_table_count$
$endif$
$else$
#define LIN_FRAME_COUNT                 $frame_count$
#define LIN_TOTAL_TX_FRAMES             $total_tx_frames$
#define LIN_TOTAL_RX_FRAMES             $total_rx_frames$
$endif$

$if(is_lin_version21)$
$if(include_diag_table_definition)$
$list_diag_table_definition : { item | 
#define $item.("definition")$             LIN_TAB_$item.("value")$}$
$endif$
$endif$

$if(include_schtab_nrmax_def)$
#define LIN_SCH_TAB_NR_MAX              $schtab_nrmax_index$
$endif$

/*
 * important defines that configure the code depending
 * on information extracted from the LDF file
 */ 
$if(is_master_node)$
#define LIN_MASTER_NODE 1
$else$
#define LIN_SLAVE_NODE  1
$endif$

$if(is_lin_version21)$
#define LIN_21
$else$
#define LIN_20
$endif$

$if(include_evt_trig_frames)$
#define LIN_INCLUDE_EVT_TRIG_FRAMES
$endif$



$if(is_master_node)$
  $if(include_sporadic_frames)$
#define LIN_INCLUDE_SPORADIC_FRAMES
  $endif$
  $if(include_sporadic_slave_frames)$
#define LIN_INCLUDE_SPORADIC_SLAVE_FRAMES
  $endif$
$endif$



/*
 * enumeration of frame identifiers
 */
typedef enum
{$list_frame_handle: {frame_handle |
  LIN_FRAME_$frame_handle.("frame_name")$ =    $frame_handle.("index")$,}$ 
  LIN_FRAME_NR_MAX =    $frame_nr_max_index$,
  LIN_INVALID_FRAME_INDEX =    0x7FFF
} l_frame_handle;

$if(is_master_node)$
/*
 * schedule table identifier enumeration
 */
typedef enum
{$list_schedule_handle: {schedule_handle |
  LIN_TAB_$schedule_handle.("table_name")$,     /* $schedule_handle.("index")$ */ }$
  LIN_TAB_GOTO_SLEEP,     /* $goto_sleep_index$ */
  L_NULL_SCHEDULE,
  LIN_SCHED_TAB_NR_MAX
} l_schedule_handle;
$endif$


#endif
