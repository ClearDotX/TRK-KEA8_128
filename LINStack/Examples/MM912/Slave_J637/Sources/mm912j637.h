/*
** ############################################################################
**     Filename  : mm912j637.h
**     DataSheet : MM912J637 Rev. 0.9 Apr, 2010
**     Compiler  : CodeWarrior compiler
**     Date/Time : 13.4.2010
**     Abstract  : This header implements the memory mapping of the analog die.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
** ############################################################################
*/

#ifndef _MM912J637_H
#define _MM912J637_H

/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

#define D2DREG_BASE 0x0200        /* Base address for the I/O register block (blocking write) */
//#define D2DREG_BASE 0x0300      /* Base address for the I/O register block (non blocking write) */

#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type   */
#pragma OPTION ADD V30toV31Compatible "-BfaGapLimitBits4294967295" /*this guarantee correct bitfield positions*/

/**************** registers I/O map ******************************************/

/*** PCR_CTL - PCR control register; 0x00 ************************************/
typedef union {
  word Word;
  struct {
    word OPM0           :1;           /* bit 0 */
    word OPM1           :1;           /* bit 1 */
    word PF0            :1;           /* bit 2 */
    word PF1            :1;           /* bit 3 */
    word D2DSM          :1;           /* bit 4 */
    word HWR            :1;           /* bit 5 */
    word UVIE           :1;           /* bit 6 */
    word HTIE           :1;           /* bit 7 */
    word OPMM0          :1;           /* bit 8 */
    word OPMM1          :1;           /* bit 9 */
    word PFM0           :1;           /* bit 10 */
    word PFM1           :1;           /* bit 11 */
    word D2DSMM         :1;           /* bit 12 */
    word HWRM           :1;           /* bit 13 */
    word UVIEM          :1;           /* bit 14 */
    word HTIEM          :1;           /* bit 15 */
  } Bits;
} PCR_CTLSTR;
extern volatile PCR_CTLSTR _PCR_CTL @(D2DREG_BASE + 0x00);
#define PCR_CTL _PCR_CTL.Word

/*** PCR_SR - PCR status register; 0x02 **************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PCR_SRH - PCR status high register; 0x02 ***/
    union {
      byte Byte;
      struct {
        byte WLPMF       :1;           /* Bit 0 */    
        byte WULTCF      :1;           /* Bit 1 */
        byte LVRF        :1;           /* Bit 2 */
        byte HVRF        :1;           /* Bit 3 */
        byte WDRF        :1;           /* Bit 4 */
        byte HWRF        :1;           /* Bit 5 */
        byte UVF         :1;           /* Bit 6 */
        byte HTF         :1;           /* Bit 7 */
      } Bits;
    } PCR_SRHSTR;
    #define PCR_SRH _PCR_SR.Overlap_STR.PCR_SRHSTR.Byte

    /*** PCR_SRL - PCR status low register; 0x03 ***/
    union {
      byte Byte;
      struct {
        byte WUPTB0F     :1;           /* Bit 0 */
        byte WUPTB1F     :1;           /* Bit 1 */
        byte WUPTB2F     :1;           /* Bit 2 */
        byte WUPTB3F     :1;           /* Bit 3 */
        byte WULINF      :1;           /* Bit 4 */
        byte WUCALF      :1;           /* Bit 5 */
        byte WUCTHF      :1;           /* Bit 6 */
        byte WUAHTHF     :1;           /* Bit 7 */
      } Bits;
    } PCR_SRLSTR;
    #define PCR_SRL _PCR_SR.Overlap_STR.PCR_SRLSTR.Byte

  } Overlap_STR;

  struct {
    word WUPTB0F        :1;           /* bit 0 */
    word WUPTB1F        :1;           /* bit 1 */
    word WUPTB2F        :1;           /* bit 2 */
    word WUPTB3F        :1;           /* bit 3 */
    word WULINF         :1;           /* bit 4 */
    word WUCALF         :1;           /* bit 5 */
    word WUCTHF         :1;           /* bit 6 */
    word WUAHTHF        :1;           /* bit 7 */
    word WLPMF          :1;           /* bit 8 */
    word WULTCF         :1;           /* bit 9 */
    word LVRF           :1;           /* bit 10 */
    word HVRF           :1;           /* bit 11 */
    word WDRF           :1;           /* bit 12 */
    word HWRF           :1;           /* bit 13 */
    word UVF            :1;           /* bit 14 */
    word HTF            :1;           /* bit 15 */
  } Bits;
} PCR_SRSTR;
extern volatile PCR_SRSTR _PCR_SR @(D2DREG_BASE + 0x02);
#define PCR_SR _PCR_SR.Word

/*** PCR_PRESC - PCR 1ms prescaler; 0x04 *************************************/
typedef union {
  word Word;
  struct {
    word PRESC0         :1;           /* bit 0 */
    word PRESC1         :1;           /* bit 1 */
    word PRESC2         :1;           /* bit 2 */
    word PRESC3         :1;           /* bit 3 */
    word PRESC4         :1;           /* bit 4 */
    word PRESC5         :1;           /* bit 5 */
    word PRESC6         :1;           /* bit 6 */
    word PRESC7         :1;           /* bit 7 */
    word PRESC8         :1;           /* bit 8 */
    word PRESC9         :1;           /* bit 9 */
    word PRESC10        :1;           /* bit 10 */
    word PRESC11        :1;           /* bit 11 */
    word PRESC12        :1;           /* bit 12 */
    word PRESC13        :1;           /* bit 13 */
    word PRESC14        :1;           /* bit 14 */
    word PRESC15        :1;           /* bit 15 */
  } Bits;
} PCR_PRESCSTR;
extern volatile PCR_PRESCSTR _PCR_PRESC @(D2DREG_BASE + 0x04);
#define PCR_PRESC _PCR_PRESC.Word


/*** PCR_WUE - Wake up enable register; 0x06 *********************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PCR_WUEH - Wake up enable high register; 0x06 ***/
    union {
      byte Byte;
      struct {
        byte WUPTB0     :1;           /* Bit 0 */    
        byte WUPTB1     :1;           /* Bit 1 */
        byte WUPTB2     :1;           /* Bit 2 */
        byte WUPTB3     :1;           /* Bit 3 */
        byte WULIN      :1;           /* Bit 4 */
        byte WUCAL      :1;           /* Bit 5 */
        byte WUCTH      :1;           /* Bit 6 */
        byte WUAHTH     :1;           /* Bit 7 */
      } Bits;
    } PCR_WUEHSTR;
    #define PCR_WUEH _PCR_WUE.Overlap_STR.PCR_WUEHSTR.Byte

    /*** PCR_WUEL - Wake up enable low register; 0x07 ***/
    union {
      byte Byte;
      struct {
        byte            :1;           /* Bit 0 */
        byte            :1;           /* Bit 1 */
        byte            :1;           /* Bit 2 */
        byte            :1;           /* Bit 3 */
        byte            :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte WULTC      :1;           /* Bit 7 */
      } Bits;
    } PCR_WUELSTR;
    #define PCR_WUEL _PCR_WUE.Overlap_STR.PCR_WUELSTR.Byte

  } Overlap_STR;

  struct {
    word                :1;           /* bit 0 */
    word                :1;           /* bit 1 */
    word                :1;           /* bit 2 */
    word                :1;           /* bit 3 */
    word                :1;           /* bit 4 */
    word                :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word WULTC          :1;           /* bit 7 */
    word WUPTB0         :1;           /* bit 8 */
    word WUPTB1         :1;           /* bit 9 */
    word WUPTB2         :1;           /* bit 10 */
    word WUPTB3         :1;           /* bit 11 */
    word WULIN          :1;           /* bit 12 */
    word WUCAL          :1;           /* bit 13 */
    word WUCTH          :1;           /* bit 14 */
    word WUAHTH         :1;           /* bit 15 */
  } Bits;
} PCR_WUESTR;
extern volatile PCR_WUESTR _PCR_WUE @(D2DREG_BASE + 0x06);
#define PCR_WUE _PCR_WUE.Word


/*** INT_SRC - Interrupt source register; 0x08 *******************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** INT_SRCH - Interrupt source high register; 0x08 ***/
    union {
      byte Byte;
      struct {
        byte UVI        :1;           /* Bit 0 */    
        byte HTI        :1;           /* Bit 1 */
        byte LTI        :1;           /* Bit 2 */
        byte CH0        :1;           /* Bit 3 */
        byte CH1        :1;           /* Bit 4 */
        byte CH2        :1;           /* Bit 5 */
        byte CH3        :1;           /* Bit 6 */
        byte TOV        :1;           /* Bit 7 */
      } Bits;
    } INT_SRCHSTR;
    #define INT_SRCH _INT_SRC.Overlap_STR.INT_SRCHSTR.Byte

    /*** INT_SRCL - Interrupt source low register; 0x09 ***/
    union {
      byte Byte;
      struct {
        byte ERR        :1;           /* Bit 0 */
        byte TX         :1;           /* Bit 1 */
        byte RX         :1;           /* Bit 2 */
        byte CVMI       :1;           /* Bit 3 */
        byte LTC        :1;           /* Bit 4 */
        byte CAL        :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } INT_SRCLSTR;
    #define INT_SRCL _INT_SRC.Overlap_STR.INT_SRCLSTR.Byte

  } Overlap_STR;

  struct {
    word ERR            :1;           /* bit 0 */
    word TX             :1;           /* bit 1 */
    word RX             :1;           /* bit 2 */
    word CVMI           :1;           /* bit 3 */
    word LTC            :1;           /* bit 4 */
    word CAL            :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word                :1;           /* bit 7 */
    word UVI            :1;           /* bit 8 */
    word HTI            :1;           /* bit 9 */
    word LTI            :1;           /* bit 10 */
    word CH0            :1;           /* bit 11 */
    word CH1            :1;           /* bit 12 */
    word CH2            :1;           /* bit 13 */
    word CH3            :1;           /* bit 14 */
    word TOV            :1;           /* bit 15 */
  } Bits;
} INT_SRCSTR;
extern volatile INT_SRCSTR _INT_SRC @(D2DREG_BASE + 0x08);
#define INT_SRC _INT_SRC.Word


/*** INT_VECT - Interrupt vector register; 0x0A ******************************/
typedef union {
  byte Byte;
  struct {
    byte IRQ0           :1;           /* bit 0 */
    byte IRQ1           :1;           /* bit 1 */
    byte IRQ2           :1;           /* bit 2 */
    byte IRQ3           :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} INT_VECTSTR;
extern volatile INT_VECTSTR _INT_VECT @(D2DREG_BASE + 0x0A);
#define INT_VECT _INT_VECT.Byte
 

/*** INT_MSK - Interrupt mask register; 0x0C *********************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** INT_MSKH - Interrupt mask high register; 0x0C ***/
    union {
      byte Byte;
      struct {
        byte UVIM       :1;           /* Bit 0 */    
        byte HTIM       :1;           /* Bit 1 */
        byte LTIM       :1;           /* Bit 2 */
        byte CH0M       :1;           /* Bit 3 */
        byte CH1M       :1;           /* Bit 4 */
        byte CH2M       :1;           /* Bit 5 */
        byte CH3M       :1;           /* Bit 6 */
        byte TOVM       :1;           /* Bit 7 */
      } Bits;
    } INT_MSKHSTR;
    #define INT_MSKH _INT_MSK.Overlap_STR.INT_MSKHSTR.Byte

    /*** INT_MSKL - Interrupt mask low register; 0x0D ***/
    union {
      byte Byte;
      struct {
        byte ERRM       :1;           /* Bit 0 */
        byte TXM        :1;           /* Bit 1 */
        byte RXM        :1;           /* Bit 2 */
        byte CVMIM      :1;           /* Bit 3 */
        byte LTCM       :1;           /* Bit 4 */
        byte CALM       :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } INT_MSKLSTR;
    #define INT_MSKL _INT_MSK.Overlap_STR.INT_MSKLSTR.Byte

  } Overlap_STR;

  struct {
    word ERRM           :1;           /* bit 0 */
    word TXM            :1;           /* bit 1 */
    word RXM            :1;           /* bit 2 */
    word CVMIM          :1;           /* bit 3 */
    word LTCM           :1;           /* bit 4 */
    word CALM           :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word                :1;           /* bit 7 */
    word UVIM           :1;           /* bit 8 */
    word HTIM           :1;           /* bit 9 */
    word LTIM           :1;           /* bit 10 */
    word CH0M           :1;           /* bit 11 */
    word CH1M           :1;           /* bit 12 */
    word CH2M           :1;           /* bit 13 */
    word CH3M           :1;           /* bit 14 */
    word TOVM           :1;           /* bit 15 */
  } Bits;
} INT_MSKSTR;
extern volatile INT_MSKSTR _INT_MSK @(D2DREG_BASE + 0x0C);
#define INT_MSK _INT_MSK.Word


/*** TRIM_ALF - ALF Clk Trim Register; 0x0E *********************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TRIM_ALFH - ALF Clk Trim high register; 0x0E ***/
    union {
      byte Byte;
      struct {
        byte APRESC8    :1;           /* Bit 0 */    
        byte APRESC9    :1;           /* Bit 1 */
        byte APRESC10   :1;           /* Bit 2 */
        byte APRESC11   :1;           /* Bit 3 */
        byte APRESC12   :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte PRDF       :1;           /* Bit 7 */
      } Bits;
    } TRIM_ALFSTR;
    #define TRIM_ALFH _TRIM_ALF.Overlap_STR.TRIM_ALFHSTR.Byte

    /*** TRIM_ALFL - ALF Clk Trim low register; 0x0F ***/
    union {
      byte Byte;
      struct {
        byte APRESC0    :1;           /* Bit 0 */
        byte APRESC1    :1;           /* Bit 1 */
        byte APRESC2    :1;           /* Bit 2 */
        byte APRESC3    :1;           /* Bit 3 */
        byte APRESC4    :1;           /* Bit 4 */
        byte APRESC5    :1;           /* Bit 5 */
        byte APRESC6    :1;           /* Bit 6 */
        byte APRESC7    :1;           /* Bit 7 */
      } Bits;
    } TRIM_ALFLSTR;
    #define TRIM_ALFL _TRIM_ALF.Overlap_STR.TRIM_ALFLSTR.Byte

  } Overlap_STR;

  struct {
    word APRESC0        :1;           /* bit 0 */
    word APRESC1        :1;           /* bit 1 */
    word APRESC2        :1;           /* bit 2 */
    word APRESC3        :1;           /* bit 3 */
    word APRESC4        :1;           /* bit 4 */
    word APRESC5        :1;           /* bit 5 */
    word APRESC6        :1;           /* bit 6 */
    word APRESC7        :1;           /* bit 7 */
    word APRESC8        :1;           /* bit 8 */
    word APRESC9        :1;           /* bit 9 */
    word APRESC10       :1;           /* bit 10 */
    word APRESC11       :1;           /* bit 11 */
    word APRESC12       :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word PRDF           :1;           /* bit 15 */
  } Bits;
} TRIM_ALFSTR;
extern volatile TRIM_ALFSTR _TRIM_ALF @(D2DREG_BASE + 0x0E);
#define TRIM_ALF _TRIM_ALF.Word


/*** WD_CTL - Watchdog control register; 0x10 ********************************/
typedef union {
  word Word;
  struct {
    word WDTO0          :1;           /* bit 0 */
    word WDTO1          :1;           /* bit 1 */
    word WDTO2          :1;           /* bit 2 */
    word                :1;           /* bit 3 */
    word                :1;           /* bit 4 */
    word                :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word WDTST          :1;           /* bit 7 */
    word WDTOM0         :1;           /* bit 8 */
    word WDTOM1         :1;           /* bit 9 */
    word WDTOM2         :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word WDTSTM         :1;           /* bit 15 */
  } Bits;
} WD_CTLSTR;
extern volatile WD_CTLSTR _WD_CTL @(D2DREG_BASE + 0x10);
#define WD_CTL _WD_CTL.Word

/*** WD_SR - Watchdog status register; 0x12 **********************************/
typedef union {
  byte Byte;
  struct {
    byte WDWO           :1;           /* bit 0 */
    byte WDOFF          :1;           /* bit 1 */
    byte                :1;           /* bit 2 */
    byte                :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} WD_SRSTR;
extern volatile WD_SRSTR _WD_SR @(D2DREG_BASE + 0x12);
#define WD_SR _WD_SR.Byte


/*** WD_RR - Watchdog rearm register; 0x14 ***********************************/
typedef union {
  byte Byte;
  struct {
    byte WDR0           :1;           /* bit 0 */
    byte WDR1           :1;           /* bit 1 */
    byte WDR2           :1;           /* bit 2 */
    byte WDR3           :1;           /* bit 3 */
    byte WDR4           :1;           /* bit 4 */
    byte WDR5           :1;           /* bit 5 */
    byte WDR6           :1;           /* bit 6 */
    byte WDR7           :1;           /* bit 7 */
  } Bits;
} WD_RRSTR;
extern volatile WD_RRSTR _WD_RR @(D2DREG_BASE + 0x14);
#define WD_RR _WD_RR.Byte


/*** SCIBD - SCI Baud Rate Register; 0x18 ************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCIBDH - SCI Baud Rate High Register; 0x18 ***/
    union {
      byte Byte;
      struct {
        byte SBR8       :1;           /* Bit 0 */    
        byte SBR9       :1;           /* Bit 1 */
        byte SBR10      :1;           /* Bit 2 */
        byte SBR11      :1;           /* Bit 3 */
        byte SBR12      :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte RXEDGIE    :1;           /* Bit 6 */
        byte LBKDIE     :1;           /* Bit 7 */
      } Bits;
    } SCIBDHSTR;
    #define SCIBDH _SCIBD.Overlap_STR.SCIBDHSTR.Byte

    /*** SCIBDL - SCI Baud Rate Low Register; 0x19 ***/
    union {
      byte Byte;
      struct {
        byte SBR0       :1;           /* Bit 0 */
        byte SBR1       :1;           /* Bit 1 */
        byte SBR2       :1;           /* Bit 2 */
        byte SBR3       :1;           /* Bit 3 */
        byte SBR4       :1;           /* Bit 4 */
        byte SBR5       :1;           /* Bit 5 */
        byte SBR6       :1;           /* Bit 6 */
        byte SBR7       :1;           /* Bit 7 */
      } Bits;
    } SCIBDLSTR;
    #define SCIBDL _SCIBD.Overlap_STR.SCIBDLSTR.Byte

  } Overlap_STR;

  struct {
    word SBR0           :1;           /* bit 0 */
    word SBR1           :1;           /* bit 1 */
    word SBR2           :1;           /* bit 2 */
    word SBR3           :1;           /* bit 3 */
    word SBR4           :1;           /* bit 4 */
    word SBR5           :1;           /* bit 5 */
    word SBR6           :1;           /* bit 6 */
    word SBR7           :1;           /* bit 7 */
    word SBR8           :1;           /* bit 8 */
    word SBR9           :1;           /* bit 9 */
    word SBR10          :1;           /* bit 10 */
    word SBR11          :1;           /* bit 11 */
    word SBR12          :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word RXEDGIE        :1;           /* bit 14 */
    word LBKDIE         :1;           /* bit 15 */
  } Bits;
} SCIBDSTR;
extern volatile SCIBDSTR _SCIBD @(D2DREG_BASE + 0x18);
#define SCIBD _SCIBD.Word


/*** SCIC1 - SCI Control Register 1; 0x1A ************************************/
typedef union {
  byte Byte;
  struct {
    byte PT             :1;           /* bit 0 */
    byte PE             :1;           /* bit 1 */
    byte ILT            :1;           /* bit 2 */
    byte                :1;           /* bit 3 */
    byte M              :1;           /* bit 4 */
    byte RSRC           :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte LOOPS          :1;           /* bit 7 */
  } Bits;
} SCIC1STR;
extern volatile SCIC1STR _SCIC1 @(D2DREG_BASE + 0x1A);
#define SCIC1 _SCIC1.Byte


/*** SCIC2 - SCI Control Register 2; 0x1B ************************************/
typedef union {
  byte Byte;
  struct {
    byte SBK            :1;           /* bit 0 */
    byte RWU            :1;           /* bit 1 */
    byte RE             :1;           /* bit 2 */
    byte TE             :1;           /* bit 3 */
    byte ILIE           :1;           /* bit 4 */
    byte RIE            :1;           /* bit 5 */
    byte TCIE           :1;           /* bit 6 */
    byte TIE            :1;           /* bit 7 */
  } Bits;
} SCIC2STR;
extern volatile SCIC2STR _SCIC2 @(D2DREG_BASE + 0x1B);
#define SCIC2 _SCIC2.Byte


/*** SCIS1 - SCI Status Register 1; 0x1C *************************************/
typedef union {
  byte Byte;
  struct {
    byte PF             :1;           /* bit 0 */
    byte FE             :1;           /* bit 1 */
    byte NF             :1;           /* bit 2 */
    byte OR             :1;           /* bit 3 */
    byte m_IDLE         :1;           /* bit 4 */
    byte RDRF           :1;           /* bit 5 */
    byte TC             :1;           /* bit 6 */
    byte TDRE           :1;           /* bit 7 */
  } Bits;
} SCIS1STR;
extern volatile SCIS1STR _SCIS1 @(D2DREG_BASE + 0x1C);
#define SCIS1 _SCIS1.Byte


/*** SCIS2 - SCI Status Register 2; 0x1D *************************************/
typedef union {
  byte Byte;
  struct {
    byte RAF            :1;           /* bit 0 */
    byte LBKDE          :1;           /* bit 1 */
    byte BRK13          :1;           /* bit 2 */
    byte RWUID          :1;           /* bit 3 */
    byte RXINV          :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte RXEDGIF        :1;           /* bit 6 */
    byte LBKDIF         :1;           /* bit 7 */
  } Bits;
} SCIS2STR;
extern volatile SCIS2STR _SCIS2 @(D2DREG_BASE + 0x1D);
#define SCIS2 _SCIS2.Byte


