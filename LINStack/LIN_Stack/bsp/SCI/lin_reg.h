/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup SCI_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      bsp/SCI/lin_reg.h
*
* @author    FPT Software
*
* @brief     SCI register definition on S08, S12, S12X
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 *
 * 20101027     v1.0    First version
 *
 *****************************************************************************/

#ifndef LIN_REG_H
#define LIN_REG_H

#include "lin_hw_cfg.h"

/*************************************/
/******   Common Register struct *****/
/*************************************/

/**
* @var typedef unsigned char tU08
* unsigned 8 bits definition
*/
typedef unsigned char   tU08;   /**< unsigned 8 bit definition */

/**
* @var typedef unsigned char tU16
* unsigned 16 bits definition
*/
typedef unsigned short    tU16;   /**< unsigned 16 bit definition */

/**
* @var typedef unsigned long tU32
* unsigned 32 bits definition
*/
typedef unsigned long   tU32;   /**< unsigned 32 bit definition */

/**
* @var typedef unsigned char tS08
* signed 32 bits definition
*/
typedef signed char     tS08;   /**< signed 8 bit definition */

/**
* @var typedef signed int      tS16
* signed 16 bits definition
*/
typedef signed short      tS16;   /**< signed 16 bit definition */

/**
* @var typedef signed long      tS32
* signed 32 bits definition
*/
typedef signed long     tS32;   /**< signed 32 bit definition */

#if (!defined(_MC9S12ZVML128_H) && !defined(_MC9S12ZVML31_H))
#pragma MESSAGE DISABLE C1106 /**< WARNING C1106: Non-standard bitfield type */
#endif /* End if (!defined(_MC9S12ZVML128_H) && !defined(_MC9S12ZVML31_H)) */

/**
* @var uREG08 tREG08
* register 8 bits
*/

/**
* @union uREG08
* register 8 bits
*/
typedef union uREG08        /**< 8 bit register with byte and bit access*/
{
    tU08  byte;               /**< access whole register e.g. var.byte   = 0xFF;*/
    struct
    {
        tU08 _0 :1; /**< bit 0 */
        tU08 _1 :1; /**< bit 1 */
        tU08 _2 :1; /**< bit 2 */
        tU08 _3 :1; /**< bit 3 */
        tU08 _4 :1; /**< bit 4 */
        tU08 _5 :1; /**< bit 5 */
        tU08 _6 :1; /**< bit 6 */
        tU08 _7 :1; /**< bit 7 */
    } bit;      /**< access bit at a time  e.g. var.bit._7 = 1;   */
} tREG08;


/**
* @var uREG16 tREG16
* register 16 bits
*/

/**
* @union uREG16
* register 16 bits
*/
typedef union uREG16        /**< 16 bit register with word and byte access*/
{
    tU16 word;                /**< access whole word */
    struct
    {
        tREG08 msb;             /**< msb byte */
        tREG08 lsb;             /**< lsb byte */
    } byte;                 /**< access byte at a time */
} tREG16;

/*************************************/
/*******   SCI Register struct *******/
/*************************************/

#if (SCI_VERSION == SCI_V2)
/**
* @var uSCIBDH tSCIBDH
* SCI baurate high register
*/
/**
* @union uSCIBDH
* SCI baurate high register
*/
typedef union uSCIBDH
{
    tU08 byte;                /**< access register as byte */
    struct
    {
        tU08 sbr8  :1; /**< msb baud rate select bits: bit 8 */
        tU08 sbr9  :1; /**< msb baud rate select bits: bit 9 */
        tU08 sbr10 :1; /**< msb baud rate select bits: bit 10 */
        tU08 sbr11 :1; /**< msb baud rate select bits: bit 11 */
        tU08 sbr12 :1; /**< msb baud rate select bits: bit 12 */
        tU08        :1; /**< bit reserved area */
        tU08        :1; /**< bit reserved area */
        tU08        :1; /**< bit reserved area */
    } bit;            /**< access register as bits */
} tSCIBDH;
#endif /* End (SCI_VERSION == SCI_V2) */

#if (SCI_VERSION == SCI_V4)
/**
* @union tSCIBDH
* SCI baud rate higher byte
*/
typedef union  uSCIBDH
{
    tU08 byte;                /**< access register as byte */
    struct
    {
        tU08 sbr8  :1;          /**< msb baud rate select bits: bit 8 */
        tU08 sbr9  :1;          /**< msb baud rate select bits: bit 9 */
        tU08 sbr10 :1;          /**< msb baud rate select bits: bit 10 */
        tU08 sbr11 :1;          /**< msb baud rate select bits: bit 11 */
        tU08 sbr12 :1;          /**< msb baud rate select bits: bit 12 */
        tU08        :1;         /**< bit reserved area */
        tU08 rxegie :1;         /**< RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        tU08 lbkdie :1;         /**< LIN Break Detect Interrupt Enable (for LBKDIF) */
    } bit;                    /**< access register as bits */
} tSCIBDH;
#endif /* End (SCI_VERSION == SCI_V4) */

