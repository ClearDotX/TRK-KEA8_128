/****************************************************************************** 
* 
* Freescale Semiconductor Inc. 
* (c) Copyright $from_year$-$to_year$ Freescale Semiconductor, Inc. 
* ALL RIGHTS RESERVED. 
* 
***************************************************************************//*! 
* 
* @file      lin_cfg.c 
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
/** \file lin_cfg.c
 */

#define LIN_CFG_C

#define LIN_CFG_C_MAJOR_VERSION          0
#define LIN_CFG_C_MINOR_VERSION          9
#define LIN_CFG_C_PATCH_VERSION          2

#define LIN_CFG_C_STM

#include "lin_cfg_types.h"
#include "lin_types.h"
#include "lin_general.h"
#include "lin_cfg.h"
#include "lin_def.h"
#include "lin_diag.h"

$if(is_master_node)$
#include "lin_master.h"
#include "lin_diag_master.h"
$else$
#include "lin_slave.h"
#include "lin_diag_slave.h"
$endif$


$if(is_lin_version21)$
#include "lin.h"
$endif$


#include "lin_version_control.h"

$if(include_stack_frame)$
$list_static_stack_frame: {frame_item |
$if(frame_item.("is_compose_frame"))$
STACK static void l_composeFrame_$frame_item.("frame_name")$
(
  __OPTIONAL_IFC_DEFINITION__
);
$else$
STACK static void l_frameReceived_$frame_item.("frame_name")$
(
  __OPTIONAL_IFC_DEFINITION__
);
$endif$

}$
$endif$

/* cluster speed definition */
const l_u16      l_speed[] = {$list_lin_speed; separator = ", "$};

$if(is_master_node)$
$else$
/* initial NAD definition */
l_u8                l_initialNad = $initial_nad$;

	$if(exist_init_nad)$
/* configured NAD definition */
l_u8                l_configuredNad = $configured_nad$;
	$endif$

/* product ID definition */
l_productId_t     l_productId = {$product_id; separator = ", "$};

$if(is_lin_version21)$
	$if(exist_p2_min)$
/* P2_min definition */
l_u16                l_P2_min = $p2_min$;           /* $p2_min$ msec is the default value */
	$endif$
	$if(exist_st_min)$
/* ST_min definition */
l_u16                l_ST_min = $st_min$;            /* $st_min$ msec is the default value */
	$endif$
	$if(exist_nas_timeout)$
/* N_As_timeout definition */
l_u16                l_N_As_timeout = $n_as_timeout$;    /* $n_as_timeout$ msec is the default value */
	$endif$
	$if(exist_ncr_timeout)$
/* N_Cr_timeout definition */
l_u16                l_N_Cr_timeout = $n_cr_timeout$;    /* $n_cr_timeout$ msec is the default value */
	$endif$
$endif$
$endif$



/* definition and initialization of signal array */

LIN_ZERO_PAGE14 l_u8    l_pFrameBuf[LIN_FRAME_BUF_SIZE] =
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

$if(is_master_node)$
/* event triggered control array */
$if(include_evt_trig_ctrl_array)$
static l_u8                    l_lastMappedFrame[LIN_EVENT_TRIGGERED_COUNT] = 
{
  $evt_trig_ctrl_array; separator=",
"$
};
$endif$

$if(is_lin_version21)$
/* collision resolving schedule table array for LIN 2.1 */
/* 1 = collision resolving schedule table               */
/* 0 = not collision resolving schedule table           */
const l_u8                     l_IsCollisionTable[SCHEDULE_TABLE_COUNT] = 
{$first(lst_collision_reslv_init): { table_item |
  $table_item.mapItem.("init_value")$     /* $table_item.mapItem.("table_name")$ */}$
$rest(lst_collision_reslv_init): { table_item |
  ,$table_item.mapItem.("init_value")$   /* $table_item.mapItem.("table_name")$ */}$
};

/* LIN 2.1 table where:   */
/* l_LastMappedFrame[i] = index of laste mapped frame if i is a collision resolving schedule table */
/* l_LastMappedFrame[i] = 0xffff if i is not a collision resolving schedule table        */
const l_u16                    l_LastMappedFrame[SCHEDULE_TABLE_COUNT] = 
{
  $last_mapped_frame; separator=",
"$
};
$endif$
$else$
const l_u16 l_pMessageId[LIN_FRAME_COUNT] = 
{
  $list_message_id; separator=",
"$
};


LIN_ZERO_PAGE15 l_u8 l_pFrameId[LIN_FRAME_COUNT] = 
{
  $list_frame_id; separator=",
"$
};


l_filter_t l_pFrameInfo[(LIN_FRAME_COUNT - 2)] = 
{
$first(list_frame_info): { frame_info |
  {$frame_info.mapItem.("direction")$, $frame_info.mapItem.("checksum_type")$, $frame_info.mapItem.("frame_id")$, $frame_info.mapItem.("frame_size")$}}$
$rest(list_frame_info): { frame_info |
  ,{$frame_info.mapItem.("direction")$, $frame_info.mapItem.("checksum_type")$, $frame_info.mapItem.("frame_id")$, $frame_info.mapItem.("frame_size")$}
}$
}; 


$if(is_lin_version21)$
const l_u8 l_pConfigFrameOrder[LIN_FRAME_COUNT] = 
{
  $list_cfg_frame_order; separator=",
"$
};
$endif$
$endif$

$if(is_master_node)$
/********************************************************************
 *
 * l_sch_tick()
 */
/** \brief function to start transfer
 *
 * the application will call this function periodically (according
 * to LIN timebase). Eventually a frame transfer will be started)
 *
 * - standard API
 * - master only
 *
 * \param ifc      interface to act upon
 *
 * \return the index of the frame to be sent with the next call to
 *         l_sch_tick()
 *
 */
