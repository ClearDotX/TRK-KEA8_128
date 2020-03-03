/* Based on CPU DB MC9S08SG32_28, version 3.00.038 (RegistersPrg V2.32) */
/*
** ###################################################################
**     Filename  : mc9s08sg32.h
**     Processor : MC9S08SG32CTL
**     FileFormat: V2.32
**     DataSheet : MC9S08SG32 Rev. 7 10/2009
**     Compiler  : CodeWarrior compiler
**     Date/Time : 5.10.2010, 13:57
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**               - none
**
**     File-Format-Revisions:
**      - 06.08.2007, V2.19 :
**               - CPUDB revisions generated ahead of the file-format revisions.
**      - 11.09.2007, V2.20 :
**               - Added comment about initialization of unbonded pins.
**      - 02.01.2008, V2.21 :
**               - Changes have not affected this file (because they are related to another family)
**      - 13.02.2008, V2.22 :
**               - Changes have not affected this file (because they are related to another family)
**      - 20.02.2008, V2.23 :
**               - Changes have not affected this file (because they are related to another family)
**      - 03.07.2008, V2.24 :
**               - Added support for bits with name starting with number (like "1HZ")
**      - 28.11.2008, V2.25 :
**               - StandBy RAM array declaration for ANSI-C added
**      - 1.12.2008, V2.26 :
**               - Duplication of bit (or bit-group) name with register name is not marked as a problem, if register is internal only and it is not displayed in I/O map.
**      - 17.3.2009, V2.27 :
**               - Merged bit-group is not generated, if the name matches with another bit name in the register
**      - 6.4.2009, V2.28 :
**               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
**      - 3.8.2009, V2.29 :
**               - If there is just one bits group matching register name, single bits are not generated
**      - 10.9.2009, V2.30 :
**               - Fixed generation of registers arrays.
**      - 15.10.2009, V2.31 :
**               - HCS08 family: Bits and bit-groups are published for 16-bit registers: 8-bit overlay registers are required.
**      - 18.05.2010, V2.32 :
**               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user’s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC9S08SG32_H
#define _MC9S08SG32_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

/* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(SRS = 0x55U, SRS = 0xAAU)
#endif
#endif /* __RESET_WATCHDOG */

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/**************** interrupt vector numbers ****************/
#define VectorNumber_VReserved31        31U
#define VectorNumber_Vacmp              30U
#define VectorNumber_VReserved29        29U
#define VectorNumber_VReserved28        28U
#define VectorNumber_VReserved27        27U
#define VectorNumber_Vmtim              26U
#define VectorNumber_Vrtc               25U
#define VectorNumber_Viic               24U
#define VectorNumber_Vadc               23U
#define VectorNumber_VReserved22        22U
#define VectorNumber_Vportb             21U
#define VectorNumber_Vporta             20U
#define VectorNumber_VReserved19        19U
#define VectorNumber_Vscitx             18U
#define VectorNumber_Vscirx             17U
#define VectorNumber_Vscierr            16U
#define VectorNumber_Vspi               15U
#define VectorNumber_Vtpm2ovf           14U
#define VectorNumber_Vtpm2ch1           13U
#define VectorNumber_Vtpm2ch0           12U
#define VectorNumber_Vtpm1ovf           11U
#define VectorNumber_VReserved10        10U
#define VectorNumber_VReserved9         9U
#define VectorNumber_VReserved8         8U
#define VectorNumber_VReserved7         7U
#define VectorNumber_Vtpm1ch1           6U
#define VectorNumber_Vtpm1ch0           5U
#define VectorNumber_VReserved4         4U
#define VectorNumber_Vlvd               3U
#define VectorNumber_VReserved2         2U
#define VectorNumber_Vswi               1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define VReserved31                     0xFFC0U
#define Vacmp                           0xFFC2U
#define VReserved29                     0xFFC4U
#define VReserved28                     0xFFC6U
#define VReserved27                     0xFFC8U
#define Vmtim                           0xFFCAU
#define Vrtc                            0xFFCCU
#define Viic                            0xFFCEU
#define Vadc                            0xFFD0U
#define VReserved22                     0xFFD2U
#define Vportb                          0xFFD4U
#define Vporta                          0xFFD6U
#define VReserved19                     0xFFD8U
#define Vscitx                          0xFFDAU
#define Vscirx                          0xFFDCU
#define Vscierr                         0xFFDEU
#define Vspi                            0xFFE0U
#define Vtpm2ovf                        0xFFE2U
#define Vtpm2ch1                        0xFFE4U
#define Vtpm2ch0                        0xFFE6U
#define Vtpm1ovf                        0xFFE8U
#define VReserved10                     0xFFEAU
#define VReserved9                      0xFFECU
#define VReserved8                      0xFFEEU
#define VReserved7                      0xFFF0U
#define Vtpm1ch1                        0xFFF2U
#define Vtpm1ch0                        0xFFF4U
#define VReserved4                      0xFFF6U
#define Vlvd                            0xFFF8U
#define VReserved2                      0xFFFAU
#define Vswi                            0xFFFCU
#define Vreset                          0xFFFEU

/**************** registers I/O map ****************/

/*** PTAD - Port A Data Register; 0x00000000 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* Port A Data Register Bit 0 */
    byte PTAD1       :1;                                       /* Port A Data Register Bit 1 */
    byte PTAD2       :1;                                       /* Port A Data Register Bit 2 */
    byte PTAD3       :1;                                       /* Port A Data Register Bit 3 */
    byte             :1; 
    byte             :1; 
    byte PTAD6       :1;                                       /* Port A Data Register Bit 6 */
    byte PTAD7       :1;                                       /* Port A Data Register Bit 7 */
  } Bits;
  struct {
    byte grpPTAD :4;
    byte         :1;
    byte         :1;
    byte grpPTAD_6 :2;
  } MergedBits;
} PTADSTR;
extern volatile PTADSTR _PTAD @0x00000000;
#define PTAD                            _PTAD.Byte
#define PTAD_PTAD0                      _PTAD.Bits.PTAD0
#define PTAD_PTAD1                      _PTAD.Bits.PTAD1
#define PTAD_PTAD2                      _PTAD.Bits.PTAD2
#define PTAD_PTAD3                      _PTAD.Bits.PTAD3
#define PTAD_PTAD6                      _PTAD.Bits.PTAD6
#define PTAD_PTAD7                      _PTAD.Bits.PTAD7
#define PTAD_PTAD                       _PTAD.MergedBits.grpPTAD
#define PTAD_PTAD_6                     _PTAD.MergedBits.grpPTAD_6

#define PTAD_PTAD0_MASK                 1U
#define PTAD_PTAD1_MASK                 2U
#define PTAD_PTAD2_MASK                 4U
#define PTAD_PTAD3_MASK                 8U
#define PTAD_PTAD6_MASK                 64U
#define PTAD_PTAD7_MASK                 128U
#define PTAD_PTAD_MASK                  15U
#define PTAD_PTAD_BITNUM                0U
#define PTAD_PTAD_6_MASK                192U
#define PTAD_PTAD_6_BITNUM              6U


/*** PTADD - Port A Data Direction Register; 0x00000001 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADD0      :1;                                       /* Data Direction for Port A Bit 0 */
    byte PTADD1      :1;                                       /* Data Direction for Port A Bit 1 */
    byte PTADD2      :1;                                       /* Data Direction for Port A Bit 2 */
    byte PTADD3      :1;                                       /* Data Direction for Port A Bit 3 */
    byte             :1; 
    byte             :1; 
    byte PTADD6      :1;                                       /* Data Direction for Port A Bit 6 */
    byte PTADD7      :1;                                       /* Data Direction for Port A Bit 7 */
  } Bits;
  struct {
    byte grpPTADD :4;
    byte         :1;
    byte         :1;
    byte grpPTADD_6 :2;
  } MergedBits;
} PTADDSTR;
extern volatile PTADDSTR _PTADD @0x00000001;
#define PTADD                           _PTADD.Byte
#define PTADD_PTADD0                    _PTADD.Bits.PTADD0
#define PTADD_PTADD1                    _PTADD.Bits.PTADD1
#define PTADD_PTADD2                    _PTADD.Bits.PTADD2
#define PTADD_PTADD3                    _PTADD.Bits.PTADD3
#define PTADD_PTADD6                    _PTADD.Bits.PTADD6
#define PTADD_PTADD7                    _PTADD.Bits.PTADD7
#define PTADD_PTADD                     _PTADD.MergedBits.grpPTADD
#define PTADD_PTADD_6                   _PTADD.MergedBits.grpPTADD_6

#define PTADD_PTADD0_MASK               1U
#define PTADD_PTADD1_MASK               2U
#define PTADD_PTADD2_MASK               4U
#define PTADD_PTADD3_MASK               8U
#define PTADD_PTADD6_MASK               64U
#define PTADD_PTADD7_MASK               128U
#define PTADD_PTADD_MASK                15U
#define PTADD_PTADD_BITNUM              0U
#define PTADD_PTADD_6_MASK              192U
#define PTADD_PTADD_6_BITNUM            6U


/*** PTBD - Port B Data Register; 0x00000002 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBD0       :1;                                       /* Port B Data Register Bit 0 */
    byte PTBD1       :1;                                       /* Port B Data Register Bit 1 */
    byte PTBD2       :1;                                       /* Port B Data Register Bit 2 */
    byte PTBD3       :1;                                       /* Port B Data Register Bit 3 */
    byte PTBD4       :1;                                       /* Port B Data Register Bit 4 */
    byte PTBD5       :1;                                       /* Port B Data Register Bit 5 */
    byte PTBD6       :1;                                       /* Port B Data Register Bit 6 */
    byte PTBD7       :1;                                       /* Port B Data Register Bit 7 */
  } Bits;
} PTBDSTR;
extern volatile PTBDSTR _PTBD @0x00000002;
#define PTBD                            _PTBD.Byte
#define PTBD_PTBD0                      _PTBD.Bits.PTBD0
#define PTBD_PTBD1                      _PTBD.Bits.PTBD1
#define PTBD_PTBD2                      _PTBD.Bits.PTBD2
#define PTBD_PTBD3                      _PTBD.Bits.PTBD3
#define PTBD_PTBD4                      _PTBD.Bits.PTBD4
#define PTBD_PTBD5                      _PTBD.Bits.PTBD5
#define PTBD_PTBD6                      _PTBD.Bits.PTBD6
#define PTBD_PTBD7                      _PTBD.Bits.PTBD7

#define PTBD_PTBD0_MASK                 1U
#define PTBD_PTBD1_MASK                 2U
#define PTBD_PTBD2_MASK                 4U
#define PTBD_PTBD3_MASK                 8U
#define PTBD_PTBD4_MASK                 16U
#define PTBD_PTBD5_MASK                 32U
#define PTBD_PTBD6_MASK                 64U
#define PTBD_PTBD7_MASK                 128U


/*** PTBDD - Port B Data Direction Register; 0x00000003 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDD0      :1;                                       /* Data Direction for Port B Bit 0 */
    byte PTBDD1      :1;                                       /* Data Direction for Port B Bit 1 */
    byte PTBDD2      :1;                                       /* Data Direction for Port B Bit 2 */
    byte PTBDD3      :1;                                       /* Data Direction for Port B Bit 3 */
    byte PTBDD4      :1;                                       /* Data Direction for Port B Bit 4 */
    byte PTBDD5      :1;                                       /* Data Direction for Port B Bit 5 */
    byte PTBDD6      :1;                                       /* Data Direction for Port B Bit 6 */
    byte PTBDD7      :1;                                       /* Data Direction for Port B Bit 7 */
  } Bits;
} PTBDDSTR;
extern volatile PTBDDSTR _PTBDD @0x00000003;
#define PTBDD                           _PTBDD.Byte
#define PTBDD_PTBDD0                    _PTBDD.Bits.PTBDD0
#define PTBDD_PTBDD1                    _PTBDD.Bits.PTBDD1
#define PTBDD_PTBDD2                    _PTBDD.Bits.PTBDD2
#define PTBDD_PTBDD3                    _PTBDD.Bits.PTBDD3
#define PTBDD_PTBDD4                    _PTBDD.Bits.PTBDD4
#define PTBDD_PTBDD5                    _PTBDD.Bits.PTBDD5
#define PTBDD_PTBDD6                    _PTBDD.Bits.PTBDD6
#define PTBDD_PTBDD7                    _PTBDD.Bits.PTBDD7

#define PTBDD_PTBDD0_MASK               1U
#define PTBDD_PTBDD1_MASK               2U
#define PTBDD_PTBDD2_MASK               4U
#define PTBDD_PTBDD3_MASK               8U
#define PTBDD_PTBDD4_MASK               16U
#define PTBDD_PTBDD5_MASK               32U
#define PTBDD_PTBDD6_MASK               64U
#define PTBDD_PTBDD7_MASK               128U


/*** PTCD - Port C Data Register; 0x00000004 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCD0       :1;                                       /* Port C Data Register Bit 0 */
    byte PTCD1       :1;                                       /* Port C Data Register Bit 1 */
    byte PTCD2       :1;                                       /* Port C Data Register Bit 2 */
    byte PTCD3       :1;                                       /* Port C Data Register Bit 3 */
    byte PTCD4       :1;                                       /* Port C Data Register Bit 4 */
    byte PTCD5       :1;                                       /* Port C Data Register Bit 5 */
    byte PTCD6       :1;                                       /* Port C Data Register Bit 6 */
    byte PTCD7       :1;                                       /* Port C Data Register Bit 7 */
  } Bits;
} PTCDSTR;
extern volatile PTCDSTR _PTCD @0x00000004;
#define PTCD                            _PTCD.Byte
#define PTCD_PTCD0                      _PTCD.Bits.PTCD0
#define PTCD_PTCD1                      _PTCD.Bits.PTCD1
#define PTCD_PTCD2                      _PTCD.Bits.PTCD2
#define PTCD_PTCD3                      _PTCD.Bits.PTCD3
#define PTCD_PTCD4                      _PTCD.Bits.PTCD4
#define PTCD_PTCD5                      _PTCD.Bits.PTCD5
#define PTCD_PTCD6                      _PTCD.Bits.PTCD6
#define PTCD_PTCD7                      _PTCD.Bits.PTCD7

#define PTCD_PTCD0_MASK                 1U
#define PTCD_PTCD1_MASK                 2U
#define PTCD_PTCD2_MASK                 4U
#define PTCD_PTCD3_MASK                 8U
#define PTCD_PTCD4_MASK                 16U
#define PTCD_PTCD5_MASK                 32U
#define PTCD_PTCD6_MASK                 64U
#define PTCD_PTCD7_MASK                 128U


/*** PTCDD - Port C Data Direction Register; 0x00000005 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDD0      :1;                                       /* Data Direction for Port C Bit 0 */
    byte PTCDD1      :1;                                       /* Data Direction for Port C Bit 1 */
    byte PTCDD2      :1;                                       /* Data Direction for Port C Bit 2 */
    byte PTCDD3      :1;                                       /* Data Direction for Port C Bit 3 */
    byte PTCDD4      :1;                                       /* Data Direction for Port C Bit 4 */
    byte PTCDD5      :1;                                       /* Data Direction for Port C Bit 5 */
    byte PTCDD6      :1;                                       /* Data Direction for Port C Bit 6 */
    byte PTCDD7      :1;                                       /* Data Direction for Port C Bit 7 */
  } Bits;
} PTCDDSTR;
extern volatile PTCDDSTR _PTCDD @0x00000005;
#define PTCDD                           _PTCDD.Byte
#define PTCDD_PTCDD0                    _PTCDD.Bits.PTCDD0
#define PTCDD_PTCDD1                    _PTCDD.Bits.PTCDD1
#define PTCDD_PTCDD2                    _PTCDD.Bits.PTCDD2
#define PTCDD_PTCDD3                    _PTCDD.Bits.PTCDD3
#define PTCDD_PTCDD4                    _PTCDD.Bits.PTCDD4
#define PTCDD_PTCDD5                    _PTCDD.Bits.PTCDD5
#define PTCDD_PTCDD6                    _PTCDD.Bits.PTCDD6
#define PTCDD_PTCDD7                    _PTCDD.Bits.PTCDD7

#define PTCDD_PTCDD0_MASK               1U
#define PTCDD_PTCDD1_MASK               2U
#define PTCDD_PTCDD2_MASK               4U
#define PTCDD_PTCDD3_MASK               8U
#define PTCDD_PTCDD4_MASK               16U
#define PTCDD_PTCDD5_MASK               32U
#define PTCDD_PTCDD6_MASK               64U
#define PTCDD_PTCDD7_MASK               128U


/*** ACMPSC - ACMP Status and Control Register; 0x0000000E ***/
typedef union {
  byte Byte;
  struct {
    byte ACMOD0      :1;                                       /* Analog Comparator Mode Bit 0 */
    byte ACMOD1      :1;                                       /* Analog Comparator Mode Bit 1 */
    byte ACOPE       :1;                                       /* Analog Comparator Output Pin Enable */
    byte ACO         :1;                                       /* Analog Comparator Output */
    byte ACIE        :1;                                       /* Analog Comparator Interrupt Enable */
    byte ACF         :1;                                       /* Analog Comparator Flag */
    byte ACBGS       :1;                                       /* Analog Comparator Bandgap Select */
    byte ACME        :1;                                       /* Analog Comparator Module Enable */
  } Bits;
  struct {
    byte grpACMOD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ACMPSCSTR;
extern volatile ACMPSCSTR _ACMPSC @0x0000000E;
#define ACMPSC                          _ACMPSC.Byte
#define ACMPSC_ACMOD0                   _ACMPSC.Bits.ACMOD0
#define ACMPSC_ACMOD1                   _ACMPSC.Bits.ACMOD1
#define ACMPSC_ACOPE                    _ACMPSC.Bits.ACOPE
#define ACMPSC_ACO                      _ACMPSC.Bits.ACO
#define ACMPSC_ACIE                     _ACMPSC.Bits.ACIE
#define ACMPSC_ACF                      _ACMPSC.Bits.ACF
#define ACMPSC_ACBGS                    _ACMPSC.Bits.ACBGS
#define ACMPSC_ACME                     _ACMPSC.Bits.ACME
#define ACMPSC_ACMOD                    _ACMPSC.MergedBits.grpACMOD

#define ACMPSC_ACMOD0_MASK              1U
#define ACMPSC_ACMOD1_MASK              2U
#define ACMPSC_ACOPE_MASK               4U
#define ACMPSC_ACO_MASK                 8U
#define ACMPSC_ACIE_MASK                16U
#define ACMPSC_ACF_MASK                 32U
#define ACMPSC_ACBGS_MASK               64U
#define ACMPSC_ACME_MASK                128U
#define ACMPSC_ACMOD_MASK               3U
#define ACMPSC_ACMOD_BITNUM             0U


/*** ADCSC1 - Status and Control Register 1; 0x00000010 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCH0       :1;                                       /* Input Channel Select Bit 0 */
    byte ADCH1       :1;                                       /* Input Channel Select Bit 1 */
    byte ADCH2       :1;                                       /* Input Channel Select Bit 2 */
    byte ADCH3       :1;                                       /* Input Channel Select Bit 3 */
    byte ADCH4       :1;                                       /* Input Channel Select Bit 4 */
    byte ADCO        :1;                                       /* Continuous Conversion Enable - ADCO is used to enable continuous conversions */
    byte AIEN        :1;                                       /* Interrupt Enable - AIEN is used to enable conversion complete interrupts. When COCO becomes set while AIEN is high, an interrupt is asserted */
    byte COCO        :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCH :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1STR;
extern volatile ADCSC1STR _ADCSC1 @0x00000010;
#define ADCSC1                          _ADCSC1.Byte
#define ADCSC1_ADCH0                    _ADCSC1.Bits.ADCH0
#define ADCSC1_ADCH1                    _ADCSC1.Bits.ADCH1
#define ADCSC1_ADCH2                    _ADCSC1.Bits.ADCH2
#define ADCSC1_ADCH3                    _ADCSC1.Bits.ADCH3
#define ADCSC1_ADCH4                    _ADCSC1.Bits.ADCH4
#define ADCSC1_ADCO                     _ADCSC1.Bits.ADCO
#define ADCSC1_AIEN                     _ADCSC1.Bits.AIEN
#define ADCSC1_COCO                     _ADCSC1.Bits.COCO
#define ADCSC1_ADCH                     _ADCSC1.MergedBits.grpADCH

#define ADCSC1_ADCH0_MASK               1U
#define ADCSC1_ADCH1_MASK               2U
#define ADCSC1_ADCH2_MASK               4U
#define ADCSC1_ADCH3_MASK               8U
#define ADCSC1_ADCH4_MASK               16U
#define ADCSC1_ADCO_MASK                32U
#define ADCSC1_AIEN_MASK                64U
#define ADCSC1_COCO_MASK                128U
#define ADCSC1_ADCH_MASK                31U
#define ADCSC1_ADCH_BITNUM              0U


/*** ADCSC2 - Status and Control Register 2; 0x00000011 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ACFGT       :1;                                       /* Compare Function Greater Than Enable */
    byte ACFE        :1;                                       /* Compare Function Enable - ACFE is used to enable the compare function */
    byte ADTRG       :1;                                       /* Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion */
    byte ADACT       :1;                                       /* Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted */
  } Bits;
} ADCSC2STR;
extern volatile ADCSC2STR _ADCSC2 @0x00000011;
#define ADCSC2                          _ADCSC2.Byte
#define ADCSC2_ACFGT                    _ADCSC2.Bits.ACFGT
#define ADCSC2_ACFE                     _ADCSC2.Bits.ACFE
#define ADCSC2_ADTRG                    _ADCSC2.Bits.ADTRG
#define ADCSC2_ADACT                    _ADCSC2.Bits.ADACT