/*** SCIS3 - SCI Status Register 3; 0x1E *************************************/
typedef union {
  byte Byte;
  struct {
    byte PEIE            :1;           /* bit 0 */
    byte FEIE            :1;           /* bit 1 */
    byte NEIE            :1;           /* bit 2 */
    byte ORIE            :1;           /* bit 3 */
    byte TXINV           :1;           /* bit 4 */
    byte TXDIR           :1;           /* bit 5 */
    byte T8              :1;           /* bit 6 */
    byte R8              :1;           /* bit 7 */
  } Bits;
} SCIS3STR;
extern volatile SCIS3STR _SCIS3 @(D2DREG_BASE + 0x1E);
#define SCIS3 _SCIS3.Byte


/*** SCID - SCI Data Register; 0x1F ******************************************/
typedef union {
  byte Byte;
  struct {
    byte SCID0          :1;           /* bit 0 */
    byte SCID1          :1;           /* bit 1 */
    byte SCID2          :1;           /* bit 2 */
    byte SCID3          :1;           /* bit 3 */
    byte SCID4          :1;           /* bit 4 */
    byte SCID5          :1;           /* bit 5 */
    byte SCID6          :1;           /* bit 6 */
    byte SCID7          :1;           /* bit 7 */
  } Bits;
} SCIDSTR;
extern volatile SCIDSTR _SCID @(D2DREG_BASE + 0x1F);
#define SCID _SCID.Byte


/*** TIOS - Timer Input Capture/Output Compare Select; 0x20 ******************/
typedef union {
  byte Byte;
  struct {
    byte IOS0           :1;           /* bit 0 */
    byte IOS1           :1;           /* bit 1 */
    byte IOS2           :1;           /* bit 2 */
    byte IOS3           :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} TIOSSTR;
extern volatile TIOSSTR _TIOS @(D2DREG_BASE + 0x20);
#define TIOS _TIOS.Byte


/*** CFORC - Timer Compare Force Register; 0x21 ******************************/
typedef union {
  byte Byte;
  struct {
    byte FOC0           :1;           /* bit 0 */
    byte FOC1           :1;           /* bit 1 */
    byte FOC2           :1;           /* bit 2 */
    byte FOC3           :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} CFORCSTR;
extern volatile CFORCSTR _CFORC @(D2DREG_BASE + 0x21);
#define CFORC _CFORC.Byte


/*** OC3M - Output Compare 3 Mask Register; 0x22 *****************************/
typedef union {
  byte Byte;
  struct {
    byte OC3M0          :1;           /* bit 0 */
    byte OC3M1          :1;           /* bit 1 */
    byte OC3M2          :1;           /* bit 2 */
    byte OC3M3          :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} OC3MSTR;
extern volatile OC3MSTR _OC3M @(D2DREG_BASE + 0x22);
#define OC3M _OC3M.Byte


/*** OC3D - Output Compare 3 Data Register; 0x23 *****************************/
typedef union {
  byte Byte;
  struct {
    byte OC3D0          :1;           /* bit 0 */
    byte OC3D1          :1;           /* bit 1 */
    byte OC3D2          :1;           /* bit 2 */
    byte OC3D3          :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} OC3DSTR;
extern volatile OC3DSTR _OC3D @(D2DREG_BASE + 0x23);
#define OC3D _OC3D.Byte


/*** TCNT - Timer Count Register; 0x24 ***************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TCNTH - Timer Count High Register; 0x24 ***/
    union {
      byte Byte;
      struct {
        byte TCNT8      :1;           /* Bit 0 */    
        byte TCNT9      :1;           /* Bit 1 */
        byte TCNT10     :1;           /* Bit 2 */
        byte TCNT11     :1;           /* Bit 3 */
        byte TCNT12     :1;           /* Bit 4 */
        byte TCNT13     :1;           /* Bit 5 */
        byte TCNT14     :1;           /* Bit 6 */
        byte TCNT15     :1;           /* Bit 7 */
      } Bits;
    } TCNTHSTR;
    #define TCNTH _TCNT.Overlap_STR.TCNTHSTR.Byte

    /*** TCNTL - Timer Count Low Register; 0x25 ***/
    union {
      byte Byte;
      struct {
        byte TCNT0      :1;           /* Bit 0 */
        byte TCNT1      :1;           /* Bit 1 */
        byte TCNT2      :1;           /* Bit 2 */
        byte TCNT3      :1;           /* Bit 3 */
        byte TCNT4      :1;           /* Bit 4 */
        byte TCNT5      :1;           /* Bit 5 */
        byte TCNT6      :1;           /* Bit 6 */
        byte TCNT7      :1;           /* Bit 7 */
      } Bits;
    } TCNTLSTR;
    #define TCNTL _TCNT.Overlap_STR.TCNTLSTR.Byte

  } Overlap_STR;

  struct {
    word TCNT0          :1;           /* bit 0 */
    word TCNT1          :1;           /* bit 1 */
    word TCNT2          :1;           /* bit 2 */
    word TCNT3          :1;           /* bit 3 */
    word TCNT4          :1;           /* bit 4 */
    word TCNT5          :1;           /* bit 5 */
    word TCNT6          :1;           /* bit 6 */
    word TCNT7          :1;           /* bit 7 */
    word TCNT8          :1;           /* bit 8 */
    word TCNT9          :1;           /* bit 9 */
    word TCNT10         :1;           /* bit 10 */
    word TCNT11         :1;           /* bit 11 */
    word TCNT12         :1;           /* bit 12 */
    word TCNT13         :1;           /* bit 13 */
    word TCNT14         :1;           /* bit 14 */
    word TCNT15         :1;           /* bit 15 */
  } Bits;
} TCNTSTR;
extern volatile TCNTSTR _TCNT @(D2DREG_BASE + 0x24);
#define TCNT _TCNT.Word


/*** TSCR1 - Timer System Control Register 1; 0x26 ***************************/
typedef union {
  byte Byte;
  struct {
    byte                :1;           /* bit 0 */
    byte                :1;           /* bit 1 */
    byte                :1;           /* bit 2 */
    byte                :1;           /* bit 3 */
    byte TFFCA          :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte TEN            :1;           /* bit 7 */
  } Bits;
} TSCR1STR;
extern volatile TSCR1STR _TSCR1 @(D2DREG_BASE + 0x26);
#define TSCR1 _TSCR1.Byte



/*** TTOV - Timer Toggle Overflow Register; 0x27 *****************************/
typedef union {
  byte Byte;
  struct {
    byte TOV0           :1;           /* bit 0 */
    byte TOV1           :1;           /* bit 1 */
    byte TOV2           :1;           /* bit 2 */
    byte TOV3           :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} TTOVSTR;
extern volatile TTOVSTR _TTOV @(D2DREG_BASE + 0x27);
#define TTOV _TTOV.Byte


/*** TCTL1 - Timer Control Register 1; 0x28 **********************************/
typedef union {
  byte Byte;
  struct {
    byte OL0            :1;           /* bit 0 */
    byte OM0            :1;           /* bit 1 */
    byte OL1            :1;           /* bit 2 */
    byte OM1            :1;           /* bit 3 */
    byte OL2            :1;           /* bit 4 */
    byte OM2            :1;           /* bit 5 */
    byte OL3            :1;           /* bit 6 */
    byte OM3            :1;           /* bit 7 */
  } Bits;
} TCTL1STR;
extern volatile TCTL1STR _TCTL1 @(D2DREG_BASE + 0x28);
#define TCTL1 _TCTL1.Byte


/*** TCTL2 - Timer Control Register 2; 0x29 **********************************/
typedef union {
  byte Byte;
  struct {
    byte EDG0A          :1;           /* bit 0 */
    byte EDG0B          :1;           /* bit 1 */
    byte EDG1A          :1;           /* bit 2 */
    byte EDG1B          :1;           /* bit 3 */
    byte EDG2A          :1;           /* bit 4 */
    byte EDG2B          :1;           /* bit 5 */
    byte EDG3A          :1;           /* bit 6 */
    byte EDG3B          :1;           /* bit 7 */
  } Bits;
} TCTL2STR;
extern volatile TCTL2STR _TCTL2 @(D2DREG_BASE + 0x29);
#define TCTL2 _TCTL2.Byte


/*** TIE - Timer Interrupt Enable Register; 0x2A *****************************/
typedef union {
  byte Byte;
  struct {
    byte C0I            :1;           /* bit 0 */
    byte C1I            :1;           /* bit 1 */
    byte C2I            :1;           /* bit 2 */
    byte C3I            :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} TIESTR;
extern volatile TIESTR _TIE @(D2DREG_BASE + 0x2A);
#define TIE _TIE.Byte


/*** TSCR2 - Timer System Control Register 2; 0x2B ***************************/
typedef union {
  byte Byte;
  struct {
    byte PR0            :1;           /* bit 0 */
    byte PR1            :1;           /* bit 1 */
    byte PR2            :1;           /* bit 2 */
    byte TCRE           :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte TOI            :1;           /* bit 7 */
  } Bits;
} TSCR2STR;
extern volatile TSCR2STR _TSCR2 @(D2DREG_BASE + 0x2B);
#define TSCR2 _TSCR2.Byte


/*** TFLG1 - Main Timer Interrupt Flag 1; 0x2C *******************************/
typedef union {
  byte Byte;
  struct {
    byte C0F            :1;           /* bit 0 */
    byte C1F            :1;           /* bit 1 */
    byte C2F            :1;           /* bit 2 */
    byte C3F            :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} TFLG1STR;
extern volatile TFLG1STR _TFLG1 @(D2DREG_BASE + 0x2C);
#define TFLG1 _TFLG1.Byte


/*** TFLG2 - Main Timer Interrupt Flag 2; 0x2D *******************************/
typedef union {
  byte Byte;
  struct {
    byte                :1;           /* bit 0 */
    byte                :1;           /* bit 1 */
    byte                :1;           /* bit 2 */
    byte                :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte TOF            :1;           /* bit 7 */
  } Bits;
} TFLG2STR;
extern volatile TFLG2STR _TFLG2 @(D2DREG_BASE + 0x2D);
#define TFLG2 _TFLG2.Byte


/*** TC0 - Timer Input Capture/Output Compare Register 0; 0x2E ***************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC0H - Timer Input Capture/Output Compare High Register 0; 0x2E ***/
    union {
      byte Byte;
      struct {
        byte TC0_8      :1;           /* Bit 0 */    
        byte TC0_9      :1;           /* Bit 1 */
        byte TC0_10     :1;           /* Bit 2 */
        byte TC0_11     :1;           /* Bit 3 */
        byte TC0_12     :1;           /* Bit 4 */
        byte TC0_13     :1;           /* Bit 5 */
        byte TC0_14     :1;           /* Bit 6 */
        byte TC0_15     :1;           /* Bit 7 */
      } Bits;
    } TC0HSTR;
    #define TC0H _TC0.Overlap_STR.TC0HSTR.Byte

    /*** TC0L - Timer Input Capture/Output Compare Low Register 0; 0x2F ***/
    union {
      byte Byte;
      struct {
        byte TC0_0      :1;           /* Bit 0 */
        byte TC0_1      :1;           /* Bit 1 */
        byte TC0_2      :1;           /* Bit 2 */
        byte TC0_3      :1;           /* Bit 3 */
        byte TC0_4      :1;           /* Bit 4 */
        byte TC0_5      :1;           /* Bit 5 */
        byte TC0_6      :1;           /* Bit 6 */
        byte TC0_7      :1;           /* Bit 7 */
      } Bits;
    } TC0LSTR;
    #define TC0L _TC0.Overlap_STR.TC0LSTR.Byte

  } Overlap_STR;

  struct {
    word TC0_0          :1;           /* bit 0 */
    word TC0_1          :1;           /* bit 1 */
    word TC0_2          :1;           /* bit 2 */
    word TC0_3          :1;           /* bit 3 */
    word TC0_4          :1;           /* bit 4 */
    word TC0_5          :1;           /* bit 5 */
    word TC0_6          :1;           /* bit 6 */
    word TC0_7          :1;           /* bit 7 */
    word TC0_8          :1;           /* bit 8 */
    word TC0_9          :1;           /* bit 9 */
    word TC0_10         :1;           /* bit 10 */
    word TC0_11         :1;           /* bit 11 */
    word TC0_12         :1;           /* bit 12 */
    word TC0_13         :1;           /* bit 13 */
    word TC0_14         :1;           /* bit 14 */
    word TC0_15         :1;           /* bit 15 */
  } Bits;
} TC0STR;
extern volatile TC0STR _TC0 @(D2DREG_BASE + 0x2E);
#define TC0 _TC0.Word


/*** TC1 - Timer Input Capture/Output Compare Register 1; 0x30 ***************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC1H - Timer Input Capture/Output Compare High Register 1; 0x30 ***/
    union {
      byte Byte;
      struct {
        byte TC1_8      :1;           /* Bit 0 */    
        byte TC1_9      :1;           /* Bit 1 */
        byte TC1_10     :1;           /* Bit 2 */
        byte TC1_11     :1;           /* Bit 3 */
        byte TC1_12     :1;           /* Bit 4 */
        byte TC1_13     :1;           /* Bit 5 */
        byte TC1_14     :1;           /* Bit 6 */
        byte TC1_15     :1;           /* Bit 7 */
      } Bits;
    } TC1HSTR;
    #define TC1H _TC1.Overlap_STR.TC1HSTR.Byte

    /*** TC1L - Timer Input Capture/Output Compare Low Register 1; 0x31 ***/
    union {
      byte Byte;
      struct {
        byte TC1_0      :1;           /* Bit 0 */
        byte TC1_1      :1;           /* Bit 1 */
        byte TC1_2      :1;           /* Bit 2 */
        byte TC1_3      :1;           /* Bit 3 */
        byte TC1_4      :1;           /* Bit 4 */
        byte TC1_5      :1;           /* Bit 5 */
        byte TC1_6      :1;           /* Bit 6 */
        byte TC1_7      :1;           /* Bit 7 */
      } Bits;
    } TC1LSTR;
    #define TC1L _TC1.Overlap_STR.TC1LSTR.Byte

  } Overlap_STR;

  struct {
    word TC1_0          :1;           /* bit 0 */
    word TC1_1          :1;           /* bit 1 */
    word TC1_2          :1;           /* bit 2 */
    word TC1_3          :1;           /* bit 3 */
    word TC1_4          :1;           /* bit 4 */
    word TC1_5          :1;           /* bit 5 */
    word TC1_6          :1;           /* bit 6 */
    word TC1_7          :1;           /* bit 7 */
    word TC1_8          :1;           /* bit 8 */
    word TC1_9          :1;           /* bit 9 */
    word TC1_10         :1;           /* bit 10 */
    word TC1_11         :1;           /* bit 11 */
    word TC1_12         :1;           /* bit 12 */
    word TC1_13         :1;           /* bit 13 */
    word TC1_14         :1;           /* bit 14 */
    word TC1_15         :1;           /* bit 15 */
  } Bits;
} TC1STR;
extern volatile TC1STR _TC1 @(D2DREG_BASE + 0x30);
#define TC1 _TC1.Word


/*** TC2 - Timer Input Capture/Output Compare Register 2; 0x32 ***************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC2H - Timer Input Capture/Output Compare High Register 2; 0x32 ***/
    union {
      byte Byte;
      struct {
        byte TC2_8      :1;           /* Bit 0 */    
        byte TC2_9      :1;           /* Bit 1 */
        byte TC2_10     :1;           /* Bit 2 */
        byte TC2_11     :1;           /* Bit 3 */
        byte TC2_12     :1;           /* Bit 4 */
        byte TC2_13     :1;           /* Bit 5 */
        byte TC2_14     :1;           /* Bit 6 */
        byte TC2_15     :1;           /* Bit 7 */
      } Bits;
    } TC2HSTR;
    #define TC2H _TC2.Overlap_STR.TC2HSTR.Byte

    /*** TC2L - Timer Input Capture/Output Compare Low Register 2; 0x33 ***/
    union {
      byte Byte;
      struct {
        byte TC2_0      :1;           /* Bit 0 */
        byte TC2_1      :1;           /* Bit 1 */
        byte TC2_2      :1;           /* Bit 2 */
        byte TC2_3      :1;           /* Bit 3 */
        byte TC2_4      :1;           /* Bit 4 */
        byte TC2_5      :1;           /* Bit 5 */
        byte TC2_6      :1;           /* Bit 6 */
        byte TC2_7      :1;           /* Bit 7 */
      } Bits;
    } TC2LSTR;
    #define TC2L _TC2.Overlap_STR.TC2LSTR.Byte

  } Overlap_STR;

  struct {
    word TC2_0          :1;           /* bit 0 */
    word TC2_1          :1;           /* bit 1 */
    word TC2_2          :1;           /* bit 2 */
    word TC2_3          :1;           /* bit 3 */
    word TC2_4          :1;           /* bit 4 */
    word TC2_5          :1;           /* bit 5 */
    word TC2_6          :1;           /* bit 6 */
    word TC2_7          :1;           /* bit 7 */
    word TC2_8          :1;           /* bit 8 */
    word TC2_9          :1;           /* bit 9 */
    word TC2_10         :1;           /* bit 10 */
    word TC2_11         :1;           /* bit 11 */
    word TC2_12         :1;           /* bit 12 */
    word TC2_13         :1;           /* bit 13 */
    word TC2_14         :1;           /* bit 14 */
    word TC2_15         :1;           /* bit 15 */
  } Bits;
} TC2STR;
extern volatile TC2STR _TC2 @(D2DREG_BASE + 0x32);
#define TC2 _TC2.Word


/*** TC3 - Timer Input Capture/Output Compare Register 3; 0x34 ***************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC3H - Timer Input Capture/Output Compare High Register 3; 0x34 ***/
    union {
      byte Byte;
      struct {
        byte TC3_8      :1;           /* Bit 0 */    
        byte TC3_9      :1;           /* Bit 1 */
        byte TC3_10     :1;           /* Bit 2 */
        byte TC3_11     :1;           /* Bit 3 */
        byte TC3_12     :1;           /* Bit 4 */
        byte TC3_13     :1;           /* Bit 5 */
        byte TC3_14     :1;           /* Bit 6 */
        byte TC3_15     :1;           /* Bit 7 */
      } Bits;
    } TC3HSTR;
    #define TC3H _TC3.Overlap_STR.TC3HSTR.Byte

    /*** TC3L - Timer Input Capture/Output Compare Low Register 3; 0x35 ***/
    union {
      byte Byte;
      struct {
        byte TC3_0      :1;           /* Bit 0 */
        byte TC3_1      :1;           /* Bit 1 */
        byte TC3_2      :1;           /* Bit 2 */
        byte TC3_3      :1;           /* Bit 3 */
        byte TC3_4      :1;           /* Bit 4 */
        byte TC3_5      :1;           /* Bit 5 */
        byte TC3_6      :1;           /* Bit 6 */
        byte TC3_7      :1;           /* Bit 7 */
      } Bits;
    } TC3LSTR;
    #define TC3L _TC3.Overlap_STR.TC3LSTR.Byte

  } Overlap_STR;

  struct {
    word TC3_0          :1;           /* bit 0 */
    word TC3_1          :1;           /* bit 1 */
    word TC3_2          :1;           /* bit 2 */
    word TC3_3          :1;           /* bit 3 */
    word TC3_4          :1;           /* bit 4 */
    word TC3_5          :1;           /* bit 5 */
    word TC3_6          :1;           /* bit 6 */
    word TC3_7          :1;           /* bit 7 */
    word TC3_8          :1;           /* bit 8 */
    word TC3_9          :1;           /* bit 9 */
    word TC3_10         :1;           /* bit 10 */
    word TC3_11         :1;           /* bit 11 */
    word TC3_12         :1;           /* bit 12 */
    word TC3_13         :1;           /* bit 13 */
    word TC3_14         :1;           /* bit 14 */
    word TC3_15         :1;           /* bit 15 */
  } Bits;
} TC3STR;
extern volatile TC3STR _TC3 @(D2DREG_BASE + 0x34);
#define TC3 _TC3.Word


/*** LTC_CTL - Life Time Counter control register; 0x38 **********************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LTC_CTLH - Life Time Counter control high register; 0x38 ***/
    union {
      byte Byte;
      struct {
        byte LTCEM      :1;           /* Bit 0 */    
        byte            :1;           /* Bit 1 */
        byte            :1;           /* Bit 2 */
        byte            :1;           /* Bit 3 */
        byte            :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte LTCIEM     :1;           /* Bit 7 */
      } Bits;
    } LTC_CTLHSTR;
    #define LTC_CTLH _LTC_CTL.Overlap_STR.LTC_CTLHSTR.Byte

    /*** LTC_CTLL - Life Time Counter control low register; 0x39 ***/
    union {
      byte Byte;
      struct {
        byte LTCE       :1;           /* Bit 0 */
        byte            :1;           /* Bit 1 */
        byte            :1;           /* Bit 2 */
        byte            :1;           /* Bit 3 */
        byte            :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte LTCIE      :1;           /* Bit 7 */
      } Bits;
    } LTC_CTLLSTR;
    #define LTC_CTLL _LTC_CTL.Overlap_STR.LTC_CTLLSTR.Byte

  } Overlap_STR;

  struct {
    word LTCE           :1;           /* bit 0 */
    word                :1;           /* bit 1 */
    word                :1;           /* bit 2 */
    word                :1;           /* bit 3 */
    word                :1;           /* bit 4 */
    word                :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word LTCIE          :1;           /* bit 7 */
    word LTCEM          :1;           /* bit 8 */
    word                :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word LTCIEM         :1;           /* bit 15 */
  } Bits;
} LTC_CTLSTR;
extern volatile LTC_CTLSTR _LTC_CTL @(D2DREG_BASE + 0x38);
#define LTC_CTL _LTC_CTL.Word


/*** LTC_SR - Life Time Counter Status register; 0x3A ************************/
typedef union {
  byte Byte;
  struct {
    byte                :1;           /* bit 0 */
    byte                :1;           /* bit 1 */
    byte                :1;           /* bit 2 */
    byte                :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte LTCOF          :1;           /* bit 7 */
  } Bits;
} LTC_SRSTR;
extern volatile LTC_SRSTR _LTC_SR @(D2DREG_BASE + 0x3A);
#define LTC_SR _LTC_SR.Byte