STACK l_u8 l_sch_tick
(
  l_ifc_handle                  ifc
) REENTRANT
{
  l_u8                          status = 0;
$if(is_lin_version21)$
  l_u8                          tempEntry = 0;
  l_schedule_handle             tempSchedule = L_NULL_SCHEDULE;
$endif$

  l_u8                          checksumModel = 0; /* enhanced */
  l_irqmask                     irqMask;

  __CHECK_INTERFACE_VALUE__(ifc, (l_u8) 0);

  irqMask = l_sys_irq_disable();

  if ((IFCCTRL_STATE(ifc) == LIN_STATE_BUSSLEEP)
    ||
    (IFCCTRL_SCHEDULE(ifc) == L_NULL_SCHEDULE)
    ||
    ((IFCCTRL_FLAGS(ifc) & LIN_IFC_CONNECT_FLAG) == 0))
  {
    if (IFCCTRL_DELAY(ifc) > 1)
    {
      --(IFCCTRL_DELAY(ifc));
    }
    l_sys_irq_restore(irqMask);
    return 0;
  }
  else
  {
    --(IFCCTRL_DELAY(ifc));

    if (IFCCTRL_DELAY(ifc) == 0)
    {
      TRANSFERCTRL_STATE(ifc) = LIN_TRANSFER_SEND;

      if (IFCCTRL_FLAGS(ifc) & LIN_IFC_EVENT_TRIGGERED_FLAG)
      {
        IFCCTRL_FLAGS(ifc) &= (l_u8) (~LIN_IFC_EVENT_TRIGGERED_FLAG);

        if ((IFCCTRL_STATE(ifc) == LIN_STATE_RECEIVE_DATA) &&
          (TRANSFERCTRL_BYTESSENT(ifc) > 1))
        {
$if(is_lin_version21)$

          IFCCTRL_FLAGS(ifc) |= LIN_IFC_COLLISION_FLAG;
        }/* collision in event triggered frame LIN 2.1 */

      }/* event triggered frame LIN 2.1 */

      if (IFCCTRL_FLAGS(ifc) & LIN_IFC_COLLISION_FLAG)
      {

        IFCCTRL_FLAGS(ifc) &= (l_u8) (~LIN_IFC_COLLISION_FLAG);
        l_serialError(__OPTIONAL_IFC_PARAMETER__);

        IFCCTRL_SCHEDULE_AFTER_COLLISION(ifc) = IFCCTRL_SCHEDULE(ifc);
        IFCCTRL_ENTRY_AFTER_COLLISION(ifc) = IFCCTRL_ENTRY(ifc);

        if (IFCCTRL_ENTRY(ifc) >= 1)
        {
          tempEntry = (l_u8) (IFCCTRL_ENTRY(ifc) - 1);
        }
        else
        {
          tempEntry = 0;
        }

        switch (IFCCTRL_SCHEDULE(ifc))
        {
$list_tab_with_evt_frame : { tab_item |
          case $tab_item.mapItem.("table_index")$u: /* schedule table $tab_item.mapItem.("table_name")$ with evt trig frames for LIN 2.1 */
          switch (tempEntry)
          {
$tab_item.lstItem : { evt_item |
            case $evt_item.("frame_index")$u: /* evt trig frame $evt_item.("frame_name")$ */
            tempSchedule = LIN_TAB_$evt_item.("collision_tab_name")$;
            break;
}$
            default:
              /* nothing to be done */
              break;

          } /* end switch (tempEntry) */
}$
        } /* end switch (IFCCTRL_SCHEDULE(ifc)) for LIN 2.1*/

        l_sch_set(ifc,tempSchedule,0);

      } /* collision in event triggered frame LIN 2.1 */
$else$
          l_serialError(__OPTIONAL_IFC_PARAMETER__);
        } /* collision in event triggered frame LIN 2.0 */

      } /* event triggered frame LIN 2.0*/
$endif$      
      switch (IFCCTRL_SCHEDULE(ifc))
      {
$list_schedule_table_handle : { table_item |  
$first(table_item) : { slot_item |  
        case $slot_item.mapItem.("table_index")$u: /* schedule table $slot_item.mapItem.("table_name")$ */
          switch (IFCCTRL_ENTRY(ifc))
          $left_bracket$
$if(slot_item.mapItem.("is_assign_nad_req"))$
            case 0u: /* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("tfctrl_buf1")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = 6;
              TRANSFERCTRL_BUFFER(ifc)[3] = 176;
              TRANSFERCTRL_BUFFER(ifc)[4] = $slot_item.mapItem.("tfctrl_buf4")$;
              TRANSFERCTRL_BUFFER(ifc)[5] = $slot_item.mapItem.("tfctrl_buf5")$;
              TRANSFERCTRL_BUFFER(ifc)[6] = $slot_item.mapItem.("tfctrl_buf6")$;
              TRANSFERCTRL_BUFFER(ifc)[7] = $slot_item.mapItem.("tfctrl_buf7")$;
              TRANSFERCTRL_BUFFER(ifc)[8] = $slot_item.mapItem.("tfctrl_buf8")$;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_save_config_req"))$
            case 0u: /* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("configured_nad")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = 1;
              TRANSFERCTRL_BUFFER(ifc)[3] = 182;
              TRANSFERCTRL_BUFFER(ifc)[4] = 255;
              TRANSFERCTRL_BUFFER(ifc)[5] = 255;
              TRANSFERCTRL_BUFFER(ifc)[6] = 255;
              TRANSFERCTRL_BUFFER(ifc)[7] = 255;
              TRANSFERCTRL_BUFFER(ifc)[8] = 255;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_unconditional_frame"))$
            case 0u: /* uncon frame $slot_item.mapItem.("frame_name")$*/

$if(slot_item.mapItem.("is_collision_table"))$
              l_ifcSetStatus(__OPTIONAL_IFC_PARAMETER_COMMA__
              LIN_STATUS_EVENT_TRIGGERED_FRAME_COLLISION,
              TRANSFERCTRL_BUFFER(ifc)[0]);


$endif$
              TRANSFERCTRL_BUFFER(ifc)[0] = $slot_item.mapItem.("tfctrl_buf0")$;
              TRANSFERCTRL_BYTESTOSEND(ifc) = $slot_item.mapItem.("tfctrl_bytetosend")$;
$if(slot_item.mapItem.("is_publisher"))$
              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
$slot_item.mapItem.("list_tfctrl_buffer"): { buffer_item |
              TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$] = l_pFrameBuf[$buffer_item.("buffer_value")$];}$              
$else$
              TRANSFERCTRL_STATE(ifc) = LIN_TRANSFER_RECEIVE;
              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
$endif$

              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_assign_frame_id_range_req"))$
            case 0u: /* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("configured_nad")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = 6;
              TRANSFERCTRL_BUFFER(ifc)[3] = 183;
              TRANSFERCTRL_BUFFER(ifc)[4] = $slot_item.mapItem.("tfctrl_buf4")$;
              TRANSFERCTRL_BUFFER(ifc)[5] = $slot_item.mapItem.("tfctrl_buf5")$;
              TRANSFERCTRL_BUFFER(ifc)[6] = $slot_item.mapItem.("tfctrl_buf6")$;
              TRANSFERCTRL_BUFFER(ifc)[7] = $slot_item.mapItem.("tfctrl_buf7")$;
              TRANSFERCTRL_BUFFER(ifc)[8] = $slot_item.mapItem.("tfctrl_buf8")$;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_sporadic_frame"))$
            case 0u:	/* sporadic frame $slot_item.mapItem.("frame_name")$ */
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;

              TRANSFERCTRL_STATE(ifc) = 0;
$slot_item.mapItem.("list_tfctrl_buffer") : { buffer_item |
              if (LIN_TEST_CHANGED_FLAG_BYTE($buffer_item.("test_changed_flag_byte")$))
              {
                TRANSFERCTRL_STATE(ifc) = LIN_TRANSFER_SEND;
                TRANSFERCTRL_BYTESTOSEND(ifc) = $buffer_item.("tfctrl_bytetosend")$;
                TRANSFERCTRL_BUFFER(ifc)[0] = $buffer_item.("tfctrl_buf0")$;
                l_composeFrame_$buffer_item.("frame_name")$(__OPTIONAL_IFC_PARAMETER__);
                TRANSFERCTRL_FRAME(ifc) = $buffer_item.("tfctrl_frame")$;
                break;
              } /* if (frame has changed) */
}$
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_evt_trig_frame"))$
            case 0u: /* event triggered frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = $slot_item.mapItem.("tfctrl_bytetosend")$;
              TRANSFERCTRL_STATE(ifc) = LIN_TRANSFER_RECEIVE;
              switch (l_lastMappedFrame[$slot_item.mapItem.("last_mapped_frame_index")$])
              {
$slot_item.mapItem.("list_tfctrl_buffer") : { buffer_item |
                case $buffer_item.("frame_index")$u: /* frame $buffer_item.("frame_name")$ */
                  TRANSFERCTRL_BUFFER(ifc)[0] = $buffer_item.("tfctrl_buf0")$;
                  l_lastMappedFrame[$slot_item.mapItem.("last_mapped_frame_index")$] = $buffer_item.("last_mapped_frame")$;
                  TRANSFERCTRL_FRAME(ifc) = $buffer_item.("tfctrl_frame")$;
                  break;
}$
                case LIN_INVALID_MAPPED_FRAME:
                default:
                  TRANSFERCTRL_BUFFER(ifc)[0] = $slot_item.mapItem.("tfctrl_buf0")$;
                  TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
                  IFCCTRL_FLAGS(ifc) |= LIN_IFC_EVENT_TRIGGERED_FLAG;
                  break;

              } /* switch (last mapped frame) */

              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_master_req"))$
            case 0u:	/* uncon frame $slot_item.mapItem.("frame_name")$ */
#ifdef LIN_INCLUDE_DIAGNOSTICS
              if (LIN_TEST_CHANGED_FLAG_BYTE($slot_item.mapItem.("test_changed_flag_byte")$))
              {
                /* do nothing */
              }
              else if ((LIN_DIAG_FLAGS(ifc) & LIN_DIAG_TX_READY_MASK) != 0)
              {
                ld_composeMasterRequest(__OPTIONAL_IFC_PARAMETER_COMMA__
                  &(l_pFrameBuf[$slot_item.mapItem.("buffer_index")$]));
              }
              else
              {
                /* nothing to send */
                TRANSFERCTRL_STATE(ifc) = 0;
              }

              if (TRANSFERCTRL_STATE(ifc) != 0)
              {
                IFCCTRL_DIAGFLAGS(ifc) |= (l_u8) LIN_DIAG_TX_FLAG;
                TRANSFERCTRL_BUFFER(ifc)[0] = 60;
$slot_item.mapItem.("list_tfctrl_buffer"): { buffer_item |
                TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$] = l_pFrameBuf[$buffer_item.("buffer_value")$];}$
                checksumModel = 1; /* classic */
                TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
                TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              }