#define ADCSC2_ACFGT_MASK               16U
#define ADCSC2_ACFE_MASK                32U
#define ADCSC2_ADTRG_MASK               64U
#define ADCSC2_ADACT_MASK               128U


/*** ADCR - Data Result Register; 0x00000012 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRH - Data Result High Register; 0x00000012 ***/
    union {
      byte Byte;
      struct {
        byte ADR8        :1;                                       /* ADC Result Data Bit 8 */
        byte ADR9        :1;                                       /* ADC Result Data Bit 9 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpADR_8 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCRHSTR;
    #define ADCRH                       _ADCR.Overlap_STR.ADCRHSTR.Byte
    #define ADCRH_ADR8                  _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR8
    #define ADCRH_ADR9                  _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR9
    #define ADCRH_ADR_8                 _ADCR.Overlap_STR.ADCRHSTR.MergedBits.grpADR_8
    #define ADCRH_ADR                   ADCRH_ADR_8
    
    #define ADCRH_ADR8_MASK             1U
    #define ADCRH_ADR9_MASK             2U
    #define ADCRH_ADR_8_MASK            3U
    #define ADCRH_ADR_8_BITNUM          0U
    

    /*** ADCRL - Data Result Low Register; 0x00000013 ***/
    union {
      byte Byte;
      struct {
        byte ADR0        :1;                                       /* ADC Result Data Bit 0 */
        byte ADR1        :1;                                       /* ADC Result Data Bit 1 */
        byte ADR2        :1;                                       /* ADC Result Data Bit 2 */
        byte ADR3        :1;                                       /* ADC Result Data Bit 3 */
        byte ADR4        :1;                                       /* ADC Result Data Bit 4 */
        byte ADR5        :1;                                       /* ADC Result Data Bit 5 */
        byte ADR6        :1;                                       /* ADC Result Data Bit 6 */
        byte ADR7        :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLSTR;
    #define ADCRL                       _ADCR.Overlap_STR.ADCRLSTR.Byte
    #define ADCRL_ADR0                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR0
    #define ADCRL_ADR1                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR1
    #define ADCRL_ADR2                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR2
    #define ADCRL_ADR3                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR3
    #define ADCRL_ADR4                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR4
    #define ADCRL_ADR5                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR5
    #define ADCRL_ADR6                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR6
    #define ADCRL_ADR7                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR7
    
    #define ADCRL_ADR0_MASK             1U
    #define ADCRL_ADR1_MASK             2U
    #define ADCRL_ADR2_MASK             4U
    #define ADCRL_ADR3_MASK             8U
    #define ADCRL_ADR4_MASK             16U
    #define ADCRL_ADR5_MASK             32U
    #define ADCRL_ADR6_MASK             64U
    #define ADCRL_ADR7_MASK             128U
    
  } Overlap_STR;

} ADCRSTR;
extern volatile ADCRSTR _ADCR @0x00000012;
#define ADCR                            _ADCR.Word


/*** ADCCV - Compare Value Register; 0x00000014 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCVH - Compare Value High Register; 0x00000014 ***/
    union {
      byte Byte;
      struct {
        byte ADCV8       :1;                                       /* Compare Function Value 8 */
        byte ADCV9       :1;                                       /* Compare Function Value 9 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpADCV_8 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCCVHSTR;
    #define ADCCVH                      _ADCCV.Overlap_STR.ADCCVHSTR.Byte
    #define ADCCVH_ADCV8                _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV8
    #define ADCCVH_ADCV9                _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV9
    #define ADCCVH_ADCV_8               _ADCCV.Overlap_STR.ADCCVHSTR.MergedBits.grpADCV_8
    #define ADCCVH_ADCV                 ADCCVH_ADCV_8
    
    #define ADCCVH_ADCV8_MASK           1U
    #define ADCCVH_ADCV9_MASK           2U
    #define ADCCVH_ADCV_8_MASK          3U
    #define ADCCVH_ADCV_8_BITNUM        0U
    

    /*** ADCCVL - Compare Value Low Register; 0x00000015 ***/
    union {
      byte Byte;
      struct {
        byte ADCV0       :1;                                       /* Compare Function Value 0 */
        byte ADCV1       :1;                                       /* Compare Function Value 1 */
        byte ADCV2       :1;                                       /* Compare Function Value 2 */
        byte ADCV3       :1;                                       /* Compare Function Value 3 */
        byte ADCV4       :1;                                       /* Compare Function Value 4 */
        byte ADCV5       :1;                                       /* Compare Function Value 5 */
        byte ADCV6       :1;                                       /* Compare Function Value 6 */
        byte ADCV7       :1;                                       /* Compare Function Value 7 */
      } Bits;
    } ADCCVLSTR;
    #define ADCCVL                      _ADCCV.Overlap_STR.ADCCVLSTR.Byte
    #define ADCCVL_ADCV0                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV0
    #define ADCCVL_ADCV1                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV1
    #define ADCCVL_ADCV2                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV2
    #define ADCCVL_ADCV3                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV3
    #define ADCCVL_ADCV4                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV4
    #define ADCCVL_ADCV5                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV5
    #define ADCCVL_ADCV6                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV6
    #define ADCCVL_ADCV7                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV7
    
    #define ADCCVL_ADCV0_MASK           1U
    #define ADCCVL_ADCV1_MASK           2U
    #define ADCCVL_ADCV2_MASK           4U
    #define ADCCVL_ADCV3_MASK           8U
    #define ADCCVL_ADCV4_MASK           16U
    #define ADCCVL_ADCV5_MASK           32U
    #define ADCCVL_ADCV6_MASK           64U
    #define ADCCVL_ADCV7_MASK           128U
    
  } Overlap_STR;

} ADCCVSTR;
extern volatile ADCCVSTR _ADCCV @0x00000014;
#define ADCCV                           _ADCCV.Word


/*** ADCCFG - Configuration Register; 0x00000016 ***/
typedef union {
  byte Byte;
  struct {
    byte ADICLK0     :1;                                       /* Input Clock Select Bit 0 */
    byte ADICLK1     :1;                                       /* Input Clock Select Bit 1 */
    byte MODE0       :1;                                       /* Conversion Mode Selection Bit 0 */
    byte MODE1       :1;                                       /* Conversion Mode Selection Bit 1 */
    byte ADLSMP      :1;                                       /* Long Sample Time Configuration */
    byte ADIV0       :1;                                       /* Clock Divide Select Bit 0 */
    byte ADIV1       :1;                                       /* Clock Divide Select Bit 1 */
    byte ADLPC       :1;                                       /* Low Power Configuration */
  } Bits;
  struct {
    byte grpADICLK :2;
    byte grpMODE :2;
    byte         :1;
    byte grpADIV :2;
    byte         :1;
  } MergedBits;
} ADCCFGSTR;
extern volatile ADCCFGSTR _ADCCFG @0x00000016;
#define ADCCFG                          _ADCCFG.Byte
#define ADCCFG_ADICLK0                  _ADCCFG.Bits.ADICLK0
#define ADCCFG_ADICLK1                  _ADCCFG.Bits.ADICLK1
#define ADCCFG_MODE0                    _ADCCFG.Bits.MODE0
#define ADCCFG_MODE1                    _ADCCFG.Bits.MODE1
#define ADCCFG_ADLSMP                   _ADCCFG.Bits.ADLSMP
#define ADCCFG_ADIV0                    _ADCCFG.Bits.ADIV0
#define ADCCFG_ADIV1                    _ADCCFG.Bits.ADIV1
#define ADCCFG_ADLPC                    _ADCCFG.Bits.ADLPC
#define ADCCFG_ADICLK                   _ADCCFG.MergedBits.grpADICLK
#define ADCCFG_MODE                     _ADCCFG.MergedBits.grpMODE
#define ADCCFG_ADIV                     _ADCCFG.MergedBits.grpADIV

#define ADCCFG_ADICLK0_MASK             1U
#define ADCCFG_ADICLK1_MASK             2U
#define ADCCFG_MODE0_MASK               4U
#define ADCCFG_MODE1_MASK               8U
#define ADCCFG_ADLSMP_MASK              16U
#define ADCCFG_ADIV0_MASK               32U
#define ADCCFG_ADIV1_MASK               64U
#define ADCCFG_ADLPC_MASK               128U
#define ADCCFG_ADICLK_MASK              3U
#define ADCCFG_ADICLK_BITNUM            0U
#define ADCCFG_MODE_MASK                12U
#define ADCCFG_MODE_BITNUM              2U
#define ADCCFG_ADIV_MASK                96U
#define ADCCFG_ADIV_BITNUM              5U


/*** APCTL1 - Pin Control 1 Register; 0x00000017 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC0       :1;                                       /* ADC Pin Control 0 - ADPC0 is used to control the pin associated with channel AD0 */
    byte ADPC1       :1;                                       /* ADC Pin Control 1 - ADPC1 is used to control the pin associated with channel AD1 */
    byte ADPC2       :1;                                       /* ADC Pin Control 2 - ADPC2 is used to control the pin associated with channel AD2 */
    byte ADPC3       :1;                                       /* ADC Pin Control 3 - ADPC3 is used to control the pin associated with channel AD3 */
    byte ADPC4       :1;                                       /* ADC Pin Control 4 - ADPC4 is used to control the pin associated with channel AD4 */
    byte ADPC5       :1;                                       /* ADC Pin Control 5 - ADPC5 is used to control the pin associated with channel AD5 */
    byte ADPC6       :1;                                       /* ADC Pin Control 6 - ADPC6 is used to control the pin associated with channel AD6 */
    byte ADPC7       :1;                                       /* ADC Pin Control 7 - ADPC7 is used to control the pin associated with channel AD7 */
  } Bits;
} APCTL1STR;
extern volatile APCTL1STR _APCTL1 @0x00000017;
#define APCTL1                          _APCTL1.Byte
#define APCTL1_ADPC0                    _APCTL1.Bits.ADPC0
#define APCTL1_ADPC1                    _APCTL1.Bits.ADPC1
#define APCTL1_ADPC2                    _APCTL1.Bits.ADPC2
#define APCTL1_ADPC3                    _APCTL1.Bits.ADPC3
#define APCTL1_ADPC4                    _APCTL1.Bits.ADPC4
#define APCTL1_ADPC5                    _APCTL1.Bits.ADPC5
#define APCTL1_ADPC6                    _APCTL1.Bits.ADPC6
#define APCTL1_ADPC7                    _APCTL1.Bits.ADPC7

#define APCTL1_ADPC0_MASK               1U
#define APCTL1_ADPC1_MASK               2U
#define APCTL1_ADPC2_MASK               4U
#define APCTL1_ADPC3_MASK               8U
#define APCTL1_ADPC4_MASK               16U
#define APCTL1_ADPC5_MASK               32U
#define APCTL1_ADPC6_MASK               64U
#define APCTL1_ADPC7_MASK               128U


/*** APCTL2 - Pin Control 2 Register; 0x00000018 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC8       :1;                                       /* ADC Pin Control 8 - ADPC8 is used to control the pin associated with channel AD8 */
    byte ADPC9       :1;                                       /* ADC Pin Control 9 - ADPC9 is used to control the pin associated with channel AD9 */
    byte ADPC10      :1;                                       /* ADC Pin Control 10 - ADPC10 is used to control the pin associated with channel AD10 */
    byte ADPC11      :1;                                       /* ADC Pin Control 11 - ADPC11 is used to control the pin associated with channel AD11 */
    byte ADPC12      :1;                                       /* ADC Pin Control 12 - ADPC12 is used to control the pin associated with channel AD12 */
    byte ADPC13      :1;                                       /* ADC Pin Control 13 - ADPC13 is used to control the pin associated with channel AD13 */
    byte ADPC14      :1;                                       /* ADC Pin Control 14 - ADPC14 is used to control the pin associated with channel AD14 */
    byte ADPC15      :1;                                       /* ADC Pin Control 15 - ADPC15 is used to control the pin associated with channel AD15 */
  } Bits;
} APCTL2STR;
extern volatile APCTL2STR _APCTL2 @0x00000018;
#define APCTL2                          _APCTL2.Byte
#define APCTL2_ADPC8                    _APCTL2.Bits.ADPC8
#define APCTL2_ADPC9                    _APCTL2.Bits.ADPC9
#define APCTL2_ADPC10                   _APCTL2.Bits.ADPC10
#define APCTL2_ADPC11                   _APCTL2.Bits.ADPC11
#define APCTL2_ADPC12                   _APCTL2.Bits.ADPC12
#define APCTL2_ADPC13                   _APCTL2.Bits.ADPC13
#define APCTL2_ADPC14                   _APCTL2.Bits.ADPC14
#define APCTL2_ADPC15                   _APCTL2.Bits.ADPC15

#define APCTL2_ADPC8_MASK               1U
#define APCTL2_ADPC9_MASK               2U
#define APCTL2_ADPC10_MASK              4U
#define APCTL2_ADPC11_MASK              8U
#define APCTL2_ADPC12_MASK              16U
#define APCTL2_ADPC13_MASK              32U
#define APCTL2_ADPC14_MASK              64U
#define APCTL2_ADPC15_MASK              128U


/*** MTIMSC - MTIM Clock Configuration Register; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TSTP        :1;                                       /* MTIM Counter Stop */
    byte TRST        :1;                                       /* MTIM Counter Reset */
    byte TOIE        :1;                                       /* MTIM Overflow Interrupt Enable */
    byte TOF         :1;                                       /* MTIM Overflow Flag */
  } Bits;
} MTIMSCSTR;
extern volatile MTIMSCSTR _MTIMSC @0x0000001C;
#define MTIMSC                          _MTIMSC.Byte
#define MTIMSC_TSTP                     _MTIMSC.Bits.TSTP
#define MTIMSC_TRST                     _MTIMSC.Bits.TRST
#define MTIMSC_TOIE                     _MTIMSC.Bits.TOIE
#define MTIMSC_TOF                      _MTIMSC.Bits.TOF

#define MTIMSC_TSTP_MASK                16U
#define MTIMSC_TRST_MASK                32U
#define MTIMSC_TOIE_MASK                64U
#define MTIMSC_TOF_MASK                 128U


/*** MTIMCLK - MTIM Clock Configuration Register; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Clock source Prescaler Bit 0 */
    byte PS1         :1;                                       /* Clock source Prescaler Bit 1 */
    byte PS2         :1;                                       /* Clock source Prescaler Bit 2 */
    byte PS3         :1;                                       /* Clock source Prescaler Bit 3 */
    byte CLKS0       :1;                                       /* Clock source Select Bit 0 */
    byte CLKS1       :1;                                       /* Clock source Select Bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPS   :4;
    byte grpCLKS :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} MTIMCLKSTR;
extern volatile MTIMCLKSTR _MTIMCLK @0x0000001D;
#define MTIMCLK                         _MTIMCLK.Byte
#define MTIMCLK_PS0                     _MTIMCLK.Bits.PS0
#define MTIMCLK_PS1                     _MTIMCLK.Bits.PS1
#define MTIMCLK_PS2                     _MTIMCLK.Bits.PS2
#define MTIMCLK_PS3                     _MTIMCLK.Bits.PS3
#define MTIMCLK_CLKS0                   _MTIMCLK.Bits.CLKS0
#define MTIMCLK_CLKS1                   _MTIMCLK.Bits.CLKS1
#define MTIMCLK_PS                      _MTIMCLK.MergedBits.grpPS
#define MTIMCLK_CLKS                    _MTIMCLK.MergedBits.grpCLKS

#define MTIMCLK_PS0_MASK                1U
#define MTIMCLK_PS1_MASK                2U
#define MTIMCLK_PS2_MASK                4U
#define MTIMCLK_PS3_MASK                8U
#define MTIMCLK_CLKS0_MASK              16U
#define MTIMCLK_CLKS1_MASK              32U
#define MTIMCLK_PS_MASK                 15U
#define MTIMCLK_PS_BITNUM               0U
#define MTIMCLK_CLKS_MASK               48U
#define MTIMCLK_CLKS_BITNUM             4U


/*** MTIMCNT - MTIM Counter Register; 0x0000001E ***/
typedef union {
  byte Byte;
} MTIMCNTSTR;
extern volatile MTIMCNTSTR _MTIMCNT @0x0000001E;
#define MTIMCNT                         _MTIMCNT.Byte


/*** MTIMMOD - MTIM Modulo Register; 0x0000001F ***/
typedef union {
  byte Byte;
} MTIMMODSTR;
extern volatile MTIMMODSTR _MTIMMOD @0x0000001F;
#define MTIMMOD                         _MTIMMOD.Byte


/*** TPM1SC - TPM1 Status and Control Register; 0x00000020 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1SCSTR;
extern volatile TPM1SCSTR _TPM1SC @0x00000020;
#define TPM1SC                          _TPM1SC.Byte
#define TPM1SC_PS0                      _TPM1SC.Bits.PS0
#define TPM1SC_PS1                      _TPM1SC.Bits.PS1
#define TPM1SC_PS2                      _TPM1SC.Bits.PS2
#define TPM1SC_CLKSA                    _TPM1SC.Bits.CLKSA
#define TPM1SC_CLKSB                    _TPM1SC.Bits.CLKSB
#define TPM1SC_CPWMS                    _TPM1SC.Bits.CPWMS
#define TPM1SC_TOIE                     _TPM1SC.Bits.TOIE
#define TPM1SC_TOF                      _TPM1SC.Bits.TOF
#define TPM1SC_PS                       _TPM1SC.MergedBits.grpPS
#define TPM1SC_CLKSx                    _TPM1SC.MergedBits.grpCLKSx

#define TPM1SC_PS0_MASK                 1U
#define TPM1SC_PS1_MASK                 2U
#define TPM1SC_PS2_MASK                 4U
#define TPM1SC_CLKSA_MASK               8U
#define TPM1SC_CLKSB_MASK               16U
#define TPM1SC_CPWMS_MASK               32U
#define TPM1SC_TOIE_MASK                64U
#define TPM1SC_TOF_MASK                 128U
#define TPM1SC_PS_MASK                  7U
#define TPM1SC_PS_BITNUM                0U
#define TPM1SC_CLKSx_MASK               24U
#define TPM1SC_CLKSx_BITNUM             3U


/*** TPM1CNT - TPM1 Timer Counter Register; 0x00000021 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1CNTH - TPM1 Timer Counter Register High; 0x00000021 ***/
    union {
      byte Byte;
    } TPM1CNTHSTR;
    #define TPM1CNTH                    _TPM1CNT.Overlap_STR.TPM1CNTHSTR.Byte
    

    /*** TPM1CNTL - TPM1 Timer Counter Register Low; 0x00000022 ***/
    union {
      byte Byte;
    } TPM1CNTLSTR;
    #define TPM1CNTL                    _TPM1CNT.Overlap_STR.TPM1CNTLSTR.Byte
    
  } Overlap_STR;

} TPM1CNTSTR;
extern volatile TPM1CNTSTR _TPM1CNT @0x00000021;
#define TPM1CNT                         _TPM1CNT.Word


/*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0x00000023 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0x00000023 ***/
    union {
      byte Byte;
    } TPM1MODHSTR;
    #define TPM1MODH                    _TPM1MOD.Overlap_STR.TPM1MODHSTR.Byte
    

    /*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0x00000024 ***/
    union {
      byte Byte;
    } TPM1MODLSTR;
    #define TPM1MODL                    _TPM1MOD.Overlap_STR.TPM1MODLSTR.Byte
    
  } Overlap_STR;

} TPM1MODSTR;
extern volatile TPM1MODSTR _TPM1MOD @0x00000023;
#define TPM1MOD                         _TPM1MOD.Word