#if (SCI_VERSION == SCI_V5)
/**
* @var uSCIBDH tSCIBDH
*/
/**
* @union uSCIBDH
* SCI Baud Rate Register
*/
typedef union uSCIBDH
{
    tU08   byte;              /**< access register as byte */
    struct
    {
        tU08 sbr8   :1;         /**< msb baud rate select bits: bit 8 */
        tU08 sbr9   :1;         /**< msb baud rate select bits: bit 9 */
        tU08 sbr10  :1;         /**< msb baud rate select bits: bit 10 */
        tU08 sbr11  :1;         /**< msb baud rate select bits: bit 11 */
        tU08 sbr12  :1;         /**< msb baud rate select bits: bit 12 */
        tU08 tnp    :2;         /**< transmit narrow pulse */
        tU08 iren   :1;         /**< IRDA enable */
    } bit;                    /**< access register as bits */
    struct                    /**< alternate bits for SCIASR1 */
    {
        tU08 bkdif  :1;         /**< break detect interrupt flag */
        tU08 berrif :1;         /**< bit error interrupt flag   */
        tU08 berrv  :1;         /**< bit error value */
        tU08        :4;         /**< bit reserved area */
        tU08 rxedgif:1;         /**< receive input active edge interrupt flag */
    } abit;                   /**< alternate bits for SCIBDH */
} tSCIBDH;
#endif /* End (SCI_VERSION == SCI_V5) */

#if (SCI_VERSION == SCI_V6)
/**
* @var uSCIBDH tSCIBDH
*/
/**
* @union uSCIBDH
* SCI Baud Rate Register
*/
typedef union uSCIBDH
{
    tU08   byte;        /**< access register as byte */
    struct
    {
        tU08 sbr8   :1;     /**< msb baud rate select bits: bit 8 */
        tU08 sbr9   :1;     /**< msb baud rate select bits: bit 9 */
        tU08 sbr10  :1;     /**< msb baud rate select bits: bit 10 */
        tU08 sbr11  :1;     /**< msb baud rate select bits: bit 11 */
        tU08 sbr12  :1;     /**< msb baud rate select bits: bit 12 */
        tU08 sbr13  :1;     /**< msb baud rate select bits: bit 13 */
        tU08 sbr14  :1;     /**< msb baud rate select bits: bit 14 */
        tU08 sbr15  :1;     /**< msb baud rate select bits: bit 15 */
    } bit;          /**< access register as bits */
    struct                  /**< alternate bits for SCIASR1 */
    {
        tU08 bkdif  :1;       /**< break detect interrupt flag */
        tU08 berrif :1;       /**< bit error interrupt flag   */
        tU08 berrv  :1;       /**< bit error value */
        tU08        :4;       /**< bit reserved area */
        tU08 rxedgif:1;       /**< receive input active edge interrupt flag */
    } abit;         /**< alternate bits for SCIBDH */
} tSCIBDH;
#endif /* End (SCI_VERSION == SCI_V6) */

#if ((SCI_VERSION != SCI_V5) && (SCI_VERSION != SCI_V6))
/**
* @union tSCIBDL
* SCI baud rate lower byte
*/
typedef union uSCIBDL
{
    tU08 byte;                /**< access register as byte */
    struct
    {
        tU08 sbr0  :1;          /**< lsb baud rate select bits: bit 0 */
        tU08 sbr1  :1;          /**< lsb baud rate select bits: bit 1 */
        tU08 sbr2  :1;          /**< lsb baud rate select bits: bit 2 */
        tU08 sbr3  :1;          /**< lsb baud rate select bits: bit 3 */
        tU08 sbr4  :1;          /**< lsb baud rate select bits: bit 4 */
        tU08 sbr5  :1;          /**< lsb baud rate select bits: bit 5 */
        tU08 sbr6  :1;          /**< lsb baud rate select bits: bit 6 */
        tU08 sbr7  :1;          /**< lsb baud rate select bits: bit 7 */
    } bit;                    /**< access register as bits */
} tSCIBDL;

#else
typedef union uSCIBDL
{
    tU08 byte;                /**< access register as byte */
    struct
    {
        tU08 sbr0  :1;          /**< lsb baud rate select bits: bit 0 */
        tU08 sbr1  :1;          /**< lsb baud rate select bits: bit 1 */
        tU08 sbr2  :1;          /**< lsb baud rate select bits: bit 2 */
        tU08 sbr3  :1;          /**< lsb baud rate select bits: bit 3 */
        tU08 sbr4  :1;          /**< lsb baud rate select bits: bit 4 */
        tU08 sbr5  :1;          /**< lsb baud rate select bits: bit 5 */
        tU08 sbr6  :1;          /**< lsb baud rate select bits: bit 6 */
        tU08 sbr7  :1;          /**< lsb baud rate select bits: bit 7 */
    } bit;                    /**< access register as bits */
    struct
    {
        tU08 bkdie  :1;         /**< break detect interrupt enable */
        tU08 berrie :1;         /**< bit error interrupt enable */
        tU08        :5;         /**< bit reserved area */
        tU08 rxedgie:1;         /**< receive input active edge interrupt enable */
    } abit;                   /**< alternate bits for SCIBDL */
} tSCIBDL;
#endif /* End (SCI_VERSION != SCI_V5 && SCI_VERSION != SCI_V6) */