/*** LTC_CNT1 - Life Time Counter Register 1; 0x3C ***************************/
typedef union {
  word Word;
  struct {
    word LTC16          :1;           /* bit 0 */
    word LTC17          :1;           /* bit 1 */
    word LTC18          :1;           /* bit 2 */
    word LTC19          :1;           /* bit 3 */
    word LTC20          :1;           /* bit 4 */
    word LTC21          :1;           /* bit 5 */
    word LTC22          :1;           /* bit 6 */
    word LTC23          :1;           /* bit 7 */
    word LTC24          :1;           /* bit 8 */
    word LTC25          :1;           /* bit 9 */
    word LTC26          :1;           /* bit 10 */
    word LTC27          :1;           /* bit 11 */
    word LTC28          :1;           /* bit 12 */
    word LTC29          :1;           /* bit 13 */
    word LTC30          :1;           /* bit 14 */
    word LTC31          :1;           /* bit 15 */
  } Bits;
} LTC_CNT1STR;
extern volatile LTC_CNT1STR _LTC_CNT1 @(D2DREG_BASE + 0x3C);
#define LTC_CNT1 _LTC_CNT1.Word


/*** LTC_CNT0 - Life Time Counter Register 0; 0x3E ***************************/
typedef union {
  word Word;
  struct {
    word LTC0           :1;           /* bit 0 */
    word LTC1           :1;           /* bit 1 */
    word LTC2           :1;           /* bit 2 */
    word LTC3           :1;           /* bit 3 */
    word LTC4           :1;           /* bit 4 */
    word LTC5           :1;           /* bit 5 */
    word LTC6           :1;           /* bit 6 */
    word LTC7           :1;           /* bit 7 */
    word LTC8           :1;           /* bit 8 */
    word LTC9           :1;           /* bit 9 */
    word LTC10          :1;           /* bit 10 */
    word LTC11          :1;           /* bit 11 */
    word LTC12          :1;           /* bit 12 */
    word LTC13          :1;           /* bit 13 */
    word LTC14          :1;           /* bit 14 */
    word LTC15          :1;           /* bit 15 */
  } Bits;
} LTC_CNT0STR;
extern volatile LTC_CNT0STR _LTC_CNT0 @(D2DREG_BASE + 0x3E);
#define LTC_CNT0 _LTC_CNT0.Word


/*** GPIO_CTL - GPIO control register; 0x40 **********************************/
typedef union {
  word Word;
  struct {
    word PE0            :1;           /* bit 0 */
    word PE1            :1;           /* bit 1 */
    word PE2            :1;           /* bit 2 */
    word PE3            :1;           /* bit 3 */
    word DIR0           :1;           /* bit 4 */
    word DIR1           :1;           /* bit 5 */
    word DIR2           :1;           /* bit 6 */
    word                :1;           /* bit 7 */
    word PE0M           :1;           /* bit 8 */
    word PE1M           :1;           /* bit 9 */
    word PE2M           :1;           /* bit 10 */
    word PE3M           :1;           /* bit 11 */
    word DIR0M          :1;           /* bit 12 */
    word DIR1M          :1;           /* bit 13 */
    word DIR2M          :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} GPIO_CTLSTR;
extern volatile GPIO_CTLSTR _GPIO_CTL @(D2DREG_BASE + 0x40);
#define GPIO_CTL _GPIO_CTL.Word

									
/*** GPIO_PUC - GPIO pull up configuration; 0x42 *****************************/
typedef union {
  byte Byte;
  struct {
    byte PUE0           :1;           /* bit 0 */
    byte PUE1           :1;           /* bit 1 */
    byte PUE2           :1;           /* bit 2 */
    byte PDE3           :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} GPIO_PUCSTR;
extern volatile GPIO_PUCSTR _GPIO_PUC @(D2DREG_BASE + 0x42);
#define GPIO_PUC _GPIO_PUC.Byte


/*** GPIO_DATA - GPIO port data register; 0x43 *******************************/
typedef union {
  byte Byte;
  struct {
    byte PD0            :1;           /* bit 0 */
    byte PD1            :1;           /* bit 1 */
    byte PD2            :1;           /* bit 2 */
    byte PD3            :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} GPIO_DATASTR;
extern volatile GPIO_DATASTR _GPIO_DATA @(D2DREG_BASE + 0x43);
#define GPIO_DATA _GPIO_DATA.Byte


/*** GPIO_IO0 - Port 0 I/O configuration; 0x44 *******************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** GPIO_IN0 - Port 0 input configuration; 0x44 ***/
    union {
      byte Byte;
      struct {
        byte            :1;           /* Bit 0 */    
        byte LINTX      :1;           /* Bit 1 */
        byte SCIRX      :1;           /* Bit 2 */
        byte TCAP0      :1;           /* Bit 3 */
        byte TCAP1      :1;           /* Bit 4 */
        byte TCAP2      :1;           /* Bit 5 */
        byte TCAP3      :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } GPIO_IN0STR;
    #define GPIO_IN0 _GPIO_IO0.Overlap_STR.GPIO_IN0STR.Byte

    /*** GPIO_OUT0 - Port 0 output configuration; 0x45 ***/
    union {
      byte Byte;
      struct {
        byte PTBX0      :1;           /* Bit 0 */
        byte LINRX      :1;           /* Bit 1 */
        byte SCITX      :1;           /* Bit 2 */
        byte TCOMP0     :1;           /* Bit 3 */
        byte TCOMP1     :1;           /* Bit 4 */
        byte TCOMP2     :1;           /* Bit 5 */
        byte TCOMP3     :1;           /* Bit 6 */
        byte WKUP       :1;           /* Bit 7 */
      } Bits;
    } GPIO_OUT0STR;
    #define GPIO_OUT0 _GPIO_IO0.Overlap_STR.GPIO_OUT0STR.Byte

  } Overlap_STR;

  struct {
    word PTBX0          :1;           /* bit 0 */
    word LINRX          :1;           /* bit 1 */
    word SCITX          :1;           /* bit 2 */
    word TCOMP0         :1;           /* bit 3 */
    word TCOMP1         :1;           /* bit 4 */
    word TCOMP2         :1;           /* bit 5 */
    word TCOMP3         :1;           /* bit 6 */
    word WKUP           :1;           /* bit 7 */
    word                :1;           /* bit 8 */
    word LINTX          :1;           /* bit 9 */
    word SCIRX          :1;           /* bit 10 */
    word TCAP0          :1;           /* bit 11 */
    word TCAP1          :1;           /* bit 12 */
    word TCAP2          :1;           /* bit 13 */
    word TCAP3          :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} GPIO_IO0STR;
extern volatile GPIO_IO0STR _GPIO_IO0 @(D2DREG_BASE + 0x44);
#define GPIO_IO0 _GPIO_IO0.Word


/*** GPIO_IO1 - Port 1 I/O configuration; 0x46 *******************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** GPIO_IN1 - Port 1 input configuration; 0x46 ***/
    union {
      byte Byte;
      struct {
        byte            :1;           /* Bit 0 */    
        byte LINTX      :1;           /* Bit 1 */
        byte SCIRX      :1;           /* Bit 2 */
        byte TCAP0      :1;           /* Bit 3 */
        byte TCAP1      :1;           /* Bit 4 */
        byte TCAP2      :1;           /* Bit 5 */
        byte TCAP3      :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } GPIO_IN1STR;
    #define GPIO_IN1 _GPIO_IO1.Overlap_STR.GPIO_IN1STR.Byte

    /*** GPIO_OUT1 - Port 1 output configuration; 0x47 ***/
    union {
      byte Byte;
      struct {
        byte PTBX1      :1;           /* Bit 0 */
        byte LINRX      :1;           /* Bit 1 */
        byte SCITX      :1;           /* Bit 2 */
        byte TCOMP0     :1;           /* Bit 3 */
        byte TCOMP1     :1;           /* Bit 4 */
        byte TCOMP2     :1;           /* Bit 5 */
        byte TCOMP3     :1;           /* Bit 6 */
        byte WKUP       :1;           /* Bit 7 */
      } Bits;
    } GPIO_OUT1STR;
    #define GPIO_OUT1 _GPIO_IO1.Overlap_STR.GPIO_OUT1STR.Byte

  } Overlap_STR;

  struct {
    word PTBX1          :1;           /* bit 0 */
    word LINRX          :1;           /* bit 1 */
    word SCITX          :1;           /* bit 2 */
    word TCOMP0         :1;           /* bit 3 */
    word TCOMP1         :1;           /* bit 4 */
    word TCOMP2         :1;           /* bit 5 */
    word TCOMP3         :1;           /* bit 6 */
    word WKUP           :1;           /* bit 7 */
    word                :1;           /* bit 8 */
    word LINTX          :1;           /* bit 9 */
    word SCIRX          :1;           /* bit 10 */
    word TCAP0          :1;           /* bit 11 */
    word TCAP1          :1;           /* bit 12 */
    word TCAP2          :1;           /* bit 13 */
    word TCAP3          :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} GPIO_IO1STR;
extern volatile GPIO_IO1STR _GPIO_IO1 @(D2DREG_BASE + 0x46);
#define GPIO_IO1 _GPIO_IO1.Word
         
         
/*** GPIO_IO2 - Port 2 I/O configuration; 0x48 *******************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** GPIO_IN2 - Port 2 input configuration; 0x48 ***/
    union {
      byte Byte;
      struct {
        byte            :1;           /* Bit 0 */    
        byte LINTX      :1;           /* Bit 1 */
        byte SCIRX      :1;           /* Bit 2 */
        byte TCAP0      :1;           /* Bit 3 */
        byte TCAP1      :1;           /* Bit 4 */
        byte TCAP2      :1;           /* Bit 5 */
        byte TCAP3      :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } GPIO_IN2STR;
    #define GPIO_IN2 _GPIO_IO2.Overlap_STR.GPIO_IN2STR.Byte

    /*** GPIO_OUT2 - Port 2 output configuration; 0x49 ***/
    union {
      byte Byte;
      struct {
        byte PTBX1      :1;           /* Bit 0 */
        byte LINRX      :1;           /* Bit 1 */
        byte SCITX      :1;           /* Bit 2 */
        byte TCOMP0     :1;           /* Bit 3 */
        byte TCOMP1     :1;           /* Bit 4 */
        byte TCOMP2     :1;           /* Bit 5 */
        byte TCOMP3     :1;           /* Bit 6 */
        byte WKUP       :1;           /* Bit 7 */
      } Bits;
    } GPIO_OUT2STR;
    #define GPIO_OUT2 _GPIO_IO2.Overlap_STR.GPIO_OUT2STR.Byte

  } Overlap_STR;

  struct {
    word PTBX2          :1;           /* bit 0 */
    word LINRX          :1;           /* bit 1 */
    word SCITX          :1;           /* bit 2 */
    word TCOMP0         :1;           /* bit 3 */
    word TCOMP1         :1;           /* bit 4 */
    word TCOMP2         :1;           /* bit 5 */
    word TCOMP3         :1;           /* bit 6 */
    word WKUP           :1;           /* bit 7 */
    word                :1;           /* bit 8 */
    word LINTX          :1;           /* bit 9 */
    word SCIRX          :1;           /* bit 10 */
    word TCAP0          :1;           /* bit 11 */
    word TCAP1          :1;           /* bit 12 */
    word TCAP2          :1;           /* bit 13 */
    word TCAP3          :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} GPIO_IO2STR;
extern volatile GPIO_IO2STR _GPIO_IO2 @(D2DREG_BASE + 0x48);
#define GPIO_IO2 _GPIO_IO2.Word


/*** GPIO_I3 - Port 3 I configuration; 0x4A **********************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** GPIO_IN3 - Port 3 input configuration; 0x4A ***/
    union {
      byte Byte;
      struct {
        byte            :1;           /* Bit 0 */    
        byte            :1;           /* Bit 1 */
        byte            :1;           /* Bit 2 */
        byte TCAP0      :1;           /* Bit 3 */
        byte TCAP1      :1;           /* Bit 4 */
        byte TCAP2      :1;           /* Bit 5 */
        byte TCAP3      :1;           /* Bit 6 */
        byte PTWU       :1;           /* Bit 7 */
      } Bits;
    } GPIO_IN3STR;
    #define GPIO_IN3 _GPIO_I3.Overlap_STR.GPIO_IN3STR.Byte

    /*** RESERVED; 0x4B ***/
    union {
      byte Byte;
      struct {
        byte            :1;           /* Bit 0 */
        byte            :1;           /* Bit 1 */
        byte            :1;           /* Bit 2 */
        byte            :1;           /* Bit 3 */
        byte            :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } GPIO_RESSTR;
    #define GPIO_RES _GPIO_I3.Overlap_STR.GPIO_RESSTR.Byte

  } Overlap_STR;

  struct {
    word                :1;           /* bit 0 */
    word                :1;           /* bit 1 */
    word                :1;           /* bit 2 */
    word                :1;           /* bit 3 */
    word                :1;           /* bit 4 */
    word                :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word                :1;           /* bit 7 */
    word                :1;           /* bit 8 */
    word                :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word TCAP0          :1;           /* bit 11 */
    word TCAP1          :1;           /* bit 12 */
    word TCAP2          :1;           /* bit 13 */
    word TCAP3          :1;           /* bit 14 */
    word PTWU           :1;           /* bit 15 */
  } Bits;
} GPIO_I3STR;
extern volatile GPIO_I3STR _GPIO_I3 @(D2DREG_BASE + 0x4A);
#define GPIO_I3 _GPIO_I3.Word

         
/*** LIN_CTL - LIN control register; 0x50 ************************************/
typedef union {
  word Word;
  struct {
    word SRS0           :1;           /* bit 0 */
    word SRS1           :1;           /* bit 1 */
    word EN             :1;           /* bit 2 */
    word LVSD           :1;           /* bit 3 */
    word TXD            :1;           /* bit 4 */
    word                :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word OTIE           :1;           /* bit 7 */
    word SRSM0          :1;           /* bit 8 */
    word SRSM1          :1;           /* bit 9 */
    word ENM            :1;           /* bit 10 */
    word LVSDM          :1;           /* bit 11 */
    word TXDM           :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word OTIEM          :1;           /* bit 15 */
  } Bits;
} LIN_CTLSTR;
extern volatile LIN_CTLSTR _LIN_CTL @(D2DREG_BASE + 0x50);
#define LIN_CTL _LIN_CTL.Word


/*** LIN_SR - LIN status register; 0x52 **************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LIN_SRH - LIN status high register; 0x52 ***/
    union {
      byte Byte;
      struct {
        byte            :1;           /* Bit 0 */    
        byte            :1;           /* Bit 1 */
        byte            :1;           /* Bit 2 */
        byte UV         :1;           /* Bit 3 */
        byte            :1;           /* Bit 4 */
        byte HF         :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte OT         :1;           /* Bit 7 */
      } Bits;
    } LIN_SRHSTR;
    #define LIN_SRH _LIN_SR.Overlap_STR.LIN_SRHSTR.Byte

    /*** LIN_SRL - LIN status low register; 0x53 ***/
    union {
      byte Byte;
      struct {
        byte TX         :1;           /* Bit 0 */
        byte RX         :1;           /* Bit 1 */
        byte            :1;           /* Bit 2 */
        byte            :1;           /* Bit 3 */
        byte            :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte RDY        :1;           /* Bit 7 */
      } Bits;
    } LIN_SRLSTR;
    #define LIN_SRL _LIN_SR.Overlap_STR.LIN_SRLSTR.Byte

  } Overlap_STR;

  struct {
    word TX             :1;           /* bit 0 */
    word RX             :1;           /* bit 1 */
    word                :1;           /* bit 2 */
    word                :1;           /* bit 3 */
    word                :1;           /* bit 4 */
    word                :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word RDY            :1;           /* bit 7 */
    word                :1;           /* bit 8 */
    word                :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word UV             :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word HF             :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word OT             :1;           /* bit 15 */
  } Bits;
} LIN_SRSTR;
extern volatile LIN_SRSTR _LIN_SR @(D2DREG_BASE + 0x52);
#define LIN_SR _LIN_SR.Word									


/*** LIN_RXTX - LIN Rx/TX line definition; 0x54 ******************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LIN_TX - LIN transmit line definition; 0x54 ***/
    union {
      byte Byte;
      struct {
        byte FROMSCI    :1;           /* Bit 0 */    
        byte FROMPTB    :1;           /* Bit 1 */
        byte            :1;           /* Bit 2 */
        byte            :1;           /* Bit 3 */
        byte            :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } LIN_TXSTR;
    #define LIN_TX _LIN_RXTX.Overlap_STR.LIN_TXSTR.Byte

    /*** LIN_RX - LIN receive line definition; 0x55 ***/
    union {
      byte Byte;
      struct {
        byte TOSCI      :1;           /* Bit 0 */
        byte TOPTB      :1;           /* Bit 1 */
        byte            :1;           /* Bit 2 */
        byte            :1;           /* Bit 3 */
        byte            :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } LIN_RXSTR;
    #define LIN_RX _LIN_RXTX.Overlap_STR.LIN_RXSTR.Byte

  } Overlap_STR;

  struct {
    word TOSCI          :1;           /* bit 0 */
    word TOPTB          :1;           /* bit 1 */
    word                :1;           /* bit 2 */
    word                :1;           /* bit 3 */
    word                :1;           /* bit 4 */
    word                :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word                :1;           /* bit 7 */
    word FROMSCI        :1;           /* bit 8 */
    word FROMPTB        :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} LIN_RXTXSTR;
extern volatile LIN_RXTXSTR _LIN_RXTX @(D2DREG_BASE + 0x54);
#define LIN_RXTX _LIN_RXTX.Word


/*** ACQ_CTL - Acquisition control register; 0x58 ****************************/
typedef union {
  word Word;
  struct {
    word CMEN           :1;           /* bit 0 */
    word VMEN           :1;           /* bit 1 */
    word ITMEN          :1;           /* bit 2 */
    word ETMEN          :1;           /* bit 3 */
    word CVMIE          :1;           /* bit 4 */
    word OPENE          :1;           /* bit 5 */
    word OPTE           :1;           /* bit 6 */
    word AHCR           :1;           /* bit 7 */
    word CMENM          :1;           /* bit 8 */
    word VMENM          :1;           /* bit 9 */
    word ITMENM         :1;           /* bit 10 */
    word ETMENM         :1;           /* bit 11 */
    word CVMIEM         :1;           /* bit 12 */
    word OPENEM         :1;           /* bit 13 */
    word OPTEM          :1;           /* bit 14 */
    word AHCRM          :1;           /* bit 15 */
  } Bits;
} ACQ_CTLSTR;
extern volatile ACQ_CTLSTR _ACQ_CTL @(D2DREG_BASE + 0x58);
#define ACQ_CTL _ACQ_CTL.Word
									

/*** ACQ_SR - Acquisition status register; 0x5A ******************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ACQ_SRH - Acquisition status high register; 0x5A ***/
    union {
      byte Byte;
      struct {
        byte CM         :1;           /* Bit 0 */    
        byte VM         :1;           /* Bit 1 */
        byte ITM        :1;           /* Bit 2 */
        byte ETM        :1;           /* Bit 3 */
        byte CMOW       :1;           /* Bit 4 */
        byte VMOW       :1;           /* Bit 5 */
        byte PGAG       :1;           /* Bit 6 */
        byte AVRF       :1;           /* Bit 7 */
      } Bits;
    } ACQ_SRHSTR;
    #define ACQ_SRH _ACQ_SR.Overlap_STR.ACQ_SRHSTR.Byte

    /*** ACQ_SRL - Acquisition status low register; 0x5B ***/
    union {
      byte Byte;
      struct {
        byte CCHOP      :1;           /* Bit 0 */
        byte VCHOP      :1;           /* Bit 1 */
        byte ITCHOP     :1;           /* Bit 2 */
        byte ETCHOP     :1;           /* Bit 3 */
        byte VTH        :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte OPEN       :1;           /* Bit 7 */
      } Bits;
    } ACQ_SRLSTR;
    #define ACQ_SRL _ACQ_SR.Overlap_STR.ACQ_SRLSTR.Byte

  } Overlap_STR;

  struct {
    word CCHOP          :1;           /* bit 0 */
    word VCHOP          :1;           /* bit 1 */
    word ITCHOP         :1;           /* bit 2 */
    word ETCHOP         :1;           /* bit 3 */
    word VTH            :1;           /* bit 4 */
    word                :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word OPEN           :1;           /* bit 7 */
    word CM             :1;           /* bit 8 */
    word VM             :1;           /* bit 9 */
    word ITM            :1;           /* bit 10 */
    word ETM            :1;           /* bit 11 */
    word CMOW           :1;           /* bit 12 */
    word VMOW           :1;           /* bit 13 */
    word PGAG           :1;           /* bit 14 */
    word AVRF           :1;           /* bit 15 */
  } Bits;
} ACQ_SRSTR;
extern volatile ACQ_SRSTR _ACQ_SR @(D2DREG_BASE + 0x5A);
#define ACQ_SR _ACQ_SR.Word


/*** ACQ_ACC1 - Acquisition chain control 1; 0x5C ****************************/
typedef union {
  word Word;
  struct {
    word AGEN           :1;           /* bit 0 */
    word CVCHOP         :1;           /* bit 1 */
    word ITCHOP         :1;           /* bit 2 */
    word ETCHOP         :1;           /* bit 3 */
    word LPFEN          :1;           /* bit 4 */
    word CCOMP          :1;           /* bit 5 */
    word VCOMP          :1;           /* bit 6 */
    word TCOMP          :1;           /* bit 7 */
    word AGENM          :1;           /* bit 8 */
    word CVCHOPM        :1;           /* bit 9 */
    word ITCHOPM        :1;           /* bit 10 */
    word ETCHOPM        :1;           /* bit 11 */
    word LPFENM         :1;           /* bit 12 */
    word CCOMPM         :1;           /* bit 13 */
    word VCOMPM         :1;           /* bit 14 */
    word TCOMPM         :1;           /* bit 15 */
  } Bits;
} ACQ_ACC1STR;
extern volatile ACQ_ACC1STR _ACQ_ACC1 @(D2DREG_BASE + 0x5C);
#define ACQ_ACC1 _ACQ_ACC1.Word


