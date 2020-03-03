/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup XGATE_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      bsp/XGATE//reg_s12x.h
*
* @author    FPT Software
*
* @brief     SCI register definition on S12X
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20090408     v1.0    First version
 *
 *****************************************************************************/

#ifndef REG_S12X_H         /*prevent duplicated includes */
#define REG_S12X_H

#include "lin_hw_cfg.h"

/*************************************/
/******   Common Register struct *****/
/*************************************/

/**
* @var typedef unsigned char tU08
* unsigned 8 bit definition
*/
typedef unsigned char   tU08;   /**< unsigned 8 bit definition */
/**
* @var typedef unsigned int tU16
* unsigned 16 bit definition
*/
typedef unsigned int    tU16;   /**< unsigned 16 bit definition*/
/**
* @var typedef unsigned long tU32
* unsigned 32 bits definition
*/
typedef unsigned long   tU32;   /**< unsigned 32 bit definition*/

/**
* @var typedef signed char tS08
* signed 8 bits definition
*/
typedef signed char     tS08;   /*< *signed 8 bit definition */
/**
* @var typedef signed int tS16
* signed 16 bits definition
*/
typedef signed int      tS16;   /**< signed 16 bit definition*/
/**
* @var typedef signed long tS32
* signed 32 bits definition
*/
typedef signed long     tS32;   /**< signed 32 bit definition*/
/**
* @var typedef uREG08 tREG08
* 8 bit register with byte and bit access
*/
/**
* @union uREG08
* 8 bit register with byte and bit access
*/
typedef union uREG08    /*8 bit register with byte and bit access*/
{
    tU08  byte;           /**< access whole register e.g. var.byte   = 0xFF;*/
    /**
    * @struct bit
    * 8 bits register with byte and bit access
    */
    struct                /*access bit at a time  e.g. var.bit._7 = 1;   */
    {
        tU08 _0 :1;   /**< bit 0 */
        tU08 _1 :1;   /**< bit 1 */
        tU08 _2 :1;   /**< bit 2 */
        tU08 _3 :1;   /**< bit 3 */
        tU08 _4 :1;   /**< bit 4 */
        tU08 _5 :1;   /**< bit 5 */
        tU08 _6 :1;   /**< bit 6 */
        tU08 _7 :1;   /**< bit 7 */
    } bit;        /*access bit at a time  e.g. var.bit._7 = 1;   */
} tREG08;

/**
* @var typedef uREG16 tREG16
* 16 bit register with word and byte access
*/
/**
* @union uREG16
* 16 bit register with word and byte access
*/
typedef union uREG16    /*16 bit register with word and byte access*/
{
    tU16  word;           /**< access whole word    */
    /**
    * @struct byte
    * two bytes of register
    */
    struct                /*access byte at a time*/
    {
        tREG08  msb;  /**< MSB byte */
        tREG08  lsb;  /**< LSB byte */
    } byte; /**< the bytes of register */
} tREG16;
/*************************************/
/*******   SCI Register struct *******/
/*************************************/
/**
* @var uSCIBDH tSCIBDH
* SCI baudrate high register
*/
/**
* @union uSCIBDH
* SCI baudrate high register
*/
typedef union uSCIBDH
{
    tU08   byte;        /**< the byte of register */
    /**
    * @struct bit
    * 8 bits of register
    */
    struct
    {
        tU08 sbr8   :1;     /**< msb baud rate select bit 8 */
        tU08 sbr9   :1;     /**< msb baud rate select bit 9 */
        tU08 sbr10  :1;     /**< msb baud rate select bit 10 */
        tU08 sbr11  :1;     /**< msb baud rate select bit 11 */
        tU08 sbr12  :1;     /**< msb baud rate select bit 12 */
        tU08 tnp    :2;     /**< transmit narrow pulse */
        tU08 iren   :1;     /**< IRDA enable */
    } bit;                /**< 8 bits of register */
    /**
    * @struct abit
    * alternate bits for SCIACR1
    */
    struct
    {
        tU08 bkdif  :1;     /**< break detect interrupt flag */
        tU08 berrif :1;     /**< bit error interrupt flag   */
        tU08 berrv  :1;     /**< bit error value */
        tU08        :4;     /**< not used */
        tU08 rxedgif:1;     /**< receive input active edge interrupt flag */
    } abit;               /**< alternate bits for SCIASR1 */
} tSCIBDH;

