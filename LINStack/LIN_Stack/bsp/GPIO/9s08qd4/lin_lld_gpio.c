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
* @file      lin_lld_gpio.c
*
* @author    FPT Software
*
* @brief     Low level GPIO functions and data
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 *
 * 20090422     v1.0    First version
 *
 *****************************************************************************/


#include <hidef.h> /* for EnableInterrupts macro */
#include "lin_cfg.h"
#include "lin_common_proto.h"
#include "lin_lld_gpio.h"
#include "timer.h"

/* External variables */
extern l_u8           lin_current_pid;
extern l_u16          time_out;

/* Global variables */
/**
* @var lin_lld_gpio_state gpio_state
* GPIO state
* @var l_u8 byte_send_count
* send bytes count
 */
lin_lld_gpio_state      gpio_state = GPIO_WAIT_BREAK;
l_u8                    byte_send_count;

/* Static variables */
/**
* @var static l_u16 bit_time
* bit time
 */
static l_u16 bit_time; /**< 1/4 us */
static l_u8 raw_pid = 0;  /**< raw pid */
/**
* @var static l_u16 gu8P1
* gu8P1
 */
static l_u8 gu8P1;
/**
* @var static l_u16 gu8P0
* gu8P0
 */
static l_u8 gu8P0;
/**
* @var static l_u16 gu8Parity
* parity
 */
static l_u8 gu8Parity;          /**< Check parity */
static l_u8 bit_count;          /**< bit counter */
static l_u8 byte_to_send;       /**< byte to send */
static l_u8 no_byte_send;       /**< number of bytes to send */
static l_u8 bit_send;           /**< bit send */
static l_u8 direction;          /**< direction */
static l_u8 *buffer = &raw_pid; /**< buffer pointer */
static l_u8 error;              /**< error */

void lin_lld_gpio_init()
{
    /* Init keyboard */
    KBIES = 0x00;
    KBIPE |= KBIPE_KBIPE2_MASK;
    KBISC |= KBISC_KBIE_MASK;
    PTAPE |= PTAPE_PTAPE2_MASK;
    KBISC |= KBISC_KBACK_MASK;  /* Clear Pending Keyboard Interrupts */

    /* Set PIN direction */
    TX_PIN_DATA = 1;
    TX_PIN_DIRECT = 1;

    bit_time = (l_u16)(4000000UL/LIN_BAUD_RATE);

    /* Init timer */
    timer_init();
    timer2_init();
    start_timer2();
} /* End of lin_lld_gpio_init() */

void lin_lld_gpio_deinit()
{
    /* Disable interrupt */
    kbd_dis_int();
    /* stop timers */
    stop_timer();
    stop_timer2();
} /* end of lin_lld_gpio_deinit() */

l_u8 lin_lld_gpio_get_status()
{
    return (l_u8)gpio_state;
} /* end of lin_lld_gpio_get_status() */

void lin_lld_gpio_ignore_response()
{
    time_out = 400;
    gpio_state = GPIO_WAIT_BREAK;
    KBISC |= KBISC_KBACK_MASK;
    kbd_ena_int();
} /* End of lin_lld_gpio_ignore_response() */

static void wait_response()
{
    bit_count = 0;
    kbd_dis_int();
    timer_init();
    timer_ena_int();
}

static void enable_keyboard_interrupt()
{
    stop_timer();
    KBISC |= KBISC_KBACK_MASK;
    kbd_ena_int();
}

static void wait_field(lin_lld_gpio_state current_state, lin_lld_gpio_state next_state, l_u8 no_bit_time)
{
    if (current_state == gpio_state)
    {
        if (0 == RX_PIN_DATA)
        {
            bit_count++;
            if (bit_count >= no_bit_time)
            {
                /* valid field */
                /* Wait synch field */
                gpio_state = next_state;
                TPM2CNTH = 0;
                enable_keyboard_interrupt();
            }
        }
        else
        {
            enable_keyboard_interrupt();
            bit_count = 0;
        }
    }
}

static void check_timeout()
{
    time_out = 400;
    gpio_state = GPIO_WAIT_BREAK;
}


void lin_lld_gpio_tx_wake_up()
{
    gpio_state = GPIO_SEND_WAKEUP;
    TX_PIN_DATA = 0;
    wait_response();
} /* End of lin_lld_gpio_tx_wake_up() */

