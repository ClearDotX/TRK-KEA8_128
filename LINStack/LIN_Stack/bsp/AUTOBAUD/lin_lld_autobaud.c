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
* @file      lin_lld_autobaud.c
*
* @author    FPT Software
*
* @brief    Functions for Autobaud feature
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 *
 * 20101027     v1.0    First version
 *
 *****************************************************************************/


#include "lin.h"
#include "lin_hw_cfg.h"
#if(defined NUM_OF_SCI_CHANNEL)
#include "lin_lld_sci.h"
#endif
#if(defined NUM_OF_UART_CHANNEL)
#include "lin_lld_uart.h"
#endif
#include "lin_common_proto.h"
#include "lin_lld_timesrv.h"
#include "lin_cfg.h"
#include "lin_lld_autobaud.h"

l_u16       autobaud_tmr_capture[6];
l_u8        autobaud_tmr_capture_index = 0;
l_u16       autobaud_current = 19200;


l_u16 lin_max_frame_res_timeout_val_autobaud[8];

#if (defined(_MC9S12VR64_H) || defined(_MC9S12VR32_H) || defined(_MC9S12VRP64_H)||defined(_MC9S12VRP48_H))
/* inline definition for CW classic 5.1 */
#pragma INLINE
l_u16 lin_calc_max_res_timeout_cnt(l_u16 baudRate, l_u8 size)
#else
/* inline definition for CW 10.6 */
inline l_u16 lin_calc_max_res_timeout_cnt(l_u16 baudRate, l_u8 size)
#endif
{
    return (l_u16) ((14*(1+size)*(1000000/TIME_BASE_PERIOD))/(baudRate) + 3 );
}

