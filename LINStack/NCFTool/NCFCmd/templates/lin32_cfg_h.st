/****************************************************************************** 
* 
* Freescale Semiconductor Inc. 
* (c) Copyright $from_year$-$to_year$ Freescale Semiconductor, Inc. 
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
* @date      $date$
*  
* @brief     configuration file for LIN 2.1 driver
* 
******************************************************************************/
$!
<lin_cfg.h file> ::= 
	<general_def> 
	<signal_flag_def> 
	<frame_flag_def>   
	<interface_handle_def>  
	<signal_handle_def>  
	<frame_handle_def>  
	<schedule_table_def>   
	<configuration_def> 
!$
/** \file lin_cfg.h
 */

#ifndef LIN_CFG_H
#define LIN_CFG_H

#define LIN_CFG_H_MAJOR_VERSION          0
#define LIN_CFG_H_MINOR_VERSION          9
#define LIN_CFG_H_PATCH_VERSION          2

#define LIN_CFG_H_STM

/*
 * include files
 */
#include "lin_cfg_types.h"
#include "lin_types.h"
#include "lin_def_arch_include.h"
#include "lin_def.h"
#include "lin_def_gen.h"
$if(is_master_node)$
#include "lin_diag_master.h"
$else$
#include "lin_diag_slave.h"
$endif$


#ifdef LIN_VERSION_CONTROL_H
  #error "lin_version_control.h shall not be included in h-files and shall be the last file to be included in a c-file!"
#endif /* LIN_VERSION_CONTROL_H */

/*
 * declaration of functions
 */
$if(is_master_node)$
STACK extern void l_serialError(__OPTIONAL_IFC_DEFINITION__);

STACK extern void l_stateSendData(__OPTIONAL_IFC_DEFINITION__);

STACK extern void l_stateReceiveData(__OPTIONAL_IFC_DEFINITION_COMMA__ l_u32 rxBuffL, l_u32 rxBuffM);

/*
 * declaration of external variables
 */
LIN_ZERO_PAGE14 extern l_u8                      l_pFrameBuf[LIN_FRAME_BUF_SIZE];
LIN_ZERO_PAGE11 extern l_u8                      l_pTxFlagData[LIN_TRANSMIT_FLAG_DATA_SIZE];
LIN_ZERO_PAGE12 extern l_u8                      l_pRxFlagData[LIN_TRANSMIT_FLAG_DATA_SIZE];
LIN_ZERO_PAGE13 extern l_u8                      l_pChangedFlagData[LIN_CHANGED_FLAG_DATA_SIZE];
$if(include_schtab_nrmax_def)$
extern const l_u8            l_pSchTabIfc[LIN_SCH_TAB_NR_MAX];
$endif$
$else$
STACK extern void l_serialErrorFrameBody(__OPTIONAL_IFC_DEFINITION_COMMA__ l_u8 status);

STACK extern void l_stateSendData(__OPTIONAL_IFC_DEFINITION__ );

STACK extern void l_stateReceiveData(__OPTIONAL_IFC_DEFINITION_COMMA__ l_u32 rxBuffL, l_u32 rxBuffM);

STACK extern void l_stateReceiveIdentifier(__OPTIONAL_IFC_DEFINITION_COMMA__ l_u8 rxChar);


/*
 * declaration of external variables
 */
LIN_ZERO_PAGE15 extern l_u8                      l_pFrameId[LIN_FRAME_COUNT];
extern const l_u16                               l_pMessageId[LIN_FRAME_COUNT];
$if(is_lin_version21)$
extern const l_u8                                l_pConfigFrameOrder[LIN_FRAME_COUNT];
$endif$