/**
* @var uSCIBDL tSCIBDL
* SCI baudrate low register
*/
/**
* @union uSCIBDL
* SCI baudrate low register
*/
typedef union uSCIBDL
{
    tU08   byte;          /**< the byte of register */
    /**
    * @struct bit
    * 8 bits of register
    */
    struct
    {
        tU08 sbr0   :1;     /**< lsb baud rate select bit 0 */
        tU08 sbr1   :1;     /**< lsb baud rate select bit 1 */
        tU08 sbr2   :1;     /**< lsb baud rate select bit 2 */
        tU08 sbr3   :1;     /**< lsb baud rate select bit 3 */
        tU08 sbr4   :1;     /**< lsb baud rate select bit 4 */
        tU08 sbr5   :1;     /**< lsb baud rate select bit 5 */
        tU08 sbr6   :1;     /**< lsb baud rate select bit 6 */
        tU08 sbr7   :1;     /**< lsb baud rate select bit 7 */
    } bit;                /**< 8 bits of register */
    /**
    * @struct abit
    * alternate bits for SCIACR1
    */
    struct
    {
        tU08 bkdie  :1;     /**< break detect interrupt enable */
        tU08 berrie :1;     /**< bit error interrupt enable */
        tU08        :5;     /**< not used */
        tU08 rxedgie:1;     /**< receive input active edge interrupt enable */
    } abit;               /**< alternate bits for SCIACR1 */
} tSCIBDL;

/**
* @var uSCICR1 tSCICR1
* SCI control register 1
*/
/**
* @union uSCICR1
* SCI control register 1
*/
typedef union uSCICR1
{
    tU08   byte;          /**< the byte of register */
    struct
    {
        tU08 pt      :1;     /**< parity type */
        tU08 pe      :1;     /**< parity enable   */
        tU08 ilt     :1;     /**< idle line type */
        tU08 wake    :1;     /**< wake up by address mark/idle */
        tU08 m       :1;     /**< mode select */
        tU08 rsrc    :1;     /**< receiver source */
        tU08 sciswai :1;     /**< stop in wait mode  */
        tU08 loops   :1;     /**< loop mode/single wire mode enable */
    } bit;                 /**< 8 bits of register */
    struct               /* alternate bits for SCIACR2 */
    {
        tU08 bkdfe   :1;     /**< break detect feature enable */
        tU08 berrm0  :1;     /**< bit error mode */
        tU08 berrm1  :1;     /**< bit error mode */
        tU08         :5;     /**< not used */
    } abit;                /**< alternate bits for SCIACR2 */
} tSCICR1;

/**
* @var uSCICR2 tSCICR2
* SCI control register 2
*/
/**
* @union uSCICR2
* SCI control register 2
*/
typedef union uSCICR2
{
    tU08   byte;          /**< the byte of register */
    struct
    {
        tU08 sbk   :1;      /**< send break character */
        tU08 rwu   :1;      /**< receiver wake-up control */
        tU08 re    :1;      /**< receiver enable */
        tU08 te    :1;      /**< transmitter enable */
        tU08 ilie  :1;      /**< idle line interrupt enable */
        tU08 rie   :1;      /**< receiver interrupt enable   */
        tU08 tcie  :1;      /**< transmit complete interrupt enable */
        tU08 tie   :1;      /**< transmit interrupt enable   */
    } bit;                /**< 8 bits of register */
} tSCICR2;

