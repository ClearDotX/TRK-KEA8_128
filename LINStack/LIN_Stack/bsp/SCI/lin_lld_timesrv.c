/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2016 Freescale Semiconductor, Inc.
* Copyright 2016-2017 NXP
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup SCI_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file            bsp/SCI/lin_lld_timesrv.c
*
* @author        FPT Software
*
* @brief         Timer for S08, S12, S12X
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 *
 * 20101027         v1.0        First version
 * 20111005         v1.1        Updated hardware support
 * 20111121     v1.2    Updated timer config for J637
 *
 *****************************************************************************/

#include "lin_lld_timesrv.h"
#include "lin_lld_sci.h"
#include "lin_common_proto.h"
#include "lin_hw_cfg.h"

#if defined(_MC9S12I32_H)
#include "analog_die_reg.h"
#endif /* End defined(_MC9S12I32_H) */

#if defined (_MC9S12I128_H)
#include "mm912j637.h"
#endif /* End defined(_MC9S12I128_H) */

#if (LIN_MODE == _MASTER_MODE_)
extern const lin_hardware_name lin_virtual_ifc[LIN_NUM_OF_IFCS];
#endif /* End (LIN_MODE == _MASTER_MODE_) */

#ifdef MULTI_TIMER_MODE
extern const l_u16 time_base_period[LIN_NUM_OF_IFCS];
#endif /* End MULTI_TIMER_MODE */