#else
              if (LIN_TEST_CHANGED_FLAG_BYTE($slot_item.mapItem.("test_changed_flag_byte")$))
              {
                TRANSFERCTRL_BUFFER(ifc)[0] = 60;
$slot_item.mapItem.("list_tfctrl_buffer"): { buffer_item |
                TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$] = l_pFrameBuf[$buffer_item.("buffer_value")$];}$
                checksumModel = 1; /* classic */
                TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
                TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              }
              else
              {
                TRANSFERCTRL_STATE(ifc) = 0;
              }
#endif

              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_slave_resp"))$
            case 0u: /* uncon frame $slot_item.mapItem.("frame_name")$*/
              TRANSFERCTRL_BUFFER(ifc)[0] = 125;
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_STATE(ifc) = LIN_TRANSFER_RECEIVE;
              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$if(is_lin_version21)$
$else$
              checksumModel = 1; /* classic *//* added ??? to avoid checksum error ! */
$endif$
$endif$
$if(slot_item.mapItem.("is_conditional_change_nad_req"))$
            case 0u:	/* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("tfctrl_buf1")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = 6;
              TRANSFERCTRL_BUFFER(ifc)[3] = 179;
              TRANSFERCTRL_BUFFER(ifc)[4] = $slot_item.mapItem.("tfctrl_buf4")$;
              TRANSFERCTRL_BUFFER(ifc)[5] = $slot_item.mapItem.("tfctrl_buf5")$;
              TRANSFERCTRL_BUFFER(ifc)[6] = $slot_item.mapItem.("tfctrl_buf6")$;
              TRANSFERCTRL_BUFFER(ifc)[7] = $slot_item.mapItem.("tfctrl_buf7")$;
              TRANSFERCTRL_BUFFER(ifc)[8] = $slot_item.mapItem.("tfctrl_buf8")$;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_data_dump_req"))$
            case 0u:	/* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("tfctrl_buf1")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = 6;
              TRANSFERCTRL_BUFFER(ifc)[3] = 180;
              TRANSFERCTRL_BUFFER(ifc)[4] = $slot_item.mapItem.("tfctrl_buf4")$;
              TRANSFERCTRL_BUFFER(ifc)[5] = $slot_item.mapItem.("tfctrl_buf5")$;
              TRANSFERCTRL_BUFFER(ifc)[6] = $slot_item.mapItem.("tfctrl_buf6")$;
              TRANSFERCTRL_BUFFER(ifc)[7] = $slot_item.mapItem.("tfctrl_buf7")$;
              TRANSFERCTRL_BUFFER(ifc)[8] = $slot_item.mapItem.("tfctrl_buf8")$;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_free_format_req"))$
            case 0u:	/* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("tfctrl_buf1")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = $slot_item.mapItem.("tfctrl_buf2")$;
              TRANSFERCTRL_BUFFER(ifc)[3] = $slot_item.mapItem.("tfctrl_buf3")$;
              TRANSFERCTRL_BUFFER(ifc)[4] = $slot_item.mapItem.("tfctrl_buf4")$;
              TRANSFERCTRL_BUFFER(ifc)[5] = $slot_item.mapItem.("tfctrl_buf5")$;
              TRANSFERCTRL_BUFFER(ifc)[6] = $slot_item.mapItem.("tfctrl_buf6")$;
              TRANSFERCTRL_BUFFER(ifc)[7] = $slot_item.mapItem.("tfctrl_buf7")$;
              TRANSFERCTRL_BUFFER(ifc)[8] = $slot_item.mapItem.("tfctrl_buf8")$;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_assign_frame_id_req"))$
            case 0u:	/* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("tfctrl_buf1")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = 6;
              TRANSFERCTRL_BUFFER(ifc)[3] = 177;
              TRANSFERCTRL_BUFFER(ifc)[4] = $slot_item.mapItem.("tfctrl_buf4")$;
              TRANSFERCTRL_BUFFER(ifc)[5] = $slot_item.mapItem.("tfctrl_buf5")$;
              TRANSFERCTRL_BUFFER(ifc)[6] = $slot_item.mapItem.("tfctrl_buf6")$;
              TRANSFERCTRL_BUFFER(ifc)[7] = $slot_item.mapItem.("tfctrl_buf7")$;
              TRANSFERCTRL_BUFFER(ifc)[8] = $slot_item.mapItem.("tfctrl_buf8")$;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$


              break;
}$
$rest(table_item) : { slot_item |
$if(slot_item.mapItem.("is_assign_nad_req"))$
          case $slot_item.mapItem.("slot_index")$u: /* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("tfctrl_buf1")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = 6;
              TRANSFERCTRL_BUFFER(ifc)[3] = 176;
              TRANSFERCTRL_BUFFER(ifc)[4] = $slot_item.mapItem.("tfctrl_buf4")$;
              TRANSFERCTRL_BUFFER(ifc)[5] = $slot_item.mapItem.("tfctrl_buf5")$;
              TRANSFERCTRL_BUFFER(ifc)[6] = $slot_item.mapItem.("tfctrl_buf6")$;
              TRANSFERCTRL_BUFFER(ifc)[7] = $slot_item.mapItem.("tfctrl_buf7")$;
              TRANSFERCTRL_BUFFER(ifc)[8] = $slot_item.mapItem.("tfctrl_buf8")$;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_save_config_req"))$
            case $slot_item.mapItem.("slot_index")$u: /* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("configured_nad")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = 1;
              TRANSFERCTRL_BUFFER(ifc)[3] = 182;
              TRANSFERCTRL_BUFFER(ifc)[4] = 255;
              TRANSFERCTRL_BUFFER(ifc)[5] = 255;
              TRANSFERCTRL_BUFFER(ifc)[6] = 255;
              TRANSFERCTRL_BUFFER(ifc)[7] = 255;
              TRANSFERCTRL_BUFFER(ifc)[8] = 255;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_unconditional_frame"))$
            case $slot_item.mapItem.("slot_index")$u: /* uncon frame $slot_item.mapItem.("frame_name")$*/
              TRANSFERCTRL_BUFFER(ifc)[0] = $slot_item.mapItem.("tfctrl_buf0")$;
              TRANSFERCTRL_BYTESTOSEND(ifc) = $slot_item.mapItem.("tfctrl_bytetosend")$;
$if(slot_item.mapItem.("is_publisher"))$
              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
$slot_item.mapItem.("list_tfctrl_buffer"): { buffer_item |
              TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$] = l_pFrameBuf[$buffer_item.("buffer_value")$];}$              
$else$
              TRANSFERCTRL_STATE(ifc) = LIN_TRANSFER_RECEIVE;
              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
$endif$

              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_assign_frame_id_range_req"))$
            case $slot_item.mapItem.("slot_index")$u: /* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("configured_nad")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = 6;
              TRANSFERCTRL_BUFFER(ifc)[3] = 183;
              TRANSFERCTRL_BUFFER(ifc)[4] = $slot_item.mapItem.("tfctrl_buf4")$;
              TRANSFERCTRL_BUFFER(ifc)[5] = $slot_item.mapItem.("tfctrl_buf5")$;
              TRANSFERCTRL_BUFFER(ifc)[6] = $slot_item.mapItem.("tfctrl_buf6")$;
              TRANSFERCTRL_BUFFER(ifc)[7] = $slot_item.mapItem.("tfctrl_buf7")$;
              TRANSFERCTRL_BUFFER(ifc)[8] = $slot_item.mapItem.("tfctrl_buf8")$;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_sporadic_frame"))$
            case $slot_item.mapItem.("slot_index")$u:	/* sporadic frame $slot_item.mapItem.("frame_name")$ */
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;

              TRANSFERCTRL_STATE(ifc) = 0;