LIN_ZERO_PAGE14 extern l_u8                      l_pFrameBuf[LIN_FRAME_BUF_SIZE];
LIN_ZERO_PAGE11 extern l_u8                      l_pTxFlagData[LIN_TRANSMIT_FLAG_DATA_SIZE];
LIN_ZERO_PAGE12 extern l_u8                      l_pRxFlagData[LIN_TRANSMIT_FLAG_DATA_SIZE];
LIN_ZERO_PAGE13 extern l_u8                      l_pChangedFlagData[LIN_CHANGED_FLAG_DATA_SIZE];
extern l_filter_t                                l_pFrameInfo[(LIN_FRAME_COUNT - 2)];
extern l_productId_t                             l_productId;
extern l_u8                                      l_initialNad;
$if(is_lin_version21)$
extern l_u8                                      l_configuredNad;
extern l_u16                                     l_P2_min;
extern l_u16                                     l_ST_min;
extern l_u16                                     l_N_As_timeout;
extern l_u16                                     l_N_Cr_timeout;
$endif$
$endif$

/*
 * write mapping of dynamic functions
 * (needed internally)
 */
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


/*
 * defines for signal access
 */
$list_signal_access: { signal_access |
$signal_access.("normal_frame_handle") : { signal_item |
#define LIN_BYTE_OFFSET_$signal_item.("signal_name")$    $signal_item.("byte_offset")$
#define LIN_BIT_OFFSET_$signal_item.("signal_name")$    $signal_item.("bit_offset")$
#define LIN_SIGNAL_SIZE_$signal_item.("signal_name")$    $signal_item.("signal_size")$
}$
$signal_access.("master_req_handle") : { signal_item |
#define LIN_BYTE_OFFSET_$signal_item.("signal_name")$    $signal_item.("byte_offset")$
#define LIN_BIT_OFFSET_$signal_item.("signal_name")$    $signal_item.("bit_offset")$
#define LIN_SIGNAL_SIZE_$signal_item.("signal_name")$    $signal_item.("signal_size")$
}$
$signal_access.("slave_resp_handle") : { signal_item |
#define LIN_BYTE_OFFSET_$signal_item.("signal_name")$    $signal_item.("byte_offset")$
#define LIN_BIT_OFFSET_$signal_item.("signal_name")$    $signal_item.("bit_offset")$
#define LIN_SIGNAL_SIZE_$signal_item.("signal_name")$    $signal_item.("signal_size")$
}$
}$
/*
 * frame ctrl defines
 */ 
 
/*
 * the static signal access macros
 */
$list_signal_access: {signal_access |
$signal_access.("normal_frame_handle") : { signal_item |
/* static access macros for signal LIN_SIGNAL_$signal_item.("signal_name")$ */
$if(signal_item.("is_bool_signal"))$
#define l_bool_rd_LIN_SIGNAL_$signal_item.("signal_name")$() l_bool_rd_$signal_item.("signal_name")$()
#define l_bool_wr_LIN_SIGNAL_$signal_item.("signal_name")$(A) l_bool_wr_$signal_item.("signal_name")$(A)

#define l_bool_rd_$signal_item.("signal_name")$()  \\
   (LIN_TEST_BIT(l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$], \\
   LIN_BIT_OFFSET_$signal_item.("signal_name")$))
#define l_bool_wr_$signal_item.("signal_name")$(A) \\
  do {(A) ? \\
  (LIN_SET_BIT(l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$], \\
  LIN_BIT_OFFSET_$signal_item.("signal_name")$)):\\
  (LIN_CLEAR_BIT(l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$], \\
  LIN_BIT_OFFSET_$signal_item.("signal_name")$));\\
  l_flg_set_changed$signal_item.("signal_name")$();} while(0)

$endif$
$if(signal_item.("is_array_signal"))$
#define l_bytes_rd_LIN_SIGNAL_$signal_item.("signal_name")$(start, count, data) l_bytes_rd_$signal_item.("signal_name")$(start, count, data)
#define l_bytes_wr_LIN_SIGNAL_$signal_item.("signal_name")$(start, count, data) l_bytes_wr_$signal_item.("signal_name")$((start), (count), (data))

#define l_bytes_rd_$signal_item.("signal_name")$(start,count, data) \\
  do {l_u8       i; \\
    for (i = 0; i < (count); ++i)  (data)[i] = l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$ + i + (start)];} while(0)
#define l_bytes_wr_$signal_item.("signal_name")$(start,count, data) \\
  do {l_u8       i; \\
    for (i = 0; i < (count); ++i)l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$ + i + (start)]  = (data)[i]; \\
  l_flg_set_changed$signal_item.("signal_name")$();} while(0)