/*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0x00000025 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C0SCSTR;
extern volatile TPM1C0SCSTR _TPM1C0SC @0x00000025;
#define TPM1C0SC                        _TPM1C0SC.Byte
#define TPM1C0SC_ELS0A                  _TPM1C0SC.Bits.ELS0A
#define TPM1C0SC_ELS0B                  _TPM1C0SC.Bits.ELS0B
#define TPM1C0SC_MS0A                   _TPM1C0SC.Bits.MS0A
#define TPM1C0SC_MS0B                   _TPM1C0SC.Bits.MS0B
#define TPM1C0SC_CH0IE                  _TPM1C0SC.Bits.CH0IE
#define TPM1C0SC_CH0F                   _TPM1C0SC.Bits.CH0F
#define TPM1C0SC_ELS0x                  _TPM1C0SC.MergedBits.grpELS0x
#define TPM1C0SC_MS0x                   _TPM1C0SC.MergedBits.grpMS0x

#define TPM1C0SC_ELS0A_MASK             4U
#define TPM1C0SC_ELS0B_MASK             8U
#define TPM1C0SC_MS0A_MASK              16U
#define TPM1C0SC_MS0B_MASK              32U
#define TPM1C0SC_CH0IE_MASK             64U
#define TPM1C0SC_CH0F_MASK              128U
#define TPM1C0SC_ELS0x_MASK             12U
#define TPM1C0SC_ELS0x_BITNUM           2U
#define TPM1C0SC_MS0x_MASK              48U
#define TPM1C0SC_MS0x_BITNUM            4U


/*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0x00000026 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0x00000026 ***/
    union {
      byte Byte;
    } TPM1C0VHSTR;
    #define TPM1C0VH                    _TPM1C0V.Overlap_STR.TPM1C0VHSTR.Byte
    

    /*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0x00000027 ***/
    union {
      byte Byte;
    } TPM1C0VLSTR;
    #define TPM1C0VL                    _TPM1C0V.Overlap_STR.TPM1C0VLSTR.Byte
    
  } Overlap_STR;

} TPM1C0VSTR;
extern volatile TPM1C0VSTR _TPM1C0V @0x00000026;
#define TPM1C0V                         _TPM1C0V.Word


/*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0x00000028 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C1SCSTR;
extern volatile TPM1C1SCSTR _TPM1C1SC @0x00000028;
#define TPM1C1SC                        _TPM1C1SC.Byte
#define TPM1C1SC_ELS1A                  _TPM1C1SC.Bits.ELS1A
#define TPM1C1SC_ELS1B                  _TPM1C1SC.Bits.ELS1B
#define TPM1C1SC_MS1A                   _TPM1C1SC.Bits.MS1A
#define TPM1C1SC_MS1B                   _TPM1C1SC.Bits.MS1B
#define TPM1C1SC_CH1IE                  _TPM1C1SC.Bits.CH1IE
#define TPM1C1SC_CH1F                   _TPM1C1SC.Bits.CH1F
#define TPM1C1SC_ELS1x                  _TPM1C1SC.MergedBits.grpELS1x
#define TPM1C1SC_MS1x                   _TPM1C1SC.MergedBits.grpMS1x

#define TPM1C1SC_ELS1A_MASK             4U
#define TPM1C1SC_ELS1B_MASK             8U
#define TPM1C1SC_MS1A_MASK              16U
#define TPM1C1SC_MS1B_MASK              32U
#define TPM1C1SC_CH1IE_MASK             64U
#define TPM1C1SC_CH1F_MASK              128U
#define TPM1C1SC_ELS1x_MASK             12U
#define TPM1C1SC_ELS1x_BITNUM           2U
#define TPM1C1SC_MS1x_MASK              48U
#define TPM1C1SC_MS1x_BITNUM            4U


/*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0x00000029 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0x00000029 ***/
    union {
      byte Byte;
    } TPM1C1VHSTR;
    #define TPM1C1VH                    _TPM1C1V.Overlap_STR.TPM1C1VHSTR.Byte
    

    /*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0x0000002A ***/
    union {
      byte Byte;
    } TPM1C1VLSTR;
    #define TPM1C1VL                    _TPM1C1V.Overlap_STR.TPM1C1VLSTR.Byte
    
  } Overlap_STR;

} TPM1C1VSTR;
extern volatile TPM1C1VSTR _TPM1C1V @0x00000029;
#define TPM1C1V                         _TPM1C1V.Word


/*** SCIBD - SCI Baud Rate Register; 0x00000038 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCIBDH - SCI Baud Rate Register High; 0x00000038 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCIBDHSTR;
    #define SCIBDH                      _SCIBD.Overlap_STR.SCIBDHSTR.Byte
    #define SCIBDH_SBR8                 _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR8
    #define SCIBDH_SBR9                 _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR9
    #define SCIBDH_SBR10                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR10
    #define SCIBDH_SBR11                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR11
    #define SCIBDH_SBR12                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR12
    #define SCIBDH_RXEDGIE              _SCIBD.Overlap_STR.SCIBDHSTR.Bits.RXEDGIE
    #define SCIBDH_LBKDIE               _SCIBD.Overlap_STR.SCIBDHSTR.Bits.LBKDIE
    #define SCIBDH_SBR_8                _SCIBD.Overlap_STR.SCIBDHSTR.MergedBits.grpSBR_8
    #define SCIBDH_SBR                  SCIBDH_SBR_8
    
    #define SCIBDH_SBR8_MASK            1U
    #define SCIBDH_SBR9_MASK            2U
    #define SCIBDH_SBR10_MASK           4U
    #define SCIBDH_SBR11_MASK           8U
    #define SCIBDH_SBR12_MASK           16U
    #define SCIBDH_RXEDGIE_MASK         64U
    #define SCIBDH_LBKDIE_MASK          128U
    #define SCIBDH_SBR_8_MASK           31U
    #define SCIBDH_SBR_8_BITNUM         0U
    

    /*** SCIBDL - SCI Baud Rate Register Low; 0x00000039 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCIBDLSTR;
    #define SCIBDL                      _SCIBD.Overlap_STR.SCIBDLSTR.Byte
    #define SCIBDL_SBR0                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR0
    #define SCIBDL_SBR1                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR1
    #define SCIBDL_SBR2                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR2
    #define SCIBDL_SBR3                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR3
    #define SCIBDL_SBR4                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR4
    #define SCIBDL_SBR5                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR5
    #define SCIBDL_SBR6                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR6
    #define SCIBDL_SBR7                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR7
    
    #define SCIBDL_SBR0_MASK            1U
    #define SCIBDL_SBR1_MASK            2U
    #define SCIBDL_SBR2_MASK            4U
    #define SCIBDL_SBR3_MASK            8U
    #define SCIBDL_SBR4_MASK            16U
    #define SCIBDL_SBR5_MASK            32U
    #define SCIBDL_SBR6_MASK            64U
    #define SCIBDL_SBR7_MASK            128U
    
  } Overlap_STR;

} SCIBDSTR;
extern volatile SCIBDSTR _SCIBD @0x00000038;
#define SCIBD                           _SCIBD.Word


/*** SCIC1 - SCI Control Register 1; 0x0000003A ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCIC1STR;
extern volatile SCIC1STR _SCIC1 @0x0000003A;
#define SCIC1                           _SCIC1.Byte
#define SCIC1_PT                        _SCIC1.Bits.PT
#define SCIC1_PE                        _SCIC1.Bits.PE
#define SCIC1_ILT                       _SCIC1.Bits.ILT
#define SCIC1_WAKE                      _SCIC1.Bits.WAKE
#define SCIC1_M                         _SCIC1.Bits.M
#define SCIC1_RSRC                      _SCIC1.Bits.RSRC
#define SCIC1_SCISWAI                   _SCIC1.Bits.SCISWAI
#define SCIC1_LOOPS                     _SCIC1.Bits.LOOPS

#define SCIC1_PT_MASK                   1U
#define SCIC1_PE_MASK                   2U
#define SCIC1_ILT_MASK                  4U
#define SCIC1_WAKE_MASK                 8U
#define SCIC1_M_MASK                    16U
#define SCIC1_RSRC_MASK                 32U
#define SCIC1_SCISWAI_MASK              64U
#define SCIC1_LOOPS_MASK                128U


/*** SCIC2 - SCI Control Register 2; 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCIC2STR;
extern volatile SCIC2STR _SCIC2 @0x0000003B;
#define SCIC2                           _SCIC2.Byte
#define SCIC2_SBK                       _SCIC2.Bits.SBK
#define SCIC2_RWU                       _SCIC2.Bits.RWU
#define SCIC2_RE                        _SCIC2.Bits.RE
#define SCIC2_TE                        _SCIC2.Bits.TE
#define SCIC2_ILIE                      _SCIC2.Bits.ILIE
#define SCIC2_RIE                       _SCIC2.Bits.RIE
#define SCIC2_TCIE                      _SCIC2.Bits.TCIE
#define SCIC2_TIE                       _SCIC2.Bits.TIE

#define SCIC2_SBK_MASK                  1U
#define SCIC2_RWU_MASK                  2U
#define SCIC2_RE_MASK                   4U
#define SCIC2_TE_MASK                   8U
#define SCIC2_ILIE_MASK                 16U
#define SCIC2_RIE_MASK                  32U
#define SCIC2_TCIE_MASK                 64U
#define SCIC2_TIE_MASK                  128U


/*** SCIS1 - SCI Status Register 1; 0x0000003C ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCIS1STR;
extern volatile SCIS1STR _SCIS1 @0x0000003C;
#define SCIS1                           _SCIS1.Byte
#define SCIS1_PF                        _SCIS1.Bits.PF
#define SCIS1_FE                        _SCIS1.Bits.FE
#define SCIS1_NF                        _SCIS1.Bits.NF
#define SCIS1_OR                        _SCIS1.Bits.OR
#define SCIS1_IDLE                      _SCIS1.Bits.IDLE
#define SCIS1_RDRF                      _SCIS1.Bits.RDRF
#define SCIS1_TC                        _SCIS1.Bits.TC
#define SCIS1_TDRE                      _SCIS1.Bits.TDRE

#define SCIS1_PF_MASK                   1U
#define SCIS1_FE_MASK                   2U
#define SCIS1_NF_MASK                   4U
#define SCIS1_OR_MASK                   8U
#define SCIS1_IDLE_MASK                 16U
#define SCIS1_RDRF_MASK                 32U
#define SCIS1_TC_MASK                   64U
#define SCIS1_TDRE_MASK                 128U


/*** SCIS2 - SCI Status Register 2; 0x0000003D ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCIS2STR;
extern volatile SCIS2STR _SCIS2 @0x0000003D;
#define SCIS2                           _SCIS2.Byte
#define SCIS2_RAF                       _SCIS2.Bits.RAF
#define SCIS2_LBKDE                     _SCIS2.Bits.LBKDE
#define SCIS2_BRK13                     _SCIS2.Bits.BRK13
#define SCIS2_RWUID                     _SCIS2.Bits.RWUID
#define SCIS2_RXINV                     _SCIS2.Bits.RXINV
#define SCIS2_RXEDGIF                   _SCIS2.Bits.RXEDGIF
#define SCIS2_LBKDIF                    _SCIS2.Bits.LBKDIF

#define SCIS2_RAF_MASK                  1U
#define SCIS2_LBKDE_MASK                2U
#define SCIS2_BRK13_MASK                4U
#define SCIS2_RWUID_MASK                8U
#define SCIS2_RXINV_MASK                16U
#define SCIS2_RXEDGIF_MASK              64U
#define SCIS2_LBKDIF_MASK               128U


/*** SCIC3 - SCI Control Register 3; 0x0000003E ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCIC3STR;
extern volatile SCIC3STR _SCIC3 @0x0000003E;
#define SCIC3                           _SCIC3.Byte
#define SCIC3_PEIE                      _SCIC3.Bits.PEIE
#define SCIC3_FEIE                      _SCIC3.Bits.FEIE
#define SCIC3_NEIE                      _SCIC3.Bits.NEIE
#define SCIC3_ORIE                      _SCIC3.Bits.ORIE
#define SCIC3_TXINV                     _SCIC3.Bits.TXINV
#define SCIC3_TXDIR                     _SCIC3.Bits.TXDIR
#define SCIC3_T8                        _SCIC3.Bits.T8
#define SCIC3_R8                        _SCIC3.Bits.R8

#define SCIC3_PEIE_MASK                 1U
#define SCIC3_FEIE_MASK                 2U
#define SCIC3_NEIE_MASK                 4U
#define SCIC3_ORIE_MASK                 8U
#define SCIC3_TXINV_MASK                16U
#define SCIC3_TXDIR_MASK                32U
#define SCIC3_T8_MASK                   64U
#define SCIC3_R8_MASK                   128U


/*** SCID - SCI Data Register; 0x0000003F ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCIDSTR;
extern volatile SCIDSTR _SCID @0x0000003F;
#define SCID                            _SCID.Byte
#define SCID_R0_T0                      _SCID.Bits.R0_T0
#define SCID_R1_T1                      _SCID.Bits.R1_T1
#define SCID_R2_T2                      _SCID.Bits.R2_T2
#define SCID_R3_T3                      _SCID.Bits.R3_T3
#define SCID_R4_T4                      _SCID.Bits.R4_T4
#define SCID_R5_T5                      _SCID.Bits.R5_T5
#define SCID_R6_T6                      _SCID.Bits.R6_T6
#define SCID_R7_T7                      _SCID.Bits.R7_T7

#define SCID_R0_T0_MASK                 1U
#define SCID_R1_T1_MASK                 2U
#define SCID_R2_T2_MASK                 4U
#define SCID_R3_T3_MASK                 8U
#define SCID_R4_T4_MASK                 16U
#define SCID_R5_T5_MASK                 32U
#define SCID_R6_T6_MASK                 64U
#define SCID_R7_T7_MASK                 128U


/*** ICSC1 - ICS Control Register 1; 0x00000048 ***/
typedef union {
  byte Byte;
  struct {
    byte IREFSTEN    :1;                                       /* Internal Reference Stop Enable */
    byte IRCLKEN     :1;                                       /* Internal Reference Clock Enable */
    byte IREFS       :1;                                       /* Internal Reference Select */
    byte RDIV0       :1;                                       /* Reference Divider, bit 0 */
    byte RDIV1       :1;                                       /* Reference Divider, bit 1 */
    byte RDIV2       :1;                                       /* Reference Divider, bit 2 */
    byte CLKS0       :1;                                       /* Clock Source Select, bit 0 */
    byte CLKS1       :1;                                       /* Clock Source Select, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDIV :3;
    byte grpCLKS :2;
  } MergedBits;
} ICSC1STR;
extern volatile ICSC1STR _ICSC1 @0x00000048;
#define ICSC1                           _ICSC1.Byte
#define ICSC1_IREFSTEN                  _ICSC1.Bits.IREFSTEN
#define ICSC1_IRCLKEN                   _ICSC1.Bits.IRCLKEN
#define ICSC1_IREFS                     _ICSC1.Bits.IREFS
#define ICSC1_RDIV0                     _ICSC1.Bits.RDIV0
#define ICSC1_RDIV1                     _ICSC1.Bits.RDIV1
#define ICSC1_RDIV2                     _ICSC1.Bits.RDIV2
#define ICSC1_CLKS0                     _ICSC1.Bits.CLKS0
#define ICSC1_CLKS1                     _ICSC1.Bits.CLKS1
#define ICSC1_RDIV                      _ICSC1.MergedBits.grpRDIV
#define ICSC1_CLKS                      _ICSC1.MergedBits.grpCLKS

#define ICSC1_IREFSTEN_MASK             1U
#define ICSC1_IRCLKEN_MASK              2U
#define ICSC1_IREFS_MASK                4U
#define ICSC1_RDIV0_MASK                8U
#define ICSC1_RDIV1_MASK                16U
#define ICSC1_RDIV2_MASK                32U
#define ICSC1_CLKS0_MASK                64U
#define ICSC1_CLKS1_MASK                128U
#define ICSC1_RDIV_MASK                 56U
#define ICSC1_RDIV_BITNUM               3U
#define ICSC1_CLKS_MASK                 192U
#define ICSC1_CLKS_BITNUM               6U


/*** ICSC2 - ICS Control Register 2; 0x00000049 ***/
typedef union {
  byte Byte;
  struct {
    byte EREFSTEN    :1;                                       /* External Reference Stop Enable */
    byte ERCLKEN     :1;                                       /* External Reference Enable */
    byte EREFS       :1;                                       /* External Reference Select */
    byte LP          :1;                                       /* Low Power Select */
    byte HGO         :1;                                       /* High Gain Oscillator Select */
    byte RANGE       :1;                                       /* Frequency Range Select */
    byte BDIV0       :1;                                       /* Bus Frequency Divider, bit 0 */
    byte BDIV1       :1;                                       /* Bus Frequency Divider, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpBDIV :2;
  } MergedBits;
} ICSC2STR;
extern volatile ICSC2STR _ICSC2 @0x00000049;
#define ICSC2                           _ICSC2.Byte
#define ICSC2_EREFSTEN                  _ICSC2.Bits.EREFSTEN
#define ICSC2_ERCLKEN                   _ICSC2.Bits.ERCLKEN
#define ICSC2_EREFS                     _ICSC2.Bits.EREFS
#define ICSC2_LP                        _ICSC2.Bits.LP
#define ICSC2_HGO                       _ICSC2.Bits.HGO
#define ICSC2_RANGE                     _ICSC2.Bits.RANGE
#define ICSC2_BDIV0                     _ICSC2.Bits.BDIV0
#define ICSC2_BDIV1                     _ICSC2.Bits.BDIV1
#define ICSC2_BDIV                      _ICSC2.MergedBits.grpBDIV

#define ICSC2_EREFSTEN_MASK             1U
#define ICSC2_ERCLKEN_MASK              2U
#define ICSC2_EREFS_MASK                4U
#define ICSC2_LP_MASK                   8U
#define ICSC2_HGO_MASK                  16U
#define ICSC2_RANGE_MASK                32U
#define ICSC2_BDIV0_MASK                64U
#define ICSC2_BDIV1_MASK                128U
#define ICSC2_BDIV_MASK                 192U
#define ICSC2_BDIV_BITNUM               6U


/*** ICSTRM - ICS Trim Register; 0x0000004A ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* ICS Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* ICS Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* ICS Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* ICS Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* ICS Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* ICS Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* ICS Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* ICS Trim Setting, bit 7 */
  } Bits;
} ICSTRMSTR;
extern volatile ICSTRMSTR _ICSTRM @0x0000004A;
#define ICSTRM                          _ICSTRM.Byte
#define ICSTRM_TRIM0                    _ICSTRM.Bits.TRIM0
#define ICSTRM_TRIM1                    _ICSTRM.Bits.TRIM1
#define ICSTRM_TRIM2                    _ICSTRM.Bits.TRIM2
#define ICSTRM_TRIM3                    _ICSTRM.Bits.TRIM3
#define ICSTRM_TRIM4                    _ICSTRM.Bits.TRIM4
#define ICSTRM_TRIM5                    _ICSTRM.Bits.TRIM5
#define ICSTRM_TRIM6                    _ICSTRM.Bits.TRIM6
#define ICSTRM_TRIM7                    _ICSTRM.Bits.TRIM7

#define ICSTRM_TRIM0_MASK               1U
#define ICSTRM_TRIM1_MASK               2U
#define ICSTRM_TRIM2_MASK               4U
#define ICSTRM_TRIM3_MASK               8U
#define ICSTRM_TRIM4_MASK               16U
#define ICSTRM_TRIM5_MASK               32U
#define ICSTRM_TRIM6_MASK               64U
#define ICSTRM_TRIM7_MASK               128U


/*** ICSSC - ICS Status and Control Register; 0x0000004B ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       /* ICS Fine Trim */
    byte OSCINIT     :1;                                       /* OSC Initialization */
    byte CLKST0      :1;                                       /* Clock Mode Status, bit 0 */
    byte CLKST1      :1;                                       /* Clock Mode Status, bit 1 */
    byte IREFST      :1;                                       /* Internal Reference Status */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLKST :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ICSSCSTR;
extern volatile ICSSCSTR _ICSSC @0x0000004B;
#define ICSSC                           _ICSSC.Byte
#define ICSSC_FTRIM                     _ICSSC.Bits.FTRIM
#define ICSSC_OSCINIT                   _ICSSC.Bits.OSCINIT
#define ICSSC_CLKST0                    _ICSSC.Bits.CLKST0
#define ICSSC_CLKST1                    _ICSSC.Bits.CLKST1
#define ICSSC_IREFST                    _ICSSC.Bits.IREFST
#define ICSSC_CLKST                     _ICSSC.MergedBits.grpCLKST

#define ICSSC_FTRIM_MASK                1U
#define ICSSC_OSCINIT_MASK              2U
#define ICSSC_CLKST0_MASK               4U
#define ICSSC_CLKST1_MASK               8U
#define ICSSC_IREFST_MASK               16U
#define ICSSC_CLKST_MASK                12U
#define ICSSC_CLKST_BITNUM              2U


/*** SPIC1 - SPI Control Register 1; 0x00000050 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (Shifter Direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable (for SPRF and MODF) */
  } Bits;
} SPIC1STR;
extern volatile SPIC1STR _SPIC1 @0x00000050;
#define SPIC1                           _SPIC1.Byte
#define SPIC1_LSBFE                     _SPIC1.Bits.LSBFE
#define SPIC1_SSOE                      _SPIC1.Bits.SSOE
#define SPIC1_CPHA                      _SPIC1.Bits.CPHA
#define SPIC1_CPOL                      _SPIC1.Bits.CPOL
#define SPIC1_MSTR                      _SPIC1.Bits.MSTR
#define SPIC1_SPTIE                     _SPIC1.Bits.SPTIE
#define SPIC1_SPE                       _SPIC1.Bits.SPE
#define SPIC1_SPIE                      _SPIC1.Bits.SPIE