/**
* @var uSCISR1 tSCISR1
* SCI status register 1
*/
/**
* @union uSCISR1
* SCI status register 1
*/
typedef union uSCISR1
{
    tU08   byte;          /**< the byte of register */
    struct
    {
        tU08 pf    :1;      /**< parity error flag  */
        tU08 fe    :1;      /**< framing error flag */
        tU08 nf    :1;      /**< noise error flag */
        tU08 orf   :1;      /**< overrun error flag - 'or' in specification */
        tU08 idle  :1;      /**< idle line detected flag */
        tU08 rdrf  :1;      /**< receive data register full flag */
        tU08 tc    :1;      /**< transmit complete flag */
        tU08 tdre  :1;      /**< transmit data register empty flag */
    } bit;                /**< 8 bits of register */
} tSCISR1;

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
    tU08   byte;        /**< the byte of register */
    struct
    {
        tU08 raf    :1;   /**< receiver active flag */
        tU08 txdir  :1;   /**< receiver active flag */
        tU08 brk13  :1;   /**< 13-bit break */
        tU08 rxpol  :1;   /**< receiver polarity */
        tU08 txpol  :1;   /**< transmitter polarity */
        tU08        :2;   /**< not used */
        tU08 amap   :1;   /**< alternate register map */
    } bit;                /**< 8 bits of register */
} tSCISR2;

/**
* @var uSCIDRH tSCIDRH
* SCI data register high
*/
/**
* @union uSCIDRH
* SCI data register high
*/
typedef union uSCIDRH
{
    tU08   byte;          /**< the byte of register */
    struct
    {
        tU08       :6;      /**< not used */
        tU08 t8    :1;      /**< transmit bit 8 */
        tU08 r8    :1;      /**< receive bit 8   */
    } bit;                /**< 8 bits of register */
} tSCIDRH;

/**
* @struct tSCI
* sci data structure
*/
typedef struct          /*sci data structure  */
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


#define sciasr1 scibdh        /* alternate register names */
#define sciacr1 scibdl
#define sciacr2 scicr1

/*************************************/
/************ SCI Bit masks **********/
/*************************************/
/* SCIASR1 - SCI Alternative Status Register*/

#define SCIASR1_BKDIF_MASK     0x01          /**< SCI alternate status register 1 bit mask: break detect interrupt flag */
#define SCIASR1_BERRIF_MASK    0x02          /**< SCI alternate status register 1 bit mask: bit error interrupt flag */
#define SCIASR1_BERRV_MASK     0x04          /**< SCI alternate status register 1 bit mask: bit error value */
#define SCIASR1_RXEDGIF_MASK   0x80        /**< SCI alternate status register 1 bit mask: receive input active interrupt flag */

/* SCI0ACR1 - SCI Alternative Control Register 1*/
#define SCIACR1_BKDIE_MASK     0x01          /**< SCI alternate control register 1 bit mask: break detect interrupt enable */
#define SCIACR1_BERRIE_MASK    0x02          /**< SCI alternate control register 1 bit mask: bit error interrupt enable */
#define SCIACR1_RXEDGIE_MASK   0x80        /**< SCI alternate control register 1 bit mask: receive input active edge interrupt enable */

/* SCICR1 - SCI Control Register 1*/
#define SCICR1_PT_MASK                0x01             /**< SCI control register 1 bit mask: parity type*/
#define SCICR1_PE_MASK                0x02             /**< SCI control register 1 bit mask: parity enable*/
#define SCICR1_ILT_MASK               0x04             /**< SCI control register 1 bit mask: idle line type select*/
#define SCICR1_WAKE_MASK              0x08             /**< SCI control register 1 bit mask: receiver wakeup method select*/
#define SCICR1_M_MASK                 0x10            /**< SCI control register 1 bit mask: 8 bit or 9 bit mode select*/
#define SCICR1_RSRC_MASK              0x20            /**< SCI control register 1 bit mask: receiver source select*/
#define SCICR1_SCISWAI_MASK           0x40            /**< SCI control register 1 bit mask: SCI stops in wait mode*/
#define SCICR1_LOOPS_MASK             0x80           /**< SCI control register 1 bit mask: loop mode select*/


/* SCIACR2 - SCI Alternative Control Register 2*/
#define SCIACR2_BKDFE_MASK         0x01                /**< SCI alternate control register 2: break detect feature enable */
#define SCIACR2_BERRM0_MASK        0x02                /**< SCI alternate control register 2: bit error mode 0 */
#define SCIACR2_BERRM1_MASK        0x04                /**< SCI alternate control register 2: bit error mode 1 */
#define SCIACR2_BERRM_MASK         0x06                /**< SCI alternate control register 2: bit error mode bit 0 and 1 is set */
#define SCIACR2_BERRM_BITNUM       0x01                /**< SCI alternate control register 2: bit num */

