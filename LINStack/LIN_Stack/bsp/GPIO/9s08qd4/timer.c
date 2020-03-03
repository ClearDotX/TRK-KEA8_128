/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup 9s08qd4_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      timer.c
*
* @author    FPT Software
*
* @brief     Timer for GPIO interface
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 *
 * 20090422     v1.0    First version
 *
 *****************************************************************************/

#include "timer.h"
#include "MC9S08QD4.h"
#include "lin.h"
#include "lin_lld_gpio.h"
#include "lin_common_proto.h"

/************************************************************************/
/*****************           VARIABLES           ************************/
/************************************************************************/
extern l_u8 byte_send_count;
extern lin_lld_gpio_state   gpio_state;
extern l_u8 lin_current_pid;
/**
* @var l_u16 time_out
* time out is 4 seconds
 */
l_u16                       time_out = 400; /* wait for 4 seconds */
/************************************************************************/
/*****************           FUNCTIONS           ************************/
/************************************************************************/

/********************************************************/
/*****************    Functions for timer 2   ***********/
/********************************************************/

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void timer2_isr ( )
* @brief The function calculate timeout for driver
*
*
* @return #void
*
* @SDD_ID LIN_SDD_166
* @endif
*
*
* @static_global_var
*   -# <B>#gpio_state</B>
*   -# <B>#time_out</B>
*   -# <B>#byte_receive</B>
*   -# <B>#lin_current_pid</B>
*
* @details
*   The function calculate timeout for driver
*
* @see  #lin_lld_gpio_set_low_power_mode
* @see  #start_timer2
 *//* END*----------------------------------------------------------------------*/
interrupt VectorNumber_Vtpm2ovf void timer2_isr()
{
    switch (gpio_state)
    {
        case GPIO_WAIT_BREAK:
            /* Check Bus No Activity */
            if (0 == (time_out--))
            {
                /* Change state to low power mode */
                lin_lld_gpio_set_low_power_mode();
                /* Callback time out activity */
                CALLBACK_HANDLER(LI0, LIN_LLD_BUS_ACTIVITY_TIMEOUT, lin_current_pid);
            }
            break;
        /* Check No Data Time Out */
        case GPIO_WAIT_RESPONSE:
            if (byte_send_count > 1)
            {
                CALLBACK_HANDLER(LI0, LIN_LLD_NODATA_TIMEOUT, lin_current_pid);
            }
        case GPIO_WAIT_SYNC:
        case GPIO_WAIT_PID:
            time_out = 400;
            gpio_state = GPIO_WAIT_BREAK;
            start_timer2();
            break;
        default:
            break;
    }
    TPM2SC_TOF = 0;
}

void start_timer2()
{
    TPM2CNTH = 0;
    TPM2SC_TOF = 0;
    TPM2SC_TOIE = 1;
    TPM2SC |= 0x0D;
}


/**
 * @}
 */