#define SPIC1_LSBFE_MASK                1U
#define SPIC1_SSOE_MASK                 2U
#define SPIC1_CPHA_MASK                 4U
#define SPIC1_CPOL_MASK                 8U
#define SPIC1_MSTR_MASK                 16U
#define SPIC1_SPTIE_MASK                32U
#define SPIC1_SPE_MASK                  64U
#define SPIC1_SPIE_MASK                 128U


/*** SPIC2 - SPI Control Register 2; 0x00000051 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPIC2STR;
extern volatile SPIC2STR _SPIC2 @0x00000051;
#define SPIC2                           _SPIC2.Byte
#define SPIC2_SPC0                      _SPIC2.Bits.SPC0
#define SPIC2_SPISWAI                   _SPIC2.Bits.SPISWAI
#define SPIC2_BIDIROE                   _SPIC2.Bits.BIDIROE
#define SPIC2_MODFEN                    _SPIC2.Bits.MODFEN

#define SPIC2_SPC0_MASK                 1U
#define SPIC2_SPISWAI_MASK              2U
#define SPIC2_BIDIROE_MASK              8U
#define SPIC2_MODFEN_MASK               16U


/*** SPIBR - SPI Baud Rate Register; 0x00000052 ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPIBRSTR;
extern volatile SPIBRSTR _SPIBR @0x00000052;
#define SPIBR                           _SPIBR.Byte
#define SPIBR_SPR0                      _SPIBR.Bits.SPR0
#define SPIBR_SPR1                      _SPIBR.Bits.SPR1
#define SPIBR_SPR2                      _SPIBR.Bits.SPR2
#define SPIBR_SPPR0                     _SPIBR.Bits.SPPR0
#define SPIBR_SPPR1                     _SPIBR.Bits.SPPR1
#define SPIBR_SPPR2                     _SPIBR.Bits.SPPR2
#define SPIBR_SPR                       _SPIBR.MergedBits.grpSPR
#define SPIBR_SPPR                      _SPIBR.MergedBits.grpSPPR

#define SPIBR_SPR0_MASK                 1U
#define SPIBR_SPR1_MASK                 2U
#define SPIBR_SPR2_MASK                 4U
#define SPIBR_SPPR0_MASK                16U
#define SPIBR_SPPR1_MASK                32U
#define SPIBR_SPPR2_MASK                64U
#define SPIBR_SPR_MASK                  7U
#define SPIBR_SPR_BITNUM                0U
#define SPIBR_SPPR_MASK                 112U
#define SPIBR_SPPR_BITNUM               4U


/*** SPIS - SPI Status Register; 0x00000053 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte             :1; 
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPISSTR;
extern volatile SPISSTR _SPIS @0x00000053;
#define SPIS                            _SPIS.Byte
#define SPIS_MODF                       _SPIS.Bits.MODF
#define SPIS_SPTEF                      _SPIS.Bits.SPTEF
#define SPIS_SPRF                       _SPIS.Bits.SPRF

#define SPIS_MODF_MASK                  16U
#define SPIS_SPTEF_MASK                 32U
#define SPIS_SPRF_MASK                  128U


/*** SPID - SPI Data Register; 0x00000055 ***/
typedef union {
  byte Byte;
} SPIDSTR;
extern volatile SPIDSTR _SPID @0x00000055;
#define SPID                            _SPID.Byte


/*** IICA - IIC Address Register; 0x00000058 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte AD1         :1;                                       /* Slave Address Bit 1 */
    byte AD2         :1;                                       /* Slave Address Bit 2 */
    byte AD3         :1;                                       /* Slave Address Bit 3 */
    byte AD4         :1;                                       /* Slave Address Bit 4 */
    byte AD5         :1;                                       /* Slave Address Bit 5 */
    byte AD6         :1;                                       /* Slave Address Bit 6 */
    byte AD7         :1;                                       /* Slave Address Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpAD_1 :7;
  } MergedBits;
} IICASTR;
extern volatile IICASTR _IICA @0x00000058;
#define IICA                            _IICA.Byte
#define IICA_AD1                        _IICA.Bits.AD1
#define IICA_AD2                        _IICA.Bits.AD2
#define IICA_AD3                        _IICA.Bits.AD3
#define IICA_AD4                        _IICA.Bits.AD4
#define IICA_AD5                        _IICA.Bits.AD5
#define IICA_AD6                        _IICA.Bits.AD6
#define IICA_AD7                        _IICA.Bits.AD7
#define IICA_AD_1                       _IICA.MergedBits.grpAD_1
#define IICA_AD                         IICA_AD_1

#define IICA_AD1_MASK                   2U
#define IICA_AD2_MASK                   4U
#define IICA_AD3_MASK                   8U
#define IICA_AD4_MASK                   16U
#define IICA_AD5_MASK                   32U
#define IICA_AD6_MASK                   64U
#define IICA_AD7_MASK                   128U
#define IICA_AD_1_MASK                  254U
#define IICA_AD_1_BITNUM                1U


/*** IICF - IIC Frequency Divider Register; 0x00000059 ***/
typedef union {
  byte Byte;
  struct {
    byte ICR0        :1;                                       /* IIC Clock Rate Bit 0 */
    byte ICR1        :1;                                       /* IIC Clock Rate Bit 1 */
    byte ICR2        :1;                                       /* IIC Clock Rate Bit 2 */
    byte ICR3        :1;                                       /* IIC Clock Rate Bit 3 */
    byte ICR4        :1;                                       /* IIC Clock Rate Bit 4 */
    byte ICR5        :1;                                       /* IIC Clock Rate Bit 5 */
    byte MULT0       :1;                                       /* Multiplier Factor Bit 0 */
    byte MULT1       :1;                                       /* Multiplier Factor Bit 1 */
  } Bits;
  struct {
    byte grpICR  :6;
    byte grpMULT :2;
  } MergedBits;
} IICFSTR;
extern volatile IICFSTR _IICF @0x00000059;
#define IICF                            _IICF.Byte
#define IICF_ICR0                       _IICF.Bits.ICR0
#define IICF_ICR1                       _IICF.Bits.ICR1
#define IICF_ICR2                       _IICF.Bits.ICR2
#define IICF_ICR3                       _IICF.Bits.ICR3
#define IICF_ICR4                       _IICF.Bits.ICR4
#define IICF_ICR5                       _IICF.Bits.ICR5
#define IICF_MULT0                      _IICF.Bits.MULT0
#define IICF_MULT1                      _IICF.Bits.MULT1
#define IICF_ICR                        _IICF.MergedBits.grpICR
#define IICF_MULT                       _IICF.MergedBits.grpMULT

#define IICF_ICR0_MASK                  1U
#define IICF_ICR1_MASK                  2U
#define IICF_ICR2_MASK                  4U
#define IICF_ICR3_MASK                  8U
#define IICF_ICR4_MASK                  16U
#define IICF_ICR5_MASK                  32U
#define IICF_MULT0_MASK                 64U
#define IICF_MULT1_MASK                 128U
#define IICF_ICR_MASK                   63U
#define IICF_ICR_BITNUM                 0U
#define IICF_MULT_MASK                  192U
#define IICF_MULT_BITNUM                6U


/*** IICC1 - IIC Control Register 1; 0x0000005A ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** IICC1 - IIC Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IICC1STR;
    #define IICC1                       _IICC1.Byte
    #define IICC1_RSTA                  _IICC1.SameAddr_STR.IICC1STR.Bits.RSTA
    #define IICC1_TXAK                  _IICC1.SameAddr_STR.IICC1STR.Bits.TXAK
    #define IICC1_TX                    _IICC1.SameAddr_STR.IICC1STR.Bits.TX
    #define IICC1_MST                   _IICC1.SameAddr_STR.IICC1STR.Bits.MST
    #define IICC1_IICIE                 _IICC1.SameAddr_STR.IICC1STR.Bits.IICIE
    #define IICC1_IICEN                 _IICC1.SameAddr_STR.IICC1STR.Bits.IICEN
    
    #define IICC1_RSTA_MASK             4U
    #define IICC1_TXAK_MASK             8U
    #define IICC1_TX_MASK               16U
    #define IICC1_MST_MASK              32U
    #define IICC1_IICIE_MASK            64U
    #define IICC1_IICEN_MASK            128U
    
    /*** IICC - IIC Control Register; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IICCSTR;
    #define IICC                        _IICC1.Byte
    #define IICC_RSTA                   _IICC1.SameAddr_STR.IICCSTR.Bits.RSTA
    #define IICC_TXAK                   _IICC1.SameAddr_STR.IICCSTR.Bits.TXAK
    #define IICC_TX                     _IICC1.SameAddr_STR.IICCSTR.Bits.TX
    #define IICC_MST                    _IICC1.SameAddr_STR.IICCSTR.Bits.MST
    #define IICC_IICIE                  _IICC1.SameAddr_STR.IICCSTR.Bits.IICIE
    #define IICC_IICEN                  _IICC1.SameAddr_STR.IICCSTR.Bits.IICEN
    
    #define IICC_RSTA_MASK              4U
    #define IICC_TXAK_MASK              8U
    #define IICC_TX_MASK                16U
    #define IICC_MST_MASK               32U
    #define IICC_IICIE_MASK             64U
    #define IICC_IICEN_MASK             128U
    
  } SameAddr_STR; /*Several registers at the same address */

} IICC1STR;
extern volatile IICC1STR _IICC1 @0x0000005A;


/*** IICS - IIC Status Register; 0x0000005B ***/
typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       /* Receive Acknowledge */
    byte IICIF       :1;                                       /* IIC Interrupt Flag */
    byte SRW         :1;                                       /* Slave Read/Write */
    byte             :1; 
    byte ARBL        :1;                                       /* Arbitration Lost */
    byte BUSY        :1;                                       /* Bus Busy */
    byte IAAS        :1;                                       /* Addressed as a Slave */
    byte TCF         :1;                                       /* Transfer Complete Flag */
  } Bits;
} IICSSTR;
extern volatile IICSSTR _IICS @0x0000005B;
#define IICS                            _IICS.Byte
#define IICS_RXAK                       _IICS.Bits.RXAK
#define IICS_IICIF                      _IICS.Bits.IICIF
#define IICS_SRW                        _IICS.Bits.SRW
#define IICS_ARBL                       _IICS.Bits.ARBL
#define IICS_BUSY                       _IICS.Bits.BUSY
#define IICS_IAAS                       _IICS.Bits.IAAS
#define IICS_TCF                        _IICS.Bits.TCF

#define IICS_RXAK_MASK                  1U
#define IICS_IICIF_MASK                 2U
#define IICS_SRW_MASK                   4U
#define IICS_ARBL_MASK                  16U
#define IICS_BUSY_MASK                  32U
#define IICS_IAAS_MASK                  64U
#define IICS_TCF_MASK                   128U


/*** IICD - IIC Data I/O Register; 0x0000005C ***/
typedef union {
  byte Byte;
  struct {
    byte DATA0       :1;                                       /* IIC Data Bit 0 */
    byte DATA1       :1;                                       /* IIC Data Bit 1 */
    byte DATA2       :1;                                       /* IIC Data Bit 2 */
    byte DATA3       :1;                                       /* IIC Data Bit 3 */
    byte DATA4       :1;                                       /* IIC Data Bit 4 */
    byte DATA5       :1;                                       /* IIC Data Bit 5 */
    byte DATA6       :1;                                       /* IIC Data Bit 6 */
    byte DATA7       :1;                                       /* IIC Data Bit 7 */
  } Bits;
} IICDSTR;
extern volatile IICDSTR _IICD @0x0000005C;
#define IICD                            _IICD.Byte
#define IICD_DATA0                      _IICD.Bits.DATA0
#define IICD_DATA1                      _IICD.Bits.DATA1
#define IICD_DATA2                      _IICD.Bits.DATA2
#define IICD_DATA3                      _IICD.Bits.DATA3
#define IICD_DATA4                      _IICD.Bits.DATA4
#define IICD_DATA5                      _IICD.Bits.DATA5
#define IICD_DATA6                      _IICD.Bits.DATA6
#define IICD_DATA7                      _IICD.Bits.DATA7

#define IICD_DATA0_MASK                 1U
#define IICD_DATA1_MASK                 2U
#define IICD_DATA2_MASK                 4U
#define IICD_DATA3_MASK                 8U
#define IICD_DATA4_MASK                 16U
#define IICD_DATA5_MASK                 32U
#define IICD_DATA6_MASK                 64U
#define IICD_DATA7_MASK                 128U


/*** IICC2 - IIC Control Register 2; 0x0000005D ***/
typedef union {
  byte Byte;
  struct {
    byte AD8         :1;                                       /* Slave Address Bit 8 */
    byte AD9         :1;                                       /* Slave Address Bit 9 */
    byte AD10        :1;                                       /* Slave Address Bit 10 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ADEXT       :1;                                       /* Address Extension */
    byte GCAEN       :1;                                       /* General Call Address Enable */
  } Bits;
  struct {
    byte grpAD_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IICC2STR;
extern volatile IICC2STR _IICC2 @0x0000005D;
#define IICC2                           _IICC2.Byte
#define IICC2_AD8                       _IICC2.Bits.AD8
#define IICC2_AD9                       _IICC2.Bits.AD9
#define IICC2_AD10                      _IICC2.Bits.AD10
#define IICC2_ADEXT                     _IICC2.Bits.ADEXT
#define IICC2_GCAEN                     _IICC2.Bits.GCAEN
#define IICC2_AD_8                      _IICC2.MergedBits.grpAD_8
#define IICC2_AD                        IICC2_AD_8

#define IICC2_AD8_MASK                  1U
#define IICC2_AD9_MASK                  2U
#define IICC2_AD10_MASK                 4U
#define IICC2_ADEXT_MASK                64U
#define IICC2_GCAEN_MASK                128U
#define IICC2_AD_8_MASK                 7U
#define IICC2_AD_8_BITNUM               0U


/*** TPM2SC - TPM2 Status and Control Register; 0x00000060 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2SCSTR;
extern volatile TPM2SCSTR _TPM2SC @0x00000060;
#define TPM2SC                          _TPM2SC.Byte
#define TPM2SC_PS0                      _TPM2SC.Bits.PS0
#define TPM2SC_PS1                      _TPM2SC.Bits.PS1
#define TPM2SC_PS2                      _TPM2SC.Bits.PS2
#define TPM2SC_CLKSA                    _TPM2SC.Bits.CLKSA
#define TPM2SC_CLKSB                    _TPM2SC.Bits.CLKSB
#define TPM2SC_CPWMS                    _TPM2SC.Bits.CPWMS
#define TPM2SC_TOIE                     _TPM2SC.Bits.TOIE
#define TPM2SC_TOF                      _TPM2SC.Bits.TOF
#define TPM2SC_PS                       _TPM2SC.MergedBits.grpPS
#define TPM2SC_CLKSx                    _TPM2SC.MergedBits.grpCLKSx

#define TPM2SC_PS0_MASK                 1U
#define TPM2SC_PS1_MASK                 2U
#define TPM2SC_PS2_MASK                 4U
#define TPM2SC_CLKSA_MASK               8U
#define TPM2SC_CLKSB_MASK               16U
#define TPM2SC_CPWMS_MASK               32U
#define TPM2SC_TOIE_MASK                64U
#define TPM2SC_TOF_MASK                 128U
#define TPM2SC_PS_MASK                  7U
#define TPM2SC_PS_BITNUM                0U
#define TPM2SC_CLKSx_MASK               24U
#define TPM2SC_CLKSx_BITNUM             3U


/*** TPM2CNT - TPM2 Timer Counter Register; 0x00000061 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2CNTH - TPM2 Timer Counter Register High; 0x00000061 ***/
    union {
      byte Byte;
    } TPM2CNTHSTR;
    #define TPM2CNTH                    _TPM2CNT.Overlap_STR.TPM2CNTHSTR.Byte
    

    /*** TPM2CNTL - TPM2 Timer Counter Register Low; 0x00000062 ***/
    union {
      byte Byte;
    } TPM2CNTLSTR;
    #define TPM2CNTL                    _TPM2CNT.Overlap_STR.TPM2CNTLSTR.Byte
    
  } Overlap_STR;

} TPM2CNTSTR;
extern volatile TPM2CNTSTR _TPM2CNT @0x00000061;
#define TPM2CNT                         _TPM2CNT.Word


/*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0x00000063 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0x00000063 ***/
    union {
      byte Byte;
    } TPM2MODHSTR;
    #define TPM2MODH                    _TPM2MOD.Overlap_STR.TPM2MODHSTR.Byte
    

    /*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0x00000064 ***/
    union {
      byte Byte;
    } TPM2MODLSTR;
    #define TPM2MODL                    _TPM2MOD.Overlap_STR.TPM2MODLSTR.Byte
    
  } Overlap_STR;

} TPM2MODSTR;
extern volatile TPM2MODSTR _TPM2MOD @0x00000063;
#define TPM2MOD                         _TPM2MOD.Word


/*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0x00000065 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C0SCSTR;
extern volatile TPM2C0SCSTR _TPM2C0SC @0x00000065;
#define TPM2C0SC                        _TPM2C0SC.Byte
#define TPM2C0SC_ELS0A                  _TPM2C0SC.Bits.ELS0A
#define TPM2C0SC_ELS0B                  _TPM2C0SC.Bits.ELS0B
#define TPM2C0SC_MS0A                   _TPM2C0SC.Bits.MS0A
#define TPM2C0SC_MS0B                   _TPM2C0SC.Bits.MS0B
#define TPM2C0SC_CH0IE                  _TPM2C0SC.Bits.CH0IE
#define TPM2C0SC_CH0F                   _TPM2C0SC.Bits.CH0F
#define TPM2C0SC_ELS0x                  _TPM2C0SC.MergedBits.grpELS0x
#define TPM2C0SC_MS0x                   _TPM2C0SC.MergedBits.grpMS0x

#define TPM2C0SC_ELS0A_MASK             4U
#define TPM2C0SC_ELS0B_MASK             8U
#define TPM2C0SC_MS0A_MASK              16U
#define TPM2C0SC_MS0B_MASK              32U
#define TPM2C0SC_CH0IE_MASK             64U
#define TPM2C0SC_CH0F_MASK              128U
#define TPM2C0SC_ELS0x_MASK             12U
#define TPM2C0SC_ELS0x_BITNUM           2U
#define TPM2C0SC_MS0x_MASK              48U
#define TPM2C0SC_MS0x_BITNUM            4U


/*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0x00000066 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0x00000066 ***/
    union {
      byte Byte;
    } TPM2C0VHSTR;
    #define TPM2C0VH                    _TPM2C0V.Overlap_STR.TPM2C0VHSTR.Byte
    

    /*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0x00000067 ***/
    union {
      byte Byte;
    } TPM2C0VLSTR;
    #define TPM2C0VL                    _TPM2C0V.Overlap_STR.TPM2C0VLSTR.Byte
    
  } Overlap_STR;

} TPM2C0VSTR;
extern volatile TPM2C0VSTR _TPM2C0V @0x00000066;
#define TPM2C0V                         _TPM2C0V.Word