#if (_MCU_ == _S12X_)
void lin_lld_timer_S12X_init (void)
{

#ifdef MULTI_TIMER_MODE

    /* Init PIT timer */
    PITTF = 0x00;
    PITCE = 0x00;
    PITINTE = 0x00;
    /* Configures the PIT (Periodic Interrupt Timer) to generate a periodic interrupt of 500us */
    /* (Interrupt on channel 0)    */

    /*** USING PIT Chanel 0 ***/
#if (_PIT0_ == 1)
    PITTF_PTF0 = 1;
    PITCE_PCE0 = 1;
    PITINTE_PINTE0 = 1;
    /* Baudrate register loading */
    PITLD0 = (l_u16)((MCU_BUS_FREQ/1000000)*(time_base_period[PIT0_INDEX]));
#endif /* (_PIT0_ == 1) */

    /*** USING PIT Chanel 1 ***/
#if (_PIT1_ == 1)
    PITTF_PTF1 = 1;
    PITCE_PCE1 = 1;
    PITINTE_PINTE1 = 1;
    /* Baudrate register loading*/
    PITLD1 = (l_u16)((MCU_BUS_FREQ/1000000)*(time_base_period[PIT1_INDEX]));
#endif /* (_PIT1_ == 1) */

    /*** USING PIT Chanel 2 ***/
#if (_PIT2_ == 1)
    PITTF_PTF2 = 1;
    PITCE_PCE2 = 1;
    PITINTE_PINTE2 = 1;
    /* Baudrate register loading*/
    PITLD2 = (l_u16)((MCU_BUS_FREQ/1000000)*(time_base_period[PIT2_INDEX]));
#endif /* (_PIT2_ == 1) */

    /*** USING PIT Chanel 3 ***/
#if (_PIT3_ == 1)
    PITTF_PTF3 = 1;
    PITCE_PCE3 = 1;
    PITINTE_PINTE3 = 1;
    /* Baudrate register loading */
    PITLD3 = (l_u16)((MCU_BUS_FREQ/1000000)*(time_base_period[PIT3_INDEX]));
#endif /* (_PIT3_ == 1) */

    /*** USING PIT Chanel 4 ***/
#if (_PIT4_ == 1)
    PITTF_PTF4 = 1;
    PITCE_PCE4 = 1;
    PITINTE_PINTE4 = 1;
    /* Baudrate register loading */
    PITLD4 = (l_u16)((MCU_BUS_FREQ/1000000)*(time_base_period[PIT4_INDEX]));
#endif /* (_PIT4_ == 1) */

    /*** USING PIT Chanel 5 ***/
#if (_PIT5_ == 1)
    PITTF_PTF5 = 1;
    PITCE_PCE5 = 1;
    PITINTE_PINTE5 = 1;
    /* Baudrate register loading*/
    PITLD5 = (l_u16)((MCU_BUS_FREQ/1000000)*(time_base_period[PIT5_INDEX]));
#endif /* (_PIT5_ == 1) */

    /*** USING PIT Chanel 2 ***/
#if (_PIT6_ == 1)
    PITTF_PTF6 = 1;
    PITCE_PCE6 = 1;
    PITINTE_PINTE6 = 1;
    /* Baudrate register loading*/
    PITLD6 = (l_u16)((MCU_BUS_FREQ/1000000)*(time_base_period[PIT6_INDEX]));
#endif /* (_PIT6_ == 1) */

    /*** USING PIT Chanel 7 ***/
#if (_PIT7_ == 1)
    PITTF_PTF7 = 1;
    PITCE_PCE7 = 1;
    PITINTE_PINTE7 = 1;
    /* Baudrate register loading */
    PITLD7 = (l_u16)((MCU_BUS_FREQ/1000000)*(time_base_period[PIT7_INDEX]));
#endif /* (_PIT7_ == 1) */

    PITMTLD0=0x00;
    /* Enable PIT Module */
    PITCFLMT = 0xA0;

#else /* Else MULTI_TIMER_MODE */
    /* Init PIT0 timer for single timer mode */
    PITTF = 0x00;
    PITCE = 0x00;
    PITINTE = 0x00;
    /* Configures the PIT (Periodic Interrupt Timer) to generate a periodic interrupt of 500us */
    /* (Interrupt on channel 0)    */

    /*** USING PIT Chanel 0 ***/
    PITTF_PTF0 = 1;
    PITCE_PCE0 = 1;
    PITINTE_PINTE0 = 1;
    /* TIME_BASE_PERIOD micro seconds with Fbus = MCU_BUS_FREQ Mhz*/
    PITLD0 = (MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD;
    PITMTLD0=0x00;

    /* Enable PIT Module */
    PITCFLMT = 0xA0;
#endif /* End MULTI_TIMER_MODE */
}


#endif /* End (_MCU_ == _S12X_) */

/* ----------------------------------------------------------------- */

#if (_MCU_ == _S12_)
void lin_lld_timer_S12_init (void)
{
#if defined(_MC9S12I32_H)
    l_u16 temp;
    /* Init timer for MM912F634 apply for 9S12I32 MCU */
    /* Initialize TIM timer */
    /* Timer functions normally */
    TSCR1 = 0x00;
    /* Output Compare Select Timer 3 */
    TIOS = 8;
    /* Define an output associated OC3 */
    TCTL1 = 192;
    /* Enable toggle output compare pin */
    TTOV = 8;
    /* Enable Hardware interrupt request */
    TSCR2 = 0x88;
    /* Enable tim3 */
    TIE = 8;
    /* Set timer period */
    temp = (MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD;
    TC3hi = (l_u8)(temp>>8);
    TC3lo = (l_u8)temp;
    TSCR1 = 128;
    /* End define for I32 */

#elif defined(_MC9S12GN32_H) || defined(_MC9S12G64_H)
    /* Timer functions normally */
    TSCR1 = 8;
    /* Set up timer channel 0 */
    /* Timer output compare */
    TIOS = TIOS_IOS0_MASK;
    /* Enable toggle output compare pin */
    TTOV = TTOV_TOV0_MASK;
    /* Enable Hardware interrupt request */
    TSCR2 = 0x00;
    /* Enable timer channel 0 interrupt */
    TIE = TIE_C0I_MASK;
    /* Set timer period */
    TC0 = (MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD;
    /* Enable timer */
    TSCR1 = TSCR1_TEN_MASK ;
    /* End define for GN32, G64 */

#elif (defined(_MC9S12VR64_H) || defined(_MC9S12VR32_H))
    /* Timer functions normally */
    TSCR1 = 8;
    /* Set up timer channel 3 */
    CFORC |= CFORC_FOC0_MASK;
    /* Timer output compare */
    TIOS |= TIOS_IOS0_MASK;
    /* Enable toggle output compare pin */
    TTOV |= TTOV_TOV0_MASK;
    /* Disable Hardware interrupt request    and Timer prescaler = 1 */
    TSCR2 = 0x00;
    /* Enable timer channel 3 interrupt */
    TIE |= TIE_C0I_MASK;
    /* Set timer period */
    TC0 = (MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD;
    /* Enable timer */
    TSCR1 = TSCR1_TEN_MASK;
    /* End (defined(_MC9S12VR64_H) || defined(_MC9S12VR32_H))*/

#elif defined(_MM912J637_H)
    /* Disable Timer */
    TSCR1 = 0x00;
    /* Timer output compare */
    TIOS = 0x08;
    /* Timer disconnect from output pin */
    TCTL1 = 0x00;
    /* Disable input capture */
    TCTL2 = 0x00;
    /* disable toggle output compare pin */
    TTOV = 0x00;
    /* Enable timer counter reset by successfull OC on channel */
    TSCR2 = 0x08;
    /* Enable timer channel 3 interrupt */
    TIE = 0x08;
    /* Set timer period */
    TC3 = (MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD;
    /* Enable timer */
    TSCR1 = 0x80;
    /* End define for 9S12I128 */
#elif defined(_MM9Z1J638_H)
    /* Disable Timer */
    B_TSCR1 = 0x00;
    /* Timer output compare */
    B_TIOS = 0x08;
    /* Timer disconnect from output pin */
    B_TCTL1 = 0x00;
    /* Disable input capture */
    B_TCTL2 = 0x00;
    /* disable toggle output compare pin */
    B_TTOV = 0x00;
    /* Enable timer counter reset by successfull OC on channel */
    B_TSCR2 = 0x08;
    /* Enable timer channel 3 interrupt */
    B_TIE = 0x08;
    /* Set timer period */
    B_TC3 = MCU_BUS_FREQ/(1000000/TIME_BASE_PERIOD);
    /* Enable timer */
    B_TSCR1 = 0x80;
#else

#if defined(_MC9S12XHY256_H) || defined(_MC9S12HY64_H)
#define TSCR1 TIM0_TSCR1
#define OCPD  TIM0_OCPD
#define PACTL TIM0_PACTL
#define OC7M  TIM0_OC7M
#define TIOS  TIM0_TIOS
#define TCTL1 TIM0_TCTL1
#define TTOV  TIM0_TTOV
#define TSCR2 TIM0_TSCR2
#define TFLG1 TIM0_TFLG1
#define TIE   TIM0_TIE
#define TC7   TIM0_TC7
#endif /* End for 9S12XHY256 and 9S12HY64 */

#if (defined(_MC9S12ZVML128_H) || defined(_MC9S12ZVL32_H)||defined(_MC9S12ZVHY64_H)||defined(_MC9S12ZVH128_H)\
    ||defined(_MC9S12ZVML31_H)||defined(_MC9S12ZVMC256_H)||defined(_MC9S12ZVL128_H)||defined(_MC9S12ZVMB_H))
    /*Configure the timer*/
    /*Timer prescaler = 1 */
    TIM0TSCR2 = 0x00;
    /*Enable Channel 2 as Output Compare */
    TIM0TIOS_IOS2 = 1;
    /*Enable Channel 2 interrupt */
    TIM0TIE_C2I = 1;
    TIM0TC2 = (MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD;
    /*Disable the timer when the MCU is in freeze mode */
    TIM0TSCR1_TSFRZ = 1;
    /*Enable the Timer */
    TIM0TSCR1_TEN = 1;
#else
#if (defined(_MC9S12ZVMA_H)|| defined(_MC9S12VRP64_H) || defined(_MC9S12VRP48_H))
    /*Configure the timer*/
    /*Timer prescaler = 1 */
    TIM1TSCR2 = 0x00;
    /*Enable Channel 0 as Output Compare */
    TIM1TIOS_IOS0 = 1;
    /*Enable Channel 0 interrupt */
    TIM1TIE_C0I = 1;
    TIM1TC0 = (MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD;
    /*Disable the timer when the MCU is in freeze mode */
    TIM1TSCR1_TSFRZ = 1;
    /*Enable the Timer */
    TIM1TSCR1_TEN = 1;
#else
#if defined(_MC9S12ZVC64_H)
    /*Configure the timer*/
    /*Timer prescaler = 32 (6.25MHZ/32 ~ 5.12[us]) */
    TIM1TSCR2 = 0x08;
    /*Enable Channel 2 as Output Compare */
    TIM1TIOS_IOS2 = 1;
    /*Enable Channel 2 interrupt */
    TIM1TIE_C2I = 1;
    TIM1TC2 = (MCU_BUS_FREQ/500000)*TIME_BASE_PERIOD;
    /*Disable the timer when the MCU is in freeze mode */
    TIM1TSCR1_TSFRZ = 1;
    /*Enable the Timer */
    TIM1TSCR1_TEN = 1;
#else
    /* Initialize TIM timer */
    /* Timer functions normally */
    TSCR1 = 8;
    /* Disable timer */
    OCPD = 128;
    /* Clock select bits: Div. by 64 clock enabled with pin low level */
    PACTL = 12;
    /* Timer output compare */
    OC7M = 128;
    /* Output Compare Select Timer 7 */
    TIOS = 128;
    /* Define an output associated OC7 */
    TCTL1 = 192;
    /* Enable toggle output compare pin */
    TTOV = 128;
    /* Enable Hardware interrupt request */
    TSCR2 = 136;
    /* Enable Output Compare */
    TFLG1 = 255;
    /* Enable tim7 */
    TIE = 128;
    /* Set timer period */
    TC7 = (MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD;
    /* Enable timer */
    TSCR1 = 128;
#endif /* End defined(_MC9S12ZVC64_H) */
#endif /* End (defined(_MC9S12ZVMA_H)|| defined(_MC9S12VRP64_H) || defined(_MC9S12VRP48_H)) */
#endif /* End (defined(_MC9S12ZVML128_H) || defined(_MC9S12ZVL32_H) || defined(_MC9S12ZVML31_H)) */
#endif /* End defined(_MC9S12I32_H) */

}

#endif /* End (_MCU_ == _S12_) */

/* ----------------------------------------------------------------- */

#if (_MCU_ == _S08_)
void lin_lld_timer_S08_init (void)
{
#if defined(_MC9S08RN60_H)
    /* Stop timer */
    MTIM0_SC = 0x10;
    /* Initialize appropriate value to the compare/modulo/reload register */
    MTIM0_MOD = 0xFE;
    /* Set pre-scaler */
    MTIM0_CLK = 0x05;
    /* Reset HW Counter and run timer */
    MTIM0_SC = 0x60;
#else
    /* Configures the TPM to generate a periodic interrupt of 500us */
    /* (Interrupt on channel 0)    */
    /* clear prescaler and disable the timer */
    TPM1SC = 0x00;

    /* clear interrupt flag and disable interrupt channel;
    channel performs output compare with not using pin */
    TPM1C0SC = 0x50;

    /* set maximum modulo value */
    TPM1C0V = TPM1MOD = (MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD;
    TPM1CNTH = 0x00;
    /* enable timer and select the TPM clock source*/
    TPM1SC = 0x08;
#endif /*End defined(_MC9S08RN60_H)*/
}
#endif /* End (_MCU_ == _S08_) */

#ifdef MULTI_TIMER_MODE
void lin_lld_timer_isr(l_u8 index)
{
    /* Timeout for SCI channel */
    lin_lld_sci_timeout(lin_virtual_ifc[index]);
    /*** Master task firing ***/
}
#else /* Else MULTI_TIMER_MODE */
void lin_lld_timer_isr(void)
{
#if LIN_MODE == _MASTER_MODE_
    l_u8 i;
    /* Timeout for SCI channel */
    for(i=0; i<LIN_NUM_OF_IFCS; i++)
    {
        lin_lld_sci_timeout(lin_virtual_ifc[i]);
    }
    /*** Master task firing ***/
#else
    lin_lld_sci_timeout();
#endif /* End LIN_MODE == _MASTER_MODE_ */
}
#endif /* End MULTI_TIMER_MODE */

/**
* @}
*/