/* SCICR2 - SCI Control Register 2 */
#define SCICR2_SBK_MASK                0x01            /**< SCI control register 2 bit mask: send break */
#define SCICR2_RWU_MASK                0x02            /**< SCI control register 2 bit mask: receiver wakeup control */
#define SCICR2_RE_MASK                 0x04            /**< SCI control register 2 bit mask: receiver enable */
#define SCICR2_TE_MASK                 0x08            /**< SCI control register 2 bit mask: transmitter enable */
#define SCICR2_ILIE_MASK               0x10           /**< SCI control register 2 bit mask: idle line interrupt enable*/
#define SCICR2_RIE_MASK                0x20           /**< SCI control register 2 bit mask: receiver interrupt enable */
#define SCICR2_TCIE_MASK               0x40           /**< SCI control register 2 bit mask: transmission complete interrupt enable */
#define SCICR2_TIE_MASK                0x80          /**< SCI control register 2 bit mask: transmit interrupt enable */

/* SCISR1 - SCI Status Register */
#define SCISR1_PF_MASK                 0x01            /**< SCI status register 1 bit mask: parity error flag */
#define SCISR1_FE_MASK                 0x02            /**< SCI status register 1 bit mask: framing error flag */
#define SCISR1_NF_MASK                 0x04            /**< SCI status register 1 bit mask: noise flag */
#define SCISR1_OR_MASK                 0x08            /**< SCI status register 1 bit mask: receiver overrun flag */
#define SCISR1_IDLE_MASK               0x10           /**< SCI status register 1 bit mask: idle line flag */
#define SCISR1_RDRF_MASK               0x20           /**< SCI status register 1 bit mask: receive data register full flag */
#define SCISR1_TC_MASK                 0x40           /**< SCI status register 1 bit mask: transmission complete flag*/
#define SCISR1_TDRE_MASK               0x80          /**< SCI status register 1 bit mask: transmit data register empty flag */


/* SCI Status Register 2 */
#define SCISR2_RAF_MASK                0x01            /**< SCI status register 2 bit mask: receiver active flag */
#define SCISR2_TXDIR_MASK              0x02            /**< SCI status register 2 bit mask: transmitter pin data direction in single-wire mode */
#define SCISR2_BRK13_MASK              0x04            /**< SCI status register 2 bit mask: break character length */
#define SCISR2_RXPOL_MASK              0x08            /**< SCI status register 2 bit mask: receive polarity */
#define SCISR2_TXPOL_MASK              0x10           /**< SCI status register 2 bit mask: transmit polarity */
#define SCISR2_AMAP_MASK               0x80          /**< SCI status register 2 bit mask: transmit map */

/* SCI Data Register High */
#define SCIDRH_T8_MASK                 0x40            /**< SCI data register high bit mask: transmit bit 8 */
#define SCIDRH_R8_MASK                 0x80           /**< SCI data register high bit mask: receive bit 8 */

/* SCI Data Register Low */
#define SCIDRL_R0_T0_MASK                0x01            /**< SCI data register low bit mask: bit 0 */
#define SCIDRL_R1_T1_MASK                0x02            /**< SCI data register low bit mask: bit 1 */
#define SCIDRL_R2_T2_MASK                0x04            /**< SCI data register low bit mask: bit 2 */
#define SCIDRL_R3_T3_MASK                0x08            /**< SCI data register low bit mask: bit 3 */
#define SCIDRL_R4_T4_MASK                0x10           /**< SCI data register low bit mask: bit 4 */
#define SCIDRL_R5_T5_MASK                0x20           /**< SCI data register low bit mask: bit 5 */
#define SCIDRL_R6_T6_MASK                0x40           /**< SCI data register low bit mask: bit 6 */
#define SCIDRL_R7_T7_MASK                0x80          /**< SCI data register low bit mask: bit 7 */


#endif /*S12SCIV5_H */
/**
* @}
*/