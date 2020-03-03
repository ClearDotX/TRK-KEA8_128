/* Based on DataSheet : MM912J637 Rev. 0.9 Apr, 2010 */

#include "mm912j637.h"

/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
volatile INT_VECTSTR _INT_VECT;                               /* Interrupt vector register; 0x0A */

volatile WD_SRSTR  _WD_SR;                                     /* Watchdog status register; 0x12 */
volatile WD_RRSTR  _WD_RR;                                      /* Watchdog rearm register; 0x14 */

volatile SCIC1STR  _SCIC1;                                       /* SCI Control Register 1; 0x1A */
volatile SCIC2STR  _SCIC2;                                       /* SCI Control Register 2; 0x1B */
volatile SCIS1STR  _SCIS1;                                        /* SCI Status Register 1; 0x1C */
volatile SCIS2STR  _SCIS2;                                        /* SCI Status Register 2; 0x1D */
volatile SCIS3STR  _SCIS3;                                        /* SCI Status Register 3; 0x1E */
volatile SCIDSTR   _SCID;                                             /* SCI Data Register; 0x1F */

volatile TIOSSTR   _TIOS;                     /* Timer Input Capture/Output Compare Select; 0x20 */
volatile CFORCSTR  _CFORC;                                 /* Timer Compare Force Register; 0x21 */
volatile OC3MSTR   _OC3M;                                /* Output Compare 3 Mask Register; 0x22 */
volatile OC3DSTR   _OC3D;                                /* Output Compare 3 Data Register; 0x23 */
volatile TSCR1STR  _TSCR1;                              /* Timer System Control Register 1; 0x26 */
volatile TTOVSTR   _TTOV;                                /* Timer Toggle Overflow Register; 0x27 */
volatile TCTL1STR  _TCTL1;                                     /* Timer Control Register 1; 0x28 */
volatile TCTL2STR  _TCTL2;                                     /* Timer Control Register 2; 0x29 */
volatile TIESTR    _TIE;                                /* Timer Interrupt Enable Register; 0x2A */
volatile TSCR2STR  _TSCR2;                              /* Timer System Control Register 2; 0x2B */
volatile TFLG1STR  _TFLG1;                                  /* Main Timer Interrupt Flag 1; 0x2C */
volatile TFLG2STR  _TFLG2;                                  /* Main Timer Interrupt Flag 2; 0x2D */

volatile LTC_SRSTR   _LTC_SR;                         /* Life Time Counter Status register; 0x3A */

volatile GPIO_PUCSTR  _GPIO_PUC;                             /* GPIO pull up configuration; 0x42 */
volatile GPIO_DATASTR _GPIO_DATA;                               /* GPIO port data register; 0x43 */

volatile ACQ_DECSTR    _ACQ_DEC;                                        /* Decimation rate; 0x60 */
volatile ACQ_BGCSTR    _ACQ_BGC;                                        /* BandGap control; 0x61 */
volatile ACQ_GAINSTR   _ACQ_GAIN;                                              /* PGA gain; 0x62 */
volatile ACQ_GCBSTR    _ACQ_GCB;                                          /* GCB threshold; 0x63 */
volatile ACQ_LPFCSTR   _ACQ_LPFC;                    /* Low pass filter coefficient number; 0x6E */
volatile ACQ_THFSTR    _ACQ_THF;           /* Low power current threshold filtering period; 0x72 */
volatile ACQ_CTHSTR    _ACQ_CTH;                            /* Low power current threshold; 0x76 */

volatile COMP_SRSTR  _COMP_SR;                             /* Compensation status register; 0xA2 */
volatile COMP_TFSTR  _COMP_TF;                             /* Temperature Filtering Period; 0xA3 */
volatile COMP_VOSTR  _COMP_VO;                              /* Offset voltage compensation; 0xAA */
volatile COMP_IOSTR  _COMP_IO;                              /* Offset current compensation; 0xAB */

volatile DFT_IDSTR _DFT_ID;                                     /* Chip mask id revision;   0xFA */
                    
/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
volatile PCR_CTLSTR   _PCR_CTL;                                /* PCR control register;     0x00 */
volatile PCR_SRSTR    _PCR_SR;                                 /* PCR status register;      0x02 */
volatile PCR_PRESCSTR _PCR_PRESC;                              /* PCR 1ms prescaler;        0x04 */
volatile PCR_WUESTR   _PCR_WUE;                                /* Wake up enable register;  0x06 */

