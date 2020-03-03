/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup 9s08el32_group
* @details This MCU supports one SLIC interface.
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      slic_isr.c
*
* @author    FPT Software
*
* @brief     SLIC interrupt routines
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 *
 * 20090427     v1.0    First version
 *
 *****************************************************************************/

#include "MC9S08EL32.h"
#include "slic_isr.h"
#include "lin.h"
#include "lin_common_proto.h"
#include "lin_lld_slic.h"
#include "lin_lld_timesrv.h"

extern lin_driver_status lin_slic_status;
extern l_u8 lin_current_pid;

/**
* @var l_u16 lin_idle_timeout
* To calculate time to set driver go to sleep
 */
l_u16 lin_idle_timeout; /* To calculate time to set driver go to sleep */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void copy_from_buffer ( )
* @brief This function copies data from SLIC buffer to driver buffer.
*
* @return #void
*
* @SDD_ID LIN_SDD_147
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>*buffer_ptr</I>
*   -# <B>#l_u8</B> <I>i</I>
*
* @static_global_var
*   -# <B>#lin_lld_response_buffer</B>
*
* @details
*   This function copies data from SLIC buffer to driver buffer.
*
*//*END*----------------------------------------------------------------------*/
static void copy_from_buffer()
{
    l_u8 i, *buffer_ptr = (l_u8*)&(SLCD0);

    lin_lld_response_buffer[0] = SLCDLC_DLC+1;
    for (i = 0; i < lin_lld_response_buffer[0]; i++)
    {
        lin_lld_response_buffer[i+1] = *buffer_ptr;
        buffer_ptr++;
    }
}

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void slic_isr ( )
* @brief The SLIC interrupt service routine
*
*
* @return #void
*
* @SDD_ID LIN_SDD_148
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>temp_SLCSV</I>
*
* @static_global_var
*   -# <B>#lin_slic_status</B>
*   -# <B>#lin_current_pid</B>
*   -# <B>#lin_idle_timeout</B>
*
* @details
*   The SLIC interrupt service routine
*
* @see  #lin_lld_slic_set_low_power_mode
* @see  #clear_slic_int_flag
* @see  #copy_from_buffer
*//*END*----------------------------------------------------------------------*/
interrupt VectorNumber_Vslic void slic_isr (void)
{
    l_u8 temp_SLCSV;

    /* Read SLCSV register */
    temp_SLCSV = SLCSV;

    switch (temp_SLCSV)
    {

        /***** NO INTERRUPT PENDING *****/
        case NO_INTERRUPT_PENDING:
            break;
        /***** NO BUS ACTIVITY *****/
        case NO_BUS_ACTIVITY:
            if (LIN_LLD_OPERATIONAL == lin_slic_status)
            {
                CALLBACK_HANDLER(0, LIN_LLD_NODATA_TIMEOUT, lin_current_pid);
                lin_slic_status = LIN_LLD_IDLE;
            }
            /* calculate idle time */
            else
            {
                lin_idle_timeout--;
                if (0 == lin_idle_timeout)
                {
                    lin_lld_slic_set_low_power_mode();
                }
            }
            /* Clear interrupt flag */
            clear_slic_int_flag();
            break;
        /***** TRANSMIT EMPTY, CHECKSUM OK *****/
        case TX_EMPTY_CHK_TRANS:
            /* Clear interrupt flag */
            clear_slic_int_flag();
            /* Callback to upper layer */
            CALLBACK_HANDLER(0, LIN_LLD_TX_COMPLETED, lin_current_pid);
            /* Set state of driver is IDLE */
            lin_slic_status = LIN_LLD_IDLE;
            break;
        /***** RECEIVE FULL, CHECKSUM OK *****/
        case RX_FULL_CHK_OK:
            /* Copy data from SLIC buffer to driver buffer */
            copy_from_buffer();
            /* Callback to upper layer */
            CALLBACK_HANDLER(0, LIN_LLD_RX_COMPLETED, lin_current_pid);
            /* Set state of driver is IDLE */
            if (LIN_LLD_LOW_POWER_MODE != lin_slic_status )
            {
                lin_slic_status = LIN_LLD_IDLE;
            }
            /* Clear interrupt flag */
            clear_slic_int_flag();
            break;
        /***** READBACK ERROR *****/
        case BIT_ERROR:
            /* Callback to upper layer */
            CALLBACK_HANDLER(0, LIN_LLD_READBACK_ERR, lin_current_pid);
            /* Set state of driver is IDLE */
            lin_slic_status = LIN_LLD_IDLE;
            /* Clear interrupt flag */
            clear_slic_int_flag();
            break;
        /***** CHECKSUM ERROR *****/
        case CHECKSUM_ERROR:
            /* Callback to upper layer */
            CALLBACK_HANDLER(0, LIN_LLD_CHECKSUM_ERR, lin_current_pid);
            /* Set state of driver is IDLE */
            lin_slic_status = LIN_LLD_IDLE;
            /* Clear interrupt flag */
            clear_slic_int_flag();
            break;
        /***** BYTE FRAMING ERROR *****/
        case BYTE_FRAMING_ERROR:
            if  (LIN_LLD_OPERATIONAL == lin_slic_status)
            {
                /* Callback to upper layer */
                CALLBACK_HANDLER(0, LIN_LLD_FRAME_ERR, lin_current_pid);
                /* Set state of driver is IDLE */
                lin_slic_status = LIN_LLD_IDLE;
            }
            /* Clear interrupt flag */
            clear_slic_int_flag();
            break;
        /***** RECEIVED SUCCESSFULLY PID *****/
        case IDENTIFIER_RECEIVED_SUC:
            /* Set state of driver is OPERATIONAL */
            lin_slic_status = LIN_LLD_OPERATIONAL;
            lin_idle_timeout = LIN_IDLE_TIMEOUT;
            /* Callback to upper layer */
            lin_current_pid = (SLCID & 0x3F);
            clear_slic_int_flag();
            CALLBACK_HANDLER(0, LIN_LLD_PID_OK, lin_current_pid);
            break;
        /***** RECEIVED PID, PARITY ERROR *****/
        case IDENTIFIER_PARITY_ERROR:
            /* Callback to upper layer */
            CALLBACK_HANDLER(0, LIN_LLD_PID_ERR, lin_current_pid);
            /* Set state of driver is IDLE */
            lin_slic_status = LIN_LLD_IDLE;
            /* Clear interrupt flag */
            clear_slic_int_flag();
            break;
        /***** RECEIVED WAKEUP SIGNAL *****/
        case WAKEUP:
            /* Set state of driver is IDLE */
            lin_slic_status = LIN_LLD_IDLE;
            /* Reset the LIN IDLE TIMEOUT counter */
            lin_idle_timeout = LIN_IDLE_TIMEOUT;
            /* Clear interrupt flag */

            clear_slic_int_flag();
            SLCC1_SLCIE = 1;
            break;
        default:
            lin_slic_status = LIN_LLD_IDLE;
            clear_slic_int_flag();
            break;
    } /* End of Switch */
}

#define ISR(ivn, x) interrupt ivn void x(void)
ISR(VectorNumber_Vtpm1ch0, TPM1_TIMER_ISR)
{
    /* CH0F = 0 */
    TPM1C0SC &= ~TPM1C0SC_CH0F_MASK;
    lin_lld_timer_isr();
}
/**
 * @}
 */