/*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register; 0x00000068 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C1SCSTR;
extern volatile TPM2C1SCSTR _TPM2C1SC @0x00000068;
#define TPM2C1SC                        _TPM2C1SC.Byte
#define TPM2C1SC_ELS1A                  _TPM2C1SC.Bits.ELS1A
#define TPM2C1SC_ELS1B                  _TPM2C1SC.Bits.ELS1B
#define TPM2C1SC_MS1A                   _TPM2C1SC.Bits.MS1A
#define TPM2C1SC_MS1B                   _TPM2C1SC.Bits.MS1B
#define TPM2C1SC_CH1IE                  _TPM2C1SC.Bits.CH1IE
#define TPM2C1SC_CH1F                   _TPM2C1SC.Bits.CH1F
#define TPM2C1SC_ELS1x                  _TPM2C1SC.MergedBits.grpELS1x
#define TPM2C1SC_MS1x                   _TPM2C1SC.MergedBits.grpMS1x

#define TPM2C1SC_ELS1A_MASK             4U
#define TPM2C1SC_ELS1B_MASK             8U
#define TPM2C1SC_MS1A_MASK              16U
#define TPM2C1SC_MS1B_MASK              32U
#define TPM2C1SC_CH1IE_MASK             64U
#define TPM2C1SC_CH1F_MASK              128U
#define TPM2C1SC_ELS1x_MASK             12U
#define TPM2C1SC_ELS1x_BITNUM           2U
#define TPM2C1SC_MS1x_MASK              48U
#define TPM2C1SC_MS1x_BITNUM            4U


/*** TPM2C1V - TPM2 Timer Channel 1 Value Register; 0x00000069 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High; 0x00000069 ***/
    union {
      byte Byte;
    } TPM2C1VHSTR;
    #define TPM2C1VH                    _TPM2C1V.Overlap_STR.TPM2C1VHSTR.Byte
    

    /*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low; 0x0000006A ***/
    union {
      byte Byte;
    } TPM2C1VLSTR;
    #define TPM2C1VL                    _TPM2C1V.Overlap_STR.TPM2C1VLSTR.Byte
    
  } Overlap_STR;

} TPM2C1VSTR;
extern volatile TPM2C1VSTR _TPM2C1V @0x00000069;
#define TPM2C1V                         _TPM2C1V.Word


/*** RTCSC - RTC Status and Control Register; 0x0000006C ***/
typedef union {
  byte Byte;
  struct {
    byte RTCPS0      :1;                                       /* Real-Time Clock Prescaler Select, bit 0 */
    byte RTCPS1      :1;                                       /* Real-Time Clock Prescaler Select, bit 1 */
    byte RTCPS2      :1;                                       /* Real-Time Clock Prescaler Select, bit 2 */
    byte RTCPS3      :1;                                       /* Real-Time Clock Prescaler Select, bit 3 */
    byte RTIE        :1;                                       /* Real-Time Interrupt Enable */
    byte RTCLKS0     :1;                                       /* Real-Time Clock Source Select, bit 0 */
    byte RTCLKS1     :1;                                       /* Real-Time Clock Source Select, bit 1 */
    byte RTIF        :1;                                       /* Real-Time Interrupt Flag */
  } Bits;
  struct {
    byte grpRTCPS :4;
    byte         :1;
    byte grpRTCLKS :2;
    byte         :1;
  } MergedBits;
} RTCSCSTR;
extern volatile RTCSCSTR _RTCSC @0x0000006C;
#define RTCSC                           _RTCSC.Byte
#define RTCSC_RTCPS0                    _RTCSC.Bits.RTCPS0
#define RTCSC_RTCPS1                    _RTCSC.Bits.RTCPS1
#define RTCSC_RTCPS2                    _RTCSC.Bits.RTCPS2
#define RTCSC_RTCPS3                    _RTCSC.Bits.RTCPS3
#define RTCSC_RTIE                      _RTCSC.Bits.RTIE
#define RTCSC_RTCLKS0                   _RTCSC.Bits.RTCLKS0
#define RTCSC_RTCLKS1                   _RTCSC.Bits.RTCLKS1
#define RTCSC_RTIF                      _RTCSC.Bits.RTIF
#define RTCSC_RTCPS                     _RTCSC.MergedBits.grpRTCPS
#define RTCSC_RTCLKS                    _RTCSC.MergedBits.grpRTCLKS

#define RTCSC_RTCPS0_MASK               1U
#define RTCSC_RTCPS1_MASK               2U
#define RTCSC_RTCPS2_MASK               4U
#define RTCSC_RTCPS3_MASK               8U
#define RTCSC_RTIE_MASK                 16U
#define RTCSC_RTCLKS0_MASK              32U
#define RTCSC_RTCLKS1_MASK              64U
#define RTCSC_RTIF_MASK                 128U
#define RTCSC_RTCPS_MASK                15U
#define RTCSC_RTCPS_BITNUM              0U
#define RTCSC_RTCLKS_MASK               96U
#define RTCSC_RTCLKS_BITNUM             5U


/*** RTCCNT - RTC Counter Register; 0x0000006D ***/
typedef union {
  byte Byte;
} RTCCNTSTR;
extern volatile RTCCNTSTR _RTCCNT @0x0000006D;
#define RTCCNT                          _RTCCNT.Byte


/*** RTCMOD - RTC Modulo Register; 0x0000006E ***/
typedef union {
  byte Byte;
} RTCMODSTR;
extern volatile RTCMODSTR _RTCMOD @0x0000006E;
#define RTCMOD                          _RTCMOD.Byte


/*** SRS - System Reset Status Register; 0x00001800 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LVD         :1;                                       /* Low Voltage Detect */
    byte             :1; 
    byte ILAD        :1;                                       /* Illegal Address */
    byte ILOP        :1;                                       /* Illegal Opcode */
    byte COP         :1;                                       /* Computer Operating Properly (COP) Watchdog */
    byte PIN         :1;                                       /* External Reset Pin */
    byte POR         :1;                                       /* Power-On Reset */
  } Bits;
} SRSSTR;
extern volatile SRSSTR _SRS @0x00001800;
#define SRS                             _SRS.Byte
#define SRS_LVD                         _SRS.Bits.LVD
#define SRS_ILAD                        _SRS.Bits.ILAD
#define SRS_ILOP                        _SRS.Bits.ILOP
#define SRS_COP                         _SRS.Bits.COP
#define SRS_PIN                         _SRS.Bits.PIN
#define SRS_POR                         _SRS.Bits.POR

#define SRS_LVD_MASK                    2U
#define SRS_ILAD_MASK                   8U
#define SRS_ILOP_MASK                   16U
#define SRS_COP_MASK                    32U
#define SRS_PIN_MASK                    64U
#define SRS_POR_MASK                    128U


/*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***/
typedef union {
  byte Byte;
  struct {
    byte BDFR        :1;                                       /* Background Debug Force Reset */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SBDFRSTR;
extern volatile SBDFRSTR _SBDFR @0x00001801;
#define SBDFR                           _SBDFR.Byte
#define SBDFR_BDFR                      _SBDFR.Bits.BDFR

#define SBDFR_BDFR_MASK                 1U


/*** SOPT1 - System Options Register 1; 0x00001802 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte IICPS       :1;                                       /* IIC Pin Select */
    byte             :1; 
    byte             :1; 
    byte STOPE       :1;                                       /* Stop Mode Enable */
    byte COPT0       :1;                                       /* COP Watchdog Timeout, bit 0 */
    byte COPT1       :1;                                       /* COP Watchdog Timeout, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpCOPT :2;
  } MergedBits;
} SOPT1STR;
extern volatile SOPT1STR _SOPT1 @0x00001802;
#define SOPT1                           _SOPT1.Byte
#define SOPT1_IICPS                     _SOPT1.Bits.IICPS
#define SOPT1_STOPE                     _SOPT1.Bits.STOPE
#define SOPT1_COPT0                     _SOPT1.Bits.COPT0
#define SOPT1_COPT1                     _SOPT1.Bits.COPT1
#define SOPT1_COPT                      _SOPT1.MergedBits.grpCOPT

#define SOPT1_IICPS_MASK                4U
#define SOPT1_STOPE_MASK                32U
#define SOPT1_COPT0_MASK                64U
#define SOPT1_COPT1_MASK                128U
#define SOPT1_COPT_MASK                 192U
#define SOPT1_COPT_BITNUM               6U


/*** SOPT2 - System Options Register 2; 0x00001803 ***/
typedef union {
  byte Byte;
  struct {
    byte T1CH0PS     :1;                                       /* This bit selects the location of the TPM1CH0 pin of the TPM1 module */
    byte T1CH1PS     :1;                                       /* This bit selects the location of the TPM1CH1 pin of the TPM1 module */
    byte T2CH0PS     :1;                                       /* This bit selects the location of the TPM2CH0 pin of the TPM2 module */
    byte T2CH1PS     :1;                                       /* This bit selects the location of the TPM2CH1 pin of the TPM2 module */
    byte ACIC        :1;                                       /* Analog Comparator to Input Capture Enable */
    byte             :1; 
    byte COPW        :1;                                       /* COP Window */
    byte COPCLKS     :1;                                       /* COP Watchdog Clock Select */
  } Bits;
} SOPT2STR;
extern volatile SOPT2STR _SOPT2 @0x00001803;
#define SOPT2                           _SOPT2.Byte
#define SOPT2_T1CH0PS                   _SOPT2.Bits.T1CH0PS
#define SOPT2_T1CH1PS                   _SOPT2.Bits.T1CH1PS
#define SOPT2_T2CH0PS                   _SOPT2.Bits.T2CH0PS
#define SOPT2_T2CH1PS                   _SOPT2.Bits.T2CH1PS
#define SOPT2_ACIC                      _SOPT2.Bits.ACIC
#define SOPT2_COPW                      _SOPT2.Bits.COPW
#define SOPT2_COPCLKS                   _SOPT2.Bits.COPCLKS

#define SOPT2_T1CH0PS_MASK              1U
#define SOPT2_T1CH1PS_MASK              2U
#define SOPT2_T2CH0PS_MASK              4U
#define SOPT2_T2CH1PS_MASK              8U
#define SOPT2_ACIC_MASK                 16U
#define SOPT2_COPW_MASK                 64U
#define SOPT2_COPCLKS_MASK              128U


/*** SDID - System Device Identification Register; 0x00001806 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SDIDH - System Device Identification Register High; 0x00001806 ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part Identification Number, bit 8 */
        byte ID9         :1;                                       /* Part Identification Number, bit 9 */
        byte ID10        :1;                                       /* Part Identification Number, bit 10 */
        byte ID11        :1;                                       /* Part Identification Number, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpID_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SDIDHSTR;
    #define SDIDH                       _SDID.Overlap_STR.SDIDHSTR.Byte
    #define SDIDH_ID8                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID8
    #define SDIDH_ID9                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID9
    #define SDIDH_ID10                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID10
    #define SDIDH_ID11                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID11
    #define SDIDH_ID_8                  _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpID_8
    #define SDIDH_ID                    SDIDH_ID_8
    
    #define SDIDH_ID8_MASK              1U
    #define SDIDH_ID9_MASK              2U
    #define SDIDH_ID10_MASK             4U
    #define SDIDH_ID11_MASK             8U
    #define SDIDH_ID_8_MASK             15U
    #define SDIDH_ID_8_BITNUM           0U
    

    /*** SDIDL - System Device Identification Register Low; 0x00001807 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part Identification Number, bit 0 */
        byte ID1         :1;                                       /* Part Identification Number, bit 1 */
        byte ID2         :1;                                       /* Part Identification Number, bit 2 */
        byte ID3         :1;                                       /* Part Identification Number, bit 3 */
        byte ID4         :1;                                       /* Part Identification Number, bit 4 */
        byte ID5         :1;                                       /* Part Identification Number, bit 5 */
        byte ID6         :1;                                       /* Part Identification Number, bit 6 */
        byte ID7         :1;                                       /* Part Identification Number, bit 7 */
      } Bits;
    } SDIDLSTR;
    #define SDIDL                       _SDID.Overlap_STR.SDIDLSTR.Byte
    #define SDIDL_ID0                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID0
    #define SDIDL_ID1                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID1
    #define SDIDL_ID2                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID2
    #define SDIDL_ID3                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID3
    #define SDIDL_ID4                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID4
    #define SDIDL_ID5                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID5
    #define SDIDL_ID6                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID6
    #define SDIDL_ID7                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID7
    
    #define SDIDL_ID0_MASK              1U
    #define SDIDL_ID1_MASK              2U
    #define SDIDL_ID2_MASK              4U
    #define SDIDL_ID3_MASK              8U
    #define SDIDL_ID4_MASK              16U
    #define SDIDL_ID5_MASK              32U
    #define SDIDL_ID6_MASK              64U
    #define SDIDL_ID7_MASK              128U
    
  } Overlap_STR;

} SDIDSTR;
extern volatile SDIDSTR _SDID @0x00001806;
#define SDID                            _SDID.Word


/*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001809 ***/
typedef union {
  byte Byte;
  struct {
    byte BGBE        :1;                                       /* Bandgap Buffer Enable */
    byte             :1; 
    byte LVDE        :1;                                       /* Low-Voltage Detect Enable */
    byte LVDSE       :1;                                       /* Low-Voltage Detect Stop Enable */
    byte LVDRE       :1;                                       /* Low-Voltage Detect Reset Enable */
    byte LVWIE       :1;                                       /* Low-Voltage Warning Interrupt Enable */
    byte LVWACK      :1;                                       /* Low-Voltage Warning Acknowledge */
    byte LVWF        :1;                                       /* Low-Voltage Warning status */
  } Bits;
} SPMSC1STR;
extern volatile SPMSC1STR _SPMSC1 @0x00001809;
#define SPMSC1                          _SPMSC1.Byte
#define SPMSC1_BGBE                     _SPMSC1.Bits.BGBE
#define SPMSC1_LVDE                     _SPMSC1.Bits.LVDE
#define SPMSC1_LVDSE                    _SPMSC1.Bits.LVDSE
#define SPMSC1_LVDRE                    _SPMSC1.Bits.LVDRE
#define SPMSC1_LVWIE                    _SPMSC1.Bits.LVWIE
#define SPMSC1_LVWACK                   _SPMSC1.Bits.LVWACK
#define SPMSC1_LVWF                     _SPMSC1.Bits.LVWF

#define SPMSC1_BGBE_MASK                1U
#define SPMSC1_LVDE_MASK                4U
#define SPMSC1_LVDSE_MASK               8U
#define SPMSC1_LVDRE_MASK               16U
#define SPMSC1_LVWIE_MASK               32U
#define SPMSC1_LVWACK_MASK              64U
#define SPMSC1_LVWF_MASK                128U


/*** SPMSC2 - System Power Management Status and Control 2 Register; 0x0000180A ***/
typedef union {
  byte Byte;
  struct {
    byte PPDC        :1;                                       /* Partial Power Down Control */
    byte             :1; 
    byte PPDACK      :1;                                       /* Partial Power Down Acknowledge */
    byte PPDF        :1;                                       /* Partial Power Down Flag */
    byte LVWV        :1;                                       /* Low-Voltage Warning Voltage Select */
    byte LVDV        :1;                                       /* Low-Voltage Detect Voltage Select */
    byte             :1; 
    byte             :1; 
  } Bits;
} SPMSC2STR;
extern volatile SPMSC2STR _SPMSC2 @0x0000180A;
#define SPMSC2                          _SPMSC2.Byte
#define SPMSC2_PPDC                     _SPMSC2.Bits.PPDC
#define SPMSC2_PPDACK                   _SPMSC2.Bits.PPDACK
#define SPMSC2_PPDF                     _SPMSC2.Bits.PPDF
#define SPMSC2_LVWV                     _SPMSC2.Bits.LVWV
#define SPMSC2_LVDV                     _SPMSC2.Bits.LVDV

#define SPMSC2_PPDC_MASK                1U
#define SPMSC2_PPDACK_MASK              4U
#define SPMSC2_PPDF_MASK                8U
#define SPMSC2_LVWV_MASK                16U
#define SPMSC2_LVDV_MASK                32U


/*** DBGCA - Debug Comparator A Register; 0x00001810 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCAH - Debug Comparator A High Register; 0x00001810 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator A High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator A High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator A High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator A High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator A High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator A High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator A High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator A High Compare Bit 15 */
      } Bits;
    } DBGCAHSTR;
    #define DBGCAH                      _DBGCA.Overlap_STR.DBGCAHSTR.Byte
    #define DBGCAH_Bit8                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit8
    #define DBGCAH_Bit9                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit9
    #define DBGCAH_Bit10                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit10
    #define DBGCAH_Bit11                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit11
    #define DBGCAH_Bit12                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit12
    #define DBGCAH_Bit13                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit13
    #define DBGCAH_Bit14                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit14
    #define DBGCAH_Bit15                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit15
    
    #define DBGCAH_Bit8_MASK            1U
    #define DBGCAH_Bit9_MASK            2U
    #define DBGCAH_Bit10_MASK           4U
    #define DBGCAH_Bit11_MASK           8U
    #define DBGCAH_Bit12_MASK           16U
    #define DBGCAH_Bit13_MASK           32U
    #define DBGCAH_Bit14_MASK           64U
    #define DBGCAH_Bit15_MASK           128U
    

    /*** DBGCAL - Debug Comparator A Low Register; 0x00001811 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator A Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator A Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator A Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator A Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator A Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator A Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator A Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator A Low Compare Bit 7 */
      } Bits;
    } DBGCALSTR;
    #define DBGCAL                      _DBGCA.Overlap_STR.DBGCALSTR.Byte
    #define DBGCAL_Bit0                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit0
    #define DBGCAL_Bit1                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit1
    #define DBGCAL_Bit2                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit2
    #define DBGCAL_Bit3                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit3
    #define DBGCAL_Bit4                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit4
    #define DBGCAL_Bit5                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit5
    #define DBGCAL_Bit6                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit6
    #define DBGCAL_Bit7                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit7
    
    #define DBGCAL_Bit0_MASK            1U
    #define DBGCAL_Bit1_MASK            2U
    #define DBGCAL_Bit2_MASK            4U
    #define DBGCAL_Bit3_MASK            8U
    #define DBGCAL_Bit4_MASK            16U
    #define DBGCAL_Bit5_MASK            32U
    #define DBGCAL_Bit6_MASK            64U
    #define DBGCAL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCASTR;
extern volatile DBGCASTR _DBGCA @0x00001810;
#define DBGCA                           _DBGCA.Word


/*** DBGCB - Debug Comparator B Register; 0x00001812 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCBH - Debug Comparator B High Register; 0x00001812 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator B High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator B High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator B High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator B High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator B High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator B High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator B High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator B High Compare Bit 15 */
      } Bits;
    } DBGCBHSTR;
    #define DBGCBH                      _DBGCB.Overlap_STR.DBGCBHSTR.Byte
    #define DBGCBH_Bit8                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit8
    #define DBGCBH_Bit9                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit9
    #define DBGCBH_Bit10                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit10
    #define DBGCBH_Bit11                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit11
    #define DBGCBH_Bit12                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit12
    #define DBGCBH_Bit13                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit13
    #define DBGCBH_Bit14                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit14
    #define DBGCBH_Bit15                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit15
    
    #define DBGCBH_Bit8_MASK            1U
    #define DBGCBH_Bit9_MASK            2U
    #define DBGCBH_Bit10_MASK           4U
    #define DBGCBH_Bit11_MASK           8U
    #define DBGCBH_Bit12_MASK           16U
    #define DBGCBH_Bit13_MASK           32U
    #define DBGCBH_Bit14_MASK           64U
    #define DBGCBH_Bit15_MASK           128U
    

    /*** DBGCBL - Debug Comparator B Low Register; 0x00001813 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator B Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator B Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator B Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator B Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator B Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator B Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator B Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator B Low Compare Bit 7 */
      } Bits;
    } DBGCBLSTR;
    #define DBGCBL                      _DBGCB.Overlap_STR.DBGCBLSTR.Byte
    #define DBGCBL_Bit0                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit0
    #define DBGCBL_Bit1                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit1
    #define DBGCBL_Bit2                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit2
    #define DBGCBL_Bit3                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit3
    #define DBGCBL_Bit4                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit4
    #define DBGCBL_Bit5                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit5
    #define DBGCBL_Bit6                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit6
    #define DBGCBL_Bit7                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit7
    
    #define DBGCBL_Bit0_MASK            1U
    #define DBGCBL_Bit1_MASK            2U
    #define DBGCBL_Bit2_MASK            4U
    #define DBGCBL_Bit3_MASK            8U
    #define DBGCBL_Bit4_MASK            16U
    #define DBGCBL_Bit5_MASK            32U
    #define DBGCBL_Bit6_MASK            64U
    #define DBGCBL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCBSTR;