/*** ACQ_ACC0 - Acquisition chain control 0; 0x5E ****************************/
typedef union {
  word Word;
  struct {
    word CDEN           :1;           /* bit 0 */
    word VDEN           :1;           /* bit 1 */
    word TDEN           :1;           /* bit 2 */
    word CADCG          :1;           /* bit 3 */
    word VADCG          :1;           /* bit 4 */
    word TADCG          :1;           /* bit 5 */
    word ECAP           :1;           /* bit 6 */
    word ZERO           :1;           /* bit 7 */
    word CDENM          :1;           /* bit 8 */
    word VDENM          :1;           /* bit 9 */
    word TDENM          :1;           /* bit 10 */
    word CADCGM         :1;           /* bit 11 */
    word VADCGM         :1;           /* bit 12 */
    word TADCGM         :1;           /* bit 13 */
    word ECAPM          :1;           /* bit 14 */
    word ZEROM          :1;           /* bit 15 */
  } Bits;
} ACQ_ACC0STR;
extern volatile ACQ_ACC0STR _ACQ_ACC0 @(D2DREG_BASE + 0x5E);
#define ACQ_ACC0 _ACQ_ACC0.Word


/*** ACQ_DEC - Decimation rate; 0x60 *****************************************/
typedef union {
  byte Byte;
  struct {
    byte DEC0           :1;           /* bit 0 */
    byte DEC1           :1;           /* bit 1 */
    byte DEC2           :1;           /* bit 2 */
    byte                :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} ACQ_DECSTR;
extern volatile ACQ_DECSTR _ACQ_DEC @(D2DREG_BASE + 0x60);
#define ACQ_DEC _ACQ_DEC.Byte


/*** ACQ_BGC - BandGap control; 0x61 *****************************************/
typedef union {
  byte Byte;
  struct {
    byte BG1EN          :1;           /* bit 0 */
    byte BG2EN          :1;           /* bit 1 */
    byte BG3EN          :1;           /* bit 2 */
    byte BGLDO          :1;           /* bit 3 */
    byte BGADC0         :1;           /* bit 4 */
    byte BGADC1         :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} ACQ_BGCSTR;
extern volatile ACQ_BGCSTR _ACQ_BGC @(D2DREG_BASE + 0x61);
#define ACQ_BGC _ACQ_BGC.Byte


/*** ACQ_GAIN - PGA gain; 0x62 ***********************************************/
typedef union {
  byte Byte;
  struct {
    byte IGAIN0         :1;           /* bit 0 */
    byte IGAIN1         :1;           /* bit 1 */
    byte IGAIN2         :1;           /* bit 2 */
    byte                :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} ACQ_GAINSTR;
extern volatile ACQ_GAINSTR _ACQ_GAIN @(D2DREG_BASE + 0x62);
#define ACQ_GAIN _ACQ_GAIN.Byte


/*** ACQ_GCB - GCB threshold; 0x63 *******************************************/
typedef union {
  byte Byte;
  struct {
    byte D0             :1;           /* bit 0 */
    byte D1             :1;           /* bit 1 */
    byte D2             :1;           /* bit 2 */
    byte D3             :1;           /* bit 3 */
    byte D4             :1;           /* bit 4 */
    byte D5             :1;           /* bit 5 */
    byte D6             :1;           /* bit 6 */
    byte D7             :1;           /* bit 7 */
  } Bits;
} ACQ_GCBSTR;
extern volatile ACQ_GCBSTR _ACQ_GCB @(D2DREG_BASE + 0x63);
#define ACQ_GCB _ACQ_GCB.Byte


/*** ACQ_ITEMP - Internal temperature measurement; 0x64 **********************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ACQ_ITEMPH - Internal temperature measurement high; 0x64 ***/
    union {
      byte Byte;
      struct {
        byte ITEMP8     :1;           /* Bit 0 */    
        byte ITEMP9     :1;           /* Bit 1 */
        byte ITEMP10    :1;           /* Bit 2 */
        byte ITEMP11    :1;           /* Bit 3 */
        byte ITEMP12    :1;           /* Bit 4 */
        byte ITEMP13    :1;           /* Bit 5 */
        byte ITEMP14    :1;           /* Bit 6 */
        byte ITEMP15    :1;           /* Bit 7 */
      } Bits;
    } ACQ_ITEMPHSTR;
    #define ACQ_ITEMPH _ACQ_ITEMP.Overlap_STR.ACQ_ITEMPHSTR.Byte

    /*** ACQ_ITEMPL - Internal temperature measurement low; 0x65 ***/
    union {
      byte Byte;
      struct {
        byte ITEMP0     :1;           /* Bit 0 */
        byte ITEMP1     :1;           /* Bit 1 */
        byte ITEMP2     :1;           /* Bit 2 */
        byte ITEMP3     :1;           /* Bit 3 */
        byte ITEMP4     :1;           /* Bit 4 */
        byte ITEMP5     :1;           /* Bit 5 */
        byte ITEMP6     :1;           /* Bit 6 */
        byte ITEMP7     :1;           /* Bit 7 */
      } Bits;
    } ACQ_ITEMPLSTR;
    #define ACQ_ITEMPL _ACQ_ITEMP.Overlap_STR.ACQ_ITEMPLSTR.Byte

  } Overlap_STR;

  struct {
    word ITEMP0         :1;           /* bit 0 */
    word ITEMP1         :1;           /* bit 1 */
    word ITEMP2         :1;           /* bit 2 */
    word ITEMP3         :1;           /* bit 3 */
    word ITEMP4         :1;           /* bit 4 */
    word ITEMP5         :1;           /* bit 5 */
    word ITEMP6         :1;           /* bit 6 */
    word ITEMP7         :1;           /* bit 7 */
    word ITEMP8         :1;           /* bit 8 */
    word ITEMP9         :1;           /* bit 9 */
    word ITEMP10        :1;           /* bit 10 */
    word ITEMP11        :1;           /* bit 11 */
    word ITEMP12        :1;           /* bit 12 */
    word ITEMP13        :1;           /* bit 13 */
    word ITEMP14        :1;           /* bit 14 */
    word ITEMP15        :1;           /* bit 15 */
  } Bits;
} ACQ_ITEMPSTR;
extern volatile ACQ_ITEMPSTR _ACQ_ITEMP @(D2DREG_BASE + 0x64);
#define ACQ_ITEMP _ACQ_ITEMP.Word


/*** ACQ_ETEMP - External temperature measurement; 0x66 **********************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ACQ_ETEMPH - External temperature measurement high; 0x66 ***/
    union {
      byte Byte;
      struct {
        byte ETEMP8     :1;           /* Bit 0 */    
        byte ETEMP9     :1;           /* Bit 1 */
        byte ETEMP10    :1;           /* Bit 2 */
        byte ETEMP11    :1;           /* Bit 3 */
        byte ETEMP12    :1;           /* Bit 4 */
        byte ETEMP13    :1;           /* Bit 5 */
        byte ETEMP14    :1;           /* Bit 6 */
        byte ETEMP15    :1;           /* Bit 7 */
      } Bits;
    } ACQ_ETEMPHSTR;
    #define ACQ_ETEMPH _ACQ_ETEMP.Overlap_STR.ACQ_ETEMPHSTR.Byte

    /*** ACQ_ETEMPL - External temperature measurement low; 0x67 ***/
    union {
      byte Byte;
      struct {
        byte ETEMP0     :1;           /* Bit 0 */
        byte ETEMP1     :1;           /* Bit 1 */
        byte ETEMP2     :1;           /* Bit 2 */
        byte ETEMP3     :1;           /* Bit 3 */
        byte ETEMP4     :1;           /* Bit 4 */
        byte ETEMP5     :1;           /* Bit 5 */
        byte ETEMP6     :1;           /* Bit 6 */
        byte ETEMP7     :1;           /* Bit 7 */
      } Bits;
    } ACQ_ETEMPLSTR;
    #define ACQ_ETEMPL _ACQ_ETEMP.Overlap_STR.ACQ_ETEMPLSTR.Byte

  } Overlap_STR;

  struct {
    word ETEMP0         :1;           /* bit 0 */
    word ETEMP1         :1;           /* bit 1 */
    word ETEMP2         :1;           /* bit 2 */
    word ETEMP3         :1;           /* bit 3 */
    word ETEMP4         :1;           /* bit 4 */
    word ETEMP5         :1;           /* bit 5 */
    word ETEMP6         :1;           /* bit 6 */
    word ETEMP7         :1;           /* bit 7 */
    word ETEMP8         :1;           /* bit 8 */
    word ETEMP9         :1;           /* bit 9 */
    word ETEMP10        :1;           /* bit 10 */
    word ETEMP11        :1;           /* bit 11 */
    word ETEMP12        :1;           /* bit 12 */
    word ETEMP13        :1;           /* bit 13 */
    word ETEMP14        :1;           /* bit 14 */
    word ETEMP15        :1;           /* bit 15 */
  } Bits;
} ACQ_ETEMPSTR;
extern volatile ACQ_ETEMPSTR _ACQ_ETEMP @(D2DREG_BASE + 0x66);
#define ACQ_ETEMP _ACQ_ETEMP.Word


/*** ACQ_CURR1 - Current measurement 1; 0x68 *********************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** RESERVED; 0x68 ***/
    union {
      byte Byte;
      struct {
        byte            :1;           /* Bit 0 */    
        byte            :1;           /* Bit 1 */
        byte            :1;           /* Bit 2 */
        byte            :1;           /* Bit 3 */
        byte            :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } ACQ_CURR1HSTR;
    #define ACQ_CURR1H _ACQ_CURR1.Overlap_STR.ACQ_CURR1HSTR.Byte

    /*** ACQ_CURR1L - Current measurement 1 low; 0x69 ***/
    union {
      byte Byte;
      struct {
        byte CURR16     :1;           /* Bit 0 */
        byte CURR17     :1;           /* Bit 1 */
        byte CURR18     :1;           /* Bit 2 */
        byte CURR19     :1;           /* Bit 3 */
        byte CURR20     :1;           /* Bit 4 */
        byte CURR21     :1;           /* Bit 5 */
        byte CURR22     :1;           /* Bit 6 */
        byte CURR23     :1;           /* Bit 7 */
      } Bits;
    } ACQ_CURR1LSTR;
    #define ACQ_CURR1L _ACQ_CURR1.Overlap_STR.ACQ_CURR1LSTR.Byte

  } Overlap_STR;

  struct {
    word CURR16         :1;           /* bit 0 */
    word CURR17         :1;           /* bit 1 */
    word CURR18         :1;           /* bit 2 */
    word CURR19         :1;           /* bit 3 */
    word CURR20         :1;           /* bit 4 */
    word CURR21         :1;           /* bit 5 */
    word CURR22         :1;           /* bit 6 */
    word CURR23         :1;           /* bit 7 */
    word                :1;           /* bit 8 */
    word                :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} ACQ_CURR1STR;
extern volatile ACQ_CURR1STR _ACQ_CURR1 @(D2DREG_BASE + 0x68);
#define ACQ_CURR1 _ACQ_CURR1.Word


/*** ACQ_CURR0 - Current measurement 0; 0x6A **************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ACQ_CURR0H - Current measurement 0 high; 0x6A ***/
    union {
      byte Byte;
      struct {
        byte CURR8      :1;           /* Bit 0 */    
        byte CURR9      :1;           /* Bit 1 */
        byte CURR10     :1;           /* Bit 2 */
        byte CURR11     :1;           /* Bit 3 */
        byte CURR12     :1;           /* Bit 4 */
        byte CURR13     :1;           /* Bit 5 */
        byte CURR14     :1;           /* Bit 6 */
        byte CURR15     :1;           /* Bit 7 */
      } Bits;
    } ACQ_CURR0HSTR;
    #define ACQ_CURR0H _ACQ_CURR0.Overlap_STR.ACQ_CURR0HSTR.Byte

    /*** ACQ_CURR0L - Current measurement 0 low; 0x6B ***/
    union {
      byte Byte;
      struct {
        byte CURR0      :1;           /* Bit 0 */
        byte CURR1      :1;           /* Bit 1 */
        byte CURR2      :1;           /* Bit 2 */
        byte CURR3      :1;           /* Bit 3 */
        byte CURR4      :1;           /* Bit 4 */
        byte CURR5      :1;           /* Bit 5 */
        byte CURR6      :1;           /* Bit 6 */
        byte CURR7      :1;           /* Bit 7 */
      } Bits;
    } ACQ_CURR0LSTR;
    #define ACQ_CURR0L _ACQ_CURR0.Overlap_STR.ACQ_CURR0LSTR.Byte

  } Overlap_STR;

  struct {
    word CURR0          :1;           /* bit 0 */
    word CURR1          :1;           /* bit 1 */
    word CURR2          :1;           /* bit 2 */
    word CURR3          :1;           /* bit 3 */
    word CURR4          :1;           /* bit 4 */
    word CURR5          :1;           /* bit 5 */
    word CURR6          :1;           /* bit 6 */
    word CURR7          :1;           /* bit 7 */
    word CURR8          :1;           /* bit 8 */
    word CURR9          :1;           /* bit 9 */
    word CURR10         :1;           /* bit 10 */
    word CURR11         :1;           /* bit 11 */
    word CURR12         :1;           /* bit 12 */
    word CURR13         :1;           /* bit 13 */
    word CURR14         :1;           /* bit 14 */
    word CURR15         :1;           /* bit 15 */
  } Bits;
} ACQ_CURR0STR;
extern volatile ACQ_CURR0STR _ACQ_CURR0 @(D2DREG_BASE + 0x6A);
#define ACQ_CURR0 _ACQ_CURR0.Word


/*** ACQ_VOLT - Voltage measurement; 0x6C ************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ACQ_VOLTH - Voltage measurement high; 0x6C ***/
    union {
      byte Byte;
      struct {
        byte VOLT8      :1;           /* Bit 0 */    
        byte VOLT9      :1;           /* Bit 1 */
        byte VOLT10     :1;           /* Bit 2 */
        byte VOLT11     :1;           /* Bit 3 */
        byte VOLT12     :1;           /* Bit 4 */
        byte VOLT13     :1;           /* Bit 5 */
        byte VOLT14     :1;           /* Bit 6 */
        byte VOLT15     :1;           /* Bit 7 */
      } Bits;
    } ACQ_VOLTHSTR;
    #define ACQ_VOLTH _ACQ_VOLT.Overlap_STR.ACQ_VOLTHSTR.Byte

    /*** ACQ_VOLTL - Voltage measurement low; 0x6D ***/
    union {
      byte Byte;
      struct {
        byte VOLT0      :1;           /* Bit 0 */
        byte VOLT1      :1;           /* Bit 1 */
        byte VOLT2      :1;           /* Bit 2 */
        byte VOLT3      :1;           /* Bit 3 */
        byte VOLT4      :1;           /* Bit 4 */
        byte VOLT5      :1;           /* Bit 5 */
        byte VOLT6      :1;           /* Bit 6 */
        byte VOLT7      :1;           /* Bit 7 */
      } Bits;
    } ACQ_VOLTLSTR;
    #define ACQ_VOLTL _ACQ_VOLT.Overlap_STR.ACQ_VOLTLSTR.Byte

  } Overlap_STR;

  struct {
    word VOLT0          :1;           /* bit 0 */
    word VOLT1          :1;           /* bit 1 */
    word VOLT2          :1;           /* bit 2 */
    word VOLT3          :1;           /* bit 3 */
    word VOLT4          :1;           /* bit 4 */
    word VOLT5          :1;           /* bit 5 */
    word VOLT6          :1;           /* bit 6 */
    word VOLT7          :1;           /* bit 7 */
    word VOLT8          :1;           /* bit 8 */
    word VOLT9          :1;           /* bit 9 */
    word VOLT10         :1;           /* bit 10 */
    word VOLT11         :1;           /* bit 11 */
    word VOLT12         :1;           /* bit 12 */
    word VOLT13         :1;           /* bit 13 */
    word VOLT14         :1;           /* bit 14 */
    word VOLT15         :1;           /* bit 15 */
  } Bits;
} ACQ_VOLTSTR;
extern volatile ACQ_VOLTSTR _ACQ_VOLT @(D2DREG_BASE + 0x6C);
#define ACQ_VOLT _ACQ_VOLT.Word


/*** ACQ_LPFC - Low pass filter coefficient number; 0x6E *********************/
typedef union {
  byte Byte;
  struct {
    byte LPFC0          :1;           /* bit 0 */
    byte LPFC1          :1;           /* bit 1 */
    byte LPFC2          :1;           /* bit 2 */
    byte LPFC3          :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} ACQ_LPFCSTR;
extern volatile ACQ_LPFCSTR _ACQ_LPFC @(D2DREG_BASE + 0x6E);
#define ACQ_LPFC _ACQ_LPFC.Byte

									
/*** ACQ_TCMP - Low power trigger current measurement period; 0x70 ***********/
typedef union {
  word Word;
  struct {
    word TCMP0          :1;           /* bit 0 */
    word TCMP1          :1;           /* bit 1 */
    word TCMP2          :1;           /* bit 2 */
    word TCMP3          :1;           /* bit 3 */
    word TCMP4          :1;           /* bit 4 */
    word TCMP5          :1;           /* bit 5 */
    word TCMP6          :1;           /* bit 6 */
    word TCMP7          :1;           /* bit 7 */
    word TCMP8          :1;           /* bit 8 */
    word TCMP9          :1;           /* bit 9 */
    word TCMP10         :1;           /* bit 10 */
    word TCMP11         :1;           /* bit 11 */
    word TCMP12         :1;           /* bit 12 */
    word TCMP13         :1;           /* bit 13 */
    word TCMP14         :1;           /* bit 14 */
    word TCMP15         :1;           /* bit 15 */
  } Bits;
} ACQ_TCMPSTR;
extern volatile ACQ_TCMPSTR _ACQ_TCMP @(D2DREG_BASE + 0x70);
#define ACQ_TCMP _ACQ_TCMP.Word


/*** ACQ_THF - Low power current threshold filtering period; 0x72 ************/
typedef union {
  byte Byte;
  struct {
    byte THF0           :1;           /* bit 0 */
    byte THF1           :1;           /* bit 1 */
    byte THF2           :1;           /* bit 2 */
    byte THF3           :1;           /* bit 3 */
    byte THF4           :1;           /* bit 4 */
    byte THF5           :1;           /* bit 5 */
    byte THF6           :1;           /* bit 6 */
    byte THF7           :1;           /* bit 7 */
  } Bits;
} ACQ_THFSTR;
extern volatile ACQ_THFSTR _ACQ_THF @(D2DREG_BASE + 0x72);
#define ACQ_THF _ACQ_THF.Byte


/*** ACQ_CVCR - Current and Voltage Chopper Control Register; 0x74 ***********/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ACQ_CVCRH - Current and Voltage Chopper Control - high; 0x74 ***/
    union {
      byte Byte;
      struct {
        byte PGAFM      :1;           /* Bit 0 */    
        byte IIRCM0     :1;           /* Bit 1 */
        byte IIRCM1     :1;           /* Bit 2 */
        byte IIRCM2     :1;           /* Bit 3 */
        byte DBTM0      :1;           /* Bit 4 */
        byte DBTM1      :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } ACQ_CVCRHSTR;
    #define ACQ_CVCRH _ACQ_CVCR.Overlap_STR.ACQ_CVCRHSTR.Byte

    /*** ACQ_CVCRL - Current and Voltage Chopper Control - low; 0x75 ***/
    union {
      byte Byte;
      struct {
        byte PGAF       :1;           /* Bit 0 */
        byte IIRC0      :1;           /* Bit 1 */
        byte IIRC1      :1;           /* Bit 2 */
        byte IIRC2      :1;           /* Bit 3 */
        byte DBT0       :1;           /* Bit 4 */
        byte DBT1       :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } ACQ_CVCRLSTR;
    #define ACQ_CVCRL _ACQ_CVCR.Overlap_STR.ACQ_CVCRLSTR.Byte

  } Overlap_STR;

  struct {
    word PGAF           :1;           /* bit 0 */
    word IIRC0          :1;           /* bit 1 */
    word IIRC1          :1;           /* bit 2 */
    word IIRC2          :1;           /* bit 3 */
    word DBT0           :1;           /* bit 4 */
    word DBT1           :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word                :1;           /* bit 7 */
    word PGAFM          :1;           /* bit 8 */
    word IIRCM0         :1;           /* bit 9 */
    word IIRCM1         :1;           /* bit 10 */
    word IIRCM2         :1;           /* bit 11 */
    word DBTM0          :1;           /* bit 12 */
    word DBTM1          :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} ACQ_CVCRSTR;
extern volatile ACQ_CVCRSTR _ACQ_CVCR @(D2DREG_BASE + 0x74);
#define ACQ_CVCR _ACQ_CVCR.Word


/*** ACQ_CTH - Low power current threshold; 0x76 *****************************/
typedef union {
  byte Byte;
  struct {
    byte CTH0           :1;           /* bit 0 */
    byte CTH1           :1;           /* bit 1 */
    byte CTH2           :1;           /* bit 2 */
    byte CTH3           :1;           /* bit 3 */
    byte CTH4           :1;           /* bit 4 */
    byte CTH5           :1;           /* bit 5 */
    byte CTH6           :1;           /* bit 6 */
    byte CTH7           :1;           /* bit 7 */
  } Bits;
} ACQ_CTHSTR;
extern volatile ACQ_CTHSTR _ACQ_CTH @(D2DREG_BASE + 0x76);
#define ACQ_CTH _ACQ_CTH.Byte


/*** ACQ_AHTH1 - Low power Ah counter threshold 1; 0x78 **********************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ACQ_AHTH1H - Low power Ah counter threshold 1 high; 0x78 ***/
    union {
      byte Byte;
      struct {
        byte AHTH24     :1;           /* Bit 0 */    
        byte AHTH25     :1;           /* Bit 1 */
        byte AHTH26     :1;           /* Bit 2 */
        byte AHTH27     :1;           /* Bit 3 */
        byte AHTH28     :1;           /* Bit 4 */
        byte AHTH29     :1;           /* Bit 5 */
        byte AHTH30     :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } ACQ_AHTH1HSTR;
    #define ACQ_AHTH1H _ACQ_AHTH1.Overlap_STR.ACQ_AHTH1HSTR.Byte

    /*** ACQ_AHTH1L - Low power Ah counter threshold 1 low; 0x79 ***/
    union {
      byte Byte;
      struct {
        byte AHTH16     :1;           /* Bit 0 */
        byte AHTH17     :1;           /* Bit 1 */
        byte AHTH18     :1;           /* Bit 2 */
        byte AHTH19     :1;           /* Bit 3 */
        byte AHTH20     :1;           /* Bit 4 */
        byte AHTH21     :1;           /* Bit 5 */
        byte AHTH22     :1;           /* Bit 6 */
        byte AHTH23     :1;           /* Bit 7 */
      } Bits;
    } ACQ_AHTH1LSTR;
    #define ACQ_AHTH1L _ACQ_AHTH1.Overlap_STR.ACQ_AHTH1LSTR.Byte

  } Overlap_STR;

  struct {
    word AHTH16         :1;           /* bit 0 */
    word AHTH17         :1;           /* bit 1 */
    word AHTH18         :1;           /* bit 2 */
    word AHTH19         :1;           /* bit 3 */
    word AHTH20         :1;           /* bit 4 */
    word AHTH21         :1;           /* bit 5 */
    word AHTH22         :1;           /* bit 6 */
    word AHTH23         :1;           /* bit 7 */
    word AHTH24         :1;           /* bit 8 */
    word AHTH25         :1;           /* bit 9 */
    word AHTH26         :1;           /* bit 10 */
    word AHTH27         :1;           /* bit 11 */
    word AHTH28         :1;           /* bit 12 */
    word AHTH29         :1;           /* bit 13 */
    word AHTH30         :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} ACQ_AHTH1STR;
extern volatile ACQ_AHTH1STR _ACQ_AHTH1 @(D2DREG_BASE + 0x78);
#define ACQ_AHTH1 _ACQ_AHTH1.Word


/*** ACQ_AHTH0 - Low power Ah counter threshold 0; 0x7A **********************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ACQ_AHTH0H - Low power Ah counter threshold 0 high; 0x7A ***/
    union {
      byte Byte;
      struct {
        byte AHTH8      :1;           /* Bit 0 */    
        byte AHTH9      :1;           /* Bit 1 */
        byte AHTH10     :1;           /* Bit 2 */
        byte AHTH11     :1;           /* Bit 3 */
        byte AHTH12     :1;           /* Bit 4 */
        byte AHTH13     :1;           /* Bit 5 */
        byte AHTH14     :1;           /* Bit 6 */
        byte AHTH15     :1;           /* Bit 7 */
      } Bits;
    } ACQ_AHTH0HSTR;
    #define ACQ_AHTH0H _ACQ_AHTH0.Overlap_STR.ACQ_AHTH0HSTR.Byte

    /*** ACQ_AHTH0L - Low power Ah counter threshold 0 low; 0x7A ***/
    union {
      byte Byte;
      struct {
        byte AHTH0      :1;           /* Bit 0 */
        byte AHTH1      :1;           /* Bit 1 */
        byte AHTH2      :1;           /* Bit 2 */
        byte AHTH3      :1;           /* Bit 3 */
        byte AHTH4      :1;           /* Bit 4 */
        byte AHTH5      :1;           /* Bit 5 */
        byte AHTH6      :1;           /* Bit 6 */
        byte AHTH7      :1;           /* Bit 7 */
      } Bits;
    } ACQ_AHTH0LSTR;
    #define ACQ_AHTH0L _ACQ_AHTH0.Overlap_STR.ACQ_AHTH0LSTR.Byte

  } Overlap_STR;

  struct {
    word AHTH0          :1;           /* bit 0 */
    word AHTH1          :1;           /* bit 1 */
    word AHTH2          :1;           /* bit 2 */
    word AHTH3          :1;           /* bit 3 */
    word AHTH4          :1;           /* bit 4 */
    word AHTH5          :1;           /* bit 5 */
    word AHTH6          :1;           /* bit 6 */
    word AHTH7          :1;           /* bit 7 */
    word AHTH8          :1;           /* bit 8 */
    word AHTH9          :1;           /* bit 9 */
    word AHTH10         :1;           /* bit 10 */
    word AHTH11         :1;           /* bit 11 */
    word AHTH12         :1;           /* bit 12 */
    word AHTH13         :1;           /* bit 13 */
    word AHTH14         :1;           /* bit 14 */
    word AHTH15         :1;           /* bit 15 */
  } Bits;
} ACQ_AHTH0STR;
extern volatile ACQ_AHTH0STR _ACQ_AHTH0 @(D2DREG_BASE + 0x7A);
#define ACQ_AHTH0 _ACQ_AHTH0.Word