#if (SCI_VERSION == SCI_V6)
/**
* @var uSCICR1 tSCICR1
*/
/**
* @union uSCICR1
* SCI Control Register 1
*/
typedef union uSCICR1
{
    tU08   byte;        /**< access register as byte */
    struct
    {
        tU08 pt      :1;      /**< parity type */
        tU08 pe      :1;      /**< parity enable   */
        tU08 ilt     :1;      /**< idle line type */
        tU08 wake    :1;      /**< wake up by address mark/idle */
        tU08 m       :1;      /**< mode select */
        tU08 rsrc    :1;      /**< receiver source */
        tU08 sciswai :1;      /**< stop in wait mode  */
        tU08 loops   :1;      /**< loop mode/single wire mode enable */
    } bit;          /**< access register as bits */
    struct
    {
        tU08 bkdfe   :1;      /**< break detect feature enable */
        tU08 berrm0  :1;      /**< bit error mode */
        tU08 berrm1  :1;      /**< bit error mode */
        tU08         :2;      /**< bit reserved area */
        tU08 tnp     :2;      /**< transmit narrow pulse */
        tU08 iren    :1;      /**< IRDA enable */
    } abit;         /**< alternate bits for SCIACR1 */
} tSCICR1;
#elif (SCI_VERSION == SCI_V5)
/**
* @var uSCICR1 tSCICR1
*/
/**
* @union uSCICR1
* SCI Control Register 1
*/
typedef union uSCICR1
{
    tU08   byte;        /**< access register as byte */
    struct
    {
        tU08 pt      :1;      /**< parity type */
        tU08 pe      :1;      /**< parity enable   */
        tU08 ilt     :1;      /**< idle line type */
        tU08 wake    :1;      /**< wake up by address mark/idle */
        tU08 m       :1;      /**< mode select */
        tU08 rsrc    :1;      /**< receiver source */
        tU08 sciswai :1;      /**< stop in wait mode  */
        tU08 loops   :1;      /**< loop mode/single wire mode enable */
    } bit;          /**< access register as bits */
    struct
    {
        tU08 bkdfe   :1;      /**< break detect feature enable */
        tU08 berrm0  :1;      /**< bit error mode */
        tU08 berrm1  :1;      /**< bit error mode */
        tU08         :5;      /**< bit reserved area */
    } abit;         /**< alternate bits for SCIACR1 */
} tSCICR1;
#else   /* SCI V2 and V4 */
/**
* @union tSCICR1
* SCI control register 1
*/
typedef union uSCICR1
{
    tU08  byte;               /**< access register as byte */
    struct
    {
        tU08 pt      :1;        /**< parity type */
        tU08 pe      :1;        /**< parity enable */
        tU08 ilt     :1;        /**< idle line type */
        tU08 wake    :1;        /**< wake up by address mark/idle */
        tU08 m       :1;        /**< mode select */
        tU08 rsrc    :1;        /**< receiver source */
        tU08 sciswai :1;        /**< stop in wait mode  */
        tU08 loops   :1;        /**< loop mode/single wire mode enable */
    } bit;                    /**< access register as bits */
} tSCICR1;
#endif /* End (SCI_VERSION == SCI_V6) */

/**
* @var uSCICR2 tSCICR2
*/
/**
* @union uSCICR2
* * SCI Control Register 2
*/
typedef union uSCICR2
{
    tU08   byte;              /**< access register as byte */
    struct
    {
        tU08 sbk   :1;          /**< send break character */
        tU08 rwu   :1;          /**< receiver wake-up control */
        tU08 re    :1;          /**< receiver enable */
        tU08 te    :1;          /**< transmitter enable */
        tU08 ilie  :1;          /**< idle line interrupt enable */
        tU08 rie   :1;          /**< receiver interrupt enable   */
        tU08 tcie  :1;          /**< transmit complete interrupt enable */
        tU08 tie   :1;          /**< transmit interrupt enable   */
    } bit;                    /**< access register as bits */
} tSCICR2;

/**
* @var uSCISR1 tSCISR1
*/
/**
* @union uSCISR1
* SCI Status Register 1
*/
typedef union uSCISR1
{
    tU08   byte;              /**< access register as byte */
    struct
    {
        tU08 pf    :1;          /**< parity error flag  */
        tU08 fe    :1;          /**< framing error flag */
        tU08 nf    :1;          /**< noise error flag */
        tU08 orf   :1;          /**< overrun error flag - 'or' in specification */
        tU08 idle  :1;          /**< idle line detected flag */
        tU08 rdrf  :1;          /**< receive data register full flag */
        tU08 tc    :1;          /**< transmit complete flag */
        tU08 tdre  :1;          /**< transmit data register empty flag */
    } bit;                    /**< access register as bits */
} tSCISR1;

#if (SCI_VERSION == SCI_V2)
/**
* @var uSCISR2 tSCISR2
* SCI status register 2
*/
/**
* @union uSCISR2
* SCI status register 2
*/
typedef union uSCISR2
{
    tU08 byte;                /**< access register as byte */
    struct
    {
        tU08 raf      :1;       /**< receiver active flag */
        tU08          :1;       /**< bit reserved area */
        tU08 brk13    :1;       /**< break character length */
        tU08          :1;       /**< bit reserved area */
        tU08          :1;       /**< bit reserved area */
        tU08          :1;       /**< bit reserved area */
        tU08          :1;       /**< bit reserved area */
        tU08          :1;       /**< bit reserved area */
    } bit;                    /**< access register as bits */
} tSCISR2;
#endif /* End (SCI_VERSION == SCI_V2) */

#if (SCI_VERSION == SCI_V4)
/**
* @var uSCISR2 tSCISR2
* SCI status register 2
*/
/**
* @union uSCISR2
* SCI status register 2
*/
typedef union uSCISR2
{
    tU08 byte;                /**< access register as byte */
    struct
    {
        tU08 raf    :1;         /**< receiver active flag */
        tU08 lbkde  :1;         /**< LIN Break Detection Enable */
        tU08 brk13  :1;         /**< Break Character Generation Length */
        tU08 rwuid  :1;         /**< Receive Wake Up Idle Detect */
        tU08 rxinv  :1;         /**< Receive Data Inversion */
        tU08        :1;         /**< bit reserved area */
        tU08 rxedgif:1;         /**< RxD Pin Active Edge Interrupt Flag */
        tU08 lbkdif :1;         /**< LIN Break Detect Interrupt Flag */
    } bit;                    /**< access register as bits */
} tSCISR2;
#endif /* End (SCI_VERSION == SCI_V4) */