extern volatile DBGCBSTR _DBGCB @0x00001812;
#define DBGCB                           _DBGCB.Word


/*** DBGF - Debug FIFO Register; 0x00001814 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGFH - Debug FIFO High Register; 0x00001814 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* FIFO High Data Bit 8 */
        byte Bit9        :1;                                       /* FIFO High Data Bit 9 */
        byte Bit10       :1;                                       /* FIFO High Data Bit 10 */
        byte Bit11       :1;                                       /* FIFO High Data Bit 11 */
        byte Bit12       :1;                                       /* FIFO High Data Bit 12 */
        byte Bit13       :1;                                       /* FIFO High Data Bit 13 */
        byte Bit14       :1;                                       /* FIFO High Data Bit 14 */
        byte Bit15       :1;                                       /* FIFO High Data Bit 15 */
      } Bits;
    } DBGFHSTR;
    #define DBGFH                       _DBGF.Overlap_STR.DBGFHSTR.Byte
    #define DBGFH_Bit8                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit8
    #define DBGFH_Bit9                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit9
    #define DBGFH_Bit10                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit10
    #define DBGFH_Bit11                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit11
    #define DBGFH_Bit12                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit12
    #define DBGFH_Bit13                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit13
    #define DBGFH_Bit14                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit14
    #define DBGFH_Bit15                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit15
    
    #define DBGFH_Bit8_MASK             1U
    #define DBGFH_Bit9_MASK             2U
    #define DBGFH_Bit10_MASK            4U
    #define DBGFH_Bit11_MASK            8U
    #define DBGFH_Bit12_MASK            16U
    #define DBGFH_Bit13_MASK            32U
    #define DBGFH_Bit14_MASK            64U
    #define DBGFH_Bit15_MASK            128U
    

    /*** DBGFL - Debug FIFO Low Register; 0x00001815 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* FIFO Low Data Bit 0 */
        byte Bit1        :1;                                       /* FIFO Low Data Bit 1 */
        byte Bit2        :1;                                       /* FIFO Low Data Bit 2 */
        byte Bit3        :1;                                       /* FIFO Low Data Bit 3 */
        byte Bit4        :1;                                       /* FIFO Low Data Bit 4 */
        byte Bit5        :1;                                       /* FIFO Low Data Bit 5 */
        byte Bit6        :1;                                       /* FIFO Low Data Bit 6 */
        byte Bit7        :1;                                       /* FIFO Low Data Bit 7 */
      } Bits;
    } DBGFLSTR;
    #define DBGFL                       _DBGF.Overlap_STR.DBGFLSTR.Byte
    #define DBGFL_Bit0                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit0
    #define DBGFL_Bit1                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit1
    #define DBGFL_Bit2                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit2
    #define DBGFL_Bit3                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit3
    #define DBGFL_Bit4                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit4
    #define DBGFL_Bit5                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit5
    #define DBGFL_Bit6                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit6
    #define DBGFL_Bit7                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit7
    
    #define DBGFL_Bit0_MASK             1U
    #define DBGFL_Bit1_MASK             2U
    #define DBGFL_Bit2_MASK             4U
    #define DBGFL_Bit3_MASK             8U
    #define DBGFL_Bit4_MASK             16U
    #define DBGFL_Bit5_MASK             32U
    #define DBGFL_Bit6_MASK             64U
    #define DBGFL_Bit7_MASK             128U
    
  } Overlap_STR;

} DBGFSTR;
extern volatile DBGFSTR _DBGF @0x00001814;
#define DBGF                            _DBGF.Word


/*** DBGC - Debug Control Register; 0x00001816 ***/
typedef union {
  byte Byte;
  struct {
    byte RWBEN       :1;                                       /* Enable R/W for Comparator B */
    byte RWB         :1;                                       /* R/W Comparison Value for Comparator B */
    byte RWAEN       :1;                                       /* Enable R/W for Comparator A */
    byte RWA         :1;                                       /* R/W Comparison Value for Comparator A */
    byte BRKEN       :1;                                       /* Break Enable */
    byte TAG         :1;                                       /* Tag/Force Select */
    byte ARM         :1;                                       /* Arm Control */
    byte DBGEN       :1;                                       /* Debug Module Enable */
  } Bits;
} DBGCSTR;
extern volatile DBGCSTR _DBGC @0x00001816;
#define DBGC                            _DBGC.Byte
#define DBGC_RWBEN                      _DBGC.Bits.RWBEN
#define DBGC_RWB                        _DBGC.Bits.RWB
#define DBGC_RWAEN                      _DBGC.Bits.RWAEN
#define DBGC_RWA                        _DBGC.Bits.RWA
#define DBGC_BRKEN                      _DBGC.Bits.BRKEN
#define DBGC_TAG                        _DBGC.Bits.TAG
#define DBGC_ARM                        _DBGC.Bits.ARM
#define DBGC_DBGEN                      _DBGC.Bits.DBGEN

#define DBGC_RWBEN_MASK                 1U
#define DBGC_RWB_MASK                   2U
#define DBGC_RWAEN_MASK                 4U
#define DBGC_RWA_MASK                   8U
#define DBGC_BRKEN_MASK                 16U
#define DBGC_TAG_MASK                   32U
#define DBGC_ARM_MASK                   64U
#define DBGC_DBGEN_MASK                 128U


/*** DBGT - Debug Trigger Register; 0x00001817 ***/
typedef union {
  byte Byte;
  struct {
    byte TRG0        :1;                                       /* Select Trigger Mode Bit 0 */
    byte TRG1        :1;                                       /* Select Trigger Mode Bit 1 */
    byte TRG2        :1;                                       /* Select Trigger Mode Bit 2 */
    byte TRG3        :1;                                       /* Select Trigger Mode Bit 3 */
    byte             :1; 
    byte             :1; 
    byte BEGIN       :1;                                       /* Begin/End Trigger Select */
    byte TRGSEL      :1;                                       /* Trigger Type */
  } Bits;
  struct {
    byte grpTRG  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGTSTR;
extern volatile DBGTSTR _DBGT @0x00001817;
#define DBGT                            _DBGT.Byte
#define DBGT_TRG0                       _DBGT.Bits.TRG0
#define DBGT_TRG1                       _DBGT.Bits.TRG1
#define DBGT_TRG2                       _DBGT.Bits.TRG2
#define DBGT_TRG3                       _DBGT.Bits.TRG3
#define DBGT_BEGIN                      _DBGT.Bits.BEGIN
#define DBGT_TRGSEL                     _DBGT.Bits.TRGSEL
#define DBGT_TRG                        _DBGT.MergedBits.grpTRG

#define DBGT_TRG0_MASK                  1U
#define DBGT_TRG1_MASK                  2U
#define DBGT_TRG2_MASK                  4U
#define DBGT_TRG3_MASK                  8U
#define DBGT_BEGIN_MASK                 64U
#define DBGT_TRGSEL_MASK                128U
#define DBGT_TRG_MASK                   15U
#define DBGT_TRG_BITNUM                 0U


/*** DBGS - Debug Status Register; 0x00001818 ***/
typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       /* FIFO Valid Count Bit 0 */
    byte CNT1        :1;                                       /* FIFO Valid Count Bit 1 */
    byte CNT2        :1;                                       /* FIFO Valid Count Bit 2 */
    byte CNT3        :1;                                       /* FIFO Valid Count Bit 3 */
    byte             :1; 
    byte ARMF        :1;                                       /* Arm Flag */
    byte BF          :1;                                       /* Trigger Match B Flag */
    byte AF          :1;                                       /* Trigger Match A Flag */
  } Bits;
  struct {
    byte grpCNT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGSSTR;
extern volatile DBGSSTR _DBGS @0x00001818;
#define DBGS                            _DBGS.Byte
#define DBGS_CNT0                       _DBGS.Bits.CNT0
#define DBGS_CNT1                       _DBGS.Bits.CNT1
#define DBGS_CNT2                       _DBGS.Bits.CNT2
#define DBGS_CNT3                       _DBGS.Bits.CNT3
#define DBGS_ARMF                       _DBGS.Bits.ARMF
#define DBGS_BF                         _DBGS.Bits.BF
#define DBGS_AF                         _DBGS.Bits.AF
#define DBGS_CNT                        _DBGS.MergedBits.grpCNT

#define DBGS_CNT0_MASK                  1U
#define DBGS_CNT1_MASK                  2U
#define DBGS_CNT2_MASK                  4U
#define DBGS_CNT3_MASK                  8U
#define DBGS_ARMF_MASK                  32U
#define DBGS_BF_MASK                    64U
#define DBGS_AF_MASK                    128U
#define DBGS_CNT_MASK                   15U
#define DBGS_CNT_BITNUM                 0U


/*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***/
typedef union {
  byte Byte;
  struct {
    byte DIV0        :1;                                       /* Divisor for FLASH Clock Divider, bit 0 */
    byte DIV1        :1;                                       /* Divisor for FLASH Clock Divider, bit 1 */
    byte DIV2        :1;                                       /* Divisor for FLASH Clock Divider, bit 2 */
    byte DIV3        :1;                                       /* Divisor for FLASH Clock Divider, bit 3 */
    byte DIV4        :1;                                       /* Divisor for FLASH Clock Divider, bit 4 */
    byte DIV5        :1;                                       /* Divisor for FLASH Clock Divider, bit 5 */
    byte PRDIV8      :1;                                       /* Prescale (Divide) FLASH Clock by 8 */
    byte DIVLD       :1;                                       /* Divisor Loaded Status Flag */
  } Bits;
  struct {
    byte grpDIV  :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCDIVSTR;
extern volatile FCDIVSTR _FCDIV @0x00001820;
#define FCDIV                           _FCDIV.Byte
#define FCDIV_DIV0                      _FCDIV.Bits.DIV0
#define FCDIV_DIV1                      _FCDIV.Bits.DIV1
#define FCDIV_DIV2                      _FCDIV.Bits.DIV2
#define FCDIV_DIV3                      _FCDIV.Bits.DIV3
#define FCDIV_DIV4                      _FCDIV.Bits.DIV4
#define FCDIV_DIV5                      _FCDIV.Bits.DIV5
#define FCDIV_PRDIV8                    _FCDIV.Bits.PRDIV8
#define FCDIV_DIVLD                     _FCDIV.Bits.DIVLD
#define FCDIV_DIV                       _FCDIV.MergedBits.grpDIV

#define FCDIV_DIV0_MASK                 1U
#define FCDIV_DIV1_MASK                 2U
#define FCDIV_DIV2_MASK                 4U
#define FCDIV_DIV3_MASK                 8U
#define FCDIV_DIV4_MASK                 16U
#define FCDIV_DIV5_MASK                 32U
#define FCDIV_PRDIV8_MASK               64U
#define FCDIV_DIVLD_MASK                128U
#define FCDIV_DIV_MASK                  63U
#define FCDIV_DIV_BITNUM                0U


/*** FOPT - FLASH Options Register; 0x00001821 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC00       :1;                                       /* Security State Code, bit 0 */
    byte SEC01       :1;                                       /* Security State Code, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FNORED      :1;                                       /* Vector Redirection Disable */
    byte KEYEN       :1;                                       /* Backdoor Key Mechanism Enable */
  } Bits;
  struct {
    byte grpSEC0 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @0x00001821;
#define FOPT                            _FOPT.Byte
#define FOPT_SEC00                      _FOPT.Bits.SEC00
#define FOPT_SEC01                      _FOPT.Bits.SEC01
#define FOPT_FNORED                     _FOPT.Bits.FNORED
#define FOPT_KEYEN                      _FOPT.Bits.KEYEN
#define FOPT_SEC0                       _FOPT.MergedBits.grpSEC0

#define FOPT_SEC00_MASK                 1U
#define FOPT_SEC01_MASK                 2U
#define FOPT_FNORED_MASK                64U
#define FOPT_KEYEN_MASK                 128U
#define FOPT_SEC0_MASK                  3U
#define FOPT_SEC0_BITNUM                0U


/*** FCNFG - FLASH Configuration Register; 0x00001823 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       /* Enable Writing of Access Key */
    byte             :1; 
    byte             :1; 
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @0x00001823;
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC

#define FCNFG_KEYACC_MASK               32U


/*** FPROT - FLASH Protection Register; 0x00001824 ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* FLASH Protection Disable */
    byte FPS1        :1;                                       /* FLASH Protect Select Bit 1 */
    byte FPS2        :1;                                       /* FLASH Protect Select Bit 2 */
    byte FPS3        :1;                                       /* FLASH Protect Select Bit 3 */
    byte FPS4        :1;                                       /* FLASH Protect Select Bit 4 */
    byte FPS5        :1;                                       /* FLASH Protect Select Bit 5 */
    byte FPS6        :1;                                       /* FLASH Protect Select Bit 6 */
    byte FPS7        :1;                                       /* FLASH Protect Select Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS_1 :7;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @0x00001824;
#define FPROT                           _FPROT.Byte
#define FPROT_FPDIS                     _FPROT.Bits.FPDIS
#define FPROT_FPS1                      _FPROT.Bits.FPS1
#define FPROT_FPS2                      _FPROT.Bits.FPS2
#define FPROT_FPS3                      _FPROT.Bits.FPS3
#define FPROT_FPS4                      _FPROT.Bits.FPS4
#define FPROT_FPS5                      _FPROT.Bits.FPS5
#define FPROT_FPS6                      _FPROT.Bits.FPS6
#define FPROT_FPS7                      _FPROT.Bits.FPS7
#define FPROT_FPS_1                     _FPROT.MergedBits.grpFPS_1
#define FPROT_FPS                       FPROT_FPS_1

#define FPROT_FPDIS_MASK                1U
#define FPROT_FPS1_MASK                 2U
#define FPROT_FPS2_MASK                 4U
#define FPROT_FPS3_MASK                 8U
#define FPROT_FPS4_MASK                 16U
#define FPROT_FPS5_MASK                 32U
#define FPROT_FPS6_MASK                 64U
#define FPROT_FPS7_MASK                 128U
#define FPROT_FPS_1_MASK                254U
#define FPROT_FPS_1_BITNUM              1U


/*** FSTAT - Flash Status Register; 0x00001825 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte FBLANK      :1;                                       /* FLASH Flag Indicating the Erase Verify Operation Status */
    byte             :1; 
    byte FACCERR     :1;                                       /* FLASH Access Error Flag */
    byte FPVIOL      :1;                                       /* FLASH Protection Violation Flag */
    byte FCCF        :1;                                       /* FLASH Command Complete Interrupt Flag */
    byte FCBEF       :1;                                       /* FLASH Command Buffer Empty Flag */
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @0x00001825;
#define FSTAT                           _FSTAT.Byte
#define FSTAT_FBLANK                    _FSTAT.Bits.FBLANK
#define FSTAT_FACCERR                   _FSTAT.Bits.FACCERR
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_FCCF                      _FSTAT.Bits.FCCF
#define FSTAT_FCBEF                     _FSTAT.Bits.FCBEF

#define FSTAT_FBLANK_MASK               4U
#define FSTAT_FACCERR_MASK              16U
#define FSTAT_FPVIOL_MASK               32U
#define FSTAT_FCCF_MASK                 64U
#define FSTAT_FCBEF_MASK                128U


/*** FCMD - FLASH Command Register; 0x00001826 ***/
typedef union {
  byte Byte;
  struct {
    byte FCMD0       :1;                                       /* FLASH Command Bit 0 */
    byte FCMD1       :1;                                       /* FLASH Command Bit 1 */
    byte FCMD2       :1;                                       /* FLASH Command Bit 2 */
    byte FCMD3       :1;                                       /* FLASH Command Bit 3 */
    byte FCMD4       :1;                                       /* FLASH Command Bit 4 */
    byte FCMD5       :1;                                       /* FLASH Command Bit 5 */
    byte FCMD6       :1;                                       /* FLASH Command Bit 6 */
    byte FCMD7       :1;                                       /* FLASH Command Bit 7 */
  } Bits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD @0x00001826;
#define FCMD                            _FCMD.Byte
#define FCMD_FCMD0                      _FCMD.Bits.FCMD0
#define FCMD_FCMD1                      _FCMD.Bits.FCMD1
#define FCMD_FCMD2                      _FCMD.Bits.FCMD2
#define FCMD_FCMD3                      _FCMD.Bits.FCMD3
#define FCMD_FCMD4                      _FCMD.Bits.FCMD4
#define FCMD_FCMD5                      _FCMD.Bits.FCMD5
#define FCMD_FCMD6                      _FCMD.Bits.FCMD6
#define FCMD_FCMD7                      _FCMD.Bits.FCMD7

#define FCMD_FCMD0_MASK                 1U
#define FCMD_FCMD1_MASK                 2U
#define FCMD_FCMD2_MASK                 4U
#define FCMD_FCMD3_MASK                 8U
#define FCMD_FCMD4_MASK                 16U
#define FCMD_FCMD5_MASK                 32U
#define FCMD_FCMD6_MASK                 64U
#define FCMD_FCMD7_MASK                 128U


/*** PTAPE - Port A Pull Enable Register; 0x00001840 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAPE0      :1;                                       /* Internal Pull Enable for Port A Bit 0 */
    byte PTAPE1      :1;                                       /* Internal Pull Enable for Port A Bit 1 */
    byte PTAPE2      :1;                                       /* Internal Pull Enable for Port A Bit 2 */
    byte PTAPE3      :1;                                       /* Internal Pull Enable for Port A Bit 3 */
    byte             :1; 
    byte             :1; 
    byte PTAPE6      :1;                                       /* Internal Pull Enable for Port A Bit 6 */
    byte PTAPE7      :1;                                       /* Internal Pull Enable for Port A Bit 7 */
  } Bits;
  struct {
    byte grpPTAPE :4;
    byte         :1;
    byte         :1;
    byte grpPTAPE_6 :2;
  } MergedBits;
} PTAPESTR;
extern volatile PTAPESTR _PTAPE @0x00001840;
#define PTAPE                           _PTAPE.Byte
#define PTAPE_PTAPE0                    _PTAPE.Bits.PTAPE0
#define PTAPE_PTAPE1                    _PTAPE.Bits.PTAPE1
#define PTAPE_PTAPE2                    _PTAPE.Bits.PTAPE2
#define PTAPE_PTAPE3                    _PTAPE.Bits.PTAPE3
#define PTAPE_PTAPE6                    _PTAPE.Bits.PTAPE6
#define PTAPE_PTAPE7                    _PTAPE.Bits.PTAPE7
#define PTAPE_PTAPE                     _PTAPE.MergedBits.grpPTAPE
#define PTAPE_PTAPE_6                   _PTAPE.MergedBits.grpPTAPE_6

#define PTAPE_PTAPE0_MASK               1U
#define PTAPE_PTAPE1_MASK               2U
#define PTAPE_PTAPE2_MASK               4U
#define PTAPE_PTAPE3_MASK               8U
#define PTAPE_PTAPE6_MASK               64U
#define PTAPE_PTAPE7_MASK               128U
#define PTAPE_PTAPE_MASK                15U
#define PTAPE_PTAPE_BITNUM              0U
#define PTAPE_PTAPE_6_MASK              192U
#define PTAPE_PTAPE_6_BITNUM            6U


/*** PTASE - Port A Slew Rate Enable Register; 0x00001841 ***/
typedef union {
  byte Byte;
  struct {
    byte PTASE0      :1;                                       /* Output Slew Rate Enable for Port A Bit 0 */
    byte PTASE1      :1;                                       /* Output Slew Rate Enable for Port A Bit 1 */
    byte PTASE2      :1;                                       /* Output Slew Rate Enable for Port A Bit 2 */
    byte PTASE3      :1;                                       /* Output Slew Rate Enable for Port A Bit 3 */
    byte             :1; 
    byte             :1; 
    byte PTASE6      :1;                                       /* Output Slew Rate Enable for Port A Bit 6 */
    byte PTASE7      :1;                                       /* Output Slew Rate Enable for Port A Bit 7 */
  } Bits;
  struct {
    byte grpPTASE :4;
    byte         :1;
    byte         :1;
    byte grpPTASE_6 :2;
  } MergedBits;
} PTASESTR;
extern volatile PTASESTR _PTASE @0x00001841;
#define PTASE                           _PTASE.Byte
#define PTASE_PTASE0                    _PTASE.Bits.PTASE0
#define PTASE_PTASE1                    _PTASE.Bits.PTASE1
#define PTASE_PTASE2                    _PTASE.Bits.PTASE2
#define PTASE_PTASE3                    _PTASE.Bits.PTASE3
#define PTASE_PTASE6                    _PTASE.Bits.PTASE6
#define PTASE_PTASE7                    _PTASE.Bits.PTASE7
#define PTASE_PTASE                     _PTASE.MergedBits.grpPTASE
#define PTASE_PTASE_6                   _PTASE.MergedBits.grpPTASE_6

#define PTASE_PTASE0_MASK               1U
#define PTASE_PTASE1_MASK               2U
#define PTASE_PTASE2_MASK               4U
#define PTASE_PTASE3_MASK               8U
#define PTASE_PTASE6_MASK               64U
#define PTASE_PTASE7_MASK               128U
#define PTASE_PTASE_MASK                15U
#define PTASE_PTASE_BITNUM              0U
#define PTASE_PTASE_6_MASK              192U
#define PTASE_PTASE_6_BITNUM            6U


/*** PTADS - Port A Drive Strength Selection Register; 0x00001842 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADS0      :1;                                       /* Output Drive Strength Selection for Port A Bit 0 */
    byte PTADS1      :1;                                       /* Output Drive Strength Selection for Port A Bit 1 */
    byte PTADS2      :1;                                       /* Output Drive Strength Selection for Port A Bit 2 */
    byte PTADS3      :1;                                       /* Output Drive Strength Selection for Port A Bit 3 */
    byte             :1; 
    byte             :1; 
    byte PTADS6      :1;                                       /* Output Drive Strength Selection for Port A Bit 6 */
    byte PTADS7      :1;                                       /* Output Drive Strength Selection for Port A Bit 7 */
  } Bits;
  struct {
    byte grpPTADS :4;
    byte         :1;
    byte         :1;
    byte grpPTADS_6 :2;
  } MergedBits;
} PTADSSTR;
extern volatile PTADSSTR _PTADS @0x00001842;
#define PTADS                           _PTADS.Byte
#define PTADS_PTADS0                    _PTADS.Bits.PTADS0
#define PTADS_PTADS1                    _PTADS.Bits.PTADS1
#define PTADS_PTADS2                    _PTADS.Bits.PTADS2
#define PTADS_PTADS3                    _PTADS.Bits.PTADS3
#define PTADS_PTADS6                    _PTADS.Bits.PTADS6
#define PTADS_PTADS7                    _PTADS.Bits.PTADS7
#define PTADS_PTADS                     _PTADS.MergedBits.grpPTADS
#define PTADS_PTADS_6                   _PTADS.MergedBits.grpPTADS_6

#define PTADS_PTADS0_MASK               1U
#define PTADS_PTADS1_MASK               2U
#define PTADS_PTADS2_MASK               4U
#define PTADS_PTADS3_MASK               8U
#define PTADS_PTADS6_MASK               64U
#define PTADS_PTADS7_MASK               128U
#define PTADS_PTADS_MASK                15U
#define PTADS_PTADS_BITNUM              0U
#define PTADS_PTADS_6_MASK              192U
#define PTADS_PTADS_6_BITNUM            6U


/*** PTASC - Port A Interrupt Status and Control Register; 0x00001844 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAMOD      :1;                                       /* Port A Detection Mode */
    byte PTAIE       :1;                                       /* Port A Interrupt Enable */
    byte PTAACK      :1;                                       /* Port A Interrupt Acknowledge */
    byte PTAIF       :1;                                       /* Port A Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PTASCSTR;
extern volatile PTASCSTR _PTASC @0x00001844;
#define PTASC                           _PTASC.Byte
#define PTASC_PTAMOD                    _PTASC.Bits.PTAMOD
#define PTASC_PTAIE                     _PTASC.Bits.PTAIE
#define PTASC_PTAACK                    _PTASC.Bits.PTAACK
#define PTASC_PTAIF                     _PTASC.Bits.PTAIF

#define PTASC_PTAMOD_MASK               1U
#define PTASC_PTAIE_MASK                2U
#define PTASC_PTAACK_MASK               4U
#define PTASC_PTAIF_MASK                8U


/*** PTAPS - Port A Interrupt Pin Select Register; 0x00001845 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAPS0      :1;                                       /* Port A Interrupt Pin Select Bit 0 */
    byte PTAPS1      :1;                                       /* Port A Interrupt Pin Select Bit 1 */
    byte PTAPS2      :1;                                       /* Port A Interrupt Pin Select Bit 2 */
    byte PTAPS3      :1;                                       /* Port A Interrupt Pin Select Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTAPS :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTAPSSTR;
extern volatile PTAPSSTR _PTAPS @0x00001845;
#define PTAPS                           _PTAPS.Byte
#define PTAPS_PTAPS0                    _PTAPS.Bits.PTAPS0
#define PTAPS_PTAPS1                    _PTAPS.Bits.PTAPS1
#define PTAPS_PTAPS2                    _PTAPS.Bits.PTAPS2
#define PTAPS_PTAPS3                    _PTAPS.Bits.PTAPS3
#define PTAPS_PTAPS                     _PTAPS.MergedBits.grpPTAPS

#define PTAPS_PTAPS0_MASK               1U
#define PTAPS_PTAPS1_MASK               2U
#define PTAPS_PTAPS2_MASK               4U
#define PTAPS_PTAPS3_MASK               8U
#define PTAPS_PTAPS_MASK                15U
#define PTAPS_PTAPS_BITNUM              0U


/*** PTAES - Port A Interrupt Edge Select Register; 0x00001846 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAES0      :1;                                       /* Port A Edge Select Bit 0 */
    byte PTAES1      :1;                                       /* Port A Edge Select Bit 1 */
    byte PTAES2      :1;                                       /* Port A Edge Select Bit 2 */
    byte PTAES3      :1;                                       /* Port A Edge Select Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTAES :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTAESSTR;
extern volatile PTAESSTR _PTAES @0x00001846;
#define PTAES                           _PTAES.Byte
#define PTAES_PTAES0                    _PTAES.Bits.PTAES0
#define PTAES_PTAES1                    _PTAES.Bits.PTAES1
#define PTAES_PTAES2                    _PTAES.Bits.PTAES2
#define PTAES_PTAES3                    _PTAES.Bits.PTAES3
#define PTAES_PTAES                     _PTAES.MergedBits.grpPTAES

#define PTAES_PTAES0_MASK               1U
#define PTAES_PTAES1_MASK               2U
#define PTAES_PTAES2_MASK               4U
#define PTAES_PTAES3_MASK               8U
#define PTAES_PTAES_MASK                15U
#define PTAES_PTAES_BITNUM              0U


/*** PTBPE - Port B Pull Enable Register; 0x00001848 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBPE0      :1;                                       /* Internal Pull Enable for Port B Bit 0 */
    byte PTBPE1      :1;                                       /* Internal Pull Enable for Port B Bit 1 */
    byte PTBPE2      :1;                                       /* Internal Pull Enable for Port B Bit 2 */
    byte PTBPE3      :1;                                       /* Internal Pull Enable for Port B Bit 3 */
    byte PTBPE4      :1;                                       /* Internal Pull Enable for Port B Bit 4 */
    byte PTBPE5      :1;                                       /* Internal Pull Enable for Port B Bit 5 */
    byte PTBPE6      :1;                                       /* Internal Pull Enable for Port B Bit 6 */
    byte PTBPE7      :1;                                       /* Internal Pull Enable for Port B Bit 7 */
  } Bits;
} PTBPESTR;
extern volatile PTBPESTR _PTBPE @0x00001848;
#define PTBPE                           _PTBPE.Byte
#define PTBPE_PTBPE0                    _PTBPE.Bits.PTBPE0
#define PTBPE_PTBPE1                    _PTBPE.Bits.PTBPE1
#define PTBPE_PTBPE2                    _PTBPE.Bits.PTBPE2
#define PTBPE_PTBPE3                    _PTBPE.Bits.PTBPE3
#define PTBPE_PTBPE4                    _PTBPE.Bits.PTBPE4
#define PTBPE_PTBPE5                    _PTBPE.Bits.PTBPE5
#define PTBPE_PTBPE6                    _PTBPE.Bits.PTBPE6
#define PTBPE_PTBPE7                    _PTBPE.Bits.PTBPE7

