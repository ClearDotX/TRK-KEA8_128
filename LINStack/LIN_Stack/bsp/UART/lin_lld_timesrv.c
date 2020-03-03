/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup UART_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      bsp/UART/lin_lld_timesrv.c
*
* @author    FPT Software
*
* @brief     Timer for KEA
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 * 2014   v1.0  First version for Kinetis timer handler
 *
 *****************************************************************************/

#include "lin_lld_timesrv.h"
#include "lin_lld_uart.h"
#include "lin_common_proto.h"
#include "lin_hw_cfg.h"


void lin_lld_timer_K_init
(
    void
)
{
#if !defined(MCU_SKEAZN84) /* Not cover for KEA8 platform */

    /* Enable Clock for FTM1 */
    SIM_SCGC |= SIM_SCGC_FTM1_MASK;
    /* Select Timer Prescale equal to 128 */
    FTM1_SC |= FTM_SC_PS(7);
    /* Enable Channle 0 */
    /* Enable channel 0 interrupt */
    FTM1_C0SC |= FTM_CnSC_CHIE_MASK;
    /* Channel as Output compare mode */
    FTM1_C0SC |= FTM_CnSC_MSA_MASK;
    /* Interrupt every TIME_BASE_PERIOD (us) */
    FTM1_C0V = FTM_CnV_VAL((MCU_BUS_FREQ /1000000.0) * (TIME_BASE_PERIOD / 128.0));
    /* FTM1 use system clock */
    FTM1_SC |= FTM_SC_CLKS(1);

    /* Set the ICPR and ISER registers accordingly */
    NVIC_ICPR |= 1 << ((INT_FTM1-16)%32);
    NVIC_ISER |= 1 << ((INT_FTM1-16)%32);
#endif /*!defined(MCU_SKEAZN84) Not cover for KEA8 platform */
}
#ifdef MULTI_TIMER_MODE
void lin_lld_timer_isr(l_u8 index)
{
    /* Timeout for UART channel */
    lin_lld_uart_timeout(lin_virtual_ifc[index]);
    /*** Master task firing ***/
}
#else /* Else MULTI_TIMER_MODE */
void lin_lld_timer_isr(void)
{
#if LIN_MODE == _MASTER_MODE_
    l_u8 i;
    /* Timeout for UART channel */
    for (i = 0; i < LIN_NUM_OF_IFCS; i++)
    {
        lin_lld_uart_timeout(lin_virtual_ifc[i]);
    }
    /*** Master task firing ***/
#else
    lin_lld_uart_timeout();
#endif /* End LIN_MODE == _MASTER_MODE_ */
}
#endif /* End MULTI_TIMER_MODE */

/**
 * @}
 */