void lin_lld_gpio_tx_response()
{
    l_u8 tmp_len;
    kbd_dis_int();
    tmp_len = lin_lld_response_buffer[0]+1;
    /* Calculate checksum to send */
    lin_lld_response_buffer[tmp_len] = lin_checksum(lin_lld_response_buffer, raw_pid);
    /* Set bus is high */
    TX_PIN_DATA = 1;
    /* stop timer */
    stop_timer();
    /* Set period of timer equal bit time */
    TPMMOD = bit_time;
    /* init bit count and byte count */
    error = 0;
    bit_count = 0;
    bit_send = 0;
    no_byte_send = tmp_len+1;
    byte_send_count = 1;
    byte_to_send = lin_lld_response_buffer[1];
    direction = TRANSMIT_DATA;
    /* start timer to send data */
    timer_init();
    timer_ena_int();
}
void lin_lld_gpio_rx_response
(   /* [IN]: Number of data will receive */
    l_u8 response_length
)
{
    lin_lld_response_buffer[0] = response_length;
    no_byte_send = response_length+1;
    byte_send_count = 1;
    TPM2CNTH = 0;
    gpio_state = GPIO_WAIT_RESPONSE;
    buffer = lin_lld_response_buffer+1;
    KBISC_KBACK = 1;    /* Clear kbd-interrupt */
    kbd_ena_int();
}/* End of lin_lld_gpio_rx_response() */

