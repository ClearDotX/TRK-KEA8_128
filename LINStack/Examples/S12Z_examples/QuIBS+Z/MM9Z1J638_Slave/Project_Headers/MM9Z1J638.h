/* Based on CPU DB MM9Z1x638_48, version 3.00.001 (RegistersPrg V2.33) */
/*
** ###################################################################
**     Filename  : mm9z1j638.h
**     Processor : MM9Z1J638
**     FileFormat: V2.33
**     DataSheet : MM9Z1_638 Rev. 0.071, August 2012
**     Compiler  : CodeWarrior compiler
**     Date/Time : 11/29/2012, 9:19 AM
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 15.11.2012, V3.00.0:
**              - Renamed port E to port B
**              -  Removed TXD and TXDM from LIN_CTL register
**      - 15.11.2012, V3.00.1:
**              - Renamed CAN0 to CAN 
**              -  Fixed registers DBGSR, RDRC, CPMUIFLG, CPMUACLKTR, CPMUOSC2, CPMUAPIR, TRIM_BG0L, WD_CTL, GPIO_PUC;
**
**     File-Format-Revisions:
**               - none
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user’s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MM9Z1J638_H
#define _MM9Z1J638_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/*lint -save  -e621 Disable MISRA rule (5.1) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma bfield_gap_limit -1 /*this guarantee correct bitfield positions*/

/**************** interrupt vector numbers ****************/
#define VectorNumber_VReserved123       123U
#define VectorNumber_VReserved122       122U
#define VectorNumber_VReserved121       121U
#define VectorNumber_VReserved120       120U
#define VectorNumber_VReserved119       119U
#define VectorNumber_VReserved118       118U
#define VectorNumber_VReserved117       117U
#define VectorNumber_VReserved116       116U
#define VectorNumber_VReserved115       115U
#define VectorNumber_VReserved114       114U
#define VectorNumber_VReserved113       113U
#define VectorNumber_VReserved112       112U
#define VectorNumber_VReserved111       111U
#define VectorNumber_VReserved110       110U
#define VectorNumber_VReserved109       109U
#define VectorNumber_VReserved108       108U
#define VectorNumber_VReserved107       107U
#define VectorNumber_VReserved106       106U
#define VectorNumber_VReserved105       105U
#define VectorNumber_VReserved104       104U
#define VectorNumber_VReserved103       103U
#define VectorNumber_VReserved102       102U
#define VectorNumber_VReserved101       101U
#define VectorNumber_VReserved100       100U
#define VectorNumber_VReserved99        99U
#define VectorNumber_VReserved98        98U
#define VectorNumber_VReserved97        97U
#define VectorNumber_VReserved96        96U
#define VectorNumber_VReserved95        95U
#define VectorNumber_VReserved94        94U
#define VectorNumber_VReserved93        93U
#define VectorNumber_VReserved92        92U
#define VectorNumber_VReserved91        91U
#define VectorNumber_VReserved90        90U
#define VectorNumber_VReserved89        89U
#define VectorNumber_VReserved88        88U
#define VectorNumber_VReserved87        87U
#define VectorNumber_VReserved86        86U
#define VectorNumber_VReserved85        85U
#define VectorNumber_VReserved84        84U
#define VectorNumber_VReserved83        83U
#define VectorNumber_VReserved82        82U
#define VectorNumber_VReserved81        81U
#define VectorNumber_VReserved80        80U
#define VectorNumber_VReserved79        79U
#define VectorNumber_VReserved78        78U
#define VectorNumber_VReserved77        77U
#define VectorNumber_VReserved76        76U
#define VectorNumber_VReserved75        75U
#define VectorNumber_VReserved74        74U
#define VectorNumber_VReserved73        73U
#define VectorNumber_VReserved72        72U
#define VectorNumber_VReserved71        71U
#define VectorNumber_VReserved70        70U
#define VectorNumber_VReserved69        69U
#define VectorNumber_VReserved68        68U
#define VectorNumber_VReserved67        67U
#define VectorNumber_VReserved66        66U
#define VectorNumber_VReserved65        65U
#define VectorNumber_VReserved64        64U
#define VectorNumber_Vapi               63U
#define VectorNumber_Vlvi               62U
#define VectorNumber_VReserved61        61U
#define VectorNumber_VReserved60        60U
#define VectorNumber_VReserved59        59U
#define VectorNumber_VReserved58        58U
#define VectorNumber_VReserved57        57U
#define VectorNumber_VReserved56        56U
#define VectorNumber_VReserved55        55U
#define VectorNumber_VReserved54        54U
#define VectorNumber_VReserved53        53U
#define VectorNumber_VReserved52        52U
#define VectorNumber_VReserved51        51U
#define VectorNumber_VReserved50        50U
#define VectorNumber_VReserved49        49U
#define VectorNumber_VReserved48        48U
#define VectorNumber_VReserved47        47U
#define VectorNumber_VReserved46        46U
#define VectorNumber_VReserved45        45U
#define VectorNumber_VReserved44        44U
#define VectorNumber_Vcan0tx            43U
#define VectorNumber_Vcan0rx            42U
#define VectorNumber_Vcan0err           41U
#define VectorNumber_Vcan0wkup          40U
#define VectorNumber_Vflash             39U
#define VectorNumber_Vflasherr          38U
#define VectorNumber_VReserved37        37U
#define VectorNumber_VReserved36        36U
#define VectorNumber_VRAM_err           35U
#define VectorNumber_VReserved34        34U
#define VectorNumber_VReserved33        33U
#define VectorNumber_Vcpmuplllck        32U
#define VectorNumber_Vcpmuosc           31U
#define VectorNumber_VReserved30        30U
#define VectorNumber_VReserved29        29U
#define VectorNumber_VReserved28        28U
#define VectorNumber_VReserved27        27U
#define VectorNumber_VReserved26        26U
#define VectorNumber_VReserved25        25U
#define VectorNumber_VReserved24        24U
#define VectorNumber_Vspi0              23U
#define VectorNumber_VReserved22        22U
#define VectorNumber_VReserved21        21U
#define VectorNumber_VReserved20        20U
#define VectorNumber_VReserved19        19U
#define VectorNumber_VReserved18        18U
#define VectorNumber_VReserved17        17U
#define VectorNumber_VReserved16        16U
#define VectorNumber_VReserved15        15U
#define VectorNumber_VReserved14        14U
#define VectorNumber_VReserved13        13U
#define VectorNumber_VReserved12        12U
#define VectorNumber_Vrti               11U
#define VectorNumber_Vd2di_ext          10U
#define VectorNumber_Vd2di_err          9U
#define VectorNumber_Vsi                8U
#define VectorNumber_VReserved7         7U
#define VectorNumber_VReserved6         6U
#define VectorNumber_Vme                5U
#define VectorNumber_Vsys               4U
#define VectorNumber_Vswi               3U
#define VectorNumber_Vtrap              2U
#define VectorNumber_Vspare             1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define VReserved123                    0x00FFFE10UL
#define VReserved122                    0x00FFFE14UL
#define VReserved121                    0x00FFFE18UL
#define VReserved120                    0x00FFFE1CUL
#define VReserved119                    0x00FFFE20UL
#define VReserved118                    0x00FFFE24UL
#define VReserved117                    0x00FFFE28UL
#define VReserved116                    0x00FFFE2CUL
#define VReserved115                    0x00FFFE30UL
#define VReserved114                    0x00FFFE34UL
#define VReserved113                    0x00FFFE38UL
#define VReserved112                    0x00FFFE3CUL
#define VReserved111                    0x00FFFE40UL
#define VReserved110                    0x00FFFE44UL
#define VReserved109                    0x00FFFE48UL
#define VReserved108                    0x00FFFE4CUL
#define VReserved107                    0x00FFFE50UL
#define VReserved106                    0x00FFFE54UL
#define VReserved105                    0x00FFFE58UL
#define VReserved104                    0x00FFFE5CUL
#define VReserved103                    0x00FFFE60UL
#define VReserved102                    0x00FFFE64UL
#define VReserved101                    0x00FFFE68UL
#define VReserved100                    0x00FFFE6CUL
#define VReserved99                     0x00FFFE70UL
#define VReserved98                     0x00FFFE74UL
#define VReserved97                     0x00FFFE78UL
#define VReserved96                     0x00FFFE7CUL
#define VReserved95                     0x00FFFE80UL
#define VReserved94                     0x00FFFE84UL
#define VReserved93                     0x00FFFE88UL
#define VReserved92                     0x00FFFE8CUL
#define VReserved91                     0x00FFFE90UL
#define VReserved90                     0x00FFFE94UL
#define VReserved89                     0x00FFFE98UL
#define VReserved88                     0x00FFFE9CUL
#define VReserved87                     0x00FFFEA0UL
#define VReserved86                     0x00FFFEA4UL
#define VReserved85                     0x00FFFEA8UL
#define VReserved84                     0x00FFFEACUL
#define VReserved83                     0x00FFFEB0UL
#define VReserved82                     0x00FFFEB4UL
#define VReserved81                     0x00FFFEB8UL
#define VReserved80                     0x00FFFEBCUL
#define VReserved79                     0x00FFFEC0UL
#define VReserved78                     0x00FFFEC4UL
#define VReserved77                     0x00FFFEC8UL
#define VReserved76                     0x00FFFECCUL
#define VReserved75                     0x00FFFED0UL
#define VReserved74                     0x00FFFED4UL
#define VReserved73                     0x00FFFED8UL
#define VReserved72                     0x00FFFEDCUL
#define VReserved71                     0x00FFFEE0UL
#define VReserved70                     0x00FFFEE4UL
#define VReserved69                     0x00FFFEE8UL
#define VReserved68                     0x00FFFEECUL
#define VReserved67                     0x00FFFEF0UL
#define VReserved66                     0x00FFFEF4UL
#define VReserved65                     0x00FFFEF8UL
#define VReserved64                     0x00FFFEFCUL
#define Vapi                            0x00FFFF00UL
#define Vlvi                            0x00FFFF04UL
#define VReserved61                     0x00FFFF08UL
#define VReserved60                     0x00FFFF0CUL
#define VReserved59                     0x00FFFF10UL
#define VReserved58                     0x00FFFF14UL
#define VReserved57                     0x00FFFF18UL
#define VReserved56                     0x00FFFF1CUL
#define VReserved55                     0x00FFFF20UL
#define VReserved54                     0x00FFFF24UL
#define VReserved53                     0x00FFFF28UL
#define VReserved52                     0x00FFFF2CUL
#define VReserved51                     0x00FFFF30UL
#define VReserved50                     0x00FFFF34UL
#define VReserved49                     0x00FFFF38UL
#define VReserved48                     0x00FFFF3CUL
#define VReserved47                     0x00FFFF40UL
#define VReserved46                     0x00FFFF44UL
#define VReserved45                     0x00FFFF48UL
#define VReserved44                     0x00FFFF4CUL
#define Vcan0tx                         0x00FFFF50UL
#define Vcan0rx                         0x00FFFF54UL
#define Vcan0err                        0x00FFFF58UL
#define Vcan0wkup                       0x00FFFF5CUL
#define Vflash                          0x00FFFF60UL
#define Vflasherr                       0x00FFFF64UL
#define VReserved37                     0x00FFFF68UL
#define VReserved36                     0x00FFFF6CUL
#define VRAM_err                        0x00FFFF70UL
#define VReserved34                     0x00FFFF74UL
#define VReserved33                     0x00FFFF78UL
#define Vcpmuplllck                     0x00FFFF7CUL
#define Vcpmuosc                        0x00FFFF80UL
#define VReserved30                     0x00FFFF84UL
#define VReserved29                     0x00FFFF88UL
#define VReserved28                     0x00FFFF8CUL
#define VReserved27                     0x00FFFF90UL
#define VReserved26                     0x00FFFF94UL
#define VReserved25                     0x00FFFF98UL
#define VReserved24                     0x00FFFF9CUL
#define Vspi0                           0x00FFFFA0UL
#define VReserved22                     0x00FFFFA4UL
#define VReserved21                     0x00FFFFA8UL
#define VReserved20                     0x00FFFFACUL
#define VReserved19                     0x00FFFFB0UL
#define VReserved18                     0x00FFFFB4UL
#define VReserved17                     0x00FFFFB8UL
#define VReserved16                     0x00FFFFBCUL
#define VReserved15                     0x00FFFFC0UL
#define VReserved14                     0x00FFFFC4UL
#define VReserved13                     0x00FFFFC8UL
#define VReserved12                     0x00FFFFCCUL
#define Vrti                            0x00FFFFD0UL
#define Vd2di_ext                       0x00FFFFD4UL
#define Vd2di_err                       0x00FFFFD8UL
#define Vsi                             0x00FFFFDCUL
#define VReserved7                      0x00FFFFE0UL
#define VReserved6                      0x00FFFFE4UL
#define Vme                             0x00FFFFE8UL
#define Vsys                            0x00FFFFECUL
#define Vswi                            0x00FFFFF0UL
#define Vtrap                           0x00FFFFF4UL
#define Vspare                          0x00FFFFF8UL
#define Vreset                          0x00FFFFFCUL

/**************** registers I/O map ****************/

/*** PARTID - Part ID Register; 0x00000000 ***/
typedef union {
  dword Dword;
   /* Overlapped registers: */
  struct {
    /*** PARTID0 - Part ID Register 0; 0x00000000 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :8;                                       /* Part ID 0 */
      } Bits;
    } PARTID0STR;
    #define PARTID0                     _PARTID.Overlap_STR.PARTID0STR.Byte
    #define PARTID0_ID0                 _PARTID.Overlap_STR.PARTID0STR.Bits.ID0
    /* PARTID_ARR: Access 4 PARTIDx registers in an array */
    #define PARTID_ARR                  ((volatile byte *) &PARTID0)
    
    #define PARTID0_ID0_MASK            255U
    #define PARTID0_ID0_BITNUM          0U
    

    /*** PARTID1 - Part ID Register 1; 0x00000001 ***/
    union {
      byte Byte;
      struct {
        byte ID1         :8;                                       /* Part ID 1 */
      } Bits;
    } PARTID1STR;
    #define PARTID1                     _PARTID.Overlap_STR.PARTID1STR.Byte
    #define PARTID1_ID1                 _PARTID.Overlap_STR.PARTID1STR.Bits.ID1
    
    #define PARTID1_ID1_MASK            255U
    #define PARTID1_ID1_BITNUM          0U
    

    /*** PARTID2 - Part ID Register 2; 0x00000002 ***/
    union {
      byte Byte;
      struct {
        byte ID2         :8;                                       /* Part ID 2 */
      } Bits;
    } PARTID2STR;
    #define PARTID2                     _PARTID.Overlap_STR.PARTID2STR.Byte
    #define PARTID2_ID2                 _PARTID.Overlap_STR.PARTID2STR.Bits.ID2
    
    #define PARTID2_ID2_MASK            255U
    #define PARTID2_ID2_BITNUM          0U
    

    /*** PARTID3 - Part ID Register 3; 0x00000003 ***/
    union {
      byte Byte;
      struct {
        byte ID3         :8;                                       /* Part ID 3 */
      } Bits;
    } PARTID3STR;
    #define PARTID3                     _PARTID.Overlap_STR.PARTID3STR.Byte
    #define PARTID3_ID3                 _PARTID.Overlap_STR.PARTID3STR.Bits.ID3
    
    #define PARTID3_ID3_MASK            255U
    #define PARTID3_ID3_BITNUM          0U
    
  } Overlap_STR;

} PARTIDSTR;
extern volatile PARTIDSTR _PARTID @0x00000000;
#define PARTID                          _PARTID.Dword


/*** IVBR - Interrupt Vector Base Register; 0x00000010 ***/
typedef union {
  word Word;
  struct {
    word             :1; 
    word IVB_ADDR    :15;                                      /* Interrupt Vector Base Address Bits */
  } Bits;
} IVBRSTR;
extern volatile IVBRSTR _IVBR @0x00000010;
#define IVBR                            _IVBR.Word
#define IVBR_IVB_ADDR                   _IVBR.Bits.IVB_ADDR

#define IVBR_IVB_ADDR_MASK              65534U
#define IVBR_IVB_ADDR_BITNUM            1U


/*** INT_XGPRIO - XGATE Interrupt Priority Configuration Register; 0x00000016 ***/
typedef union {
  byte Byte;
  struct {
    byte XILVL       :3;                                       /* XGATE Interrupt Priority Level */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} INT_XGPRIOSTR;
extern volatile INT_XGPRIOSTR _INT_XGPRIO @0x00000016;
#define INT_XGPRIO                      _INT_XGPRIO.Byte
#define INT_XGPRIO_XILVL                _INT_XGPRIO.Bits.XILVL

#define INT_XGPRIO_XILVL_MASK           7U
#define INT_XGPRIO_XILVL_BITNUM         0U


/*** INT_CFADDR - Interrupt Request Configuration Address Register; 0x00000017 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte INT_CFADDR_grp :4;                                    /* Interrupt Request Configuration Data Register Select Bits */ /*Warning: group name is duplicated with register name*/
    byte             :1; 
  } Bits;
} INT_CFADDRSTR;
extern volatile INT_CFADDRSTR _INT_CFADDR @0x00000017;
#define INT_CFADDR                      _INT_CFADDR.Byte
#define INT_CFADDR_INT_CFADDR           _INT_CFADDR.Bits.INT_CFADDR_grp

#define INT_CFADDR_INT_CFADDR_MASK      120U
#define INT_CFADDR_INT_CFADDR_BITNUM    3U


/*** INT_CFDATA0 - Interrupt Request Configuration Data Register 0; 0x00000018 ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA0STR;
extern volatile INT_CFDATA0STR _INT_CFDATA0 @0x00000018;
#define INT_CFDATA0                     _INT_CFDATA0.Byte
#define INT_CFDATA0_PRIOLVL             _INT_CFDATA0.Bits.PRIOLVL
#define INT_CFDATA0_RQST                _INT_CFDATA0.Bits.RQST
/* INT_CFDATA_ARR: Access 8 INT_CFDATAx registers in an array */
#define INT_CFDATA_ARR                  ((volatile byte *) &INT_CFDATA0)

#define INT_CFDATA0_PRIOLVL_MASK        7U
#define INT_CFDATA0_PRIOLVL_BITNUM      0U
#define INT_CFDATA0_RQST_MASK           128U


/*** INT_CFDATA1 - Interrupt Request Configuration Data Register 1; 0x00000019 ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA1STR;
extern volatile INT_CFDATA1STR _INT_CFDATA1 @0x00000019;
#define INT_CFDATA1                     _INT_CFDATA1.Byte
#define INT_CFDATA1_PRIOLVL             _INT_CFDATA1.Bits.PRIOLVL
#define INT_CFDATA1_RQST                _INT_CFDATA1.Bits.RQST

#define INT_CFDATA1_PRIOLVL_MASK        7U
#define INT_CFDATA1_PRIOLVL_BITNUM      0U
#define INT_CFDATA1_RQST_MASK           128U


/*** INT_CFDATA2 - Interrupt Request Configuration Data Register 2; 0x0000001A ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA2STR;
extern volatile INT_CFDATA2STR _INT_CFDATA2 @0x0000001A;
#define INT_CFDATA2                     _INT_CFDATA2.Byte
#define INT_CFDATA2_PRIOLVL             _INT_CFDATA2.Bits.PRIOLVL
#define INT_CFDATA2_RQST                _INT_CFDATA2.Bits.RQST

#define INT_CFDATA2_PRIOLVL_MASK        7U
#define INT_CFDATA2_PRIOLVL_BITNUM      0U
#define INT_CFDATA2_RQST_MASK           128U


/*** INT_CFDATA3 - Interrupt Request Configuration Data Register 3; 0x0000001B ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA3STR;
extern volatile INT_CFDATA3STR _INT_CFDATA3 @0x0000001B;
#define INT_CFDATA3                     _INT_CFDATA3.Byte
#define INT_CFDATA3_PRIOLVL             _INT_CFDATA3.Bits.PRIOLVL
#define INT_CFDATA3_RQST                _INT_CFDATA3.Bits.RQST

#define INT_CFDATA3_PRIOLVL_MASK        7U
#define INT_CFDATA3_PRIOLVL_BITNUM      0U
#define INT_CFDATA3_RQST_MASK           128U


/*** INT_CFDATA4 - Interrupt Request Configuration Data Register 4; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA4STR;
extern volatile INT_CFDATA4STR _INT_CFDATA4 @0x0000001C;
#define INT_CFDATA4                     _INT_CFDATA4.Byte
#define INT_CFDATA4_PRIOLVL             _INT_CFDATA4.Bits.PRIOLVL
#define INT_CFDATA4_RQST                _INT_CFDATA4.Bits.RQST

#define INT_CFDATA4_PRIOLVL_MASK        7U
#define INT_CFDATA4_PRIOLVL_BITNUM      0U
#define INT_CFDATA4_RQST_MASK           128U


/*** INT_CFDATA5 - Interrupt Request Configuration Data Register 5; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA5STR;
extern volatile INT_CFDATA5STR _INT_CFDATA5 @0x0000001D;
#define INT_CFDATA5                     _INT_CFDATA5.Byte
#define INT_CFDATA5_PRIOLVL             _INT_CFDATA5.Bits.PRIOLVL
#define INT_CFDATA5_RQST                _INT_CFDATA5.Bits.RQST

#define INT_CFDATA5_PRIOLVL_MASK        7U
#define INT_CFDATA5_PRIOLVL_BITNUM      0U
#define INT_CFDATA5_RQST_MASK           128U


/*** INT_CFDATA6 - Interrupt Request Configuration Data Register 6; 0x0000001E ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA6STR;
extern volatile INT_CFDATA6STR _INT_CFDATA6 @0x0000001E;
#define INT_CFDATA6                     _INT_CFDATA6.Byte
#define INT_CFDATA6_PRIOLVL             _INT_CFDATA6.Bits.PRIOLVL
#define INT_CFDATA6_RQST                _INT_CFDATA6.Bits.RQST

#define INT_CFDATA6_PRIOLVL_MASK        7U
#define INT_CFDATA6_PRIOLVL_BITNUM      0U
#define INT_CFDATA6_RQST_MASK           128U


/*** INT_CFDATA7 - Interrupt Request Configuration Data Register 7; 0x0000001F ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA7STR;
extern volatile INT_CFDATA7STR _INT_CFDATA7 @0x0000001F;
#define INT_CFDATA7                     _INT_CFDATA7.Byte
#define INT_CFDATA7_PRIOLVL             _INT_CFDATA7.Bits.PRIOLVL
#define INT_CFDATA7_RQST                _INT_CFDATA7.Bits.RQST

#define INT_CFDATA7_PRIOLVL_MASK        7U
#define INT_CFDATA7_PRIOLVL_BITNUM      0U
#define INT_CFDATA7_RQST_MASK           128U


/*** MODE - Mode Register; 0x00000070 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODC        :1;                                       /* Mode Select Bit */
  } Bits;
} MODESTR;
extern volatile MODESTR _MODE @0x00000070;
#define MODE                            _MODE.Byte
#define MODE_MODC                       _MODE.Bits.MODC

#define MODE_MODC_MASK                  128U


/*** MMCEC - Error code register; 0x00000080 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MMCECH - Error code register high; 0x00000080 ***/
    union {
      byte Byte;
      struct {
        byte TGT         :4;                                       /* Target Field */
        byte ITR         :4;                                       /* Initiator Field */
      } Bits;
    } MMCECHSTR;
    #define MMCECH                      _MMCEC.Overlap_STR.MMCECHSTR.Byte
    #define MMCECH_TGT                  _MMCEC.Overlap_STR.MMCECHSTR.Bits.TGT
    #define MMCECH_ITR                  _MMCEC.Overlap_STR.MMCECHSTR.Bits.ITR
    
    #define MMCECH_TGT_MASK             15U
    #define MMCECH_TGT_BITNUM           0U
    #define MMCECH_ITR_MASK             240U
    #define MMCECH_ITR_BITNUM           4U
    

    /*** MMCECL - Error code register low; 0x00000081 ***/
    union {
      byte Byte;
      struct {
        byte ERR         :4;                                       /* Error Type Field */
        byte ACC         :4;                                       /* Access Type Field */
      } Bits;
    } MMCECLSTR;
    #define MMCECL                      _MMCEC.Overlap_STR.MMCECLSTR.Byte
    #define MMCECL_ERR                  _MMCEC.Overlap_STR.MMCECLSTR.Bits.ERR
    #define MMCECL_ACC                  _MMCEC.Overlap_STR.MMCECLSTR.Bits.ACC
    
    #define MMCECL_ERR_MASK             15U
    #define MMCECL_ERR_BITNUM           0U
    #define MMCECL_ACC_MASK             240U
    #define MMCECL_ACC_BITNUM           4U
    
  } Overlap_STR;

  struct {
    word ERR         :4;                                       /* Error Type Field */
    word ACC         :4;                                       /* Access Type Field */
    word TGT         :4;                                       /* Target Field */
    word ITR         :4;                                       /* Initiator Field */
  } Bits;
} MMCECSTR;
extern volatile MMCECSTR _MMCEC @0x00000080;
#define MMCEC                           _MMCEC.Word
#define MMCEC_ERR                       _MMCEC.Bits.ERR
#define MMCEC_ACC                       _MMCEC.Bits.ACC
#define MMCEC_TGT                       _MMCEC.Bits.TGT
#define MMCEC_ITR                       _MMCEC.Bits.ITR

#define MMCEC_ERR_MASK                  15U
#define MMCEC_ERR_BITNUM                0U
#define MMCEC_ACC_MASK                  240U
#define MMCEC_ACC_BITNUM                4U
#define MMCEC_TGT_MASK                  3840U
#define MMCEC_TGT_BITNUM                8U
#define MMCEC_ITR_MASK                  61440U
#define MMCEC_ITR_BITNUM                12U


/*** MMCCCR - Captured S12ZCPU Condition Code Register Low; 0x00000082 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MMCCCRH - Captured S12ZCPU Condition Code Register High; 0x00000082 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte CPUU        :1;                                       /* S12ZCPU User State Flag */
      } Bits;
    } MMCCCRHSTR;
    #define MMCCCRH                     _MMCCCR.Overlap_STR.MMCCCRHSTR.Byte
    #define MMCCCRH_CPUU                _MMCCCR.Overlap_STR.MMCCCRHSTR.Bits.CPUU
    
    #define MMCCCRH_CPUU_MASK           128U
    

    /*** MMCCCRL - Captured S12ZCPU Condition Code Register Low; 0x00000083 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte CPUI        :1;                                       /* S12ZCPU I-Interrupt Mask */
        byte             :1; 
        byte CPUX        :1;                                       /* S12ZCPU X-Interrupt Mask */
        byte             :1; 
      } Bits;
    } MMCCCRLSTR;
    #define MMCCCRL                     _MMCCCR.Overlap_STR.MMCCCRLSTR.Byte
    #define MMCCCRL_CPUI                _MMCCCR.Overlap_STR.MMCCCRLSTR.Bits.CPUI
    #define MMCCCRL_CPUX                _MMCCCR.Overlap_STR.MMCCCRLSTR.Bits.CPUX
    
    #define MMCCCRL_CPUI_MASK           16U
    #define MMCCCRL_CPUX_MASK           64U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word CPUI        :1;                                       /* S12ZCPU I-Interrupt Mask */
    word             :1; 
    word CPUX        :1;                                       /* S12ZCPU X-Interrupt Mask */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word CPUU        :1;                                       /* S12ZCPU User State Flag */
  } Bits;
} MMCCCRSTR;
extern volatile MMCCCRSTR _MMCCCR @0x00000082;
#define MMCCCR                          _MMCCCR.Word
#define MMCCCR_CPUI                     _MMCCCR.Bits.CPUI
#define MMCCCR_CPUX                     _MMCCCR.Bits.CPUX
#define MMCCCR_CPUU                     _MMCCCR.Bits.CPUU

#define MMCCCR_CPUI_MASK                16U
#define MMCCCR_CPUX_MASK                64U
#define MMCCCR_CPUU_MASK                32768U


/*** MMCPCH - Captured S12ZCPU Program Counter High; 0x00000085 ***/
typedef union {
  byte Byte;
  struct {
    byte CPUPC       :8;                                       /* S12ZCPU Program Counter Value */
  } Bits;
} MMCPCHSTR;
extern volatile MMCPCHSTR _MMCPCH @0x00000085;
#define MMCPCH                          _MMCPCH.Byte
#define MMCPCH_CPUPC                    _MMCPCH.Bits.CPUPC

#define MMCPCH_CPUPC_MASK               255U
#define MMCPCH_CPUPC_BITNUM             0U


/*** MMCPCM - Captured S12ZCPU Program Counter Middle; 0x00000086 ***/
typedef union {
  byte Byte;
  struct {
    byte CPUPC       :8;                                       /* S12ZCPU Program Counter Value */
  } Bits;
} MMCPCMSTR;
extern volatile MMCPCMSTR _MMCPCM @0x00000086;
#define MMCPCM                          _MMCPCM.Byte
#define MMCPCM_CPUPC                    _MMCPCM.Bits.CPUPC

#define MMCPCM_CPUPC_MASK               255U
#define MMCPCM_CPUPC_BITNUM             0U


/*** MMCPCL - Captured S12ZCPU Program Counter Low; 0x00000087 ***/
typedef union {
  byte Byte;
  struct {
    byte CPUPC       :8;                                       /* S12ZCPU Program Counter Value */
  } Bits;
} MMCPCLSTR;
extern volatile MMCPCLSTR _MMCPCL @0x00000087;
#define MMCPCL                          _MMCPCL.Byte
#define MMCPCL_CPUPC                    _MMCPCL.Bits.CPUPC

#define MMCPCL_CPUPC_MASK               255U
#define MMCPCL_CPUPC_BITNUM             0U


/*** DBGC1 - Debug Control Register 1; 0x00000100 ***/
typedef union {
  byte Byte;
  struct {
    byte EEVE        :2;                                       /* External Event Enable Bits */
    byte             :1; 
    byte BRKCPU      :1;                                       /* CPU Breakpoint Enable */
    byte BDMBP       :1;                                       /* Background Debug Mode Enable */
    byte             :1; 
    byte TRIG        :1;                                       /* Immediate Trigger Request Bit */
    byte ARM         :1;                                       /* Arm Bit */
  } Bits;
} DBGC1STR;
extern volatile DBGC1STR _DBGC1 @0x00000100;
#define DBGC1                           _DBGC1.Byte
#define DBGC1_EEVE                      _DBGC1.Bits.EEVE
#define DBGC1_BRKCPU                    _DBGC1.Bits.BRKCPU
#define DBGC1_BDMBP                     _DBGC1.Bits.BDMBP
#define DBGC1_TRIG                      _DBGC1.Bits.TRIG
#define DBGC1_ARM                       _DBGC1.Bits.ARM

#define DBGC1_EEVE_MASK                 3U
#define DBGC1_EEVE_BITNUM               0U
#define DBGC1_BRKCPU_MASK               8U
#define DBGC1_BDMBP_MASK                16U
#define DBGC1_TRIG_MASK                 64U
#define DBGC1_ARM_MASK                  128U


/*** DBGC2 - Debug Control Register 2; 0x00000101 ***/
typedef union {
  byte Byte;
  struct {
    byte ABCM        :2;                                       /* A and B Comparator Match Control */
    byte CDCM        :2;                                       /* C and D Comparator Match Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} DBGC2STR;
extern volatile DBGC2STR _DBGC2 @0x00000101;
#define DBGC2                           _DBGC2.Byte
#define DBGC2_ABCM                      _DBGC2.Bits.ABCM
#define DBGC2_CDCM                      _DBGC2.Bits.CDCM

#define DBGC2_ABCM_MASK                 3U
#define DBGC2_ABCM_BITNUM               0U
#define DBGC2_CDCM_MASK                 12U
#define DBGC2_CDCM_BITNUM               2U


/*** DBGTCRH - Debug Trace Control Register High; 0x00000102 ***/
typedef union {
  byte Byte;
  struct {
    byte TALIGN      :2;                                       /* Trigger Align Bits */
    byte TRCMOD      :2;                                       /* Trace Mode Bits */
    byte TRANGE      :2;                                       /* Trace Range Bits */
    byte TSOURCE     :1;                                       /* Trace Source Control Bits */
    byte             :1; 
  } Bits;
} DBGTCRHSTR;
extern volatile DBGTCRHSTR _DBGTCRH @0x00000102;
#define DBGTCRH                         _DBGTCRH.Byte
#define DBGTCRH_TALIGN                  _DBGTCRH.Bits.TALIGN
#define DBGTCRH_TRCMOD                  _DBGTCRH.Bits.TRCMOD
#define DBGTCRH_TRANGE                  _DBGTCRH.Bits.TRANGE
#define DBGTCRH_TSOURCE                 _DBGTCRH.Bits.TSOURCE

#define DBGTCRH_TALIGN_MASK             3U
#define DBGTCRH_TALIGN_BITNUM           0U
#define DBGTCRH_TRCMOD_MASK             12U
#define DBGTCRH_TRCMOD_BITNUM           2U
#define DBGTCRH_TRANGE_MASK             48U
#define DBGTCRH_TRANGE_BITNUM           4U
#define DBGTCRH_TSOURCE_MASK            64U


/*** DBGTCRL - Debug Trace Control Register Low; 0x00000103 ***/
typedef union {
  byte Byte;
  struct {
    byte STAMP       :1;                                       /* Timestamp Enable */
    byte PROFILE     :1;                                       /* Profile Enable */
    byte PDOE        :1;                                       /* Profile Data Out Enable */
    byte DSTAMP      :1;                                       /* Comparator D Timestamp Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} DBGTCRLSTR;
extern volatile DBGTCRLSTR _DBGTCRL @0x00000103;
#define DBGTCRL                         _DBGTCRL.Byte
#define DBGTCRL_STAMP                   _DBGTCRL.Bits.STAMP
#define DBGTCRL_PROFILE                 _DBGTCRL.Bits.PROFILE
#define DBGTCRL_PDOE                    _DBGTCRL.Bits.PDOE
#define DBGTCRL_DSTAMP                  _DBGTCRL.Bits.DSTAMP

#define DBGTCRL_STAMP_MASK              1U
#define DBGTCRL_PROFILE_MASK            2U
#define DBGTCRL_PDOE_MASK               4U
#define DBGTCRL_DSTAMP_MASK             8U


/*** DBGTB - Debug Trace Buffer Register; 0x00000104 ***/
typedef union {
  word Word;
  struct {
    word BIT0        :1;                                       /* Trace Buffer Data Bits */
    word BIT1        :1;                                       /* Trace Buffer Data Bit 1 */
    word BIT2        :1;                                       /* Trace Buffer Data Bit 2 */
    word BIT3        :1;                                       /* Trace Buffer Data Bit 3 */
    word BIT4        :1;                                       /* Trace Buffer Data Bit 4 */
    word BIT5        :1;                                       /* Trace Buffer Data Bit 5 */
    word BIT6        :1;                                       /* Trace Buffer Data Bit 6 */
    word BIT7        :1;                                       /* Trace Buffer Data Bit 7 */
    word BIT8        :1;                                       /* Trace Buffer Data Bit 8 */
    word BIT9        :1;                                       /* Trace Buffer Data Bit 9 */
    word BIT10       :1;                                       /* Trace Buffer Data Bit 10 */
    word BIT11       :1;                                       /* Trace Buffer Data Bit 11 */
    word BIT12       :1;                                       /* Trace Buffer Data Bit 12 */
    word BIT13       :1;                                       /* Trace Buffer Data Bit 13 */
    word BIT14       :1;                                       /* Trace Buffer Data Bit 14 */
    word BIT15       :1;                                       /* Trace Buffer Data Bit 15 */
  } Bits;
} DBGTBSTR;
extern volatile DBGTBSTR _DBGTB @0x00000104;
#define DBGTB                           _DBGTB.Word
#define DBGTB_BIT0                      _DBGTB.Bits.BIT0
#define DBGTB_BIT1                      _DBGTB.Bits.BIT1
#define DBGTB_BIT2                      _DBGTB.Bits.BIT2
#define DBGTB_BIT3                      _DBGTB.Bits.BIT3
#define DBGTB_BIT4                      _DBGTB.Bits.BIT4
#define DBGTB_BIT5                      _DBGTB.Bits.BIT5
#define DBGTB_BIT6                      _DBGTB.Bits.BIT6
#define DBGTB_BIT7                      _DBGTB.Bits.BIT7
#define DBGTB_BIT8                      _DBGTB.Bits.BIT8
#define DBGTB_BIT9                      _DBGTB.Bits.BIT9
#define DBGTB_BIT10                     _DBGTB.Bits.BIT10
#define DBGTB_BIT11                     _DBGTB.Bits.BIT11
#define DBGTB_BIT12                     _DBGTB.Bits.BIT12
#define DBGTB_BIT13                     _DBGTB.Bits.BIT13
#define DBGTB_BIT14                     _DBGTB.Bits.BIT14
#define DBGTB_BIT15                     _DBGTB.Bits.BIT15

#define DBGTB_BIT0_MASK                 1U
#define DBGTB_BIT1_MASK                 2U
#define DBGTB_BIT2_MASK                 4U
#define DBGTB_BIT3_MASK                 8U
#define DBGTB_BIT4_MASK                 16U
#define DBGTB_BIT5_MASK                 32U
#define DBGTB_BIT6_MASK                 64U
#define DBGTB_BIT7_MASK                 128U
#define DBGTB_BIT8_MASK                 256U
#define DBGTB_BIT9_MASK                 512U
#define DBGTB_BIT10_MASK                1024U
#define DBGTB_BIT11_MASK                2048U
#define DBGTB_BIT12_MASK                4096U
#define DBGTB_BIT13_MASK                8192U
#define DBGTB_BIT14_MASK                16384U
#define DBGTB_BIT15_MASK                32768U


/*** DBGCNT - Debug Count Register; 0x00000106 ***/
typedef union {
  byte Byte;
  struct {
    byte CNT         :7;                                       /* Count Value */
    byte             :1; 
  } Bits;
} DBGCNTSTR;
extern volatile DBGCNTSTR _DBGCNT @0x00000106;
#define DBGCNT                          _DBGCNT.Byte
#define DBGCNT_CNT                      _DBGCNT.Bits.CNT

#define DBGCNT_CNT_MASK                 127U
#define DBGCNT_CNT_BITNUM               0U


/*** DBGSCR1 - Debug State Control Register 1; 0x00000107 ***/
typedef union {
  byte Byte;
  struct {
    byte C0SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C1SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C2SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C3SC        :2;                                       /* Match State Sequencer Transitions Bits */
  } Bits;
} DBGSCR1STR;
extern volatile DBGSCR1STR _DBGSCR1 @0x00000107;
#define DBGSCR1                         _DBGSCR1.Byte
#define DBGSCR1_C0SC                    _DBGSCR1.Bits.C0SC
#define DBGSCR1_C1SC                    _DBGSCR1.Bits.C1SC
#define DBGSCR1_C2SC                    _DBGSCR1.Bits.C2SC
#define DBGSCR1_C3SC                    _DBGSCR1.Bits.C3SC

#define DBGSCR1_C0SC_MASK               3U
#define DBGSCR1_C0SC_BITNUM             0U
#define DBGSCR1_C1SC_MASK               12U
#define DBGSCR1_C1SC_BITNUM             2U
#define DBGSCR1_C2SC_MASK               48U
#define DBGSCR1_C2SC_BITNUM             4U
#define DBGSCR1_C3SC_MASK               192U
#define DBGSCR1_C3SC_BITNUM             6U


/*** DBGSCR2 - Debug State Control Register 2; 0x00000108 ***/
typedef union {
  byte Byte;
  struct {
    byte C0SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C1SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C2SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C3SC        :2;                                       /* Match State Sequencer Transitions Bits */
  } Bits;
} DBGSCR2STR;
extern volatile DBGSCR2STR _DBGSCR2 @0x00000108;
#define DBGSCR2                         _DBGSCR2.Byte
#define DBGSCR2_C0SC                    _DBGSCR2.Bits.C0SC
#define DBGSCR2_C1SC                    _DBGSCR2.Bits.C1SC
#define DBGSCR2_C2SC                    _DBGSCR2.Bits.C2SC
#define DBGSCR2_C3SC                    _DBGSCR2.Bits.C3SC

#define DBGSCR2_C0SC_MASK               3U
#define DBGSCR2_C0SC_BITNUM             0U
#define DBGSCR2_C1SC_MASK               12U
#define DBGSCR2_C1SC_BITNUM             2U
#define DBGSCR2_C2SC_MASK               48U
#define DBGSCR2_C2SC_BITNUM             4U
#define DBGSCR2_C3SC_MASK               192U
#define DBGSCR2_C3SC_BITNUM             6U


/*** DBGSCR3 - Debug State Control Register 3; 0x00000109 ***/
typedef union {
  byte Byte;
  struct {
    byte C0SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C1SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C2SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C3SC        :2;                                       /* Match State Sequencer Transitions Bits */
  } Bits;
} DBGSCR3STR;
extern volatile DBGSCR3STR _DBGSCR3 @0x00000109;
#define DBGSCR3                         _DBGSCR3.Byte
#define DBGSCR3_C0SC                    _DBGSCR3.Bits.C0SC
#define DBGSCR3_C1SC                    _DBGSCR3.Bits.C1SC
#define DBGSCR3_C2SC                    _DBGSCR3.Bits.C2SC
#define DBGSCR3_C3SC                    _DBGSCR3.Bits.C3SC

#define DBGSCR3_C0SC_MASK               3U
#define DBGSCR3_C0SC_BITNUM             0U
#define DBGSCR3_C1SC_MASK               12U
#define DBGSCR3_C1SC_BITNUM             2U
#define DBGSCR3_C2SC_MASK               48U
#define DBGSCR3_C2SC_BITNUM             4U
#define DBGSCR3_C3SC_MASK               192U
#define DBGSCR3_C3SC_BITNUM             6U


/*** DBGEFR - Debug Event Flag Register; 0x0000010A ***/
typedef union {
  byte Byte;
  struct {
    byte ME0         :1;                                       /* Match Event 0 */
    byte ME1         :1;                                       /* Match Event 1 */
    byte ME2         :1;                                       /* Match Event 2 */
    byte ME3         :1;                                       /* Match Event 3 */
    byte EEVF        :1;                                       /* External Event Flag */
    byte             :1; 
    byte TRIGF       :1;                                       /* TRIG Flag */
    byte PTBOVF      :1;                                       /* Profiling Trace Buffer Overflow Flag */
  } Bits;
  struct {
    byte grpME   :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGEFRSTR;
extern volatile DBGEFRSTR _DBGEFR @0x0000010A;
#define DBGEFR                          _DBGEFR.Byte
#define DBGEFR_ME0                      _DBGEFR.Bits.ME0
#define DBGEFR_ME1                      _DBGEFR.Bits.ME1
#define DBGEFR_ME2                      _DBGEFR.Bits.ME2
#define DBGEFR_ME3                      _DBGEFR.Bits.ME3
#define DBGEFR_EEVF                     _DBGEFR.Bits.EEVF
#define DBGEFR_TRIGF                    _DBGEFR.Bits.TRIGF
#define DBGEFR_PTBOVF                   _DBGEFR.Bits.PTBOVF
#define DBGEFR_ME                       _DBGEFR.MergedBits.grpME

#define DBGEFR_ME0_MASK                 1U
#define DBGEFR_ME1_MASK                 2U
#define DBGEFR_ME2_MASK                 4U
#define DBGEFR_ME3_MASK                 8U
#define DBGEFR_EEVF_MASK                16U
#define DBGEFR_TRIGF_MASK               64U
#define DBGEFR_PTBOVF_MASK              128U
#define DBGEFR_ME_MASK                  15U
#define DBGEFR_ME_BITNUM                0U


/*** DBGSR - Debug Status Register; 0x0000010B ***/
typedef union {
  byte Byte;
  struct {
    byte SSF0        :1;                                       /* State Sequencer Flag Bits */
    byte SSF1        :1;                                       /* State Sequencer Flag Bit 1 */
    byte SSF2        :1;                                       /* State Sequencer Flag Bit 2 */
    byte             :1; 
    byte PTACT       :1;                                       /* Profiling Transmission Active */
    byte             :1; 
    byte             :1; 
    byte TBF         :1;                                       /* Trace Buffer Full */
  } Bits;
  struct {
    byte grpSSF  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGSRSTR;
extern volatile DBGSRSTR _DBGSR @0x0000010B;
#define DBGSR                           _DBGSR.Byte
#define DBGSR_SSF0                      _DBGSR.Bits.SSF0
#define DBGSR_SSF1                      _DBGSR.Bits.SSF1
#define DBGSR_SSF2                      _DBGSR.Bits.SSF2
#define DBGSR_PTACT                     _DBGSR.Bits.PTACT
#define DBGSR_TBF                       _DBGSR.Bits.TBF
#define DBGSR_SSF                       _DBGSR.MergedBits.grpSSF

#define DBGSR_SSF0_MASK                 1U
#define DBGSR_SSF1_MASK                 2U
#define DBGSR_SSF2_MASK                 4U
#define DBGSR_PTACT_MASK                16U
#define DBGSR_TBF_MASK                  128U
#define DBGSR_SSF_MASK                  7U
#define DBGSR_SSF_BITNUM                0U


/*** DBGACTL - Debug Comparator A Control Register; 0x00000110 ***/
typedef union {
  byte Byte;
  struct {
    byte COMPE       :1;                                       /* Determines if comparator is enabled */
    byte             :1; 
    byte RWE         :1;                                       /* Read/Write Enable Bit */
    byte RW          :1;                                       /* Read/Write Comparator Value Bit */
    byte             :1; 
    byte INST        :1;                                       /* Instruction Select */
    byte NDB         :1;                                       /* Not Data Bus */
    byte             :1; 
  } Bits;
} DBGACTLSTR;
extern volatile DBGACTLSTR _DBGACTL @0x00000110;
#define DBGACTL                         _DBGACTL.Byte
#define DBGACTL_COMPE                   _DBGACTL.Bits.COMPE
#define DBGACTL_RWE                     _DBGACTL.Bits.RWE
#define DBGACTL_RW                      _DBGACTL.Bits.RW
#define DBGACTL_INST                    _DBGACTL.Bits.INST
#define DBGACTL_NDB                     _DBGACTL.Bits.NDB

#define DBGACTL_COMPE_MASK              1U
#define DBGACTL_RWE_MASK                4U
#define DBGACTL_RW_MASK                 8U
#define DBGACTL_INST_MASK               32U
#define DBGACTL_NDB_MASK                64U


/*** DBGAAH - Debug Comparator A Address Register High; 0x00000115 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGAA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGAAHSTR;
extern volatile DBGAAHSTR _DBGAAH @0x00000115;
#define DBGAAH                          _DBGAAH.Byte
#define DBGAAH_DBGAA                    _DBGAAH.Bits.DBGAA

#define DBGAAH_DBGAA_MASK               255U
#define DBGAAH_DBGAA_BITNUM             0U


/*** DBGAAM - Debug Comparator A Address Register Middle; 0x00000116 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGAA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGAAMSTR;
extern volatile DBGAAMSTR _DBGAAM @0x00000116;
#define DBGAAM                          _DBGAAM.Byte
#define DBGAAM_DBGAA                    _DBGAAM.Bits.DBGAA

#define DBGAAM_DBGAA_MASK               255U
#define DBGAAM_DBGAA_BITNUM             0U


/*** DBGAAL - Debug Comparator A Address Register Low; 0x00000117 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGAA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGAALSTR;
extern volatile DBGAALSTR _DBGAAL @0x00000117;
#define DBGAAL                          _DBGAAL.Byte
#define DBGAAL_DBGAA                    _DBGAAL.Bits.DBGAA

#define DBGAAL_DBGAA_MASK               255U
#define DBGAAL_DBGAA_BITNUM             0U


/*** DBGAD0 - Debug Comparator A Data Register 0; 0x00000118 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT24       :1;                                       /* Comparator Data Bit 24 */
    byte BIT25       :1;                                       /* Comparator Data Bit 25 */
    byte BIT26       :1;                                       /* Comparator Data Bit 26 */
    byte BIT27       :1;                                       /* Comparator Data Bit 27 */
    byte BIT28       :1;                                       /* Comparator Data Bit 28 */
    byte BIT29       :1;                                       /* Comparator Data Bit 29 */
    byte BIT30       :1;                                       /* Comparator Data Bit 30 */
    byte BIT31       :1;                                       /* Comparator Data Bit 31 */
  } Bits;
} DBGAD0STR;
extern volatile DBGAD0STR _DBGAD0 @0x00000118;
#define DBGAD0                          _DBGAD0.Byte
#define DBGAD0_BIT24                    _DBGAD0.Bits.BIT24
#define DBGAD0_BIT25                    _DBGAD0.Bits.BIT25
#define DBGAD0_BIT26                    _DBGAD0.Bits.BIT26
#define DBGAD0_BIT27                    _DBGAD0.Bits.BIT27
#define DBGAD0_BIT28                    _DBGAD0.Bits.BIT28
#define DBGAD0_BIT29                    _DBGAD0.Bits.BIT29
#define DBGAD0_BIT30                    _DBGAD0.Bits.BIT30
#define DBGAD0_BIT31                    _DBGAD0.Bits.BIT31
/* DBGAD_ARR: Access 4 DBGADx registers in an array */
#define DBGAD_ARR                       ((volatile byte *) &DBGAD0)

#define DBGAD0_BIT24_MASK               1U
#define DBGAD0_BIT25_MASK               2U
#define DBGAD0_BIT26_MASK               4U
#define DBGAD0_BIT27_MASK               8U
#define DBGAD0_BIT28_MASK               16U
#define DBGAD0_BIT29_MASK               32U
#define DBGAD0_BIT30_MASK               64U
#define DBGAD0_BIT31_MASK               128U


/*** DBGAD1 - Debug Comparator A Data Register 1; 0x00000119 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT16       :1;                                       /* Comparator Data Bit 16 */
    byte BIT17       :1;                                       /* Comparator Data Bit 17 */
    byte BIT18       :1;                                       /* Comparator Data Bit 18 */
    byte BIT19       :1;                                       /* Comparator Data Bit 19 */
    byte BIT20       :1;                                       /* Comparator Data Bit 20 */
    byte BIT21       :1;                                       /* Comparator Data Bit 21 */
    byte BIT22       :1;                                       /* Comparator Data Bit 22 */
    byte BIT23       :1;                                       /* Comparator Data Bit 23 */
  } Bits;
} DBGAD1STR;
extern volatile DBGAD1STR _DBGAD1 @0x00000119;
#define DBGAD1                          _DBGAD1.Byte
#define DBGAD1_BIT16                    _DBGAD1.Bits.BIT16
#define DBGAD1_BIT17                    _DBGAD1.Bits.BIT17
#define DBGAD1_BIT18                    _DBGAD1.Bits.BIT18
#define DBGAD1_BIT19                    _DBGAD1.Bits.BIT19
#define DBGAD1_BIT20                    _DBGAD1.Bits.BIT20
#define DBGAD1_BIT21                    _DBGAD1.Bits.BIT21
#define DBGAD1_BIT22                    _DBGAD1.Bits.BIT22
#define DBGAD1_BIT23                    _DBGAD1.Bits.BIT23

#define DBGAD1_BIT16_MASK               1U
#define DBGAD1_BIT17_MASK               2U
#define DBGAD1_BIT18_MASK               4U
#define DBGAD1_BIT19_MASK               8U
#define DBGAD1_BIT20_MASK               16U
#define DBGAD1_BIT21_MASK               32U
#define DBGAD1_BIT22_MASK               64U
#define DBGAD1_BIT23_MASK               128U


/*** DBGAD2 - Debug Comparator A Data Register 2; 0x0000011A ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data Bit 15 */
  } Bits;
} DBGAD2STR;
extern volatile DBGAD2STR _DBGAD2 @0x0000011A;
#define DBGAD2                          _DBGAD2.Byte
#define DBGAD2_BIT8                     _DBGAD2.Bits.BIT8
#define DBGAD2_BIT9                     _DBGAD2.Bits.BIT9
#define DBGAD2_BIT10                    _DBGAD2.Bits.BIT10
#define DBGAD2_BIT11                    _DBGAD2.Bits.BIT11
#define DBGAD2_BIT12                    _DBGAD2.Bits.BIT12
#define DBGAD2_BIT13                    _DBGAD2.Bits.BIT13
#define DBGAD2_BIT14                    _DBGAD2.Bits.BIT14
#define DBGAD2_BIT15                    _DBGAD2.Bits.BIT15

#define DBGAD2_BIT8_MASK                1U
#define DBGAD2_BIT9_MASK                2U
#define DBGAD2_BIT10_MASK               4U
#define DBGAD2_BIT11_MASK               8U
#define DBGAD2_BIT12_MASK               16U
#define DBGAD2_BIT13_MASK               32U
#define DBGAD2_BIT14_MASK               64U
#define DBGAD2_BIT15_MASK               128U


/*** DBGAD3 - Debug Comparator A Data Register 3; 0x0000011B ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Bit 7 */
  } Bits;
} DBGAD3STR;
extern volatile DBGAD3STR _DBGAD3 @0x0000011B;
#define DBGAD3                          _DBGAD3.Byte
#define DBGAD3_BIT0                     _DBGAD3.Bits.BIT0
#define DBGAD3_BIT1                     _DBGAD3.Bits.BIT1
#define DBGAD3_BIT2                     _DBGAD3.Bits.BIT2
#define DBGAD3_BIT3                     _DBGAD3.Bits.BIT3
#define DBGAD3_BIT4                     _DBGAD3.Bits.BIT4
#define DBGAD3_BIT5                     _DBGAD3.Bits.BIT5
#define DBGAD3_BIT6                     _DBGAD3.Bits.BIT6
#define DBGAD3_BIT7                     _DBGAD3.Bits.BIT7

#define DBGAD3_BIT0_MASK                1U
#define DBGAD3_BIT1_MASK                2U
#define DBGAD3_BIT2_MASK                4U
#define DBGAD3_BIT3_MASK                8U
#define DBGAD3_BIT4_MASK                16U
#define DBGAD3_BIT5_MASK                32U
#define DBGAD3_BIT6_MASK                64U
#define DBGAD3_BIT7_MASK                128U


/*** DBGADM0 - Debug Comparator A Data Mask Register 0; 0x0000011C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT24       :1;                                       /* Comparator Data Mask Bit 24 */
    byte BIT25       :1;                                       /* Comparator Data Mask Bit 25 */
    byte BIT26       :1;                                       /* Comparator Data Mask Bit 26 */
    byte BIT27       :1;                                       /* Comparator Data Mask Bit 27 */
    byte BIT28       :1;                                       /* Comparator Data Mask Bit 28 */
    byte BIT29       :1;                                       /* Comparator Data Mask Bit 29 */
    byte BIT30       :1;                                       /* Comparator Data Mask Bit 30 */
    byte BIT31       :1;                                       /* Comparator Data Mask Bit 31 */
  } Bits;
} DBGADM0STR;
extern volatile DBGADM0STR _DBGADM0 @0x0000011C;
#define DBGADM0                         _DBGADM0.Byte
#define DBGADM0_BIT24                   _DBGADM0.Bits.BIT24
#define DBGADM0_BIT25                   _DBGADM0.Bits.BIT25
#define DBGADM0_BIT26                   _DBGADM0.Bits.BIT26
#define DBGADM0_BIT27                   _DBGADM0.Bits.BIT27
#define DBGADM0_BIT28                   _DBGADM0.Bits.BIT28
#define DBGADM0_BIT29                   _DBGADM0.Bits.BIT29
#define DBGADM0_BIT30                   _DBGADM0.Bits.BIT30
#define DBGADM0_BIT31                   _DBGADM0.Bits.BIT31
/* DBGADM_ARR: Access 4 DBGADMx registers in an array */
#define DBGADM_ARR                      ((volatile byte *) &DBGADM0)

#define DBGADM0_BIT24_MASK              1U
#define DBGADM0_BIT25_MASK              2U
#define DBGADM0_BIT26_MASK              4U
#define DBGADM0_BIT27_MASK              8U
#define DBGADM0_BIT28_MASK              16U
#define DBGADM0_BIT29_MASK              32U
#define DBGADM0_BIT30_MASK              64U
#define DBGADM0_BIT31_MASK              128U


/*** DBGADM1 - Debug Comparator A Data Mask Register 1; 0x0000011D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT16       :1;                                       /* Comparator Data Mask Bit 16 */
    byte BIT17       :1;                                       /* Comparator Data Mask Bit 17 */
    byte BIT18       :1;                                       /* Comparator Data Mask Bit 18 */
    byte BIT19       :1;                                       /* Comparator Data Mask Bit 19 */
    byte BIT20       :1;                                       /* Comparator Data Mask Bit 20 */
    byte BIT21       :1;                                       /* Comparator Data Mask Bit 21 */
    byte BIT22       :1;                                       /* Comparator Data Mask Bit 22 */
    byte BIT23       :1;                                       /* Comparator Data Mask Bit 23 */
  } Bits;
} DBGADM1STR;
extern volatile DBGADM1STR _DBGADM1 @0x0000011D;
#define DBGADM1                         _DBGADM1.Byte
#define DBGADM1_BIT16                   _DBGADM1.Bits.BIT16
#define DBGADM1_BIT17                   _DBGADM1.Bits.BIT17
#define DBGADM1_BIT18                   _DBGADM1.Bits.BIT18
#define DBGADM1_BIT19                   _DBGADM1.Bits.BIT19
#define DBGADM1_BIT20                   _DBGADM1.Bits.BIT20
#define DBGADM1_BIT21                   _DBGADM1.Bits.BIT21
#define DBGADM1_BIT22                   _DBGADM1.Bits.BIT22
#define DBGADM1_BIT23                   _DBGADM1.Bits.BIT23

#define DBGADM1_BIT16_MASK              1U
#define DBGADM1_BIT17_MASK              2U
#define DBGADM1_BIT18_MASK              4U
#define DBGADM1_BIT19_MASK              8U
#define DBGADM1_BIT20_MASK              16U
#define DBGADM1_BIT21_MASK              32U
#define DBGADM1_BIT22_MASK              64U
#define DBGADM1_BIT23_MASK              128U


/*** DBGADM2 - Debug Comparator A Data Mask Register 2; 0x0000011E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data Mask Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data Mask Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data Mask Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data Mask Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data Mask Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data Mask Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data Mask Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data Mask Bit 15 */
  } Bits;
} DBGADM2STR;
extern volatile DBGADM2STR _DBGADM2 @0x0000011E;
#define DBGADM2                         _DBGADM2.Byte
#define DBGADM2_BIT8                    _DBGADM2.Bits.BIT8
#define DBGADM2_BIT9                    _DBGADM2.Bits.BIT9
#define DBGADM2_BIT10                   _DBGADM2.Bits.BIT10
#define DBGADM2_BIT11                   _DBGADM2.Bits.BIT11
#define DBGADM2_BIT12                   _DBGADM2.Bits.BIT12
#define DBGADM2_BIT13                   _DBGADM2.Bits.BIT13
#define DBGADM2_BIT14                   _DBGADM2.Bits.BIT14
#define DBGADM2_BIT15                   _DBGADM2.Bits.BIT15

#define DBGADM2_BIT8_MASK               1U
#define DBGADM2_BIT9_MASK               2U
#define DBGADM2_BIT10_MASK              4U
#define DBGADM2_BIT11_MASK              8U
#define DBGADM2_BIT12_MASK              16U
#define DBGADM2_BIT13_MASK              32U
#define DBGADM2_BIT14_MASK              64U
#define DBGADM2_BIT15_MASK              128U


/*** DBGADM3 - Debug Comparator A Data Mask Register 3; 0x0000011F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Mask Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Mask Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Mask Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Mask Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Mask Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Mask Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Mask Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Mask Bit 7 */
  } Bits;
} DBGADM3STR;
extern volatile DBGADM3STR _DBGADM3 @0x0000011F;
#define DBGADM3                         _DBGADM3.Byte
#define DBGADM3_BIT0                    _DBGADM3.Bits.BIT0
#define DBGADM3_BIT1                    _DBGADM3.Bits.BIT1
#define DBGADM3_BIT2                    _DBGADM3.Bits.BIT2
#define DBGADM3_BIT3                    _DBGADM3.Bits.BIT3
#define DBGADM3_BIT4                    _DBGADM3.Bits.BIT4
#define DBGADM3_BIT5                    _DBGADM3.Bits.BIT5
#define DBGADM3_BIT6                    _DBGADM3.Bits.BIT6
#define DBGADM3_BIT7                    _DBGADM3.Bits.BIT7

#define DBGADM3_BIT0_MASK               1U
#define DBGADM3_BIT1_MASK               2U
#define DBGADM3_BIT2_MASK               4U
#define DBGADM3_BIT3_MASK               8U
#define DBGADM3_BIT4_MASK               16U
#define DBGADM3_BIT5_MASK               32U
#define DBGADM3_BIT6_MASK               64U
#define DBGADM3_BIT7_MASK               128U


/*** DBGBCTL - Debug Comparator B Control Register; 0x00000120 ***/
typedef union {
  byte Byte;
  struct {
    byte COMPE       :1;                                       /* Determines if comparator is enabled */
    byte             :1; 
    byte RWE         :1;                                       /* Read/Write Enable Bit */
    byte RW          :1;                                       /* Read/Write Comparator Value Bit */
    byte             :1; 
    byte INST        :1;                                       /* Instruction Select */
    byte             :1; 
    byte             :1; 
  } Bits;
} DBGBCTLSTR;
extern volatile DBGBCTLSTR _DBGBCTL @0x00000120;
#define DBGBCTL                         _DBGBCTL.Byte
#define DBGBCTL_COMPE                   _DBGBCTL.Bits.COMPE
#define DBGBCTL_RWE                     _DBGBCTL.Bits.RWE
#define DBGBCTL_RW                      _DBGBCTL.Bits.RW
#define DBGBCTL_INST                    _DBGBCTL.Bits.INST

#define DBGBCTL_COMPE_MASK              1U
#define DBGBCTL_RWE_MASK                4U
#define DBGBCTL_RW_MASK                 8U
#define DBGBCTL_INST_MASK               32U


/*** DBGBAH - Debug Comparator B Address Register High; 0x00000125 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGBA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGBAHSTR;
extern volatile DBGBAHSTR _DBGBAH @0x00000125;
#define DBGBAH                          _DBGBAH.Byte
#define DBGBAH_DBGBA                    _DBGBAH.Bits.DBGBA

#define DBGBAH_DBGBA_MASK               255U
#define DBGBAH_DBGBA_BITNUM             0U


/*** DBGBAM - Debug Comparator B Address Register Middle; 0x00000126 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGBA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGBAMSTR;
extern volatile DBGBAMSTR _DBGBAM @0x00000126;
#define DBGBAM                          _DBGBAM.Byte
#define DBGBAM_DBGBA                    _DBGBAM.Bits.DBGBA

#define DBGBAM_DBGBA_MASK               255U
#define DBGBAM_DBGBA_BITNUM             0U


/*** DBGBAL - Debug Comparator B Address Register Low; 0x00000127 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGBA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGBALSTR;
extern volatile DBGBALSTR _DBGBAL @0x00000127;
#define DBGBAL                          _DBGBAL.Byte
#define DBGBAL_DBGBA                    _DBGBAL.Bits.DBGBA

#define DBGBAL_DBGBA_MASK               255U
#define DBGBAL_DBGBA_BITNUM             0U


/*** DBGCCTL - Debug Comparator C Control Register; 0x00000130 ***/
typedef union {
  byte Byte;
  struct {
    byte COMPE       :1;                                       /* Determines if comparator is enabled */
    byte             :1; 
    byte RWE         :1;                                       /* Read/Write Enable Bit */
    byte RW          :1;                                       /* Read/Write Comparator Value Bit */
    byte             :1; 
    byte INST        :1;                                       /* Instruction Select */
    byte NDB         :1;                                       /* Not Data Bus */
    byte             :1; 
  } Bits;
} DBGCCTLSTR;
extern volatile DBGCCTLSTR _DBGCCTL @0x00000130;
#define DBGCCTL                         _DBGCCTL.Byte
#define DBGCCTL_COMPE                   _DBGCCTL.Bits.COMPE
#define DBGCCTL_RWE                     _DBGCCTL.Bits.RWE
#define DBGCCTL_RW                      _DBGCCTL.Bits.RW
#define DBGCCTL_INST                    _DBGCCTL.Bits.INST
#define DBGCCTL_NDB                     _DBGCCTL.Bits.NDB

#define DBGCCTL_COMPE_MASK              1U
#define DBGCCTL_RWE_MASK                4U
#define DBGCCTL_RW_MASK                 8U
#define DBGCCTL_INST_MASK               32U
#define DBGCCTL_NDB_MASK                64U


/*** DBGCAH - Debug Comparator C Address Register High; 0x00000135 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGCA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGCAHSTR;
extern volatile DBGCAHSTR _DBGCAH @0x00000135;
#define DBGCAH                          _DBGCAH.Byte
#define DBGCAH_DBGCA                    _DBGCAH.Bits.DBGCA

#define DBGCAH_DBGCA_MASK               255U
#define DBGCAH_DBGCA_BITNUM             0U


/*** DBGCAM - Debug Comparator C Address Register Middle; 0x00000136 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGCA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGCAMSTR;
extern volatile DBGCAMSTR _DBGCAM @0x00000136;
#define DBGCAM                          _DBGCAM.Byte
#define DBGCAM_DBGCA                    _DBGCAM.Bits.DBGCA

#define DBGCAM_DBGCA_MASK               255U
#define DBGCAM_DBGCA_BITNUM             0U


/*** DBGCAL - Debug Comparator C Address Register Low; 0x00000137 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGCA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGCALSTR;
extern volatile DBGCALSTR _DBGCAL @0x00000137;
#define DBGCAL                          _DBGCAL.Byte
#define DBGCAL_DBGCA                    _DBGCAL.Bits.DBGCA

#define DBGCAL_DBGCA_MASK               255U
#define DBGCAL_DBGCA_BITNUM             0U


/*** DBGCD0 - Debug Comparator C Data Register 0; 0x00000138 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT24       :1;                                       /* Comparator Data Bit 24 */
    byte BIT25       :1;                                       /* Comparator Data Bit 25 */
    byte BIT26       :1;                                       /* Comparator Data Bit 26 */
    byte BIT27       :1;                                       /* Comparator Data Bit 27 */
    byte BIT28       :1;                                       /* Comparator Data Bit 28 */
    byte BIT29       :1;                                       /* Comparator Data Bit 29 */
    byte BIT30       :1;                                       /* Comparator Data Bit 30 */
    byte BIT31       :1;                                       /* Comparator Data Bit 31 */
  } Bits;
} DBGCD0STR;
extern volatile DBGCD0STR _DBGCD0 @0x00000138;
#define DBGCD0                          _DBGCD0.Byte
#define DBGCD0_BIT24                    _DBGCD0.Bits.BIT24
#define DBGCD0_BIT25                    _DBGCD0.Bits.BIT25
#define DBGCD0_BIT26                    _DBGCD0.Bits.BIT26
#define DBGCD0_BIT27                    _DBGCD0.Bits.BIT27
#define DBGCD0_BIT28                    _DBGCD0.Bits.BIT28
#define DBGCD0_BIT29                    _DBGCD0.Bits.BIT29
#define DBGCD0_BIT30                    _DBGCD0.Bits.BIT30
#define DBGCD0_BIT31                    _DBGCD0.Bits.BIT31
/* DBGCD_ARR: Access 4 DBGCDx registers in an array */
#define DBGCD_ARR                       ((volatile byte *) &DBGCD0)

#define DBGCD0_BIT24_MASK               1U
#define DBGCD0_BIT25_MASK               2U
#define DBGCD0_BIT26_MASK               4U
#define DBGCD0_BIT27_MASK               8U
#define DBGCD0_BIT28_MASK               16U
#define DBGCD0_BIT29_MASK               32U
#define DBGCD0_BIT30_MASK               64U
#define DBGCD0_BIT31_MASK               128U


/*** DBGCD1 - Debug Comparator C Data Register 1; 0x00000139 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT16       :1;                                       /* Comparator Data Bit 16 */
    byte BIT17       :1;                                       /* Comparator Data Bit 17 */
    byte BIT18       :1;                                       /* Comparator Data Bit 18 */
    byte BIT19       :1;                                       /* Comparator Data Bit 19 */
    byte BIT20       :1;                                       /* Comparator Data Bit 20 */
    byte BIT21       :1;                                       /* Comparator Data Bit 21 */
    byte BIT22       :1;                                       /* Comparator Data Bit 22 */
    byte BIT23       :1;                                       /* Comparator Data Bit 23 */
  } Bits;
} DBGCD1STR;
extern volatile DBGCD1STR _DBGCD1 @0x00000139;
#define DBGCD1                          _DBGCD1.Byte
#define DBGCD1_BIT16                    _DBGCD1.Bits.BIT16
#define DBGCD1_BIT17                    _DBGCD1.Bits.BIT17
#define DBGCD1_BIT18                    _DBGCD1.Bits.BIT18
#define DBGCD1_BIT19                    _DBGCD1.Bits.BIT19
#define DBGCD1_BIT20                    _DBGCD1.Bits.BIT20
#define DBGCD1_BIT21                    _DBGCD1.Bits.BIT21
#define DBGCD1_BIT22                    _DBGCD1.Bits.BIT22
#define DBGCD1_BIT23                    _DBGCD1.Bits.BIT23

#define DBGCD1_BIT16_MASK               1U
#define DBGCD1_BIT17_MASK               2U
#define DBGCD1_BIT18_MASK               4U
#define DBGCD1_BIT19_MASK               8U
#define DBGCD1_BIT20_MASK               16U
#define DBGCD1_BIT21_MASK               32U
#define DBGCD1_BIT22_MASK               64U
#define DBGCD1_BIT23_MASK               128U


/*** DBGCD2 - Debug Comparator C Data Register 2; 0x0000013A ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data Bit 15 */
  } Bits;
} DBGCD2STR;
extern volatile DBGCD2STR _DBGCD2 @0x0000013A;
#define DBGCD2                          _DBGCD2.Byte
#define DBGCD2_BIT8                     _DBGCD2.Bits.BIT8
#define DBGCD2_BIT9                     _DBGCD2.Bits.BIT9
#define DBGCD2_BIT10                    _DBGCD2.Bits.BIT10
#define DBGCD2_BIT11                    _DBGCD2.Bits.BIT11
#define DBGCD2_BIT12                    _DBGCD2.Bits.BIT12
#define DBGCD2_BIT13                    _DBGCD2.Bits.BIT13
#define DBGCD2_BIT14                    _DBGCD2.Bits.BIT14
#define DBGCD2_BIT15                    _DBGCD2.Bits.BIT15

#define DBGCD2_BIT8_MASK                1U
#define DBGCD2_BIT9_MASK                2U
#define DBGCD2_BIT10_MASK               4U
#define DBGCD2_BIT11_MASK               8U
#define DBGCD2_BIT12_MASK               16U
#define DBGCD2_BIT13_MASK               32U
#define DBGCD2_BIT14_MASK               64U
#define DBGCD2_BIT15_MASK               128U


/*** DBGCD3 - Debug Comparator C Data Register 3; 0x0000013B ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Bit 7 */
  } Bits;
} DBGCD3STR;
extern volatile DBGCD3STR _DBGCD3 @0x0000013B;
#define DBGCD3                          _DBGCD3.Byte
#define DBGCD3_BIT0                     _DBGCD3.Bits.BIT0
#define DBGCD3_BIT1                     _DBGCD3.Bits.BIT1
#define DBGCD3_BIT2                     _DBGCD3.Bits.BIT2
#define DBGCD3_BIT3                     _DBGCD3.Bits.BIT3
#define DBGCD3_BIT4                     _DBGCD3.Bits.BIT4
#define DBGCD3_BIT5                     _DBGCD3.Bits.BIT5
#define DBGCD3_BIT6                     _DBGCD3.Bits.BIT6
#define DBGCD3_BIT7                     _DBGCD3.Bits.BIT7

#define DBGCD3_BIT0_MASK                1U
#define DBGCD3_BIT1_MASK                2U
#define DBGCD3_BIT2_MASK                4U
#define DBGCD3_BIT3_MASK                8U
#define DBGCD3_BIT4_MASK                16U
#define DBGCD3_BIT5_MASK                32U
#define DBGCD3_BIT6_MASK                64U
#define DBGCD3_BIT7_MASK                128U


/*** DBGCDM0 - Debug Comparator C Data Mask Register 0; 0x0000013C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT24       :1;                                       /* Comparator Data Mask Bit 24 */
    byte BIT25       :1;                                       /* Comparator Data Mask Bit 25 */
    byte BIT26       :1;                                       /* Comparator Data Mask Bit 26 */
    byte BIT27       :1;                                       /* Comparator Data Mask Bit 27 */
    byte BIT28       :1;                                       /* Comparator Data Mask Bit 28 */
    byte BIT29       :1;                                       /* Comparator Data Mask Bit 29 */
    byte BIT30       :1;                                       /* Comparator Data Mask Bit 30 */
    byte BIT31       :1;                                       /* Comparator Data Mask Bit 31 */
  } Bits;
} DBGCDM0STR;
extern volatile DBGCDM0STR _DBGCDM0 @0x0000013C;
#define DBGCDM0                         _DBGCDM0.Byte
#define DBGCDM0_BIT24                   _DBGCDM0.Bits.BIT24
#define DBGCDM0_BIT25                   _DBGCDM0.Bits.BIT25
#define DBGCDM0_BIT26                   _DBGCDM0.Bits.BIT26
#define DBGCDM0_BIT27                   _DBGCDM0.Bits.BIT27
#define DBGCDM0_BIT28                   _DBGCDM0.Bits.BIT28
#define DBGCDM0_BIT29                   _DBGCDM0.Bits.BIT29
#define DBGCDM0_BIT30                   _DBGCDM0.Bits.BIT30
#define DBGCDM0_BIT31                   _DBGCDM0.Bits.BIT31
/* DBGCDM_ARR: Access 4 DBGCDMx registers in an array */
#define DBGCDM_ARR                      ((volatile byte *) &DBGCDM0)

#define DBGCDM0_BIT24_MASK              1U
#define DBGCDM0_BIT25_MASK              2U
#define DBGCDM0_BIT26_MASK              4U
#define DBGCDM0_BIT27_MASK              8U
#define DBGCDM0_BIT28_MASK              16U
#define DBGCDM0_BIT29_MASK              32U
#define DBGCDM0_BIT30_MASK              64U
#define DBGCDM0_BIT31_MASK              128U


/*** DBGCDM1 - Debug Comparator C Data Mask Register 1; 0x0000013D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT16       :1;                                       /* Comparator Data Mask Bit 16 */
    byte BIT17       :1;                                       /* Comparator Data Mask Bit 17 */
    byte BIT18       :1;                                       /* Comparator Data Mask Bit 18 */
    byte BIT19       :1;                                       /* Comparator Data Mask Bit 19 */
    byte BIT20       :1;                                       /* Comparator Data Mask Bit 20 */
    byte BIT21       :1;                                       /* Comparator Data Mask Bit 21 */
    byte BIT22       :1;                                       /* Comparator Data Mask Bit 22 */
    byte BIT23       :1;                                       /* Comparator Data Mask Bit 23 */
  } Bits;
} DBGCDM1STR;
extern volatile DBGCDM1STR _DBGCDM1 @0x0000013D;
#define DBGCDM1                         _DBGCDM1.Byte
#define DBGCDM1_BIT16                   _DBGCDM1.Bits.BIT16
#define DBGCDM1_BIT17                   _DBGCDM1.Bits.BIT17
#define DBGCDM1_BIT18                   _DBGCDM1.Bits.BIT18
#define DBGCDM1_BIT19                   _DBGCDM1.Bits.BIT19
#define DBGCDM1_BIT20                   _DBGCDM1.Bits.BIT20
#define DBGCDM1_BIT21                   _DBGCDM1.Bits.BIT21
#define DBGCDM1_BIT22                   _DBGCDM1.Bits.BIT22
#define DBGCDM1_BIT23                   _DBGCDM1.Bits.BIT23

#define DBGCDM1_BIT16_MASK              1U
#define DBGCDM1_BIT17_MASK              2U
#define DBGCDM1_BIT18_MASK              4U
#define DBGCDM1_BIT19_MASK              8U
#define DBGCDM1_BIT20_MASK              16U
#define DBGCDM1_BIT21_MASK              32U
#define DBGCDM1_BIT22_MASK              64U
#define DBGCDM1_BIT23_MASK              128U


/*** DBGCDM2 - Debug Comparator C Data Mask Register 2; 0x0000013E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data Mask Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data Mask Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data Mask Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data Mask Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data Mask Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data Mask Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data Mask Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data Mask Bit 15 */
  } Bits;
} DBGCDM2STR;
extern volatile DBGCDM2STR _DBGCDM2 @0x0000013E;
#define DBGCDM2                         _DBGCDM2.Byte
#define DBGCDM2_BIT8                    _DBGCDM2.Bits.BIT8
#define DBGCDM2_BIT9                    _DBGCDM2.Bits.BIT9
#define DBGCDM2_BIT10                   _DBGCDM2.Bits.BIT10
#define DBGCDM2_BIT11                   _DBGCDM2.Bits.BIT11
#define DBGCDM2_BIT12                   _DBGCDM2.Bits.BIT12
#define DBGCDM2_BIT13                   _DBGCDM2.Bits.BIT13
#define DBGCDM2_BIT14                   _DBGCDM2.Bits.BIT14
#define DBGCDM2_BIT15                   _DBGCDM2.Bits.BIT15

#define DBGCDM2_BIT8_MASK               1U
#define DBGCDM2_BIT9_MASK               2U
#define DBGCDM2_BIT10_MASK              4U
#define DBGCDM2_BIT11_MASK              8U
#define DBGCDM2_BIT12_MASK              16U
#define DBGCDM2_BIT13_MASK              32U
#define DBGCDM2_BIT14_MASK              64U
#define DBGCDM2_BIT15_MASK              128U


/*** DBGCDM3 - Debug Comparator C Data Mask Register 3; 0x0000013F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Mask Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Mask Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Mask Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Mask Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Mask Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Mask Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Mask Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Mask Bit 7 */
  } Bits;
} DBGCDM3STR;
extern volatile DBGCDM3STR _DBGCDM3 @0x0000013F;
#define DBGCDM3                         _DBGCDM3.Byte
#define DBGCDM3_BIT0                    _DBGCDM3.Bits.BIT0
#define DBGCDM3_BIT1                    _DBGCDM3.Bits.BIT1
#define DBGCDM3_BIT2                    _DBGCDM3.Bits.BIT2
#define DBGCDM3_BIT3                    _DBGCDM3.Bits.BIT3
#define DBGCDM3_BIT4                    _DBGCDM3.Bits.BIT4
#define DBGCDM3_BIT5                    _DBGCDM3.Bits.BIT5
#define DBGCDM3_BIT6                    _DBGCDM3.Bits.BIT6
#define DBGCDM3_BIT7                    _DBGCDM3.Bits.BIT7

#define DBGCDM3_BIT0_MASK               1U
#define DBGCDM3_BIT1_MASK               2U
#define DBGCDM3_BIT2_MASK               4U
#define DBGCDM3_BIT3_MASK               8U
#define DBGCDM3_BIT4_MASK               16U
#define DBGCDM3_BIT5_MASK               32U
#define DBGCDM3_BIT6_MASK               64U
#define DBGCDM3_BIT7_MASK               128U


/*** DBGDCTL - Debug Comparator D Control Register; 0x00000140 ***/
typedef union {
  byte Byte;
  struct {
    byte COMPE       :1;                                       /* Determines if comparator is enabled */
    byte             :1; 
    byte RWE         :1;                                       /* Read/Write Enable Bit */
    byte RW          :1;                                       /* Read/Write Comparator Value Bit */
    byte             :1; 
    byte INST        :1;                                       /* Instruction Select */
    byte             :1; 
    byte             :1; 
  } Bits;
} DBGDCTLSTR;
extern volatile DBGDCTLSTR _DBGDCTL @0x00000140;
#define DBGDCTL                         _DBGDCTL.Byte
#define DBGDCTL_COMPE                   _DBGDCTL.Bits.COMPE
#define DBGDCTL_RWE                     _DBGDCTL.Bits.RWE
#define DBGDCTL_RW                      _DBGDCTL.Bits.RW
#define DBGDCTL_INST                    _DBGDCTL.Bits.INST

#define DBGDCTL_COMPE_MASK              1U
#define DBGDCTL_RWE_MASK                4U
#define DBGDCTL_RW_MASK                 8U
#define DBGDCTL_INST_MASK               32U


/*** DBGDAH - Debug Comparator D Address Register High; 0x00000145 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGDA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGDAHSTR;
extern volatile DBGDAHSTR _DBGDAH @0x00000145;
#define DBGDAH                          _DBGDAH.Byte
#define DBGDAH_DBGDA                    _DBGDAH.Bits.DBGDA

#define DBGDAH_DBGDA_MASK               255U
#define DBGDAH_DBGDA_BITNUM             0U


/*** DBGDAM - Debug Comparator D Address Register Middle; 0x00000146 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGDA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGDAMSTR;
extern volatile DBGDAMSTR _DBGDAM @0x00000146;
#define DBGDAM                          _DBGDAM.Byte
#define DBGDAM_DBGDA                    _DBGDAM.Bits.DBGDA

#define DBGDAM_DBGDA_MASK               255U
#define DBGDAM_DBGDA_BITNUM             0U


/*** DBGDAL - Debug Comparator D Address Register Low; 0x00000147 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGDA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGDALSTR;
extern volatile DBGDALSTR _DBGDAL @0x00000147;
#define DBGDAL                          _DBGDAL.Byte
#define DBGDAL_DBGDA                    _DBGDAL.Bits.DBGDA

#define DBGDAL_DBGDA_MASK               255U
#define DBGDAL_DBGDA_BITNUM             0U


/*** PTA - Port A Data Register; 0x00000220 ***/
typedef union {
  byte Byte;
  struct {
    byte PTA0        :1;                                       /* Port A general purpose I/O data 0 */
    byte PTA1        :1;                                       /* Port A general purpose I/O data 1 */
    byte PTA2        :1;                                       /* Port A general purpose I/O data 2 */
    byte PTA3        :1;                                       /* Port A general purpose I/O data 3 */
    byte PTA4        :1;                                       /* Port A general purpose I/O data 4 */
    byte PTA5        :1;                                       /* Port A general purpose I/O data 5 */
    byte PTA6        :1;                                       /* Port A general purpose I/O data 6 */
    byte PTA7        :1;                                       /* Port A general purpose I/O data 7 */
  } Bits;
} PTASTR;
extern volatile PTASTR _PTA @0x00000220;
#define PTA                             _PTA.Byte
#define PTA_PTA0                        _PTA.Bits.PTA0
#define PTA_PTA1                        _PTA.Bits.PTA1
#define PTA_PTA2                        _PTA.Bits.PTA2
#define PTA_PTA3                        _PTA.Bits.PTA3
#define PTA_PTA4                        _PTA.Bits.PTA4
#define PTA_PTA5                        _PTA.Bits.PTA5
#define PTA_PTA6                        _PTA.Bits.PTA6
#define PTA_PTA7                        _PTA.Bits.PTA7

#define PTA_PTA0_MASK                   1U
#define PTA_PTA1_MASK                   2U
#define PTA_PTA2_MASK                   4U
#define PTA_PTA3_MASK                   8U
#define PTA_PTA4_MASK                   16U
#define PTA_PTA5_MASK                   32U
#define PTA_PTA6_MASK                   64U
#define PTA_PTA7_MASK                   128U


/*** PTB - Port B Data Register; 0x00000221 ***/
typedef union {
  byte Byte;
  struct {
    byte PTB0        :1;                                       /* Port B general purpose I/O data 0 */
    byte PTB1        :1;                                       /* Port B general purpose I/O data 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTB  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTBSTR;
extern volatile PTBSTR _PTB @0x00000221;
#define PTB                             _PTB.Byte
#define PTB_PTB0                        _PTB.Bits.PTB0
#define PTB_PTB1                        _PTB.Bits.PTB1
#define PTB_PTB                         _PTB.MergedBits.grpPTB

#define PTB_PTB0_MASK                   1U
#define PTB_PTB1_MASK                   2U
#define PTB_PTB_MASK                    3U
#define PTB_PTB_BITNUM                  0U


/*** PTIA - Port A Input Register; 0x00000222 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIA0       :1;                                       /* Port A data input 0 */
    byte PTIA1       :1;                                       /* Port A data input 1 */
    byte PTIA2       :1;                                       /* Port A data input 2 */
    byte PTIA3       :1;                                       /* Port A data input 3 */
    byte PTIA4       :1;                                       /* Port A data input 4 */
    byte PTIA5       :1;                                       /* Port A data input 5 */
    byte PTIA6       :1;                                       /* Port A data input 6 */
    byte PTIA7       :1;                                       /* Port A data input 7 */
  } Bits;
} PTIASTR;
extern volatile PTIASTR _PTIA @0x00000222;
#define PTIA                            _PTIA.Byte
#define PTIA_PTIA0                      _PTIA.Bits.PTIA0
#define PTIA_PTIA1                      _PTIA.Bits.PTIA1
#define PTIA_PTIA2                      _PTIA.Bits.PTIA2
#define PTIA_PTIA3                      _PTIA.Bits.PTIA3
#define PTIA_PTIA4                      _PTIA.Bits.PTIA4
#define PTIA_PTIA5                      _PTIA.Bits.PTIA5
#define PTIA_PTIA6                      _PTIA.Bits.PTIA6
#define PTIA_PTIA7                      _PTIA.Bits.PTIA7

#define PTIA_PTIA0_MASK                 1U
#define PTIA_PTIA1_MASK                 2U
#define PTIA_PTIA2_MASK                 4U
#define PTIA_PTIA3_MASK                 8U
#define PTIA_PTIA4_MASK                 16U
#define PTIA_PTIA5_MASK                 32U
#define PTIA_PTIA6_MASK                 64U
#define PTIA_PTIA7_MASK                 128U


/*** PTIB - Port B Input Register; 0x00000223 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIB0       :1;                                       /* Port B data input 0 */
    byte PTIB1       :1;                                       /* Port B data input 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIB :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTIBSTR;
extern volatile PTIBSTR _PTIB @0x00000223;
#define PTIB                            _PTIB.Byte
#define PTIB_PTIB0                      _PTIB.Bits.PTIB0
#define PTIB_PTIB1                      _PTIB.Bits.PTIB1
#define PTIB_PTIB                       _PTIB.MergedBits.grpPTIB

#define PTIB_PTIB0_MASK                 1U
#define PTIB_PTIB1_MASK                 2U
#define PTIB_PTIB_MASK                  3U
#define PTIB_PTIB_BITNUM                0U


/*** DDRA - Port A Data Direction Register; 0x00000224 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRA0       :1;                                       /* Port A data direction select 0 */
    byte DDRA1       :1;                                       /* Port A data direction select 1 */
    byte DDRA2       :1;                                       /* Port A data direction select 2 */
    byte DDRA3       :1;                                       /* Port A data direction select 3 */
    byte DDRA4       :1;                                       /* Port A data direction select 4 */
    byte DDRA5       :1;                                       /* Port A data direction select 5 */
    byte DDRA6       :1;                                       /* Port A data direction select 6 */
    byte DDRA7       :1;                                       /* Port A data direction select 7 */
  } Bits;
} DDRASTR;
extern volatile DDRASTR _DDRA @0x00000224;
#define DDRA                            _DDRA.Byte
#define DDRA_DDRA0                      _DDRA.Bits.DDRA0
#define DDRA_DDRA1                      _DDRA.Bits.DDRA1
#define DDRA_DDRA2                      _DDRA.Bits.DDRA2
#define DDRA_DDRA3                      _DDRA.Bits.DDRA3
#define DDRA_DDRA4                      _DDRA.Bits.DDRA4
#define DDRA_DDRA5                      _DDRA.Bits.DDRA5
#define DDRA_DDRA6                      _DDRA.Bits.DDRA6
#define DDRA_DDRA7                      _DDRA.Bits.DDRA7

#define DDRA_DDRA0_MASK                 1U
#define DDRA_DDRA1_MASK                 2U
#define DDRA_DDRA2_MASK                 4U
#define DDRA_DDRA3_MASK                 8U
#define DDRA_DDRA4_MASK                 16U
#define DDRA_DDRA5_MASK                 32U
#define DDRA_DDRA6_MASK                 64U
#define DDRA_DDRA7_MASK                 128U


/*** DDRB - Port B Data Direction Register; 0x00000225 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRB0       :1;                                       /* Port B data direction select 0 */
    byte DDRB1       :1;                                       /* Port B data direction select 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRB :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRBSTR;
extern volatile DDRBSTR _DDRB @0x00000225;
#define DDRB                            _DDRB.Byte
#define DDRB_DDRB0                      _DDRB.Bits.DDRB0
#define DDRB_DDRB1                      _DDRB.Bits.DDRB1
#define DDRB_DDRB                       _DDRB.MergedBits.grpDDRB

#define DDRB_DDRB0_MASK                 1U
#define DDRB_DDRB1_MASK                 2U
#define DDRB_DDRB_MASK                  3U
#define DDRB_DDRB_BITNUM                0U


/*** PERA - Port A Pull Device Enable Register; 0x00000226 ***/
typedef union {
  byte Byte;
  struct {
    byte PERA0       :1;                                       /* Port A pull device enable 0 */
    byte PERA1       :1;                                       /* Port A pull device enable 1 */
    byte PERA2       :1;                                       /* Port A pull device enable 2 */
    byte PERA3       :1;                                       /* Port A pull device enable 3 */
    byte PERA4       :1;                                       /* Port A pull device enable 4 */
    byte PERA5       :1;                                       /* Port A pull device enable 5 */
    byte PERA6       :1;                                       /* Port A pull device enable 6 */
    byte PERA7       :1;                                       /* Port A pull device enable 7 */
  } Bits;
} PERASTR;
extern volatile PERASTR _PERA @0x00000226;
#define PERA                            _PERA.Byte
#define PERA_PERA0                      _PERA.Bits.PERA0
#define PERA_PERA1                      _PERA.Bits.PERA1
#define PERA_PERA2                      _PERA.Bits.PERA2
#define PERA_PERA3                      _PERA.Bits.PERA3
#define PERA_PERA4                      _PERA.Bits.PERA4
#define PERA_PERA5                      _PERA.Bits.PERA5
#define PERA_PERA6                      _PERA.Bits.PERA6
#define PERA_PERA7                      _PERA.Bits.PERA7

#define PERA_PERA0_MASK                 1U
#define PERA_PERA1_MASK                 2U
#define PERA_PERA2_MASK                 4U
#define PERA_PERA3_MASK                 8U
#define PERA_PERA4_MASK                 16U
#define PERA_PERA5_MASK                 32U
#define PERA_PERA6_MASK                 64U
#define PERA_PERA7_MASK                 128U


/*** PERB - Port B Pull Device Enable Register; 0x00000227 ***/
typedef union {
  byte Byte;
  struct {
    byte PERB0       :1;                                       /* Port B pull device enable 0 */
    byte PERB1       :1;                                       /* Port B pull device enable 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERB :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERBSTR;
extern volatile PERBSTR _PERB @0x00000227;
#define PERB                            _PERB.Byte
#define PERB_PERB0                      _PERB.Bits.PERB0
#define PERB_PERB1                      _PERB.Bits.PERB1
#define PERB_PERB                       _PERB.MergedBits.grpPERB

#define PERB_PERB0_MASK                 1U
#define PERB_PERB1_MASK                 2U
#define PERB_PERB_MASK                  3U
#define PERB_PERB_BITNUM                0U


/*** PPSA - Port A Polarity Select Register; 0x00000228 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSA0       :1;                                       /* Port A pull polarity select 0 */
    byte PPSA1       :1;                                       /* Port A pull polarity select 1 */
    byte PPSA2       :1;                                       /* Port A pull polarity select 2 */
    byte PPSA3       :1;                                       /* Port A pull polarity select 3 */
    byte PPSA4       :1;                                       /* Port A pull polarity select 4 */
    byte PPSA5       :1;                                       /* Port A pull polarity select 5 */
    byte PPSA6       :1;                                       /* Port A pull polarity select 6 */
    byte PPSA7       :1;                                       /* Port A pull polarity select 7 */
  } Bits;
} PPSASTR;
extern volatile PPSASTR _PPSA @0x00000228;
#define PPSA                            _PPSA.Byte
#define PPSA_PPSA0                      _PPSA.Bits.PPSA0
#define PPSA_PPSA1                      _PPSA.Bits.PPSA1
#define PPSA_PPSA2                      _PPSA.Bits.PPSA2
#define PPSA_PPSA3                      _PPSA.Bits.PPSA3
#define PPSA_PPSA4                      _PPSA.Bits.PPSA4
#define PPSA_PPSA5                      _PPSA.Bits.PPSA5
#define PPSA_PPSA6                      _PPSA.Bits.PPSA6
#define PPSA_PPSA7                      _PPSA.Bits.PPSA7

#define PPSA_PPSA0_MASK                 1U
#define PPSA_PPSA1_MASK                 2U
#define PPSA_PPSA2_MASK                 4U
#define PPSA_PPSA3_MASK                 8U
#define PPSA_PPSA4_MASK                 16U
#define PPSA_PPSA5_MASK                 32U
#define PPSA_PPSA6_MASK                 64U
#define PPSA_PPSA7_MASK                 128U


/*** PPSB - Port B Polarity Select Register; 0x00000229 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSB0       :1;                                       /* Port B pull polarity select 0 */
    byte PPSB1       :1;                                       /* Port B pull polarity select 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSB :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSBSTR;
extern volatile PPSBSTR _PPSB @0x00000229;
#define PPSB                            _PPSB.Byte
#define PPSB_PPSB0                      _PPSB.Bits.PPSB0
#define PPSB_PPSB1                      _PPSB.Bits.PPSB1
#define PPSB_PPSB                       _PPSB.MergedBits.grpPPSB

#define PPSB_PPSB0_MASK                 1U
#define PPSB_PPSB1_MASK                 2U
#define PPSB_PPSB_MASK                  3U
#define PPSB_PPSB_BITNUM                0U


/*** RDRC - Port C Reduced Drive Register; 0x0000025A ***/
typedef union {
  byte Byte;
  struct {
    byte RDRC0       :1;                                       /* Port C reduced drive select 0 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} RDRCSTR;
extern volatile RDRCSTR _RDRC @0x0000025A;
#define RDRC                            _RDRC.Byte
#define RDRC_RDRC0                      _RDRC.Bits.RDRC0

#define RDRC_RDRC0_MASK                 1U


/*** RDRD - Port D Reduced Drive Register; 0x0000025B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRD0       :1;                                       /* Port D reduced drive select 0 */
    byte RDRD1       :1;                                       /* Port D reduced drive select 1 */
    byte RDRD2       :1;                                       /* Port D reduced drive select 2 */
    byte RDRD3       :1;                                       /* Port D reduced drive select 3 */
    byte RDRD4       :1;                                       /* Port D reduced drive select 4 */
    byte RDRD5       :1;                                       /* Port D reduced drive select 5 */
    byte RDRD6       :1;                                       /* Port D reduced drive select 6 */
    byte RDRD7       :1;                                       /* Port D reduced drive select 7 */
  } Bits;
} RDRDSTR;
extern volatile RDRDSTR _RDRD @0x0000025B;
#define RDRD                            _RDRD.Byte
#define RDRD_RDRD0                      _RDRD.Bits.RDRD0
#define RDRD_RDRD1                      _RDRD.Bits.RDRD1
#define RDRD_RDRD2                      _RDRD.Bits.RDRD2
#define RDRD_RDRD3                      _RDRD.Bits.RDRD3
#define RDRD_RDRD4                      _RDRD.Bits.RDRD4
#define RDRD_RDRD5                      _RDRD.Bits.RDRD5
#define RDRD_RDRD6                      _RDRD.Bits.RDRD6
#define RDRD_RDRD7                      _RDRD.Bits.RDRD7

#define RDRD_RDRD0_MASK                 1U
#define RDRD_RDRD1_MASK                 2U
#define RDRD_RDRD2_MASK                 4U
#define RDRD_RDRD3_MASK                 8U
#define RDRD_RDRD4_MASK                 16U
#define RDRD_RDRD5_MASK                 32U
#define RDRD_RDRD6_MASK                 64U
#define RDRD_RDRD7_MASK                 128U


/*** FCLKDIV - Flash Clock Divider Register; 0x00000380 ***/
typedef union {
  byte Byte;
  struct {
    byte FDIV0       :1;                                       /* Clock Divider Bit 0 */
    byte FDIV1       :1;                                       /* Clock Divider Bit 1 */
    byte FDIV2       :1;                                       /* Clock Divider Bit 2 */
    byte FDIV3       :1;                                       /* Clock Divider Bit 3 */
    byte FDIV4       :1;                                       /* Clock Divider Bit 4 */
    byte FDIV5       :1;                                       /* Clock Divider Bit 5 */
    byte FDIVLCK     :1;                                       /* Clock divider locked */
    byte FDIVLD      :1;                                       /* Clock Divider Loaded */
  } Bits;
  struct {
    byte grpFDIV :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} FCLKDIVSTR;
extern volatile FCLKDIVSTR _FCLKDIV @0x00000380;
#define FCLKDIV                         _FCLKDIV.Byte
#define FCLKDIV_FDIV0                   _FCLKDIV.Bits.FDIV0
#define FCLKDIV_FDIV1                   _FCLKDIV.Bits.FDIV1
#define FCLKDIV_FDIV2                   _FCLKDIV.Bits.FDIV2
#define FCLKDIV_FDIV3                   _FCLKDIV.Bits.FDIV3
#define FCLKDIV_FDIV4                   _FCLKDIV.Bits.FDIV4
#define FCLKDIV_FDIV5                   _FCLKDIV.Bits.FDIV5
#define FCLKDIV_FDIVLCK                 _FCLKDIV.Bits.FDIVLCK
#define FCLKDIV_FDIVLD                  _FCLKDIV.Bits.FDIVLD
#define FCLKDIV_FDIV                    _FCLKDIV.MergedBits.grpFDIV

#define FCLKDIV_FDIV0_MASK              1U
#define FCLKDIV_FDIV1_MASK              2U
#define FCLKDIV_FDIV2_MASK              4U
#define FCLKDIV_FDIV3_MASK              8U
#define FCLKDIV_FDIV4_MASK              16U
#define FCLKDIV_FDIV5_MASK              32U
#define FCLKDIV_FDIVLCK_MASK            64U
#define FCLKDIV_FDIVLD_MASK             128U
#define FCLKDIV_FDIV_MASK               63U
#define FCLKDIV_FDIV_BITNUM             0U


/*** FSEC - Flash Security Register; 0x00000381 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte RNV2        :1;                                       /* Reserved Nonvolatile Bit 2 */
    byte RNV3        :1;                                       /* Reserved Nonvolatile Bit 3 */
    byte RNV4        :1;                                       /* Reserved Nonvolatile Bit 4 */
    byte RNV5        :1;                                       /* Reserved Nonvolatile Bit 5 */
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpRNV_2 :4;
    byte grpKEYEN :2;
  } MergedBits;
} FSECSTR;
extern volatile FSECSTR _FSEC @0x00000381;
#define FSEC                            _FSEC.Byte
#define FSEC_SEC0                       _FSEC.Bits.SEC0
#define FSEC_SEC1                       _FSEC.Bits.SEC1
#define FSEC_RNV2                       _FSEC.Bits.RNV2
#define FSEC_RNV3                       _FSEC.Bits.RNV3
#define FSEC_RNV4                       _FSEC.Bits.RNV4
#define FSEC_RNV5                       _FSEC.Bits.RNV5
#define FSEC_KEYEN0                     _FSEC.Bits.KEYEN0
#define FSEC_KEYEN1                     _FSEC.Bits.KEYEN1
#define FSEC_SEC                        _FSEC.MergedBits.grpSEC
#define FSEC_RNV_2                      _FSEC.MergedBits.grpRNV_2
#define FSEC_KEYEN                      _FSEC.MergedBits.grpKEYEN
#define FSEC_RNV                        FSEC_RNV_2

#define FSEC_SEC0_MASK                  1U
#define FSEC_SEC1_MASK                  2U
#define FSEC_RNV2_MASK                  4U
#define FSEC_RNV3_MASK                  8U
#define FSEC_RNV4_MASK                  16U
#define FSEC_RNV5_MASK                  32U
#define FSEC_KEYEN0_MASK                64U
#define FSEC_KEYEN1_MASK                128U
#define FSEC_SEC_MASK                   3U
#define FSEC_SEC_BITNUM                 0U
#define FSEC_RNV_2_MASK                 60U
#define FSEC_RNV_2_BITNUM               2U
#define FSEC_KEYEN_MASK                 192U
#define FSEC_KEYEN_BITNUM               6U


/*** FCCOBIX - Flash CCOB Index Register; 0x00000382 ***/
typedef union {
  byte Byte;
  struct {
    byte CCOBIX0     :1;                                       /* Common Command Register Index Bit 0 */
    byte CCOBIX1     :1;                                       /* Common Command Register Index Bit 1 */
    byte CCOBIX2     :1;                                       /* Common Command Register Index Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCCOBIX :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FCCOBIXSTR;
extern volatile FCCOBIXSTR _FCCOBIX @0x00000382;
#define FCCOBIX                         _FCCOBIX.Byte
#define FCCOBIX_CCOBIX0                 _FCCOBIX.Bits.CCOBIX0
#define FCCOBIX_CCOBIX1                 _FCCOBIX.Bits.CCOBIX1
#define FCCOBIX_CCOBIX2                 _FCCOBIX.Bits.CCOBIX2
#define FCCOBIX_CCOBIX                  _FCCOBIX.MergedBits.grpCCOBIX

#define FCCOBIX_CCOBIX0_MASK            1U
#define FCCOBIX_CCOBIX1_MASK            2U
#define FCCOBIX_CCOBIX2_MASK            4U
#define FCCOBIX_CCOBIX_MASK             7U
#define FCCOBIX_CCOBIX_BITNUM           0U


/*** FPSTAT - Flash Protection Status Register; 0x00000383 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FPOVRD      :1;                                       /* Flash Protection Override Status */
  } Bits;
} FPSTATSTR;
extern volatile FPSTATSTR _FPSTAT @0x00000383;
#define FPSTAT                          _FPSTAT.Byte
#define FPSTAT_FPOVRD                   _FPSTAT.Bits.FPOVRD

#define FPSTAT_FPOVRD_MASK              128U


/*** FCNFG - Flash Configuration Register; 0x00000384 ***/
typedef union {
  byte Byte;
  struct {
    byte FSFD        :1;                                       /* Force Single Bit Fault Detect */
    byte FDFD        :1;                                       /* Force Double Bit Fault Detect */
    byte             :1; 
    byte             :1; 
    byte IGNSF       :1;                                       /* Ignore Single Bit Fault */
    byte ERSAREQ     :1;                                       /* Erase All Request */
    byte             :1; 
    byte CCIE        :1;                                       /* Command Complete Interrupt Enable */
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @0x00000384;
#define FCNFG                           _FCNFG.Byte
#define FCNFG_FSFD                      _FCNFG.Bits.FSFD
#define FCNFG_FDFD                      _FCNFG.Bits.FDFD
#define FCNFG_IGNSF                     _FCNFG.Bits.IGNSF
#define FCNFG_ERSAREQ                   _FCNFG.Bits.ERSAREQ
#define FCNFG_CCIE                      _FCNFG.Bits.CCIE

#define FCNFG_FSFD_MASK                 1U
#define FCNFG_FDFD_MASK                 2U
#define FCNFG_IGNSF_MASK                16U
#define FCNFG_ERSAREQ_MASK              32U
#define FCNFG_CCIE_MASK                 128U


/*** FERCNFG - Flash Error Configuration Register; 0x00000385 ***/
typedef union {
  byte Byte;
  struct {
    byte SFDIE       :1;                                       /* Single Bit Fault Detect Interrupt Enable */
    byte DFDIE       :1;                                       /* Double Bit Fault Detect Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FERCNFGSTR;
extern volatile FERCNFGSTR _FERCNFG @0x00000385;
#define FERCNFG                         _FERCNFG.Byte
#define FERCNFG_SFDIE                   _FERCNFG.Bits.SFDIE
#define FERCNFG_DFDIE                   _FERCNFG.Bits.DFDIE

#define FERCNFG_SFDIE_MASK              1U
#define FERCNFG_DFDIE_MASK              2U


/*** FSTAT - Flash Status Register; 0x00000386 ***/
typedef union {
  byte Byte;
  struct {
    byte MGSTAT0     :1;                                       /* Memory Controller Command Completion Status Flag 0 */
    byte MGSTAT1     :1;                                       /* Memory Controller Command Completion Status Flag 1 */
    byte             :1; 
    byte MGBUSY      :1;                                       /* Memory Controller Busy Flag */
    byte FPVIOL      :1;                                       /* Flash Protection Violation Flag */
    byte ACCERR      :1;                                       /* Flash Access Error Flag */
    byte             :1; 
    byte CCIF        :1;                                       /* Command Complete Interrupt Flag */
  } Bits;
  struct {
    byte grpMGSTAT :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @0x00000386;
#define FSTAT                           _FSTAT.Byte
#define FSTAT_MGSTAT0                   _FSTAT.Bits.MGSTAT0
#define FSTAT_MGSTAT1                   _FSTAT.Bits.MGSTAT1
#define FSTAT_MGBUSY                    _FSTAT.Bits.MGBUSY
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_ACCERR                    _FSTAT.Bits.ACCERR
#define FSTAT_CCIF                      _FSTAT.Bits.CCIF
#define FSTAT_MGSTAT                    _FSTAT.MergedBits.grpMGSTAT

#define FSTAT_MGSTAT0_MASK              1U
#define FSTAT_MGSTAT1_MASK              2U
#define FSTAT_MGBUSY_MASK               8U
#define FSTAT_FPVIOL_MASK               16U
#define FSTAT_ACCERR_MASK               32U
#define FSTAT_CCIF_MASK                 128U
#define FSTAT_MGSTAT_MASK               3U
#define FSTAT_MGSTAT_BITNUM             0U


/*** FERSTAT - Flash Error Status Register; 0x00000387 ***/
typedef union {
  byte Byte;
  struct {
    byte SFDIF       :1;                                       /* Single Bit Fault Detect Interrupt Flag */
    byte DFDIF       :1;                                       /* Double Bit Fault Detect Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FERSTATSTR;
extern volatile FERSTATSTR _FERSTAT @0x00000387;
#define FERSTAT                         _FERSTAT.Byte
#define FERSTAT_SFDIF                   _FERSTAT.Bits.SFDIF
#define FERSTAT_DFDIF                   _FERSTAT.Bits.DFDIF

#define FERSTAT_SFDIF_MASK              1U
#define FERSTAT_DFDIF_MASK              2U


/*** FPROT - P-Flash Protection Register; 0x00000388 ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address Size Bit 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address Size Bit 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower Address Range Disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher Address Size Bit 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher Address Size Bit 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher Address Range Disable */
    byte RNV6        :1;                                       /* Reserved Nonvolatile Bit */
    byte FPOPEN      :1;                                       /* Flash Protection Operation Enable */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpRNV_6 :1;
    byte         :1;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @0x00000388;
#define FPROT                           _FPROT.Byte
#define FPROT_FPLS0                     _FPROT.Bits.FPLS0
#define FPROT_FPLS1                     _FPROT.Bits.FPLS1
#define FPROT_FPLDIS                    _FPROT.Bits.FPLDIS
#define FPROT_FPHS0                     _FPROT.Bits.FPHS0
#define FPROT_FPHS1                     _FPROT.Bits.FPHS1
#define FPROT_FPHDIS                    _FPROT.Bits.FPHDIS
#define FPROT_RNV6                      _FPROT.Bits.RNV6
#define FPROT_FPOPEN                    _FPROT.Bits.FPOPEN
#define FPROT_FPLS                      _FPROT.MergedBits.grpFPLS
#define FPROT_FPHS                      _FPROT.MergedBits.grpFPHS

#define FPROT_FPLS0_MASK                1U
#define FPROT_FPLS1_MASK                2U
#define FPROT_FPLDIS_MASK               4U
#define FPROT_FPHS0_MASK                8U
#define FPROT_FPHS1_MASK                16U
#define FPROT_FPHDIS_MASK               32U
#define FPROT_RNV6_MASK                 64U
#define FPROT_FPOPEN_MASK               128U
#define FPROT_FPLS_MASK                 3U
#define FPROT_FPLS_BITNUM               0U
#define FPROT_FPHS_MASK                 24U
#define FPROT_FPHS_BITNUM               3U


/*** DFPROT - D-Flash Protection Register; 0x00000389 ***/
typedef union {
  byte Byte;
  struct {
    byte DPS0        :1;                                       /* D-Flash Protection Size Bit 0 */
    byte DPS1        :1;                                       /* D-Flash Protection Size Bit 1 */
    byte DPS2        :1;                                       /* D-Flash Protection Size Bit 2 */
    byte DPS3        :1;                                       /* D-Flash Protection Size Bit 3 */
    byte DPS4        :1;                                       /* D-Flash Protection Size Bit 4 */
    byte DPS5        :1;                                       /* D-Flash Protection Size Bit 5 */
    byte DPS6        :1;                                       /* D-Flash Protection Size Bit 6 */
    byte DPOPEN      :1;                                       /* D-Flash Protection Control */
  } Bits;
  struct {
    byte grpDPS  :7;
    byte         :1;
  } MergedBits;
} DFPROTSTR;
extern volatile DFPROTSTR _DFPROT @0x00000389;
#define DFPROT                          _DFPROT.Byte
#define DFPROT_DPS0                     _DFPROT.Bits.DPS0
#define DFPROT_DPS1                     _DFPROT.Bits.DPS1
#define DFPROT_DPS2                     _DFPROT.Bits.DPS2
#define DFPROT_DPS3                     _DFPROT.Bits.DPS3
#define DFPROT_DPS4                     _DFPROT.Bits.DPS4
#define DFPROT_DPS5                     _DFPROT.Bits.DPS5
#define DFPROT_DPS6                     _DFPROT.Bits.DPS6
#define DFPROT_DPOPEN                   _DFPROT.Bits.DPOPEN
#define DFPROT_DPS                      _DFPROT.MergedBits.grpDPS

#define DFPROT_DPS0_MASK                1U
#define DFPROT_DPS1_MASK                2U
#define DFPROT_DPS2_MASK                4U
#define DFPROT_DPS3_MASK                8U
#define DFPROT_DPS4_MASK                16U
#define DFPROT_DPS5_MASK                32U
#define DFPROT_DPS6_MASK                64U
#define DFPROT_DPOPEN_MASK              128U
#define DFPROT_DPS_MASK                 127U
#define DFPROT_DPS_BITNUM               0U


/*** FOPT - Flash Option Register; 0x0000038A ***/
typedef union {
  byte Byte;
  struct {
    byte NV0         :1;                                       /* Nonvolatile Bit 0 */
    byte NV1         :1;                                       /* Nonvolatile Bit 1 */
    byte NV2         :1;                                       /* Nonvolatile Bit 2 */
    byte NV3         :1;                                       /* Nonvolatile Bit 3 */
    byte NV4         :1;                                       /* Nonvolatile Bit 4 */
    byte NV5         :1;                                       /* Nonvolatile Bit 5 */
    byte NV6         :1;                                       /* Nonvolatile Bit 6 */
    byte NV7         :1;                                       /* Nonvolatile Bit 7 */
  } Bits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @0x0000038A;
#define FOPT                            _FOPT.Byte
#define FOPT_NV0                        _FOPT.Bits.NV0
#define FOPT_NV1                        _FOPT.Bits.NV1
#define FOPT_NV2                        _FOPT.Bits.NV2
#define FOPT_NV3                        _FOPT.Bits.NV3
#define FOPT_NV4                        _FOPT.Bits.NV4
#define FOPT_NV5                        _FOPT.Bits.NV5
#define FOPT_NV6                        _FOPT.Bits.NV6
#define FOPT_NV7                        _FOPT.Bits.NV7

#define FOPT_NV0_MASK                   1U
#define FOPT_NV1_MASK                   2U
#define FOPT_NV2_MASK                   4U
#define FOPT_NV3_MASK                   8U
#define FOPT_NV4_MASK                   16U
#define FOPT_NV5_MASK                   32U
#define FOPT_NV6_MASK                   64U
#define FOPT_NV7_MASK                   128U


/*** FCCOB0 - Flash Common Command Object Register; 0x0000038C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOB0HI - Flash Common Command Object Register High; 0x0000038C ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOB0HISTR;
    #define FCCOB0HI                    _FCCOB0.Overlap_STR.FCCOB0HISTR.Byte
    #define FCCOB0HI_CCOB8              _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB8
    #define FCCOB0HI_CCOB9              _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB9
    #define FCCOB0HI_CCOB10             _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB10
    #define FCCOB0HI_CCOB11             _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB11
    #define FCCOB0HI_CCOB12             _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB12
    #define FCCOB0HI_CCOB13             _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB13
    #define FCCOB0HI_CCOB14             _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB14
    #define FCCOB0HI_CCOB15             _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB15
    
    #define FCCOB0HI_CCOB8_MASK         1U
    #define FCCOB0HI_CCOB9_MASK         2U
    #define FCCOB0HI_CCOB10_MASK        4U
    #define FCCOB0HI_CCOB11_MASK        8U
    #define FCCOB0HI_CCOB12_MASK        16U
    #define FCCOB0HI_CCOB13_MASK        32U
    #define FCCOB0HI_CCOB14_MASK        64U
    #define FCCOB0HI_CCOB15_MASK        128U
    

    /*** FCCOB0LO - Flash Common Command Object Register Low; 0x0000038D ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOB0LOSTR;
    #define FCCOB0LO                    _FCCOB0.Overlap_STR.FCCOB0LOSTR.Byte
    #define FCCOB0LO_CCOB0              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB0
    #define FCCOB0LO_CCOB1              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB1
    #define FCCOB0LO_CCOB2              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB2
    #define FCCOB0LO_CCOB3              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB3
    #define FCCOB0LO_CCOB4              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB4
    #define FCCOB0LO_CCOB5              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB5
    #define FCCOB0LO_CCOB6              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB6
    #define FCCOB0LO_CCOB7              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB7
    
    #define FCCOB0LO_CCOB0_MASK         1U
    #define FCCOB0LO_CCOB1_MASK         2U
    #define FCCOB0LO_CCOB2_MASK         4U
    #define FCCOB0LO_CCOB3_MASK         8U
    #define FCCOB0LO_CCOB4_MASK         16U
    #define FCCOB0LO_CCOB5_MASK         32U
    #define FCCOB0LO_CCOB6_MASK         64U
    #define FCCOB0LO_CCOB7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOB0STR;
extern volatile FCCOB0STR _FCCOB0 @0x0000038C;
#define FCCOB0                          _FCCOB0.Word
#define FCCOB0_CCOB0                    _FCCOB0.Bits.CCOB0
#define FCCOB0_CCOB1                    _FCCOB0.Bits.CCOB1
#define FCCOB0_CCOB2                    _FCCOB0.Bits.CCOB2
#define FCCOB0_CCOB3                    _FCCOB0.Bits.CCOB3
#define FCCOB0_CCOB4                    _FCCOB0.Bits.CCOB4
#define FCCOB0_CCOB5                    _FCCOB0.Bits.CCOB5
#define FCCOB0_CCOB6                    _FCCOB0.Bits.CCOB6
#define FCCOB0_CCOB7                    _FCCOB0.Bits.CCOB7
#define FCCOB0_CCOB8                    _FCCOB0.Bits.CCOB8
#define FCCOB0_CCOB9                    _FCCOB0.Bits.CCOB9
#define FCCOB0_CCOB10                   _FCCOB0.Bits.CCOB10
#define FCCOB0_CCOB11                   _FCCOB0.Bits.CCOB11
#define FCCOB0_CCOB12                   _FCCOB0.Bits.CCOB12
#define FCCOB0_CCOB13                   _FCCOB0.Bits.CCOB13
#define FCCOB0_CCOB14                   _FCCOB0.Bits.CCOB14
#define FCCOB0_CCOB15                   _FCCOB0.Bits.CCOB15
/* FCCOB_ARR: Access 6 FCCOBx registers in an array */
#define FCCOB_ARR                       ((volatile word *) &FCCOB0)

#define FCCOB0_CCOB0_MASK               1U
#define FCCOB0_CCOB1_MASK               2U
#define FCCOB0_CCOB2_MASK               4U
#define FCCOB0_CCOB3_MASK               8U
#define FCCOB0_CCOB4_MASK               16U
#define FCCOB0_CCOB5_MASK               32U
#define FCCOB0_CCOB6_MASK               64U
#define FCCOB0_CCOB7_MASK               128U
#define FCCOB0_CCOB8_MASK               256U
#define FCCOB0_CCOB9_MASK               512U
#define FCCOB0_CCOB10_MASK              1024U
#define FCCOB0_CCOB11_MASK              2048U
#define FCCOB0_CCOB12_MASK              4096U
#define FCCOB0_CCOB13_MASK              8192U
#define FCCOB0_CCOB14_MASK              16384U
#define FCCOB0_CCOB15_MASK              32768U


/*** FCCOB1 - Flash Common Command Object Register; 0x0000038E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOB1HI - Flash Common Command Object Register High; 0x0000038E ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOB1HISTR;
    #define FCCOB1HI                    _FCCOB1.Overlap_STR.FCCOB1HISTR.Byte
    #define FCCOB1HI_CCOB8              _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB8
    #define FCCOB1HI_CCOB9              _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB9
    #define FCCOB1HI_CCOB10             _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB10
    #define FCCOB1HI_CCOB11             _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB11
    #define FCCOB1HI_CCOB12             _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB12
    #define FCCOB1HI_CCOB13             _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB13
    #define FCCOB1HI_CCOB14             _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB14
    #define FCCOB1HI_CCOB15             _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB15
    
    #define FCCOB1HI_CCOB8_MASK         1U
    #define FCCOB1HI_CCOB9_MASK         2U
    #define FCCOB1HI_CCOB10_MASK        4U
    #define FCCOB1HI_CCOB11_MASK        8U
    #define FCCOB1HI_CCOB12_MASK        16U
    #define FCCOB1HI_CCOB13_MASK        32U
    #define FCCOB1HI_CCOB14_MASK        64U
    #define FCCOB1HI_CCOB15_MASK        128U
    

    /*** FCCOB1LO - Flash Common Command Object Register Low; 0x0000038F ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOB1LOSTR;
    #define FCCOB1LO                    _FCCOB1.Overlap_STR.FCCOB1LOSTR.Byte
    #define FCCOB1LO_CCOB0              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB0
    #define FCCOB1LO_CCOB1              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB1
    #define FCCOB1LO_CCOB2              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB2
    #define FCCOB1LO_CCOB3              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB3
    #define FCCOB1LO_CCOB4              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB4
    #define FCCOB1LO_CCOB5              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB5
    #define FCCOB1LO_CCOB6              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB6
    #define FCCOB1LO_CCOB7              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB7
    
    #define FCCOB1LO_CCOB0_MASK         1U
    #define FCCOB1LO_CCOB1_MASK         2U
    #define FCCOB1LO_CCOB2_MASK         4U
    #define FCCOB1LO_CCOB3_MASK         8U
    #define FCCOB1LO_CCOB4_MASK         16U
    #define FCCOB1LO_CCOB5_MASK         32U
    #define FCCOB1LO_CCOB6_MASK         64U
    #define FCCOB1LO_CCOB7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOB1STR;
extern volatile FCCOB1STR _FCCOB1 @0x0000038E;
#define FCCOB1                          _FCCOB1.Word
#define FCCOB1_CCOB0                    _FCCOB1.Bits.CCOB0
#define FCCOB1_CCOB1                    _FCCOB1.Bits.CCOB1
#define FCCOB1_CCOB2                    _FCCOB1.Bits.CCOB2
#define FCCOB1_CCOB3                    _FCCOB1.Bits.CCOB3
#define FCCOB1_CCOB4                    _FCCOB1.Bits.CCOB4
#define FCCOB1_CCOB5                    _FCCOB1.Bits.CCOB5
#define FCCOB1_CCOB6                    _FCCOB1.Bits.CCOB6
#define FCCOB1_CCOB7                    _FCCOB1.Bits.CCOB7
#define FCCOB1_CCOB8                    _FCCOB1.Bits.CCOB8
#define FCCOB1_CCOB9                    _FCCOB1.Bits.CCOB9
#define FCCOB1_CCOB10                   _FCCOB1.Bits.CCOB10
#define FCCOB1_CCOB11                   _FCCOB1.Bits.CCOB11
#define FCCOB1_CCOB12                   _FCCOB1.Bits.CCOB12
#define FCCOB1_CCOB13                   _FCCOB1.Bits.CCOB13
#define FCCOB1_CCOB14                   _FCCOB1.Bits.CCOB14
#define FCCOB1_CCOB15                   _FCCOB1.Bits.CCOB15

#define FCCOB1_CCOB0_MASK               1U
#define FCCOB1_CCOB1_MASK               2U
#define FCCOB1_CCOB2_MASK               4U
#define FCCOB1_CCOB3_MASK               8U
#define FCCOB1_CCOB4_MASK               16U
#define FCCOB1_CCOB5_MASK               32U
#define FCCOB1_CCOB6_MASK               64U
#define FCCOB1_CCOB7_MASK               128U
#define FCCOB1_CCOB8_MASK               256U
#define FCCOB1_CCOB9_MASK               512U
#define FCCOB1_CCOB10_MASK              1024U
#define FCCOB1_CCOB11_MASK              2048U
#define FCCOB1_CCOB12_MASK              4096U
#define FCCOB1_CCOB13_MASK              8192U
#define FCCOB1_CCOB14_MASK              16384U
#define FCCOB1_CCOB15_MASK              32768U


/*** FCCOB2 - Flash Common Command Object Register; 0x00000390 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOB2HI - Flash Common Command Object Register High; 0x00000390 ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOB2HISTR;
    #define FCCOB2HI                    _FCCOB2.Overlap_STR.FCCOB2HISTR.Byte
    #define FCCOB2HI_CCOB8              _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB8
    #define FCCOB2HI_CCOB9              _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB9
    #define FCCOB2HI_CCOB10             _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB10
    #define FCCOB2HI_CCOB11             _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB11
    #define FCCOB2HI_CCOB12             _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB12
    #define FCCOB2HI_CCOB13             _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB13
    #define FCCOB2HI_CCOB14             _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB14
    #define FCCOB2HI_CCOB15             _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB15
    
    #define FCCOB2HI_CCOB8_MASK         1U
    #define FCCOB2HI_CCOB9_MASK         2U
    #define FCCOB2HI_CCOB10_MASK        4U
    #define FCCOB2HI_CCOB11_MASK        8U
    #define FCCOB2HI_CCOB12_MASK        16U
    #define FCCOB2HI_CCOB13_MASK        32U
    #define FCCOB2HI_CCOB14_MASK        64U
    #define FCCOB2HI_CCOB15_MASK        128U
    

    /*** FCCOB2LO - Flash Common Command Object Register Low; 0x00000391 ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOB2LOSTR;
    #define FCCOB2LO                    _FCCOB2.Overlap_STR.FCCOB2LOSTR.Byte
    #define FCCOB2LO_CCOB0              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB0
    #define FCCOB2LO_CCOB1              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB1
    #define FCCOB2LO_CCOB2              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB2
    #define FCCOB2LO_CCOB3              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB3
    #define FCCOB2LO_CCOB4              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB4
    #define FCCOB2LO_CCOB5              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB5
    #define FCCOB2LO_CCOB6              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB6
    #define FCCOB2LO_CCOB7              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB7
    
    #define FCCOB2LO_CCOB0_MASK         1U
    #define FCCOB2LO_CCOB1_MASK         2U
    #define FCCOB2LO_CCOB2_MASK         4U
    #define FCCOB2LO_CCOB3_MASK         8U
    #define FCCOB2LO_CCOB4_MASK         16U
    #define FCCOB2LO_CCOB5_MASK         32U
    #define FCCOB2LO_CCOB6_MASK         64U
    #define FCCOB2LO_CCOB7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOB2STR;
extern volatile FCCOB2STR _FCCOB2 @0x00000390;
#define FCCOB2                          _FCCOB2.Word
#define FCCOB2_CCOB0                    _FCCOB2.Bits.CCOB0
#define FCCOB2_CCOB1                    _FCCOB2.Bits.CCOB1
#define FCCOB2_CCOB2                    _FCCOB2.Bits.CCOB2
#define FCCOB2_CCOB3                    _FCCOB2.Bits.CCOB3
#define FCCOB2_CCOB4                    _FCCOB2.Bits.CCOB4
#define FCCOB2_CCOB5                    _FCCOB2.Bits.CCOB5
#define FCCOB2_CCOB6                    _FCCOB2.Bits.CCOB6
#define FCCOB2_CCOB7                    _FCCOB2.Bits.CCOB7
#define FCCOB2_CCOB8                    _FCCOB2.Bits.CCOB8
#define FCCOB2_CCOB9                    _FCCOB2.Bits.CCOB9
#define FCCOB2_CCOB10                   _FCCOB2.Bits.CCOB10
#define FCCOB2_CCOB11                   _FCCOB2.Bits.CCOB11
#define FCCOB2_CCOB12                   _FCCOB2.Bits.CCOB12
#define FCCOB2_CCOB13                   _FCCOB2.Bits.CCOB13
#define FCCOB2_CCOB14                   _FCCOB2.Bits.CCOB14
#define FCCOB2_CCOB15                   _FCCOB2.Bits.CCOB15

#define FCCOB2_CCOB0_MASK               1U
#define FCCOB2_CCOB1_MASK               2U
#define FCCOB2_CCOB2_MASK               4U
#define FCCOB2_CCOB3_MASK               8U
#define FCCOB2_CCOB4_MASK               16U
#define FCCOB2_CCOB5_MASK               32U
#define FCCOB2_CCOB6_MASK               64U
#define FCCOB2_CCOB7_MASK               128U
#define FCCOB2_CCOB8_MASK               256U
#define FCCOB2_CCOB9_MASK               512U
#define FCCOB2_CCOB10_MASK              1024U
#define FCCOB2_CCOB11_MASK              2048U
#define FCCOB2_CCOB12_MASK              4096U
#define FCCOB2_CCOB13_MASK              8192U
#define FCCOB2_CCOB14_MASK              16384U
#define FCCOB2_CCOB15_MASK              32768U


/*** FCCOB3 - Flash Common Command Object Register; 0x00000392 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOB3HI - Flash Common Command Object Register High; 0x00000392 ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOB3HISTR;
    #define FCCOB3HI                    _FCCOB3.Overlap_STR.FCCOB3HISTR.Byte
    #define FCCOB3HI_CCOB8              _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB8
    #define FCCOB3HI_CCOB9              _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB9
    #define FCCOB3HI_CCOB10             _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB10
    #define FCCOB3HI_CCOB11             _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB11
    #define FCCOB3HI_CCOB12             _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB12
    #define FCCOB3HI_CCOB13             _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB13
    #define FCCOB3HI_CCOB14             _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB14
    #define FCCOB3HI_CCOB15             _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB15
    
    #define FCCOB3HI_CCOB8_MASK         1U
    #define FCCOB3HI_CCOB9_MASK         2U
    #define FCCOB3HI_CCOB10_MASK        4U
    #define FCCOB3HI_CCOB11_MASK        8U
    #define FCCOB3HI_CCOB12_MASK        16U
    #define FCCOB3HI_CCOB13_MASK        32U
    #define FCCOB3HI_CCOB14_MASK        64U
    #define FCCOB3HI_CCOB15_MASK        128U
    

    /*** FCCOB3LO - Flash Common Command Object Register Low; 0x00000393 ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOB3LOSTR;
    #define FCCOB3LO                    _FCCOB3.Overlap_STR.FCCOB3LOSTR.Byte
    #define FCCOB3LO_CCOB0              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB0
    #define FCCOB3LO_CCOB1              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB1
    #define FCCOB3LO_CCOB2              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB2
    #define FCCOB3LO_CCOB3              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB3
    #define FCCOB3LO_CCOB4              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB4
    #define FCCOB3LO_CCOB5              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB5
    #define FCCOB3LO_CCOB6              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB6
    #define FCCOB3LO_CCOB7              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB7
    
    #define FCCOB3LO_CCOB0_MASK         1U
    #define FCCOB3LO_CCOB1_MASK         2U
    #define FCCOB3LO_CCOB2_MASK         4U
    #define FCCOB3LO_CCOB3_MASK         8U
    #define FCCOB3LO_CCOB4_MASK         16U
    #define FCCOB3LO_CCOB5_MASK         32U
    #define FCCOB3LO_CCOB6_MASK         64U
    #define FCCOB3LO_CCOB7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOB3STR;
extern volatile FCCOB3STR _FCCOB3 @0x00000392;
#define FCCOB3                          _FCCOB3.Word
#define FCCOB3_CCOB0                    _FCCOB3.Bits.CCOB0
#define FCCOB3_CCOB1                    _FCCOB3.Bits.CCOB1
#define FCCOB3_CCOB2                    _FCCOB3.Bits.CCOB2
#define FCCOB3_CCOB3                    _FCCOB3.Bits.CCOB3
#define FCCOB3_CCOB4                    _FCCOB3.Bits.CCOB4
#define FCCOB3_CCOB5                    _FCCOB3.Bits.CCOB5
#define FCCOB3_CCOB6                    _FCCOB3.Bits.CCOB6
#define FCCOB3_CCOB7                    _FCCOB3.Bits.CCOB7
#define FCCOB3_CCOB8                    _FCCOB3.Bits.CCOB8
#define FCCOB3_CCOB9                    _FCCOB3.Bits.CCOB9
#define FCCOB3_CCOB10                   _FCCOB3.Bits.CCOB10
#define FCCOB3_CCOB11                   _FCCOB3.Bits.CCOB11
#define FCCOB3_CCOB12                   _FCCOB3.Bits.CCOB12
#define FCCOB3_CCOB13                   _FCCOB3.Bits.CCOB13
#define FCCOB3_CCOB14                   _FCCOB3.Bits.CCOB14
#define FCCOB3_CCOB15                   _FCCOB3.Bits.CCOB15

#define FCCOB3_CCOB0_MASK               1U
#define FCCOB3_CCOB1_MASK               2U
#define FCCOB3_CCOB2_MASK               4U
#define FCCOB3_CCOB3_MASK               8U
#define FCCOB3_CCOB4_MASK               16U
#define FCCOB3_CCOB5_MASK               32U
#define FCCOB3_CCOB6_MASK               64U
#define FCCOB3_CCOB7_MASK               128U
#define FCCOB3_CCOB8_MASK               256U
#define FCCOB3_CCOB9_MASK               512U
#define FCCOB3_CCOB10_MASK              1024U
#define FCCOB3_CCOB11_MASK              2048U
#define FCCOB3_CCOB12_MASK              4096U
#define FCCOB3_CCOB13_MASK              8192U
#define FCCOB3_CCOB14_MASK              16384U
#define FCCOB3_CCOB15_MASK              32768U


/*** FCCOB4 - Flash Common Command Object Register; 0x00000394 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOB4HI - Flash Common Command Object Register High; 0x00000394 ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOB4HISTR;
    #define FCCOB4HI                    _FCCOB4.Overlap_STR.FCCOB4HISTR.Byte
    #define FCCOB4HI_CCOB8              _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB8
    #define FCCOB4HI_CCOB9              _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB9
    #define FCCOB4HI_CCOB10             _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB10
    #define FCCOB4HI_CCOB11             _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB11
    #define FCCOB4HI_CCOB12             _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB12
    #define FCCOB4HI_CCOB13             _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB13
    #define FCCOB4HI_CCOB14             _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB14
    #define FCCOB4HI_CCOB15             _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB15
    
    #define FCCOB4HI_CCOB8_MASK         1U
    #define FCCOB4HI_CCOB9_MASK         2U
    #define FCCOB4HI_CCOB10_MASK        4U
    #define FCCOB4HI_CCOB11_MASK        8U
    #define FCCOB4HI_CCOB12_MASK        16U
    #define FCCOB4HI_CCOB13_MASK        32U
    #define FCCOB4HI_CCOB14_MASK        64U
    #define FCCOB4HI_CCOB15_MASK        128U
    

    /*** FCCOB4LO - Flash Common Command Object Register Low; 0x00000395 ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOB4LOSTR;
    #define FCCOB4LO                    _FCCOB4.Overlap_STR.FCCOB4LOSTR.Byte
    #define FCCOB4LO_CCOB0              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB0
    #define FCCOB4LO_CCOB1              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB1
    #define FCCOB4LO_CCOB2              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB2
    #define FCCOB4LO_CCOB3              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB3
    #define FCCOB4LO_CCOB4              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB4
    #define FCCOB4LO_CCOB5              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB5
    #define FCCOB4LO_CCOB6              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB6
    #define FCCOB4LO_CCOB7              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB7
    
    #define FCCOB4LO_CCOB0_MASK         1U
    #define FCCOB4LO_CCOB1_MASK         2U
    #define FCCOB4LO_CCOB2_MASK         4U
    #define FCCOB4LO_CCOB3_MASK         8U
    #define FCCOB4LO_CCOB4_MASK         16U
    #define FCCOB4LO_CCOB5_MASK         32U
    #define FCCOB4LO_CCOB6_MASK         64U
    #define FCCOB4LO_CCOB7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOB4STR;
extern volatile FCCOB4STR _FCCOB4 @0x00000394;
#define FCCOB4                          _FCCOB4.Word
#define FCCOB4_CCOB0                    _FCCOB4.Bits.CCOB0
#define FCCOB4_CCOB1                    _FCCOB4.Bits.CCOB1
#define FCCOB4_CCOB2                    _FCCOB4.Bits.CCOB2
#define FCCOB4_CCOB3                    _FCCOB4.Bits.CCOB3
#define FCCOB4_CCOB4                    _FCCOB4.Bits.CCOB4
#define FCCOB4_CCOB5                    _FCCOB4.Bits.CCOB5
#define FCCOB4_CCOB6                    _FCCOB4.Bits.CCOB6
#define FCCOB4_CCOB7                    _FCCOB4.Bits.CCOB7
#define FCCOB4_CCOB8                    _FCCOB4.Bits.CCOB8
#define FCCOB4_CCOB9                    _FCCOB4.Bits.CCOB9
#define FCCOB4_CCOB10                   _FCCOB4.Bits.CCOB10
#define FCCOB4_CCOB11                   _FCCOB4.Bits.CCOB11
#define FCCOB4_CCOB12                   _FCCOB4.Bits.CCOB12
#define FCCOB4_CCOB13                   _FCCOB4.Bits.CCOB13
#define FCCOB4_CCOB14                   _FCCOB4.Bits.CCOB14
#define FCCOB4_CCOB15                   _FCCOB4.Bits.CCOB15

#define FCCOB4_CCOB0_MASK               1U
#define FCCOB4_CCOB1_MASK               2U
#define FCCOB4_CCOB2_MASK               4U
#define FCCOB4_CCOB3_MASK               8U
#define FCCOB4_CCOB4_MASK               16U
#define FCCOB4_CCOB5_MASK               32U
#define FCCOB4_CCOB6_MASK               64U
#define FCCOB4_CCOB7_MASK               128U
#define FCCOB4_CCOB8_MASK               256U
#define FCCOB4_CCOB9_MASK               512U
#define FCCOB4_CCOB10_MASK              1024U
#define FCCOB4_CCOB11_MASK              2048U
#define FCCOB4_CCOB12_MASK              4096U
#define FCCOB4_CCOB13_MASK              8192U
#define FCCOB4_CCOB14_MASK              16384U
#define FCCOB4_CCOB15_MASK              32768U


/*** FCCOB5 - Flash Common Command Object Register; 0x00000396 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOB5HI - Flash Common Command Object Register High; 0x00000396 ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOB5HISTR;
    #define FCCOB5HI                    _FCCOB5.Overlap_STR.FCCOB5HISTR.Byte
    #define FCCOB5HI_CCOB8              _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB8
    #define FCCOB5HI_CCOB9              _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB9
    #define FCCOB5HI_CCOB10             _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB10
    #define FCCOB5HI_CCOB11             _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB11
    #define FCCOB5HI_CCOB12             _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB12
    #define FCCOB5HI_CCOB13             _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB13
    #define FCCOB5HI_CCOB14             _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB14
    #define FCCOB5HI_CCOB15             _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB15
    
    #define FCCOB5HI_CCOB8_MASK         1U
    #define FCCOB5HI_CCOB9_MASK         2U
    #define FCCOB5HI_CCOB10_MASK        4U
    #define FCCOB5HI_CCOB11_MASK        8U
    #define FCCOB5HI_CCOB12_MASK        16U
    #define FCCOB5HI_CCOB13_MASK        32U
    #define FCCOB5HI_CCOB14_MASK        64U
    #define FCCOB5HI_CCOB15_MASK        128U
    

    /*** FCCOB5LO - Flash Common Command Object Register Low; 0x00000397 ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOB5LOSTR;
    #define FCCOB5LO                    _FCCOB5.Overlap_STR.FCCOB5LOSTR.Byte
    #define FCCOB5LO_CCOB0              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB0
    #define FCCOB5LO_CCOB1              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB1
    #define FCCOB5LO_CCOB2              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB2
    #define FCCOB5LO_CCOB3              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB3
    #define FCCOB5LO_CCOB4              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB4
    #define FCCOB5LO_CCOB5              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB5
    #define FCCOB5LO_CCOB6              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB6
    #define FCCOB5LO_CCOB7              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB7
    
    #define FCCOB5LO_CCOB0_MASK         1U
    #define FCCOB5LO_CCOB1_MASK         2U
    #define FCCOB5LO_CCOB2_MASK         4U
    #define FCCOB5LO_CCOB3_MASK         8U
    #define FCCOB5LO_CCOB4_MASK         16U
    #define FCCOB5LO_CCOB5_MASK         32U
    #define FCCOB5LO_CCOB6_MASK         64U
    #define FCCOB5LO_CCOB7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOB5STR;
extern volatile FCCOB5STR _FCCOB5 @0x00000396;
#define FCCOB5                          _FCCOB5.Word
#define FCCOB5_CCOB0                    _FCCOB5.Bits.CCOB0
#define FCCOB5_CCOB1                    _FCCOB5.Bits.CCOB1
#define FCCOB5_CCOB2                    _FCCOB5.Bits.CCOB2
#define FCCOB5_CCOB3                    _FCCOB5.Bits.CCOB3
#define FCCOB5_CCOB4                    _FCCOB5.Bits.CCOB4
#define FCCOB5_CCOB5                    _FCCOB5.Bits.CCOB5
#define FCCOB5_CCOB6                    _FCCOB5.Bits.CCOB6
#define FCCOB5_CCOB7                    _FCCOB5.Bits.CCOB7
#define FCCOB5_CCOB8                    _FCCOB5.Bits.CCOB8
#define FCCOB5_CCOB9                    _FCCOB5.Bits.CCOB9
#define FCCOB5_CCOB10                   _FCCOB5.Bits.CCOB10
#define FCCOB5_CCOB11                   _FCCOB5.Bits.CCOB11
#define FCCOB5_CCOB12                   _FCCOB5.Bits.CCOB12
#define FCCOB5_CCOB13                   _FCCOB5.Bits.CCOB13
#define FCCOB5_CCOB14                   _FCCOB5.Bits.CCOB14
#define FCCOB5_CCOB15                   _FCCOB5.Bits.CCOB15

#define FCCOB5_CCOB0_MASK               1U
#define FCCOB5_CCOB1_MASK               2U
#define FCCOB5_CCOB2_MASK               4U
#define FCCOB5_CCOB3_MASK               8U
#define FCCOB5_CCOB4_MASK               16U
#define FCCOB5_CCOB5_MASK               32U
#define FCCOB5_CCOB6_MASK               64U
#define FCCOB5_CCOB7_MASK               128U
#define FCCOB5_CCOB8_MASK               256U
#define FCCOB5_CCOB9_MASK               512U
#define FCCOB5_CCOB10_MASK              1024U
#define FCCOB5_CCOB11_MASK              2048U
#define FCCOB5_CCOB12_MASK              4096U
#define FCCOB5_CCOB13_MASK              8192U
#define FCCOB5_CCOB14_MASK              16384U
#define FCCOB5_CCOB15_MASK              32768U


/*** ECCSTAT - ECC Status Register; 0x000003C0 ***/
typedef union {
  byte Byte;
  struct {
    byte RDY         :1;                                       /* ECC Ready */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} ECCSTATSTR;
extern volatile ECCSTATSTR _ECCSTAT @0x000003C0;
#define ECCSTAT                         _ECCSTAT.Byte
#define ECCSTAT_RDY                     _ECCSTAT.Bits.RDY

#define ECCSTAT_RDY_MASK                1U


/*** ECCIE - ECC Interrupt Enable Register; 0x000003C1 ***/
typedef union {
  byte Byte;
  struct {
    byte SBEEIE      :1;                                       /* Single Bit ECC Error Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} ECCIESTR;
extern volatile ECCIESTR _ECCIE @0x000003C1;
#define ECCIE                           _ECCIE.Byte
#define ECCIE_SBEEIE                    _ECCIE.Bits.SBEEIE

#define ECCIE_SBEEIE_MASK               1U


/*** ECCIF - ECC Interrupt Flag Register; 0x000003C2 ***/
typedef union {
  byte Byte;
  struct {
    byte SBEEIF      :1;                                       /* Single bit ECC Error Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} ECCIFSTR;
extern volatile ECCIFSTR _ECCIF @0x000003C2;
#define ECCIF                           _ECCIF.Byte
#define ECCIF_SBEEIF                    _ECCIF.Bits.SBEEIF

#define ECCIF_SBEEIF_MASK               1U


/*** ECCDPTRH - ECC Debug Point Register High; 0x000003C7 ***/
typedef union {
  byte Byte;
  struct {
    byte DPTR        :8;                                       /* ECC Debug Pointer */
  } Bits;
} ECCDPTRHSTR;
extern volatile ECCDPTRHSTR _ECCDPTRH @0x000003C7;
#define ECCDPTRH                        _ECCDPTRH.Byte
#define ECCDPTRH_DPTR                   _ECCDPTRH.Bits.DPTR

#define ECCDPTRH_DPTR_MASK              255U
#define ECCDPTRH_DPTR_BITNUM            0U


/*** ECCDPTRM - ECC Debug Point Register Middle; 0x000003C8 ***/
typedef union {
  byte Byte;
  struct {
    byte DPTR        :8;                                       /* ECC Debug Pointer */
  } Bits;
} ECCDPTRMSTR;
extern volatile ECCDPTRMSTR _ECCDPTRM @0x000003C8;
#define ECCDPTRM                        _ECCDPTRM.Byte
#define ECCDPTRM_DPTR                   _ECCDPTRM.Bits.DPTR

#define ECCDPTRM_DPTR_MASK              255U
#define ECCDPTRM_DPTR_BITNUM            0U


/*** ECCDPTRL - ECC Debug Point Register Low; 0x000003C9 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte DPTR        :7;                                       /* ECC Debug Pointer */
  } Bits;
} ECCDPTRLSTR;
extern volatile ECCDPTRLSTR _ECCDPTRL @0x000003C9;
#define ECCDPTRL                        _ECCDPTRL.Byte
#define ECCDPTRL_DPTR                   _ECCDPTRL.Bits.DPTR

#define ECCDPTRL_DPTR_MASK              254U
#define ECCDPTRL_DPTR_BITNUM            1U


/*** ECCDD - ECC Debug Data; 0x000003CC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ECCDDH - ECC Debug Data High; 0x000003CC ***/
    union {
      byte Byte;
      struct {
        byte DDATA       :8;                                       /* ECC Debug Data */
      } Bits;
    } ECCDDHSTR;
    #define ECCDDH                      _ECCDD.Overlap_STR.ECCDDHSTR.Byte
    #define ECCDDH_DDATA                _ECCDD.Overlap_STR.ECCDDHSTR.Bits.DDATA
    
    #define ECCDDH_DDATA_MASK           255U
    #define ECCDDH_DDATA_BITNUM         0U
    

    /*** ECCDDL - ECC Debug Data Low; 0x000003CD ***/
    union {
      byte Byte;
      struct {
        byte DDATA       :8;                                       /* ECC Debug Data */
      } Bits;
    } ECCDDLSTR;
    #define ECCDDL                      _ECCDD.Overlap_STR.ECCDDLSTR.Byte
    #define ECCDDL_DDATA                _ECCDD.Overlap_STR.ECCDDLSTR.Bits.DDATA
    
    #define ECCDDL_DDATA_MASK           255U
    #define ECCDDL_DDATA_BITNUM         0U
    
  } Overlap_STR;

  struct {
    word DDATA       :16;                                      /* ECC Debug Data */
  } Bits;
} ECCDDSTR;
extern volatile ECCDDSTR _ECCDD @0x000003CC;
#define ECCDD                           _ECCDD.Word
#define ECCDD_DDATA                     _ECCDD.Bits.DDATA

#define ECCDD_DDATA_MASK                65535U
#define ECCDD_DDATA_BITNUM              0U


/*** ECCDE - ECC Debug ECC; 0x000003CE ***/
typedef union {
  byte Byte;
  struct {
    byte DECC        :6;                                       /* ECC Debug ECC */
    byte             :1; 
    byte             :1; 
  } Bits;
} ECCDESTR;
extern volatile ECCDESTR _ECCDE @0x000003CE;
#define ECCDE                           _ECCDE.Byte
#define ECCDE_DECC                      _ECCDE.Bits.DECC

#define ECCDE_DECC_MASK                 63U
#define ECCDE_DECC_BITNUM               0U


/*** ECCDCMD - ECC Debug Comamnd; 0x000003CF ***/
typedef union {
  byte Byte;
  struct {
    byte ECCDR       :1;                                       /* ECC Debug Read Command */
    byte ECCDW       :1;                                       /* ECC Debug Write Command */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ECCDRR      :1;                                       /* ECC Disable Read Repair Function */
  } Bits;
} ECCDCMDSTR;
extern volatile ECCDCMDSTR _ECCDCMD @0x000003CF;
#define ECCDCMD                         _ECCDCMD.Byte
#define ECCDCMD_ECCDR                   _ECCDCMD.Bits.ECCDR
#define ECCDCMD_ECCDW                   _ECCDCMD.Bits.ECCDW
#define ECCDCMD_ECCDRR                  _ECCDCMD.Bits.ECCDRR

#define ECCDCMD_ECCDR_MASK              1U
#define ECCDCMD_ECCDW_MASK              2U
#define ECCDCMD_ECCDRR_MASK             128U


/*** CPMURFLG - CPMU Reset Flags Register; 0x000006C3 ***/
typedef union {
  byte Byte;
  struct {
    byte PMRF        :1;                                       /* PLL Clock Monitor Reset Flag */
    byte OMRF        :1;                                       /* Oscillator Clock Monitor Reset Flag */
    byte             :1; 
    byte COPRF       :1;                                       /* COP Reset Flag */
    byte             :1; 
    byte LVRF        :1;                                       /* Low Voltage Reset Flag */
    byte PORF        :1;                                       /* Power on Reset Flag */
    byte             :1; 
  } Bits;
} CPMURFLGSTR;
extern volatile CPMURFLGSTR _CPMURFLG @0x000006C3;
#define CPMURFLG                        _CPMURFLG.Byte
#define CPMURFLG_PMRF                   _CPMURFLG.Bits.PMRF
#define CPMURFLG_OMRF                   _CPMURFLG.Bits.OMRF
#define CPMURFLG_COPRF                  _CPMURFLG.Bits.COPRF
#define CPMURFLG_LVRF                   _CPMURFLG.Bits.LVRF
#define CPMURFLG_PORF                   _CPMURFLG.Bits.PORF

#define CPMURFLG_PMRF_MASK              1U
#define CPMURFLG_OMRF_MASK              2U
#define CPMURFLG_COPRF_MASK             8U
#define CPMURFLG_LVRF_MASK              32U
#define CPMURFLG_PORF_MASK              64U


/*** CPMUSYNR - CPMU Synthesizer Register; 0x000006C4 ***/
typedef union {
  byte Byte;
  struct {
    byte SYNDIV0     :1;                                       /* Multiplication factor of the IPLL bit 0 */
    byte SYNDIV1     :1;                                       /* Multiplication factor of the IPLL bit 1 */
    byte SYNDIV2     :1;                                       /* Multiplication factor of the IPLL bit 2 */
    byte SYNDIV3     :1;                                       /* Multiplication factor of the IPLL bit 3 */
    byte SYNDIV4     :1;                                       /* Multiplication factor of the IPLL bit 4 */
    byte SYNDIV5     :1;                                       /* Multiplication factor of the IPLL bit 5 */
    byte VCOFRQ0     :1;                                       /* VCO frequency range bit 0 */
    byte VCOFRQ1     :1;                                       /* VCO frequency range bit 1 */
  } Bits;
  struct {
    byte grpSYNDIV :6;
    byte grpVCOFRQ :2;
  } MergedBits;
} CPMUSYNRSTR;
extern volatile CPMUSYNRSTR _CPMUSYNR @0x000006C4;
#define CPMUSYNR                        _CPMUSYNR.Byte
#define CPMUSYNR_SYNDIV0                _CPMUSYNR.Bits.SYNDIV0
#define CPMUSYNR_SYNDIV1                _CPMUSYNR.Bits.SYNDIV1
#define CPMUSYNR_SYNDIV2                _CPMUSYNR.Bits.SYNDIV2
#define CPMUSYNR_SYNDIV3                _CPMUSYNR.Bits.SYNDIV3
#define CPMUSYNR_SYNDIV4                _CPMUSYNR.Bits.SYNDIV4
#define CPMUSYNR_SYNDIV5                _CPMUSYNR.Bits.SYNDIV5
#define CPMUSYNR_VCOFRQ0                _CPMUSYNR.Bits.VCOFRQ0
#define CPMUSYNR_VCOFRQ1                _CPMUSYNR.Bits.VCOFRQ1
#define CPMUSYNR_SYNDIV                 _CPMUSYNR.MergedBits.grpSYNDIV
#define CPMUSYNR_VCOFRQ                 _CPMUSYNR.MergedBits.grpVCOFRQ

#define CPMUSYNR_SYNDIV0_MASK           1U
#define CPMUSYNR_SYNDIV1_MASK           2U
#define CPMUSYNR_SYNDIV2_MASK           4U
#define CPMUSYNR_SYNDIV3_MASK           8U
#define CPMUSYNR_SYNDIV4_MASK           16U
#define CPMUSYNR_SYNDIV5_MASK           32U
#define CPMUSYNR_VCOFRQ0_MASK           64U
#define CPMUSYNR_VCOFRQ1_MASK           128U
#define CPMUSYNR_SYNDIV_MASK            63U
#define CPMUSYNR_SYNDIV_BITNUM          0U
#define CPMUSYNR_VCOFRQ_MASK            192U
#define CPMUSYNR_VCOFRQ_BITNUM          6U


/*** CPMUREFDIV - CPMU Reference Divider Register; 0x000006C5 ***/
typedef union {
  byte Byte;
  struct {
    byte REFDIV0     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 0 */
    byte REFDIV1     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 1 */
    byte REFDIV2     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 2 */
    byte REFDIV3     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 3 */
    byte             :1; 
    byte             :1; 
    byte REFFRQ0     :1;                                       /* IPLL optimal stability and lock time configuration bit 0 */
    byte REFFRQ1     :1;                                       /* IPLL optimal stability and lock time configuration bit 1 */
  } Bits;
  struct {
    byte grpREFDIV :4;
    byte         :1;
    byte         :1;
    byte grpREFFRQ :2;
  } MergedBits;
} CPMUREFDIVSTR;
extern volatile CPMUREFDIVSTR _CPMUREFDIV @0x000006C5;
#define CPMUREFDIV                      _CPMUREFDIV.Byte
#define CPMUREFDIV_REFDIV0              _CPMUREFDIV.Bits.REFDIV0
#define CPMUREFDIV_REFDIV1              _CPMUREFDIV.Bits.REFDIV1
#define CPMUREFDIV_REFDIV2              _CPMUREFDIV.Bits.REFDIV2
#define CPMUREFDIV_REFDIV3              _CPMUREFDIV.Bits.REFDIV3
#define CPMUREFDIV_REFFRQ0              _CPMUREFDIV.Bits.REFFRQ0
#define CPMUREFDIV_REFFRQ1              _CPMUREFDIV.Bits.REFFRQ1
#define CPMUREFDIV_REFDIV               _CPMUREFDIV.MergedBits.grpREFDIV
#define CPMUREFDIV_REFFRQ               _CPMUREFDIV.MergedBits.grpREFFRQ

#define CPMUREFDIV_REFDIV0_MASK         1U
#define CPMUREFDIV_REFDIV1_MASK         2U
#define CPMUREFDIV_REFDIV2_MASK         4U
#define CPMUREFDIV_REFDIV3_MASK         8U
#define CPMUREFDIV_REFFRQ0_MASK         64U
#define CPMUREFDIV_REFFRQ1_MASK         128U
#define CPMUREFDIV_REFDIV_MASK          15U
#define CPMUREFDIV_REFDIV_BITNUM        0U
#define CPMUREFDIV_REFFRQ_MASK          192U
#define CPMUREFDIV_REFFRQ_BITNUM        6U


/*** CPMUPOSTDIV - CPMU Post Divider Register; 0x000006C6 ***/
typedef union {
  byte Byte;
  struct {
    byte POSTDIV0    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 0 */
    byte POSTDIV1    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 1 */
    byte POSTDIV2    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 2 */
    byte POSTDIV3    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 3 */
    byte POSTDIV4    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPOSTDIV :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUPOSTDIVSTR;
extern volatile CPMUPOSTDIVSTR _CPMUPOSTDIV @0x000006C6;
#define CPMUPOSTDIV                     _CPMUPOSTDIV.Byte
#define CPMUPOSTDIV_POSTDIV0            _CPMUPOSTDIV.Bits.POSTDIV0
#define CPMUPOSTDIV_POSTDIV1            _CPMUPOSTDIV.Bits.POSTDIV1
#define CPMUPOSTDIV_POSTDIV2            _CPMUPOSTDIV.Bits.POSTDIV2
#define CPMUPOSTDIV_POSTDIV3            _CPMUPOSTDIV.Bits.POSTDIV3
#define CPMUPOSTDIV_POSTDIV4            _CPMUPOSTDIV.Bits.POSTDIV4
#define CPMUPOSTDIV_POSTDIV             _CPMUPOSTDIV.MergedBits.grpPOSTDIV

#define CPMUPOSTDIV_POSTDIV0_MASK       1U
#define CPMUPOSTDIV_POSTDIV1_MASK       2U
#define CPMUPOSTDIV_POSTDIV2_MASK       4U
#define CPMUPOSTDIV_POSTDIV3_MASK       8U
#define CPMUPOSTDIV_POSTDIV4_MASK       16U
#define CPMUPOSTDIV_POSTDIV_MASK        31U
#define CPMUPOSTDIV_POSTDIV_BITNUM      0U


/*** CPMUIFLG - CPMU Interrupt Flags Register; 0x000006C7 ***/
typedef union {
  byte Byte;
  struct {
    byte UPOSC       :1;                                       /* Oscillator Status Bit */
    byte OSCIF       :1;                                       /* Oscillator Interrupt Flag */
    byte             :1; 
    byte LOCK        :1;                                       /* Lock Status Bit */
    byte LOCKIF      :1;                                       /* PLL Lock Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte RTIF        :1;                                       /* Real Time Interrupt Flag */
  } Bits;
} CPMUIFLGSTR;
extern volatile CPMUIFLGSTR _CPMUIFLG @0x000006C7;
#define CPMUIFLG                        _CPMUIFLG.Byte
#define CPMUIFLG_UPOSC                  _CPMUIFLG.Bits.UPOSC
#define CPMUIFLG_OSCIF                  _CPMUIFLG.Bits.OSCIF
#define CPMUIFLG_LOCK                   _CPMUIFLG.Bits.LOCK
#define CPMUIFLG_LOCKIF                 _CPMUIFLG.Bits.LOCKIF
#define CPMUIFLG_RTIF                   _CPMUIFLG.Bits.RTIF

#define CPMUIFLG_UPOSC_MASK             1U
#define CPMUIFLG_OSCIF_MASK             2U
#define CPMUIFLG_LOCK_MASK              8U
#define CPMUIFLG_LOCKIF_MASK            16U
#define CPMUIFLG_RTIF_MASK              128U


/*** CPMUINT - CPMU Interrupt Enable Register; 0x000006C8 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte OSCIE       :1;                                       /* Oscillator Corrupt Interrupt Enable Bit */
    byte             :1; 
    byte             :1; 
    byte LOCKIE      :1;                                       /* Lock Interrupt Enable Bit */
    byte             :1; 
    byte             :1; 
    byte RTIE        :1;                                       /* Real Time Interrupt Enable Bit */
  } Bits;
} CPMUINTSTR;
extern volatile CPMUINTSTR _CPMUINT @0x000006C8;
#define CPMUINT                         _CPMUINT.Byte
#define CPMUINT_OSCIE                   _CPMUINT.Bits.OSCIE
#define CPMUINT_LOCKIE                  _CPMUINT.Bits.LOCKIE
#define CPMUINT_RTIE                    _CPMUINT.Bits.RTIE

#define CPMUINT_OSCIE_MASK              2U
#define CPMUINT_LOCKIE_MASK             16U
#define CPMUINT_RTIE_MASK               128U


/*** CPMUCLKS - CPMU Clock Select Register; 0x000006C9 ***/
typedef union {
  byte Byte;
  struct {
    byte COPOSCSEL0  :1;                                       /* COP Clock Select 0 */
    byte RTIOSCSEL   :1;                                       /* RTI Clock Select */
    byte PCE         :1;                                       /* COP Enable During Pseudo Stop Bit */
    byte PRE         :1;                                       /* RTI Enable During Pseudo Stop Bit */
    byte COPOSCSEL1  :1;                                       /* COP Clock Select 1 */
    byte CSAD        :1;                                       /* COP in Stop Mode ACLK Disable */
    byte PSTP        :1;                                       /* Pseudo Stop Bit */
    byte PLLSEL      :1;                                       /* PLL Select Bit */
  } Bits;
} CPMUCLKSSTR;
extern volatile CPMUCLKSSTR _CPMUCLKS @0x000006C9;
#define CPMUCLKS                        _CPMUCLKS.Byte
#define CPMUCLKS_COPOSCSEL0             _CPMUCLKS.Bits.COPOSCSEL0
#define CPMUCLKS_RTIOSCSEL              _CPMUCLKS.Bits.RTIOSCSEL
#define CPMUCLKS_PCE                    _CPMUCLKS.Bits.PCE
#define CPMUCLKS_PRE                    _CPMUCLKS.Bits.PRE
#define CPMUCLKS_COPOSCSEL1             _CPMUCLKS.Bits.COPOSCSEL1
#define CPMUCLKS_CSAD                   _CPMUCLKS.Bits.CSAD
#define CPMUCLKS_PSTP                   _CPMUCLKS.Bits.PSTP
#define CPMUCLKS_PLLSEL                 _CPMUCLKS.Bits.PLLSEL

#define CPMUCLKS_COPOSCSEL0_MASK        1U
#define CPMUCLKS_RTIOSCSEL_MASK         2U
#define CPMUCLKS_PCE_MASK               4U
#define CPMUCLKS_PRE_MASK               8U
#define CPMUCLKS_COPOSCSEL1_MASK        16U
#define CPMUCLKS_CSAD_MASK              32U
#define CPMUCLKS_PSTP_MASK              64U
#define CPMUCLKS_PLLSEL_MASK            128U


/*** CPMUPLL - CPMU PLL Control Register; 0x000006CA ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FM0         :1;                                       /* PLL Frequency Modulation Enable Bit 0 */
    byte FM1         :1;                                       /* PLL Frequency Modulation Enable Bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpFM   :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUPLLSTR;
extern volatile CPMUPLLSTR _CPMUPLL @0x000006CA;
#define CPMUPLL                         _CPMUPLL.Byte
#define CPMUPLL_FM0                     _CPMUPLL.Bits.FM0
#define CPMUPLL_FM1                     _CPMUPLL.Bits.FM1
#define CPMUPLL_FM                      _CPMUPLL.MergedBits.grpFM

#define CPMUPLL_FM0_MASK                16U
#define CPMUPLL_FM1_MASK                32U
#define CPMUPLL_FM_MASK                 48U
#define CPMUPLL_FM_BITNUM               4U


/*** CPMURTI - CPMU RTI Control Register; 0x000006CB ***/
typedef union {
  byte Byte;
  struct {
    byte RTR0        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 0 */
    byte RTR1        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 1 */
    byte RTR2        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 2 */
    byte RTR3        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 3 */
    byte RTR4        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 4 */
    byte RTR5        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 5 */
    byte RTR6        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 6 */
    byte RTDEC       :1;                                       /* Decimal or Binary Divider Select Bit */
  } Bits;
  struct {
    byte grpRTR  :7;
    byte         :1;
  } MergedBits;
} CPMURTISTR;
extern volatile CPMURTISTR _CPMURTI @0x000006CB;
#define CPMURTI                         _CPMURTI.Byte
#define CPMURTI_RTR0                    _CPMURTI.Bits.RTR0
#define CPMURTI_RTR1                    _CPMURTI.Bits.RTR1
#define CPMURTI_RTR2                    _CPMURTI.Bits.RTR2
#define CPMURTI_RTR3                    _CPMURTI.Bits.RTR3
#define CPMURTI_RTR4                    _CPMURTI.Bits.RTR4
#define CPMURTI_RTR5                    _CPMURTI.Bits.RTR5
#define CPMURTI_RTR6                    _CPMURTI.Bits.RTR6
#define CPMURTI_RTDEC                   _CPMURTI.Bits.RTDEC
#define CPMURTI_RTR                     _CPMURTI.MergedBits.grpRTR

#define CPMURTI_RTR0_MASK               1U
#define CPMURTI_RTR1_MASK               2U
#define CPMURTI_RTR2_MASK               4U
#define CPMURTI_RTR3_MASK               8U
#define CPMURTI_RTR4_MASK               16U
#define CPMURTI_RTR5_MASK               32U
#define CPMURTI_RTR6_MASK               64U
#define CPMURTI_RTDEC_MASK              128U
#define CPMURTI_RTR_MASK                127U
#define CPMURTI_RTR_BITNUM              0U


/*** CPMUCOP - CPMU COP Control Register; 0x000006CC ***/
typedef union {
  byte Byte;
  struct {
    byte CR0         :1;                                       /* COP Watchdog Timer Rate select Bit 0 */
    byte CR1         :1;                                       /* COP Watchdog Timer Rate select Bit 1 */
    byte CR2         :1;                                       /* COP Watchdog Timer Rate select Bit 2 */
    byte             :1; 
    byte             :1; 
    byte WRTMASK     :1;                                       /* Write Mask for WCOP */
    byte RSBCK       :1;                                       /* COP and RTI stop in Active BDM mode Bit */
    byte WCOP        :1;                                       /* Window COP mode */
  } Bits;
  struct {
    byte grpCR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUCOPSTR;
extern volatile CPMUCOPSTR _CPMUCOP @0x000006CC;
#define CPMUCOP                         _CPMUCOP.Byte
#define CPMUCOP_CR0                     _CPMUCOP.Bits.CR0
#define CPMUCOP_CR1                     _CPMUCOP.Bits.CR1
#define CPMUCOP_CR2                     _CPMUCOP.Bits.CR2
#define CPMUCOP_WRTMASK                 _CPMUCOP.Bits.WRTMASK
#define CPMUCOP_RSBCK                   _CPMUCOP.Bits.RSBCK
#define CPMUCOP_WCOP                    _CPMUCOP.Bits.WCOP
#define CPMUCOP_CR                      _CPMUCOP.MergedBits.grpCR

#define CPMUCOP_CR0_MASK                1U
#define CPMUCOP_CR1_MASK                2U
#define CPMUCOP_CR2_MASK                4U
#define CPMUCOP_WRTMASK_MASK            32U
#define CPMUCOP_RSBCK_MASK              64U
#define CPMUCOP_WCOP_MASK               128U
#define CPMUCOP_CR_MASK                 7U
#define CPMUCOP_CR_BITNUM               0U


/*** CPMUARMCOP - CPMU COP Timer Arm/Reset Register; 0x000006CF ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* CPMU COP Timer Arm/Reset Bit 0 */
    byte BIT1        :1;                                       /* CPMU COP Timer Arm/Reset Bit 1 */
    byte BIT2        :1;                                       /* CPMU COP Timer Arm/Reset Bit 2 */
    byte BIT3        :1;                                       /* CPMU COP Timer Arm/Reset Bit 3 */
    byte BIT4        :1;                                       /* CPMU COP Timer Arm/Reset Bit 4 */
    byte BIT5        :1;                                       /* CPMU COP Timer Arm/Reset Bit 5 */
    byte BIT6        :1;                                       /* CPMU COP Timer Arm/Reset Bit 6 */
    byte BIT7        :1;                                       /* CPMU COP Timer Arm/Reset Bit 7 */
  } Bits;
} CPMUARMCOPSTR;
extern volatile CPMUARMCOPSTR _CPMUARMCOP @0x000006CF;
#define CPMUARMCOP                      _CPMUARMCOP.Byte
#define CPMUARMCOP_BIT0                 _CPMUARMCOP.Bits.BIT0
#define CPMUARMCOP_BIT1                 _CPMUARMCOP.Bits.BIT1
#define CPMUARMCOP_BIT2                 _CPMUARMCOP.Bits.BIT2
#define CPMUARMCOP_BIT3                 _CPMUARMCOP.Bits.BIT3
#define CPMUARMCOP_BIT4                 _CPMUARMCOP.Bits.BIT4
#define CPMUARMCOP_BIT5                 _CPMUARMCOP.Bits.BIT5
#define CPMUARMCOP_BIT6                 _CPMUARMCOP.Bits.BIT6
#define CPMUARMCOP_BIT7                 _CPMUARMCOP.Bits.BIT7

#define CPMUARMCOP_BIT0_MASK            1U
#define CPMUARMCOP_BIT1_MASK            2U
#define CPMUARMCOP_BIT2_MASK            4U
#define CPMUARMCOP_BIT3_MASK            8U
#define CPMUARMCOP_BIT4_MASK            16U
#define CPMUARMCOP_BIT5_MASK            32U
#define CPMUARMCOP_BIT6_MASK            64U
#define CPMUARMCOP_BIT7_MASK            128U


/*** CPMULVCTL - Low Voltage Control Register; 0x000006D1 ***/
typedef union {
  byte Byte;
  struct {
    byte LVIF        :1;                                       /* Low-Voltage Interrupt Flag */
    byte LVIE        :1;                                       /* Low-Voltage Interrupt Enable Bit */
    byte LVDS        :1;                                       /* Low-Voltage Detect Status Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMULVCTLSTR;
extern volatile CPMULVCTLSTR _CPMULVCTL @0x000006D1;
#define CPMULVCTL                       _CPMULVCTL.Byte
#define CPMULVCTL_LVIF                  _CPMULVCTL.Bits.LVIF
#define CPMULVCTL_LVIE                  _CPMULVCTL.Bits.LVIE
#define CPMULVCTL_LVDS                  _CPMULVCTL.Bits.LVDS

#define CPMULVCTL_LVIF_MASK             1U
#define CPMULVCTL_LVIE_MASK             2U
#define CPMULVCTL_LVDS_MASK             4U


/*** CPMUAPICTL - Autonomous Periodical Interrupt Control Register; 0x000006D2 ***/
typedef union {
  byte Byte;
  struct {
    byte APIF        :1;                                       /* Autonomous Periodical Interrupt Flag */
    byte APIE        :1;                                       /* Autonomous Periodical Interrupt Enable Bit */
    byte APIFE       :1;                                       /* Autonomous Periodical Interrupt Feature Enable Bit */
    byte APIEA       :1;                                       /* Autonomous Periodical Interrupt External Access Enable Bit */
    byte APIES       :1;                                       /* Autonomous Periodical Interrupt External Select Bit */
    byte             :1; 
    byte             :1; 
    byte APICLK      :1;                                       /* Autonomous Periodical Interrupt Clock Select Bit */
  } Bits;
} CPMUAPICTLSTR;
extern volatile CPMUAPICTLSTR _CPMUAPICTL @0x000006D2;
#define CPMUAPICTL                      _CPMUAPICTL.Byte
#define CPMUAPICTL_APIF                 _CPMUAPICTL.Bits.APIF
#define CPMUAPICTL_APIE                 _CPMUAPICTL.Bits.APIE
#define CPMUAPICTL_APIFE                _CPMUAPICTL.Bits.APIFE
#define CPMUAPICTL_APIEA                _CPMUAPICTL.Bits.APIEA
#define CPMUAPICTL_APIES                _CPMUAPICTL.Bits.APIES
#define CPMUAPICTL_APICLK               _CPMUAPICTL.Bits.APICLK

#define CPMUAPICTL_APIF_MASK            1U
#define CPMUAPICTL_APIE_MASK            2U
#define CPMUAPICTL_APIFE_MASK           4U
#define CPMUAPICTL_APIEA_MASK           8U
#define CPMUAPICTL_APIES_MASK           16U
#define CPMUAPICTL_APICLK_MASK          128U


/*** CPMUACLKTR - Autonomous Clock Trimming Register; 0x000006D3 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ACLKTR0     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 0 */
    byte ACLKTR1     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 1 */
    byte ACLKTR2     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 2 */
    byte ACLKTR3     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 3 */
    byte ACLKTR4     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 4 */
    byte ACLKTR5     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 5 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpACLKTR :6;
  } MergedBits;
} CPMUACLKTRSTR;
extern volatile CPMUACLKTRSTR _CPMUACLKTR @0x000006D3;
#define CPMUACLKTR                      _CPMUACLKTR.Byte
#define CPMUACLKTR_ACLKTR0              _CPMUACLKTR.Bits.ACLKTR0
#define CPMUACLKTR_ACLKTR1              _CPMUACLKTR.Bits.ACLKTR1
#define CPMUACLKTR_ACLKTR2              _CPMUACLKTR.Bits.ACLKTR2
#define CPMUACLKTR_ACLKTR3              _CPMUACLKTR.Bits.ACLKTR3
#define CPMUACLKTR_ACLKTR4              _CPMUACLKTR.Bits.ACLKTR4
#define CPMUACLKTR_ACLKTR5              _CPMUACLKTR.Bits.ACLKTR5
#define CPMUACLKTR_ACLKTR               _CPMUACLKTR.MergedBits.grpACLKTR

#define CPMUACLKTR_ACLKTR0_MASK         4U
#define CPMUACLKTR_ACLKTR1_MASK         8U
#define CPMUACLKTR_ACLKTR2_MASK         16U
#define CPMUACLKTR_ACLKTR3_MASK         32U
#define CPMUACLKTR_ACLKTR4_MASK         64U
#define CPMUACLKTR_ACLKTR5_MASK         128U
#define CPMUACLKTR_ACLKTR_MASK          252U
#define CPMUACLKTR_ACLKTR_BITNUM        2U


/*** CPMUAPIR - Autonomous Periodical Interrupt Rate Register; 0x000006D4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CPMUAPIRH - Autonomous Periodical Interrupt Rate Register High; 0x000006D4 ***/
    union {
      byte Byte;
      struct {
        byte APIR8       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 8 */
        byte APIR9       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 9 */
        byte APIR10      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 10 */
        byte APIR11      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 11 */
        byte APIR12      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 12 */
        byte APIR13      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 13 */
        byte APIR14      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 14 */
        byte APIR15      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 15 */
      } Bits;
    } CPMUAPIRHSTR;
    #define CPMUAPIRH                   _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Byte
    #define CPMUAPIRH_APIR8             _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR8
    #define CPMUAPIRH_APIR9             _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR9
    #define CPMUAPIRH_APIR10            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR10
    #define CPMUAPIRH_APIR11            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR11
    #define CPMUAPIRH_APIR12            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR12
    #define CPMUAPIRH_APIR13            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR13
    #define CPMUAPIRH_APIR14            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR14
    #define CPMUAPIRH_APIR15            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR15
    
    #define CPMUAPIRH_APIR8_MASK        1U
    #define CPMUAPIRH_APIR9_MASK        2U
    #define CPMUAPIRH_APIR10_MASK       4U
    #define CPMUAPIRH_APIR11_MASK       8U
    #define CPMUAPIRH_APIR12_MASK       16U
    #define CPMUAPIRH_APIR13_MASK       32U
    #define CPMUAPIRH_APIR14_MASK       64U
    #define CPMUAPIRH_APIR15_MASK       128U
    

    /*** CPMUAPIRL - Autonomous Periodical Interrupt Rate Register Low; 0x000006D5 ***/
    union {
      byte Byte;
      struct {
        byte APIR0       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 0 */
        byte APIR1       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 1 */
        byte APIR2       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 2 */
        byte APIR3       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 3 */
        byte APIR4       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 4 */
        byte APIR5       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 5 */
        byte APIR6       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 6 */
        byte APIR7       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 7 */
      } Bits;
    } CPMUAPIRLSTR;
    #define CPMUAPIRL                   _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Byte
    #define CPMUAPIRL_APIR0             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR0
    #define CPMUAPIRL_APIR1             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR1
    #define CPMUAPIRL_APIR2             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR2
    #define CPMUAPIRL_APIR3             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR3
    #define CPMUAPIRL_APIR4             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR4
    #define CPMUAPIRL_APIR5             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR5
    #define CPMUAPIRL_APIR6             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR6
    #define CPMUAPIRL_APIR7             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR7
    
    #define CPMUAPIRL_APIR0_MASK        1U
    #define CPMUAPIRL_APIR1_MASK        2U
    #define CPMUAPIRL_APIR2_MASK        4U
    #define CPMUAPIRL_APIR3_MASK        8U
    #define CPMUAPIRL_APIR4_MASK        16U
    #define CPMUAPIRL_APIR5_MASK        32U
    #define CPMUAPIRL_APIR6_MASK        64U
    #define CPMUAPIRL_APIR7_MASK        128U
    
  } Overlap_STR;

  struct {
    word APIR0       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 0 */
    word APIR1       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 1 */
    word APIR2       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 2 */
    word APIR3       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 3 */
    word APIR4       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 4 */
    word APIR5       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 5 */
    word APIR6       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 6 */
    word APIR7       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 7 */
    word APIR8       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 8 */
    word APIR9       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 9 */
    word APIR10      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 10 */
    word APIR11      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 11 */
    word APIR12      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 12 */
    word APIR13      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 13 */
    word APIR14      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 14 */
    word APIR15      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 15 */
  } Bits;
} CPMUAPIRSTR;
extern volatile CPMUAPIRSTR _CPMUAPIR @0x000006D4;
#define CPMUAPIR                        _CPMUAPIR.Word
#define CPMUAPIR_APIR0                  _CPMUAPIR.Bits.APIR0
#define CPMUAPIR_APIR1                  _CPMUAPIR.Bits.APIR1
#define CPMUAPIR_APIR2                  _CPMUAPIR.Bits.APIR2
#define CPMUAPIR_APIR3                  _CPMUAPIR.Bits.APIR3
#define CPMUAPIR_APIR4                  _CPMUAPIR.Bits.APIR4
#define CPMUAPIR_APIR5                  _CPMUAPIR.Bits.APIR5
#define CPMUAPIR_APIR6                  _CPMUAPIR.Bits.APIR6
#define CPMUAPIR_APIR7                  _CPMUAPIR.Bits.APIR7
#define CPMUAPIR_APIR8                  _CPMUAPIR.Bits.APIR8
#define CPMUAPIR_APIR9                  _CPMUAPIR.Bits.APIR9
#define CPMUAPIR_APIR10                 _CPMUAPIR.Bits.APIR10
#define CPMUAPIR_APIR11                 _CPMUAPIR.Bits.APIR11
#define CPMUAPIR_APIR12                 _CPMUAPIR.Bits.APIR12
#define CPMUAPIR_APIR13                 _CPMUAPIR.Bits.APIR13
#define CPMUAPIR_APIR14                 _CPMUAPIR.Bits.APIR14
#define CPMUAPIR_APIR15                 _CPMUAPIR.Bits.APIR15

#define CPMUAPIR_APIR0_MASK             1U
#define CPMUAPIR_APIR1_MASK             2U
#define CPMUAPIR_APIR2_MASK             4U
#define CPMUAPIR_APIR3_MASK             8U
#define CPMUAPIR_APIR4_MASK             16U
#define CPMUAPIR_APIR5_MASK             32U
#define CPMUAPIR_APIR6_MASK             64U
#define CPMUAPIR_APIR7_MASK             128U
#define CPMUAPIR_APIR8_MASK             256U
#define CPMUAPIR_APIR9_MASK             512U
#define CPMUAPIR_APIR10_MASK            1024U
#define CPMUAPIR_APIR11_MASK            2048U
#define CPMUAPIR_APIR12_MASK            4096U
#define CPMUAPIR_APIR13_MASK            8192U
#define CPMUAPIR_APIR14_MASK            16384U
#define CPMUAPIR_APIR15_MASK            32768U


/*** CPMUIRCTRIM - CPMU IRC1M Trim Registers; 0x000006D8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CPMUIRCTRIMH - CPMU IRC1M Trim Registers High; 0x000006D8 ***/
    union {
      byte Byte;
      struct {
        byte IRCTRIM8    :1;                                       /* IRC1M Frequency Trim Bit 8 */
        byte IRCTRIM9    :1;                                       /* IRC1M Frequency Trim Bit 9 */
        byte             :1; 
        byte TCTRIM0     :1;                                       /* IRC1M temperature coeficient Trim Bit 0 */
        byte TCTRIM1     :1;                                       /* IRC1M temperature coeficient Trim Bit 1 */
        byte TCTRIM2     :1;                                       /* IRC1M temperature coeficient Trim Bit 2 */
        byte TCTRIM3     :1;                                       /* IRC1M temperature coeficient Trim Bit 3 */
        byte TCTRIM4     :1;                                       /* IRC1M temperature coeficient Trim Bit 4 */
      } Bits;
      struct {
        byte grpIRCTRIM_8 :2;
        byte     :1;
        byte grpTCTRIM :5;
      } MergedBits;
    } CPMUIRCTRIMHSTR;
    #define CPMUIRCTRIMH                _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Byte
    #define CPMUIRCTRIMH_IRCTRIM8       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.IRCTRIM8
    #define CPMUIRCTRIMH_IRCTRIM9       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.IRCTRIM9
    #define CPMUIRCTRIMH_TCTRIM0        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM0
    #define CPMUIRCTRIMH_TCTRIM1        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM1
    #define CPMUIRCTRIMH_TCTRIM2        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM2
    #define CPMUIRCTRIMH_TCTRIM3        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM3
    #define CPMUIRCTRIMH_TCTRIM4        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM4
    #define CPMUIRCTRIMH_IRCTRIM_8      _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.MergedBits.grpIRCTRIM_8
    #define CPMUIRCTRIMH_TCTRIM         _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.MergedBits.grpTCTRIM
    #define CPMUIRCTRIMH_IRCTRIM        CPMUIRCTRIMH_IRCTRIM_8
    
    #define CPMUIRCTRIMH_IRCTRIM8_MASK  1U
    #define CPMUIRCTRIMH_IRCTRIM9_MASK  2U
    #define CPMUIRCTRIMH_TCTRIM0_MASK   8U
    #define CPMUIRCTRIMH_TCTRIM1_MASK   16U
    #define CPMUIRCTRIMH_TCTRIM2_MASK   32U
    #define CPMUIRCTRIMH_TCTRIM3_MASK   64U
    #define CPMUIRCTRIMH_TCTRIM4_MASK   128U
    #define CPMUIRCTRIMH_IRCTRIM_8_MASK 3U
    #define CPMUIRCTRIMH_IRCTRIM_8_BITNUM 0U
    #define CPMUIRCTRIMH_TCTRIM_MASK    248U
    #define CPMUIRCTRIMH_TCTRIM_BITNUM  3U
    

    /*** CPMUIRCTRIML - CPMU IRC1M Trim Registers Low; 0x000006D9 ***/
    union {
      byte Byte;
      struct {
        byte IRCTRIM0    :1;                                       /* IRC1M Frequency Trim Bit 0 */
        byte IRCTRIM1    :1;                                       /* IRC1M Frequency Trim Bit 1 */
        byte IRCTRIM2    :1;                                       /* IRC1M Frequency Trim Bit 2 */
        byte IRCTRIM3    :1;                                       /* IRC1M Frequency Trim Bit 3 */
        byte IRCTRIM4    :1;                                       /* IRC1M Frequency Trim Bit 4 */
        byte IRCTRIM5    :1;                                       /* IRC1M Frequency Trim Bit 5 */
        byte IRCTRIM6    :1;                                       /* IRC1M Frequency Trim Bit 6 */
        byte IRCTRIM7    :1;                                       /* IRC1M Frequency Trim Bit 7 */
      } Bits;
    } CPMUIRCTRIMLSTR;
    #define CPMUIRCTRIML                _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Byte
    #define CPMUIRCTRIML_IRCTRIM0       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM0
    #define CPMUIRCTRIML_IRCTRIM1       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM1
    #define CPMUIRCTRIML_IRCTRIM2       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM2
    #define CPMUIRCTRIML_IRCTRIM3       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM3
    #define CPMUIRCTRIML_IRCTRIM4       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM4
    #define CPMUIRCTRIML_IRCTRIM5       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM5
    #define CPMUIRCTRIML_IRCTRIM6       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM6
    #define CPMUIRCTRIML_IRCTRIM7       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM7
    
    #define CPMUIRCTRIML_IRCTRIM0_MASK  1U
    #define CPMUIRCTRIML_IRCTRIM1_MASK  2U
    #define CPMUIRCTRIML_IRCTRIM2_MASK  4U
    #define CPMUIRCTRIML_IRCTRIM3_MASK  8U
    #define CPMUIRCTRIML_IRCTRIM4_MASK  16U
    #define CPMUIRCTRIML_IRCTRIM5_MASK  32U
    #define CPMUIRCTRIML_IRCTRIM6_MASK  64U
    #define CPMUIRCTRIML_IRCTRIM7_MASK  128U
    
  } Overlap_STR;

  struct {
    word IRCTRIM0    :1;                                       /* IRC1M Frequency Trim Bit 0 */
    word IRCTRIM1    :1;                                       /* IRC1M Frequency Trim Bit 1 */
    word IRCTRIM2    :1;                                       /* IRC1M Frequency Trim Bit 2 */
    word IRCTRIM3    :1;                                       /* IRC1M Frequency Trim Bit 3 */
    word IRCTRIM4    :1;                                       /* IRC1M Frequency Trim Bit 4 */
    word IRCTRIM5    :1;                                       /* IRC1M Frequency Trim Bit 5 */
    word IRCTRIM6    :1;                                       /* IRC1M Frequency Trim Bit 6 */
    word IRCTRIM7    :1;                                       /* IRC1M Frequency Trim Bit 7 */
    word IRCTRIM8    :1;                                       /* IRC1M Frequency Trim Bit 8 */
    word IRCTRIM9    :1;                                       /* IRC1M Frequency Trim Bit 9 */
    word             :1; 
    word TCTRIM0     :1;                                       /* IRC1M temperature coeficient Trim Bit 0 */
    word TCTRIM1     :1;                                       /* IRC1M temperature coeficient Trim Bit 1 */
    word TCTRIM2     :1;                                       /* IRC1M temperature coeficient Trim Bit 2 */
    word TCTRIM3     :1;                                       /* IRC1M temperature coeficient Trim Bit 3 */
    word TCTRIM4     :1;                                       /* IRC1M temperature coeficient Trim Bit 4 */
  } Bits;
  struct {
    word grpIRCTRIM :10;
    word         :1;
    word grpTCTRIM :5;
  } MergedBits;
} CPMUIRCTRIMSTR;
extern volatile CPMUIRCTRIMSTR _CPMUIRCTRIM @0x000006D8;
#define CPMUIRCTRIM                     _CPMUIRCTRIM.Word
#define CPMUIRCTRIM_IRCTRIM0            _CPMUIRCTRIM.Bits.IRCTRIM0
#define CPMUIRCTRIM_IRCTRIM1            _CPMUIRCTRIM.Bits.IRCTRIM1
#define CPMUIRCTRIM_IRCTRIM2            _CPMUIRCTRIM.Bits.IRCTRIM2
#define CPMUIRCTRIM_IRCTRIM3            _CPMUIRCTRIM.Bits.IRCTRIM3
#define CPMUIRCTRIM_IRCTRIM4            _CPMUIRCTRIM.Bits.IRCTRIM4
#define CPMUIRCTRIM_IRCTRIM5            _CPMUIRCTRIM.Bits.IRCTRIM5
#define CPMUIRCTRIM_IRCTRIM6            _CPMUIRCTRIM.Bits.IRCTRIM6
#define CPMUIRCTRIM_IRCTRIM7            _CPMUIRCTRIM.Bits.IRCTRIM7
#define CPMUIRCTRIM_IRCTRIM8            _CPMUIRCTRIM.Bits.IRCTRIM8
#define CPMUIRCTRIM_IRCTRIM9            _CPMUIRCTRIM.Bits.IRCTRIM9
#define CPMUIRCTRIM_TCTRIM0             _CPMUIRCTRIM.Bits.TCTRIM0
#define CPMUIRCTRIM_TCTRIM1             _CPMUIRCTRIM.Bits.TCTRIM1
#define CPMUIRCTRIM_TCTRIM2             _CPMUIRCTRIM.Bits.TCTRIM2
#define CPMUIRCTRIM_TCTRIM3             _CPMUIRCTRIM.Bits.TCTRIM3
#define CPMUIRCTRIM_TCTRIM4             _CPMUIRCTRIM.Bits.TCTRIM4
#define CPMUIRCTRIM_IRCTRIM             _CPMUIRCTRIM.MergedBits.grpIRCTRIM
#define CPMUIRCTRIM_TCTRIM              _CPMUIRCTRIM.MergedBits.grpTCTRIM

#define CPMUIRCTRIM_IRCTRIM0_MASK       1U
#define CPMUIRCTRIM_IRCTRIM1_MASK       2U
#define CPMUIRCTRIM_IRCTRIM2_MASK       4U
#define CPMUIRCTRIM_IRCTRIM3_MASK       8U
#define CPMUIRCTRIM_IRCTRIM4_MASK       16U
#define CPMUIRCTRIM_IRCTRIM5_MASK       32U
#define CPMUIRCTRIM_IRCTRIM6_MASK       64U
#define CPMUIRCTRIM_IRCTRIM7_MASK       128U
#define CPMUIRCTRIM_IRCTRIM8_MASK       256U
#define CPMUIRCTRIM_IRCTRIM9_MASK       512U
#define CPMUIRCTRIM_TCTRIM0_MASK        2048U
#define CPMUIRCTRIM_TCTRIM1_MASK        4096U
#define CPMUIRCTRIM_TCTRIM2_MASK        8192U
#define CPMUIRCTRIM_TCTRIM3_MASK        16384U
#define CPMUIRCTRIM_TCTRIM4_MASK        32768U
#define CPMUIRCTRIM_IRCTRIM_MASK        1023U
#define CPMUIRCTRIM_IRCTRIM_BITNUM      0U
#define CPMUIRCTRIM_TCTRIM_MASK         63488U
#define CPMUIRCTRIM_TCTRIM_BITNUM       11U


/*** CPMUOSC - CPMU Oscillator Register; 0x000006DA ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte OSCE        :1;                                       /* Oscillator Enable Bit */
  } Bits;
} CPMUOSCSTR;
extern volatile CPMUOSCSTR _CPMUOSC @0x000006DA;
#define CPMUOSC                         _CPMUOSC.Byte
#define CPMUOSC_OSCE                    _CPMUOSC.Bits.OSCE

#define CPMUOSC_OSCE_MASK               128U


/*** CPMUPROT - CPMUV1 Protection Register; 0x000006DB ***/
typedef union {
  byte Byte;
  struct {
    byte PROT        :1;                                       /* Clock Configuration Registers Protection Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMUPROTSTR;
extern volatile CPMUPROTSTR _CPMUPROT @0x000006DB;
#define CPMUPROT                        _CPMUPROT.Byte
#define CPMUPROT_PROT                   _CPMUPROT.Bits.PROT

#define CPMUPROT_PROT_MASK              1U


/*** CPMUOSC2 - CPMU Oscillator Register 2; 0x000006DE ***/
typedef union {
  byte Byte;
  struct {
    byte OSCMOD      :1;                                       /* This bit selects the mode of the external oscillator (XOSCLCP) */
    byte OMRE        :1;                                       /* This bit enables the oscillator clock monitor reset */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMUOSC2STR;
extern volatile CPMUOSC2STR _CPMUOSC2 @0x000006DE;
#define CPMUOSC2                        _CPMUOSC2.Byte
#define CPMUOSC2_OSCMOD                 _CPMUOSC2.Bits.OSCMOD
#define CPMUOSC2_OMRE                   _CPMUOSC2.Bits.OMRE

#define CPMUOSC2_OSCMOD_MASK            1U
#define CPMUOSC2_OMRE_MASK              2U


/*** SPICR1 - SPI  Control Register 1; 0x00000780 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* SPI LSB-First Enable */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* SPI Clock Phase Bit */
    byte CPOL        :1;                                       /* SPI Clock Polarity Bit */
    byte MSTR        :1;                                       /* SPI Master/Slave Mode Select Bit */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable Bit */
    byte SPIE        :1;                                       /* SPI Interrupt Enable Bit */
  } Bits;
} SPICR1STR;
extern volatile SPICR1STR _SPICR1 @0x00000780;
#define SPICR1                          _SPICR1.Byte
#define SPICR1_LSBFE                    _SPICR1.Bits.LSBFE
#define SPICR1_SSOE                     _SPICR1.Bits.SSOE
#define SPICR1_CPHA                     _SPICR1.Bits.CPHA
#define SPICR1_CPOL                     _SPICR1.Bits.CPOL
#define SPICR1_MSTR                     _SPICR1.Bits.MSTR
#define SPICR1_SPTIE                    _SPICR1.Bits.SPTIE
#define SPICR1_SPE                      _SPICR1.Bits.SPE
#define SPICR1_SPIE                     _SPICR1.Bits.SPIE

#define SPICR1_LSBFE_MASK               1U
#define SPICR1_SSOE_MASK                2U
#define SPICR1_CPHA_MASK                4U
#define SPICR1_CPOL_MASK                8U
#define SPICR1_MSTR_MASK                16U
#define SPICR1_SPTIE_MASK               32U
#define SPICR1_SPE_MASK                 64U
#define SPICR1_SPIE_MASK                128U


/*** SPICR2 - SPI  Control Register 2; 0x00000781 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* Serial Pin Control Bit 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode Bit */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Output enable in the Bidirectional mode of operation */
    byte MODFEN      :1;                                       /* Mode Fault Enable Bit */
    byte             :1; 
    byte XFRW        :1;                                       /* Transfer Width */
    byte             :1; 
  } Bits;
} SPICR2STR;
extern volatile SPICR2STR _SPICR2 @0x00000781;
#define SPICR2                          _SPICR2.Byte
#define SPICR2_SPC0                     _SPICR2.Bits.SPC0
#define SPICR2_SPISWAI                  _SPICR2.Bits.SPISWAI
#define SPICR2_BIDIROE                  _SPICR2.Bits.BIDIROE
#define SPICR2_MODFEN                   _SPICR2.Bits.MODFEN
#define SPICR2_XFRW                     _SPICR2.Bits.XFRW

#define SPICR2_SPC0_MASK                1U
#define SPICR2_SPISWAI_MASK             2U
#define SPICR2_BIDIROE_MASK             8U
#define SPICR2_MODFEN_MASK              16U
#define SPICR2_XFRW_MASK                64U


/*** SPIBR - SPI  Baud Rate Register; 0x00000782 ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Selection Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Selection Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Selection Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Preselection Bits 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Preselection Bits 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Preselection Bits 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPIBRSTR;
extern volatile SPIBRSTR _SPIBR @0x00000782;
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


/*** SPISR - SPI  Status Register; 0x00000783 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Empty Interrupt Flag */
    byte             :1; 
    byte SPIF        :1;                                       /* SPIF Receive Interrupt Flag */
  } Bits;
} SPISRSTR;
extern volatile SPISRSTR _SPISR @0x00000783;
#define SPISR                           _SPISR.Byte
#define SPISR_MODF                      _SPISR.Bits.MODF
#define SPISR_SPTEF                     _SPISR.Bits.SPTEF
#define SPISR_SPIF                      _SPISR.Bits.SPIF

#define SPISR_MODF_MASK                 16U
#define SPISR_SPTEF_MASK                32U
#define SPISR_SPIF_MASK                 128U


/*** SPIDR - SPI  Data Register; 0x00000784 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPIDRH - SPI  Data Register High; 0x00000784 ***/
    union {
      byte Byte;
      struct {
        byte R8_T8       :1;                                       /* SPI  Data Bit 8 */
        byte R9_T9       :1;                                       /* SPI  Data Bit 9 */
        byte R10_T10     :1;                                       /* SPI  Data Bit 10 */
        byte R11_T11     :1;                                       /* SPI  Data Bit 11 */
        byte R12_T12     :1;                                       /* SPI  Data Bit 12 */
        byte R13_T13     :1;                                       /* SPI  Data Bit 13 */
        byte R14_T14     :1;                                       /* SPI  Data Bit 14 */
        byte R15_T15     :1;                                       /* SPI  Data Bit 15 */
      } Bits;
    } SPIDRHSTR;
    #define SPIDRH                      _SPIDR.Overlap_STR.SPIDRHSTR.Byte
    #define SPIDRH_R8_T8                _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R8_T8
    #define SPIDRH_R9_T9                _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R9_T9
    #define SPIDRH_R10_T10              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R10_T10
    #define SPIDRH_R11_T11              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R11_T11
    #define SPIDRH_R12_T12              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R12_T12
    #define SPIDRH_R13_T13              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R13_T13
    #define SPIDRH_R14_T14              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R14_T14
    #define SPIDRH_R15_T15              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R15_T15
    
    #define SPIDRH_R8_T8_MASK           1U
    #define SPIDRH_R9_T9_MASK           2U
    #define SPIDRH_R10_T10_MASK         4U
    #define SPIDRH_R11_T11_MASK         8U
    #define SPIDRH_R12_T12_MASK         16U
    #define SPIDRH_R13_T13_MASK         32U
    #define SPIDRH_R14_T14_MASK         64U
    #define SPIDRH_R15_T15_MASK         128U
    

    /*** SPIDRL - SPI  Data Register Low; 0x00000785 ***/
    union {
      byte Byte;
      struct {
        byte R0_T0       :1;                                       /* SPI  Data Bit 0 */
        byte R1_T1       :1;                                       /* SPI  Data Bit 1 */
        byte R2_T2       :1;                                       /* SPI  Data Bit 2 */
        byte R3_T3       :1;                                       /* SPI  Data Bit 3 */
        byte R4_T4       :1;                                       /* SPI  Data Bit 4 */
        byte R5_T5       :1;                                       /* SPI  Data Bit 5 */
        byte R6_T6       :1;                                       /* SPI  Data Bit 6 */
        byte R7_T7       :1;                                       /* SPI  Data Bit 7 */
      } Bits;
    } SPIDRLSTR;
    #define SPIDRL                      _SPIDR.Overlap_STR.SPIDRLSTR.Byte
    #define SPIDRL_R0_T0                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R0_T0
    #define SPIDRL_R1_T1                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R1_T1
    #define SPIDRL_R2_T2                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R2_T2
    #define SPIDRL_R3_T3                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R3_T3
    #define SPIDRL_R4_T4                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R4_T4
    #define SPIDRL_R5_T5                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R5_T5
    #define SPIDRL_R6_T6                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R6_T6
    #define SPIDRL_R7_T7                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R7_T7
    
    #define SPIDRL_R0_T0_MASK           1U
    #define SPIDRL_R1_T1_MASK           2U
    #define SPIDRL_R2_T2_MASK           4U
    #define SPIDRL_R3_T3_MASK           8U
    #define SPIDRL_R4_T4_MASK           16U
    #define SPIDRL_R5_T5_MASK           32U
    #define SPIDRL_R6_T6_MASK           64U
    #define SPIDRL_R7_T7_MASK           128U
    
  } Overlap_STR;

  struct {
    word R0_T0       :1;                                       /* SPI  Data Bit 0 */
    word R1_T1       :1;                                       /* SPI  Data Bit 1 */
    word R2_T2       :1;                                       /* SPI  Data Bit 2 */
    word R3_T3       :1;                                       /* SPI  Data Bit 3 */
    word R4_T4       :1;                                       /* SPI  Data Bit 4 */
    word R5_T5       :1;                                       /* SPI  Data Bit 5 */
    word R6_T6       :1;                                       /* SPI  Data Bit 6 */
    word R7_T7       :1;                                       /* SPI  Data Bit 7 */
    word R8_T8       :1;                                       /* SPI  Data Bit 8 */
    word R9_T9       :1;                                       /* SPI  Data Bit 9 */
    word R10_T10     :1;                                       /* SPI  Data Bit 10 */
    word R11_T11     :1;                                       /* SPI  Data Bit 11 */
    word R12_T12     :1;                                       /* SPI  Data Bit 12 */
    word R13_T13     :1;                                       /* SPI  Data Bit 13 */
    word R14_T14     :1;                                       /* SPI  Data Bit 14 */
    word R15_T15     :1;                                       /* SPI  Data Bit 15 */
  } Bits;
} SPIDRSTR;
extern volatile SPIDRSTR _SPIDR @0x00000784;
#define SPIDR                           _SPIDR.Word
#define SPIDR_R0_T0                     _SPIDR.Bits.R0_T0
#define SPIDR_R1_T1                     _SPIDR.Bits.R1_T1
#define SPIDR_R2_T2                     _SPIDR.Bits.R2_T2
#define SPIDR_R3_T3                     _SPIDR.Bits.R3_T3
#define SPIDR_R4_T4                     _SPIDR.Bits.R4_T4
#define SPIDR_R5_T5                     _SPIDR.Bits.R5_T5
#define SPIDR_R6_T6                     _SPIDR.Bits.R6_T6
#define SPIDR_R7_T7                     _SPIDR.Bits.R7_T7
#define SPIDR_R8_T8                     _SPIDR.Bits.R8_T8
#define SPIDR_R9_T9                     _SPIDR.Bits.R9_T9
#define SPIDR_R10_T10                   _SPIDR.Bits.R10_T10
#define SPIDR_R11_T11                   _SPIDR.Bits.R11_T11
#define SPIDR_R12_T12                   _SPIDR.Bits.R12_T12
#define SPIDR_R13_T13                   _SPIDR.Bits.R13_T13
#define SPIDR_R14_T14                   _SPIDR.Bits.R14_T14
#define SPIDR_R15_T15                   _SPIDR.Bits.R15_T15

#define SPIDR_R0_T0_MASK                1U
#define SPIDR_R1_T1_MASK                2U
#define SPIDR_R2_T2_MASK                4U
#define SPIDR_R3_T3_MASK                8U
#define SPIDR_R4_T4_MASK                16U
#define SPIDR_R5_T5_MASK                32U
#define SPIDR_R6_T6_MASK                64U
#define SPIDR_R7_T7_MASK                128U
#define SPIDR_R8_T8_MASK                256U
#define SPIDR_R9_T9_MASK                512U
#define SPIDR_R10_T10_MASK              1024U
#define SPIDR_R11_T11_MASK              2048U
#define SPIDR_R12_T12_MASK              4096U
#define SPIDR_R13_T13_MASK              8192U
#define SPIDR_R14_T14_MASK              16384U
#define SPIDR_R15_T15_MASK              32768U


/*** D2DCTL0 - D2D Control Register 0; 0x000007F0 ***/
typedef union {
  byte Byte;
  struct {
    byte D2DCLKDIV   :2;                                       /* InterfaceClockDivider */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte D2DSWAI     :1;                                       /* D2D Stop In Wait */
    byte D2DCW       :1;                                       /* D2D Connection Width */
    byte D2DEN       :1;                                       /* D2D Enable */
  } Bits;
} D2DCTL0STR;
extern volatile D2DCTL0STR _D2DCTL0 @0x000007F0;
#define D2DCTL0                         _D2DCTL0.Byte
#define D2DCTL0_D2DCLKDIV               _D2DCTL0.Bits.D2DCLKDIV
#define D2DCTL0_D2DSWAI                 _D2DCTL0.Bits.D2DSWAI
#define D2DCTL0_D2DCW                   _D2DCTL0.Bits.D2DCW
#define D2DCTL0_D2DEN                   _D2DCTL0.Bits.D2DEN
/* D2DCTL_ARR: Access 2 D2DCTLx registers in an array */
#define D2DCTL_ARR                      ((volatile byte *) &D2DCTL0)

#define D2DCTL0_D2DCLKDIV_MASK          3U
#define D2DCTL0_D2DCLKDIV_BITNUM        0U
#define D2DCTL0_D2DSWAI_MASK            32U
#define D2DCTL0_D2DCW_MASK              64U
#define D2DCTL0_D2DEN_MASK              128U


/*** D2DCTL1 - D2D Control Register 1; 0x000007F1 ***/
typedef union {
  byte Byte;
  struct {
    byte TIMOUT      :4;                                       /* Time-out Setting */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte D2DIE       :1;                                       /* D2D Interrupt Enable */
  } Bits;
} D2DCTL1STR;
extern volatile D2DCTL1STR _D2DCTL1 @0x000007F1;
#define D2DCTL1                         _D2DCTL1.Byte
#define D2DCTL1_TIMOUT                  _D2DCTL1.Bits.TIMOUT
#define D2DCTL1_D2DIE                   _D2DCTL1.Bits.D2DIE

#define D2DCTL1_TIMOUT_MASK             15U
#define D2DCTL1_TIMOUT_BITNUM           0U
#define D2DCTL1_D2DIE_MASK              128U


/*** D2DSTAT0 - D2D Status Register 0; 0x000007F2 ***/
typedef union {
  byte Byte;
  struct {
    byte PAR0        :1;                                       /* Parity Bit */
    byte PAR1        :1;                                       /* Parity Bit */
    byte PARF        :1;                                       /* Parity Error Flag */
    byte TERRF       :1;                                       /* Transaction Error Flag */
    byte TIMEF       :1;                                       /* TimeOutErrorFlag */
    byte CNCLF       :1;                                       /* CNCLF */
    byte ACKERF      :1;                                       /* Acknowledge Error Flag */
    byte ERRIF       :1;                                       /* D2D error interrupt flag */
  } Bits;
  struct {
    byte grpPAR  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} D2DSTAT0STR;
extern volatile D2DSTAT0STR _D2DSTAT0 @0x000007F2;
#define D2DSTAT0                        _D2DSTAT0.Byte
#define D2DSTAT0_PAR0                   _D2DSTAT0.Bits.PAR0
#define D2DSTAT0_PAR1                   _D2DSTAT0.Bits.PAR1
#define D2DSTAT0_PARF                   _D2DSTAT0.Bits.PARF
#define D2DSTAT0_TERRF                  _D2DSTAT0.Bits.TERRF
#define D2DSTAT0_TIMEF                  _D2DSTAT0.Bits.TIMEF
#define D2DSTAT0_CNCLF                  _D2DSTAT0.Bits.CNCLF
#define D2DSTAT0_ACKERF                 _D2DSTAT0.Bits.ACKERF
#define D2DSTAT0_ERRIF                  _D2DSTAT0.Bits.ERRIF
/* D2DSTAT_ARR: Access 2 D2DSTATx registers in an array */
#define D2DSTAT_ARR                     ((volatile byte *) &D2DSTAT0)
#define D2DSTAT0_PAR                    _D2DSTAT0.MergedBits.grpPAR

#define D2DSTAT0_PAR0_MASK              1U
#define D2DSTAT0_PAR1_MASK              2U
#define D2DSTAT0_PARF_MASK              4U
#define D2DSTAT0_TERRF_MASK             8U
#define D2DSTAT0_TIMEF_MASK             16U
#define D2DSTAT0_CNCLF_MASK             32U
#define D2DSTAT0_ACKERF_MASK            64U
#define D2DSTAT0_ERRIF_MASK             128U
#define D2DSTAT0_PAR_MASK               3U
#define D2DSTAT0_PAR_BITNUM             0U


/*** D2DSTAT1 - D2D Status Register 1; 0x000007F3 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte D2DBSY      :1;                                       /* D2D Initiator Busy */
    byte D2DIF       :1;                                       /* D2D InterruptFlag */
  } Bits;
} D2DSTAT1STR;
extern volatile D2DSTAT1STR _D2DSTAT1 @0x000007F3;
#define D2DSTAT1                        _D2DSTAT1.Byte
#define D2DSTAT1_D2DBSY                 _D2DSTAT1.Bits.D2DBSY
#define D2DSTAT1_D2DIF                  _D2DSTAT1.Bits.D2DIF

#define D2DSTAT1_D2DBSY_MASK            64U
#define D2DSTAT1_D2DIF_MASK             128U


/*** D2DADR - D2D Address Buffer Register; 0x000007F4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** D2DADRHI - D2D Address Buffer Register High; 0x000007F4 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte NBLK        :1;                                       /* Transaction Mode */
        byte             :1; 
        byte SZ8         :1;                                       /* Transaction Size */
        byte RWB         :1;                                       /* Transaction Read-Write Direction */
      } Bits;
    } D2DADRHISTR;
    #define D2DADRHI                    _D2DADR.Overlap_STR.D2DADRHISTR.Byte
    #define D2DADRHI_NBLK               _D2DADR.Overlap_STR.D2DADRHISTR.Bits.NBLK
    #define D2DADRHI_SZ8                _D2DADR.Overlap_STR.D2DADRHISTR.Bits.SZ8
    #define D2DADRHI_RWB                _D2DADR.Overlap_STR.D2DADRHISTR.Bits.RWB
    
    #define D2DADRHI_NBLK_MASK          16U
    #define D2DADRHI_SZ8_MASK           64U
    #define D2DADRHI_RWB_MASK           128U
    

    /*** D2DADRLO - D2D Address Buffer Register Low; 0x000007F5 ***/
    union {
      byte Byte;
      struct {
        byte ADR         :8;                                       /* Transaction Address */
      } Bits;
    } D2DADRLOSTR;
    #define D2DADRLO                    _D2DADR.Overlap_STR.D2DADRLOSTR.Byte
    #define D2DADRLO_ADR                _D2DADR.Overlap_STR.D2DADRLOSTR.Bits.ADR
    
    #define D2DADRLO_ADR_MASK           255U
    #define D2DADRLO_ADR_BITNUM         0U
    
  } Overlap_STR;

  struct {
    word ADR         :8;                                       /* Transaction Address */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word NBLK        :1;                                       /* Transaction Mode */
    word             :1; 
    word SZ8         :1;                                       /* Transaction Size */
    word RWB         :1;                                       /* Transaction Read-Write Direction */
  } Bits;
} D2DADRSTR;
extern volatile D2DADRSTR _D2DADR @0x000007F4;
#define D2DADR                          _D2DADR.Word
#define D2DADR_ADR                      _D2DADR.Bits.ADR
#define D2DADR_NBLK                     _D2DADR.Bits.NBLK
#define D2DADR_SZ8                      _D2DADR.Bits.SZ8
#define D2DADR_RWB                      _D2DADR.Bits.RWB

#define D2DADR_ADR_MASK                 255U
#define D2DADR_ADR_BITNUM               0U
#define D2DADR_NBLK_MASK                4096U
#define D2DADR_SZ8_MASK                 16384U
#define D2DADR_RWB_MASK                 32768U


/*** D2DDATA - D2D Data Buffer Register; 0x000007F6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** D2DDATAHI - D2D Data Buffer Register High; 0x000007F6 ***/
    union {
      byte Byte;
      struct {
        byte DATA8       :1;                                       /* Transaction Data, bit 8 */
        byte DATA9       :1;                                       /* Transaction Data, bit 9 */
        byte DATA10      :1;                                       /* Transaction Data, bit 10 */
        byte DATA11      :1;                                       /* Transaction Data, bit 11 */
        byte DATA12      :1;                                       /* Transaction Data, bit 12 */
        byte DATA13      :1;                                       /* Transaction Data, bit 13 */
        byte DATA14      :1;                                       /* Transaction Data, bit 14 */
        byte DATA15      :1;                                       /* Transaction Data, bit 15 */
      } Bits;
    } D2DDATAHISTR;
    #define D2DDATAHI                   _D2DDATA.Overlap_STR.D2DDATAHISTR.Byte
    #define D2DDATAHI_DATA8             _D2DDATA.Overlap_STR.D2DDATAHISTR.Bits.DATA8
    #define D2DDATAHI_DATA9             _D2DDATA.Overlap_STR.D2DDATAHISTR.Bits.DATA9
    #define D2DDATAHI_DATA10            _D2DDATA.Overlap_STR.D2DDATAHISTR.Bits.DATA10
    #define D2DDATAHI_DATA11            _D2DDATA.Overlap_STR.D2DDATAHISTR.Bits.DATA11
    #define D2DDATAHI_DATA12            _D2DDATA.Overlap_STR.D2DDATAHISTR.Bits.DATA12
    #define D2DDATAHI_DATA13            _D2DDATA.Overlap_STR.D2DDATAHISTR.Bits.DATA13
    #define D2DDATAHI_DATA14            _D2DDATA.Overlap_STR.D2DDATAHISTR.Bits.DATA14
    #define D2DDATAHI_DATA15            _D2DDATA.Overlap_STR.D2DDATAHISTR.Bits.DATA15
    
    #define D2DDATAHI_DATA8_MASK        1U
    #define D2DDATAHI_DATA9_MASK        2U
    #define D2DDATAHI_DATA10_MASK       4U
    #define D2DDATAHI_DATA11_MASK       8U
    #define D2DDATAHI_DATA12_MASK       16U
    #define D2DDATAHI_DATA13_MASK       32U
    #define D2DDATAHI_DATA14_MASK       64U
    #define D2DDATAHI_DATA15_MASK       128U
    

    /*** D2DDATALO - D2D Data Buffer Register Low; 0x000007F7 ***/
    union {
      byte Byte;
      struct {
        byte DATA        :8;                                       /* Transaction Data */
      } Bits;
    } D2DDATALOSTR;
    #define D2DDATALO                   _D2DDATA.Overlap_STR.D2DDATALOSTR.Byte
    #define D2DDATALO_DATA              _D2DDATA.Overlap_STR.D2DDATALOSTR.Bits.DATA
    
    #define D2DDATALO_DATA_MASK         255U
    #define D2DDATALO_DATA_BITNUM       0U
    
  } Overlap_STR;

  struct {
    word DATA        :16;                                      /* Transaction Data */
  } Bits;
} D2DDATASTR;
extern volatile D2DDATASTR _D2DDATA @0x000007F6;
#define D2DDATA                         _D2DDATA.Word
#define D2DDATA_DATA                    _D2DDATA.Bits.DATA

#define D2DDATA_DATA_MASK               65535U
#define D2DDATA_DATA_BITNUM             0U


/*** CANCTL0 - MSCAN Control 0 Register; 0x00000800 ***/
typedef union {
  byte Byte;
  struct {
    byte INITRQ      :1;                                       /* Initialization Mode Request */
    byte SLPRQ       :1;                                       /* Sleep Mode Request */
    byte WUPE        :1;                                       /* Wake-Up Enable */
    byte TIME        :1;                                       /* Timer Enable */
    byte SYNCH       :1;                                       /* Synchronized Status */
    byte CSWAI       :1;                                       /* CAN Stops in Wait Mode */
    byte RXACT       :1;                                       /* Receiver Active Status */
    byte RXFRM       :1;                                       /* Received Frame Flag */
  } Bits;
} CANCTL0STR;
extern volatile CANCTL0STR _CANCTL0 @0x00000800;
#define CANCTL0                         _CANCTL0.Byte
#define CANCTL0_INITRQ                  _CANCTL0.Bits.INITRQ
#define CANCTL0_SLPRQ                   _CANCTL0.Bits.SLPRQ
#define CANCTL0_WUPE                    _CANCTL0.Bits.WUPE
#define CANCTL0_TIME                    _CANCTL0.Bits.TIME
#define CANCTL0_SYNCH                   _CANCTL0.Bits.SYNCH
#define CANCTL0_CSWAI                   _CANCTL0.Bits.CSWAI
#define CANCTL0_RXACT                   _CANCTL0.Bits.RXACT
#define CANCTL0_RXFRM                   _CANCTL0.Bits.RXFRM
/* CANCTL_ARR: Access 2 CANCTLx registers in an array */
#define CANCTL_ARR                      ((volatile byte *) &CANCTL0)

#define CANCTL0_INITRQ_MASK             1U
#define CANCTL0_SLPRQ_MASK              2U
#define CANCTL0_WUPE_MASK               4U
#define CANCTL0_TIME_MASK               8U
#define CANCTL0_SYNCH_MASK              16U
#define CANCTL0_CSWAI_MASK              32U
#define CANCTL0_RXACT_MASK              64U
#define CANCTL0_RXFRM_MASK              128U


/*** CANCTL1 - MSCAN Control 1 Register; 0x00000801 ***/
typedef union {
  byte Byte;
  struct {
    byte INITAK      :1;                                       /* Initialization Mode Acknowledge */
    byte SLPAK       :1;                                       /* Sleep Mode Acknowledge */
    byte WUPM        :1;                                       /* Wake-Up Mode */
    byte BORM        :1;                                       /* Bus-Off Recovery Mode */
    byte LISTEN      :1;                                       /* Listen Only Mode */
    byte LOOPB       :1;                                       /* Loop Back Self Test Mode */
    byte CLKSRC      :1;                                       /* MSCAN Clock Source */
    byte CANE        :1;                                       /* MSCAN Enable */
  } Bits;
} CANCTL1STR;
extern volatile CANCTL1STR _CANCTL1 @0x00000801;
#define CANCTL1                         _CANCTL1.Byte
#define CANCTL1_INITAK                  _CANCTL1.Bits.INITAK
#define CANCTL1_SLPAK                   _CANCTL1.Bits.SLPAK
#define CANCTL1_WUPM                    _CANCTL1.Bits.WUPM
#define CANCTL1_BORM                    _CANCTL1.Bits.BORM
#define CANCTL1_LISTEN                  _CANCTL1.Bits.LISTEN
#define CANCTL1_LOOPB                   _CANCTL1.Bits.LOOPB
#define CANCTL1_CLKSRC                  _CANCTL1.Bits.CLKSRC
#define CANCTL1_CANE                    _CANCTL1.Bits.CANE

#define CANCTL1_INITAK_MASK             1U
#define CANCTL1_SLPAK_MASK              2U
#define CANCTL1_WUPM_MASK               4U
#define CANCTL1_BORM_MASK               8U
#define CANCTL1_LISTEN_MASK             16U
#define CANCTL1_LOOPB_MASK              32U
#define CANCTL1_CLKSRC_MASK             64U
#define CANCTL1_CANE_MASK               128U


/*** CANBTR0 - MSCAN Bus Timing Register 0; 0x00000802 ***/
typedef union {
  byte Byte;
  struct {
    byte BRP0        :1;                                       /* Baud Rate Prescaler 0 */
    byte BRP1        :1;                                       /* Baud Rate Prescaler 1 */
    byte BRP2        :1;                                       /* Baud Rate Prescaler 2 */
    byte BRP3        :1;                                       /* Baud Rate Prescaler 3 */
    byte BRP4        :1;                                       /* Baud Rate Prescaler 4 */
    byte BRP5        :1;                                       /* Baud Rate Prescaler 5 */
    byte SJW0        :1;                                       /* Synchronization Jump Width 0 */
    byte SJW1        :1;                                       /* Synchronization Jump Width 1 */
  } Bits;
  struct {
    byte grpBRP  :6;
    byte grpSJW  :2;
  } MergedBits;
} CANBTR0STR;
extern volatile CANBTR0STR _CANBTR0 @0x00000802;
#define CANBTR0                         _CANBTR0.Byte
#define CANBTR0_BRP0                    _CANBTR0.Bits.BRP0
#define CANBTR0_BRP1                    _CANBTR0.Bits.BRP1
#define CANBTR0_BRP2                    _CANBTR0.Bits.BRP2
#define CANBTR0_BRP3                    _CANBTR0.Bits.BRP3
#define CANBTR0_BRP4                    _CANBTR0.Bits.BRP4
#define CANBTR0_BRP5                    _CANBTR0.Bits.BRP5
#define CANBTR0_SJW0                    _CANBTR0.Bits.SJW0
#define CANBTR0_SJW1                    _CANBTR0.Bits.SJW1
/* CANBTR_ARR: Access 2 CANBTRx registers in an array */
#define CANBTR_ARR                      ((volatile byte *) &CANBTR0)
#define CANBTR0_BRP                     _CANBTR0.MergedBits.grpBRP
#define CANBTR0_SJW                     _CANBTR0.MergedBits.grpSJW

#define CANBTR0_BRP0_MASK               1U
#define CANBTR0_BRP1_MASK               2U
#define CANBTR0_BRP2_MASK               4U
#define CANBTR0_BRP3_MASK               8U
#define CANBTR0_BRP4_MASK               16U
#define CANBTR0_BRP5_MASK               32U
#define CANBTR0_SJW0_MASK               64U
#define CANBTR0_SJW1_MASK               128U
#define CANBTR0_BRP_MASK                63U
#define CANBTR0_BRP_BITNUM              0U
#define CANBTR0_SJW_MASK                192U
#define CANBTR0_SJW_BITNUM              6U


/*** CANBTR1 - MSCAN Bus Timing Register 1; 0x00000803 ***/
typedef union {
  byte Byte;
  struct {
    byte TSEG10      :1;                                       /* Time Segment 10 */
    byte TSEG11      :1;                                       /* Time Segment 11 */
    byte TSEG12      :1;                                       /* Time Segment 12 */
    byte TSEG13      :1;                                       /* Time Segment 13 */
    byte TSEG20      :1;                                       /* Time Segment 20 */
    byte TSEG21      :1;                                       /* Time Segment 21 */
    byte TSEG22      :1;                                       /* Time Segment 22 */
    byte SAMP        :1;                                       /* Sampling */
  } Bits;
  struct {
    byte grpTSEG_10 :4;
    byte grpTSEG_20 :3;
    byte         :1;
  } MergedBits;
} CANBTR1STR;
extern volatile CANBTR1STR _CANBTR1 @0x00000803;
#define CANBTR1                         _CANBTR1.Byte
#define CANBTR1_TSEG10                  _CANBTR1.Bits.TSEG10
#define CANBTR1_TSEG11                  _CANBTR1.Bits.TSEG11
#define CANBTR1_TSEG12                  _CANBTR1.Bits.TSEG12
#define CANBTR1_TSEG13                  _CANBTR1.Bits.TSEG13
#define CANBTR1_TSEG20                  _CANBTR1.Bits.TSEG20
#define CANBTR1_TSEG21                  _CANBTR1.Bits.TSEG21
#define CANBTR1_TSEG22                  _CANBTR1.Bits.TSEG22
#define CANBTR1_SAMP                    _CANBTR1.Bits.SAMP
#define CANBTR1_TSEG_10                 _CANBTR1.MergedBits.grpTSEG_10
#define CANBTR1_TSEG_20                 _CANBTR1.MergedBits.grpTSEG_20
#define CANBTR1_TSEG                    CANBTR1_TSEG_10

#define CANBTR1_TSEG10_MASK             1U
#define CANBTR1_TSEG11_MASK             2U
#define CANBTR1_TSEG12_MASK             4U
#define CANBTR1_TSEG13_MASK             8U
#define CANBTR1_TSEG20_MASK             16U
#define CANBTR1_TSEG21_MASK             32U
#define CANBTR1_TSEG22_MASK             64U
#define CANBTR1_SAMP_MASK               128U
#define CANBTR1_TSEG_10_MASK            15U
#define CANBTR1_TSEG_10_BITNUM          0U
#define CANBTR1_TSEG_20_MASK            112U
#define CANBTR1_TSEG_20_BITNUM          4U


/*** CANRFLG - MSCAN Receiver Flag Register; 0x00000804 ***/
typedef union {
  byte Byte;
  struct {
    byte RXF         :1;                                       /* Receive Buffer Full */
    byte OVRIF       :1;                                       /* Overrun Interrupt Flag */
    byte TSTAT0      :1;                                       /* Transmitter Status Bit 0 */
    byte TSTAT1      :1;                                       /* Transmitter Status Bit 1 */
    byte RSTAT0      :1;                                       /* Receiver Status Bit 0 */
    byte RSTAT1      :1;                                       /* Receiver Status Bit 1 */
    byte CSCIF       :1;                                       /* CAN Status Change Interrupt Flag */
    byte WUPIF       :1;                                       /* Wake-up Interrupt Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTAT :2;
    byte grpRSTAT :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRFLGSTR;
extern volatile CANRFLGSTR _CANRFLG @0x00000804;
#define CANRFLG                         _CANRFLG.Byte
#define CANRFLG_RXF                     _CANRFLG.Bits.RXF
#define CANRFLG_OVRIF                   _CANRFLG.Bits.OVRIF
#define CANRFLG_TSTAT0                  _CANRFLG.Bits.TSTAT0
#define CANRFLG_TSTAT1                  _CANRFLG.Bits.TSTAT1
#define CANRFLG_RSTAT0                  _CANRFLG.Bits.RSTAT0
#define CANRFLG_RSTAT1                  _CANRFLG.Bits.RSTAT1
#define CANRFLG_CSCIF                   _CANRFLG.Bits.CSCIF
#define CANRFLG_WUPIF                   _CANRFLG.Bits.WUPIF
#define CANRFLG_TSTAT                   _CANRFLG.MergedBits.grpTSTAT
#define CANRFLG_RSTAT                   _CANRFLG.MergedBits.grpRSTAT

#define CANRFLG_RXF_MASK                1U
#define CANRFLG_OVRIF_MASK              2U
#define CANRFLG_TSTAT0_MASK             4U
#define CANRFLG_TSTAT1_MASK             8U
#define CANRFLG_RSTAT0_MASK             16U
#define CANRFLG_RSTAT1_MASK             32U
#define CANRFLG_CSCIF_MASK              64U
#define CANRFLG_WUPIF_MASK              128U
#define CANRFLG_TSTAT_MASK              12U
#define CANRFLG_TSTAT_BITNUM            2U
#define CANRFLG_RSTAT_MASK              48U
#define CANRFLG_RSTAT_BITNUM            4U


/*** CANRIER - MSCAN Receiver Interrupt Enable Register; 0x00000805 ***/
typedef union {
  byte Byte;
  struct {
    byte RXFIE       :1;                                       /* Receiver Full Interrupt Enable */
    byte OVRIE       :1;                                       /* Overrun Interrupt Enable */
    byte TSTATE0     :1;                                       /* Transmitter Status Change Enable 0 */
    byte TSTATE1     :1;                                       /* Transmitter Status Change Enable 1 */
    byte RSTATE0     :1;                                       /* Receiver Status Change Enable 0 */
    byte RSTATE1     :1;                                       /* Receiver Status Change Enable 1 */
    byte CSCIE       :1;                                       /* CAN Status Change Interrupt Enable */
    byte WUPIE       :1;                                       /* Wake-up Interrupt Enable */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTATE :2;
    byte grpRSTATE :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRIERSTR;
extern volatile CANRIERSTR _CANRIER @0x00000805;
#define CANRIER                         _CANRIER.Byte
#define CANRIER_RXFIE                   _CANRIER.Bits.RXFIE
#define CANRIER_OVRIE                   _CANRIER.Bits.OVRIE
#define CANRIER_TSTATE0                 _CANRIER.Bits.TSTATE0
#define CANRIER_TSTATE1                 _CANRIER.Bits.TSTATE1
#define CANRIER_RSTATE0                 _CANRIER.Bits.RSTATE0
#define CANRIER_RSTATE1                 _CANRIER.Bits.RSTATE1
#define CANRIER_CSCIE                   _CANRIER.Bits.CSCIE
#define CANRIER_WUPIE                   _CANRIER.Bits.WUPIE
#define CANRIER_TSTATE                  _CANRIER.MergedBits.grpTSTATE
#define CANRIER_RSTATE                  _CANRIER.MergedBits.grpRSTATE

#define CANRIER_RXFIE_MASK              1U
#define CANRIER_OVRIE_MASK              2U
#define CANRIER_TSTATE0_MASK            4U
#define CANRIER_TSTATE1_MASK            8U
#define CANRIER_RSTATE0_MASK            16U
#define CANRIER_RSTATE1_MASK            32U
#define CANRIER_CSCIE_MASK              64U
#define CANRIER_WUPIE_MASK              128U
#define CANRIER_TSTATE_MASK             12U
#define CANRIER_TSTATE_BITNUM           2U
#define CANRIER_RSTATE_MASK             48U
#define CANRIER_RSTATE_BITNUM           4U


/*** CANTFLG - MSCAN Transmitter Flag Register; 0x00000806 ***/
typedef union {
  byte Byte;
  struct {
    byte TXE0        :1;                                       /* Transmitter Buffer Empty 0 */
    byte TXE1        :1;                                       /* Transmitter Buffer Empty 1 */
    byte TXE2        :1;                                       /* Transmitter Buffer Empty 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXE  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTFLGSTR;
extern volatile CANTFLGSTR _CANTFLG @0x00000806;
#define CANTFLG                         _CANTFLG.Byte
#define CANTFLG_TXE0                    _CANTFLG.Bits.TXE0
#define CANTFLG_TXE1                    _CANTFLG.Bits.TXE1
#define CANTFLG_TXE2                    _CANTFLG.Bits.TXE2
#define CANTFLG_TXE                     _CANTFLG.MergedBits.grpTXE

#define CANTFLG_TXE0_MASK               1U
#define CANTFLG_TXE1_MASK               2U
#define CANTFLG_TXE2_MASK               4U
#define CANTFLG_TXE_MASK                7U
#define CANTFLG_TXE_BITNUM              0U


/*** CANTIER - MSCAN Transmitter Interrupt Enable Register; 0x00000807 ***/
typedef union {
  byte Byte;
  struct {
    byte TXEIE0      :1;                                       /* Transmitter Empty Interrupt Enable 0 */
    byte TXEIE1      :1;                                       /* Transmitter Empty Interrupt Enable 1 */
    byte TXEIE2      :1;                                       /* Transmitter Empty Interrupt Enable 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXEIE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTIERSTR;
extern volatile CANTIERSTR _CANTIER @0x00000807;
#define CANTIER                         _CANTIER.Byte
#define CANTIER_TXEIE0                  _CANTIER.Bits.TXEIE0
#define CANTIER_TXEIE1                  _CANTIER.Bits.TXEIE1
#define CANTIER_TXEIE2                  _CANTIER.Bits.TXEIE2
#define CANTIER_TXEIE                   _CANTIER.MergedBits.grpTXEIE

#define CANTIER_TXEIE0_MASK             1U
#define CANTIER_TXEIE1_MASK             2U
#define CANTIER_TXEIE2_MASK             4U
#define CANTIER_TXEIE_MASK              7U
#define CANTIER_TXEIE_BITNUM            0U


/*** CANTARQ - MSCAN Transmitter Message Abort Request; 0x00000808 ***/
typedef union {
  byte Byte;
  struct {
    byte ABTRQ0      :1;                                       /* Abort Request 0 */
    byte ABTRQ1      :1;                                       /* Abort Request 1 */
    byte ABTRQ2      :1;                                       /* Abort Request 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTRQ :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTARQSTR;
extern volatile CANTARQSTR _CANTARQ @0x00000808;
#define CANTARQ                         _CANTARQ.Byte
#define CANTARQ_ABTRQ0                  _CANTARQ.Bits.ABTRQ0
#define CANTARQ_ABTRQ1                  _CANTARQ.Bits.ABTRQ1
#define CANTARQ_ABTRQ2                  _CANTARQ.Bits.ABTRQ2
#define CANTARQ_ABTRQ                   _CANTARQ.MergedBits.grpABTRQ

#define CANTARQ_ABTRQ0_MASK             1U
#define CANTARQ_ABTRQ1_MASK             2U
#define CANTARQ_ABTRQ2_MASK             4U
#define CANTARQ_ABTRQ_MASK              7U
#define CANTARQ_ABTRQ_BITNUM            0U


/*** CANTAAK - MSCAN Transmitter Message Abort Acknowledge; 0x00000809 ***/
typedef union {
  byte Byte;
  struct {
    byte ABTAK0      :1;                                       /* Abort Acknowledge 0 */
    byte ABTAK1      :1;                                       /* Abort Acknowledge 1 */
    byte ABTAK2      :1;                                       /* Abort Acknowledge 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTAK :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTAAKSTR;
extern volatile CANTAAKSTR _CANTAAK @0x00000809;
#define CANTAAK                         _CANTAAK.Byte
#define CANTAAK_ABTAK0                  _CANTAAK.Bits.ABTAK0
#define CANTAAK_ABTAK1                  _CANTAAK.Bits.ABTAK1
#define CANTAAK_ABTAK2                  _CANTAAK.Bits.ABTAK2
#define CANTAAK_ABTAK                   _CANTAAK.MergedBits.grpABTAK

#define CANTAAK_ABTAK0_MASK             1U
#define CANTAAK_ABTAK1_MASK             2U
#define CANTAAK_ABTAK2_MASK             4U
#define CANTAAK_ABTAK_MASK              7U
#define CANTAAK_ABTAK_BITNUM            0U


/*** CANTBSEL - MSCAN Transmit Buffer Selection; 0x0000080A ***/
typedef union {
  byte Byte;
  struct {
    byte TX0         :1;                                       /* Transmit Buffer Select 0 */
    byte TX1         :1;                                       /* Transmit Buffer Select 1 */
    byte TX2         :1;                                       /* Transmit Buffer Select 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTX   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTBSELSTR;
extern volatile CANTBSELSTR _CANTBSEL @0x0000080A;
#define CANTBSEL                        _CANTBSEL.Byte
#define CANTBSEL_TX0                    _CANTBSEL.Bits.TX0
#define CANTBSEL_TX1                    _CANTBSEL.Bits.TX1
#define CANTBSEL_TX2                    _CANTBSEL.Bits.TX2
#define CANTBSEL_TX                     _CANTBSEL.MergedBits.grpTX

#define CANTBSEL_TX0_MASK               1U
#define CANTBSEL_TX1_MASK               2U
#define CANTBSEL_TX2_MASK               4U
#define CANTBSEL_TX_MASK                7U
#define CANTBSEL_TX_BITNUM              0U


/*** CANIDAC - MSCAN Identifier Acceptance Control Register; 0x0000080B ***/
typedef union {
  byte Byte;
  struct {
    byte IDHIT0      :1;                                       /* Identifier Acceptance Hit Indicator 0 */
    byte IDHIT1      :1;                                       /* Identifier Acceptance Hit Indicator 1 */
    byte IDHIT2      :1;                                       /* Identifier Acceptance Hit Indicator 2 */
    byte             :1; 
    byte IDAM0       :1;                                       /* Identifier Acceptance Mode 0 */
    byte IDAM1       :1;                                       /* Identifier Acceptance Mode 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIDHIT :3;
    byte         :1;
    byte grpIDAM :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANIDACSTR;
extern volatile CANIDACSTR _CANIDAC @0x0000080B;
#define CANIDAC                         _CANIDAC.Byte
#define CANIDAC_IDHIT0                  _CANIDAC.Bits.IDHIT0
#define CANIDAC_IDHIT1                  _CANIDAC.Bits.IDHIT1
#define CANIDAC_IDHIT2                  _CANIDAC.Bits.IDHIT2
#define CANIDAC_IDAM0                   _CANIDAC.Bits.IDAM0
#define CANIDAC_IDAM1                   _CANIDAC.Bits.IDAM1
#define CANIDAC_IDHIT                   _CANIDAC.MergedBits.grpIDHIT
#define CANIDAC_IDAM                    _CANIDAC.MergedBits.grpIDAM

#define CANIDAC_IDHIT0_MASK             1U
#define CANIDAC_IDHIT1_MASK             2U
#define CANIDAC_IDHIT2_MASK             4U
#define CANIDAC_IDAM0_MASK              16U
#define CANIDAC_IDAM1_MASK              32U
#define CANIDAC_IDHIT_MASK              7U
#define CANIDAC_IDHIT_BITNUM            0U
#define CANIDAC_IDAM_MASK               48U
#define CANIDAC_IDAM_BITNUM             4U


/*** CANMISC - MSCAN Miscellaneous Register; 0x0000080D ***/
typedef union {
  byte Byte;
  struct {
    byte BOHOLD      :1;                                       /* Bus-off State Hold Until User Request */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CANMISCSTR;
extern volatile CANMISCSTR _CANMISC @0x0000080D;
#define CANMISC                         _CANMISC.Byte
#define CANMISC_BOHOLD                  _CANMISC.Bits.BOHOLD

#define CANMISC_BOHOLD_MASK             1U


/*** CANRXERR - MSCAN Receive Error Counter Register; 0x0000080E ***/
typedef union {
  byte Byte;
  struct {
    byte RXERR0      :1;                                       /* Bit 0 */
    byte RXERR1      :1;                                       /* Bit 1 */
    byte RXERR2      :1;                                       /* Bit 2 */
    byte RXERR3      :1;                                       /* Bit 3 */
    byte RXERR4      :1;                                       /* Bit 4 */
    byte RXERR5      :1;                                       /* Bit 5 */
    byte RXERR6      :1;                                       /* Bit 6 */
    byte RXERR7      :1;                                       /* Bit 7 */
  } Bits;
} CANRXERRSTR;
extern volatile CANRXERRSTR _CANRXERR @0x0000080E;
#define CANRXERR                        _CANRXERR.Byte
#define CANRXERR_RXERR0                 _CANRXERR.Bits.RXERR0
#define CANRXERR_RXERR1                 _CANRXERR.Bits.RXERR1
#define CANRXERR_RXERR2                 _CANRXERR.Bits.RXERR2
#define CANRXERR_RXERR3                 _CANRXERR.Bits.RXERR3
#define CANRXERR_RXERR4                 _CANRXERR.Bits.RXERR4
#define CANRXERR_RXERR5                 _CANRXERR.Bits.RXERR5
#define CANRXERR_RXERR6                 _CANRXERR.Bits.RXERR6
#define CANRXERR_RXERR7                 _CANRXERR.Bits.RXERR7

#define CANRXERR_RXERR0_MASK            1U
#define CANRXERR_RXERR1_MASK            2U
#define CANRXERR_RXERR2_MASK            4U
#define CANRXERR_RXERR3_MASK            8U
#define CANRXERR_RXERR4_MASK            16U
#define CANRXERR_RXERR5_MASK            32U
#define CANRXERR_RXERR6_MASK            64U
#define CANRXERR_RXERR7_MASK            128U


/*** CANTXERR - MSCAN Transmit Error Counter Register; 0x0000080F ***/
typedef union {
  byte Byte;
  struct {
    byte TXERR0      :1;                                       /* Bit 0 */
    byte TXERR1      :1;                                       /* Bit 1 */
    byte TXERR2      :1;                                       /* Bit 2 */
    byte TXERR3      :1;                                       /* Bit 3 */
    byte TXERR4      :1;                                       /* Bit 4 */
    byte TXERR5      :1;                                       /* Bit 5 */
    byte TXERR6      :1;                                       /* Bit 6 */
    byte TXERR7      :1;                                       /* Bit 7 */
  } Bits;
} CANTXERRSTR;
extern volatile CANTXERRSTR _CANTXERR @0x0000080F;
#define CANTXERR                        _CANTXERR.Byte
#define CANTXERR_TXERR0                 _CANTXERR.Bits.TXERR0
#define CANTXERR_TXERR1                 _CANTXERR.Bits.TXERR1
#define CANTXERR_TXERR2                 _CANTXERR.Bits.TXERR2
#define CANTXERR_TXERR3                 _CANTXERR.Bits.TXERR3
#define CANTXERR_TXERR4                 _CANTXERR.Bits.TXERR4
#define CANTXERR_TXERR5                 _CANTXERR.Bits.TXERR5
#define CANTXERR_TXERR6                 _CANTXERR.Bits.TXERR6
#define CANTXERR_TXERR7                 _CANTXERR.Bits.TXERR7

#define CANTXERR_TXERR0_MASK            1U
#define CANTXERR_TXERR1_MASK            2U
#define CANTXERR_TXERR2_MASK            4U
#define CANTXERR_TXERR3_MASK            8U
#define CANTXERR_TXERR4_MASK            16U
#define CANTXERR_TXERR5_MASK            32U
#define CANTXERR_TXERR6_MASK            64U
#define CANTXERR_TXERR7_MASK            128U


/*** CANIDAR0 - MSCAN Identifier Acceptance Register 0; 0x00000810 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR0STR;
extern volatile CANIDAR0STR _CANIDAR0 @0x00000810;
#define CANIDAR0                        _CANIDAR0.Byte
#define CANIDAR0_AC0                    _CANIDAR0.Bits.AC0
#define CANIDAR0_AC1                    _CANIDAR0.Bits.AC1
#define CANIDAR0_AC2                    _CANIDAR0.Bits.AC2
#define CANIDAR0_AC3                    _CANIDAR0.Bits.AC3
#define CANIDAR0_AC4                    _CANIDAR0.Bits.AC4
#define CANIDAR0_AC5                    _CANIDAR0.Bits.AC5
#define CANIDAR0_AC6                    _CANIDAR0.Bits.AC6
#define CANIDAR0_AC7                    _CANIDAR0.Bits.AC7
/* CANIDAR_ARR: Access 4 CANIDARx registers in an array */
#define CANIDAR_ARR                     ((volatile byte *) &CANIDAR0)

#define CANIDAR0_AC0_MASK               1U
#define CANIDAR0_AC1_MASK               2U
#define CANIDAR0_AC2_MASK               4U
#define CANIDAR0_AC3_MASK               8U
#define CANIDAR0_AC4_MASK               16U
#define CANIDAR0_AC5_MASK               32U
#define CANIDAR0_AC6_MASK               64U
#define CANIDAR0_AC7_MASK               128U


/*** CANIDAR1 - MSCAN Identifier Acceptance Register 1; 0x00000811 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR1STR;
extern volatile CANIDAR1STR _CANIDAR1 @0x00000811;
#define CANIDAR1                        _CANIDAR1.Byte
#define CANIDAR1_AC0                    _CANIDAR1.Bits.AC0
#define CANIDAR1_AC1                    _CANIDAR1.Bits.AC1
#define CANIDAR1_AC2                    _CANIDAR1.Bits.AC2
#define CANIDAR1_AC3                    _CANIDAR1.Bits.AC3
#define CANIDAR1_AC4                    _CANIDAR1.Bits.AC4
#define CANIDAR1_AC5                    _CANIDAR1.Bits.AC5
#define CANIDAR1_AC6                    _CANIDAR1.Bits.AC6
#define CANIDAR1_AC7                    _CANIDAR1.Bits.AC7

#define CANIDAR1_AC0_MASK               1U
#define CANIDAR1_AC1_MASK               2U
#define CANIDAR1_AC2_MASK               4U
#define CANIDAR1_AC3_MASK               8U
#define CANIDAR1_AC4_MASK               16U
#define CANIDAR1_AC5_MASK               32U
#define CANIDAR1_AC6_MASK               64U
#define CANIDAR1_AC7_MASK               128U


/*** CANIDAR2 - MSCAN Identifier Acceptance Register 2; 0x00000812 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR2STR;
extern volatile CANIDAR2STR _CANIDAR2 @0x00000812;
#define CANIDAR2                        _CANIDAR2.Byte
#define CANIDAR2_AC0                    _CANIDAR2.Bits.AC0
#define CANIDAR2_AC1                    _CANIDAR2.Bits.AC1
#define CANIDAR2_AC2                    _CANIDAR2.Bits.AC2
#define CANIDAR2_AC3                    _CANIDAR2.Bits.AC3
#define CANIDAR2_AC4                    _CANIDAR2.Bits.AC4
#define CANIDAR2_AC5                    _CANIDAR2.Bits.AC5
#define CANIDAR2_AC6                    _CANIDAR2.Bits.AC6
#define CANIDAR2_AC7                    _CANIDAR2.Bits.AC7

#define CANIDAR2_AC0_MASK               1U
#define CANIDAR2_AC1_MASK               2U
#define CANIDAR2_AC2_MASK               4U
#define CANIDAR2_AC3_MASK               8U
#define CANIDAR2_AC4_MASK               16U
#define CANIDAR2_AC5_MASK               32U
#define CANIDAR2_AC6_MASK               64U
#define CANIDAR2_AC7_MASK               128U


/*** CANIDAR3 - MSCAN Identifier Acceptance Register 3; 0x00000813 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR3STR;
extern volatile CANIDAR3STR _CANIDAR3 @0x00000813;
#define CANIDAR3                        _CANIDAR3.Byte
#define CANIDAR3_AC0                    _CANIDAR3.Bits.AC0
#define CANIDAR3_AC1                    _CANIDAR3.Bits.AC1
#define CANIDAR3_AC2                    _CANIDAR3.Bits.AC2
#define CANIDAR3_AC3                    _CANIDAR3.Bits.AC3
#define CANIDAR3_AC4                    _CANIDAR3.Bits.AC4
#define CANIDAR3_AC5                    _CANIDAR3.Bits.AC5
#define CANIDAR3_AC6                    _CANIDAR3.Bits.AC6
#define CANIDAR3_AC7                    _CANIDAR3.Bits.AC7

#define CANIDAR3_AC0_MASK               1U
#define CANIDAR3_AC1_MASK               2U
#define CANIDAR3_AC2_MASK               4U
#define CANIDAR3_AC3_MASK               8U
#define CANIDAR3_AC4_MASK               16U
#define CANIDAR3_AC5_MASK               32U
#define CANIDAR3_AC6_MASK               64U
#define CANIDAR3_AC7_MASK               128U


/*** CANIDMR0 - MSCAN Identifier Mask Register 0; 0x00000814 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR0STR;
extern volatile CANIDMR0STR _CANIDMR0 @0x00000814;
#define CANIDMR0                        _CANIDMR0.Byte
#define CANIDMR0_AM0                    _CANIDMR0.Bits.AM0
#define CANIDMR0_AM1                    _CANIDMR0.Bits.AM1
#define CANIDMR0_AM2                    _CANIDMR0.Bits.AM2
#define CANIDMR0_AM3                    _CANIDMR0.Bits.AM3
#define CANIDMR0_AM4                    _CANIDMR0.Bits.AM4
#define CANIDMR0_AM5                    _CANIDMR0.Bits.AM5
#define CANIDMR0_AM6                    _CANIDMR0.Bits.AM6
#define CANIDMR0_AM7                    _CANIDMR0.Bits.AM7
/* CANIDMR_ARR: Access 4 CANIDMRx registers in an array */
#define CANIDMR_ARR                     ((volatile byte *) &CANIDMR0)

#define CANIDMR0_AM0_MASK               1U
#define CANIDMR0_AM1_MASK               2U
#define CANIDMR0_AM2_MASK               4U
#define CANIDMR0_AM3_MASK               8U
#define CANIDMR0_AM4_MASK               16U
#define CANIDMR0_AM5_MASK               32U
#define CANIDMR0_AM6_MASK               64U
#define CANIDMR0_AM7_MASK               128U


/*** CANIDMR1 - MSCAN Identifier Mask Register 1; 0x00000815 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR1STR;
extern volatile CANIDMR1STR _CANIDMR1 @0x00000815;
#define CANIDMR1                        _CANIDMR1.Byte
#define CANIDMR1_AM0                    _CANIDMR1.Bits.AM0
#define CANIDMR1_AM1                    _CANIDMR1.Bits.AM1
#define CANIDMR1_AM2                    _CANIDMR1.Bits.AM2
#define CANIDMR1_AM3                    _CANIDMR1.Bits.AM3
#define CANIDMR1_AM4                    _CANIDMR1.Bits.AM4
#define CANIDMR1_AM5                    _CANIDMR1.Bits.AM5
#define CANIDMR1_AM6                    _CANIDMR1.Bits.AM6
#define CANIDMR1_AM7                    _CANIDMR1.Bits.AM7

#define CANIDMR1_AM0_MASK               1U
#define CANIDMR1_AM1_MASK               2U
#define CANIDMR1_AM2_MASK               4U
#define CANIDMR1_AM3_MASK               8U
#define CANIDMR1_AM4_MASK               16U
#define CANIDMR1_AM5_MASK               32U
#define CANIDMR1_AM6_MASK               64U
#define CANIDMR1_AM7_MASK               128U


/*** CANIDMR2 - MSCAN Identifier Mask Register 2; 0x00000816 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR2STR;
extern volatile CANIDMR2STR _CANIDMR2 @0x00000816;
#define CANIDMR2                        _CANIDMR2.Byte
#define CANIDMR2_AM0                    _CANIDMR2.Bits.AM0
#define CANIDMR2_AM1                    _CANIDMR2.Bits.AM1
#define CANIDMR2_AM2                    _CANIDMR2.Bits.AM2
#define CANIDMR2_AM3                    _CANIDMR2.Bits.AM3
#define CANIDMR2_AM4                    _CANIDMR2.Bits.AM4
#define CANIDMR2_AM5                    _CANIDMR2.Bits.AM5
#define CANIDMR2_AM6                    _CANIDMR2.Bits.AM6
#define CANIDMR2_AM7                    _CANIDMR2.Bits.AM7

#define CANIDMR2_AM0_MASK               1U
#define CANIDMR2_AM1_MASK               2U
#define CANIDMR2_AM2_MASK               4U
#define CANIDMR2_AM3_MASK               8U
#define CANIDMR2_AM4_MASK               16U
#define CANIDMR2_AM5_MASK               32U
#define CANIDMR2_AM6_MASK               64U
#define CANIDMR2_AM7_MASK               128U


/*** CANIDMR3 - MSCAN Identifier Mask Register 3; 0x00000817 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR3STR;
extern volatile CANIDMR3STR _CANIDMR3 @0x00000817;
#define CANIDMR3                        _CANIDMR3.Byte
#define CANIDMR3_AM0                    _CANIDMR3.Bits.AM0
#define CANIDMR3_AM1                    _CANIDMR3.Bits.AM1
#define CANIDMR3_AM2                    _CANIDMR3.Bits.AM2
#define CANIDMR3_AM3                    _CANIDMR3.Bits.AM3
#define CANIDMR3_AM4                    _CANIDMR3.Bits.AM4
#define CANIDMR3_AM5                    _CANIDMR3.Bits.AM5
#define CANIDMR3_AM6                    _CANIDMR3.Bits.AM6
#define CANIDMR3_AM7                    _CANIDMR3.Bits.AM7

#define CANIDMR3_AM0_MASK               1U
#define CANIDMR3_AM1_MASK               2U
#define CANIDMR3_AM2_MASK               4U
#define CANIDMR3_AM3_MASK               8U
#define CANIDMR3_AM4_MASK               16U
#define CANIDMR3_AM5_MASK               32U
#define CANIDMR3_AM6_MASK               64U
#define CANIDMR3_AM7_MASK               128U


/*** CANIDAR4 - MSCAN Identifier Acceptance Register 4; 0x00000818 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR4STR;
extern volatile CANIDAR4STR _CANIDAR4 @0x00000818;
#define CANIDAR4                        _CANIDAR4.Byte
#define CANIDAR4_AC0                    _CANIDAR4.Bits.AC0
#define CANIDAR4_AC1                    _CANIDAR4.Bits.AC1
#define CANIDAR4_AC2                    _CANIDAR4.Bits.AC2
#define CANIDAR4_AC3                    _CANIDAR4.Bits.AC3
#define CANIDAR4_AC4                    _CANIDAR4.Bits.AC4
#define CANIDAR4_AC5                    _CANIDAR4.Bits.AC5
#define CANIDAR4_AC6                    _CANIDAR4.Bits.AC6
#define CANIDAR4_AC7                    _CANIDAR4.Bits.AC7

#define CANIDAR4_AC0_MASK               1U
#define CANIDAR4_AC1_MASK               2U
#define CANIDAR4_AC2_MASK               4U
#define CANIDAR4_AC3_MASK               8U
#define CANIDAR4_AC4_MASK               16U
#define CANIDAR4_AC5_MASK               32U
#define CANIDAR4_AC6_MASK               64U
#define CANIDAR4_AC7_MASK               128U


/*** CANIDAR5 - MSCAN Identifier Acceptance Register 5; 0x00000819 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR5STR;
extern volatile CANIDAR5STR _CANIDAR5 @0x00000819;
#define CANIDAR5                        _CANIDAR5.Byte
#define CANIDAR5_AC0                    _CANIDAR5.Bits.AC0
#define CANIDAR5_AC1                    _CANIDAR5.Bits.AC1
#define CANIDAR5_AC2                    _CANIDAR5.Bits.AC2
#define CANIDAR5_AC3                    _CANIDAR5.Bits.AC3
#define CANIDAR5_AC4                    _CANIDAR5.Bits.AC4
#define CANIDAR5_AC5                    _CANIDAR5.Bits.AC5
#define CANIDAR5_AC6                    _CANIDAR5.Bits.AC6
#define CANIDAR5_AC7                    _CANIDAR5.Bits.AC7

#define CANIDAR5_AC0_MASK               1U
#define CANIDAR5_AC1_MASK               2U
#define CANIDAR5_AC2_MASK               4U
#define CANIDAR5_AC3_MASK               8U
#define CANIDAR5_AC4_MASK               16U
#define CANIDAR5_AC5_MASK               32U
#define CANIDAR5_AC6_MASK               64U
#define CANIDAR5_AC7_MASK               128U


/*** CANIDAR6 - MSCAN Identifier Acceptance Register 6; 0x0000081A ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR6STR;
extern volatile CANIDAR6STR _CANIDAR6 @0x0000081A;
#define CANIDAR6                        _CANIDAR6.Byte
#define CANIDAR6_AC0                    _CANIDAR6.Bits.AC0
#define CANIDAR6_AC1                    _CANIDAR6.Bits.AC1
#define CANIDAR6_AC2                    _CANIDAR6.Bits.AC2
#define CANIDAR6_AC3                    _CANIDAR6.Bits.AC3
#define CANIDAR6_AC4                    _CANIDAR6.Bits.AC4
#define CANIDAR6_AC5                    _CANIDAR6.Bits.AC5
#define CANIDAR6_AC6                    _CANIDAR6.Bits.AC6
#define CANIDAR6_AC7                    _CANIDAR6.Bits.AC7

#define CANIDAR6_AC0_MASK               1U
#define CANIDAR6_AC1_MASK               2U
#define CANIDAR6_AC2_MASK               4U
#define CANIDAR6_AC3_MASK               8U
#define CANIDAR6_AC4_MASK               16U
#define CANIDAR6_AC5_MASK               32U
#define CANIDAR6_AC6_MASK               64U
#define CANIDAR6_AC7_MASK               128U


/*** CANIDAR7 - MSCAN Identifier Acceptance Register 7; 0x0000081B ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR7STR;
extern volatile CANIDAR7STR _CANIDAR7 @0x0000081B;
#define CANIDAR7                        _CANIDAR7.Byte
#define CANIDAR7_AC0                    _CANIDAR7.Bits.AC0
#define CANIDAR7_AC1                    _CANIDAR7.Bits.AC1
#define CANIDAR7_AC2                    _CANIDAR7.Bits.AC2
#define CANIDAR7_AC3                    _CANIDAR7.Bits.AC3
#define CANIDAR7_AC4                    _CANIDAR7.Bits.AC4
#define CANIDAR7_AC5                    _CANIDAR7.Bits.AC5
#define CANIDAR7_AC6                    _CANIDAR7.Bits.AC6
#define CANIDAR7_AC7                    _CANIDAR7.Bits.AC7

#define CANIDAR7_AC0_MASK               1U
#define CANIDAR7_AC1_MASK               2U
#define CANIDAR7_AC2_MASK               4U
#define CANIDAR7_AC3_MASK               8U
#define CANIDAR7_AC4_MASK               16U
#define CANIDAR7_AC5_MASK               32U
#define CANIDAR7_AC6_MASK               64U
#define CANIDAR7_AC7_MASK               128U


/*** CANIDMR4 - MSCAN Identifier Mask Register 4; 0x0000081C ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR4STR;
extern volatile CANIDMR4STR _CANIDMR4 @0x0000081C;
#define CANIDMR4                        _CANIDMR4.Byte
#define CANIDMR4_AM0                    _CANIDMR4.Bits.AM0
#define CANIDMR4_AM1                    _CANIDMR4.Bits.AM1
#define CANIDMR4_AM2                    _CANIDMR4.Bits.AM2
#define CANIDMR4_AM3                    _CANIDMR4.Bits.AM3
#define CANIDMR4_AM4                    _CANIDMR4.Bits.AM4
#define CANIDMR4_AM5                    _CANIDMR4.Bits.AM5
#define CANIDMR4_AM6                    _CANIDMR4.Bits.AM6
#define CANIDMR4_AM7                    _CANIDMR4.Bits.AM7

#define CANIDMR4_AM0_MASK               1U
#define CANIDMR4_AM1_MASK               2U
#define CANIDMR4_AM2_MASK               4U
#define CANIDMR4_AM3_MASK               8U
#define CANIDMR4_AM4_MASK               16U
#define CANIDMR4_AM5_MASK               32U
#define CANIDMR4_AM6_MASK               64U
#define CANIDMR4_AM7_MASK               128U


/*** CANIDMR5 - MSCAN Identifier Mask Register 5; 0x0000081D ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR5STR;
extern volatile CANIDMR5STR _CANIDMR5 @0x0000081D;
#define CANIDMR5                        _CANIDMR5.Byte
#define CANIDMR5_AM0                    _CANIDMR5.Bits.AM0
#define CANIDMR5_AM1                    _CANIDMR5.Bits.AM1
#define CANIDMR5_AM2                    _CANIDMR5.Bits.AM2
#define CANIDMR5_AM3                    _CANIDMR5.Bits.AM3
#define CANIDMR5_AM4                    _CANIDMR5.Bits.AM4
#define CANIDMR5_AM5                    _CANIDMR5.Bits.AM5
#define CANIDMR5_AM6                    _CANIDMR5.Bits.AM6
#define CANIDMR5_AM7                    _CANIDMR5.Bits.AM7

#define CANIDMR5_AM0_MASK               1U
#define CANIDMR5_AM1_MASK               2U
#define CANIDMR5_AM2_MASK               4U
#define CANIDMR5_AM3_MASK               8U
#define CANIDMR5_AM4_MASK               16U
#define CANIDMR5_AM5_MASK               32U
#define CANIDMR5_AM6_MASK               64U
#define CANIDMR5_AM7_MASK               128U


/*** CANIDMR6 - MSCAN Identifier Mask Register 6; 0x0000081E ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR6STR;
extern volatile CANIDMR6STR _CANIDMR6 @0x0000081E;
#define CANIDMR6                        _CANIDMR6.Byte
#define CANIDMR6_AM0                    _CANIDMR6.Bits.AM0
#define CANIDMR6_AM1                    _CANIDMR6.Bits.AM1
#define CANIDMR6_AM2                    _CANIDMR6.Bits.AM2
#define CANIDMR6_AM3                    _CANIDMR6.Bits.AM3
#define CANIDMR6_AM4                    _CANIDMR6.Bits.AM4
#define CANIDMR6_AM5                    _CANIDMR6.Bits.AM5
#define CANIDMR6_AM6                    _CANIDMR6.Bits.AM6
#define CANIDMR6_AM7                    _CANIDMR6.Bits.AM7

#define CANIDMR6_AM0_MASK               1U
#define CANIDMR6_AM1_MASK               2U
#define CANIDMR6_AM2_MASK               4U
#define CANIDMR6_AM3_MASK               8U
#define CANIDMR6_AM4_MASK               16U
#define CANIDMR6_AM5_MASK               32U
#define CANIDMR6_AM6_MASK               64U
#define CANIDMR6_AM7_MASK               128U


/*** CANIDMR7 - MSCAN Identifier Mask Register 7; 0x0000081F ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR7STR;
extern volatile CANIDMR7STR _CANIDMR7 @0x0000081F;
#define CANIDMR7                        _CANIDMR7.Byte
#define CANIDMR7_AM0                    _CANIDMR7.Bits.AM0
#define CANIDMR7_AM1                    _CANIDMR7.Bits.AM1
#define CANIDMR7_AM2                    _CANIDMR7.Bits.AM2
#define CANIDMR7_AM3                    _CANIDMR7.Bits.AM3
#define CANIDMR7_AM4                    _CANIDMR7.Bits.AM4
#define CANIDMR7_AM5                    _CANIDMR7.Bits.AM5
#define CANIDMR7_AM6                    _CANIDMR7.Bits.AM6
#define CANIDMR7_AM7                    _CANIDMR7.Bits.AM7

#define CANIDMR7_AM0_MASK               1U
#define CANIDMR7_AM1_MASK               2U
#define CANIDMR7_AM2_MASK               4U
#define CANIDMR7_AM3_MASK               8U
#define CANIDMR7_AM4_MASK               16U
#define CANIDMR7_AM5_MASK               32U
#define CANIDMR7_AM6_MASK               64U
#define CANIDMR7_AM7_MASK               128U


/*** CANRXIDR0 - MSCAN Receive Identifier Register 0; 0x00000820 ***/
typedef union {
  byte Byte;
  struct {
    byte ID21        :1;                                       /* Extended format identifier Bit 21 */
    byte ID22        :1;                                       /* Extended format identifier Bit 22 */
    byte ID23        :1;                                       /* Extended format identifier Bit 23 */
    byte ID24        :1;                                       /* Extended format identifier Bit 24 */
    byte ID25        :1;                                       /* Extended format identifier Bit 25 */
    byte ID26        :1;                                       /* Extended format identifier Bit 26 */
    byte ID27        :1;                                       /* Extended format identifier Bit 27 */
    byte ID28        :1;                                       /* Extended format identifier Bit 28 */
  } Bits;
} CANRXIDR0STR;
extern volatile CANRXIDR0STR _CANRXIDR0 @0x00000820;
#define CANRXIDR0                       _CANRXIDR0.Byte
#define CANRXIDR0_ID21                  _CANRXIDR0.Bits.ID21
#define CANRXIDR0_ID22                  _CANRXIDR0.Bits.ID22
#define CANRXIDR0_ID23                  _CANRXIDR0.Bits.ID23
#define CANRXIDR0_ID24                  _CANRXIDR0.Bits.ID24
#define CANRXIDR0_ID25                  _CANRXIDR0.Bits.ID25
#define CANRXIDR0_ID26                  _CANRXIDR0.Bits.ID26
#define CANRXIDR0_ID27                  _CANRXIDR0.Bits.ID27
#define CANRXIDR0_ID28                  _CANRXIDR0.Bits.ID28
/* CANRXIDR_ARR: Access 4 CANRXIDRx registers in an array */
#define CANRXIDR_ARR                    ((volatile byte *) &CANRXIDR0)

#define CANRXIDR0_ID21_MASK             1U
#define CANRXIDR0_ID22_MASK             2U
#define CANRXIDR0_ID23_MASK             4U
#define CANRXIDR0_ID24_MASK             8U
#define CANRXIDR0_ID25_MASK             16U
#define CANRXIDR0_ID26_MASK             32U
#define CANRXIDR0_ID27_MASK             64U
#define CANRXIDR0_ID28_MASK             128U


/*** CANRXIDR1 - MSCAN Receive Identifier Register 1; 0x00000821 ***/
typedef union {
  byte Byte;
  struct {
    byte ID15        :1;                                       /* Extended format identifier Bit 15 */
    byte ID16        :1;                                       /* Extended format identifier Bit 16 */
    byte ID17        :1;                                       /* Extended format identifier Bit 17 */
    byte IDE         :1;                                       /* ID Extended */
    byte SRR         :1;                                       /* Substitute Remote Request */
    byte ID18        :1;                                       /* Extended format identifier Bit 18 */
    byte ID19        :1;                                       /* Extended format identifier Bit 19 */
    byte ID20        :1;                                       /* Extended format identifier Bit 20 */
  } Bits;
  struct {
    byte grpID_15 :3;
    byte         :1;
    byte         :1;
    byte grpID_18 :3;
  } MergedBits;
} CANRXIDR1STR;
extern volatile CANRXIDR1STR _CANRXIDR1 @0x00000821;
#define CANRXIDR1                       _CANRXIDR1.Byte
#define CANRXIDR1_ID15                  _CANRXIDR1.Bits.ID15
#define CANRXIDR1_ID16                  _CANRXIDR1.Bits.ID16
#define CANRXIDR1_ID17                  _CANRXIDR1.Bits.ID17
#define CANRXIDR1_IDE                   _CANRXIDR1.Bits.IDE
#define CANRXIDR1_SRR                   _CANRXIDR1.Bits.SRR
#define CANRXIDR1_ID18                  _CANRXIDR1.Bits.ID18
#define CANRXIDR1_ID19                  _CANRXIDR1.Bits.ID19
#define CANRXIDR1_ID20                  _CANRXIDR1.Bits.ID20
#define CANRXIDR1_ID_15                 _CANRXIDR1.MergedBits.grpID_15
#define CANRXIDR1_ID_18                 _CANRXIDR1.MergedBits.grpID_18
#define CANRXIDR1_ID                    CANRXIDR1_ID_15

#define CANRXIDR1_ID15_MASK             1U
#define CANRXIDR1_ID16_MASK             2U
#define CANRXIDR1_ID17_MASK             4U
#define CANRXIDR1_IDE_MASK              8U
#define CANRXIDR1_SRR_MASK              16U
#define CANRXIDR1_ID18_MASK             32U
#define CANRXIDR1_ID19_MASK             64U
#define CANRXIDR1_ID20_MASK             128U
#define CANRXIDR1_ID_15_MASK            7U
#define CANRXIDR1_ID_15_BITNUM          0U
#define CANRXIDR1_ID_18_MASK            224U
#define CANRXIDR1_ID_18_BITNUM          5U


/*** CANRXIDR2 - MSCAN Receive Identifier Register 2; 0x00000822 ***/
typedef union {
  byte Byte;
  struct {
    byte ID7         :1;                                       /* Extended format identifier Bit 7 */
    byte ID8         :1;                                       /* Extended format identifier Bit 8 */
    byte ID9         :1;                                       /* Extended format identifier Bit 9 */
    byte ID10        :1;                                       /* Extended format identifier Bit 10 */
    byte ID11        :1;                                       /* Extended format identifier Bit 11 */
    byte ID12        :1;                                       /* Extended format identifier Bit 12 */
    byte ID13        :1;                                       /* Extended format identifier Bit 13 */
    byte ID14        :1;                                       /* Extended format identifier Bit 14 */
  } Bits;
} CANRXIDR2STR;
extern volatile CANRXIDR2STR _CANRXIDR2 @0x00000822;
#define CANRXIDR2                       _CANRXIDR2.Byte
#define CANRXIDR2_ID7                   _CANRXIDR2.Bits.ID7
#define CANRXIDR2_ID8                   _CANRXIDR2.Bits.ID8
#define CANRXIDR2_ID9                   _CANRXIDR2.Bits.ID9
#define CANRXIDR2_ID10                  _CANRXIDR2.Bits.ID10
#define CANRXIDR2_ID11                  _CANRXIDR2.Bits.ID11
#define CANRXIDR2_ID12                  _CANRXIDR2.Bits.ID12
#define CANRXIDR2_ID13                  _CANRXIDR2.Bits.ID13
#define CANRXIDR2_ID14                  _CANRXIDR2.Bits.ID14

#define CANRXIDR2_ID7_MASK              1U
#define CANRXIDR2_ID8_MASK              2U
#define CANRXIDR2_ID9_MASK              4U
#define CANRXIDR2_ID10_MASK             8U
#define CANRXIDR2_ID11_MASK             16U
#define CANRXIDR2_ID12_MASK             32U
#define CANRXIDR2_ID13_MASK             64U
#define CANRXIDR2_ID14_MASK             128U


/*** CANRXIDR3 - MSCAN Receive Identifier Register 3; 0x00000823 ***/
typedef union {
  byte Byte;
  struct {
    byte RTR         :1;                                       /* Remote Transmission Request */
    byte ID0         :1;                                       /* Extended format identifier Bit 0 */
    byte ID1         :1;                                       /* Extended format identifier Bit 1 */
    byte ID2         :1;                                       /* Extended format identifier Bit 2 */
    byte ID3         :1;                                       /* Extended format identifier Bit 3 */
    byte ID4         :1;                                       /* Extended format identifier Bit 4 */
    byte ID5         :1;                                       /* Extended format identifier Bit 5 */
    byte ID6         :1;                                       /* Extended format identifier Bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpID   :7;
  } MergedBits;
} CANRXIDR3STR;
extern volatile CANRXIDR3STR _CANRXIDR3 @0x00000823;
#define CANRXIDR3                       _CANRXIDR3.Byte
#define CANRXIDR3_RTR                   _CANRXIDR3.Bits.RTR
#define CANRXIDR3_ID0                   _CANRXIDR3.Bits.ID0
#define CANRXIDR3_ID1                   _CANRXIDR3.Bits.ID1
#define CANRXIDR3_ID2                   _CANRXIDR3.Bits.ID2
#define CANRXIDR3_ID3                   _CANRXIDR3.Bits.ID3
#define CANRXIDR3_ID4                   _CANRXIDR3.Bits.ID4
#define CANRXIDR3_ID5                   _CANRXIDR3.Bits.ID5
#define CANRXIDR3_ID6                   _CANRXIDR3.Bits.ID6
#define CANRXIDR3_ID                    _CANRXIDR3.MergedBits.grpID

#define CANRXIDR3_RTR_MASK              1U
#define CANRXIDR3_ID0_MASK              2U
#define CANRXIDR3_ID1_MASK              4U
#define CANRXIDR3_ID2_MASK              8U
#define CANRXIDR3_ID3_MASK              16U
#define CANRXIDR3_ID4_MASK              32U
#define CANRXIDR3_ID5_MASK              64U
#define CANRXIDR3_ID6_MASK              128U
#define CANRXIDR3_ID_MASK               254U
#define CANRXIDR3_ID_BITNUM             1U


/*** CANRXDSR0 - MSCAN Receive Data Segment Register 0; 0x00000824 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR0STR;
extern volatile CANRXDSR0STR _CANRXDSR0 @0x00000824;
#define CANRXDSR0                       _CANRXDSR0.Byte
#define CANRXDSR0_DB0                   _CANRXDSR0.Bits.DB0
#define CANRXDSR0_DB1                   _CANRXDSR0.Bits.DB1
#define CANRXDSR0_DB2                   _CANRXDSR0.Bits.DB2
#define CANRXDSR0_DB3                   _CANRXDSR0.Bits.DB3
#define CANRXDSR0_DB4                   _CANRXDSR0.Bits.DB4
#define CANRXDSR0_DB5                   _CANRXDSR0.Bits.DB5
#define CANRXDSR0_DB6                   _CANRXDSR0.Bits.DB6
#define CANRXDSR0_DB7                   _CANRXDSR0.Bits.DB7
/* CANRXDSR_ARR: Access 8 CANRXDSRx registers in an array */
#define CANRXDSR_ARR                    ((volatile byte *) &CANRXDSR0)

#define CANRXDSR0_DB0_MASK              1U
#define CANRXDSR0_DB1_MASK              2U
#define CANRXDSR0_DB2_MASK              4U
#define CANRXDSR0_DB3_MASK              8U
#define CANRXDSR0_DB4_MASK              16U
#define CANRXDSR0_DB5_MASK              32U
#define CANRXDSR0_DB6_MASK              64U
#define CANRXDSR0_DB7_MASK              128U


/*** CANRXDSR1 - MSCAN Receive Data Segment Register 1; 0x00000825 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR1STR;
extern volatile CANRXDSR1STR _CANRXDSR1 @0x00000825;
#define CANRXDSR1                       _CANRXDSR1.Byte
#define CANRXDSR1_DB0                   _CANRXDSR1.Bits.DB0
#define CANRXDSR1_DB1                   _CANRXDSR1.Bits.DB1
#define CANRXDSR1_DB2                   _CANRXDSR1.Bits.DB2
#define CANRXDSR1_DB3                   _CANRXDSR1.Bits.DB3
#define CANRXDSR1_DB4                   _CANRXDSR1.Bits.DB4
#define CANRXDSR1_DB5                   _CANRXDSR1.Bits.DB5
#define CANRXDSR1_DB6                   _CANRXDSR1.Bits.DB6
#define CANRXDSR1_DB7                   _CANRXDSR1.Bits.DB7

#define CANRXDSR1_DB0_MASK              1U
#define CANRXDSR1_DB1_MASK              2U
#define CANRXDSR1_DB2_MASK              4U
#define CANRXDSR1_DB3_MASK              8U
#define CANRXDSR1_DB4_MASK              16U
#define CANRXDSR1_DB5_MASK              32U
#define CANRXDSR1_DB6_MASK              64U
#define CANRXDSR1_DB7_MASK              128U


/*** CANRXDSR2 - MSCAN Receive Data Segment Register 2; 0x00000826 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR2STR;
extern volatile CANRXDSR2STR _CANRXDSR2 @0x00000826;
#define CANRXDSR2                       _CANRXDSR2.Byte
#define CANRXDSR2_DB0                   _CANRXDSR2.Bits.DB0
#define CANRXDSR2_DB1                   _CANRXDSR2.Bits.DB1
#define CANRXDSR2_DB2                   _CANRXDSR2.Bits.DB2
#define CANRXDSR2_DB3                   _CANRXDSR2.Bits.DB3
#define CANRXDSR2_DB4                   _CANRXDSR2.Bits.DB4
#define CANRXDSR2_DB5                   _CANRXDSR2.Bits.DB5
#define CANRXDSR2_DB6                   _CANRXDSR2.Bits.DB6
#define CANRXDSR2_DB7                   _CANRXDSR2.Bits.DB7

#define CANRXDSR2_DB0_MASK              1U
#define CANRXDSR2_DB1_MASK              2U
#define CANRXDSR2_DB2_MASK              4U
#define CANRXDSR2_DB3_MASK              8U
#define CANRXDSR2_DB4_MASK              16U
#define CANRXDSR2_DB5_MASK              32U
#define CANRXDSR2_DB6_MASK              64U
#define CANRXDSR2_DB7_MASK              128U


/*** CANRXDSR3 - MSCAN Receive Data Segment Register 3; 0x00000827 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR3STR;
extern volatile CANRXDSR3STR _CANRXDSR3 @0x00000827;
#define CANRXDSR3                       _CANRXDSR3.Byte
#define CANRXDSR3_DB0                   _CANRXDSR3.Bits.DB0
#define CANRXDSR3_DB1                   _CANRXDSR3.Bits.DB1
#define CANRXDSR3_DB2                   _CANRXDSR3.Bits.DB2
#define CANRXDSR3_DB3                   _CANRXDSR3.Bits.DB3
#define CANRXDSR3_DB4                   _CANRXDSR3.Bits.DB4
#define CANRXDSR3_DB5                   _CANRXDSR3.Bits.DB5
#define CANRXDSR3_DB6                   _CANRXDSR3.Bits.DB6
#define CANRXDSR3_DB7                   _CANRXDSR3.Bits.DB7

#define CANRXDSR3_DB0_MASK              1U
#define CANRXDSR3_DB1_MASK              2U
#define CANRXDSR3_DB2_MASK              4U
#define CANRXDSR3_DB3_MASK              8U
#define CANRXDSR3_DB4_MASK              16U
#define CANRXDSR3_DB5_MASK              32U
#define CANRXDSR3_DB6_MASK              64U
#define CANRXDSR3_DB7_MASK              128U


/*** CANRXDSR4 - MSCAN Receive Data Segment Register 4; 0x00000828 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR4STR;
extern volatile CANRXDSR4STR _CANRXDSR4 @0x00000828;
#define CANRXDSR4                       _CANRXDSR4.Byte
#define CANRXDSR4_DB0                   _CANRXDSR4.Bits.DB0
#define CANRXDSR4_DB1                   _CANRXDSR4.Bits.DB1
#define CANRXDSR4_DB2                   _CANRXDSR4.Bits.DB2
#define CANRXDSR4_DB3                   _CANRXDSR4.Bits.DB3
#define CANRXDSR4_DB4                   _CANRXDSR4.Bits.DB4
#define CANRXDSR4_DB5                   _CANRXDSR4.Bits.DB5
#define CANRXDSR4_DB6                   _CANRXDSR4.Bits.DB6
#define CANRXDSR4_DB7                   _CANRXDSR4.Bits.DB7

#define CANRXDSR4_DB0_MASK              1U
#define CANRXDSR4_DB1_MASK              2U
#define CANRXDSR4_DB2_MASK              4U
#define CANRXDSR4_DB3_MASK              8U
#define CANRXDSR4_DB4_MASK              16U
#define CANRXDSR4_DB5_MASK              32U
#define CANRXDSR4_DB6_MASK              64U
#define CANRXDSR4_DB7_MASK              128U


/*** CANRXDSR5 - MSCAN Receive Data Segment Register 5; 0x00000829 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR5STR;
extern volatile CANRXDSR5STR _CANRXDSR5 @0x00000829;
#define CANRXDSR5                       _CANRXDSR5.Byte
#define CANRXDSR5_DB0                   _CANRXDSR5.Bits.DB0
#define CANRXDSR5_DB1                   _CANRXDSR5.Bits.DB1
#define CANRXDSR5_DB2                   _CANRXDSR5.Bits.DB2
#define CANRXDSR5_DB3                   _CANRXDSR5.Bits.DB3
#define CANRXDSR5_DB4                   _CANRXDSR5.Bits.DB4
#define CANRXDSR5_DB5                   _CANRXDSR5.Bits.DB5
#define CANRXDSR5_DB6                   _CANRXDSR5.Bits.DB6
#define CANRXDSR5_DB7                   _CANRXDSR5.Bits.DB7

#define CANRXDSR5_DB0_MASK              1U
#define CANRXDSR5_DB1_MASK              2U
#define CANRXDSR5_DB2_MASK              4U
#define CANRXDSR5_DB3_MASK              8U
#define CANRXDSR5_DB4_MASK              16U
#define CANRXDSR5_DB5_MASK              32U
#define CANRXDSR5_DB6_MASK              64U
#define CANRXDSR5_DB7_MASK              128U


/*** CANRXDSR6 - MSCAN Receive Data Segment Register 6; 0x0000082A ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR6STR;
extern volatile CANRXDSR6STR _CANRXDSR6 @0x0000082A;
#define CANRXDSR6                       _CANRXDSR6.Byte
#define CANRXDSR6_DB0                   _CANRXDSR6.Bits.DB0
#define CANRXDSR6_DB1                   _CANRXDSR6.Bits.DB1
#define CANRXDSR6_DB2                   _CANRXDSR6.Bits.DB2
#define CANRXDSR6_DB3                   _CANRXDSR6.Bits.DB3
#define CANRXDSR6_DB4                   _CANRXDSR6.Bits.DB4
#define CANRXDSR6_DB5                   _CANRXDSR6.Bits.DB5
#define CANRXDSR6_DB6                   _CANRXDSR6.Bits.DB6
#define CANRXDSR6_DB7                   _CANRXDSR6.Bits.DB7

#define CANRXDSR6_DB0_MASK              1U
#define CANRXDSR6_DB1_MASK              2U
#define CANRXDSR6_DB2_MASK              4U
#define CANRXDSR6_DB3_MASK              8U
#define CANRXDSR6_DB4_MASK              16U
#define CANRXDSR6_DB5_MASK              32U
#define CANRXDSR6_DB6_MASK              64U
#define CANRXDSR6_DB7_MASK              128U


/*** CANRXDSR7 - MSCAN Receive Data Segment Register 7; 0x0000082B ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR7STR;
extern volatile CANRXDSR7STR _CANRXDSR7 @0x0000082B;
#define CANRXDSR7                       _CANRXDSR7.Byte
#define CANRXDSR7_DB0                   _CANRXDSR7.Bits.DB0
#define CANRXDSR7_DB1                   _CANRXDSR7.Bits.DB1
#define CANRXDSR7_DB2                   _CANRXDSR7.Bits.DB2
#define CANRXDSR7_DB3                   _CANRXDSR7.Bits.DB3
#define CANRXDSR7_DB4                   _CANRXDSR7.Bits.DB4
#define CANRXDSR7_DB5                   _CANRXDSR7.Bits.DB5
#define CANRXDSR7_DB6                   _CANRXDSR7.Bits.DB6
#define CANRXDSR7_DB7                   _CANRXDSR7.Bits.DB7

#define CANRXDSR7_DB0_MASK              1U
#define CANRXDSR7_DB1_MASK              2U
#define CANRXDSR7_DB2_MASK              4U
#define CANRXDSR7_DB3_MASK              8U
#define CANRXDSR7_DB4_MASK              16U
#define CANRXDSR7_DB5_MASK              32U
#define CANRXDSR7_DB6_MASK              64U
#define CANRXDSR7_DB7_MASK              128U


/*** CANRXDLR - MSCAN Receive Data Length Register; 0x0000082C ***/
typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       /* Data Length Code Bit 0 */
    byte DLC1        :1;                                       /* Data Length Code Bit 1 */
    byte DLC2        :1;                                       /* Data Length Code Bit 2 */
    byte DLC3        :1;                                       /* Data Length Code Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRXDLRSTR;
extern volatile CANRXDLRSTR _CANRXDLR @0x0000082C;
#define CANRXDLR                        _CANRXDLR.Byte
#define CANRXDLR_DLC0                   _CANRXDLR.Bits.DLC0
#define CANRXDLR_DLC1                   _CANRXDLR.Bits.DLC1
#define CANRXDLR_DLC2                   _CANRXDLR.Bits.DLC2
#define CANRXDLR_DLC3                   _CANRXDLR.Bits.DLC3
#define CANRXDLR_DLC                    _CANRXDLR.MergedBits.grpDLC

#define CANRXDLR_DLC0_MASK              1U
#define CANRXDLR_DLC1_MASK              2U
#define CANRXDLR_DLC2_MASK              4U
#define CANRXDLR_DLC3_MASK              8U
#define CANRXDLR_DLC_MASK               15U
#define CANRXDLR_DLC_BITNUM             0U


/*** CANRXTSR - MSCAN Receive Time Stamp Register; 0x0000082E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CANRXTSRH - MSCAN Receive Time Stamp Register High; 0x0000082E ***/
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       /* Time Stamp Bit 8 */
        byte TSR9        :1;                                       /* Time Stamp Bit 9 */
        byte TSR10       :1;                                       /* Time Stamp Bit 10 */
        byte TSR11       :1;                                       /* Time Stamp Bit 11 */
        byte TSR12       :1;                                       /* Time Stamp Bit 12 */
        byte TSR13       :1;                                       /* Time Stamp Bit 13 */
        byte TSR14       :1;                                       /* Time Stamp Bit 14 */
        byte TSR15       :1;                                       /* Time Stamp Bit 15 */
      } Bits;
    } CANRXTSRHSTR;
    #define CANRXTSRH                   _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Byte
    #define CANRXTSRH_TSR8              _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR8
    #define CANRXTSRH_TSR9              _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR9
    #define CANRXTSRH_TSR10             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR10
    #define CANRXTSRH_TSR11             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR11
    #define CANRXTSRH_TSR12             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR12
    #define CANRXTSRH_TSR13             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR13
    #define CANRXTSRH_TSR14             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR14
    #define CANRXTSRH_TSR15             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR15
    
    #define CANRXTSRH_TSR8_MASK         1U
    #define CANRXTSRH_TSR9_MASK         2U
    #define CANRXTSRH_TSR10_MASK        4U
    #define CANRXTSRH_TSR11_MASK        8U
    #define CANRXTSRH_TSR12_MASK        16U
    #define CANRXTSRH_TSR13_MASK        32U
    #define CANRXTSRH_TSR14_MASK        64U
    #define CANRXTSRH_TSR15_MASK        128U
    

    /*** CANRXTSRL - MSCAN Receive Time Stamp Register Low; 0x0000082F ***/
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       /* Time Stamp Bit 0 */
        byte TSR1        :1;                                       /* Time Stamp Bit 1 */
        byte TSR2        :1;                                       /* Time Stamp Bit 2 */
        byte TSR3        :1;                                       /* Time Stamp Bit 3 */
        byte TSR4        :1;                                       /* Time Stamp Bit 4 */
        byte TSR5        :1;                                       /* Time Stamp Bit 5 */
        byte TSR6        :1;                                       /* Time Stamp Bit 6 */
        byte TSR7        :1;                                       /* Time Stamp Bit 7 */
      } Bits;
    } CANRXTSRLSTR;
    #define CANRXTSRL                   _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Byte
    #define CANRXTSRL_TSR0              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR0
    #define CANRXTSRL_TSR1              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR1
    #define CANRXTSRL_TSR2              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR2
    #define CANRXTSRL_TSR3              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR3
    #define CANRXTSRL_TSR4              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR4
    #define CANRXTSRL_TSR5              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR5
    #define CANRXTSRL_TSR6              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR6
    #define CANRXTSRL_TSR7              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR7
    
    #define CANRXTSRL_TSR0_MASK         1U
    #define CANRXTSRL_TSR1_MASK         2U
    #define CANRXTSRL_TSR2_MASK         4U
    #define CANRXTSRL_TSR3_MASK         8U
    #define CANRXTSRL_TSR4_MASK         16U
    #define CANRXTSRL_TSR5_MASK         32U
    #define CANRXTSRL_TSR6_MASK         64U
    #define CANRXTSRL_TSR7_MASK         128U
    
  } Overlap_STR;

  struct {
    word TSR0        :1;                                       /* Time Stamp Bit 0 */
    word TSR1        :1;                                       /* Time Stamp Bit 1 */
    word TSR2        :1;                                       /* Time Stamp Bit 2 */
    word TSR3        :1;                                       /* Time Stamp Bit 3 */
    word TSR4        :1;                                       /* Time Stamp Bit 4 */
    word TSR5        :1;                                       /* Time Stamp Bit 5 */
    word TSR6        :1;                                       /* Time Stamp Bit 6 */
    word TSR7        :1;                                       /* Time Stamp Bit 7 */
    word TSR8        :1;                                       /* Time Stamp Bit 8 */
    word TSR9        :1;                                       /* Time Stamp Bit 9 */
    word TSR10       :1;                                       /* Time Stamp Bit 10 */
    word TSR11       :1;                                       /* Time Stamp Bit 11 */
    word TSR12       :1;                                       /* Time Stamp Bit 12 */
    word TSR13       :1;                                       /* Time Stamp Bit 13 */
    word TSR14       :1;                                       /* Time Stamp Bit 14 */
    word TSR15       :1;                                       /* Time Stamp Bit 15 */
  } Bits;
} CANRXTSRSTR;
extern volatile CANRXTSRSTR _CANRXTSR @0x0000082E;
#define CANRXTSR                        _CANRXTSR.Word
#define CANRXTSR_TSR0                   _CANRXTSR.Bits.TSR0
#define CANRXTSR_TSR1                   _CANRXTSR.Bits.TSR1
#define CANRXTSR_TSR2                   _CANRXTSR.Bits.TSR2
#define CANRXTSR_TSR3                   _CANRXTSR.Bits.TSR3
#define CANRXTSR_TSR4                   _CANRXTSR.Bits.TSR4
#define CANRXTSR_TSR5                   _CANRXTSR.Bits.TSR5
#define CANRXTSR_TSR6                   _CANRXTSR.Bits.TSR6
#define CANRXTSR_TSR7                   _CANRXTSR.Bits.TSR7
#define CANRXTSR_TSR8                   _CANRXTSR.Bits.TSR8
#define CANRXTSR_TSR9                   _CANRXTSR.Bits.TSR9
#define CANRXTSR_TSR10                  _CANRXTSR.Bits.TSR10
#define CANRXTSR_TSR11                  _CANRXTSR.Bits.TSR11
#define CANRXTSR_TSR12                  _CANRXTSR.Bits.TSR12
#define CANRXTSR_TSR13                  _CANRXTSR.Bits.TSR13
#define CANRXTSR_TSR14                  _CANRXTSR.Bits.TSR14
#define CANRXTSR_TSR15                  _CANRXTSR.Bits.TSR15

#define CANRXTSR_TSR0_MASK              1U
#define CANRXTSR_TSR1_MASK              2U
#define CANRXTSR_TSR2_MASK              4U
#define CANRXTSR_TSR3_MASK              8U
#define CANRXTSR_TSR4_MASK              16U
#define CANRXTSR_TSR5_MASK              32U
#define CANRXTSR_TSR6_MASK              64U
#define CANRXTSR_TSR7_MASK              128U
#define CANRXTSR_TSR8_MASK              256U
#define CANRXTSR_TSR9_MASK              512U
#define CANRXTSR_TSR10_MASK             1024U
#define CANRXTSR_TSR11_MASK             2048U
#define CANRXTSR_TSR12_MASK             4096U
#define CANRXTSR_TSR13_MASK             8192U
#define CANRXTSR_TSR14_MASK             16384U
#define CANRXTSR_TSR15_MASK             32768U


/*** CANTXIDR0 - MSCAN Transmit Identifier Register 0; 0x00000830 ***/
typedef union {
  byte Byte;
  struct {
    byte ID21        :1;                                       /* Extended format identifier Bit 21 */
    byte ID22        :1;                                       /* Extended format identifier Bit 22 */
    byte ID23        :1;                                       /* Extended format identifier Bit 23 */
    byte ID24        :1;                                       /* Extended format identifier Bit 24 */
    byte ID25        :1;                                       /* Extended format identifier Bit 25 */
    byte ID26        :1;                                       /* Extended format identifier Bit 26 */
    byte ID27        :1;                                       /* Extended format identifier Bit 27 */
    byte ID28        :1;                                       /* Extended format identifier Bit 28 */
  } Bits;
} CANTXIDR0STR;
extern volatile CANTXIDR0STR _CANTXIDR0 @0x00000830;
#define CANTXIDR0                       _CANTXIDR0.Byte
#define CANTXIDR0_ID21                  _CANTXIDR0.Bits.ID21
#define CANTXIDR0_ID22                  _CANTXIDR0.Bits.ID22
#define CANTXIDR0_ID23                  _CANTXIDR0.Bits.ID23
#define CANTXIDR0_ID24                  _CANTXIDR0.Bits.ID24
#define CANTXIDR0_ID25                  _CANTXIDR0.Bits.ID25
#define CANTXIDR0_ID26                  _CANTXIDR0.Bits.ID26
#define CANTXIDR0_ID27                  _CANTXIDR0.Bits.ID27
#define CANTXIDR0_ID28                  _CANTXIDR0.Bits.ID28
/* CANTXIDR_ARR: Access 4 CANTXIDRx registers in an array */
#define CANTXIDR_ARR                    ((volatile byte *) &CANTXIDR0)

#define CANTXIDR0_ID21_MASK             1U
#define CANTXIDR0_ID22_MASK             2U
#define CANTXIDR0_ID23_MASK             4U
#define CANTXIDR0_ID24_MASK             8U
#define CANTXIDR0_ID25_MASK             16U
#define CANTXIDR0_ID26_MASK             32U
#define CANTXIDR0_ID27_MASK             64U
#define CANTXIDR0_ID28_MASK             128U


/*** CANTXIDR1 - MSCAN Transmit Identifier Register 1; 0x00000831 ***/
typedef union {
  byte Byte;
  struct {
    byte ID15        :1;                                       /* Extended format identifier Bit 15 */
    byte ID16        :1;                                       /* Extended format identifier Bit 16 */
    byte ID17        :1;                                       /* Extended format identifier Bit 17 */
    byte IDE         :1;                                       /* ID Extended */
    byte SRR         :1;                                       /* Substitute Remote Request */
    byte ID18        :1;                                       /* Extended format identifier Bit 18 */
    byte ID19        :1;                                       /* Extended format identifier Bit 19 */
    byte ID20        :1;                                       /* Extended format identifier Bit 20 */
  } Bits;
  struct {
    byte grpID_15 :3;
    byte         :1;
    byte         :1;
    byte grpID_18 :3;
  } MergedBits;
} CANTXIDR1STR;
extern volatile CANTXIDR1STR _CANTXIDR1 @0x00000831;
#define CANTXIDR1                       _CANTXIDR1.Byte
#define CANTXIDR1_ID15                  _CANTXIDR1.Bits.ID15
#define CANTXIDR1_ID16                  _CANTXIDR1.Bits.ID16
#define CANTXIDR1_ID17                  _CANTXIDR1.Bits.ID17
#define CANTXIDR1_IDE                   _CANTXIDR1.Bits.IDE
#define CANTXIDR1_SRR                   _CANTXIDR1.Bits.SRR
#define CANTXIDR1_ID18                  _CANTXIDR1.Bits.ID18
#define CANTXIDR1_ID19                  _CANTXIDR1.Bits.ID19
#define CANTXIDR1_ID20                  _CANTXIDR1.Bits.ID20
#define CANTXIDR1_ID_15                 _CANTXIDR1.MergedBits.grpID_15
#define CANTXIDR1_ID_18                 _CANTXIDR1.MergedBits.grpID_18
#define CANTXIDR1_ID                    CANTXIDR1_ID_15

#define CANTXIDR1_ID15_MASK             1U
#define CANTXIDR1_ID16_MASK             2U
#define CANTXIDR1_ID17_MASK             4U
#define CANTXIDR1_IDE_MASK              8U
#define CANTXIDR1_SRR_MASK              16U
#define CANTXIDR1_ID18_MASK             32U
#define CANTXIDR1_ID19_MASK             64U
#define CANTXIDR1_ID20_MASK             128U
#define CANTXIDR1_ID_15_MASK            7U
#define CANTXIDR1_ID_15_BITNUM          0U
#define CANTXIDR1_ID_18_MASK            224U
#define CANTXIDR1_ID_18_BITNUM          5U


/*** CANTXIDR2 - MSCAN Transmit Identifier Register 2; 0x00000832 ***/
typedef union {
  byte Byte;
  struct {
    byte ID7         :1;                                       /* Extended format identifier Bit 7 */
    byte ID8         :1;                                       /* Extended format identifier Bit 8 */
    byte ID9         :1;                                       /* Extended format identifier Bit 9 */
    byte ID10        :1;                                       /* Extended format identifier Bit 10 */
    byte ID11        :1;                                       /* Extended format identifier Bit 11 */
    byte ID12        :1;                                       /* Extended format identifier Bit 12 */
    byte ID13        :1;                                       /* Extended format identifier Bit 13 */
    byte ID14        :1;                                       /* Extended format identifier Bit 14 */
  } Bits;
} CANTXIDR2STR;
extern volatile CANTXIDR2STR _CANTXIDR2 @0x00000832;
#define CANTXIDR2                       _CANTXIDR2.Byte
#define CANTXIDR2_ID7                   _CANTXIDR2.Bits.ID7
#define CANTXIDR2_ID8                   _CANTXIDR2.Bits.ID8
#define CANTXIDR2_ID9                   _CANTXIDR2.Bits.ID9
#define CANTXIDR2_ID10                  _CANTXIDR2.Bits.ID10
#define CANTXIDR2_ID11                  _CANTXIDR2.Bits.ID11
#define CANTXIDR2_ID12                  _CANTXIDR2.Bits.ID12
#define CANTXIDR2_ID13                  _CANTXIDR2.Bits.ID13
#define CANTXIDR2_ID14                  _CANTXIDR2.Bits.ID14

#define CANTXIDR2_ID7_MASK              1U
#define CANTXIDR2_ID8_MASK              2U
#define CANTXIDR2_ID9_MASK              4U
#define CANTXIDR2_ID10_MASK             8U
#define CANTXIDR2_ID11_MASK             16U
#define CANTXIDR2_ID12_MASK             32U
#define CANTXIDR2_ID13_MASK             64U
#define CANTXIDR2_ID14_MASK             128U


/*** CANTXIDR3 - MSCAN Transmit Identifier Register 3; 0x00000833 ***/
typedef union {
  byte Byte;
  struct {
    byte RTR         :1;                                       /* Remote Transmission Request */
    byte ID0         :1;                                       /* Extended format identifier Bit 0 */
    byte ID1         :1;                                       /* Extended format identifier Bit 1 */
    byte ID2         :1;                                       /* Extended format identifier Bit 2 */
    byte ID3         :1;                                       /* Extended format identifier Bit 3 */
    byte ID4         :1;                                       /* Extended format identifier Bit 4 */
    byte ID5         :1;                                       /* Extended format identifier Bit 5 */
    byte ID6         :1;                                       /* Extended format identifier Bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpID   :7;
  } MergedBits;
} CANTXIDR3STR;
extern volatile CANTXIDR3STR _CANTXIDR3 @0x00000833;
#define CANTXIDR3                       _CANTXIDR3.Byte
#define CANTXIDR3_RTR                   _CANTXIDR3.Bits.RTR
#define CANTXIDR3_ID0                   _CANTXIDR3.Bits.ID0
#define CANTXIDR3_ID1                   _CANTXIDR3.Bits.ID1
#define CANTXIDR3_ID2                   _CANTXIDR3.Bits.ID2
#define CANTXIDR3_ID3                   _CANTXIDR3.Bits.ID3
#define CANTXIDR3_ID4                   _CANTXIDR3.Bits.ID4
#define CANTXIDR3_ID5                   _CANTXIDR3.Bits.ID5
#define CANTXIDR3_ID6                   _CANTXIDR3.Bits.ID6
#define CANTXIDR3_ID                    _CANTXIDR3.MergedBits.grpID

#define CANTXIDR3_RTR_MASK              1U
#define CANTXIDR3_ID0_MASK              2U
#define CANTXIDR3_ID1_MASK              4U
#define CANTXIDR3_ID2_MASK              8U
#define CANTXIDR3_ID3_MASK              16U
#define CANTXIDR3_ID4_MASK              32U
#define CANTXIDR3_ID5_MASK              64U
#define CANTXIDR3_ID6_MASK              128U
#define CANTXIDR3_ID_MASK               254U
#define CANTXIDR3_ID_BITNUM             1U


/*** CANTXDSR0 - MSCAN Transmit Data Segment Register 0; 0x00000834 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR0STR;
extern volatile CANTXDSR0STR _CANTXDSR0 @0x00000834;
#define CANTXDSR0                       _CANTXDSR0.Byte
#define CANTXDSR0_DB0                   _CANTXDSR0.Bits.DB0
#define CANTXDSR0_DB1                   _CANTXDSR0.Bits.DB1
#define CANTXDSR0_DB2                   _CANTXDSR0.Bits.DB2
#define CANTXDSR0_DB3                   _CANTXDSR0.Bits.DB3
#define CANTXDSR0_DB4                   _CANTXDSR0.Bits.DB4
#define CANTXDSR0_DB5                   _CANTXDSR0.Bits.DB5
#define CANTXDSR0_DB6                   _CANTXDSR0.Bits.DB6
#define CANTXDSR0_DB7                   _CANTXDSR0.Bits.DB7
/* CANTXDSR_ARR: Access 8 CANTXDSRx registers in an array */
#define CANTXDSR_ARR                    ((volatile byte *) &CANTXDSR0)

#define CANTXDSR0_DB0_MASK              1U
#define CANTXDSR0_DB1_MASK              2U
#define CANTXDSR0_DB2_MASK              4U
#define CANTXDSR0_DB3_MASK              8U
#define CANTXDSR0_DB4_MASK              16U
#define CANTXDSR0_DB5_MASK              32U
#define CANTXDSR0_DB6_MASK              64U
#define CANTXDSR0_DB7_MASK              128U


/*** CANTXDSR1 - MSCAN Transmit Data Segment Register 1; 0x00000835 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR1STR;
extern volatile CANTXDSR1STR _CANTXDSR1 @0x00000835;
#define CANTXDSR1                       _CANTXDSR1.Byte
#define CANTXDSR1_DB0                   _CANTXDSR1.Bits.DB0
#define CANTXDSR1_DB1                   _CANTXDSR1.Bits.DB1
#define CANTXDSR1_DB2                   _CANTXDSR1.Bits.DB2
#define CANTXDSR1_DB3                   _CANTXDSR1.Bits.DB3
#define CANTXDSR1_DB4                   _CANTXDSR1.Bits.DB4
#define CANTXDSR1_DB5                   _CANTXDSR1.Bits.DB5
#define CANTXDSR1_DB6                   _CANTXDSR1.Bits.DB6
#define CANTXDSR1_DB7                   _CANTXDSR1.Bits.DB7

#define CANTXDSR1_DB0_MASK              1U
#define CANTXDSR1_DB1_MASK              2U
#define CANTXDSR1_DB2_MASK              4U
#define CANTXDSR1_DB3_MASK              8U
#define CANTXDSR1_DB4_MASK              16U
#define CANTXDSR1_DB5_MASK              32U
#define CANTXDSR1_DB6_MASK              64U
#define CANTXDSR1_DB7_MASK              128U


/*** CANTXDSR2 - MSCAN Transmit Data Segment Register 2; 0x00000836 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR2STR;
extern volatile CANTXDSR2STR _CANTXDSR2 @0x00000836;
#define CANTXDSR2                       _CANTXDSR2.Byte
#define CANTXDSR2_DB0                   _CANTXDSR2.Bits.DB0
#define CANTXDSR2_DB1                   _CANTXDSR2.Bits.DB1
#define CANTXDSR2_DB2                   _CANTXDSR2.Bits.DB2
#define CANTXDSR2_DB3                   _CANTXDSR2.Bits.DB3
#define CANTXDSR2_DB4                   _CANTXDSR2.Bits.DB4
#define CANTXDSR2_DB5                   _CANTXDSR2.Bits.DB5
#define CANTXDSR2_DB6                   _CANTXDSR2.Bits.DB6
#define CANTXDSR2_DB7                   _CANTXDSR2.Bits.DB7

#define CANTXDSR2_DB0_MASK              1U
#define CANTXDSR2_DB1_MASK              2U
#define CANTXDSR2_DB2_MASK              4U
#define CANTXDSR2_DB3_MASK              8U
#define CANTXDSR2_DB4_MASK              16U
#define CANTXDSR2_DB5_MASK              32U
#define CANTXDSR2_DB6_MASK              64U
#define CANTXDSR2_DB7_MASK              128U


/*** CANTXDSR3 - MSCAN Transmit Data Segment Register 3; 0x00000837 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR3STR;
extern volatile CANTXDSR3STR _CANTXDSR3 @0x00000837;
#define CANTXDSR3                       _CANTXDSR3.Byte
#define CANTXDSR3_DB0                   _CANTXDSR3.Bits.DB0
#define CANTXDSR3_DB1                   _CANTXDSR3.Bits.DB1
#define CANTXDSR3_DB2                   _CANTXDSR3.Bits.DB2
#define CANTXDSR3_DB3                   _CANTXDSR3.Bits.DB3
#define CANTXDSR3_DB4                   _CANTXDSR3.Bits.DB4
#define CANTXDSR3_DB5                   _CANTXDSR3.Bits.DB5
#define CANTXDSR3_DB6                   _CANTXDSR3.Bits.DB6
#define CANTXDSR3_DB7                   _CANTXDSR3.Bits.DB7

#define CANTXDSR3_DB0_MASK              1U
#define CANTXDSR3_DB1_MASK              2U
#define CANTXDSR3_DB2_MASK              4U
#define CANTXDSR3_DB3_MASK              8U
#define CANTXDSR3_DB4_MASK              16U
#define CANTXDSR3_DB5_MASK              32U
#define CANTXDSR3_DB6_MASK              64U
#define CANTXDSR3_DB7_MASK              128U


/*** CANTXDSR4 - MSCAN Transmit Data Segment Register 4; 0x00000838 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR4STR;
extern volatile CANTXDSR4STR _CANTXDSR4 @0x00000838;
#define CANTXDSR4                       _CANTXDSR4.Byte
#define CANTXDSR4_DB0                   _CANTXDSR4.Bits.DB0
#define CANTXDSR4_DB1                   _CANTXDSR4.Bits.DB1
#define CANTXDSR4_DB2                   _CANTXDSR4.Bits.DB2
#define CANTXDSR4_DB3                   _CANTXDSR4.Bits.DB3
#define CANTXDSR4_DB4                   _CANTXDSR4.Bits.DB4
#define CANTXDSR4_DB5                   _CANTXDSR4.Bits.DB5
#define CANTXDSR4_DB6                   _CANTXDSR4.Bits.DB6
#define CANTXDSR4_DB7                   _CANTXDSR4.Bits.DB7

#define CANTXDSR4_DB0_MASK              1U
#define CANTXDSR4_DB1_MASK              2U
#define CANTXDSR4_DB2_MASK              4U
#define CANTXDSR4_DB3_MASK              8U
#define CANTXDSR4_DB4_MASK              16U
#define CANTXDSR4_DB5_MASK              32U
#define CANTXDSR4_DB6_MASK              64U
#define CANTXDSR4_DB7_MASK              128U


/*** CANTXDSR5 - MSCAN Transmit Data Segment Register 5; 0x00000839 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR5STR;
extern volatile CANTXDSR5STR _CANTXDSR5 @0x00000839;
#define CANTXDSR5                       _CANTXDSR5.Byte
#define CANTXDSR5_DB0                   _CANTXDSR5.Bits.DB0
#define CANTXDSR5_DB1                   _CANTXDSR5.Bits.DB1
#define CANTXDSR5_DB2                   _CANTXDSR5.Bits.DB2
#define CANTXDSR5_DB3                   _CANTXDSR5.Bits.DB3
#define CANTXDSR5_DB4                   _CANTXDSR5.Bits.DB4
#define CANTXDSR5_DB5                   _CANTXDSR5.Bits.DB5
#define CANTXDSR5_DB6                   _CANTXDSR5.Bits.DB6
#define CANTXDSR5_DB7                   _CANTXDSR5.Bits.DB7

#define CANTXDSR5_DB0_MASK              1U
#define CANTXDSR5_DB1_MASK              2U
#define CANTXDSR5_DB2_MASK              4U
#define CANTXDSR5_DB3_MASK              8U
#define CANTXDSR5_DB4_MASK              16U
#define CANTXDSR5_DB5_MASK              32U
#define CANTXDSR5_DB6_MASK              64U
#define CANTXDSR5_DB7_MASK              128U


/*** CANTXDSR6 - MSCAN Transmit Data Segment Register 6; 0x0000083A ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR6STR;
extern volatile CANTXDSR6STR _CANTXDSR6 @0x0000083A;
#define CANTXDSR6                       _CANTXDSR6.Byte
#define CANTXDSR6_DB0                   _CANTXDSR6.Bits.DB0
#define CANTXDSR6_DB1                   _CANTXDSR6.Bits.DB1
#define CANTXDSR6_DB2                   _CANTXDSR6.Bits.DB2
#define CANTXDSR6_DB3                   _CANTXDSR6.Bits.DB3
#define CANTXDSR6_DB4                   _CANTXDSR6.Bits.DB4
#define CANTXDSR6_DB5                   _CANTXDSR6.Bits.DB5
#define CANTXDSR6_DB6                   _CANTXDSR6.Bits.DB6
#define CANTXDSR6_DB7                   _CANTXDSR6.Bits.DB7

#define CANTXDSR6_DB0_MASK              1U
#define CANTXDSR6_DB1_MASK              2U
#define CANTXDSR6_DB2_MASK              4U
#define CANTXDSR6_DB3_MASK              8U
#define CANTXDSR6_DB4_MASK              16U
#define CANTXDSR6_DB5_MASK              32U
#define CANTXDSR6_DB6_MASK              64U
#define CANTXDSR6_DB7_MASK              128U


/*** CANTXDSR7 - MSCAN Transmit Data Segment Register 7; 0x0000083B ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR7STR;
extern volatile CANTXDSR7STR _CANTXDSR7 @0x0000083B;
#define CANTXDSR7                       _CANTXDSR7.Byte
#define CANTXDSR7_DB0                   _CANTXDSR7.Bits.DB0
#define CANTXDSR7_DB1                   _CANTXDSR7.Bits.DB1
#define CANTXDSR7_DB2                   _CANTXDSR7.Bits.DB2
#define CANTXDSR7_DB3                   _CANTXDSR7.Bits.DB3
#define CANTXDSR7_DB4                   _CANTXDSR7.Bits.DB4
#define CANTXDSR7_DB5                   _CANTXDSR7.Bits.DB5
#define CANTXDSR7_DB6                   _CANTXDSR7.Bits.DB6
#define CANTXDSR7_DB7                   _CANTXDSR7.Bits.DB7

#define CANTXDSR7_DB0_MASK              1U
#define CANTXDSR7_DB1_MASK              2U
#define CANTXDSR7_DB2_MASK              4U
#define CANTXDSR7_DB3_MASK              8U
#define CANTXDSR7_DB4_MASK              16U
#define CANTXDSR7_DB5_MASK              32U
#define CANTXDSR7_DB6_MASK              64U
#define CANTXDSR7_DB7_MASK              128U


/*** CANTXDLR - MSCAN Transmit Data Length Register; 0x0000083C ***/
typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       /* Data Length Code Bit 0 */
    byte DLC1        :1;                                       /* Data Length Code Bit 1 */
    byte DLC2        :1;                                       /* Data Length Code Bit 2 */
    byte DLC3        :1;                                       /* Data Length Code Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTXDLRSTR;
extern volatile CANTXDLRSTR _CANTXDLR @0x0000083C;
#define CANTXDLR                        _CANTXDLR.Byte
#define CANTXDLR_DLC0                   _CANTXDLR.Bits.DLC0
#define CANTXDLR_DLC1                   _CANTXDLR.Bits.DLC1
#define CANTXDLR_DLC2                   _CANTXDLR.Bits.DLC2
#define CANTXDLR_DLC3                   _CANTXDLR.Bits.DLC3
#define CANTXDLR_DLC                    _CANTXDLR.MergedBits.grpDLC

#define CANTXDLR_DLC0_MASK              1U
#define CANTXDLR_DLC1_MASK              2U
#define CANTXDLR_DLC2_MASK              4U
#define CANTXDLR_DLC3_MASK              8U
#define CANTXDLR_DLC_MASK               15U
#define CANTXDLR_DLC_BITNUM             0U


/*** CANTXTBPR - MSCAN Transmit Buffer Priority; 0x0000083D ***/
typedef union {
  byte Byte;
  struct {
    byte PRIO0       :1;                                       /* Transmit Buffer Priority Bit 0 */
    byte PRIO1       :1;                                       /* Transmit Buffer Priority Bit 1 */
    byte PRIO2       :1;                                       /* Transmit Buffer Priority Bit 2 */
    byte PRIO3       :1;                                       /* Transmit Buffer Priority Bit 3 */
    byte PRIO4       :1;                                       /* Transmit Buffer Priority Bit 4 */
    byte PRIO5       :1;                                       /* Transmit Buffer Priority Bit 5 */
    byte PRIO6       :1;                                       /* Transmit Buffer Priority Bit 6 */
    byte PRIO7       :1;                                       /* Transmit Buffer Priority Bit 7 */
  } Bits;
} CANTXTBPRSTR;
extern volatile CANTXTBPRSTR _CANTXTBPR @0x0000083D;
#define CANTXTBPR                       _CANTXTBPR.Byte
#define CANTXTBPR_PRIO0                 _CANTXTBPR.Bits.PRIO0
#define CANTXTBPR_PRIO1                 _CANTXTBPR.Bits.PRIO1
#define CANTXTBPR_PRIO2                 _CANTXTBPR.Bits.PRIO2
#define CANTXTBPR_PRIO3                 _CANTXTBPR.Bits.PRIO3
#define CANTXTBPR_PRIO4                 _CANTXTBPR.Bits.PRIO4
#define CANTXTBPR_PRIO5                 _CANTXTBPR.Bits.PRIO5
#define CANTXTBPR_PRIO6                 _CANTXTBPR.Bits.PRIO6
#define CANTXTBPR_PRIO7                 _CANTXTBPR.Bits.PRIO7

#define CANTXTBPR_PRIO0_MASK            1U
#define CANTXTBPR_PRIO1_MASK            2U
#define CANTXTBPR_PRIO2_MASK            4U
#define CANTXTBPR_PRIO3_MASK            8U
#define CANTXTBPR_PRIO4_MASK            16U
#define CANTXTBPR_PRIO5_MASK            32U
#define CANTXTBPR_PRIO6_MASK            64U
#define CANTXTBPR_PRIO7_MASK            128U


/*** CANTXTSR - MSCAN Transmit Time Stamp Register; 0x0000083E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CANTXTSRH - MSCAN Transmit Time Stamp Register High; 0x0000083E ***/
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       /* Time Stamp Bit 8 */
        byte TSR9        :1;                                       /* Time Stamp Bit 9 */
        byte TSR10       :1;                                       /* Time Stamp Bit 10 */
        byte TSR11       :1;                                       /* Time Stamp Bit 11 */
        byte TSR12       :1;                                       /* Time Stamp Bit 12 */
        byte TSR13       :1;                                       /* Time Stamp Bit 13 */
        byte TSR14       :1;                                       /* Time Stamp Bit 14 */
        byte TSR15       :1;                                       /* Time Stamp Bit 15 */
      } Bits;
    } CANTXTSRHSTR;
    #define CANTXTSRH                   _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Byte
    #define CANTXTSRH_TSR8              _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR8
    #define CANTXTSRH_TSR9              _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR9
    #define CANTXTSRH_TSR10             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR10
    #define CANTXTSRH_TSR11             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR11
    #define CANTXTSRH_TSR12             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR12
    #define CANTXTSRH_TSR13             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR13
    #define CANTXTSRH_TSR14             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR14
    #define CANTXTSRH_TSR15             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR15
    
    #define CANTXTSRH_TSR8_MASK         1U
    #define CANTXTSRH_TSR9_MASK         2U
    #define CANTXTSRH_TSR10_MASK        4U
    #define CANTXTSRH_TSR11_MASK        8U
    #define CANTXTSRH_TSR12_MASK        16U
    #define CANTXTSRH_TSR13_MASK        32U
    #define CANTXTSRH_TSR14_MASK        64U
    #define CANTXTSRH_TSR15_MASK        128U
    

    /*** CANTXTSRL - MSCAN Transmit Time Stamp Register Low; 0x0000083F ***/
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       /* Time Stamp Bit 0 */
        byte TSR1        :1;                                       /* Time Stamp Bit 1 */
        byte TSR2        :1;                                       /* Time Stamp Bit 2 */
        byte TSR3        :1;                                       /* Time Stamp Bit 3 */
        byte TSR4        :1;                                       /* Time Stamp Bit 4 */
        byte TSR5        :1;                                       /* Time Stamp Bit 5 */
        byte TSR6        :1;                                       /* Time Stamp Bit 6 */
        byte TSR7        :1;                                       /* Time Stamp Bit 7 */
      } Bits;
    } CANTXTSRLSTR;
    #define CANTXTSRL                   _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Byte
    #define CANTXTSRL_TSR0              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR0
    #define CANTXTSRL_TSR1              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR1
    #define CANTXTSRL_TSR2              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR2
    #define CANTXTSRL_TSR3              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR3
    #define CANTXTSRL_TSR4              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR4
    #define CANTXTSRL_TSR5              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR5
    #define CANTXTSRL_TSR6              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR6
    #define CANTXTSRL_TSR7              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR7
    
    #define CANTXTSRL_TSR0_MASK         1U
    #define CANTXTSRL_TSR1_MASK         2U
    #define CANTXTSRL_TSR2_MASK         4U
    #define CANTXTSRL_TSR3_MASK         8U
    #define CANTXTSRL_TSR4_MASK         16U
    #define CANTXTSRL_TSR5_MASK         32U
    #define CANTXTSRL_TSR6_MASK         64U
    #define CANTXTSRL_TSR7_MASK         128U
    
  } Overlap_STR;

  struct {
    word TSR0        :1;                                       /* Time Stamp Bit 0 */
    word TSR1        :1;                                       /* Time Stamp Bit 1 */
    word TSR2        :1;                                       /* Time Stamp Bit 2 */
    word TSR3        :1;                                       /* Time Stamp Bit 3 */
    word TSR4        :1;                                       /* Time Stamp Bit 4 */
    word TSR5        :1;                                       /* Time Stamp Bit 5 */
    word TSR6        :1;                                       /* Time Stamp Bit 6 */
    word TSR7        :1;                                       /* Time Stamp Bit 7 */
    word TSR8        :1;                                       /* Time Stamp Bit 8 */
    word TSR9        :1;                                       /* Time Stamp Bit 9 */
    word TSR10       :1;                                       /* Time Stamp Bit 10 */
    word TSR11       :1;                                       /* Time Stamp Bit 11 */
    word TSR12       :1;                                       /* Time Stamp Bit 12 */
    word TSR13       :1;                                       /* Time Stamp Bit 13 */
    word TSR14       :1;                                       /* Time Stamp Bit 14 */
    word TSR15       :1;                                       /* Time Stamp Bit 15 */
  } Bits;
} CANTXTSRSTR;
extern volatile CANTXTSRSTR _CANTXTSR @0x0000083E;
#define CANTXTSR                        _CANTXTSR.Word
#define CANTXTSR_TSR0                   _CANTXTSR.Bits.TSR0
#define CANTXTSR_TSR1                   _CANTXTSR.Bits.TSR1
#define CANTXTSR_TSR2                   _CANTXTSR.Bits.TSR2
#define CANTXTSR_TSR3                   _CANTXTSR.Bits.TSR3
#define CANTXTSR_TSR4                   _CANTXTSR.Bits.TSR4
#define CANTXTSR_TSR5                   _CANTXTSR.Bits.TSR5
#define CANTXTSR_TSR6                   _CANTXTSR.Bits.TSR6
#define CANTXTSR_TSR7                   _CANTXTSR.Bits.TSR7
#define CANTXTSR_TSR8                   _CANTXTSR.Bits.TSR8
#define CANTXTSR_TSR9                   _CANTXTSR.Bits.TSR9
#define CANTXTSR_TSR10                  _CANTXTSR.Bits.TSR10
#define CANTXTSR_TSR11                  _CANTXTSR.Bits.TSR11
#define CANTXTSR_TSR12                  _CANTXTSR.Bits.TSR12
#define CANTXTSR_TSR13                  _CANTXTSR.Bits.TSR13
#define CANTXTSR_TSR14                  _CANTXTSR.Bits.TSR14
#define CANTXTSR_TSR15                  _CANTXTSR.Bits.TSR15

#define CANTXTSR_TSR0_MASK              1U
#define CANTXTSR_TSR1_MASK              2U
#define CANTXTSR_TSR2_MASK              4U
#define CANTXTSR_TSR3_MASK              8U
#define CANTXTSR_TSR4_MASK              16U
#define CANTXTSR_TSR5_MASK              32U
#define CANTXTSR_TSR6_MASK              64U
#define CANTXTSR_TSR7_MASK              128U
#define CANTXTSR_TSR8_MASK              256U
#define CANTXTSR_TSR9_MASK              512U
#define CANTXTSR_TSR10_MASK             1024U
#define CANTXTSR_TSR11_MASK             2048U
#define CANTXTSR_TSR12_MASK             4096U
#define CANTXTSR_TSR13_MASK             8192U
#define CANTXTSR_TSR14_MASK             16384U
#define CANTXTSR_TSR15_MASK             32768U


/*** B_PCR_CTL - PCR Control Register; 0x00000E00 ***/
typedef union {
  word Word;
  struct {
    word OPM         :2;                                       /* Operation mode select 0 */
    word PF          :2;                                       /* 1 ms Prescaler 0 */
    word             :1; 
    word HWR         :1;                                       /* Hardware Reset */
    word UVIE        :1;                                       /* Low Supply Voltage Interrupt enable */
    word HTIE        :1;                                       /* High Temperature Interrupt enable */
    word OPMM        :2;                                       /* Operation mode mask 0 */
    word PFM         :2;                                       /* Prescalar factor mask 0 */
    word             :1; 
    word HWRM        :1;                                       /* Hardware reset mask */
    word UVIEM       :1;                                       /* Supply Under Voltage interrupt enable mask */
    word HTIEM       :1;                                       /* High temperature interrupt enable mask */
  } Bits;
} B_PCR_CTLSTR;
extern volatile B_PCR_CTLSTR _B_PCR_CTL @0x00000E00;
#define B_PCR_CTL                       _B_PCR_CTL.Word
#define B_PCR_CTL_OPM                   _B_PCR_CTL.Bits.OPM
#define B_PCR_CTL_PF                    _B_PCR_CTL.Bits.PF
#define B_PCR_CTL_HWR                   _B_PCR_CTL.Bits.HWR
#define B_PCR_CTL_UVIE                  _B_PCR_CTL.Bits.UVIE
#define B_PCR_CTL_HTIE                  _B_PCR_CTL.Bits.HTIE
#define B_PCR_CTL_OPMM                  _B_PCR_CTL.Bits.OPMM
#define B_PCR_CTL_PFM                   _B_PCR_CTL.Bits.PFM
#define B_PCR_CTL_HWRM                  _B_PCR_CTL.Bits.HWRM
#define B_PCR_CTL_UVIEM                 _B_PCR_CTL.Bits.UVIEM
#define B_PCR_CTL_HTIEM                 _B_PCR_CTL.Bits.HTIEM

#define B_PCR_CTL_OPM_MASK              3U
#define B_PCR_CTL_OPM_BITNUM            0U
#define B_PCR_CTL_PF_MASK               12U
#define B_PCR_CTL_PF_BITNUM             2U
#define B_PCR_CTL_HWR_MASK              32U
#define B_PCR_CTL_UVIE_MASK             64U
#define B_PCR_CTL_HTIE_MASK             128U
#define B_PCR_CTL_OPMM_MASK             768U
#define B_PCR_CTL_OPMM_BITNUM           8U
#define B_PCR_CTL_PFM_MASK              3072U
#define B_PCR_CTL_PFM_BITNUM            10U
#define B_PCR_CTL_HWRM_MASK             8192U
#define B_PCR_CTL_UVIEM_MASK            16384U
#define B_PCR_CTL_HTIEM_MASK            32768U


/*** B_PCR_SR - PCR Status Register; 0x00000E02 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_PCR_SRH - PCR Status Register High; 0x00000E02 ***/
    union {
      byte Byte;
      struct {
        byte WLPMF       :1;                                       /* Wake-up after Low Power Mode Flag */
        byte WULTCF      :1;                                       /* Life Time Counter Wake Up Flag */
        byte LVRF        :1;                                       /* VDDL Low Voltage (POR) Reset Flag */
        byte HVRF        :1;                                       /* VDDH Low Voltage Reset Flag */
        byte WDRF        :1;                                       /* Watchdog Reset Flag */
        byte HWRF        :1;                                       /* Hardware Reset Flag */
        byte UVF         :1;                                       /* Supply Undervoltage Condition Flag */
        byte HTF         :1;                                       /* High Temperature Condition Flag */
      } Bits;
    } B_PCR_SRHSTR;
    #define B_PCR_SRH                   _B_PCR_SR.Overlap_STR.B_PCR_SRHSTR.Byte
    #define B_PCR_SRH_WLPMF             _B_PCR_SR.Overlap_STR.B_PCR_SRHSTR.Bits.WLPMF
    #define B_PCR_SRH_WULTCF            _B_PCR_SR.Overlap_STR.B_PCR_SRHSTR.Bits.WULTCF
    #define B_PCR_SRH_LVRF              _B_PCR_SR.Overlap_STR.B_PCR_SRHSTR.Bits.LVRF
    #define B_PCR_SRH_HVRF              _B_PCR_SR.Overlap_STR.B_PCR_SRHSTR.Bits.HVRF
    #define B_PCR_SRH_WDRF              _B_PCR_SR.Overlap_STR.B_PCR_SRHSTR.Bits.WDRF
    #define B_PCR_SRH_HWRF              _B_PCR_SR.Overlap_STR.B_PCR_SRHSTR.Bits.HWRF
    #define B_PCR_SRH_UVF               _B_PCR_SR.Overlap_STR.B_PCR_SRHSTR.Bits.UVF
    #define B_PCR_SRH_HTF               _B_PCR_SR.Overlap_STR.B_PCR_SRHSTR.Bits.HTF
    
    #define B_PCR_SRH_WLPMF_MASK        1U
    #define B_PCR_SRH_WULTCF_MASK       2U
    #define B_PCR_SRH_LVRF_MASK         4U
    #define B_PCR_SRH_HVRF_MASK         8U
    #define B_PCR_SRH_WDRF_MASK         16U
    #define B_PCR_SRH_HWRF_MASK         32U
    #define B_PCR_SRH_UVF_MASK          64U
    #define B_PCR_SRH_HTF_MASK          128U
    

    /*** B_PCR_SRL - PCR Status Register Low; 0x00000E03 ***/
    union {
      byte Byte;
      struct {
        byte WUPTB1F     :1;                                       /* Wake-up on GPIO 1 event flag */
        byte WUPTB2F     :1;                                       /* Wake-up on GPIO 2 event flag */
        byte WUPTB3F     :1;                                       /* Wake-up on GPIO 3 event flag */
        byte WUPTB4F     :1;                                       /* Wake-up on GPIO 4 event flag */
        byte WULINF      :1;                                       /* Wake-up on LIN flag */
        byte WUCALF      :1;                                       /* Wake-up on calibration request flag */
        byte WUCTHF      :1;                                       /* Wake-up on current threshold Flag */
        byte WUAHTHF     :1;                                       /* Wake-up on Ah counter threshold Flag */
      } Bits;
    } B_PCR_SRLSTR;
    #define B_PCR_SRL                   _B_PCR_SR.Overlap_STR.B_PCR_SRLSTR.Byte
    #define B_PCR_SRL_WUPTB1F           _B_PCR_SR.Overlap_STR.B_PCR_SRLSTR.Bits.WUPTB1F
    #define B_PCR_SRL_WUPTB2F           _B_PCR_SR.Overlap_STR.B_PCR_SRLSTR.Bits.WUPTB2F
    #define B_PCR_SRL_WUPTB3F           _B_PCR_SR.Overlap_STR.B_PCR_SRLSTR.Bits.WUPTB3F
    #define B_PCR_SRL_WUPTB4F           _B_PCR_SR.Overlap_STR.B_PCR_SRLSTR.Bits.WUPTB4F
    #define B_PCR_SRL_WULINF            _B_PCR_SR.Overlap_STR.B_PCR_SRLSTR.Bits.WULINF
    #define B_PCR_SRL_WUCALF            _B_PCR_SR.Overlap_STR.B_PCR_SRLSTR.Bits.WUCALF
    #define B_PCR_SRL_WUCTHF            _B_PCR_SR.Overlap_STR.B_PCR_SRLSTR.Bits.WUCTHF
    #define B_PCR_SRL_WUAHTHF           _B_PCR_SR.Overlap_STR.B_PCR_SRLSTR.Bits.WUAHTHF
    
    #define B_PCR_SRL_WUPTB1F_MASK      1U
    #define B_PCR_SRL_WUPTB2F_MASK      2U
    #define B_PCR_SRL_WUPTB3F_MASK      4U
    #define B_PCR_SRL_WUPTB4F_MASK      8U
    #define B_PCR_SRL_WULINF_MASK       16U
    #define B_PCR_SRL_WUCALF_MASK       32U
    #define B_PCR_SRL_WUCTHF_MASK       64U
    #define B_PCR_SRL_WUAHTHF_MASK      128U
    
  } Overlap_STR;

  struct {
    word WUPTB1F     :1;                                       /* Wake-up on GPIO 1 event flag */
    word WUPTB2F     :1;                                       /* Wake-up on GPIO 2 event flag */
    word WUPTB3F     :1;                                       /* Wake-up on GPIO 3 event flag */
    word WUPTB4F     :1;                                       /* Wake-up on GPIO 4 event flag */
    word WULINF      :1;                                       /* Wake-up on LIN flag */
    word WUCALF      :1;                                       /* Wake-up on calibration request flag */
    word WUCTHF      :1;                                       /* Wake-up on current threshold Flag */
    word WUAHTHF     :1;                                       /* Wake-up on Ah counter threshold Flag */
    word WLPMF       :1;                                       /* Wake-up after Low Power Mode Flag */
    word WULTCF      :1;                                       /* Life Time Counter Wake Up Flag */
    word LVRF        :1;                                       /* VDDL Low Voltage (POR) Reset Flag */
    word HVRF        :1;                                       /* VDDH Low Voltage Reset Flag */
    word WDRF        :1;                                       /* Watchdog Reset Flag */
    word HWRF        :1;                                       /* Hardware Reset Flag */
    word UVF         :1;                                       /* Supply Undervoltage Condition Flag */
    word HTF         :1;                                       /* High Temperature Condition Flag */
  } Bits;
} B_PCR_SRSTR;
extern volatile B_PCR_SRSTR _B_PCR_SR @0x00000E02;
#define B_PCR_SR                        _B_PCR_SR.Word
#define B_PCR_SR_WUPTB1F                _B_PCR_SR.Bits.WUPTB1F
#define B_PCR_SR_WUPTB2F                _B_PCR_SR.Bits.WUPTB2F
#define B_PCR_SR_WUPTB3F                _B_PCR_SR.Bits.WUPTB3F
#define B_PCR_SR_WUPTB4F                _B_PCR_SR.Bits.WUPTB4F
#define B_PCR_SR_WULINF                 _B_PCR_SR.Bits.WULINF
#define B_PCR_SR_WUCALF                 _B_PCR_SR.Bits.WUCALF
#define B_PCR_SR_WUCTHF                 _B_PCR_SR.Bits.WUCTHF
#define B_PCR_SR_WUAHTHF                _B_PCR_SR.Bits.WUAHTHF
#define B_PCR_SR_WLPMF                  _B_PCR_SR.Bits.WLPMF
#define B_PCR_SR_WULTCF                 _B_PCR_SR.Bits.WULTCF
#define B_PCR_SR_LVRF                   _B_PCR_SR.Bits.LVRF
#define B_PCR_SR_HVRF                   _B_PCR_SR.Bits.HVRF
#define B_PCR_SR_WDRF                   _B_PCR_SR.Bits.WDRF
#define B_PCR_SR_HWRF                   _B_PCR_SR.Bits.HWRF
#define B_PCR_SR_UVF                    _B_PCR_SR.Bits.UVF
#define B_PCR_SR_HTF                    _B_PCR_SR.Bits.HTF

#define B_PCR_SR_WUPTB1F_MASK           1U
#define B_PCR_SR_WUPTB2F_MASK           2U
#define B_PCR_SR_WUPTB3F_MASK           4U
#define B_PCR_SR_WUPTB4F_MASK           8U
#define B_PCR_SR_WULINF_MASK            16U
#define B_PCR_SR_WUCALF_MASK            32U
#define B_PCR_SR_WUCTHF_MASK            64U
#define B_PCR_SR_WUAHTHF_MASK           128U
#define B_PCR_SR_WLPMF_MASK             256U
#define B_PCR_SR_WULTCF_MASK            512U
#define B_PCR_SR_LVRF_MASK              1024U
#define B_PCR_SR_HVRF_MASK              2048U
#define B_PCR_SR_WDRF_MASK              4096U
#define B_PCR_SR_HWRF_MASK              8192U
#define B_PCR_SR_UVF_MASK               16384U
#define B_PCR_SR_HTF_MASK               32768U


/*** B_PCR_PRESC - PCR 1ms prescaler; 0x00000E04 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_PCR_PRESCH - PCR 1ms prescaler high byte; 0x00000E04 ***/
    union {
      byte Byte;
    } B_PCR_PRESCHSTR;
    #define B_PCR_PRESCH                _B_PCR_PRESC.Overlap_STR.B_PCR_PRESCHSTR.Byte
    

    /*** B_PCR_PRESCL - PCR 1ms prescaler low byte; 0x00000E05 ***/
    union {
      byte Byte;
    } B_PCR_PRESCLSTR;
    #define B_PCR_PRESCL                _B_PCR_PRESC.Overlap_STR.B_PCR_PRESCLSTR.Byte
    
  } Overlap_STR;

} B_PCR_PRESCSTR;
extern volatile B_PCR_PRESCSTR _B_PCR_PRESC @0x00000E04;
#define B_PCR_PRESC                     _B_PCR_PRESC.Word


/*** B_PCR_WUE - Wake Up Enable Register; 0x00000E06 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_PCR_WUEH - Wake Up Enable Register High; 0x00000E06 ***/
    union {
      byte Byte;
      struct {
        byte WUPTB1      :1;                                       /* Wake-up on GPIO 1 event */
        byte WUPTB2      :1;                                       /* Wake-up on GPIO 2 event */
        byte WUPTB3      :1;                                       /* Wake-up on GPIO 3 event */
        byte WUPTB4      :1;                                       /* Wake-up on GPIO 4 event */
        byte WULIN       :1;                                       /* Wake-up on LIN */
        byte WUCAL       :1;                                       /* Wake-up on calibration request */
        byte WUCTH       :1;                                       /* Wake-up on current threshold */
        byte WUAHTH      :1;                                       /* Wake-up on Ah counter */
      } Bits;
      struct {
        byte grpWUPTB_1 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } B_PCR_WUEHSTR;
    #define B_PCR_WUEH                  _B_PCR_WUE.Overlap_STR.B_PCR_WUEHSTR.Byte
    #define B_PCR_WUEH_WUPTB1           _B_PCR_WUE.Overlap_STR.B_PCR_WUEHSTR.Bits.WUPTB1
    #define B_PCR_WUEH_WUPTB2           _B_PCR_WUE.Overlap_STR.B_PCR_WUEHSTR.Bits.WUPTB2
    #define B_PCR_WUEH_WUPTB3           _B_PCR_WUE.Overlap_STR.B_PCR_WUEHSTR.Bits.WUPTB3
    #define B_PCR_WUEH_WUPTB4           _B_PCR_WUE.Overlap_STR.B_PCR_WUEHSTR.Bits.WUPTB4
    #define B_PCR_WUEH_WULIN            _B_PCR_WUE.Overlap_STR.B_PCR_WUEHSTR.Bits.WULIN
    #define B_PCR_WUEH_WUCAL            _B_PCR_WUE.Overlap_STR.B_PCR_WUEHSTR.Bits.WUCAL
    #define B_PCR_WUEH_WUCTH            _B_PCR_WUE.Overlap_STR.B_PCR_WUEHSTR.Bits.WUCTH
    #define B_PCR_WUEH_WUAHTH           _B_PCR_WUE.Overlap_STR.B_PCR_WUEHSTR.Bits.WUAHTH
    #define B_PCR_WUEH_WUPTB_1          _B_PCR_WUE.Overlap_STR.B_PCR_WUEHSTR.MergedBits.grpWUPTB_1
    #define B_PCR_WUEH_WUPTB            B_PCR_WUEH_WUPTB_1
    
    #define B_PCR_WUEH_WUPTB1_MASK      1U
    #define B_PCR_WUEH_WUPTB2_MASK      2U
    #define B_PCR_WUEH_WUPTB3_MASK      4U
    #define B_PCR_WUEH_WUPTB4_MASK      8U
    #define B_PCR_WUEH_WULIN_MASK       16U
    #define B_PCR_WUEH_WUCAL_MASK       32U
    #define B_PCR_WUEH_WUCTH_MASK       64U
    #define B_PCR_WUEH_WUAHTH_MASK      128U
    #define B_PCR_WUEH_WUPTB_1_MASK     15U
    #define B_PCR_WUEH_WUPTB_1_BITNUM   0U
    

    /*** B_PCR_WUEL - Wake Up Enable Register Low; 0x00000E07 ***/
    union {
      byte Byte;
      struct {
        byte TSDF        :1; 
        byte HTWF        :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte WULTC       :1;                                       /* Wake-up on Life Timer Counter Overflow */
      } Bits;
    } B_PCR_WUELSTR;
    #define B_PCR_WUEL                  _B_PCR_WUE.Overlap_STR.B_PCR_WUELSTR.Byte
    #define B_PCR_WUEL_TSDF             _B_PCR_WUE.Overlap_STR.B_PCR_WUELSTR.Bits.TSDF
    #define B_PCR_WUEL_HTWF             _B_PCR_WUE.Overlap_STR.B_PCR_WUELSTR.Bits.HTWF
    #define B_PCR_WUEL_WULTC            _B_PCR_WUE.Overlap_STR.B_PCR_WUELSTR.Bits.WULTC
    
    #define B_PCR_WUEL_TSDF_MASK        1U
    #define B_PCR_WUEL_HTWF_MASK        2U
    #define B_PCR_WUEL_WULTC_MASK       128U
    
  } Overlap_STR;

  struct {
    word TSDF        :1; 
    word HTWF        :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word WULTC       :1;                                       /* Wake-up on Life Timer Counter Overflow */
    word WUPTB1      :1;                                       /* Wake-up on GPIO 1 event */
    word WUPTB2      :1;                                       /* Wake-up on GPIO 2 event */
    word WUPTB3      :1;                                       /* Wake-up on GPIO 3 event */
    word WUPTB4      :1;                                       /* Wake-up on GPIO 4 event */
    word WULIN       :1;                                       /* Wake-up on LIN */
    word WUCAL       :1;                                       /* Wake-up on calibration request */
    word WUCTH       :1;                                       /* Wake-up on current threshold */
    word WUAHTH      :1;                                       /* Wake-up on Ah counter */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpWUPTB_1 :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} B_PCR_WUESTR;
extern volatile B_PCR_WUESTR _B_PCR_WUE @0x00000E06;
#define B_PCR_WUE                       _B_PCR_WUE.Word
#define B_PCR_WUE_TSDF                  _B_PCR_WUE.Bits.TSDF
#define B_PCR_WUE_HTWF                  _B_PCR_WUE.Bits.HTWF
#define B_PCR_WUE_WULTC                 _B_PCR_WUE.Bits.WULTC
#define B_PCR_WUE_WUPTB1                _B_PCR_WUE.Bits.WUPTB1
#define B_PCR_WUE_WUPTB2                _B_PCR_WUE.Bits.WUPTB2
#define B_PCR_WUE_WUPTB3                _B_PCR_WUE.Bits.WUPTB3
#define B_PCR_WUE_WUPTB4                _B_PCR_WUE.Bits.WUPTB4
#define B_PCR_WUE_WULIN                 _B_PCR_WUE.Bits.WULIN
#define B_PCR_WUE_WUCAL                 _B_PCR_WUE.Bits.WUCAL
#define B_PCR_WUE_WUCTH                 _B_PCR_WUE.Bits.WUCTH
#define B_PCR_WUE_WUAHTH                _B_PCR_WUE.Bits.WUAHTH
#define B_PCR_WUE_WUPTB_1               _B_PCR_WUE.MergedBits.grpWUPTB_1
#define B_PCR_WUE_WUPTB                 B_PCR_WUE_WUPTB_1

#define B_PCR_WUE_TSDF_MASK             1U
#define B_PCR_WUE_HTWF_MASK             2U
#define B_PCR_WUE_WULTC_MASK            128U
#define B_PCR_WUE_WUPTB1_MASK           256U
#define B_PCR_WUE_WUPTB2_MASK           512U
#define B_PCR_WUE_WUPTB3_MASK           1024U
#define B_PCR_WUE_WUPTB4_MASK           2048U
#define B_PCR_WUE_WULIN_MASK            4096U
#define B_PCR_WUE_WUCAL_MASK            8192U
#define B_PCR_WUE_WUCTH_MASK            16384U
#define B_PCR_WUE_WUAHTH_MASK           32768U
#define B_PCR_WUE_WUPTB_1_MASK          3840U
#define B_PCR_WUE_WUPTB_1_BITNUM        8U


/*** B_INT_SRC - Interrupt source register; 0x00000E08 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_INT_SRCH - Interrupt source register high; 0x00000E08 ***/
    union {
      byte Byte;
      struct {
        byte UVI         :1;                                       /* Undervoltage Interrupt pending or wake up from Cranking Mode Status */
        byte HTI         :1;                                       /* High Temperature Interrupt Status */
        byte LFI         :1; 
        byte CH0         :1;                                       /* TIM16B4C - TIM Channel 0 Interrupt Status */
        byte CH1         :1;                                       /* TIM16B4C - TIM Channel 1 Interrupt Status */
        byte CH2         :1;                                       /* TIM16B4C - TIM Channel 2 Interrupt Status */
        byte CH3         :1;                                       /* TIM16B4C - TIM Channel 3 Interrupt Status */
        byte TOV         :1;                                       /* TIM16B4C - Timer Overflow Interrupt Status */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpCH :4;
        byte     :1;
      } MergedBits;
    } B_INT_SRCHSTR;
    #define B_INT_SRCH                  _B_INT_SRC.Overlap_STR.B_INT_SRCHSTR.Byte
    #define B_INT_SRCH_UVI              _B_INT_SRC.Overlap_STR.B_INT_SRCHSTR.Bits.UVI
    #define B_INT_SRCH_HTI              _B_INT_SRC.Overlap_STR.B_INT_SRCHSTR.Bits.HTI
    #define B_INT_SRCH_LFI              _B_INT_SRC.Overlap_STR.B_INT_SRCHSTR.Bits.LFI
    #define B_INT_SRCH_CH0              _B_INT_SRC.Overlap_STR.B_INT_SRCHSTR.Bits.CH0
    #define B_INT_SRCH_CH1              _B_INT_SRC.Overlap_STR.B_INT_SRCHSTR.Bits.CH1
    #define B_INT_SRCH_CH2              _B_INT_SRC.Overlap_STR.B_INT_SRCHSTR.Bits.CH2
    #define B_INT_SRCH_CH3              _B_INT_SRC.Overlap_STR.B_INT_SRCHSTR.Bits.CH3
    #define B_INT_SRCH_TOV              _B_INT_SRC.Overlap_STR.B_INT_SRCHSTR.Bits.TOV
    #define B_INT_SRCH_CH               _B_INT_SRC.Overlap_STR.B_INT_SRCHSTR.MergedBits.grpCH
    
    #define B_INT_SRCH_UVI_MASK         1U
    #define B_INT_SRCH_HTI_MASK         2U
    #define B_INT_SRCH_LFI_MASK         4U
    #define B_INT_SRCH_CH0_MASK         8U
    #define B_INT_SRCH_CH1_MASK         16U
    #define B_INT_SRCH_CH2_MASK         32U
    #define B_INT_SRCH_CH3_MASK         64U
    #define B_INT_SRCH_TOV_MASK         128U
    #define B_INT_SRCH_CH_MASK          120U
    #define B_INT_SRCH_CH_BITNUM        3U
    

    /*** B_INT_SRCL - Interrupt source register low; 0x00000E09 ***/
    union {
      byte Byte;
      struct {
        byte ERR         :1;                                       /* SCI Error Interrupt Status */
        byte TX          :1;                                       /* SCI Transmit Interrupt Status */
        byte RX          :1;                                       /* SCI Receive Interrupt Status */
        byte CVMI        :1;                                       /* Current / Voltage Measurement Interrupt Status */
        byte LTC         :1;                                       /* Life Time Counter Interrupt Status */
        byte CAL         :1;                                       /* Calibration Request Interrupt Status */
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_INT_SRCLSTR;
    #define B_INT_SRCL                  _B_INT_SRC.Overlap_STR.B_INT_SRCLSTR.Byte
    #define B_INT_SRCL_ERR              _B_INT_SRC.Overlap_STR.B_INT_SRCLSTR.Bits.ERR
    #define B_INT_SRCL_TX               _B_INT_SRC.Overlap_STR.B_INT_SRCLSTR.Bits.TX
    #define B_INT_SRCL_RX               _B_INT_SRC.Overlap_STR.B_INT_SRCLSTR.Bits.RX
    #define B_INT_SRCL_CVMI             _B_INT_SRC.Overlap_STR.B_INT_SRCLSTR.Bits.CVMI
    #define B_INT_SRCL_LTC              _B_INT_SRC.Overlap_STR.B_INT_SRCLSTR.Bits.LTC
    #define B_INT_SRCL_CAL              _B_INT_SRC.Overlap_STR.B_INT_SRCLSTR.Bits.CAL
    
    #define B_INT_SRCL_ERR_MASK         1U
    #define B_INT_SRCL_TX_MASK          2U
    #define B_INT_SRCL_RX_MASK          4U
    #define B_INT_SRCL_CVMI_MASK        8U
    #define B_INT_SRCL_LTC_MASK         16U
    #define B_INT_SRCL_CAL_MASK         32U
    
  } Overlap_STR;

  struct {
    word ERR         :1;                                       /* SCI Error Interrupt Status */
    word TX          :1;                                       /* SCI Transmit Interrupt Status */
    word RX          :1;                                       /* SCI Receive Interrupt Status */
    word CVMI        :1;                                       /* Current / Voltage Measurement Interrupt Status */
    word LTC         :1;                                       /* Life Time Counter Interrupt Status */
    word CAL         :1;                                       /* Calibration Request Interrupt Status */
    word             :1; 
    word             :1; 
    word UVI         :1;                                       /* Undervoltage Interrupt pending or wake up from Cranking Mode Status */
    word HTI         :1;                                       /* High Temperature Interrupt Status */
    word LFI         :1; 
    word CH0         :1;                                       /* TIM16B4C - TIM Channel 0 Interrupt Status */
    word CH1         :1;                                       /* TIM16B4C - TIM Channel 1 Interrupt Status */
    word CH2         :1;                                       /* TIM16B4C - TIM Channel 2 Interrupt Status */
    word CH3         :1;                                       /* TIM16B4C - TIM Channel 3 Interrupt Status */
    word TOV         :1;                                       /* TIM16B4C - Timer Overflow Interrupt Status */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpCH   :4;
    word         :1;
  } MergedBits;
} B_INT_SRCSTR;
extern volatile B_INT_SRCSTR _B_INT_SRC @0x00000E08;
#define B_INT_SRC                       _B_INT_SRC.Word
#define B_INT_SRC_ERR                   _B_INT_SRC.Bits.ERR
#define B_INT_SRC_TX                    _B_INT_SRC.Bits.TX
#define B_INT_SRC_RX                    _B_INT_SRC.Bits.RX
#define B_INT_SRC_CVMI                  _B_INT_SRC.Bits.CVMI
#define B_INT_SRC_LTC                   _B_INT_SRC.Bits.LTC
#define B_INT_SRC_CAL                   _B_INT_SRC.Bits.CAL
#define B_INT_SRC_UVI                   _B_INT_SRC.Bits.UVI
#define B_INT_SRC_HTI                   _B_INT_SRC.Bits.HTI
#define B_INT_SRC_LFI                   _B_INT_SRC.Bits.LFI
#define B_INT_SRC_CH0                   _B_INT_SRC.Bits.CH0
#define B_INT_SRC_CH1                   _B_INT_SRC.Bits.CH1
#define B_INT_SRC_CH2                   _B_INT_SRC.Bits.CH2
#define B_INT_SRC_CH3                   _B_INT_SRC.Bits.CH3
#define B_INT_SRC_TOV                   _B_INT_SRC.Bits.TOV
#define B_INT_SRC_CH                    _B_INT_SRC.MergedBits.grpCH

#define B_INT_SRC_ERR_MASK              1U
#define B_INT_SRC_TX_MASK               2U
#define B_INT_SRC_RX_MASK               4U
#define B_INT_SRC_CVMI_MASK             8U
#define B_INT_SRC_LTC_MASK              16U
#define B_INT_SRC_CAL_MASK              32U
#define B_INT_SRC_UVI_MASK              256U
#define B_INT_SRC_HTI_MASK              512U
#define B_INT_SRC_LFI_MASK              1024U
#define B_INT_SRC_CH0_MASK              2048U
#define B_INT_SRC_CH1_MASK              4096U
#define B_INT_SRC_CH2_MASK              8192U
#define B_INT_SRC_CH3_MASK              16384U
#define B_INT_SRC_TOV_MASK              32768U
#define B_INT_SRC_CH_MASK               30720U
#define B_INT_SRC_CH_BITNUM             11U


/*** B_INT_VECT - Interrupt vector register; 0x00000E0A ***/
typedef union {
  byte Byte;
  struct {
    byte IRQ         :4;                                       /* Represents the highest prioritized interrupt pending */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} B_INT_VECTSTR;
extern volatile B_INT_VECTSTR _B_INT_VECT @0x00000E0A;
#define B_INT_VECT                      _B_INT_VECT.Byte
#define B_INT_VECT_IRQ                  _B_INT_VECT.Bits.IRQ

#define B_INT_VECT_IRQ_MASK             15U
#define B_INT_VECT_IRQ_BITNUM           0U


/*** B_INT_MSK - Interrupt mask register; 0x00000E0C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_INT_MSKH - Interrupt mask register high; 0x00000E0C ***/
    union {
      byte Byte;
      struct {
        byte UVIM        :1;                                       /* Undervoltage Interrupt Mask */
        byte HTIM        :1;                                       /* High Temperature Interrupt Mask */
        byte LFIM        :1; 
        byte CH0M        :1;                                       /* Timer Channel 1 Interrupt Mask */
        byte CH1M        :1;                                       /* Timer Channel 1 Interrupt Mask */
        byte CH2M        :1;                                       /* Timer Channel 2 Interrupt Mask */
        byte CH3M        :1;                                       /* Timer Channel 3 Interrupt Mask */
        byte TOVM        :1;                                       /* Timer Overflow Interrupt Mask */
      } Bits;
    } B_INT_MSKHSTR;
    #define B_INT_MSKH                  _B_INT_MSK.Overlap_STR.B_INT_MSKHSTR.Byte
    #define B_INT_MSKH_UVIM             _B_INT_MSK.Overlap_STR.B_INT_MSKHSTR.Bits.UVIM
    #define B_INT_MSKH_HTIM             _B_INT_MSK.Overlap_STR.B_INT_MSKHSTR.Bits.HTIM
    #define B_INT_MSKH_LFIM             _B_INT_MSK.Overlap_STR.B_INT_MSKHSTR.Bits.LFIM
    #define B_INT_MSKH_CH0M             _B_INT_MSK.Overlap_STR.B_INT_MSKHSTR.Bits.CH0M
    #define B_INT_MSKH_CH1M             _B_INT_MSK.Overlap_STR.B_INT_MSKHSTR.Bits.CH1M
    #define B_INT_MSKH_CH2M             _B_INT_MSK.Overlap_STR.B_INT_MSKHSTR.Bits.CH2M
    #define B_INT_MSKH_CH3M             _B_INT_MSK.Overlap_STR.B_INT_MSKHSTR.Bits.CH3M
    #define B_INT_MSKH_TOVM             _B_INT_MSK.Overlap_STR.B_INT_MSKHSTR.Bits.TOVM
    
    #define B_INT_MSKH_UVIM_MASK        1U
    #define B_INT_MSKH_HTIM_MASK        2U
    #define B_INT_MSKH_LFIM_MASK        4U
    #define B_INT_MSKH_CH0M_MASK        8U
    #define B_INT_MSKH_CH1M_MASK        16U
    #define B_INT_MSKH_CH2M_MASK        32U
    #define B_INT_MSKH_CH3M_MASK        64U
    #define B_INT_MSKH_TOVM_MASK        128U
    

    /*** B_INT_MSKL - Interrupt mask register low; 0x00000E0D ***/
    union {
      byte Byte;
      struct {
        byte ERRM        :1;                                       /* SCI Error Interrupt Mask */
        byte TXM         :1;                                       /* SCI Transmit Interrupt Mask */
        byte RXM         :1;                                       /* SCI Receive Interrupt Mask */
        byte CVMM        :1;                                       /* Current / Voltage Measurement Interrupt Mask */
        byte LTCM        :1;                                       /* Life Time Counter Interrupt Mask */
        byte CALM        :1;                                       /* Calibration Request Interrupt Mask */
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_INT_MSKLSTR;
    #define B_INT_MSKL                  _B_INT_MSK.Overlap_STR.B_INT_MSKLSTR.Byte
    #define B_INT_MSKL_ERRM             _B_INT_MSK.Overlap_STR.B_INT_MSKLSTR.Bits.ERRM
    #define B_INT_MSKL_TXM              _B_INT_MSK.Overlap_STR.B_INT_MSKLSTR.Bits.TXM
    #define B_INT_MSKL_RXM              _B_INT_MSK.Overlap_STR.B_INT_MSKLSTR.Bits.RXM
    #define B_INT_MSKL_CVMM             _B_INT_MSK.Overlap_STR.B_INT_MSKLSTR.Bits.CVMM
    #define B_INT_MSKL_LTCM             _B_INT_MSK.Overlap_STR.B_INT_MSKLSTR.Bits.LTCM
    #define B_INT_MSKL_CALM             _B_INT_MSK.Overlap_STR.B_INT_MSKLSTR.Bits.CALM
    
    #define B_INT_MSKL_ERRM_MASK        1U
    #define B_INT_MSKL_TXM_MASK         2U
    #define B_INT_MSKL_RXM_MASK         4U
    #define B_INT_MSKL_CVMM_MASK        8U
    #define B_INT_MSKL_LTCM_MASK        16U
    #define B_INT_MSKL_CALM_MASK        32U
    
  } Overlap_STR;

  struct {
    word ERRM        :1;                                       /* SCI Error Interrupt Mask */
    word TXM         :1;                                       /* SCI Transmit Interrupt Mask */
    word RXM         :1;                                       /* SCI Receive Interrupt Mask */
    word CVMM        :1;                                       /* Current / Voltage Measurement Interrupt Mask */
    word LTCM        :1;                                       /* Life Time Counter Interrupt Mask */
    word CALM        :1;                                       /* Calibration Request Interrupt Mask */
    word             :1; 
    word             :1; 
    word UVIM        :1;                                       /* Undervoltage Interrupt Mask */
    word HTIM        :1;                                       /* High Temperature Interrupt Mask */
    word LFIM        :1; 
    word CH0M        :1;                                       /* Timer Channel 1 Interrupt Mask */
    word CH1M        :1;                                       /* Timer Channel 1 Interrupt Mask */
    word CH2M        :1;                                       /* Timer Channel 2 Interrupt Mask */
    word CH3M        :1;                                       /* Timer Channel 3 Interrupt Mask */
    word TOVM        :1;                                       /* Timer Overflow Interrupt Mask */
  } Bits;
} B_INT_MSKSTR;
extern volatile B_INT_MSKSTR _B_INT_MSK @0x00000E0C;
#define B_INT_MSK                       _B_INT_MSK.Word
#define B_INT_MSK_ERRM                  _B_INT_MSK.Bits.ERRM
#define B_INT_MSK_TXM                   _B_INT_MSK.Bits.TXM
#define B_INT_MSK_RXM                   _B_INT_MSK.Bits.RXM
#define B_INT_MSK_CVMM                  _B_INT_MSK.Bits.CVMM
#define B_INT_MSK_LTCM                  _B_INT_MSK.Bits.LTCM
#define B_INT_MSK_CALM                  _B_INT_MSK.Bits.CALM
#define B_INT_MSK_UVIM                  _B_INT_MSK.Bits.UVIM
#define B_INT_MSK_HTIM                  _B_INT_MSK.Bits.HTIM
#define B_INT_MSK_LFIM                  _B_INT_MSK.Bits.LFIM
#define B_INT_MSK_CH0M                  _B_INT_MSK.Bits.CH0M
#define B_INT_MSK_CH1M                  _B_INT_MSK.Bits.CH1M
#define B_INT_MSK_CH2M                  _B_INT_MSK.Bits.CH2M
#define B_INT_MSK_CH3M                  _B_INT_MSK.Bits.CH3M
#define B_INT_MSK_TOVM                  _B_INT_MSK.Bits.TOVM

#define B_INT_MSK_ERRM_MASK             1U
#define B_INT_MSK_TXM_MASK              2U
#define B_INT_MSK_RXM_MASK              4U
#define B_INT_MSK_CVMM_MASK             8U
#define B_INT_MSK_LTCM_MASK             16U
#define B_INT_MSK_CALM_MASK             32U
#define B_INT_MSK_UVIM_MASK             256U
#define B_INT_MSK_HTIM_MASK             512U
#define B_INT_MSK_LFIM_MASK             1024U
#define B_INT_MSK_CH0M_MASK             2048U
#define B_INT_MSK_CH1M_MASK             4096U
#define B_INT_MSK_CH2M_MASK             8192U
#define B_INT_MSK_CH3M_MASK             16384U
#define B_INT_MSK_TOVM_MASK             32768U


/*** B_TRIM_ALF - Trim for accurate 1ms low freq clock; 0x00000E0E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_TRIM_ALFH - Trim for accurate 1ms low freq clock high; 0x00000E0E ***/
    union {
      byte Byte;
      struct {
        byte APRESC      :5;                                       /* ALFCLK Prescaler 8 */
        byte             :1; 
        byte             :1; 
        byte PRDF        :1;                                       /* ALFCLK Prescaler ready Flag */
      } Bits;
    } B_TRIM_ALFHSTR;
    #define B_TRIM_ALFH                 _B_TRIM_ALF.Overlap_STR.B_TRIM_ALFHSTR.Byte
    #define B_TRIM_ALFH_APRESC          _B_TRIM_ALF.Overlap_STR.B_TRIM_ALFHSTR.Bits.APRESC
    #define B_TRIM_ALFH_PRDF            _B_TRIM_ALF.Overlap_STR.B_TRIM_ALFHSTR.Bits.PRDF
    
    #define B_TRIM_ALFH_APRESC_MASK     31U
    #define B_TRIM_ALFH_APRESC_BITNUM   0U
    #define B_TRIM_ALFH_PRDF_MASK       128U
    

    /*** B_TRIM_ALFL - Trim for accurate 1ms low freq clock low; 0x00000E0F ***/
    union {
      byte Byte;
    } B_TRIM_ALFLSTR;
    #define B_TRIM_ALFL                 _B_TRIM_ALF.Overlap_STR.B_TRIM_ALFLSTR.Byte
    
  } Overlap_STR;

  struct {
    word APRESC      :13;                                      /* ALFCLK Prescaler 0 */
    word             :1; 
    word             :1; 
    word PRDF        :1;                                       /* ALFCLK Prescaler ready Flag */
  } Bits;
} B_TRIM_ALFSTR;
extern volatile B_TRIM_ALFSTR _B_TRIM_ALF @0x00000E0E;
#define B_TRIM_ALF                      _B_TRIM_ALF.Word
#define B_TRIM_ALF_APRESC               _B_TRIM_ALF.Bits.APRESC
#define B_TRIM_ALF_PRDF                 _B_TRIM_ALF.Bits.PRDF

#define B_TRIM_ALF_APRESC_MASK          8191U
#define B_TRIM_ALF_APRESC_BITNUM        0U
#define B_TRIM_ALF_PRDF_MASK            32768U


/*** B_WD_CTL - Watchdog control register; 0x00000E10 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_WD_CTLH - Watchdog control register high; 0x00000E10 ***/
    union {
      byte Byte;
      struct {
        byte WDTOM       :3;                                       /* Watchdog Time Out - Mask */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte WDTSTM      :1;                                       /* Watchdog Test - Mask */
      } Bits;
    } B_WD_CTLHSTR;
    #define B_WD_CTLH                   _B_WD_CTL.Overlap_STR.B_WD_CTLHSTR.Byte
    #define B_WD_CTLH_WDTOM             _B_WD_CTL.Overlap_STR.B_WD_CTLHSTR.Bits.WDTOM
    #define B_WD_CTLH_WDTSTM            _B_WD_CTL.Overlap_STR.B_WD_CTLHSTR.Bits.WDTSTM
    
    #define B_WD_CTLH_WDTOM_MASK        7U
    #define B_WD_CTLH_WDTOM_BITNUM      0U
    #define B_WD_CTLH_WDTSTM_MASK       128U
    

    /*** B_WD_CTLL - Watchdog control register low; 0x00000E11 ***/
    union {
      byte Byte;
      struct {
        byte WDTO        :3;                                       /* Watchdog Time Out Configuration */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte WDTST       :1;                                       /* Watchdog Test */
      } Bits;
    } B_WD_CTLLSTR;
    #define B_WD_CTLL                   _B_WD_CTL.Overlap_STR.B_WD_CTLLSTR.Byte
    #define B_WD_CTLL_WDTO              _B_WD_CTL.Overlap_STR.B_WD_CTLLSTR.Bits.WDTO
    #define B_WD_CTLL_WDTST             _B_WD_CTL.Overlap_STR.B_WD_CTLLSTR.Bits.WDTST
    
    #define B_WD_CTLL_WDTO_MASK         7U
    #define B_WD_CTLL_WDTO_BITNUM       0U
    #define B_WD_CTLL_WDTST_MASK        128U
    
  } Overlap_STR;

  struct {
    word WDTO        :3;                                       /* Watchdog Time Out Configuration */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word WDTST       :1;                                       /* Watchdog Test */
    word WDTOM       :3;                                       /* Watchdog Time Out - Mask */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word WDTSTM      :1;                                       /* Watchdog Test - Mask */
  } Bits;
} B_WD_CTLSTR;
extern volatile B_WD_CTLSTR _B_WD_CTL @0x00000E10;
#define B_WD_CTL                        _B_WD_CTL.Word
#define B_WD_CTL_WDTO                   _B_WD_CTL.Bits.WDTO
#define B_WD_CTL_WDTST                  _B_WD_CTL.Bits.WDTST
#define B_WD_CTL_WDTOM                  _B_WD_CTL.Bits.WDTOM
#define B_WD_CTL_WDTSTM                 _B_WD_CTL.Bits.WDTSTM

#define B_WD_CTL_WDTO_MASK              7U
#define B_WD_CTL_WDTO_BITNUM            0U
#define B_WD_CTL_WDTST_MASK             128U
#define B_WD_CTL_WDTOM_MASK             1792U
#define B_WD_CTL_WDTOM_BITNUM           8U
#define B_WD_CTL_WDTSTM_MASK            32768U


/*** B_WD_SR - Watchdog status register; 0x00000E12 ***/
typedef union {
  byte Byte;
  struct {
    byte WDWO        :1;                                       /* Watchdog Status */
    byte WDOFF       :1;                                       /* Watchdog Window Status */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} B_WD_SRSTR;
extern volatile B_WD_SRSTR _B_WD_SR @0x00000E12;
#define B_WD_SR                         _B_WD_SR.Byte
#define B_WD_SR_WDWO                    _B_WD_SR.Bits.WDWO
#define B_WD_SR_WDOFF                   _B_WD_SR.Bits.WDOFF

#define B_WD_SR_WDWO_MASK               1U
#define B_WD_SR_WDOFF_MASK              2U


/*** B_WD_RR - Watchdog rearm register; 0x00000E14 ***/
typedef union {
  byte Byte;
} B_WD_RRSTR;
extern volatile B_WD_RRSTR _B_WD_RR @0x00000E14;
#define B_WD_RR                         _B_WD_RR.Byte


/*** B_SCIBD - SCI Baud Rate Register; 0x00000E18 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_SCIBDH - SCI Baud Rate Register High; 0x00000E18 ***/
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
    } B_SCIBDHSTR;
    #define B_SCIBDH                    _B_SCIBD.Overlap_STR.B_SCIBDHSTR.Byte
    #define B_SCIBDH_SBR8               _B_SCIBD.Overlap_STR.B_SCIBDHSTR.Bits.SBR8
    #define B_SCIBDH_SBR9               _B_SCIBD.Overlap_STR.B_SCIBDHSTR.Bits.SBR9
    #define B_SCIBDH_SBR10              _B_SCIBD.Overlap_STR.B_SCIBDHSTR.Bits.SBR10
    #define B_SCIBDH_SBR11              _B_SCIBD.Overlap_STR.B_SCIBDHSTR.Bits.SBR11
    #define B_SCIBDH_SBR12              _B_SCIBD.Overlap_STR.B_SCIBDHSTR.Bits.SBR12
    #define B_SCIBDH_RXEDGIE            _B_SCIBD.Overlap_STR.B_SCIBDHSTR.Bits.RXEDGIE
    #define B_SCIBDH_LBKDIE             _B_SCIBD.Overlap_STR.B_SCIBDHSTR.Bits.LBKDIE
    #define B_SCIBDH_SBR_8              _B_SCIBD.Overlap_STR.B_SCIBDHSTR.MergedBits.grpSBR_8
    #define B_SCIBDH_SBR                B_SCIBDH_SBR_8
    
    #define B_SCIBDH_SBR8_MASK          1U
    #define B_SCIBDH_SBR9_MASK          2U
    #define B_SCIBDH_SBR10_MASK         4U
    #define B_SCIBDH_SBR11_MASK         8U
    #define B_SCIBDH_SBR12_MASK         16U
    #define B_SCIBDH_RXEDGIE_MASK       64U
    #define B_SCIBDH_LBKDIE_MASK        128U
    #define B_SCIBDH_SBR_8_MASK         31U
    #define B_SCIBDH_SBR_8_BITNUM       0U
    

    /*** B_SCIBDL - SCI Baud Rate Register Low; 0x00000E19 ***/
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
    } B_SCIBDLSTR;
    #define B_SCIBDL                    _B_SCIBD.Overlap_STR.B_SCIBDLSTR.Byte
    #define B_SCIBDL_SBR0               _B_SCIBD.Overlap_STR.B_SCIBDLSTR.Bits.SBR0
    #define B_SCIBDL_SBR1               _B_SCIBD.Overlap_STR.B_SCIBDLSTR.Bits.SBR1
    #define B_SCIBDL_SBR2               _B_SCIBD.Overlap_STR.B_SCIBDLSTR.Bits.SBR2
    #define B_SCIBDL_SBR3               _B_SCIBD.Overlap_STR.B_SCIBDLSTR.Bits.SBR3
    #define B_SCIBDL_SBR4               _B_SCIBD.Overlap_STR.B_SCIBDLSTR.Bits.SBR4
    #define B_SCIBDL_SBR5               _B_SCIBD.Overlap_STR.B_SCIBDLSTR.Bits.SBR5
    #define B_SCIBDL_SBR6               _B_SCIBD.Overlap_STR.B_SCIBDLSTR.Bits.SBR6
    #define B_SCIBDL_SBR7               _B_SCIBD.Overlap_STR.B_SCIBDLSTR.Bits.SBR7
    
    #define B_SCIBDL_SBR0_MASK          1U
    #define B_SCIBDL_SBR1_MASK          2U
    #define B_SCIBDL_SBR2_MASK          4U
    #define B_SCIBDL_SBR3_MASK          8U
    #define B_SCIBDL_SBR4_MASK          16U
    #define B_SCIBDL_SBR5_MASK          32U
    #define B_SCIBDL_SBR6_MASK          64U
    #define B_SCIBDL_SBR7_MASK          128U
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
    word SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
    word SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
    word SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
    word SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
    word SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
    word SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
    word SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
    word SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
    word SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
    word SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
    word SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
    word SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
    word             :1; 
    word RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
    word LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
  } Bits;
  struct {
    word grpSBR  :13;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} B_SCIBDSTR;
extern volatile B_SCIBDSTR _B_SCIBD @0x00000E18;
#define B_SCIBD                         _B_SCIBD.Word
#define B_SCIBD_SBR0                    _B_SCIBD.Bits.SBR0
#define B_SCIBD_SBR1                    _B_SCIBD.Bits.SBR1
#define B_SCIBD_SBR2                    _B_SCIBD.Bits.SBR2
#define B_SCIBD_SBR3                    _B_SCIBD.Bits.SBR3
#define B_SCIBD_SBR4                    _B_SCIBD.Bits.SBR4
#define B_SCIBD_SBR5                    _B_SCIBD.Bits.SBR5
#define B_SCIBD_SBR6                    _B_SCIBD.Bits.SBR6
#define B_SCIBD_SBR7                    _B_SCIBD.Bits.SBR7
#define B_SCIBD_SBR8                    _B_SCIBD.Bits.SBR8
#define B_SCIBD_SBR9                    _B_SCIBD.Bits.SBR9
#define B_SCIBD_SBR10                   _B_SCIBD.Bits.SBR10
#define B_SCIBD_SBR11                   _B_SCIBD.Bits.SBR11
#define B_SCIBD_SBR12                   _B_SCIBD.Bits.SBR12
#define B_SCIBD_RXEDGIE                 _B_SCIBD.Bits.RXEDGIE
#define B_SCIBD_LBKDIE                  _B_SCIBD.Bits.LBKDIE
#define B_SCIBD_SBR                     _B_SCIBD.MergedBits.grpSBR

#define B_SCIBD_SBR0_MASK               1U
#define B_SCIBD_SBR1_MASK               2U
#define B_SCIBD_SBR2_MASK               4U
#define B_SCIBD_SBR3_MASK               8U
#define B_SCIBD_SBR4_MASK               16U
#define B_SCIBD_SBR5_MASK               32U
#define B_SCIBD_SBR6_MASK               64U
#define B_SCIBD_SBR7_MASK               128U
#define B_SCIBD_SBR8_MASK               256U
#define B_SCIBD_SBR9_MASK               512U
#define B_SCIBD_SBR10_MASK              1024U
#define B_SCIBD_SBR11_MASK              2048U
#define B_SCIBD_SBR12_MASK              4096U
#define B_SCIBD_RXEDGIE_MASK            16384U
#define B_SCIBD_LBKDIE_MASK             32768U
#define B_SCIBD_SBR_MASK                8191U
#define B_SCIBD_SBR_BITNUM              0U


/*** B_SCIC1 - SCI Control Register 1; 0x00000E1A ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte DPD0        :1; 
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte DPD1        :1; 
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} B_SCIC1STR;
extern volatile B_SCIC1STR _B_SCIC1 @0x00000E1A;
#define B_SCIC1                         _B_SCIC1.Byte
#define B_SCIC1_PT                      _B_SCIC1.Bits.PT
#define B_SCIC1_PE                      _B_SCIC1.Bits.PE
#define B_SCIC1_ILT                     _B_SCIC1.Bits.ILT
#define B_SCIC1_DPD0                    _B_SCIC1.Bits.DPD0
#define B_SCIC1_M                       _B_SCIC1.Bits.M
#define B_SCIC1_RSRC                    _B_SCIC1.Bits.RSRC
#define B_SCIC1_DPD1                    _B_SCIC1.Bits.DPD1
#define B_SCIC1_LOOPS                   _B_SCIC1.Bits.LOOPS

#define B_SCIC1_PT_MASK                 1U
#define B_SCIC1_PE_MASK                 2U
#define B_SCIC1_ILT_MASK                4U
#define B_SCIC1_DPD0_MASK               8U
#define B_SCIC1_M_MASK                  16U
#define B_SCIC1_RSRC_MASK               32U
#define B_SCIC1_DPD1_MASK               64U
#define B_SCIC1_LOOPS_MASK              128U


/*** B_SCIC2 - SCI Control Register 2; 0x00000E1B ***/
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
} B_SCIC2STR;
extern volatile B_SCIC2STR _B_SCIC2 @0x00000E1B;
#define B_SCIC2                         _B_SCIC2.Byte
#define B_SCIC2_SBK                     _B_SCIC2.Bits.SBK
#define B_SCIC2_RWU                     _B_SCIC2.Bits.RWU
#define B_SCIC2_RE                      _B_SCIC2.Bits.RE
#define B_SCIC2_TE                      _B_SCIC2.Bits.TE
#define B_SCIC2_ILIE                    _B_SCIC2.Bits.ILIE
#define B_SCIC2_RIE                     _B_SCIC2.Bits.RIE
#define B_SCIC2_TCIE                    _B_SCIC2.Bits.TCIE
#define B_SCIC2_TIE                     _B_SCIC2.Bits.TIE

#define B_SCIC2_SBK_MASK                1U
#define B_SCIC2_RWU_MASK                2U
#define B_SCIC2_RE_MASK                 4U
#define B_SCIC2_TE_MASK                 8U
#define B_SCIC2_ILIE_MASK               16U
#define B_SCIC2_RIE_MASK                32U
#define B_SCIC2_TCIE_MASK               64U
#define B_SCIC2_TIE_MASK                128U


/*** B_SCIS1 - SCI Status Register 1; 0x00000E1C ***/
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
} B_SCIS1STR;
extern volatile B_SCIS1STR _B_SCIS1 @0x00000E1C;
#define B_SCIS1                         _B_SCIS1.Byte
#define B_SCIS1_PF                      _B_SCIS1.Bits.PF
#define B_SCIS1_FE                      _B_SCIS1.Bits.FE
#define B_SCIS1_NF                      _B_SCIS1.Bits.NF
#define B_SCIS1_OR                      _B_SCIS1.Bits.OR
#define B_SCIS1_IDLE                    _B_SCIS1.Bits.IDLE
#define B_SCIS1_RDRF                    _B_SCIS1.Bits.RDRF
#define B_SCIS1_TC                      _B_SCIS1.Bits.TC
#define B_SCIS1_TDRE                    _B_SCIS1.Bits.TDRE

#define B_SCIS1_PF_MASK                 1U
#define B_SCIS1_FE_MASK                 2U
#define B_SCIS1_NF_MASK                 4U
#define B_SCIS1_OR_MASK                 8U
#define B_SCIS1_IDLE_MASK               16U
#define B_SCIS1_RDRF_MASK               32U
#define B_SCIS1_TC_MASK                 64U
#define B_SCIS1_TDRE_MASK               128U


/*** B_SCIS2 - SCI Status Register 2; 0x00000E1D ***/
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
} B_SCIS2STR;
extern volatile B_SCIS2STR _B_SCIS2 @0x00000E1D;
#define B_SCIS2                         _B_SCIS2.Byte
#define B_SCIS2_RAF                     _B_SCIS2.Bits.RAF
#define B_SCIS2_LBKDE                   _B_SCIS2.Bits.LBKDE
#define B_SCIS2_BRK13                   _B_SCIS2.Bits.BRK13
#define B_SCIS2_RWUID                   _B_SCIS2.Bits.RWUID
#define B_SCIS2_RXINV                   _B_SCIS2.Bits.RXINV
#define B_SCIS2_RXEDGIF                 _B_SCIS2.Bits.RXEDGIF
#define B_SCIS2_LBKDIF                  _B_SCIS2.Bits.LBKDIF

#define B_SCIS2_RAF_MASK                1U
#define B_SCIS2_LBKDE_MASK              2U
#define B_SCIS2_BRK13_MASK              4U
#define B_SCIS2_RWUID_MASK              8U
#define B_SCIS2_RXINV_MASK              16U
#define B_SCIS2_RXEDGIF_MASK            64U
#define B_SCIS2_LBKDIF_MASK             128U


/*** B_SCIC3 - SCI Control Register 3; 0x00000E1E ***/
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
} B_SCIC3STR;
extern volatile B_SCIC3STR _B_SCIC3 @0x00000E1E;
#define B_SCIC3                         _B_SCIC3.Byte
#define B_SCIC3_PEIE                    _B_SCIC3.Bits.PEIE
#define B_SCIC3_FEIE                    _B_SCIC3.Bits.FEIE
#define B_SCIC3_NEIE                    _B_SCIC3.Bits.NEIE
#define B_SCIC3_ORIE                    _B_SCIC3.Bits.ORIE
#define B_SCIC3_TXINV                   _B_SCIC3.Bits.TXINV
#define B_SCIC3_TXDIR                   _B_SCIC3.Bits.TXDIR
#define B_SCIC3_T8                      _B_SCIC3.Bits.T8
#define B_SCIC3_R8                      _B_SCIC3.Bits.R8

#define B_SCIC3_PEIE_MASK               1U
#define B_SCIC3_FEIE_MASK               2U
#define B_SCIC3_NEIE_MASK               4U
#define B_SCIC3_ORIE_MASK               8U
#define B_SCIC3_TXINV_MASK              16U
#define B_SCIC3_TXDIR_MASK              32U
#define B_SCIC3_T8_MASK                 64U
#define B_SCIC3_R8_MASK                 128U


/*** B_SCID - SCI Data Register; 0x00000E1F ***/
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
} B_SCIDSTR;
extern volatile B_SCIDSTR _B_SCID @0x00000E1F;
#define B_SCID                          _B_SCID.Byte
#define B_SCID_R0_T0                    _B_SCID.Bits.R0_T0
#define B_SCID_R1_T1                    _B_SCID.Bits.R1_T1
#define B_SCID_R2_T2                    _B_SCID.Bits.R2_T2
#define B_SCID_R3_T3                    _B_SCID.Bits.R3_T3
#define B_SCID_R4_T4                    _B_SCID.Bits.R4_T4
#define B_SCID_R5_T5                    _B_SCID.Bits.R5_T5
#define B_SCID_R6_T6                    _B_SCID.Bits.R6_T6
#define B_SCID_R7_T7                    _B_SCID.Bits.R7_T7

#define B_SCID_R0_T0_MASK               1U
#define B_SCID_R1_T1_MASK               2U
#define B_SCID_R2_T2_MASK               4U
#define B_SCID_R3_T3_MASK               8U
#define B_SCID_R4_T4_MASK               16U
#define B_SCID_R5_T5_MASK               32U
#define B_SCID_R6_T6_MASK               64U
#define B_SCID_R7_T7_MASK               128U


/*** B_TIOS - Timer Input Capture/Output Compare Select; 0x00000E20 ***/
typedef union {
  byte Byte;
  struct {
    byte IOS0        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 0 */
    byte IOS1        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 1 */
    byte IOS2        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 2 */
    byte IOS3        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIOS  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} B_TIOSSTR;
extern volatile B_TIOSSTR _B_TIOS @0x00000E20;
#define B_TIOS                          _B_TIOS.Byte
#define B_TIOS_IOS0                     _B_TIOS.Bits.IOS0
#define B_TIOS_IOS1                     _B_TIOS.Bits.IOS1
#define B_TIOS_IOS2                     _B_TIOS.Bits.IOS2
#define B_TIOS_IOS3                     _B_TIOS.Bits.IOS3
#define B_TIOS_IOS                      _B_TIOS.MergedBits.grpIOS

#define B_TIOS_IOS0_MASK                1U
#define B_TIOS_IOS1_MASK                2U
#define B_TIOS_IOS2_MASK                4U
#define B_TIOS_IOS3_MASK                8U
#define B_TIOS_IOS_MASK                 15U
#define B_TIOS_IOS_BITNUM               0U


/*** B_CFORC - Timer Compare Force Register; 0x00000E21 ***/
typedef union {
  byte Byte;
  struct {
    byte FOC0        :1;                                       /* Force Output Compare Action for Channel 0 */
    byte FOC1        :1;                                       /* Force Output Compare Action for Channel 1 */
    byte FOC2        :1;                                       /* Force Output Compare Action for Channel 2 */
    byte FOC3        :1;                                       /* Force Output Compare Action for Channel 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFOC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} B_CFORCSTR;
extern volatile B_CFORCSTR _B_CFORC @0x00000E21;
#define B_CFORC                         _B_CFORC.Byte
#define B_CFORC_FOC0                    _B_CFORC.Bits.FOC0
#define B_CFORC_FOC1                    _B_CFORC.Bits.FOC1
#define B_CFORC_FOC2                    _B_CFORC.Bits.FOC2
#define B_CFORC_FOC3                    _B_CFORC.Bits.FOC3
#define B_CFORC_FOC                     _B_CFORC.MergedBits.grpFOC

#define B_CFORC_FOC0_MASK               1U
#define B_CFORC_FOC1_MASK               2U
#define B_CFORC_FOC2_MASK               4U
#define B_CFORC_FOC3_MASK               8U
#define B_CFORC_FOC_MASK                15U
#define B_CFORC_FOC_BITNUM              0U


/*** B_OC3M - Output Compare 3 Mask Register; 0x00000E22 ***/
typedef union {
  byte Byte;
  struct {
    byte OC3M0       :1;                                       /* Output Compare 3 Mask Bit 0 */
    byte OC3M1       :1;                                       /* Output Compare 3 Mask Bit 1 */
    byte OC3M2       :1;                                       /* Output Compare 3 Mask Bit 2 */
    byte OC3M3       :1;                                       /* Output Compare 3 Mask Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpOC3M :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} B_OC3MSTR;
extern volatile B_OC3MSTR _B_OC3M @0x00000E22;
#define B_OC3M                          _B_OC3M.Byte
#define B_OC3M_OC3M0                    _B_OC3M.Bits.OC3M0
#define B_OC3M_OC3M1                    _B_OC3M.Bits.OC3M1
#define B_OC3M_OC3M2                    _B_OC3M.Bits.OC3M2
#define B_OC3M_OC3M3                    _B_OC3M.Bits.OC3M3
#define B_OC3M_OC3M                     _B_OC3M.MergedBits.grpOC3M

#define B_OC3M_OC3M0_MASK               1U
#define B_OC3M_OC3M1_MASK               2U
#define B_OC3M_OC3M2_MASK               4U
#define B_OC3M_OC3M3_MASK               8U
#define B_OC3M_OC3M_MASK                15U
#define B_OC3M_OC3M_BITNUM              0U


/*** B_OC3D - Output Compare 3 Data Register; 0x00000E23 ***/
typedef union {
  byte Byte;
  struct {
    byte OC3D0       :1;                                       /* Output Compare 3 Bit 0 */
    byte OC3D1       :1;                                       /* Output Compare 3 Bit 1 */
    byte OC3D2       :1;                                       /* Output Compare 3 Bit 2 */
    byte OC3D3       :1;                                       /* Output Compare 3 Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpOC3D :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} B_OC3DSTR;
extern volatile B_OC3DSTR _B_OC3D @0x00000E23;
#define B_OC3D                          _B_OC3D.Byte
#define B_OC3D_OC3D0                    _B_OC3D.Bits.OC3D0
#define B_OC3D_OC3D1                    _B_OC3D.Bits.OC3D1
#define B_OC3D_OC3D2                    _B_OC3D.Bits.OC3D2
#define B_OC3D_OC3D3                    _B_OC3D.Bits.OC3D3
#define B_OC3D_OC3D                     _B_OC3D.MergedBits.grpOC3D

#define B_OC3D_OC3D0_MASK               1U
#define B_OC3D_OC3D1_MASK               2U
#define B_OC3D_OC3D2_MASK               4U
#define B_OC3D_OC3D3_MASK               8U
#define B_OC3D_OC3D_MASK                15U
#define B_OC3D_OC3D_BITNUM              0U


/*** B_TCNT - Timer Count Register; 0x00000E24 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_TCNTHi - Timer Count Register High; 0x00000E24 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Count Register Bit 8 */
        byte BIT9        :1;                                       /* Timer Count Register Bit 9 */
        byte BIT10       :1;                                       /* Timer Count Register Bit 10 */
        byte BIT11       :1;                                       /* Timer Count Register Bit 11 */
        byte BIT12       :1;                                       /* Timer Count Register Bit 12 */
        byte BIT13       :1;                                       /* Timer Count Register Bit 13 */
        byte BIT14       :1;                                       /* Timer Count Register Bit 14 */
        byte BIT15       :1;                                       /* Timer Count Register Bit 15 */
      } Bits;
    } B_TCNTHiSTR;
    #define B_TCNTHi                    _B_TCNT.Overlap_STR.B_TCNTHiSTR.Byte
    #define B_TCNTHi_BIT8               _B_TCNT.Overlap_STR.B_TCNTHiSTR.Bits.BIT8
    #define B_TCNTHi_BIT9               _B_TCNT.Overlap_STR.B_TCNTHiSTR.Bits.BIT9
    #define B_TCNTHi_BIT10              _B_TCNT.Overlap_STR.B_TCNTHiSTR.Bits.BIT10
    #define B_TCNTHi_BIT11              _B_TCNT.Overlap_STR.B_TCNTHiSTR.Bits.BIT11
    #define B_TCNTHi_BIT12              _B_TCNT.Overlap_STR.B_TCNTHiSTR.Bits.BIT12
    #define B_TCNTHi_BIT13              _B_TCNT.Overlap_STR.B_TCNTHiSTR.Bits.BIT13
    #define B_TCNTHi_BIT14              _B_TCNT.Overlap_STR.B_TCNTHiSTR.Bits.BIT14
    #define B_TCNTHi_BIT15              _B_TCNT.Overlap_STR.B_TCNTHiSTR.Bits.BIT15
    
    #define B_TCNTHi_BIT8_MASK          1U
    #define B_TCNTHi_BIT9_MASK          2U
    #define B_TCNTHi_BIT10_MASK         4U
    #define B_TCNTHi_BIT11_MASK         8U
    #define B_TCNTHi_BIT12_MASK         16U
    #define B_TCNTHi_BIT13_MASK         32U
    #define B_TCNTHi_BIT14_MASK         64U
    #define B_TCNTHi_BIT15_MASK         128U
    

    /*** B_TCNTLo - Timer Count Register Low; 0x00000E25 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Count Register Bit 0 */
        byte BIT1        :1;                                       /* Timer Count Register Bit 1 */
        byte BIT2        :1;                                       /* Timer Count Register Bit 2 */
        byte BIT3        :1;                                       /* Timer Count Register Bit 3 */
        byte BIT4        :1;                                       /* Timer Count Register Bit 4 */
        byte BIT5        :1;                                       /* Timer Count Register Bit 5 */
        byte BIT6        :1;                                       /* Timer Count Register Bit 6 */
        byte BIT7        :1;                                       /* Timer Count Register Bit 7 */
      } Bits;
    } B_TCNTLoSTR;
    #define B_TCNTLo                    _B_TCNT.Overlap_STR.B_TCNTLoSTR.Byte
    #define B_TCNTLo_BIT0               _B_TCNT.Overlap_STR.B_TCNTLoSTR.Bits.BIT0
    #define B_TCNTLo_BIT1               _B_TCNT.Overlap_STR.B_TCNTLoSTR.Bits.BIT1
    #define B_TCNTLo_BIT2               _B_TCNT.Overlap_STR.B_TCNTLoSTR.Bits.BIT2
    #define B_TCNTLo_BIT3               _B_TCNT.Overlap_STR.B_TCNTLoSTR.Bits.BIT3
    #define B_TCNTLo_BIT4               _B_TCNT.Overlap_STR.B_TCNTLoSTR.Bits.BIT4
    #define B_TCNTLo_BIT5               _B_TCNT.Overlap_STR.B_TCNTLoSTR.Bits.BIT5
    #define B_TCNTLo_BIT6               _B_TCNT.Overlap_STR.B_TCNTLoSTR.Bits.BIT6
    #define B_TCNTLo_BIT7               _B_TCNT.Overlap_STR.B_TCNTLoSTR.Bits.BIT7
    
    #define B_TCNTLo_BIT0_MASK          1U
    #define B_TCNTLo_BIT1_MASK          2U
    #define B_TCNTLo_BIT2_MASK          4U
    #define B_TCNTLo_BIT3_MASK          8U
    #define B_TCNTLo_BIT4_MASK          16U
    #define B_TCNTLo_BIT5_MASK          32U
    #define B_TCNTLo_BIT6_MASK          64U
    #define B_TCNTLo_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Timer Count Register Bit 0 */
    word BIT1        :1;                                       /* Timer Count Register Bit 1 */
    word BIT2        :1;                                       /* Timer Count Register Bit 2 */
    word BIT3        :1;                                       /* Timer Count Register Bit 3 */
    word BIT4        :1;                                       /* Timer Count Register Bit 4 */
    word BIT5        :1;                                       /* Timer Count Register Bit 5 */
    word BIT6        :1;                                       /* Timer Count Register Bit 6 */
    word BIT7        :1;                                       /* Timer Count Register Bit 7 */
    word BIT8        :1;                                       /* Timer Count Register Bit 8 */
    word BIT9        :1;                                       /* Timer Count Register Bit 9 */
    word BIT10       :1;                                       /* Timer Count Register Bit 10 */
    word BIT11       :1;                                       /* Timer Count Register Bit 11 */
    word BIT12       :1;                                       /* Timer Count Register Bit 12 */
    word BIT13       :1;                                       /* Timer Count Register Bit 13 */
    word BIT14       :1;                                       /* Timer Count Register Bit 14 */
    word BIT15       :1;                                       /* Timer Count Register Bit 15 */
  } Bits;
} B_TCNTSTR;
extern volatile B_TCNTSTR _B_TCNT @0x00000E24;
#define B_TCNT                          _B_TCNT.Word
#define B_TCNT_BIT0                     _B_TCNT.Bits.BIT0
#define B_TCNT_BIT1                     _B_TCNT.Bits.BIT1
#define B_TCNT_BIT2                     _B_TCNT.Bits.BIT2
#define B_TCNT_BIT3                     _B_TCNT.Bits.BIT3
#define B_TCNT_BIT4                     _B_TCNT.Bits.BIT4
#define B_TCNT_BIT5                     _B_TCNT.Bits.BIT5
#define B_TCNT_BIT6                     _B_TCNT.Bits.BIT6
#define B_TCNT_BIT7                     _B_TCNT.Bits.BIT7
#define B_TCNT_BIT8                     _B_TCNT.Bits.BIT8
#define B_TCNT_BIT9                     _B_TCNT.Bits.BIT9
#define B_TCNT_BIT10                    _B_TCNT.Bits.BIT10
#define B_TCNT_BIT11                    _B_TCNT.Bits.BIT11
#define B_TCNT_BIT12                    _B_TCNT.Bits.BIT12
#define B_TCNT_BIT13                    _B_TCNT.Bits.BIT13
#define B_TCNT_BIT14                    _B_TCNT.Bits.BIT14
#define B_TCNT_BIT15                    _B_TCNT.Bits.BIT15

#define B_TCNT_BIT0_MASK                1U
#define B_TCNT_BIT1_MASK                2U
#define B_TCNT_BIT2_MASK                4U
#define B_TCNT_BIT3_MASK                8U
#define B_TCNT_BIT4_MASK                16U
#define B_TCNT_BIT5_MASK                32U
#define B_TCNT_BIT6_MASK                64U
#define B_TCNT_BIT7_MASK                128U
#define B_TCNT_BIT8_MASK                256U
#define B_TCNT_BIT9_MASK                512U
#define B_TCNT_BIT10_MASK               1024U
#define B_TCNT_BIT11_MASK               2048U
#define B_TCNT_BIT12_MASK               4096U
#define B_TCNT_BIT13_MASK               8192U
#define B_TCNT_BIT14_MASK               16384U
#define B_TCNT_BIT15_MASK               32768U


/*** B_TSCR1 - Timer System Control Register1; 0x00000E26 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TFFCA       :1;                                       /* Timer Fast Flag Clear All */
    byte             :1; 
    byte             :1; 
    byte TEN         :1;                                       /* Timer Enable */
  } Bits;
} B_TSCR1STR;
extern volatile B_TSCR1STR _B_TSCR1 @0x00000E26;
#define B_TSCR1                         _B_TSCR1.Byte
#define B_TSCR1_TFFCA                   _B_TSCR1.Bits.TFFCA
#define B_TSCR1_TEN                     _B_TSCR1.Bits.TEN

#define B_TSCR1_TFFCA_MASK              16U
#define B_TSCR1_TEN_MASK                128U


/*** B_TTOV - Timer Toggle On Overflow Register; 0x00000E27 ***/
typedef union {
  byte Byte;
  struct {
    byte TOV0        :1;                                       /* Toggle On Overflow Bit 0 */
    byte TOV1        :1;                                       /* Toggle On Overflow Bit 1 */
    byte TOV2        :1;                                       /* Toggle On Overflow Bit 2 */
    byte TOV3        :1;                                       /* Toggle On Overflow Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTOV  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} B_TTOVSTR;
extern volatile B_TTOVSTR _B_TTOV @0x00000E27;
#define B_TTOV                          _B_TTOV.Byte
#define B_TTOV_TOV0                     _B_TTOV.Bits.TOV0
#define B_TTOV_TOV1                     _B_TTOV.Bits.TOV1
#define B_TTOV_TOV2                     _B_TTOV.Bits.TOV2
#define B_TTOV_TOV3                     _B_TTOV.Bits.TOV3
#define B_TTOV_TOV                      _B_TTOV.MergedBits.grpTOV

#define B_TTOV_TOV0_MASK                1U
#define B_TTOV_TOV1_MASK                2U
#define B_TTOV_TOV2_MASK                4U
#define B_TTOV_TOV3_MASK                8U
#define B_TTOV_TOV_MASK                 15U
#define B_TTOV_TOV_BITNUM               0U


/*** B_TCTL1 - Timer Control Register 1; 0x00000E28 ***/
typedef union {
  byte Byte;
  struct {
    byte OL0         :1;                                       /* Output Level Bit 0 */
    byte OM0         :1;                                       /* Output Mode Bit 0 */
    byte OL1         :1;                                       /* Output Lecel Bit 1 */
    byte OM1         :1;                                       /* Output Mode Bit 1 */
    byte OL2         :1;                                       /* Output Level Bit 2 */
    byte OM2         :1;                                       /* Output Mode Bit 2 */
    byte OL3         :1;                                       /* Output Level Bit 3 */
    byte OM3         :1;                                       /* Output Mode Bit 3 */
  } Bits;
} B_TCTL1STR;
extern volatile B_TCTL1STR _B_TCTL1 @0x00000E28;
#define B_TCTL1                         _B_TCTL1.Byte
#define B_TCTL1_OL0                     _B_TCTL1.Bits.OL0
#define B_TCTL1_OM0                     _B_TCTL1.Bits.OM0
#define B_TCTL1_OL1                     _B_TCTL1.Bits.OL1
#define B_TCTL1_OM1                     _B_TCTL1.Bits.OM1
#define B_TCTL1_OL2                     _B_TCTL1.Bits.OL2
#define B_TCTL1_OM2                     _B_TCTL1.Bits.OM2
#define B_TCTL1_OL3                     _B_TCTL1.Bits.OL3
#define B_TCTL1_OM3                     _B_TCTL1.Bits.OM3

#define B_TCTL1_OL0_MASK                1U
#define B_TCTL1_OM0_MASK                2U
#define B_TCTL1_OL1_MASK                4U
#define B_TCTL1_OM1_MASK                8U
#define B_TCTL1_OL2_MASK                16U
#define B_TCTL1_OM2_MASK                32U
#define B_TCTL1_OL3_MASK                64U
#define B_TCTL1_OM3_MASK                128U


/*** B_TCTL2 - Timer Control Register 2; 0x00000E29 ***/
typedef union {
  byte Byte;
  struct {
    byte EDG0A       :1;                                       /* Input Capture Edge 0 Control A */
    byte EDG0B       :1;                                       /* Input Capture Edge 0 Control B */
    byte EDG1A       :1;                                       /* Input Capture Edge 1 Control A */
    byte EDG1B       :1;                                       /* Input Capture Edge 1 Control B */
    byte EDG2A       :1;                                       /* Input Capture Edge 2 Control A */
    byte EDG2B       :1;                                       /* Input Capture Edge 2 Control B */
    byte EDG3A       :1;                                       /* Input Capture Edge 3 Control A */
    byte EDG3B       :1;                                       /* Input Capture Edge 3 Control B */
  } Bits;
  struct {
    byte grpEDG0x :2;
    byte grpEDG1x :2;
    byte grpEDG2x :2;
    byte grpEDG3x :2;
  } MergedBits;
} B_TCTL2STR;
extern volatile B_TCTL2STR _B_TCTL2 @0x00000E29;
#define B_TCTL2                         _B_TCTL2.Byte
#define B_TCTL2_EDG0A                   _B_TCTL2.Bits.EDG0A
#define B_TCTL2_EDG0B                   _B_TCTL2.Bits.EDG0B
#define B_TCTL2_EDG1A                   _B_TCTL2.Bits.EDG1A
#define B_TCTL2_EDG1B                   _B_TCTL2.Bits.EDG1B
#define B_TCTL2_EDG2A                   _B_TCTL2.Bits.EDG2A
#define B_TCTL2_EDG2B                   _B_TCTL2.Bits.EDG2B
#define B_TCTL2_EDG3A                   _B_TCTL2.Bits.EDG3A
#define B_TCTL2_EDG3B                   _B_TCTL2.Bits.EDG3B
#define B_TCTL2_EDG0x                   _B_TCTL2.MergedBits.grpEDG0x
#define B_TCTL2_EDG1x                   _B_TCTL2.MergedBits.grpEDG1x
#define B_TCTL2_EDG2x                   _B_TCTL2.MergedBits.grpEDG2x
#define B_TCTL2_EDG3x                   _B_TCTL2.MergedBits.grpEDG3x

#define B_TCTL2_EDG0A_MASK              1U
#define B_TCTL2_EDG0B_MASK              2U
#define B_TCTL2_EDG1A_MASK              4U
#define B_TCTL2_EDG1B_MASK              8U
#define B_TCTL2_EDG2A_MASK              16U
#define B_TCTL2_EDG2B_MASK              32U
#define B_TCTL2_EDG3A_MASK              64U
#define B_TCTL2_EDG3B_MASK              128U
#define B_TCTL2_EDG0x_MASK              3U
#define B_TCTL2_EDG0x_BITNUM            0U
#define B_TCTL2_EDG1x_MASK              12U
#define B_TCTL2_EDG1x_BITNUM            2U
#define B_TCTL2_EDG2x_MASK              48U
#define B_TCTL2_EDG2x_BITNUM            4U
#define B_TCTL2_EDG3x_MASK              192U
#define B_TCTL2_EDG3x_BITNUM            6U


/*** B_TIE - Timer Interrupt Enable Register; 0x00000E2A ***/
typedef union {
  byte Byte;
  struct {
    byte C0I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 0 */
    byte C1I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 1 */
    byte C2I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 2 */
    byte C3I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} B_TIESTR;
extern volatile B_TIESTR _B_TIE @0x00000E2A;
#define B_TIE                           _B_TIE.Byte
#define B_TIE_C0I                       _B_TIE.Bits.C0I
#define B_TIE_C1I                       _B_TIE.Bits.C1I
#define B_TIE_C2I                       _B_TIE.Bits.C2I
#define B_TIE_C3I                       _B_TIE.Bits.C3I

#define B_TIE_C0I_MASK                  1U
#define B_TIE_C1I_MASK                  2U
#define B_TIE_C2I_MASK                  4U
#define B_TIE_C3I_MASK                  8U


/*** B_TSCR2 - Timer System Control Register 2; 0x00000E2B ***/
typedef union {
  byte Byte;
  struct {
    byte PR0         :1;                                       /* Timer Prescaler Select Bit 0 */
    byte PR1         :1;                                       /* Timer Prescaler Select Bit 1 */
    byte PR2         :1;                                       /* Timer Prescaler Select Bit 2 */
    byte TCRE        :1;                                       /* Timer Counter Reset Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOI         :1;                                       /* Timer Overflow Interrupt Enable */
  } Bits;
  struct {
    byte grpPR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} B_TSCR2STR;
extern volatile B_TSCR2STR _B_TSCR2 @0x00000E2B;
#define B_TSCR2                         _B_TSCR2.Byte
#define B_TSCR2_PR0                     _B_TSCR2.Bits.PR0
#define B_TSCR2_PR1                     _B_TSCR2.Bits.PR1
#define B_TSCR2_PR2                     _B_TSCR2.Bits.PR2
#define B_TSCR2_TCRE                    _B_TSCR2.Bits.TCRE
#define B_TSCR2_TOI                     _B_TSCR2.Bits.TOI
#define B_TSCR2_PR                      _B_TSCR2.MergedBits.grpPR

#define B_TSCR2_PR0_MASK                1U
#define B_TSCR2_PR1_MASK                2U
#define B_TSCR2_PR2_MASK                4U
#define B_TSCR2_TCRE_MASK               8U
#define B_TSCR2_TOI_MASK                128U
#define B_TSCR2_PR_MASK                 7U
#define B_TSCR2_PR_BITNUM               0U


/*** B_TFLG1 - Main Timer Interrupt Flag 1; 0x00000E2C ***/
typedef union {
  byte Byte;
  struct {
    byte C0F         :1;                                       /* Input Capture/Output Compare Channel Flag 0 */
    byte C1F         :1;                                       /* Input Capture/Output Compare Channel Flag 1 */
    byte C2F         :1;                                       /* Input Capture/Output Compare Channel Flag 2 */
    byte C3F         :1;                                       /* Input Capture/Output Compare Channel Flag 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} B_TFLG1STR;
extern volatile B_TFLG1STR _B_TFLG1 @0x00000E2C;
#define B_TFLG1                         _B_TFLG1.Byte
#define B_TFLG1_C0F                     _B_TFLG1.Bits.C0F
#define B_TFLG1_C1F                     _B_TFLG1.Bits.C1F
#define B_TFLG1_C2F                     _B_TFLG1.Bits.C2F
#define B_TFLG1_C3F                     _B_TFLG1.Bits.C3F

#define B_TFLG1_C0F_MASK                1U
#define B_TFLG1_C1F_MASK                2U
#define B_TFLG1_C2F_MASK                4U
#define B_TFLG1_C3F_MASK                8U


/*** B_TFLG2 - Main Timer Interrupt Flag 2; 0x00000E2D ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
} B_TFLG2STR;
extern volatile B_TFLG2STR _B_TFLG2 @0x00000E2D;
#define B_TFLG2                         _B_TFLG2.Byte
#define B_TFLG2_TOF                     _B_TFLG2.Bits.TOF

#define B_TFLG2_TOF_MASK                128U


/*** B_TC0 - Timer Input Capture/Output Compare Register 0; 0x00000E2E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_TC0Hi - Timer Input Capture/Output Compare Register 0 High; 0x00000E2E ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 8 */
        byte BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 9 */
        byte BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 10 */
        byte BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 11 */
        byte BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 12 */
        byte BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 13 */
        byte BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 14 */
        byte BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 15 */
      } Bits;
    } B_TC0HiSTR;
    #define B_TC0Hi                     _B_TC0.Overlap_STR.B_TC0HiSTR.Byte
    #define B_TC0Hi_BIT8                _B_TC0.Overlap_STR.B_TC0HiSTR.Bits.BIT8
    #define B_TC0Hi_BIT9                _B_TC0.Overlap_STR.B_TC0HiSTR.Bits.BIT9
    #define B_TC0Hi_BIT10               _B_TC0.Overlap_STR.B_TC0HiSTR.Bits.BIT10
    #define B_TC0Hi_BIT11               _B_TC0.Overlap_STR.B_TC0HiSTR.Bits.BIT11
    #define B_TC0Hi_BIT12               _B_TC0.Overlap_STR.B_TC0HiSTR.Bits.BIT12
    #define B_TC0Hi_BIT13               _B_TC0.Overlap_STR.B_TC0HiSTR.Bits.BIT13
    #define B_TC0Hi_BIT14               _B_TC0.Overlap_STR.B_TC0HiSTR.Bits.BIT14
    #define B_TC0Hi_BIT15               _B_TC0.Overlap_STR.B_TC0HiSTR.Bits.BIT15
    
    #define B_TC0Hi_BIT8_MASK           1U
    #define B_TC0Hi_BIT9_MASK           2U
    #define B_TC0Hi_BIT10_MASK          4U
    #define B_TC0Hi_BIT11_MASK          8U
    #define B_TC0Hi_BIT12_MASK          16U
    #define B_TC0Hi_BIT13_MASK          32U
    #define B_TC0Hi_BIT14_MASK          64U
    #define B_TC0Hi_BIT15_MASK          128U
    

    /*** B_TC0Lo - Timer Input Capture/Output Compare Register 0 Low; 0x00000E2F ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 0 */
        byte BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 1 */
        byte BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 2 */
        byte BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 3 */
        byte BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 4 */
        byte BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 5 */
        byte BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 6 */
        byte BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 7 */
      } Bits;
    } B_TC0LoSTR;
    #define B_TC0Lo                     _B_TC0.Overlap_STR.B_TC0LoSTR.Byte
    #define B_TC0Lo_BIT0                _B_TC0.Overlap_STR.B_TC0LoSTR.Bits.BIT0
    #define B_TC0Lo_BIT1                _B_TC0.Overlap_STR.B_TC0LoSTR.Bits.BIT1
    #define B_TC0Lo_BIT2                _B_TC0.Overlap_STR.B_TC0LoSTR.Bits.BIT2
    #define B_TC0Lo_BIT3                _B_TC0.Overlap_STR.B_TC0LoSTR.Bits.BIT3
    #define B_TC0Lo_BIT4                _B_TC0.Overlap_STR.B_TC0LoSTR.Bits.BIT4
    #define B_TC0Lo_BIT5                _B_TC0.Overlap_STR.B_TC0LoSTR.Bits.BIT5
    #define B_TC0Lo_BIT6                _B_TC0.Overlap_STR.B_TC0LoSTR.Bits.BIT6
    #define B_TC0Lo_BIT7                _B_TC0.Overlap_STR.B_TC0LoSTR.Bits.BIT7
    
    #define B_TC0Lo_BIT0_MASK           1U
    #define B_TC0Lo_BIT1_MASK           2U
    #define B_TC0Lo_BIT2_MASK           4U
    #define B_TC0Lo_BIT3_MASK           8U
    #define B_TC0Lo_BIT4_MASK           16U
    #define B_TC0Lo_BIT5_MASK           32U
    #define B_TC0Lo_BIT6_MASK           64U
    #define B_TC0Lo_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 0 */
    word BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 1 */
    word BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 2 */
    word BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 3 */
    word BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 4 */
    word BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 5 */
    word BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 6 */
    word BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 7 */
    word BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 8 */
    word BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 9 */
    word BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 10 */
    word BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 11 */
    word BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 12 */
    word BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 13 */
    word BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 14 */
    word BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 15 */
  } Bits;
} B_TC0STR;
extern volatile B_TC0STR _B_TC0 @0x00000E2E;
#define B_TC0                           _B_TC0.Word
#define B_TC0_BIT0                      _B_TC0.Bits.BIT0
#define B_TC0_BIT1                      _B_TC0.Bits.BIT1
#define B_TC0_BIT2                      _B_TC0.Bits.BIT2
#define B_TC0_BIT3                      _B_TC0.Bits.BIT3
#define B_TC0_BIT4                      _B_TC0.Bits.BIT4
#define B_TC0_BIT5                      _B_TC0.Bits.BIT5
#define B_TC0_BIT6                      _B_TC0.Bits.BIT6
#define B_TC0_BIT7                      _B_TC0.Bits.BIT7
#define B_TC0_BIT8                      _B_TC0.Bits.BIT8
#define B_TC0_BIT9                      _B_TC0.Bits.BIT9
#define B_TC0_BIT10                     _B_TC0.Bits.BIT10
#define B_TC0_BIT11                     _B_TC0.Bits.BIT11
#define B_TC0_BIT12                     _B_TC0.Bits.BIT12
#define B_TC0_BIT13                     _B_TC0.Bits.BIT13
#define B_TC0_BIT14                     _B_TC0.Bits.BIT14
#define B_TC0_BIT15                     _B_TC0.Bits.BIT15
/* B_TC_ARR: Access 4 B_TCx registers in an array */
#define B_TC_ARR                        ((volatile word *) &B_TC0)

#define B_TC0_BIT0_MASK                 1U
#define B_TC0_BIT1_MASK                 2U
#define B_TC0_BIT2_MASK                 4U
#define B_TC0_BIT3_MASK                 8U
#define B_TC0_BIT4_MASK                 16U
#define B_TC0_BIT5_MASK                 32U
#define B_TC0_BIT6_MASK                 64U
#define B_TC0_BIT7_MASK                 128U
#define B_TC0_BIT8_MASK                 256U
#define B_TC0_BIT9_MASK                 512U
#define B_TC0_BIT10_MASK                1024U
#define B_TC0_BIT11_MASK                2048U
#define B_TC0_BIT12_MASK                4096U
#define B_TC0_BIT13_MASK                8192U
#define B_TC0_BIT14_MASK                16384U
#define B_TC0_BIT15_MASK                32768U


/*** B_TC1 - Timer Input Capture/Output Compare Register 1; 0x00000E30 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_TC1Hi - Timer Input Capture/Output Compare Register 1 High; 0x00000E30 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 8 */
        byte BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 9 */
        byte BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 10 */
        byte BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 11 */
        byte BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 12 */
        byte BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 13 */
        byte BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 14 */
        byte BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 15 */
      } Bits;
    } B_TC1HiSTR;
    #define B_TC1Hi                     _B_TC1.Overlap_STR.B_TC1HiSTR.Byte
    #define B_TC1Hi_BIT8                _B_TC1.Overlap_STR.B_TC1HiSTR.Bits.BIT8
    #define B_TC1Hi_BIT9                _B_TC1.Overlap_STR.B_TC1HiSTR.Bits.BIT9
    #define B_TC1Hi_BIT10               _B_TC1.Overlap_STR.B_TC1HiSTR.Bits.BIT10
    #define B_TC1Hi_BIT11               _B_TC1.Overlap_STR.B_TC1HiSTR.Bits.BIT11
    #define B_TC1Hi_BIT12               _B_TC1.Overlap_STR.B_TC1HiSTR.Bits.BIT12
    #define B_TC1Hi_BIT13               _B_TC1.Overlap_STR.B_TC1HiSTR.Bits.BIT13
    #define B_TC1Hi_BIT14               _B_TC1.Overlap_STR.B_TC1HiSTR.Bits.BIT14
    #define B_TC1Hi_BIT15               _B_TC1.Overlap_STR.B_TC1HiSTR.Bits.BIT15
    
    #define B_TC1Hi_BIT8_MASK           1U
    #define B_TC1Hi_BIT9_MASK           2U
    #define B_TC1Hi_BIT10_MASK          4U
    #define B_TC1Hi_BIT11_MASK          8U
    #define B_TC1Hi_BIT12_MASK          16U
    #define B_TC1Hi_BIT13_MASK          32U
    #define B_TC1Hi_BIT14_MASK          64U
    #define B_TC1Hi_BIT15_MASK          128U
    

    /*** B_TC1Lo - Timer Input Capture/Output Compare Register 1 Low; 0x00000E31 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 0 */
        byte BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 1 */
        byte BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 2 */
        byte BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 3 */
        byte BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 4 */
        byte BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 5 */
        byte BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 6 */
        byte BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 7 */
      } Bits;
    } B_TC1LoSTR;
    #define B_TC1Lo                     _B_TC1.Overlap_STR.B_TC1LoSTR.Byte
    #define B_TC1Lo_BIT0                _B_TC1.Overlap_STR.B_TC1LoSTR.Bits.BIT0
    #define B_TC1Lo_BIT1                _B_TC1.Overlap_STR.B_TC1LoSTR.Bits.BIT1
    #define B_TC1Lo_BIT2                _B_TC1.Overlap_STR.B_TC1LoSTR.Bits.BIT2
    #define B_TC1Lo_BIT3                _B_TC1.Overlap_STR.B_TC1LoSTR.Bits.BIT3
    #define B_TC1Lo_BIT4                _B_TC1.Overlap_STR.B_TC1LoSTR.Bits.BIT4
    #define B_TC1Lo_BIT5                _B_TC1.Overlap_STR.B_TC1LoSTR.Bits.BIT5
    #define B_TC1Lo_BIT6                _B_TC1.Overlap_STR.B_TC1LoSTR.Bits.BIT6
    #define B_TC1Lo_BIT7                _B_TC1.Overlap_STR.B_TC1LoSTR.Bits.BIT7
    
    #define B_TC1Lo_BIT0_MASK           1U
    #define B_TC1Lo_BIT1_MASK           2U
    #define B_TC1Lo_BIT2_MASK           4U
    #define B_TC1Lo_BIT3_MASK           8U
    #define B_TC1Lo_BIT4_MASK           16U
    #define B_TC1Lo_BIT5_MASK           32U
    #define B_TC1Lo_BIT6_MASK           64U
    #define B_TC1Lo_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 0 */
    word BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 1 */
    word BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 2 */
    word BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 3 */
    word BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 4 */
    word BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 5 */
    word BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 6 */
    word BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 7 */
    word BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 8 */
    word BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 9 */
    word BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 10 */
    word BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 11 */
    word BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 12 */
    word BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 13 */
    word BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 14 */
    word BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 15 */
  } Bits;
} B_TC1STR;
extern volatile B_TC1STR _B_TC1 @0x00000E30;
#define B_TC1                           _B_TC1.Word
#define B_TC1_BIT0                      _B_TC1.Bits.BIT0
#define B_TC1_BIT1                      _B_TC1.Bits.BIT1
#define B_TC1_BIT2                      _B_TC1.Bits.BIT2
#define B_TC1_BIT3                      _B_TC1.Bits.BIT3
#define B_TC1_BIT4                      _B_TC1.Bits.BIT4
#define B_TC1_BIT5                      _B_TC1.Bits.BIT5
#define B_TC1_BIT6                      _B_TC1.Bits.BIT6
#define B_TC1_BIT7                      _B_TC1.Bits.BIT7
#define B_TC1_BIT8                      _B_TC1.Bits.BIT8
#define B_TC1_BIT9                      _B_TC1.Bits.BIT9
#define B_TC1_BIT10                     _B_TC1.Bits.BIT10
#define B_TC1_BIT11                     _B_TC1.Bits.BIT11
#define B_TC1_BIT12                     _B_TC1.Bits.BIT12
#define B_TC1_BIT13                     _B_TC1.Bits.BIT13
#define B_TC1_BIT14                     _B_TC1.Bits.BIT14
#define B_TC1_BIT15                     _B_TC1.Bits.BIT15

#define B_TC1_BIT0_MASK                 1U
#define B_TC1_BIT1_MASK                 2U
#define B_TC1_BIT2_MASK                 4U
#define B_TC1_BIT3_MASK                 8U
#define B_TC1_BIT4_MASK                 16U
#define B_TC1_BIT5_MASK                 32U
#define B_TC1_BIT6_MASK                 64U
#define B_TC1_BIT7_MASK                 128U
#define B_TC1_BIT8_MASK                 256U
#define B_TC1_BIT9_MASK                 512U
#define B_TC1_BIT10_MASK                1024U
#define B_TC1_BIT11_MASK                2048U
#define B_TC1_BIT12_MASK                4096U
#define B_TC1_BIT13_MASK                8192U
#define B_TC1_BIT14_MASK                16384U
#define B_TC1_BIT15_MASK                32768U


/*** B_TC2 - Timer Input Capture/Output Compare Register 2; 0x00000E32 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_TC2Hi - Timer Input Capture/Output Compare Register 2 High; 0x00000E32 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 8 */
        byte BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 9 */
        byte BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 10 */
        byte BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 11 */
        byte BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 12 */
        byte BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 13 */
        byte BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 14 */
        byte BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 15 */
      } Bits;
    } B_TC2HiSTR;
    #define B_TC2Hi                     _B_TC2.Overlap_STR.B_TC2HiSTR.Byte
    #define B_TC2Hi_BIT8                _B_TC2.Overlap_STR.B_TC2HiSTR.Bits.BIT8
    #define B_TC2Hi_BIT9                _B_TC2.Overlap_STR.B_TC2HiSTR.Bits.BIT9
    #define B_TC2Hi_BIT10               _B_TC2.Overlap_STR.B_TC2HiSTR.Bits.BIT10
    #define B_TC2Hi_BIT11               _B_TC2.Overlap_STR.B_TC2HiSTR.Bits.BIT11
    #define B_TC2Hi_BIT12               _B_TC2.Overlap_STR.B_TC2HiSTR.Bits.BIT12
    #define B_TC2Hi_BIT13               _B_TC2.Overlap_STR.B_TC2HiSTR.Bits.BIT13
    #define B_TC2Hi_BIT14               _B_TC2.Overlap_STR.B_TC2HiSTR.Bits.BIT14
    #define B_TC2Hi_BIT15               _B_TC2.Overlap_STR.B_TC2HiSTR.Bits.BIT15
    
    #define B_TC2Hi_BIT8_MASK           1U
    #define B_TC2Hi_BIT9_MASK           2U
    #define B_TC2Hi_BIT10_MASK          4U
    #define B_TC2Hi_BIT11_MASK          8U
    #define B_TC2Hi_BIT12_MASK          16U
    #define B_TC2Hi_BIT13_MASK          32U
    #define B_TC2Hi_BIT14_MASK          64U
    #define B_TC2Hi_BIT15_MASK          128U
    

    /*** B_TC2Lo - Timer Input Capture/Output Compare Register 2 Low; 0x00000E33 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 0 */
        byte BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 1 */
        byte BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 2 */
        byte BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 3 */
        byte BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 4 */
        byte BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 5 */
        byte BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 6 */
        byte BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 7 */
      } Bits;
    } B_TC2LoSTR;
    #define B_TC2Lo                     _B_TC2.Overlap_STR.B_TC2LoSTR.Byte
    #define B_TC2Lo_BIT0                _B_TC2.Overlap_STR.B_TC2LoSTR.Bits.BIT0
    #define B_TC2Lo_BIT1                _B_TC2.Overlap_STR.B_TC2LoSTR.Bits.BIT1
    #define B_TC2Lo_BIT2                _B_TC2.Overlap_STR.B_TC2LoSTR.Bits.BIT2
    #define B_TC2Lo_BIT3                _B_TC2.Overlap_STR.B_TC2LoSTR.Bits.BIT3
    #define B_TC2Lo_BIT4                _B_TC2.Overlap_STR.B_TC2LoSTR.Bits.BIT4
    #define B_TC2Lo_BIT5                _B_TC2.Overlap_STR.B_TC2LoSTR.Bits.BIT5
    #define B_TC2Lo_BIT6                _B_TC2.Overlap_STR.B_TC2LoSTR.Bits.BIT6
    #define B_TC2Lo_BIT7                _B_TC2.Overlap_STR.B_TC2LoSTR.Bits.BIT7
    
    #define B_TC2Lo_BIT0_MASK           1U
    #define B_TC2Lo_BIT1_MASK           2U
    #define B_TC2Lo_BIT2_MASK           4U
    #define B_TC2Lo_BIT3_MASK           8U
    #define B_TC2Lo_BIT4_MASK           16U
    #define B_TC2Lo_BIT5_MASK           32U
    #define B_TC2Lo_BIT6_MASK           64U
    #define B_TC2Lo_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 0 */
    word BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 1 */
    word BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 2 */
    word BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 3 */
    word BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 4 */
    word BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 5 */
    word BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 6 */
    word BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 7 */
    word BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 8 */
    word BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 9 */
    word BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 10 */
    word BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 11 */
    word BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 12 */
    word BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 13 */
    word BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 14 */
    word BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 15 */
  } Bits;
} B_TC2STR;
extern volatile B_TC2STR _B_TC2 @0x00000E32;
#define B_TC2                           _B_TC2.Word
#define B_TC2_BIT0                      _B_TC2.Bits.BIT0
#define B_TC2_BIT1                      _B_TC2.Bits.BIT1
#define B_TC2_BIT2                      _B_TC2.Bits.BIT2
#define B_TC2_BIT3                      _B_TC2.Bits.BIT3
#define B_TC2_BIT4                      _B_TC2.Bits.BIT4
#define B_TC2_BIT5                      _B_TC2.Bits.BIT5
#define B_TC2_BIT6                      _B_TC2.Bits.BIT6
#define B_TC2_BIT7                      _B_TC2.Bits.BIT7
#define B_TC2_BIT8                      _B_TC2.Bits.BIT8
#define B_TC2_BIT9                      _B_TC2.Bits.BIT9
#define B_TC2_BIT10                     _B_TC2.Bits.BIT10
#define B_TC2_BIT11                     _B_TC2.Bits.BIT11
#define B_TC2_BIT12                     _B_TC2.Bits.BIT12
#define B_TC2_BIT13                     _B_TC2.Bits.BIT13
#define B_TC2_BIT14                     _B_TC2.Bits.BIT14
#define B_TC2_BIT15                     _B_TC2.Bits.BIT15

#define B_TC2_BIT0_MASK                 1U
#define B_TC2_BIT1_MASK                 2U
#define B_TC2_BIT2_MASK                 4U
#define B_TC2_BIT3_MASK                 8U
#define B_TC2_BIT4_MASK                 16U
#define B_TC2_BIT5_MASK                 32U
#define B_TC2_BIT6_MASK                 64U
#define B_TC2_BIT7_MASK                 128U
#define B_TC2_BIT8_MASK                 256U
#define B_TC2_BIT9_MASK                 512U
#define B_TC2_BIT10_MASK                1024U
#define B_TC2_BIT11_MASK                2048U
#define B_TC2_BIT12_MASK                4096U
#define B_TC2_BIT13_MASK                8192U
#define B_TC2_BIT14_MASK                16384U
#define B_TC2_BIT15_MASK                32768U


/*** B_TC3 - Timer Input Capture/Output Compare Register 3; 0x00000E34 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_TC3Hi - Timer Input Capture/Output Compare Register 3 High; 0x00000E34 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 8 */
        byte BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 9 */
        byte BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 10 */
        byte BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 11 */
        byte BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 12 */
        byte BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 13 */
        byte BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 14 */
        byte BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 15 */
      } Bits;
    } B_TC3HiSTR;
    #define B_TC3Hi                     _B_TC3.Overlap_STR.B_TC3HiSTR.Byte
    #define B_TC3Hi_BIT8                _B_TC3.Overlap_STR.B_TC3HiSTR.Bits.BIT8
    #define B_TC3Hi_BIT9                _B_TC3.Overlap_STR.B_TC3HiSTR.Bits.BIT9
    #define B_TC3Hi_BIT10               _B_TC3.Overlap_STR.B_TC3HiSTR.Bits.BIT10
    #define B_TC3Hi_BIT11               _B_TC3.Overlap_STR.B_TC3HiSTR.Bits.BIT11
    #define B_TC3Hi_BIT12               _B_TC3.Overlap_STR.B_TC3HiSTR.Bits.BIT12
    #define B_TC3Hi_BIT13               _B_TC3.Overlap_STR.B_TC3HiSTR.Bits.BIT13
    #define B_TC3Hi_BIT14               _B_TC3.Overlap_STR.B_TC3HiSTR.Bits.BIT14
    #define B_TC3Hi_BIT15               _B_TC3.Overlap_STR.B_TC3HiSTR.Bits.BIT15
    
    #define B_TC3Hi_BIT8_MASK           1U
    #define B_TC3Hi_BIT9_MASK           2U
    #define B_TC3Hi_BIT10_MASK          4U
    #define B_TC3Hi_BIT11_MASK          8U
    #define B_TC3Hi_BIT12_MASK          16U
    #define B_TC3Hi_BIT13_MASK          32U
    #define B_TC3Hi_BIT14_MASK          64U
    #define B_TC3Hi_BIT15_MASK          128U
    

    /*** B_TC3Lo - Timer Input Capture/Output Compare Register 3 Low; 0x00000E35 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 0 */
        byte BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 1 */
        byte BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 2 */
        byte BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 3 */
        byte BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 4 */
        byte BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 5 */
        byte BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 6 */
        byte BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 7 */
      } Bits;
    } B_TC3LoSTR;
    #define B_TC3Lo                     _B_TC3.Overlap_STR.B_TC3LoSTR.Byte
    #define B_TC3Lo_BIT0                _B_TC3.Overlap_STR.B_TC3LoSTR.Bits.BIT0
    #define B_TC3Lo_BIT1                _B_TC3.Overlap_STR.B_TC3LoSTR.Bits.BIT1
    #define B_TC3Lo_BIT2                _B_TC3.Overlap_STR.B_TC3LoSTR.Bits.BIT2
    #define B_TC3Lo_BIT3                _B_TC3.Overlap_STR.B_TC3LoSTR.Bits.BIT3
    #define B_TC3Lo_BIT4                _B_TC3.Overlap_STR.B_TC3LoSTR.Bits.BIT4
    #define B_TC3Lo_BIT5                _B_TC3.Overlap_STR.B_TC3LoSTR.Bits.BIT5
    #define B_TC3Lo_BIT6                _B_TC3.Overlap_STR.B_TC3LoSTR.Bits.BIT6
    #define B_TC3Lo_BIT7                _B_TC3.Overlap_STR.B_TC3LoSTR.Bits.BIT7
    
    #define B_TC3Lo_BIT0_MASK           1U
    #define B_TC3Lo_BIT1_MASK           2U
    #define B_TC3Lo_BIT2_MASK           4U
    #define B_TC3Lo_BIT3_MASK           8U
    #define B_TC3Lo_BIT4_MASK           16U
    #define B_TC3Lo_BIT5_MASK           32U
    #define B_TC3Lo_BIT6_MASK           64U
    #define B_TC3Lo_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 0 */
    word BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 1 */
    word BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 2 */
    word BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 3 */
    word BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 4 */
    word BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 5 */
    word BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 6 */
    word BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 7 */
    word BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 8 */
    word BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 9 */
    word BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 10 */
    word BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 11 */
    word BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 12 */
    word BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 13 */
    word BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 14 */
    word BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 15 */
  } Bits;
} B_TC3STR;
extern volatile B_TC3STR _B_TC3 @0x00000E34;
#define B_TC3                           _B_TC3.Word
#define B_TC3_BIT0                      _B_TC3.Bits.BIT0
#define B_TC3_BIT1                      _B_TC3.Bits.BIT1
#define B_TC3_BIT2                      _B_TC3.Bits.BIT2
#define B_TC3_BIT3                      _B_TC3.Bits.BIT3
#define B_TC3_BIT4                      _B_TC3.Bits.BIT4
#define B_TC3_BIT5                      _B_TC3.Bits.BIT5
#define B_TC3_BIT6                      _B_TC3.Bits.BIT6
#define B_TC3_BIT7                      _B_TC3.Bits.BIT7
#define B_TC3_BIT8                      _B_TC3.Bits.BIT8
#define B_TC3_BIT9                      _B_TC3.Bits.BIT9
#define B_TC3_BIT10                     _B_TC3.Bits.BIT10
#define B_TC3_BIT11                     _B_TC3.Bits.BIT11
#define B_TC3_BIT12                     _B_TC3.Bits.BIT12
#define B_TC3_BIT13                     _B_TC3.Bits.BIT13
#define B_TC3_BIT14                     _B_TC3.Bits.BIT14
#define B_TC3_BIT15                     _B_TC3.Bits.BIT15

#define B_TC3_BIT0_MASK                 1U
#define B_TC3_BIT1_MASK                 2U
#define B_TC3_BIT2_MASK                 4U
#define B_TC3_BIT3_MASK                 8U
#define B_TC3_BIT4_MASK                 16U
#define B_TC3_BIT5_MASK                 32U
#define B_TC3_BIT6_MASK                 64U
#define B_TC3_BIT7_MASK                 128U
#define B_TC3_BIT8_MASK                 256U
#define B_TC3_BIT9_MASK                 512U
#define B_TC3_BIT10_MASK                1024U
#define B_TC3_BIT11_MASK                2048U
#define B_TC3_BIT12_MASK                4096U
#define B_TC3_BIT13_MASK                8192U
#define B_TC3_BIT14_MASK                16384U
#define B_TC3_BIT15_MASK                32768U


/*** B_LTC_CTL - Life Time Counter control register; 0x00000E38 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LTC_CTLH - Life Time Counter control register high; 0x00000E38 ***/
    union {
      byte Byte;
      struct {
        byte LTCEM       :1;                                       /* Life Time Counter Enable Mask */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte LTCIEM      :1;                                       /* Life Time Counter Interrupt Enable Mask */
      } Bits;
    } B_LTC_CTLHSTR;
    #define B_LTC_CTLH                  _B_LTC_CTL.Overlap_STR.B_LTC_CTLHSTR.Byte
    #define B_LTC_CTLH_LTCEM            _B_LTC_CTL.Overlap_STR.B_LTC_CTLHSTR.Bits.LTCEM
    #define B_LTC_CTLH_LTCIEM           _B_LTC_CTL.Overlap_STR.B_LTC_CTLHSTR.Bits.LTCIEM
    
    #define B_LTC_CTLH_LTCEM_MASK       1U
    #define B_LTC_CTLH_LTCIEM_MASK      128U
    

    /*** B_LTC_CTLL - Life Time Counter control register low; 0x00000E39 ***/
    union {
      byte Byte;
      struct {
        byte LTCE        :1;                                       /* Life Time Counter Enable */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte LTCIE       :1;                                       /* Life Time Counter Interrupt Enable */
      } Bits;
    } B_LTC_CTLLSTR;
    #define B_LTC_CTLL                  _B_LTC_CTL.Overlap_STR.B_LTC_CTLLSTR.Byte
    #define B_LTC_CTLL_LTCE             _B_LTC_CTL.Overlap_STR.B_LTC_CTLLSTR.Bits.LTCE
    #define B_LTC_CTLL_LTCIE            _B_LTC_CTL.Overlap_STR.B_LTC_CTLLSTR.Bits.LTCIE
    
    #define B_LTC_CTLL_LTCE_MASK        1U
    #define B_LTC_CTLL_LTCIE_MASK       128U
    
  } Overlap_STR;

  struct {
    word LTCE        :1;                                       /* Life Time Counter Enable */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word LTCIE       :1;                                       /* Life Time Counter Interrupt Enable */
    word LTCEM       :1;                                       /* Life Time Counter Enable Mask */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word LTCIEM      :1;                                       /* Life Time Counter Interrupt Enable Mask */
  } Bits;
} B_LTC_CTLSTR;
extern volatile B_LTC_CTLSTR _B_LTC_CTL @0x00000E38;
#define B_LTC_CTL                       _B_LTC_CTL.Word
#define B_LTC_CTL_LTCE                  _B_LTC_CTL.Bits.LTCE
#define B_LTC_CTL_LTCIE                 _B_LTC_CTL.Bits.LTCIE
#define B_LTC_CTL_LTCEM                 _B_LTC_CTL.Bits.LTCEM
#define B_LTC_CTL_LTCIEM                _B_LTC_CTL.Bits.LTCIEM

#define B_LTC_CTL_LTCE_MASK             1U
#define B_LTC_CTL_LTCIE_MASK            128U
#define B_LTC_CTL_LTCEM_MASK            256U
#define B_LTC_CTL_LTCIEM_MASK           32768U


/*** B_LTC_SR - Life Time Counter status register; 0x00000E3A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LTCOF       :1;                                       /* Life Time Counter Overflow Flag */
  } Bits;
} B_LTC_SRSTR;
extern volatile B_LTC_SRSTR _B_LTC_SR @0x00000E3A;
#define B_LTC_SR                        _B_LTC_SR.Byte
#define B_LTC_SR_LTCOF                  _B_LTC_SR.Bits.LTCOF

#define B_LTC_SR_LTCOF_MASK             128U


/*** B_LTC_CNT1 - Life Time Counter Register 1; 0x00000E3C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LTC_CNT1H - Life Time Counter Register 1 High; 0x00000E3C ***/
    union {
      byte Byte;
    } B_LTC_CNT1HSTR;
    #define B_LTC_CNT1H                 _B_LTC_CNT1.Overlap_STR.B_LTC_CNT1HSTR.Byte
    

    /*** B_LTC_CNT1L - Life Time Counter Register 1 Low; 0x00000E3D ***/
    union {
      byte Byte;
    } B_LTC_CNT1LSTR;
    #define B_LTC_CNT1L                 _B_LTC_CNT1.Overlap_STR.B_LTC_CNT1LSTR.Byte
    
  } Overlap_STR;

} B_LTC_CNT1STR;
extern volatile B_LTC_CNT1STR _B_LTC_CNT1 @0x00000E3C;
#define B_LTC_CNT1                      _B_LTC_CNT1.Word


/*** B_LTC_CNT0 - Life Time Counter Register 0; 0x00000E3E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LTC_CNT0H - Life Time Counter Register 0 High; 0x00000E3E ***/
    union {
      byte Byte;
    } B_LTC_CNT0HSTR;
    #define B_LTC_CNT0H                 _B_LTC_CNT0.Overlap_STR.B_LTC_CNT0HSTR.Byte
    

    /*** B_LTC_CNT0L - Life Time Counter Register 0 Low; 0x00000E3F ***/
    union {
      byte Byte;
    } B_LTC_CNT0LSTR;
    #define B_LTC_CNT0L                 _B_LTC_CNT0.Overlap_STR.B_LTC_CNT0LSTR.Byte
    
  } Overlap_STR;

} B_LTC_CNT0STR;
extern volatile B_LTC_CNT0STR _B_LTC_CNT0 @0x00000E3E;
#define B_LTC_CNT0                      _B_LTC_CNT0.Word


/*** B_GPIO_CTL - GPIO control register; 0x00000E40 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_GPIO_CTLH - GPIO control register high; 0x00000E40 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte PE1M        :1;                                       /* Port 1 Enable - Mask */
        byte PE2M        :1;                                       /* Port 2 Enable - Mask */
        byte PE3M        :1;                                       /* Port 3 Enable - Mask */
        byte PE4M        :1;                                       /* Port 4 Enable - Mask */
        byte DIR1M       :1;                                       /* Data Direction PTB1 - Mask */
        byte DIR2M       :1;                                       /* Data Direction PTB2 - Mask */
        byte DIR3M       :1;                                       /* Data Direction PTB3 - Mask */
      } Bits;
    } B_GPIO_CTLHSTR;
    #define B_GPIO_CTLH                 _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLHSTR.Byte
    #define B_GPIO_CTLH_PE1M            _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLHSTR.Bits.PE1M
    #define B_GPIO_CTLH_PE2M            _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLHSTR.Bits.PE2M
    #define B_GPIO_CTLH_PE3M            _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLHSTR.Bits.PE3M
    #define B_GPIO_CTLH_PE4M            _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLHSTR.Bits.PE4M
    #define B_GPIO_CTLH_DIR1M           _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLHSTR.Bits.DIR1M
    #define B_GPIO_CTLH_DIR2M           _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLHSTR.Bits.DIR2M
    #define B_GPIO_CTLH_DIR3M           _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLHSTR.Bits.DIR3M
    
    #define B_GPIO_CTLH_PE1M_MASK       2U
    #define B_GPIO_CTLH_PE2M_MASK       4U
    #define B_GPIO_CTLH_PE3M_MASK       8U
    #define B_GPIO_CTLH_PE4M_MASK       16U
    #define B_GPIO_CTLH_DIR1M_MASK      32U
    #define B_GPIO_CTLH_DIR2M_MASK      64U
    #define B_GPIO_CTLH_DIR3M_MASK      128U
    

    /*** B_GPIO_CTLL - GPIO control register low; 0x00000E41 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte PE1         :1;                                       /* Port 1 Enable */
        byte PE2         :1;                                       /* Port 2 Enable */
        byte PE3         :1;                                       /* Port 3 Enable */
        byte PE4         :1;                                       /* Port 4 Enable */
        byte DIR1        :1;                                       /* Data Direction PTB1 */
        byte DIR2        :1;                                       /* Data Direction PTB2 */
        byte DIR3        :1;                                       /* Data Direction PTB3 */
      } Bits;
      struct {
        byte     :1;
        byte grpPE_1 :4;
        byte grpDIR_1 :3;
      } MergedBits;
    } B_GPIO_CTLLSTR;
    #define B_GPIO_CTLL                 _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLLSTR.Byte
    #define B_GPIO_CTLL_PE1             _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLLSTR.Bits.PE1
    #define B_GPIO_CTLL_PE2             _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLLSTR.Bits.PE2
    #define B_GPIO_CTLL_PE3             _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLLSTR.Bits.PE3
    #define B_GPIO_CTLL_PE4             _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLLSTR.Bits.PE4
    #define B_GPIO_CTLL_DIR1            _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLLSTR.Bits.DIR1
    #define B_GPIO_CTLL_DIR2            _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLLSTR.Bits.DIR2
    #define B_GPIO_CTLL_DIR3            _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLLSTR.Bits.DIR3
    #define B_GPIO_CTLL_PE_1            _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLLSTR.MergedBits.grpPE_1
    #define B_GPIO_CTLL_DIR_1           _B_GPIO_CTL.Overlap_STR.B_GPIO_CTLLSTR.MergedBits.grpDIR_1
    #define B_GPIO_CTLL_PE              B_GPIO_CTLL_PE_1
    #define B_GPIO_CTLL_DIR             B_GPIO_CTLL_DIR_1
    
    #define B_GPIO_CTLL_PE1_MASK        2U
    #define B_GPIO_CTLL_PE2_MASK        4U
    #define B_GPIO_CTLL_PE3_MASK        8U
    #define B_GPIO_CTLL_PE4_MASK        16U
    #define B_GPIO_CTLL_DIR1_MASK       32U
    #define B_GPIO_CTLL_DIR2_MASK       64U
    #define B_GPIO_CTLL_DIR3_MASK       128U
    #define B_GPIO_CTLL_PE_1_MASK       30U
    #define B_GPIO_CTLL_PE_1_BITNUM     1U
    #define B_GPIO_CTLL_DIR_1_MASK      224U
    #define B_GPIO_CTLL_DIR_1_BITNUM    5U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word PE1         :1;                                       /* Port 1 Enable */
    word PE2         :1;                                       /* Port 2 Enable */
    word PE3         :1;                                       /* Port 3 Enable */
    word PE4         :1;                                       /* Port 4 Enable */
    word DIR1        :1;                                       /* Data Direction PTB1 */
    word DIR2        :1;                                       /* Data Direction PTB2 */
    word DIR3        :1;                                       /* Data Direction PTB3 */
    word             :1; 
    word PE1M        :1;                                       /* Port 1 Enable - Mask */
    word PE2M        :1;                                       /* Port 2 Enable - Mask */
    word PE3M        :1;                                       /* Port 3 Enable - Mask */
    word PE4M        :1;                                       /* Port 4 Enable - Mask */
    word DIR1M       :1;                                       /* Data Direction PTB1 - Mask */
    word DIR2M       :1;                                       /* Data Direction PTB2 - Mask */
    word DIR3M       :1;                                       /* Data Direction PTB3 - Mask */
  } Bits;
  struct {
    word         :1;
    word grpPE_1 :4;
    word grpDIR_1 :3;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} B_GPIO_CTLSTR;
extern volatile B_GPIO_CTLSTR _B_GPIO_CTL @0x00000E40;
#define B_GPIO_CTL                      _B_GPIO_CTL.Word
#define B_GPIO_CTL_PE1                  _B_GPIO_CTL.Bits.PE1
#define B_GPIO_CTL_PE2                  _B_GPIO_CTL.Bits.PE2
#define B_GPIO_CTL_PE3                  _B_GPIO_CTL.Bits.PE3
#define B_GPIO_CTL_PE4                  _B_GPIO_CTL.Bits.PE4
#define B_GPIO_CTL_DIR1                 _B_GPIO_CTL.Bits.DIR1
#define B_GPIO_CTL_DIR2                 _B_GPIO_CTL.Bits.DIR2
#define B_GPIO_CTL_DIR3                 _B_GPIO_CTL.Bits.DIR3
#define B_GPIO_CTL_PE1M                 _B_GPIO_CTL.Bits.PE1M
#define B_GPIO_CTL_PE2M                 _B_GPIO_CTL.Bits.PE2M
#define B_GPIO_CTL_PE3M                 _B_GPIO_CTL.Bits.PE3M
#define B_GPIO_CTL_PE4M                 _B_GPIO_CTL.Bits.PE4M
#define B_GPIO_CTL_DIR1M                _B_GPIO_CTL.Bits.DIR1M
#define B_GPIO_CTL_DIR2M                _B_GPIO_CTL.Bits.DIR2M
#define B_GPIO_CTL_DIR3M                _B_GPIO_CTL.Bits.DIR3M
#define B_GPIO_CTL_PE_1                 _B_GPIO_CTL.MergedBits.grpPE_1
#define B_GPIO_CTL_DIR_1                _B_GPIO_CTL.MergedBits.grpDIR_1
#define B_GPIO_CTL_PE                   B_GPIO_CTL_PE_1
#define B_GPIO_CTL_DIR                  B_GPIO_CTL_DIR_1

#define B_GPIO_CTL_PE1_MASK             2U
#define B_GPIO_CTL_PE2_MASK             4U
#define B_GPIO_CTL_PE3_MASK             8U
#define B_GPIO_CTL_PE4_MASK             16U
#define B_GPIO_CTL_DIR1_MASK            32U
#define B_GPIO_CTL_DIR2_MASK            64U
#define B_GPIO_CTL_DIR3_MASK            128U
#define B_GPIO_CTL_PE1M_MASK            512U
#define B_GPIO_CTL_PE2M_MASK            1024U
#define B_GPIO_CTL_PE3M_MASK            2048U
#define B_GPIO_CTL_PE4M_MASK            4096U
#define B_GPIO_CTL_DIR1M_MASK           8192U
#define B_GPIO_CTL_DIR2M_MASK           16384U
#define B_GPIO_CTL_DIR3M_MASK           32768U
#define B_GPIO_CTL_PE_1_MASK            30U
#define B_GPIO_CTL_PE_1_BITNUM          1U
#define B_GPIO_CTL_DIR_1_MASK           224U
#define B_GPIO_CTL_DIR_1_BITNUM         5U


/*** B_GPIO_PUC - GPIO pull up configuration; 0x00000E42 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte PUE1        :1;                                       /* PTB1 Pull Up Enable */
    byte PUE2        :1;                                       /* PTB2 Pull Up Enable */
    byte PUE3        :1;                                       /* PTB3 Pull Up Enable */
    byte PDE4        :1;                                       /* PTB4 Pull Down Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte grpPUE_1 :3;
    byte grpPDE_4 :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} B_GPIO_PUCSTR;
extern volatile B_GPIO_PUCSTR _B_GPIO_PUC @0x00000E42;
#define B_GPIO_PUC                      _B_GPIO_PUC.Byte
#define B_GPIO_PUC_PUE1                 _B_GPIO_PUC.Bits.PUE1
#define B_GPIO_PUC_PUE2                 _B_GPIO_PUC.Bits.PUE2
#define B_GPIO_PUC_PUE3                 _B_GPIO_PUC.Bits.PUE3
#define B_GPIO_PUC_PDE4                 _B_GPIO_PUC.Bits.PDE4
#define B_GPIO_PUC_PUE_1                _B_GPIO_PUC.MergedBits.grpPUE_1
#define B_GPIO_PUC_PUE                  B_GPIO_PUC_PUE_1

#define B_GPIO_PUC_PUE1_MASK            2U
#define B_GPIO_PUC_PUE2_MASK            4U
#define B_GPIO_PUC_PUE3_MASK            8U
#define B_GPIO_PUC_PDE4_MASK            16U
#define B_GPIO_PUC_PUE_1_MASK           14U
#define B_GPIO_PUC_PUE_1_BITNUM         1U


/*** B_GPIO_DATA - GPIO port data register; 0x00000E43 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte PD1         :1;                                       /* PTB1 Data Register */
    byte PD2         :1;                                       /* PTB2 Data Register */
    byte PD3         :1;                                       /* PTB3 Data Register */
    byte PD4         :1;                                       /* PTB4 Data Register */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte grpPD_1 :4;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} B_GPIO_DATASTR;
extern volatile B_GPIO_DATASTR _B_GPIO_DATA @0x00000E43;
#define B_GPIO_DATA                     _B_GPIO_DATA.Byte
#define B_GPIO_DATA_PD1                 _B_GPIO_DATA.Bits.PD1
#define B_GPIO_DATA_PD2                 _B_GPIO_DATA.Bits.PD2
#define B_GPIO_DATA_PD3                 _B_GPIO_DATA.Bits.PD3
#define B_GPIO_DATA_PD4                 _B_GPIO_DATA.Bits.PD4
#define B_GPIO_DATA_PD_1                _B_GPIO_DATA.MergedBits.grpPD_1
#define B_GPIO_DATA_PD                  B_GPIO_DATA_PD_1

#define B_GPIO_DATA_PD1_MASK            2U
#define B_GPIO_DATA_PD2_MASK            4U
#define B_GPIO_DATA_PD3_MASK            8U
#define B_GPIO_DATA_PD4_MASK            16U
#define B_GPIO_DATA_PD_1_MASK           30U
#define B_GPIO_DATA_PD_1_BITNUM         1U


/*** B_GPIO_IN1 - Port 1 input configuration; 0x00000E44 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LINTX       :1;                                       /* PTB1 - LIN Module Tx Input */
    byte SCIRX       :1;                                       /* PTB1 - SCI Module Rx Input */
    byte TCAP0       :1;                                       /* PTB1 - Timer Input Capture Channel 0 */
    byte TCAP1       :1;                                       /* PTB1 - Timer Input Capture Channel 1 */
    byte TCAP2       :1;                                       /* PTB1 - Timer Input Capture Channel 2 */
    byte TCAP3       :1;                                       /* PTB1 - Timer Input Capture Channel 3 */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTCAP :4;
    byte         :1;
  } MergedBits;
} B_GPIO_IN1STR;
extern volatile B_GPIO_IN1STR _B_GPIO_IN1 @0x00000E44;
#define B_GPIO_IN1                      _B_GPIO_IN1.Byte
#define B_GPIO_IN1_LINTX                _B_GPIO_IN1.Bits.LINTX
#define B_GPIO_IN1_SCIRX                _B_GPIO_IN1.Bits.SCIRX
#define B_GPIO_IN1_TCAP0                _B_GPIO_IN1.Bits.TCAP0
#define B_GPIO_IN1_TCAP1                _B_GPIO_IN1.Bits.TCAP1
#define B_GPIO_IN1_TCAP2                _B_GPIO_IN1.Bits.TCAP2
#define B_GPIO_IN1_TCAP3                _B_GPIO_IN1.Bits.TCAP3
#define B_GPIO_IN1_TCAP                 _B_GPIO_IN1.MergedBits.grpTCAP

#define B_GPIO_IN1_LINTX_MASK           2U
#define B_GPIO_IN1_SCIRX_MASK           4U
#define B_GPIO_IN1_TCAP0_MASK           8U
#define B_GPIO_IN1_TCAP1_MASK           16U
#define B_GPIO_IN1_TCAP2_MASK           32U
#define B_GPIO_IN1_TCAP3_MASK           64U
#define B_GPIO_IN1_TCAP_MASK            120U
#define B_GPIO_IN1_TCAP_BITNUM          3U


/*** B_GPIO_OUT1 - Port 1 output configuration; 0x00000E45 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBX1       :1;                                       /* PTB1 - Output Buffer Control */
    byte LINRX       :1;                                       /* PTB1 - LIN RX Output */
    byte SCITX       :1;                                       /* PTB1 - SCI TX Output */
    byte TCOMP0      :1;                                       /* PTB1 - Timer Channel 0 - Output Compare output */
    byte TCOMP1      :1;                                       /* PTB1 - Timer Channel 1 - Output Compare output */
    byte TCOMP2      :1;                                       /* PTB1 - Timer Channel 2 - Output Compare output */
    byte TCOMP3      :1;                                       /* PTB1 - Timer Channel 3 - Output Compare output */
    byte WKUP        :1;                                       /* PTB1 - Wake Up output */
  } Bits;
  struct {
    byte grpPTBX_1 :1;
    byte         :1;
    byte         :1;
    byte grpTCOMP :4;
    byte         :1;
  } MergedBits;
} B_GPIO_OUT1STR;
extern volatile B_GPIO_OUT1STR _B_GPIO_OUT1 @0x00000E45;
#define B_GPIO_OUT1                     _B_GPIO_OUT1.Byte
#define B_GPIO_OUT1_PTBX1               _B_GPIO_OUT1.Bits.PTBX1
#define B_GPIO_OUT1_LINRX               _B_GPIO_OUT1.Bits.LINRX
#define B_GPIO_OUT1_SCITX               _B_GPIO_OUT1.Bits.SCITX
#define B_GPIO_OUT1_TCOMP0              _B_GPIO_OUT1.Bits.TCOMP0
#define B_GPIO_OUT1_TCOMP1              _B_GPIO_OUT1.Bits.TCOMP1
#define B_GPIO_OUT1_TCOMP2              _B_GPIO_OUT1.Bits.TCOMP2
#define B_GPIO_OUT1_TCOMP3              _B_GPIO_OUT1.Bits.TCOMP3
#define B_GPIO_OUT1_WKUP                _B_GPIO_OUT1.Bits.WKUP
#define B_GPIO_OUT1_TCOMP               _B_GPIO_OUT1.MergedBits.grpTCOMP

#define B_GPIO_OUT1_PTBX1_MASK          1U
#define B_GPIO_OUT1_LINRX_MASK          2U
#define B_GPIO_OUT1_SCITX_MASK          4U
#define B_GPIO_OUT1_TCOMP0_MASK         8U
#define B_GPIO_OUT1_TCOMP1_MASK         16U
#define B_GPIO_OUT1_TCOMP2_MASK         32U
#define B_GPIO_OUT1_TCOMP3_MASK         64U
#define B_GPIO_OUT1_WKUP_MASK           128U
#define B_GPIO_OUT1_TCOMP_MASK          120U
#define B_GPIO_OUT1_TCOMP_BITNUM        3U


/*** B_GPIO_IN2 - Port 2 input configuration; 0x00000E46 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LINTX       :1;                                       /* PTB2 - LIN Module Tx Input */
    byte SCIRX       :1;                                       /* PTB2 - SCI Module Rx Input */
    byte TCAP0       :1;                                       /* PTB2 - Timer Input Capture Channel 0 */
    byte TCAP1       :1;                                       /* PTB2 - Timer Input Capture Channel 1 */
    byte TCAP2       :1;                                       /* PTB2 - Timer Input Capture Channel 2 */
    byte TCAP3       :1;                                       /* PTB2 - Timer Input Capture Channel 3 */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTCAP :4;
    byte         :1;
  } MergedBits;
} B_GPIO_IN2STR;
extern volatile B_GPIO_IN2STR _B_GPIO_IN2 @0x00000E46;
#define B_GPIO_IN2                      _B_GPIO_IN2.Byte
#define B_GPIO_IN2_LINTX                _B_GPIO_IN2.Bits.LINTX
#define B_GPIO_IN2_SCIRX                _B_GPIO_IN2.Bits.SCIRX
#define B_GPIO_IN2_TCAP0                _B_GPIO_IN2.Bits.TCAP0
#define B_GPIO_IN2_TCAP1                _B_GPIO_IN2.Bits.TCAP1
#define B_GPIO_IN2_TCAP2                _B_GPIO_IN2.Bits.TCAP2
#define B_GPIO_IN2_TCAP3                _B_GPIO_IN2.Bits.TCAP3
#define B_GPIO_IN2_TCAP                 _B_GPIO_IN2.MergedBits.grpTCAP

#define B_GPIO_IN2_LINTX_MASK           2U
#define B_GPIO_IN2_SCIRX_MASK           4U
#define B_GPIO_IN2_TCAP0_MASK           8U
#define B_GPIO_IN2_TCAP1_MASK           16U
#define B_GPIO_IN2_TCAP2_MASK           32U
#define B_GPIO_IN2_TCAP3_MASK           64U
#define B_GPIO_IN2_TCAP_MASK            120U
#define B_GPIO_IN2_TCAP_BITNUM          3U


/*** B_GPIO_OUT2 - Port 2 output configuration; 0x00000E47 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBX2       :1;                                       /* PTB2 - Output Buffer Control */
    byte LINRX       :1;                                       /* PTB2 - LIN RX Output */
    byte SCITX       :1;                                       /* PTB2 - SCI TX Output */
    byte TCOMP0      :1;                                       /* PTB2 - Timer Channel 0 - Output Compare output */
    byte TCOMP1      :1;                                       /* PTB2 - Timer Channel 1 - Output Compare output */
    byte TCOMP2      :1;                                       /* PTB2 - Timer Channel 2 - Output Compare output */
    byte TCOMP3      :1;                                       /* PTB2 - Timer Channel 3 - Output Compare output */
    byte WKUP        :1;                                       /* PTB2 - Wake Up output */
  } Bits;
  struct {
    byte grpPTBX_2 :1;
    byte         :1;
    byte         :1;
    byte grpTCOMP :4;
    byte         :1;
  } MergedBits;
} B_GPIO_OUT2STR;
extern volatile B_GPIO_OUT2STR _B_GPIO_OUT2 @0x00000E47;
#define B_GPIO_OUT2                     _B_GPIO_OUT2.Byte
#define B_GPIO_OUT2_PTBX2               _B_GPIO_OUT2.Bits.PTBX2
#define B_GPIO_OUT2_LINRX               _B_GPIO_OUT2.Bits.LINRX
#define B_GPIO_OUT2_SCITX               _B_GPIO_OUT2.Bits.SCITX
#define B_GPIO_OUT2_TCOMP0              _B_GPIO_OUT2.Bits.TCOMP0
#define B_GPIO_OUT2_TCOMP1              _B_GPIO_OUT2.Bits.TCOMP1
#define B_GPIO_OUT2_TCOMP2              _B_GPIO_OUT2.Bits.TCOMP2
#define B_GPIO_OUT2_TCOMP3              _B_GPIO_OUT2.Bits.TCOMP3
#define B_GPIO_OUT2_WKUP                _B_GPIO_OUT2.Bits.WKUP
#define B_GPIO_OUT2_TCOMP               _B_GPIO_OUT2.MergedBits.grpTCOMP

#define B_GPIO_OUT2_PTBX2_MASK          1U
#define B_GPIO_OUT2_LINRX_MASK          2U
#define B_GPIO_OUT2_SCITX_MASK          4U
#define B_GPIO_OUT2_TCOMP0_MASK         8U
#define B_GPIO_OUT2_TCOMP1_MASK         16U
#define B_GPIO_OUT2_TCOMP2_MASK         32U
#define B_GPIO_OUT2_TCOMP3_MASK         64U
#define B_GPIO_OUT2_WKUP_MASK           128U
#define B_GPIO_OUT2_TCOMP_MASK          120U
#define B_GPIO_OUT2_TCOMP_BITNUM        3U


/*** B_GPIO_IN3 - Port 3 input configuration; 0x00000E48 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LINTX       :1;                                       /* PTB3 - LIN Module Tx Input */
    byte SCIRX       :1;                                       /* PTB3 - SCI Module Rx Input */
    byte TCAP0       :1;                                       /* PTB3 - Timer Input Capture Channel 0 */
    byte TCAP1       :1;                                       /* PTB3 - Timer Input Capture Channel 1 */
    byte TCAP2       :1;                                       /* PTB3 - Timer Input Capture Channel 2 */
    byte TCAP3       :1;                                       /* PTB3 - Timer Input Capture Channel 3 */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTCAP :4;
    byte         :1;
  } MergedBits;
} B_GPIO_IN3STR;
extern volatile B_GPIO_IN3STR _B_GPIO_IN3 @0x00000E48;
#define B_GPIO_IN3                      _B_GPIO_IN3.Byte
#define B_GPIO_IN3_LINTX                _B_GPIO_IN3.Bits.LINTX
#define B_GPIO_IN3_SCIRX                _B_GPIO_IN3.Bits.SCIRX
#define B_GPIO_IN3_TCAP0                _B_GPIO_IN3.Bits.TCAP0
#define B_GPIO_IN3_TCAP1                _B_GPIO_IN3.Bits.TCAP1
#define B_GPIO_IN3_TCAP2                _B_GPIO_IN3.Bits.TCAP2
#define B_GPIO_IN3_TCAP3                _B_GPIO_IN3.Bits.TCAP3
#define B_GPIO_IN3_TCAP                 _B_GPIO_IN3.MergedBits.grpTCAP

#define B_GPIO_IN3_LINTX_MASK           2U
#define B_GPIO_IN3_SCIRX_MASK           4U
#define B_GPIO_IN3_TCAP0_MASK           8U
#define B_GPIO_IN3_TCAP1_MASK           16U
#define B_GPIO_IN3_TCAP2_MASK           32U
#define B_GPIO_IN3_TCAP3_MASK           64U
#define B_GPIO_IN3_TCAP_MASK            120U
#define B_GPIO_IN3_TCAP_BITNUM          3U


/*** B_GPIO_OUT3 - Port 3 output configuration; 0x00000E49 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBX3       :1;                                       /* PTB3 - Output Buffer Control */
    byte LINRX       :1;                                       /* PTB3 - LIN RX Output */
    byte SCITX       :1;                                       /* PTB3 - SCI TX Output */
    byte TCOMP0      :1;                                       /* PTB3 - Timer Channel 0 - Output Compare output */
    byte TCOMP1      :1;                                       /* PTB3 - Timer Channel 1 - Output Compare output */
    byte TCOMP2      :1;                                       /* PTB3 - Timer Channel 2 - Output Compare output */
    byte TCOMP3      :1;                                       /* PTB3 - Timer Channel 3 - Output Compare output */
    byte WKUP        :1;                                       /* PTB3 - Wake Up output */
  } Bits;
  struct {
    byte grpPTBX_3 :1;
    byte         :1;
    byte         :1;
    byte grpTCOMP :4;
    byte         :1;
  } MergedBits;
} B_GPIO_OUT3STR;
extern volatile B_GPIO_OUT3STR _B_GPIO_OUT3 @0x00000E49;
#define B_GPIO_OUT3                     _B_GPIO_OUT3.Byte
#define B_GPIO_OUT3_PTBX3               _B_GPIO_OUT3.Bits.PTBX3
#define B_GPIO_OUT3_LINRX               _B_GPIO_OUT3.Bits.LINRX
#define B_GPIO_OUT3_SCITX               _B_GPIO_OUT3.Bits.SCITX
#define B_GPIO_OUT3_TCOMP0              _B_GPIO_OUT3.Bits.TCOMP0
#define B_GPIO_OUT3_TCOMP1              _B_GPIO_OUT3.Bits.TCOMP1
#define B_GPIO_OUT3_TCOMP2              _B_GPIO_OUT3.Bits.TCOMP2
#define B_GPIO_OUT3_TCOMP3              _B_GPIO_OUT3.Bits.TCOMP3
#define B_GPIO_OUT3_WKUP                _B_GPIO_OUT3.Bits.WKUP
#define B_GPIO_OUT3_TCOMP               _B_GPIO_OUT3.MergedBits.grpTCOMP

#define B_GPIO_OUT3_PTBX3_MASK          1U
#define B_GPIO_OUT3_LINRX_MASK          2U
#define B_GPIO_OUT3_SCITX_MASK          4U
#define B_GPIO_OUT3_TCOMP0_MASK         8U
#define B_GPIO_OUT3_TCOMP1_MASK         16U
#define B_GPIO_OUT3_TCOMP2_MASK         32U
#define B_GPIO_OUT3_TCOMP3_MASK         64U
#define B_GPIO_OUT3_WKUP_MASK           128U
#define B_GPIO_OUT3_TCOMP_MASK          120U
#define B_GPIO_OUT3_TCOMP_BITNUM        3U


/*** B_GPIO_IN4 - Port 4 input configuration; 0x00000E4A ***/
typedef union {
  byte Byte;
  struct {
    byte NWUE        :1; 
    byte NWUS        :1; 
    byte             :1; 
    byte TCAP0       :1;                                       /* PTB3 - Timer Input Capture Channel 0 */
    byte TCAP1       :1;                                       /* PTB3 - Timer Input Capture Channel 1 */
    byte TCAP2       :1;                                       /* PTB3 - Timer Input Capture Channel 2 */
    byte TCAP3       :1;                                       /* PTB3 - Timer Input Capture Channel 3 */
    byte PTWU        :1;                                       /* PTB3 Wake Up */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTCAP :4;
    byte         :1;
  } MergedBits;
} B_GPIO_IN4STR;
extern volatile B_GPIO_IN4STR _B_GPIO_IN4 @0x00000E4A;
#define B_GPIO_IN4                      _B_GPIO_IN4.Byte
#define B_GPIO_IN4_NWUE                 _B_GPIO_IN4.Bits.NWUE
#define B_GPIO_IN4_NWUS                 _B_GPIO_IN4.Bits.NWUS
#define B_GPIO_IN4_TCAP0                _B_GPIO_IN4.Bits.TCAP0
#define B_GPIO_IN4_TCAP1                _B_GPIO_IN4.Bits.TCAP1
#define B_GPIO_IN4_TCAP2                _B_GPIO_IN4.Bits.TCAP2
#define B_GPIO_IN4_TCAP3                _B_GPIO_IN4.Bits.TCAP3
#define B_GPIO_IN4_PTWU                 _B_GPIO_IN4.Bits.PTWU
#define B_GPIO_IN4_TCAP                 _B_GPIO_IN4.MergedBits.grpTCAP

#define B_GPIO_IN4_NWUE_MASK            1U
#define B_GPIO_IN4_NWUS_MASK            2U
#define B_GPIO_IN4_TCAP0_MASK           8U
#define B_GPIO_IN4_TCAP1_MASK           16U
#define B_GPIO_IN4_TCAP2_MASK           32U
#define B_GPIO_IN4_TCAP3_MASK           64U
#define B_GPIO_IN4_PTWU_MASK            128U
#define B_GPIO_IN4_TCAP_MASK            120U
#define B_GPIO_IN4_TCAP_BITNUM          3U


/*** B_GPIO_VSENSE - GPIO Vsense Configuration; 0x00000E4B ***/
typedef union {
  byte Byte;
  struct {
    byte VSE0        :1; 
    byte VSE1        :1; 
    byte VSE2        :1; 
    byte VSE3        :1; 
    byte VSE4        :1; 
    byte             :1; 
    byte VSSEL       :2; 
  } Bits;
  struct {
    byte grpVSE  :5;
    byte         :1;
    byte         :2;
  } MergedBits;
} B_GPIO_VSENSESTR;
extern volatile B_GPIO_VSENSESTR _B_GPIO_VSENSE @0x00000E4B;
#define B_GPIO_VSENSE                   _B_GPIO_VSENSE.Byte
#define B_GPIO_VSENSE_VSE0              _B_GPIO_VSENSE.Bits.VSE0
#define B_GPIO_VSENSE_VSE1              _B_GPIO_VSENSE.Bits.VSE1
#define B_GPIO_VSENSE_VSE2              _B_GPIO_VSENSE.Bits.VSE2
#define B_GPIO_VSENSE_VSE3              _B_GPIO_VSENSE.Bits.VSE3
#define B_GPIO_VSENSE_VSE4              _B_GPIO_VSENSE.Bits.VSE4
#define B_GPIO_VSENSE_VSSEL             _B_GPIO_VSENSE.Bits.VSSEL
#define B_GPIO_VSENSE_VSE               _B_GPIO_VSENSE.MergedBits.grpVSE

#define B_GPIO_VSENSE_VSE0_MASK         1U
#define B_GPIO_VSENSE_VSE1_MASK         2U
#define B_GPIO_VSENSE_VSE2_MASK         4U
#define B_GPIO_VSENSE_VSE3_MASK         8U
#define B_GPIO_VSENSE_VSE4_MASK         16U
#define B_GPIO_VSENSE_VSSEL_MASK        192U
#define B_GPIO_VSENSE_VSSEL_BITNUM      6U
#define B_GPIO_VSENSE_VSE_MASK          31U
#define B_GPIO_VSENSE_VSE_BITNUM        0U


/*** B_GPIO_TSENSE - GPIO Tsense Configuration; 0x00000E4C ***/
typedef union {
  byte Byte;
  struct {
    byte TSE0        :1; 
    byte TSE1        :1; 
    byte TSE2        :1; 
    byte TSE3        :1; 
    byte TSE4        :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTSE  :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} B_GPIO_TSENSESTR;
extern volatile B_GPIO_TSENSESTR _B_GPIO_TSENSE @0x00000E4C;
#define B_GPIO_TSENSE                   _B_GPIO_TSENSE.Byte
#define B_GPIO_TSENSE_TSE0              _B_GPIO_TSENSE.Bits.TSE0
#define B_GPIO_TSENSE_TSE1              _B_GPIO_TSENSE.Bits.TSE1
#define B_GPIO_TSENSE_TSE2              _B_GPIO_TSENSE.Bits.TSE2
#define B_GPIO_TSENSE_TSE3              _B_GPIO_TSENSE.Bits.TSE3
#define B_GPIO_TSENSE_TSE4              _B_GPIO_TSENSE.Bits.TSE4
#define B_GPIO_TSENSE_TSE               _B_GPIO_TSENSE.MergedBits.grpTSE

#define B_GPIO_TSENSE_TSE0_MASK         1U
#define B_GPIO_TSENSE_TSE1_MASK         2U
#define B_GPIO_TSENSE_TSE2_MASK         4U
#define B_GPIO_TSENSE_TSE3_MASK         8U
#define B_GPIO_TSENSE_TSE4_MASK         16U
#define B_GPIO_TSENSE_TSE_MASK          31U
#define B_GPIO_TSENSE_TSE_BITNUM        0U


/*** B_LIN_CTL - LIN control register; 0x00000E50 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LIN_CTLH - LIN control register high; 0x00000E50 ***/
    union {
      byte Byte;
      struct {
        byte SRSM        :2;                                       /* Slew Rate Select - Mask */
        byte ENM         :1;                                       /* Module Enable - Mask */
        byte LVSDM       :1;                                       /* Low Voltage Shutdown Disable (J2602 Compliance Control) - Mask */
        byte             :1; 
        byte             :1; 
        byte TXDOMIEM    :1; 
        byte OTIEM       :1;                                       /* Overtemperature Interrupt Enable - Mask */
      } Bits;
    } B_LIN_CTLHSTR;
    #define B_LIN_CTLH                  _B_LIN_CTL.Overlap_STR.B_LIN_CTLHSTR.Byte
    #define B_LIN_CTLH_SRSM             _B_LIN_CTL.Overlap_STR.B_LIN_CTLHSTR.Bits.SRSM
    #define B_LIN_CTLH_ENM              _B_LIN_CTL.Overlap_STR.B_LIN_CTLHSTR.Bits.ENM
    #define B_LIN_CTLH_LVSDM            _B_LIN_CTL.Overlap_STR.B_LIN_CTLHSTR.Bits.LVSDM
    #define B_LIN_CTLH_TXDOMIEM         _B_LIN_CTL.Overlap_STR.B_LIN_CTLHSTR.Bits.TXDOMIEM
    #define B_LIN_CTLH_OTIEM            _B_LIN_CTL.Overlap_STR.B_LIN_CTLHSTR.Bits.OTIEM
    
    #define B_LIN_CTLH_SRSM_MASK        3U
    #define B_LIN_CTLH_SRSM_BITNUM      0U
    #define B_LIN_CTLH_ENM_MASK         4U
    #define B_LIN_CTLH_LVSDM_MASK       8U
    #define B_LIN_CTLH_TXDOMIEM_MASK    64U
    #define B_LIN_CTLH_OTIEM_MASK       128U
    

    /*** B_LIN_CTLL - LIN control register low; 0x00000E51 ***/
    union {
      byte Byte;
      struct {
        byte SRS         :2;                                       /* Slew Rate Select */
        byte EN          :1;                                       /* Module Enable */
        byte LVSD        :1;                                       /* Low Voltage Shutdown Disable (J2602 Compliance Control) */
        byte             :1; 
        byte             :1; 
        byte TXDOMIE     :1; 
        byte OTIE        :1;                                       /* Overtemperature Interrupt Enable */
      } Bits;
    } B_LIN_CTLLSTR;
    #define B_LIN_CTLL                  _B_LIN_CTL.Overlap_STR.B_LIN_CTLLSTR.Byte
    #define B_LIN_CTLL_SRS              _B_LIN_CTL.Overlap_STR.B_LIN_CTLLSTR.Bits.SRS
    #define B_LIN_CTLL_EN               _B_LIN_CTL.Overlap_STR.B_LIN_CTLLSTR.Bits.EN
    #define B_LIN_CTLL_LVSD             _B_LIN_CTL.Overlap_STR.B_LIN_CTLLSTR.Bits.LVSD
    #define B_LIN_CTLL_TXDOMIE          _B_LIN_CTL.Overlap_STR.B_LIN_CTLLSTR.Bits.TXDOMIE
    #define B_LIN_CTLL_OTIE             _B_LIN_CTL.Overlap_STR.B_LIN_CTLLSTR.Bits.OTIE
    
    #define B_LIN_CTLL_SRS_MASK         3U
    #define B_LIN_CTLL_SRS_BITNUM       0U
    #define B_LIN_CTLL_EN_MASK          4U
    #define B_LIN_CTLL_LVSD_MASK        8U
    #define B_LIN_CTLL_TXDOMIE_MASK     64U
    #define B_LIN_CTLL_OTIE_MASK        128U
    
  } Overlap_STR;

  struct {
    word SRS         :2;                                       /* Slew Rate Select */
    word EN          :1;                                       /* Module Enable */
    word LVSD        :1;                                       /* Low Voltage Shutdown Disable (J2602 Compliance Control) */
    word             :1; 
    word             :1; 
    word TXDOMIE     :1; 
    word OTIE        :1;                                       /* Overtemperature Interrupt Enable */
    word SRSM        :2;                                       /* Slew Rate Select - Mask */
    word ENM         :1;                                       /* Module Enable - Mask */
    word LVSDM       :1;                                       /* Low Voltage Shutdown Disable (J2602 Compliance Control) - Mask */
    word             :1; 
    word             :1; 
    word TXDOMIEM    :1; 
    word OTIEM       :1;                                       /* Overtemperature Interrupt Enable - Mask */
  } Bits;
} B_LIN_CTLSTR;
extern volatile B_LIN_CTLSTR _B_LIN_CTL @0x00000E50;
#define B_LIN_CTL                       _B_LIN_CTL.Word
#define B_LIN_CTL_SRS                   _B_LIN_CTL.Bits.SRS
#define B_LIN_CTL_EN                    _B_LIN_CTL.Bits.EN
#define B_LIN_CTL_LVSD                  _B_LIN_CTL.Bits.LVSD
#define B_LIN_CTL_TXDOMIE               _B_LIN_CTL.Bits.TXDOMIE
#define B_LIN_CTL_OTIE                  _B_LIN_CTL.Bits.OTIE
#define B_LIN_CTL_SRSM                  _B_LIN_CTL.Bits.SRSM
#define B_LIN_CTL_ENM                   _B_LIN_CTL.Bits.ENM
#define B_LIN_CTL_LVSDM                 _B_LIN_CTL.Bits.LVSDM
#define B_LIN_CTL_TXDOMIEM              _B_LIN_CTL.Bits.TXDOMIEM
#define B_LIN_CTL_OTIEM                 _B_LIN_CTL.Bits.OTIEM

#define B_LIN_CTL_SRS_MASK              3U
#define B_LIN_CTL_SRS_BITNUM            0U
#define B_LIN_CTL_EN_MASK               4U
#define B_LIN_CTL_LVSD_MASK             8U
#define B_LIN_CTL_TXDOMIE_MASK          64U
#define B_LIN_CTL_OTIE_MASK             128U
#define B_LIN_CTL_SRSM_MASK             768U
#define B_LIN_CTL_SRSM_BITNUM           8U
#define B_LIN_CTL_ENM_MASK              1024U
#define B_LIN_CTL_LVSDM_MASK            2048U
#define B_LIN_CTL_TXDOMIEM_MASK         16384U
#define B_LIN_CTL_OTIEM_MASK            32768U


/*** B_LIN_SR - LIN status register; 0x00000E52 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LIN_SRH - LIN status register high; 0x00000E52 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte UV          :1;                                       /* Undervoltage Status */
        byte             :1; 
        byte HF          :1;                                       /* HF (High Frequency) Condition Status indicating HF disturbance in the LIN module */
        byte TXDOM       :1; 
        byte OT          :1;                                       /* Overtemperature Status */
      } Bits;
    } B_LIN_SRHSTR;
    #define B_LIN_SRH                   _B_LIN_SR.Overlap_STR.B_LIN_SRHSTR.Byte
    #define B_LIN_SRH_UV                _B_LIN_SR.Overlap_STR.B_LIN_SRHSTR.Bits.UV
    #define B_LIN_SRH_HF                _B_LIN_SR.Overlap_STR.B_LIN_SRHSTR.Bits.HF
    #define B_LIN_SRH_TXDOM             _B_LIN_SR.Overlap_STR.B_LIN_SRHSTR.Bits.TXDOM
    #define B_LIN_SRH_OT                _B_LIN_SR.Overlap_STR.B_LIN_SRHSTR.Bits.OT
    
    #define B_LIN_SRH_UV_MASK           8U
    #define B_LIN_SRH_HF_MASK           32U
    #define B_LIN_SRH_TXDOM_MASK        64U
    #define B_LIN_SRH_OT_MASK           128U
    

    /*** B_LIN_SRL - LIN status register low; 0x00000E53 ***/
    union {
      byte Byte;
      struct {
        byte TX          :1;                                       /* Current TX status */
        byte RX          :1;                                       /* Current RX status */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte RDY         :1;                                       /* Transmitter Ready Status */
      } Bits;
    } B_LIN_SRLSTR;
    #define B_LIN_SRL                   _B_LIN_SR.Overlap_STR.B_LIN_SRLSTR.Byte
    #define B_LIN_SRL_TX                _B_LIN_SR.Overlap_STR.B_LIN_SRLSTR.Bits.TX
    #define B_LIN_SRL_RX                _B_LIN_SR.Overlap_STR.B_LIN_SRLSTR.Bits.RX
    #define B_LIN_SRL_RDY               _B_LIN_SR.Overlap_STR.B_LIN_SRLSTR.Bits.RDY
    
    #define B_LIN_SRL_TX_MASK           1U
    #define B_LIN_SRL_RX_MASK           2U
    #define B_LIN_SRL_RDY_MASK          128U
    
  } Overlap_STR;

  struct {
    word TX          :1;                                       /* Current TX status */
    word RX          :1;                                       /* Current RX status */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word RDY         :1;                                       /* Transmitter Ready Status */
    word             :1; 
    word             :1; 
    word             :1; 
    word UV          :1;                                       /* Undervoltage Status */
    word             :1; 
    word HF          :1;                                       /* HF (High Frequency) Condition Status indicating HF disturbance in the LIN module */
    word TXDOM       :1; 
    word OT          :1;                                       /* Overtemperature Status */
  } Bits;
} B_LIN_SRSTR;
extern volatile B_LIN_SRSTR _B_LIN_SR @0x00000E52;
#define B_LIN_SR                        _B_LIN_SR.Word
#define B_LIN_SR_TX                     _B_LIN_SR.Bits.TX
#define B_LIN_SR_RX                     _B_LIN_SR.Bits.RX
#define B_LIN_SR_RDY                    _B_LIN_SR.Bits.RDY
#define B_LIN_SR_UV                     _B_LIN_SR.Bits.UV
#define B_LIN_SR_HF                     _B_LIN_SR.Bits.HF
#define B_LIN_SR_TXDOM                  _B_LIN_SR.Bits.TXDOM
#define B_LIN_SR_OT                     _B_LIN_SR.Bits.OT

#define B_LIN_SR_TX_MASK                1U
#define B_LIN_SR_RX_MASK                2U
#define B_LIN_SR_RDY_MASK               128U
#define B_LIN_SR_UV_MASK                2048U
#define B_LIN_SR_HF_MASK                8192U
#define B_LIN_SR_TXDOM_MASK             16384U
#define B_LIN_SR_OT_MASK                32768U


/*** B_LIN_TX - LIN transmit line definition; 0x00000E54 ***/
typedef union {
  byte Byte;
  struct {
    byte FROMSCI     :1;                                       /* LIN_TX internally routed from SCI */
    byte FROMPTB     :1;                                       /* LIN_TX internally routed from PTB */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} B_LIN_TXSTR;
extern volatile B_LIN_TXSTR _B_LIN_TX @0x00000E54;
#define B_LIN_TX                        _B_LIN_TX.Byte
#define B_LIN_TX_FROMSCI                _B_LIN_TX.Bits.FROMSCI
#define B_LIN_TX_FROMPTB                _B_LIN_TX.Bits.FROMPTB

#define B_LIN_TX_FROMSCI_MASK           1U
#define B_LIN_TX_FROMPTB_MASK           2U


/*** B_LIN_RX - LIN receive line definition; 0x00000E55 ***/
typedef union {
  byte Byte;
  struct {
    byte TOSCI       :1;                                       /* LIN_RX internally routed to SCI */
    byte TOPTB       :1;                                       /* LIN_RX internally routed to PTB */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} B_LIN_RXSTR;
extern volatile B_LIN_RXSTR _B_LIN_RX @0x00000E55;
#define B_LIN_RX                        _B_LIN_RX.Byte
#define B_LIN_RX_TOSCI                  _B_LIN_RX.Bits.TOSCI
#define B_LIN_RX_TOPTB                  _B_LIN_RX.Bits.TOPTB

#define B_LIN_RX_TOSCI_MASK             1U
#define B_LIN_RX_TOPTB_MASK             2U


/*** B_ACQ_CTL - Acquisition control register; 0x00000E58 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_ACQ_CTLH - Acquisition control register high; 0x00000E58 ***/
    union {
      byte Byte;
      struct {
        byte CMENM       :1;                                       /* Current Measurement Enable - Mask */
        byte VMENM       :1;                                       /* Voltage Measurement Enable - Mask */
        byte ITMENM      :1;                                       /* Internal Temperature Measurement Enable - Mask */
        byte ETMENM      :1;                                       /* External Temperature Measurement Enable - Mask */
        byte CVMIEM      :1;                                       /* Current / Voltage Measurement Interrupt Enable - Mask */
        byte NVSEM       :1; 
        byte             :1; 
        byte AHCRM       :1;                                       /* Ampere Hour Counter Reset - Mask */
      } Bits;
    } B_ACQ_CTLHSTR;
    #define B_ACQ_CTLH                  _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLHSTR.Byte
    #define B_ACQ_CTLH_CMENM            _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLHSTR.Bits.CMENM
    #define B_ACQ_CTLH_VMENM            _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLHSTR.Bits.VMENM
    #define B_ACQ_CTLH_ITMENM           _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLHSTR.Bits.ITMENM
    #define B_ACQ_CTLH_ETMENM           _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLHSTR.Bits.ETMENM
    #define B_ACQ_CTLH_CVMIEM           _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLHSTR.Bits.CVMIEM
    #define B_ACQ_CTLH_NVSEM            _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLHSTR.Bits.NVSEM
    #define B_ACQ_CTLH_AHCRM            _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLHSTR.Bits.AHCRM
    
    #define B_ACQ_CTLH_CMENM_MASK       1U
    #define B_ACQ_CTLH_VMENM_MASK       2U
    #define B_ACQ_CTLH_ITMENM_MASK      4U
    #define B_ACQ_CTLH_ETMENM_MASK      8U
    #define B_ACQ_CTLH_CVMIEM_MASK      16U
    #define B_ACQ_CTLH_NVSEM_MASK       32U
    #define B_ACQ_CTLH_AHCRM_MASK       128U
    

    /*** B_ACQ_CTLL - Acquisition control register low; 0x00000E59 ***/
    union {
      byte Byte;
      struct {
        byte CMEN        :1;                                       /* Current Measurement Enable */
        byte VMEN        :1;                                       /* Voltage Measurement Enable */
        byte ITMEN       :1;                                       /* Internal Temperature Measurement Enable */
        byte ETMEN       :1;                                       /* External Temperature Measurement Enable */
        byte CVMIE       :1;                                       /* Current / Voltage Measurement Interrupt Enable */
        byte NVSE        :1; 
        byte             :1; 
        byte AHCR        :1;                                       /* Ampere Hour Counter Reset, this write only bit will reset the ACQ_AHC register */
      } Bits;
    } B_ACQ_CTLLSTR;
    #define B_ACQ_CTLL                  _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLLSTR.Byte
    #define B_ACQ_CTLL_CMEN             _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLLSTR.Bits.CMEN
    #define B_ACQ_CTLL_VMEN             _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLLSTR.Bits.VMEN
    #define B_ACQ_CTLL_ITMEN            _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLLSTR.Bits.ITMEN
    #define B_ACQ_CTLL_ETMEN            _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLLSTR.Bits.ETMEN
    #define B_ACQ_CTLL_CVMIE            _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLLSTR.Bits.CVMIE
    #define B_ACQ_CTLL_NVSE             _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLLSTR.Bits.NVSE
    #define B_ACQ_CTLL_AHCR             _B_ACQ_CTL.Overlap_STR.B_ACQ_CTLLSTR.Bits.AHCR
    
    #define B_ACQ_CTLL_CMEN_MASK        1U
    #define B_ACQ_CTLL_VMEN_MASK        2U
    #define B_ACQ_CTLL_ITMEN_MASK       4U
    #define B_ACQ_CTLL_ETMEN_MASK       8U
    #define B_ACQ_CTLL_CVMIE_MASK       16U
    #define B_ACQ_CTLL_NVSE_MASK        32U
    #define B_ACQ_CTLL_AHCR_MASK        128U
    
  } Overlap_STR;

  struct {
    word CMEN        :1;                                       /* Current Measurement Enable */
    word VMEN        :1;                                       /* Voltage Measurement Enable */
    word ITMEN       :1;                                       /* Internal Temperature Measurement Enable */
    word ETMEN       :1;                                       /* External Temperature Measurement Enable */
    word CVMIE       :1;                                       /* Current / Voltage Measurement Interrupt Enable */
    word NVSE        :1; 
    word             :1; 
    word AHCR        :1;                                       /* Ampere Hour Counter Reset, this write only bit will reset the ACQ_AHC register */
    word CMENM       :1;                                       /* Current Measurement Enable - Mask */
    word VMENM       :1;                                       /* Voltage Measurement Enable - Mask */
    word ITMENM      :1;                                       /* Internal Temperature Measurement Enable - Mask */
    word ETMENM      :1;                                       /* External Temperature Measurement Enable - Mask */
    word CVMIEM      :1;                                       /* Current / Voltage Measurement Interrupt Enable - Mask */
    word NVSEM       :1; 
    word             :1; 
    word AHCRM       :1;                                       /* Ampere Hour Counter Reset - Mask */
  } Bits;
} B_ACQ_CTLSTR;
extern volatile B_ACQ_CTLSTR _B_ACQ_CTL @0x00000E58;
#define B_ACQ_CTL                       _B_ACQ_CTL.Word
#define B_ACQ_CTL_CMEN                  _B_ACQ_CTL.Bits.CMEN
#define B_ACQ_CTL_VMEN                  _B_ACQ_CTL.Bits.VMEN
#define B_ACQ_CTL_ITMEN                 _B_ACQ_CTL.Bits.ITMEN
#define B_ACQ_CTL_ETMEN                 _B_ACQ_CTL.Bits.ETMEN
#define B_ACQ_CTL_CVMIE                 _B_ACQ_CTL.Bits.CVMIE
#define B_ACQ_CTL_NVSE                  _B_ACQ_CTL.Bits.NVSE
#define B_ACQ_CTL_AHCR                  _B_ACQ_CTL.Bits.AHCR
#define B_ACQ_CTL_CMENM                 _B_ACQ_CTL.Bits.CMENM
#define B_ACQ_CTL_VMENM                 _B_ACQ_CTL.Bits.VMENM
#define B_ACQ_CTL_ITMENM                _B_ACQ_CTL.Bits.ITMENM
#define B_ACQ_CTL_ETMENM                _B_ACQ_CTL.Bits.ETMENM
#define B_ACQ_CTL_CVMIEM                _B_ACQ_CTL.Bits.CVMIEM
#define B_ACQ_CTL_NVSEM                 _B_ACQ_CTL.Bits.NVSEM
#define B_ACQ_CTL_AHCRM                 _B_ACQ_CTL.Bits.AHCRM

#define B_ACQ_CTL_CMEN_MASK             1U
#define B_ACQ_CTL_VMEN_MASK             2U
#define B_ACQ_CTL_ITMEN_MASK            4U
#define B_ACQ_CTL_ETMEN_MASK            8U
#define B_ACQ_CTL_CVMIE_MASK            16U
#define B_ACQ_CTL_NVSE_MASK             32U
#define B_ACQ_CTL_AHCR_MASK             128U
#define B_ACQ_CTL_CMENM_MASK            256U
#define B_ACQ_CTL_VMENM_MASK            512U
#define B_ACQ_CTL_ITMENM_MASK           1024U
#define B_ACQ_CTL_ETMENM_MASK           2048U
#define B_ACQ_CTL_CVMIEM_MASK           4096U
#define B_ACQ_CTL_NVSEM_MASK            8192U
#define B_ACQ_CTL_AHCRM_MASK            32768U


/*** B_ACQ_SR - Acquisition status register; 0x00000E5A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_ACQ_SRH - Acquisition status register high; 0x00000E5A ***/
    union {
      byte Byte;
      struct {
        byte CM          :1;                                       /* End of Measurement - Current */
        byte VM          :1;                                       /* End of Measurement - Voltage */
        byte ITM         :1;                                       /* End of Measurement - Internal Temperature */
        byte ETM         :1;                                       /* End of Measurement - External Temperature */
        byte CMOW        :1;                                       /* Current Measurement Result Overwritten */
        byte VMOW        :1;                                       /* Voltage Measurement Result Overwritten */
        byte PGAG        :1;                                       /* PGA Gain Change Flag */
        byte AVRF        :1;                                       /* VDDA Low Voltage Reset Flag */
      } Bits;
    } B_ACQ_SRHSTR;
    #define B_ACQ_SRH                   _B_ACQ_SR.Overlap_STR.B_ACQ_SRHSTR.Byte
    #define B_ACQ_SRH_CM                _B_ACQ_SR.Overlap_STR.B_ACQ_SRHSTR.Bits.CM
    #define B_ACQ_SRH_VM                _B_ACQ_SR.Overlap_STR.B_ACQ_SRHSTR.Bits.VM
    #define B_ACQ_SRH_ITM               _B_ACQ_SR.Overlap_STR.B_ACQ_SRHSTR.Bits.ITM
    #define B_ACQ_SRH_ETM               _B_ACQ_SR.Overlap_STR.B_ACQ_SRHSTR.Bits.ETM
    #define B_ACQ_SRH_CMOW              _B_ACQ_SR.Overlap_STR.B_ACQ_SRHSTR.Bits.CMOW
    #define B_ACQ_SRH_VMOW              _B_ACQ_SR.Overlap_STR.B_ACQ_SRHSTR.Bits.VMOW
    #define B_ACQ_SRH_PGAG              _B_ACQ_SR.Overlap_STR.B_ACQ_SRHSTR.Bits.PGAG
    #define B_ACQ_SRH_AVRF              _B_ACQ_SR.Overlap_STR.B_ACQ_SRHSTR.Bits.AVRF
    
    #define B_ACQ_SRH_CM_MASK           1U
    #define B_ACQ_SRH_VM_MASK           2U
    #define B_ACQ_SRH_ITM_MASK          4U
    #define B_ACQ_SRH_ETM_MASK          8U
    #define B_ACQ_SRH_CMOW_MASK         16U
    #define B_ACQ_SRH_VMOW_MASK         32U
    #define B_ACQ_SRH_PGAG_MASK         64U
    #define B_ACQ_SRH_AVRF_MASK         128U
    

    /*** B_ACQ_SRL - Acquisition status register low; 0x00000E5B ***/
    union {
      byte Byte;
      struct {
        byte CCHOP       :1;                                       /* Chopping Active Status - Current */
        byte VCHOP       :1;                                       /* Chopping Active Status - Voltage */
        byte ITCHOP      :1;                                       /* Chopping Active Status - Internal Temperature */
        byte ETCHOP      :1;                                       /* Chopping Active Status - External Temperature */
        byte VTH         :1;                                       /* Digital Voltage High Threshold Reached */
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_ACQ_SRLSTR;
    #define B_ACQ_SRL                   _B_ACQ_SR.Overlap_STR.B_ACQ_SRLSTR.Byte
    #define B_ACQ_SRL_CCHOP             _B_ACQ_SR.Overlap_STR.B_ACQ_SRLSTR.Bits.CCHOP
    #define B_ACQ_SRL_VCHOP             _B_ACQ_SR.Overlap_STR.B_ACQ_SRLSTR.Bits.VCHOP
    #define B_ACQ_SRL_ITCHOP            _B_ACQ_SR.Overlap_STR.B_ACQ_SRLSTR.Bits.ITCHOP
    #define B_ACQ_SRL_ETCHOP            _B_ACQ_SR.Overlap_STR.B_ACQ_SRLSTR.Bits.ETCHOP
    #define B_ACQ_SRL_VTH               _B_ACQ_SR.Overlap_STR.B_ACQ_SRLSTR.Bits.VTH
    
    #define B_ACQ_SRL_CCHOP_MASK        1U
    #define B_ACQ_SRL_VCHOP_MASK        2U
    #define B_ACQ_SRL_ITCHOP_MASK       4U
    #define B_ACQ_SRL_ETCHOP_MASK       8U
    #define B_ACQ_SRL_VTH_MASK          16U
    
  } Overlap_STR;

  struct {
    word CCHOP       :1;                                       /* Chopping Active Status - Current */
    word VCHOP       :1;                                       /* Chopping Active Status - Voltage */
    word ITCHOP      :1;                                       /* Chopping Active Status - Internal Temperature */
    word ETCHOP      :1;                                       /* Chopping Active Status - External Temperature */
    word VTH         :1;                                       /* Digital Voltage High Threshold Reached */
    word             :1; 
    word             :1; 
    word             :1; 
    word CM          :1;                                       /* End of Measurement - Current */
    word VM          :1;                                       /* End of Measurement - Voltage */
    word ITM         :1;                                       /* End of Measurement - Internal Temperature */
    word ETM         :1;                                       /* End of Measurement - External Temperature */
    word CMOW        :1;                                       /* Current Measurement Result Overwritten */
    word VMOW        :1;                                       /* Voltage Measurement Result Overwritten */
    word PGAG        :1;                                       /* PGA Gain Change Flag */
    word AVRF        :1;                                       /* VDDA Low Voltage Reset Flag */
  } Bits;
} B_ACQ_SRSTR;
extern volatile B_ACQ_SRSTR _B_ACQ_SR @0x00000E5A;
#define B_ACQ_SR                        _B_ACQ_SR.Word
#define B_ACQ_SR_CCHOP                  _B_ACQ_SR.Bits.CCHOP
#define B_ACQ_SR_VCHOP                  _B_ACQ_SR.Bits.VCHOP
#define B_ACQ_SR_ITCHOP                 _B_ACQ_SR.Bits.ITCHOP
#define B_ACQ_SR_ETCHOP                 _B_ACQ_SR.Bits.ETCHOP
#define B_ACQ_SR_VTH                    _B_ACQ_SR.Bits.VTH
#define B_ACQ_SR_CM                     _B_ACQ_SR.Bits.CM
#define B_ACQ_SR_VM                     _B_ACQ_SR.Bits.VM
#define B_ACQ_SR_ITM                    _B_ACQ_SR.Bits.ITM
#define B_ACQ_SR_ETM                    _B_ACQ_SR.Bits.ETM
#define B_ACQ_SR_CMOW                   _B_ACQ_SR.Bits.CMOW
#define B_ACQ_SR_VMOW                   _B_ACQ_SR.Bits.VMOW
#define B_ACQ_SR_PGAG                   _B_ACQ_SR.Bits.PGAG
#define B_ACQ_SR_AVRF                   _B_ACQ_SR.Bits.AVRF

#define B_ACQ_SR_CCHOP_MASK             1U
#define B_ACQ_SR_VCHOP_MASK             2U
#define B_ACQ_SR_ITCHOP_MASK            4U
#define B_ACQ_SR_ETCHOP_MASK            8U
#define B_ACQ_SR_VTH_MASK               16U
#define B_ACQ_SR_CM_MASK                256U
#define B_ACQ_SR_VM_MASK                512U
#define B_ACQ_SR_ITM_MASK               1024U
#define B_ACQ_SR_ETM_MASK               2048U
#define B_ACQ_SR_CMOW_MASK              4096U
#define B_ACQ_SR_VMOW_MASK              8192U
#define B_ACQ_SR_PGAG_MASK              16384U
#define B_ACQ_SR_AVRF_MASK              32768U


/*** B_ACQ_ACC1 - Acquisition chain control 1; 0x00000E5C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_ACQ_ACC1H - Acquisition chain control 1 high; 0x00000E5C ***/
    union {
      byte Byte;
      struct {
        byte AGENM       :1;                                       /* Temperature Measurement Channel - Compensation Enable */
        byte CVCHOPM     :1;                                       /* Voltage Compensation Enable */
        byte ITCHOPM     :1;                                       /* Current Compensation Enable */
        byte ETCHOPM     :1;                                       /* LPF Enable */
        byte LPFENM      :1;                                       /* Chopping Enable - External Temperature */
        byte CCOMPM      :1;                                       /* Chopping Enable - Internal Temperature */
        byte VCOMPM      :1;                                       /* Chopping Enable - Voltage */
        byte TCOMPM      :1;                                       /* Automatic Gain Control Enable */
      } Bits;
    } B_ACQ_ACC1HSTR;
    #define B_ACQ_ACC1H                 _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1HSTR.Byte
    #define B_ACQ_ACC1H_AGENM           _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1HSTR.Bits.AGENM
    #define B_ACQ_ACC1H_CVCHOPM         _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1HSTR.Bits.CVCHOPM
    #define B_ACQ_ACC1H_ITCHOPM         _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1HSTR.Bits.ITCHOPM
    #define B_ACQ_ACC1H_ETCHOPM         _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1HSTR.Bits.ETCHOPM
    #define B_ACQ_ACC1H_LPFENM          _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1HSTR.Bits.LPFENM
    #define B_ACQ_ACC1H_CCOMPM          _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1HSTR.Bits.CCOMPM
    #define B_ACQ_ACC1H_VCOMPM          _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1HSTR.Bits.VCOMPM
    #define B_ACQ_ACC1H_TCOMPM          _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1HSTR.Bits.TCOMPM
    
    #define B_ACQ_ACC1H_AGENM_MASK      1U
    #define B_ACQ_ACC1H_CVCHOPM_MASK    2U
    #define B_ACQ_ACC1H_ITCHOPM_MASK    4U
    #define B_ACQ_ACC1H_ETCHOPM_MASK    8U
    #define B_ACQ_ACC1H_LPFENM_MASK     16U
    #define B_ACQ_ACC1H_CCOMPM_MASK     32U
    #define B_ACQ_ACC1H_VCOMPM_MASK     64U
    #define B_ACQ_ACC1H_TCOMPM_MASK     128U
    

    /*** B_ACQ_ACC1L - Acquisition chain control 1 low; 0x00000E5D ***/
    union {
      byte Byte;
      struct {
        byte AGEN        :1;                                       /* Automatic Gain Control Enable - Mask */
        byte CVCHOP      :1;                                       /* Chopping Enable - Voltage Measurement Channel - Mask */
        byte ITCHOP      :1;                                       /* Chopping Enable - Internal Temperature Measurement Channel - Mask */
        byte ETCHOP      :1;                                       /* Chopping Enable - External Temperature Measurement Channel - Mask */
        byte LPFEN       :1;                                       /* LPF Enable - Mask */
        byte CCOMP       :1;                                       /* Current Measurement Channel - Compensation Enable - Mask */
        byte VCOMP       :1;                                       /* Voltage Measurement Channel - Compensation Enable - Mask */
        byte TCOMP       :1;                                       /* Temperature Measurement Channel - Compensation Enable - Mask */
      } Bits;
    } B_ACQ_ACC1LSTR;
    #define B_ACQ_ACC1L                 _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1LSTR.Byte
    #define B_ACQ_ACC1L_AGEN            _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1LSTR.Bits.AGEN
    #define B_ACQ_ACC1L_CVCHOP          _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1LSTR.Bits.CVCHOP
    #define B_ACQ_ACC1L_ITCHOP          _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1LSTR.Bits.ITCHOP
    #define B_ACQ_ACC1L_ETCHOP          _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1LSTR.Bits.ETCHOP
    #define B_ACQ_ACC1L_LPFEN           _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1LSTR.Bits.LPFEN
    #define B_ACQ_ACC1L_CCOMP           _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1LSTR.Bits.CCOMP
    #define B_ACQ_ACC1L_VCOMP           _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1LSTR.Bits.VCOMP
    #define B_ACQ_ACC1L_TCOMP           _B_ACQ_ACC1.Overlap_STR.B_ACQ_ACC1LSTR.Bits.TCOMP
    
    #define B_ACQ_ACC1L_AGEN_MASK       1U
    #define B_ACQ_ACC1L_CVCHOP_MASK     2U
    #define B_ACQ_ACC1L_ITCHOP_MASK     4U
    #define B_ACQ_ACC1L_ETCHOP_MASK     8U
    #define B_ACQ_ACC1L_LPFEN_MASK      16U
    #define B_ACQ_ACC1L_CCOMP_MASK      32U
    #define B_ACQ_ACC1L_VCOMP_MASK      64U
    #define B_ACQ_ACC1L_TCOMP_MASK      128U
    
  } Overlap_STR;

  struct {
    word AGEN        :1;                                       /* Automatic Gain Control Enable - Mask */
    word CVCHOP      :1;                                       /* Chopping Enable - Voltage Measurement Channel - Mask */
    word ITCHOP      :1;                                       /* Chopping Enable - Internal Temperature Measurement Channel - Mask */
    word ETCHOP      :1;                                       /* Chopping Enable - External Temperature Measurement Channel - Mask */
    word LPFEN       :1;                                       /* LPF Enable - Mask */
    word CCOMP       :1;                                       /* Current Measurement Channel - Compensation Enable - Mask */
    word VCOMP       :1;                                       /* Voltage Measurement Channel - Compensation Enable - Mask */
    word TCOMP       :1;                                       /* Temperature Measurement Channel - Compensation Enable - Mask */
    word AGENM       :1;                                       /* Temperature Measurement Channel - Compensation Enable */
    word CVCHOPM     :1;                                       /* Voltage Compensation Enable */
    word ITCHOPM     :1;                                       /* Current Compensation Enable */
    word ETCHOPM     :1;                                       /* LPF Enable */
    word LPFENM      :1;                                       /* Chopping Enable - External Temperature */
    word CCOMPM      :1;                                       /* Chopping Enable - Internal Temperature */
    word VCOMPM      :1;                                       /* Chopping Enable - Voltage */
    word TCOMPM      :1;                                       /* Automatic Gain Control Enable */
  } Bits;
} B_ACQ_ACC1STR;
extern volatile B_ACQ_ACC1STR _B_ACQ_ACC1 @0x00000E5C;
#define B_ACQ_ACC1                      _B_ACQ_ACC1.Word
#define B_ACQ_ACC1_AGEN                 _B_ACQ_ACC1.Bits.AGEN
#define B_ACQ_ACC1_CVCHOP               _B_ACQ_ACC1.Bits.CVCHOP
#define B_ACQ_ACC1_ITCHOP               _B_ACQ_ACC1.Bits.ITCHOP
#define B_ACQ_ACC1_ETCHOP               _B_ACQ_ACC1.Bits.ETCHOP
#define B_ACQ_ACC1_LPFEN                _B_ACQ_ACC1.Bits.LPFEN
#define B_ACQ_ACC1_CCOMP                _B_ACQ_ACC1.Bits.CCOMP
#define B_ACQ_ACC1_VCOMP                _B_ACQ_ACC1.Bits.VCOMP
#define B_ACQ_ACC1_TCOMP                _B_ACQ_ACC1.Bits.TCOMP
#define B_ACQ_ACC1_AGENM                _B_ACQ_ACC1.Bits.AGENM
#define B_ACQ_ACC1_CVCHOPM              _B_ACQ_ACC1.Bits.CVCHOPM
#define B_ACQ_ACC1_ITCHOPM              _B_ACQ_ACC1.Bits.ITCHOPM
#define B_ACQ_ACC1_ETCHOPM              _B_ACQ_ACC1.Bits.ETCHOPM
#define B_ACQ_ACC1_LPFENM               _B_ACQ_ACC1.Bits.LPFENM
#define B_ACQ_ACC1_CCOMPM               _B_ACQ_ACC1.Bits.CCOMPM
#define B_ACQ_ACC1_VCOMPM               _B_ACQ_ACC1.Bits.VCOMPM
#define B_ACQ_ACC1_TCOMPM               _B_ACQ_ACC1.Bits.TCOMPM

#define B_ACQ_ACC1_AGEN_MASK            1U
#define B_ACQ_ACC1_CVCHOP_MASK          2U
#define B_ACQ_ACC1_ITCHOP_MASK          4U
#define B_ACQ_ACC1_ETCHOP_MASK          8U
#define B_ACQ_ACC1_LPFEN_MASK           16U
#define B_ACQ_ACC1_CCOMP_MASK           32U
#define B_ACQ_ACC1_VCOMP_MASK           64U
#define B_ACQ_ACC1_TCOMP_MASK           128U
#define B_ACQ_ACC1_AGENM_MASK           256U
#define B_ACQ_ACC1_CVCHOPM_MASK         512U
#define B_ACQ_ACC1_ITCHOPM_MASK         1024U
#define B_ACQ_ACC1_ETCHOPM_MASK         2048U
#define B_ACQ_ACC1_LPFENM_MASK          4096U
#define B_ACQ_ACC1_CCOMPM_MASK          8192U
#define B_ACQ_ACC1_VCOMPM_MASK          16384U
#define B_ACQ_ACC1_TCOMPM_MASK          32768U


/*** B_ACQ_ACC0 - Acquisition chain control 0; 0x00000E5E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_ACQ_ACC0H - Acquisition chain control 0 high; 0x00000E5E ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte ZEROM       :1;                                       /* Current and Voltage Sigma Delta Input Short - Mask */
      } Bits;
    } B_ACQ_ACC0HSTR;
    #define B_ACQ_ACC0H                 _B_ACQ_ACC0.Overlap_STR.B_ACQ_ACC0HSTR.Byte
    #define B_ACQ_ACC0H_ZEROM           _B_ACQ_ACC0.Overlap_STR.B_ACQ_ACC0HSTR.Bits.ZEROM
    
    #define B_ACQ_ACC0H_ZEROM_MASK      128U
    

    /*** B_ACQ_ACC0L - Acquisition chain control 0 low; 0x00000E5F ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte ZERO        :1;                                       /* Current and Voltage Sigma Delta Input Short */
      } Bits;
    } B_ACQ_ACC0LSTR;
    #define B_ACQ_ACC0L                 _B_ACQ_ACC0.Overlap_STR.B_ACQ_ACC0LSTR.Byte
    #define B_ACQ_ACC0L_ZERO            _B_ACQ_ACC0.Overlap_STR.B_ACQ_ACC0LSTR.Bits.ZERO
    
    #define B_ACQ_ACC0L_ZERO_MASK       128U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word ZERO        :1;                                       /* Current and Voltage Sigma Delta Input Short */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word ZEROM       :1;                                       /* Current and Voltage Sigma Delta Input Short - Mask */
  } Bits;
} B_ACQ_ACC0STR;
extern volatile B_ACQ_ACC0STR _B_ACQ_ACC0 @0x00000E5E;
#define B_ACQ_ACC0                      _B_ACQ_ACC0.Word
#define B_ACQ_ACC0_ZERO                 _B_ACQ_ACC0.Bits.ZERO
#define B_ACQ_ACC0_ZEROM                _B_ACQ_ACC0.Bits.ZEROM

#define B_ACQ_ACC0_ZERO_MASK            128U
#define B_ACQ_ACC0_ZEROM_MASK           32768U


/*** B_ACQ_DEC - Decimation Rate; 0x00000E60 ***/
typedef union {
  byte Byte;
  struct {
    byte DEC         :3;                                       /* Decimation Rate Selection */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} B_ACQ_DECSTR;
extern volatile B_ACQ_DECSTR _B_ACQ_DEC @0x00000E60;
#define B_ACQ_DEC                       _B_ACQ_DEC.Byte
#define B_ACQ_DEC_DEC                   _B_ACQ_DEC.Bits.DEC

#define B_ACQ_DEC_DEC_MASK              7U
#define B_ACQ_DEC_DEC_BITNUM            0U


/*** B_ACQ_GAIN - PGA gain; 0x00000E62 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte IGAIN       :2;                                       /* PGA Gain Register */
    byte LPGEN       :1; 
    byte G4DIS       :1; 
    byte G16DIS      :1; 
    byte G64DIS      :1; 
    byte G256DIS     :1; 
  } Bits;
} B_ACQ_GAINSTR;
extern volatile B_ACQ_GAINSTR _B_ACQ_GAIN @0x00000E62;
#define B_ACQ_GAIN                      _B_ACQ_GAIN.Byte
#define B_ACQ_GAIN_IGAIN                _B_ACQ_GAIN.Bits.IGAIN
#define B_ACQ_GAIN_LPGEN                _B_ACQ_GAIN.Bits.LPGEN
#define B_ACQ_GAIN_G4DIS                _B_ACQ_GAIN.Bits.G4DIS
#define B_ACQ_GAIN_G16DIS               _B_ACQ_GAIN.Bits.G16DIS
#define B_ACQ_GAIN_G64DIS               _B_ACQ_GAIN.Bits.G64DIS
#define B_ACQ_GAIN_G256DIS              _B_ACQ_GAIN.Bits.G256DIS

#define B_ACQ_GAIN_IGAIN_MASK           6U
#define B_ACQ_GAIN_IGAIN_BITNUM         1U
#define B_ACQ_GAIN_LPGEN_MASK           8U
#define B_ACQ_GAIN_G4DIS_MASK           16U
#define B_ACQ_GAIN_G16DIS_MASK          32U
#define B_ACQ_GAIN_G64DIS_MASK          64U
#define B_ACQ_GAIN_G256DIS_MASK         128U


/*** B_ACQ_GCB - PGA gain; 0x00000E63 ***/
typedef union {
  byte Byte;
  struct {
    byte Dlo         :4;                                       /* Gain Control Block (GCB) - Down Threshold */
    byte Dhi         :4;                                       /* Gain Control Block (GCB) - Up Threshold */
  } Bits;
} B_ACQ_GCBSTR;
extern volatile B_ACQ_GCBSTR _B_ACQ_GCB @0x00000E63;
#define B_ACQ_GCB                       _B_ACQ_GCB.Byte
#define B_ACQ_GCB_Dlo                   _B_ACQ_GCB.Bits.Dlo
#define B_ACQ_GCB_Dhi                   _B_ACQ_GCB.Bits.Dhi

#define B_ACQ_GCB_Dlo_MASK              15U
#define B_ACQ_GCB_Dlo_BITNUM            0U
#define B_ACQ_GCB_Dhi_MASK              240U
#define B_ACQ_GCB_Dhi_BITNUM            4U


/*** B_ACQ_ITEMP - Internal temperature measurement result; 0x00000E64 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_ACQ_ITEMPH - Internal temperature measurement result high; 0x00000E64 ***/
    union {
      byte Byte;
    } B_ACQ_ITEMPHSTR;
    #define B_ACQ_ITEMPH                _B_ACQ_ITEMP.Overlap_STR.B_ACQ_ITEMPHSTR.Byte
    

    /*** B_ACQ_ITEMPL - Internal temperature measurement result low; 0x00000E65 ***/
    union {
      byte Byte;
    } B_ACQ_ITEMPLSTR;
    #define B_ACQ_ITEMPL                _B_ACQ_ITEMP.Overlap_STR.B_ACQ_ITEMPLSTR.Byte
    
  } Overlap_STR;

} B_ACQ_ITEMPSTR;
extern volatile B_ACQ_ITEMPSTR _B_ACQ_ITEMP @0x00000E64;
#define B_ACQ_ITEMP                     _B_ACQ_ITEMP.Word


/*** B_ACQ_ETEMP - External temperature measurement result; 0x00000E66 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_ACQ_ETEMPH - External temperature measurement result high; 0x00000E66 ***/
    union {
      byte Byte;
    } B_ACQ_ETEMPHSTR;
    #define B_ACQ_ETEMPH                _B_ACQ_ETEMP.Overlap_STR.B_ACQ_ETEMPHSTR.Byte
    

    /*** B_ACQ_ETEMPL - External temperature measurement result low; 0x00000E67 ***/
    union {
      byte Byte;
    } B_ACQ_ETEMPLSTR;
    #define B_ACQ_ETEMPL                _B_ACQ_ETEMP.Overlap_STR.B_ACQ_ETEMPLSTR.Byte
    
  } Overlap_STR;

} B_ACQ_ETEMPSTR;
extern volatile B_ACQ_ETEMPSTR _B_ACQ_ETEMP @0x00000E66;
#define B_ACQ_ETEMP                     _B_ACQ_ETEMP.Word


/*** B_ACQ_CURR1 - Current measurement result 16Bit; 0x00000E68 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    byte _Reserved_1[1];
    /*** B_ACQ_CURR1L - Current measurement result 8Bit; 0x00000E69 ***/
    union {
      byte Byte;
    } B_ACQ_CURR1LSTR;
    #define B_ACQ_CURR1L                _B_ACQ_CURR1.Overlap_STR.B_ACQ_CURR1LSTR.Byte
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word CURR        :8;                                       /* Two's complement 24 Bit signed integer result register for the current measurement channel */
  } Bits;
} B_ACQ_CURR1STR;
extern volatile B_ACQ_CURR1STR _B_ACQ_CURR1 @0x00000E68;
#define B_ACQ_CURR1                     _B_ACQ_CURR1.Word
#define B_ACQ_CURR1_CURR                _B_ACQ_CURR1.Bits.CURR

#define B_ACQ_CURR1_CURR_MASK           65280U
#define B_ACQ_CURR1_CURR_BITNUM         8U


/*** B_ACQ_CURR0 - Current measurement result; 0x00000E6A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_ACQ_CURR0H - Current measurement result high; 0x00000E6A ***/
    union {
      byte Byte;
    } B_ACQ_CURR0HSTR;
    #define B_ACQ_CURR0H                _B_ACQ_CURR0.Overlap_STR.B_ACQ_CURR0HSTR.Byte
    

    /*** B_ACQ_CURR0L - Current measurement result low; 0x00000E6B ***/
    union {
      byte Byte;
    } B_ACQ_CURR0LSTR;
    #define B_ACQ_CURR0L                _B_ACQ_CURR0.Overlap_STR.B_ACQ_CURR0LSTR.Byte
    
  } Overlap_STR;

} B_ACQ_CURR0STR;
extern volatile B_ACQ_CURR0STR _B_ACQ_CURR0 @0x00000E6A;
#define B_ACQ_CURR0                     _B_ACQ_CURR0.Word


/*** B_ACQ_VOLT - Voltage measurement result; 0x00000E6C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_ACQ_VOLTH - Voltage measurement result high; 0x00000E6C ***/
    union {
      byte Byte;
    } B_ACQ_VOLTHSTR;
    #define B_ACQ_VOLTH                 _B_ACQ_VOLT.Overlap_STR.B_ACQ_VOLTHSTR.Byte
    

    /*** B_ACQ_VOLTL - Voltage measurement result low; 0x00000E6D ***/
    union {
      byte Byte;
    } B_ACQ_VOLTLSTR;
    #define B_ACQ_VOLTL                 _B_ACQ_VOLT.Overlap_STR.B_ACQ_VOLTLSTR.Byte
    
  } Overlap_STR;

} B_ACQ_VOLTSTR;
extern volatile B_ACQ_VOLTSTR _B_ACQ_VOLT @0x00000E6C;
#define B_ACQ_VOLT                      _B_ACQ_VOLT.Word


/*** B_ACQ_LPFC - Low pass filter coefficient number; 0x00000E6E ***/
typedef union {
  byte Byte;
  struct {
    byte LPFC        :4;                                       /* Low Pass Filter Coefficient Number */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} B_ACQ_LPFCSTR;
extern volatile B_ACQ_LPFCSTR _B_ACQ_LPFC @0x00000E6E;
#define B_ACQ_LPFC                      _B_ACQ_LPFC.Byte
#define B_ACQ_LPFC_LPFC                 _B_ACQ_LPFC.Bits.LPFC

#define B_ACQ_LPFC_LPFC_MASK            15U
#define B_ACQ_LPFC_LPFC_BITNUM          0U


/*** B_ACQ_TCMP - Low power trigger current measurement period; 0x00000E70 ***/
typedef union {
  word Word;
} B_ACQ_TCMPSTR;
extern volatile B_ACQ_TCMPSTR _B_ACQ_TCMP @0x00000E70;
#define B_ACQ_TCMP                      _B_ACQ_TCMP.Word


/*** B_ACQ_THF - Low power current threshold filtering period; 0x00000E72 ***/
typedef union {
  byte Byte;
} B_ACQ_THFSTR;
extern volatile B_ACQ_THFSTR _B_ACQ_THF @0x00000E72;
#define B_ACQ_THF                       _B_ACQ_THF.Byte


/*** B_ACQ_CVCR - I and V chopper control register; 0x00000E74 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_ACQ_CVCRH - I and V chopper control register high; 0x00000E74 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte IIRCM       :3;                                       /* IIR Low Pass Filter Configuration - Mask */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_ACQ_CVCRHSTR;
    #define B_ACQ_CVCRH                 _B_ACQ_CVCR.Overlap_STR.B_ACQ_CVCRHSTR.Byte
    #define B_ACQ_CVCRH_IIRCM           _B_ACQ_CVCR.Overlap_STR.B_ACQ_CVCRHSTR.Bits.IIRCM
    
    #define B_ACQ_CVCRH_IIRCM_MASK      14U
    #define B_ACQ_CVCRH_IIRCM_BITNUM    1U
    

    /*** B_ACQ_CVCRL - I and V chopper control register high low; 0x00000E75 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte IIRC        :3;                                       /* IIR Low Pass Filter Coefficient */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_ACQ_CVCRLSTR;
    #define B_ACQ_CVCRL                 _B_ACQ_CVCR.Overlap_STR.B_ACQ_CVCRLSTR.Byte
    #define B_ACQ_CVCRL_IIRC            _B_ACQ_CVCR.Overlap_STR.B_ACQ_CVCRLSTR.Bits.IIRC
    
    #define B_ACQ_CVCRL_IIRC_MASK       14U
    #define B_ACQ_CVCRL_IIRC_BITNUM     1U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word IIRC        :3;                                       /* IIR Low Pass Filter Coefficient */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word IIRCM       :3;                                       /* IIR Low Pass Filter Configuration - Mask */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_ACQ_CVCRSTR;
extern volatile B_ACQ_CVCRSTR _B_ACQ_CVCR @0x00000E74;
#define B_ACQ_CVCR                      _B_ACQ_CVCR.Word
#define B_ACQ_CVCR_IIRC                 _B_ACQ_CVCR.Bits.IIRC
#define B_ACQ_CVCR_IIRCM                _B_ACQ_CVCR.Bits.IIRCM

#define B_ACQ_CVCR_IIRC_MASK            14U
#define B_ACQ_CVCR_IIRC_BITNUM          1U
#define B_ACQ_CVCR_IIRCM_MASK           3584U
#define B_ACQ_CVCR_IIRCM_BITNUM         9U


/*** B_ACQ_CTH - Low power current threshold; 0x00000E76 ***/
typedef union {
  byte Byte;
} B_ACQ_CTHSTR;
extern volatile B_ACQ_CTHSTR _B_ACQ_CTH @0x00000E76;
#define B_ACQ_CTH                       _B_ACQ_CTH.Byte


/*** B_ACQ_AHTH - Low power Ah counter threshold; 0x00000E78 ***/
typedef union {
  dword Dword;
   /* Overlapped registers: */
  struct {
    /*** B_ACQ_AHTH1 - Low power Ah counter threshold 1; 0x00000E78 ***/
    union {
      word Word;
       /* Overlapped registers: */
      struct {
        /*** B_ACQ_AHTH1H - Low power Ah counter threshold 1 high; 0x00000E78 ***/
        union {
          byte Byte;
          struct {
            byte AHTH        :7;                                       /* Low power Ah counter threshold 1 high */
            byte             :1; 
          } Bits;
        } B_ACQ_AHTH1HSTR;
        #define B_ACQ_AHTH1H            _B_ACQ_AHTH.Overlap_STR.B_ACQ_AHTH1STR.Overlap_STR.B_ACQ_AHTH1HSTR.Byte
        #define B_ACQ_AHTH1H_AHTH       _B_ACQ_AHTH.Overlap_STR.B_ACQ_AHTH1STR.Overlap_STR.B_ACQ_AHTH1HSTR.Bits.AHTH
        
        #define B_ACQ_AHTH1H_AHTH_MASK  127U
        #define B_ACQ_AHTH1H_AHTH_BITNUM 0U
        
    
        /*** B_ACQ_AHTH1L - Low power Ah counter threshold 1 low; 0x00000E79 ***/
        union {
          byte Byte;
        } B_ACQ_AHTH1LSTR;
        #define B_ACQ_AHTH1L            _B_ACQ_AHTH.Overlap_STR.B_ACQ_AHTH1STR.Overlap_STR.B_ACQ_AHTH1LSTR.Byte
        
      } Overlap_STR;
    
      struct {
        word AHTH        :15;                                      /* Low power Ah counter threshold 1 */
        word             :1; 
      } Bits;
    } B_ACQ_AHTH1STR;
    #define B_ACQ_AHTH1                 _B_ACQ_AHTH.Overlap_STR.B_ACQ_AHTH1STR.Word
    #define B_ACQ_AHTH1_AHTH            _B_ACQ_AHTH.Overlap_STR.B_ACQ_AHTH1STR.Bits.AHTH
    
    #define B_ACQ_AHTH1_AHTH_MASK       32767U
    #define B_ACQ_AHTH1_AHTH_BITNUM     0U
    

    /*** B_ACQ_AHTH0 - Low power Ah counter threshold 0; 0x00000E7A ***/
    union {
      word Word;
       /* Overlapped registers: */
      struct {
        /*** B_ACQ_AHTH0H - Low power Ah counter threshold 0 high; 0x00000E7A ***/
        union {
          byte Byte;
        } B_ACQ_AHTH0HSTR;
        #define B_ACQ_AHTH0H            _B_ACQ_AHTH.Overlap_STR.B_ACQ_AHTH0STR.Overlap_STR.B_ACQ_AHTH0HSTR.Byte
        
    
        /*** B_ACQ_AHTH0L - Low power Ah counter threshold 0 low; 0x00000E7B ***/
        union {
          byte Byte;
        } B_ACQ_AHTH0LSTR;
        #define B_ACQ_AHTH0L            _B_ACQ_AHTH.Overlap_STR.B_ACQ_AHTH0STR.Overlap_STR.B_ACQ_AHTH0LSTR.Byte
        
      } Overlap_STR;
    
    } B_ACQ_AHTH0STR;
    #define B_ACQ_AHTH0                 _B_ACQ_AHTH.Overlap_STR.B_ACQ_AHTH0STR.Word
    
  } Overlap_STR;

} B_ACQ_AHTHSTR;
extern volatile B_ACQ_AHTHSTR _B_ACQ_AHTH @0x00000E78;
#define B_ACQ_AHTH                      _B_ACQ_AHTH.Dword


/*** B_ACQ_AHC - Low power Ah counter; 0x00000E7C ***/
typedef union {
  dword Dword;
   /* Overlapped registers: */
  struct {
    /*** B_ACQ_AHC1 - Low power Ah counter 1; 0x00000E7C ***/
    union {
      word Word;
       /* Overlapped registers: */
      struct {
        /*** B_ACQ_AHC1H - Low power Ah counter 1 high; 0x00000E7C ***/
        union {
          byte Byte;
        } B_ACQ_AHC1HSTR;
        #define B_ACQ_AHC1H             _B_ACQ_AHC.Overlap_STR.B_ACQ_AHC1STR.Overlap_STR.B_ACQ_AHC1HSTR.Byte
        
    
        /*** B_ACQ_AHC1L - Low power Ah counter 1 low; 0x00000E7D ***/
        union {
          byte Byte;
        } B_ACQ_AHC1LSTR;
        #define B_ACQ_AHC1L             _B_ACQ_AHC.Overlap_STR.B_ACQ_AHC1STR.Overlap_STR.B_ACQ_AHC1LSTR.Byte
        
      } Overlap_STR;
    
    } B_ACQ_AHC1STR;
    #define B_ACQ_AHC1                  _B_ACQ_AHC.Overlap_STR.B_ACQ_AHC1STR.Word
    

    /*** B_ACQ_AHC0 - Low power Ah counter 0; 0x00000E7E ***/
    union {
      word Word;
       /* Overlapped registers: */
      struct {
        /*** B_ACQ_AHC0H - Low power Ah counter 0 high; 0x00000E7E ***/
        union {
          byte Byte;
        } B_ACQ_AHC0HSTR;
        #define B_ACQ_AHC0H             _B_ACQ_AHC.Overlap_STR.B_ACQ_AHC0STR.Overlap_STR.B_ACQ_AHC0HSTR.Byte
        
    
        /*** B_ACQ_AHC0L - Low power Ah counter 0 low; 0x00000E7F ***/
        union {
          byte Byte;
        } B_ACQ_AHC0LSTR;
        #define B_ACQ_AHC0L             _B_ACQ_AHC.Overlap_STR.B_ACQ_AHC0STR.Overlap_STR.B_ACQ_AHC0LSTR.Byte
        
      } Overlap_STR;
    
    } B_ACQ_AHC0STR;
    #define B_ACQ_AHC0                  _B_ACQ_AHC.Overlap_STR.B_ACQ_AHC0STR.Word
    
  } Overlap_STR;

} B_ACQ_AHCSTR;
extern volatile B_ACQ_AHCSTR _B_ACQ_AHC @0x00000E7C;
#define B_ACQ_AHC                       _B_ACQ_AHC.Dword


/*** B_LPF_A0 - Low Pass Filter Coefficient A0; 0x00000E80 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A0H - Low Pass Filter Coefficient A0 high; 0x00000E80 ***/
    union {
      byte Byte;
    } B_LPF_A0HSTR;
    #define B_LPF_A0H                   _B_LPF_A0.Overlap_STR.B_LPF_A0HSTR.Byte
    

    /*** B_LPF_A0L - Low Pass Filter Coefficient A0 low; 0x00000E81 ***/
    union {
      byte Byte;
    } B_LPF_A0LSTR;
    #define B_LPF_A0L                   _B_LPF_A0.Overlap_STR.B_LPF_A0LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A0STR;
extern volatile B_LPF_A0STR _B_LPF_A0 @0x00000E80;
#define B_LPF_A0                        _B_LPF_A0.Word
/* B_LPF_A_ARR: Access 16 B_LPF_Ax registers in an array */
#define B_LPF_A_ARR                     ((volatile word *) &B_LPF_A0)


/*** B_LPF_A1 - Low Pass Filter Coefficient A1; 0x00000E82 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A1H - Low Pass Filter Coefficient A1 high; 0x00000E82 ***/
    union {
      byte Byte;
    } B_LPF_A1HSTR;
    #define B_LPF_A1H                   _B_LPF_A1.Overlap_STR.B_LPF_A1HSTR.Byte
    

    /*** B_LPF_A1L - Low Pass Filter Coefficient A1 low; 0x00000E83 ***/
    union {
      byte Byte;
    } B_LPF_A1LSTR;
    #define B_LPF_A1L                   _B_LPF_A1.Overlap_STR.B_LPF_A1LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A1STR;
extern volatile B_LPF_A1STR _B_LPF_A1 @0x00000E82;
#define B_LPF_A1                        _B_LPF_A1.Word


/*** B_LPF_A2 - Low Pass Filter Coefficient A2; 0x00000E84 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A2H - Low Pass Filter Coefficient A2 high; 0x00000E84 ***/
    union {
      byte Byte;
    } B_LPF_A2HSTR;
    #define B_LPF_A2H                   _B_LPF_A2.Overlap_STR.B_LPF_A2HSTR.Byte
    

    /*** B_LPF_A2L - Low Pass Filter Coefficient A2 low; 0x00000E85 ***/
    union {
      byte Byte;
    } B_LPF_A2LSTR;
    #define B_LPF_A2L                   _B_LPF_A2.Overlap_STR.B_LPF_A2LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A2STR;
extern volatile B_LPF_A2STR _B_LPF_A2 @0x00000E84;
#define B_LPF_A2                        _B_LPF_A2.Word


/*** B_LPF_A3 - Low Pass Filter Coefficient A3; 0x00000E86 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A3H - Low Pass Filter Coefficient A3 high; 0x00000E86 ***/
    union {
      byte Byte;
    } B_LPF_A3HSTR;
    #define B_LPF_A3H                   _B_LPF_A3.Overlap_STR.B_LPF_A3HSTR.Byte
    

    /*** B_LPF_A3L - Low Pass Filter Coefficient A3 low; 0x00000E87 ***/
    union {
      byte Byte;
    } B_LPF_A3LSTR;
    #define B_LPF_A3L                   _B_LPF_A3.Overlap_STR.B_LPF_A3LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A3STR;
extern volatile B_LPF_A3STR _B_LPF_A3 @0x00000E86;
#define B_LPF_A3                        _B_LPF_A3.Word


/*** B_LPF_A4 - Low Pass Filter Coefficient A4; 0x00000E88 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A4H - Low Pass Filter Coefficient A4 high; 0x00000E88 ***/
    union {
      byte Byte;
    } B_LPF_A4HSTR;
    #define B_LPF_A4H                   _B_LPF_A4.Overlap_STR.B_LPF_A4HSTR.Byte
    

    /*** B_LPF_A4L - Low Pass Filter Coefficient A4 low; 0x00000E89 ***/
    union {
      byte Byte;
    } B_LPF_A4LSTR;
    #define B_LPF_A4L                   _B_LPF_A4.Overlap_STR.B_LPF_A4LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A4STR;
extern volatile B_LPF_A4STR _B_LPF_A4 @0x00000E88;
#define B_LPF_A4                        _B_LPF_A4.Word


/*** B_LPF_A5 - Low Pass Filter Coefficient A5; 0x00000E8A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A5H - Low Pass Filter Coefficient A5 high; 0x00000E8A ***/
    union {
      byte Byte;
    } B_LPF_A5HSTR;
    #define B_LPF_A5H                   _B_LPF_A5.Overlap_STR.B_LPF_A5HSTR.Byte
    

    /*** B_LPF_A5L - Low Pass Filter Coefficient A5 low; 0x00000E8B ***/
    union {
      byte Byte;
    } B_LPF_A5LSTR;
    #define B_LPF_A5L                   _B_LPF_A5.Overlap_STR.B_LPF_A5LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A5STR;
extern volatile B_LPF_A5STR _B_LPF_A5 @0x00000E8A;
#define B_LPF_A5                        _B_LPF_A5.Word


/*** B_LPF_A6 - Low Pass Filter Coefficient A6; 0x00000E8C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A6H - Low Pass Filter Coefficient A6 high; 0x00000E8C ***/
    union {
      byte Byte;
    } B_LPF_A6HSTR;
    #define B_LPF_A6H                   _B_LPF_A6.Overlap_STR.B_LPF_A6HSTR.Byte
    

    /*** B_LPF_A6L - Low Pass Filter Coefficient A6 low; 0x00000E8D ***/
    union {
      byte Byte;
    } B_LPF_A6LSTR;
    #define B_LPF_A6L                   _B_LPF_A6.Overlap_STR.B_LPF_A6LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A6STR;
extern volatile B_LPF_A6STR _B_LPF_A6 @0x00000E8C;
#define B_LPF_A6                        _B_LPF_A6.Word


/*** B_LPF_A7 - Low Pass Filter Coefficient A7; 0x00000E8E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A7H - Low Pass Filter Coefficient A7 high; 0x00000E8E ***/
    union {
      byte Byte;
    } B_LPF_A7HSTR;
    #define B_LPF_A7H                   _B_LPF_A7.Overlap_STR.B_LPF_A7HSTR.Byte
    

    /*** B_LPF_A7L - Low Pass Filter Coefficient A7 low; 0x00000E8F ***/
    union {
      byte Byte;
    } B_LPF_A7LSTR;
    #define B_LPF_A7L                   _B_LPF_A7.Overlap_STR.B_LPF_A7LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A7STR;
extern volatile B_LPF_A7STR _B_LPF_A7 @0x00000E8E;
#define B_LPF_A7                        _B_LPF_A7.Word


/*** B_LPF_A8 - Low Pass Filter Coefficient A8; 0x00000E90 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A8H - Low Pass Filter Coefficient A8 high; 0x00000E90 ***/
    union {
      byte Byte;
    } B_LPF_A8HSTR;
    #define B_LPF_A8H                   _B_LPF_A8.Overlap_STR.B_LPF_A8HSTR.Byte
    

    /*** B_LPF_A8L - Low Pass Filter Coefficient A8 low; 0x00000E91 ***/
    union {
      byte Byte;
    } B_LPF_A8LSTR;
    #define B_LPF_A8L                   _B_LPF_A8.Overlap_STR.B_LPF_A8LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A8STR;
extern volatile B_LPF_A8STR _B_LPF_A8 @0x00000E90;
#define B_LPF_A8                        _B_LPF_A8.Word


/*** B_LPF_A9 - Low Pass Filter Coefficient A9; 0x00000E92 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A9H - Low Pass Filter Coefficient A9 high; 0x00000E92 ***/
    union {
      byte Byte;
    } B_LPF_A9HSTR;
    #define B_LPF_A9H                   _B_LPF_A9.Overlap_STR.B_LPF_A9HSTR.Byte
    

    /*** B_LPF_A9L - Low Pass Filter Coefficient A9 low; 0x00000E93 ***/
    union {
      byte Byte;
    } B_LPF_A9LSTR;
    #define B_LPF_A9L                   _B_LPF_A9.Overlap_STR.B_LPF_A9LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A9STR;
extern volatile B_LPF_A9STR _B_LPF_A9 @0x00000E92;
#define B_LPF_A9                        _B_LPF_A9.Word


/*** B_LPF_A10 - Low Pass Filter Coefficient A10; 0x00000E94 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A10H - Low Pass Filter Coefficient A10 high; 0x00000E94 ***/
    union {
      byte Byte;
    } B_LPF_A10HSTR;
    #define B_LPF_A10H                  _B_LPF_A10.Overlap_STR.B_LPF_A10HSTR.Byte
    

    /*** B_LPF_A10L - Low Pass Filter Coefficient A10 low; 0x00000E95 ***/
    union {
      byte Byte;
    } B_LPF_A10LSTR;
    #define B_LPF_A10L                  _B_LPF_A10.Overlap_STR.B_LPF_A10LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A10STR;
extern volatile B_LPF_A10STR _B_LPF_A10 @0x00000E94;
#define B_LPF_A10                       _B_LPF_A10.Word


/*** B_LPF_A11 - Low Pass Filter Coefficient A11; 0x00000E96 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A11H - Low Pass Filter Coefficient A11 high; 0x00000E96 ***/
    union {
      byte Byte;
    } B_LPF_A11HSTR;
    #define B_LPF_A11H                  _B_LPF_A11.Overlap_STR.B_LPF_A11HSTR.Byte
    

    /*** B_LPF_A11L - Low Pass Filter Coefficient A11 low; 0x00000E97 ***/
    union {
      byte Byte;
    } B_LPF_A11LSTR;
    #define B_LPF_A11L                  _B_LPF_A11.Overlap_STR.B_LPF_A11LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A11STR;
extern volatile B_LPF_A11STR _B_LPF_A11 @0x00000E96;
#define B_LPF_A11                       _B_LPF_A11.Word


/*** B_LPF_A12 - Low Pass Filter Coefficient A12; 0x00000E98 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A12H - Low Pass Filter Coefficient A12 high; 0x00000E98 ***/
    union {
      byte Byte;
    } B_LPF_A12HSTR;
    #define B_LPF_A12H                  _B_LPF_A12.Overlap_STR.B_LPF_A12HSTR.Byte
    

    /*** B_LPF_A12L - Low Pass Filter Coefficient A12 low; 0x00000E99 ***/
    union {
      byte Byte;
    } B_LPF_A12LSTR;
    #define B_LPF_A12L                  _B_LPF_A12.Overlap_STR.B_LPF_A12LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A12STR;
extern volatile B_LPF_A12STR _B_LPF_A12 @0x00000E98;
#define B_LPF_A12                       _B_LPF_A12.Word


/*** B_LPF_A13 - Low Pass Filter Coefficient A13; 0x00000E9A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A13H - Low Pass Filter Coefficient A13 high; 0x00000E9A ***/
    union {
      byte Byte;
    } B_LPF_A13HSTR;
    #define B_LPF_A13H                  _B_LPF_A13.Overlap_STR.B_LPF_A13HSTR.Byte
    

    /*** B_LPF_A13L - Low Pass Filter Coefficient A13 low; 0x00000E9B ***/
    union {
      byte Byte;
    } B_LPF_A13LSTR;
    #define B_LPF_A13L                  _B_LPF_A13.Overlap_STR.B_LPF_A13LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A13STR;
extern volatile B_LPF_A13STR _B_LPF_A13 @0x00000E9A;
#define B_LPF_A13                       _B_LPF_A13.Word


/*** B_LPF_A14 - Low Pass Filter Coefficient A14; 0x00000E9C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A14H - Low Pass Filter Coefficient A14 high; 0x00000E9C ***/
    union {
      byte Byte;
    } B_LPF_A14HSTR;
    #define B_LPF_A14H                  _B_LPF_A14.Overlap_STR.B_LPF_A14HSTR.Byte
    

    /*** B_LPF_A14L - Low Pass Filter Coefficient A14 low; 0x00000E9D ***/
    union {
      byte Byte;
    } B_LPF_A14LSTR;
    #define B_LPF_A14L                  _B_LPF_A14.Overlap_STR.B_LPF_A14LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A14STR;
extern volatile B_LPF_A14STR _B_LPF_A14 @0x00000E9C;
#define B_LPF_A14                       _B_LPF_A14.Word


/*** B_LPF_A15 - Low Pass Filter Coefficient A15; 0x00000E9E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_LPF_A15H - Low Pass Filter Coefficient A15 high; 0x00000E9E ***/
    union {
      byte Byte;
    } B_LPF_A15HSTR;
    #define B_LPF_A15H                  _B_LPF_A15.Overlap_STR.B_LPF_A15HSTR.Byte
    

    /*** B_LPF_A15L - Low Pass Filter Coefficient A15 low; 0x00000E9F ***/
    union {
      byte Byte;
    } B_LPF_A15LSTR;
    #define B_LPF_A15L                  _B_LPF_A15.Overlap_STR.B_LPF_A15LSTR.Byte
    
  } Overlap_STR;

} B_LPF_A15STR;
extern volatile B_LPF_A15STR _B_LPF_A15 @0x00000E9E;
#define B_LPF_A15                       _B_LPF_A15.Word


/*** B_COMP_CTL - Compensation control register; 0x00000EA0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_CTLH - Compensation control register high; 0x00000EA0 ***/
    union {
      byte Byte;
      struct {
        byte CALIEM      :1;                                       /* Calibration IRQ Enable - Mask */
        byte DIAGTM      :1; 
        byte DIAGIM      :1;                                       /* Diagnostic Mode Current Channel - Mask */
        byte DIAGVM      :1;                                       /* Diagnostic Mode Voltage Channel - Mask */
        byte PGAOM       :1;                                       /* PGA Offset Calibration - Mask */
        byte PGAZM       :1;                                       /* PGA Input Zero - Mask */
        byte             :1; 
        byte OPENEM      :1; 
      } Bits;
    } B_COMP_CTLHSTR;
    #define B_COMP_CTLH                 _B_COMP_CTL.Overlap_STR.B_COMP_CTLHSTR.Byte
    #define B_COMP_CTLH_CALIEM          _B_COMP_CTL.Overlap_STR.B_COMP_CTLHSTR.Bits.CALIEM
    #define B_COMP_CTLH_DIAGTM          _B_COMP_CTL.Overlap_STR.B_COMP_CTLHSTR.Bits.DIAGTM
    #define B_COMP_CTLH_DIAGIM          _B_COMP_CTL.Overlap_STR.B_COMP_CTLHSTR.Bits.DIAGIM
    #define B_COMP_CTLH_DIAGVM          _B_COMP_CTL.Overlap_STR.B_COMP_CTLHSTR.Bits.DIAGVM
    #define B_COMP_CTLH_PGAOM           _B_COMP_CTL.Overlap_STR.B_COMP_CTLHSTR.Bits.PGAOM
    #define B_COMP_CTLH_PGAZM           _B_COMP_CTL.Overlap_STR.B_COMP_CTLHSTR.Bits.PGAZM
    #define B_COMP_CTLH_OPENEM          _B_COMP_CTL.Overlap_STR.B_COMP_CTLHSTR.Bits.OPENEM
    
    #define B_COMP_CTLH_CALIEM_MASK     1U
    #define B_COMP_CTLH_DIAGTM_MASK     2U
    #define B_COMP_CTLH_DIAGIM_MASK     4U
    #define B_COMP_CTLH_DIAGVM_MASK     8U
    #define B_COMP_CTLH_PGAOM_MASK      16U
    #define B_COMP_CTLH_PGAZM_MASK      32U
    #define B_COMP_CTLH_OPENEM_MASK     128U
    

    /*** B_COMP_CTLL - Compensation control register low; 0x00000EA1 ***/
    union {
      byte Byte;
      struct {
        byte CALIE       :1;                                       /* Calibration IRQ Enable */
        byte DIAGT       :1; 
        byte DIAGI       :1;                                       /* Diagnostic Mode Current Channel */
        byte DIAGV       :1;                                       /* Diagnostic Mode Voltage Channel */
        byte PGAO        :1;                                       /* PGA Offset Calibration Start */
        byte PGAZ        :1;                                       /* PGA Input Zero */
        byte             :1; 
        byte OPENE       :1; 
      } Bits;
    } B_COMP_CTLLSTR;
    #define B_COMP_CTLL                 _B_COMP_CTL.Overlap_STR.B_COMP_CTLLSTR.Byte
    #define B_COMP_CTLL_CALIE           _B_COMP_CTL.Overlap_STR.B_COMP_CTLLSTR.Bits.CALIE
    #define B_COMP_CTLL_DIAGT           _B_COMP_CTL.Overlap_STR.B_COMP_CTLLSTR.Bits.DIAGT
    #define B_COMP_CTLL_DIAGI           _B_COMP_CTL.Overlap_STR.B_COMP_CTLLSTR.Bits.DIAGI
    #define B_COMP_CTLL_DIAGV           _B_COMP_CTL.Overlap_STR.B_COMP_CTLLSTR.Bits.DIAGV
    #define B_COMP_CTLL_PGAO            _B_COMP_CTL.Overlap_STR.B_COMP_CTLLSTR.Bits.PGAO
    #define B_COMP_CTLL_PGAZ            _B_COMP_CTL.Overlap_STR.B_COMP_CTLLSTR.Bits.PGAZ
    #define B_COMP_CTLL_OPENE           _B_COMP_CTL.Overlap_STR.B_COMP_CTLLSTR.Bits.OPENE
    
    #define B_COMP_CTLL_CALIE_MASK      1U
    #define B_COMP_CTLL_DIAGT_MASK      2U
    #define B_COMP_CTLL_DIAGI_MASK      4U
    #define B_COMP_CTLL_DIAGV_MASK      8U
    #define B_COMP_CTLL_PGAO_MASK       16U
    #define B_COMP_CTLL_PGAZ_MASK       32U
    #define B_COMP_CTLL_OPENE_MASK      128U
    
  } Overlap_STR;

  struct {
    word CALIE       :1;                                       /* Calibration IRQ Enable */
    word DIAGT       :1; 
    word DIAGI       :1;                                       /* Diagnostic Mode Current Channel */
    word DIAGV       :1;                                       /* Diagnostic Mode Voltage Channel */
    word PGAO        :1;                                       /* PGA Offset Calibration Start */
    word PGAZ        :1;                                       /* PGA Input Zero */
    word             :1; 
    word OPENE       :1; 
    word CALIEM      :1;                                       /* Calibration IRQ Enable - Mask */
    word DIAGTM      :1; 
    word DIAGIM      :1;                                       /* Diagnostic Mode Current Channel - Mask */
    word DIAGVM      :1;                                       /* Diagnostic Mode Voltage Channel - Mask */
    word PGAOM       :1;                                       /* PGA Offset Calibration - Mask */
    word PGAZM       :1;                                       /* PGA Input Zero - Mask */
    word             :1; 
    word OPENEM      :1; 
  } Bits;
} B_COMP_CTLSTR;
extern volatile B_COMP_CTLSTR _B_COMP_CTL @0x00000EA0;
#define B_COMP_CTL                      _B_COMP_CTL.Word
#define B_COMP_CTL_CALIE                _B_COMP_CTL.Bits.CALIE
#define B_COMP_CTL_DIAGT                _B_COMP_CTL.Bits.DIAGT
#define B_COMP_CTL_DIAGI                _B_COMP_CTL.Bits.DIAGI
#define B_COMP_CTL_DIAGV                _B_COMP_CTL.Bits.DIAGV
#define B_COMP_CTL_PGAO                 _B_COMP_CTL.Bits.PGAO
#define B_COMP_CTL_PGAZ                 _B_COMP_CTL.Bits.PGAZ
#define B_COMP_CTL_OPENE                _B_COMP_CTL.Bits.OPENE
#define B_COMP_CTL_CALIEM               _B_COMP_CTL.Bits.CALIEM
#define B_COMP_CTL_DIAGTM               _B_COMP_CTL.Bits.DIAGTM
#define B_COMP_CTL_DIAGIM               _B_COMP_CTL.Bits.DIAGIM
#define B_COMP_CTL_DIAGVM               _B_COMP_CTL.Bits.DIAGVM
#define B_COMP_CTL_PGAOM                _B_COMP_CTL.Bits.PGAOM
#define B_COMP_CTL_PGAZM                _B_COMP_CTL.Bits.PGAZM
#define B_COMP_CTL_OPENEM               _B_COMP_CTL.Bits.OPENEM

#define B_COMP_CTL_CALIE_MASK           1U
#define B_COMP_CTL_DIAGT_MASK           2U
#define B_COMP_CTL_DIAGI_MASK           4U
#define B_COMP_CTL_DIAGV_MASK           8U
#define B_COMP_CTL_PGAO_MASK            16U
#define B_COMP_CTL_PGAZ_MASK            32U
#define B_COMP_CTL_OPENE_MASK           128U
#define B_COMP_CTL_CALIEM_MASK          256U
#define B_COMP_CTL_DIAGTM_MASK          512U
#define B_COMP_CTL_DIAGIM_MASK          1024U
#define B_COMP_CTL_DIAGVM_MASK          2048U
#define B_COMP_CTL_PGAOM_MASK           4096U
#define B_COMP_CTL_PGAZM_MASK           8192U
#define B_COMP_CTL_OPENEM_MASK          32768U


/*** B_COMP_SR - Compensation status register; 0x00000EA2 ***/
typedef union {
  byte Byte;
  struct {
    byte CALF        :1;                                       /* Calibration Request Status Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PGAOF       :1;                                       /* PGA Internal Offset Compensation Complete Flag */
    byte             :1; 
    byte BGRF        :1;                                       /* Band Gap Reference Status Flag */
    byte OPEN        :1; 
  } Bits;
} B_COMP_SRSTR;
extern volatile B_COMP_SRSTR _B_COMP_SR @0x00000EA2;
#define B_COMP_SR                       _B_COMP_SR.Byte
#define B_COMP_SR_CALF                  _B_COMP_SR.Bits.CALF
#define B_COMP_SR_PGAOF                 _B_COMP_SR.Bits.PGAOF
#define B_COMP_SR_BGRF                  _B_COMP_SR.Bits.BGRF
#define B_COMP_SR_OPEN                  _B_COMP_SR.Bits.OPEN

#define B_COMP_SR_CALF_MASK             1U
#define B_COMP_SR_PGAOF_MASK            16U
#define B_COMP_SR_BGRF_MASK             64U
#define B_COMP_SR_OPEN_MASK             128U


/*** B_COMP_TF - Temperature filtering period; 0x00000EA3 ***/
typedef union {
  byte Byte;
  struct {
    byte TMF         :3;                                       /* Recalibration Temperature Filtering Period */
    byte ATGCE       :1; 
    byte IRSEL       :3; 
    byte             :1; 
  } Bits;
} B_COMP_TFSTR;
extern volatile B_COMP_TFSTR _B_COMP_TF @0x00000EA3;
#define B_COMP_TF                       _B_COMP_TF.Byte
#define B_COMP_TF_TMF                   _B_COMP_TF.Bits.TMF
#define B_COMP_TF_ATGCE                 _B_COMP_TF.Bits.ATGCE
#define B_COMP_TF_IRSEL                 _B_COMP_TF.Bits.IRSEL

#define B_COMP_TF_TMF_MASK              7U
#define B_COMP_TF_TMF_BITNUM            0U
#define B_COMP_TF_ATGCE_MASK            8U
#define B_COMP_TF_IRSEL_MASK            112U
#define B_COMP_TF_IRSEL_BITNUM          4U


/*** B_COMP_TMAX - Max temp before recalibration; 0x00000EA4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_TMAXH - Max temp before recalibration high; 0x00000EA4 ***/
    union {
      byte Byte;
    } B_COMP_TMAXHSTR;
    #define B_COMP_TMAXH                _B_COMP_TMAX.Overlap_STR.B_COMP_TMAXHSTR.Byte
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TCMAX       :8;                                       /* Maximum Temperature before recalibration */
  } Bits;
} B_COMP_TMAXSTR;
extern volatile B_COMP_TMAXSTR _B_COMP_TMAX @0x00000EA4;
#define B_COMP_TMAX                     _B_COMP_TMAX.Word
#define B_COMP_TMAX_TCMAX               _B_COMP_TMAX.Bits.TCMAX

#define B_COMP_TMAX_TCMAX_MASK          65280U
#define B_COMP_TMAX_TCMAX_BITNUM        8U


/*** B_COMP_TMIN - Min temp before recalibration; 0x00000EA6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_TMINH - Min temp before recalibration high; 0x00000EA6 ***/
    union {
      byte Byte;
    } B_COMP_TMINHSTR;
    #define B_COMP_TMINH                _B_COMP_TMIN.Overlap_STR.B_COMP_TMINHSTR.Byte
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TCMIN       :8;                                       /* Minimum Temperature before recalibration */
  } Bits;
} B_COMP_TMINSTR;
extern volatile B_COMP_TMINSTR _B_COMP_TMIN @0x00000EA6;
#define B_COMP_TMIN                     _B_COMP_TMIN.Word
#define B_COMP_TMIN_TCMIN               _B_COMP_TMIN.Bits.TCMIN

#define B_COMP_TMIN_TCMIN_MASK          65280U
#define B_COMP_TMIN_TCMIN_BITNUM        8U


/*** B_COMP_VO - Offset voltage compensation; 0x00000EAA ***/
typedef union {
  byte Byte;
} B_COMP_VOSTR;
extern volatile B_COMP_VOSTR _B_COMP_VO @0x00000EAA;
#define B_COMP_VO                       _B_COMP_VO.Byte


/*** B_COMP_IO - Offset current compensation window; 0x00000EAB ***/
typedef union {
  byte Byte;
} B_COMP_IOSTR;
extern volatile B_COMP_IOSTR _B_COMP_IO @0x00000EAB;
#define B_COMP_IO                       _B_COMP_IO.Byte


/*** B_COMP_VSG - Gain voltage compensation vsense channel; 0x00000EAC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_VSGH - Gain voltage compensation vsense channel high; 0x00000EAC ***/
    union {
      byte Byte;
      struct {
        byte VSGC        :2;                                       /* Voltage Channel Gain Compensation Buffer */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_VSGHSTR;
    #define B_COMP_VSGH                 _B_COMP_VSG.Overlap_STR.B_COMP_VSGHSTR.Byte
    #define B_COMP_VSGH_VSGC            _B_COMP_VSG.Overlap_STR.B_COMP_VSGHSTR.Bits.VSGC
    
    #define B_COMP_VSGH_VSGC_MASK       3U
    #define B_COMP_VSGH_VSGC_BITNUM     0U
    

    /*** B_COMP_VSGL - Gain voltage compensation vsense channel low; 0x00000EAD ***/
    union {
      byte Byte;
    } B_COMP_VSGLSTR;
    #define B_COMP_VSGL                 _B_COMP_VSG.Overlap_STR.B_COMP_VSGLSTR.Byte
    
  } Overlap_STR;

  struct {
    word VSGC        :10;                                      /* Voltage Channel Gain Compensation Buffer */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_VSGSTR;
extern volatile B_COMP_VSGSTR _B_COMP_VSG @0x00000EAC;
#define B_COMP_VSG                      _B_COMP_VSG.Word
#define B_COMP_VSG_VSGC                 _B_COMP_VSG.Bits.VSGC

#define B_COMP_VSG_VSGC_MASK            1023U
#define B_COMP_VSG_VSGC_BITNUM          0U


/*** B_COMP_TVSG - Voltage Gain temp compensation; 0x00000EAE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_TVSGH - Voltage Gain temp compensation above 25 C; 0x00000EAE ***/
    union {
      byte Byte;
      struct {
        byte TVSGCP      :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_TVSGHSTR;
    #define B_COMP_TVSGH                _B_COMP_TVSG.Overlap_STR.B_COMP_TVSGHSTR.Byte
    #define B_COMP_TVSGH_TVSGCP         _B_COMP_TVSG.Overlap_STR.B_COMP_TVSGHSTR.Bits.TVSGCP
    
    #define B_COMP_TVSGH_TVSGCP_MASK    31U
    #define B_COMP_TVSGH_TVSGCP_BITNUM  0U
    

    /*** B_COMP_TVSGL - Voltage Gain temp compensation below 25 C; 0x00000EAF ***/
    union {
      byte Byte;
      struct {
        byte TVSGCN      :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_TVSGLSTR;
    #define B_COMP_TVSGL                _B_COMP_TVSG.Overlap_STR.B_COMP_TVSGLSTR.Byte
    #define B_COMP_TVSGL_TVSGCN         _B_COMP_TVSG.Overlap_STR.B_COMP_TVSGLSTR.Bits.TVSGCN
    
    #define B_COMP_TVSGL_TVSGCN_MASK    31U
    #define B_COMP_TVSGL_TVSGCN_BITNUM  0U
    
  } Overlap_STR;

  struct {
    word TVSGCN      :5; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TVSGCP      :5; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_TVSGSTR;
extern volatile B_COMP_TVSGSTR _B_COMP_TVSG @0x00000EAE;
#define B_COMP_TVSG                     _B_COMP_TVSG.Word
#define B_COMP_TVSG_TVSGCN              _B_COMP_TVSG.Bits.TVSGCN
#define B_COMP_TVSG_TVSGCP              _B_COMP_TVSG.Bits.TVSGCP

#define B_COMP_TVSG_TVSGCN_MASK         31U
#define B_COMP_TVSG_TVSGCN_BITNUM       0U
#define B_COMP_TVSG_TVSGCP_MASK         7936U
#define B_COMP_TVSG_TVSGCP_BITNUM       8U


/*** B_COMP_IG4 - Gain Current Compensation 4; 0x00000EB0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_IG4H - Gain Current Compensation 4 high byte; 0x00000EB0 ***/
    union {
      byte Byte;
      struct {
        byte IGC4        :2;                                       /* Current Gain Compensation Buffer 4 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_IG4HSTR;
    #define B_COMP_IG4H                 _B_COMP_IG4.Overlap_STR.B_COMP_IG4HSTR.Byte
    #define B_COMP_IG4H_IGC4            _B_COMP_IG4.Overlap_STR.B_COMP_IG4HSTR.Bits.IGC4
    
    #define B_COMP_IG4H_IGC4_MASK       3U
    #define B_COMP_IG4H_IGC4_BITNUM     0U
    

    /*** B_COMP_IG4L - Gain Current Compensation 4 low byte; 0x00000EB1 ***/
    union {
      byte Byte;
    } B_COMP_IG4LSTR;
    #define B_COMP_IG4L                 _B_COMP_IG4.Overlap_STR.B_COMP_IG4LSTR.Byte
    
  } Overlap_STR;

  struct {
    word IGC4        :10;                                      /* Current Gain Compensation Buffer 4 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_IG4STR;
extern volatile B_COMP_IG4STR _B_COMP_IG4 @0x00000EB0;
#define B_COMP_IG4                      _B_COMP_IG4.Word
#define B_COMP_IG4_IGC4                 _B_COMP_IG4.Bits.IGC4

#define B_COMP_IG4_IGC4_MASK            1023U
#define B_COMP_IG4_IGC4_BITNUM          0U


/*** B_COMP_TIG4 - Current Gain temp compensation; 0x00000EB2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_TIG4H - Current Gain temp compensation above 25 C; 0x00000EB2 ***/
    union {
      byte Byte;
      struct {
        byte TIGC4P      :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_TIG4HSTR;
    #define B_COMP_TIG4H                _B_COMP_TIG4.Overlap_STR.B_COMP_TIG4HSTR.Byte
    #define B_COMP_TIG4H_TIGC4P         _B_COMP_TIG4.Overlap_STR.B_COMP_TIG4HSTR.Bits.TIGC4P
    
    #define B_COMP_TIG4H_TIGC4P_MASK    31U
    #define B_COMP_TIG4H_TIGC4P_BITNUM  0U
    

    /*** B_COMP_TIG4L - Current Gain temp compensation below 25 C; 0x00000EB3 ***/
    union {
      byte Byte;
      struct {
        byte TIGC4N      :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_TIG4LSTR;
    #define B_COMP_TIG4L                _B_COMP_TIG4.Overlap_STR.B_COMP_TIG4LSTR.Byte
    #define B_COMP_TIG4L_TIGC4N         _B_COMP_TIG4.Overlap_STR.B_COMP_TIG4LSTR.Bits.TIGC4N
    
    #define B_COMP_TIG4L_TIGC4N_MASK    31U
    #define B_COMP_TIG4L_TIGC4N_BITNUM  0U
    
  } Overlap_STR;

  struct {
    word TIGC4N      :5; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TIGC4P      :5; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_TIG4STR;
extern volatile B_COMP_TIG4STR _B_COMP_TIG4 @0x00000EB2;
#define B_COMP_TIG4                     _B_COMP_TIG4.Word
#define B_COMP_TIG4_TIGC4N              _B_COMP_TIG4.Bits.TIGC4N
#define B_COMP_TIG4_TIGC4P              _B_COMP_TIG4.Bits.TIGC4P

#define B_COMP_TIG4_TIGC4N_MASK         31U
#define B_COMP_TIG4_TIGC4N_BITNUM       0U
#define B_COMP_TIG4_TIGC4P_MASK         7936U
#define B_COMP_TIG4_TIGC4P_BITNUM       8U


/*** B_COMP_IG16 - Gain Current Compensation 16; 0x00000EB4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_IG16H - Gain Current Compensation 16 high byte; 0x00000EB4 ***/
    union {
      byte Byte;
      struct {
        byte IGC16       :2;                                       /* Current Gain Compensation Buffer 16 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_IG16HSTR;
    #define B_COMP_IG16H                _B_COMP_IG16.Overlap_STR.B_COMP_IG16HSTR.Byte
    #define B_COMP_IG16H_IGC16          _B_COMP_IG16.Overlap_STR.B_COMP_IG16HSTR.Bits.IGC16
    
    #define B_COMP_IG16H_IGC16_MASK     3U
    #define B_COMP_IG16H_IGC16_BITNUM   0U
    

    /*** B_COMP_IG16L - Gain Current Compensation 16 low byte; 0x00000EB5 ***/
    union {
      byte Byte;
    } B_COMP_IG16LSTR;
    #define B_COMP_IG16L                _B_COMP_IG16.Overlap_STR.B_COMP_IG16LSTR.Byte
    
  } Overlap_STR;

  struct {
    word IGC16       :10;                                      /* Current Gain Compensation Buffer 16 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_IG16STR;
extern volatile B_COMP_IG16STR _B_COMP_IG16 @0x00000EB4;
#define B_COMP_IG16                     _B_COMP_IG16.Word
#define B_COMP_IG16_IGC16               _B_COMP_IG16.Bits.IGC16

#define B_COMP_IG16_IGC16_MASK          1023U
#define B_COMP_IG16_IGC16_BITNUM        0U


/*** B_COMP_TIG16 - Current Gain temp compensation; 0x00000EB6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_TIG16H - Current Gain temp compensation above 25 C; 0x00000EB6 ***/
    union {
      byte Byte;
      struct {
        byte TIGC16P     :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_TIG16HSTR;
    #define B_COMP_TIG16H               _B_COMP_TIG16.Overlap_STR.B_COMP_TIG16HSTR.Byte
    #define B_COMP_TIG16H_TIGC16P       _B_COMP_TIG16.Overlap_STR.B_COMP_TIG16HSTR.Bits.TIGC16P
    
    #define B_COMP_TIG16H_TIGC16P_MASK  31U
    #define B_COMP_TIG16H_TIGC16P_BITNUM 0U
    

    /*** B_COMP_TIG16L - Current Gain temp compensation below 25 C; 0x00000EB7 ***/
    union {
      byte Byte;
      struct {
        byte TIGC16N     :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_TIG16LSTR;
    #define B_COMP_TIG16L               _B_COMP_TIG16.Overlap_STR.B_COMP_TIG16LSTR.Byte
    #define B_COMP_TIG16L_TIGC16N       _B_COMP_TIG16.Overlap_STR.B_COMP_TIG16LSTR.Bits.TIGC16N
    
    #define B_COMP_TIG16L_TIGC16N_MASK  31U
    #define B_COMP_TIG16L_TIGC16N_BITNUM 0U
    
  } Overlap_STR;

  struct {
    word TIGC16N     :5; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TIGC16P     :5; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_TIG16STR;
extern volatile B_COMP_TIG16STR _B_COMP_TIG16 @0x00000EB6;
#define B_COMP_TIG16                    _B_COMP_TIG16.Word
#define B_COMP_TIG16_TIGC16N            _B_COMP_TIG16.Bits.TIGC16N
#define B_COMP_TIG16_TIGC16P            _B_COMP_TIG16.Bits.TIGC16P

#define B_COMP_TIG16_TIGC16N_MASK       31U
#define B_COMP_TIG16_TIGC16N_BITNUM     0U
#define B_COMP_TIG16_TIGC16P_MASK       7936U
#define B_COMP_TIG16_TIGC16P_BITNUM     8U


/*** B_COMP_IG64 - Gain Current Compensation 64; 0x00000EB8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_IG64H - Gain Current Compensation 64 high byte; 0x00000EB8 ***/
    union {
      byte Byte;
      struct {
        byte IGC64       :2;                                       /* Current Gain Compensation Buffer 64 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_IG64HSTR;
    #define B_COMP_IG64H                _B_COMP_IG64.Overlap_STR.B_COMP_IG64HSTR.Byte
    #define B_COMP_IG64H_IGC64          _B_COMP_IG64.Overlap_STR.B_COMP_IG64HSTR.Bits.IGC64
    
    #define B_COMP_IG64H_IGC64_MASK     3U
    #define B_COMP_IG64H_IGC64_BITNUM   0U
    

    /*** B_COMP_IG64L - Gain Current Compensation 64 low byte; 0x00000EB9 ***/
    union {
      byte Byte;
    } B_COMP_IG64LSTR;
    #define B_COMP_IG64L                _B_COMP_IG64.Overlap_STR.B_COMP_IG64LSTR.Byte
    
  } Overlap_STR;

  struct {
    word IGC64       :10;                                      /* Current Gain Compensation Buffer 64 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_IG64STR;
extern volatile B_COMP_IG64STR _B_COMP_IG64 @0x00000EB8;
#define B_COMP_IG64                     _B_COMP_IG64.Word
#define B_COMP_IG64_IGC64               _B_COMP_IG64.Bits.IGC64

#define B_COMP_IG64_IGC64_MASK          1023U
#define B_COMP_IG64_IGC64_BITNUM        0U


/*** B_COMP_TIG64 - Current Gain temp compensation; 0x00000EBA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_TIG64H - Current Gain temp compensation above 25 C; 0x00000EBA ***/
    union {
      byte Byte;
      struct {
        byte TIGC64P     :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_TIG64HSTR;
    #define B_COMP_TIG64H               _B_COMP_TIG64.Overlap_STR.B_COMP_TIG64HSTR.Byte
    #define B_COMP_TIG64H_TIGC64P       _B_COMP_TIG64.Overlap_STR.B_COMP_TIG64HSTR.Bits.TIGC64P
    
    #define B_COMP_TIG64H_TIGC64P_MASK  31U
    #define B_COMP_TIG64H_TIGC64P_BITNUM 0U
    

    /*** B_COMP_TIG64L - Current Gain temp compensation below 25 C; 0x00000EBB ***/
    union {
      byte Byte;
      struct {
        byte TIGC64N     :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_TIG64LSTR;
    #define B_COMP_TIG64L               _B_COMP_TIG64.Overlap_STR.B_COMP_TIG64LSTR.Byte
    #define B_COMP_TIG64L_TIGC64N       _B_COMP_TIG64.Overlap_STR.B_COMP_TIG64LSTR.Bits.TIGC64N
    
    #define B_COMP_TIG64L_TIGC64N_MASK  31U
    #define B_COMP_TIG64L_TIGC64N_BITNUM 0U
    
  } Overlap_STR;

  struct {
    word TIGC64N     :5; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TIGC64P     :5; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_TIG64STR;
extern volatile B_COMP_TIG64STR _B_COMP_TIG64 @0x00000EBA;
#define B_COMP_TIG64                    _B_COMP_TIG64.Word
#define B_COMP_TIG64_TIGC64N            _B_COMP_TIG64.Bits.TIGC64N
#define B_COMP_TIG64_TIGC64P            _B_COMP_TIG64.Bits.TIGC64P

#define B_COMP_TIG64_TIGC64N_MASK       31U
#define B_COMP_TIG64_TIGC64N_BITNUM     0U
#define B_COMP_TIG64_TIGC64P_MASK       7936U
#define B_COMP_TIG64_TIGC64P_BITNUM     8U


/*** B_COMP_IG256 - Gain Current Compensation 256; 0x00000EBC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_IG256H - Gain Current Compensation 256 high byte; 0x00000EBC ***/
    union {
      byte Byte;
      struct {
        byte IGC256      :2;                                       /* Current Gain Compensation Buffer 256 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_IG256HSTR;
    #define B_COMP_IG256H               _B_COMP_IG256.Overlap_STR.B_COMP_IG256HSTR.Byte
    #define B_COMP_IG256H_IGC256        _B_COMP_IG256.Overlap_STR.B_COMP_IG256HSTR.Bits.IGC256
    
    #define B_COMP_IG256H_IGC256_MASK   3U
    #define B_COMP_IG256H_IGC256_BITNUM 0U
    

    /*** B_COMP_IG256L - Gain Current Compensation 256 low byte; 0x00000EBD ***/
    union {
      byte Byte;
    } B_COMP_IG256LSTR;
    #define B_COMP_IG256L               _B_COMP_IG256.Overlap_STR.B_COMP_IG256LSTR.Byte
    
  } Overlap_STR;

  struct {
    word IGC256      :10;                                      /* Current Gain Compensation Buffer 256 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_IG256STR;
extern volatile B_COMP_IG256STR _B_COMP_IG256 @0x00000EBC;
#define B_COMP_IG256                    _B_COMP_IG256.Word
#define B_COMP_IG256_IGC256             _B_COMP_IG256.Bits.IGC256

#define B_COMP_IG256_IGC256_MASK        1023U
#define B_COMP_IG256_IGC256_BITNUM      0U


/*** B_COMP_TIG256 - Current Gain temp compensation; 0x00000EBE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_TIG256H - Current Gain temp compensation above 25 C; 0x00000EBE ***/
    union {
      byte Byte;
      struct {
        byte TIGC256P    :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_TIG256HSTR;
    #define B_COMP_TIG256H              _B_COMP_TIG256.Overlap_STR.B_COMP_TIG256HSTR.Byte
    #define B_COMP_TIG256H_TIGC256P     _B_COMP_TIG256.Overlap_STR.B_COMP_TIG256HSTR.Bits.TIGC256P
    
    #define B_COMP_TIG256H_TIGC256P_MASK 31U
    #define B_COMP_TIG256H_TIGC256P_BITNUM 0U
    

    /*** B_COMP_TIG256L - Current Gain temp compensation below 25 C; 0x00000EBF ***/
    union {
      byte Byte;
      struct {
        byte TIGC256N    :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_TIG256LSTR;
    #define B_COMP_TIG256L              _B_COMP_TIG256.Overlap_STR.B_COMP_TIG256LSTR.Byte
    #define B_COMP_TIG256L_TIGC256N     _B_COMP_TIG256.Overlap_STR.B_COMP_TIG256LSTR.Bits.TIGC256N
    
    #define B_COMP_TIG256L_TIGC256N_MASK 31U
    #define B_COMP_TIG256L_TIGC256N_BITNUM 0U
    
  } Overlap_STR;

  struct {
    word TIGC256N    :5; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TIGC256P    :5; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_TIG256STR;
extern volatile B_COMP_TIG256STR _B_COMP_TIG256 @0x00000EBE;
#define B_COMP_TIG256                   _B_COMP_TIG256.Word
#define B_COMP_TIG256_TIGC256N          _B_COMP_TIG256.Bits.TIGC256N
#define B_COMP_TIG256_TIGC256P          _B_COMP_TIG256.Bits.TIGC256P

#define B_COMP_TIG256_TIGC256N_MASK     31U
#define B_COMP_TIG256_TIGC256N_BITNUM   0U
#define B_COMP_TIG256_TIGC256P_MASK     7936U
#define B_COMP_TIG256_TIGC256P_BITNUM   8U


/*** B_COMP_PGAO4 - Offset PGA compensation 4; 0x00000EC0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_PGAO4H - Offset PGA compensation 4 high byte; 0x00000EC0 ***/
    union {
      byte Byte;
      struct {
        byte PGAOC4      :3;                                       /* PGA Offset Compensation Buffer 4 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_PGAO4HSTR;
    #define B_COMP_PGAO4H               _B_COMP_PGAO4.Overlap_STR.B_COMP_PGAO4HSTR.Byte
    #define B_COMP_PGAO4H_PGAOC4        _B_COMP_PGAO4.Overlap_STR.B_COMP_PGAO4HSTR.Bits.PGAOC4
    
    #define B_COMP_PGAO4H_PGAOC4_MASK   7U
    #define B_COMP_PGAO4H_PGAOC4_BITNUM 0U
    

    /*** B_COMP_PGAO4L - Offset PGA compensation 4 low byte; 0x00000EC1 ***/
    union {
      byte Byte;
    } B_COMP_PGAO4LSTR;
    #define B_COMP_PGAO4L               _B_COMP_PGAO4.Overlap_STR.B_COMP_PGAO4LSTR.Byte
    
  } Overlap_STR;

  struct {
    word PGAOC4      :11;                                      /* PGA Offset Compensation Buffer 4 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_PGAO4STR;
extern volatile B_COMP_PGAO4STR _B_COMP_PGAO4 @0x00000EC0;
#define B_COMP_PGAO4                    _B_COMP_PGAO4.Word
#define B_COMP_PGAO4_PGAOC4             _B_COMP_PGAO4.Bits.PGAOC4

#define B_COMP_PGAO4_PGAOC4_MASK        2047U
#define B_COMP_PGAO4_PGAOC4_BITNUM      0U


/*** B_COMP_PGAO16 - Offset PGA compensation 16; 0x00000EC4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_PGAO16H - Offset PGA compensation 16 high byte; 0x00000EC4 ***/
    union {
      byte Byte;
      struct {
        byte PGAOC16     :3;                                       /* PGA Offset Compensation Buffer 16 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_PGAO16HSTR;
    #define B_COMP_PGAO16H              _B_COMP_PGAO16.Overlap_STR.B_COMP_PGAO16HSTR.Byte
    #define B_COMP_PGAO16H_PGAOC16      _B_COMP_PGAO16.Overlap_STR.B_COMP_PGAO16HSTR.Bits.PGAOC16
    
    #define B_COMP_PGAO16H_PGAOC16_MASK 7U
    #define B_COMP_PGAO16H_PGAOC16_BITNUM 0U
    

    /*** B_COMP_PGAO16L - Offset PGA compensation 16 low byte; 0x00000EC5 ***/
    union {
      byte Byte;
    } B_COMP_PGAO16LSTR;
    #define B_COMP_PGAO16L              _B_COMP_PGAO16.Overlap_STR.B_COMP_PGAO16LSTR.Byte
    
  } Overlap_STR;

  struct {
    word PGAOC16     :11;                                      /* PGA Offset Compensation Buffer 16 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_PGAO16STR;
extern volatile B_COMP_PGAO16STR _B_COMP_PGAO16 @0x00000EC4;
#define B_COMP_PGAO16                   _B_COMP_PGAO16.Word
#define B_COMP_PGAO16_PGAOC16           _B_COMP_PGAO16.Bits.PGAOC16

#define B_COMP_PGAO16_PGAOC16_MASK      2047U
#define B_COMP_PGAO16_PGAOC16_BITNUM    0U


/*** B_COMP_PGAO64 - Offset PGA compensation 64; 0x00000EC8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_PGAO64H - Offset PGA compensation 64 high byte; 0x00000EC8 ***/
    union {
      byte Byte;
      struct {
        byte PGAOC64     :3;                                       /* PGA Offset Compensation Buffer 64 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_PGAO64HSTR;
    #define B_COMP_PGAO64H              _B_COMP_PGAO64.Overlap_STR.B_COMP_PGAO64HSTR.Byte
    #define B_COMP_PGAO64H_PGAOC64      _B_COMP_PGAO64.Overlap_STR.B_COMP_PGAO64HSTR.Bits.PGAOC64
    
    #define B_COMP_PGAO64H_PGAOC64_MASK 7U
    #define B_COMP_PGAO64H_PGAOC64_BITNUM 0U
    

    /*** B_COMP_PGAO64L - Offset PGA compensation 64 low byte; 0x00000EC9 ***/
    union {
      byte Byte;
    } B_COMP_PGAO64LSTR;
    #define B_COMP_PGAO64L              _B_COMP_PGAO64.Overlap_STR.B_COMP_PGAO64LSTR.Byte
    
  } Overlap_STR;

  struct {
    word PGAOC64     :11;                                      /* PGA Offset Compensation Buffer 64 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_PGAO64STR;
extern volatile B_COMP_PGAO64STR _B_COMP_PGAO64 @0x00000EC8;
#define B_COMP_PGAO64                   _B_COMP_PGAO64.Word
#define B_COMP_PGAO64_PGAOC64           _B_COMP_PGAO64.Bits.PGAOC64

#define B_COMP_PGAO64_PGAOC64_MASK      2047U
#define B_COMP_PGAO64_PGAOC64_BITNUM    0U


/*** B_COMP_PGAO256 - Offset PGA compensation 256; 0x00000ECC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** B_COMP_PGAO256H - Offset PGA compensation 256 high byte; 0x00000ECC ***/
    union {
      byte Byte;
      struct {
        byte PGAOC256    :3;                                       /* PGA Offset Compensation Buffer 256 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } B_COMP_PGAO256HSTR;
    #define B_COMP_PGAO256H             _B_COMP_PGAO256.Overlap_STR.B_COMP_PGAO256HSTR.Byte
    #define B_COMP_PGAO256H_PGAOC256    _B_COMP_PGAO256.Overlap_STR.B_COMP_PGAO256HSTR.Bits.PGAOC256
    
    #define B_COMP_PGAO256H_PGAOC256_MASK 7U
    #define B_COMP_PGAO256H_PGAOC256_BITNUM 0U
    

    /*** B_COMP_PGAO256L - Offset PGA compensation 256 low byte; 0x00000ECD ***/
    union {
      byte Byte;
    } B_COMP_PGAO256LSTR;
    #define B_COMP_PGAO256L             _B_COMP_PGAO256.Overlap_STR.B_COMP_PGAO256LSTR.Byte
    
  } Overlap_STR;

  struct {
    word PGAOC256    :11;                                      /* PGA Offset Compensation Buffer 256 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} B_COMP_PGAO256STR;
extern volatile B_COMP_PGAO256STR _B_COMP_PGAO256 @0x00000ECC;
#define B_COMP_PGAO256                  _B_COMP_PGAO256.Word
#define B_COMP_PGAO256_PGAOC256         _B_COMP_PGAO256.Bits.PGAOC256

#define B_COMP_PGAO256_PGAOC256_MASK    2047U
#define B_COMP_PGAO256_PGAOC256_BITNUM  0U


/*** B_COMP_ITO - Internal temperature offset compensation; 0x00000ED0 ***/
typedef union {
  byte Byte;
} B_COMP_ITOSTR;
extern volatile B_COMP_ITOSTR _B_COMP_ITO @0x00000ED0;
#define B_COMP_ITO                      _B_COMP_ITO.Byte


/*** B_COMP_ITG - Internal temperature gain compensation; 0x00000ED1 ***/
typedef union {
  byte Byte;
} B_COMP_ITGSTR;
extern volatile B_COMP_ITGSTR _B_COMP_ITG @0x00000ED1;
#define B_COMP_ITG                      _B_COMP_ITG.Byte


/*** B_COMP_ETO - External temperature offset compensation; 0x00000ED2 ***/
typedef union {
  byte Byte;
} B_COMP_ETOSTR;
extern volatile B_COMP_ETOSTR _B_COMP_ETO @0x00000ED2;
#define B_COMP_ETO                      _B_COMP_ETO.Byte


/*** B_COMP_ETG - External temperature gain compensation; 0x00000ED3 ***/
typedef union {
  byte Byte;
} B_COMP_ETGSTR;
extern volatile B_COMP_ETGSTR _B_COMP_ETG @0x00000ED3;
#define B_COMP_ETG                      _B_COMP_ETG.Byte


/*** B_TRIM_BG0H - Trim bandgap 0 high; 0x00000EE0 ***/
typedef union {
  byte Byte;
  struct {
    byte TCIBG1      :3; 
    byte TCIBG2      :3; 
    byte IBG1        :2; 
  } Bits;
} B_TRIM_BG0HSTR;
extern volatile B_TRIM_BG0HSTR _B_TRIM_BG0H @0x00000EE0;
#define B_TRIM_BG0H                     _B_TRIM_BG0H.Byte
#define B_TRIM_BG0H_TCIBG1              _B_TRIM_BG0H.Bits.TCIBG1
#define B_TRIM_BG0H_TCIBG2              _B_TRIM_BG0H.Bits.TCIBG2
#define B_TRIM_BG0H_IBG1                _B_TRIM_BG0H.Bits.IBG1

#define B_TRIM_BG0H_TCIBG1_MASK         7U
#define B_TRIM_BG0H_TCIBG1_BITNUM       0U
#define B_TRIM_BG0H_TCIBG2_MASK         56U
#define B_TRIM_BG0H_TCIBG2_BITNUM       3U
#define B_TRIM_BG0H_IBG1_MASK           192U
#define B_TRIM_BG0H_IBG1_BITNUM         6U


/*** B_TRIM_BG0L - Trim bandgap 0 low; 0x00000EE1 ***/
typedef union {
  byte Byte;
  struct {
    byte TCBG1       :3; 
    byte TCBG2       :3; 
    byte LVT         :1; 
    byte IBG1        :1; 
  } Bits;
} B_TRIM_BG0LSTR;
extern volatile B_TRIM_BG0LSTR _B_TRIM_BG0L @0x00000EE1;
#define B_TRIM_BG0L                     _B_TRIM_BG0L.Byte
#define B_TRIM_BG0L_TCBG1               _B_TRIM_BG0L.Bits.TCBG1
#define B_TRIM_BG0L_TCBG2               _B_TRIM_BG0L.Bits.TCBG2
#define B_TRIM_BG0L_LVT                 _B_TRIM_BG0L.Bits.LVT
#define B_TRIM_BG0L_IBG1                _B_TRIM_BG0L.Bits.IBG1

#define B_TRIM_BG0L_TCBG1_MASK          7U
#define B_TRIM_BG0L_TCBG1_BITNUM        0U
#define B_TRIM_BG0L_TCBG2_MASK          56U
#define B_TRIM_BG0L_TCBG2_BITNUM        3U
#define B_TRIM_BG0L_LVT_MASK            64U
#define B_TRIM_BG0L_IBG1_MASK           128U


/*** B_TRIM_BG1H - Trim bandgap 1 high; 0x00000EE2 ***/
typedef union {
  byte Byte;
  struct {
    byte V1P2BG1     :4; 
    byte V1P2BG2     :4; 
  } Bits;
} B_TRIM_BG1HSTR;
extern volatile B_TRIM_BG1HSTR _B_TRIM_BG1H @0x00000EE2;
#define B_TRIM_BG1H                     _B_TRIM_BG1H.Byte
#define B_TRIM_BG1H_V1P2BG1             _B_TRIM_BG1H.Bits.V1P2BG1
#define B_TRIM_BG1H_V1P2BG2             _B_TRIM_BG1H.Bits.V1P2BG2

#define B_TRIM_BG1H_V1P2BG1_MASK        15U
#define B_TRIM_BG1H_V1P2BG1_BITNUM      0U
#define B_TRIM_BG1H_V1P2BG2_MASK        240U
#define B_TRIM_BG1H_V1P2BG2_BITNUM      4U


/*** B_TRIM_BG1L - Trim bandgap 1 low; 0x00000EE3 ***/
typedef union {
  byte Byte;
  struct {
    byte V2P5BG1     :4; 
    byte VDDXLPMODE  :4; 
  } Bits;
} B_TRIM_BG1LSTR;
extern volatile B_TRIM_BG1LSTR _B_TRIM_BG1L @0x00000EE3;
#define B_TRIM_BG1L                     _B_TRIM_BG1L.Byte
#define B_TRIM_BG1L_V2P5BG1             _B_TRIM_BG1L.Bits.V2P5BG1
#define B_TRIM_BG1L_VDDXLPMODE          _B_TRIM_BG1L.Bits.VDDXLPMODE

#define B_TRIM_BG1L_V2P5BG1_MASK        15U
#define B_TRIM_BG1L_V2P5BG1_BITNUM      0U
#define B_TRIM_BG1L_VDDXLPMODE_MASK     240U
#define B_TRIM_BG1L_VDDXLPMODE_BITNUM   4U


/*** B_TRIM_OSCH - Trim LP oscillator high; 0x00000EE4 ***/
typedef union {
  byte Byte;
  struct {
    byte LPOSC       :5; 
    byte SLPBG       :3; 
  } Bits;
} B_TRIM_OSCHSTR;
extern volatile B_TRIM_OSCHSTR _B_TRIM_OSCH @0x00000EE4;
#define B_TRIM_OSCH                     _B_TRIM_OSCH.Byte
#define B_TRIM_OSCH_LPOSC               _B_TRIM_OSCH.Bits.LPOSC
#define B_TRIM_OSCH_SLPBG               _B_TRIM_OSCH.Bits.SLPBG

#define B_TRIM_OSCH_LPOSC_MASK          31U
#define B_TRIM_OSCH_LPOSC_BITNUM        0U
#define B_TRIM_OSCH_SLPBG_MASK          224U
#define B_TRIM_OSCH_SLPBG_BITNUM        5U


/*** B_TRIM_OSCL - Trim LP oscillator low; 0x00000EE5 ***/
typedef union {
  byte Byte;
} B_TRIM_OSCLSTR;
extern volatile B_TRIM_OSCLSTR _B_TRIM_OSCL @0x00000EE5;
#define B_TRIM_OSCL                     _B_TRIM_OSCL.Byte


/*** NB_PCR_CTL - PCR Control Register; 0x00000F00 ***/
typedef union {
  word Word;
  struct {
    word OPM         :2;                                       /* Operation mode select 0 */
    word PF          :2;                                       /* 1 ms Prescaler 0 */
    word             :1; 
    word HWR         :1;                                       /* Hardware Reset */
    word UVIE        :1;                                       /* Low Supply Voltage Interrupt enable */
    word HTIE        :1;                                       /* High Temperature Interrupt enable */
    word OPMM        :2;                                       /* Operation mode mask 0 */
    word PFM         :2;                                       /* Prescalar factor mask 0 */
    word             :1; 
    word HWRM        :1;                                       /* Hardware reset mask */
    word UVIEM       :1;                                       /* Supply Under Voltage interrupt enable mask */
    word HTIEM       :1;                                       /* High temperature interrupt enable mask */
  } Bits;
} NB_PCR_CTLSTR;
extern volatile NB_PCR_CTLSTR _NB_PCR_CTL @0x00000F00;
#define NB_PCR_CTL                      _NB_PCR_CTL.Word
#define NB_PCR_CTL_OPM                  _NB_PCR_CTL.Bits.OPM
#define NB_PCR_CTL_PF                   _NB_PCR_CTL.Bits.PF
#define NB_PCR_CTL_HWR                  _NB_PCR_CTL.Bits.HWR
#define NB_PCR_CTL_UVIE                 _NB_PCR_CTL.Bits.UVIE
#define NB_PCR_CTL_HTIE                 _NB_PCR_CTL.Bits.HTIE
#define NB_PCR_CTL_OPMM                 _NB_PCR_CTL.Bits.OPMM
#define NB_PCR_CTL_PFM                  _NB_PCR_CTL.Bits.PFM
#define NB_PCR_CTL_HWRM                 _NB_PCR_CTL.Bits.HWRM
#define NB_PCR_CTL_UVIEM                _NB_PCR_CTL.Bits.UVIEM
#define NB_PCR_CTL_HTIEM                _NB_PCR_CTL.Bits.HTIEM

#define NB_PCR_CTL_OPM_MASK             3U
#define NB_PCR_CTL_OPM_BITNUM           0U
#define NB_PCR_CTL_PF_MASK              12U
#define NB_PCR_CTL_PF_BITNUM            2U
#define NB_PCR_CTL_HWR_MASK             32U
#define NB_PCR_CTL_UVIE_MASK            64U
#define NB_PCR_CTL_HTIE_MASK            128U
#define NB_PCR_CTL_OPMM_MASK            768U
#define NB_PCR_CTL_OPMM_BITNUM          8U
#define NB_PCR_CTL_PFM_MASK             3072U
#define NB_PCR_CTL_PFM_BITNUM           10U
#define NB_PCR_CTL_HWRM_MASK            8192U
#define NB_PCR_CTL_UVIEM_MASK           16384U
#define NB_PCR_CTL_HTIEM_MASK           32768U


/*** NB_PCR_SR - PCR Status Register; 0x00000F02 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_PCR_SRH - PCR Status Register High; 0x00000F02 ***/
    union {
      byte Byte;
      struct {
        byte WLPMF       :1;                                       /* Wake-up after Low Power Mode Flag */
        byte WULTCF      :1;                                       /* Life Time Counter Wake Up Flag */
        byte LVRF        :1;                                       /* VDDL Low Voltage (POR) Reset Flag */
        byte HVRF        :1;                                       /* VDDH Low Voltage Reset Flag */
        byte WDRF        :1;                                       /* Watchdog Reset Flag */
        byte HWRF        :1;                                       /* Hardware Reset Flag */
        byte UVF         :1;                                       /* Supply Undervoltage Condition Flag */
        byte HTF         :1;                                       /* High Temperature Condition Flag */
      } Bits;
    } NB_PCR_SRHSTR;
    #define NB_PCR_SRH                  _NB_PCR_SR.Overlap_STR.NB_PCR_SRHSTR.Byte
    #define NB_PCR_SRH_WLPMF            _NB_PCR_SR.Overlap_STR.NB_PCR_SRHSTR.Bits.WLPMF
    #define NB_PCR_SRH_WULTCF           _NB_PCR_SR.Overlap_STR.NB_PCR_SRHSTR.Bits.WULTCF
    #define NB_PCR_SRH_LVRF             _NB_PCR_SR.Overlap_STR.NB_PCR_SRHSTR.Bits.LVRF
    #define NB_PCR_SRH_HVRF             _NB_PCR_SR.Overlap_STR.NB_PCR_SRHSTR.Bits.HVRF
    #define NB_PCR_SRH_WDRF             _NB_PCR_SR.Overlap_STR.NB_PCR_SRHSTR.Bits.WDRF
    #define NB_PCR_SRH_HWRF             _NB_PCR_SR.Overlap_STR.NB_PCR_SRHSTR.Bits.HWRF
    #define NB_PCR_SRH_UVF              _NB_PCR_SR.Overlap_STR.NB_PCR_SRHSTR.Bits.UVF
    #define NB_PCR_SRH_HTF              _NB_PCR_SR.Overlap_STR.NB_PCR_SRHSTR.Bits.HTF
    
    #define NB_PCR_SRH_WLPMF_MASK       1U
    #define NB_PCR_SRH_WULTCF_MASK      2U
    #define NB_PCR_SRH_LVRF_MASK        4U
    #define NB_PCR_SRH_HVRF_MASK        8U
    #define NB_PCR_SRH_WDRF_MASK        16U
    #define NB_PCR_SRH_HWRF_MASK        32U
    #define NB_PCR_SRH_UVF_MASK         64U
    #define NB_PCR_SRH_HTF_MASK         128U
    

    /*** NB_PCR_SRL - PCR Status Register Low; 0x00000F03 ***/
    union {
      byte Byte;
      struct {
        byte WUPTB1F     :1;                                       /* Wake-up on GPIO 1 event flag */
        byte WUPTB2F     :1;                                       /* Wake-up on GPIO 2 event flag */
        byte WUPTB3F     :1;                                       /* Wake-up on GPIO 3 event flag */
        byte WUPTB4F     :1;                                       /* Wake-up on GPIO 4 event flag */
        byte WULINF      :1;                                       /* Wake-up on LIN flag */
        byte WUCALF      :1;                                       /* Wake-up on calibration request flag */
        byte WUCTHF      :1;                                       /* Wake-up on current threshold Flag */
        byte WUAHTHF     :1;                                       /* Wake-up on Ah counter threshold Flag */
      } Bits;
    } NB_PCR_SRLSTR;
    #define NB_PCR_SRL                  _NB_PCR_SR.Overlap_STR.NB_PCR_SRLSTR.Byte
    #define NB_PCR_SRL_WUPTB1F          _NB_PCR_SR.Overlap_STR.NB_PCR_SRLSTR.Bits.WUPTB1F
    #define NB_PCR_SRL_WUPTB2F          _NB_PCR_SR.Overlap_STR.NB_PCR_SRLSTR.Bits.WUPTB2F
    #define NB_PCR_SRL_WUPTB3F          _NB_PCR_SR.Overlap_STR.NB_PCR_SRLSTR.Bits.WUPTB3F
    #define NB_PCR_SRL_WUPTB4F          _NB_PCR_SR.Overlap_STR.NB_PCR_SRLSTR.Bits.WUPTB4F
    #define NB_PCR_SRL_WULINF           _NB_PCR_SR.Overlap_STR.NB_PCR_SRLSTR.Bits.WULINF
    #define NB_PCR_SRL_WUCALF           _NB_PCR_SR.Overlap_STR.NB_PCR_SRLSTR.Bits.WUCALF
    #define NB_PCR_SRL_WUCTHF           _NB_PCR_SR.Overlap_STR.NB_PCR_SRLSTR.Bits.WUCTHF
    #define NB_PCR_SRL_WUAHTHF          _NB_PCR_SR.Overlap_STR.NB_PCR_SRLSTR.Bits.WUAHTHF
    
    #define NB_PCR_SRL_WUPTB1F_MASK     1U
    #define NB_PCR_SRL_WUPTB2F_MASK     2U
    #define NB_PCR_SRL_WUPTB3F_MASK     4U
    #define NB_PCR_SRL_WUPTB4F_MASK     8U
    #define NB_PCR_SRL_WULINF_MASK      16U
    #define NB_PCR_SRL_WUCALF_MASK      32U
    #define NB_PCR_SRL_WUCTHF_MASK      64U
    #define NB_PCR_SRL_WUAHTHF_MASK     128U
    
  } Overlap_STR;

  struct {
    word WUPTB1F     :1;                                       /* Wake-up on GPIO 1 event flag */
    word WUPTB2F     :1;                                       /* Wake-up on GPIO 2 event flag */
    word WUPTB3F     :1;                                       /* Wake-up on GPIO 3 event flag */
    word WUPTB4F     :1;                                       /* Wake-up on GPIO 4 event flag */
    word WULINF      :1;                                       /* Wake-up on LIN flag */
    word WUCALF      :1;                                       /* Wake-up on calibration request flag */
    word WUCTHF      :1;                                       /* Wake-up on current threshold Flag */
    word WUAHTHF     :1;                                       /* Wake-up on Ah counter threshold Flag */
    word WLPMF       :1;                                       /* Wake-up after Low Power Mode Flag */
    word WULTCF      :1;                                       /* Life Time Counter Wake Up Flag */
    word LVRF        :1;                                       /* VDDL Low Voltage (POR) Reset Flag */
    word HVRF        :1;                                       /* VDDH Low Voltage Reset Flag */
    word WDRF        :1;                                       /* Watchdog Reset Flag */
    word HWRF        :1;                                       /* Hardware Reset Flag */
    word UVF         :1;                                       /* Supply Undervoltage Condition Flag */
    word HTF         :1;                                       /* High Temperature Condition Flag */
  } Bits;
} NB_PCR_SRSTR;
extern volatile NB_PCR_SRSTR _NB_PCR_SR @0x00000F02;
#define NB_PCR_SR                       _NB_PCR_SR.Word
#define NB_PCR_SR_WUPTB1F               _NB_PCR_SR.Bits.WUPTB1F
#define NB_PCR_SR_WUPTB2F               _NB_PCR_SR.Bits.WUPTB2F
#define NB_PCR_SR_WUPTB3F               _NB_PCR_SR.Bits.WUPTB3F
#define NB_PCR_SR_WUPTB4F               _NB_PCR_SR.Bits.WUPTB4F
#define NB_PCR_SR_WULINF                _NB_PCR_SR.Bits.WULINF
#define NB_PCR_SR_WUCALF                _NB_PCR_SR.Bits.WUCALF
#define NB_PCR_SR_WUCTHF                _NB_PCR_SR.Bits.WUCTHF
#define NB_PCR_SR_WUAHTHF               _NB_PCR_SR.Bits.WUAHTHF
#define NB_PCR_SR_WLPMF                 _NB_PCR_SR.Bits.WLPMF
#define NB_PCR_SR_WULTCF                _NB_PCR_SR.Bits.WULTCF
#define NB_PCR_SR_LVRF                  _NB_PCR_SR.Bits.LVRF
#define NB_PCR_SR_HVRF                  _NB_PCR_SR.Bits.HVRF
#define NB_PCR_SR_WDRF                  _NB_PCR_SR.Bits.WDRF
#define NB_PCR_SR_HWRF                  _NB_PCR_SR.Bits.HWRF
#define NB_PCR_SR_UVF                   _NB_PCR_SR.Bits.UVF
#define NB_PCR_SR_HTF                   _NB_PCR_SR.Bits.HTF

#define NB_PCR_SR_WUPTB1F_MASK          1U
#define NB_PCR_SR_WUPTB2F_MASK          2U
#define NB_PCR_SR_WUPTB3F_MASK          4U
#define NB_PCR_SR_WUPTB4F_MASK          8U
#define NB_PCR_SR_WULINF_MASK           16U
#define NB_PCR_SR_WUCALF_MASK           32U
#define NB_PCR_SR_WUCTHF_MASK           64U
#define NB_PCR_SR_WUAHTHF_MASK          128U
#define NB_PCR_SR_WLPMF_MASK            256U
#define NB_PCR_SR_WULTCF_MASK           512U
#define NB_PCR_SR_LVRF_MASK             1024U
#define NB_PCR_SR_HVRF_MASK             2048U
#define NB_PCR_SR_WDRF_MASK             4096U
#define NB_PCR_SR_HWRF_MASK             8192U
#define NB_PCR_SR_UVF_MASK              16384U
#define NB_PCR_SR_HTF_MASK              32768U


/*** NB_PCR_PRESC - PCR 1ms prescaler; 0x00000F04 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_PCR_PRESCH - PCR 1ms prescaler high byte; 0x00000F04 ***/
    union {
      byte Byte;
    } NB_PCR_PRESCHSTR;
    #define NB_PCR_PRESCH               _NB_PCR_PRESC.Overlap_STR.NB_PCR_PRESCHSTR.Byte
    

    /*** NB_PCR_PRESCL - PCR 1ms prescaler low byte; 0x00000F05 ***/
    union {
      byte Byte;
    } NB_PCR_PRESCLSTR;
    #define NB_PCR_PRESCL               _NB_PCR_PRESC.Overlap_STR.NB_PCR_PRESCLSTR.Byte
    
  } Overlap_STR;

} NB_PCR_PRESCSTR;
extern volatile NB_PCR_PRESCSTR _NB_PCR_PRESC @0x00000F04;
#define NB_PCR_PRESC                    _NB_PCR_PRESC.Word


/*** NB_PCR_WUE - Wake Up Enable Register; 0x00000F06 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_PCR_WUEH - Wake Up Enable Register High; 0x00000F06 ***/
    union {
      byte Byte;
      struct {
        byte WUPTB1      :1;                                       /* Wake-up on GPIO 1 event */
        byte WUPTB2      :1;                                       /* Wake-up on GPIO 2 event */
        byte WUPTB3      :1;                                       /* Wake-up on GPIO 3 event */
        byte WUPTB4      :1;                                       /* Wake-up on GPIO 4 event */
        byte WULIN       :1;                                       /* Wake-up on LIN */
        byte WUCAL       :1;                                       /* Wake-up on calibration request */
        byte WUCTH       :1;                                       /* Wake-up on current threshold */
        byte WUAHTH      :1;                                       /* Wake-up on Ah counter */
      } Bits;
      struct {
        byte grpWUPTB_1 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } NB_PCR_WUEHSTR;
    #define NB_PCR_WUEH                 _NB_PCR_WUE.Overlap_STR.NB_PCR_WUEHSTR.Byte
    #define NB_PCR_WUEH_WUPTB1          _NB_PCR_WUE.Overlap_STR.NB_PCR_WUEHSTR.Bits.WUPTB1
    #define NB_PCR_WUEH_WUPTB2          _NB_PCR_WUE.Overlap_STR.NB_PCR_WUEHSTR.Bits.WUPTB2
    #define NB_PCR_WUEH_WUPTB3          _NB_PCR_WUE.Overlap_STR.NB_PCR_WUEHSTR.Bits.WUPTB3
    #define NB_PCR_WUEH_WUPTB4          _NB_PCR_WUE.Overlap_STR.NB_PCR_WUEHSTR.Bits.WUPTB4
    #define NB_PCR_WUEH_WULIN           _NB_PCR_WUE.Overlap_STR.NB_PCR_WUEHSTR.Bits.WULIN
    #define NB_PCR_WUEH_WUCAL           _NB_PCR_WUE.Overlap_STR.NB_PCR_WUEHSTR.Bits.WUCAL
    #define NB_PCR_WUEH_WUCTH           _NB_PCR_WUE.Overlap_STR.NB_PCR_WUEHSTR.Bits.WUCTH
    #define NB_PCR_WUEH_WUAHTH          _NB_PCR_WUE.Overlap_STR.NB_PCR_WUEHSTR.Bits.WUAHTH
    #define NB_PCR_WUEH_WUPTB_1         _NB_PCR_WUE.Overlap_STR.NB_PCR_WUEHSTR.MergedBits.grpWUPTB_1
    #define NB_PCR_WUEH_WUPTB           NB_PCR_WUEH_WUPTB_1
    
    #define NB_PCR_WUEH_WUPTB1_MASK     1U
    #define NB_PCR_WUEH_WUPTB2_MASK     2U
    #define NB_PCR_WUEH_WUPTB3_MASK     4U
    #define NB_PCR_WUEH_WUPTB4_MASK     8U
    #define NB_PCR_WUEH_WULIN_MASK      16U
    #define NB_PCR_WUEH_WUCAL_MASK      32U
    #define NB_PCR_WUEH_WUCTH_MASK      64U
    #define NB_PCR_WUEH_WUAHTH_MASK     128U
    #define NB_PCR_WUEH_WUPTB_1_MASK    15U
    #define NB_PCR_WUEH_WUPTB_1_BITNUM  0U
    

    /*** NB_PCR_WUEL - Wake Up Enable Register Low; 0x00000F07 ***/
    union {
      byte Byte;
      struct {
        byte TSDF        :1; 
        byte HTWF        :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte WULTC       :1;                                       /* Wake-up on Life Timer Counter Overflow */
      } Bits;
    } NB_PCR_WUELSTR;
    #define NB_PCR_WUEL                 _NB_PCR_WUE.Overlap_STR.NB_PCR_WUELSTR.Byte
    #define NB_PCR_WUEL_TSDF            _NB_PCR_WUE.Overlap_STR.NB_PCR_WUELSTR.Bits.TSDF
    #define NB_PCR_WUEL_HTWF            _NB_PCR_WUE.Overlap_STR.NB_PCR_WUELSTR.Bits.HTWF
    #define NB_PCR_WUEL_WULTC           _NB_PCR_WUE.Overlap_STR.NB_PCR_WUELSTR.Bits.WULTC
    
    #define NB_PCR_WUEL_TSDF_MASK       1U
    #define NB_PCR_WUEL_HTWF_MASK       2U
    #define NB_PCR_WUEL_WULTC_MASK      128U
    
  } Overlap_STR;

  struct {
    word TSDF        :1; 
    word HTWF        :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word WULTC       :1;                                       /* Wake-up on Life Timer Counter Overflow */
    word WUPTB1      :1;                                       /* Wake-up on GPIO 1 event */
    word WUPTB2      :1;                                       /* Wake-up on GPIO 2 event */
    word WUPTB3      :1;                                       /* Wake-up on GPIO 3 event */
    word WUPTB4      :1;                                       /* Wake-up on GPIO 4 event */
    word WULIN       :1;                                       /* Wake-up on LIN */
    word WUCAL       :1;                                       /* Wake-up on calibration request */
    word WUCTH       :1;                                       /* Wake-up on current threshold */
    word WUAHTH      :1;                                       /* Wake-up on Ah counter */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpWUPTB_1 :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} NB_PCR_WUESTR;
extern volatile NB_PCR_WUESTR _NB_PCR_WUE @0x00000F06;
#define NB_PCR_WUE                      _NB_PCR_WUE.Word
#define NB_PCR_WUE_TSDF                 _NB_PCR_WUE.Bits.TSDF
#define NB_PCR_WUE_HTWF                 _NB_PCR_WUE.Bits.HTWF
#define NB_PCR_WUE_WULTC                _NB_PCR_WUE.Bits.WULTC
#define NB_PCR_WUE_WUPTB1               _NB_PCR_WUE.Bits.WUPTB1
#define NB_PCR_WUE_WUPTB2               _NB_PCR_WUE.Bits.WUPTB2
#define NB_PCR_WUE_WUPTB3               _NB_PCR_WUE.Bits.WUPTB3
#define NB_PCR_WUE_WUPTB4               _NB_PCR_WUE.Bits.WUPTB4
#define NB_PCR_WUE_WULIN                _NB_PCR_WUE.Bits.WULIN
#define NB_PCR_WUE_WUCAL                _NB_PCR_WUE.Bits.WUCAL
#define NB_PCR_WUE_WUCTH                _NB_PCR_WUE.Bits.WUCTH
#define NB_PCR_WUE_WUAHTH               _NB_PCR_WUE.Bits.WUAHTH
#define NB_PCR_WUE_WUPTB_1              _NB_PCR_WUE.MergedBits.grpWUPTB_1
#define NB_PCR_WUE_WUPTB                NB_PCR_WUE_WUPTB_1

#define NB_PCR_WUE_TSDF_MASK            1U
#define NB_PCR_WUE_HTWF_MASK            2U
#define NB_PCR_WUE_WULTC_MASK           128U
#define NB_PCR_WUE_WUPTB1_MASK          256U
#define NB_PCR_WUE_WUPTB2_MASK          512U
#define NB_PCR_WUE_WUPTB3_MASK          1024U
#define NB_PCR_WUE_WUPTB4_MASK          2048U
#define NB_PCR_WUE_WULIN_MASK           4096U
#define NB_PCR_WUE_WUCAL_MASK           8192U
#define NB_PCR_WUE_WUCTH_MASK           16384U
#define NB_PCR_WUE_WUAHTH_MASK          32768U
#define NB_PCR_WUE_WUPTB_1_MASK         3840U
#define NB_PCR_WUE_WUPTB_1_BITNUM       8U


/*** NB_INT_SRC - Interrupt source register; 0x00000F08 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_INT_SRCH - Interrupt source register high; 0x00000F08 ***/
    union {
      byte Byte;
      struct {
        byte UVI         :1;                                       /* Undervoltage Interrupt pending or wake up from Cranking Mode Status */
        byte HTI         :1;                                       /* High Temperature Interrupt Status */
        byte LFI         :1; 
        byte CH0         :1;                                       /* TIM16B4C - TIM Channel 0 Interrupt Status */
        byte CH1         :1;                                       /* TIM16B4C - TIM Channel 1 Interrupt Status */
        byte CH2         :1;                                       /* TIM16B4C - TIM Channel 2 Interrupt Status */
        byte CH3         :1;                                       /* TIM16B4C - TIM Channel 3 Interrupt Status */
        byte TOV         :1;                                       /* TIM16B4C - Timer Overflow Interrupt Status */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpCH :4;
        byte     :1;
      } MergedBits;
    } NB_INT_SRCHSTR;
    #define NB_INT_SRCH                 _NB_INT_SRC.Overlap_STR.NB_INT_SRCHSTR.Byte
    #define NB_INT_SRCH_UVI             _NB_INT_SRC.Overlap_STR.NB_INT_SRCHSTR.Bits.UVI
    #define NB_INT_SRCH_HTI             _NB_INT_SRC.Overlap_STR.NB_INT_SRCHSTR.Bits.HTI
    #define NB_INT_SRCH_LFI             _NB_INT_SRC.Overlap_STR.NB_INT_SRCHSTR.Bits.LFI
    #define NB_INT_SRCH_CH0             _NB_INT_SRC.Overlap_STR.NB_INT_SRCHSTR.Bits.CH0
    #define NB_INT_SRCH_CH1             _NB_INT_SRC.Overlap_STR.NB_INT_SRCHSTR.Bits.CH1
    #define NB_INT_SRCH_CH2             _NB_INT_SRC.Overlap_STR.NB_INT_SRCHSTR.Bits.CH2
    #define NB_INT_SRCH_CH3             _NB_INT_SRC.Overlap_STR.NB_INT_SRCHSTR.Bits.CH3
    #define NB_INT_SRCH_TOV             _NB_INT_SRC.Overlap_STR.NB_INT_SRCHSTR.Bits.TOV
    #define NB_INT_SRCH_CH              _NB_INT_SRC.Overlap_STR.NB_INT_SRCHSTR.MergedBits.grpCH
    
    #define NB_INT_SRCH_UVI_MASK        1U
    #define NB_INT_SRCH_HTI_MASK        2U
    #define NB_INT_SRCH_LFI_MASK        4U
    #define NB_INT_SRCH_CH0_MASK        8U
    #define NB_INT_SRCH_CH1_MASK        16U
    #define NB_INT_SRCH_CH2_MASK        32U
    #define NB_INT_SRCH_CH3_MASK        64U
    #define NB_INT_SRCH_TOV_MASK        128U
    #define NB_INT_SRCH_CH_MASK         120U
    #define NB_INT_SRCH_CH_BITNUM       3U
    

    /*** NB_INT_SRCL - Interrupt source register low; 0x00000F09 ***/
    union {
      byte Byte;
      struct {
        byte ERR         :1;                                       /* SCI Error Interrupt Status */
        byte TX          :1;                                       /* SCI Transmit Interrupt Status */
        byte RX          :1;                                       /* SCI Receive Interrupt Status */
        byte CVMI        :1;                                       /* Current / Voltage Measurement Interrupt Status */
        byte LTC         :1;                                       /* Life Time Counter Interrupt Status */
        byte CAL         :1;                                       /* Calibration Request Interrupt Status */
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_INT_SRCLSTR;
    #define NB_INT_SRCL                 _NB_INT_SRC.Overlap_STR.NB_INT_SRCLSTR.Byte
    #define NB_INT_SRCL_ERR             _NB_INT_SRC.Overlap_STR.NB_INT_SRCLSTR.Bits.ERR
    #define NB_INT_SRCL_TX              _NB_INT_SRC.Overlap_STR.NB_INT_SRCLSTR.Bits.TX
    #define NB_INT_SRCL_RX              _NB_INT_SRC.Overlap_STR.NB_INT_SRCLSTR.Bits.RX
    #define NB_INT_SRCL_CVMI            _NB_INT_SRC.Overlap_STR.NB_INT_SRCLSTR.Bits.CVMI
    #define NB_INT_SRCL_LTC             _NB_INT_SRC.Overlap_STR.NB_INT_SRCLSTR.Bits.LTC
    #define NB_INT_SRCL_CAL             _NB_INT_SRC.Overlap_STR.NB_INT_SRCLSTR.Bits.CAL
    
    #define NB_INT_SRCL_ERR_MASK        1U
    #define NB_INT_SRCL_TX_MASK         2U
    #define NB_INT_SRCL_RX_MASK         4U
    #define NB_INT_SRCL_CVMI_MASK       8U
    #define NB_INT_SRCL_LTC_MASK        16U
    #define NB_INT_SRCL_CAL_MASK        32U
    
  } Overlap_STR;

  struct {
    word ERR         :1;                                       /* SCI Error Interrupt Status */
    word TX          :1;                                       /* SCI Transmit Interrupt Status */
    word RX          :1;                                       /* SCI Receive Interrupt Status */
    word CVMI        :1;                                       /* Current / Voltage Measurement Interrupt Status */
    word LTC         :1;                                       /* Life Time Counter Interrupt Status */
    word CAL         :1;                                       /* Calibration Request Interrupt Status */
    word             :1; 
    word             :1; 
    word UVI         :1;                                       /* Undervoltage Interrupt pending or wake up from Cranking Mode Status */
    word HTI         :1;                                       /* High Temperature Interrupt Status */
    word LFI         :1; 
    word CH0         :1;                                       /* TIM16B4C - TIM Channel 0 Interrupt Status */
    word CH1         :1;                                       /* TIM16B4C - TIM Channel 1 Interrupt Status */
    word CH2         :1;                                       /* TIM16B4C - TIM Channel 2 Interrupt Status */
    word CH3         :1;                                       /* TIM16B4C - TIM Channel 3 Interrupt Status */
    word TOV         :1;                                       /* TIM16B4C - Timer Overflow Interrupt Status */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpCH   :4;
    word         :1;
  } MergedBits;
} NB_INT_SRCSTR;
extern volatile NB_INT_SRCSTR _NB_INT_SRC @0x00000F08;
#define NB_INT_SRC                      _NB_INT_SRC.Word
#define NB_INT_SRC_ERR                  _NB_INT_SRC.Bits.ERR
#define NB_INT_SRC_TX                   _NB_INT_SRC.Bits.TX
#define NB_INT_SRC_RX                   _NB_INT_SRC.Bits.RX
#define NB_INT_SRC_CVMI                 _NB_INT_SRC.Bits.CVMI
#define NB_INT_SRC_LTC                  _NB_INT_SRC.Bits.LTC
#define NB_INT_SRC_CAL                  _NB_INT_SRC.Bits.CAL
#define NB_INT_SRC_UVI                  _NB_INT_SRC.Bits.UVI
#define NB_INT_SRC_HTI                  _NB_INT_SRC.Bits.HTI
#define NB_INT_SRC_LFI                  _NB_INT_SRC.Bits.LFI
#define NB_INT_SRC_CH0                  _NB_INT_SRC.Bits.CH0
#define NB_INT_SRC_CH1                  _NB_INT_SRC.Bits.CH1
#define NB_INT_SRC_CH2                  _NB_INT_SRC.Bits.CH2
#define NB_INT_SRC_CH3                  _NB_INT_SRC.Bits.CH3
#define NB_INT_SRC_TOV                  _NB_INT_SRC.Bits.TOV
#define NB_INT_SRC_CH                   _NB_INT_SRC.MergedBits.grpCH

#define NB_INT_SRC_ERR_MASK             1U
#define NB_INT_SRC_TX_MASK              2U
#define NB_INT_SRC_RX_MASK              4U
#define NB_INT_SRC_CVMI_MASK            8U
#define NB_INT_SRC_LTC_MASK             16U
#define NB_INT_SRC_CAL_MASK             32U
#define NB_INT_SRC_UVI_MASK             256U
#define NB_INT_SRC_HTI_MASK             512U
#define NB_INT_SRC_LFI_MASK             1024U
#define NB_INT_SRC_CH0_MASK             2048U
#define NB_INT_SRC_CH1_MASK             4096U
#define NB_INT_SRC_CH2_MASK             8192U
#define NB_INT_SRC_CH3_MASK             16384U
#define NB_INT_SRC_TOV_MASK             32768U
#define NB_INT_SRC_CH_MASK              30720U
#define NB_INT_SRC_CH_BITNUM            11U


/*** NB_INT_VECT - Interrupt vector register; 0x00000F0A ***/
typedef union {
  byte Byte;
  struct {
    byte IRQ         :4;                                       /* Represents the highest prioritized interrupt pending */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NB_INT_VECTSTR;
extern volatile NB_INT_VECTSTR _NB_INT_VECT @0x00000F0A;
#define NB_INT_VECT                     _NB_INT_VECT.Byte
#define NB_INT_VECT_IRQ                 _NB_INT_VECT.Bits.IRQ

#define NB_INT_VECT_IRQ_MASK            15U
#define NB_INT_VECT_IRQ_BITNUM          0U


/*** NB_INT_MSK - Interrupt mask register; 0x00000F0C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_INT_MSKH - Interrupt mask register high; 0x00000F0C ***/
    union {
      byte Byte;
      struct {
        byte UVIM        :1;                                       /* Undervoltage Interrupt Mask */
        byte HTIM        :1;                                       /* High Temperature Interrupt Mask */
        byte LFIM        :1; 
        byte CH0M        :1;                                       /* Timer Channel 1 Interrupt Mask */
        byte CH1M        :1;                                       /* Timer Channel 1 Interrupt Mask */
        byte CH2M        :1;                                       /* Timer Channel 2 Interrupt Mask */
        byte CH3M        :1;                                       /* Timer Channel 3 Interrupt Mask */
        byte TOVM        :1;                                       /* Timer Overflow Interrupt Mask */
      } Bits;
    } NB_INT_MSKHSTR;
    #define NB_INT_MSKH                 _NB_INT_MSK.Overlap_STR.NB_INT_MSKHSTR.Byte
    #define NB_INT_MSKH_UVIM            _NB_INT_MSK.Overlap_STR.NB_INT_MSKHSTR.Bits.UVIM
    #define NB_INT_MSKH_HTIM            _NB_INT_MSK.Overlap_STR.NB_INT_MSKHSTR.Bits.HTIM
    #define NB_INT_MSKH_LFIM            _NB_INT_MSK.Overlap_STR.NB_INT_MSKHSTR.Bits.LFIM
    #define NB_INT_MSKH_CH0M            _NB_INT_MSK.Overlap_STR.NB_INT_MSKHSTR.Bits.CH0M
    #define NB_INT_MSKH_CH1M            _NB_INT_MSK.Overlap_STR.NB_INT_MSKHSTR.Bits.CH1M
    #define NB_INT_MSKH_CH2M            _NB_INT_MSK.Overlap_STR.NB_INT_MSKHSTR.Bits.CH2M
    #define NB_INT_MSKH_CH3M            _NB_INT_MSK.Overlap_STR.NB_INT_MSKHSTR.Bits.CH3M
    #define NB_INT_MSKH_TOVM            _NB_INT_MSK.Overlap_STR.NB_INT_MSKHSTR.Bits.TOVM
    
    #define NB_INT_MSKH_UVIM_MASK       1U
    #define NB_INT_MSKH_HTIM_MASK       2U
    #define NB_INT_MSKH_LFIM_MASK       4U
    #define NB_INT_MSKH_CH0M_MASK       8U
    #define NB_INT_MSKH_CH1M_MASK       16U
    #define NB_INT_MSKH_CH2M_MASK       32U
    #define NB_INT_MSKH_CH3M_MASK       64U
    #define NB_INT_MSKH_TOVM_MASK       128U
    

    /*** NB_INT_MSKL - Interrupt mask register low; 0x00000F0D ***/
    union {
      byte Byte;
      struct {
        byte ERRM        :1;                                       /* SCI Error Interrupt Mask */
        byte TXM         :1;                                       /* SCI Transmit Interrupt Mask */
        byte RXM         :1;                                       /* SCI Receive Interrupt Mask */
        byte CVMM        :1;                                       /* Current / Voltage Measurement Interrupt Mask */
        byte LTCM        :1;                                       /* Life Time Counter Interrupt Mask */
        byte CALM        :1;                                       /* Calibration Request Interrupt Mask */
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_INT_MSKLSTR;
    #define NB_INT_MSKL                 _NB_INT_MSK.Overlap_STR.NB_INT_MSKLSTR.Byte
    #define NB_INT_MSKL_ERRM            _NB_INT_MSK.Overlap_STR.NB_INT_MSKLSTR.Bits.ERRM
    #define NB_INT_MSKL_TXM             _NB_INT_MSK.Overlap_STR.NB_INT_MSKLSTR.Bits.TXM
    #define NB_INT_MSKL_RXM             _NB_INT_MSK.Overlap_STR.NB_INT_MSKLSTR.Bits.RXM
    #define NB_INT_MSKL_CVMM            _NB_INT_MSK.Overlap_STR.NB_INT_MSKLSTR.Bits.CVMM
    #define NB_INT_MSKL_LTCM            _NB_INT_MSK.Overlap_STR.NB_INT_MSKLSTR.Bits.LTCM
    #define NB_INT_MSKL_CALM            _NB_INT_MSK.Overlap_STR.NB_INT_MSKLSTR.Bits.CALM
    
    #define NB_INT_MSKL_ERRM_MASK       1U
    #define NB_INT_MSKL_TXM_MASK        2U
    #define NB_INT_MSKL_RXM_MASK        4U
    #define NB_INT_MSKL_CVMM_MASK       8U
    #define NB_INT_MSKL_LTCM_MASK       16U
    #define NB_INT_MSKL_CALM_MASK       32U
    
  } Overlap_STR;

  struct {
    word ERRM        :1;                                       /* SCI Error Interrupt Mask */
    word TXM         :1;                                       /* SCI Transmit Interrupt Mask */
    word RXM         :1;                                       /* SCI Receive Interrupt Mask */
    word CVMM        :1;                                       /* Current / Voltage Measurement Interrupt Mask */
    word LTCM        :1;                                       /* Life Time Counter Interrupt Mask */
    word CALM        :1;                                       /* Calibration Request Interrupt Mask */
    word             :1; 
    word             :1; 
    word UVIM        :1;                                       /* Undervoltage Interrupt Mask */
    word HTIM        :1;                                       /* High Temperature Interrupt Mask */
    word LFIM        :1; 
    word CH0M        :1;                                       /* Timer Channel 1 Interrupt Mask */
    word CH1M        :1;                                       /* Timer Channel 1 Interrupt Mask */
    word CH2M        :1;                                       /* Timer Channel 2 Interrupt Mask */
    word CH3M        :1;                                       /* Timer Channel 3 Interrupt Mask */
    word TOVM        :1;                                       /* Timer Overflow Interrupt Mask */
  } Bits;
} NB_INT_MSKSTR;
extern volatile NB_INT_MSKSTR _NB_INT_MSK @0x00000F0C;
#define NB_INT_MSK                      _NB_INT_MSK.Word
#define NB_INT_MSK_ERRM                 _NB_INT_MSK.Bits.ERRM
#define NB_INT_MSK_TXM                  _NB_INT_MSK.Bits.TXM
#define NB_INT_MSK_RXM                  _NB_INT_MSK.Bits.RXM
#define NB_INT_MSK_CVMM                 _NB_INT_MSK.Bits.CVMM
#define NB_INT_MSK_LTCM                 _NB_INT_MSK.Bits.LTCM
#define NB_INT_MSK_CALM                 _NB_INT_MSK.Bits.CALM
#define NB_INT_MSK_UVIM                 _NB_INT_MSK.Bits.UVIM
#define NB_INT_MSK_HTIM                 _NB_INT_MSK.Bits.HTIM
#define NB_INT_MSK_LFIM                 _NB_INT_MSK.Bits.LFIM
#define NB_INT_MSK_CH0M                 _NB_INT_MSK.Bits.CH0M
#define NB_INT_MSK_CH1M                 _NB_INT_MSK.Bits.CH1M
#define NB_INT_MSK_CH2M                 _NB_INT_MSK.Bits.CH2M
#define NB_INT_MSK_CH3M                 _NB_INT_MSK.Bits.CH3M
#define NB_INT_MSK_TOVM                 _NB_INT_MSK.Bits.TOVM

#define NB_INT_MSK_ERRM_MASK            1U
#define NB_INT_MSK_TXM_MASK             2U
#define NB_INT_MSK_RXM_MASK             4U
#define NB_INT_MSK_CVMM_MASK            8U
#define NB_INT_MSK_LTCM_MASK            16U
#define NB_INT_MSK_CALM_MASK            32U
#define NB_INT_MSK_UVIM_MASK            256U
#define NB_INT_MSK_HTIM_MASK            512U
#define NB_INT_MSK_LFIM_MASK            1024U
#define NB_INT_MSK_CH0M_MASK            2048U
#define NB_INT_MSK_CH1M_MASK            4096U
#define NB_INT_MSK_CH2M_MASK            8192U
#define NB_INT_MSK_CH3M_MASK            16384U
#define NB_INT_MSK_TOVM_MASK            32768U


/*** NB_TRIM_ALF - Trim for accurate 1ms low freq clock; 0x00000F0E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_TRIM_ALFH - Trim for accurate 1ms low freq clock high; 0x00000F0E ***/
    union {
      byte Byte;
      struct {
        byte APRESC      :5;                                       /* ALFCLK Prescaler 8 */
        byte             :1; 
        byte             :1; 
        byte PRDF        :1;                                       /* ALFCLK Prescaler ready Flag */
      } Bits;
    } NB_TRIM_ALFHSTR;
    #define NB_TRIM_ALFH                _NB_TRIM_ALF.Overlap_STR.NB_TRIM_ALFHSTR.Byte
    #define NB_TRIM_ALFH_APRESC         _NB_TRIM_ALF.Overlap_STR.NB_TRIM_ALFHSTR.Bits.APRESC
    #define NB_TRIM_ALFH_PRDF           _NB_TRIM_ALF.Overlap_STR.NB_TRIM_ALFHSTR.Bits.PRDF
    
    #define NB_TRIM_ALFH_APRESC_MASK    31U
    #define NB_TRIM_ALFH_APRESC_BITNUM  0U
    #define NB_TRIM_ALFH_PRDF_MASK      128U
    

    /*** NB_TRIM_ALFL - Trim for accurate 1ms low freq clock low; 0x00000F0F ***/
    union {
      byte Byte;
    } NB_TRIM_ALFLSTR;
    #define NB_TRIM_ALFL                _NB_TRIM_ALF.Overlap_STR.NB_TRIM_ALFLSTR.Byte
    
  } Overlap_STR;

  struct {
    word APRESC      :13;                                      /* ALFCLK Prescaler 0 */
    word             :1; 
    word             :1; 
    word PRDF        :1;                                       /* ALFCLK Prescaler ready Flag */
  } Bits;
} NB_TRIM_ALFSTR;
extern volatile NB_TRIM_ALFSTR _NB_TRIM_ALF @0x00000F0E;
#define NB_TRIM_ALF                     _NB_TRIM_ALF.Word
#define NB_TRIM_ALF_APRESC              _NB_TRIM_ALF.Bits.APRESC
#define NB_TRIM_ALF_PRDF                _NB_TRIM_ALF.Bits.PRDF

#define NB_TRIM_ALF_APRESC_MASK         8191U
#define NB_TRIM_ALF_APRESC_BITNUM       0U
#define NB_TRIM_ALF_PRDF_MASK           32768U


/*** NB_WD_CTL - Watchdog control register; 0x00000F10 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_WD_CTLH - Watchdog control register high; 0x00000F10 ***/
    union {
      byte Byte;
      struct {
        byte WDTOM       :3;                                       /* Watchdog Time Out - Mask */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte WDTSTM      :1;                                       /* Watchdog Test - Mask */
      } Bits;
    } NB_WD_CTLHSTR;
    #define NB_WD_CTLH                  _NB_WD_CTL.Overlap_STR.NB_WD_CTLHSTR.Byte
    #define NB_WD_CTLH_WDTOM            _NB_WD_CTL.Overlap_STR.NB_WD_CTLHSTR.Bits.WDTOM
    #define NB_WD_CTLH_WDTSTM           _NB_WD_CTL.Overlap_STR.NB_WD_CTLHSTR.Bits.WDTSTM
    
    #define NB_WD_CTLH_WDTOM_MASK       7U
    #define NB_WD_CTLH_WDTOM_BITNUM     0U
    #define NB_WD_CTLH_WDTSTM_MASK      128U
    

    /*** NB_WD_CTLL - Watchdog control register low; 0x00000F11 ***/
    union {
      byte Byte;
      struct {
        byte WDTO        :3;                                       /* Watchdog Time Out Configuration */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte WDTST       :1;                                       /* Watchdog Test */
      } Bits;
    } NB_WD_CTLLSTR;
    #define NB_WD_CTLL                  _NB_WD_CTL.Overlap_STR.NB_WD_CTLLSTR.Byte
    #define NB_WD_CTLL_WDTO             _NB_WD_CTL.Overlap_STR.NB_WD_CTLLSTR.Bits.WDTO
    #define NB_WD_CTLL_WDTST            _NB_WD_CTL.Overlap_STR.NB_WD_CTLLSTR.Bits.WDTST
    
    #define NB_WD_CTLL_WDTO_MASK        7U
    #define NB_WD_CTLL_WDTO_BITNUM      0U
    #define NB_WD_CTLL_WDTST_MASK       128U
    
  } Overlap_STR;

  struct {
    word WDTO        :3;                                       /* Watchdog Time Out Configuration */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word WDTST       :1;                                       /* Watchdog Test */
    word WDTOM       :3;                                       /* Watchdog Time Out - Mask */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word WDTSTM      :1;                                       /* Watchdog Test - Mask */
  } Bits;
} NB_WD_CTLSTR;
extern volatile NB_WD_CTLSTR _NB_WD_CTL @0x00000F10;
#define NB_WD_CTL                       _NB_WD_CTL.Word
#define NB_WD_CTL_WDTO                  _NB_WD_CTL.Bits.WDTO
#define NB_WD_CTL_WDTST                 _NB_WD_CTL.Bits.WDTST
#define NB_WD_CTL_WDTOM                 _NB_WD_CTL.Bits.WDTOM
#define NB_WD_CTL_WDTSTM                _NB_WD_CTL.Bits.WDTSTM

#define NB_WD_CTL_WDTO_MASK             7U
#define NB_WD_CTL_WDTO_BITNUM           0U
#define NB_WD_CTL_WDTST_MASK            128U
#define NB_WD_CTL_WDTOM_MASK            1792U
#define NB_WD_CTL_WDTOM_BITNUM          8U
#define NB_WD_CTL_WDTSTM_MASK           32768U


/*** NB_WD_SR - Watchdog status register; 0x00000F12 ***/
typedef union {
  byte Byte;
  struct {
    byte WDWO        :1;                                       /* Watchdog Status */
    byte WDOFF       :1;                                       /* Watchdog Window Status */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NB_WD_SRSTR;
extern volatile NB_WD_SRSTR _NB_WD_SR @0x00000F12;
#define NB_WD_SR                        _NB_WD_SR.Byte
#define NB_WD_SR_WDWO                   _NB_WD_SR.Bits.WDWO
#define NB_WD_SR_WDOFF                  _NB_WD_SR.Bits.WDOFF

#define NB_WD_SR_WDWO_MASK              1U
#define NB_WD_SR_WDOFF_MASK             2U


/*** NB_WD_RR - Watchdog rearm register; 0x00000F14 ***/
typedef union {
  byte Byte;
} NB_WD_RRSTR;
extern volatile NB_WD_RRSTR _NB_WD_RR @0x00000F14;
#define NB_WD_RR                        _NB_WD_RR.Byte


/*** NB_SCIBD - SCI Baud Rate Register; 0x00000F18 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_SCIBDH - SCI Baud Rate Register High; 0x00000F18 ***/
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
    } NB_SCIBDHSTR;
    #define NB_SCIBDH                   _NB_SCIBD.Overlap_STR.NB_SCIBDHSTR.Byte
    #define NB_SCIBDH_SBR8              _NB_SCIBD.Overlap_STR.NB_SCIBDHSTR.Bits.SBR8
    #define NB_SCIBDH_SBR9              _NB_SCIBD.Overlap_STR.NB_SCIBDHSTR.Bits.SBR9
    #define NB_SCIBDH_SBR10             _NB_SCIBD.Overlap_STR.NB_SCIBDHSTR.Bits.SBR10
    #define NB_SCIBDH_SBR11             _NB_SCIBD.Overlap_STR.NB_SCIBDHSTR.Bits.SBR11
    #define NB_SCIBDH_SBR12             _NB_SCIBD.Overlap_STR.NB_SCIBDHSTR.Bits.SBR12
    #define NB_SCIBDH_RXEDGIE           _NB_SCIBD.Overlap_STR.NB_SCIBDHSTR.Bits.RXEDGIE
    #define NB_SCIBDH_LBKDIE            _NB_SCIBD.Overlap_STR.NB_SCIBDHSTR.Bits.LBKDIE
    #define NB_SCIBDH_SBR_8             _NB_SCIBD.Overlap_STR.NB_SCIBDHSTR.MergedBits.grpSBR_8
    #define NB_SCIBDH_SBR               NB_SCIBDH_SBR_8
    
    #define NB_SCIBDH_SBR8_MASK         1U
    #define NB_SCIBDH_SBR9_MASK         2U
    #define NB_SCIBDH_SBR10_MASK        4U
    #define NB_SCIBDH_SBR11_MASK        8U
    #define NB_SCIBDH_SBR12_MASK        16U
    #define NB_SCIBDH_RXEDGIE_MASK      64U
    #define NB_SCIBDH_LBKDIE_MASK       128U
    #define NB_SCIBDH_SBR_8_MASK        31U
    #define NB_SCIBDH_SBR_8_BITNUM      0U
    

    /*** NB_SCIBDL - SCI Baud Rate Register Low; 0x00000F19 ***/
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
    } NB_SCIBDLSTR;
    #define NB_SCIBDL                   _NB_SCIBD.Overlap_STR.NB_SCIBDLSTR.Byte
    #define NB_SCIBDL_SBR0              _NB_SCIBD.Overlap_STR.NB_SCIBDLSTR.Bits.SBR0
    #define NB_SCIBDL_SBR1              _NB_SCIBD.Overlap_STR.NB_SCIBDLSTR.Bits.SBR1
    #define NB_SCIBDL_SBR2              _NB_SCIBD.Overlap_STR.NB_SCIBDLSTR.Bits.SBR2
    #define NB_SCIBDL_SBR3              _NB_SCIBD.Overlap_STR.NB_SCIBDLSTR.Bits.SBR3
    #define NB_SCIBDL_SBR4              _NB_SCIBD.Overlap_STR.NB_SCIBDLSTR.Bits.SBR4
    #define NB_SCIBDL_SBR5              _NB_SCIBD.Overlap_STR.NB_SCIBDLSTR.Bits.SBR5
    #define NB_SCIBDL_SBR6              _NB_SCIBD.Overlap_STR.NB_SCIBDLSTR.Bits.SBR6
    #define NB_SCIBDL_SBR7              _NB_SCIBD.Overlap_STR.NB_SCIBDLSTR.Bits.SBR7
    
    #define NB_SCIBDL_SBR0_MASK         1U
    #define NB_SCIBDL_SBR1_MASK         2U
    #define NB_SCIBDL_SBR2_MASK         4U
    #define NB_SCIBDL_SBR3_MASK         8U
    #define NB_SCIBDL_SBR4_MASK         16U
    #define NB_SCIBDL_SBR5_MASK         32U
    #define NB_SCIBDL_SBR6_MASK         64U
    #define NB_SCIBDL_SBR7_MASK         128U
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
    word SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
    word SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
    word SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
    word SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
    word SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
    word SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
    word SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
    word SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
    word SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
    word SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
    word SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
    word SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
    word             :1; 
    word RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
    word LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
  } Bits;
  struct {
    word grpSBR  :13;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} NB_SCIBDSTR;
extern volatile NB_SCIBDSTR _NB_SCIBD @0x00000F18;
#define NB_SCIBD                        _NB_SCIBD.Word
#define NB_SCIBD_SBR0                   _NB_SCIBD.Bits.SBR0
#define NB_SCIBD_SBR1                   _NB_SCIBD.Bits.SBR1
#define NB_SCIBD_SBR2                   _NB_SCIBD.Bits.SBR2
#define NB_SCIBD_SBR3                   _NB_SCIBD.Bits.SBR3
#define NB_SCIBD_SBR4                   _NB_SCIBD.Bits.SBR4
#define NB_SCIBD_SBR5                   _NB_SCIBD.Bits.SBR5
#define NB_SCIBD_SBR6                   _NB_SCIBD.Bits.SBR6
#define NB_SCIBD_SBR7                   _NB_SCIBD.Bits.SBR7
#define NB_SCIBD_SBR8                   _NB_SCIBD.Bits.SBR8
#define NB_SCIBD_SBR9                   _NB_SCIBD.Bits.SBR9
#define NB_SCIBD_SBR10                  _NB_SCIBD.Bits.SBR10
#define NB_SCIBD_SBR11                  _NB_SCIBD.Bits.SBR11
#define NB_SCIBD_SBR12                  _NB_SCIBD.Bits.SBR12
#define NB_SCIBD_RXEDGIE                _NB_SCIBD.Bits.RXEDGIE
#define NB_SCIBD_LBKDIE                 _NB_SCIBD.Bits.LBKDIE
#define NB_SCIBD_SBR                    _NB_SCIBD.MergedBits.grpSBR

#define NB_SCIBD_SBR0_MASK              1U
#define NB_SCIBD_SBR1_MASK              2U
#define NB_SCIBD_SBR2_MASK              4U
#define NB_SCIBD_SBR3_MASK              8U
#define NB_SCIBD_SBR4_MASK              16U
#define NB_SCIBD_SBR5_MASK              32U
#define NB_SCIBD_SBR6_MASK              64U
#define NB_SCIBD_SBR7_MASK              128U
#define NB_SCIBD_SBR8_MASK              256U
#define NB_SCIBD_SBR9_MASK              512U
#define NB_SCIBD_SBR10_MASK             1024U
#define NB_SCIBD_SBR11_MASK             2048U
#define NB_SCIBD_SBR12_MASK             4096U
#define NB_SCIBD_RXEDGIE_MASK           16384U
#define NB_SCIBD_LBKDIE_MASK            32768U
#define NB_SCIBD_SBR_MASK               8191U
#define NB_SCIBD_SBR_BITNUM             0U


/*** NB_SCIC1 - SCI Control Register 1; 0x00000F1A ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte DPD0        :1; 
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte DPD1        :1; 
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} NB_SCIC1STR;
extern volatile NB_SCIC1STR _NB_SCIC1 @0x00000F1A;
#define NB_SCIC1                        _NB_SCIC1.Byte
#define NB_SCIC1_PT                     _NB_SCIC1.Bits.PT
#define NB_SCIC1_PE                     _NB_SCIC1.Bits.PE
#define NB_SCIC1_ILT                    _NB_SCIC1.Bits.ILT
#define NB_SCIC1_DPD0                   _NB_SCIC1.Bits.DPD0
#define NB_SCIC1_M                      _NB_SCIC1.Bits.M
#define NB_SCIC1_RSRC                   _NB_SCIC1.Bits.RSRC
#define NB_SCIC1_DPD1                   _NB_SCIC1.Bits.DPD1
#define NB_SCIC1_LOOPS                  _NB_SCIC1.Bits.LOOPS

#define NB_SCIC1_PT_MASK                1U
#define NB_SCIC1_PE_MASK                2U
#define NB_SCIC1_ILT_MASK               4U
#define NB_SCIC1_DPD0_MASK              8U
#define NB_SCIC1_M_MASK                 16U
#define NB_SCIC1_RSRC_MASK              32U
#define NB_SCIC1_DPD1_MASK              64U
#define NB_SCIC1_LOOPS_MASK             128U


/*** NB_SCIC2 - SCI Control Register 2; 0x00000F1B ***/
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
} NB_SCIC2STR;
extern volatile NB_SCIC2STR _NB_SCIC2 @0x00000F1B;
#define NB_SCIC2                        _NB_SCIC2.Byte
#define NB_SCIC2_SBK                    _NB_SCIC2.Bits.SBK
#define NB_SCIC2_RWU                    _NB_SCIC2.Bits.RWU
#define NB_SCIC2_RE                     _NB_SCIC2.Bits.RE
#define NB_SCIC2_TE                     _NB_SCIC2.Bits.TE
#define NB_SCIC2_ILIE                   _NB_SCIC2.Bits.ILIE
#define NB_SCIC2_RIE                    _NB_SCIC2.Bits.RIE
#define NB_SCIC2_TCIE                   _NB_SCIC2.Bits.TCIE
#define NB_SCIC2_TIE                    _NB_SCIC2.Bits.TIE

#define NB_SCIC2_SBK_MASK               1U
#define NB_SCIC2_RWU_MASK               2U
#define NB_SCIC2_RE_MASK                4U
#define NB_SCIC2_TE_MASK                8U
#define NB_SCIC2_ILIE_MASK              16U
#define NB_SCIC2_RIE_MASK               32U
#define NB_SCIC2_TCIE_MASK              64U
#define NB_SCIC2_TIE_MASK               128U


/*** NB_SCIS1 - SCI Status Register 1; 0x00000F1C ***/
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
} NB_SCIS1STR;
extern volatile NB_SCIS1STR _NB_SCIS1 @0x00000F1C;
#define NB_SCIS1                        _NB_SCIS1.Byte
#define NB_SCIS1_PF                     _NB_SCIS1.Bits.PF
#define NB_SCIS1_FE                     _NB_SCIS1.Bits.FE
#define NB_SCIS1_NF                     _NB_SCIS1.Bits.NF
#define NB_SCIS1_OR                     _NB_SCIS1.Bits.OR
#define NB_SCIS1_IDLE                   _NB_SCIS1.Bits.IDLE
#define NB_SCIS1_RDRF                   _NB_SCIS1.Bits.RDRF
#define NB_SCIS1_TC                     _NB_SCIS1.Bits.TC
#define NB_SCIS1_TDRE                   _NB_SCIS1.Bits.TDRE

#define NB_SCIS1_PF_MASK                1U
#define NB_SCIS1_FE_MASK                2U
#define NB_SCIS1_NF_MASK                4U
#define NB_SCIS1_OR_MASK                8U
#define NB_SCIS1_IDLE_MASK              16U
#define NB_SCIS1_RDRF_MASK              32U
#define NB_SCIS1_TC_MASK                64U
#define NB_SCIS1_TDRE_MASK              128U


/*** NB_SCIS2 - SCI Status Register 2; 0x00000F1D ***/
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
} NB_SCIS2STR;
extern volatile NB_SCIS2STR _NB_SCIS2 @0x00000F1D;
#define NB_SCIS2                        _NB_SCIS2.Byte
#define NB_SCIS2_RAF                    _NB_SCIS2.Bits.RAF
#define NB_SCIS2_LBKDE                  _NB_SCIS2.Bits.LBKDE
#define NB_SCIS2_BRK13                  _NB_SCIS2.Bits.BRK13
#define NB_SCIS2_RWUID                  _NB_SCIS2.Bits.RWUID
#define NB_SCIS2_RXINV                  _NB_SCIS2.Bits.RXINV
#define NB_SCIS2_RXEDGIF                _NB_SCIS2.Bits.RXEDGIF
#define NB_SCIS2_LBKDIF                 _NB_SCIS2.Bits.LBKDIF

#define NB_SCIS2_RAF_MASK               1U
#define NB_SCIS2_LBKDE_MASK             2U
#define NB_SCIS2_BRK13_MASK             4U
#define NB_SCIS2_RWUID_MASK             8U
#define NB_SCIS2_RXINV_MASK             16U
#define NB_SCIS2_RXEDGIF_MASK           64U
#define NB_SCIS2_LBKDIF_MASK            128U


/*** NB_SCIC3 - SCI Control Register 3; 0x00000F1E ***/
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
} NB_SCIC3STR;
extern volatile NB_SCIC3STR _NB_SCIC3 @0x00000F1E;
#define NB_SCIC3                        _NB_SCIC3.Byte
#define NB_SCIC3_PEIE                   _NB_SCIC3.Bits.PEIE
#define NB_SCIC3_FEIE                   _NB_SCIC3.Bits.FEIE
#define NB_SCIC3_NEIE                   _NB_SCIC3.Bits.NEIE
#define NB_SCIC3_ORIE                   _NB_SCIC3.Bits.ORIE
#define NB_SCIC3_TXINV                  _NB_SCIC3.Bits.TXINV
#define NB_SCIC3_TXDIR                  _NB_SCIC3.Bits.TXDIR
#define NB_SCIC3_T8                     _NB_SCIC3.Bits.T8
#define NB_SCIC3_R8                     _NB_SCIC3.Bits.R8

#define NB_SCIC3_PEIE_MASK              1U
#define NB_SCIC3_FEIE_MASK              2U
#define NB_SCIC3_NEIE_MASK              4U
#define NB_SCIC3_ORIE_MASK              8U
#define NB_SCIC3_TXINV_MASK             16U
#define NB_SCIC3_TXDIR_MASK             32U
#define NB_SCIC3_T8_MASK                64U
#define NB_SCIC3_R8_MASK                128U


/*** NB_SCID - SCI Data Register; 0x00000F1F ***/
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
} NB_SCIDSTR;
extern volatile NB_SCIDSTR _NB_SCID @0x00000F1F;
#define NB_SCID                         _NB_SCID.Byte
#define NB_SCID_R0_T0                   _NB_SCID.Bits.R0_T0
#define NB_SCID_R1_T1                   _NB_SCID.Bits.R1_T1
#define NB_SCID_R2_T2                   _NB_SCID.Bits.R2_T2
#define NB_SCID_R3_T3                   _NB_SCID.Bits.R3_T3
#define NB_SCID_R4_T4                   _NB_SCID.Bits.R4_T4
#define NB_SCID_R5_T5                   _NB_SCID.Bits.R5_T5
#define NB_SCID_R6_T6                   _NB_SCID.Bits.R6_T6
#define NB_SCID_R7_T7                   _NB_SCID.Bits.R7_T7

#define NB_SCID_R0_T0_MASK              1U
#define NB_SCID_R1_T1_MASK              2U
#define NB_SCID_R2_T2_MASK              4U
#define NB_SCID_R3_T3_MASK              8U
#define NB_SCID_R4_T4_MASK              16U
#define NB_SCID_R5_T5_MASK              32U
#define NB_SCID_R6_T6_MASK              64U
#define NB_SCID_R7_T7_MASK              128U


/*** NB_TIOS - Timer Input Capture/Output Compare Select; 0x00000F20 ***/
typedef union {
  byte Byte;
  struct {
    byte IOS0        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 0 */
    byte IOS1        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 1 */
    byte IOS2        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 2 */
    byte IOS3        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIOS  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NB_TIOSSTR;
extern volatile NB_TIOSSTR _NB_TIOS @0x00000F20;
#define NB_TIOS                         _NB_TIOS.Byte
#define NB_TIOS_IOS0                    _NB_TIOS.Bits.IOS0
#define NB_TIOS_IOS1                    _NB_TIOS.Bits.IOS1
#define NB_TIOS_IOS2                    _NB_TIOS.Bits.IOS2
#define NB_TIOS_IOS3                    _NB_TIOS.Bits.IOS3
#define NB_TIOS_IOS                     _NB_TIOS.MergedBits.grpIOS

#define NB_TIOS_IOS0_MASK               1U
#define NB_TIOS_IOS1_MASK               2U
#define NB_TIOS_IOS2_MASK               4U
#define NB_TIOS_IOS3_MASK               8U
#define NB_TIOS_IOS_MASK                15U
#define NB_TIOS_IOS_BITNUM              0U


/*** NB_CFORC - Timer Compare Force Register; 0x00000F21 ***/
typedef union {
  byte Byte;
  struct {
    byte FOC0        :1;                                       /* Force Output Compare Action for Channel 0 */
    byte FOC1        :1;                                       /* Force Output Compare Action for Channel 1 */
    byte FOC2        :1;                                       /* Force Output Compare Action for Channel 2 */
    byte FOC3        :1;                                       /* Force Output Compare Action for Channel 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFOC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NB_CFORCSTR;
extern volatile NB_CFORCSTR _NB_CFORC @0x00000F21;
#define NB_CFORC                        _NB_CFORC.Byte
#define NB_CFORC_FOC0                   _NB_CFORC.Bits.FOC0
#define NB_CFORC_FOC1                   _NB_CFORC.Bits.FOC1
#define NB_CFORC_FOC2                   _NB_CFORC.Bits.FOC2
#define NB_CFORC_FOC3                   _NB_CFORC.Bits.FOC3
#define NB_CFORC_FOC                    _NB_CFORC.MergedBits.grpFOC

#define NB_CFORC_FOC0_MASK              1U
#define NB_CFORC_FOC1_MASK              2U
#define NB_CFORC_FOC2_MASK              4U
#define NB_CFORC_FOC3_MASK              8U
#define NB_CFORC_FOC_MASK               15U
#define NB_CFORC_FOC_BITNUM             0U


/*** NB_OC3M - Output Compare 3 Mask Register; 0x00000F22 ***/
typedef union {
  byte Byte;
  struct {
    byte OC3M0       :1;                                       /* Output Compare 3 Mask Bit 0 */
    byte OC3M1       :1;                                       /* Output Compare 3 Mask Bit 1 */
    byte OC3M2       :1;                                       /* Output Compare 3 Mask Bit 2 */
    byte OC3M3       :1;                                       /* Output Compare 3 Mask Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpOC3M :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NB_OC3MSTR;
extern volatile NB_OC3MSTR _NB_OC3M @0x00000F22;
#define NB_OC3M                         _NB_OC3M.Byte
#define NB_OC3M_OC3M0                   _NB_OC3M.Bits.OC3M0
#define NB_OC3M_OC3M1                   _NB_OC3M.Bits.OC3M1
#define NB_OC3M_OC3M2                   _NB_OC3M.Bits.OC3M2
#define NB_OC3M_OC3M3                   _NB_OC3M.Bits.OC3M3
#define NB_OC3M_OC3M                    _NB_OC3M.MergedBits.grpOC3M

#define NB_OC3M_OC3M0_MASK              1U
#define NB_OC3M_OC3M1_MASK              2U
#define NB_OC3M_OC3M2_MASK              4U
#define NB_OC3M_OC3M3_MASK              8U
#define NB_OC3M_OC3M_MASK               15U
#define NB_OC3M_OC3M_BITNUM             0U


/*** NB_OC3D - Output Compare 3 Data Register; 0x00000F23 ***/
typedef union {
  byte Byte;
  struct {
    byte OC3D0       :1;                                       /* Output Compare 3 Bit 0 */
    byte OC3D1       :1;                                       /* Output Compare 3 Bit 1 */
    byte OC3D2       :1;                                       /* Output Compare 3 Bit 2 */
    byte OC3D3       :1;                                       /* Output Compare 3 Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpOC3D :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NB_OC3DSTR;
extern volatile NB_OC3DSTR _NB_OC3D @0x00000F23;
#define NB_OC3D                         _NB_OC3D.Byte
#define NB_OC3D_OC3D0                   _NB_OC3D.Bits.OC3D0
#define NB_OC3D_OC3D1                   _NB_OC3D.Bits.OC3D1
#define NB_OC3D_OC3D2                   _NB_OC3D.Bits.OC3D2
#define NB_OC3D_OC3D3                   _NB_OC3D.Bits.OC3D3
#define NB_OC3D_OC3D                    _NB_OC3D.MergedBits.grpOC3D

#define NB_OC3D_OC3D0_MASK              1U
#define NB_OC3D_OC3D1_MASK              2U
#define NB_OC3D_OC3D2_MASK              4U
#define NB_OC3D_OC3D3_MASK              8U
#define NB_OC3D_OC3D_MASK               15U
#define NB_OC3D_OC3D_BITNUM             0U


/*** NB_TCNT - Timer Count Register; 0x00000F24 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_TCNTHi - Timer Count Register High; 0x00000F24 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Count Register Bit 8 */
        byte BIT9        :1;                                       /* Timer Count Register Bit 9 */
        byte BIT10       :1;                                       /* Timer Count Register Bit 10 */
        byte BIT11       :1;                                       /* Timer Count Register Bit 11 */
        byte BIT12       :1;                                       /* Timer Count Register Bit 12 */
        byte BIT13       :1;                                       /* Timer Count Register Bit 13 */
        byte BIT14       :1;                                       /* Timer Count Register Bit 14 */
        byte BIT15       :1;                                       /* Timer Count Register Bit 15 */
      } Bits;
    } NB_TCNTHiSTR;
    #define NB_TCNTHi                   _NB_TCNT.Overlap_STR.NB_TCNTHiSTR.Byte
    #define NB_TCNTHi_BIT8              _NB_TCNT.Overlap_STR.NB_TCNTHiSTR.Bits.BIT8
    #define NB_TCNTHi_BIT9              _NB_TCNT.Overlap_STR.NB_TCNTHiSTR.Bits.BIT9
    #define NB_TCNTHi_BIT10             _NB_TCNT.Overlap_STR.NB_TCNTHiSTR.Bits.BIT10
    #define NB_TCNTHi_BIT11             _NB_TCNT.Overlap_STR.NB_TCNTHiSTR.Bits.BIT11
    #define NB_TCNTHi_BIT12             _NB_TCNT.Overlap_STR.NB_TCNTHiSTR.Bits.BIT12
    #define NB_TCNTHi_BIT13             _NB_TCNT.Overlap_STR.NB_TCNTHiSTR.Bits.BIT13
    #define NB_TCNTHi_BIT14             _NB_TCNT.Overlap_STR.NB_TCNTHiSTR.Bits.BIT14
    #define NB_TCNTHi_BIT15             _NB_TCNT.Overlap_STR.NB_TCNTHiSTR.Bits.BIT15
    
    #define NB_TCNTHi_BIT8_MASK         1U
    #define NB_TCNTHi_BIT9_MASK         2U
    #define NB_TCNTHi_BIT10_MASK        4U
    #define NB_TCNTHi_BIT11_MASK        8U
    #define NB_TCNTHi_BIT12_MASK        16U
    #define NB_TCNTHi_BIT13_MASK        32U
    #define NB_TCNTHi_BIT14_MASK        64U
    #define NB_TCNTHi_BIT15_MASK        128U
    

    /*** NB_TCNTLo - Timer Count Register Low; 0x00000F25 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Count Register Bit 0 */
        byte BIT1        :1;                                       /* Timer Count Register Bit 1 */
        byte BIT2        :1;                                       /* Timer Count Register Bit 2 */
        byte BIT3        :1;                                       /* Timer Count Register Bit 3 */
        byte BIT4        :1;                                       /* Timer Count Register Bit 4 */
        byte BIT5        :1;                                       /* Timer Count Register Bit 5 */
        byte BIT6        :1;                                       /* Timer Count Register Bit 6 */
        byte BIT7        :1;                                       /* Timer Count Register Bit 7 */
      } Bits;
    } NB_TCNTLoSTR;
    #define NB_TCNTLo                   _NB_TCNT.Overlap_STR.NB_TCNTLoSTR.Byte
    #define NB_TCNTLo_BIT0              _NB_TCNT.Overlap_STR.NB_TCNTLoSTR.Bits.BIT0
    #define NB_TCNTLo_BIT1              _NB_TCNT.Overlap_STR.NB_TCNTLoSTR.Bits.BIT1
    #define NB_TCNTLo_BIT2              _NB_TCNT.Overlap_STR.NB_TCNTLoSTR.Bits.BIT2
    #define NB_TCNTLo_BIT3              _NB_TCNT.Overlap_STR.NB_TCNTLoSTR.Bits.BIT3
    #define NB_TCNTLo_BIT4              _NB_TCNT.Overlap_STR.NB_TCNTLoSTR.Bits.BIT4
    #define NB_TCNTLo_BIT5              _NB_TCNT.Overlap_STR.NB_TCNTLoSTR.Bits.BIT5
    #define NB_TCNTLo_BIT6              _NB_TCNT.Overlap_STR.NB_TCNTLoSTR.Bits.BIT6
    #define NB_TCNTLo_BIT7              _NB_TCNT.Overlap_STR.NB_TCNTLoSTR.Bits.BIT7
    
    #define NB_TCNTLo_BIT0_MASK         1U
    #define NB_TCNTLo_BIT1_MASK         2U
    #define NB_TCNTLo_BIT2_MASK         4U
    #define NB_TCNTLo_BIT3_MASK         8U
    #define NB_TCNTLo_BIT4_MASK         16U
    #define NB_TCNTLo_BIT5_MASK         32U
    #define NB_TCNTLo_BIT6_MASK         64U
    #define NB_TCNTLo_BIT7_MASK         128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Timer Count Register Bit 0 */
    word BIT1        :1;                                       /* Timer Count Register Bit 1 */
    word BIT2        :1;                                       /* Timer Count Register Bit 2 */
    word BIT3        :1;                                       /* Timer Count Register Bit 3 */
    word BIT4        :1;                                       /* Timer Count Register Bit 4 */
    word BIT5        :1;                                       /* Timer Count Register Bit 5 */
    word BIT6        :1;                                       /* Timer Count Register Bit 6 */
    word BIT7        :1;                                       /* Timer Count Register Bit 7 */
    word BIT8        :1;                                       /* Timer Count Register Bit 8 */
    word BIT9        :1;                                       /* Timer Count Register Bit 9 */
    word BIT10       :1;                                       /* Timer Count Register Bit 10 */
    word BIT11       :1;                                       /* Timer Count Register Bit 11 */
    word BIT12       :1;                                       /* Timer Count Register Bit 12 */
    word BIT13       :1;                                       /* Timer Count Register Bit 13 */
    word BIT14       :1;                                       /* Timer Count Register Bit 14 */
    word BIT15       :1;                                       /* Timer Count Register Bit 15 */
  } Bits;
} NB_TCNTSTR;
extern volatile NB_TCNTSTR _NB_TCNT @0x00000F24;
#define NB_TCNT                         _NB_TCNT.Word
#define NB_TCNT_BIT0                    _NB_TCNT.Bits.BIT0
#define NB_TCNT_BIT1                    _NB_TCNT.Bits.BIT1
#define NB_TCNT_BIT2                    _NB_TCNT.Bits.BIT2
#define NB_TCNT_BIT3                    _NB_TCNT.Bits.BIT3
#define NB_TCNT_BIT4                    _NB_TCNT.Bits.BIT4
#define NB_TCNT_BIT5                    _NB_TCNT.Bits.BIT5
#define NB_TCNT_BIT6                    _NB_TCNT.Bits.BIT6
#define NB_TCNT_BIT7                    _NB_TCNT.Bits.BIT7
#define NB_TCNT_BIT8                    _NB_TCNT.Bits.BIT8
#define NB_TCNT_BIT9                    _NB_TCNT.Bits.BIT9
#define NB_TCNT_BIT10                   _NB_TCNT.Bits.BIT10
#define NB_TCNT_BIT11                   _NB_TCNT.Bits.BIT11
#define NB_TCNT_BIT12                   _NB_TCNT.Bits.BIT12
#define NB_TCNT_BIT13                   _NB_TCNT.Bits.BIT13
#define NB_TCNT_BIT14                   _NB_TCNT.Bits.BIT14
#define NB_TCNT_BIT15                   _NB_TCNT.Bits.BIT15

#define NB_TCNT_BIT0_MASK               1U
#define NB_TCNT_BIT1_MASK               2U
#define NB_TCNT_BIT2_MASK               4U
#define NB_TCNT_BIT3_MASK               8U
#define NB_TCNT_BIT4_MASK               16U
#define NB_TCNT_BIT5_MASK               32U
#define NB_TCNT_BIT6_MASK               64U
#define NB_TCNT_BIT7_MASK               128U
#define NB_TCNT_BIT8_MASK               256U
#define NB_TCNT_BIT9_MASK               512U
#define NB_TCNT_BIT10_MASK              1024U
#define NB_TCNT_BIT11_MASK              2048U
#define NB_TCNT_BIT12_MASK              4096U
#define NB_TCNT_BIT13_MASK              8192U
#define NB_TCNT_BIT14_MASK              16384U
#define NB_TCNT_BIT15_MASK              32768U


/*** NB_TSCR1 - Timer System Control Register1; 0x00000F26 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TFFCA       :1;                                       /* Timer Fast Flag Clear All */
    byte             :1; 
    byte             :1; 
    byte TEN         :1;                                       /* Timer Enable */
  } Bits;
} NB_TSCR1STR;
extern volatile NB_TSCR1STR _NB_TSCR1 @0x00000F26;
#define NB_TSCR1                        _NB_TSCR1.Byte
#define NB_TSCR1_TFFCA                  _NB_TSCR1.Bits.TFFCA
#define NB_TSCR1_TEN                    _NB_TSCR1.Bits.TEN

#define NB_TSCR1_TFFCA_MASK             16U
#define NB_TSCR1_TEN_MASK               128U


/*** NB_TTOV - Timer Toggle On Overflow Register; 0x00000F27 ***/
typedef union {
  byte Byte;
  struct {
    byte TOV0        :1;                                       /* Toggle On Overflow Bit 0 */
    byte TOV1        :1;                                       /* Toggle On Overflow Bit 1 */
    byte TOV2        :1;                                       /* Toggle On Overflow Bit 2 */
    byte TOV3        :1;                                       /* Toggle On Overflow Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTOV  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NB_TTOVSTR;
extern volatile NB_TTOVSTR _NB_TTOV @0x00000F27;
#define NB_TTOV                         _NB_TTOV.Byte
#define NB_TTOV_TOV0                    _NB_TTOV.Bits.TOV0
#define NB_TTOV_TOV1                    _NB_TTOV.Bits.TOV1
#define NB_TTOV_TOV2                    _NB_TTOV.Bits.TOV2
#define NB_TTOV_TOV3                    _NB_TTOV.Bits.TOV3
#define NB_TTOV_TOV                     _NB_TTOV.MergedBits.grpTOV

#define NB_TTOV_TOV0_MASK               1U
#define NB_TTOV_TOV1_MASK               2U
#define NB_TTOV_TOV2_MASK               4U
#define NB_TTOV_TOV3_MASK               8U
#define NB_TTOV_TOV_MASK                15U
#define NB_TTOV_TOV_BITNUM              0U


/*** NB_TCTL1 - Timer Control Register 1; 0x00000F28 ***/
typedef union {
  byte Byte;
  struct {
    byte OL0         :1;                                       /* Output Level Bit 0 */
    byte OM0         :1;                                       /* Output Mode Bit 0 */
    byte OL1         :1;                                       /* Output Lecel Bit 1 */
    byte OM1         :1;                                       /* Output Mode Bit 1 */
    byte OL2         :1;                                       /* Output Level Bit 2 */
    byte OM2         :1;                                       /* Output Mode Bit 2 */
    byte OL3         :1;                                       /* Output Level Bit 3 */
    byte OM3         :1;                                       /* Output Mode Bit 3 */
  } Bits;
} NB_TCTL1STR;
extern volatile NB_TCTL1STR _NB_TCTL1 @0x00000F28;
#define NB_TCTL1                        _NB_TCTL1.Byte
#define NB_TCTL1_OL0                    _NB_TCTL1.Bits.OL0
#define NB_TCTL1_OM0                    _NB_TCTL1.Bits.OM0
#define NB_TCTL1_OL1                    _NB_TCTL1.Bits.OL1
#define NB_TCTL1_OM1                    _NB_TCTL1.Bits.OM1
#define NB_TCTL1_OL2                    _NB_TCTL1.Bits.OL2
#define NB_TCTL1_OM2                    _NB_TCTL1.Bits.OM2
#define NB_TCTL1_OL3                    _NB_TCTL1.Bits.OL3
#define NB_TCTL1_OM3                    _NB_TCTL1.Bits.OM3

#define NB_TCTL1_OL0_MASK               1U
#define NB_TCTL1_OM0_MASK               2U
#define NB_TCTL1_OL1_MASK               4U
#define NB_TCTL1_OM1_MASK               8U
#define NB_TCTL1_OL2_MASK               16U
#define NB_TCTL1_OM2_MASK               32U
#define NB_TCTL1_OL3_MASK               64U
#define NB_TCTL1_OM3_MASK               128U


/*** NB_TCTL2 - Timer Control Register 2; 0x00000F29 ***/
typedef union {
  byte Byte;
  struct {
    byte EDG0A       :1;                                       /* Input Capture Edge 0 Control A */
    byte EDG0B       :1;                                       /* Input Capture Edge 0 Control B */
    byte EDG1A       :1;                                       /* Input Capture Edge 1 Control A */
    byte EDG1B       :1;                                       /* Input Capture Edge 1 Control B */
    byte EDG2A       :1;                                       /* Input Capture Edge 2 Control A */
    byte EDG2B       :1;                                       /* Input Capture Edge 2 Control B */
    byte EDG3A       :1;                                       /* Input Capture Edge 3 Control A */
    byte EDG3B       :1;                                       /* Input Capture Edge 3 Control B */
  } Bits;
  struct {
    byte grpEDG0x :2;
    byte grpEDG1x :2;
    byte grpEDG2x :2;
    byte grpEDG3x :2;
  } MergedBits;
} NB_TCTL2STR;
extern volatile NB_TCTL2STR _NB_TCTL2 @0x00000F29;
#define NB_TCTL2                        _NB_TCTL2.Byte
#define NB_TCTL2_EDG0A                  _NB_TCTL2.Bits.EDG0A
#define NB_TCTL2_EDG0B                  _NB_TCTL2.Bits.EDG0B
#define NB_TCTL2_EDG1A                  _NB_TCTL2.Bits.EDG1A
#define NB_TCTL2_EDG1B                  _NB_TCTL2.Bits.EDG1B
#define NB_TCTL2_EDG2A                  _NB_TCTL2.Bits.EDG2A
#define NB_TCTL2_EDG2B                  _NB_TCTL2.Bits.EDG2B
#define NB_TCTL2_EDG3A                  _NB_TCTL2.Bits.EDG3A
#define NB_TCTL2_EDG3B                  _NB_TCTL2.Bits.EDG3B
#define NB_TCTL2_EDG0x                  _NB_TCTL2.MergedBits.grpEDG0x
#define NB_TCTL2_EDG1x                  _NB_TCTL2.MergedBits.grpEDG1x
#define NB_TCTL2_EDG2x                  _NB_TCTL2.MergedBits.grpEDG2x
#define NB_TCTL2_EDG3x                  _NB_TCTL2.MergedBits.grpEDG3x

#define NB_TCTL2_EDG0A_MASK             1U
#define NB_TCTL2_EDG0B_MASK             2U
#define NB_TCTL2_EDG1A_MASK             4U
#define NB_TCTL2_EDG1B_MASK             8U
#define NB_TCTL2_EDG2A_MASK             16U
#define NB_TCTL2_EDG2B_MASK             32U
#define NB_TCTL2_EDG3A_MASK             64U
#define NB_TCTL2_EDG3B_MASK             128U
#define NB_TCTL2_EDG0x_MASK             3U
#define NB_TCTL2_EDG0x_BITNUM           0U
#define NB_TCTL2_EDG1x_MASK             12U
#define NB_TCTL2_EDG1x_BITNUM           2U
#define NB_TCTL2_EDG2x_MASK             48U
#define NB_TCTL2_EDG2x_BITNUM           4U
#define NB_TCTL2_EDG3x_MASK             192U
#define NB_TCTL2_EDG3x_BITNUM           6U


/*** NB_TIE - Timer Interrupt Enable Register; 0x00000F2A ***/
typedef union {
  byte Byte;
  struct {
    byte C0I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 0 */
    byte C1I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 1 */
    byte C2I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 2 */
    byte C3I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NB_TIESTR;
extern volatile NB_TIESTR _NB_TIE @0x00000F2A;
#define NB_TIE                          _NB_TIE.Byte
#define NB_TIE_C0I                      _NB_TIE.Bits.C0I
#define NB_TIE_C1I                      _NB_TIE.Bits.C1I
#define NB_TIE_C2I                      _NB_TIE.Bits.C2I
#define NB_TIE_C3I                      _NB_TIE.Bits.C3I

#define NB_TIE_C0I_MASK                 1U
#define NB_TIE_C1I_MASK                 2U
#define NB_TIE_C2I_MASK                 4U
#define NB_TIE_C3I_MASK                 8U


/*** NB_TSCR2 - Timer System Control Register 2; 0x00000F2B ***/
typedef union {
  byte Byte;
  struct {
    byte PR0         :1;                                       /* Timer Prescaler Select Bit 0 */
    byte PR1         :1;                                       /* Timer Prescaler Select Bit 1 */
    byte PR2         :1;                                       /* Timer Prescaler Select Bit 2 */
    byte TCRE        :1;                                       /* Timer Counter Reset Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOI         :1;                                       /* Timer Overflow Interrupt Enable */
  } Bits;
  struct {
    byte grpPR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NB_TSCR2STR;
extern volatile NB_TSCR2STR _NB_TSCR2 @0x00000F2B;
#define NB_TSCR2                        _NB_TSCR2.Byte
#define NB_TSCR2_PR0                    _NB_TSCR2.Bits.PR0
#define NB_TSCR2_PR1                    _NB_TSCR2.Bits.PR1
#define NB_TSCR2_PR2                    _NB_TSCR2.Bits.PR2
#define NB_TSCR2_TCRE                   _NB_TSCR2.Bits.TCRE
#define NB_TSCR2_TOI                    _NB_TSCR2.Bits.TOI
#define NB_TSCR2_PR                     _NB_TSCR2.MergedBits.grpPR

#define NB_TSCR2_PR0_MASK               1U
#define NB_TSCR2_PR1_MASK               2U
#define NB_TSCR2_PR2_MASK               4U
#define NB_TSCR2_TCRE_MASK              8U
#define NB_TSCR2_TOI_MASK               128U
#define NB_TSCR2_PR_MASK                7U
#define NB_TSCR2_PR_BITNUM              0U


/*** NB_TFLG1 - Main Timer Interrupt Flag 1; 0x00000F2C ***/
typedef union {
  byte Byte;
  struct {
    byte C0F         :1;                                       /* Input Capture/Output Compare Channel Flag 0 */
    byte C1F         :1;                                       /* Input Capture/Output Compare Channel Flag 1 */
    byte C2F         :1;                                       /* Input Capture/Output Compare Channel Flag 2 */
    byte C3F         :1;                                       /* Input Capture/Output Compare Channel Flag 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NB_TFLG1STR;
extern volatile NB_TFLG1STR _NB_TFLG1 @0x00000F2C;
#define NB_TFLG1                        _NB_TFLG1.Byte
#define NB_TFLG1_C0F                    _NB_TFLG1.Bits.C0F
#define NB_TFLG1_C1F                    _NB_TFLG1.Bits.C1F
#define NB_TFLG1_C2F                    _NB_TFLG1.Bits.C2F
#define NB_TFLG1_C3F                    _NB_TFLG1.Bits.C3F

#define NB_TFLG1_C0F_MASK               1U
#define NB_TFLG1_C1F_MASK               2U
#define NB_TFLG1_C2F_MASK               4U
#define NB_TFLG1_C3F_MASK               8U


/*** NB_TFLG2 - Main Timer Interrupt Flag 2; 0x00000F2D ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
} NB_TFLG2STR;
extern volatile NB_TFLG2STR _NB_TFLG2 @0x00000F2D;
#define NB_TFLG2                        _NB_TFLG2.Byte
#define NB_TFLG2_TOF                    _NB_TFLG2.Bits.TOF

#define NB_TFLG2_TOF_MASK               128U


/*** NB_TC0 - Timer Input Capture/Output Compare Register 0; 0x00000F2E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_TC0Hi - Timer Input Capture/Output Compare Register 0 High; 0x00000F2E ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 8 */
        byte BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 9 */
        byte BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 10 */
        byte BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 11 */
        byte BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 12 */
        byte BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 13 */
        byte BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 14 */
        byte BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 15 */
      } Bits;
    } NB_TC0HiSTR;
    #define NB_TC0Hi                    _NB_TC0.Overlap_STR.NB_TC0HiSTR.Byte
    #define NB_TC0Hi_BIT8               _NB_TC0.Overlap_STR.NB_TC0HiSTR.Bits.BIT8
    #define NB_TC0Hi_BIT9               _NB_TC0.Overlap_STR.NB_TC0HiSTR.Bits.BIT9
    #define NB_TC0Hi_BIT10              _NB_TC0.Overlap_STR.NB_TC0HiSTR.Bits.BIT10
    #define NB_TC0Hi_BIT11              _NB_TC0.Overlap_STR.NB_TC0HiSTR.Bits.BIT11
    #define NB_TC0Hi_BIT12              _NB_TC0.Overlap_STR.NB_TC0HiSTR.Bits.BIT12
    #define NB_TC0Hi_BIT13              _NB_TC0.Overlap_STR.NB_TC0HiSTR.Bits.BIT13
    #define NB_TC0Hi_BIT14              _NB_TC0.Overlap_STR.NB_TC0HiSTR.Bits.BIT14
    #define NB_TC0Hi_BIT15              _NB_TC0.Overlap_STR.NB_TC0HiSTR.Bits.BIT15
    
    #define NB_TC0Hi_BIT8_MASK          1U
    #define NB_TC0Hi_BIT9_MASK          2U
    #define NB_TC0Hi_BIT10_MASK         4U
    #define NB_TC0Hi_BIT11_MASK         8U
    #define NB_TC0Hi_BIT12_MASK         16U
    #define NB_TC0Hi_BIT13_MASK         32U
    #define NB_TC0Hi_BIT14_MASK         64U
    #define NB_TC0Hi_BIT15_MASK         128U
    

    /*** NB_TC0Lo - Timer Input Capture/Output Compare Register 0 Low; 0x00000F2F ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 0 */
        byte BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 1 */
        byte BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 2 */
        byte BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 3 */
        byte BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 4 */
        byte BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 5 */
        byte BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 6 */
        byte BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 7 */
      } Bits;
    } NB_TC0LoSTR;
    #define NB_TC0Lo                    _NB_TC0.Overlap_STR.NB_TC0LoSTR.Byte
    #define NB_TC0Lo_BIT0               _NB_TC0.Overlap_STR.NB_TC0LoSTR.Bits.BIT0
    #define NB_TC0Lo_BIT1               _NB_TC0.Overlap_STR.NB_TC0LoSTR.Bits.BIT1
    #define NB_TC0Lo_BIT2               _NB_TC0.Overlap_STR.NB_TC0LoSTR.Bits.BIT2
    #define NB_TC0Lo_BIT3               _NB_TC0.Overlap_STR.NB_TC0LoSTR.Bits.BIT3
    #define NB_TC0Lo_BIT4               _NB_TC0.Overlap_STR.NB_TC0LoSTR.Bits.BIT4
    #define NB_TC0Lo_BIT5               _NB_TC0.Overlap_STR.NB_TC0LoSTR.Bits.BIT5
    #define NB_TC0Lo_BIT6               _NB_TC0.Overlap_STR.NB_TC0LoSTR.Bits.BIT6
    #define NB_TC0Lo_BIT7               _NB_TC0.Overlap_STR.NB_TC0LoSTR.Bits.BIT7
    
    #define NB_TC0Lo_BIT0_MASK          1U
    #define NB_TC0Lo_BIT1_MASK          2U
    #define NB_TC0Lo_BIT2_MASK          4U
    #define NB_TC0Lo_BIT3_MASK          8U
    #define NB_TC0Lo_BIT4_MASK          16U
    #define NB_TC0Lo_BIT5_MASK          32U
    #define NB_TC0Lo_BIT6_MASK          64U
    #define NB_TC0Lo_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 0 */
    word BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 1 */
    word BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 2 */
    word BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 3 */
    word BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 4 */
    word BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 5 */
    word BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 6 */
    word BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 7 */
    word BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 8 */
    word BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 9 */
    word BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 10 */
    word BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 11 */
    word BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 12 */
    word BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 13 */
    word BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 14 */
    word BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 0 Bit 15 */
  } Bits;
} NB_TC0STR;
extern volatile NB_TC0STR _NB_TC0 @0x00000F2E;
#define NB_TC0                          _NB_TC0.Word
#define NB_TC0_BIT0                     _NB_TC0.Bits.BIT0
#define NB_TC0_BIT1                     _NB_TC0.Bits.BIT1
#define NB_TC0_BIT2                     _NB_TC0.Bits.BIT2
#define NB_TC0_BIT3                     _NB_TC0.Bits.BIT3
#define NB_TC0_BIT4                     _NB_TC0.Bits.BIT4
#define NB_TC0_BIT5                     _NB_TC0.Bits.BIT5
#define NB_TC0_BIT6                     _NB_TC0.Bits.BIT6
#define NB_TC0_BIT7                     _NB_TC0.Bits.BIT7
#define NB_TC0_BIT8                     _NB_TC0.Bits.BIT8
#define NB_TC0_BIT9                     _NB_TC0.Bits.BIT9
#define NB_TC0_BIT10                    _NB_TC0.Bits.BIT10
#define NB_TC0_BIT11                    _NB_TC0.Bits.BIT11
#define NB_TC0_BIT12                    _NB_TC0.Bits.BIT12
#define NB_TC0_BIT13                    _NB_TC0.Bits.BIT13
#define NB_TC0_BIT14                    _NB_TC0.Bits.BIT14
#define NB_TC0_BIT15                    _NB_TC0.Bits.BIT15
/* NB_TC_ARR: Access 4 NB_TCx registers in an array */
#define NB_TC_ARR                       ((volatile word *) &NB_TC0)

#define NB_TC0_BIT0_MASK                1U
#define NB_TC0_BIT1_MASK                2U
#define NB_TC0_BIT2_MASK                4U
#define NB_TC0_BIT3_MASK                8U
#define NB_TC0_BIT4_MASK                16U
#define NB_TC0_BIT5_MASK                32U
#define NB_TC0_BIT6_MASK                64U
#define NB_TC0_BIT7_MASK                128U
#define NB_TC0_BIT8_MASK                256U
#define NB_TC0_BIT9_MASK                512U
#define NB_TC0_BIT10_MASK               1024U
#define NB_TC0_BIT11_MASK               2048U
#define NB_TC0_BIT12_MASK               4096U
#define NB_TC0_BIT13_MASK               8192U
#define NB_TC0_BIT14_MASK               16384U
#define NB_TC0_BIT15_MASK               32768U


/*** NB_TC1 - Timer Input Capture/Output Compare Register 1; 0x00000F30 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_TC1Hi - Timer Input Capture/Output Compare Register 1 High; 0x00000F30 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 8 */
        byte BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 9 */
        byte BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 10 */
        byte BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 11 */
        byte BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 12 */
        byte BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 13 */
        byte BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 14 */
        byte BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 15 */
      } Bits;
    } NB_TC1HiSTR;
    #define NB_TC1Hi                    _NB_TC1.Overlap_STR.NB_TC1HiSTR.Byte
    #define NB_TC1Hi_BIT8               _NB_TC1.Overlap_STR.NB_TC1HiSTR.Bits.BIT8
    #define NB_TC1Hi_BIT9               _NB_TC1.Overlap_STR.NB_TC1HiSTR.Bits.BIT9
    #define NB_TC1Hi_BIT10              _NB_TC1.Overlap_STR.NB_TC1HiSTR.Bits.BIT10
    #define NB_TC1Hi_BIT11              _NB_TC1.Overlap_STR.NB_TC1HiSTR.Bits.BIT11
    #define NB_TC1Hi_BIT12              _NB_TC1.Overlap_STR.NB_TC1HiSTR.Bits.BIT12
    #define NB_TC1Hi_BIT13              _NB_TC1.Overlap_STR.NB_TC1HiSTR.Bits.BIT13
    #define NB_TC1Hi_BIT14              _NB_TC1.Overlap_STR.NB_TC1HiSTR.Bits.BIT14
    #define NB_TC1Hi_BIT15              _NB_TC1.Overlap_STR.NB_TC1HiSTR.Bits.BIT15
    
    #define NB_TC1Hi_BIT8_MASK          1U
    #define NB_TC1Hi_BIT9_MASK          2U
    #define NB_TC1Hi_BIT10_MASK         4U
    #define NB_TC1Hi_BIT11_MASK         8U
    #define NB_TC1Hi_BIT12_MASK         16U
    #define NB_TC1Hi_BIT13_MASK         32U
    #define NB_TC1Hi_BIT14_MASK         64U
    #define NB_TC1Hi_BIT15_MASK         128U
    

    /*** NB_TC1Lo - Timer Input Capture/Output Compare Register 1 Low; 0x00000F31 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 0 */
        byte BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 1 */
        byte BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 2 */
        byte BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 3 */
        byte BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 4 */
        byte BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 5 */
        byte BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 6 */
        byte BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 7 */
      } Bits;
    } NB_TC1LoSTR;
    #define NB_TC1Lo                    _NB_TC1.Overlap_STR.NB_TC1LoSTR.Byte
    #define NB_TC1Lo_BIT0               _NB_TC1.Overlap_STR.NB_TC1LoSTR.Bits.BIT0
    #define NB_TC1Lo_BIT1               _NB_TC1.Overlap_STR.NB_TC1LoSTR.Bits.BIT1
    #define NB_TC1Lo_BIT2               _NB_TC1.Overlap_STR.NB_TC1LoSTR.Bits.BIT2
    #define NB_TC1Lo_BIT3               _NB_TC1.Overlap_STR.NB_TC1LoSTR.Bits.BIT3
    #define NB_TC1Lo_BIT4               _NB_TC1.Overlap_STR.NB_TC1LoSTR.Bits.BIT4
    #define NB_TC1Lo_BIT5               _NB_TC1.Overlap_STR.NB_TC1LoSTR.Bits.BIT5
    #define NB_TC1Lo_BIT6               _NB_TC1.Overlap_STR.NB_TC1LoSTR.Bits.BIT6
    #define NB_TC1Lo_BIT7               _NB_TC1.Overlap_STR.NB_TC1LoSTR.Bits.BIT7
    
    #define NB_TC1Lo_BIT0_MASK          1U
    #define NB_TC1Lo_BIT1_MASK          2U
    #define NB_TC1Lo_BIT2_MASK          4U
    #define NB_TC1Lo_BIT3_MASK          8U
    #define NB_TC1Lo_BIT4_MASK          16U
    #define NB_TC1Lo_BIT5_MASK          32U
    #define NB_TC1Lo_BIT6_MASK          64U
    #define NB_TC1Lo_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 0 */
    word BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 1 */
    word BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 2 */
    word BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 3 */
    word BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 4 */
    word BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 5 */
    word BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 6 */
    word BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 7 */
    word BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 8 */
    word BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 9 */
    word BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 10 */
    word BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 11 */
    word BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 12 */
    word BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 13 */
    word BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 14 */
    word BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 1 Bit 15 */
  } Bits;
} NB_TC1STR;
extern volatile NB_TC1STR _NB_TC1 @0x00000F30;
#define NB_TC1                          _NB_TC1.Word
#define NB_TC1_BIT0                     _NB_TC1.Bits.BIT0
#define NB_TC1_BIT1                     _NB_TC1.Bits.BIT1
#define NB_TC1_BIT2                     _NB_TC1.Bits.BIT2
#define NB_TC1_BIT3                     _NB_TC1.Bits.BIT3
#define NB_TC1_BIT4                     _NB_TC1.Bits.BIT4
#define NB_TC1_BIT5                     _NB_TC1.Bits.BIT5
#define NB_TC1_BIT6                     _NB_TC1.Bits.BIT6
#define NB_TC1_BIT7                     _NB_TC1.Bits.BIT7
#define NB_TC1_BIT8                     _NB_TC1.Bits.BIT8
#define NB_TC1_BIT9                     _NB_TC1.Bits.BIT9
#define NB_TC1_BIT10                    _NB_TC1.Bits.BIT10
#define NB_TC1_BIT11                    _NB_TC1.Bits.BIT11
#define NB_TC1_BIT12                    _NB_TC1.Bits.BIT12
#define NB_TC1_BIT13                    _NB_TC1.Bits.BIT13
#define NB_TC1_BIT14                    _NB_TC1.Bits.BIT14
#define NB_TC1_BIT15                    _NB_TC1.Bits.BIT15

#define NB_TC1_BIT0_MASK                1U
#define NB_TC1_BIT1_MASK                2U
#define NB_TC1_BIT2_MASK                4U
#define NB_TC1_BIT3_MASK                8U
#define NB_TC1_BIT4_MASK                16U
#define NB_TC1_BIT5_MASK                32U
#define NB_TC1_BIT6_MASK                64U
#define NB_TC1_BIT7_MASK                128U
#define NB_TC1_BIT8_MASK                256U
#define NB_TC1_BIT9_MASK                512U
#define NB_TC1_BIT10_MASK               1024U
#define NB_TC1_BIT11_MASK               2048U
#define NB_TC1_BIT12_MASK               4096U
#define NB_TC1_BIT13_MASK               8192U
#define NB_TC1_BIT14_MASK               16384U
#define NB_TC1_BIT15_MASK               32768U


/*** NB_TC2 - Timer Input Capture/Output Compare Register 2; 0x00000F32 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_TC2Hi - Timer Input Capture/Output Compare Register 2 High; 0x00000F32 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 8 */
        byte BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 9 */
        byte BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 10 */
        byte BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 11 */
        byte BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 12 */
        byte BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 13 */
        byte BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 14 */
        byte BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 15 */
      } Bits;
    } NB_TC2HiSTR;
    #define NB_TC2Hi                    _NB_TC2.Overlap_STR.NB_TC2HiSTR.Byte
    #define NB_TC2Hi_BIT8               _NB_TC2.Overlap_STR.NB_TC2HiSTR.Bits.BIT8
    #define NB_TC2Hi_BIT9               _NB_TC2.Overlap_STR.NB_TC2HiSTR.Bits.BIT9
    #define NB_TC2Hi_BIT10              _NB_TC2.Overlap_STR.NB_TC2HiSTR.Bits.BIT10
    #define NB_TC2Hi_BIT11              _NB_TC2.Overlap_STR.NB_TC2HiSTR.Bits.BIT11
    #define NB_TC2Hi_BIT12              _NB_TC2.Overlap_STR.NB_TC2HiSTR.Bits.BIT12
    #define NB_TC2Hi_BIT13              _NB_TC2.Overlap_STR.NB_TC2HiSTR.Bits.BIT13
    #define NB_TC2Hi_BIT14              _NB_TC2.Overlap_STR.NB_TC2HiSTR.Bits.BIT14
    #define NB_TC2Hi_BIT15              _NB_TC2.Overlap_STR.NB_TC2HiSTR.Bits.BIT15
    
    #define NB_TC2Hi_BIT8_MASK          1U
    #define NB_TC2Hi_BIT9_MASK          2U
    #define NB_TC2Hi_BIT10_MASK         4U
    #define NB_TC2Hi_BIT11_MASK         8U
    #define NB_TC2Hi_BIT12_MASK         16U
    #define NB_TC2Hi_BIT13_MASK         32U
    #define NB_TC2Hi_BIT14_MASK         64U
    #define NB_TC2Hi_BIT15_MASK         128U
    

    /*** NB_TC2Lo - Timer Input Capture/Output Compare Register 2 Low; 0x00000F33 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 0 */
        byte BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 1 */
        byte BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 2 */
        byte BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 3 */
        byte BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 4 */
        byte BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 5 */
        byte BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 6 */
        byte BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 7 */
      } Bits;
    } NB_TC2LoSTR;
    #define NB_TC2Lo                    _NB_TC2.Overlap_STR.NB_TC2LoSTR.Byte
    #define NB_TC2Lo_BIT0               _NB_TC2.Overlap_STR.NB_TC2LoSTR.Bits.BIT0
    #define NB_TC2Lo_BIT1               _NB_TC2.Overlap_STR.NB_TC2LoSTR.Bits.BIT1
    #define NB_TC2Lo_BIT2               _NB_TC2.Overlap_STR.NB_TC2LoSTR.Bits.BIT2
    #define NB_TC2Lo_BIT3               _NB_TC2.Overlap_STR.NB_TC2LoSTR.Bits.BIT3
    #define NB_TC2Lo_BIT4               _NB_TC2.Overlap_STR.NB_TC2LoSTR.Bits.BIT4
    #define NB_TC2Lo_BIT5               _NB_TC2.Overlap_STR.NB_TC2LoSTR.Bits.BIT5
    #define NB_TC2Lo_BIT6               _NB_TC2.Overlap_STR.NB_TC2LoSTR.Bits.BIT6
    #define NB_TC2Lo_BIT7               _NB_TC2.Overlap_STR.NB_TC2LoSTR.Bits.BIT7
    
    #define NB_TC2Lo_BIT0_MASK          1U
    #define NB_TC2Lo_BIT1_MASK          2U
    #define NB_TC2Lo_BIT2_MASK          4U
    #define NB_TC2Lo_BIT3_MASK          8U
    #define NB_TC2Lo_BIT4_MASK          16U
    #define NB_TC2Lo_BIT5_MASK          32U
    #define NB_TC2Lo_BIT6_MASK          64U
    #define NB_TC2Lo_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 0 */
    word BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 1 */
    word BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 2 */
    word BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 3 */
    word BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 4 */
    word BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 5 */
    word BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 6 */
    word BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 7 */
    word BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 8 */
    word BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 9 */
    word BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 10 */
    word BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 11 */
    word BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 12 */
    word BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 13 */
    word BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 14 */
    word BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 2 Bit 15 */
  } Bits;
} NB_TC2STR;
extern volatile NB_TC2STR _NB_TC2 @0x00000F32;
#define NB_TC2                          _NB_TC2.Word
#define NB_TC2_BIT0                     _NB_TC2.Bits.BIT0
#define NB_TC2_BIT1                     _NB_TC2.Bits.BIT1
#define NB_TC2_BIT2                     _NB_TC2.Bits.BIT2
#define NB_TC2_BIT3                     _NB_TC2.Bits.BIT3
#define NB_TC2_BIT4                     _NB_TC2.Bits.BIT4
#define NB_TC2_BIT5                     _NB_TC2.Bits.BIT5
#define NB_TC2_BIT6                     _NB_TC2.Bits.BIT6
#define NB_TC2_BIT7                     _NB_TC2.Bits.BIT7
#define NB_TC2_BIT8                     _NB_TC2.Bits.BIT8
#define NB_TC2_BIT9                     _NB_TC2.Bits.BIT9
#define NB_TC2_BIT10                    _NB_TC2.Bits.BIT10
#define NB_TC2_BIT11                    _NB_TC2.Bits.BIT11
#define NB_TC2_BIT12                    _NB_TC2.Bits.BIT12
#define NB_TC2_BIT13                    _NB_TC2.Bits.BIT13
#define NB_TC2_BIT14                    _NB_TC2.Bits.BIT14
#define NB_TC2_BIT15                    _NB_TC2.Bits.BIT15

#define NB_TC2_BIT0_MASK                1U
#define NB_TC2_BIT1_MASK                2U
#define NB_TC2_BIT2_MASK                4U
#define NB_TC2_BIT3_MASK                8U
#define NB_TC2_BIT4_MASK                16U
#define NB_TC2_BIT5_MASK                32U
#define NB_TC2_BIT6_MASK                64U
#define NB_TC2_BIT7_MASK                128U
#define NB_TC2_BIT8_MASK                256U
#define NB_TC2_BIT9_MASK                512U
#define NB_TC2_BIT10_MASK               1024U
#define NB_TC2_BIT11_MASK               2048U
#define NB_TC2_BIT12_MASK               4096U
#define NB_TC2_BIT13_MASK               8192U
#define NB_TC2_BIT14_MASK               16384U
#define NB_TC2_BIT15_MASK               32768U


/*** NB_TC3 - Timer Input Capture/Output Compare Register 3; 0x00000F34 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_TC3Hi - Timer Input Capture/Output Compare Register 3 High; 0x00000F34 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 8 */
        byte BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 9 */
        byte BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 10 */
        byte BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 11 */
        byte BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 12 */
        byte BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 13 */
        byte BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 14 */
        byte BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 15 */
      } Bits;
    } NB_TC3HiSTR;
    #define NB_TC3Hi                    _NB_TC3.Overlap_STR.NB_TC3HiSTR.Byte
    #define NB_TC3Hi_BIT8               _NB_TC3.Overlap_STR.NB_TC3HiSTR.Bits.BIT8
    #define NB_TC3Hi_BIT9               _NB_TC3.Overlap_STR.NB_TC3HiSTR.Bits.BIT9
    #define NB_TC3Hi_BIT10              _NB_TC3.Overlap_STR.NB_TC3HiSTR.Bits.BIT10
    #define NB_TC3Hi_BIT11              _NB_TC3.Overlap_STR.NB_TC3HiSTR.Bits.BIT11
    #define NB_TC3Hi_BIT12              _NB_TC3.Overlap_STR.NB_TC3HiSTR.Bits.BIT12
    #define NB_TC3Hi_BIT13              _NB_TC3.Overlap_STR.NB_TC3HiSTR.Bits.BIT13
    #define NB_TC3Hi_BIT14              _NB_TC3.Overlap_STR.NB_TC3HiSTR.Bits.BIT14
    #define NB_TC3Hi_BIT15              _NB_TC3.Overlap_STR.NB_TC3HiSTR.Bits.BIT15
    
    #define NB_TC3Hi_BIT8_MASK          1U
    #define NB_TC3Hi_BIT9_MASK          2U
    #define NB_TC3Hi_BIT10_MASK         4U
    #define NB_TC3Hi_BIT11_MASK         8U
    #define NB_TC3Hi_BIT12_MASK         16U
    #define NB_TC3Hi_BIT13_MASK         32U
    #define NB_TC3Hi_BIT14_MASK         64U
    #define NB_TC3Hi_BIT15_MASK         128U
    

    /*** NB_TC3Lo - Timer Input Capture/Output Compare Register 3 Low; 0x00000F35 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 0 */
        byte BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 1 */
        byte BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 2 */
        byte BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 3 */
        byte BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 4 */
        byte BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 5 */
        byte BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 6 */
        byte BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 7 */
      } Bits;
    } NB_TC3LoSTR;
    #define NB_TC3Lo                    _NB_TC3.Overlap_STR.NB_TC3LoSTR.Byte
    #define NB_TC3Lo_BIT0               _NB_TC3.Overlap_STR.NB_TC3LoSTR.Bits.BIT0
    #define NB_TC3Lo_BIT1               _NB_TC3.Overlap_STR.NB_TC3LoSTR.Bits.BIT1
    #define NB_TC3Lo_BIT2               _NB_TC3.Overlap_STR.NB_TC3LoSTR.Bits.BIT2
    #define NB_TC3Lo_BIT3               _NB_TC3.Overlap_STR.NB_TC3LoSTR.Bits.BIT3
    #define NB_TC3Lo_BIT4               _NB_TC3.Overlap_STR.NB_TC3LoSTR.Bits.BIT4
    #define NB_TC3Lo_BIT5               _NB_TC3.Overlap_STR.NB_TC3LoSTR.Bits.BIT5
    #define NB_TC3Lo_BIT6               _NB_TC3.Overlap_STR.NB_TC3LoSTR.Bits.BIT6
    #define NB_TC3Lo_BIT7               _NB_TC3.Overlap_STR.NB_TC3LoSTR.Bits.BIT7
    
    #define NB_TC3Lo_BIT0_MASK          1U
    #define NB_TC3Lo_BIT1_MASK          2U
    #define NB_TC3Lo_BIT2_MASK          4U
    #define NB_TC3Lo_BIT3_MASK          8U
    #define NB_TC3Lo_BIT4_MASK          16U
    #define NB_TC3Lo_BIT5_MASK          32U
    #define NB_TC3Lo_BIT6_MASK          64U
    #define NB_TC3Lo_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 0 */
    word BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 1 */
    word BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 2 */
    word BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 3 */
    word BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 4 */
    word BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 5 */
    word BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 6 */
    word BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 7 */
    word BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 8 */
    word BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 9 */
    word BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 10 */
    word BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 11 */
    word BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 12 */
    word BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 13 */
    word BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 14 */
    word BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 3 Bit 15 */
  } Bits;
} NB_TC3STR;
extern volatile NB_TC3STR _NB_TC3 @0x00000F34;
#define NB_TC3                          _NB_TC3.Word
#define NB_TC3_BIT0                     _NB_TC3.Bits.BIT0
#define NB_TC3_BIT1                     _NB_TC3.Bits.BIT1
#define NB_TC3_BIT2                     _NB_TC3.Bits.BIT2
#define NB_TC3_BIT3                     _NB_TC3.Bits.BIT3
#define NB_TC3_BIT4                     _NB_TC3.Bits.BIT4
#define NB_TC3_BIT5                     _NB_TC3.Bits.BIT5
#define NB_TC3_BIT6                     _NB_TC3.Bits.BIT6
#define NB_TC3_BIT7                     _NB_TC3.Bits.BIT7
#define NB_TC3_BIT8                     _NB_TC3.Bits.BIT8
#define NB_TC3_BIT9                     _NB_TC3.Bits.BIT9
#define NB_TC3_BIT10                    _NB_TC3.Bits.BIT10
#define NB_TC3_BIT11                    _NB_TC3.Bits.BIT11
#define NB_TC3_BIT12                    _NB_TC3.Bits.BIT12
#define NB_TC3_BIT13                    _NB_TC3.Bits.BIT13
#define NB_TC3_BIT14                    _NB_TC3.Bits.BIT14
#define NB_TC3_BIT15                    _NB_TC3.Bits.BIT15

#define NB_TC3_BIT0_MASK                1U
#define NB_TC3_BIT1_MASK                2U
#define NB_TC3_BIT2_MASK                4U
#define NB_TC3_BIT3_MASK                8U
#define NB_TC3_BIT4_MASK                16U
#define NB_TC3_BIT5_MASK                32U
#define NB_TC3_BIT6_MASK                64U
#define NB_TC3_BIT7_MASK                128U
#define NB_TC3_BIT8_MASK                256U
#define NB_TC3_BIT9_MASK                512U
#define NB_TC3_BIT10_MASK               1024U
#define NB_TC3_BIT11_MASK               2048U
#define NB_TC3_BIT12_MASK               4096U
#define NB_TC3_BIT13_MASK               8192U
#define NB_TC3_BIT14_MASK               16384U
#define NB_TC3_BIT15_MASK               32768U


/*** NB_LTC_CTL - Life Time Counter control register; 0x00000F38 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LTC_CTLH - Life Time Counter control register high; 0x00000F38 ***/
    union {
      byte Byte;
      struct {
        byte LTCEM       :1;                                       /* Life Time Counter Enable Mask */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte LTCIEM      :1;                                       /* Life Time Counter Interrupt Enable Mask */
      } Bits;
    } NB_LTC_CTLHSTR;
    #define NB_LTC_CTLH                 _NB_LTC_CTL.Overlap_STR.NB_LTC_CTLHSTR.Byte
    #define NB_LTC_CTLH_LTCEM           _NB_LTC_CTL.Overlap_STR.NB_LTC_CTLHSTR.Bits.LTCEM
    #define NB_LTC_CTLH_LTCIEM          _NB_LTC_CTL.Overlap_STR.NB_LTC_CTLHSTR.Bits.LTCIEM
    
    #define NB_LTC_CTLH_LTCEM_MASK      1U
    #define NB_LTC_CTLH_LTCIEM_MASK     128U
    

    /*** NB_LTC_CTLL - Life Time Counter control register low; 0x00000F39 ***/
    union {
      byte Byte;
      struct {
        byte LTCE        :1;                                       /* Life Time Counter Enable */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte LTCIE       :1;                                       /* Life Time Counter Interrupt Enable */
      } Bits;
    } NB_LTC_CTLLSTR;
    #define NB_LTC_CTLL                 _NB_LTC_CTL.Overlap_STR.NB_LTC_CTLLSTR.Byte
    #define NB_LTC_CTLL_LTCE            _NB_LTC_CTL.Overlap_STR.NB_LTC_CTLLSTR.Bits.LTCE
    #define NB_LTC_CTLL_LTCIE           _NB_LTC_CTL.Overlap_STR.NB_LTC_CTLLSTR.Bits.LTCIE
    
    #define NB_LTC_CTLL_LTCE_MASK       1U
    #define NB_LTC_CTLL_LTCIE_MASK      128U
    
  } Overlap_STR;

  struct {
    word LTCE        :1;                                       /* Life Time Counter Enable */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word LTCIE       :1;                                       /* Life Time Counter Interrupt Enable */
    word LTCEM       :1;                                       /* Life Time Counter Enable Mask */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word LTCIEM      :1;                                       /* Life Time Counter Interrupt Enable Mask */
  } Bits;
} NB_LTC_CTLSTR;
extern volatile NB_LTC_CTLSTR _NB_LTC_CTL @0x00000F38;
#define NB_LTC_CTL                      _NB_LTC_CTL.Word
#define NB_LTC_CTL_LTCE                 _NB_LTC_CTL.Bits.LTCE
#define NB_LTC_CTL_LTCIE                _NB_LTC_CTL.Bits.LTCIE
#define NB_LTC_CTL_LTCEM                _NB_LTC_CTL.Bits.LTCEM
#define NB_LTC_CTL_LTCIEM               _NB_LTC_CTL.Bits.LTCIEM

#define NB_LTC_CTL_LTCE_MASK            1U
#define NB_LTC_CTL_LTCIE_MASK           128U
#define NB_LTC_CTL_LTCEM_MASK           256U
#define NB_LTC_CTL_LTCIEM_MASK          32768U


/*** NB_LTC_SR - Life Time Counter status register; 0x00000F3A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LTCOF       :1;                                       /* Life Time Counter Overflow Flag */
  } Bits;
} NB_LTC_SRSTR;
extern volatile NB_LTC_SRSTR _NB_LTC_SR @0x00000F3A;
#define NB_LTC_SR                       _NB_LTC_SR.Byte
#define NB_LTC_SR_LTCOF                 _NB_LTC_SR.Bits.LTCOF

#define NB_LTC_SR_LTCOF_MASK            128U


/*** NB_LTC_CNT1 - Life Time Counter Register 1; 0x00000F3C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LTC_CNT1H - Life Time Counter Register 1 High; 0x00000F3C ***/
    union {
      byte Byte;
    } NB_LTC_CNT1HSTR;
    #define NB_LTC_CNT1H                _NB_LTC_CNT1.Overlap_STR.NB_LTC_CNT1HSTR.Byte
    

    /*** NB_LTC_CNT1L - Life Time Counter Register 1 Low; 0x00000F3D ***/
    union {
      byte Byte;
    } NB_LTC_CNT1LSTR;
    #define NB_LTC_CNT1L                _NB_LTC_CNT1.Overlap_STR.NB_LTC_CNT1LSTR.Byte
    
  } Overlap_STR;

} NB_LTC_CNT1STR;
extern volatile NB_LTC_CNT1STR _NB_LTC_CNT1 @0x00000F3C;
#define NB_LTC_CNT1                     _NB_LTC_CNT1.Word


/*** NB_LTC_CNT0 - Life Time Counter Register 0; 0x00000F3E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LTC_CNT0H - Life Time Counter Register 0 High; 0x00000F3E ***/
    union {
      byte Byte;
    } NB_LTC_CNT0HSTR;
    #define NB_LTC_CNT0H                _NB_LTC_CNT0.Overlap_STR.NB_LTC_CNT0HSTR.Byte
    

    /*** NB_LTC_CNT0L - Life Time Counter Register 0 Low; 0x00000F3F ***/
    union {
      byte Byte;
    } NB_LTC_CNT0LSTR;
    #define NB_LTC_CNT0L                _NB_LTC_CNT0.Overlap_STR.NB_LTC_CNT0LSTR.Byte
    
  } Overlap_STR;

} NB_LTC_CNT0STR;
extern volatile NB_LTC_CNT0STR _NB_LTC_CNT0 @0x00000F3E;
#define NB_LTC_CNT0                     _NB_LTC_CNT0.Word


/*** NB_GPIO_CTL - GPIO control register; 0x00000F40 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_GPIO_CTLH - GPIO control register high; 0x00000F40 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte PE1M        :1;                                       /* Port 1 Enable - Mask */
        byte PE2M        :1;                                       /* Port 2 Enable - Mask */
        byte PE3M        :1;                                       /* Port 3 Enable - Mask */
        byte PE4M        :1;                                       /* Port 4 Enable - Mask */
        byte DIR1M       :1;                                       /* Data Direction PTB1 - Mask */
        byte DIR2M       :1;                                       /* Data Direction PTB2 - Mask */
        byte DIR3M       :1;                                       /* Data Direction PTB3 - Mask */
      } Bits;
    } NB_GPIO_CTLHSTR;
    #define NB_GPIO_CTLH                _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLHSTR.Byte
    #define NB_GPIO_CTLH_PE1M           _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLHSTR.Bits.PE1M
    #define NB_GPIO_CTLH_PE2M           _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLHSTR.Bits.PE2M
    #define NB_GPIO_CTLH_PE3M           _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLHSTR.Bits.PE3M
    #define NB_GPIO_CTLH_PE4M           _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLHSTR.Bits.PE4M
    #define NB_GPIO_CTLH_DIR1M          _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLHSTR.Bits.DIR1M
    #define NB_GPIO_CTLH_DIR2M          _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLHSTR.Bits.DIR2M
    #define NB_GPIO_CTLH_DIR3M          _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLHSTR.Bits.DIR3M
    
    #define NB_GPIO_CTLH_PE1M_MASK      2U
    #define NB_GPIO_CTLH_PE2M_MASK      4U
    #define NB_GPIO_CTLH_PE3M_MASK      8U
    #define NB_GPIO_CTLH_PE4M_MASK      16U
    #define NB_GPIO_CTLH_DIR1M_MASK     32U
    #define NB_GPIO_CTLH_DIR2M_MASK     64U
    #define NB_GPIO_CTLH_DIR3M_MASK     128U
    

    /*** NB_GPIO_CTLL - GPIO control register low; 0x00000F41 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte PE1         :1;                                       /* Port 1 Enable */
        byte PE2         :1;                                       /* Port 2 Enable */
        byte PE3         :1;                                       /* Port 3 Enable */
        byte PE4         :1;                                       /* Port 4 Enable */
        byte DIR1        :1;                                       /* Data Direction PTB1 */
        byte DIR2        :1;                                       /* Data Direction PTB2 */
        byte DIR3        :1;                                       /* Data Direction PTB3 */
      } Bits;
      struct {
        byte     :1;
        byte grpPE_1 :4;
        byte grpDIR_1 :3;
      } MergedBits;
    } NB_GPIO_CTLLSTR;
    #define NB_GPIO_CTLL                _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLLSTR.Byte
    #define NB_GPIO_CTLL_PE1            _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLLSTR.Bits.PE1
    #define NB_GPIO_CTLL_PE2            _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLLSTR.Bits.PE2
    #define NB_GPIO_CTLL_PE3            _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLLSTR.Bits.PE3
    #define NB_GPIO_CTLL_PE4            _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLLSTR.Bits.PE4
    #define NB_GPIO_CTLL_DIR1           _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLLSTR.Bits.DIR1
    #define NB_GPIO_CTLL_DIR2           _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLLSTR.Bits.DIR2
    #define NB_GPIO_CTLL_DIR3           _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLLSTR.Bits.DIR3
    #define NB_GPIO_CTLL_PE_1           _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLLSTR.MergedBits.grpPE_1
    #define NB_GPIO_CTLL_DIR_1          _NB_GPIO_CTL.Overlap_STR.NB_GPIO_CTLLSTR.MergedBits.grpDIR_1
    #define NB_GPIO_CTLL_PE             NB_GPIO_CTLL_PE_1
    #define NB_GPIO_CTLL_DIR            NB_GPIO_CTLL_DIR_1
    
    #define NB_GPIO_CTLL_PE1_MASK       2U
    #define NB_GPIO_CTLL_PE2_MASK       4U
    #define NB_GPIO_CTLL_PE3_MASK       8U
    #define NB_GPIO_CTLL_PE4_MASK       16U
    #define NB_GPIO_CTLL_DIR1_MASK      32U
    #define NB_GPIO_CTLL_DIR2_MASK      64U
    #define NB_GPIO_CTLL_DIR3_MASK      128U
    #define NB_GPIO_CTLL_PE_1_MASK      30U
    #define NB_GPIO_CTLL_PE_1_BITNUM    1U
    #define NB_GPIO_CTLL_DIR_1_MASK     224U
    #define NB_GPIO_CTLL_DIR_1_BITNUM   5U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word PE1         :1;                                       /* Port 1 Enable */
    word PE2         :1;                                       /* Port 2 Enable */
    word PE3         :1;                                       /* Port 3 Enable */
    word PE4         :1;                                       /* Port 4 Enable */
    word DIR1        :1;                                       /* Data Direction PTB1 */
    word DIR2        :1;                                       /* Data Direction PTB2 */
    word DIR3        :1;                                       /* Data Direction PTB3 */
    word             :1; 
    word PE1M        :1;                                       /* Port 1 Enable - Mask */
    word PE2M        :1;                                       /* Port 2 Enable - Mask */
    word PE3M        :1;                                       /* Port 3 Enable - Mask */
    word PE4M        :1;                                       /* Port 4 Enable - Mask */
    word DIR1M       :1;                                       /* Data Direction PTB1 - Mask */
    word DIR2M       :1;                                       /* Data Direction PTB2 - Mask */
    word DIR3M       :1;                                       /* Data Direction PTB3 - Mask */
  } Bits;
  struct {
    word         :1;
    word grpPE_1 :4;
    word grpDIR_1 :3;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} NB_GPIO_CTLSTR;
extern volatile NB_GPIO_CTLSTR _NB_GPIO_CTL @0x00000F40;
#define NB_GPIO_CTL                     _NB_GPIO_CTL.Word
#define NB_GPIO_CTL_PE1                 _NB_GPIO_CTL.Bits.PE1
#define NB_GPIO_CTL_PE2                 _NB_GPIO_CTL.Bits.PE2
#define NB_GPIO_CTL_PE3                 _NB_GPIO_CTL.Bits.PE3
#define NB_GPIO_CTL_PE4                 _NB_GPIO_CTL.Bits.PE4
#define NB_GPIO_CTL_DIR1                _NB_GPIO_CTL.Bits.DIR1
#define NB_GPIO_CTL_DIR2                _NB_GPIO_CTL.Bits.DIR2
#define NB_GPIO_CTL_DIR3                _NB_GPIO_CTL.Bits.DIR3
#define NB_GPIO_CTL_PE1M                _NB_GPIO_CTL.Bits.PE1M
#define NB_GPIO_CTL_PE2M                _NB_GPIO_CTL.Bits.PE2M
#define NB_GPIO_CTL_PE3M                _NB_GPIO_CTL.Bits.PE3M
#define NB_GPIO_CTL_PE4M                _NB_GPIO_CTL.Bits.PE4M
#define NB_GPIO_CTL_DIR1M               _NB_GPIO_CTL.Bits.DIR1M
#define NB_GPIO_CTL_DIR2M               _NB_GPIO_CTL.Bits.DIR2M
#define NB_GPIO_CTL_DIR3M               _NB_GPIO_CTL.Bits.DIR3M
#define NB_GPIO_CTL_PE_1                _NB_GPIO_CTL.MergedBits.grpPE_1
#define NB_GPIO_CTL_DIR_1               _NB_GPIO_CTL.MergedBits.grpDIR_1
#define NB_GPIO_CTL_PE                  NB_GPIO_CTL_PE_1
#define NB_GPIO_CTL_DIR                 NB_GPIO_CTL_DIR_1

#define NB_GPIO_CTL_PE1_MASK            2U
#define NB_GPIO_CTL_PE2_MASK            4U
#define NB_GPIO_CTL_PE3_MASK            8U
#define NB_GPIO_CTL_PE4_MASK            16U
#define NB_GPIO_CTL_DIR1_MASK           32U
#define NB_GPIO_CTL_DIR2_MASK           64U
#define NB_GPIO_CTL_DIR3_MASK           128U
#define NB_GPIO_CTL_PE1M_MASK           512U
#define NB_GPIO_CTL_PE2M_MASK           1024U
#define NB_GPIO_CTL_PE3M_MASK           2048U
#define NB_GPIO_CTL_PE4M_MASK           4096U
#define NB_GPIO_CTL_DIR1M_MASK          8192U
#define NB_GPIO_CTL_DIR2M_MASK          16384U
#define NB_GPIO_CTL_DIR3M_MASK          32768U
#define NB_GPIO_CTL_PE_1_MASK           30U
#define NB_GPIO_CTL_PE_1_BITNUM         1U
#define NB_GPIO_CTL_DIR_1_MASK          224U
#define NB_GPIO_CTL_DIR_1_BITNUM        5U


/*** NB_GPIO_PUC - GPIO pull up configuration; 0x00000F42 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte PUE1        :1;                                       /* PTB1 Pull Up Enable */
    byte PUE2        :1;                                       /* PTB2 Pull Up Enable */
    byte PUE3        :1;                                       /* PTB3 Pull Up Enable */
    byte PDE4        :1;                                       /* PTB4 Pull Down Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte grpPUE_1 :3;
    byte grpPDE_4 :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NB_GPIO_PUCSTR;
extern volatile NB_GPIO_PUCSTR _NB_GPIO_PUC @0x00000F42;
#define NB_GPIO_PUC                     _NB_GPIO_PUC.Byte
#define NB_GPIO_PUC_PUE1                _NB_GPIO_PUC.Bits.PUE1
#define NB_GPIO_PUC_PUE2                _NB_GPIO_PUC.Bits.PUE2
#define NB_GPIO_PUC_PUE3                _NB_GPIO_PUC.Bits.PUE3
#define NB_GPIO_PUC_PDE4                _NB_GPIO_PUC.Bits.PDE4
#define NB_GPIO_PUC_PUE_1               _NB_GPIO_PUC.MergedBits.grpPUE_1
#define NB_GPIO_PUC_PUE                 NB_GPIO_PUC_PUE_1

#define NB_GPIO_PUC_PUE1_MASK           2U
#define NB_GPIO_PUC_PUE2_MASK           4U
#define NB_GPIO_PUC_PUE3_MASK           8U
#define NB_GPIO_PUC_PDE4_MASK           16U
#define NB_GPIO_PUC_PUE_1_MASK          14U
#define NB_GPIO_PUC_PUE_1_BITNUM        1U


/*** NB_GPIO_DATA - GPIO port data register; 0x00000F43 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte PD1         :1;                                       /* PTB1 Data Register */
    byte PD2         :1;                                       /* PTB2 Data Register */
    byte PD3         :1;                                       /* PTB3 Data Register */
    byte PD4         :1;                                       /* PTB4 Data Register */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte grpPD_1 :4;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NB_GPIO_DATASTR;
extern volatile NB_GPIO_DATASTR _NB_GPIO_DATA @0x00000F43;
#define NB_GPIO_DATA                    _NB_GPIO_DATA.Byte
#define NB_GPIO_DATA_PD1                _NB_GPIO_DATA.Bits.PD1
#define NB_GPIO_DATA_PD2                _NB_GPIO_DATA.Bits.PD2
#define NB_GPIO_DATA_PD3                _NB_GPIO_DATA.Bits.PD3
#define NB_GPIO_DATA_PD4                _NB_GPIO_DATA.Bits.PD4
#define NB_GPIO_DATA_PD_1               _NB_GPIO_DATA.MergedBits.grpPD_1
#define NB_GPIO_DATA_PD                 NB_GPIO_DATA_PD_1

#define NB_GPIO_DATA_PD1_MASK           2U
#define NB_GPIO_DATA_PD2_MASK           4U
#define NB_GPIO_DATA_PD3_MASK           8U
#define NB_GPIO_DATA_PD4_MASK           16U
#define NB_GPIO_DATA_PD_1_MASK          30U
#define NB_GPIO_DATA_PD_1_BITNUM        1U


/*** NB_GPIO_IN1 - Port 1 input configuration; 0x00000F44 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LINTX       :1;                                       /* PTB1 - LIN Module Tx Input */
    byte SCIRX       :1;                                       /* PTB1 - SCI Module Rx Input */
    byte TCAP0       :1;                                       /* PTB1 - Timer Input Capture Channel 0 */
    byte TCAP1       :1;                                       /* PTB1 - Timer Input Capture Channel 1 */
    byte TCAP2       :1;                                       /* PTB1 - Timer Input Capture Channel 2 */
    byte TCAP3       :1;                                       /* PTB1 - Timer Input Capture Channel 3 */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTCAP :4;
    byte         :1;
  } MergedBits;
} NB_GPIO_IN1STR;
extern volatile NB_GPIO_IN1STR _NB_GPIO_IN1 @0x00000F44;
#define NB_GPIO_IN1                     _NB_GPIO_IN1.Byte
#define NB_GPIO_IN1_LINTX               _NB_GPIO_IN1.Bits.LINTX
#define NB_GPIO_IN1_SCIRX               _NB_GPIO_IN1.Bits.SCIRX
#define NB_GPIO_IN1_TCAP0               _NB_GPIO_IN1.Bits.TCAP0
#define NB_GPIO_IN1_TCAP1               _NB_GPIO_IN1.Bits.TCAP1
#define NB_GPIO_IN1_TCAP2               _NB_GPIO_IN1.Bits.TCAP2
#define NB_GPIO_IN1_TCAP3               _NB_GPIO_IN1.Bits.TCAP3
#define NB_GPIO_IN1_TCAP                _NB_GPIO_IN1.MergedBits.grpTCAP

#define NB_GPIO_IN1_LINTX_MASK          2U
#define NB_GPIO_IN1_SCIRX_MASK          4U
#define NB_GPIO_IN1_TCAP0_MASK          8U
#define NB_GPIO_IN1_TCAP1_MASK          16U
#define NB_GPIO_IN1_TCAP2_MASK          32U
#define NB_GPIO_IN1_TCAP3_MASK          64U
#define NB_GPIO_IN1_TCAP_MASK           120U
#define NB_GPIO_IN1_TCAP_BITNUM         3U


/*** NB_GPIO_OUT1 - Port 1 output configuration; 0x00000F45 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBX1       :1;                                       /* PTB1 - Output Buffer Control */
    byte LINRX       :1;                                       /* PTB1 - LIN RX Output */
    byte SCITX       :1;                                       /* PTB1 - SCI TX Output */
    byte TCOMP0      :1;                                       /* PTB1 - Timer Channel 0 - Output Compare output */
    byte TCOMP1      :1;                                       /* PTB1 - Timer Channel 1 - Output Compare output */
    byte TCOMP2      :1;                                       /* PTB1 - Timer Channel 2 - Output Compare output */
    byte TCOMP3      :1;                                       /* PTB1 - Timer Channel 3 - Output Compare output */
    byte WKUP        :1;                                       /* PTB1 - Wake Up output */
  } Bits;
  struct {
    byte grpPTBX_1 :1;
    byte         :1;
    byte         :1;
    byte grpTCOMP :4;
    byte         :1;
  } MergedBits;
} NB_GPIO_OUT1STR;
extern volatile NB_GPIO_OUT1STR _NB_GPIO_OUT1 @0x00000F45;
#define NB_GPIO_OUT1                    _NB_GPIO_OUT1.Byte
#define NB_GPIO_OUT1_PTBX1              _NB_GPIO_OUT1.Bits.PTBX1
#define NB_GPIO_OUT1_LINRX              _NB_GPIO_OUT1.Bits.LINRX
#define NB_GPIO_OUT1_SCITX              _NB_GPIO_OUT1.Bits.SCITX
#define NB_GPIO_OUT1_TCOMP0             _NB_GPIO_OUT1.Bits.TCOMP0
#define NB_GPIO_OUT1_TCOMP1             _NB_GPIO_OUT1.Bits.TCOMP1
#define NB_GPIO_OUT1_TCOMP2             _NB_GPIO_OUT1.Bits.TCOMP2
#define NB_GPIO_OUT1_TCOMP3             _NB_GPIO_OUT1.Bits.TCOMP3
#define NB_GPIO_OUT1_WKUP               _NB_GPIO_OUT1.Bits.WKUP
#define NB_GPIO_OUT1_TCOMP              _NB_GPIO_OUT1.MergedBits.grpTCOMP

#define NB_GPIO_OUT1_PTBX1_MASK         1U
#define NB_GPIO_OUT1_LINRX_MASK         2U
#define NB_GPIO_OUT1_SCITX_MASK         4U
#define NB_GPIO_OUT1_TCOMP0_MASK        8U
#define NB_GPIO_OUT1_TCOMP1_MASK        16U
#define NB_GPIO_OUT1_TCOMP2_MASK        32U
#define NB_GPIO_OUT1_TCOMP3_MASK        64U
#define NB_GPIO_OUT1_WKUP_MASK          128U
#define NB_GPIO_OUT1_TCOMP_MASK         120U
#define NB_GPIO_OUT1_TCOMP_BITNUM       3U


/*** NB_GPIO_IN2 - Port 2 input configuration; 0x00000F46 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LINTX       :1;                                       /* PTB2 - LIN Module Tx Input */
    byte SCIRX       :1;                                       /* PTB2 - SCI Module Rx Input */
    byte TCAP0       :1;                                       /* PTB2 - Timer Input Capture Channel 0 */
    byte TCAP1       :1;                                       /* PTB2 - Timer Input Capture Channel 1 */
    byte TCAP2       :1;                                       /* PTB2 - Timer Input Capture Channel 2 */
    byte TCAP3       :1;                                       /* PTB2 - Timer Input Capture Channel 3 */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTCAP :4;
    byte         :1;
  } MergedBits;
} NB_GPIO_IN2STR;
extern volatile NB_GPIO_IN2STR _NB_GPIO_IN2 @0x00000F46;
#define NB_GPIO_IN2                     _NB_GPIO_IN2.Byte
#define NB_GPIO_IN2_LINTX               _NB_GPIO_IN2.Bits.LINTX
#define NB_GPIO_IN2_SCIRX               _NB_GPIO_IN2.Bits.SCIRX
#define NB_GPIO_IN2_TCAP0               _NB_GPIO_IN2.Bits.TCAP0
#define NB_GPIO_IN2_TCAP1               _NB_GPIO_IN2.Bits.TCAP1
#define NB_GPIO_IN2_TCAP2               _NB_GPIO_IN2.Bits.TCAP2
#define NB_GPIO_IN2_TCAP3               _NB_GPIO_IN2.Bits.TCAP3
#define NB_GPIO_IN2_TCAP                _NB_GPIO_IN2.MergedBits.grpTCAP

#define NB_GPIO_IN2_LINTX_MASK          2U
#define NB_GPIO_IN2_SCIRX_MASK          4U
#define NB_GPIO_IN2_TCAP0_MASK          8U
#define NB_GPIO_IN2_TCAP1_MASK          16U
#define NB_GPIO_IN2_TCAP2_MASK          32U
#define NB_GPIO_IN2_TCAP3_MASK          64U
#define NB_GPIO_IN2_TCAP_MASK           120U
#define NB_GPIO_IN2_TCAP_BITNUM         3U


/*** NB_GPIO_OUT2 - Port 2 output configuration; 0x00000F47 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBX2       :1;                                       /* PTB2 - Output Buffer Control */
    byte LINRX       :1;                                       /* PTB2 - LIN RX Output */
    byte SCITX       :1;                                       /* PTB2 - SCI TX Output */
    byte TCOMP0      :1;                                       /* PTB2 - Timer Channel 0 - Output Compare output */
    byte TCOMP1      :1;                                       /* PTB2 - Timer Channel 1 - Output Compare output */
    byte TCOMP2      :1;                                       /* PTB2 - Timer Channel 2 - Output Compare output */
    byte TCOMP3      :1;                                       /* PTB2 - Timer Channel 3 - Output Compare output */
    byte WKUP        :1;                                       /* PTB2 - Wake Up output */
  } Bits;
  struct {
    byte grpPTBX_2 :1;
    byte         :1;
    byte         :1;
    byte grpTCOMP :4;
    byte         :1;
  } MergedBits;
} NB_GPIO_OUT2STR;
extern volatile NB_GPIO_OUT2STR _NB_GPIO_OUT2 @0x00000F47;
#define NB_GPIO_OUT2                    _NB_GPIO_OUT2.Byte
#define NB_GPIO_OUT2_PTBX2              _NB_GPIO_OUT2.Bits.PTBX2
#define NB_GPIO_OUT2_LINRX              _NB_GPIO_OUT2.Bits.LINRX
#define NB_GPIO_OUT2_SCITX              _NB_GPIO_OUT2.Bits.SCITX
#define NB_GPIO_OUT2_TCOMP0             _NB_GPIO_OUT2.Bits.TCOMP0
#define NB_GPIO_OUT2_TCOMP1             _NB_GPIO_OUT2.Bits.TCOMP1
#define NB_GPIO_OUT2_TCOMP2             _NB_GPIO_OUT2.Bits.TCOMP2
#define NB_GPIO_OUT2_TCOMP3             _NB_GPIO_OUT2.Bits.TCOMP3
#define NB_GPIO_OUT2_WKUP               _NB_GPIO_OUT2.Bits.WKUP
#define NB_GPIO_OUT2_TCOMP              _NB_GPIO_OUT2.MergedBits.grpTCOMP

#define NB_GPIO_OUT2_PTBX2_MASK         1U
#define NB_GPIO_OUT2_LINRX_MASK         2U
#define NB_GPIO_OUT2_SCITX_MASK         4U
#define NB_GPIO_OUT2_TCOMP0_MASK        8U
#define NB_GPIO_OUT2_TCOMP1_MASK        16U
#define NB_GPIO_OUT2_TCOMP2_MASK        32U
#define NB_GPIO_OUT2_TCOMP3_MASK        64U
#define NB_GPIO_OUT2_WKUP_MASK          128U
#define NB_GPIO_OUT2_TCOMP_MASK         120U
#define NB_GPIO_OUT2_TCOMP_BITNUM       3U


/*** NB_GPIO_IN3 - Port 3 input configuration; 0x00000F48 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LINTX       :1;                                       /* PTB3 - LIN Module Tx Input */
    byte SCIRX       :1;                                       /* PTB3 - SCI Module Rx Input */
    byte TCAP0       :1;                                       /* PTB3 - Timer Input Capture Channel 0 */
    byte TCAP1       :1;                                       /* PTB3 - Timer Input Capture Channel 1 */
    byte TCAP2       :1;                                       /* PTB3 - Timer Input Capture Channel 2 */
    byte TCAP3       :1;                                       /* PTB3 - Timer Input Capture Channel 3 */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTCAP :4;
    byte         :1;
  } MergedBits;
} NB_GPIO_IN3STR;
extern volatile NB_GPIO_IN3STR _NB_GPIO_IN3 @0x00000F48;
#define NB_GPIO_IN3                     _NB_GPIO_IN3.Byte
#define NB_GPIO_IN3_LINTX               _NB_GPIO_IN3.Bits.LINTX
#define NB_GPIO_IN3_SCIRX               _NB_GPIO_IN3.Bits.SCIRX
#define NB_GPIO_IN3_TCAP0               _NB_GPIO_IN3.Bits.TCAP0
#define NB_GPIO_IN3_TCAP1               _NB_GPIO_IN3.Bits.TCAP1
#define NB_GPIO_IN3_TCAP2               _NB_GPIO_IN3.Bits.TCAP2
#define NB_GPIO_IN3_TCAP3               _NB_GPIO_IN3.Bits.TCAP3
#define NB_GPIO_IN3_TCAP                _NB_GPIO_IN3.MergedBits.grpTCAP

#define NB_GPIO_IN3_LINTX_MASK          2U
#define NB_GPIO_IN3_SCIRX_MASK          4U
#define NB_GPIO_IN3_TCAP0_MASK          8U
#define NB_GPIO_IN3_TCAP1_MASK          16U
#define NB_GPIO_IN3_TCAP2_MASK          32U
#define NB_GPIO_IN3_TCAP3_MASK          64U
#define NB_GPIO_IN3_TCAP_MASK           120U
#define NB_GPIO_IN3_TCAP_BITNUM         3U


/*** NB_GPIO_OUT3 - Port 3 output configuration; 0x00000F49 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBX3       :1;                                       /* PTB3 - Output Buffer Control */
    byte LINRX       :1;                                       /* PTB3 - LIN RX Output */
    byte SCITX       :1;                                       /* PTB3 - SCI TX Output */
    byte TCOMP0      :1;                                       /* PTB3 - Timer Channel 0 - Output Compare output */
    byte TCOMP1      :1;                                       /* PTB3 - Timer Channel 1 - Output Compare output */
    byte TCOMP2      :1;                                       /* PTB3 - Timer Channel 2 - Output Compare output */
    byte TCOMP3      :1;                                       /* PTB3 - Timer Channel 3 - Output Compare output */
    byte WKUP        :1;                                       /* PTB3 - Wake Up output */
  } Bits;
  struct {
    byte grpPTBX_3 :1;
    byte         :1;
    byte         :1;
    byte grpTCOMP :4;
    byte         :1;
  } MergedBits;
} NB_GPIO_OUT3STR;
extern volatile NB_GPIO_OUT3STR _NB_GPIO_OUT3 @0x00000F49;
#define NB_GPIO_OUT3                    _NB_GPIO_OUT3.Byte
#define NB_GPIO_OUT3_PTBX3              _NB_GPIO_OUT3.Bits.PTBX3
#define NB_GPIO_OUT3_LINRX              _NB_GPIO_OUT3.Bits.LINRX
#define NB_GPIO_OUT3_SCITX              _NB_GPIO_OUT3.Bits.SCITX
#define NB_GPIO_OUT3_TCOMP0             _NB_GPIO_OUT3.Bits.TCOMP0
#define NB_GPIO_OUT3_TCOMP1             _NB_GPIO_OUT3.Bits.TCOMP1
#define NB_GPIO_OUT3_TCOMP2             _NB_GPIO_OUT3.Bits.TCOMP2
#define NB_GPIO_OUT3_TCOMP3             _NB_GPIO_OUT3.Bits.TCOMP3
#define NB_GPIO_OUT3_WKUP               _NB_GPIO_OUT3.Bits.WKUP
#define NB_GPIO_OUT3_TCOMP              _NB_GPIO_OUT3.MergedBits.grpTCOMP

#define NB_GPIO_OUT3_PTBX3_MASK         1U
#define NB_GPIO_OUT3_LINRX_MASK         2U
#define NB_GPIO_OUT3_SCITX_MASK         4U
#define NB_GPIO_OUT3_TCOMP0_MASK        8U
#define NB_GPIO_OUT3_TCOMP1_MASK        16U
#define NB_GPIO_OUT3_TCOMP2_MASK        32U
#define NB_GPIO_OUT3_TCOMP3_MASK        64U
#define NB_GPIO_OUT3_WKUP_MASK          128U
#define NB_GPIO_OUT3_TCOMP_MASK         120U
#define NB_GPIO_OUT3_TCOMP_BITNUM       3U


/*** NB_GPIO_IN4 - Port 4 input configuration; 0x00000F4A ***/
typedef union {
  byte Byte;
  struct {
    byte NWUE        :1; 
    byte NWUS        :1; 
    byte             :1; 
    byte TCAP0       :1;                                       /* PTB3 - Timer Input Capture Channel 0 */
    byte TCAP1       :1;                                       /* PTB3 - Timer Input Capture Channel 1 */
    byte TCAP2       :1;                                       /* PTB3 - Timer Input Capture Channel 2 */
    byte TCAP3       :1;                                       /* PTB3 - Timer Input Capture Channel 3 */
    byte PTWU        :1;                                       /* PTB3 Wake Up */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTCAP :4;
    byte         :1;
  } MergedBits;
} NB_GPIO_IN4STR;
extern volatile NB_GPIO_IN4STR _NB_GPIO_IN4 @0x00000F4A;
#define NB_GPIO_IN4                     _NB_GPIO_IN4.Byte
#define NB_GPIO_IN4_NWUE                _NB_GPIO_IN4.Bits.NWUE
#define NB_GPIO_IN4_NWUS                _NB_GPIO_IN4.Bits.NWUS
#define NB_GPIO_IN4_TCAP0               _NB_GPIO_IN4.Bits.TCAP0
#define NB_GPIO_IN4_TCAP1               _NB_GPIO_IN4.Bits.TCAP1
#define NB_GPIO_IN4_TCAP2               _NB_GPIO_IN4.Bits.TCAP2
#define NB_GPIO_IN4_TCAP3               _NB_GPIO_IN4.Bits.TCAP3
#define NB_GPIO_IN4_PTWU                _NB_GPIO_IN4.Bits.PTWU
#define NB_GPIO_IN4_TCAP                _NB_GPIO_IN4.MergedBits.grpTCAP

#define NB_GPIO_IN4_NWUE_MASK           1U
#define NB_GPIO_IN4_NWUS_MASK           2U
#define NB_GPIO_IN4_TCAP0_MASK          8U
#define NB_GPIO_IN4_TCAP1_MASK          16U
#define NB_GPIO_IN4_TCAP2_MASK          32U
#define NB_GPIO_IN4_TCAP3_MASK          64U
#define NB_GPIO_IN4_PTWU_MASK           128U
#define NB_GPIO_IN4_TCAP_MASK           120U
#define NB_GPIO_IN4_TCAP_BITNUM         3U


/*** NB_GPIO_VSENSE - GPIO Vsense Configuration; 0x00000F4B ***/
typedef union {
  byte Byte;
  struct {
    byte VSE0        :1; 
    byte VSE1        :1; 
    byte VSE2        :1; 
    byte VSE3        :1; 
    byte VSE4        :1; 
    byte             :1; 
    byte VSSEL       :2; 
  } Bits;
  struct {
    byte grpVSE  :5;
    byte         :1;
    byte         :2;
  } MergedBits;
} NB_GPIO_VSENSESTR;
extern volatile NB_GPIO_VSENSESTR _NB_GPIO_VSENSE @0x00000F4B;
#define NB_GPIO_VSENSE                  _NB_GPIO_VSENSE.Byte
#define NB_GPIO_VSENSE_VSE0             _NB_GPIO_VSENSE.Bits.VSE0
#define NB_GPIO_VSENSE_VSE1             _NB_GPIO_VSENSE.Bits.VSE1
#define NB_GPIO_VSENSE_VSE2             _NB_GPIO_VSENSE.Bits.VSE2
#define NB_GPIO_VSENSE_VSE3             _NB_GPIO_VSENSE.Bits.VSE3
#define NB_GPIO_VSENSE_VSE4             _NB_GPIO_VSENSE.Bits.VSE4
#define NB_GPIO_VSENSE_VSSEL            _NB_GPIO_VSENSE.Bits.VSSEL
#define NB_GPIO_VSENSE_VSE              _NB_GPIO_VSENSE.MergedBits.grpVSE

#define NB_GPIO_VSENSE_VSE0_MASK        1U
#define NB_GPIO_VSENSE_VSE1_MASK        2U
#define NB_GPIO_VSENSE_VSE2_MASK        4U
#define NB_GPIO_VSENSE_VSE3_MASK        8U
#define NB_GPIO_VSENSE_VSE4_MASK        16U
#define NB_GPIO_VSENSE_VSSEL_MASK       192U
#define NB_GPIO_VSENSE_VSSEL_BITNUM     6U
#define NB_GPIO_VSENSE_VSE_MASK         31U
#define NB_GPIO_VSENSE_VSE_BITNUM       0U


/*** NB_GPIO_TSENSE - GPIO Tsense Configuration; 0x00000F4C ***/
typedef union {
  byte Byte;
  struct {
    byte TSE0        :1; 
    byte TSE1        :1; 
    byte TSE2        :1; 
    byte TSE3        :1; 
    byte TSE4        :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTSE  :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NB_GPIO_TSENSESTR;
extern volatile NB_GPIO_TSENSESTR _NB_GPIO_TSENSE @0x00000F4C;
#define NB_GPIO_TSENSE                  _NB_GPIO_TSENSE.Byte
#define NB_GPIO_TSENSE_TSE0             _NB_GPIO_TSENSE.Bits.TSE0
#define NB_GPIO_TSENSE_TSE1             _NB_GPIO_TSENSE.Bits.TSE1
#define NB_GPIO_TSENSE_TSE2             _NB_GPIO_TSENSE.Bits.TSE2
#define NB_GPIO_TSENSE_TSE3             _NB_GPIO_TSENSE.Bits.TSE3
#define NB_GPIO_TSENSE_TSE4             _NB_GPIO_TSENSE.Bits.TSE4
#define NB_GPIO_TSENSE_TSE              _NB_GPIO_TSENSE.MergedBits.grpTSE

#define NB_GPIO_TSENSE_TSE0_MASK        1U
#define NB_GPIO_TSENSE_TSE1_MASK        2U
#define NB_GPIO_TSENSE_TSE2_MASK        4U
#define NB_GPIO_TSENSE_TSE3_MASK        8U
#define NB_GPIO_TSENSE_TSE4_MASK        16U
#define NB_GPIO_TSENSE_TSE_MASK         31U
#define NB_GPIO_TSENSE_TSE_BITNUM       0U


/*** NB_LIN_CTL - LIN control register; 0x00000F50 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LIN_CTLH - LIN control register high; 0x00000F50 ***/
    union {
      byte Byte;
      struct {
        byte SRSM        :2;                                       /* Slew Rate Select - Mask */
        byte ENM         :1;                                       /* Module Enable - Mask */
        byte LVSDM       :1;                                       /* Low Voltage Shutdown Disable (J2602 Compliance Control) - Mask */
        byte             :1; 
        byte             :1; 
        byte TXDOMIEM    :1; 
        byte OTIEM       :1;                                       /* Overtemperature Interrupt Enable - Mask */
      } Bits;
    } NB_LIN_CTLHSTR;
    #define NB_LIN_CTLH                 _NB_LIN_CTL.Overlap_STR.NB_LIN_CTLHSTR.Byte
    #define NB_LIN_CTLH_SRSM            _NB_LIN_CTL.Overlap_STR.NB_LIN_CTLHSTR.Bits.SRSM
    #define NB_LIN_CTLH_ENM             _NB_LIN_CTL.Overlap_STR.NB_LIN_CTLHSTR.Bits.ENM
    #define NB_LIN_CTLH_LVSDM           _NB_LIN_CTL.Overlap_STR.NB_LIN_CTLHSTR.Bits.LVSDM
    #define NB_LIN_CTLH_TXDOMIEM        _NB_LIN_CTL.Overlap_STR.NB_LIN_CTLHSTR.Bits.TXDOMIEM
    #define NB_LIN_CTLH_OTIEM           _NB_LIN_CTL.Overlap_STR.NB_LIN_CTLHSTR.Bits.OTIEM
    
    #define NB_LIN_CTLH_SRSM_MASK       3U
    #define NB_LIN_CTLH_SRSM_BITNUM     0U
    #define NB_LIN_CTLH_ENM_MASK        4U
    #define NB_LIN_CTLH_LVSDM_MASK      8U
    #define NB_LIN_CTLH_TXDOMIEM_MASK   64U
    #define NB_LIN_CTLH_OTIEM_MASK      128U
    

    /*** NB_LIN_CTLL - LIN control register low; 0x00000F51 ***/
    union {
      byte Byte;
      struct {
        byte SRS         :2;                                       /* Slew Rate Select */
        byte EN          :1;                                       /* Module Enable */
        byte LVSD        :1;                                       /* Low Voltage Shutdown Disable (J2602 Compliance Control) */
        byte             :1; 
        byte             :1; 
        byte TXDOMIE     :1; 
        byte OTIE        :1;                                       /* Overtemperature Interrupt Enable */
      } Bits;
    } NB_LIN_CTLLSTR;
    #define NB_LIN_CTLL                 _NB_LIN_CTL.Overlap_STR.NB_LIN_CTLLSTR.Byte
    #define NB_LIN_CTLL_SRS             _NB_LIN_CTL.Overlap_STR.NB_LIN_CTLLSTR.Bits.SRS
    #define NB_LIN_CTLL_EN              _NB_LIN_CTL.Overlap_STR.NB_LIN_CTLLSTR.Bits.EN
    #define NB_LIN_CTLL_LVSD            _NB_LIN_CTL.Overlap_STR.NB_LIN_CTLLSTR.Bits.LVSD
    #define NB_LIN_CTLL_TXDOMIE         _NB_LIN_CTL.Overlap_STR.NB_LIN_CTLLSTR.Bits.TXDOMIE
    #define NB_LIN_CTLL_OTIE            _NB_LIN_CTL.Overlap_STR.NB_LIN_CTLLSTR.Bits.OTIE
    
    #define NB_LIN_CTLL_SRS_MASK        3U
    #define NB_LIN_CTLL_SRS_BITNUM      0U
    #define NB_LIN_CTLL_EN_MASK         4U
    #define NB_LIN_CTLL_LVSD_MASK       8U
    #define NB_LIN_CTLL_TXDOMIE_MASK    64U
    #define NB_LIN_CTLL_OTIE_MASK       128U
    
  } Overlap_STR;

  struct {
    word SRS         :2;                                       /* Slew Rate Select */
    word EN          :1;                                       /* Module Enable */
    word LVSD        :1;                                       /* Low Voltage Shutdown Disable (J2602 Compliance Control) */
    word             :1; 
    word             :1; 
    word TXDOMIE     :1; 
    word OTIE        :1;                                       /* Overtemperature Interrupt Enable */
    word SRSM        :2;                                       /* Slew Rate Select - Mask */
    word ENM         :1;                                       /* Module Enable - Mask */
    word LVSDM       :1;                                       /* Low Voltage Shutdown Disable (J2602 Compliance Control) - Mask */
    word             :1; 
    word             :1; 
    word TXDOMIEM    :1; 
    word OTIEM       :1;                                       /* Overtemperature Interrupt Enable - Mask */
  } Bits;
} NB_LIN_CTLSTR;
extern volatile NB_LIN_CTLSTR _NB_LIN_CTL @0x00000F50;
#define NB_LIN_CTL                      _NB_LIN_CTL.Word
#define NB_LIN_CTL_SRS                  _NB_LIN_CTL.Bits.SRS
#define NB_LIN_CTL_EN                   _NB_LIN_CTL.Bits.EN
#define NB_LIN_CTL_LVSD                 _NB_LIN_CTL.Bits.LVSD
#define NB_LIN_CTL_TXDOMIE              _NB_LIN_CTL.Bits.TXDOMIE
#define NB_LIN_CTL_OTIE                 _NB_LIN_CTL.Bits.OTIE
#define NB_LIN_CTL_SRSM                 _NB_LIN_CTL.Bits.SRSM
#define NB_LIN_CTL_ENM                  _NB_LIN_CTL.Bits.ENM
#define NB_LIN_CTL_LVSDM                _NB_LIN_CTL.Bits.LVSDM
#define NB_LIN_CTL_TXDOMIEM             _NB_LIN_CTL.Bits.TXDOMIEM
#define NB_LIN_CTL_OTIEM                _NB_LIN_CTL.Bits.OTIEM

#define NB_LIN_CTL_SRS_MASK             3U
#define NB_LIN_CTL_SRS_BITNUM           0U
#define NB_LIN_CTL_EN_MASK              4U
#define NB_LIN_CTL_LVSD_MASK            8U
#define NB_LIN_CTL_TXDOMIE_MASK         64U
#define NB_LIN_CTL_OTIE_MASK            128U
#define NB_LIN_CTL_SRSM_MASK            768U
#define NB_LIN_CTL_SRSM_BITNUM          8U
#define NB_LIN_CTL_ENM_MASK             1024U
#define NB_LIN_CTL_LVSDM_MASK           2048U
#define NB_LIN_CTL_TXDOMIEM_MASK        16384U
#define NB_LIN_CTL_OTIEM_MASK           32768U


/*** NB_LIN_SR - LIN status register; 0x00000F52 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LIN_SRH - LIN status register high; 0x00000F52 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte UV          :1;                                       /* Undervoltage Status */
        byte             :1; 
        byte HF          :1;                                       /* HF (High Frequency) Condition Status indicating HF disturbance in the LIN module */
        byte TXDOM       :1; 
        byte OT          :1;                                       /* Overtemperature Status */
      } Bits;
    } NB_LIN_SRHSTR;
    #define NB_LIN_SRH                  _NB_LIN_SR.Overlap_STR.NB_LIN_SRHSTR.Byte
    #define NB_LIN_SRH_UV               _NB_LIN_SR.Overlap_STR.NB_LIN_SRHSTR.Bits.UV
    #define NB_LIN_SRH_HF               _NB_LIN_SR.Overlap_STR.NB_LIN_SRHSTR.Bits.HF
    #define NB_LIN_SRH_TXDOM            _NB_LIN_SR.Overlap_STR.NB_LIN_SRHSTR.Bits.TXDOM
    #define NB_LIN_SRH_OT               _NB_LIN_SR.Overlap_STR.NB_LIN_SRHSTR.Bits.OT
    
    #define NB_LIN_SRH_UV_MASK          8U
    #define NB_LIN_SRH_HF_MASK          32U
    #define NB_LIN_SRH_TXDOM_MASK       64U
    #define NB_LIN_SRH_OT_MASK          128U
    

    /*** NB_LIN_SRL - LIN status register low; 0x00000F53 ***/
    union {
      byte Byte;
      struct {
        byte TX          :1;                                       /* Current TX status */
        byte RX          :1;                                       /* Current RX status */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte RDY         :1;                                       /* Transmitter Ready Status */
      } Bits;
    } NB_LIN_SRLSTR;
    #define NB_LIN_SRL                  _NB_LIN_SR.Overlap_STR.NB_LIN_SRLSTR.Byte
    #define NB_LIN_SRL_TX               _NB_LIN_SR.Overlap_STR.NB_LIN_SRLSTR.Bits.TX
    #define NB_LIN_SRL_RX               _NB_LIN_SR.Overlap_STR.NB_LIN_SRLSTR.Bits.RX
    #define NB_LIN_SRL_RDY              _NB_LIN_SR.Overlap_STR.NB_LIN_SRLSTR.Bits.RDY
    
    #define NB_LIN_SRL_TX_MASK          1U
    #define NB_LIN_SRL_RX_MASK          2U
    #define NB_LIN_SRL_RDY_MASK         128U
    
  } Overlap_STR;

  struct {
    word TX          :1;                                       /* Current TX status */
    word RX          :1;                                       /* Current RX status */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word RDY         :1;                                       /* Transmitter Ready Status */
    word             :1; 
    word             :1; 
    word             :1; 
    word UV          :1;                                       /* Undervoltage Status */
    word             :1; 
    word HF          :1;                                       /* HF (High Frequency) Condition Status indicating HF disturbance in the LIN module */
    word TXDOM       :1; 
    word OT          :1;                                       /* Overtemperature Status */
  } Bits;
} NB_LIN_SRSTR;
extern volatile NB_LIN_SRSTR _NB_LIN_SR @0x00000F52;
#define NB_LIN_SR                       _NB_LIN_SR.Word
#define NB_LIN_SR_TX                    _NB_LIN_SR.Bits.TX
#define NB_LIN_SR_RX                    _NB_LIN_SR.Bits.RX
#define NB_LIN_SR_RDY                   _NB_LIN_SR.Bits.RDY
#define NB_LIN_SR_UV                    _NB_LIN_SR.Bits.UV
#define NB_LIN_SR_HF                    _NB_LIN_SR.Bits.HF
#define NB_LIN_SR_TXDOM                 _NB_LIN_SR.Bits.TXDOM
#define NB_LIN_SR_OT                    _NB_LIN_SR.Bits.OT

#define NB_LIN_SR_TX_MASK               1U
#define NB_LIN_SR_RX_MASK               2U
#define NB_LIN_SR_RDY_MASK              128U
#define NB_LIN_SR_UV_MASK               2048U
#define NB_LIN_SR_HF_MASK               8192U
#define NB_LIN_SR_TXDOM_MASK            16384U
#define NB_LIN_SR_OT_MASK               32768U


/*** NB_LIN_TX - LIN transmit line definition; 0x00000F54 ***/
typedef union {
  byte Byte;
  struct {
    byte FROMSCI     :1;                                       /* LIN_TX internally routed from SCI */
    byte FROMPTB     :1;                                       /* LIN_TX internally routed from PTB */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NB_LIN_TXSTR;
extern volatile NB_LIN_TXSTR _NB_LIN_TX @0x00000F54;
#define NB_LIN_TX                       _NB_LIN_TX.Byte
#define NB_LIN_TX_FROMSCI               _NB_LIN_TX.Bits.FROMSCI
#define NB_LIN_TX_FROMPTB               _NB_LIN_TX.Bits.FROMPTB

#define NB_LIN_TX_FROMSCI_MASK          1U
#define NB_LIN_TX_FROMPTB_MASK          2U


/*** NB_LIN_RX - LIN receive line definition; 0x00000F55 ***/
typedef union {
  byte Byte;
  struct {
    byte TOSCI       :1;                                       /* LIN_RX internally routed to SCI */
    byte TOPTB       :1;                                       /* LIN_RX internally routed to PTB */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NB_LIN_RXSTR;
extern volatile NB_LIN_RXSTR _NB_LIN_RX @0x00000F55;
#define NB_LIN_RX                       _NB_LIN_RX.Byte
#define NB_LIN_RX_TOSCI                 _NB_LIN_RX.Bits.TOSCI
#define NB_LIN_RX_TOPTB                 _NB_LIN_RX.Bits.TOPTB

#define NB_LIN_RX_TOSCI_MASK            1U
#define NB_LIN_RX_TOPTB_MASK            2U


/*** NB_ACQ_CTL - Acquisition control register; 0x00000F58 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_ACQ_CTLH - Acquisition control register high; 0x00000F58 ***/
    union {
      byte Byte;
      struct {
        byte CMENM       :1;                                       /* Current Measurement Enable - Mask */
        byte VMENM       :1;                                       /* Voltage Measurement Enable - Mask */
        byte ITMENM      :1;                                       /* Internal Temperature Measurement Enable - Mask */
        byte ETMENM      :1;                                       /* External Temperature Measurement Enable - Mask */
        byte CVMIEM      :1;                                       /* Current / Voltage Measurement Interrupt Enable - Mask */
        byte NVSEM       :1; 
        byte             :1; 
        byte AHCRM       :1;                                       /* Ampere Hour Counter Reset - Mask */
      } Bits;
    } NB_ACQ_CTLHSTR;
    #define NB_ACQ_CTLH                 _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLHSTR.Byte
    #define NB_ACQ_CTLH_CMENM           _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLHSTR.Bits.CMENM
    #define NB_ACQ_CTLH_VMENM           _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLHSTR.Bits.VMENM
    #define NB_ACQ_CTLH_ITMENM          _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLHSTR.Bits.ITMENM
    #define NB_ACQ_CTLH_ETMENM          _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLHSTR.Bits.ETMENM
    #define NB_ACQ_CTLH_CVMIEM          _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLHSTR.Bits.CVMIEM
    #define NB_ACQ_CTLH_NVSEM           _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLHSTR.Bits.NVSEM
    #define NB_ACQ_CTLH_AHCRM           _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLHSTR.Bits.AHCRM
    
    #define NB_ACQ_CTLH_CMENM_MASK      1U
    #define NB_ACQ_CTLH_VMENM_MASK      2U
    #define NB_ACQ_CTLH_ITMENM_MASK     4U
    #define NB_ACQ_CTLH_ETMENM_MASK     8U
    #define NB_ACQ_CTLH_CVMIEM_MASK     16U
    #define NB_ACQ_CTLH_NVSEM_MASK      32U
    #define NB_ACQ_CTLH_AHCRM_MASK      128U
    

    /*** NB_ACQ_CTLL - Acquisition control register low; 0x00000F59 ***/
    union {
      byte Byte;
      struct {
        byte CMEN        :1;                                       /* Current Measurement Enable */
        byte VMEN        :1;                                       /* Voltage Measurement Enable */
        byte ITMEN       :1;                                       /* Internal Temperature Measurement Enable */
        byte ETMEN       :1;                                       /* External Temperature Measurement Enable */
        byte CVMIE       :1;                                       /* Current / Voltage Measurement Interrupt Enable */
        byte NVSE        :1; 
        byte             :1; 
        byte AHCR        :1;                                       /* Ampere Hour Counter Reset, this write only bit will reset the ACQ_AHC register */
      } Bits;
    } NB_ACQ_CTLLSTR;
    #define NB_ACQ_CTLL                 _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLLSTR.Byte
    #define NB_ACQ_CTLL_CMEN            _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLLSTR.Bits.CMEN
    #define NB_ACQ_CTLL_VMEN            _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLLSTR.Bits.VMEN
    #define NB_ACQ_CTLL_ITMEN           _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLLSTR.Bits.ITMEN
    #define NB_ACQ_CTLL_ETMEN           _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLLSTR.Bits.ETMEN
    #define NB_ACQ_CTLL_CVMIE           _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLLSTR.Bits.CVMIE
    #define NB_ACQ_CTLL_NVSE            _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLLSTR.Bits.NVSE
    #define NB_ACQ_CTLL_AHCR            _NB_ACQ_CTL.Overlap_STR.NB_ACQ_CTLLSTR.Bits.AHCR
    
    #define NB_ACQ_CTLL_CMEN_MASK       1U
    #define NB_ACQ_CTLL_VMEN_MASK       2U
    #define NB_ACQ_CTLL_ITMEN_MASK      4U
    #define NB_ACQ_CTLL_ETMEN_MASK      8U
    #define NB_ACQ_CTLL_CVMIE_MASK      16U
    #define NB_ACQ_CTLL_NVSE_MASK       32U
    #define NB_ACQ_CTLL_AHCR_MASK       128U
    
  } Overlap_STR;

  struct {
    word CMEN        :1;                                       /* Current Measurement Enable */
    word VMEN        :1;                                       /* Voltage Measurement Enable */
    word ITMEN       :1;                                       /* Internal Temperature Measurement Enable */
    word ETMEN       :1;                                       /* External Temperature Measurement Enable */
    word CVMIE       :1;                                       /* Current / Voltage Measurement Interrupt Enable */
    word NVSE        :1; 
    word             :1; 
    word AHCR        :1;                                       /* Ampere Hour Counter Reset, this write only bit will reset the ACQ_AHC register */
    word CMENM       :1;                                       /* Current Measurement Enable - Mask */
    word VMENM       :1;                                       /* Voltage Measurement Enable - Mask */
    word ITMENM      :1;                                       /* Internal Temperature Measurement Enable - Mask */
    word ETMENM      :1;                                       /* External Temperature Measurement Enable - Mask */
    word CVMIEM      :1;                                       /* Current / Voltage Measurement Interrupt Enable - Mask */
    word NVSEM       :1; 
    word             :1; 
    word AHCRM       :1;                                       /* Ampere Hour Counter Reset - Mask */
  } Bits;
} NB_ACQ_CTLSTR;
extern volatile NB_ACQ_CTLSTR _NB_ACQ_CTL @0x00000F58;
#define NB_ACQ_CTL                      _NB_ACQ_CTL.Word
#define NB_ACQ_CTL_CMEN                 _NB_ACQ_CTL.Bits.CMEN
#define NB_ACQ_CTL_VMEN                 _NB_ACQ_CTL.Bits.VMEN
#define NB_ACQ_CTL_ITMEN                _NB_ACQ_CTL.Bits.ITMEN
#define NB_ACQ_CTL_ETMEN                _NB_ACQ_CTL.Bits.ETMEN
#define NB_ACQ_CTL_CVMIE                _NB_ACQ_CTL.Bits.CVMIE
#define NB_ACQ_CTL_NVSE                 _NB_ACQ_CTL.Bits.NVSE
#define NB_ACQ_CTL_AHCR                 _NB_ACQ_CTL.Bits.AHCR
#define NB_ACQ_CTL_CMENM                _NB_ACQ_CTL.Bits.CMENM
#define NB_ACQ_CTL_VMENM                _NB_ACQ_CTL.Bits.VMENM
#define NB_ACQ_CTL_ITMENM               _NB_ACQ_CTL.Bits.ITMENM
#define NB_ACQ_CTL_ETMENM               _NB_ACQ_CTL.Bits.ETMENM
#define NB_ACQ_CTL_CVMIEM               _NB_ACQ_CTL.Bits.CVMIEM
#define NB_ACQ_CTL_NVSEM                _NB_ACQ_CTL.Bits.NVSEM
#define NB_ACQ_CTL_AHCRM                _NB_ACQ_CTL.Bits.AHCRM

#define NB_ACQ_CTL_CMEN_MASK            1U
#define NB_ACQ_CTL_VMEN_MASK            2U
#define NB_ACQ_CTL_ITMEN_MASK           4U
#define NB_ACQ_CTL_ETMEN_MASK           8U
#define NB_ACQ_CTL_CVMIE_MASK           16U
#define NB_ACQ_CTL_NVSE_MASK            32U
#define NB_ACQ_CTL_AHCR_MASK            128U
#define NB_ACQ_CTL_CMENM_MASK           256U
#define NB_ACQ_CTL_VMENM_MASK           512U
#define NB_ACQ_CTL_ITMENM_MASK          1024U
#define NB_ACQ_CTL_ETMENM_MASK          2048U
#define NB_ACQ_CTL_CVMIEM_MASK          4096U
#define NB_ACQ_CTL_NVSEM_MASK           8192U
#define NB_ACQ_CTL_AHCRM_MASK           32768U


/*** NB_ACQ_SR - Acquisition status register; 0x00000F5A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_ACQ_SRH - Acquisition status register high; 0x00000F5A ***/
    union {
      byte Byte;
      struct {
        byte CM          :1;                                       /* End of Measurement - Current */
        byte VM          :1;                                       /* End of Measurement - Voltage */
        byte ITM         :1;                                       /* End of Measurement - Internal Temperature */
        byte ETM         :1;                                       /* End of Measurement - External Temperature */
        byte CMOW        :1;                                       /* Current Measurement Result Overwritten */
        byte VMOW        :1;                                       /* Voltage Measurement Result Overwritten */
        byte PGAG        :1;                                       /* PGA Gain Change Flag */
        byte AVRF        :1;                                       /* VDDA Low Voltage Reset Flag */
      } Bits;
    } NB_ACQ_SRHSTR;
    #define NB_ACQ_SRH                  _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRHSTR.Byte
    #define NB_ACQ_SRH_CM               _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRHSTR.Bits.CM
    #define NB_ACQ_SRH_VM               _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRHSTR.Bits.VM
    #define NB_ACQ_SRH_ITM              _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRHSTR.Bits.ITM
    #define NB_ACQ_SRH_ETM              _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRHSTR.Bits.ETM
    #define NB_ACQ_SRH_CMOW             _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRHSTR.Bits.CMOW
    #define NB_ACQ_SRH_VMOW             _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRHSTR.Bits.VMOW
    #define NB_ACQ_SRH_PGAG             _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRHSTR.Bits.PGAG
    #define NB_ACQ_SRH_AVRF             _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRHSTR.Bits.AVRF
    
    #define NB_ACQ_SRH_CM_MASK          1U
    #define NB_ACQ_SRH_VM_MASK          2U
    #define NB_ACQ_SRH_ITM_MASK         4U
    #define NB_ACQ_SRH_ETM_MASK         8U
    #define NB_ACQ_SRH_CMOW_MASK        16U
    #define NB_ACQ_SRH_VMOW_MASK        32U
    #define NB_ACQ_SRH_PGAG_MASK        64U
    #define NB_ACQ_SRH_AVRF_MASK        128U
    

    /*** NB_ACQ_SRL - Acquisition status register low; 0x00000F5B ***/
    union {
      byte Byte;
      struct {
        byte CCHOP       :1;                                       /* Chopping Active Status - Current */
        byte VCHOP       :1;                                       /* Chopping Active Status - Voltage */
        byte ITCHOP      :1;                                       /* Chopping Active Status - Internal Temperature */
        byte ETCHOP      :1;                                       /* Chopping Active Status - External Temperature */
        byte VTH         :1;                                       /* Digital Voltage High Threshold Reached */
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_ACQ_SRLSTR;
    #define NB_ACQ_SRL                  _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRLSTR.Byte
    #define NB_ACQ_SRL_CCHOP            _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRLSTR.Bits.CCHOP
    #define NB_ACQ_SRL_VCHOP            _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRLSTR.Bits.VCHOP
    #define NB_ACQ_SRL_ITCHOP           _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRLSTR.Bits.ITCHOP
    #define NB_ACQ_SRL_ETCHOP           _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRLSTR.Bits.ETCHOP
    #define NB_ACQ_SRL_VTH              _NB_ACQ_SR.Overlap_STR.NB_ACQ_SRLSTR.Bits.VTH
    
    #define NB_ACQ_SRL_CCHOP_MASK       1U
    #define NB_ACQ_SRL_VCHOP_MASK       2U
    #define NB_ACQ_SRL_ITCHOP_MASK      4U
    #define NB_ACQ_SRL_ETCHOP_MASK      8U
    #define NB_ACQ_SRL_VTH_MASK         16U
    
  } Overlap_STR;

  struct {
    word CCHOP       :1;                                       /* Chopping Active Status - Current */
    word VCHOP       :1;                                       /* Chopping Active Status - Voltage */
    word ITCHOP      :1;                                       /* Chopping Active Status - Internal Temperature */
    word ETCHOP      :1;                                       /* Chopping Active Status - External Temperature */
    word VTH         :1;                                       /* Digital Voltage High Threshold Reached */
    word             :1; 
    word             :1; 
    word             :1; 
    word CM          :1;                                       /* End of Measurement - Current */
    word VM          :1;                                       /* End of Measurement - Voltage */
    word ITM         :1;                                       /* End of Measurement - Internal Temperature */
    word ETM         :1;                                       /* End of Measurement - External Temperature */
    word CMOW        :1;                                       /* Current Measurement Result Overwritten */
    word VMOW        :1;                                       /* Voltage Measurement Result Overwritten */
    word PGAG        :1;                                       /* PGA Gain Change Flag */
    word AVRF        :1;                                       /* VDDA Low Voltage Reset Flag */
  } Bits;
} NB_ACQ_SRSTR;
extern volatile NB_ACQ_SRSTR _NB_ACQ_SR @0x00000F5A;
#define NB_ACQ_SR                       _NB_ACQ_SR.Word
#define NB_ACQ_SR_CCHOP                 _NB_ACQ_SR.Bits.CCHOP
#define NB_ACQ_SR_VCHOP                 _NB_ACQ_SR.Bits.VCHOP
#define NB_ACQ_SR_ITCHOP                _NB_ACQ_SR.Bits.ITCHOP
#define NB_ACQ_SR_ETCHOP                _NB_ACQ_SR.Bits.ETCHOP
#define NB_ACQ_SR_VTH                   _NB_ACQ_SR.Bits.VTH
#define NB_ACQ_SR_CM                    _NB_ACQ_SR.Bits.CM
#define NB_ACQ_SR_VM                    _NB_ACQ_SR.Bits.VM
#define NB_ACQ_SR_ITM                   _NB_ACQ_SR.Bits.ITM
#define NB_ACQ_SR_ETM                   _NB_ACQ_SR.Bits.ETM
#define NB_ACQ_SR_CMOW                  _NB_ACQ_SR.Bits.CMOW
#define NB_ACQ_SR_VMOW                  _NB_ACQ_SR.Bits.VMOW
#define NB_ACQ_SR_PGAG                  _NB_ACQ_SR.Bits.PGAG
#define NB_ACQ_SR_AVRF                  _NB_ACQ_SR.Bits.AVRF

#define NB_ACQ_SR_CCHOP_MASK            1U
#define NB_ACQ_SR_VCHOP_MASK            2U
#define NB_ACQ_SR_ITCHOP_MASK           4U
#define NB_ACQ_SR_ETCHOP_MASK           8U
#define NB_ACQ_SR_VTH_MASK              16U
#define NB_ACQ_SR_CM_MASK               256U
#define NB_ACQ_SR_VM_MASK               512U
#define NB_ACQ_SR_ITM_MASK              1024U
#define NB_ACQ_SR_ETM_MASK              2048U
#define NB_ACQ_SR_CMOW_MASK             4096U
#define NB_ACQ_SR_VMOW_MASK             8192U
#define NB_ACQ_SR_PGAG_MASK             16384U
#define NB_ACQ_SR_AVRF_MASK             32768U


/*** NB_ACQ_ACC1 - Acquisition chain control 1; 0x00000F5C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_ACQ_ACC1H - Acquisition chain control 1 high; 0x00000F5C ***/
    union {
      byte Byte;
      struct {
        byte AGENM       :1;                                       /* Temperature Measurement Channel - Compensation Enable */
        byte CVCHOPM     :1;                                       /* Voltage Compensation Enable */
        byte ITCHOPM     :1;                                       /* Current Compensation Enable */
        byte ETCHOPM     :1;                                       /* LPF Enable */
        byte LPFENM      :1;                                       /* Chopping Enable - External Temperature */
        byte CCOMPM      :1;                                       /* Chopping Enable - Internal Temperature */
        byte VCOMPM      :1;                                       /* Chopping Enable - Voltage */
        byte TCOMPM      :1;                                       /* Automatic Gain Control Enable */
      } Bits;
    } NB_ACQ_ACC1HSTR;
    #define NB_ACQ_ACC1H                _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1HSTR.Byte
    #define NB_ACQ_ACC1H_AGENM          _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1HSTR.Bits.AGENM
    #define NB_ACQ_ACC1H_CVCHOPM        _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1HSTR.Bits.CVCHOPM
    #define NB_ACQ_ACC1H_ITCHOPM        _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1HSTR.Bits.ITCHOPM
    #define NB_ACQ_ACC1H_ETCHOPM        _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1HSTR.Bits.ETCHOPM
    #define NB_ACQ_ACC1H_LPFENM         _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1HSTR.Bits.LPFENM
    #define NB_ACQ_ACC1H_CCOMPM         _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1HSTR.Bits.CCOMPM
    #define NB_ACQ_ACC1H_VCOMPM         _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1HSTR.Bits.VCOMPM
    #define NB_ACQ_ACC1H_TCOMPM         _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1HSTR.Bits.TCOMPM
    
    #define NB_ACQ_ACC1H_AGENM_MASK     1U
    #define NB_ACQ_ACC1H_CVCHOPM_MASK   2U
    #define NB_ACQ_ACC1H_ITCHOPM_MASK   4U
    #define NB_ACQ_ACC1H_ETCHOPM_MASK   8U
    #define NB_ACQ_ACC1H_LPFENM_MASK    16U
    #define NB_ACQ_ACC1H_CCOMPM_MASK    32U
    #define NB_ACQ_ACC1H_VCOMPM_MASK    64U
    #define NB_ACQ_ACC1H_TCOMPM_MASK    128U
    

    /*** NB_ACQ_ACC1L - Acquisition chain control 1 low; 0x00000F5D ***/
    union {
      byte Byte;
      struct {
        byte AGEN        :1;                                       /* Automatic Gain Control Enable - Mask */
        byte CVCHOP      :1;                                       /* Chopping Enable - Voltage Measurement Channel - Mask */
        byte ITCHOP      :1;                                       /* Chopping Enable - Internal Temperature Measurement Channel - Mask */
        byte ETCHOP      :1;                                       /* Chopping Enable - External Temperature Measurement Channel - Mask */
        byte LPFEN       :1;                                       /* LPF Enable - Mask */
        byte CCOMP       :1;                                       /* Current Measurement Channel - Compensation Enable - Mask */
        byte VCOMP       :1;                                       /* Voltage Measurement Channel - Compensation Enable - Mask */
        byte TCOMP       :1;                                       /* Temperature Measurement Channel - Compensation Enable - Mask */
      } Bits;
    } NB_ACQ_ACC1LSTR;
    #define NB_ACQ_ACC1L                _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1LSTR.Byte
    #define NB_ACQ_ACC1L_AGEN           _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1LSTR.Bits.AGEN
    #define NB_ACQ_ACC1L_CVCHOP         _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1LSTR.Bits.CVCHOP
    #define NB_ACQ_ACC1L_ITCHOP         _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1LSTR.Bits.ITCHOP
    #define NB_ACQ_ACC1L_ETCHOP         _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1LSTR.Bits.ETCHOP
    #define NB_ACQ_ACC1L_LPFEN          _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1LSTR.Bits.LPFEN
    #define NB_ACQ_ACC1L_CCOMP          _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1LSTR.Bits.CCOMP
    #define NB_ACQ_ACC1L_VCOMP          _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1LSTR.Bits.VCOMP
    #define NB_ACQ_ACC1L_TCOMP          _NB_ACQ_ACC1.Overlap_STR.NB_ACQ_ACC1LSTR.Bits.TCOMP
    
    #define NB_ACQ_ACC1L_AGEN_MASK      1U
    #define NB_ACQ_ACC1L_CVCHOP_MASK    2U
    #define NB_ACQ_ACC1L_ITCHOP_MASK    4U
    #define NB_ACQ_ACC1L_ETCHOP_MASK    8U
    #define NB_ACQ_ACC1L_LPFEN_MASK     16U
    #define NB_ACQ_ACC1L_CCOMP_MASK     32U
    #define NB_ACQ_ACC1L_VCOMP_MASK     64U
    #define NB_ACQ_ACC1L_TCOMP_MASK     128U
    
  } Overlap_STR;

  struct {
    word AGEN        :1;                                       /* Automatic Gain Control Enable - Mask */
    word CVCHOP      :1;                                       /* Chopping Enable - Voltage Measurement Channel - Mask */
    word ITCHOP      :1;                                       /* Chopping Enable - Internal Temperature Measurement Channel - Mask */
    word ETCHOP      :1;                                       /* Chopping Enable - External Temperature Measurement Channel - Mask */
    word LPFEN       :1;                                       /* LPF Enable - Mask */
    word CCOMP       :1;                                       /* Current Measurement Channel - Compensation Enable - Mask */
    word VCOMP       :1;                                       /* Voltage Measurement Channel - Compensation Enable - Mask */
    word TCOMP       :1;                                       /* Temperature Measurement Channel - Compensation Enable - Mask */
    word AGENM       :1;                                       /* Temperature Measurement Channel - Compensation Enable */
    word CVCHOPM     :1;                                       /* Voltage Compensation Enable */
    word ITCHOPM     :1;                                       /* Current Compensation Enable */
    word ETCHOPM     :1;                                       /* LPF Enable */
    word LPFENM      :1;                                       /* Chopping Enable - External Temperature */
    word CCOMPM      :1;                                       /* Chopping Enable - Internal Temperature */
    word VCOMPM      :1;                                       /* Chopping Enable - Voltage */
    word TCOMPM      :1;                                       /* Automatic Gain Control Enable */
  } Bits;
} NB_ACQ_ACC1STR;
extern volatile NB_ACQ_ACC1STR _NB_ACQ_ACC1 @0x00000F5C;
#define NB_ACQ_ACC1                     _NB_ACQ_ACC1.Word
#define NB_ACQ_ACC1_AGEN                _NB_ACQ_ACC1.Bits.AGEN
#define NB_ACQ_ACC1_CVCHOP              _NB_ACQ_ACC1.Bits.CVCHOP
#define NB_ACQ_ACC1_ITCHOP              _NB_ACQ_ACC1.Bits.ITCHOP
#define NB_ACQ_ACC1_ETCHOP              _NB_ACQ_ACC1.Bits.ETCHOP
#define NB_ACQ_ACC1_LPFEN               _NB_ACQ_ACC1.Bits.LPFEN
#define NB_ACQ_ACC1_CCOMP               _NB_ACQ_ACC1.Bits.CCOMP
#define NB_ACQ_ACC1_VCOMP               _NB_ACQ_ACC1.Bits.VCOMP
#define NB_ACQ_ACC1_TCOMP               _NB_ACQ_ACC1.Bits.TCOMP
#define NB_ACQ_ACC1_AGENM               _NB_ACQ_ACC1.Bits.AGENM
#define NB_ACQ_ACC1_CVCHOPM             _NB_ACQ_ACC1.Bits.CVCHOPM
#define NB_ACQ_ACC1_ITCHOPM             _NB_ACQ_ACC1.Bits.ITCHOPM
#define NB_ACQ_ACC1_ETCHOPM             _NB_ACQ_ACC1.Bits.ETCHOPM
#define NB_ACQ_ACC1_LPFENM              _NB_ACQ_ACC1.Bits.LPFENM
#define NB_ACQ_ACC1_CCOMPM              _NB_ACQ_ACC1.Bits.CCOMPM
#define NB_ACQ_ACC1_VCOMPM              _NB_ACQ_ACC1.Bits.VCOMPM
#define NB_ACQ_ACC1_TCOMPM              _NB_ACQ_ACC1.Bits.TCOMPM

#define NB_ACQ_ACC1_AGEN_MASK           1U
#define NB_ACQ_ACC1_CVCHOP_MASK         2U
#define NB_ACQ_ACC1_ITCHOP_MASK         4U
#define NB_ACQ_ACC1_ETCHOP_MASK         8U
#define NB_ACQ_ACC1_LPFEN_MASK          16U
#define NB_ACQ_ACC1_CCOMP_MASK          32U
#define NB_ACQ_ACC1_VCOMP_MASK          64U
#define NB_ACQ_ACC1_TCOMP_MASK          128U
#define NB_ACQ_ACC1_AGENM_MASK          256U
#define NB_ACQ_ACC1_CVCHOPM_MASK        512U
#define NB_ACQ_ACC1_ITCHOPM_MASK        1024U
#define NB_ACQ_ACC1_ETCHOPM_MASK        2048U
#define NB_ACQ_ACC1_LPFENM_MASK         4096U
#define NB_ACQ_ACC1_CCOMPM_MASK         8192U
#define NB_ACQ_ACC1_VCOMPM_MASK         16384U
#define NB_ACQ_ACC1_TCOMPM_MASK         32768U


/*** NB_ACQ_ACC0 - Acquisition chain control 0; 0x00000F5E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_ACQ_ACC0H - Acquisition chain control 0 high; 0x00000F5E ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte ZEROM       :1;                                       /* Current and Voltage Sigma Delta Input Short - Mask */
      } Bits;
    } NB_ACQ_ACC0HSTR;
    #define NB_ACQ_ACC0H                _NB_ACQ_ACC0.Overlap_STR.NB_ACQ_ACC0HSTR.Byte
    #define NB_ACQ_ACC0H_ZEROM          _NB_ACQ_ACC0.Overlap_STR.NB_ACQ_ACC0HSTR.Bits.ZEROM
    
    #define NB_ACQ_ACC0H_ZEROM_MASK     128U
    

    /*** NB_ACQ_ACC0L - Acquisition chain control 0 low; 0x00000F5F ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte ZERO        :1;                                       /* Current and Voltage Sigma Delta Input Short */
      } Bits;
    } NB_ACQ_ACC0LSTR;
    #define NB_ACQ_ACC0L                _NB_ACQ_ACC0.Overlap_STR.NB_ACQ_ACC0LSTR.Byte
    #define NB_ACQ_ACC0L_ZERO           _NB_ACQ_ACC0.Overlap_STR.NB_ACQ_ACC0LSTR.Bits.ZERO
    
    #define NB_ACQ_ACC0L_ZERO_MASK      128U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word ZERO        :1;                                       /* Current and Voltage Sigma Delta Input Short */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word ZEROM       :1;                                       /* Current and Voltage Sigma Delta Input Short - Mask */
  } Bits;
} NB_ACQ_ACC0STR;
extern volatile NB_ACQ_ACC0STR _NB_ACQ_ACC0 @0x00000F5E;
#define NB_ACQ_ACC0                     _NB_ACQ_ACC0.Word
#define NB_ACQ_ACC0_ZERO                _NB_ACQ_ACC0.Bits.ZERO
#define NB_ACQ_ACC0_ZEROM               _NB_ACQ_ACC0.Bits.ZEROM

#define NB_ACQ_ACC0_ZERO_MASK           128U
#define NB_ACQ_ACC0_ZEROM_MASK          32768U


/*** NB_ACQ_DEC - Decimation Rate; 0x00000F60 ***/
typedef union {
  byte Byte;
  struct {
    byte DEC         :3;                                       /* Decimation Rate Selection */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NB_ACQ_DECSTR;
extern volatile NB_ACQ_DECSTR _NB_ACQ_DEC @0x00000F60;
#define NB_ACQ_DEC                      _NB_ACQ_DEC.Byte
#define NB_ACQ_DEC_DEC                  _NB_ACQ_DEC.Bits.DEC

#define NB_ACQ_DEC_DEC_MASK             7U
#define NB_ACQ_DEC_DEC_BITNUM           0U


/*** NB_ACQ_GAIN - PGA gain; 0x00000F62 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte IGAIN       :2;                                       /* PGA Gain Register */
    byte LPGEN       :1; 
    byte G4DIS       :1; 
    byte G16DIS      :1; 
    byte G64DIS      :1; 
    byte G256DIS     :1; 
  } Bits;
} NB_ACQ_GAINSTR;
extern volatile NB_ACQ_GAINSTR _NB_ACQ_GAIN @0x00000F62;
#define NB_ACQ_GAIN                     _NB_ACQ_GAIN.Byte
#define NB_ACQ_GAIN_IGAIN               _NB_ACQ_GAIN.Bits.IGAIN
#define NB_ACQ_GAIN_LPGEN               _NB_ACQ_GAIN.Bits.LPGEN
#define NB_ACQ_GAIN_G4DIS               _NB_ACQ_GAIN.Bits.G4DIS
#define NB_ACQ_GAIN_G16DIS              _NB_ACQ_GAIN.Bits.G16DIS
#define NB_ACQ_GAIN_G64DIS              _NB_ACQ_GAIN.Bits.G64DIS
#define NB_ACQ_GAIN_G256DIS             _NB_ACQ_GAIN.Bits.G256DIS

#define NB_ACQ_GAIN_IGAIN_MASK          6U
#define NB_ACQ_GAIN_IGAIN_BITNUM        1U
#define NB_ACQ_GAIN_LPGEN_MASK          8U
#define NB_ACQ_GAIN_G4DIS_MASK          16U
#define NB_ACQ_GAIN_G16DIS_MASK         32U
#define NB_ACQ_GAIN_G64DIS_MASK         64U
#define NB_ACQ_GAIN_G256DIS_MASK        128U


/*** NB_ACQ_GCB - PGA gain; 0x00000F63 ***/
typedef union {
  byte Byte;
  struct {
    byte Dlo         :4;                                       /* Gain Control Block (GCB) - Down Threshold */
    byte Dhi         :4;                                       /* Gain Control Block (GCB) - Up Threshold */
  } Bits;
} NB_ACQ_GCBSTR;
extern volatile NB_ACQ_GCBSTR _NB_ACQ_GCB @0x00000F63;
#define NB_ACQ_GCB                      _NB_ACQ_GCB.Byte
#define NB_ACQ_GCB_Dlo                  _NB_ACQ_GCB.Bits.Dlo
#define NB_ACQ_GCB_Dhi                  _NB_ACQ_GCB.Bits.Dhi

#define NB_ACQ_GCB_Dlo_MASK             15U
#define NB_ACQ_GCB_Dlo_BITNUM           0U
#define NB_ACQ_GCB_Dhi_MASK             240U
#define NB_ACQ_GCB_Dhi_BITNUM           4U


/*** NB_ACQ_ITEMP - Internal temperature measurement result; 0x00000F64 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_ACQ_ITEMPH - Internal temperature measurement result high; 0x00000F64 ***/
    union {
      byte Byte;
    } NB_ACQ_ITEMPHSTR;
    #define NB_ACQ_ITEMPH               _NB_ACQ_ITEMP.Overlap_STR.NB_ACQ_ITEMPHSTR.Byte
    

    /*** NB_ACQ_ITEMPL - Internal temperature measurement result low; 0x00000F65 ***/
    union {
      byte Byte;
    } NB_ACQ_ITEMPLSTR;
    #define NB_ACQ_ITEMPL               _NB_ACQ_ITEMP.Overlap_STR.NB_ACQ_ITEMPLSTR.Byte
    
  } Overlap_STR;

} NB_ACQ_ITEMPSTR;
extern volatile NB_ACQ_ITEMPSTR _NB_ACQ_ITEMP @0x00000F64;
#define NB_ACQ_ITEMP                    _NB_ACQ_ITEMP.Word


/*** NB_ACQ_ETEMP - External temperature measurement result; 0x00000F66 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_ACQ_ETEMPH - External temperature measurement result high; 0x00000F66 ***/
    union {
      byte Byte;
    } NB_ACQ_ETEMPHSTR;
    #define NB_ACQ_ETEMPH               _NB_ACQ_ETEMP.Overlap_STR.NB_ACQ_ETEMPHSTR.Byte
    

    /*** NB_ACQ_ETEMPL - External temperature measurement result low; 0x00000F67 ***/
    union {
      byte Byte;
    } NB_ACQ_ETEMPLSTR;
    #define NB_ACQ_ETEMPL               _NB_ACQ_ETEMP.Overlap_STR.NB_ACQ_ETEMPLSTR.Byte
    
  } Overlap_STR;

} NB_ACQ_ETEMPSTR;
extern volatile NB_ACQ_ETEMPSTR _NB_ACQ_ETEMP @0x00000F66;
#define NB_ACQ_ETEMP                    _NB_ACQ_ETEMP.Word


/*** NB_ACQ_CURR1 - Current measurement result 16Bit; 0x00000F68 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    byte _Reserved_1[1];
    /*** NB_ACQ_CURR1L - Current measurement result 8Bit; 0x00000F69 ***/
    union {
      byte Byte;
    } NB_ACQ_CURR1LSTR;
    #define NB_ACQ_CURR1L               _NB_ACQ_CURR1.Overlap_STR.NB_ACQ_CURR1LSTR.Byte
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word CURR        :8;                                       /* Two's complement 24 Bit signed integer result register for the current measurement channel */
  } Bits;
} NB_ACQ_CURR1STR;
extern volatile NB_ACQ_CURR1STR _NB_ACQ_CURR1 @0x00000F68;
#define NB_ACQ_CURR1                    _NB_ACQ_CURR1.Word
#define NB_ACQ_CURR1_CURR               _NB_ACQ_CURR1.Bits.CURR

#define NB_ACQ_CURR1_CURR_MASK          65280U
#define NB_ACQ_CURR1_CURR_BITNUM        8U


/*** NB_ACQ_CURR0 - Current measurement result; 0x00000F6A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_ACQ_CURR0H - Current measurement result high; 0x00000F6A ***/
    union {
      byte Byte;
    } NB_ACQ_CURR0HSTR;
    #define NB_ACQ_CURR0H               _NB_ACQ_CURR0.Overlap_STR.NB_ACQ_CURR0HSTR.Byte
    

    /*** NB_ACQ_CURR0L - Current measurement result low; 0x00000F6B ***/
    union {
      byte Byte;
    } NB_ACQ_CURR0LSTR;
    #define NB_ACQ_CURR0L               _NB_ACQ_CURR0.Overlap_STR.NB_ACQ_CURR0LSTR.Byte
    
  } Overlap_STR;

} NB_ACQ_CURR0STR;
extern volatile NB_ACQ_CURR0STR _NB_ACQ_CURR0 @0x00000F6A;
#define NB_ACQ_CURR0                    _NB_ACQ_CURR0.Word


/*** NB_ACQ_VOLT - Voltage measurement result; 0x00000F6C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_ACQ_VOLTH - Voltage measurement result high; 0x00000F6C ***/
    union {
      byte Byte;
    } NB_ACQ_VOLTHSTR;
    #define NB_ACQ_VOLTH                _NB_ACQ_VOLT.Overlap_STR.NB_ACQ_VOLTHSTR.Byte
    

    /*** NB_ACQ_VOLTL - Voltage measurement result low; 0x00000F6D ***/
    union {
      byte Byte;
    } NB_ACQ_VOLTLSTR;
    #define NB_ACQ_VOLTL                _NB_ACQ_VOLT.Overlap_STR.NB_ACQ_VOLTLSTR.Byte
    
  } Overlap_STR;

} NB_ACQ_VOLTSTR;
extern volatile NB_ACQ_VOLTSTR _NB_ACQ_VOLT @0x00000F6C;
#define NB_ACQ_VOLT                     _NB_ACQ_VOLT.Word


/*** NB_ACQ_LPFC - Low pass filter coefficient number; 0x00000F6E ***/
typedef union {
  byte Byte;
  struct {
    byte LPFC        :4;                                       /* Low Pass Filter Coefficient Number */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NB_ACQ_LPFCSTR;
extern volatile NB_ACQ_LPFCSTR _NB_ACQ_LPFC @0x00000F6E;
#define NB_ACQ_LPFC                     _NB_ACQ_LPFC.Byte
#define NB_ACQ_LPFC_LPFC                _NB_ACQ_LPFC.Bits.LPFC

#define NB_ACQ_LPFC_LPFC_MASK           15U
#define NB_ACQ_LPFC_LPFC_BITNUM         0U


/*** NB_ACQ_TCMP - Low power trigger current measurement period; 0x00000F70 ***/
typedef union {
  word Word;
} NB_ACQ_TCMPSTR;
extern volatile NB_ACQ_TCMPSTR _NB_ACQ_TCMP @0x00000F70;
#define NB_ACQ_TCMP                     _NB_ACQ_TCMP.Word


/*** NB_ACQ_THF - Low power current threshold filtering period; 0x00000F72 ***/
typedef union {
  byte Byte;
} NB_ACQ_THFSTR;
extern volatile NB_ACQ_THFSTR _NB_ACQ_THF @0x00000F72;
#define NB_ACQ_THF                      _NB_ACQ_THF.Byte


/*** NB_ACQ_CVCR - I and V chopper control register; 0x00000F74 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_ACQ_CVCRH - I and V chopper control register high; 0x00000F74 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte IIRCM       :3;                                       /* IIR Low Pass Filter Configuration - Mask */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_ACQ_CVCRHSTR;
    #define NB_ACQ_CVCRH                _NB_ACQ_CVCR.Overlap_STR.NB_ACQ_CVCRHSTR.Byte
    #define NB_ACQ_CVCRH_IIRCM          _NB_ACQ_CVCR.Overlap_STR.NB_ACQ_CVCRHSTR.Bits.IIRCM
    
    #define NB_ACQ_CVCRH_IIRCM_MASK     14U
    #define NB_ACQ_CVCRH_IIRCM_BITNUM   1U
    

    /*** NB_ACQ_CVCRL - I and V chopper control register high low; 0x00000F75 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte IIRC        :3;                                       /* IIR Low Pass Filter Coefficient */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_ACQ_CVCRLSTR;
    #define NB_ACQ_CVCRL                _NB_ACQ_CVCR.Overlap_STR.NB_ACQ_CVCRLSTR.Byte
    #define NB_ACQ_CVCRL_IIRC           _NB_ACQ_CVCR.Overlap_STR.NB_ACQ_CVCRLSTR.Bits.IIRC
    
    #define NB_ACQ_CVCRL_IIRC_MASK      14U
    #define NB_ACQ_CVCRL_IIRC_BITNUM    1U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word IIRC        :3;                                       /* IIR Low Pass Filter Coefficient */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word IIRCM       :3;                                       /* IIR Low Pass Filter Configuration - Mask */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_ACQ_CVCRSTR;
extern volatile NB_ACQ_CVCRSTR _NB_ACQ_CVCR @0x00000F74;
#define NB_ACQ_CVCR                     _NB_ACQ_CVCR.Word
#define NB_ACQ_CVCR_IIRC                _NB_ACQ_CVCR.Bits.IIRC
#define NB_ACQ_CVCR_IIRCM               _NB_ACQ_CVCR.Bits.IIRCM

#define NB_ACQ_CVCR_IIRC_MASK           14U
#define NB_ACQ_CVCR_IIRC_BITNUM         1U
#define NB_ACQ_CVCR_IIRCM_MASK          3584U
#define NB_ACQ_CVCR_IIRCM_BITNUM        9U


/*** NB_ACQ_CTH - Low power current threshold; 0x00000F76 ***/
typedef union {
  byte Byte;
} NB_ACQ_CTHSTR;
extern volatile NB_ACQ_CTHSTR _NB_ACQ_CTH @0x00000F76;
#define NB_ACQ_CTH                      _NB_ACQ_CTH.Byte


/*** NB_ACQ_AHTH - Low power Ah counter threshold; 0x00000F78 ***/
typedef union {
  dword Dword;
   /* Overlapped registers: */
  struct {
    /*** NB_ACQ_AHTH1 - Low power Ah counter threshold 1; 0x00000F78 ***/
    union {
      word Word;
       /* Overlapped registers: */
      struct {
        /*** NB_ACQ_AHTH1H - Low power Ah counter threshold 1 high; 0x00000F78 ***/
        union {
          byte Byte;
          struct {
            byte AHTH        :7;                                       /* Low power Ah counter threshold 1 high */
            byte             :1; 
          } Bits;
        } NB_ACQ_AHTH1HSTR;
        #define NB_ACQ_AHTH1H           _NB_ACQ_AHTH.Overlap_STR.NB_ACQ_AHTH1STR.Overlap_STR.NB_ACQ_AHTH1HSTR.Byte
        #define NB_ACQ_AHTH1H_AHTH      _NB_ACQ_AHTH.Overlap_STR.NB_ACQ_AHTH1STR.Overlap_STR.NB_ACQ_AHTH1HSTR.Bits.AHTH
        
        #define NB_ACQ_AHTH1H_AHTH_MASK 127U
        #define NB_ACQ_AHTH1H_AHTH_BITNUM 0U
        
    
        /*** NB_ACQ_AHTH1L - Low power Ah counter threshold 1 low; 0x00000F79 ***/
        union {
          byte Byte;
        } NB_ACQ_AHTH1LSTR;
        #define NB_ACQ_AHTH1L           _NB_ACQ_AHTH.Overlap_STR.NB_ACQ_AHTH1STR.Overlap_STR.NB_ACQ_AHTH1LSTR.Byte
        
      } Overlap_STR;
    
      struct {
        word AHTH        :15;                                      /* Low power Ah counter threshold 1 */
        word             :1; 
      } Bits;
    } NB_ACQ_AHTH1STR;
    #define NB_ACQ_AHTH1                _NB_ACQ_AHTH.Overlap_STR.NB_ACQ_AHTH1STR.Word
    #define NB_ACQ_AHTH1_AHTH           _NB_ACQ_AHTH.Overlap_STR.NB_ACQ_AHTH1STR.Bits.AHTH
    
    #define NB_ACQ_AHTH1_AHTH_MASK      32767U
    #define NB_ACQ_AHTH1_AHTH_BITNUM    0U
    

    /*** NB_ACQ_AHTH0 - Low power Ah counter threshold 0; 0x00000F7A ***/
    union {
      word Word;
       /* Overlapped registers: */
      struct {
        /*** NB_ACQ_AHTH0H - Low power Ah counter threshold 0 high; 0x00000F7A ***/
        union {
          byte Byte;
        } NB_ACQ_AHTH0HSTR;
        #define NB_ACQ_AHTH0H           _NB_ACQ_AHTH.Overlap_STR.NB_ACQ_AHTH0STR.Overlap_STR.NB_ACQ_AHTH0HSTR.Byte
        
    
        /*** NB_ACQ_AHTH0L - Low power Ah counter threshold 0 low; 0x00000F7B ***/
        union {
          byte Byte;
        } NB_ACQ_AHTH0LSTR;
        #define NB_ACQ_AHTH0L           _NB_ACQ_AHTH.Overlap_STR.NB_ACQ_AHTH0STR.Overlap_STR.NB_ACQ_AHTH0LSTR.Byte
        
      } Overlap_STR;
    
    } NB_ACQ_AHTH0STR;
    #define NB_ACQ_AHTH0                _NB_ACQ_AHTH.Overlap_STR.NB_ACQ_AHTH0STR.Word
    
  } Overlap_STR;

} NB_ACQ_AHTHSTR;
extern volatile NB_ACQ_AHTHSTR _NB_ACQ_AHTH @0x00000F78;
#define NB_ACQ_AHTH                     _NB_ACQ_AHTH.Dword


/*** NB_ACQ_AHC - Low power Ah counter; 0x00000F7C ***/
typedef union {
  dword Dword;
   /* Overlapped registers: */
  struct {
    /*** NB_ACQ_AHC1 - Low power Ah counter 1; 0x00000F7C ***/
    union {
      word Word;
       /* Overlapped registers: */
      struct {
        /*** NB_ACQ_AHC1H - Low power Ah counter 1 high; 0x00000F7C ***/
        union {
          byte Byte;
        } NB_ACQ_AHC1HSTR;
        #define NB_ACQ_AHC1H            _NB_ACQ_AHC.Overlap_STR.NB_ACQ_AHC1STR.Overlap_STR.NB_ACQ_AHC1HSTR.Byte
        
    
        /*** NB_ACQ_AHC1L - Low power Ah counter 1 low; 0x00000F7D ***/
        union {
          byte Byte;
        } NB_ACQ_AHC1LSTR;
        #define NB_ACQ_AHC1L            _NB_ACQ_AHC.Overlap_STR.NB_ACQ_AHC1STR.Overlap_STR.NB_ACQ_AHC1LSTR.Byte
        
      } Overlap_STR;
    
    } NB_ACQ_AHC1STR;
    #define NB_ACQ_AHC1                 _NB_ACQ_AHC.Overlap_STR.NB_ACQ_AHC1STR.Word
    

    /*** NB_ACQ_AHC0 - Low power Ah counter 0; 0x00000F7E ***/
    union {
      word Word;
       /* Overlapped registers: */
      struct {
        /*** NB_ACQ_AHC0H - Low power Ah counter 0 high; 0x00000F7E ***/
        union {
          byte Byte;
        } NB_ACQ_AHC0HSTR;
        #define NB_ACQ_AHC0H            _NB_ACQ_AHC.Overlap_STR.NB_ACQ_AHC0STR.Overlap_STR.NB_ACQ_AHC0HSTR.Byte
        
    
        /*** NB_ACQ_AHC0L - Low power Ah counter 0 low; 0x00000F7F ***/
        union {
          byte Byte;
        } NB_ACQ_AHC0LSTR;
        #define NB_ACQ_AHC0L            _NB_ACQ_AHC.Overlap_STR.NB_ACQ_AHC0STR.Overlap_STR.NB_ACQ_AHC0LSTR.Byte
        
      } Overlap_STR;
    
    } NB_ACQ_AHC0STR;
    #define NB_ACQ_AHC0                 _NB_ACQ_AHC.Overlap_STR.NB_ACQ_AHC0STR.Word
    
  } Overlap_STR;

} NB_ACQ_AHCSTR;
extern volatile NB_ACQ_AHCSTR _NB_ACQ_AHC @0x00000F7C;
#define NB_ACQ_AHC                      _NB_ACQ_AHC.Dword


/*** NB_LPF_A0 - Low Pass Filter Coefficient A0; 0x00000F80 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A0H - Low Pass Filter Coefficient A0 high; 0x00000F80 ***/
    union {
      byte Byte;
    } NB_LPF_A0HSTR;
    #define NB_LPF_A0H                  _NB_LPF_A0.Overlap_STR.NB_LPF_A0HSTR.Byte
    

    /*** NB_LPF_A0L - Low Pass Filter Coefficient A0 low; 0x00000F81 ***/
    union {
      byte Byte;
    } NB_LPF_A0LSTR;
    #define NB_LPF_A0L                  _NB_LPF_A0.Overlap_STR.NB_LPF_A0LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A0STR;
extern volatile NB_LPF_A0STR _NB_LPF_A0 @0x00000F80;
#define NB_LPF_A0                       _NB_LPF_A0.Word
/* NB_LPF_A_ARR: Access 16 NB_LPF_Ax registers in an array */
#define NB_LPF_A_ARR                    ((volatile word *) &NB_LPF_A0)


/*** NB_LPF_A1 - Low Pass Filter Coefficient A1; 0x00000F82 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A1H - Low Pass Filter Coefficient A1 high; 0x00000F82 ***/
    union {
      byte Byte;
    } NB_LPF_A1HSTR;
    #define NB_LPF_A1H                  _NB_LPF_A1.Overlap_STR.NB_LPF_A1HSTR.Byte
    

    /*** NB_LPF_A1L - Low Pass Filter Coefficient A1 low; 0x00000F83 ***/
    union {
      byte Byte;
    } NB_LPF_A1LSTR;
    #define NB_LPF_A1L                  _NB_LPF_A1.Overlap_STR.NB_LPF_A1LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A1STR;
extern volatile NB_LPF_A1STR _NB_LPF_A1 @0x00000F82;
#define NB_LPF_A1                       _NB_LPF_A1.Word


/*** NB_LPF_A2 - Low Pass Filter Coefficient A2; 0x00000F84 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A2H - Low Pass Filter Coefficient A2 high; 0x00000F84 ***/
    union {
      byte Byte;
    } NB_LPF_A2HSTR;
    #define NB_LPF_A2H                  _NB_LPF_A2.Overlap_STR.NB_LPF_A2HSTR.Byte
    

    /*** NB_LPF_A2L - Low Pass Filter Coefficient A2 low; 0x00000F85 ***/
    union {
      byte Byte;
    } NB_LPF_A2LSTR;
    #define NB_LPF_A2L                  _NB_LPF_A2.Overlap_STR.NB_LPF_A2LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A2STR;
extern volatile NB_LPF_A2STR _NB_LPF_A2 @0x00000F84;
#define NB_LPF_A2                       _NB_LPF_A2.Word


/*** NB_LPF_A3 - Low Pass Filter Coefficient A3; 0x00000F86 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A3H - Low Pass Filter Coefficient A3 high; 0x00000F86 ***/
    union {
      byte Byte;
    } NB_LPF_A3HSTR;
    #define NB_LPF_A3H                  _NB_LPF_A3.Overlap_STR.NB_LPF_A3HSTR.Byte
    

    /*** NB_LPF_A3L - Low Pass Filter Coefficient A3 low; 0x00000F87 ***/
    union {
      byte Byte;
    } NB_LPF_A3LSTR;
    #define NB_LPF_A3L                  _NB_LPF_A3.Overlap_STR.NB_LPF_A3LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A3STR;
extern volatile NB_LPF_A3STR _NB_LPF_A3 @0x00000F86;
#define NB_LPF_A3                       _NB_LPF_A3.Word


/*** NB_LPF_A4 - Low Pass Filter Coefficient A4; 0x00000F88 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A4H - Low Pass Filter Coefficient A4 high; 0x00000F88 ***/
    union {
      byte Byte;
    } NB_LPF_A4HSTR;
    #define NB_LPF_A4H                  _NB_LPF_A4.Overlap_STR.NB_LPF_A4HSTR.Byte
    

    /*** NB_LPF_A4L - Low Pass Filter Coefficient A4 low; 0x00000F89 ***/
    union {
      byte Byte;
    } NB_LPF_A4LSTR;
    #define NB_LPF_A4L                  _NB_LPF_A4.Overlap_STR.NB_LPF_A4LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A4STR;
extern volatile NB_LPF_A4STR _NB_LPF_A4 @0x00000F88;
#define NB_LPF_A4                       _NB_LPF_A4.Word


/*** NB_LPF_A5 - Low Pass Filter Coefficient A5; 0x00000F8A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A5H - Low Pass Filter Coefficient A5 high; 0x00000F8A ***/
    union {
      byte Byte;
    } NB_LPF_A5HSTR;
    #define NB_LPF_A5H                  _NB_LPF_A5.Overlap_STR.NB_LPF_A5HSTR.Byte
    

    /*** NB_LPF_A5L - Low Pass Filter Coefficient A5 low; 0x00000F8B ***/
    union {
      byte Byte;
    } NB_LPF_A5LSTR;
    #define NB_LPF_A5L                  _NB_LPF_A5.Overlap_STR.NB_LPF_A5LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A5STR;
extern volatile NB_LPF_A5STR _NB_LPF_A5 @0x00000F8A;
#define NB_LPF_A5                       _NB_LPF_A5.Word


/*** NB_LPF_A6 - Low Pass Filter Coefficient A6; 0x00000F8C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A6H - Low Pass Filter Coefficient A6 high; 0x00000F8C ***/
    union {
      byte Byte;
    } NB_LPF_A6HSTR;
    #define NB_LPF_A6H                  _NB_LPF_A6.Overlap_STR.NB_LPF_A6HSTR.Byte
    

    /*** NB_LPF_A6L - Low Pass Filter Coefficient A6 low; 0x00000F8D ***/
    union {
      byte Byte;
    } NB_LPF_A6LSTR;
    #define NB_LPF_A6L                  _NB_LPF_A6.Overlap_STR.NB_LPF_A6LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A6STR;
extern volatile NB_LPF_A6STR _NB_LPF_A6 @0x00000F8C;
#define NB_LPF_A6                       _NB_LPF_A6.Word


/*** NB_LPF_A7 - Low Pass Filter Coefficient A7; 0x00000F8E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A7H - Low Pass Filter Coefficient A7 high; 0x00000F8E ***/
    union {
      byte Byte;
    } NB_LPF_A7HSTR;
    #define NB_LPF_A7H                  _NB_LPF_A7.Overlap_STR.NB_LPF_A7HSTR.Byte
    

    /*** NB_LPF_A7L - Low Pass Filter Coefficient A7 low; 0x00000F8F ***/
    union {
      byte Byte;
    } NB_LPF_A7LSTR;
    #define NB_LPF_A7L                  _NB_LPF_A7.Overlap_STR.NB_LPF_A7LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A7STR;
extern volatile NB_LPF_A7STR _NB_LPF_A7 @0x00000F8E;
#define NB_LPF_A7                       _NB_LPF_A7.Word


/*** NB_LPF_A8 - Low Pass Filter Coefficient A8; 0x00000F90 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A8H - Low Pass Filter Coefficient A8 high; 0x00000F90 ***/
    union {
      byte Byte;
    } NB_LPF_A8HSTR;
    #define NB_LPF_A8H                  _NB_LPF_A8.Overlap_STR.NB_LPF_A8HSTR.Byte
    

    /*** NB_LPF_A8L - Low Pass Filter Coefficient A8 low; 0x00000F91 ***/
    union {
      byte Byte;
    } NB_LPF_A8LSTR;
    #define NB_LPF_A8L                  _NB_LPF_A8.Overlap_STR.NB_LPF_A8LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A8STR;
extern volatile NB_LPF_A8STR _NB_LPF_A8 @0x00000F90;
#define NB_LPF_A8                       _NB_LPF_A8.Word


/*** NB_LPF_A9 - Low Pass Filter Coefficient A9; 0x00000F92 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A9H - Low Pass Filter Coefficient A9 high; 0x00000F92 ***/
    union {
      byte Byte;
    } NB_LPF_A9HSTR;
    #define NB_LPF_A9H                  _NB_LPF_A9.Overlap_STR.NB_LPF_A9HSTR.Byte
    

    /*** NB_LPF_A9L - Low Pass Filter Coefficient A9 low; 0x00000F93 ***/
    union {
      byte Byte;
    } NB_LPF_A9LSTR;
    #define NB_LPF_A9L                  _NB_LPF_A9.Overlap_STR.NB_LPF_A9LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A9STR;
extern volatile NB_LPF_A9STR _NB_LPF_A9 @0x00000F92;
#define NB_LPF_A9                       _NB_LPF_A9.Word


/*** NB_LPF_A10 - Low Pass Filter Coefficient A10; 0x00000F94 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A10H - Low Pass Filter Coefficient A10 high; 0x00000F94 ***/
    union {
      byte Byte;
    } NB_LPF_A10HSTR;
    #define NB_LPF_A10H                 _NB_LPF_A10.Overlap_STR.NB_LPF_A10HSTR.Byte
    

    /*** NB_LPF_A10L - Low Pass Filter Coefficient A10 low; 0x00000F95 ***/
    union {
      byte Byte;
    } NB_LPF_A10LSTR;
    #define NB_LPF_A10L                 _NB_LPF_A10.Overlap_STR.NB_LPF_A10LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A10STR;
extern volatile NB_LPF_A10STR _NB_LPF_A10 @0x00000F94;
#define NB_LPF_A10                      _NB_LPF_A10.Word


/*** NB_LPF_A11 - Low Pass Filter Coefficient A11; 0x00000F96 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A11H - Low Pass Filter Coefficient A11 high; 0x00000F96 ***/
    union {
      byte Byte;
    } NB_LPF_A11HSTR;
    #define NB_LPF_A11H                 _NB_LPF_A11.Overlap_STR.NB_LPF_A11HSTR.Byte
    

    /*** NB_LPF_A11L - Low Pass Filter Coefficient A11 low; 0x00000F97 ***/
    union {
      byte Byte;
    } NB_LPF_A11LSTR;
    #define NB_LPF_A11L                 _NB_LPF_A11.Overlap_STR.NB_LPF_A11LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A11STR;
extern volatile NB_LPF_A11STR _NB_LPF_A11 @0x00000F96;
#define NB_LPF_A11                      _NB_LPF_A11.Word


/*** NB_LPF_A12 - Low Pass Filter Coefficient A12; 0x00000F98 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A12H - Low Pass Filter Coefficient A12 high; 0x00000F98 ***/
    union {
      byte Byte;
    } NB_LPF_A12HSTR;
    #define NB_LPF_A12H                 _NB_LPF_A12.Overlap_STR.NB_LPF_A12HSTR.Byte
    

    /*** NB_LPF_A12L - Low Pass Filter Coefficient A12 low; 0x00000F99 ***/
    union {
      byte Byte;
    } NB_LPF_A12LSTR;
    #define NB_LPF_A12L                 _NB_LPF_A12.Overlap_STR.NB_LPF_A12LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A12STR;
extern volatile NB_LPF_A12STR _NB_LPF_A12 @0x00000F98;
#define NB_LPF_A12                      _NB_LPF_A12.Word


/*** NB_LPF_A13 - Low Pass Filter Coefficient A13; 0x00000F9A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A13H - Low Pass Filter Coefficient A13 high; 0x00000F9A ***/
    union {
      byte Byte;
    } NB_LPF_A13HSTR;
    #define NB_LPF_A13H                 _NB_LPF_A13.Overlap_STR.NB_LPF_A13HSTR.Byte
    

    /*** NB_LPF_A13L - Low Pass Filter Coefficient A13 low; 0x00000F9B ***/
    union {
      byte Byte;
    } NB_LPF_A13LSTR;
    #define NB_LPF_A13L                 _NB_LPF_A13.Overlap_STR.NB_LPF_A13LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A13STR;
extern volatile NB_LPF_A13STR _NB_LPF_A13 @0x00000F9A;
#define NB_LPF_A13                      _NB_LPF_A13.Word


/*** NB_LPF_A14 - Low Pass Filter Coefficient A14; 0x00000F9C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A14H - Low Pass Filter Coefficient A14 high; 0x00000F9C ***/
    union {
      byte Byte;
    } NB_LPF_A14HSTR;
    #define NB_LPF_A14H                 _NB_LPF_A14.Overlap_STR.NB_LPF_A14HSTR.Byte
    

    /*** NB_LPF_A14L - Low Pass Filter Coefficient A14 low; 0x00000F9D ***/
    union {
      byte Byte;
    } NB_LPF_A14LSTR;
    #define NB_LPF_A14L                 _NB_LPF_A14.Overlap_STR.NB_LPF_A14LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A14STR;
extern volatile NB_LPF_A14STR _NB_LPF_A14 @0x00000F9C;
#define NB_LPF_A14                      _NB_LPF_A14.Word


/*** NB_LPF_A15 - Low Pass Filter Coefficient A15; 0x00000F9E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_LPF_A15H - Low Pass Filter Coefficient A15 high; 0x00000F9E ***/
    union {
      byte Byte;
    } NB_LPF_A15HSTR;
    #define NB_LPF_A15H                 _NB_LPF_A15.Overlap_STR.NB_LPF_A15HSTR.Byte
    

    /*** NB_LPF_A15L - Low Pass Filter Coefficient A15 low; 0x00000F9F ***/
    union {
      byte Byte;
    } NB_LPF_A15LSTR;
    #define NB_LPF_A15L                 _NB_LPF_A15.Overlap_STR.NB_LPF_A15LSTR.Byte
    
  } Overlap_STR;

} NB_LPF_A15STR;
extern volatile NB_LPF_A15STR _NB_LPF_A15 @0x00000F9E;
#define NB_LPF_A15                      _NB_LPF_A15.Word


/*** NB_COMP_CTL - Compensation control register; 0x00000FA0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_CTLH - Compensation control register high; 0x00000FA0 ***/
    union {
      byte Byte;
      struct {
        byte CALIEM      :1;                                       /* Calibration IRQ Enable - Mask */
        byte DIAGTM      :1; 
        byte DIAGIM      :1;                                       /* Diagnostic Mode Current Channel - Mask */
        byte DIAGVM      :1;                                       /* Diagnostic Mode Voltage Channel - Mask */
        byte PGAOM       :1;                                       /* PGA Offset Calibration - Mask */
        byte PGAZM       :1;                                       /* PGA Input Zero - Mask */
        byte             :1; 
        byte OPENEM      :1; 
      } Bits;
    } NB_COMP_CTLHSTR;
    #define NB_COMP_CTLH                _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLHSTR.Byte
    #define NB_COMP_CTLH_CALIEM         _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLHSTR.Bits.CALIEM
    #define NB_COMP_CTLH_DIAGTM         _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLHSTR.Bits.DIAGTM
    #define NB_COMP_CTLH_DIAGIM         _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLHSTR.Bits.DIAGIM
    #define NB_COMP_CTLH_DIAGVM         _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLHSTR.Bits.DIAGVM
    #define NB_COMP_CTLH_PGAOM          _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLHSTR.Bits.PGAOM
    #define NB_COMP_CTLH_PGAZM          _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLHSTR.Bits.PGAZM
    #define NB_COMP_CTLH_OPENEM         _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLHSTR.Bits.OPENEM
    
    #define NB_COMP_CTLH_CALIEM_MASK    1U
    #define NB_COMP_CTLH_DIAGTM_MASK    2U
    #define NB_COMP_CTLH_DIAGIM_MASK    4U
    #define NB_COMP_CTLH_DIAGVM_MASK    8U
    #define NB_COMP_CTLH_PGAOM_MASK     16U
    #define NB_COMP_CTLH_PGAZM_MASK     32U
    #define NB_COMP_CTLH_OPENEM_MASK    128U
    

    /*** NB_COMP_CTLL - Compensation control register low; 0x00000FA1 ***/
    union {
      byte Byte;
      struct {
        byte CALIE       :1;                                       /* Calibration IRQ Enable */
        byte DIAGT       :1; 
        byte DIAGI       :1;                                       /* Diagnostic Mode Current Channel */
        byte DIAGV       :1;                                       /* Diagnostic Mode Voltage Channel */
        byte PGAO        :1;                                       /* PGA Offset Calibration Start */
        byte PGAZ        :1;                                       /* PGA Input Zero */
        byte             :1; 
        byte OPENE       :1; 
      } Bits;
    } NB_COMP_CTLLSTR;
    #define NB_COMP_CTLL                _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLLSTR.Byte
    #define NB_COMP_CTLL_CALIE          _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLLSTR.Bits.CALIE
    #define NB_COMP_CTLL_DIAGT          _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLLSTR.Bits.DIAGT
    #define NB_COMP_CTLL_DIAGI          _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLLSTR.Bits.DIAGI
    #define NB_COMP_CTLL_DIAGV          _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLLSTR.Bits.DIAGV
    #define NB_COMP_CTLL_PGAO           _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLLSTR.Bits.PGAO
    #define NB_COMP_CTLL_PGAZ           _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLLSTR.Bits.PGAZ
    #define NB_COMP_CTLL_OPENE          _NB_COMP_CTL.Overlap_STR.NB_COMP_CTLLSTR.Bits.OPENE
    
    #define NB_COMP_CTLL_CALIE_MASK     1U
    #define NB_COMP_CTLL_DIAGT_MASK     2U
    #define NB_COMP_CTLL_DIAGI_MASK     4U
    #define NB_COMP_CTLL_DIAGV_MASK     8U
    #define NB_COMP_CTLL_PGAO_MASK      16U
    #define NB_COMP_CTLL_PGAZ_MASK      32U
    #define NB_COMP_CTLL_OPENE_MASK     128U
    
  } Overlap_STR;

  struct {
    word CALIE       :1;                                       /* Calibration IRQ Enable */
    word DIAGT       :1; 
    word DIAGI       :1;                                       /* Diagnostic Mode Current Channel */
    word DIAGV       :1;                                       /* Diagnostic Mode Voltage Channel */
    word PGAO        :1;                                       /* PGA Offset Calibration Start */
    word PGAZ        :1;                                       /* PGA Input Zero */
    word             :1; 
    word OPENE       :1; 
    word CALIEM      :1;                                       /* Calibration IRQ Enable - Mask */
    word DIAGTM      :1; 
    word DIAGIM      :1;                                       /* Diagnostic Mode Current Channel - Mask */
    word DIAGVM      :1;                                       /* Diagnostic Mode Voltage Channel - Mask */
    word PGAOM       :1;                                       /* PGA Offset Calibration - Mask */
    word PGAZM       :1;                                       /* PGA Input Zero - Mask */
    word             :1; 
    word OPENEM      :1; 
  } Bits;
} NB_COMP_CTLSTR;
extern volatile NB_COMP_CTLSTR _NB_COMP_CTL @0x00000FA0;
#define NB_COMP_CTL                     _NB_COMP_CTL.Word
#define NB_COMP_CTL_CALIE               _NB_COMP_CTL.Bits.CALIE
#define NB_COMP_CTL_DIAGT               _NB_COMP_CTL.Bits.DIAGT
#define NB_COMP_CTL_DIAGI               _NB_COMP_CTL.Bits.DIAGI
#define NB_COMP_CTL_DIAGV               _NB_COMP_CTL.Bits.DIAGV
#define NB_COMP_CTL_PGAO                _NB_COMP_CTL.Bits.PGAO
#define NB_COMP_CTL_PGAZ                _NB_COMP_CTL.Bits.PGAZ
#define NB_COMP_CTL_OPENE               _NB_COMP_CTL.Bits.OPENE
#define NB_COMP_CTL_CALIEM              _NB_COMP_CTL.Bits.CALIEM
#define NB_COMP_CTL_DIAGTM              _NB_COMP_CTL.Bits.DIAGTM
#define NB_COMP_CTL_DIAGIM              _NB_COMP_CTL.Bits.DIAGIM
#define NB_COMP_CTL_DIAGVM              _NB_COMP_CTL.Bits.DIAGVM
#define NB_COMP_CTL_PGAOM               _NB_COMP_CTL.Bits.PGAOM
#define NB_COMP_CTL_PGAZM               _NB_COMP_CTL.Bits.PGAZM
#define NB_COMP_CTL_OPENEM              _NB_COMP_CTL.Bits.OPENEM

#define NB_COMP_CTL_CALIE_MASK          1U
#define NB_COMP_CTL_DIAGT_MASK          2U
#define NB_COMP_CTL_DIAGI_MASK          4U
#define NB_COMP_CTL_DIAGV_MASK          8U
#define NB_COMP_CTL_PGAO_MASK           16U
#define NB_COMP_CTL_PGAZ_MASK           32U
#define NB_COMP_CTL_OPENE_MASK          128U
#define NB_COMP_CTL_CALIEM_MASK         256U
#define NB_COMP_CTL_DIAGTM_MASK         512U
#define NB_COMP_CTL_DIAGIM_MASK         1024U
#define NB_COMP_CTL_DIAGVM_MASK         2048U
#define NB_COMP_CTL_PGAOM_MASK          4096U
#define NB_COMP_CTL_PGAZM_MASK          8192U
#define NB_COMP_CTL_OPENEM_MASK         32768U


/*** NB_COMP_SR - Compensation status register; 0x00000FA2 ***/
typedef union {
  byte Byte;
  struct {
    byte CALF        :1;                                       /* Calibration Request Status Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PGAOF       :1;                                       /* PGA Internal Offset Compensation Complete Flag */
    byte             :1; 
    byte BGRF        :1;                                       /* Band Gap Reference Status Flag */
    byte OPEN        :1; 
  } Bits;
} NB_COMP_SRSTR;
extern volatile NB_COMP_SRSTR _NB_COMP_SR @0x00000FA2;
#define NB_COMP_SR                      _NB_COMP_SR.Byte
#define NB_COMP_SR_CALF                 _NB_COMP_SR.Bits.CALF
#define NB_COMP_SR_PGAOF                _NB_COMP_SR.Bits.PGAOF
#define NB_COMP_SR_BGRF                 _NB_COMP_SR.Bits.BGRF
#define NB_COMP_SR_OPEN                 _NB_COMP_SR.Bits.OPEN

#define NB_COMP_SR_CALF_MASK            1U
#define NB_COMP_SR_PGAOF_MASK           16U
#define NB_COMP_SR_BGRF_MASK            64U
#define NB_COMP_SR_OPEN_MASK            128U


/*** NB_COMP_TF - Temperature filtering period; 0x00000FA3 ***/
typedef union {
  byte Byte;
  struct {
    byte TMF         :3;                                       /* Recalibration Temperature Filtering Period */
    byte ATGCE       :1; 
    byte IRSEL       :3; 
    byte             :1; 
  } Bits;
} NB_COMP_TFSTR;
extern volatile NB_COMP_TFSTR _NB_COMP_TF @0x00000FA3;
#define NB_COMP_TF                      _NB_COMP_TF.Byte
#define NB_COMP_TF_TMF                  _NB_COMP_TF.Bits.TMF
#define NB_COMP_TF_ATGCE                _NB_COMP_TF.Bits.ATGCE
#define NB_COMP_TF_IRSEL                _NB_COMP_TF.Bits.IRSEL

#define NB_COMP_TF_TMF_MASK             7U
#define NB_COMP_TF_TMF_BITNUM           0U
#define NB_COMP_TF_ATGCE_MASK           8U
#define NB_COMP_TF_IRSEL_MASK           112U
#define NB_COMP_TF_IRSEL_BITNUM         4U


/*** NB_COMP_TMAX - Max temp before recalibration; 0x00000FA4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_TMAXH - Max temp before recalibration high; 0x00000FA4 ***/
    union {
      byte Byte;
    } NB_COMP_TMAXHSTR;
    #define NB_COMP_TMAXH               _NB_COMP_TMAX.Overlap_STR.NB_COMP_TMAXHSTR.Byte
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TCMAX       :8;                                       /* Maximum Temperature before recalibration */
  } Bits;
} NB_COMP_TMAXSTR;
extern volatile NB_COMP_TMAXSTR _NB_COMP_TMAX @0x00000FA4;
#define NB_COMP_TMAX                    _NB_COMP_TMAX.Word
#define NB_COMP_TMAX_TCMAX              _NB_COMP_TMAX.Bits.TCMAX

#define NB_COMP_TMAX_TCMAX_MASK         65280U
#define NB_COMP_TMAX_TCMAX_BITNUM       8U


/*** NB_COMP_TMIN - Min temp before recalibration; 0x00000FA6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_TMINH - Min temp before recalibration high; 0x00000FA6 ***/
    union {
      byte Byte;
    } NB_COMP_TMINHSTR;
    #define NB_COMP_TMINH               _NB_COMP_TMIN.Overlap_STR.NB_COMP_TMINHSTR.Byte
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TCMIN       :8;                                       /* Minimum Temperature before recalibration */
  } Bits;
} NB_COMP_TMINSTR;
extern volatile NB_COMP_TMINSTR _NB_COMP_TMIN @0x00000FA6;
#define NB_COMP_TMIN                    _NB_COMP_TMIN.Word
#define NB_COMP_TMIN_TCMIN              _NB_COMP_TMIN.Bits.TCMIN

#define NB_COMP_TMIN_TCMIN_MASK         65280U
#define NB_COMP_TMIN_TCMIN_BITNUM       8U


/*** NB_COMP_VO - Offset voltage compensation; 0x00000FAA ***/
typedef union {
  byte Byte;
} NB_COMP_VOSTR;
extern volatile NB_COMP_VOSTR _NB_COMP_VO @0x00000FAA;
#define NB_COMP_VO                      _NB_COMP_VO.Byte


/*** NB_COMP_IO - Offset current compensation window; 0x00000FAB ***/
typedef union {
  byte Byte;
} NB_COMP_IOSTR;
extern volatile NB_COMP_IOSTR _NB_COMP_IO @0x00000FAB;
#define NB_COMP_IO                      _NB_COMP_IO.Byte


/*** NB_COMP_VSG - Gain voltage compensation vsense channel; 0x00000FAC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_VSGH - Gain voltage compensation vsense channel high; 0x00000FAC ***/
    union {
      byte Byte;
      struct {
        byte VSGC        :2;                                       /* Voltage Channel Gain Compensation Buffer */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_VSGHSTR;
    #define NB_COMP_VSGH                _NB_COMP_VSG.Overlap_STR.NB_COMP_VSGHSTR.Byte
    #define NB_COMP_VSGH_VSGC           _NB_COMP_VSG.Overlap_STR.NB_COMP_VSGHSTR.Bits.VSGC
    
    #define NB_COMP_VSGH_VSGC_MASK      3U
    #define NB_COMP_VSGH_VSGC_BITNUM    0U
    

    /*** NB_COMP_VSGL - Gain voltage compensation vsense channel low; 0x00000FAD ***/
    union {
      byte Byte;
    } NB_COMP_VSGLSTR;
    #define NB_COMP_VSGL                _NB_COMP_VSG.Overlap_STR.NB_COMP_VSGLSTR.Byte
    
  } Overlap_STR;

  struct {
    word VSGC        :10;                                      /* Voltage Channel Gain Compensation Buffer */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_VSGSTR;
extern volatile NB_COMP_VSGSTR _NB_COMP_VSG @0x00000FAC;
#define NB_COMP_VSG                     _NB_COMP_VSG.Word
#define NB_COMP_VSG_VSGC                _NB_COMP_VSG.Bits.VSGC

#define NB_COMP_VSG_VSGC_MASK           1023U
#define NB_COMP_VSG_VSGC_BITNUM         0U


/*** NB_COMP_TVSG - Voltage Gain temp compensation; 0x00000FAE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_TVSGH - Voltage Gain temp compensation above 25 C; 0x00000FAE ***/
    union {
      byte Byte;
      struct {
        byte TVSGCP      :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_TVSGHSTR;
    #define NB_COMP_TVSGH               _NB_COMP_TVSG.Overlap_STR.NB_COMP_TVSGHSTR.Byte
    #define NB_COMP_TVSGH_TVSGCP        _NB_COMP_TVSG.Overlap_STR.NB_COMP_TVSGHSTR.Bits.TVSGCP
    
    #define NB_COMP_TVSGH_TVSGCP_MASK   31U
    #define NB_COMP_TVSGH_TVSGCP_BITNUM 0U
    

    /*** NB_COMP_TVSGL - Voltage Gain temp compensation below 25 C; 0x00000FAF ***/
    union {
      byte Byte;
      struct {
        byte TVSGCN      :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_TVSGLSTR;
    #define NB_COMP_TVSGL               _NB_COMP_TVSG.Overlap_STR.NB_COMP_TVSGLSTR.Byte
    #define NB_COMP_TVSGL_TVSGCN        _NB_COMP_TVSG.Overlap_STR.NB_COMP_TVSGLSTR.Bits.TVSGCN
    
    #define NB_COMP_TVSGL_TVSGCN_MASK   31U
    #define NB_COMP_TVSGL_TVSGCN_BITNUM 0U
    
  } Overlap_STR;

  struct {
    word TVSGCN      :5; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TVSGCP      :5; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_TVSGSTR;
extern volatile NB_COMP_TVSGSTR _NB_COMP_TVSG @0x00000FAE;
#define NB_COMP_TVSG                    _NB_COMP_TVSG.Word
#define NB_COMP_TVSG_TVSGCN             _NB_COMP_TVSG.Bits.TVSGCN
#define NB_COMP_TVSG_TVSGCP             _NB_COMP_TVSG.Bits.TVSGCP

#define NB_COMP_TVSG_TVSGCN_MASK        31U
#define NB_COMP_TVSG_TVSGCN_BITNUM      0U
#define NB_COMP_TVSG_TVSGCP_MASK        7936U
#define NB_COMP_TVSG_TVSGCP_BITNUM      8U


/*** NB_COMP_IG4 - Gain Current Compensation 4; 0x00000FB0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_IG4H - Gain Current Compensation 4 high byte; 0x00000FB0 ***/
    union {
      byte Byte;
      struct {
        byte IGC4        :2;                                       /* Current Gain Compensation Buffer 4 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_IG4HSTR;
    #define NB_COMP_IG4H                _NB_COMP_IG4.Overlap_STR.NB_COMP_IG4HSTR.Byte
    #define NB_COMP_IG4H_IGC4           _NB_COMP_IG4.Overlap_STR.NB_COMP_IG4HSTR.Bits.IGC4
    
    #define NB_COMP_IG4H_IGC4_MASK      3U
    #define NB_COMP_IG4H_IGC4_BITNUM    0U
    

    /*** NB_COMP_IG4L - Gain Current Compensation 4 low byte; 0x00000FB1 ***/
    union {
      byte Byte;
    } NB_COMP_IG4LSTR;
    #define NB_COMP_IG4L                _NB_COMP_IG4.Overlap_STR.NB_COMP_IG4LSTR.Byte
    
  } Overlap_STR;

  struct {
    word IGC4        :10;                                      /* Current Gain Compensation Buffer 4 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_IG4STR;
extern volatile NB_COMP_IG4STR _NB_COMP_IG4 @0x00000FB0;
#define NB_COMP_IG4                     _NB_COMP_IG4.Word
#define NB_COMP_IG4_IGC4                _NB_COMP_IG4.Bits.IGC4

#define NB_COMP_IG4_IGC4_MASK           1023U
#define NB_COMP_IG4_IGC4_BITNUM         0U


/*** NB_COMP_TIG4 - Current Gain temp compensation; 0x00000FB2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_TIG4H - Current Gain temp compensation above 25 C; 0x00000FB2 ***/
    union {
      byte Byte;
      struct {
        byte TIGC4P      :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_TIG4HSTR;
    #define NB_COMP_TIG4H               _NB_COMP_TIG4.Overlap_STR.NB_COMP_TIG4HSTR.Byte
    #define NB_COMP_TIG4H_TIGC4P        _NB_COMP_TIG4.Overlap_STR.NB_COMP_TIG4HSTR.Bits.TIGC4P
    
    #define NB_COMP_TIG4H_TIGC4P_MASK   31U
    #define NB_COMP_TIG4H_TIGC4P_BITNUM 0U
    

    /*** NB_COMP_TIG4L - Current Gain temp compensation below 25 C; 0x00000FB3 ***/
    union {
      byte Byte;
      struct {
        byte TIGC4N      :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_TIG4LSTR;
    #define NB_COMP_TIG4L               _NB_COMP_TIG4.Overlap_STR.NB_COMP_TIG4LSTR.Byte
    #define NB_COMP_TIG4L_TIGC4N        _NB_COMP_TIG4.Overlap_STR.NB_COMP_TIG4LSTR.Bits.TIGC4N
    
    #define NB_COMP_TIG4L_TIGC4N_MASK   31U
    #define NB_COMP_TIG4L_TIGC4N_BITNUM 0U
    
  } Overlap_STR;

  struct {
    word TIGC4N      :5; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TIGC4P      :5; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_TIG4STR;
extern volatile NB_COMP_TIG4STR _NB_COMP_TIG4 @0x00000FB2;
#define NB_COMP_TIG4                    _NB_COMP_TIG4.Word
#define NB_COMP_TIG4_TIGC4N             _NB_COMP_TIG4.Bits.TIGC4N
#define NB_COMP_TIG4_TIGC4P             _NB_COMP_TIG4.Bits.TIGC4P

#define NB_COMP_TIG4_TIGC4N_MASK        31U
#define NB_COMP_TIG4_TIGC4N_BITNUM      0U
#define NB_COMP_TIG4_TIGC4P_MASK        7936U
#define NB_COMP_TIG4_TIGC4P_BITNUM      8U


/*** NB_COMP_IG16 - Gain Current Compensation 16; 0x00000FB4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_IG16H - Gain Current Compensation 16 high byte; 0x00000FB4 ***/
    union {
      byte Byte;
      struct {
        byte IGC16       :2;                                       /* Current Gain Compensation Buffer 16 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_IG16HSTR;
    #define NB_COMP_IG16H               _NB_COMP_IG16.Overlap_STR.NB_COMP_IG16HSTR.Byte
    #define NB_COMP_IG16H_IGC16         _NB_COMP_IG16.Overlap_STR.NB_COMP_IG16HSTR.Bits.IGC16
    
    #define NB_COMP_IG16H_IGC16_MASK    3U
    #define NB_COMP_IG16H_IGC16_BITNUM  0U
    

    /*** NB_COMP_IG16L - Gain Current Compensation 16 low byte; 0x00000FB5 ***/
    union {
      byte Byte;
    } NB_COMP_IG16LSTR;
    #define NB_COMP_IG16L               _NB_COMP_IG16.Overlap_STR.NB_COMP_IG16LSTR.Byte
    
  } Overlap_STR;

  struct {
    word IGC16       :10;                                      /* Current Gain Compensation Buffer 16 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_IG16STR;
extern volatile NB_COMP_IG16STR _NB_COMP_IG16 @0x00000FB4;
#define NB_COMP_IG16                    _NB_COMP_IG16.Word
#define NB_COMP_IG16_IGC16              _NB_COMP_IG16.Bits.IGC16

#define NB_COMP_IG16_IGC16_MASK         1023U
#define NB_COMP_IG16_IGC16_BITNUM       0U


/*** NB_COMP_TIG16 - Current Gain temp compensation; 0x00000FB6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_TIG16H - Current Gain temp compensation above 25 C; 0x00000FB6 ***/
    union {
      byte Byte;
      struct {
        byte TIGC16P     :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_TIG16HSTR;
    #define NB_COMP_TIG16H              _NB_COMP_TIG16.Overlap_STR.NB_COMP_TIG16HSTR.Byte
    #define NB_COMP_TIG16H_TIGC16P      _NB_COMP_TIG16.Overlap_STR.NB_COMP_TIG16HSTR.Bits.TIGC16P
    
    #define NB_COMP_TIG16H_TIGC16P_MASK 31U
    #define NB_COMP_TIG16H_TIGC16P_BITNUM 0U
    

    /*** NB_COMP_TIG16L - Current Gain temp compensation below 25 C; 0x00000FB7 ***/
    union {
      byte Byte;
      struct {
        byte TIGC16N     :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_TIG16LSTR;
    #define NB_COMP_TIG16L              _NB_COMP_TIG16.Overlap_STR.NB_COMP_TIG16LSTR.Byte
    #define NB_COMP_TIG16L_TIGC16N      _NB_COMP_TIG16.Overlap_STR.NB_COMP_TIG16LSTR.Bits.TIGC16N
    
    #define NB_COMP_TIG16L_TIGC16N_MASK 31U
    #define NB_COMP_TIG16L_TIGC16N_BITNUM 0U
    
  } Overlap_STR;

  struct {
    word TIGC16N     :5; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TIGC16P     :5; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_TIG16STR;
extern volatile NB_COMP_TIG16STR _NB_COMP_TIG16 @0x00000FB6;
#define NB_COMP_TIG16                   _NB_COMP_TIG16.Word
#define NB_COMP_TIG16_TIGC16N           _NB_COMP_TIG16.Bits.TIGC16N
#define NB_COMP_TIG16_TIGC16P           _NB_COMP_TIG16.Bits.TIGC16P

#define NB_COMP_TIG16_TIGC16N_MASK      31U
#define NB_COMP_TIG16_TIGC16N_BITNUM    0U
#define NB_COMP_TIG16_TIGC16P_MASK      7936U
#define NB_COMP_TIG16_TIGC16P_BITNUM    8U


/*** NB_COMP_IG64 - Gain Current Compensation 64; 0x00000FB8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_IG64H - Gain Current Compensation 64 high byte; 0x00000FB8 ***/
    union {
      byte Byte;
      struct {
        byte IGC64       :2;                                       /* Current Gain Compensation Buffer 64 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_IG64HSTR;
    #define NB_COMP_IG64H               _NB_COMP_IG64.Overlap_STR.NB_COMP_IG64HSTR.Byte
    #define NB_COMP_IG64H_IGC64         _NB_COMP_IG64.Overlap_STR.NB_COMP_IG64HSTR.Bits.IGC64
    
    #define NB_COMP_IG64H_IGC64_MASK    3U
    #define NB_COMP_IG64H_IGC64_BITNUM  0U
    

    /*** NB_COMP_IG64L - Gain Current Compensation 64 low byte; 0x00000FB9 ***/
    union {
      byte Byte;
    } NB_COMP_IG64LSTR;
    #define NB_COMP_IG64L               _NB_COMP_IG64.Overlap_STR.NB_COMP_IG64LSTR.Byte
    
  } Overlap_STR;

  struct {
    word IGC64       :10;                                      /* Current Gain Compensation Buffer 64 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_IG64STR;
extern volatile NB_COMP_IG64STR _NB_COMP_IG64 @0x00000FB8;
#define NB_COMP_IG64                    _NB_COMP_IG64.Word
#define NB_COMP_IG64_IGC64              _NB_COMP_IG64.Bits.IGC64

#define NB_COMP_IG64_IGC64_MASK         1023U
#define NB_COMP_IG64_IGC64_BITNUM       0U


/*** NB_COMP_TIG64 - Current Gain temp compensation; 0x00000FBA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_TIG64H - Current Gain temp compensation above 25 C; 0x00000FBA ***/
    union {
      byte Byte;
      struct {
        byte TIGC64P     :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_TIG64HSTR;
    #define NB_COMP_TIG64H              _NB_COMP_TIG64.Overlap_STR.NB_COMP_TIG64HSTR.Byte
    #define NB_COMP_TIG64H_TIGC64P      _NB_COMP_TIG64.Overlap_STR.NB_COMP_TIG64HSTR.Bits.TIGC64P
    
    #define NB_COMP_TIG64H_TIGC64P_MASK 31U
    #define NB_COMP_TIG64H_TIGC64P_BITNUM 0U
    

    /*** NB_COMP_TIG64L - Current Gain temp compensation below 25 C; 0x00000FBB ***/
    union {
      byte Byte;
      struct {
        byte TIGC64N     :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_TIG64LSTR;
    #define NB_COMP_TIG64L              _NB_COMP_TIG64.Overlap_STR.NB_COMP_TIG64LSTR.Byte
    #define NB_COMP_TIG64L_TIGC64N      _NB_COMP_TIG64.Overlap_STR.NB_COMP_TIG64LSTR.Bits.TIGC64N
    
    #define NB_COMP_TIG64L_TIGC64N_MASK 31U
    #define NB_COMP_TIG64L_TIGC64N_BITNUM 0U
    
  } Overlap_STR;

  struct {
    word TIGC64N     :5; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TIGC64P     :5; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_TIG64STR;
extern volatile NB_COMP_TIG64STR _NB_COMP_TIG64 @0x00000FBA;
#define NB_COMP_TIG64                   _NB_COMP_TIG64.Word
#define NB_COMP_TIG64_TIGC64N           _NB_COMP_TIG64.Bits.TIGC64N
#define NB_COMP_TIG64_TIGC64P           _NB_COMP_TIG64.Bits.TIGC64P

#define NB_COMP_TIG64_TIGC64N_MASK      31U
#define NB_COMP_TIG64_TIGC64N_BITNUM    0U
#define NB_COMP_TIG64_TIGC64P_MASK      7936U
#define NB_COMP_TIG64_TIGC64P_BITNUM    8U


/*** NB_COMP_IG256 - Gain Current Compensation 256; 0x00000FBC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_IG256H - Gain Current Compensation 256 high byte; 0x00000FBC ***/
    union {
      byte Byte;
      struct {
        byte IGC256      :2;                                       /* Current Gain Compensation Buffer 256 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_IG256HSTR;
    #define NB_COMP_IG256H              _NB_COMP_IG256.Overlap_STR.NB_COMP_IG256HSTR.Byte
    #define NB_COMP_IG256H_IGC256       _NB_COMP_IG256.Overlap_STR.NB_COMP_IG256HSTR.Bits.IGC256
    
    #define NB_COMP_IG256H_IGC256_MASK  3U
    #define NB_COMP_IG256H_IGC256_BITNUM 0U
    

    /*** NB_COMP_IG256L - Gain Current Compensation 256 low byte; 0x00000FBD ***/
    union {
      byte Byte;
    } NB_COMP_IG256LSTR;
    #define NB_COMP_IG256L              _NB_COMP_IG256.Overlap_STR.NB_COMP_IG256LSTR.Byte
    
  } Overlap_STR;

  struct {
    word IGC256      :10;                                      /* Current Gain Compensation Buffer 256 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_IG256STR;
extern volatile NB_COMP_IG256STR _NB_COMP_IG256 @0x00000FBC;
#define NB_COMP_IG256                   _NB_COMP_IG256.Word
#define NB_COMP_IG256_IGC256            _NB_COMP_IG256.Bits.IGC256

#define NB_COMP_IG256_IGC256_MASK       1023U
#define NB_COMP_IG256_IGC256_BITNUM     0U


/*** NB_COMP_TIG256 - Current Gain temp compensation; 0x00000FBE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_TIG256H - Current Gain temp compensation above 25 C; 0x00000FBE ***/
    union {
      byte Byte;
      struct {
        byte TIGC256P    :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_TIG256HSTR;
    #define NB_COMP_TIG256H             _NB_COMP_TIG256.Overlap_STR.NB_COMP_TIG256HSTR.Byte
    #define NB_COMP_TIG256H_TIGC256P    _NB_COMP_TIG256.Overlap_STR.NB_COMP_TIG256HSTR.Bits.TIGC256P
    
    #define NB_COMP_TIG256H_TIGC256P_MASK 31U
    #define NB_COMP_TIG256H_TIGC256P_BITNUM 0U
    

    /*** NB_COMP_TIG256L - Current Gain temp compensation below 25 C; 0x00000FBF ***/
    union {
      byte Byte;
      struct {
        byte TIGC256N    :5; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_TIG256LSTR;
    #define NB_COMP_TIG256L             _NB_COMP_TIG256.Overlap_STR.NB_COMP_TIG256LSTR.Byte
    #define NB_COMP_TIG256L_TIGC256N    _NB_COMP_TIG256.Overlap_STR.NB_COMP_TIG256LSTR.Bits.TIGC256N
    
    #define NB_COMP_TIG256L_TIGC256N_MASK 31U
    #define NB_COMP_TIG256L_TIGC256N_BITNUM 0U
    
  } Overlap_STR;

  struct {
    word TIGC256N    :5; 
    word             :1; 
    word             :1; 
    word             :1; 
    word TIGC256P    :5; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_TIG256STR;
extern volatile NB_COMP_TIG256STR _NB_COMP_TIG256 @0x00000FBE;
#define NB_COMP_TIG256                  _NB_COMP_TIG256.Word
#define NB_COMP_TIG256_TIGC256N         _NB_COMP_TIG256.Bits.TIGC256N
#define NB_COMP_TIG256_TIGC256P         _NB_COMP_TIG256.Bits.TIGC256P

#define NB_COMP_TIG256_TIGC256N_MASK    31U
#define NB_COMP_TIG256_TIGC256N_BITNUM  0U
#define NB_COMP_TIG256_TIGC256P_MASK    7936U
#define NB_COMP_TIG256_TIGC256P_BITNUM  8U


/*** NB_COMP_PGAO4 - Offset PGA compensation 4; 0x00000FC0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_PGAO4H - Offset PGA compensation 4 high byte; 0x00000FC0 ***/
    union {
      byte Byte;
      struct {
        byte PGAOC4      :3;                                       /* PGA Offset Compensation Buffer 4 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_PGAO4HSTR;
    #define NB_COMP_PGAO4H              _NB_COMP_PGAO4.Overlap_STR.NB_COMP_PGAO4HSTR.Byte
    #define NB_COMP_PGAO4H_PGAOC4       _NB_COMP_PGAO4.Overlap_STR.NB_COMP_PGAO4HSTR.Bits.PGAOC4
    
    #define NB_COMP_PGAO4H_PGAOC4_MASK  7U
    #define NB_COMP_PGAO4H_PGAOC4_BITNUM 0U
    

    /*** NB_COMP_PGAO4L - Offset PGA compensation 4 low byte; 0x00000FC1 ***/
    union {
      byte Byte;
    } NB_COMP_PGAO4LSTR;
    #define NB_COMP_PGAO4L              _NB_COMP_PGAO4.Overlap_STR.NB_COMP_PGAO4LSTR.Byte
    
  } Overlap_STR;

  struct {
    word PGAOC4      :11;                                      /* PGA Offset Compensation Buffer 4 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_PGAO4STR;
extern volatile NB_COMP_PGAO4STR _NB_COMP_PGAO4 @0x00000FC0;
#define NB_COMP_PGAO4                   _NB_COMP_PGAO4.Word
#define NB_COMP_PGAO4_PGAOC4            _NB_COMP_PGAO4.Bits.PGAOC4

#define NB_COMP_PGAO4_PGAOC4_MASK       2047U
#define NB_COMP_PGAO4_PGAOC4_BITNUM     0U


/*** NB_COMP_PGAO16 - Offset PGA compensation 16; 0x00000FC4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_PGAO16H - Offset PGA compensation 16 high byte; 0x00000FC4 ***/
    union {
      byte Byte;
      struct {
        byte PGAOC16     :3;                                       /* PGA Offset Compensation Buffer 16 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_PGAO16HSTR;
    #define NB_COMP_PGAO16H             _NB_COMP_PGAO16.Overlap_STR.NB_COMP_PGAO16HSTR.Byte
    #define NB_COMP_PGAO16H_PGAOC16     _NB_COMP_PGAO16.Overlap_STR.NB_COMP_PGAO16HSTR.Bits.PGAOC16
    
    #define NB_COMP_PGAO16H_PGAOC16_MASK 7U
    #define NB_COMP_PGAO16H_PGAOC16_BITNUM 0U
    

    /*** NB_COMP_PGAO16L - Offset PGA compensation 16 low byte; 0x00000FC5 ***/
    union {
      byte Byte;
    } NB_COMP_PGAO16LSTR;
    #define NB_COMP_PGAO16L             _NB_COMP_PGAO16.Overlap_STR.NB_COMP_PGAO16LSTR.Byte
    
  } Overlap_STR;

  struct {
    word PGAOC16     :11;                                      /* PGA Offset Compensation Buffer 16 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_PGAO16STR;
extern volatile NB_COMP_PGAO16STR _NB_COMP_PGAO16 @0x00000FC4;
#define NB_COMP_PGAO16                  _NB_COMP_PGAO16.Word
#define NB_COMP_PGAO16_PGAOC16          _NB_COMP_PGAO16.Bits.PGAOC16

#define NB_COMP_PGAO16_PGAOC16_MASK     2047U
#define NB_COMP_PGAO16_PGAOC16_BITNUM   0U


/*** NB_COMP_PGAO64 - Offset PGA compensation 64; 0x00000FC8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_PGAO64H - Offset PGA compensation 64 high byte; 0x00000FC8 ***/
    union {
      byte Byte;
      struct {
        byte PGAOC64     :3;                                       /* PGA Offset Compensation Buffer 64 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_PGAO64HSTR;
    #define NB_COMP_PGAO64H             _NB_COMP_PGAO64.Overlap_STR.NB_COMP_PGAO64HSTR.Byte
    #define NB_COMP_PGAO64H_PGAOC64     _NB_COMP_PGAO64.Overlap_STR.NB_COMP_PGAO64HSTR.Bits.PGAOC64
    
    #define NB_COMP_PGAO64H_PGAOC64_MASK 7U
    #define NB_COMP_PGAO64H_PGAOC64_BITNUM 0U
    

    /*** NB_COMP_PGAO64L - Offset PGA compensation 64 low byte; 0x00000FC9 ***/
    union {
      byte Byte;
    } NB_COMP_PGAO64LSTR;
    #define NB_COMP_PGAO64L             _NB_COMP_PGAO64.Overlap_STR.NB_COMP_PGAO64LSTR.Byte
    
  } Overlap_STR;

  struct {
    word PGAOC64     :11;                                      /* PGA Offset Compensation Buffer 64 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_PGAO64STR;
extern volatile NB_COMP_PGAO64STR _NB_COMP_PGAO64 @0x00000FC8;
#define NB_COMP_PGAO64                  _NB_COMP_PGAO64.Word
#define NB_COMP_PGAO64_PGAOC64          _NB_COMP_PGAO64.Bits.PGAOC64

#define NB_COMP_PGAO64_PGAOC64_MASK     2047U
#define NB_COMP_PGAO64_PGAOC64_BITNUM   0U


/*** NB_COMP_PGAO256 - Offset PGA compensation 256; 0x00000FCC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NB_COMP_PGAO256H - Offset PGA compensation 256 high byte; 0x00000FCC ***/
    union {
      byte Byte;
      struct {
        byte PGAOC256    :3;                                       /* PGA Offset Compensation Buffer 256 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } NB_COMP_PGAO256HSTR;
    #define NB_COMP_PGAO256H            _NB_COMP_PGAO256.Overlap_STR.NB_COMP_PGAO256HSTR.Byte
    #define NB_COMP_PGAO256H_PGAOC256   _NB_COMP_PGAO256.Overlap_STR.NB_COMP_PGAO256HSTR.Bits.PGAOC256
    
    #define NB_COMP_PGAO256H_PGAOC256_MASK 7U
    #define NB_COMP_PGAO256H_PGAOC256_BITNUM 0U
    

    /*** NB_COMP_PGAO256L - Offset PGA compensation 256 low byte; 0x00000FCD ***/
    union {
      byte Byte;
    } NB_COMP_PGAO256LSTR;
    #define NB_COMP_PGAO256L            _NB_COMP_PGAO256.Overlap_STR.NB_COMP_PGAO256LSTR.Byte
    
  } Overlap_STR;

  struct {
    word PGAOC256    :11;                                      /* PGA Offset Compensation Buffer 256 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} NB_COMP_PGAO256STR;
extern volatile NB_COMP_PGAO256STR _NB_COMP_PGAO256 @0x00000FCC;
#define NB_COMP_PGAO256                 _NB_COMP_PGAO256.Word
#define NB_COMP_PGAO256_PGAOC256        _NB_COMP_PGAO256.Bits.PGAOC256

#define NB_COMP_PGAO256_PGAOC256_MASK   2047U
#define NB_COMP_PGAO256_PGAOC256_BITNUM 0U


/*** NB_COMP_ITO - Internal temperature offset compensation; 0x00000FD0 ***/
typedef union {
  byte Byte;
} NB_COMP_ITOSTR;
extern volatile NB_COMP_ITOSTR _NB_COMP_ITO @0x00000FD0;
#define NB_COMP_ITO                     _NB_COMP_ITO.Byte


/*** NB_COMP_ITG - Internal temperature gain compensation; 0x00000FD1 ***/
typedef union {
  byte Byte;
} NB_COMP_ITGSTR;
extern volatile NB_COMP_ITGSTR _NB_COMP_ITG @0x00000FD1;
#define NB_COMP_ITG                     _NB_COMP_ITG.Byte


/*** NB_COMP_ETO - External temperature offset compensation; 0x00000FD2 ***/
typedef union {
  byte Byte;
} NB_COMP_ETOSTR;
extern volatile NB_COMP_ETOSTR _NB_COMP_ETO @0x00000FD2;
#define NB_COMP_ETO                     _NB_COMP_ETO.Byte


/*** NB_COMP_ETG - External temperature gain compensation; 0x00000FD3 ***/
typedef union {
  byte Byte;
} NB_COMP_ETGSTR;
extern volatile NB_COMP_ETGSTR _NB_COMP_ETG @0x00000FD3;
#define NB_COMP_ETG                     _NB_COMP_ETG.Byte


/*** NB_TRIM_BG0H - Trim bandgap 0 high; 0x00000FE0 ***/
typedef union {
  byte Byte;
  struct {
    byte TCIBG1      :3; 
    byte TCIBG2      :3; 
    byte IBG1        :2; 
  } Bits;
} NB_TRIM_BG0HSTR;
extern volatile NB_TRIM_BG0HSTR _NB_TRIM_BG0H @0x00000FE0;
#define NB_TRIM_BG0H                    _NB_TRIM_BG0H.Byte
#define NB_TRIM_BG0H_TCIBG1             _NB_TRIM_BG0H.Bits.TCIBG1
#define NB_TRIM_BG0H_TCIBG2             _NB_TRIM_BG0H.Bits.TCIBG2
#define NB_TRIM_BG0H_IBG1               _NB_TRIM_BG0H.Bits.IBG1

#define NB_TRIM_BG0H_TCIBG1_MASK        7U
#define NB_TRIM_BG0H_TCIBG1_BITNUM      0U
#define NB_TRIM_BG0H_TCIBG2_MASK        56U
#define NB_TRIM_BG0H_TCIBG2_BITNUM      3U
#define NB_TRIM_BG0H_IBG1_MASK          192U
#define NB_TRIM_BG0H_IBG1_BITNUM        6U


/*** NB_TRIM_BG0L - Trim bandgap 0 low; 0x00000FE1 ***/
typedef union {
  byte Byte;
  struct {
    byte TCBG1       :3; 
    byte TCBG2       :3; 
    byte LVT         :1; 
    byte IBG1        :1; 
  } Bits;
} NB_TRIM_BG0LSTR;
extern volatile NB_TRIM_BG0LSTR _NB_TRIM_BG0L @0x00000FE1;
#define NB_TRIM_BG0L                    _NB_TRIM_BG0L.Byte
#define NB_TRIM_BG0L_TCBG1              _NB_TRIM_BG0L.Bits.TCBG1
#define NB_TRIM_BG0L_TCBG2              _NB_TRIM_BG0L.Bits.TCBG2
#define NB_TRIM_BG0L_LVT                _NB_TRIM_BG0L.Bits.LVT
#define NB_TRIM_BG0L_IBG1               _NB_TRIM_BG0L.Bits.IBG1

#define NB_TRIM_BG0L_TCBG1_MASK         7U
#define NB_TRIM_BG0L_TCBG1_BITNUM       0U
#define NB_TRIM_BG0L_TCBG2_MASK         56U
#define NB_TRIM_BG0L_TCBG2_BITNUM       3U
#define NB_TRIM_BG0L_LVT_MASK           64U
#define NB_TRIM_BG0L_IBG1_MASK          128U


/*** NB_TRIM_BG1H - Trim bandgap 1 high; 0x00000FE2 ***/
typedef union {
  byte Byte;
  struct {
    byte V1P2BG1     :4; 
    byte V1P2BG2     :4; 
  } Bits;
} NB_TRIM_BG1HSTR;
extern volatile NB_TRIM_BG1HSTR _NB_TRIM_BG1H @0x00000FE2;
#define NB_TRIM_BG1H                    _NB_TRIM_BG1H.Byte
#define NB_TRIM_BG1H_V1P2BG1            _NB_TRIM_BG1H.Bits.V1P2BG1
#define NB_TRIM_BG1H_V1P2BG2            _NB_TRIM_BG1H.Bits.V1P2BG2

#define NB_TRIM_BG1H_V1P2BG1_MASK       15U
#define NB_TRIM_BG1H_V1P2BG1_BITNUM     0U
#define NB_TRIM_BG1H_V1P2BG2_MASK       240U
#define NB_TRIM_BG1H_V1P2BG2_BITNUM     4U


/*** NB_TRIM_BG1L - Trim bandgap 1 low; 0x00000FE3 ***/
typedef union {
  byte Byte;
  struct {
    byte V2P5BG1     :4; 
    byte VDDXLPMODE  :4; 
  } Bits;
} NB_TRIM_BG1LSTR;
extern volatile NB_TRIM_BG1LSTR _NB_TRIM_BG1L @0x00000FE3;
#define NB_TRIM_BG1L                    _NB_TRIM_BG1L.Byte
#define NB_TRIM_BG1L_V2P5BG1            _NB_TRIM_BG1L.Bits.V2P5BG1
#define NB_TRIM_BG1L_VDDXLPMODE         _NB_TRIM_BG1L.Bits.VDDXLPMODE

#define NB_TRIM_BG1L_V2P5BG1_MASK       15U
#define NB_TRIM_BG1L_V2P5BG1_BITNUM     0U
#define NB_TRIM_BG1L_VDDXLPMODE_MASK    240U
#define NB_TRIM_BG1L_VDDXLPMODE_BITNUM  4U


/*** NB_TRIM_OSCH - Trim LP oscillator high; 0x00000FE4 ***/
typedef union {
  byte Byte;
  struct {
    byte LPOSC       :5; 
    byte SLPBG       :3; 
  } Bits;
} NB_TRIM_OSCHSTR;
extern volatile NB_TRIM_OSCHSTR _NB_TRIM_OSCH @0x00000FE4;
#define NB_TRIM_OSCH                    _NB_TRIM_OSCH.Byte
#define NB_TRIM_OSCH_LPOSC              _NB_TRIM_OSCH.Bits.LPOSC
#define NB_TRIM_OSCH_SLPBG              _NB_TRIM_OSCH.Bits.SLPBG

#define NB_TRIM_OSCH_LPOSC_MASK         31U
#define NB_TRIM_OSCH_LPOSC_BITNUM       0U
#define NB_TRIM_OSCH_SLPBG_MASK         224U
#define NB_TRIM_OSCH_SLPBG_BITNUM       5U


/*** NB_TRIM_OSCL - Trim LP oscillator low; 0x00000FE5 ***/
typedef union {
  byte Byte;
} NB_TRIM_OSCLSTR;
extern volatile NB_TRIM_OSCLSTR _NB_TRIM_OSCL @0x00000FE5;
#define NB_TRIM_OSCL                    _NB_TRIM_OSCL.Byte


/* * * * *  24-BIT ADDRESS REGISTERS  * * * * * * * * * * * * * * * * * * * * * * */
extern volatile void* volatile MMCPC @0x00000085;          /* Captured S12ZCPU Program Counter Low; 0x00000087 */
extern volatile void* volatile DBGAA @0x00000115;          /* Debug Comparator A Address Register Low; 0x00000117 */
extern volatile void* volatile DBGBA @0x00000125;          /* Debug Comparator B Address Register Low; 0x00000127 */
extern volatile void* volatile DBGCA @0x00000135;          /* Debug Comparator C Address Register Low; 0x00000137 */
extern volatile void* volatile DBGDA @0x00000145;          /* Debug Comparator D Address Register Low; 0x00000147 */
extern volatile void* volatile ECCDPTR @0x000003C7;        /* ECC Debug Point Register Low; 0x000003C9 */


  /* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (CPMUARMCOP = 0x55U, CPMUARMCOP = 0xAAU)
#endif
#endif /* __RESET_WATCHDOG */


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */

/* **** 11/21/2012, 9:47 AM */

#define PTE                              PTB
#define PTE_PTE0                         PTB_PTB0
#define PTE_PTE1                         PTB_PTB1
#define PTE_PTE                          PTB_PTB
#define PTE_PTE0_MASK                    PTB_PTB0_MASK
#define PTE_PTE1_MASK                    PTB_PTB1_MASK
#define PTE_PTE_MASK                     PTB_PTB_MASK
#define PTE_PTE_BITNUM                   PTB_PTB_BITNUM
#define PTIE                             PTIB
#define PTIE_PTIE0                       PTIB_PTIB0
#define PTIE_PTIE1                       PTIB_PTIB1
#define PTIE_PTIE                        PTIB_PTIB
#define PTIE_PTIE0_MASK                  PTIB_PTIB0_MASK
#define PTIE_PTIE1_MASK                  PTIB_PTIB1_MASK
#define PTIE_PTIE_MASK                   PTIB_PTIB_MASK
#define PTIE_PTIE_BITNUM                 PTIB_PTIB_BITNUM
#define DDRE                             DDRB
#define DDRE_DDRE0                       DDRB_DDRB0
#define DDRE_DDRE1                       DDRB_DDRB1
#define DDRE_DDRE                        DDRB_DDRB
#define DDRE_DDRE0_MASK                  DDRB_DDRB0_MASK
#define DDRE_DDRE1_MASK                  DDRB_DDRB1_MASK
#define DDRE_DDRE_MASK                   DDRB_DDRB_MASK
#define DDRE_DDRE_BITNUM                 DDRB_DDRB_BITNUM
#define PERE                             PERB
#define PERE_PERE0                       PERB_PERB0
#define PERE_PERE1                       PERB_PERB1
#define PERE_PERE                        PERB_PERB
#define PERE_PERE0_MASK                  PERB_PERB0_MASK
#define PERE_PERE1_MASK                  PERB_PERB1_MASK
#define PERE_PERE_MASK                   PERB_PERB_MASK
#define PERE_PERE_BITNUM                 PERB_PERB_BITNUM
#define PPSE                             PPSB
#define PPSE_PPSE0                       PPSB_PPSB0
#define PPSE_PPSE1                       PPSB_PPSB1
#define PPSE_PPSE                        PPSB_PPSB
#define PPSE_PPSE0_MASK                  PPSB_PPSB0_MASK
#define PPSE_PPSE1_MASK                  PPSB_PPSB1_MASK
#define PPSE_PPSE_MASK                   PPSB_PPSB_MASK
#define PPSE_PPSE_BITNUM                 PPSB_PPSB_BITNUM

#define B_LIN_CTLH_TXDM                  This_symb_has_been_depreciated
#define B_LIN_CTLH_TXDM_MASK             This_symb_has_been_depreciated
#define B_LIN_CTLL_TXD                   This_symb_has_been_depreciated
#define B_LIN_CTLL_TXD_MASK              This_symb_has_been_depreciated
#define B_LIN_CTL_TXDM                   This_symb_has_been_depreciated
#define B_LIN_CTL_TXDM_MASK              This_symb_has_been_depreciated
#define B_LIN_CTL_TXD                    This_symb_has_been_depreciated
#define B_LIN_CTL_TXD_MASK               This_symb_has_been_depreciated
#define NB_LIN_CTLH_TXDM                 This_symb_has_been_depreciated
#define NB_LIN_CTLH_TXDM_MASK            This_symb_has_been_depreciated
#define NB_LIN_CTLL_TXD                  This_symb_has_been_depreciated
#define NB_LIN_CTLL_TXD_MASK             This_symb_has_been_depreciated
#define NB_LIN_CTL_TXDM                  This_symb_has_been_depreciated
#define NB_LIN_CTL_TXDM_MASK             This_symb_has_been_depreciated
#define NB_LIN_CTL_TXD                   This_symb_has_been_depreciated
#define NB_LIN_CTL_TXD_MASK              This_symb_has_been_depreciated

#define RDRC_RDRC1                       This_symb_has_been_depreciated
#define RDRC_RDRC                        This_symb_has_been_depreciated
#define RDRC_RDRC1_MASK                  This_symb_has_been_depreciated
#define RDRC_RDRC_MASK                   This_symb_has_been_depreciated
#define RDRC_RDRC_BITNUM                 This_symb_has_been_depreciated
#define CPMUIFLG_ILAF                    This_symb_has_been_depreciated
#define CPMUIFLG_LVRF                    This_symb_has_been_depreciated
#define CPMUIFLG_PORF                    This_symb_has_been_depreciated
#define CPMUIFLG_ILAF_MASK               This_symb_has_been_depreciated
#define CPMUIFLG_LVRF_MASK               This_symb_has_been_depreciated
#define CPMUIFLG_PORF_MASK               This_symb_has_been_depreciated
#define CPMUVREGCTL                      This_symb_has_been_depreciated
#define CPMUVREGCTL_INTXON               This_symb_has_been_depreciated
#define CPMUVREGCTL_EXTXON               This_symb_has_been_depreciated
#define CPMUVREGCTL_EXTCON               This_symb_has_been_depreciated
#define CPMUVREGCTL_INTXON_MASK          This_symb_has_been_depreciated
#define CPMUVREGCTL_EXTXON_MASK          This_symb_has_been_depreciated
#define CPMUVREGCTL_EXTCON_MASK          This_symb_has_been_depreciated

#define CAN0CTL0                         CANCTL0
#define CAN0CTL0_INITRQ                  CANCTL0_INITRQ
#define CAN0CTL0_SLPRQ                   CANCTL0_SLPRQ
#define CAN0CTL0_WUPE                    CANCTL0_WUPE
#define CAN0CTL0_TIME                    CANCTL0_TIME
#define CAN0CTL0_SYNCH                   CANCTL0_SYNCH
#define CAN0CTL0_CSWAI                   CANCTL0_CSWAI
#define CAN0CTL0_RXACT                   CANCTL0_RXACT
#define CAN0CTL0_RXFRM                   CANCTL0_RXFRM
#define CAN0CTL_ARR                      CANCTL_ARR
#define CAN0CTL0_INITRQ_MASK             CANCTL0_INITRQ_MASK
#define CAN0CTL0_SLPRQ_MASK              CANCTL0_SLPRQ_MASK
#define CAN0CTL0_WUPE_MASK               CANCTL0_WUPE_MASK
#define CAN0CTL0_TIME_MASK               CANCTL0_TIME_MASK
#define CAN0CTL0_SYNCH_MASK              CANCTL0_SYNCH_MASK
#define CAN0CTL0_CSWAI_MASK              CANCTL0_CSWAI_MASK
#define CAN0CTL0_RXACT_MASK              CANCTL0_RXACT_MASK
#define CAN0CTL0_RXFRM_MASK              CANCTL0_RXFRM_MASK
#define CAN0CTL1                         CANCTL1
#define CAN0CTL1_INITAK                  CANCTL1_INITAK
#define CAN0CTL1_SLPAK                   CANCTL1_SLPAK
#define CAN0CTL1_WUPM                    CANCTL1_WUPM
#define CAN0CTL1_BORM                    CANCTL1_BORM
#define CAN0CTL1_LISTEN                  CANCTL1_LISTEN
#define CAN0CTL1_LOOPB                   CANCTL1_LOOPB
#define CAN0CTL1_CLKSRC                  CANCTL1_CLKSRC
#define CAN0CTL1_CANE                    CANCTL1_CANE
#define CAN0CTL1_INITAK_MASK             CANCTL1_INITAK_MASK
#define CAN0CTL1_SLPAK_MASK              CANCTL1_SLPAK_MASK
#define CAN0CTL1_WUPM_MASK               CANCTL1_WUPM_MASK
#define CAN0CTL1_BORM_MASK               CANCTL1_BORM_MASK
#define CAN0CTL1_LISTEN_MASK             CANCTL1_LISTEN_MASK
#define CAN0CTL1_LOOPB_MASK              CANCTL1_LOOPB_MASK
#define CAN0CTL1_CLKSRC_MASK             CANCTL1_CLKSRC_MASK
#define CAN0CTL1_CANE_MASK               CANCTL1_CANE_MASK
#define CAN0BTR0                         CANBTR0
#define CAN0BTR0_BRP0                    CANBTR0_BRP0
#define CAN0BTR0_BRP1                    CANBTR0_BRP1
#define CAN0BTR0_BRP2                    CANBTR0_BRP2
#define CAN0BTR0_BRP3                    CANBTR0_BRP3
#define CAN0BTR0_BRP4                    CANBTR0_BRP4
#define CAN0BTR0_BRP5                    CANBTR0_BRP5
#define CAN0BTR0_SJW0                    CANBTR0_SJW0
#define CAN0BTR0_SJW1                    CANBTR0_SJW1
#define CAN0BTR_ARR                      CANBTR_ARR
#define CAN0BTR0_BRP                     CANBTR0_BRP
#define CAN0BTR0_SJW                     CANBTR0_SJW
#define CAN0BTR0_BRP0_MASK               CANBTR0_BRP0_MASK
#define CAN0BTR0_BRP1_MASK               CANBTR0_BRP1_MASK
#define CAN0BTR0_BRP2_MASK               CANBTR0_BRP2_MASK
#define CAN0BTR0_BRP3_MASK               CANBTR0_BRP3_MASK
#define CAN0BTR0_BRP4_MASK               CANBTR0_BRP4_MASK
#define CAN0BTR0_BRP5_MASK               CANBTR0_BRP5_MASK
#define CAN0BTR0_SJW0_MASK               CANBTR0_SJW0_MASK
#define CAN0BTR0_SJW1_MASK               CANBTR0_SJW1_MASK
#define CAN0BTR0_BRP_MASK                CANBTR0_BRP_MASK
#define CAN0BTR0_BRP_BITNUM              CANBTR0_BRP_BITNUM
#define CAN0BTR0_SJW_MASK                CANBTR0_SJW_MASK
#define CAN0BTR0_SJW_BITNUM              CANBTR0_SJW_BITNUM
#define CAN0BTR1                         CANBTR1
#define CAN0BTR1_TSEG10                  CANBTR1_TSEG10
#define CAN0BTR1_TSEG11                  CANBTR1_TSEG11
#define CAN0BTR1_TSEG12                  CANBTR1_TSEG12
#define CAN0BTR1_TSEG13                  CANBTR1_TSEG13
#define CAN0BTR1_TSEG20                  CANBTR1_TSEG20
#define CAN0BTR1_TSEG21                  CANBTR1_TSEG21
#define CAN0BTR1_TSEG22                  CANBTR1_TSEG22
#define CAN0BTR1_SAMP                    CANBTR1_SAMP
#define CAN0BTR1_TSEG_10                 CANBTR1_TSEG_10
#define CAN0BTR1_TSEG_20                 CANBTR1_TSEG_20
#define CAN0BTR1_TSEG                    CANBTR1_TSEG
#define CAN0BTR1_TSEG10_MASK             CANBTR1_TSEG10_MASK
#define CAN0BTR1_TSEG11_MASK             CANBTR1_TSEG11_MASK
#define CAN0BTR1_TSEG12_MASK             CANBTR1_TSEG12_MASK
#define CAN0BTR1_TSEG13_MASK             CANBTR1_TSEG13_MASK
#define CAN0BTR1_TSEG20_MASK             CANBTR1_TSEG20_MASK
#define CAN0BTR1_TSEG21_MASK             CANBTR1_TSEG21_MASK
#define CAN0BTR1_TSEG22_MASK             CANBTR1_TSEG22_MASK
#define CAN0BTR1_SAMP_MASK               CANBTR1_SAMP_MASK
#define CAN0BTR1_TSEG_10_MASK            CANBTR1_TSEG_10_MASK
#define CAN0BTR1_TSEG_10_BITNUM          CANBTR1_TSEG_10_BITNUM
#define CAN0BTR1_TSEG_20_MASK            CANBTR1_TSEG_20_MASK
#define CAN0BTR1_TSEG_20_BITNUM          CANBTR1_TSEG_20_BITNUM
#define CAN0RFLG                         CANRFLG
#define CAN0RFLG_RXF                     CANRFLG_RXF
#define CAN0RFLG_OVRIF                   CANRFLG_OVRIF
#define CAN0RFLG_TSTAT0                  CANRFLG_TSTAT0
#define CAN0RFLG_TSTAT1                  CANRFLG_TSTAT1
#define CAN0RFLG_RSTAT0                  CANRFLG_RSTAT0
#define CAN0RFLG_RSTAT1                  CANRFLG_RSTAT1
#define CAN0RFLG_CSCIF                   CANRFLG_CSCIF
#define CAN0RFLG_WUPIF                   CANRFLG_WUPIF
#define CAN0RFLG_TSTAT                   CANRFLG_TSTAT
#define CAN0RFLG_RSTAT                   CANRFLG_RSTAT
#define CAN0RFLG_RXF_MASK                CANRFLG_RXF_MASK
#define CAN0RFLG_OVRIF_MASK              CANRFLG_OVRIF_MASK
#define CAN0RFLG_TSTAT0_MASK             CANRFLG_TSTAT0_MASK
#define CAN0RFLG_TSTAT1_MASK             CANRFLG_TSTAT1_MASK
#define CAN0RFLG_RSTAT0_MASK             CANRFLG_RSTAT0_MASK
#define CAN0RFLG_RSTAT1_MASK             CANRFLG_RSTAT1_MASK
#define CAN0RFLG_CSCIF_MASK              CANRFLG_CSCIF_MASK
#define CAN0RFLG_WUPIF_MASK              CANRFLG_WUPIF_MASK
#define CAN0RFLG_TSTAT_MASK              CANRFLG_TSTAT_MASK
#define CAN0RFLG_TSTAT_BITNUM            CANRFLG_TSTAT_BITNUM
#define CAN0RFLG_RSTAT_MASK              CANRFLG_RSTAT_MASK
#define CAN0RFLG_RSTAT_BITNUM            CANRFLG_RSTAT_BITNUM
#define CAN0RIER                         CANRIER
#define CAN0RIER_RXFIE                   CANRIER_RXFIE
#define CAN0RIER_OVRIE                   CANRIER_OVRIE
#define CAN0RIER_TSTATE0                 CANRIER_TSTATE0
#define CAN0RIER_TSTATE1                 CANRIER_TSTATE1
#define CAN0RIER_RSTATE0                 CANRIER_RSTATE0
#define CAN0RIER_RSTATE1                 CANRIER_RSTATE1
#define CAN0RIER_CSCIE                   CANRIER_CSCIE
#define CAN0RIER_WUPIE                   CANRIER_WUPIE
#define CAN0RIER_TSTATE                  CANRIER_TSTATE
#define CAN0RIER_RSTATE                  CANRIER_RSTATE
#define CAN0RIER_RXFIE_MASK              CANRIER_RXFIE_MASK
#define CAN0RIER_OVRIE_MASK              CANRIER_OVRIE_MASK
#define CAN0RIER_TSTATE0_MASK            CANRIER_TSTATE0_MASK
#define CAN0RIER_TSTATE1_MASK            CANRIER_TSTATE1_MASK
#define CAN0RIER_RSTATE0_MASK            CANRIER_RSTATE0_MASK
#define CAN0RIER_RSTATE1_MASK            CANRIER_RSTATE1_MASK
#define CAN0RIER_CSCIE_MASK              CANRIER_CSCIE_MASK
#define CAN0RIER_WUPIE_MASK              CANRIER_WUPIE_MASK
#define CAN0RIER_TSTATE_MASK             CANRIER_TSTATE_MASK
#define CAN0RIER_TSTATE_BITNUM           CANRIER_TSTATE_BITNUM
#define CAN0RIER_RSTATE_MASK             CANRIER_RSTATE_MASK
#define CAN0RIER_RSTATE_BITNUM           CANRIER_RSTATE_BITNUM
#define CAN0TFLG                         CANTFLG
#define CAN0TFLG_TXE0                    CANTFLG_TXE0
#define CAN0TFLG_TXE1                    CANTFLG_TXE1
#define CAN0TFLG_TXE2                    CANTFLG_TXE2
#define CAN0TFLG_TXE                     CANTFLG_TXE
#define CAN0TFLG_TXE0_MASK               CANTFLG_TXE0_MASK
#define CAN0TFLG_TXE1_MASK               CANTFLG_TXE1_MASK
#define CAN0TFLG_TXE2_MASK               CANTFLG_TXE2_MASK
#define CAN0TFLG_TXE_MASK                CANTFLG_TXE_MASK
#define CAN0TFLG_TXE_BITNUM              CANTFLG_TXE_BITNUM
#define CAN0TIER                         CANTIER
#define CAN0TIER_TXEIE0                  CANTIER_TXEIE0
#define CAN0TIER_TXEIE1                  CANTIER_TXEIE1
#define CAN0TIER_TXEIE2                  CANTIER_TXEIE2
#define CAN0TIER_TXEIE                   CANTIER_TXEIE
#define CAN0TIER_TXEIE0_MASK             CANTIER_TXEIE0_MASK
#define CAN0TIER_TXEIE1_MASK             CANTIER_TXEIE1_MASK
#define CAN0TIER_TXEIE2_MASK             CANTIER_TXEIE2_MASK
#define CAN0TIER_TXEIE_MASK              CANTIER_TXEIE_MASK
#define CAN0TIER_TXEIE_BITNUM            CANTIER_TXEIE_BITNUM
#define CAN0TARQ                         CANTARQ
#define CAN0TARQ_ABTRQ0                  CANTARQ_ABTRQ0
#define CAN0TARQ_ABTRQ1                  CANTARQ_ABTRQ1
#define CAN0TARQ_ABTRQ2                  CANTARQ_ABTRQ2
#define CAN0TARQ_ABTRQ                   CANTARQ_ABTRQ
#define CAN0TARQ_ABTRQ0_MASK             CANTARQ_ABTRQ0_MASK
#define CAN0TARQ_ABTRQ1_MASK             CANTARQ_ABTRQ1_MASK
#define CAN0TARQ_ABTRQ2_MASK             CANTARQ_ABTRQ2_MASK
#define CAN0TARQ_ABTRQ_MASK              CANTARQ_ABTRQ_MASK
#define CAN0TARQ_ABTRQ_BITNUM            CANTARQ_ABTRQ_BITNUM
#define CAN0TAAK                         CANTAAK
#define CAN0TAAK_ABTAK0                  CANTAAK_ABTAK0
#define CAN0TAAK_ABTAK1                  CANTAAK_ABTAK1
#define CAN0TAAK_ABTAK2                  CANTAAK_ABTAK2
#define CAN0TAAK_ABTAK                   CANTAAK_ABTAK
#define CAN0TAAK_ABTAK0_MASK             CANTAAK_ABTAK0_MASK
#define CAN0TAAK_ABTAK1_MASK             CANTAAK_ABTAK1_MASK
#define CAN0TAAK_ABTAK2_MASK             CANTAAK_ABTAK2_MASK
#define CAN0TAAK_ABTAK_MASK              CANTAAK_ABTAK_MASK
#define CAN0TAAK_ABTAK_BITNUM            CANTAAK_ABTAK_BITNUM
#define CAN0TBSEL                        CANTBSEL
#define CAN0TBSEL_TX0                    CANTBSEL_TX0
#define CAN0TBSEL_TX1                    CANTBSEL_TX1
#define CAN0TBSEL_TX2                    CANTBSEL_TX2
#define CAN0TBSEL_TX                     CANTBSEL_TX
#define CAN0TBSEL_TX0_MASK               CANTBSEL_TX0_MASK
#define CAN0TBSEL_TX1_MASK               CANTBSEL_TX1_MASK
#define CAN0TBSEL_TX2_MASK               CANTBSEL_TX2_MASK
#define CAN0TBSEL_TX_MASK                CANTBSEL_TX_MASK
#define CAN0TBSEL_TX_BITNUM              CANTBSEL_TX_BITNUM
#define CAN0IDAC                         CANIDAC
#define CAN0IDAC_IDHIT0                  CANIDAC_IDHIT0
#define CAN0IDAC_IDHIT1                  CANIDAC_IDHIT1
#define CAN0IDAC_IDHIT2                  CANIDAC_IDHIT2
#define CAN0IDAC_IDAM0                   CANIDAC_IDAM0
#define CAN0IDAC_IDAM1                   CANIDAC_IDAM1
#define CAN0IDAC_IDHIT                   CANIDAC_IDHIT
#define CAN0IDAC_IDAM                    CANIDAC_IDAM
#define CAN0IDAC_IDHIT0_MASK             CANIDAC_IDHIT0_MASK
#define CAN0IDAC_IDHIT1_MASK             CANIDAC_IDHIT1_MASK
#define CAN0IDAC_IDHIT2_MASK             CANIDAC_IDHIT2_MASK
#define CAN0IDAC_IDAM0_MASK              CANIDAC_IDAM0_MASK
#define CAN0IDAC_IDAM1_MASK              CANIDAC_IDAM1_MASK
#define CAN0IDAC_IDHIT_MASK              CANIDAC_IDHIT_MASK
#define CAN0IDAC_IDHIT_BITNUM            CANIDAC_IDHIT_BITNUM
#define CAN0IDAC_IDAM_MASK               CANIDAC_IDAM_MASK
#define CAN0IDAC_IDAM_BITNUM             CANIDAC_IDAM_BITNUM
#define CAN0MISC                         CANMISC
#define CAN0MISC_BOHOLD                  CANMISC_BOHOLD
#define CAN0MISC_BOHOLD_MASK             CANMISC_BOHOLD_MASK
#define CAN0RXERR                        CANRXERR
#define CAN0RXERR_RXERR0                 CANRXERR_RXERR0
#define CAN0RXERR_RXERR1                 CANRXERR_RXERR1
#define CAN0RXERR_RXERR2                 CANRXERR_RXERR2
#define CAN0RXERR_RXERR3                 CANRXERR_RXERR3
#define CAN0RXERR_RXERR4                 CANRXERR_RXERR4
#define CAN0RXERR_RXERR5                 CANRXERR_RXERR5
#define CAN0RXERR_RXERR6                 CANRXERR_RXERR6
#define CAN0RXERR_RXERR7                 CANRXERR_RXERR7
#define CAN0RXERR_RXERR0_MASK            CANRXERR_RXERR0_MASK
#define CAN0RXERR_RXERR1_MASK            CANRXERR_RXERR1_MASK
#define CAN0RXERR_RXERR2_MASK            CANRXERR_RXERR2_MASK
#define CAN0RXERR_RXERR3_MASK            CANRXERR_RXERR3_MASK
#define CAN0RXERR_RXERR4_MASK            CANRXERR_RXERR4_MASK
#define CAN0RXERR_RXERR5_MASK            CANRXERR_RXERR5_MASK
#define CAN0RXERR_RXERR6_MASK            CANRXERR_RXERR6_MASK
#define CAN0RXERR_RXERR7_MASK            CANRXERR_RXERR7_MASK
#define CAN0TXERR                        CANTXERR
#define CAN0TXERR_TXERR0                 CANTXERR_TXERR0
#define CAN0TXERR_TXERR1                 CANTXERR_TXERR1
#define CAN0TXERR_TXERR2                 CANTXERR_TXERR2
#define CAN0TXERR_TXERR3                 CANTXERR_TXERR3
#define CAN0TXERR_TXERR4                 CANTXERR_TXERR4
#define CAN0TXERR_TXERR5                 CANTXERR_TXERR5
#define CAN0TXERR_TXERR6                 CANTXERR_TXERR6
#define CAN0TXERR_TXERR7                 CANTXERR_TXERR7
#define CAN0TXERR_TXERR0_MASK            CANTXERR_TXERR0_MASK
#define CAN0TXERR_TXERR1_MASK            CANTXERR_TXERR1_MASK
#define CAN0TXERR_TXERR2_MASK            CANTXERR_TXERR2_MASK
#define CAN0TXERR_TXERR3_MASK            CANTXERR_TXERR3_MASK
#define CAN0TXERR_TXERR4_MASK            CANTXERR_TXERR4_MASK
#define CAN0TXERR_TXERR5_MASK            CANTXERR_TXERR5_MASK
#define CAN0TXERR_TXERR6_MASK            CANTXERR_TXERR6_MASK
#define CAN0TXERR_TXERR7_MASK            CANTXERR_TXERR7_MASK
#define CAN0IDAR0                        CANIDAR0
#define CAN0IDAR0_AC0                    CANIDAR0_AC0
#define CAN0IDAR0_AC1                    CANIDAR0_AC1
#define CAN0IDAR0_AC2                    CANIDAR0_AC2
#define CAN0IDAR0_AC3                    CANIDAR0_AC3
#define CAN0IDAR0_AC4                    CANIDAR0_AC4
#define CAN0IDAR0_AC5                    CANIDAR0_AC5
#define CAN0IDAR0_AC6                    CANIDAR0_AC6
#define CAN0IDAR0_AC7                    CANIDAR0_AC7
#define CAN0IDAR_ARR                     CANIDAR_ARR
#define CAN0IDAR0_AC0_MASK               CANIDAR0_AC0_MASK
#define CAN0IDAR0_AC1_MASK               CANIDAR0_AC1_MASK
#define CAN0IDAR0_AC2_MASK               CANIDAR0_AC2_MASK
#define CAN0IDAR0_AC3_MASK               CANIDAR0_AC3_MASK
#define CAN0IDAR0_AC4_MASK               CANIDAR0_AC4_MASK
#define CAN0IDAR0_AC5_MASK               CANIDAR0_AC5_MASK
#define CAN0IDAR0_AC6_MASK               CANIDAR0_AC6_MASK
#define CAN0IDAR0_AC7_MASK               CANIDAR0_AC7_MASK
#define CAN0IDAR1                        CANIDAR1
#define CAN0IDAR1_AC0                    CANIDAR1_AC0
#define CAN0IDAR1_AC1                    CANIDAR1_AC1
#define CAN0IDAR1_AC2                    CANIDAR1_AC2
#define CAN0IDAR1_AC3                    CANIDAR1_AC3
#define CAN0IDAR1_AC4                    CANIDAR1_AC4
#define CAN0IDAR1_AC5                    CANIDAR1_AC5
#define CAN0IDAR1_AC6                    CANIDAR1_AC6
#define CAN0IDAR1_AC7                    CANIDAR1_AC7
#define CAN0IDAR1_AC0_MASK               CANIDAR1_AC0_MASK
#define CAN0IDAR1_AC1_MASK               CANIDAR1_AC1_MASK
#define CAN0IDAR1_AC2_MASK               CANIDAR1_AC2_MASK
#define CAN0IDAR1_AC3_MASK               CANIDAR1_AC3_MASK
#define CAN0IDAR1_AC4_MASK               CANIDAR1_AC4_MASK
#define CAN0IDAR1_AC5_MASK               CANIDAR1_AC5_MASK
#define CAN0IDAR1_AC6_MASK               CANIDAR1_AC6_MASK
#define CAN0IDAR1_AC7_MASK               CANIDAR1_AC7_MASK
#define CAN0IDAR2                        CANIDAR2
#define CAN0IDAR2_AC0                    CANIDAR2_AC0
#define CAN0IDAR2_AC1                    CANIDAR2_AC1
#define CAN0IDAR2_AC2                    CANIDAR2_AC2
#define CAN0IDAR2_AC3                    CANIDAR2_AC3
#define CAN0IDAR2_AC4                    CANIDAR2_AC4
#define CAN0IDAR2_AC5                    CANIDAR2_AC5
#define CAN0IDAR2_AC6                    CANIDAR2_AC6
#define CAN0IDAR2_AC7                    CANIDAR2_AC7
#define CAN0IDAR2_AC0_MASK               CANIDAR2_AC0_MASK
#define CAN0IDAR2_AC1_MASK               CANIDAR2_AC1_MASK
#define CAN0IDAR2_AC2_MASK               CANIDAR2_AC2_MASK
#define CAN0IDAR2_AC3_MASK               CANIDAR2_AC3_MASK
#define CAN0IDAR2_AC4_MASK               CANIDAR2_AC4_MASK
#define CAN0IDAR2_AC5_MASK               CANIDAR2_AC5_MASK
#define CAN0IDAR2_AC6_MASK               CANIDAR2_AC6_MASK
#define CAN0IDAR2_AC7_MASK               CANIDAR2_AC7_MASK
#define CAN0IDAR3                        CANIDAR3
#define CAN0IDAR3_AC0                    CANIDAR3_AC0
#define CAN0IDAR3_AC1                    CANIDAR3_AC1
#define CAN0IDAR3_AC2                    CANIDAR3_AC2
#define CAN0IDAR3_AC3                    CANIDAR3_AC3
#define CAN0IDAR3_AC4                    CANIDAR3_AC4
#define CAN0IDAR3_AC5                    CANIDAR3_AC5
#define CAN0IDAR3_AC6                    CANIDAR3_AC6
#define CAN0IDAR3_AC7                    CANIDAR3_AC7
#define CAN0IDAR3_AC0_MASK               CANIDAR3_AC0_MASK
#define CAN0IDAR3_AC1_MASK               CANIDAR3_AC1_MASK
#define CAN0IDAR3_AC2_MASK               CANIDAR3_AC2_MASK
#define CAN0IDAR3_AC3_MASK               CANIDAR3_AC3_MASK
#define CAN0IDAR3_AC4_MASK               CANIDAR3_AC4_MASK
#define CAN0IDAR3_AC5_MASK               CANIDAR3_AC5_MASK
#define CAN0IDAR3_AC6_MASK               CANIDAR3_AC6_MASK
#define CAN0IDAR3_AC7_MASK               CANIDAR3_AC7_MASK
#define CAN0IDMR0                        CANIDMR0
#define CAN0IDMR0_AM0                    CANIDMR0_AM0
#define CAN0IDMR0_AM1                    CANIDMR0_AM1
#define CAN0IDMR0_AM2                    CANIDMR0_AM2
#define CAN0IDMR0_AM3                    CANIDMR0_AM3
#define CAN0IDMR0_AM4                    CANIDMR0_AM4
#define CAN0IDMR0_AM5                    CANIDMR0_AM5
#define CAN0IDMR0_AM6                    CANIDMR0_AM6
#define CAN0IDMR0_AM7                    CANIDMR0_AM7
#define CAN0IDMR_ARR                     CANIDMR_ARR
#define CAN0IDMR0_AM0_MASK               CANIDMR0_AM0_MASK
#define CAN0IDMR0_AM1_MASK               CANIDMR0_AM1_MASK
#define CAN0IDMR0_AM2_MASK               CANIDMR0_AM2_MASK
#define CAN0IDMR0_AM3_MASK               CANIDMR0_AM3_MASK
#define CAN0IDMR0_AM4_MASK               CANIDMR0_AM4_MASK
#define CAN0IDMR0_AM5_MASK               CANIDMR0_AM5_MASK
#define CAN0IDMR0_AM6_MASK               CANIDMR0_AM6_MASK
#define CAN0IDMR0_AM7_MASK               CANIDMR0_AM7_MASK
#define CAN0IDMR1                        CANIDMR1
#define CAN0IDMR1_AM0                    CANIDMR1_AM0
#define CAN0IDMR1_AM1                    CANIDMR1_AM1
#define CAN0IDMR1_AM2                    CANIDMR1_AM2
#define CAN0IDMR1_AM3                    CANIDMR1_AM3
#define CAN0IDMR1_AM4                    CANIDMR1_AM4
#define CAN0IDMR1_AM5                    CANIDMR1_AM5
#define CAN0IDMR1_AM6                    CANIDMR1_AM6
#define CAN0IDMR1_AM7                    CANIDMR1_AM7
#define CAN0IDMR1_AM0_MASK               CANIDMR1_AM0_MASK
#define CAN0IDMR1_AM1_MASK               CANIDMR1_AM1_MASK
#define CAN0IDMR1_AM2_MASK               CANIDMR1_AM2_MASK
#define CAN0IDMR1_AM3_MASK               CANIDMR1_AM3_MASK
#define CAN0IDMR1_AM4_MASK               CANIDMR1_AM4_MASK
#define CAN0IDMR1_AM5_MASK               CANIDMR1_AM5_MASK
#define CAN0IDMR1_AM6_MASK               CANIDMR1_AM6_MASK
#define CAN0IDMR1_AM7_MASK               CANIDMR1_AM7_MASK
#define CAN0IDMR2                        CANIDMR2
#define CAN0IDMR2_AM0                    CANIDMR2_AM0
#define CAN0IDMR2_AM1                    CANIDMR2_AM1
#define CAN0IDMR2_AM2                    CANIDMR2_AM2
#define CAN0IDMR2_AM3                    CANIDMR2_AM3
#define CAN0IDMR2_AM4                    CANIDMR2_AM4
#define CAN0IDMR2_AM5                    CANIDMR2_AM5
#define CAN0IDMR2_AM6                    CANIDMR2_AM6
#define CAN0IDMR2_AM7                    CANIDMR2_AM7
#define CAN0IDMR2_AM0_MASK               CANIDMR2_AM0_MASK
#define CAN0IDMR2_AM1_MASK               CANIDMR2_AM1_MASK
#define CAN0IDMR2_AM2_MASK               CANIDMR2_AM2_MASK
#define CAN0IDMR2_AM3_MASK               CANIDMR2_AM3_MASK
#define CAN0IDMR2_AM4_MASK               CANIDMR2_AM4_MASK
#define CAN0IDMR2_AM5_MASK               CANIDMR2_AM5_MASK
#define CAN0IDMR2_AM6_MASK               CANIDMR2_AM6_MASK
#define CAN0IDMR2_AM7_MASK               CANIDMR2_AM7_MASK
#define CAN0IDMR3                        CANIDMR3
#define CAN0IDMR3_AM0                    CANIDMR3_AM0
#define CAN0IDMR3_AM1                    CANIDMR3_AM1
#define CAN0IDMR3_AM2                    CANIDMR3_AM2
#define CAN0IDMR3_AM3                    CANIDMR3_AM3
#define CAN0IDMR3_AM4                    CANIDMR3_AM4
#define CAN0IDMR3_AM5                    CANIDMR3_AM5
#define CAN0IDMR3_AM6                    CANIDMR3_AM6
#define CAN0IDMR3_AM7                    CANIDMR3_AM7
#define CAN0IDMR3_AM0_MASK               CANIDMR3_AM0_MASK
#define CAN0IDMR3_AM1_MASK               CANIDMR3_AM1_MASK
#define CAN0IDMR3_AM2_MASK               CANIDMR3_AM2_MASK
#define CAN0IDMR3_AM3_MASK               CANIDMR3_AM3_MASK
#define CAN0IDMR3_AM4_MASK               CANIDMR3_AM4_MASK
#define CAN0IDMR3_AM5_MASK               CANIDMR3_AM5_MASK
#define CAN0IDMR3_AM6_MASK               CANIDMR3_AM6_MASK
#define CAN0IDMR3_AM7_MASK               CANIDMR3_AM7_MASK
#define CAN0IDAR4                        CANIDAR4
#define CAN0IDAR4_AC0                    CANIDAR4_AC0
#define CAN0IDAR4_AC1                    CANIDAR4_AC1
#define CAN0IDAR4_AC2                    CANIDAR4_AC2
#define CAN0IDAR4_AC3                    CANIDAR4_AC3
#define CAN0IDAR4_AC4                    CANIDAR4_AC4
#define CAN0IDAR4_AC5                    CANIDAR4_AC5
#define CAN0IDAR4_AC6                    CANIDAR4_AC6
#define CAN0IDAR4_AC7                    CANIDAR4_AC7
#define CAN0IDAR4_AC0_MASK               CANIDAR4_AC0_MASK
#define CAN0IDAR4_AC1_MASK               CANIDAR4_AC1_MASK
#define CAN0IDAR4_AC2_MASK               CANIDAR4_AC2_MASK
#define CAN0IDAR4_AC3_MASK               CANIDAR4_AC3_MASK
#define CAN0IDAR4_AC4_MASK               CANIDAR4_AC4_MASK
#define CAN0IDAR4_AC5_MASK               CANIDAR4_AC5_MASK
#define CAN0IDAR4_AC6_MASK               CANIDAR4_AC6_MASK
#define CAN0IDAR4_AC7_MASK               CANIDAR4_AC7_MASK
#define CAN0IDAR5                        CANIDAR5
#define CAN0IDAR5_AC0                    CANIDAR5_AC0
#define CAN0IDAR5_AC1                    CANIDAR5_AC1
#define CAN0IDAR5_AC2                    CANIDAR5_AC2
#define CAN0IDAR5_AC3                    CANIDAR5_AC3
#define CAN0IDAR5_AC4                    CANIDAR5_AC4
#define CAN0IDAR5_AC5                    CANIDAR5_AC5
#define CAN0IDAR5_AC6                    CANIDAR5_AC6
#define CAN0IDAR5_AC7                    CANIDAR5_AC7
#define CAN0IDAR5_AC0_MASK               CANIDAR5_AC0_MASK
#define CAN0IDAR5_AC1_MASK               CANIDAR5_AC1_MASK
#define CAN0IDAR5_AC2_MASK               CANIDAR5_AC2_MASK
#define CAN0IDAR5_AC3_MASK               CANIDAR5_AC3_MASK
#define CAN0IDAR5_AC4_MASK               CANIDAR5_AC4_MASK
#define CAN0IDAR5_AC5_MASK               CANIDAR5_AC5_MASK
#define CAN0IDAR5_AC6_MASK               CANIDAR5_AC6_MASK
#define CAN0IDAR5_AC7_MASK               CANIDAR5_AC7_MASK
#define CAN0IDAR6                        CANIDAR6
#define CAN0IDAR6_AC0                    CANIDAR6_AC0
#define CAN0IDAR6_AC1                    CANIDAR6_AC1
#define CAN0IDAR6_AC2                    CANIDAR6_AC2
#define CAN0IDAR6_AC3                    CANIDAR6_AC3
#define CAN0IDAR6_AC4                    CANIDAR6_AC4
#define CAN0IDAR6_AC5                    CANIDAR6_AC5
#define CAN0IDAR6_AC6                    CANIDAR6_AC6
#define CAN0IDAR6_AC7                    CANIDAR6_AC7
#define CAN0IDAR6_AC0_MASK               CANIDAR6_AC0_MASK
#define CAN0IDAR6_AC1_MASK               CANIDAR6_AC1_MASK
#define CAN0IDAR6_AC2_MASK               CANIDAR6_AC2_MASK
#define CAN0IDAR6_AC3_MASK               CANIDAR6_AC3_MASK
#define CAN0IDAR6_AC4_MASK               CANIDAR6_AC4_MASK
#define CAN0IDAR6_AC5_MASK               CANIDAR6_AC5_MASK
#define CAN0IDAR6_AC6_MASK               CANIDAR6_AC6_MASK
#define CAN0IDAR6_AC7_MASK               CANIDAR6_AC7_MASK
#define CAN0IDAR7                        CANIDAR7
#define CAN0IDAR7_AC0                    CANIDAR7_AC0
#define CAN0IDAR7_AC1                    CANIDAR7_AC1
#define CAN0IDAR7_AC2                    CANIDAR7_AC2
#define CAN0IDAR7_AC3                    CANIDAR7_AC3
#define CAN0IDAR7_AC4                    CANIDAR7_AC4
#define CAN0IDAR7_AC5                    CANIDAR7_AC5
#define CAN0IDAR7_AC6                    CANIDAR7_AC6
#define CAN0IDAR7_AC7                    CANIDAR7_AC7
#define CAN0IDAR7_AC0_MASK               CANIDAR7_AC0_MASK
#define CAN0IDAR7_AC1_MASK               CANIDAR7_AC1_MASK
#define CAN0IDAR7_AC2_MASK               CANIDAR7_AC2_MASK
#define CAN0IDAR7_AC3_MASK               CANIDAR7_AC3_MASK
#define CAN0IDAR7_AC4_MASK               CANIDAR7_AC4_MASK
#define CAN0IDAR7_AC5_MASK               CANIDAR7_AC5_MASK
#define CAN0IDAR7_AC6_MASK               CANIDAR7_AC6_MASK
#define CAN0IDAR7_AC7_MASK               CANIDAR7_AC7_MASK
#define CAN0IDMR4                        CANIDMR4
#define CAN0IDMR4_AM0                    CANIDMR4_AM0
#define CAN0IDMR4_AM1                    CANIDMR4_AM1
#define CAN0IDMR4_AM2                    CANIDMR4_AM2
#define CAN0IDMR4_AM3                    CANIDMR4_AM3
#define CAN0IDMR4_AM4                    CANIDMR4_AM4
#define CAN0IDMR4_AM5                    CANIDMR4_AM5
#define CAN0IDMR4_AM6                    CANIDMR4_AM6
#define CAN0IDMR4_AM7                    CANIDMR4_AM7
#define CAN0IDMR4_AM0_MASK               CANIDMR4_AM0_MASK
#define CAN0IDMR4_AM1_MASK               CANIDMR4_AM1_MASK
#define CAN0IDMR4_AM2_MASK               CANIDMR4_AM2_MASK
#define CAN0IDMR4_AM3_MASK               CANIDMR4_AM3_MASK
#define CAN0IDMR4_AM4_MASK               CANIDMR4_AM4_MASK
#define CAN0IDMR4_AM5_MASK               CANIDMR4_AM5_MASK
#define CAN0IDMR4_AM6_MASK               CANIDMR4_AM6_MASK
#define CAN0IDMR4_AM7_MASK               CANIDMR4_AM7_MASK
#define CAN0IDMR5                        CANIDMR5
#define CAN0IDMR5_AM0                    CANIDMR5_AM0
#define CAN0IDMR5_AM1                    CANIDMR5_AM1
#define CAN0IDMR5_AM2                    CANIDMR5_AM2
#define CAN0IDMR5_AM3                    CANIDMR5_AM3
#define CAN0IDMR5_AM4                    CANIDMR5_AM4
#define CAN0IDMR5_AM5                    CANIDMR5_AM5
#define CAN0IDMR5_AM6                    CANIDMR5_AM6
#define CAN0IDMR5_AM7                    CANIDMR5_AM7
#define CAN0IDMR5_AM0_MASK               CANIDMR5_AM0_MASK
#define CAN0IDMR5_AM1_MASK               CANIDMR5_AM1_MASK
#define CAN0IDMR5_AM2_MASK               CANIDMR5_AM2_MASK
#define CAN0IDMR5_AM3_MASK               CANIDMR5_AM3_MASK
#define CAN0IDMR5_AM4_MASK               CANIDMR5_AM4_MASK
#define CAN0IDMR5_AM5_MASK               CANIDMR5_AM5_MASK
#define CAN0IDMR5_AM6_MASK               CANIDMR5_AM6_MASK
#define CAN0IDMR5_AM7_MASK               CANIDMR5_AM7_MASK
#define CAN0IDMR6                        CANIDMR6
#define CAN0IDMR6_AM0                    CANIDMR6_AM0
#define CAN0IDMR6_AM1                    CANIDMR6_AM1
#define CAN0IDMR6_AM2                    CANIDMR6_AM2
#define CAN0IDMR6_AM3                    CANIDMR6_AM3
#define CAN0IDMR6_AM4                    CANIDMR6_AM4
#define CAN0IDMR6_AM5                    CANIDMR6_AM5
#define CAN0IDMR6_AM6                    CANIDMR6_AM6
#define CAN0IDMR6_AM7                    CANIDMR6_AM7
#define CAN0IDMR6_AM0_MASK               CANIDMR6_AM0_MASK
#define CAN0IDMR6_AM1_MASK               CANIDMR6_AM1_MASK
#define CAN0IDMR6_AM2_MASK               CANIDMR6_AM2_MASK
#define CAN0IDMR6_AM3_MASK               CANIDMR6_AM3_MASK
#define CAN0IDMR6_AM4_MASK               CANIDMR6_AM4_MASK
#define CAN0IDMR6_AM5_MASK               CANIDMR6_AM5_MASK
#define CAN0IDMR6_AM6_MASK               CANIDMR6_AM6_MASK
#define CAN0IDMR6_AM7_MASK               CANIDMR6_AM7_MASK
#define CAN0IDMR7                        CANIDMR7
#define CAN0IDMR7_AM0                    CANIDMR7_AM0
#define CAN0IDMR7_AM1                    CANIDMR7_AM1
#define CAN0IDMR7_AM2                    CANIDMR7_AM2
#define CAN0IDMR7_AM3                    CANIDMR7_AM3
#define CAN0IDMR7_AM4                    CANIDMR7_AM4
#define CAN0IDMR7_AM5                    CANIDMR7_AM5
#define CAN0IDMR7_AM6                    CANIDMR7_AM6
#define CAN0IDMR7_AM7                    CANIDMR7_AM7
#define CAN0IDMR7_AM0_MASK               CANIDMR7_AM0_MASK
#define CAN0IDMR7_AM1_MASK               CANIDMR7_AM1_MASK
#define CAN0IDMR7_AM2_MASK               CANIDMR7_AM2_MASK
#define CAN0IDMR7_AM3_MASK               CANIDMR7_AM3_MASK
#define CAN0IDMR7_AM4_MASK               CANIDMR7_AM4_MASK
#define CAN0IDMR7_AM5_MASK               CANIDMR7_AM5_MASK
#define CAN0IDMR7_AM6_MASK               CANIDMR7_AM6_MASK
#define CAN0IDMR7_AM7_MASK               CANIDMR7_AM7_MASK
#define CAN0RXIDR0                       CANRXIDR0
#define CAN0RXIDR0_ID21                  CANRXIDR0_ID21
#define CAN0RXIDR0_ID22                  CANRXIDR0_ID22
#define CAN0RXIDR0_ID23                  CANRXIDR0_ID23
#define CAN0RXIDR0_ID24                  CANRXIDR0_ID24
#define CAN0RXIDR0_ID25                  CANRXIDR0_ID25
#define CAN0RXIDR0_ID26                  CANRXIDR0_ID26
#define CAN0RXIDR0_ID27                  CANRXIDR0_ID27
#define CAN0RXIDR0_ID28                  CANRXIDR0_ID28
#define CAN0RXIDR_ARR                    CANRXIDR_ARR
#define CAN0RXIDR0_ID21_MASK             CANRXIDR0_ID21_MASK
#define CAN0RXIDR0_ID22_MASK             CANRXIDR0_ID22_MASK
#define CAN0RXIDR0_ID23_MASK             CANRXIDR0_ID23_MASK
#define CAN0RXIDR0_ID24_MASK             CANRXIDR0_ID24_MASK
#define CAN0RXIDR0_ID25_MASK             CANRXIDR0_ID25_MASK
#define CAN0RXIDR0_ID26_MASK             CANRXIDR0_ID26_MASK
#define CAN0RXIDR0_ID27_MASK             CANRXIDR0_ID27_MASK
#define CAN0RXIDR0_ID28_MASK             CANRXIDR0_ID28_MASK
#define CAN0RXIDR1                       CANRXIDR1
#define CAN0RXIDR1_ID15                  CANRXIDR1_ID15
#define CAN0RXIDR1_ID16                  CANRXIDR1_ID16
#define CAN0RXIDR1_ID17                  CANRXIDR1_ID17
#define CAN0RXIDR1_IDE                   CANRXIDR1_IDE
#define CAN0RXIDR1_SRR                   CANRXIDR1_SRR
#define CAN0RXIDR1_ID18                  CANRXIDR1_ID18
#define CAN0RXIDR1_ID19                  CANRXIDR1_ID19
#define CAN0RXIDR1_ID20                  CANRXIDR1_ID20
#define CAN0RXIDR1_ID_15                 CANRXIDR1_ID_15
#define CAN0RXIDR1_ID_18                 CANRXIDR1_ID_18
#define CAN0RXIDR1_ID                    CANRXIDR1_ID
#define CAN0RXIDR1_ID15_MASK             CANRXIDR1_ID15_MASK
#define CAN0RXIDR1_ID16_MASK             CANRXIDR1_ID16_MASK
#define CAN0RXIDR1_ID17_MASK             CANRXIDR1_ID17_MASK
#define CAN0RXIDR1_IDE_MASK              CANRXIDR1_IDE_MASK
#define CAN0RXIDR1_SRR_MASK              CANRXIDR1_SRR_MASK
#define CAN0RXIDR1_ID18_MASK             CANRXIDR1_ID18_MASK
#define CAN0RXIDR1_ID19_MASK             CANRXIDR1_ID19_MASK
#define CAN0RXIDR1_ID20_MASK             CANRXIDR1_ID20_MASK
#define CAN0RXIDR1_ID_15_MASK            CANRXIDR1_ID_15_MASK
#define CAN0RXIDR1_ID_15_BITNUM          CANRXIDR1_ID_15_BITNUM
#define CAN0RXIDR1_ID_18_MASK            CANRXIDR1_ID_18_MASK
#define CAN0RXIDR1_ID_18_BITNUM          CANRXIDR1_ID_18_BITNUM
#define CAN0RXIDR2                       CANRXIDR2
#define CAN0RXIDR2_ID7                   CANRXIDR2_ID7
#define CAN0RXIDR2_ID8                   CANRXIDR2_ID8
#define CAN0RXIDR2_ID9                   CANRXIDR2_ID9
#define CAN0RXIDR2_ID10                  CANRXIDR2_ID10
#define CAN0RXIDR2_ID11                  CANRXIDR2_ID11
#define CAN0RXIDR2_ID12                  CANRXIDR2_ID12
#define CAN0RXIDR2_ID13                  CANRXIDR2_ID13
#define CAN0RXIDR2_ID14                  CANRXIDR2_ID14
#define CAN0RXIDR2_ID7_MASK              CANRXIDR2_ID7_MASK
#define CAN0RXIDR2_ID8_MASK              CANRXIDR2_ID8_MASK
#define CAN0RXIDR2_ID9_MASK              CANRXIDR2_ID9_MASK
#define CAN0RXIDR2_ID10_MASK             CANRXIDR2_ID10_MASK
#define CAN0RXIDR2_ID11_MASK             CANRXIDR2_ID11_MASK
#define CAN0RXIDR2_ID12_MASK             CANRXIDR2_ID12_MASK
#define CAN0RXIDR2_ID13_MASK             CANRXIDR2_ID13_MASK
#define CAN0RXIDR2_ID14_MASK             CANRXIDR2_ID14_MASK
#define CAN0RXIDR3                       CANRXIDR3
#define CAN0RXIDR3_RTR                   CANRXIDR3_RTR
#define CAN0RXIDR3_ID0                   CANRXIDR3_ID0
#define CAN0RXIDR3_ID1                   CANRXIDR3_ID1
#define CAN0RXIDR3_ID2                   CANRXIDR3_ID2
#define CAN0RXIDR3_ID3                   CANRXIDR3_ID3
#define CAN0RXIDR3_ID4                   CANRXIDR3_ID4
#define CAN0RXIDR3_ID5                   CANRXIDR3_ID5
#define CAN0RXIDR3_ID6                   CANRXIDR3_ID6
#define CAN0RXIDR3_ID                    CANRXIDR3_ID
#define CAN0RXIDR3_RTR_MASK              CANRXIDR3_RTR_MASK
#define CAN0RXIDR3_ID0_MASK              CANRXIDR3_ID0_MASK
#define CAN0RXIDR3_ID1_MASK              CANRXIDR3_ID1_MASK
#define CAN0RXIDR3_ID2_MASK              CANRXIDR3_ID2_MASK
#define CAN0RXIDR3_ID3_MASK              CANRXIDR3_ID3_MASK
#define CAN0RXIDR3_ID4_MASK              CANRXIDR3_ID4_MASK
#define CAN0RXIDR3_ID5_MASK              CANRXIDR3_ID5_MASK
#define CAN0RXIDR3_ID6_MASK              CANRXIDR3_ID6_MASK
#define CAN0RXIDR3_ID_MASK               CANRXIDR3_ID_MASK
#define CAN0RXIDR3_ID_BITNUM             CANRXIDR3_ID_BITNUM
#define CAN0RXDSR0                       CANRXDSR0
#define CAN0RXDSR0_DB0                   CANRXDSR0_DB0
#define CAN0RXDSR0_DB1                   CANRXDSR0_DB1
#define CAN0RXDSR0_DB2                   CANRXDSR0_DB2
#define CAN0RXDSR0_DB3                   CANRXDSR0_DB3
#define CAN0RXDSR0_DB4                   CANRXDSR0_DB4
#define CAN0RXDSR0_DB5                   CANRXDSR0_DB5
#define CAN0RXDSR0_DB6                   CANRXDSR0_DB6
#define CAN0RXDSR0_DB7                   CANRXDSR0_DB7
#define CAN0RXDSR_ARR                    CANRXDSR_ARR
#define CAN0RXDSR0_DB0_MASK              CANRXDSR0_DB0_MASK
#define CAN0RXDSR0_DB1_MASK              CANRXDSR0_DB1_MASK
#define CAN0RXDSR0_DB2_MASK              CANRXDSR0_DB2_MASK
#define CAN0RXDSR0_DB3_MASK              CANRXDSR0_DB3_MASK
#define CAN0RXDSR0_DB4_MASK              CANRXDSR0_DB4_MASK
#define CAN0RXDSR0_DB5_MASK              CANRXDSR0_DB5_MASK
#define CAN0RXDSR0_DB6_MASK              CANRXDSR0_DB6_MASK
#define CAN0RXDSR0_DB7_MASK              CANRXDSR0_DB7_MASK
#define CAN0RXDSR1                       CANRXDSR1
#define CAN0RXDSR1_DB0                   CANRXDSR1_DB0
#define CAN0RXDSR1_DB1                   CANRXDSR1_DB1
#define CAN0RXDSR1_DB2                   CANRXDSR1_DB2
#define CAN0RXDSR1_DB3                   CANRXDSR1_DB3
#define CAN0RXDSR1_DB4                   CANRXDSR1_DB4
#define CAN0RXDSR1_DB5                   CANRXDSR1_DB5
#define CAN0RXDSR1_DB6                   CANRXDSR1_DB6
#define CAN0RXDSR1_DB7                   CANRXDSR1_DB7
#define CAN0RXDSR1_DB0_MASK              CANRXDSR1_DB0_MASK
#define CAN0RXDSR1_DB1_MASK              CANRXDSR1_DB1_MASK
#define CAN0RXDSR1_DB2_MASK              CANRXDSR1_DB2_MASK
#define CAN0RXDSR1_DB3_MASK              CANRXDSR1_DB3_MASK
#define CAN0RXDSR1_DB4_MASK              CANRXDSR1_DB4_MASK
#define CAN0RXDSR1_DB5_MASK              CANRXDSR1_DB5_MASK
#define CAN0RXDSR1_DB6_MASK              CANRXDSR1_DB6_MASK
#define CAN0RXDSR1_DB7_MASK              CANRXDSR1_DB7_MASK
#define CAN0RXDSR2                       CANRXDSR2
#define CAN0RXDSR2_DB0                   CANRXDSR2_DB0
#define CAN0RXDSR2_DB1                   CANRXDSR2_DB1
#define CAN0RXDSR2_DB2                   CANRXDSR2_DB2
#define CAN0RXDSR2_DB3                   CANRXDSR2_DB3
#define CAN0RXDSR2_DB4                   CANRXDSR2_DB4
#define CAN0RXDSR2_DB5                   CANRXDSR2_DB5
#define CAN0RXDSR2_DB6                   CANRXDSR2_DB6
#define CAN0RXDSR2_DB7                   CANRXDSR2_DB7
#define CAN0RXDSR2_DB0_MASK              CANRXDSR2_DB0_MASK
#define CAN0RXDSR2_DB1_MASK              CANRXDSR2_DB1_MASK
#define CAN0RXDSR2_DB2_MASK              CANRXDSR2_DB2_MASK
#define CAN0RXDSR2_DB3_MASK              CANRXDSR2_DB3_MASK
#define CAN0RXDSR2_DB4_MASK              CANRXDSR2_DB4_MASK
#define CAN0RXDSR2_DB5_MASK              CANRXDSR2_DB5_MASK
#define CAN0RXDSR2_DB6_MASK              CANRXDSR2_DB6_MASK
#define CAN0RXDSR2_DB7_MASK              CANRXDSR2_DB7_MASK
#define CAN0RXDSR3                       CANRXDSR3
#define CAN0RXDSR3_DB0                   CANRXDSR3_DB0
#define CAN0RXDSR3_DB1                   CANRXDSR3_DB1
#define CAN0RXDSR3_DB2                   CANRXDSR3_DB2
#define CAN0RXDSR3_DB3                   CANRXDSR3_DB3
#define CAN0RXDSR3_DB4                   CANRXDSR3_DB4
#define CAN0RXDSR3_DB5                   CANRXDSR3_DB5
#define CAN0RXDSR3_DB6                   CANRXDSR3_DB6
#define CAN0RXDSR3_DB7                   CANRXDSR3_DB7
#define CAN0RXDSR3_DB0_MASK              CANRXDSR3_DB0_MASK
#define CAN0RXDSR3_DB1_MASK              CANRXDSR3_DB1_MASK
#define CAN0RXDSR3_DB2_MASK              CANRXDSR3_DB2_MASK
#define CAN0RXDSR3_DB3_MASK              CANRXDSR3_DB3_MASK
#define CAN0RXDSR3_DB4_MASK              CANRXDSR3_DB4_MASK
#define CAN0RXDSR3_DB5_MASK              CANRXDSR3_DB5_MASK
#define CAN0RXDSR3_DB6_MASK              CANRXDSR3_DB6_MASK
#define CAN0RXDSR3_DB7_MASK              CANRXDSR3_DB7_MASK
#define CAN0RXDSR4                       CANRXDSR4
#define CAN0RXDSR4_DB0                   CANRXDSR4_DB0
#define CAN0RXDSR4_DB1                   CANRXDSR4_DB1
#define CAN0RXDSR4_DB2                   CANRXDSR4_DB2
#define CAN0RXDSR4_DB3                   CANRXDSR4_DB3
#define CAN0RXDSR4_DB4                   CANRXDSR4_DB4
#define CAN0RXDSR4_DB5                   CANRXDSR4_DB5
#define CAN0RXDSR4_DB6                   CANRXDSR4_DB6
#define CAN0RXDSR4_DB7                   CANRXDSR4_DB7
#define CAN0RXDSR4_DB0_MASK              CANRXDSR4_DB0_MASK
#define CAN0RXDSR4_DB1_MASK              CANRXDSR4_DB1_MASK
#define CAN0RXDSR4_DB2_MASK              CANRXDSR4_DB2_MASK
#define CAN0RXDSR4_DB3_MASK              CANRXDSR4_DB3_MASK
#define CAN0RXDSR4_DB4_MASK              CANRXDSR4_DB4_MASK
#define CAN0RXDSR4_DB5_MASK              CANRXDSR4_DB5_MASK
#define CAN0RXDSR4_DB6_MASK              CANRXDSR4_DB6_MASK
#define CAN0RXDSR4_DB7_MASK              CANRXDSR4_DB7_MASK
#define CAN0RXDSR5                       CANRXDSR5
#define CAN0RXDSR5_DB0                   CANRXDSR5_DB0
#define CAN0RXDSR5_DB1                   CANRXDSR5_DB1
#define CAN0RXDSR5_DB2                   CANRXDSR5_DB2
#define CAN0RXDSR5_DB3                   CANRXDSR5_DB3
#define CAN0RXDSR5_DB4                   CANRXDSR5_DB4
#define CAN0RXDSR5_DB5                   CANRXDSR5_DB5
#define CAN0RXDSR5_DB6                   CANRXDSR5_DB6
#define CAN0RXDSR5_DB7                   CANRXDSR5_DB7
#define CAN0RXDSR5_DB0_MASK              CANRXDSR5_DB0_MASK
#define CAN0RXDSR5_DB1_MASK              CANRXDSR5_DB1_MASK
#define CAN0RXDSR5_DB2_MASK              CANRXDSR5_DB2_MASK
#define CAN0RXDSR5_DB3_MASK              CANRXDSR5_DB3_MASK
#define CAN0RXDSR5_DB4_MASK              CANRXDSR5_DB4_MASK
#define CAN0RXDSR5_DB5_MASK              CANRXDSR5_DB5_MASK
#define CAN0RXDSR5_DB6_MASK              CANRXDSR5_DB6_MASK
#define CAN0RXDSR5_DB7_MASK              CANRXDSR5_DB7_MASK
#define CAN0RXDSR6                       CANRXDSR6
#define CAN0RXDSR6_DB0                   CANRXDSR6_DB0
#define CAN0RXDSR6_DB1                   CANRXDSR6_DB1
#define CAN0RXDSR6_DB2                   CANRXDSR6_DB2
#define CAN0RXDSR6_DB3                   CANRXDSR6_DB3
#define CAN0RXDSR6_DB4                   CANRXDSR6_DB4
#define CAN0RXDSR6_DB5                   CANRXDSR6_DB5
#define CAN0RXDSR6_DB6                   CANRXDSR6_DB6
#define CAN0RXDSR6_DB7                   CANRXDSR6_DB7
#define CAN0RXDSR6_DB0_MASK              CANRXDSR6_DB0_MASK
#define CAN0RXDSR6_DB1_MASK              CANRXDSR6_DB1_MASK
#define CAN0RXDSR6_DB2_MASK              CANRXDSR6_DB2_MASK
#define CAN0RXDSR6_DB3_MASK              CANRXDSR6_DB3_MASK
#define CAN0RXDSR6_DB4_MASK              CANRXDSR6_DB4_MASK
#define CAN0RXDSR6_DB5_MASK              CANRXDSR6_DB5_MASK
#define CAN0RXDSR6_DB6_MASK              CANRXDSR6_DB6_MASK
#define CAN0RXDSR6_DB7_MASK              CANRXDSR6_DB7_MASK
#define CAN0RXDSR7                       CANRXDSR7
#define CAN0RXDSR7_DB0                   CANRXDSR7_DB0
#define CAN0RXDSR7_DB1                   CANRXDSR7_DB1
#define CAN0RXDSR7_DB2                   CANRXDSR7_DB2
#define CAN0RXDSR7_DB3                   CANRXDSR7_DB3
#define CAN0RXDSR7_DB4                   CANRXDSR7_DB4
#define CAN0RXDSR7_DB5                   CANRXDSR7_DB5
#define CAN0RXDSR7_DB6                   CANRXDSR7_DB6
#define CAN0RXDSR7_DB7                   CANRXDSR7_DB7
#define CAN0RXDSR7_DB0_MASK              CANRXDSR7_DB0_MASK
#define CAN0RXDSR7_DB1_MASK              CANRXDSR7_DB1_MASK
#define CAN0RXDSR7_DB2_MASK              CANRXDSR7_DB2_MASK
#define CAN0RXDSR7_DB3_MASK              CANRXDSR7_DB3_MASK
#define CAN0RXDSR7_DB4_MASK              CANRXDSR7_DB4_MASK
#define CAN0RXDSR7_DB5_MASK              CANRXDSR7_DB5_MASK
#define CAN0RXDSR7_DB6_MASK              CANRXDSR7_DB6_MASK
#define CAN0RXDSR7_DB7_MASK              CANRXDSR7_DB7_MASK
#define CAN0RXDLR                        CANRXDLR
#define CAN0RXDLR_DLC0                   CANRXDLR_DLC0
#define CAN0RXDLR_DLC1                   CANRXDLR_DLC1
#define CAN0RXDLR_DLC2                   CANRXDLR_DLC2
#define CAN0RXDLR_DLC3                   CANRXDLR_DLC3
#define CAN0RXDLR_DLC                    CANRXDLR_DLC
#define CAN0RXDLR_DLC0_MASK              CANRXDLR_DLC0_MASK
#define CAN0RXDLR_DLC1_MASK              CANRXDLR_DLC1_MASK
#define CAN0RXDLR_DLC2_MASK              CANRXDLR_DLC2_MASK
#define CAN0RXDLR_DLC3_MASK              CANRXDLR_DLC3_MASK
#define CAN0RXDLR_DLC_MASK               CANRXDLR_DLC_MASK
#define CAN0RXDLR_DLC_BITNUM             CANRXDLR_DLC_BITNUM
#define CAN0RXTSRH                       CANRXTSRH
#define CAN0RXTSRH_TSR8                  CANRXTSRH_TSR8
#define CAN0RXTSRH_TSR9                  CANRXTSRH_TSR9
#define CAN0RXTSRH_TSR10                 CANRXTSRH_TSR10
#define CAN0RXTSRH_TSR11                 CANRXTSRH_TSR11
#define CAN0RXTSRH_TSR12                 CANRXTSRH_TSR12
#define CAN0RXTSRH_TSR13                 CANRXTSRH_TSR13
#define CAN0RXTSRH_TSR14                 CANRXTSRH_TSR14
#define CAN0RXTSRH_TSR15                 CANRXTSRH_TSR15
#define CAN0RXTSRH_TSR8_MASK             CANRXTSRH_TSR8_MASK
#define CAN0RXTSRH_TSR9_MASK             CANRXTSRH_TSR9_MASK
#define CAN0RXTSRH_TSR10_MASK            CANRXTSRH_TSR10_MASK
#define CAN0RXTSRH_TSR11_MASK            CANRXTSRH_TSR11_MASK
#define CAN0RXTSRH_TSR12_MASK            CANRXTSRH_TSR12_MASK
#define CAN0RXTSRH_TSR13_MASK            CANRXTSRH_TSR13_MASK
#define CAN0RXTSRH_TSR14_MASK            CANRXTSRH_TSR14_MASK
#define CAN0RXTSRH_TSR15_MASK            CANRXTSRH_TSR15_MASK
#define CAN0RXTSRL                       CANRXTSRL
#define CAN0RXTSRL_TSR0                  CANRXTSRL_TSR0
#define CAN0RXTSRL_TSR1                  CANRXTSRL_TSR1
#define CAN0RXTSRL_TSR2                  CANRXTSRL_TSR2
#define CAN0RXTSRL_TSR3                  CANRXTSRL_TSR3
#define CAN0RXTSRL_TSR4                  CANRXTSRL_TSR4
#define CAN0RXTSRL_TSR5                  CANRXTSRL_TSR5
#define CAN0RXTSRL_TSR6                  CANRXTSRL_TSR6
#define CAN0RXTSRL_TSR7                  CANRXTSRL_TSR7
#define CAN0RXTSRL_TSR0_MASK             CANRXTSRL_TSR0_MASK
#define CAN0RXTSRL_TSR1_MASK             CANRXTSRL_TSR1_MASK
#define CAN0RXTSRL_TSR2_MASK             CANRXTSRL_TSR2_MASK
#define CAN0RXTSRL_TSR3_MASK             CANRXTSRL_TSR3_MASK
#define CAN0RXTSRL_TSR4_MASK             CANRXTSRL_TSR4_MASK
#define CAN0RXTSRL_TSR5_MASK             CANRXTSRL_TSR5_MASK
#define CAN0RXTSRL_TSR6_MASK             CANRXTSRL_TSR6_MASK
#define CAN0RXTSRL_TSR7_MASK             CANRXTSRL_TSR7_MASK
#define CAN0RXTSR                        CANRXTSR
#define CAN0RXTSR_TSR0                   CANRXTSR_TSR0
#define CAN0RXTSR_TSR1                   CANRXTSR_TSR1
#define CAN0RXTSR_TSR2                   CANRXTSR_TSR2
#define CAN0RXTSR_TSR3                   CANRXTSR_TSR3
#define CAN0RXTSR_TSR4                   CANRXTSR_TSR4
#define CAN0RXTSR_TSR5                   CANRXTSR_TSR5
#define CAN0RXTSR_TSR6                   CANRXTSR_TSR6
#define CAN0RXTSR_TSR7                   CANRXTSR_TSR7
#define CAN0RXTSR_TSR8                   CANRXTSR_TSR8
#define CAN0RXTSR_TSR9                   CANRXTSR_TSR9
#define CAN0RXTSR_TSR10                  CANRXTSR_TSR10
#define CAN0RXTSR_TSR11                  CANRXTSR_TSR11
#define CAN0RXTSR_TSR12                  CANRXTSR_TSR12
#define CAN0RXTSR_TSR13                  CANRXTSR_TSR13
#define CAN0RXTSR_TSR14                  CANRXTSR_TSR14
#define CAN0RXTSR_TSR15                  CANRXTSR_TSR15
#define CAN0RXTSR_TSR0_MASK              CANRXTSR_TSR0_MASK
#define CAN0RXTSR_TSR1_MASK              CANRXTSR_TSR1_MASK
#define CAN0RXTSR_TSR2_MASK              CANRXTSR_TSR2_MASK
#define CAN0RXTSR_TSR3_MASK              CANRXTSR_TSR3_MASK
#define CAN0RXTSR_TSR4_MASK              CANRXTSR_TSR4_MASK
#define CAN0RXTSR_TSR5_MASK              CANRXTSR_TSR5_MASK
#define CAN0RXTSR_TSR6_MASK              CANRXTSR_TSR6_MASK
#define CAN0RXTSR_TSR7_MASK              CANRXTSR_TSR7_MASK
#define CAN0RXTSR_TSR8_MASK              CANRXTSR_TSR8_MASK
#define CAN0RXTSR_TSR9_MASK              CANRXTSR_TSR9_MASK
#define CAN0RXTSR_TSR10_MASK             CANRXTSR_TSR10_MASK
#define CAN0RXTSR_TSR11_MASK             CANRXTSR_TSR11_MASK
#define CAN0RXTSR_TSR12_MASK             CANRXTSR_TSR12_MASK
#define CAN0RXTSR_TSR13_MASK             CANRXTSR_TSR13_MASK
#define CAN0RXTSR_TSR14_MASK             CANRXTSR_TSR14_MASK
#define CAN0RXTSR_TSR15_MASK             CANRXTSR_TSR15_MASK
#define CAN0TXIDR0                       CANTXIDR0
#define CAN0TXIDR0_ID21                  CANTXIDR0_ID21
#define CAN0TXIDR0_ID22                  CANTXIDR0_ID22
#define CAN0TXIDR0_ID23                  CANTXIDR0_ID23
#define CAN0TXIDR0_ID24                  CANTXIDR0_ID24
#define CAN0TXIDR0_ID25                  CANTXIDR0_ID25
#define CAN0TXIDR0_ID26                  CANTXIDR0_ID26
#define CAN0TXIDR0_ID27                  CANTXIDR0_ID27
#define CAN0TXIDR0_ID28                  CANTXIDR0_ID28
#define CAN0TXIDR_ARR                    CANTXIDR_ARR
#define CAN0TXIDR0_ID21_MASK             CANTXIDR0_ID21_MASK
#define CAN0TXIDR0_ID22_MASK             CANTXIDR0_ID22_MASK
#define CAN0TXIDR0_ID23_MASK             CANTXIDR0_ID23_MASK
#define CAN0TXIDR0_ID24_MASK             CANTXIDR0_ID24_MASK
#define CAN0TXIDR0_ID25_MASK             CANTXIDR0_ID25_MASK
#define CAN0TXIDR0_ID26_MASK             CANTXIDR0_ID26_MASK
#define CAN0TXIDR0_ID27_MASK             CANTXIDR0_ID27_MASK
#define CAN0TXIDR0_ID28_MASK             CANTXIDR0_ID28_MASK
#define CAN0TXIDR1                       CANTXIDR1
#define CAN0TXIDR1_ID15                  CANTXIDR1_ID15
#define CAN0TXIDR1_ID16                  CANTXIDR1_ID16
#define CAN0TXIDR1_ID17                  CANTXIDR1_ID17
#define CAN0TXIDR1_IDE                   CANTXIDR1_IDE
#define CAN0TXIDR1_SRR                   CANTXIDR1_SRR
#define CAN0TXIDR1_ID18                  CANTXIDR1_ID18
#define CAN0TXIDR1_ID19                  CANTXIDR1_ID19
#define CAN0TXIDR1_ID20                  CANTXIDR1_ID20
#define CAN0TXIDR1_ID_15                 CANTXIDR1_ID_15
#define CAN0TXIDR1_ID_18                 CANTXIDR1_ID_18
#define CAN0TXIDR1_ID                    CANTXIDR1_ID
#define CAN0TXIDR1_ID15_MASK             CANTXIDR1_ID15_MASK
#define CAN0TXIDR1_ID16_MASK             CANTXIDR1_ID16_MASK
#define CAN0TXIDR1_ID17_MASK             CANTXIDR1_ID17_MASK
#define CAN0TXIDR1_IDE_MASK              CANTXIDR1_IDE_MASK
#define CAN0TXIDR1_SRR_MASK              CANTXIDR1_SRR_MASK
#define CAN0TXIDR1_ID18_MASK             CANTXIDR1_ID18_MASK
#define CAN0TXIDR1_ID19_MASK             CANTXIDR1_ID19_MASK
#define CAN0TXIDR1_ID20_MASK             CANTXIDR1_ID20_MASK
#define CAN0TXIDR1_ID_15_MASK            CANTXIDR1_ID_15_MASK
#define CAN0TXIDR1_ID_15_BITNUM          CANTXIDR1_ID_15_BITNUM
#define CAN0TXIDR1_ID_18_MASK            CANTXIDR1_ID_18_MASK
#define CAN0TXIDR1_ID_18_BITNUM          CANTXIDR1_ID_18_BITNUM
#define CAN0TXIDR2                       CANTXIDR2
#define CAN0TXIDR2_ID7                   CANTXIDR2_ID7
#define CAN0TXIDR2_ID8                   CANTXIDR2_ID8
#define CAN0TXIDR2_ID9                   CANTXIDR2_ID9
#define CAN0TXIDR2_ID10                  CANTXIDR2_ID10
#define CAN0TXIDR2_ID11                  CANTXIDR2_ID11
#define CAN0TXIDR2_ID12                  CANTXIDR2_ID12
#define CAN0TXIDR2_ID13                  CANTXIDR2_ID13
#define CAN0TXIDR2_ID14                  CANTXIDR2_ID14
#define CAN0TXIDR2_ID7_MASK              CANTXIDR2_ID7_MASK
#define CAN0TXIDR2_ID8_MASK              CANTXIDR2_ID8_MASK
#define CAN0TXIDR2_ID9_MASK              CANTXIDR2_ID9_MASK
#define CAN0TXIDR2_ID10_MASK             CANTXIDR2_ID10_MASK
#define CAN0TXIDR2_ID11_MASK             CANTXIDR2_ID11_MASK
#define CAN0TXIDR2_ID12_MASK             CANTXIDR2_ID12_MASK
#define CAN0TXIDR2_ID13_MASK             CANTXIDR2_ID13_MASK
#define CAN0TXIDR2_ID14_MASK             CANTXIDR2_ID14_MASK
#define CAN0TXIDR3                       CANTXIDR3
#define CAN0TXIDR3_RTR                   CANTXIDR3_RTR
#define CAN0TXIDR3_ID0                   CANTXIDR3_ID0
#define CAN0TXIDR3_ID1                   CANTXIDR3_ID1
#define CAN0TXIDR3_ID2                   CANTXIDR3_ID2
#define CAN0TXIDR3_ID3                   CANTXIDR3_ID3
#define CAN0TXIDR3_ID4                   CANTXIDR3_ID4
#define CAN0TXIDR3_ID5                   CANTXIDR3_ID5
#define CAN0TXIDR3_ID6                   CANTXIDR3_ID6
#define CAN0TXIDR3_ID                    CANTXIDR3_ID
#define CAN0TXIDR3_RTR_MASK              CANTXIDR3_RTR_MASK
#define CAN0TXIDR3_ID0_MASK              CANTXIDR3_ID0_MASK
#define CAN0TXIDR3_ID1_MASK              CANTXIDR3_ID1_MASK
#define CAN0TXIDR3_ID2_MASK              CANTXIDR3_ID2_MASK
#define CAN0TXIDR3_ID3_MASK              CANTXIDR3_ID3_MASK
#define CAN0TXIDR3_ID4_MASK              CANTXIDR3_ID4_MASK
#define CAN0TXIDR3_ID5_MASK              CANTXIDR3_ID5_MASK
#define CAN0TXIDR3_ID6_MASK              CANTXIDR3_ID6_MASK
#define CAN0TXIDR3_ID_MASK               CANTXIDR3_ID_MASK
#define CAN0TXIDR3_ID_BITNUM             CANTXIDR3_ID_BITNUM
#define CAN0TXDSR0                       CANTXDSR0
#define CAN0TXDSR0_DB0                   CANTXDSR0_DB0
#define CAN0TXDSR0_DB1                   CANTXDSR0_DB1
#define CAN0TXDSR0_DB2                   CANTXDSR0_DB2
#define CAN0TXDSR0_DB3                   CANTXDSR0_DB3
#define CAN0TXDSR0_DB4                   CANTXDSR0_DB4
#define CAN0TXDSR0_DB5                   CANTXDSR0_DB5
#define CAN0TXDSR0_DB6                   CANTXDSR0_DB6
#define CAN0TXDSR0_DB7                   CANTXDSR0_DB7
#define CAN0TXDSR_ARR                    CANTXDSR_ARR
#define CAN0TXDSR0_DB0_MASK              CANTXDSR0_DB0_MASK
#define CAN0TXDSR0_DB1_MASK              CANTXDSR0_DB1_MASK
#define CAN0TXDSR0_DB2_MASK              CANTXDSR0_DB2_MASK
#define CAN0TXDSR0_DB3_MASK              CANTXDSR0_DB3_MASK
#define CAN0TXDSR0_DB4_MASK              CANTXDSR0_DB4_MASK
#define CAN0TXDSR0_DB5_MASK              CANTXDSR0_DB5_MASK
#define CAN0TXDSR0_DB6_MASK              CANTXDSR0_DB6_MASK
#define CAN0TXDSR0_DB7_MASK              CANTXDSR0_DB7_MASK
#define CAN0TXDSR1                       CANTXDSR1
#define CAN0TXDSR1_DB0                   CANTXDSR1_DB0
#define CAN0TXDSR1_DB1                   CANTXDSR1_DB1
#define CAN0TXDSR1_DB2                   CANTXDSR1_DB2
#define CAN0TXDSR1_DB3                   CANTXDSR1_DB3
#define CAN0TXDSR1_DB4                   CANTXDSR1_DB4
#define CAN0TXDSR1_DB5                   CANTXDSR1_DB5
#define CAN0TXDSR1_DB6                   CANTXDSR1_DB6
#define CAN0TXDSR1_DB7                   CANTXDSR1_DB7
#define CAN0TXDSR1_DB0_MASK              CANTXDSR1_DB0_MASK
#define CAN0TXDSR1_DB1_MASK              CANTXDSR1_DB1_MASK
#define CAN0TXDSR1_DB2_MASK              CANTXDSR1_DB2_MASK
#define CAN0TXDSR1_DB3_MASK              CANTXDSR1_DB3_MASK
#define CAN0TXDSR1_DB4_MASK              CANTXDSR1_DB4_MASK
#define CAN0TXDSR1_DB5_MASK              CANTXDSR1_DB5_MASK
#define CAN0TXDSR1_DB6_MASK              CANTXDSR1_DB6_MASK
#define CAN0TXDSR1_DB7_MASK              CANTXDSR1_DB7_MASK
#define CAN0TXDSR2                       CANTXDSR2
#define CAN0TXDSR2_DB0                   CANTXDSR2_DB0
#define CAN0TXDSR2_DB1                   CANTXDSR2_DB1
#define CAN0TXDSR2_DB2                   CANTXDSR2_DB2
#define CAN0TXDSR2_DB3                   CANTXDSR2_DB3
#define CAN0TXDSR2_DB4                   CANTXDSR2_DB4
#define CAN0TXDSR2_DB5                   CANTXDSR2_DB5
#define CAN0TXDSR2_DB6                   CANTXDSR2_DB6
#define CAN0TXDSR2_DB7                   CANTXDSR2_DB7
#define CAN0TXDSR2_DB0_MASK              CANTXDSR2_DB0_MASK
#define CAN0TXDSR2_DB1_MASK              CANTXDSR2_DB1_MASK
#define CAN0TXDSR2_DB2_MASK              CANTXDSR2_DB2_MASK
#define CAN0TXDSR2_DB3_MASK              CANTXDSR2_DB3_MASK
#define CAN0TXDSR2_DB4_MASK              CANTXDSR2_DB4_MASK
#define CAN0TXDSR2_DB5_MASK              CANTXDSR2_DB5_MASK
#define CAN0TXDSR2_DB6_MASK              CANTXDSR2_DB6_MASK
#define CAN0TXDSR2_DB7_MASK              CANTXDSR2_DB7_MASK
#define CAN0TXDSR3                       CANTXDSR3
#define CAN0TXDSR3_DB0                   CANTXDSR3_DB0
#define CAN0TXDSR3_DB1                   CANTXDSR3_DB1
#define CAN0TXDSR3_DB2                   CANTXDSR3_DB2
#define CAN0TXDSR3_DB3                   CANTXDSR3_DB3
#define CAN0TXDSR3_DB4                   CANTXDSR3_DB4
#define CAN0TXDSR3_DB5                   CANTXDSR3_DB5
#define CAN0TXDSR3_DB6                   CANTXDSR3_DB6
#define CAN0TXDSR3_DB7                   CANTXDSR3_DB7
#define CAN0TXDSR3_DB0_MASK              CANTXDSR3_DB0_MASK
#define CAN0TXDSR3_DB1_MASK              CANTXDSR3_DB1_MASK
#define CAN0TXDSR3_DB2_MASK              CANTXDSR3_DB2_MASK
#define CAN0TXDSR3_DB3_MASK              CANTXDSR3_DB3_MASK
#define CAN0TXDSR3_DB4_MASK              CANTXDSR3_DB4_MASK
#define CAN0TXDSR3_DB5_MASK              CANTXDSR3_DB5_MASK
#define CAN0TXDSR3_DB6_MASK              CANTXDSR3_DB6_MASK
#define CAN0TXDSR3_DB7_MASK              CANTXDSR3_DB7_MASK
#define CAN0TXDSR4                       CANTXDSR4
#define CAN0TXDSR4_DB0                   CANTXDSR4_DB0
#define CAN0TXDSR4_DB1                   CANTXDSR4_DB1
#define CAN0TXDSR4_DB2                   CANTXDSR4_DB2
#define CAN0TXDSR4_DB3                   CANTXDSR4_DB3
#define CAN0TXDSR4_DB4                   CANTXDSR4_DB4
#define CAN0TXDSR4_DB5                   CANTXDSR4_DB5
#define CAN0TXDSR4_DB6                   CANTXDSR4_DB6
#define CAN0TXDSR4_DB7                   CANTXDSR4_DB7
#define CAN0TXDSR4_DB0_MASK              CANTXDSR4_DB0_MASK
#define CAN0TXDSR4_DB1_MASK              CANTXDSR4_DB1_MASK
#define CAN0TXDSR4_DB2_MASK              CANTXDSR4_DB2_MASK
#define CAN0TXDSR4_DB3_MASK              CANTXDSR4_DB3_MASK
#define CAN0TXDSR4_DB4_MASK              CANTXDSR4_DB4_MASK
#define CAN0TXDSR4_DB5_MASK              CANTXDSR4_DB5_MASK
#define CAN0TXDSR4_DB6_MASK              CANTXDSR4_DB6_MASK
#define CAN0TXDSR4_DB7_MASK              CANTXDSR4_DB7_MASK
#define CAN0TXDSR5                       CANTXDSR5
#define CAN0TXDSR5_DB0                   CANTXDSR5_DB0
#define CAN0TXDSR5_DB1                   CANTXDSR5_DB1
#define CAN0TXDSR5_DB2                   CANTXDSR5_DB2
#define CAN0TXDSR5_DB3                   CANTXDSR5_DB3
#define CAN0TXDSR5_DB4                   CANTXDSR5_DB4
#define CAN0TXDSR5_DB5                   CANTXDSR5_DB5
#define CAN0TXDSR5_DB6                   CANTXDSR5_DB6
#define CAN0TXDSR5_DB7                   CANTXDSR5_DB7
#define CAN0TXDSR5_DB0_MASK              CANTXDSR5_DB0_MASK
#define CAN0TXDSR5_DB1_MASK              CANTXDSR5_DB1_MASK
#define CAN0TXDSR5_DB2_MASK              CANTXDSR5_DB2_MASK
#define CAN0TXDSR5_DB3_MASK              CANTXDSR5_DB3_MASK
#define CAN0TXDSR5_DB4_MASK              CANTXDSR5_DB4_MASK
#define CAN0TXDSR5_DB5_MASK              CANTXDSR5_DB5_MASK
#define CAN0TXDSR5_DB6_MASK              CANTXDSR5_DB6_MASK
#define CAN0TXDSR5_DB7_MASK              CANTXDSR5_DB7_MASK
#define CAN0TXDSR6                       CANTXDSR6
#define CAN0TXDSR6_DB0                   CANTXDSR6_DB0
#define CAN0TXDSR6_DB1                   CANTXDSR6_DB1
#define CAN0TXDSR6_DB2                   CANTXDSR6_DB2
#define CAN0TXDSR6_DB3                   CANTXDSR6_DB3
#define CAN0TXDSR6_DB4                   CANTXDSR6_DB4
#define CAN0TXDSR6_DB5                   CANTXDSR6_DB5
#define CAN0TXDSR6_DB6                   CANTXDSR6_DB6
#define CAN0TXDSR6_DB7                   CANTXDSR6_DB7
#define CAN0TXDSR6_DB0_MASK              CANTXDSR6_DB0_MASK
#define CAN0TXDSR6_DB1_MASK              CANTXDSR6_DB1_MASK
#define CAN0TXDSR6_DB2_MASK              CANTXDSR6_DB2_MASK
#define CAN0TXDSR6_DB3_MASK              CANTXDSR6_DB3_MASK
#define CAN0TXDSR6_DB4_MASK              CANTXDSR6_DB4_MASK
#define CAN0TXDSR6_DB5_MASK              CANTXDSR6_DB5_MASK
#define CAN0TXDSR6_DB6_MASK              CANTXDSR6_DB6_MASK
#define CAN0TXDSR6_DB7_MASK              CANTXDSR6_DB7_MASK
#define CAN0TXDSR7                       CANTXDSR7
#define CAN0TXDSR7_DB0                   CANTXDSR7_DB0
#define CAN0TXDSR7_DB1                   CANTXDSR7_DB1
#define CAN0TXDSR7_DB2                   CANTXDSR7_DB2
#define CAN0TXDSR7_DB3                   CANTXDSR7_DB3
#define CAN0TXDSR7_DB4                   CANTXDSR7_DB4
#define CAN0TXDSR7_DB5                   CANTXDSR7_DB5
#define CAN0TXDSR7_DB6                   CANTXDSR7_DB6
#define CAN0TXDSR7_DB7                   CANTXDSR7_DB7
#define CAN0TXDSR7_DB0_MASK              CANTXDSR7_DB0_MASK
#define CAN0TXDSR7_DB1_MASK              CANTXDSR7_DB1_MASK
#define CAN0TXDSR7_DB2_MASK              CANTXDSR7_DB2_MASK
#define CAN0TXDSR7_DB3_MASK              CANTXDSR7_DB3_MASK
#define CAN0TXDSR7_DB4_MASK              CANTXDSR7_DB4_MASK
#define CAN0TXDSR7_DB5_MASK              CANTXDSR7_DB5_MASK
#define CAN0TXDSR7_DB6_MASK              CANTXDSR7_DB6_MASK
#define CAN0TXDSR7_DB7_MASK              CANTXDSR7_DB7_MASK
#define CAN0TXDLR                        CANTXDLR
#define CAN0TXDLR_DLC0                   CANTXDLR_DLC0
#define CAN0TXDLR_DLC1                   CANTXDLR_DLC1
#define CAN0TXDLR_DLC2                   CANTXDLR_DLC2
#define CAN0TXDLR_DLC3                   CANTXDLR_DLC3
#define CAN0TXDLR_DLC                    CANTXDLR_DLC
#define CAN0TXDLR_DLC0_MASK              CANTXDLR_DLC0_MASK
#define CAN0TXDLR_DLC1_MASK              CANTXDLR_DLC1_MASK
#define CAN0TXDLR_DLC2_MASK              CANTXDLR_DLC2_MASK
#define CAN0TXDLR_DLC3_MASK              CANTXDLR_DLC3_MASK
#define CAN0TXDLR_DLC_MASK               CANTXDLR_DLC_MASK
#define CAN0TXDLR_DLC_BITNUM             CANTXDLR_DLC_BITNUM
#define CAN0TXTBPR                       CANTXTBPR
#define CAN0TXTBPR_PRIO0                 CANTXTBPR_PRIO0
#define CAN0TXTBPR_PRIO1                 CANTXTBPR_PRIO1
#define CAN0TXTBPR_PRIO2                 CANTXTBPR_PRIO2
#define CAN0TXTBPR_PRIO3                 CANTXTBPR_PRIO3
#define CAN0TXTBPR_PRIO4                 CANTXTBPR_PRIO4
#define CAN0TXTBPR_PRIO5                 CANTXTBPR_PRIO5
#define CAN0TXTBPR_PRIO6                 CANTXTBPR_PRIO6
#define CAN0TXTBPR_PRIO7                 CANTXTBPR_PRIO7
#define CAN0TXTBPR_PRIO0_MASK            CANTXTBPR_PRIO0_MASK
#define CAN0TXTBPR_PRIO1_MASK            CANTXTBPR_PRIO1_MASK
#define CAN0TXTBPR_PRIO2_MASK            CANTXTBPR_PRIO2_MASK
#define CAN0TXTBPR_PRIO3_MASK            CANTXTBPR_PRIO3_MASK
#define CAN0TXTBPR_PRIO4_MASK            CANTXTBPR_PRIO4_MASK
#define CAN0TXTBPR_PRIO5_MASK            CANTXTBPR_PRIO5_MASK
#define CAN0TXTBPR_PRIO6_MASK            CANTXTBPR_PRIO6_MASK
#define CAN0TXTBPR_PRIO7_MASK            CANTXTBPR_PRIO7_MASK
#define CAN0TXTSRH                       CANTXTSRH
#define CAN0TXTSRH_TSR8                  CANTXTSRH_TSR8
#define CAN0TXTSRH_TSR9                  CANTXTSRH_TSR9
#define CAN0TXTSRH_TSR10                 CANTXTSRH_TSR10
#define CAN0TXTSRH_TSR11                 CANTXTSRH_TSR11
#define CAN0TXTSRH_TSR12                 CANTXTSRH_TSR12
#define CAN0TXTSRH_TSR13                 CANTXTSRH_TSR13
#define CAN0TXTSRH_TSR14                 CANTXTSRH_TSR14
#define CAN0TXTSRH_TSR15                 CANTXTSRH_TSR15
#define CAN0TXTSRH_TSR8_MASK             CANTXTSRH_TSR8_MASK
#define CAN0TXTSRH_TSR9_MASK             CANTXTSRH_TSR9_MASK
#define CAN0TXTSRH_TSR10_MASK            CANTXTSRH_TSR10_MASK
#define CAN0TXTSRH_TSR11_MASK            CANTXTSRH_TSR11_MASK
#define CAN0TXTSRH_TSR12_MASK            CANTXTSRH_TSR12_MASK
#define CAN0TXTSRH_TSR13_MASK            CANTXTSRH_TSR13_MASK
#define CAN0TXTSRH_TSR14_MASK            CANTXTSRH_TSR14_MASK
#define CAN0TXTSRH_TSR15_MASK            CANTXTSRH_TSR15_MASK
#define CAN0TXTSRL                       CANTXTSRL
#define CAN0TXTSRL_TSR0                  CANTXTSRL_TSR0
#define CAN0TXTSRL_TSR1                  CANTXTSRL_TSR1
#define CAN0TXTSRL_TSR2                  CANTXTSRL_TSR2
#define CAN0TXTSRL_TSR3                  CANTXTSRL_TSR3
#define CAN0TXTSRL_TSR4                  CANTXTSRL_TSR4
#define CAN0TXTSRL_TSR5                  CANTXTSRL_TSR5
#define CAN0TXTSRL_TSR6                  CANTXTSRL_TSR6
#define CAN0TXTSRL_TSR7                  CANTXTSRL_TSR7
#define CAN0TXTSRL_TSR0_MASK             CANTXTSRL_TSR0_MASK
#define CAN0TXTSRL_TSR1_MASK             CANTXTSRL_TSR1_MASK
#define CAN0TXTSRL_TSR2_MASK             CANTXTSRL_TSR2_MASK
#define CAN0TXTSRL_TSR3_MASK             CANTXTSRL_TSR3_MASK
#define CAN0TXTSRL_TSR4_MASK             CANTXTSRL_TSR4_MASK
#define CAN0TXTSRL_TSR5_MASK             CANTXTSRL_TSR5_MASK
#define CAN0TXTSRL_TSR6_MASK             CANTXTSRL_TSR6_MASK
#define CAN0TXTSRL_TSR7_MASK             CANTXTSRL_TSR7_MASK
#define CAN0TXTSR                        CANTXTSR
#define CAN0TXTSR_TSR0                   CANTXTSR_TSR0
#define CAN0TXTSR_TSR1                   CANTXTSR_TSR1
#define CAN0TXTSR_TSR2                   CANTXTSR_TSR2
#define CAN0TXTSR_TSR3                   CANTXTSR_TSR3
#define CAN0TXTSR_TSR4                   CANTXTSR_TSR4
#define CAN0TXTSR_TSR5                   CANTXTSR_TSR5
#define CAN0TXTSR_TSR6                   CANTXTSR_TSR6
#define CAN0TXTSR_TSR7                   CANTXTSR_TSR7
#define CAN0TXTSR_TSR8                   CANTXTSR_TSR8
#define CAN0TXTSR_TSR9                   CANTXTSR_TSR9
#define CAN0TXTSR_TSR10                  CANTXTSR_TSR10
#define CAN0TXTSR_TSR11                  CANTXTSR_TSR11
#define CAN0TXTSR_TSR12                  CANTXTSR_TSR12
#define CAN0TXTSR_TSR13                  CANTXTSR_TSR13
#define CAN0TXTSR_TSR14                  CANTXTSR_TSR14
#define CAN0TXTSR_TSR15                  CANTXTSR_TSR15
#define CAN0TXTSR_TSR0_MASK              CANTXTSR_TSR0_MASK
#define CAN0TXTSR_TSR1_MASK              CANTXTSR_TSR1_MASK
#define CAN0TXTSR_TSR2_MASK              CANTXTSR_TSR2_MASK
#define CAN0TXTSR_TSR3_MASK              CANTXTSR_TSR3_MASK
#define CAN0TXTSR_TSR4_MASK              CANTXTSR_TSR4_MASK
#define CAN0TXTSR_TSR5_MASK              CANTXTSR_TSR5_MASK
#define CAN0TXTSR_TSR6_MASK              CANTXTSR_TSR6_MASK
#define CAN0TXTSR_TSR7_MASK              CANTXTSR_TSR7_MASK
#define CAN0TXTSR_TSR8_MASK              CANTXTSR_TSR8_MASK
#define CAN0TXTSR_TSR9_MASK              CANTXTSR_TSR9_MASK
#define CAN0TXTSR_TSR10_MASK             CANTXTSR_TSR10_MASK
#define CAN0TXTSR_TSR11_MASK             CANTXTSR_TSR11_MASK
#define CAN0TXTSR_TSR12_MASK             CANTXTSR_TSR12_MASK
#define CAN0TXTSR_TSR13_MASK             CANTXTSR_TSR13_MASK
#define CAN0TXTSR_TSR14_MASK             CANTXTSR_TSR14_MASK
#define CAN0TXTSR_TSR15_MASK             CANTXTSR_TSR15_MASK

#define B_WD_CTLH_WDSTM                  B_WD_CTLH_WDTSTM
#define B_WD_CTLH_WDSTM_MASK             B_WD_CTLH_WDTSTM_MASK
#define B_WD_CTL_WDSTM                   B_WD_CTL_WDTSTM
#define B_WD_CTL_WDSTM_MASK              B_WD_CTL_WDTSTM_MASK
#define B_GPIO_PUC_PUE5                  This_symb_has_been_depreciated
#define B_GPIO_PUC_PUE5_MASK             This_symb_has_been_depreciated
#define B_TRIM_BG0L_TCIBG2               B_TRIM_BG0L_TCBG2
#define B_TRIM_BG0L_TCIBG2_MASK          B_TRIM_BG0L_TCBG2_MASK
#define B_TRIM_BG0L_TCIBG2_BITNUM        B_TRIM_BG0L_TCBG2_BITNUM
#define NB_WD_CTLH_WDSTM                 NB_WD_CTLH_WDTSTM
#define NB_WD_CTLH_WDSTM_MASK            NB_WD_CTLH_WDTSTM_MASK
#define NB_WD_CTL_WDSTM                  NB_WD_CTL_WDTSTM
#define NB_WD_CTL_WDSTM_MASK             NB_WD_CTL_WDTSTM_MASK
#define NB_GPIO_PUC_PUE5                 This_symb_has_been_depreciated
#define NB_GPIO_PUC_PUE5_MASK            This_symb_has_been_depreciated
#define NB_TRIM_BG0L_TCIBG2              NB_TRIM_BG0L_TCBG2
#define NB_TRIM_BG0L_TCIBG2_MASK         NB_TRIM_BG0L_TCBG2_MASK
#define NB_TRIM_BG0L_TCIBG2_BITNUM       NB_TRIM_BG0L_TCBG2_BITNUM

#define B_GPIO_CTL_PE0                  This_symb_has_been_depreciated
#define B_GPIO_CTL_PE0M                 This_symb_has_been_depreciated
#define B_GPIO_CTL_PE0_MASK             This_symb_has_been_depreciated
#define B_GPIO_CTL_PE0M_MASK            This_symb_has_been_depreciated
#define NB_GPIO_CTL_PE0                 This_symb_has_been_depreciated
#define NB_GPIO_CTL_PE0M                This_symb_has_been_depreciated
#define NB_GPIO_CTL_PE0_MASK            This_symb_has_been_depreciated
#define NB_GPIO_CTL_PE0M_MASK           This_symb_has_been_depreciated
#define B_GPIO_CTL_PE_MASK              This_symb_has_been_depreciated
#define B_GPIO_CTL_PE_BITNUM            This_symb_has_been_depreciated
#define NB_GPIO_CTL_PE_MASK             This_symb_has_been_depreciated
#define NB_GPIO_CTL_PE_BITNUM           This_symb_has_been_depreciated

/*lint -restore  +esym(960,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
#endif
/*lint -restore Enable MISRA rule (5.1) checking. */