#if ((SCI_VERSION == SCI_V5) || (SCI_VERSION == SCI_V6))
/**
* @var uSCISR2 tSCISR2
*/
/**
* @union uSCISR2
* SCI status register 2
*/
typedef union uSCISR2
{
    tU08   byte;              /**< access register as byte */
    struct
    {
        tU08 raf    :1;        /**< receiver active flag */
        tU08 txdir  :1;        /**< receiver active flag */
        tU08 brk13  :1;        /**< 13-bit break */
        tU08 rxpol  :1;        /**< receiver polarity */
        tU08 txpol  :1;        /**< transmitter polarity */
        tU08        :2;        /**< bit reserved area */
        tU08 amap   :1;        /**< alternate register map */
    } bit;                    /**< access register as bits */
} tSCISR2;
#endif /* End (SCI_VERSION == SCI_V5 || SCI_VERSION == SCI_V6) */

#if ((SCI_VERSION != SCI_V5) && (SCI_VERSION != SCI_V6))
/**
* @var uSCICR3 tSCICR3
*/
/**
* @union uSCICR3
* SCI control register 3
*/
typedef union uSCICR3
{
    tU08 byte;                /**< access register as byte */
    struct
    {
        tU08 peie     :1;        /**< Parity Error Interrupt Enable */
        tU08 feie     :1;        /**< Framing Error Interrupt Enable */
        tU08 neie     :1;        /**< Noise Error Interrupt Enable */
        tU08 orie     :1;        /**< Overrun Interrupt Enable */
        tU08 txinv    :1;        /**< Transmit Data Inversion */
        tU08 txdir    :1;        /**< TxD Pin Direction in Single-Wire Mode */
        tU08 t8       :1;        /**< Ninth Data Bit for Transmitter */
        tU08 r8       :1;        /**< Ninth Data Bit for Receiver */
    } bit;                     /**< access register as bits */
} tSCICR3;

/**
* @var uSCID tSCID
*/
/**
* @union uSCID
* SCI data
*/
typedef union uSCID
{
    tU08   byte;              /**< access register as byte */
    struct
    {
        tU08 r0_t0 :1;          /**< Receive/Transmit Data Bit 0 */
        tU08 r1_t1 :1;          /**< Receive/Transmit Data Bit 1 */
        tU08 r2_t2 :1;          /**< Receive/Transmit Data Bit 2 */
        tU08 r3_t3 :1;          /**< Receive/Transmit Data Bit 3 */
        tU08 r4_t4 :1;          /**< Receive/Transmit Data Bit 4 */
        tU08 r5_t5 :1;          /**< Receive/Transmit Data Bit 5 */
        tU08 r6_t6 :1;          /**< Receive/Transmit Data Bit 6 */
        tU08 r7_t7 :1;          /**< Receive/Transmit Data Bit 7 */
    } bit;                    /**< access register as bits */
} tSCID;
#else
/**
* @var uSCIDRH tSCIDRH
*/
/**
* @union uSCIDRH
* SCI Data Register hight
*/
typedef union uSCIDRH
{
    tU08   byte;              /**< access register as byte */
    struct
    {
        tU08       :6;          /**< not used */
        tU08 t8    :1;          /**< transmit bit 8 */
        tU08 r8    :1;          /**< receive bit 8   */
    } bit;                    /**< access register as bits */
} tSCIDRH;
#endif /* End (SCI_VERSION != SCI_V5) */

#if ((SCI_VERSION != SCI_V5) && (SCI_VERSION != SCI_V6))
/**
* @struct tSCI
* SCI data structure
*/
typedef struct               /**< sci datastructure  */
{
    volatile tSCIBDH scibdh;   /**< sci baud rate high register  */
    volatile tSCIBDL scibdl;   /**< sci baud rate low register   */
    volatile tSCICR1 scicr1;   /**< sci control register 1       */
    volatile tSCICR2 scicr2;   /**< sci control register 2 */
    volatile tSCISR1 scisr1;   /**< sci status register 1 */
    volatile tSCISR2 scisr2;   /**< sci status register 2 */
    volatile tSCICR3 scicr3;   /**< sci control register 3 */
    volatile tSCID   scid;     /**< sci data register */
} tSCI;
#else /* SCI v5 and v6 */
/**
* @struct tSCI
* sci datastructure
*/
typedef struct                /**< sci datastructure  */
{
    volatile tSCIBDH  scibdh;   /**< sci baud rate high register / alternate status register */
    volatile tSCIBDL  scibdl;   /**< sci baud rate low register  / alternate control register 1 */
    volatile tSCICR1  scicr1;   /**< sci control register 1      / alternate control register 2 */
    volatile tSCICR2  scicr2;   /**< sci control register 2 */
    volatile tSCISR1  scisr1;   /**< sci status register 1 */
    volatile tSCISR2  scisr2;   /**< sci status register 2 */
    volatile tSCIDRH  scidrh;   /**< sci data register high */
    volatile tREG08   scidrl;   /**< sci data register low */
} tSCI;