interrupt VectorNumber_Vtpm1ovf void tpm1_isr(void)
{
    /**************************/
    /* to send wakeup */
    /**************************/
    if (GPIO_SEND_WAKEUP == gpio_state)
    {
        /* send 5 bit times */
        bit_count++;
        if (5 < bit_count)
        {
            TX_PIN_DATA = 0;
            time_out = 400;
            gpio_state = GPIO_WAIT_BREAK;
        }
    }

    /**************************/
    /* to receive break */
    /**************************/
    wait_field(GPIO_WAIT_BREAK, GPIO_WAIT_SYNC, 11);

    /**************************/
    /* to receive wakeup */
    /**************************/
    wait_field(GPIO_WAIT_WAKEUP, GPIO_WAIT_BREAK, 5);

    /*****************************/
    /* to receive data */
    /*****************************/
    if (RECEIVE_DATA == direction )
    {
        /* check STOP BIT */
        if (8 == bit_count)
        {
            if (RX_PIN_DATA == 0)
            {
                /* have Framing error */
                CALLBACK_HANDLER(LI0, LIN_LLD_FRAME_ERR, lin_current_pid);
                time_out = 400;
                gpio_state = GPIO_WAIT_BREAK;
                enable_keyboard_interrupt();
            }
            else
            {

                /*****************************/
                /* to receive synch field */
                /*****************************/
                if (GPIO_WAIT_SYNC == gpio_state)
                {
                    /* check synch byte */
                    if (0x55 == (*buffer))
                    {
                        /* valid synch field */
                        gpio_state = GPIO_WAIT_PID;
                        TPM2CNTH = 0;
                        buffer = &raw_pid;
                    }
                    else
                    {
                        gpio_state = GPIO_WAIT_BREAK;
                    }
                    enable_keyboard_interrupt();
                }
                else

                    /*****************************/
                    /* to receive pid field */
                    /*****************************/
                    if (GPIO_WAIT_PID == gpio_state)
                    {
                        lin_current_pid = raw_pid & 0x3F;
                        if (gu8Parity)
                        {
                            /* invalid pid */
                            stop_timer();
                            CALLBACK_HANDLER(LI0, LIN_LLD_PID_OK, lin_current_pid);
                        }
                        else
                        {
                            /* valid pid */
                            CALLBACK_HANDLER(LI0, LIN_LLD_PID_ERR, lin_current_pid);
                            time_out = 400;
                            gpio_state = GPIO_WAIT_BREAK;
                            enable_keyboard_interrupt();
                        }
                    }
                    else

                        /*****************************/
                        /* to receive response */
                        /*****************************/
                        if (GPIO_WAIT_RESPONSE == gpio_state)
                        {
                            /* receive next byte */
                            bit_count = 0;
                            /* check receive is complete? */
                            if (byte_send_count++ == no_byte_send)
                            {
                                if (lin_checksum(&lin_lld_response_buffer[0], raw_pid) == lin_lld_response_buffer[no_byte_send])
                                {
                                    /* call back to upper layer event RX_COMPLETE */
                                    CALLBACK_HANDLER(LI0, LIN_LLD_RX_COMPLETED, lin_current_pid);
                                    if (GPIO_WAIT_WAKEUP != gpio_state)
                                    {
                                        time_out = 400;
                                        gpio_state = GPIO_WAIT_BREAK;
                                        enable_keyboard_interrupt();
                                    }
                                }
                                else
                                {
                                    /* call back to upper layer event CHECKSUM_ERR */
                                    CALLBACK_HANDLER(LI0, LIN_LLD_CHECKSUM_ERR, lin_current_pid);
                                    time_out = 400;
                                    gpio_state = GPIO_WAIT_BREAK;
                                    enable_keyboard_interrupt();
                                }
                            }
                            else
                            {
                                /* send next byte */
                                bit_count = 0;
                                buffer++;
                                TPM2CNTH = 0;
                                gpio_state = GPIO_WAIT_RESPONSE;
                                enable_keyboard_interrupt();
                            }
                        }
            }
        }
        else
        {
            bit_send = RX_PIN_DATA;
            *buffer >>= 0x01;
            if (bit_send)
            {
                *buffer |= 0x80;
            }
            /*****************************/
            /* check pid parity */
            /*****************************/
            if (GPIO_WAIT_PID == gpio_state)
            {
                TPMMOD = bit_time;
                if ( bit_count == 0 || bit_count == 1 || bit_count == 2 || bit_count == 4)
                {
                    /* Calculate 1st gu8Parity bit =
                     *
                     *  gu8P0 = (ID0)XOR(ID1)XOR(ID2)XOR(ID4)
                     */
                    if (bit_send)
                    {
                        gu8P0++;
                    }
                }


                if (bit_count == 1 || bit_count == 3 || bit_count == 4 || bit_count == 5)
                {
                    /* Calculate 2nd gu8Parity bit =
                     *      ______________________________
                     *  gu8P1 = (ID1)XOR(ID3)XOR(ID4)XOR(ID5)
                     */
                    if (bit_send)
                    {
                        gu8P1++;
                    }
                }

                if ( bit_count == 6)
                    if (bit_send == (gu8P0&0x01))
                    {
                        gu8Parity = 0x01 ;
                    }

                if ( bit_count == 7)
                {

                    if ( bit_send != (gu8P1&0x01))
                    {
                        gu8Parity &= 0x01;
                    }
                    else
                    {
                        gu8Parity = 0;
                    }
                }
            }
            bit_count++;
        }
    }
    /**************************/
    /* to send response frame */
    /**************************/
    if (TRANSMIT_DATA == direction)
    {
        /* check have readback error in previous bit */
        if (1 == error)
        {
            TX_PIN_DATA = 1;
            CALLBACK_HANDLER(LI0, LIN_LLD_READBACK_ERR, lin_current_pid);
            time_out = 400;
            gpio_state = GPIO_WAIT_BREAK;
            KBIES = 0;
            enable_keyboard_interrupt();
        }
        else
        {
            kbd_dis_int();
            /* Get bit to send */
            if (10 == bit_count)
            {
                /* prepare to send next byte */
                byte_send_count++;
                bit_count = 0;
                /* check send all of bytes */
                if (byte_send_count == no_byte_send)
                {
                    CALLBACK_HANDLER(LI0, LIN_LLD_TX_COMPLETED, lin_current_pid);
                    KBIES = 0;
                    time_out = 400;
                    gpio_state = GPIO_WAIT_BREAK;
                    enable_keyboard_interrupt();
                }
                else
                {
                    byte_to_send = lin_lld_response_buffer[byte_send_count];
                    bit_send = 0;
                }
            }
            else
            {
                if ((9 == bit_count))
                {
                    /* Send stop bit */
                    TX_PIN_DATA = 1;
                }
                else
                {
                    TX_PIN_DATA = bit_send;
                }
                /* set to wait edge interrupt */
                /* if bit_send = 1, wait falling interrupt */
                /* if bit_send = 0, wait rising interrupt */
                KBIES_KBEDG2 = 1 - TX_PIN_DATA;
                bit_send = byte_to_send & 0x01;
                byte_to_send >>= 1;
                bit_count++;
                gpio_state = GPIO_CHECK_BIT_ERROR;
                KBISC |= KBISC_KBACK_MASK;
                kbd_ena_int();
            }
        }
    }
    /* clear interrupt */
    TPMSC_TOF = 0;
}

interrupt VectorNumber_Vkeyboard1 void kbi_isr(void)
{
    if (GPIO_CHECK_BIT_ERROR == gpio_state)
    {
        /* have readback error */
        error = 1;
    }
    else
    {
        switch (gpio_state)
        {
            /* Receive response */
            case GPIO_WAIT_RESPONSE:
            /* Receive synch byte */
            case GPIO_WAIT_SYNC:
                TPMMOD = bit_time;
                direction = RECEIVE_DATA;
                break;
            /* Receive pid byte */
            case GPIO_WAIT_PID:
                gu8P1 = 0;
                gu8P0 = 0;
                gu8Parity = 0;
                direction = RECEIVE_DATA;
                TPMMOD = bit_time-40;
                break;
            /* Receive break signal */
            case GPIO_WAIT_BREAK:
            /* Receive wakeup signal */
            case GPIO_WAIT_WAKEUP:
                TPMMOD = bit_time;
                direction = RECEIVE_SIGNAL;
                break;
            /* Receive wakeup signal */
            default:
                /* Clear Pending Keyboard Interrupts */
                KBISC_KBACK = 1;
                break;
        }
        wait_response();
    }
} /* end of kbi_isr() */

/**
 * @}
 */