volatile INT_SRCSTR  _INT_SRC;                                 /* Interrupt source register;0x08 */
volatile INT_MSKSTR  _INT_MSK;                                 /* Interrupt mask register;  0x0C */

volatile TRIM_ALFSTR _TRIM_ALF;                                /* ALF Clk Trim Register;    0x0E */

volatile WD_CTLSTR   _WD_CTL;                                  /* Watchdog control register;0x10 */

volatile SCIBDSTR    _SCIBD;                                   /* SCI Baud Rate Register;   0x18 */

volatile TCNTSTR _TCNT;                                            /* Timer Count Register; 0x24 */
volatile TC0STR  _TC0;                    /* Timer Input Capture/Output Compare Register 0; 0x2E */
volatile TC1STR  _TC1;                    /* Timer Input Capture/Output Compare Register 1; 0x30 */
volatile TC2STR  _TC2;                    /* Timer Input Capture/Output Compare Register 2; 0x32 */
volatile TC3STR  _TC3;                    /* Timer Input Capture/Output Compare Register 3; 0x34 */

volatile LTC_CTLSTR  _LTC_CTL;                       /* Life Time Counter control register; 0x38 */
volatile LTC_CNT1STR _LTC_CNT1;                            /* Life Time Counter Register 1; 0x3C */
volatile LTC_CNT0STR _LTC_CNT0;                            /* Life Time Counter Register 0; 0x3E */

volatile GPIO_CTLSTR _GPIO_CTL;                                /* GPIO control register;    0x40 */
volatile GPIO_IO0STR _GPIO_IO0;                                /* Port 0 I/O configuration; 0x44 */
volatile GPIO_IO1STR _GPIO_IO1;                                /* Port 1 I/O configuration; 0x46 */
volatile GPIO_IO2STR _GPIO_IO2;                                /* Port 2 I/O configuration; 0x48 */
volatile GPIO_I3STR  _GPIO_I3;                                 /* Port 3 I configuration;   0x4A */

volatile LIN_CTLSTR  _LIN_CTL;                                 /* LIN control register;     0x50 */
volatile LIN_SRSTR   _LIN_SR;                                  /* LIN status register;      0x52 */
volatile LIN_RXTXSTR _LIN_RXTX;                                /* LIN Rx/TX line definition;0x54 */

volatile ACQ_CTLSTR   _ACQ_CTL;                            /* Acquisition control register; 0x58 */
volatile ACQ_SRSTR    _ACQ_SR;                             /* Acquisition status register;  0x5A */
volatile ACQ_ACC1STR  _ACQ_ACC1;                           /* Acquisition chain control 1;  0x5C */
volatile ACQ_ACC0STR  _ACQ_ACC0;                           /* Acquisition chain control 0;  0x5E */
volatile ACQ_ITEMPSTR _ACQ_ITEMP;                      /* Internal temperature measurement; 0x64 */
volatile ACQ_ETEMPSTR _ACQ_ETEMP;                      /* External temperature measurement; 0x66 */
volatile ACQ_CURR1STR _ACQ_CURR1;                              /* Current measurement 1;    0x68 */
volatile ACQ_CURR0STR _ACQ_CURR0;                              /* Current measurement 0;    0x6A */
volatile ACQ_VOLTSTR  _ACQ_VOLT;                               /* Voltage measurement;      0x6C */
volatile ACQ_TCMPSTR  _ACQ_TCMP;           /* Low power trigger current measurement period; 0x70 */
volatile ACQ_CVCRSTR  _ACQ_CVCR;           /* Current and Voltage Chopper Control Register; 0x74 */
volatile ACQ_AHTH1STR _ACQ_AHTH1;                      /* Low power Ah counter threshold 1; 0x78 */
volatile ACQ_AHTH0STR _ACQ_AHTH0;                      /* Low power Ah counter threshold 0; 0x7A */
volatile ACQ_AHC1STR  _ACQ_AHC1;                               /* Low power Ah counter 1;   0x7C */
volatile ACQ_AHC0STR  _ACQ_AHC0;                               /* Low power Ah counter 0;   0x7E */
                     