$endif$
$if(signal_item.("is_u16_signal"))$
#define $signal_item.("signal_type")$_rd_LIN_SIGNAL_$signal_item.("signal_name")$() $signal_item.("signal_type")$_rd_$signal_item.("signal_name")$()
#define $signal_item.("signal_type")$_wr_LIN_SIGNAL_$signal_item.("signal_name")$(A) $signal_item.("signal_type")$_wr_$signal_item.("signal_name")$(A)

#define $signal_item.("signal_type")$_rd_$signal_item.("signal_name")$()  \\
  ((l_u8) ((l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$ + 1] & $signal_item.("mask_value1")$) << $signal_item.("num_shifted_bit")$) + ((l_u8) (l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$]) >> $signal_item.("hex_bit_offset")$))

#define $signal_item.("signal_type")$_wr_$signal_item.("signal_name")$(A) \\
do {l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$ + 1] = \\
  ((l_u8) (((l_u8) (l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$ + 1] &  ($signal_item.("mask_value2")$))) | \\
   ((l_u8) ((l_u8) ((A) >> $signal_item.("num_shifted_bit")$)) & $signal_item.("mask_value1")$))); \\
  l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$] = \\
  ((l_u8) (((l_u8) (l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$] & ($signal_item.("mask_signal_offset")$))) | \\
  ((l_u8) (A) << LIN_BIT_OFFSET_$signal_item.("signal_name")$))); \\
   l_flg_set_changed$signal_item.("signal_name")$();} while(0)
$endif$
$if(signal_item.("is_u8_signal"))$
#define $signal_item.("signal_type")$_rd_LIN_SIGNAL_$signal_item.("signal_name")$() $signal_item.("signal_type")$_rd_$signal_item.("signal_name")$()
#define $signal_item.("signal_type")$_wr_LIN_SIGNAL_$signal_item.("signal_name")$(A) $signal_item.("signal_type")$_wr_$signal_item.("signal_name")$(A)

#define $signal_item.("signal_type")$_rd_$signal_item.("signal_name")$()  \\
  (($signal_item.("signal_type")$) ((l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$] & \\
   (((1U << LIN_SIGNAL_SIZE_$signal_item.("signal_name")$) - 1) \\
    << LIN_BIT_OFFSET_$signal_item.("signal_name")$ )) >> LIN_BIT_OFFSET_$signal_item.("signal_name")$))
#define $signal_item.("signal_type")$_wr_$signal_item.("signal_name")$(A) \\
  do {l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$] = \\
  (($signal_item.("signal_type")$) ((($signal_item.("signal_type")$) (l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$] & \\
   (($signal_item.("signal_type")$) (~(((1U << LIN_SIGNAL_SIZE_$signal_item.("signal_name")$) - 1) << LIN_BIT_OFFSET_$signal_item.("signal_name")$)))))  | \\
  (($signal_item.("signal_type")$) ((((1U << LIN_SIGNAL_SIZE_$signal_item.("signal_name")$) - 1) & (A)) << LIN_BIT_OFFSET_$signal_item.("signal_name")$))));\\
  l_flg_set_changed$signal_item.("signal_name")$();} while(0)

$endif$

}$
$signal_access.("master_req_handle") : { signal_item |
/* static access macros for signal LIN_SIGNAL_$signal_item.("signal_name")$ */
#define $signal_item.("signal_type")$_rd_LIN_SIGNAL_$signal_item.("signal_name")$() $signal_item.("signal_type")$_rd_$signal_item.("signal_name")$()
#define $signal_item.("signal_type")$_wr_LIN_SIGNAL_$signal_item.("signal_name")$(A) $signal_item.("signal_type")$_wr_$signal_item.("signal_name")$(A)

#define $signal_item.("signal_type")$_rd_$signal_item.("signal_name")$()  \\
  (($signal_item.("signal_type")$) ((l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$] & \\
   (((1U << LIN_SIGNAL_SIZE_$signal_item.("signal_name")$) - 1) \\
    << LIN_BIT_OFFSET_$signal_item.("signal_name")$ )) >> LIN_BIT_OFFSET_$signal_item.("signal_name")$))