#define sciasr1 scibdh        /**< SCI alternate status register */
#define sciacr1 scibdl        /**< SCI alternate control register 1 */
#define sciacr2 scicr1        /**< SCI alternate control register 2 */
#endif /* End (SCI_VERSION != SCI_V5) */

/*************************************/
/************ SCI Bit masks **********/
/*************************************/

/* SCIBH - SCI Baud Rate Register High */
#if (defined(_MC9S08DZ128_H)|| defined(_MM9Z1J638_H)||(SCI_VERSION == SCI_V4))
#ifndef SCIBDH_RXEDGIE_MASK
#define SCIBDH_RXEDGIE_MASK         64              /**< SCI baud rate register high bit mask: RxD input active edge interrupt enable */
#endif /* ifndef SCIBDH_RXEDGIE_MASK */

#ifndef SCIBDH_LBKDIE_MASK
#define SCIBDH_LBKDIE_MASK          128             /**< SCI baud rate register high bit mask: LIN break detected interrupt enable */
#endif /* ifndef SCIBDH_LBKDIE_MASK */
#endif /* End (SCI_VERSION == SCI_V4) */


/* SCIASR1 - SCI Alternative Status Register */
#if ((SCI_VERSION == SCI_V5) || (SCI_VERSION == SCI_V6))
#ifndef SCIASR1_BKDIF_MASK
#define SCIASR1_BKDIF_MASK          1               /**< SCI alternate status register 1 bit mask: break detect interrupt flag */
#endif /* ifndef SCIASR1_BKDIF_MASK */

#ifndef SCIASR1_BERRIF_MASK
#define SCIASR1_BERRIF_MASK         2               /**< SCI alternate status register 1 bit mask: bit error interrupt flag */
#endif /* ifndef SCIASR1_BERRIF_MASK */

#ifndef SCIASR1_BERRV_MASK
#define SCIASR1_BERRV_MASK          4               /**< SCI alternate status register 1 bit mask: bit error value */
#endif /* ifndef SCIASR1_BERRV_MASK */

#ifndef SCIASR1_RXEDGIF_MASK
#define SCIASR1_RXEDGIF_MASK        128             /**< SCI alternate status register 1 bit mask: receive input active interrupt flag */
#endif /* ifndef SCIASR1_RXEDGIF_MASK */

/* SCI0ACR1 - SCI Alternative Control Register 1 */
#ifndef SCIACR1_BKDIE_MASK
#define SCIACR1_BKDIE_MASK     1                    /**< SCI alternate control register 1 bit mask: break detect interrupt enable */
#endif /* ifndef SCIACR1_BKDIE_MASK */

#ifndef SCIACR1_BERRIE_MASK
#define SCIACR1_BERRIE_MASK    2                    /**< SCI alternate control register 1 bit mask: bit error interrupt enable */
#endif /* ifndef SCIACR1_BERRIE_MASK */

#ifndef SCIACR1_RXEDGIE_MASK
#define SCIACR1_RXEDGIE_MASK   128                  /**< SCI alternate control register 1 bit mask: receive input active edge interrupt enable */
#endif /* ifndef SCIACR1_RXEDGIE_MASK */
#endif /* End (SCI_VERSION == SCI_V5) */

/* SCICR1 - SCI Control Register 1 */
#if (SCI_VERSION == SCI_V2)
#ifndef SCICR1_PT_MASK
#define SCICR1_PT_MASK                1             /**< SCI control register 1 bit mask: parity type*/
#endif /* ifndef SCICR1_PT_MASK */

#ifndef SCICR1_PE_MASK
#define SCICR1_PE_MASK                2           /**< SCI control register 1 bit mask: parity enable*/
#endif /* ifndef SCICR1_PE_MASK */

#ifndef SCICR1_ILT_MASK
#define SCICR1_ILT_MASK               4           /**< SCI control register 1 bit mask: idle line type select*/
#endif /* ifndef SCICR1_ILT_MASK */

#ifndef SCICR1_WAKE_MASK
#define SCICR1_WAKE_MASK              8           /**< SCI control register 1 bit mask: receiver wakeup method select*/
#endif /* ifndef SCICR1_WAKE_MASK */

#ifndef SCICR1_M_MASK
#define SCICR1_M_MASK                 16              /**< SCI control register 1 bit mask: 8 bit or 9 bit mode select*/
#endif /* ifndef SCICR1_M_MASK */

#ifndef SCICR1_RSTC_MASK
#define SCICR1_RSTC_MASK              32              /**< SCI control register 1 bit mask: receiver source select*/
#endif /* ifndef SCICR1_RSTC_MASK */

#ifndef SCICR1_SCIWAI_MASK
#define SCICR1_SCIWAI_MASK            64              /**< SCI control register 1 bit mask: SCI stops in wait mode*/
#endif /* ifndef SCICR1_SCIWAI_MASK */

#ifndef SCICR1_LOOPS_MASK
#define SCICR1_LOOPS_MASK             128             /**< SCI control register 1 bit mask: loop mode select*/
#endif /* ifndef SCICR1_LOOPS_MASK */

#else
#ifndef SCICR1_PT_MASK
#define SCICR1_PT_MASK                1             /**< SCI control register 1 bit mask: parity type*/
#endif /* ifndef SCICR1_PT_MASK */

#ifndef SCICR1_PE_MASK
#define SCICR1_PE_MASK                2             /**< SCI control register 1 bit mask: parity enable*/
#endif /* ifndef SCICR1_PE_MASK */