$slot_item.mapItem.("list_tfctrl_buffer") : { buffer_item |
              if (LIN_TEST_CHANGED_FLAG_BYTE($buffer_item.("test_changed_flag_byte")$))
              {
                TRANSFERCTRL_STATE(ifc) = LIN_TRANSFER_SEND;
                TRANSFERCTRL_BYTESTOSEND(ifc) = $buffer_item.("tfctrl_bytetosend")$;
                TRANSFERCTRL_BUFFER(ifc)[0] = $buffer_item.("tfctrl_buf0")$;
                l_composeFrame_$buffer_item.("frame_name")$(__OPTIONAL_IFC_PARAMETER__);
                TRANSFERCTRL_FRAME(ifc) = $buffer_item.("tfctrl_frame")$;
                break;
              } /* if (frame has changed) */
}$
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_evt_trig_frame"))$
            case $slot_item.mapItem.("slot_index")$u: /* event triggered frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = $slot_item.mapItem.("tfctrl_bytetosend")$;
              TRANSFERCTRL_STATE(ifc) = LIN_TRANSFER_RECEIVE;
              switch (l_lastMappedFrame[$slot_item.mapItem.("last_mapped_frame_index")$])
              {
$slot_item.mapItem.("list_tfctrl_buffer") : { buffer_item |
                case $buffer_item.("frame_index")$u: /* frame $buffer_item.("frame_name")$ */
                  TRANSFERCTRL_BUFFER(ifc)[0] = $buffer_item.("tfctrl_buf0")$;
                  l_lastMappedFrame[$slot_item.mapItem.("last_mapped_frame_index")$] = $buffer_item.("last_mapped_frame")$;
                  TRANSFERCTRL_FRAME(ifc) = $buffer_item.("tfctrl_frame")$;
                  break;
}$
                case LIN_INVALID_MAPPED_FRAME:
                default:
                  TRANSFERCTRL_BUFFER(ifc)[0] = $slot_item.mapItem.("tfctrl_buf0")$;
                  TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
                  IFCCTRL_FLAGS(ifc) |= LIN_IFC_EVENT_TRIGGERED_FLAG;
                  break;

              } /* switch (last mapped frame) */

              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_master_req"))$
            case $slot_item.mapItem.("slot_index")$u:	/* uncon frame $slot_item.mapItem.("frame_name")$ */
#ifdef LIN_INCLUDE_DIAGNOSTICS
              if (LIN_TEST_CHANGED_FLAG_BYTE($slot_item.mapItem.("test_changed_flag_byte")$))
              {
                /* do nothing */
              }
              else if ((LIN_DIAG_FLAGS(ifc) & LIN_DIAG_TX_READY_MASK) != 0)
              {
                ld_composeMasterRequest(__OPTIONAL_IFC_PARAMETER_COMMA__
                  &(l_pFrameBuf[$slot_item.mapItem.("buffer_index")$]));
              }
              else
              {
                /* nothing to send */
                TRANSFERCTRL_STATE(ifc) = 0;
              }

              if (TRANSFERCTRL_STATE(ifc) != 0)
              {
                IFCCTRL_DIAGFLAGS(ifc) |= (l_u8) LIN_DIAG_TX_FLAG;
                TRANSFERCTRL_BUFFER(ifc)[0] = 60;
$slot_item.mapItem.("list_tfctrl_buffer"): { buffer_item |
                TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$] = l_pFrameBuf[$buffer_item.("buffer_value")$];}$
                checksumModel = 1; /* classic */
                TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
                TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              }
#else
              if (LIN_TEST_CHANGED_FLAG_BYTE($slot_item.mapItem.("test_changed_flag_byte")$))
              {
                TRANSFERCTRL_BUFFER(ifc)[0] = 60;
$slot_item.mapItem.("list_tfctrl_buffer"): { buffer_item |
                TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$] = l_pFrameBuf[$buffer_item.("buffer_value")$];}$
                checksumModel = 1; /* classic */
                TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
                TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              }
              else
              {
                TRANSFERCTRL_STATE(ifc) = 0;
              }
#endif

              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_slave_resp"))$
            case $slot_item.mapItem.("slot_index")$u: /* uncon frame $slot_item.mapItem.("frame_name")$*/
              TRANSFERCTRL_BUFFER(ifc)[0] = 125;
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_STATE(ifc) = LIN_TRANSFER_RECEIVE;
              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$if(is_lin_version21)$
$else$
              checksumModel = 1; /* classic *//* added ??? to avoid checksum error ! */