#define $signal_item.("signal_type")$_wr_$signal_item.("signal_name")$(A) \\
  do {l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$] = \\
  (($signal_item.("signal_type")$) ((($signal_item.("signal_type")$) (l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$] & \\
   (($signal_item.("signal_type")$) (~(((1U << LIN_SIGNAL_SIZE_$signal_item.("signal_name")$) - 1) << LIN_BIT_OFFSET_$signal_item.("signal_name")$)))))  | \\
  (($signal_item.("signal_type")$) ((((1U << LIN_SIGNAL_SIZE_$signal_item.("signal_name")$) - 1) & (A)) << LIN_BIT_OFFSET_$signal_item.("signal_name")$))));\\
  l_flg_set_changed$signal_item.("signal_name")$();} while(0)

}$
$signal_access.("slave_resp_handle") : { signal_item |
/* static access macros for signal LIN_SIGNAL_$signal_item.("signal_name")$ */
#define $signal_item.("signal_type")$_rd_LIN_SIGNAL_$signal_item.("signal_name")$() $signal_item.("signal_type")$_rd_$signal_item.("signal_name")$()
#define $signal_item.("signal_type")$_wr_LIN_SIGNAL_$signal_item.("signal_name")$(A) $signal_item.("signal_type")$_wr_$signal_item.("signal_name")$(A)

#define $signal_item.("signal_type")$_rd_$signal_item.("signal_name")$()  \\
  (($signal_item.("signal_type")$) ((l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$] & \\
   (((1U << LIN_SIGNAL_SIZE_$signal_item.("signal_name")$) - 1) \\
    << LIN_BIT_OFFSET_$signal_item.("signal_name")$ )) >> LIN_BIT_OFFSET_$signal_item.("signal_name")$))
#define $signal_item.("signal_type")$_wr_$signal_item.("signal_name")$(A) \\
  do {l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$] = \\
  (($signal_item.("signal_type")$) ((($signal_item.("signal_type")$) (l_pFrameBuf[LIN_BYTE_OFFSET_$signal_item.("signal_name")$] & \\
   (($signal_item.("signal_type")$) (~(((1U << LIN_SIGNAL_SIZE_$signal_item.("signal_name")$) - 1) << LIN_BIT_OFFSET_$signal_item.("signal_name")$)))))  | \\
  (($signal_item.("signal_type")$) ((((1U << LIN_SIGNAL_SIZE_$signal_item.("signal_name")$) - 1) & (A)) << LIN_BIT_OFFSET_$signal_item.("signal_name")$))));\\
  l_flg_set_changed$signal_item.("signal_name")$();} while(0)

}$
}$
/*
 * static access macros for notification flags
 */