void autobaud_init(void)
{
    l_u8 i;
    /* disconnect IOC0_3 from TIM0 input capture channel 3 and reroute the timer input to the RXD0 signal of SCI0. */
    /* T0IC3RR1:T0IC3RR0 */
#if (defined(_MC9S12ZVL32_H) || defined(_MC9S12ZVL128_H))
    MODRR4 = 0x1;
    /* disabled edge for capture */
    TIM0TCTL4_EDG3x = 0U;
    /* Clear interrupt  flag */
    TIM0TFLG1 = TIM0TFLG1_C3F_MASK;
    /* Disable interrupt */
    TIM0TIE_C3I = 0U;
    /* Channel 3 is configure for capture */
    TIM0TIOS_IOS3 = 0;
    /* Set prescaler register Bus Clock / 1 */
    TIM0TSCR2_PR = 0x00;
    /* TSCR1: TEN = 0, TSWAI = 0, TSFRZ = 1, TFFCA = 0, PRNT = 1 */
    TIM0TSCR1 = 0x28;
    /* Clear interrupt  flag */
    TIM0TFLG1 = TIM0TFLG1_C3F_MASK;
    /* Enable interrupt from timer capture */
    TIM0TIE_C3I = 1U;
    /* TSCR1: TEN = 1 */
    TIM0TSCR1 |= 0x80U;
    /* Disbale LIN Timer capture for SYNC byte */
    TIM0TCTL4_EDG3x = 0U;
#endif /* (defined(_MC9S12ZVL32_H) || defined(_MC9S12ZVL128_H)) */

#if defined(_MC9S12ZVH128_H)
    /* TIM1 input capture channel 0 is connected to RXD0 */
    MODRR2 = 0x2;
    /* disabled edge for capture */
    TIM1TCTL4_EDG0x = 0U;
    /* Clear interrupt  flag */
    TIM1TFLG1 = TIM1TFLG1_C0F_MASK;
    /* Disable interrupt */
    TIM1TIE_C0I = 0U;
    /* Channel 3 is configure for capture */
    TIM1TIOS_IOS0 = 0;
    /* Set prescaler register Bus Clock / 1 */
    TIM1TSCR2_PR = 0x00;
    /* TSCR1: TEN = 0, TSWAI = 0, TSFRZ = 1, TFFCA = 0, PRNT = 1 */
    TIM1TSCR1 = 0x28;
    /* Clear interrupt  flag */
    TIM1TFLG1 = TIM1TFLG1_C0F_MASK;
    /* Enable interrupt from timer capture */
    TIM1TIE_C0I = 1U;
    /* TSCR1: TEN = 1 */
    TIM1TSCR1 |= 0x80U;
    /* Disable LIN Timer capture for SYNC byte */
    TIM1TCTL4_EDG0x = 0U;
#endif /* (defined(_MC9S12ZVH128_H)) */

#if (defined(_MC9S12ZVML128_H) || defined(_MC9S12ZVML31_H))
    /* TIM0 input capture channel 3 is connected to RXD0 */
    MODRR2_T0IC3RR = 0x1;
    /* disabled edge for capture */
    TIM0TCTL4_EDG3x = 0U;
    /* Clear interrupt  flag */
    TIM0TFLG1 = TIM0TFLG1_C3F_MASK;
    /* Disable interrupt */
    TIM0TIE_C3I = 0U;
    /* Channel 3 is configure for capture */
    TIM0TIOS_IOS3 = 0;
    /* Set prescaler register Bus Clock / 1 */
    TIM0TSCR2_PR = 0x00;
    /* TSCR1: TEN = 0, TSWAI = 0, TSFRZ = 1, TFFCA = 0, PRNT = 1 */
    TIM0TSCR1 = 0x28;
    /* Clear interrupt  flag */
    TIM0TFLG1 = TIM0TFLG1_C3F_MASK;
    /* Enable interrupt from timer capture */
    TIM0TIE_C3I = 1U;
    /* TSCR1: TEN = 1 */
    TIM0TSCR1 |= 0x80U;
    TIM0TCTL4_EDG3x = 0U;
#endif /* End if (defined(_MC9S12ZVML128_H) || defined(_MC9S12ZVML31_H)) */

#if defined(_MC9S12ZVMC256_H)
    /* TIM0 input capture channel 3 is connected to RXD1 */
    MODRR2_T0IC3RR = 0x2;
    /* disabled edge for capture */
    TIM0TCTL4_EDG3x = 0U;
    /* Clear interrupt  flag */
    TIM0TFLG1 = TIM0TFLG1_C3F_MASK;
    /* Disable interrupt */
    TIM0TIE_C3I = 0U;
    /* Channel 3 is configure for capture */
    TIM0TIOS_IOS3 = 0;
    /* Set prescaler register Bus Clock / 1 */
    TIM0TSCR2_PR = 0x00;
    /* TSCR1: TEN = 0, TSWAI = 0, TSFRZ = 1, TFFCA = 0, PRNT = 1 */
    TIM0TSCR1 = 0x28;
    /* Clear interrupt  flag */
    TIM0TFLG1 = TIM0TFLG1_C3F_MASK;
    /* Enable interrupt from timer capture */
    TIM0TIE_C3I = 1U;
    /* TSCR1: TEN = 1 */
    TIM0TSCR1 |= 0x80U;
    /* Disable LIN Timer capture for SYNC byte */
    TIM0TCTL4_EDG3x = 0U;
#endif /* End if (defined(_MC9S12ZVMC256_H)) */

#if (defined(_MC9S12VR64_H) || defined(_MC9S12VR32_H))

    /* TIM0 input capture channel 3 is connected to RXD0 */
    MODRR2_MODRR27 = 0x1;
    /* disabled edge for capture */
    TCTL4_EDG3x = 0U;
    /* Clear interrupt  flag */
    TFLG1 = TFLG1_C3F_MASK;
    /* Disable interrupt */
    TIE_C3I = 0U;
    /* Channel 3 is configure for capture */
    TIOS_IOS3 = 0;
    /* Set prescaler register Bus Clock / 1 */
    TSCR2_PR = 0x00;
    /* TSCR1: TEN = 0, TSWAI = 0, TSFRZ = 1, TFFCA = 0, PRNT = 1 */
    TSCR1 = 0x28;
    /* Clear interrupt  flag */
    TFLG1 = TFLG1_C3F_MASK;
    /* Enable interrupt from timer capture */
    TIE_C3I = 1U;
    /* TSCR1: TEN = 1 */
    TSCR1 |= 0x80U;
    /* Diable LIN Timer capture for SYNC byte */
    TCTL4_EDG3x = 0U;
#endif /* End if (defined(_MC9S12VR64_H) || defined(_MC9S12VR32_H)) */

#if (defined(_MC9S12VRP64_H) || defined(_MC9S12VRP48_H))
    /* TIM1 input capture channel 1 is connected to RXD0 */
    MODRR2_MODRR27 = 0x1;
    /* Disable interrupt */
    TIM1TIE_C1I = 0U;
    /* Channel 1 is configure for capture */
    TIM1TIOS_IOS1 = 0;
    /* Set prescaler register Bus Clock / 1 */
    TIM1TSCR2_PR = 0x00;
    /* Clear interrupt  flag */
    TIM1TFLG1 = TIM1TFLG1_C1F_MASK;
    /* Enable interrupt from timer capture */
    TIM1TIE_C1I = 1U;
    /* TSCR1: TEN = 1, TSWAI = 0, TSFRZ = 1, TFFCA = 0, PRNT = 1 */
    TIM1TSCR1 = 0xA8;
    /* Disable LIN Timer capture for SYNC byte */
    TIM1TCTL4_EDG1x = 0U;
#endif /* End if (defined(_MC9S12VRP64_H) || defined(_MC9S12VRP48_H)) */

#if (defined(_MC9S12ZVMA_H))
    /* TIM1 input capture channel 1 is connected to RXD0 */
    MODRR3_T1IC1RR = 0x1;
    /* disabled edge for capture */
    TIM1TCTL4_EDG1x = 0U;
    /* Clear interrupt  flag */
    TIM1TFLG1 = TIM1TFLG1_C1F_MASK;
    /* Disable interrupt */
    TIM1TIE_C1I = 0U;
    /* Channel 1 is configure for capture */
    TIM1TIOS_IOS1 = 0;
    /* Set prescaler register Bus Clock / 1 */
    TIM1TSCR2_PR = 0x00;
    /* TSCR1: TEN = 0, TSWAI = 1, TSFRZ = 1, TFFCA = 0, PRNT = 1 */
    TIM1TSCR1 = 0x28;
    /* Clear interrupt  flag */
    TIM1TFLG1 = TIM1TFLG1_C1F_MASK;
    /* Enable interrupt from timer capture */
    TIM1TIE_C1I = 1U;
    /* TSCR1: TEN = 1 */
    TIM1TSCR1 |= 0x80U;
    /* Disable LIN Timer capture for SYNC byte */
    TIM1TCTL4_EDG1x = 0U;
#endif /* End if (defined(_MC9S12ZVMA_H)) */

#if (defined(_MC9S12ZVMB_H))
    /* TIM0 input capture channel 3 is connected to RXD0 */
    MODRR3_T0IC3RR = 0x1;
    /* disabled edge for capture */
    TIM0TCTL4_EDG3x = 0U;
    /* Clear interrupt  flag */
    TIM0TFLG1 = TIM0TFLG1_C3F_MASK;
    /* Disable interrupt */
    TIM0TIE_C3I = 0U;
    /* Channel 3 is configure for capture */
    TIM0TIOS_IOS3 = 0;
    /* Set prescaler is 1 */
    TIM0TSCR2_PR = 0x00;
    /* TSCR1: TEN = 0, TSWAI = 1, TSFRZ = 1, TFFCA = 0, PRNT = 1*/
    TIM0TSCR1 = 0x28;
    /* Clear interrupt  flag */
    TIM0TFLG1 = TIM0TFLG1_C3F_MASK;
    /* Enable interrupt from timer capture */
    TIM0TIE_C3I = 1U;
    /* TSCR1: TEN = 1 */
    TIM0TSCR1 |= 0x80U;
    /* Disable LIN Timer capture for SYNC byte */
    TIM0TCTL4_EDG3x = 0U;
#endif /* End if (defined(_MC9S12ZVMB_H)) */

#if ((defined(MCU_SKEAZ1284)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)))
    /* Enable Clock for FTM1 */
	SIM_SCGC |= SIM_SCGC_FTM0_MASK;
	/* Select Timer Prescale equal to 0*/
	FTM0_SC |= FTM_SC_PS(0);
	/* FTM0 use system clock */
	FTM0_SC |= FTM_SC_CLKS(1);

	/* Set the ICPR and ISER registers accordingly */
	NVIC_ICPR |= 1 << ((INT_FTM0-16)%32);
	NVIC_ISER |= 1 << ((INT_FTM0-16)%32);

    /* TIM0 input capture channel 1 is connected to UART0 */
#if defined(MCU_SKEAZ1284)
    SIM_SOPT0 |= SIM_SOPT0_RXDCE_MASK;
#elif ((defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)))
    SIM_SOPT |= SIM_SOPT_RXDCE_MASK;
#endif

    /* Set TIM0 channel to input capture mode */
    FTM0_SC &= (~FTM_SC_CPWMS_MASK);
    FTM0_C1SC = (FTM0_C1SC & FTM_CnSC_CHIE_MASK) | FTM_CnSC_ELSB_MASK | FTM_CnSC_CHIE_MASK;
#endif /* End if (defined(_MC9S12ZVMB_H)) */

    for (i = 0; i < 8; i++)
    {
        lin_max_frame_res_timeout_val_autobaud[i] = lin_calc_max_res_timeout_cnt(autobaud_current, i+1);
    }

}

/* End of File */

/**
 * @}
 */