$endif$
$endif$
$if(slot_item.mapItem.("is_conditional_change_nad_req"))$
            case $slot_item.mapItem.("slot_index")$u:	/* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("tfctrl_buf1")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = 6;
              TRANSFERCTRL_BUFFER(ifc)[3] = 179;
              TRANSFERCTRL_BUFFER(ifc)[4] = $slot_item.mapItem.("tfctrl_buf4")$;
              TRANSFERCTRL_BUFFER(ifc)[5] = $slot_item.mapItem.("tfctrl_buf5")$;
              TRANSFERCTRL_BUFFER(ifc)[6] = $slot_item.mapItem.("tfctrl_buf6")$;
              TRANSFERCTRL_BUFFER(ifc)[7] = $slot_item.mapItem.("tfctrl_buf7")$;
              TRANSFERCTRL_BUFFER(ifc)[8] = $slot_item.mapItem.("tfctrl_buf8")$;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_data_dump_req"))$
            case $slot_item.mapItem.("slot_index")$u:	/* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("tfctrl_buf1")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = 6;
              TRANSFERCTRL_BUFFER(ifc)[3] = 180;
              TRANSFERCTRL_BUFFER(ifc)[4] = $slot_item.mapItem.("tfctrl_buf4")$;
              TRANSFERCTRL_BUFFER(ifc)[5] = $slot_item.mapItem.("tfctrl_buf5")$;
              TRANSFERCTRL_BUFFER(ifc)[6] = $slot_item.mapItem.("tfctrl_buf6")$;
              TRANSFERCTRL_BUFFER(ifc)[7] = $slot_item.mapItem.("tfctrl_buf7")$;
              TRANSFERCTRL_BUFFER(ifc)[8] = $slot_item.mapItem.("tfctrl_buf8")$;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_free_format_req"))$
            case $slot_item.mapItem.("slot_index")$u:	/* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("tfctrl_buf1")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = $slot_item.mapItem.("tfctrl_buf2")$;
              TRANSFERCTRL_BUFFER(ifc)[3] = $slot_item.mapItem.("tfctrl_buf3")$;
              TRANSFERCTRL_BUFFER(ifc)[4] = $slot_item.mapItem.("tfctrl_buf4")$;
              TRANSFERCTRL_BUFFER(ifc)[5] = $slot_item.mapItem.("tfctrl_buf5")$;
              TRANSFERCTRL_BUFFER(ifc)[6] = $slot_item.mapItem.("tfctrl_buf6")$;
              TRANSFERCTRL_BUFFER(ifc)[7] = $slot_item.mapItem.("tfctrl_buf7")$;
              TRANSFERCTRL_BUFFER(ifc)[8] = $slot_item.mapItem.("tfctrl_buf8")$;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$
$if(slot_item.mapItem.("is_assign_frame_id_req"))$
            case $slot_item.mapItem.("slot_index")$u:	/* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = $slot_item.mapItem.("tfctrl_buf1")$;
              TRANSFERCTRL_BUFFER(ifc)[2] = 6;
              TRANSFERCTRL_BUFFER(ifc)[3] = 177;
              TRANSFERCTRL_BUFFER(ifc)[4] = $slot_item.mapItem.("tfctrl_buf4")$;
              TRANSFERCTRL_BUFFER(ifc)[5] = $slot_item.mapItem.("tfctrl_buf5")$;
              TRANSFERCTRL_BUFFER(ifc)[6] = $slot_item.mapItem.("tfctrl_buf6")$;
              TRANSFERCTRL_BUFFER(ifc)[7] = $slot_item.mapItem.("tfctrl_buf7")$;
              TRANSFERCTRL_BUFFER(ifc)[8] = $slot_item.mapItem.("tfctrl_buf8")$;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = LIN_DIAG2_EXPECT_RESPONSE;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $slot_item.mapItem.("tfctrl_frame")$;
              IFCCTRL_ENTRY(ifc) = $slot_item.mapItem.("ifcctrl_entry")$;
              IFCCTRL_DELAY(ifc) = $slot_item.mapItem.("ifcctrl_delay")$;
$endif$


              break;
}$
            default:
              /* should never happen */
              break;
          $right_bracket$
          
          break;
        
}$
        case $goto_sleep_tab_index$u: /* schedule table GOTO_SLEEP */
          switch (IFCCTRL_ENTRY(ifc))
          {
            case 0u: /* configuration frame $slot_item.mapItem.("frame_name")$ */
              TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
              TRANSFERCTRL_BUFFER(ifc)[0] = 60;
              TRANSFERCTRL_BUFFER(ifc)[1] = 0;
              TRANSFERCTRL_BUFFER(ifc)[2] = 0xFF;
              IFCCTRL_SCHEDULE(ifc) = IFCCTRL_GOTOSLEEPSCHEDULE(ifc);
              IFCCTRL_ENTRY(ifc) = IFCCTRL_GOTOSLEEPENTRY(ifc);
              IFCCTRL_DELAY(ifc) = 0xff;
#ifdef LIN_INCLUDE_DIAGNOSTICS
              LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#ifdef LIN_INCLUDE_DIAG2
              LIN_DIAG_FLAGS(ifc) |= LIN_ORIGINATOR_DIAG2_TX;
              LIN_DIAG2_FLAGS(ifc) = 0;
#endif /* LIN_INCLUDE_DIAG2 */
#endif /* LIN_INCLUDE_DIAGNOSTICS */
              checksumModel = 1; /* classic */

              TRANSFERCTRL_FRAME(ifc) = $goto_sleep_tab_tfctrl_frame$;
              break;

            default:
              /* should never happen */
              break;

          }
          break;
          
        default:
          /* this shoud never happen, still we try to set things straight */
          TRANSFERCTRL_STATE(ifc) = 0;
          IFCCTRL_ENTRY(ifc) = 0;
          IFCCTRL_DELAY(ifc) = 1;
          break;

      } /* switch (schedule) */

      /*
       * now start transfer
       */
      if (TRANSFERCTRL_STATE(ifc) != 0)
      {

#ifdef LIN_DEBUG 

        l_dbgMasterSendBuffer(TRANSFERCTRL_BUFFER(ifc), TRANSFERCTRL_BYTESTOSEND(ifc));

#endif /* LIN_DEBUG */

        l_TimerStart(__OPTIONAL_TIMER_IFC_PARAMETER_COMMA__
          (l_u8) LIN_FRAME_SUBCHANNEL,
          LIN_FRAME_TIMER_VALUE(ifc));

        IFCCTRL_STATE(ifc) = LIN_STATE_SEND_IDENTIFIER;
        TRANSFERCTRL_BUFFER(ifc)[TRANSFERCTRL_BYTESTOSEND(ifc) - 1] =
          ((l_u8) (checksumModel ? 0 : TRANSFERCTRL_BUFFER(ifc)[0]));
        l_sendBreak(__OPTIONAL_IFC_PARAMETER__);
      } /* if (send || receive) */
    } /* if (frame to send) */

    if (IFCCTRL_DELAY(ifc) == 1)
    {
      status = (l_u8) (IFCCTRL_ENTRY(ifc) + 1);
    } 

  } /* if (!bussleep) */

  l_sys_irq_restore(irqMask);

  return status;

} /* end l_sch_tick() */
$else$
/********************************************************************
 *
 * l_stateReceiveIdentifier()
 */
/** \brief state machine function
 *
 * This function handles incoming characters in state
 * RECEIVE_IDENTIFIER
 *
 * - internal function
 * - slave only
 *
 * \param ifc      interface to act upon
 * \param rxChar   the character just received
 *
 * \retval none
 *
 */
STACK void l_stateReceiveIdentifier
(
  __OPTIONAL_IFC_DEFINITION_COMMA__
  l_u8                          rxChar
)
{
  l_u8                  checksumModel = 0; /* enhanced */
  l_u8                  flag = 0; 
  l_u8                  FlagErrorReset = 0; 
  TRANSFERCTRL_BUFFER(ifc)[0] = rxChar;
  TRANSFERCTRL_BYTESSENT(ifc) = 1;
  IFCCTRL_STATE(ifc) = LIN_STATE_RECEIVE_DATA;
  switch (LINFLEX_FILTERS_MATCH_INDEX_READ())
  {
$list_para_rev_id_func : { para_item |
$if(para_item.("is_evt_trig_frame"))$
    case $para_item.("frame_index")$u:   /* event triggered frame $para_item.("frame_name")$ */
$else$
    case $para_item.("frame_index")$u:   /* frame $para_item.("frame_name")$ */
$endif$
$if(para_item.("is_normal_frame"))$
$if(para_item.("is_publisher"))$
$para_item.("list_tfctrl_buffer") : { buffer_item |
      TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$] = l_pFrameBuf[$buffer_item.("buffer_value")$];}$
      TRANSFERCTRL_BYTESTOSEND(ifc) = $para_item.("tfctrl_bytetosend")$;
$if(para_item.("contain_error_signal"))$
      /* Set flag to remember to clear error signal for node */
      FlagErrorReset = 1;
$endif$
$else$

      TRANSFERCTRL_BYTESTOSEND(ifc) = $para_item.("tfctrl_bytetosend")$;
      l_receiveResponse(__OPTIONAL_IFC_PARAMETER__);
      flag = 1; 
      
$endif$
$endif$
$if(para_item.("is_compose_frame"))$

      l_composeFrame_$para_item.("frame_name")$(__OPTIONAL_IFC_PARAMETER__);
      if (LIN_TEST_CHANGED_FLAG_BYTE($para_item.("test_changed_flag_byte")$)
        )
      {
        LIN_CLEAR_CHANGED_FLAG_BYTE($para_item.("test_changed_flag_byte")$);
      }
      TRANSFERCTRL_BYTESTOSEND(ifc) = $para_item.("tfctrl_bytetosend")$;
$endif$
$if(para_item.("is_evt_trig_frame"))$

      TRANSFERCTRL_BYTESTOSEND(ifc) = $para_item.("tfctrl_bytetosend")$;
      /* one frame is sent by the node
       * first we check whether that frame has changed
       */
      if (LIN_TEST_CHANGED_FLAG_BYTE($para_item.("test_changed_flag_byte")$)
        )
      {
        l_composeFrame_$para_item.("ass_frame_name")$(__OPTIONAL_IFC_PARAMETER__);
        TRANSFERCTRL_BUFFER(ifc)[1] =
          l_pFrameId[$para_item.("ass_frame_index")$];
        TRANSFERCTRL_FRAME(ifc) = $para_item.("ass_frame_index")$;
        LIN_CLEAR_CHANGED_FLAG_BYTE($para_item.("test_changed_flag_byte")$);
        break;

      }
      l_terminateTransfer(__OPTIONAL_IFC_PARAMETER__);
      flag = 1; 
$endif$
$if(para_item.("is_diagnostic_frame"))$

$if(para_item.("is_publisher"))$
#ifdef LIN_INCLUDE_DIAGNOSTICS
      if ((LIN_DIAG_FLAGS(ifc) & (l_u8) LIN_DIAG_ORIGINATOR_MASK) != 0)
      {
        ld_signalTxFrameError(__OPTIONAL_IFC_PARAMETER__);
      }
      LIN_DIAG_FLAGS(ifc) &= (l_u8) ~LIN_DIAG_ORIGINATOR_MASK;
#endif /* LIN_INCLUDE_DIAGNOSTICS */

      if (LIN_TEST_CHANGED_FLAG_BYTE($para_item.("test_changed_flag_byte")$))
      {
        /* do nothing */
      }
#ifdef LIN_INCLUDE_DIAGNOSTICS
      else if ((LIN_DIAG_FLAGS(ifc) & LIN_DIAG_TX_READY_MASK) != 0)
      {
        (void) ld_composeSlaveResponse(__OPTIONAL_IFC_PARAMETER_COMMA__
          &(l_pFrameBuf[$para_item.("buffer_index")$]));
      }

#endif /* LIN_INCLUDE_DIAGNOSTICS */
      else
      {
        l_terminateTransfer(__OPTIONAL_IFC_PARAMETER__);
        flag = 1; 
      }
      if (!flag)
      {
$para_item.("list_tfctrl_buffer") : { buffer_item |
        TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$] = l_pFrameBuf[$buffer_item.("buffer_value")$];}$
        checksumModel = 1; /* classic */
        TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
        TRANSFERCTRL_BUFFER(ifc)[TRANSFERCTRL_BYTESTOSEND(ifc) - 1] = 
          ((l_u8) (checksumModel ? 0 : TRANSFERCTRL_BUFFER(ifc)[0]));

        l_sendResponse(__OPTIONAL_IFC_PARAMETER__);
      }
$else$
      TRANSFERCTRL_BYTESTOSEND(ifc) = 10;
      checksumModel = 1; /* classic *//* added to avoid checksum error ! */
      TRANSFERCTRL_BUFFER(ifc)[TRANSFERCTRL_BYTESTOSEND(ifc) - 1] = 
        ((l_u8) (checksumModel ? 0 : TRANSFERCTRL_BUFFER(ifc)[0]));/* added to avoid checksum error ! */

      l_receiveResponse(__OPTIONAL_IFC_PARAMETER__);
      flag = 1; 
$endif$
$endif$

      break;
}$
    case (l_u16) LIN_INVALID_FRAME_INDEX:
    default:
      l_discardResponse(__OPTIONAL_IFC_PARAMETER__);
      l_terminateTransfer(__OPTIONAL_IFC_PARAMETER__);
      flag = 1; 
      break;
    
  }

  /* getting means that we are about to send a frame */
  if (!flag)
  {

#ifdef LIN_DEBUG
    /* allow application to modify send buffer */
    l_dbgSlaveSendBuffer(TRANSFERCTRL_BUFFER(ifc),TRANSFERCTRL_BYTESTOSEND(ifc));

#endif /* LIN_DEBUG */

    IFCCTRL_STATE(ifc) = LIN_STATE_SEND_DATA;
    TRANSFERCTRL_BYTESSENT(ifc)++;
    l_sendResponse(__OPTIONAL_IFC_PARAMETER__);
    TRANSFERCTRL_BUFFER(ifc)[TRANSFERCTRL_BYTESTOSEND(ifc) - 1] = 
      ((l_u8) (checksumModel ? 0 : TRANSFERCTRL_BUFFER(ifc)[0]));

    /* Clear error signal for node if FlagErrorReset is set */
    if (FlagErrorReset)
    {
      l_bool_wr_$error_signal_name$(0);
      FlagErrorReset = 0;
    }

#ifdef LIN_DEBUG
    /* allow application to modify send buffer */
    l_dbgSlaveSendBuffer(TRANSFERCTRL_BUFFER(ifc),TRANSFERCTRL_BYTESTOSEND(ifc));

#endif /* LIN_DEBUG */

  }
  return ;

} /* end l_stateReceivedIdentifier() */
$endif$