#ifndef SCICR1_ILT_MASK
#define SCICR1_ILT_MASK               4             /**< SCI control register 1 bit mask: idle line type select*/
#endif /* ifndef SCICR1_ILT_MASK */

#ifndef SCICR1_WAKE_MASK
#define SCICR1_WAKE_MASK              8             /**< SCI control register 1 bit mask: receiver wakeup method select*/
#endif /* ifndef SCICR1_WAKE_MASK */

#ifndef SCICR1_M_MASK
#define SCICR1_M_MASK                 16            /**< SCI control register 1 bit mask: 8 bit or 9 bit mode select*/
#endif /* ifndef SCICR1_M_MASK */

#ifndef SCICR1_RSRC_MASK
#define SCICR1_RSRC_MASK              32            /**< SCI control register 1 bit mask: receiver source select*/
#endif /* ifndef SCICR1_RSRC_MASK */

#ifndef SCICR1_SCISWAI_MASK
#define SCICR1_SCISWAI_MASK           64            /**< SCI control register 1 bit mask: SCI stops in wait mode*/
#endif /* ifndef SCICR1_SCISWAI_MASK */

#ifndef SCICR1_LOOPS_MASK
#define SCICR1_LOOPS_MASK             128           /**< SCI control register 1 bit mask: loop mode select*/
#endif /* ifndef SCICR1_LOOPS_MASK */
#endif /* End (SCI_VERSION == SCI_V2) */


/* SCIACR2 - SCI Alternative Control Register 2 */
#if ((SCI_VERSION == SCI_V5) || (SCI_VERSION == SCI_V6))
#ifndef SCIACR2_BKDFE_MASK
#define SCIACR2_BKDFE_MASK         1                /**< SCI alternate control register 2: break detect feature enable */
#endif /* ifndef SCIACR2_BKDFE_MASK */

#ifndef SCIACR2_BERRM0_MASK
#define SCIACR2_BERRM0_MASK        2                /**< SCI alternate control register 2: bit error mode 0 */
#endif /* ifndef SCIACR2_BERRM0_MASK */

#ifndef SCIACR2_BERRM1_MASK
#define SCIACR2_BERRM1_MASK        4                /**< SCI alternate control register 2: bit error mode 1 */
#endif /* ifndef SCIACR2_BERRM1_MASK */

#ifndef SCIACR2_BERRM_MASK
#define SCIACR2_BERRM_MASK         6                /**< SCI alternate control register 2: bit error mode bit 0 and 1 is set */
#endif /* ifndef SCIACR2_BERRM_MASK */

#ifndef SCIACR2_BERRM_BITNUM
#define SCIACR2_BERRM_BITNUM       1              /**< SCI alternate control register 2: bit num */
#endif /* ifndef SCIACR2_BERRM_BITNUM */
#endif /* End (SCI_VERSION == SCI_V5) */

/* SCICR2 - SCI Control Register 2 */
#ifndef SCICR2_SBK_MASK
#define SCICR2_SBK_MASK                1            /**< SCI control register 2 bit mask: send break */
#endif /* ifndef SCICR2_SBK_MASK */

#ifndef SCICR2_RWU_MASK
#define SCICR2_RWU_MASK                2            /**< SCI control register 2 bit mask: receiver wakeup control */
#endif /* ifndef SCICR2_RWU_MASK */

#ifndef SCICR2_RE_MASK
#define SCICR2_RE_MASK                 4            /**< SCI control register 2 bit mask: receiver enable */
#endif /* ifndef SCICR2_RE_MASK */

#ifndef SCICR2_TE_MASK
#define SCICR2_TE_MASK                 8            /**< SCI control register 2 bit mask: transmitter enable */
#endif /* ifndef SCICR2_TE_MASK */

#ifndef SCICR2_ILIE_MASK
#define SCICR2_ILIE_MASK               16           /**< SCI control register 2 bit mask: idle line interrupt enable*/
#endif /* ifndef SCICR2_ILIE_MASK */

#ifndef SCICR2_RIE_MASK
#define SCICR2_RIE_MASK                32           /**< SCI control register 2 bit mask: receiver interrupt enable */
#endif /* ifndef SCICR2_RIE_MASK */

#ifndef SCICR2_TCIE_MASK
#define SCICR2_TCIE_MASK               64           /**< SCI control register 2 bit mask: transmission complete interrupt enable */
#endif /* ifndef SCICR2_TCIE_MASK */

#ifndef SCICR2_TIE_MASK
#define SCICR2_TIE_MASK                128          /**< SCI control register 2 bit mask: transmit interrupt enable */
#endif /* ifndef SCICR2_TIE_MASK */

/* SCISR1 - SCI Status Register */
#ifndef SCISR1_PF_MASK
#define SCISR1_PF_MASK                 1            /**< SCI status register 1 bit mask: parity error flag */
#endif /* ifndef SCISR1_PF_MASK */

#ifndef SCISR1_FE_MASK
#define SCISR1_FE_MASK                 2            /**< SCI status register 1 bit mask: framing error flag */
#endif /* ifndef SCISR1_FE_MASK */

#ifndef SCISR1_NF_MASK
#define SCISR1_NF_MASK                 4            /**< SCI status register 1 bit mask: noise flag */
#endif /* ifndef SCISR1_NF_MASK */

#ifndef SCISR1_OR_MASK
#define SCISR1_OR_MASK                 8            /**< SCI status register 1 bit mask: receiver overrun flag */
#endif /* ifndef SCISR1_OR_MASK */