#define PTBPE_PTBPE0_MASK               1U
#define PTBPE_PTBPE1_MASK               2U
#define PTBPE_PTBPE2_MASK               4U
#define PTBPE_PTBPE3_MASK               8U
#define PTBPE_PTBPE4_MASK               16U
#define PTBPE_PTBPE5_MASK               32U
#define PTBPE_PTBPE6_MASK               64U
#define PTBPE_PTBPE7_MASK               128U


/*** PTBSE - Port B Slew Rate Enable Register; 0x00001849 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBSE0      :1;                                       /* Output Slew Rate Enable for Port B Bit 0 */
    byte PTBSE1      :1;                                       /* Output Slew Rate Enable for Port B Bit 1 */
    byte PTBSE2      :1;                                       /* Output Slew Rate Enable for Port B Bit 2 */
    byte PTBSE3      :1;                                       /* Output Slew Rate Enable for Port B Bit 3 */
    byte PTBSE4      :1;                                       /* Output Slew Rate Enable for Port B Bit 4 */
    byte PTBSE5      :1;                                       /* Output Slew Rate Enable for Port B Bit 5 */
    byte PTBSE6      :1;                                       /* Output Slew Rate Enable for Port B Bit 6 */
    byte PTBSE7      :1;                                       /* Output Slew Rate Enable for Port B Bit 7 */
  } Bits;
} PTBSESTR;
extern volatile PTBSESTR _PTBSE @0x00001849;
#define PTBSE                           _PTBSE.Byte
#define PTBSE_PTBSE0                    _PTBSE.Bits.PTBSE0
#define PTBSE_PTBSE1                    _PTBSE.Bits.PTBSE1
#define PTBSE_PTBSE2                    _PTBSE.Bits.PTBSE2
#define PTBSE_PTBSE3                    _PTBSE.Bits.PTBSE3
#define PTBSE_PTBSE4                    _PTBSE.Bits.PTBSE4
#define PTBSE_PTBSE5                    _PTBSE.Bits.PTBSE5
#define PTBSE_PTBSE6                    _PTBSE.Bits.PTBSE6
#define PTBSE_PTBSE7                    _PTBSE.Bits.PTBSE7

#define PTBSE_PTBSE0_MASK               1U
#define PTBSE_PTBSE1_MASK               2U
#define PTBSE_PTBSE2_MASK               4U
#define PTBSE_PTBSE3_MASK               8U
#define PTBSE_PTBSE4_MASK               16U
#define PTBSE_PTBSE5_MASK               32U
#define PTBSE_PTBSE6_MASK               64U
#define PTBSE_PTBSE7_MASK               128U


/*** PTBDS - Port B Drive Strength Selection Register; 0x0000184A ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDS0      :1;                                       /* Output Drive Strength Selection for Port B Bit 0 */
    byte PTBDS1      :1;                                       /* Output Drive Strength Selection for Port B Bit 1 */
    byte PTBDS2      :1;                                       /* Output Drive Strength Selection for Port B Bit 2 */
    byte PTBDS3      :1;                                       /* Output Drive Strength Selection for Port B Bit 3 */
    byte PTBDS4      :1;                                       /* Output Drive Strength Selection for Port B Bit 4 */
    byte PTBDS5      :1;                                       /* Output Drive Strength Selection for Port B Bit 5 */
    byte PTBDS6      :1;                                       /* Output Drive Strength Selection for Port B Bit 6 */
    byte PTBDS7      :1;                                       /* Output Drive Strength Selection for Port B Bit 7 */
  } Bits;
} PTBDSSTR;
extern volatile PTBDSSTR _PTBDS @0x0000184A;
#define PTBDS                           _PTBDS.Byte
#define PTBDS_PTBDS0                    _PTBDS.Bits.PTBDS0
#define PTBDS_PTBDS1                    _PTBDS.Bits.PTBDS1
#define PTBDS_PTBDS2                    _PTBDS.Bits.PTBDS2
#define PTBDS_PTBDS3                    _PTBDS.Bits.PTBDS3
#define PTBDS_PTBDS4                    _PTBDS.Bits.PTBDS4
#define PTBDS_PTBDS5                    _PTBDS.Bits.PTBDS5
#define PTBDS_PTBDS6                    _PTBDS.Bits.PTBDS6
#define PTBDS_PTBDS7                    _PTBDS.Bits.PTBDS7

#define PTBDS_PTBDS0_MASK               1U
#define PTBDS_PTBDS1_MASK               2U
#define PTBDS_PTBDS2_MASK               4U
#define PTBDS_PTBDS3_MASK               8U
#define PTBDS_PTBDS4_MASK               16U
#define PTBDS_PTBDS5_MASK               32U
#define PTBDS_PTBDS6_MASK               64U
#define PTBDS_PTBDS7_MASK               128U


/*** PTBSC - Port B Interrupt Status and Control Register; 0x0000184C ***/
typedef union {
  byte Byte;
  struct {
    byte PTBMOD      :1;                                       /* Port B Detection Mode */
    byte PTBIE       :1;                                       /* Port B Interrupt Enable */
    byte PTBACK      :1;                                       /* Port B Interrupt Acknowledge */
    byte PTBIF       :1;                                       /* Port B Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PTBSCSTR;
extern volatile PTBSCSTR _PTBSC @0x0000184C;
#define PTBSC                           _PTBSC.Byte
#define PTBSC_PTBMOD                    _PTBSC.Bits.PTBMOD
#define PTBSC_PTBIE                     _PTBSC.Bits.PTBIE
#define PTBSC_PTBACK                    _PTBSC.Bits.PTBACK
#define PTBSC_PTBIF                     _PTBSC.Bits.PTBIF

#define PTBSC_PTBMOD_MASK               1U
#define PTBSC_PTBIE_MASK                2U
#define PTBSC_PTBACK_MASK               4U
#define PTBSC_PTBIF_MASK                8U


/*** PTBPS - Port B Interrupt Pin Select Register; 0x0000184D ***/
typedef union {
  byte Byte;
  struct {
    byte PTBPS0      :1;                                       /* Port B Interrupt Pin Select Bit 0 */
    byte PTBPS1      :1;                                       /* Port B Interrupt Pin Select Bit 1 */
    byte PTBPS2      :1;                                       /* Port B Interrupt Pin Select Bit 2 */
    byte PTBPS3      :1;                                       /* Port B Interrupt Pin Select Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTBPS :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTBPSSTR;
extern volatile PTBPSSTR _PTBPS @0x0000184D;
#define PTBPS                           _PTBPS.Byte
#define PTBPS_PTBPS0                    _PTBPS.Bits.PTBPS0
#define PTBPS_PTBPS1                    _PTBPS.Bits.PTBPS1
#define PTBPS_PTBPS2                    _PTBPS.Bits.PTBPS2
#define PTBPS_PTBPS3                    _PTBPS.Bits.PTBPS3
#define PTBPS_PTBPS                     _PTBPS.MergedBits.grpPTBPS

#define PTBPS_PTBPS0_MASK               1U
#define PTBPS_PTBPS1_MASK               2U
#define PTBPS_PTBPS2_MASK               4U
#define PTBPS_PTBPS3_MASK               8U
#define PTBPS_PTBPS_MASK                15U
#define PTBPS_PTBPS_BITNUM              0U


/*** PTBES - Port B Interrupt Edge Select Register; 0x0000184E ***/
typedef union {
  byte Byte;
  struct {
    byte PTBES0      :1;                                       /* Port B Edge Select Bit 0 */
    byte PTBES1      :1;                                       /* Port B Edge Select Bit 1 */
    byte PTBES2      :1;                                       /* Port B Edge Select Bit 2 */
    byte PTBES3      :1;                                       /* Port B Edge Select Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTBES :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTBESSTR;
extern volatile PTBESSTR _PTBES @0x0000184E;
#define PTBES                           _PTBES.Byte
#define PTBES_PTBES0                    _PTBES.Bits.PTBES0
#define PTBES_PTBES1                    _PTBES.Bits.PTBES1
#define PTBES_PTBES2                    _PTBES.Bits.PTBES2
#define PTBES_PTBES3                    _PTBES.Bits.PTBES3
#define PTBES_PTBES                     _PTBES.MergedBits.grpPTBES

#define PTBES_PTBES0_MASK               1U
#define PTBES_PTBES1_MASK               2U
#define PTBES_PTBES2_MASK               4U
#define PTBES_PTBES3_MASK               8U
#define PTBES_PTBES_MASK                15U
#define PTBES_PTBES_BITNUM              0U


/*** PTCPE - Port C Pull Enable Register; 0x00001850 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCPE0      :1;                                       /* Internal Pull Enable for Port C Bit 0 */
    byte PTCPE1      :1;                                       /* Internal Pull Enable for Port C Bit 1 */
    byte PTCPE2      :1;                                       /* Internal Pull Enable for Port C Bit 2 */
    byte PTCPE3      :1;                                       /* Internal Pull Enable for Port C Bit 3 */
    byte PTCPE4      :1;                                       /* Internal Pull Enable for Port C Bit 4 */
    byte PTCPE5      :1;                                       /* Internal Pull Enable for Port C Bit 5 */
    byte PTCPE6      :1;                                       /* Internal Pull Enable for Port C Bit 6 */
    byte PTCPE7      :1;                                       /* Internal Pull Enable for Port C Bit 7 */
  } Bits;
} PTCPESTR;
extern volatile PTCPESTR _PTCPE @0x00001850;
#define PTCPE                           _PTCPE.Byte
#define PTCPE_PTCPE0                    _PTCPE.Bits.PTCPE0
#define PTCPE_PTCPE1                    _PTCPE.Bits.PTCPE1
#define PTCPE_PTCPE2                    _PTCPE.Bits.PTCPE2
#define PTCPE_PTCPE3                    _PTCPE.Bits.PTCPE3
#define PTCPE_PTCPE4                    _PTCPE.Bits.PTCPE4
#define PTCPE_PTCPE5                    _PTCPE.Bits.PTCPE5
#define PTCPE_PTCPE6                    _PTCPE.Bits.PTCPE6
#define PTCPE_PTCPE7                    _PTCPE.Bits.PTCPE7

#define PTCPE_PTCPE0_MASK               1U
#define PTCPE_PTCPE1_MASK               2U
#define PTCPE_PTCPE2_MASK               4U
#define PTCPE_PTCPE3_MASK               8U
#define PTCPE_PTCPE4_MASK               16U
#define PTCPE_PTCPE5_MASK               32U
#define PTCPE_PTCPE6_MASK               64U
#define PTCPE_PTCPE7_MASK               128U


/*** PTCSE - Port C Slew Rate Enable Register; 0x00001851 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCSE0      :1;                                       /* Output Slew Rate Enable for Port C Bit 0 */
    byte PTCSE1      :1;                                       /* Output Slew Rate Enable for Port C Bit 1 */
    byte PTCSE2      :1;                                       /* Output Slew Rate Enable for Port C Bit 2 */
    byte PTCSE3      :1;                                       /* Output Slew Rate Enable for Port C Bit 3 */
    byte PTCSE4      :1;                                       /* Output Slew Rate Enable for Port C Bit 4 */
    byte PTCSE5      :1;                                       /* Output Slew Rate Enable for Port C Bit 5 */
    byte PTCSE6      :1;                                       /* Output Slew Rate Enable for Port C Bit 6 */
    byte PTCSE7      :1;                                       /* Output Slew Rate Enable for Port C Bit 7 */
  } Bits;
} PTCSESTR;
extern volatile PTCSESTR _PTCSE @0x00001851;
#define PTCSE                           _PTCSE.Byte
#define PTCSE_PTCSE0                    _PTCSE.Bits.PTCSE0
#define PTCSE_PTCSE1                    _PTCSE.Bits.PTCSE1
#define PTCSE_PTCSE2                    _PTCSE.Bits.PTCSE2
#define PTCSE_PTCSE3                    _PTCSE.Bits.PTCSE3
#define PTCSE_PTCSE4                    _PTCSE.Bits.PTCSE4
#define PTCSE_PTCSE5                    _PTCSE.Bits.PTCSE5
#define PTCSE_PTCSE6                    _PTCSE.Bits.PTCSE6
#define PTCSE_PTCSE7                    _PTCSE.Bits.PTCSE7

#define PTCSE_PTCSE0_MASK               1U
#define PTCSE_PTCSE1_MASK               2U
#define PTCSE_PTCSE2_MASK               4U
#define PTCSE_PTCSE3_MASK               8U
#define PTCSE_PTCSE4_MASK               16U
#define PTCSE_PTCSE5_MASK               32U
#define PTCSE_PTCSE6_MASK               64U
#define PTCSE_PTCSE7_MASK               128U


/*** PTCDS - Port C Drive Strength Selection Register; 0x00001852 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDS0      :1;                                       /* Output Drive Strength Selection for Port C Bit 0 */
    byte PTCDS1      :1;                                       /* Output Drive Strength Selection for Port C Bit 1 */
    byte PTCDS2      :1;                                       /* Output Drive Strength Selection for Port C Bit 2 */
    byte PTCDS3      :1;                                       /* Output Drive Strength Selection for Port C Bit 3 */
    byte PTCDS4      :1;                                       /* Output Drive Strength Selection for Port C Bit 4 */
    byte PTCDS5      :1;                                       /* Output Drive Strength Selection for Port C Bit 5 */
    byte PTCDS6      :1;                                       /* Output Drive Strength Selection for Port C Bit 6 */
    byte PTCDS7      :1;                                       /* Output Drive Strength Selection for Port C Bit 7 */
  } Bits;
} PTCDSSTR;
extern volatile PTCDSSTR _PTCDS @0x00001852;
#define PTCDS                           _PTCDS.Byte
#define PTCDS_PTCDS0                    _PTCDS.Bits.PTCDS0
#define PTCDS_PTCDS1                    _PTCDS.Bits.PTCDS1
#define PTCDS_PTCDS2                    _PTCDS.Bits.PTCDS2
#define PTCDS_PTCDS3                    _PTCDS.Bits.PTCDS3
#define PTCDS_PTCDS4                    _PTCDS.Bits.PTCDS4
#define PTCDS_PTCDS5                    _PTCDS.Bits.PTCDS5
#define PTCDS_PTCDS6                    _PTCDS.Bits.PTCDS6
#define PTCDS_PTCDS7                    _PTCDS.Bits.PTCDS7