/********************************************************************
 *
 * l_stateReceiveData()
 */
/** \brief state machine function
 *
 * This function handles incoming characters in state RECEIVE_DATA
 *
 * - internal function
 * - master and slave
 * 
 * \param ifc      interface to act upon
 * \param rxChar   the character just received
 *
 * \retval none
 *
 */
STACK void l_stateReceiveData
(
  __OPTIONAL_IFC_DEFINITION_COMMA__
  l_u32                          rxBuffL,
  l_u32                          rxBuffM
)
{
  l_u8                          status = LIN_STATUS_SUCCESS;
/* Copy bytes from buffer */
  TRANSFERCTRL_BUFFER(ifc)[1] = (l_u8)rxBuffL;
  TRANSFERCTRL_BUFFER(ifc)[2] = (l_u8) (rxBuffL>>8);
  TRANSFERCTRL_BUFFER(ifc)[3] = (l_u8) (rxBuffL>>16);
  TRANSFERCTRL_BUFFER(ifc)[4] = (l_u8) (rxBuffL>>24);
  TRANSFERCTRL_BUFFER(ifc)[5] = (l_u8)rxBuffM;
  TRANSFERCTRL_BUFFER(ifc)[6] = (l_u8) (rxBuffM>>8);
  TRANSFERCTRL_BUFFER(ifc)[7] = (l_u8) (rxBuffM>>16);
  TRANSFERCTRL_BUFFER(ifc)[8] = (l_u8) (rxBuffM>>24);
  l_TimerStop(__OPTIONAL_TIMER_IFC_PARAMETER__);
#ifdef LIN_DEBUG
  /* allow test application to change the receive buffer */
$if(is_master_node)$
  l_dbgMasterReceiveBuffer(TRANSFERCTRL_BUFFER(ifc), TRANSFERCTRL_BYTESSENT(ifc));
#endif
  switch (TRANSFERCTRL_FRAME(ifc))
  {
$list_para_receive_data_func : { para_item |
$if(para_item.("is_normal_frame"))$
    case $para_item.("frame_index")$u: /* frame $para_item.("frame_name")$ */
$para_item.("list_tfctrl_buffer") : { buffer_item |
      l_pFrameBuf[$buffer_item.("buffer_value")$] = TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$];}$
      /* set the rx flags for the frame */
      l_pRxFlagData[$para_item.("rx_flag_data1")$] = 0xFF;
      /* set the changed flags for the frame */
      LIN_SET_CHANGED_FLAG_BYTE($para_item.("frame_index")$, (l_u8) 0xFF);

      /* handle all signals with different reference pos (maybe none)*/
$endif$

$if(para_item.("is_last_in_evttrig_frame"))$
    case $para_item.("frame_index")$u: /* frame $para_item.("frame_name")$ */
      if ((IFCCTRL_SCHEDULE(ifc) == $para_item.("table_index")$))
      {
        if (l_LastMappedFrame[IFCCTRL_SCHEDULE(ifc)] == $para_item.("last_mapped_frame")$)
        {

          l_ifcSetStatus(__OPTIONAL_IFC_PARAMETER_COMMA__
          LIN_STATUS_EVENT_TRIGGERED_FRAME_COLLISION_SOLVED,
          TRANSFERCTRL_BUFFER(ifc)[0]);

          IFCCTRL_SCHEDULE(ifc) = IFCCTRL_SCHEDULE_AFTER_COLLISION(ifc);

          IFCCTRL_ENTRY(ifc) = IFCCTRL_ENTRY_AFTER_COLLISION(ifc);
        }

      }

      l_frameReceived_$para_item.("frame_name")$(__OPTIONAL_IFC_PARAMETER__);
$endif$

$if(para_item.("not_is_last_in_evttrig_frame"))$
    case $para_item.("frame_index")$u: /* frame $para_item.("frame_name")$ */
      l_frameReceived_$para_item.("frame_name")$(__OPTIONAL_IFC_PARAMETER__);
$endif$

$if(para_item.("is_diagnostic_frame"))$
    case $para_item.("frame_index")$u: /* frame $para_item.("frame_name")$ */
#ifdef LIN_MASTER_NODE
#ifdef LIN_INCLUDE_DIAGNOSTICS
      ld_responseDistributor(__OPTIONAL_IFC_PARAMETER_COMMA__
        &(TRANSFERCTRL_BUFFER(ifc)[1]));
#endif /* LIN_INCLUDE_DIAGNOSTICS */
#endif /* LIN_MASTER_NODE */
$para_item.("list_tfctrl_buffer") : { buffer_item |
      l_pFrameBuf[$buffer_item.("buffer_value")$] = TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$];}$
      /* set the rx flags for the frame */
      l_pRxFlagData[$para_item.("rx_flag_data1")$] = 0xFF;
      l_pRxFlagData[$para_item.("rx_flag_data2")$] = 0xFF;
      /* set the changed flags for the frame */
      LIN_SET_CHANGED_FLAG_BYTE($para_item.("frame_index")$, (l_u8) 0xFF);

      /* handle all signals with different reference pos (maybe none)*/
#ifdef LIN_INCLUDE_DIAGNOSTICS
#endif /* LIN_INCLUDE_DIAGNOSTICS */
$endif$

$if(para_item.("is_evt_trig_frame"))$
    case $para_item.("frame_index")$u: /* event triggered frame $para_item.("frame_name")$ */
      if ((l_u8) (~(TRANSFERCTRL_CHECKSUM(ifc))) == 0)
      {
        switch (TRANSFERCTRL_BUFFER(ifc)[1])
        {
$para_item.("list_tfctrl_buffer") : { item |
          case $item.("frame_id")$u: /* mapped frame $item.("frame_name")$ */
            l_frameReceived_$item.("frame_name")$(__OPTIONAL_IFC_PARAMETER__ );
            break;
}$
          case LIN_INVALID_PROT_ID:
          default:
            /* should never happen, most likely an error */
            status = 0;
            break;
        }
      }
      else
      {
        status = 0; /* error in event triggered frame does not affect status word */
        l_lastMappedFrame[$para_item.("last_mapped_frame_index")$] = 0;
      }
$endif$

      break;
}$

