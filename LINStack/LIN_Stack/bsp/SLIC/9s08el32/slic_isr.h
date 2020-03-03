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
* @file      slic_isr.h
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
 * 20090407     v1.0    First version
 *
 *****************************************************************************/

#ifndef SLIC_ISR_H
#define SLIC_ISR_H

#define _TEST_RECEIVE_RESPONSE_ 0       /**< Test receive response */

#define _TEST_SEND_RESPONSE_    0       /**< Test send response */


#define clear_slic_int_flag() SLCS |= 0x01 /**< Clear SLIC interrupt flag */

#define  NO_INTERRUPT_PENDING     0x00      /**< No interrupt pendding */

#define  NO_BUS_ACTIVITY          0x04      /**< No bus activity */

#define  TX_EMPTY_CHK_TRANS       0x08      /**< Tx empty check transmit */

#define  TX_BUFFER_EMPTY          0x0C      /**< Tx buffer empty */

#define  RX_FULL_CHK_OK           0x10      /**< Rx full check ok */

#define  RX_FULL_NO_ERR           0x14      /**< Rx full no error */

#define  BIT_ERROR                0x18      /**< Bit error */

#define  RECEIVE_BUFFER_OVERRUN   0x1C      /**< Receive buffer overrun */

#define  RESERVED1                0x20      /**< Reserved 1 */

#define  CHECKSUM_ERROR           0x24      /**< Check sum */

#define  BYTE_FRAMING_ERROR       0x28      /**< Byte framing error */

#define  IDENTIFIER_RECEIVED_SUC  0x2C      /**< Indentifier recevied suc */

#define  IDENTIFIER_PARITY_ERROR  0x30      /**< Indentifier parity error */

#define  RESERVED2                0x34      /**< Reserved 2 */

#define  RESERVED3                0x38      /**< Reserved 3 */

#define  WAKEUP                   0x3c      /**< Wake up */

void timer_init(void);
extern interrupt VectorNumber_Vrtc  void timer_isr(void);
extern interrupt VectorNumber_Vslic  void SLIC_ISR(void);
#endif

/**
* @}
*/