/******************************************************************************
* 
* Freescale Semiconductor Inc.
* (c) Copyright $from_year$-2016 Freescale Semiconductor, Inc.
* Copyright 2016-$to_year$ NXP
* ALL RIGHTS RESERVED.
* 
****************************************************************************//*!
*
* @file      lin_hw_cfg.h
*
* @author    FPT Software
*
* @version   1.0
*
* @date      $date$
*
* @brief     Hardware configuration file
*
******************************************************************************/
$!
<lin_hw_cfg.h file> ::=
            <general_def>
            <interface_type_def>
            (<sci_config_def>)
            (<gpio_config_def>)
!$
#ifndef      _LIN_HW_CFG_H
#define      _LIN_HW_CFG_H
#include <$mcu_name$.h>

$if(is_using_uart)$
typedef enum {
   LINUART0,
   LINUART1,
   LINUART2
} lin_hardware_name;
$else$
typedef enum {
   SCI0,
   SCI1,
   SCI2,
   SCI3,
   SCI4,
   SCI5,
   GPIO,
   SLIC
} lin_hardware_name;
  $if(is_multi_timer)$
    $if(is_master_mode)$
        $if(xgate_status)$
        $else$
typedef enum {
   PIT0,
   PIT1,
   PIT2,
   PIT3,
   PIT4,
   PIT5,
   PIT6,
   PIT7
}lin_timer_name;
        $endif$
    $endif$
  $endif$
$endif$

$if(is_using_gpio)$
#define TX_PIN_DATA PTAD_PTAD1
#define TX_PIN_DIRECT PTADD_PTADD1
#define RX_PIN_DATA PTAD_PTAD2
#define RX_PIN_DIRECT PTADD_PTADD2

/* Interface type that MCU uses */
#define XGATE_SUPPORT 0
#define _LIN_XGATE_   0
#define _LIN_SCI_     0
#define _LIN_UART_    0
#define _LIN_SLIC_    0
#define _LIN_GPIO_    1
$else$
    $if(is_using_slic)$
#define XGATE_SUPPORT 0
#define _LIN_XGATE_   0
#define _LIN_SCI_     0
#define _LIN_UART_    0
#define _LIN_SLIC_    1
#define _LIN_GPIO_    0

/* MCU bus frequency */
#define MCU_BUS_FREQ       $bus_clock$
#define TIME_BASE_PERIOD   $period_time$
    $else$

      $if(is_using_sci)$
/* MCU type definition */
#define _S08_   0
#define _S12_   1
#define _S12X_  2
#define _K_     3

#define SCI_V2  0
#define SCI_V4  1
#define SCI_V5  2
#define SCI_V6  3

/* SCI version */
#define SCI_VERSION $mcu_version$
      $endif$

/* Type of MCU */
#define _MCU_  $mcu_type$

      $if(is_slave_mode)$
/* Resynchronization support */
#define __RESYN_EN   $resynchronization_support$

/* Autobaud support */
#define AUTOBAUD     $autobaud_support$
      $endif$
      $if(is_master_mode)$
/* Resynchronization support */
#define __RESYN_EN   0
      $endif$

/* Interface type that MCU uses */
#define XGATE_SUPPORT $xgate_support_status$
#define _LIN_XGATE_   $xgate_using_status$
      $if(xgate_status)$
#define _LIN_SCI_     0
#define _LIN_UART_    0
#define _LIN_SLIC_    0
#define _LIN_GPIO_    0
      $else$
#define _LIN_SCI_     $sci_using_status$
#define _LIN_UART_    $uart_using_status$
#define _LIN_SLIC_    0
#define _LIN_GPIO_    0
      $endif$
/***********  SCI HARDWARE SECTION  *********/
      $if(is_using_sci)$
#define NUM_OF_SCI_CHANNEL    $number_sci_channel$

/* SCI Base Register definition */
$list_reg_address:{reg_address | #define $reg_address.("sci_type")$_ADDR  $reg_address.("sci_address")$
}$
/* Use SCI Channel  */
#define _SCI0_   $sci0_using_status$
#define _SCI1_   $sci1_using_status$
#define _SCI2_   $sci2_using_status$
#define _SCI3_   $sci3_using_status$
#define _SCI4_   $sci4_using_status$
#define _SCI5_   $sci5_using_status$
        $if(is_multi_timer)$
          $if(is_master_mode)$
            $if(xgate_status)$
            $else$

/* Multi Timer mode  */
#define MULTI_TIMER_MODE  1

/* Use PIT Channel  */
#define _PIT0_   $pit0_using_status$
#define _PIT1_   $pit1_using_status$
#define _PIT2_   $pit2_using_status$
#define _PIT3_   $pit3_using_status$
#define _PIT4_   $pit4_using_status$
#define _PIT5_   $pit5_using_status$
#define _PIT6_   $pit6_using_status$
#define _PIT7_   $pit7_using_status$

/* Timer index */
$first(list_timer_index): { timer_idx | #define $timer_idx.mapItem.("name")$ $timer_idx.mapItem.("index")$}$
$rest(list_timer_index): { timer_idx |
#define $timer_idx.mapItem.("name")$ $timer_idx.mapItem.("index")$}$
            $endif$
          $endif$
        $endif$

      $elseif(is_using_uart)$
#define NUM_OF_UART_CHANNEL    $number_sci_channel$
/* UART Base Register definition */
$list_reg_address:{reg_address | #define $reg_address.("sci_type")$_ADDR  $reg_address.("sci_address")$
}$
/* Use UART Channel  */
#define _UART0_   $uart0_using_status$
#define _UART1_   $uart1_using_status$
#define _UART2_   $uart2_using_status$
      $endif$

/* MCU bus frequency */
#define MCU_BUS_FREQ       $bus_clock$
      $if(is_multi_timer)$
        $if(is_slave_mode)$
#define TIME_BASE_PERIOD   $period_time$

/* max idle timeout for all networks = idle_timeout_value*1000000/time_base_period */
#define _MAX_IDLE_TIMEOUT_    $max_idle_timeout$      /* idle_timeout_value = $idle_timeout_value$s */
        $else$
          $if(xgate_status)$
/* Default interrupt period of the timer for LIN is TIME_BASE_PERIOD micro seconds */
#define TIME_BASE_PERIOD   $period_time$

/* max idle timeout for all networks = idle_timeout_value*1000000/time_base_period */
#define _MAX_IDLE_TIMEOUT_    $max_idle_timeout$      /* idle_timeout_value = $idle_timeout_value$s */
          $endif$
        $endif$
      $else$

/* Default interrupt period of the timer for LIN is TIME_BASE_PERIOD micro seconds */
#define TIME_BASE_PERIOD   $period_time$

/* max idle timeout for all networks = idle_timeout_value*1000000/time_base_period */
#define _MAX_IDLE_TIMEOUT_    $max_idle_timeout$      /* idle_timeout_value = $idle_timeout_value$s */
      $endif$
    $endif$
  $endif$
#endif