#ifndef SCISR1_IDLE_MASK
#define SCISR1_IDLE_MASK               16           /**< SCI status register 1 bit mask: idle line flag */
#endif /* ifndef SCISR1_IDLE_MASK */

#ifndef SCISR1_RDRF_MASK
#define SCISR1_RDRF_MASK               32           /**< SCI status register 1 bit mask: receive data register full flag */
#endif /* ifndef SCISR1_RDRF_MASK */

#ifndef SCISR1_TC_MASK
#define SCISR1_TC_MASK                 64           /**< SCI status register 1 bit mask: transmission complete flag*/
#endif /* ifndef SCISR1_TC_MASK */

#ifndef SCISR1_TDRE_MASK
#define SCISR1_TDRE_MASK               128          /**< SCI status register 1 bit mask: transmit data register empty flag */
#endif /* ifndef SCISR1_TDRE_MASK */

/* SCISR2 - SCI Status Register 2 */

#if (SCI_VERSION == SCI_V2)
#ifndef SCISR2_RAF_MASK
#define SCISR2_RAF_MASK                1            /**< SCI status register 2 bit mask: receiver active flag */
#endif /* ifndef SCISR2_RAF_MASK */

#ifndef SCISR2_BRK13_MASK
#define SCISR2_BRK13_MASK              4            /**< SCI status register 2 bit mask: break character length */
#endif /* ifndef SCISR2_BRK13_MASK */
#endif /* End (SCI_VERSION == SCI_V2) */

#if (SCI_VERSION == SCI_V4)
#ifndef SCISR2_RAF_MASK
#define SCISR2_RAF_MASK                  1          /**< SCI status register 2 bit mask: receiver active flag */
#endif /* ifndef SCISR2_RAF_MASK */

#ifndef SCISR2_LBKDE_MASK
#define SCISR2_LBKDE_MASK                2          /**< SCI status register 2 bit mask: LIN break detection enable */
#endif /* ifndef SCISR2_LBKDE_MASK */

#ifndef SCISR2_BRK13_MASK
#define SCISR2_BRK13_MASK                4          /**< SCI status register 2 bit mask: break character length */
#endif /* ifndef SCISR2_BRK13_MASK */

#ifndef SCISR2_RWUID_MASK
#define SCISR2_RWUID_MASK                8          /**< SCI status register 2 bit mask: receive wakeup idle detect */
#endif /* ifndef SCISR2_RWUID_MASK */

#ifndef SCISR2_RXINV_MASK
#define SCISR2_RXINV_MASK                16         /**< SCI status register 2 bit mask: receive data inversion */
#endif /* ifndef SCISR2_RXINV_MASK */

#ifndef SCISR2_RXEDGIF_MASK
#define SCISR2_RXEDGIF_MASK              64         /**< SCI status register 2 bit mask: RxD pin active edge interrupt flag */
#endif /* ifndef SCISR2_RXEDGIF_MASK */

#ifndef SCISR2_LBKDIF_MASK
#define SCISR2_LBKDIF_MASK               128        /**< SCI status register 2 bit mask: LIN break detect interrupt flag */
#endif /* ifndef SCISR2_LBKDIF_MASK */

#endif /* End (SCI_VERSION == SCI_V4) */

#if ((SCI_VERSION == SCI_V5) || (SCI_VERSION == SCI_V6))
#ifndef SCISR2_RAF_MASK
#define SCISR2_RAF_MASK                1            /**< SCI status register 2 bit mask: receiver active flag */
#endif /* ifndef SCISR2_RAF_MASK */

#ifndef SCISR2_TXDIR_MASK
#define SCISR2_TXDIR_MASK              2            /**< SCI status register 2 bit mask: transmitter pin data direction in single-wire mode */
#endif /* ifndef SCISR2_TXDIR_MASK */

#ifndef SCISR2_BRK13_MASK
#define SCISR2_BRK13_MASK              4            /**< SCI status register 2 bit mask: break character length */
#endif /* ifndef SCISR2_BRK13_MASK */

#ifndef SCISR2_RXPOL_MASK
#define SCISR2_RXPOL_MASK              8            /**< SCI status register 2 bit mask: receive polarity */
#endif /* ifndef SCISR2_RXPOL_MASK */

#ifndef SCISR2_TXPOL_MASK
#define SCISR2_TXPOL_MASK              16           /**< SCI status register 2 bit mask: transmit polarity */
#endif /* ifndef SCISR2_TXPOL_MASK */

#ifndef SCISR2_AMAP_MASK
#define SCISR2_AMAP_MASK               128          /**< SCI status register 2 bit mask: transmit map */
#endif /* ifndef SCISR2_AMAP_MASK */

#endif /* End (SCI_VERSION == SCI_V5) */

#if ((SCI_VERSION != SCI_V5) && (SCI_VERSION != SCI_V6))
/* SCICR3 - SCI Control Register 3 */
#ifndef SCICR3_PEIE_MASK
#define SCICR3_PEIE_MASK               1            /**< SCI control register 3 bit mask: parity error interrupt enable */
#endif /* ifndef SCICR3_PEIE_MASK */

#ifndef SCICR3_FEIE_MASK
#define SCICR3_FEIE_MASK               2            /**< SCI control register 3 bit mask: framing error interrupt enable */
#endif /* ifndef SCICR3_FEIE_MASK */

#ifndef SCICR3_NEIE_MASK
#define SCICR3_NEIE_MASK               4            /**< SCI control register 3 bit mask: noise error interrupt enable */
#endif /* ifndef SCICR3_NEIE_MASK */

