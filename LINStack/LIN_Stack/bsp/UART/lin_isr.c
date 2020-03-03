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
* @file      bsp/UART/lin_isr.c
*
* @author    FPT Software
*
* @brief     Interrupt service routine used in LIN driver
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 *
 * 20140422     v1.0    First version for KEA family support
 *
 *****************************************************************************/

#include "lin_hw_cfg.h"
#include "lin_lld_timesrv.h"
#include "lin_lld_uart.h"

#if AUTOBAUD == 1 /* AUTOBAUD feature applicible for S12Z MCU family*/
#include "lin_lld_autobaud.h"

extern l_u16 lin_max_frame_res_timeout_val_autobaud[8];
volatile l_bool stop_flag = 0;
l_u16 dTbit[5] = {0};

#endif /* End (1==AUTOBAUD) */
/**********************************************************************************************
* Local functions
**********************************************************************************************/
#if _UART0_ == 1
void UART0_SCI0_IRQHandler ();
/***********************************************************************************************
*
* @brief    UART0_SCI0_IRQHandler - Uart0 reception interrupt, calls the user defined callback function
* @param    none
* @return   none
*
************************************************************************************************/
void UART0_SCI0_IRQHandler ()
{
#if (LIN_MODE == _MASTER_MODE_)
    lin_lld_uart_rx_isr(LINUART0);
#else
    lin_lld_uart_rx_isr();
#endif /* (LIN_MODE == _MASTER_MODE_) */

}
#endif /* end _UART0_ == 1 */

#if _UART1_ == 1
void UART1_SCI1_IRQHandler ();
/***********************************************************************************************
*
* @brief    UART1_SCI1_IRQHandler - Uart1 reception interrupt, calls the user defined callback function
* @param    none
* @return   none
*
************************************************************************************************/
void UART1_SCI1_IRQHandler ()
{
#if (LIN_MODE == _MASTER_MODE_)
    lin_lld_uart_rx_isr(LINUART1);
#else
    lin_lld_uart_rx_isr();
#endif /* (LIN_MODE == _MASTER_MODE_) */

}
#endif /* end _UART1_ == 1 */

#if _UART2_ == 1
void UART2_SCI2_IRQHandler ();
/***********************************************************************************************
*
* @brief    UART2_SCI2_IRQHandler - Uart2 reception interrupt, calls the user defined callback function
* @param    none
* @return   none
*
************************************************************************************************/
void UART2_SCI2_IRQHandler ()
{
#if (LIN_MODE == _MASTER_MODE_)
    lin_lld_uart_rx_isr(LINUART2);
#else
    lin_lld_uart_rx_isr();
#endif /* (LIN_MODE == _MASTER_MODE_) */

}
#endif /* end _UART2_ == 1 */

/***********************************************************************************************
*
* @brief    FTM2_IRQHandler - Interrupt for FTM channels, clear flag, set new tiemout and execute callback
* @param    none
* @return   none
*
************************************************************************************************/
#if !defined(MCU_SKEAZN84) /* Not support for KEA8 */
void FTM1_IRQHandler();
void FTM1_IRQHandler()
{
    if (1 == ((FTM1_C0SC & FTM_CnSC_CHF_MASK) >> FTM_CnSC_CHF_SHIFT))  /* If the CHF of the channel is equal to 0 */
    {
        (void)FTM1_C0SC;                            /* Read to clear flag */
        /* Clear flag */
        FTM1_C0SC ^= FTM_CnSC_CHF_MASK;
        /* Update Value of Channel Value register to generate next interrupt after TIME_BASE_PERIOD (us) */
        FTM1_C0V += ((MCU_BUS_FREQ  / 1000000.0) * (TIME_BASE_PERIOD / 128.0));
        /* Call Timer interrupt handler function */
        lin_lld_timer_isr();
    }
}
#endif /*!defined(MCU_SKEAZN84) */

#if (AUTOBAUD == 1)
void AutobaudTimerValEval(void)
{
    l_u8 i;

    if ((0 == stop_flag) && (autobaud_tmr_capture_index  < 5))
    {

        autobaud_tmr_capture[autobaud_tmr_capture_index]=TIMER_CNT_REG;
        /* Calculate 2xTbit time for the second and later capture */
        if (autobaud_tmr_capture_index > 0)
        {
            i = autobaud_tmr_capture_index - 1;
            dTbit[i] = autobaud_tmr_capture[i+1] - autobaud_tmr_capture[i];
            /* Check if 2xTbit time satisfy valid conditions:
             * 1. The following 2xTbit must be +/-14% of the 2xTbit right before it
             * 2. And it is in the acceptable ranges of master baud rate of 19200 bps or 9600 bps
             */
            if ((dTbit[i] < DBIT_DURATION_MIN_19200) ||
                ((dTbit[i] > DBIT_DURATION_MAX_19200) && (dTbit[i] < DBIT_DURATION_MIN_9600)) ||
                (dTbit[i] > DBIT_DURATION_MAX_9600))
            {
                stop_flag = 1;
                /* Disable interrupt from timer channel */
                lin_goto_idle_state();
                return;
            }else
            {
                if (i > 0)
                {
                    if ((dTbit[i] < ((100 - BIT_RATE_TOLERANCE_UNSYNC) * (dTbit[i-1] / 100))) || (dTbit[i] > ((100 + BIT_RATE_TOLERANCE_UNSYNC) * (dTbit[i-1] / 100))))
                    {
                        stop_flag = 2;
                        /* Disable interrupt from timer channel */
                        lin_goto_idle_state();
                        return;
                    }
                }
            }
        }
         autobaud_tmr_capture_index ++;
    }
    /* Adjust the baud rate if there is no error in SYNC BYTE */
    if ((autobaud_tmr_capture_index > 4) && (stop_flag == 0))
    {
        /* Disable interrupt from timer channel */
        TIMER_INT_ENA(0);
        if (dTbit[i] >= DBIT_DURATION_MIN_9600)
        {
            autobaud_current = 9600;
        }
        lin_lld_uart_init_autobaud(autobaud_current);
        stop_flag = 3;
    }
    return;
}

void FTM0_IRQHandler()
{
	/* input capture happend in FTM0 channel 1 */
	if (1 == ((FTM0_C1SC & FTM_CnSC_CHF_MASK) >> FTM_CnSC_CHF_SHIFT))
	{
		(void)FTM0_C1SC;                            /* Read to clear flag */
		/* Clear flag */
		FTM0_C1SC &= (~FTM_CnSC_CHF_MASK);
		/* Clear interrupt flag */
		AutobaudTimerValEval();
	}
}
#endif