$else$

  l_dbgSlaveReceiveBuffer(TRANSFERCTRL_BUFFER(ifc),
     TRANSFERCTRL_BYTESSENT(ifc));
#endif
  switch (LINFLEX_FILTERS_MATCH_INDEX_READ())
  {
$list_para_receive_data_func : { para_item |
$if(para_item.("is_normal_frame"))$
    case $para_item.("frame_index")$u: /* frame $para_item.("frame_name")$ */
$para_item.("list_tfctrl_buffer") : { buffer_item |
      l_pFrameBuf[$buffer_item.("buffer_value")$] = TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$];}$
      /* set the rx flags for the frame */
      l_pRxFlagData[$para_item.("rx_flag_data1")$] = 0xFF;
      /* set the changed flags for the frame */
      LIN_SET_CHANGED_FLAG_BYTE($para_item.("set_changed_flag_byte")$, (l_u8) 0xFF);

      /* handle all signals with different reference pos (maybe none)*/
$endif$

$if(para_item.("is_evt_trig_frame"))$
    case $para_item.("frame_index")$u: /* event triggered frame $para_item.("frame_name")$ */
      if ((l_u8) (~(TRANSFERCTRL_CHECKSUM(ifc)))== TRANSFERCTRL_BUFFER(ifc)[0])
      {
        switch (l_getFrameIndex(TRANSFERCTRL_BUFFER(ifc)[1]))
        {
          case LIN_INVALID_FRAME_INDEX:
          default:
            /* should never happen, most likely an error */
            status = 0;
            break;
        }
      }
      else
      {
        status = 0; /* error in event triggered frame does not affect status word */
      }
$endif$

$if(para_item.("is_diagnostic_frame"))$
    case $para_item.("frame_index")$u: /* frame $para_item.("frame_name")$ */
#ifdef LIN_SLAVE_NODE
#ifdef LIN_INCLUDE_DIAGNOSTICS
      ld_requestReceived(__OPTIONAL_IFC_PARAMETER_COMMA__ &(TRANSFERCTRL_BUFFER(ifc)[1]));
#endif
#endif
$para_item.("list_tfctrl_buffer") : { buffer_item |
      l_pFrameBuf[$buffer_item.("buffer_value")$] = TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$];}$
      /* set the rx flags for the frame */
      l_pRxFlagData[$para_item.("rx_flag_data1")$] = 0xFF;
      l_pRxFlagData[$para_item.("rx_flag_data2")$] = 0xFF;
      /* set the changed flags for the frame */
      LIN_SET_CHANGED_FLAG_BYTE($para_item.("set_changed_flag_byte")$, (l_u8) 0xFF);

      /* handle all signals with different reference pos (maybe none)*/
#ifdef LIN_INCLUDE_DIAGNOSTICS
#endif /* LIN_INCLUDE_DIAGNOSTICS */
$endif$

      break;
}$

$endif$

    default:
      /* should never happen */
      l_terminateTransfer(__OPTIONAL_IFC_PARAMETER__);

      return ;

  }

  if (status != 0)
  {
    l_ifcSetStatus(__OPTIONAL_IFC_PARAMETER_COMMA__
      status,
      TRANSFERCTRL_BUFFER(ifc)[0]);
  } /* if (status) */

  l_terminateTransfer(__OPTIONAL_IFC_PARAMETER__);

  return ;

} /* end l_stateReceiveData() */


/********************************************************************
 *
 * l_stateSendData()
 */
/** \brief state machine function
 *
 * This function handles incoming characters in state SEND_DATA
 *
 * - internal function
 * - master and slave
 *
 * \param ifc      interface to act upon
 *
 * \retval none
 *
 */