/*** ACQ_AHC1 - Low power Ah counter 1; 0x7C *********************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ACQ_AHC1H - Low power Ah counter 1 high; 0x7C ***/
    union {
      byte Byte;
      struct {
        byte AHC24      :1;           /* Bit 0 */    
        byte AHC25      :1;           /* Bit 1 */
        byte AHC26      :1;           /* Bit 2 */
        byte AHC27      :1;           /* Bit 3 */
        byte AHC28      :1;           /* Bit 4 */
        byte AHC29      :1;           /* Bit 5 */
        byte AHC30      :1;           /* Bit 6 */
        byte AHC31      :1;           /* Bit 7 */
      } Bits;
    } ACQ_AHC1HSTR;
    #define ACQ_AHC1H _ACQ_AHC1.Overlap_STR.ACQ_AHC1HSTR.Byte

    /*** ACQ_AHC1L - Low power Ah counter 1 low; 0x7D ***/
    union {
      byte Byte;
      struct {
        byte AHC16      :1;           /* Bit 0 */
        byte AHC17      :1;           /* Bit 1 */
        byte AHC18      :1;           /* Bit 2 */
        byte AHC19      :1;           /* Bit 3 */
        byte AHC20      :1;           /* Bit 4 */
        byte AHC21      :1;           /* Bit 5 */
        byte AHC22      :1;           /* Bit 6 */
        byte AHC23      :1;           /* Bit 7 */
      } Bits;
    } ACQ_AHC1LSTR;
    #define ACQ_AHC1L _ACQ_AHC1.Overlap_STR.ACQ_AHC1LSTR.Byte

  } Overlap_STR;

  struct {
    word AHC16          :1;           /* bit 0 */
    word AHC17          :1;           /* bit 1 */
    word AHC18          :1;           /* bit 2 */
    word AHC19          :1;           /* bit 3 */
    word AHC20          :1;           /* bit 4 */
    word AHC21          :1;           /* bit 5 */
    word AHC22          :1;           /* bit 6 */
    word AHC23          :1;           /* bit 7 */
    word AHC24          :1;           /* bit 8 */
    word AHC25          :1;           /* bit 9 */
    word AHC26          :1;           /* bit 10 */
    word AHC27          :1;           /* bit 11 */
    word AHC28          :1;           /* bit 12 */
    word AHC29          :1;           /* bit 13 */
    word AHC30          :1;           /* bit 14 */
    word AHC31          :1;           /* bit 15 */
  } Bits;
} ACQ_AHC1STR;
extern volatile ACQ_AHC1STR _ACQ_AHC1 @(D2DREG_BASE + 0x7C);
#define ACQ_AHC1 _ACQ_AHC1.Word


/*** ACQ_AHC0 - Low power Ah counter 0; 0x7E *********************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ACQ_AHC0H - Low power Ah counter 0 high; 0x7E ***/
    union {
      byte Byte;
      struct {
        byte AHC8       :1;           /* Bit 0 */    
        byte AHC9       :1;           /* Bit 1 */
        byte AHC10      :1;           /* Bit 2 */
        byte AHC11      :1;           /* Bit 3 */
        byte AHC12      :1;           /* Bit 4 */
        byte AHC13      :1;           /* Bit 5 */
        byte AHC14      :1;           /* Bit 6 */
        byte AHC15      :1;           /* Bit 7 */
      } Bits;
    } ACQ_AHC0HSTR;
    #define ACQ_AHC0H _ACQ_AHC0.Overlap_STR.ACQ_AHC0HSTR.Byte

    /*** ACQ_AHC0L - Low power Ah counter 0 low; 0x7F ***/
    union {
      byte Byte;
      struct {
        byte AHC0       :1;           /* Bit 0 */
        byte AHC1       :1;           /* Bit 1 */
        byte AHC2       :1;           /* Bit 2 */
        byte AHC3       :1;           /* Bit 3 */
        byte AHC4       :1;           /* Bit 4 */
        byte AHC5       :1;           /* Bit 5 */
        byte AHC6       :1;           /* Bit 6 */
        byte AHC7       :1;           /* Bit 7 */
      } Bits;
    } ACQ_AHC0LSTR;
    #define ACQ_AHC0L _ACQ_AHC0.Overlap_STR.ACQ_AHC0LSTR.Byte

  } Overlap_STR;

  struct {
    word AHC0           :1;           /* bit 0 */
    word AHC1           :1;           /* bit 1 */
    word AHC2           :1;           /* bit 2 */
    word AHC3           :1;           /* bit 3 */
    word AHC4           :1;           /* bit 4 */
    word AHC5           :1;           /* bit 5 */
    word AHC6           :1;           /* bit 6 */
    word AHC7           :1;           /* bit 7 */
    word AHC8           :1;           /* bit 8 */
    word AHC9           :1;           /* bit 9 */
    word AHC10          :1;           /* bit 10 */
    word AHC11          :1;           /* bit 11 */
    word AHC12          :1;           /* bit 12 */
    word AHC13          :1;           /* bit 13 */
    word AHC14          :1;           /* bit 14 */
    word AHC15          :1;           /* bit 15 */
  } Bits;
} ACQ_AHC0STR;
extern volatile ACQ_AHC0STR _ACQ_AHC0 @(D2DREG_BASE + 0x7E);
#define ACQ_AHC0 _ACQ_AHC0.Word


/*** LPF_A0 - A0 filter coeff; 0x80 ******************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A0H - A0 filter coeff (hi); 0x80 ***/
    union {
      byte Byte;
      struct {
        byte A0_8       :1;           /* Bit 0 */    
        byte A0_9       :1;           /* Bit 1 */
        byte A0_10      :1;           /* Bit 2 */
        byte A0_11      :1;           /* Bit 3 */
        byte A0_12      :1;           /* Bit 4 */
        byte A0_13      :1;           /* Bit 5 */
        byte A0_14      :1;           /* Bit 6 */
        byte A0_15      :1;           /* Bit 7 */
      } Bits;
    } LPF_A0HSTR;
    #define LPF_A0H _LPF_A0.Overlap_STR.LPF_A0HSTR.Byte

    /*** LPF_A0L - A0 filter coeff (lo); 0x81 ***/
    union {
      byte Byte;
      struct {
        byte A0_0       :1;           /* Bit 0 */
        byte A0_1       :1;           /* Bit 1 */
        byte A0_2       :1;           /* Bit 2 */
        byte A0_3       :1;           /* Bit 3 */
        byte A0_4       :1;           /* Bit 4 */
        byte A0_5       :1;           /* Bit 5 */
        byte A0_6       :1;           /* Bit 6 */
        byte A0_7       :1;           /* Bit 7 */
      } Bits;
    } LPF_A0LSTR;
    #define LPF_A0L _LPF_A0.Overlap_STR.LPF_A0LSTR.Byte

  } Overlap_STR;

  struct {
    word A0_0           :1;           /* bit 0 */
    word A0_1           :1;           /* bit 1 */
    word A0_2           :1;           /* bit 2 */
    word A0_3           :1;           /* bit 3 */
    word A0_4           :1;           /* bit 4 */
    word A0_5           :1;           /* bit 5 */
    word A0_6           :1;           /* bit 6 */
    word A0_7           :1;           /* bit 7 */
    word A0_8           :1;           /* bit 8 */
    word A0_9           :1;           /* bit 9 */
    word A0_10          :1;           /* bit 10 */
    word A0_11          :1;           /* bit 11 */
    word A0_12          :1;           /* bit 12 */
    word A0_13          :1;           /* bit 13 */
    word A0_14          :1;           /* bit 14 */
    word A0_15          :1;           /* bit 15 */
  } Bits;
} LPF_A0STR;
extern volatile LPF_A0STR _LPF_A0 @(D2DREG_BASE + 0x80);
#define LPF_A0 _LPF_A0.Word


/*** LPF_A1 - A1 filter coeff; 0x82 ******************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A1H - A1 filter coeff (hi); 0x82 ***/
    union {
      byte Byte;
      struct {
        byte A1_8       :1;           /* Bit 0 */    
        byte A1_9       :1;           /* Bit 1 */
        byte A1_10      :1;           /* Bit 2 */
        byte A1_11      :1;           /* Bit 3 */
        byte A1_12      :1;           /* Bit 4 */
        byte A1_13      :1;           /* Bit 5 */
        byte A1_14      :1;           /* Bit 6 */
        byte A1_15      :1;           /* Bit 7 */
      } Bits;
    } LPF_A1HSTR;
    #define LPF_A1H _LPF_A1.Overlap_STR.LPF_A1HSTR.Byte

    /*** LPF_A1L - A1 filter coeff (lo); 0x83 ***/
    union {
      byte Byte;
      struct {
        byte A1_0       :1;           /* Bit 0 */
        byte A1_1       :1;           /* Bit 1 */
        byte A1_2       :1;           /* Bit 2 */
        byte A1_3       :1;           /* Bit 3 */
        byte A1_4       :1;           /* Bit 4 */
        byte A1_5       :1;           /* Bit 5 */
        byte A1_6       :1;           /* Bit 6 */
        byte A1_7       :1;           /* Bit 7 */
      } Bits;
    } LPF_A1LSTR;
    #define LPF_A1L _LPF_A1.Overlap_STR.LPF_A1LSTR.Byte

  } Overlap_STR;

  struct {
    word A1_0           :1;           /* bit 0 */
    word A1_1           :1;           /* bit 1 */
    word A1_2           :1;           /* bit 2 */
    word A1_3           :1;           /* bit 3 */
    word A1_4           :1;           /* bit 4 */
    word A1_5           :1;           /* bit 5 */
    word A1_6           :1;           /* bit 6 */
    word A1_7           :1;           /* bit 7 */
    word A1_8           :1;           /* bit 8 */
    word A1_9           :1;           /* bit 9 */
    word A1_10          :1;           /* bit 10 */
    word A1_11          :1;           /* bit 11 */
    word A1_12          :1;           /* bit 12 */
    word A1_13          :1;           /* bit 13 */
    word A1_14          :1;           /* bit 14 */
    word A1_15          :1;           /* bit 15 */
  } Bits;
} LPF_A1STR;
extern volatile LPF_A1STR _LPF_A1 @(D2DREG_BASE + 0x82);
#define LPF_A1 _LPF_A1.Word


/*** LPF_A2 - A2 filter coeff; 0x84 ******************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A2H - A2 filter coeff (hi); 0x84 ***/
    union {
      byte Byte;
      struct {
        byte A2_8       :1;           /* Bit 0 */    
        byte A2_9       :1;           /* Bit 1 */
        byte A2_10      :1;           /* Bit 2 */
        byte A2_11      :1;           /* Bit 3 */
        byte A2_12      :1;           /* Bit 4 */
        byte A2_13      :1;           /* Bit 5 */
        byte A2_14      :1;           /* Bit 6 */
        byte A2_15      :1;           /* Bit 7 */
      } Bits;
    } LPF_A2HSTR;
    #define LPF_A2H _LPF_A2.Overlap_STR.LPF_A2HSTR.Byte

    /*** LPF_A2L - A2 filter coeff (lo); 0x85 ***/
    union {
      byte Byte;
      struct {
        byte A2_0       :1;           /* Bit 0 */
        byte A2_1       :1;           /* Bit 1 */
        byte A2_2       :1;           /* Bit 2 */
        byte A2_3       :1;           /* Bit 3 */
        byte A2_4       :1;           /* Bit 4 */
        byte A2_5       :1;           /* Bit 5 */
        byte A2_6       :1;           /* Bit 6 */
        byte A2_7       :1;           /* Bit 7 */
      } Bits;
    } LPF_A2LSTR;
    #define LPF_A2L _LPF_A2.Overlap_STR.LPF_A2LSTR.Byte

  } Overlap_STR;

  struct {
    word A2_0           :1;           /* bit 0 */
    word A2_1           :1;           /* bit 1 */
    word A2_2           :1;           /* bit 2 */
    word A2_3           :1;           /* bit 3 */
    word A2_4           :1;           /* bit 4 */
    word A2_5           :1;           /* bit 5 */
    word A2_6           :1;           /* bit 6 */
    word A2_7           :1;           /* bit 7 */
    word A2_8           :1;           /* bit 8 */
    word A2_9           :1;           /* bit 9 */
    word A2_10          :1;           /* bit 10 */
    word A2_11          :1;           /* bit 11 */
    word A2_12          :1;           /* bit 12 */
    word A2_13          :1;           /* bit 13 */
    word A2_14          :1;           /* bit 14 */
    word A2_15          :1;           /* bit 15 */
  } Bits;
} LPF_A2STR;
extern volatile LPF_A2STR _LPF_A2 @(D2DREG_BASE + 0x84);
#define LPF_A2 _LPF_A2.Word


/*** LPF_A3 - A3 filter coeff; 0x86 ******************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A3H - A3 filter coeff (hi); 0x86 ***/
    union {
      byte Byte;
      struct {
        byte A3_8       :1;           /* Bit 0 */    
        byte A3_9       :1;           /* Bit 1 */
        byte A3_10      :1;           /* Bit 2 */
        byte A3_11      :1;           /* Bit 3 */
        byte A3_12      :1;           /* Bit 4 */
        byte A3_13      :1;           /* Bit 5 */
        byte A3_14      :1;           /* Bit 6 */
        byte A3_15      :1;           /* Bit 7 */
      } Bits;
    } LPF_A3HSTR;
    #define LPF_A3H _LPF_A3.Overlap_STR.LPF_A3HSTR.Byte

    /*** LPF_A3L - A3 filter coeff (lo); 0x87 ***/
    union {
      byte Byte;
      struct {
        byte A3_0       :1;           /* Bit 0 */
        byte A3_1       :1;           /* Bit 1 */
        byte A3_2       :1;           /* Bit 2 */
        byte A3_3       :1;           /* Bit 3 */
        byte A3_4       :1;           /* Bit 4 */
        byte A3_5       :1;           /* Bit 5 */
        byte A3_6       :1;           /* Bit 6 */
        byte A3_7       :1;           /* Bit 7 */
      } Bits;
    } LPF_A3LSTR;
    #define LPF_A3L _LPF_A3.Overlap_STR.LPF_A3LSTR.Byte

  } Overlap_STR;

  struct {
    word A3_0           :1;           /* bit 0 */
    word A3_1           :1;           /* bit 1 */
    word A3_2           :1;           /* bit 2 */
    word A3_3           :1;           /* bit 3 */
    word A3_4           :1;           /* bit 4 */
    word A3_5           :1;           /* bit 5 */
    word A3_6           :1;           /* bit 6 */
    word A3_7           :1;           /* bit 7 */
    word A3_8           :1;           /* bit 8 */
    word A3_9           :1;           /* bit 9 */
    word A3_10          :1;           /* bit 10 */
    word A3_11          :1;           /* bit 11 */
    word A3_12          :1;           /* bit 12 */
    word A3_13          :1;           /* bit 13 */
    word A3_14          :1;           /* bit 14 */
    word A3_15          :1;           /* bit 15 */
  } Bits;
} LPF_A3STR;
extern volatile LPF_A3STR _LPF_A3 @(D2DREG_BASE + 0x86);
#define LPF_A3 _LPF_A3.Word


/*** LPF_A4 - A4 filter coeff; 0x88 **************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A4H - A4 filter coeff (hi); 0x88 ***/
    union {
      byte Byte;
      struct {
        byte A4_8       :1;           /* Bit 0 */    
        byte A4_9       :1;           /* Bit 1 */
        byte A4_10      :1;           /* Bit 2 */
        byte A4_11      :1;           /* Bit 3 */
        byte A4_12      :1;           /* Bit 4 */
        byte A4_13      :1;           /* Bit 5 */
        byte A4_14      :1;           /* Bit 6 */
        byte A4_15      :1;           /* Bit 7 */
      } Bits;
    } LPF_A4HSTR;
    #define LPF_A4H _LPF_A4.Overlap_STR.LPF_A4HSTR.Byte

    /*** LPF_A4L - A4 filter coeff (lo); 0x89 ***/
    union {
      byte Byte;
      struct {
        byte A4_0       :1;           /* Bit 0 */
        byte A4_1       :1;           /* Bit 1 */
        byte A4_2       :1;           /* Bit 2 */
        byte A4_3       :1;           /* Bit 3 */
        byte A4_4       :1;           /* Bit 4 */
        byte A4_5       :1;           /* Bit 5 */
        byte A4_6       :1;           /* Bit 6 */
        byte A4_7       :1;           /* Bit 7 */
      } Bits;
    } LPF_A4LSTR;
    #define LPF_A4L _LPF_A4.Overlap_STR.LPF_A4LSTR.Byte

  } Overlap_STR;

  struct {
    word A4_0           :1;           /* bit 0 */
    word A4_1           :1;           /* bit 1 */
    word A4_2           :1;           /* bit 2 */
    word A4_3           :1;           /* bit 3 */
    word A4_4           :1;           /* bit 4 */
    word A4_5           :1;           /* bit 5 */
    word A4_6           :1;           /* bit 6 */
    word A4_7           :1;           /* bit 7 */
    word A4_8           :1;           /* bit 8 */
    word A4_9           :1;           /* bit 9 */
    word A4_10          :1;           /* bit 10 */
    word A4_11          :1;           /* bit 11 */
    word A4_12          :1;           /* bit 12 */
    word A4_13          :1;           /* bit 13 */
    word A4_14          :1;           /* bit 14 */
    word A4_15          :1;           /* bit 15 */
  } Bits;
} LPF_A4STR;
extern volatile LPF_A4STR _LPF_A4 @(D2DREG_BASE + 0x88);
#define LPF_A4 _LPF_A4.Word