volatile LPF_A0STR  _LPF_A0;                                   /* A0 filter coeff;          0x80 */
volatile LPF_A1STR  _LPF_A1;                                   /* A1 filter coeff;          0x82 */
volatile LPF_A2STR  _LPF_A2;                                   /* A2 filter coeff;          0x84 */
volatile LPF_A3STR  _LPF_A3;                                   /* A3 filter coeff;          0x86 */
volatile LPF_A4STR  _LPF_A4;                                   /* A4 filter coeff;          0x88 */
volatile LPF_A5STR  _LPF_A5;                                   /* A5 filter coeff;          0x8A */
volatile LPF_A6STR  _LPF_A6;                                   /* A6 filter coeff;          0x8C */
volatile LPF_A7STR  _LPF_A7;                                   /* A7 filter coeff;          0x8E */
volatile LPF_A8STR  _LPF_A8;                                   /* A8 filter coeff;          0x90 */
volatile LPF_A9STR  _LPF_A9;                                   /* A9 filter coeff;          0x92 */
volatile LPF_A10STR _LPF_A10;                                  /* A10 filter coeff;         0x94 */
volatile LPF_A11STR _LPF_A11;                                  /* A11 filter coeff;         0x96 */
volatile LPF_A12STR _LPF_A12;                                  /* A12 filter coeff;         0x98 */
volatile LPF_A13STR _LPF_A13;                                  /* A13 filter coeff;         0x9A */
volatile LPF_A14STR _LPF_A14;                                  /* A14 filter coeff;         0x9C */
volatile LPF_A15STR _LPF_A15;                                  /* A15 filter coeff;         0x9E */

volatile COMP_CTLSTR   _COMP_CTL;                         /* Compensation control register; 0xA0 */
volatile COMP_TMAXSTR  _COMP_TMAX;                              /* Max temp before recalib; 0xA4 */
volatile COMP_TMINSTR  _COMP_TMIN;                              /* Min temp before recalib; 0xA6 */

volatile COMP_VSGSTR   _COMP_VSG;         /* Gain voltage compensation for voltage channel; 0xAC */

volatile COMP_IG4STR   _COMP_IG4;                          /* Gain current compensation 4;  0xB0 */
volatile COMP_IG8STR   _COMP_IG8;                          /* Gain current compensation 8;  0xB2 */
volatile COMP_IG16STR  _COMP_IG16;                         /* Gain current compensation 16; 0xB4 */
volatile COMP_IG32STR  _COMP_IG32;                         /* Gain current compensation 32; 0xB6 */
volatile COMP_IG64STR  _COMP_IG64;                         /* Gain current compensation 4;  0xB8 */
volatile COMP_IG128STR _COMP_IG128;                        /* Gain current compensation 8;  0xBA */
volatile COMP_IG256STR _COMP_IG256;                        /* Gain current compensation 16; 0xBC */
volatile COMP_IG512STR _COMP_IG512;                        /* Gain current compensation 32; 0xBE */

volatile COMP_PGAO4STR   _COMP_PGAO4;                      /* Offset PGA compensation 4;   0xC0 */
volatile COMP_PGAO8STR   _COMP_PGAO8;                      /* Offset PGA compensation 8;   0xC2 */
volatile COMP_PGAO16STR  _COMP_PGAO16;                     /* Offset PGA compensation 16;  0xC4 */
volatile COMP_PGAO32STR  _COMP_PGAO32;                     /* Offset PGA compensation 32;  0xC6 */
volatile COMP_PGAO64STR  _COMP_PGAO64;                     /* Offset PGA compensation 64;  0xC8 */
volatile COMP_PGAO128STR _COMP_PGAO128;                    /* Offset PGA compensation 128; 0xCA */
volatile COMP_PGAO256STR _COMP_PGAO256;                    /* Offset PGA compensation 256; 0xCC */
volatile COMP_PGAO512STR _COMP_PGAO512;                    /* Offset PGA compensation 512; 0xCE */

volatile COMP_ITSTR _COMP_IT;            /* Internal temperature offset/gain compensation; 0xD0 */
volatile COMP_ETSTR _COMP_ET;            /* External temperature offset/gain compensation; 0xD2 */

volatile TRIM_BG0STR _TRIM_BG0;                                   /* Bandgap 0 Trim;       0xE0 */
volatile TRIM_BG1STR _TRIM_BG1;                                   /* Bandgap 1 Trim;       0xE2 */
volatile TRIM_BG2STR _TRIM_BG2;                                   /* Bandgap 2 Trim;       0xE4 */
volatile TRIM_LINLVTSTR _TRIM_LINLVT;                             /* LIN + LVT Trim;       0xE6 */
volatile TRIM_OSCSTR _TRIM_OSC;                                   /* LP Oscillator Trim;   0xE8 */

/* EOF */

