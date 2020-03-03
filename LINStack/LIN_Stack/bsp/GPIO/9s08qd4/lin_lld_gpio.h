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
* @file      lin_lld_gpio.h
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

#ifndef _LIN_LLD_GPIO_H_
#define _LIN_LLD_GPIO_H_

#include "MC9S08QD4.h"

#define TRANSMIT_DATA        1         /**< transmitting data */
#define RECEIVE_DATA         0         /**< receving data */
#define RECEIVE_SIGNAL       2         /**< receving signal */

#define GPIO_STOP_BIT_ERROR -1         /**< GPIO stop bit error */
#define GPIO_OK 0                      /**< GPIO ok */

#define kbd_dis_int() KBISC_KBIE = 0;  /**< Disable Interrupt KB */
#define kbd_ena_int() KBISC_KBIE = 1;  /**< Enable Interrupt KB */
#define ADJUSTMENT    30               /**< used for setting input value of the counter (1/4us) */

#define lin_lld_gpio_int_enable() kbd_ena_int()    /**< LIN GPIO interrupt enable */
#define lin_lld_gpio_int_disable() kbd_dis_int()   /**< LIN GPIO interrupt disable */

/**
* @enum lin_lld_gpio_state
* all state of GPIO driver
*/
typedef enum {
    GPIO_WAIT_BREAK,      /**< GPIO wait break field */
    GPIO_WAIT_RESPONSE,   /**< GPIO wait response */
    GPIO_WAIT_RESPONSE1,  /**< GPIO wait response */
    GPIO_WAIT_PID,        /**< GPIO wait PID */
    GPIO_WAIT_SYNC,       /**< GPIO wait sync field */
    GPIO_WAIT_WAKEUP,     /**< GPIO wait wakeup signal */
    GPIO_SEND_WAKEUP,     /**< GPIO send wakeup signal */
    GPIO_CHECK_BIT_ERROR  /**< GPIO check bit error */
} lin_lld_gpio_state;

#define lin_lld_gpio_set_low_power_mode() gpio_state = GPIO_WAIT_WAKEUP  /**< Define function lin_lld_gpio_set_low_power_mode() for gpio_state */
extern lin_lld_gpio_state    gpio_state; /**< GPIO State */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_gpio_get_status (  )
* @brief This function deinitialization module
*
* @return #void
*
* @static_global_var
*   -# <B>#gpio_state</B>
*
* @SDD_ID LIN_SDD_151
* @endif
*
* @details
*   This function deinitialization module
*
*//*END*----------------------------------------------------------------------*/


l_u8 lin_lld_gpio_get_status(void);
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_gpio_init (  )
* @brief This function performs the initialization of the GPIO hardware
*
* @return #void
*
* @SDD_ID LIN_SDD_149
* @endif
*
* @static_global_var
*   -# <B>#bit_time</B>
*
* @details
*   This function performs the initialization of the GPIO hardware
*
* @see  #timer_init
* @see  #timer2_init
* @see  #start_timer2
*//*END*----------------------------------------------------------------------*/

void lin_lld_gpio_init (void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_gpio_deinit (  )
* @brief This function deinitialization module
*
* @return #void
*
* @SDD_ID LIN_SDD_150
* @endif
*
* @details
*   This function deinitialization module
*
* @see  #kbd_dis_int
* @see  #stop_timer
* @see  #stop_timer2
*//*END*----------------------------------------------------------------------*/

void lin_lld_gpio_deinit (void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_gpio_tx_wake_up ( )
* @brief This function transmits wakeup signal
*
* @return #void
*
* @SDD_ID LIN_SDD_152
* @endif
*
* @static_global_var
*   -# <B>#time_out</B>
*   -# <B>#gpio_state</B>
*
* @details
*   This function transmits wakeup signal
*
* @see  #lin_lld_gpio_send_byte
*//*END*----------------------------------------------------------------------*/
void lin_lld_gpio_tx_wake_up (void);


/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_gpio_ignore_response ( )
* @brief This function ignores next response
*
* @return #void
*
* @SDD_ID LIN_SDD_153
* @endif
*
* @static_global_var
*   -# <B>#gpio_state</B>
*
* @details
*   This function ignores next response
*
* @see  #lin_lld_gpio_send_byte
*//*END*----------------------------------------------------------------------*/
void lin_lld_gpio_ignore_response(void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_gpio_tx_response ( )
* @brief This function sets SLIC module to low power mode
*
* @return #void
*
* @SDD_ID LIN_SDD_155
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>i</I>
*   -# <B>#l_u8</B> <I>tmp_len</I>
*   -# <B>#l_u8</B> <I>send_error</I>
*
* @static_global_var
*   -# <B>#lin_lld_response_buffer</B>
*   -# <B>#bit_time</B>
*   -# <B>#lin_current_pid</B>
*   -# <B>#gpio_state</B>
*
* @details
*   This function sets SLIC module to low power mode
*
* @see  #lin_checksum
* @see  #lin_lld_gpio_send_byte
*//*END*----------------------------------------------------------------------*/
void lin_lld_gpio_tx_response (void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void lin_lld_gpio_rx_response (l_u8 response_length)
* @brief This function sets SLIC module to low power mode
*
* @param response_length <B>[IN]</B>  Number of data will receive
*
* @return #void
*
* @SDD_ID LIN_SDD_156
* @endif
*
* @static_global_var
*   -# <B>#lin_lld_response_buffer</B>
*   -# <B>#byte_receive</B>
*   -# <B>#byte_count</B>
*   -# <B>#gpio_state</B>
*
* @details
*   This function sets SLIC module to low power mode
*
* @see  #start_timer2
*//*END*----------------------------------------------------------------------*/
void lin_lld_gpio_rx_response (l_u8 response_length);

interrupt VectorNumber_Vkeyboard1 void  kbi_isr(void);

#endif /* End of _LIN_LLD_GPIO_H_ */
/**
* @}
*/