/*** LPF_A5 - A5 filter coeff; 0x8A ******************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A5H - A5 filter coeff (hi); 0x8A ***/
    union {
      byte Byte;
      struct {
        byte A5_8       :1;           /* Bit 0 */    
        byte A5_9       :1;           /* Bit 1 */
        byte A5_10      :1;           /* Bit 2 */
        byte A5_11      :1;           /* Bit 3 */
        byte A5_12      :1;           /* Bit 4 */
        byte A5_13      :1;           /* Bit 5 */
        byte A5_14      :1;           /* Bit 6 */
        byte A5_15      :1;           /* Bit 7 */
      } Bits;
    } LPF_A5HSTR;
    #define LPF_A5H _LPF_A5.Overlap_STR.LPF_A5HSTR.Byte

    /*** LPF_A5L - A5 filter coeff (lo); 0x8B ***/
    union {
      byte Byte;
      struct {
        byte A5_0       :1;           /* Bit 0 */
        byte A5_1       :1;           /* Bit 1 */
        byte A5_2       :1;           /* Bit 2 */
        byte A5_3       :1;           /* Bit 3 */
        byte A5_4       :1;           /* Bit 4 */
        byte A5_5       :1;           /* Bit 5 */
        byte A5_6       :1;           /* Bit 6 */
        byte A5_7       :1;           /* Bit 7 */
      } Bits;
    } LPF_A5LSTR;
    #define LPF_A5L _LPF_A5.Overlap_STR.LPF_A5LSTR.Byte

  } Overlap_STR;

  struct {
    word A5_0           :1;           /* bit 0 */
    word A5_1           :1;           /* bit 1 */
    word A5_2           :1;           /* bit 2 */
    word A5_3           :1;           /* bit 3 */
    word A5_4           :1;           /* bit 4 */
    word A5_5           :1;           /* bit 5 */
    word A5_6           :1;           /* bit 6 */
    word A5_7           :1;           /* bit 7 */
    word A5_8           :1;           /* bit 8 */
    word A5_9           :1;           /* bit 9 */
    word A5_10          :1;           /* bit 10 */
    word A5_11          :1;           /* bit 11 */
    word A5_12          :1;           /* bit 12 */
    word A5_13          :1;           /* bit 13 */
    word A5_14          :1;           /* bit 14 */
    word A5_15          :1;           /* bit 15 */
  } Bits;
} LPF_A5STR;
extern volatile LPF_A5STR _LPF_A5 @(D2DREG_BASE + 0x8A);
#define LPF_A5 _LPF_A5.Word


/*** LPF_A6 - A6 filter coeff; 0x8C ******************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A6H - A6 filter coeff (hi); 0x8C ***/
    union {
      byte Byte;
      struct {
        byte A6_8       :1;           /* Bit 0 */    
        byte A6_9       :1;           /* Bit 1 */
        byte A6_10      :1;           /* Bit 2 */
        byte A6_11      :1;           /* Bit 3 */
        byte A6_12      :1;           /* Bit 4 */
        byte A6_13      :1;           /* Bit 5 */
        byte A6_14      :1;           /* Bit 6 */
        byte A6_15      :1;           /* Bit 7 */
      } Bits;
    } LPF_A6HSTR;
    #define LPF_A6H _LPF_A6.Overlap_STR.LPF_A6HSTR.Byte

    /*** LPF_A6L - A6 filter coeff (lo); 0x8D ***/
    union {
      byte Byte;
      struct {
        byte A6_0       :1;           /* Bit 0 */
        byte A6_1       :1;           /* Bit 1 */
        byte A6_2       :1;           /* Bit 2 */
        byte A6_3       :1;           /* Bit 3 */
        byte A6_4       :1;           /* Bit 4 */
        byte A6_5       :1;           /* Bit 5 */
        byte A6_6       :1;           /* Bit 6 */
        byte A6_7       :1;           /* Bit 7 */
      } Bits;
    } LPF_A6LSTR;
    #define LPF_A6L _LPF_A6.Overlap_STR.LPF_A6LSTR.Byte

  } Overlap_STR;

  struct {
    word A6_0           :1;           /* bit 0 */
    word A6_1           :1;           /* bit 1 */
    word A6_2           :1;           /* bit 2 */
    word A6_3           :1;           /* bit 3 */
    word A6_4           :1;           /* bit 4 */
    word A6_5           :1;           /* bit 5 */
    word A6_6           :1;           /* bit 6 */
    word A6_7           :1;           /* bit 7 */
    word A6_8           :1;           /* bit 8 */
    word A6_9           :1;           /* bit 9 */
    word A6_10          :1;           /* bit 10 */
    word A6_11          :1;           /* bit 11 */
    word A6_12          :1;           /* bit 12 */
    word A6_13          :1;           /* bit 13 */
    word A6_14          :1;           /* bit 14 */
    word A6_15          :1;           /* bit 15 */
  } Bits;
} LPF_A6STR;
extern volatile LPF_A6STR _LPF_A6 @(D2DREG_BASE + 0x8C);
#define LPF_A6 _LPF_A6.Word


/*** LPF_A7 - A7 filter coeff; 0x8E ******************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A7H - A7 filter coeff (hi); 0x8E ***/
    union {
      byte Byte;
      struct {
        byte A7_8       :1;           /* Bit 0 */    
        byte A7_9       :1;           /* Bit 1 */
        byte A7_10      :1;           /* Bit 2 */
        byte A7_11      :1;           /* Bit 3 */
        byte A7_12      :1;           /* Bit 4 */
        byte A7_13      :1;           /* Bit 5 */
        byte A7_14      :1;           /* Bit 6 */
        byte A7_15      :1;           /* Bit 7 */
      } Bits;
    } LPF_A7HSTR;
    #define LPF_A7H _LPF_A7.Overlap_STR.LPF_A7HSTR.Byte

    /*** LPF_A7L - A7 filter coeff (lo); 0x8F ***/
    union {
      byte Byte;
      struct {
        byte A7_0       :1;           /* Bit 0 */
        byte A7_1       :1;           /* Bit 1 */
        byte A7_2       :1;           /* Bit 2 */
        byte A7_3       :1;           /* Bit 3 */
        byte A7_4       :1;           /* Bit 4 */
        byte A7_5       :1;           /* Bit 5 */
        byte A7_6       :1;           /* Bit 6 */
        byte A7_7       :1;           /* Bit 7 */
      } Bits;
    } LPF_A7LSTR;
    #define LPF_A7L _LPF_A7.Overlap_STR.LPF_A7LSTR.Byte

  } Overlap_STR;

  struct {
    word A7_0           :1;           /* bit 0 */
    word A7_1           :1;           /* bit 1 */
    word A7_2           :1;           /* bit 2 */
    word A7_3           :1;           /* bit 3 */
    word A7_4           :1;           /* bit 4 */
    word A7_5           :1;           /* bit 5 */
    word A7_6           :1;           /* bit 6 */
    word A7_7           :1;           /* bit 7 */
    word A7_8           :1;           /* bit 8 */
    word A7_9           :1;           /* bit 9 */
    word A7_10          :1;           /* bit 10 */
    word A7_11          :1;           /* bit 11 */
    word A7_12          :1;           /* bit 12 */
    word A7_13          :1;           /* bit 13 */
    word A7_14          :1;           /* bit 14 */
    word A7_15          :1;           /* bit 15 */
  } Bits;
} LPF_A7STR;
extern volatile LPF_A7STR _LPF_A7 @(D2DREG_BASE + 0x8E);
#define LPF_A7 _LPF_A7.Word


/*** LPF_A8 - A8 filter coeff; 0x90 ******************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A8H - A8 filter coeff (hi); 0x90 ***/
    union {
      byte Byte;
      struct {
        byte A8_8       :1;           /* Bit 0 */    
        byte A8_9       :1;           /* Bit 1 */
        byte A8_10      :1;           /* Bit 2 */
        byte A8_11      :1;           /* Bit 3 */
        byte A8_12      :1;           /* Bit 4 */
        byte A8_13      :1;           /* Bit 5 */
        byte A8_14      :1;           /* Bit 6 */
        byte A8_15      :1;           /* Bit 7 */
      } Bits;
    } LPF_A8HSTR;
    #define LPF_A8H _LPF_A8.Overlap_STR.LPF_A8HSTR.Byte

    /*** LPF_A8L - A8 filter coeff (lo); 0x91 ***/
    union {
      byte Byte;
      struct {
        byte A8_0       :1;           /* Bit 0 */
        byte A8_1       :1;           /* Bit 1 */
        byte A8_2       :1;           /* Bit 2 */
        byte A8_3       :1;           /* Bit 3 */
        byte A8_4       :1;           /* Bit 4 */
        byte A8_5       :1;           /* Bit 5 */
        byte A8_6       :1;           /* Bit 6 */
        byte A8_7       :1;           /* Bit 7 */
      } Bits;
    } LPF_A8LSTR;
    #define LPF_A8L _LPF_A8.Overlap_STR.LPF_A8LSTR.Byte

  } Overlap_STR;

  struct {
    word A8_0           :1;           /* bit 0 */
    word A8_1           :1;           /* bit 1 */
    word A8_2           :1;           /* bit 2 */
    word A8_3           :1;           /* bit 3 */
    word A8_4           :1;           /* bit 4 */
    word A8_5           :1;           /* bit 5 */
    word A8_6           :1;           /* bit 6 */
    word A8_7           :1;           /* bit 7 */
    word A8_8           :1;           /* bit 8 */
    word A8_9           :1;           /* bit 9 */
    word A8_10          :1;           /* bit 10 */
    word A8_11          :1;           /* bit 11 */
    word A8_12          :1;           /* bit 12 */
    word A8_13          :1;           /* bit 13 */
    word A8_14          :1;           /* bit 14 */
    word A8_15          :1;           /* bit 15 */
  } Bits;
} LPF_A8STR;
extern volatile LPF_A8STR _LPF_A8 @(D2DREG_BASE + 0x90);
#define LPF_A8 _LPF_A8.Word


/*** LPF_A9 - A9 filter coeff; 0x92 ******************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A9H - A9 filter coeff (hi); 0x92 ***/
    union {
      byte Byte;
      struct {
        byte A9_8       :1;           /* Bit 0 */    
        byte A9_9       :1;           /* Bit 1 */
        byte A9_10      :1;           /* Bit 2 */
        byte A9_11      :1;           /* Bit 3 */
        byte A9_12      :1;           /* Bit 4 */
        byte A9_13      :1;           /* Bit 5 */
        byte A9_14      :1;           /* Bit 6 */
        byte A9_15      :1;           /* Bit 7 */
      } Bits;
    } LPF_A9HSTR;
    #define LPF_A9H _LPF_A9.Overlap_STR.LPF_A9HSTR.Byte

    /*** LPF_A9L - A9 filter coeff (lo); 0x93 ***/
    union {
      byte Byte;
      struct {
        byte A9_0       :1;           /* Bit 0 */
        byte A9_1       :1;           /* Bit 1 */
        byte A9_2       :1;           /* Bit 2 */
        byte A9_3       :1;           /* Bit 3 */
        byte A9_4       :1;           /* Bit 4 */
        byte A9_5       :1;           /* Bit 5 */
        byte A9_6       :1;           /* Bit 6 */
        byte A9_7       :1;           /* Bit 7 */
      } Bits;
    } LPF_A9LSTR;
    #define LPF_A9L _LPF_A9.Overlap_STR.LPF_A9LSTR.Byte

  } Overlap_STR;

  struct {
    word A9_0           :1;           /* bit 0 */
    word A9_1           :1;           /* bit 1 */
    word A9_2           :1;           /* bit 2 */
    word A9_3           :1;           /* bit 3 */
    word A9_4           :1;           /* bit 4 */
    word A9_5           :1;           /* bit 5 */
    word A9_6           :1;           /* bit 6 */
    word A9_7           :1;           /* bit 7 */
    word A9_8           :1;           /* bit 8 */
    word A9_9           :1;           /* bit 9 */
    word A9_10          :1;           /* bit 10 */
    word A9_11          :1;           /* bit 11 */
    word A9_12          :1;           /* bit 12 */
    word A9_13          :1;           /* bit 13 */
    word A9_14          :1;           /* bit 14 */
    word A9_15          :1;           /* bit 15 */
  } Bits;
} LPF_A9STR;
extern volatile LPF_A9STR _LPF_A9 @(D2DREG_BASE + 0x92);
#define LPF_A9 _LPF_A9.Word


/*** LPF_A10 - A10 filter coeff; 0x94 ****************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A10H - A10 filter coeff (hi); 0x94 ***/
    union {
      byte Byte;
      struct {
        byte A10_8      :1;           /* Bit 0 */    
        byte A10_9      :1;           /* Bit 1 */
        byte A10_10     :1;           /* Bit 2 */
        byte A10_11     :1;           /* Bit 3 */
        byte A10_12     :1;           /* Bit 4 */
        byte A10_13     :1;           /* Bit 5 */
        byte A10_14     :1;           /* Bit 6 */
        byte A10_15     :1;           /* Bit 7 */
      } Bits;
    } LPF_A10HSTR;
    #define LPF_A10H _LPF_A10.Overlap_STR.LPF_A10HSTR.Byte

    /*** LPF_A10L - A10 filter coeff (lo); 0x95 ***/
    union {
      byte Byte;
      struct {
        byte A10_0      :1;           /* Bit 0 */
        byte A10_1      :1;           /* Bit 1 */
        byte A10_2      :1;           /* Bit 2 */
        byte A10_3      :1;           /* Bit 3 */
        byte A10_4      :1;           /* Bit 4 */
        byte A10_5      :1;           /* Bit 5 */
        byte A10_6      :1;           /* Bit 6 */
        byte A10_7      :1;           /* Bit 7 */
      } Bits;
    } LPF_A10LSTR;
    #define LPF_A10L _LPF_A10.Overlap_STR.LPF_A10LSTR.Byte

  } Overlap_STR;

  struct {
    word A10_0          :1;           /* bit 0 */
    word A10_1          :1;           /* bit 1 */
    word A10_2          :1;           /* bit 2 */
    word A10_3          :1;           /* bit 3 */
    word A10_4          :1;           /* bit 4 */
    word A10_5          :1;           /* bit 5 */
    word A10_6          :1;           /* bit 6 */
    word A10_7          :1;           /* bit 7 */
    word A10_8          :1;           /* bit 8 */
    word A10_9          :1;           /* bit 9 */
    word A10_10         :1;           /* bit 10 */
    word A10_11         :1;           /* bit 11 */
    word A10_12         :1;           /* bit 12 */
    word A10_13         :1;           /* bit 13 */
    word A10_14         :1;           /* bit 14 */
    word A10_15         :1;           /* bit 15 */
  } Bits;
} LPF_A10STR;
extern volatile LPF_A10STR _LPF_A10 @(D2DREG_BASE + 0x94);
#define LPF_A10 _LPF_A10.Word


/*** LPF_A11 - A11 filter coeff; 0x96 ****************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A11H - A11 filter coeff (hi); 0x96 ***/
    union {
      byte Byte;
      struct {
        byte A11_8      :1;           /* Bit 0 */    
        byte A11_9      :1;           /* Bit 1 */
        byte A11_10     :1;           /* Bit 2 */
        byte A11_11     :1;           /* Bit 3 */
        byte A11_12     :1;           /* Bit 4 */
        byte A11_13     :1;           /* Bit 5 */
        byte A11_14     :1;           /* Bit 6 */
        byte A11_15     :1;           /* Bit 7 */
      } Bits;
    } LPF_A11HSTR;
    #define LPF_A11H _LPF_A11.Overlap_STR.LPF_A11HSTR.Byte

    /*** LPF_A11L - A11 filter coeff (lo); 0x97 ***/
    union {
      byte Byte;
      struct {
        byte A11_0      :1;           /* Bit 0 */
        byte A11_1      :1;           /* Bit 1 */
        byte A11_2      :1;           /* Bit 2 */
        byte A11_3      :1;           /* Bit 3 */
        byte A11_4      :1;           /* Bit 4 */
        byte A11_5      :1;           /* Bit 5 */
        byte A11_6      :1;           /* Bit 6 */
        byte A11_7      :1;           /* Bit 7 */
      } Bits;
    } LPF_A11LSTR;
    #define LPF_A11L _LPF_A11.Overlap_STR.LPF_A11LSTR.Byte

  } Overlap_STR;

  struct {
    word A11_0          :1;           /* bit 0 */
    word A11_1          :1;           /* bit 1 */
    word A11_2          :1;           /* bit 2 */
    word A11_3          :1;           /* bit 3 */
    word A11_4          :1;           /* bit 4 */
    word A11_5          :1;           /* bit 5 */
    word A11_6          :1;           /* bit 6 */
    word A11_7          :1;           /* bit 7 */
    word A11_8          :1;           /* bit 8 */
    word A11_9          :1;           /* bit 9 */
    word A11_10         :1;           /* bit 10 */
    word A11_11         :1;           /* bit 11 */
    word A11_12         :1;           /* bit 12 */
    word A11_13         :1;           /* bit 13 */
    word A11_14         :1;           /* bit 14 */
    word A11_15         :1;           /* bit 15 */
  } Bits;
} LPF_A11STR;
extern volatile LPF_A11STR _LPF_A11 @(D2DREG_BASE + 0x96);
#define LPF_A11 _LPF_A11.Word


/*** LPF_A12 - A12 filter coeff; 0x98 ****************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A12H - A12 filter coeff (hi); 0x98 ***/
    union {
      byte Byte;
      struct {
        byte A12_8      :1;           /* Bit 0 */    
        byte A12_9      :1;           /* Bit 1 */
        byte A12_10     :1;           /* Bit 2 */
        byte A12_11     :1;           /* Bit 3 */
        byte A12_12     :1;           /* Bit 4 */
        byte A12_13     :1;           /* Bit 5 */
        byte A12_14     :1;           /* Bit 6 */
        byte A12_15     :1;           /* Bit 7 */
      } Bits;
    } LPF_A12HSTR;
    #define LPF_A12H _LPF_A12.Overlap_STR.LPF_A12HSTR.Byte

    /*** LPF_A12L - A12 filter coeff (lo); 0x99 ***/
    union {
      byte Byte;
      struct {
        byte A12_0      :1;           /* Bit 0 */
        byte A12_1      :1;           /* Bit 1 */
        byte A12_2      :1;           /* Bit 2 */
        byte A12_3      :1;           /* Bit 3 */
        byte A12_4      :1;           /* Bit 4 */
        byte A12_5      :1;           /* Bit 5 */
        byte A12_6      :1;           /* Bit 6 */
        byte A12_7      :1;           /* Bit 7 */
      } Bits;
    } LPF_A12LSTR;
    #define LPF_A12L _LPF_A12.Overlap_STR.LPF_A12LSTR.Byte

  } Overlap_STR;

  struct {
    word A12_0          :1;           /* bit 0 */
    word A12_1          :1;           /* bit 1 */
    word A12_2          :1;           /* bit 2 */
    word A12_3          :1;           /* bit 3 */
    word A12_4          :1;           /* bit 4 */
    word A12_5          :1;           /* bit 5 */
    word A12_6          :1;           /* bit 6 */
    word A12_7          :1;           /* bit 7 */
    word A12_8          :1;           /* bit 8 */
    word A12_9          :1;           /* bit 9 */
    word A12_10         :1;           /* bit 10 */
    word A12_11         :1;           /* bit 11 */
    word A12_12         :1;           /* bit 12 */
    word A12_13         :1;           /* bit 13 */
    word A12_14         :1;           /* bit 14 */
    word A12_15         :1;           /* bit 15 */
  } Bits;
} LPF_A12STR;
extern volatile LPF_A12STR _LPF_A12 @(D2DREG_BASE + 0x98);
#define LPF_A12 _LPF_A12.Word


/*** LPF_A13 - A13 filter coeff; 0x9A ****************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A13H - A13 filter coeff (hi); 0x9A ***/
    union {
      byte Byte;
      struct {
        byte A13_8      :1;           /* Bit 0 */    
        byte A13_9      :1;           /* Bit 1 */
        byte A13_10     :1;           /* Bit 2 */
        byte A13_11     :1;           /* Bit 3 */
        byte A13_12     :1;           /* Bit 4 */
        byte A13_13     :1;           /* Bit 5 */
        byte A13_14     :1;           /* Bit 6 */
        byte A13_15     :1;           /* Bit 7 */
      } Bits;
    } LPF_A13HSTR;
    #define LPF_A13H _LPF_A13.Overlap_STR.LPF_A13HSTR.Byte

    /*** LPF_A13L - A13 filter coeff (lo); 0x9B ***/
    union {
      byte Byte;
      struct {
        byte A13_0      :1;           /* Bit 0 */
        byte A13_1      :1;           /* Bit 1 */
        byte A13_2      :1;           /* Bit 2 */
        byte A13_3      :1;           /* Bit 3 */
        byte A13_4      :1;           /* Bit 4 */
        byte A13_5      :1;           /* Bit 5 */
        byte A13_6      :1;           /* Bit 6 */
        byte A13_7      :1;           /* Bit 7 */
      } Bits;
    } LPF_A13LSTR;
    #define LPF_A13L _LPF_A13.Overlap_STR.LPF_A13LSTR.Byte

  } Overlap_STR;

  struct {
    word A13_0          :1;           /* bit 0 */
    word A13_1          :1;           /* bit 1 */
    word A13_2          :1;           /* bit 2 */
    word A13_3          :1;           /* bit 3 */
    word A13_4          :1;           /* bit 4 */
    word A13_5          :1;           /* bit 5 */
    word A13_6          :1;           /* bit 6 */
    word A13_7          :1;           /* bit 7 */
    word A13_8          :1;           /* bit 8 */
    word A13_9          :1;           /* bit 9 */
    word A13_10         :1;           /* bit 10 */
    word A13_11         :1;           /* bit 11 */
    word A13_12         :1;           /* bit 12 */
    word A13_13         :1;           /* bit 13 */
    word A13_14         :1;           /* bit 14 */
    word A13_15         :1;           /* bit 15 */
  } Bits;
} LPF_A13STR;
extern volatile LPF_A13STR _LPF_A13 @(D2DREG_BASE + 0x9A);
#define LPF_A13 _LPF_A13.Word