#define PTCDS_PTCDS0_MASK               1U
#define PTCDS_PTCDS1_MASK               2U
#define PTCDS_PTCDS2_MASK               4U
#define PTCDS_PTCDS3_MASK               8U
#define PTCDS_PTCDS4_MASK               16U
#define PTCDS_PTCDS5_MASK               32U
#define PTCDS_PTCDS6_MASK               64U
#define PTCDS_PTCDS7_MASK               128U


/*** GNGC - Ganged Output Drive Control Register; 0x00001853 ***/
typedef union {
  byte Byte;
  struct {
    byte GNGEN       :1;                                       /* Ganged Output Drive Enable Bit */
    byte GNGPS1      :1;                                       /* Ganged Output Pin Select Bit 1 */
    byte GNGPS2      :1;                                       /* Ganged Output Pin Select Bit 2 */
    byte GNGPS3      :1;                                       /* Ganged Output Pin Select Bit 3 */
    byte GNGPS4      :1;                                       /* Ganged Output Pin Select Bit 4 */
    byte GNGPS5      :1;                                       /* Ganged Output Pin Select Bit 5 */
    byte GNGPS6      :1;                                       /* Ganged Output Pin Select Bit 6 */
    byte GNGPS7      :1;                                       /* Ganged Output Pin Select Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpGNGPS_1 :7;
  } MergedBits;
} GNGCSTR;
extern volatile GNGCSTR _GNGC @0x00001853;
#define GNGC                            _GNGC.Byte
#define GNGC_GNGEN                      _GNGC.Bits.GNGEN
#define GNGC_GNGPS1                     _GNGC.Bits.GNGPS1
#define GNGC_GNGPS2                     _GNGC.Bits.GNGPS2
#define GNGC_GNGPS3                     _GNGC.Bits.GNGPS3
#define GNGC_GNGPS4                     _GNGC.Bits.GNGPS4
#define GNGC_GNGPS5                     _GNGC.Bits.GNGPS5
#define GNGC_GNGPS6                     _GNGC.Bits.GNGPS6
#define GNGC_GNGPS7                     _GNGC.Bits.GNGPS7
#define GNGC_GNGPS_1                    _GNGC.MergedBits.grpGNGPS_1
#define GNGC_GNGPS                      GNGC_GNGPS_1

#define GNGC_GNGEN_MASK                 1U
#define GNGC_GNGPS1_MASK                2U
#define GNGC_GNGPS2_MASK                4U
#define GNGC_GNGPS3_MASK                8U
#define GNGC_GNGPS4_MASK                16U
#define GNGC_GNGPS5_MASK                32U
#define GNGC_GNGPS6_MASK                64U
#define GNGC_GNGPS7_MASK                128U
#define GNGC_GNGPS_1_MASK               254U
#define GNGC_GNGPS_1_BITNUM             1U


/*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x0000FFB0 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 7 */
  } Bits;
} NVBACKKEY0STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
#define _NVBACKKEY0 (*(const NVBACKKEY0STR * __far)0x0000FFB0)
#define NVBACKKEY0                      _NVBACKKEY0.Byte
#define NVBACKKEY0_KEY0                 _NVBACKKEY0.Bits.KEY0
#define NVBACKKEY0_KEY1                 _NVBACKKEY0.Bits.KEY1
#define NVBACKKEY0_KEY2                 _NVBACKKEY0.Bits.KEY2
#define NVBACKKEY0_KEY3                 _NVBACKKEY0.Bits.KEY3
#define NVBACKKEY0_KEY4                 _NVBACKKEY0.Bits.KEY4
#define NVBACKKEY0_KEY5                 _NVBACKKEY0.Bits.KEY5
#define NVBACKKEY0_KEY6                 _NVBACKKEY0.Bits.KEY6
#define NVBACKKEY0_KEY7                 _NVBACKKEY0.Bits.KEY7
/* NVBACKKEY_ARR: Access 8 NVBACKKEYx registers in an array */
#define NVBACKKEY_ARR                   ((volatile byte * __far) &NVBACKKEY0)

#define NVBACKKEY0_KEY0_MASK            1U
#define NVBACKKEY0_KEY1_MASK            2U
#define NVBACKKEY0_KEY2_MASK            4U
#define NVBACKKEY0_KEY3_MASK            8U
#define NVBACKKEY0_KEY4_MASK            16U
#define NVBACKKEY0_KEY5_MASK            32U
#define NVBACKKEY0_KEY6_MASK            64U
#define NVBACKKEY0_KEY7_MASK            128U


/*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x0000FFB1 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 7 */
  } Bits;
} NVBACKKEY1STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
#define _NVBACKKEY1 (*(const NVBACKKEY1STR * __far)0x0000FFB1)
#define NVBACKKEY1                      _NVBACKKEY1.Byte
#define NVBACKKEY1_KEY0                 _NVBACKKEY1.Bits.KEY0
#define NVBACKKEY1_KEY1                 _NVBACKKEY1.Bits.KEY1
#define NVBACKKEY1_KEY2                 _NVBACKKEY1.Bits.KEY2
#define NVBACKKEY1_KEY3                 _NVBACKKEY1.Bits.KEY3
#define NVBACKKEY1_KEY4                 _NVBACKKEY1.Bits.KEY4
#define NVBACKKEY1_KEY5                 _NVBACKKEY1.Bits.KEY5
#define NVBACKKEY1_KEY6                 _NVBACKKEY1.Bits.KEY6
#define NVBACKKEY1_KEY7                 _NVBACKKEY1.Bits.KEY7

#define NVBACKKEY1_KEY0_MASK            1U
#define NVBACKKEY1_KEY1_MASK            2U
#define NVBACKKEY1_KEY2_MASK            4U
#define NVBACKKEY1_KEY3_MASK            8U
#define NVBACKKEY1_KEY4_MASK            16U
#define NVBACKKEY1_KEY5_MASK            32U
#define NVBACKKEY1_KEY6_MASK            64U
#define NVBACKKEY1_KEY7_MASK            128U


/*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x0000FFB2 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 7 */
  } Bits;
} NVBACKKEY2STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
#define _NVBACKKEY2 (*(const NVBACKKEY2STR * __far)0x0000FFB2)
#define NVBACKKEY2                      _NVBACKKEY2.Byte
#define NVBACKKEY2_KEY0                 _NVBACKKEY2.Bits.KEY0
#define NVBACKKEY2_KEY1                 _NVBACKKEY2.Bits.KEY1
#define NVBACKKEY2_KEY2                 _NVBACKKEY2.Bits.KEY2
#define NVBACKKEY2_KEY3                 _NVBACKKEY2.Bits.KEY3
#define NVBACKKEY2_KEY4                 _NVBACKKEY2.Bits.KEY4
#define NVBACKKEY2_KEY5                 _NVBACKKEY2.Bits.KEY5
#define NVBACKKEY2_KEY6                 _NVBACKKEY2.Bits.KEY6
#define NVBACKKEY2_KEY7                 _NVBACKKEY2.Bits.KEY7

#define NVBACKKEY2_KEY0_MASK            1U
#define NVBACKKEY2_KEY1_MASK            2U
#define NVBACKKEY2_KEY2_MASK            4U
#define NVBACKKEY2_KEY3_MASK            8U
#define NVBACKKEY2_KEY4_MASK            16U
#define NVBACKKEY2_KEY5_MASK            32U
#define NVBACKKEY2_KEY6_MASK            64U
#define NVBACKKEY2_KEY7_MASK            128U


/*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x0000FFB3 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 7 */
  } Bits;
} NVBACKKEY3STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
#define _NVBACKKEY3 (*(const NVBACKKEY3STR * __far)0x0000FFB3)
#define NVBACKKEY3                      _NVBACKKEY3.Byte
#define NVBACKKEY3_KEY0                 _NVBACKKEY3.Bits.KEY0
#define NVBACKKEY3_KEY1                 _NVBACKKEY3.Bits.KEY1
#define NVBACKKEY3_KEY2                 _NVBACKKEY3.Bits.KEY2
#define NVBACKKEY3_KEY3                 _NVBACKKEY3.Bits.KEY3
#define NVBACKKEY3_KEY4                 _NVBACKKEY3.Bits.KEY4
#define NVBACKKEY3_KEY5                 _NVBACKKEY3.Bits.KEY5
#define NVBACKKEY3_KEY6                 _NVBACKKEY3.Bits.KEY6
#define NVBACKKEY3_KEY7                 _NVBACKKEY3.Bits.KEY7

#define NVBACKKEY3_KEY0_MASK            1U
#define NVBACKKEY3_KEY1_MASK            2U
#define NVBACKKEY3_KEY2_MASK            4U
#define NVBACKKEY3_KEY3_MASK            8U
#define NVBACKKEY3_KEY4_MASK            16U
#define NVBACKKEY3_KEY5_MASK            32U
#define NVBACKKEY3_KEY6_MASK            64U
#define NVBACKKEY3_KEY7_MASK            128U


/*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x0000FFB4 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 7 */
  } Bits;
} NVBACKKEY4STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
#define _NVBACKKEY4 (*(const NVBACKKEY4STR * __far)0x0000FFB4)
#define NVBACKKEY4                      _NVBACKKEY4.Byte
#define NVBACKKEY4_KEY0                 _NVBACKKEY4.Bits.KEY0
#define NVBACKKEY4_KEY1                 _NVBACKKEY4.Bits.KEY1
#define NVBACKKEY4_KEY2                 _NVBACKKEY4.Bits.KEY2
#define NVBACKKEY4_KEY3                 _NVBACKKEY4.Bits.KEY3
#define NVBACKKEY4_KEY4                 _NVBACKKEY4.Bits.KEY4
#define NVBACKKEY4_KEY5                 _NVBACKKEY4.Bits.KEY5
#define NVBACKKEY4_KEY6                 _NVBACKKEY4.Bits.KEY6
#define NVBACKKEY4_KEY7                 _NVBACKKEY4.Bits.KEY7

#define NVBACKKEY4_KEY0_MASK            1U
#define NVBACKKEY4_KEY1_MASK            2U
#define NVBACKKEY4_KEY2_MASK            4U
#define NVBACKKEY4_KEY3_MASK            8U
#define NVBACKKEY4_KEY4_MASK            16U
#define NVBACKKEY4_KEY5_MASK            32U
#define NVBACKKEY4_KEY6_MASK            64U
#define NVBACKKEY4_KEY7_MASK            128U


/*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x0000FFB5 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 7 */
  } Bits;
} NVBACKKEY5STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
#define _NVBACKKEY5 (*(const NVBACKKEY5STR * __far)0x0000FFB5)
#define NVBACKKEY5                      _NVBACKKEY5.Byte
#define NVBACKKEY5_KEY0                 _NVBACKKEY5.Bits.KEY0
#define NVBACKKEY5_KEY1                 _NVBACKKEY5.Bits.KEY1
#define NVBACKKEY5_KEY2                 _NVBACKKEY5.Bits.KEY2
#define NVBACKKEY5_KEY3                 _NVBACKKEY5.Bits.KEY3
#define NVBACKKEY5_KEY4                 _NVBACKKEY5.Bits.KEY4
#define NVBACKKEY5_KEY5                 _NVBACKKEY5.Bits.KEY5
#define NVBACKKEY5_KEY6                 _NVBACKKEY5.Bits.KEY6
#define NVBACKKEY5_KEY7                 _NVBACKKEY5.Bits.KEY7

#define NVBACKKEY5_KEY0_MASK            1U
#define NVBACKKEY5_KEY1_MASK            2U
#define NVBACKKEY5_KEY2_MASK            4U
#define NVBACKKEY5_KEY3_MASK            8U
#define NVBACKKEY5_KEY4_MASK            16U
#define NVBACKKEY5_KEY5_MASK            32U
#define NVBACKKEY5_KEY6_MASK            64U
#define NVBACKKEY5_KEY7_MASK            128U


/*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x0000FFB6 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 7 */
  } Bits;
} NVBACKKEY6STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
#define _NVBACKKEY6 (*(const NVBACKKEY6STR * __far)0x0000FFB6)
#define NVBACKKEY6                      _NVBACKKEY6.Byte
#define NVBACKKEY6_KEY0                 _NVBACKKEY6.Bits.KEY0
#define NVBACKKEY6_KEY1                 _NVBACKKEY6.Bits.KEY1
#define NVBACKKEY6_KEY2                 _NVBACKKEY6.Bits.KEY2
#define NVBACKKEY6_KEY3                 _NVBACKKEY6.Bits.KEY3
#define NVBACKKEY6_KEY4                 _NVBACKKEY6.Bits.KEY4
#define NVBACKKEY6_KEY5                 _NVBACKKEY6.Bits.KEY5
#define NVBACKKEY6_KEY6                 _NVBACKKEY6.Bits.KEY6
#define NVBACKKEY6_KEY7                 _NVBACKKEY6.Bits.KEY7

#define NVBACKKEY6_KEY0_MASK            1U
#define NVBACKKEY6_KEY1_MASK            2U
#define NVBACKKEY6_KEY2_MASK            4U
#define NVBACKKEY6_KEY3_MASK            8U
#define NVBACKKEY6_KEY4_MASK            16U
#define NVBACKKEY6_KEY5_MASK            32U
#define NVBACKKEY6_KEY6_MASK            64U
#define NVBACKKEY6_KEY7_MASK            128U


/*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x0000FFB7 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 7 */
  } Bits;
} NVBACKKEY7STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
#define _NVBACKKEY7 (*(const NVBACKKEY7STR * __far)0x0000FFB7)
#define NVBACKKEY7                      _NVBACKKEY7.Byte
#define NVBACKKEY7_KEY0                 _NVBACKKEY7.Bits.KEY0
#define NVBACKKEY7_KEY1                 _NVBACKKEY7.Bits.KEY1
#define NVBACKKEY7_KEY2                 _NVBACKKEY7.Bits.KEY2
#define NVBACKKEY7_KEY3                 _NVBACKKEY7.Bits.KEY3
#define NVBACKKEY7_KEY4                 _NVBACKKEY7.Bits.KEY4
#define NVBACKKEY7_KEY5                 _NVBACKKEY7.Bits.KEY5
#define NVBACKKEY7_KEY6                 _NVBACKKEY7.Bits.KEY6
#define NVBACKKEY7_KEY7                 _NVBACKKEY7.Bits.KEY7

#define NVBACKKEY7_KEY0_MASK            1U
#define NVBACKKEY7_KEY1_MASK            2U
#define NVBACKKEY7_KEY2_MASK            4U
#define NVBACKKEY7_KEY3_MASK            8U
#define NVBACKKEY7_KEY4_MASK            16U
#define NVBACKKEY7_KEY5_MASK            32U
#define NVBACKKEY7_KEY6_MASK            64U
#define NVBACKKEY7_KEY7_MASK            128U


/*** NVPROT - Nonvolatile FLASH Protection Register; 0x0000FFBD ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* FLASH Protection Disable */
    byte FPS1        :1;                                       /* FLASH Protect Select Bit 1 */
    byte FPS2        :1;                                       /* FLASH Protect Select Bit 2 */
    byte FPS3        :1;                                       /* FLASH Protect Select Bit 3 */
    byte FPS4        :1;                                       /* FLASH Protect Select Bit 4 */
    byte FPS5        :1;                                       /* FLASH Protect Select Bit 5 */
    byte FPS6        :1;                                       /* FLASH Protect Select Bit 6 */
    byte FPS7        :1;                                       /* FLASH Protect Select Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS_1 :7;
  } MergedBits;
} NVPROTSTR;
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
#define _NVPROT (*(const NVPROTSTR * __far)0x0000FFBD)
#define NVPROT                          _NVPROT.Byte
#define NVPROT_FPDIS                    _NVPROT.Bits.FPDIS
#define NVPROT_FPS1                     _NVPROT.Bits.FPS1
#define NVPROT_FPS2                     _NVPROT.Bits.FPS2
#define NVPROT_FPS3                     _NVPROT.Bits.FPS3
#define NVPROT_FPS4                     _NVPROT.Bits.FPS4
#define NVPROT_FPS5                     _NVPROT.Bits.FPS5
#define NVPROT_FPS6                     _NVPROT.Bits.FPS6
#define NVPROT_FPS7                     _NVPROT.Bits.FPS7
#define NVPROT_FPS_1                    _NVPROT.MergedBits.grpFPS_1
#define NVPROT_FPS                      NVPROT_FPS_1

#define NVPROT_FPDIS_MASK               1U
#define NVPROT_FPS1_MASK                2U
#define NVPROT_FPS2_MASK                4U
#define NVPROT_FPS3_MASK                8U
#define NVPROT_FPS4_MASK                16U
#define NVPROT_FPS5_MASK                32U
#define NVPROT_FPS6_MASK                64U
#define NVPROT_FPS7_MASK                128U
#define NVPROT_FPS_1_MASK               254U
#define NVPROT_FPS_1_BITNUM             1U


/*** NVOPT - Nonvolatile Flash Options Register; 0x0000FFBF ***/
typedef union {
  byte Byte;
  struct {
    byte SEC00       :1;                                       /* Security State Code, bit 0 */
    byte SEC01       :1;                                       /* Security State Code, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FNORED      :1;                                       /* Vector Redirection Disable */
    byte KEYEN       :1;                                       /* Backdoor Key Mechanism Enable */
  } Bits;
  struct {
    byte grpSEC0 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVOPTSTR;
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */
#define _NVOPT (*(const NVOPTSTR * __far)0x0000FFBF)
#define NVOPT                           _NVOPT.Byte
#define NVOPT_SEC00                     _NVOPT.Bits.SEC00
#define NVOPT_SEC01                     _NVOPT.Bits.SEC01
#define NVOPT_FNORED                    _NVOPT.Bits.FNORED
#define NVOPT_KEYEN                     _NVOPT.Bits.KEYEN
#define NVOPT_SEC0                      _NVOPT.MergedBits.grpSEC0

#define NVOPT_SEC00_MASK                1U
#define NVOPT_SEC01_MASK                2U
#define NVOPT_FNORED_MASK               64U
#define NVOPT_KEYEN_MASK                128U
#define NVOPT_SEC0_MASK                 3U
#define NVOPT_SEC0_BITNUM               0U



/* Flash commands */
#define mBlank                          0x05
#define mBurstProg                      0x25
#define mByteProg                       0x20
#define mMassErase                      0x41
#define mPageErase                      0x40


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
#endif
/*lint -restore  +esym(961,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