#ifndef SCICR3_ORIE_MASK
#define SCICR3_ORIE_MASK               8            /**< SCI control register 3 bit mask: overrun interrupt enable */
#endif /* ifndef SCICR3_ORIE_MASK */

#ifndef SCICR3_TXINV_MASK
#define SCICR3_TXINV_MASK              16           /**< SCI control register 3 bit mask: transmit data inversion */
#endif /* ifndef SCICR3_TXINV_MASK */

#ifndef SCICR3_TXDIR_MASK
#define SCICR3_TXDIR_MASK              32           /**< SCI control register 3 bit mask: TxD pin direction in single-wire mode */
#endif /* ifndef SCICR3_TXDIR_MASK */

#ifndef SCICR3_T8_MASK
#define SCICR3_T8_MASK                 64           /**< SCI control register 3 bit mask: Ninth data bit for transmitter */
#endif /* ifndef SCICR3_T8_MASK */

#ifndef SCICR3_R8_MASK
#define SCICR3_R8_MASK                 128          /**< SCI control register 3 bit mask: ninth data bit for receiver */
#endif /* ifndef SCICR3_R8_MASK */

/* SCID - SCI Data Register */
#if (defined(_MC9S08DZ128_H)|| defined(_MM9Z1J638_H)||(SCI_VERSION == SCI_V4))
#ifndef SCID_R0_T0_MASK
#define SCID_R0_T0_MASK                1            /**< SCI data register bit mask: bit 0 */
#endif /* ifndef SCID_R0_T0_MASK */

#ifndef SCID_R1_T1_MASK
#define SCID_R1_T1_MASK                2            /**< SCI data register bit mask: bit 1 */
#endif /* ifndef SCID_R1_T1_MASK */

#ifndef SCID_R2_T2_MASK
#define SCID_R2_T2_MASK                4            /**< SCI data register bit mask: bit 2 */
#endif /* ifndef SCID_R2_T2_MASK */

#ifndef SCID_R3_T3_MASK
#define SCID_R3_T3_MASK                8            /**< SCI data register bit mask: bit 3 */
#endif /* ifndef SCID_R3_T3_MASK */

#ifndef SCID_R4_T4_MASK
#define SCID_R4_T4_MASK                16           /**< SCI data register bit mask: bit 4 */
#endif /* ifndef SCID_R4_T4_MASK */

#ifndef SCID_R5_T5_MASK
#define SCID_R5_T5_MASK                32           /**< SCI data register bit mask: bit 5 */
#endif /* ifndef SCID_R5_T5_MASK */

#ifndef SCID_R6_T6_MASK
#define SCID_R6_T6_MASK                64           /**< SCI data register bit mask: bit 6 */
#endif /* ifndef SCID_R6_T6_MASK */

#ifndef SCID_R7_T7_MASK
#define SCID_R7_T7_MASK                128          /**< SCI data register bit mask: bit 7 */
#endif /* ifndef SCID_R7_T7_MASK */
#endif /* End (!defined(_MC9S08SG32_H))*/

#else

/* SCI Data Register High */
#ifndef SCIDRH_T8_MASK
#define SCIDRH_T8_MASK                 64           /**< SCI data register high bit mask: transmit bit 8 */
#endif /* ifndef SCIDRH_T8_MASK */
#ifndef SCIDRH_R8_MASK
#define SCIDRH_R8_MASK                 128          /**< SCI data register high bit mask: receive bit 8 */
#endif /* ifndef SCIDRH_R8_MASK */

/* SCI Data Register Low */
#ifndef SCIDRL_R0_T0_MASK
#define SCIDRL_R0_T0_MASK                1          /**< SCI data register low bit mask: bit 0 */
#endif /* ifndef SCIDRL_R0_T0_MASK */

#ifndef SCIDRL_R1_T1_MASK
#define SCIDRL_R1_T1_MASK                2          /**< SCI data register low bit mask: bit 1 */
#endif /* ifndef SCIDRL_R1_T1_MASK */

#ifndef SCIDRL_R2_T2_MASK
#define SCIDRL_R2_T2_MASK                4          /**< SCI data register low bit mask: bit 2 */
#endif /* ifndef SCIDRL_R2_T2_MASK */

#ifndef SCIDRL_R3_T3_MASK
#define SCIDRL_R3_T3_MASK                8          /**< SCI data register low bit mask: bit 3 */
#endif /* ifndef SCIDRL_R3_T3_MASK */

#ifndef SCIDRL_R4_T4_MASK
#define SCIDRL_R4_T4_MASK                16         /**< SCI data register low bit mask: bit 4 */
#endif /* ifndef SCIDRL_R4_T4_MASK */

#ifndef SCIDRL_R5_T5_MASK
#define SCIDRL_R5_T5_MASK                32         /**< SCI data register low bit mask: bit 5 */
#endif /* ifndef SCIDRL_R5_T5_MASK */

#ifndef SCIDRL_R6_T6_MASK
#define SCIDRL_R6_T6_MASK                64         /**< SCI data register low bit mask: bit 6 */
#endif /* ifndef SCIDRL_R6_T6_MASK */

#ifndef SCIDRL_R7_T7_MASK
#define SCIDRL_R7_T7_MASK                128        /**< SCI data register low bit mask: bit 7 */
#endif /* ifndef SCIDRL_R7_T7_MASK */

#endif /* End (SCI_VERSION != SCI_V5) */
#endif /* Lin register */

/**
* @}
*/