/*** LPF_A14 - A14 filter coeff; 0x9C ****************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A14H - A14 filter coeff (hi); 0x9C ***/
    union {
      byte Byte;
      struct {
        byte A14_8      :1;           /* Bit 0 */    
        byte A14_9      :1;           /* Bit 1 */
        byte A14_10     :1;           /* Bit 2 */
        byte A14_11     :1;           /* Bit 3 */
        byte A14_12     :1;           /* Bit 4 */
        byte A14_13     :1;           /* Bit 5 */
        byte A14_14     :1;           /* Bit 6 */
        byte A14_15     :1;           /* Bit 7 */
      } Bits;
    } LPF_A14HSTR;
    #define LPF_A14H _LPF_A14.Overlap_STR.LPF_A14HSTR.Byte

    /*** LPF_A14L - A14 filter coeff (lo); 0x9D ***/
    union {
      byte Byte;
      struct {
        byte A14_0      :1;           /* Bit 0 */
        byte A14_1      :1;           /* Bit 1 */
        byte A14_2      :1;           /* Bit 2 */
        byte A14_3      :1;           /* Bit 3 */
        byte A14_4      :1;           /* Bit 4 */
        byte A14_5      :1;           /* Bit 5 */
        byte A14_6      :1;           /* Bit 6 */
        byte A14_7      :1;           /* Bit 7 */
      } Bits;
    } LPF_A14LSTR;
    #define LPF_A14L _LPF_A14.Overlap_STR.LPF_A14LSTR.Byte

  } Overlap_STR;

  struct {
    word A14_0          :1;           /* bit 0 */
    word A14_1          :1;           /* bit 1 */
    word A14_2          :1;           /* bit 2 */
    word A14_3          :1;           /* bit 3 */
    word A14_4          :1;           /* bit 4 */
    word A14_5          :1;           /* bit 5 */
    word A14_6          :1;           /* bit 6 */
    word A14_7          :1;           /* bit 7 */
    word A14_8          :1;           /* bit 8 */
    word A14_9          :1;           /* bit 9 */
    word A14_10         :1;           /* bit 10 */
    word A14_11         :1;           /* bit 11 */
    word A14_12         :1;           /* bit 12 */
    word A14_13         :1;           /* bit 13 */
    word A14_14         :1;           /* bit 14 */
    word A14_15         :1;           /* bit 15 */
  } Bits;
} LPF_A14STR;
extern volatile LPF_A14STR _LPF_A14 @(D2DREG_BASE + 0x9C);
#define LPF_A14 _LPF_A14.Word


/*** LPF_A15 - A15 filter coeff; 0x9E ****************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LPF_A15H - A15 filter coeff (hi); 0x9E ***/
    union {
      byte Byte;
      struct {
        byte A15_8      :1;           /* Bit 0 */    
        byte A15_9      :1;           /* Bit 1 */
        byte A15_10     :1;           /* Bit 2 */
        byte A15_11     :1;           /* Bit 3 */
        byte A15_12     :1;           /* Bit 4 */
        byte A15_13     :1;           /* Bit 5 */
        byte A15_14     :1;           /* Bit 6 */
        byte A15_15     :1;           /* Bit 7 */
      } Bits;
    } LPF_A15HSTR;
    #define LPF_A15H _LPF_A15.Overlap_STR.LPF_A15HSTR.Byte

    /*** LPF_A15L - A15 filter coeff (lo); 0x9F ***/
    union {
      byte Byte;
      struct {
        byte A15_0      :1;           /* Bit 0 */
        byte A15_1      :1;           /* Bit 1 */
        byte A15_2      :1;           /* Bit 2 */
        byte A15_3      :1;           /* Bit 3 */
        byte A15_4      :1;           /* Bit 4 */
        byte A15_5      :1;           /* Bit 5 */
        byte A15_6      :1;           /* Bit 6 */
        byte A15_7      :1;           /* Bit 7 */
      } Bits;
    } LPF_A15LSTR;
    #define LPF_A15L _LPF_A15.Overlap_STR.LPF_A15LSTR.Byte

  } Overlap_STR;

  struct {
    word A15_0          :1;           /* bit 0 */
    word A15_1          :1;           /* bit 1 */
    word A15_2          :1;           /* bit 2 */
    word A15_3          :1;           /* bit 3 */
    word A15_4          :1;           /* bit 4 */
    word A15_5          :1;           /* bit 5 */
    word A15_6          :1;           /* bit 6 */
    word A15_7          :1;           /* bit 7 */
    word A15_8          :1;           /* bit 8 */
    word A15_9          :1;           /* bit 9 */
    word A15_10         :1;           /* bit 10 */
    word A15_11         :1;           /* bit 11 */
    word A15_12         :1;           /* bit 12 */
    word A15_13         :1;           /* bit 13 */
    word A15_14         :1;           /* bit 14 */
    word A15_15         :1;           /* bit 15 */
  } Bits;
} LPF_A15STR;
extern volatile LPF_A15STR _LPF_A15 @(D2DREG_BASE + 0x9E);
#define LPF_A15 _LPF_A15.Word


/*** COMP_CTL - Compensation control register; 0xA0 **************************/
typedef union {
  word Word;
  struct {
    word CALIE          :1;           /* bit 0 */
    word                :1;           /* bit 1 */
    word DIAGI          :1;           /* bit 2 */
    word DIAGV          :1;           /* bit 3 */
    word PGAO           :1;           /* bit 4 */
    word PGAZ           :1;           /* bit 5 */
    word BGCAL0         :1;           /* bit 6 */
    word BGCAL1         :1;           /* bit 7 */
    word CALIEM         :1;           /* bit 8 */
    word                :1;           /* bit 9 */
    word DIAGIM         :1;           /* bit 10 */
    word DIAGVM         :1;           /* bit 11 */
    word PGAOM          :1;           /* bit 12 */
    word PGAZM          :1;           /* bit 13 */
    word BGCAL0M        :1;           /* bit 14 */
    word BGCAL1M        :1;           /* bit 15 */
  } Bits;
} COMP_CTLSTR;
extern volatile COMP_CTLSTR _COMP_CTL @(D2DREG_BASE + 0xA0);
#define COMP_CTL _COMP_CTL.Word


