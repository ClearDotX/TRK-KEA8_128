/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2016 Freescale Semiconductor, Inc.
* Copyright 2016-2017 NXP
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup autobaud_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      lin_lld_autobaud.h

@brief     Functions for Autobaud feature
*****************************************************************************/
#ifndef __LIN_LLD_AUTOBAUD
#define __LIN_LLD_AUTOBAUD

#include "lin.h"
#if(defined NUM_OF_SCI_CHANNEL)
#include "lin_lld_sci.h"
#endif
#if(defined NUM_OF_UART_CHANNEL)
#include "lin_lld_uart.h"
#endif
#include "lin_hw_cfg.h"
#include "lin_common_proto.h"
#include "lin_lld_timesrv.h"
#include "lin_cfg.h"
#include "lin_lld_autobaud.h"

#if (defined(_MC9S12ZVML128_H)||defined(_MC9S12ZVML31_H)||defined(_MC9S12ZVL32_H)||defined(_MC9S12ZVL128_H) \
    ||defined(_MC9S12ZVMC256_H)||defined(_MC9S12ZVMB_H))

#define CLEAR_TIMER_CHANNEL_INTERRUPT_FLAG (TIM0TFLG1 = TIM0TFLG1_C3F_MASK) /*Clear Channel Interrupt Flag */
#define TIMER_CNT_REG  TIM0TC3                                              /* Address of timer counter register */
#define TIMER_CONTROL_EDG TIM0TCTL4_EDG3x                                   /* Input Capture Active Edge Control */
#define TIMER_INT_ENA       TIM0TIE_C3I                                     /* Timer Channel Interrupt Enable */
#define TIMER_FREQ      MCU_BUS_FREQ/(1 << TIM0TSCR2_PR)                    /* Timer Frequency */

#elif (defined(_MC9S12ZVH128_H))
#define CLEAR_TIMER_CHANNEL_INTERRUPT_FLAG (TIM1TFLG1 = TIM1TFLG1_C3F_MASK) /*Clear Channel Interrupt Flag */
#define TIMER_CNT_REG  TIM1TC0                                              /* Address of timer counter register */
#define TIMER_CONTROL_EDG TIM1TCTL4_EDG0x                                   /* Input Capture Active Edge Control */
#define TIMER_INT_ENA       TIM1TIE_C0I                                     /* Timer Channel Interrupt Enable */
#define TIMER_FREQ      MCU_BUS_FREQ/(1 << TIM1TSCR2_PR)                    /* Timer Frequency */

#elif (defined(_MC9S12VR64_H)||defined(_MC9S12VR32_H))
#define CLEAR_TIMER_CHANNEL_INTERRUPT_FLAG (TFLG1 = TFLG1_C3F_MASK)         /*Clear Channel Interrupt Flag */
#define TIMER_CNT_REG  TC3                                                  /* Address of timer counter register */
#define TIMER_CONTROL_EDG TCTL4_EDG3x                                       /* Input Capture Active Edge Control */
#define TIMER_INT_ENA       TIE_C3I                                         /* Timer Channel Interrupt Enable */
#define TIMER_FREQ      MCU_BUS_FREQ/(1 << TSCR2_PR)                        /* Timer Frequency */

#elif (defined(_MC9S12ZVMA_H)||defined(_MC9S12VRP64_H)||defined(_MC9S12VRP48_H))
#define CLEAR_TIMER_CHANNEL_INTERRUPT_FLAG (TIM1TFLG1 = TIM1TFLG1_C1F_MASK) /*Clear Channel Interrupt Flag */
#define TIMER_CNT_REG  TIM1TC1                                              /* Address of timer counter register */
#define TIMER_CONTROL_EDG TIM1TCTL4_EDG1x                                   /* Input Capture Active Edge Control */
#define TIMER_INT_ENA       TIM1TIE_C1I                                     /* Timer Channel Interrupt Enable */
#define TIMER_FREQ      MCU_BUS_FREQ/(1 << TIM1TSCR2_PR)                    /* Timer Frequency */

#elif ((defined(MCU_SKEAZ1284)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)))
#define TIMER_CNT_REG  FTM0_C1V                                              /* Address of timer counter register */
#define TIMER_INT_ENA(A)      FTM0_C1SC = (FTM0_C1SC & (~FTM_CnSC_CHIE_MASK)) | (A << FTM_CnSC_CHIE_SHIFT) /* Timer Channel Interrupt Enable */
#define TIMER_FREQ      MCU_BUS_FREQ        /* Timer Frequency */
#endif

#define AUTOBAUD_BAUDRATE_TOLERANCE 5    /* Accept Master Baudrate to be tolerated for 5% */
#define BIT_RATE_TOLERANCE_UNSYNC 14     /* Unsynchronized Baudrate to be tolerated for 5% */
/* Timer Count equivalent to Bit Max Duration 19200bps*/
#define BIT_DURATION_MAX_19200 ((TIMER_FREQ / 192000)* (100 + AUTOBAUD_BAUDRATE_TOLERANCE))/10
/* Timer Count equivalent to Bit Min Duration 19200bps*/
#define BIT_DURATION_MIN_19200 ((TIMER_FREQ  / 192000)* (100 - AUTOBAUD_BAUDRATE_TOLERANCE))/10
/* Timer Count equivalent to Bit Max Duration 9600bps*/
#define BIT_DURATION_MAX_9600 ((TIMER_FREQ  / 96000 )* (100 + AUTOBAUD_BAUDRATE_TOLERANCE))/10
/* Timer Count equivalent to Bit Min Duration 9600bps*/
#define BIT_DURATION_MIN_9600 ((TIMER_FREQ  / 96000) * (100 - AUTOBAUD_BAUDRATE_TOLERANCE))/10

#define DBIT_DURATION_MAX_19200 2*BIT_DURATION_MAX_19200
#define DBIT_DURATION_MIN_19200 2*BIT_DURATION_MIN_19200
#define DBIT_DURATION_MAX_9600 2*BIT_DURATION_MAX_9600
#define DBIT_DURATION_MIN_9600 2*BIT_DURATION_MIN_9600

extern  l_u16       autobaud_tmr_capture[];
extern  l_u8       autobaud_tmr_capture_index;
extern  l_u16       autobaud_current;
extern volatile l_bool stop_flag;

void autobaud_init(void);

#if (defined(_MC9S12VR64_H)||defined(_MC9S12VR32_H)||defined(_MC9S12VRP64_H)||defined(_MC9S12VRP48_H))
/* inline definition for CW classic 5.1 */
#pragma INLINE
l_u16 lin_calc_max_res_timeout_cnt(l_u16 baudRate, l_u8 size);
#else
/* inline definition for CW 10.6 */
inline l_u16 lin_calc_max_res_timeout_cnt(l_u16 baudRate, l_u8 size);
#endif

#endif