$list_signal_flag: { signal_flag |
/* flag access macros for signal $signal_flag.("signal_name")$*/
#define l_flg_tst_LIN_FLAG_Rx$signal_flag.("signal_name")$() l_flg_tst_Rx$signal_flag.("signal_name")$()
#define l_flg_clr_LIN_FLAG_Rx$signal_flag.("signal_name")$() l_flg_clr_Rx$signal_flag.("signal_name")$()
#define l_flg_tst_LIN_FLAG_Tx$signal_flag.("signal_name")$() l_flg_tst_Tx$signal_flag.("signal_name")$()
#define l_flg_clr_LIN_FLAG_Tx$signal_flag.("signal_name")$() l_flg_clr_Tx$signal_flag.("signal_name")$()
#define l_flg_tst_Rx$signal_flag.("signal_name")$() LIN_TEST_BIT(l_pRxFlagData[$signal_flag.("flag_index")$], $signal_flag.("flag_offset")$)
#define l_flg_clr_Rx$signal_flag.("signal_name")$() LIN_CLEAR_BIT(l_pRxFlagData[$signal_flag.("flag_index")$], $signal_flag.("flag_offset")$)
#define l_flg_set_Rx$signal_flag.("signal_name")$() LIN_SET_BIT(l_pRxFlagData[$signal_flag.("flag_index")$], $signal_flag.("flag_offset")$)
#define l_flg_tst_Tx$signal_flag.("signal_name")$() LIN_TEST_BIT(l_pTxFlagData[$signal_flag.("flag_index")$], $signal_flag.("flag_offset")$)
#define l_flg_clr_Tx$signal_flag.("signal_name")$() LIN_CLEAR_BIT(l_pTxFlagData[$signal_flag.("flag_index")$], $signal_flag.("flag_offset")$)
#define l_flg_set_Tx$signal_flag.("signal_name")$() LIN_SET_BIT(l_pTxFlagData[$signal_flag.("flag_index")$], $signal_flag.("flag_offset")$)

#define l_flg_tst_changed$signal_flag.("signal_name")$(ifc) LIN_TEST_CHANGED_FLAG_BIT($signal_flag.("changed_flag_index")$, $signal_flag.("changed_flag_offset")$)
#define l_flg_set_changed$signal_flag.("signal_name")$() LIN_SET_CHANGED_FLAG_BIT($signal_flag.("changed_flag_index")$, $signal_flag.("changed_flag_offset")$)
#define l_flg_clr_changed$signal_flag.("signal_name")$(ifc) LIN_CLEAR_CHANGED_FLAG_BIT($signal_flag.("changed_flag_index")$, $signal_flag.("changed_flag_offset")$)

$if(signal_flag.("is_publisher"))$
/* flag access macros for signal $signal_flag.("signal_name")$ published by $node_name$*/
#define l_flg_clr_$signal_flag.("signal_name")$() l_flg_clr_Tx$signal_flag.("signal_name")$()
#define l_flg_tst_$signal_flag.("signal_name")$() l_flg_tst_Tx$signal_flag.("signal_name")$()
$else$
/* flag access macros for signal $signal_flag.("signal_name")$ subscribed by $node_name$*/
#define l_flg_clr_$signal_flag.("signal_name")$() l_flg_clr_Rx$signal_flag.("signal_name")$()
#define l_flg_tst_$signal_flag.("signal_name")$() l_flg_tst_Rx$signal_flag.("signal_name")$()
$endif$

}$
$list_frame_flag: { frame_flag |
/* flag access macros for frame $frame_flag.("frame_name")$*/
#define l_flg_tst_LIN_FLAG_Rx$frame_flag.("frame_name")$() l_flg_tst_Rx$frame_flag.("frame_name")$()
#define l_flg_clr_LIN_FLAG_Rx$frame_flag.("frame_name")$() l_flg_clr_Rx$frame_flag.("frame_name")$()
#define l_flg_tst_LIN_FLAG_Tx$frame_flag.("frame_name")$() l_flg_tst_Tx$frame_flag.("frame_name")$()
#define l_flg_clr_LIN_FLAG_Tx$frame_flag.("frame_name")$() l_flg_clr_Tx$frame_flag.("frame_name")$()
#define l_flg_tst_Rx$frame_flag.("frame_name")$() LIN_TEST_BIT(l_pRxFlagData[$frame_flag.("flag_index")$], 0)
#define l_flg_clr_Rx$frame_flag.("frame_name")$() LIN_CLEAR_BIT(l_pRxFlagData[$frame_flag.("flag_index")$], 0)
#define l_flg_set_Rx$frame_flag.("frame_name")$() LIN_SET_BIT(l_pRxFlagData[$frame_flag.("flag_index")$], 0)
#define l_flg_tst_Tx$frame_flag.("frame_name")$() LIN_TEST_BIT(l_pTxFlagData[$frame_flag.("flag_index")$], 0)
#define l_flg_clr_Tx$frame_flag.("frame_name")$() LIN_CLEAR_BIT(l_pTxFlagData[$frame_flag.("flag_index")$], 0)
#define l_flg_set_Tx$frame_flag.("frame_name")$() LIN_SET_BIT(l_pTxFlagData[$frame_flag.("flag_index")$], 0)
}$

$if(is_master_node)$
$else$
/* macro for setting error signals */
#define l_setErrorSignal() l_bool_wr_$error_signal$(1)
$endif$


#endif /* LIN_CFG_H */