/*** COMP_SR - Compensation status register; 0xA2 ****************************/
typedef union {
  byte Byte;
  struct {
    byte CALF           :1;           /* bit 0 */
    byte                :1;           /* bit 1 */
    byte                :1;           /* bit 2 */
    byte                :1;           /* bit 3 */
    byte PGAOF          :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte BGRF           :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} COMP_SRSTR;
extern volatile COMP_SRSTR _COMP_SR @(D2DREG_BASE + 0xA2);
#define COMP_SR _COMP_SR.Byte


/*** COMP_TF - Temperature Filtering Period; 0xA3 ****************************/
typedef union {
  byte Byte;
  struct {
    byte TMF0           :1;           /* bit 0 */
    byte TMF1           :1;           /* bit 1 */
    byte TMF2           :1;           /* bit 2 */
    byte                :1;           /* bit 3 */
    byte                :1;           /* bit 4 */
    byte                :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} COMP_TFSTR;
extern volatile COMP_TFSTR _COMP_TF @(D2DREG_BASE + 0xA3);
#define COMP_TF _COMP_TF.Byte


/*** COMP_TMAX - Max temp before recalib; 0xA4 *******************************/
typedef union {
  word Word;
  struct {
    word TCMAX0         :1;           /* bit 0 */
    word TCMAX1         :1;           /* bit 1 */
    word TCMAX2         :1;           /* bit 2 */
    word TCMAX3         :1;           /* bit 3 */
    word TCMAX4         :1;           /* bit 4 */
    word TCMAX5         :1;           /* bit 5 */
    word TCMAX6         :1;           /* bit 6 */
    word TCMAX7         :1;           /* bit 7 */
    word TCMAX8         :1;           /* bit 8 */
    word TCMAX9         :1;           /* bit 9 */
    word TCMAX10        :1;           /* bit 10 */
    word TCMAX11        :1;           /* bit 11 */
    word TCMAX12        :1;           /* bit 12 */
    word TCMAX13        :1;           /* bit 13 */
    word TCMAX14        :1;           /* bit 14 */
    word TCMAX15        :1;           /* bit 15 */
  } Bits;
} COMP_TMAXSTR;
extern volatile COMP_TMAXSTR _COMP_TMAX @(D2DREG_BASE + 0xA4);
#define COMP_TMAX _COMP_TMAX.Word
													

/*** COMP_TMIN - Min temp before recalib; 0xA6 *******************************/
typedef union {
  word Word;
  struct {
    word TCMIN0         :1;           /* bit 0 */
    word TCMIN1         :1;           /* bit 1 */
    word TCMIN2         :1;           /* bit 2 */
    word TCMIN3         :1;           /* bit 3 */
    word TCMIN4         :1;           /* bit 4 */
    word TCMIN5         :1;           /* bit 5 */
    word TCMIN6         :1;           /* bit 6 */
    word TCMIN7         :1;           /* bit 7 */
    word TCMIN8         :1;           /* bit 8 */
    word TCMIN9         :1;           /* bit 9 */
    word TCMIN10        :1;           /* bit 10 */
    word TCMIN11        :1;           /* bit 11 */
    word TCMIN12        :1;           /* bit 12 */
    word TCMIN13        :1;           /* bit 13 */
    word TCMIN14        :1;           /* bit 14 */
    word TCMIN15        :1;           /* bit 15 */
  } Bits;
} COMP_TMINSTR;
extern volatile COMP_TMINSTR _COMP_TMIN @(D2DREG_BASE + 0xA6);
#define COMP_TMIN _COMP_TMIN.Word
													

/*** COMP_VO - Offset voltage compensation; 0xAA *****************************/
typedef union {
  byte Byte;
  struct {
    byte VOC0           :1;           /* bit 0 */
    byte VOC1           :1;           /* bit 1 */
    byte VOC2           :1;           /* bit 2 */
    byte VOC3           :1;           /* bit 3 */
    byte VOC4           :1;           /* bit 4 */
    byte VOC5           :1;           /* bit 5 */
    byte VOC6           :1;           /* bit 6 */
    byte VOC7           :1;           /* bit 7 */
  } Bits;
} COMP_VOSTR;
extern volatile COMP_VOSTR _COMP_VO @(D2DREG_BASE + 0xAA);
#define COMP_VO _COMP_VO.Byte


/*** COMP_IO - Offset current compensation; 0xAB *****************************/
typedef union {
  byte Byte;
  struct {
    byte COC0           :1;           /* bit 0 */
    byte COC1           :1;           /* bit 1 */
    byte COC2           :1;           /* bit 2 */
    byte COC3           :1;           /* bit 3 */
    byte COC4           :1;           /* bit 4 */
    byte COC5           :1;           /* bit 5 */
    byte COC6           :1;           /* bit 6 */
    byte COC7           :1;           /* bit 7 */
  } Bits;
} COMP_IOSTR;
extern volatile COMP_IOSTR _COMP_IO @(D2DREG_BASE + 0xAB);
#define COMP_IO _COMP_IO.Byte

													
/*** COMP_VSG - Gain voltage compensation for voltage channel; 0xAC ***********/
typedef union {
  word Word;
  struct {
    word VSGC0          :1;           /* bit 0 */
    word VSGC1          :1;           /* bit 1 */
    word VSGC2          :1;           /* bit 2 */
    word VSGC3          :1;           /* bit 3 */
    word VSGC4          :1;           /* bit 4 */
    word VSGC5          :1;           /* bit 5 */
    word VSGC6          :1;           /* bit 6 */
    word VSGC7          :1;           /* bit 7 */
    word VSGC8          :1;           /* bit 8 */
    word VSGC9          :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_VSGSTR;
extern volatile COMP_VSGSTR _COMP_VSG @(D2DREG_BASE + 0xAC);
#define COMP_VSG _COMP_VSG.Word
													

/*** COMP_IG4 - Gain current compensation 4;  0xB0 ***************************/
typedef union {
  word Word;
  struct {
    word IGC4_0         :1;           /* bit 0 */
    word IGC4_1         :1;           /* bit 1 */
    word IGC4_2         :1;           /* bit 2 */
    word IGC4_3         :1;           /* bit 3 */
    word IGC4_4         :1;           /* bit 4 */
    word IGC4_5         :1;           /* bit 5 */
    word IGC4_6         :1;           /* bit 6 */
    word IGC4_7         :1;           /* bit 7 */
    word IGC4_8         :1;           /* bit 8 */
    word IGC4_9         :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_IG4STR;
extern volatile COMP_IG4STR _COMP_IG4 @(D2DREG_BASE + 0xB0);
#define COMP_IG4 _COMP_IG4.Word


/*** COMP_IG8 - Gain current compensation 8;  0xB2 ***************************/
typedef union {
  word Word;
  struct {
    word IGC8_0         :1;           /* bit 0 */
    word IGC8_1         :1;           /* bit 1 */
    word IGC8_2         :1;           /* bit 2 */
    word IGC8_3         :1;           /* bit 3 */
    word IGC8_4         :1;           /* bit 4 */
    word IGC8_5         :1;           /* bit 5 */
    word IGC8_6         :1;           /* bit 6 */
    word IGC8_7         :1;           /* bit 7 */
    word IGC8_8         :1;           /* bit 8 */
    word IGC8_9         :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_IG8STR;
extern volatile COMP_IG8STR _COMP_IG8 @(D2DREG_BASE + 0xB2);
#define COMP_IG8 _COMP_IG8.Word


/*** COMP_IG16 - Gain current compensation 16;  0xB4 *************************/
typedef union {
  word Word;
  struct {
    word IGC16_0        :1;           /* bit 0 */
    word IGC16_1        :1;           /* bit 1 */
    word IGC16_2        :1;           /* bit 2 */
    word IGC16_3        :1;           /* bit 3 */
    word IGC16_4        :1;           /* bit 4 */
    word IGC16_5        :1;           /* bit 5 */
    word IGC16_6        :1;           /* bit 6 */
    word IGC16_7        :1;           /* bit 7 */
    word IGC16_8        :1;           /* bit 8 */
    word IGC16_9        :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_IG16STR;
extern volatile COMP_IG16STR _COMP_IG16 @(D2DREG_BASE + 0xB4);
#define COMP_IG16 _COMP_IG16.Word


/*** COMP_IG32 - Gain current compensation 32;  0xB6 *************************/
typedef union {
  word Word;
  struct {
    word IGC32_0        :1;           /* bit 0 */
    word IGC32_1        :1;           /* bit 1 */
    word IGC32_2        :1;           /* bit 2 */
    word IGC32_3        :1;           /* bit 3 */
    word IGC32_4        :1;           /* bit 4 */
    word IGC32_5        :1;           /* bit 5 */
    word IGC32_6        :1;           /* bit 6 */
    word IGC32_7        :1;           /* bit 7 */
    word IGC32_8        :1;           /* bit 8 */
    word IGC32_9        :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_IG32STR;
extern volatile COMP_IG32STR _COMP_IG32 @(D2DREG_BASE + 0xB6);
#define COMP_IG32 _COMP_IG32.Word


/*** COMP_IG64 - Gain current compensation 64;  0xB8 *************************/
typedef union {
  word Word;
  struct {
    word IGC64_0        :1;           /* bit 0 */
    word IGC64_1        :1;           /* bit 1 */
    word IGC64_2        :1;           /* bit 2 */
    word IGC64_3        :1;           /* bit 3 */
    word IGC64_4        :1;           /* bit 4 */
    word IGC64_5        :1;           /* bit 5 */
    word IGC64_6        :1;           /* bit 6 */
    word IGC64_7        :1;           /* bit 7 */
    word IGC64_8        :1;           /* bit 8 */
    word IGC64_9        :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_IG64STR;
extern volatile COMP_IG64STR _COMP_IG64 @(D2DREG_BASE + 0xB8);
#define COMP_IG64 _COMP_IG64.Word


/*** COMP_IG128 - Gain current compensation 128;  0xBA ***********************/
typedef union {
  word Word;
  struct {
    word IGC128_0       :1;           /* bit 0 */
    word IGC128_1       :1;           /* bit 1 */
    word IGC128_2       :1;           /* bit 2 */
    word IGC128_3       :1;           /* bit 3 */
    word IGC128_4       :1;           /* bit 4 */
    word IGC128_5       :1;           /* bit 5 */
    word IGC128_6       :1;           /* bit 6 */
    word IGC128_7       :1;           /* bit 7 */
    word IGC128_8       :1;           /* bit 8 */
    word IGC128_9       :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_IG128STR;
extern volatile COMP_IG128STR _COMP_IG128 @(D2DREG_BASE + 0xBA);
#define COMP_IG128 _COMP_IG128.Word


/*** COMP_IG256 - Gain current compensation 256;  0xBC ***********************/
typedef union {
  word Word;
  struct {
    word IGC256_0       :1;           /* bit 0 */
    word IGC256_1       :1;           /* bit 1 */
    word IGC256_2       :1;           /* bit 2 */
    word IGC256_3       :1;           /* bit 3 */
    word IGC256_4       :1;           /* bit 4 */
    word IGC256_5       :1;           /* bit 5 */
    word IGC256_6       :1;           /* bit 6 */
    word IGC256_7       :1;           /* bit 7 */
    word IGC256_8       :1;           /* bit 8 */
    word IGC256_9       :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_IG256STR;
extern volatile COMP_IG256STR _COMP_IG256 @(D2DREG_BASE + 0xBC);
#define COMP_IG256 _COMP_IG256.Word


/*** COMP_IG512 - Gain current compensation 512;  0xBE ***********************/
typedef union {
  word Word;
  struct {
    word IGC512_0       :1;           /* bit 0 */
    word IGC512_1       :1;           /* bit 1 */
    word IGC512_2       :1;           /* bit 2 */
    word IGC512_3       :1;           /* bit 3 */
    word IGC512_4       :1;           /* bit 4 */
    word IGC512_5       :1;           /* bit 5 */
    word IGC512_6       :1;           /* bit 6 */
    word IGC512_7       :1;           /* bit 7 */
    word IGC512_8       :1;           /* bit 8 */
    word IGC512_9       :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_IG512STR;
extern volatile COMP_IG512STR _COMP_IG512 @(D2DREG_BASE + 0xBE);
#define COMP_IG512 _COMP_IG512.Word
									

/*** COMP_PGAO4 - Offset PGA compensation 4;  0xC0 ***************************/
typedef union {
  word Word;
  struct {
    word PGAOC4_0       :1;           /* bit 0 */
    word PGAOC4_1       :1;           /* bit 1 */
    word PGAOC4_2       :1;           /* bit 2 */
    word PGAOC4_3       :1;           /* bit 3 */
    word PGAOC4_4       :1;           /* bit 4 */
    word PGAOC4_5       :1;           /* bit 5 */
    word PGAOC4_6       :1;           /* bit 6 */
    word PGAOC4_7       :1;           /* bit 7 */
    word PGAOC4_8       :1;           /* bit 8 */
    word PGAOC4_9       :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_PGAO4STR;
extern volatile COMP_PGAO4STR _COMP_PGAO4 @(D2DREG_BASE + 0xC0);
#define COMP_PGAO4 _COMP_PGAO4.Word


/*** COMP_PGAO8 - Offset PGA compensation 8;  0xC2 ***************************/
typedef union {
  word Word;
  struct {
    word PGAOC8_0       :1;           /* bit 0 */
    word PGAOC8_1       :1;           /* bit 1 */
    word PGAOC8_2       :1;           /* bit 2 */
    word PGAOC8_3       :1;           /* bit 3 */
    word PGAOC8_4       :1;           /* bit 4 */
    word PGAOC8_5       :1;           /* bit 5 */
    word PGAOC8_6       :1;           /* bit 6 */
    word PGAOC8_7       :1;           /* bit 7 */
    word PGAOC8_8       :1;           /* bit 8 */
    word PGAOC8_9       :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_PGAO8STR;
extern volatile COMP_PGAO8STR _COMP_PGAO8 @(D2DREG_BASE + 0xC2);
#define COMP_PGAO8 _COMP_PGAO8.Word


/*** COMP_PGAO16 - Offset PGA compensation 16;  0xC4 *************************/
typedef union {
  word Word;
  struct {
    word PGAOC16_0      :1;           /* bit 0 */
    word PGAOC16_1      :1;           /* bit 1 */
    word PGAOC16_2      :1;           /* bit 2 */
    word PGAOC16_3      :1;           /* bit 3 */
    word PGAOC16_4      :1;           /* bit 4 */
    word PGAOC16_5      :1;           /* bit 5 */
    word PGAOC16_6      :1;           /* bit 6 */
    word PGAOC16_7      :1;           /* bit 7 */
    word PGAOC16_8      :1;           /* bit 8 */
    word PGAOC16_9      :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_PGAO16STR;
extern volatile COMP_PGAO16STR _COMP_PGAO16 @(D2DREG_BASE + 0xC4);
#define COMP_PGAO16 _COMP_PGAO16.Word


/*** COMP_PGAO32 - Offset PGA compensation 32;  0xC6 *************************/
typedef union {
  word Word;
  struct {
    word PGAOC32_0      :1;           /* bit 0 */
    word PGAOC32_1      :1;           /* bit 1 */
    word PGAOC32_2      :1;           /* bit 2 */
    word PGAOC32_3      :1;           /* bit 3 */
    word PGAOC32_4      :1;           /* bit 4 */
    word PGAOC32_5      :1;           /* bit 5 */
    word PGAOC32_6      :1;           /* bit 6 */
    word PGAOC32_7      :1;           /* bit 7 */
    word PGAOC32_8      :1;           /* bit 8 */
    word PGAOC32_9      :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_PGAO32STR;
extern volatile COMP_PGAO32STR _COMP_PGAO32 @(D2DREG_BASE + 0xC6);
#define COMP_PGAO32 _COMP_PGAO32.Word


/*** COMP_PGAO64 - Offset PGA compensation 64;  0xC8 *************************/
typedef union {
  word Word;
  struct {
    word PGAOC64_0      :1;           /* bit 0 */
    word PGAOC64_1      :1;           /* bit 1 */
    word PGAOC64_2      :1;           /* bit 2 */
    word PGAOC64_3      :1;           /* bit 3 */
    word PGAOC64_4      :1;           /* bit 4 */
    word PGAOC64_5      :1;           /* bit 5 */
    word PGAOC64_6      :1;           /* bit 6 */
    word PGAOC64_7      :1;           /* bit 7 */
    word PGAOC64_8      :1;           /* bit 8 */
    word PGAOC64_9      :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_PGAO64STR;
extern volatile COMP_PGAO64STR _COMP_PGAO64 @(D2DREG_BASE + 0xC8);
#define COMP_PGAO64 _COMP_PGAO64.Word


/*** COMP_PGAO128 - Offset PGA compensation 128;  0xCA ***********************/
typedef union {
  word Word;
  struct {
    word PGAOC128_0     :1;           /* bit 0 */
    word PGAOC128_1     :1;           /* bit 1 */
    word PGAOC128_2     :1;           /* bit 2 */
    word PGAOC128_3     :1;           /* bit 3 */
    word PGAOC128_4     :1;           /* bit 4 */
    word PGAOC128_5     :1;           /* bit 5 */
    word PGAOC128_6     :1;           /* bit 6 */
    word PGAOC128_7     :1;           /* bit 7 */
    word PGAOC128_8     :1;           /* bit 8 */
    word PGAOC128_9     :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_PGAO128STR;
extern volatile COMP_PGAO128STR _COMP_PGAO128 @(D2DREG_BASE + 0xCA);
#define COMP_PGAO128 _COMP_PGAO128.Word


/*** COMP_PGAO256 - Offset PGA compensation 256;  0xCC ***********************/
typedef union {
  word Word;
  struct {
    word PGAOC256_0     :1;           /* bit 0 */
    word PGAOC256_1     :1;           /* bit 1 */
    word PGAOC256_2     :1;           /* bit 2 */
    word PGAOC256_3     :1;           /* bit 3 */
    word PGAOC256_4     :1;           /* bit 4 */
    word PGAOC256_5     :1;           /* bit 5 */
    word PGAOC256_6     :1;           /* bit 6 */
    word PGAOC256_7     :1;           /* bit 7 */
    word PGAOC256_8     :1;           /* bit 8 */
    word PGAOC256_9     :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_PGAO256STR;
extern volatile COMP_PGAO256STR _COMP_PGAO256 @(D2DREG_BASE + 0xCC);
#define COMP_PGAO256 _COMP_PGAO256.Word


/*** COMP_PGAO512 - Offset PGA compensation 512;  0xCE ***********************/
typedef union {
  word Word;
  struct {
    word PGAOC512_0     :1;           /* bit 0 */
    word PGAOC512_1     :1;           /* bit 1 */
    word PGAOC512_2     :1;           /* bit 2 */
    word PGAOC512_3     :1;           /* bit 3 */
    word PGAOC512_4     :1;           /* bit 4 */
    word PGAOC512_5     :1;           /* bit 5 */
    word PGAOC512_6     :1;           /* bit 6 */
    word PGAOC512_7     :1;           /* bit 7 */
    word PGAOC512_8     :1;           /* bit 8 */
    word PGAOC512_9     :1;           /* bit 9 */
    word                :1;           /* bit 10 */
    word                :1;           /* bit 11 */
    word                :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} COMP_PGAO512STR;
extern volatile COMP_PGAO512STR _COMP_PGAO512 @(D2DREG_BASE + 0xCE);
#define COMP_PGAO512 _COMP_PGAO512.Word


/*** COMP_IT - Internal temperature offset/gain compensation; 0xD0 ***********/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** COMP_ITO - Internal temperature offset compensation; 0xD0 ***/
    union {
      byte Byte;
      struct {
        byte ITOC0      :1;           /* Bit 0 */    
        byte ITOC1      :1;           /* Bit 1 */
        byte ITOC2      :1;           /* Bit 2 */
        byte ITOC3      :1;           /* Bit 3 */
        byte ITOC4      :1;           /* Bit 4 */
        byte ITOC5      :1;           /* Bit 5 */
        byte ITOC6      :1;           /* Bit 6 */
        byte ITOC7      :1;           /* Bit 7 */
      } Bits;
    } COMP_ITOSTR;
    #define COMP_ITO _COMP_IT.Overlap_STR.COMP_ITOSTR.Byte

    /*** COMP_ITG - Internal temperature gain compensation; 0xD1 ***/
    union {
      byte Byte;
      struct {
        byte ITGC0      :1;           /* Bit 0 */
        byte ITGC1      :1;           /* Bit 1 */
        byte ITGC2      :1;           /* Bit 2 */
        byte ITGC3      :1;           /* Bit 3 */
        byte ITGC4      :1;           /* Bit 4 */
        byte ITGC5      :1;           /* Bit 5 */
        byte ITGC6      :1;           /* Bit 6 */
        byte ITGC8      :1;           /* Bit 7 */
      } Bits;
    } COMP_ITGSTR;
    #define COMP_ITG _COMP_IT.Overlap_STR.COMP_ITGSTR.Byte

  } Overlap_STR;

  struct {
    word ITGC0          :1;           /* bit 0 */
    word ITGC1          :1;           /* bit 1 */
    word ITGC2          :1;           /* bit 2 */
    word ITGC3          :1;           /* bit 3 */
    word ITGC4          :1;           /* bit 4 */
    word ITGC5          :1;           /* bit 5 */
    word ITGC6          :1;           /* bit 6 */
    word ITGC8          :1;           /* bit 7 */
    word ITOC0          :1;           /* bit 8 */
    word ITOC1          :1;           /* bit 9 */
    word ITOC2          :1;           /* bit 10 */
    word ITOC3          :1;           /* bit 11 */
    word ITOC4          :1;           /* bit 12 */
    word ITOC5          :1;           /* bit 13 */
    word ITOC6          :1;           /* bit 14 */
    word ITOC7          :1;           /* bit 15 */
  } Bits;
} COMP_ITSTR;
extern volatile COMP_ITSTR _COMP_IT @(D2DREG_BASE + 0xD0);
#define COMP_IT _COMP_IT.Word


/*** COMP_ET - External temperature offset/gain compensation; 0xD2 ***********/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** COMP_ETO - External temperature offset compensation; 0xD2 ***/
    union {
      byte Byte;
      struct {
        byte ETOC0      :1;           /* Bit 0 */    
        byte ETOC1      :1;           /* Bit 1 */
        byte ETOC2      :1;           /* Bit 2 */
        byte ETOC3      :1;           /* Bit 3 */
        byte ETOC4      :1;           /* Bit 4 */
        byte ETOC5      :1;           /* Bit 5 */
        byte ETOC6      :1;           /* Bit 6 */
        byte ETOC7      :1;           /* Bit 7 */
      } Bits;
    } COMP_ETOSTR;
    #define COMP_ETO _COMP_ET.Overlap_STR.COMP_ETOSTR.Byte

    /*** COMP_ETG - External temperature gain compensation; 0xD3 ***/
    union {
      byte Byte;
      struct {
        byte ETGC0      :1;           /* Bit 0 */
        byte ETGC1      :1;           /* Bit 1 */
        byte ETGC2      :1;           /* Bit 2 */
        byte ETGC3      :1;           /* Bit 3 */
        byte ETGC4      :1;           /* Bit 4 */
        byte ETGC5      :1;           /* Bit 5 */
        byte ETGC6      :1;           /* Bit 6 */
        byte ETGC7      :1;           /* Bit 7 */
      } Bits;
    } COMP_ETGSTR;
    #define COMP_ETG _COMP_ET.Overlap_STR.COMP_ETGSTR.Byte

  } Overlap_STR;

  struct {
    word ETGC0          :1;           /* bit 0 */
    word ETGC1          :1;           /* bit 1 */
    word ETGC2          :1;           /* bit 2 */
    word ETGC3          :1;           /* bit 3 */
    word ETGC4          :1;           /* bit 4 */
    word ETGC5          :1;           /* bit 5 */
    word ETGC6          :1;           /* bit 6 */
    word ETGC7          :1;           /* bit 7 */
    word ETOC0          :1;           /* bit 8 */
    word ETOC1          :1;           /* bit 9 */
    word ETOC2          :1;           /* bit 10 */
    word ETOC3          :1;           /* bit 11 */
    word ETOC4          :1;           /* bit 12 */
    word ETOC5          :1;           /* bit 13 */
    word ETOC6          :1;           /* bit 14 */
    word ETOC7          :1;           /* bit 15 */
  } Bits;
} COMP_ETSTR;
extern volatile COMP_ETSTR _COMP_ET @(D2DREG_BASE + 0xD2);
#define COMP_ET _COMP_ET.Word


/*** TRIM_BG0 - Bandgap 0 Trim; 0xE0 *****************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TRIM_BG0H - Bandgap 0 Trim (hi); 0xE0 ***/
    union {
      byte Byte;
      struct {
        byte TCIBG1_0   :1;           /* Bit 0 */    
        byte TCIBG1_1   :1;           /* Bit 1 */
        byte TCIBG1_2   :1;           /* Bit 2 */
        byte TCIBG2_0   :1;           /* Bit 3 */
        byte TCIBG2_1   :1;           /* Bit 4 */
        byte TCIBG2_2   :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } TRIM_BG0HSTR;
    #define TRIM_BG0H _TRIM_BG0.Overlap_STR.TRIM_BG0HSTR.Byte

    /*** TRIM_BG0L - Bandgap 0 Trim (lo); 0xE1 ***/
    union {
      byte Byte;
      struct {
        byte IBG1_0     :1;           /* Bit 0 */
        byte IBG1_1     :1;           /* Bit 1 */
        byte IBG1_2     :1;           /* Bit 2 */
        byte IBG2_0     :1;           /* Bit 3 */
        byte IBG2_1     :1;           /* Bit 4 */
        byte IBG2_2     :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } TRIM_BG0LSTR;
    #define TRIM_BG0L _TRIM_BG0.Overlap_STR.TRIM_BG0LSTR.Byte

  } Overlap_STR;

  struct {
    word IBG1_0         :1;           /* bit 0 */
    word IBG1_1         :1;           /* bit 1 */
    word IBG1_2         :1;           /* bit 2 */
    word IBG2_0         :1;           /* bit 3 */
    word IBG2_1         :1;           /* bit 4 */
    word IBG2_2         :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word                :1;           /* bit 7 */
    word TCIBG1_0       :1;           /* bit 8 */
    word TCIBG1_1       :1;           /* bit 9 */
    word TCIBG1_2       :1;           /* bit 10 */
    word TCIBG2_0       :1;           /* bit 11 */
    word TCIBG2_1       :1;           /* bit 12 */
    word TCIBG2_2       :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} TRIM_BG0STR;
extern volatile TRIM_BG0STR _TRIM_BG0 @(D2DREG_BASE + 0xE0);
#define TRIM_BG0 _TRIM_BG0.Word


/*** TRIM_BG1 - Bandgap 1 Trim; 0xE2 *****************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TRIM_BG1H - Bandgap 1 Trim (hi); 0xE2 ***/
    union {
      byte Byte;
      struct {
        byte TCBG1_0    :1;           /* Bit 0 */    
        byte TCBG1_1    :1;           /* Bit 1 */
        byte TCBG1_2    :1;           /* Bit 2 */
        byte TCBG2_0    :1;           /* Bit 3 */
        byte TCBG2_1    :1;           /* Bit 4 */
        byte TCBG2_2    :1;           /* Bit 5 */
        byte DBG3       :1;           /* Bit 6 */
        byte UBG3       :1;           /* Bit 7 */
      } Bits;
    } TRIM_BG1HSTR;
    #define TRIM_BG1H _TRIM_BG1.Overlap_STR.TRIM_BG1HSTR.Byte

    /*** TRIM_BG1L - Bandgap 1 Trim (lo); 0xE3 ***/
    union {
      byte Byte;
      struct {
        byte SLPBG0     :1;           /* Bit 0 */
        byte SLPBG1     :1;           /* Bit 1 */
        byte SLPBG2     :1;           /* Bit 2 */
        byte            :1;           /* Bit 3 */
        byte            :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } TRIM_BG1LSTR;
    #define TRIM_BG1L _TRIM_BG1.Overlap_STR.TRIM_BG1LSTR.Byte

  } Overlap_STR;

  struct {
    word SLPBG0         :1;           /* bit 0 */
    word SLPBG1         :1;           /* bit 1 */
    word SLPBG2         :1;           /* bit 2 */
    word                :1;           /* bit 3 */
    word                :1;           /* bit 4 */
    word                :1;           /* bit 5 */
    word                :1;           /* bit 6 */
    word                :1;           /* bit 7 */
    word TCBG1_0        :1;           /* bit 8 */
    word TCBG1_1        :1;           /* bit 9 */
    word TCBG1_2        :1;           /* bit 10 */
    word TCBG2_0        :1;           /* bit 11 */
    word TCBG2_1        :1;           /* bit 12 */
    word TCBG2_2        :1;           /* bit 13 */
    word DBG3           :1;           /* bit 14 */
    word UBG3           :1;           /* bit 15 */
  } Bits;
} TRIM_BG1STR;
extern volatile TRIM_BG1STR _TRIM_BG1 @(D2DREG_BASE + 0xE2);
#define TRIM_BG1 _TRIM_BG1.Word


/*** TRIM_BG2 - Bandgap 2 Trim; 0xE4 *****************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TRIM_BG2H - Bandgap 2 Trim (hi); 0xE4 ***/
    union {
      byte Byte;
      struct {
        byte V1P2BG1_0  :1;           /* Bit 0 */    
        byte V1P2BG1_1  :1;           /* Bit 1 */
        byte V1P2BG1_2  :1;           /* Bit 2 */
        byte V1P2BG1_3  :1;           /* Bit 3 */
        byte V1P2BG2_0  :1;           /* Bit 4 */
        byte V1P2BG2_1  :1;           /* Bit 5 */
        byte V1P2BG2_2  :1;           /* Bit 6 */
        byte V1P2BG2_3  :1;           /* Bit 7 */
      } Bits;
    } TRIM_BG2HSTR;
    #define TRIM_BG2H _TRIM_BG2.Overlap_STR.TRIM_BG2HSTR.Byte

    /*** TRIM_BG2L - Bandgap 2 Trim (lo); 0xE5 ***/
    union {
      byte Byte;
      struct {
        byte V2P5BG1_0  :1;           /* Bit 0 */
        byte V2P5BG1_1  :1;           /* Bit 1 */
        byte V2P5BG1_2  :1;           /* Bit 2 */
        byte V2P5BG1_3  :1;           /* Bit 3 */
        byte V2P5BG2_0  :1;           /* Bit 4 */
        byte V2P5BG2_1  :1;           /* Bit 5 */
        byte V2P5BG2_2  :1;           /* Bit 6 */
        byte V2P5BG2_3  :1;           /* Bit 7 */
      } Bits;
    } TRIM_BG2LSTR;
    #define TRIM_BG2L _TRIM_BG2.Overlap_STR.TRIM_BG2LSTR.Byte

  } Overlap_STR;

  struct {
    word V2P5BG1_0      :1;           /* bit 0 */
    word V2P5BG1_1      :1;           /* bit 1 */
    word V2P5BG1_2      :1;           /* bit 2 */
    word V2P5BG1_3      :1;           /* bit 3 */
    word V2P5BG2_0      :1;           /* bit 4 */
    word V2P5BG2_1      :1;           /* bit 5 */
    word V2P5BG2_2      :1;           /* bit 6 */
    word V2P5BG2_3      :1;           /* bit 7 */
    word V1P2BG1_0      :1;           /* bit 8 */
    word V1P2BG1_1      :1;           /* bit 9 */
    word V1P2BG1_2      :1;           /* bit 10 */
    word V1P2BG1_3      :1;           /* bit 11 */
    word V1P2BG2_0      :1;           /* bit 12 */
    word V1P2BG2_1      :1;           /* bit 13 */
    word V1P2BG2_2      :1;           /* bit 14 */
    word V1P2BG2_3      :1;           /* bit 15 */
  } Bits;
} TRIM_BG2STR;
extern volatile TRIM_BG2STR _TRIM_BG2 @(D2DREG_BASE + 0xE4);
#define TRIM_BG2 _TRIM_BG2.Word


/*** _TRIM_LINLVT - LIN + LVT Trim; 0xE8 *************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TRIM_LIN - LIN Trim; 0xE6 ***/
    union {
      byte Byte;
      struct {
        byte LIN        :1;           /* bit 0 */  
        byte            :1;           /* bit 1 */
        byte            :1;           /* bit 2 */
        byte            :1;           /* bit 3 */
        byte            :1;           /* bit 4 */
        byte            :1;           /* bit 5 */
        byte            :1;           /* bit 6 */
        byte            :1;           /* bit 7 */
      } Bits;
    } TRIM_LINSTR;
    #define TRIM_LIN _TRIM_LINLVT.Overlap_STR.TRIM_LINSTR.Byte

    /*** TRIM_LVT - LVT Trim; 0xE7 ***/
    union {
      byte Byte;
      struct {
        byte LVT        :1;           /* bit 0 */
        byte            :1;           /* bit 1 */
        byte            :1;           /* bit 2 */
        byte            :1;           /* bit 3 */
        byte            :1;           /* bit 4 */
        byte            :1;           /* bit 5 */
        byte            :1;           /* bit 6 */
        byte            :1;           /* bit 7 */
      } Bits;
    } TRIM_LVTSTR;
    #define TRIM_LVT _TRIM_LINLVT.Overlap_STR.TRIM_LVTSTR.Byte

  } Overlap_STR;

  struct {
    word LPOSC0         :1;           /* bit 0 */
    word LPOSC1         :1;           /* bit 1 */
    word LPOSC2         :1;           /* bit 2 */
    word LPOSC3         :1;           /* bit 3 */
    word LPOSC4         :1;           /* bit 4 */
    word LPOSC5         :1;           /* bit 5 */
    word LPOSC6         :1;           /* bit 6 */
    word LPOSC7         :1;           /* bit 7 */
    word LPOSC8         :1;           /* bit 8 */
    word LPOSC9         :1;           /* bit 9 */
    word LPOSC10        :1;           /* bit 10 */
    word LPOSC11        :1;           /* bit 11 */
    word LPOSC12        :1;           /* bit 12 */
    word LPOSC13        :1;           /* bit 13 */
    word LPOSC14        :1;           /* bit 14 */
    word LPOSC15        :1;           /* bit 15 */
  } Bits;
} TRIM_LINLVTSTR;
extern volatile TRIM_LINLVTSTR _TRIM_LINLVT @(D2DREG_BASE + 0xE6);
#define TRIM_LINLVT _TRIM_LINLVT.Word


/*** TRIM_OSC - LP Oscillator Trim; 0xE8 *************************************/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TRIM_OSCH - LP Oscillator Trim (hi); 0xE8 ***/
    union {
      byte Byte;
      struct {
        byte LPOSC8     :1;           /* Bit 0 */    
        byte LPOSC9     :1;           /* Bit 1 */
        byte LPOSC10    :1;           /* Bit 2 */
        byte LPOSC11    :1;           /* Bit 3 */
        byte LPOSC12    :1;           /* Bit 4 */
        byte            :1;           /* Bit 5 */
        byte            :1;           /* Bit 6 */
        byte            :1;           /* Bit 7 */
      } Bits;
    } TRIM_OSCHSTR;
    #define TRIM_OSCH _TRIM_OSC.Overlap_STR.TRIM_OSCHSTR.Byte

    /*** TRIM_OSCL - LP Oscillator Trim (lo); 0xE9 ***/
    union {
      byte Byte;
      struct {
        byte LPOSC0     :1;           /* Bit 0 */
        byte LPOSC1     :1;           /* Bit 1 */
        byte LPOSC2     :1;           /* Bit 2 */
        byte LPOSC3     :1;           /* Bit 3 */
        byte LPOSC4     :1;           /* Bit 4 */
        byte LPOSC5     :1;           /* Bit 5 */
        byte LPOSC6     :1;           /* Bit 6 */
        byte LPOSC7     :1;           /* Bit 7 */
      } Bits;
    } TRIM_OSCLSTR;
    #define TRIM_OSCL _TRIM_OSC.Overlap_STR.TRIM_OSCLSTR.Byte

  } Overlap_STR;

  struct {
    word LPOSC0         :1;           /* bit 0 */
    word LPOSC1         :1;           /* bit 1 */
    word LPOSC2         :1;           /* bit 2 */
    word LPOSC3         :1;           /* bit 3 */
    word LPOSC4         :1;           /* bit 4 */
    word LPOSC5         :1;           /* bit 5 */
    word LPOSC6         :1;           /* bit 6 */
    word LPOSC7         :1;           /* bit 7 */
    word LPOSC8         :1;           /* bit 8 */
    word LPOSC9         :1;           /* bit 9 */
    word LPOSC10        :1;           /* bit 10 */
    word LPOSC11        :1;           /* bit 11 */
    word LPOSC12        :1;           /* bit 12 */
    word                :1;           /* bit 13 */
    word                :1;           /* bit 14 */
    word                :1;           /* bit 15 */
  } Bits;
} TRIM_OSCSTR;
extern volatile TRIM_OSCSTR _TRIM_OSC @(D2DREG_BASE + 0xE8);
#define TRIM_OSC _TRIM_OSC.Word

/*** DFT_ID - Chip mask id revision; 0xFA ************************************/
typedef union {
  byte Byte;
  struct {
    byte FMREV0         :1;           /* bit 0 */
    byte FMREV1         :1;           /* bit 1 */
    byte FMREV2         :1;           /* bit 2 */
    byte MMREV0         :1;           /* bit 3 */
    byte MMREV1         :1;           /* bit 4 */
    byte MMREV2         :1;           /* bit 5 */
    byte                :1;           /* bit 6 */
    byte                :1;           /* bit 7 */
  } Bits;
} DFT_IDSTR;
extern volatile DFT_IDSTR _DFT_ID @(D2DREG_BASE + 0xFA);
#define DFT_ID _DFT_ID.Byte


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/

#ifndef __V30COMPATIBLE__
#pragma OPTION DEL V30toV31Compatible
#endif

#endif