STACK void l_stateSendData
(
  __OPTIONAL_IFC_DEFINITION__
)
{
  l_u8 frameId = LIN_INVALID_PROT_ID;
  l_TimerStop(__OPTIONAL_TIMER_IFC_PARAMETER__);
$if(is_master_node)$
  switch (TRANSFERCTRL_FRAME(ifc))
  {
$list_para_send_data_func : { para_item |
    case $para_item.("frame_index")$u: /* frame $para_item.("frame_name")$ */
$if(para_item.("is_diagnostic_frame"))$
#ifdef LIN_MASTER_NODE
#ifdef LIN_INCLUDE_DIAGNOSTICS
      ld_transmittedMasterRequest(__OPTIONAL_IFC_PARAMETER__);
      IFCCTRL_DIAGFLAGS(ifc) &= (l_u8)  ~LIN_DIAG_TX_FLAG;
#endif /* LIN_INCLUDE_DIAGNOSTICS */
#endif /* LIN_MASTER_NODE */

      /* set the tx flags for the frame */
      l_pTxFlagData[$para_item.("tx_flag_data1")$] = 0xFF;
      l_pTxFlagData[$para_item.("tx_flag_data2")$] = 0xFF;
      /* clear the changed flags for the frame */
      LIN_CLEAR_CHANGED_FLAG_BYTE($para_item.("frame_index")$);
      frameId = 60;
$else$
      /* set the tx flags for the frame */
      l_pTxFlagData[$para_item.("tx_flag_data1")$] = 0xFF;
      /* clear the changed flags for the frame */
      LIN_CLEAR_CHANGED_FLAG_BYTE($para_item.("frame_index")$);
      frameId = $para_item.("frame_id")$;
$endif$

      break;
}$
$else$
  switch (LINFLEX_FILTERS_MATCH_INDEX_READ())
  {
$list_para_send_data_func : { para_item |
    case $para_item.("frame_index")$u: /* frame $para_item.("frame_name")$ */
$if(para_item.("is_diagnostic_frame"))$
#ifdef LIN_SLAVE_NODE
#ifdef LIN_INCLUDE_DIAGNOSTICS
      ld_transmittedSlaveResponse(__OPTIONAL_IFC_PARAMETER__);
#endif /* LIN_INCLUDE_DIAGNOSTICS */
#endif /* LIN_SLAVE_NODE */

      /* set the tx flags for the frame */
      l_pTxFlagData[$para_item.("tx_flag_data1")$] = 0xFF;
      l_pTxFlagData[$para_item.("tx_flag_data2")$] = 0xFF;
      /* clear the changed flags for the frame */
      LIN_CLEAR_CHANGED_FLAG_BYTE($para_item.("clear_changed_flag_byte")$);
      frameId = l_pFrameId[$para_item.("frame_index")$];
$else$
      /* set the tx flags for the frame */
      l_pTxFlagData[$para_item.("tx_flag_data1")$] = 0xFF;
      /* clear the changed flags for the frame */
      LIN_CLEAR_CHANGED_FLAG_BYTE($para_item.("clear_changed_flag_byte")$);
$if(para_item.("contain_error_signal"))$
      /* clear error signal for node */
      l_bool_wr_$error_signal_name$(0);
$endif$

      frameId = l_pFrameId[$para_item.("frame_index")$];
$endif$


      break;
}$
$endif$
    default:
      /* nothing to be done */
      break;

  } /* switch (frame index) */

  l_terminateTransfer(__OPTIONAL_IFC_PARAMETER__);
  l_ifcSetStatus(__OPTIONAL_IFC_PARAMETER_COMMA__
    LIN_STATUS_SUCCESS,
    frameId);

  return ;

} /* end l_stateSendData() */


$if(is_master_node)$
/********************************************************************
 *
 * l_serialError()
 */
/** \brief function handling serial errors
 *
 * Serial transmission errors are handled in this function
 *
 * - internal function
 * - master only
 *
 * \param ifc      interface to act upon
 *
 * \retval none
 *
 */
STACK void l_serialError
(
  __OPTIONAL_IFC_DEFINITION__
)
{
  if (IFCCTRL_STATE(ifc) == LIN_STATE_BUSSLEEP)
  {
#ifdef __MORE_IFCS__
    if (Timer.SubChannel[ifc] != LIN_WAKEUP_SUBCHANNEL)
#else
    if (Timer.SubChannel != LIN_WAKEUP_SUBCHANNEL)
#endif
    {
      l_TimerStart(__OPTIONAL_TIMER_IFC_PARAMETER_COMMA__
        LIN_WAKEUP_SUBCHANNEL,
        LIN_WAKEUP_TIMER_VALUE(ifc));

    } /* if (timer running) */

  } /* if (state bussleep) */
  else if (IFCCTRL_STATE(ifc) == LIN_STATE_IDLE)
  {

    /* nothing to be done */

  } /* if (state idle) */
  else
  {
    l_u8                  status = LIN_STATUS_ERROR;
    switch (TRANSFERCTRL_FRAME(ifc))
    {
$list_para_serial_error_func : { para_item |
$if(para_item.("is_diagnostic_frame"))$
#ifdef LIN_INCLUDE_DIAGNOSTICS
$if(para_item.("is_publisher"))$
      case $para_item.("frame_index")$u: /* master request frame */
        ld_signalTxFrameError(__OPTIONAL_IFC_PARAMETER__);
        break;
$else$
      case $para_item.("frame_index")$u: /* slave response frame */
        ld_signalRxFrameError(__OPTIONAL_IFC_PARAMETER__);
        break;
$endif$

#endif /* LIN_INCLUDE_DIAGNOSTICS */
$endif$

$if(para_item.("is_evt_trig_frame"))$
      case $para_item.("frame_index")$u: /* event triggered frame $para_item.("frame_name")$ */
        l_lastMappedFrame[$para_item.("last_mapped_frame_index")$] = 0;
        status = 0;
        break;
$endif$
}$

      default:
        /* should never happen */
        break;

    } /* switch (frame) */

    if (status
      &&
      ((IFCCTRL_STATE(ifc) == LIN_STATE_RECEIVE_DATA)
      ||
      (IFCCTRL_STATE(ifc) == LIN_STATE_SEND_DATA)))
    {
      l_ifcSetStatus(__OPTIONAL_IFC_PARAMETER_COMMA__
        LIN_STATUS_ERROR,
        TRANSFERCTRL_BUFFER(ifc)[0]);

    } /* if (status) */

    l_terminateTransfer(__OPTIONAL_IFC_PARAMETER__);
  } /* if (state) */

  return ;

} /* l_serialError() */
$else$

/********************************************************************
 *
 * l_serialErrorFrameBody()
 */
/** \brief function handling serial errors
 *
 * This function handles serial errors in state RECEIVE_DATA and SEND_DATA 

 *
 * - internal function
 * - slave only
 *
 * \param ifc      interface to act upon
 * \param status   indicates whether status word shall be set
 *
 * \retval none
 *
 */
STACK void l_serialErrorFrameBody
(
  __OPTIONAL_IFC_DEFINITION_COMMA__
  l_u8                        status
)
{
  l_u16                       frame = LIN_INVALID_FRAME_INDEX;

  if (TRANSFERCTRL_FRAME(ifc) < LIN_FRAME_NR_MAX)
  {
    frame = (l_u16) (LINFLEX_FILTERS_MATCH_INDEX_READ());
    switch (frame)
    {
      case (l_u16) LIN_INVALID_FRAME_INDEX:
        status = 0; /* no error reporting */
        break;
$list_para_error_frame_body : { para_item |
$if(para_item.("is_evt_trig_frame"))$
      case $para_item.("frame_index")$u: /* event triggered frame $para_item.("frame_name")$ */
        LIN_SET_CHANGED_FLAG_BYTE($para_item.("set_changed_flag_byte")$, (l_u8) 0xFF);
        status = 0; /* no error reporting */
        break;
$else$

$if(para_item.("is_diagnostic_frame"))$
#ifdef LIN_INCLUDE_DIAGNOSTICS
$if(para_item.("is_publisher"))$
      case $para_item.("frame_index")$u: /* SlaveResp frame */
        ld_signalTxFrameError(__OPTIONAL_IFC_PARAMETER__);
        break;
$else$
      case $para_item.("frame_index")$u: /* MasterReq frame */
        ld_signalRxFrameError(__OPTIONAL_IFC_PARAMETER__);
        break;
$endif$

#endif /* LIN_INCLUDE_DIAGNOSTICS */
$else$
      case $para_item.("frame_index")$u:   /* frame $para_item.("frame_name")$ */
        LIN_SET_CHANGED_FLAG_BYTE($para_item.("set_changed_flag_byte")$, (l_u8) 0xFF);
        status = 0; /* no error reporting */
        break;

$endif$

$endif$
}$

      default:
        /* nothing to be done here */

        break;

    } /* switch(frame) */ 

    if (status)
    {
      l_ifcSetStatus(__OPTIONAL_IFC_PARAMETER_COMMA__
        LIN_STATUS_ERROR,
        TRANSFERCTRL_BUFFER(ifc)[0]);
    }

  } /* if (valid frame index) */

  l_terminateTransfer(__OPTIONAL_IFC_PARAMETER__);

  return ;

} /* end l_serialErrorFrameBody() */
$endif$

$list_para_other_func : { para_item |
$if(para_item.("is_compose_frame"))$
STACK static void l_composeFrame_$para_item.("frame_name")$
(
  __OPTIONAL_IFC_DEFINITION__
)
{$para_item.("list_tfctrl_buffer") : { buffer_item |
  TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$] = l_pFrameBuf[$buffer_item.("buffer_value")$];}$
}

$else$
STACK static void l_frameReceived_$para_item.("frame_name")$
(
  __OPTIONAL_IFC_DEFINITION__
)
{$para_item.("list_tfctrl_buffer") : { buffer_item |
  l_pFrameBuf[$buffer_item.("buffer_value")$] = TRANSFERCTRL_BUFFER(ifc)[$buffer_item.("buffer_index")$];}$
  /* set the rx flags for the frame */
  l_pRxFlagData[$para_item.("rx_flag_data1")$] = 0xFF;
  /* set the changed flags for the frame */
  LIN_SET_CHANGED_FLAG_BYTE($para_item.("set_changed_flag_byte")$, (l_u8) 0xFF);

  /* handle all signals with different reference pos (maybe none)*/
} /* end l_frameReceived_$para_item.("frame_name")$() */
$endif$
}$

$if(include_schtab_nrmax_def)$
/* interface definition for schedule tables */
const l_u8     l_pSchTabIfc[LIN_SCH_TAB_NR_MAX] = 
{
 $intf_def_for_sch_tab; separator= ", "$
};
$endif$
