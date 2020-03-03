/* Based on CPU DB MM9Z1x638_48, version 3.00.001 (RegistersPrg V2.33) */
/* DataSheet : MM9Z1_638 Rev. 0.071, August 2012 */

#include <mm9z1j638.h>

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile INT_XGPRIOSTR _INT_XGPRIO;                        /* XGATE Interrupt Priority Configuration Register; 0x00000016 */
volatile INT_CFADDRSTR _INT_CFADDR;                        /* Interrupt Request Configuration Address Register; 0x00000017 */
volatile INT_CFDATA0STR _INT_CFDATA0;                      /* Interrupt Request Configuration Data Register 0; 0x00000018 */
volatile INT_CFDATA1STR _INT_CFDATA1;                      /* Interrupt Request Configuration Data Register 1; 0x00000019 */
volatile INT_CFDATA2STR _INT_CFDATA2;                      /* Interrupt Request Configuration Data Register 2; 0x0000001A */
volatile INT_CFDATA3STR _INT_CFDATA3;                      /* Interrupt Request Configuration Data Register 3; 0x0000001B */
volatile INT_CFDATA4STR _INT_CFDATA4;                      /* Interrupt Request Configuration Data Register 4; 0x0000001C */
volatile INT_CFDATA5STR _INT_CFDATA5;                      /* Interrupt Request Configuration Data Register 5; 0x0000001D */
volatile INT_CFDATA6STR _INT_CFDATA6;                      /* Interrupt Request Configuration Data Register 6; 0x0000001E */
volatile INT_CFDATA7STR _INT_CFDATA7;                      /* Interrupt Request Configuration Data Register 7; 0x0000001F */
volatile MODESTR _MODE;                                    /* Mode Register; 0x00000070 */
volatile MMCPCHSTR _MMCPCH;                                /* Captured S12ZCPU Program Counter High; 0x00000085 */
volatile MMCPCMSTR _MMCPCM;                                /* Captured S12ZCPU Program Counter Middle; 0x00000086 */
volatile MMCPCLSTR _MMCPCL;                                /* Captured S12ZCPU Program Counter Low; 0x00000087 */
volatile DBGC1STR _DBGC1;                                  /* Debug Control Register 1; 0x00000100 */
volatile DBGC2STR _DBGC2;                                  /* Debug Control Register 2; 0x00000101 */
volatile DBGTCRHSTR _DBGTCRH;                              /* Debug Trace Control Register High; 0x00000102 */
volatile DBGTCRLSTR _DBGTCRL;                              /* Debug Trace Control Register Low; 0x00000103 */
volatile DBGCNTSTR _DBGCNT;                                /* Debug Count Register; 0x00000106 */
volatile DBGSCR1STR _DBGSCR1;                              /* Debug State Control Register 1; 0x00000107 */
volatile DBGSCR2STR _DBGSCR2;                              /* Debug State Control Register 2; 0x00000108 */
volatile DBGSCR3STR _DBGSCR3;                              /* Debug State Control Register 3; 0x00000109 */
volatile DBGEFRSTR _DBGEFR;                                /* Debug Event Flag Register; 0x0000010A */
volatile DBGSRSTR _DBGSR;                                  /* Debug Status Register; 0x0000010B */
volatile DBGACTLSTR _DBGACTL;                              /* Debug Comparator A Control Register; 0x00000110 */
volatile DBGAAHSTR _DBGAAH;                                /* Debug Comparator A Address Register High; 0x00000115 */
volatile DBGAAMSTR _DBGAAM;                                /* Debug Comparator A Address Register Middle; 0x00000116 */
volatile DBGAALSTR _DBGAAL;                                /* Debug Comparator A Address Register Low; 0x00000117 */
volatile DBGAD0STR _DBGAD0;                                /* Debug Comparator A Data Register 0; 0x00000118 */
volatile DBGAD1STR _DBGAD1;                                /* Debug Comparator A Data Register 1; 0x00000119 */
volatile DBGAD2STR _DBGAD2;                                /* Debug Comparator A Data Register 2; 0x0000011A */
volatile DBGAD3STR _DBGAD3;                                /* Debug Comparator A Data Register 3; 0x0000011B */
volatile DBGADM0STR _DBGADM0;                              /* Debug Comparator A Data Mask Register 0; 0x0000011C */
volatile DBGADM1STR _DBGADM1;                              /* Debug Comparator A Data Mask Register 1; 0x0000011D */
volatile DBGADM2STR _DBGADM2;                              /* Debug Comparator A Data Mask Register 2; 0x0000011E */
volatile DBGADM3STR _DBGADM3;                              /* Debug Comparator A Data Mask Register 3; 0x0000011F */
volatile DBGBCTLSTR _DBGBCTL;                              /* Debug Comparator B Control Register; 0x00000120 */
volatile DBGBAHSTR _DBGBAH;                                /* Debug Comparator B Address Register High; 0x00000125 */
volatile DBGBAMSTR _DBGBAM;                                /* Debug Comparator B Address Register Middle; 0x00000126 */
volatile DBGBALSTR _DBGBAL;                                /* Debug Comparator B Address Register Low; 0x00000127 */
volatile DBGCCTLSTR _DBGCCTL;                              /* Debug Comparator C Control Register; 0x00000130 */
volatile DBGCAHSTR _DBGCAH;                                /* Debug Comparator C Address Register High; 0x00000135 */
volatile DBGCAMSTR _DBGCAM;                                /* Debug Comparator C Address Register Middle; 0x00000136 */
volatile DBGCALSTR _DBGCAL;                                /* Debug Comparator C Address Register Low; 0x00000137 */
volatile DBGCD0STR _DBGCD0;                                /* Debug Comparator C Data Register 0; 0x00000138 */
volatile DBGCD1STR _DBGCD1;                                /* Debug Comparator C Data Register 1; 0x00000139 */
volatile DBGCD2STR _DBGCD2;                                /* Debug Comparator C Data Register 2; 0x0000013A */
volatile DBGCD3STR _DBGCD3;                                /* Debug Comparator C Data Register 3; 0x0000013B */
volatile DBGCDM0STR _DBGCDM0;                              /* Debug Comparator C Data Mask Register 0; 0x0000013C */
volatile DBGCDM1STR _DBGCDM1;                              /* Debug Comparator C Data Mask Register 1; 0x0000013D */
volatile DBGCDM2STR _DBGCDM2;                              /* Debug Comparator C Data Mask Register 2; 0x0000013E */
volatile DBGCDM3STR _DBGCDM3;                              /* Debug Comparator C Data Mask Register 3; 0x0000013F */
volatile DBGDCTLSTR _DBGDCTL;                              /* Debug Comparator D Control Register; 0x00000140 */
volatile DBGDAHSTR _DBGDAH;                                /* Debug Comparator D Address Register High; 0x00000145 */
volatile DBGDAMSTR _DBGDAM;                                /* Debug Comparator D Address Register Middle; 0x00000146 */
volatile DBGDALSTR _DBGDAL;                                /* Debug Comparator D Address Register Low; 0x00000147 */
volatile PTASTR _PTA;                                      /* Port A Data Register; 0x00000220 */
volatile PTBSTR _PTB;                                      /* Port B Data Register; 0x00000221 */
volatile PTIASTR _PTIA;                                    /* Port A Input Register; 0x00000222 */
volatile PTIBSTR _PTIB;                                    /* Port B Input Register; 0x00000223 */
volatile DDRASTR _DDRA;                                    /* Port A Data Direction Register; 0x00000224 */
volatile DDRBSTR _DDRB;                                    /* Port B Data Direction Register; 0x00000225 */
volatile PERASTR _PERA;                                    /* Port A Pull Device Enable Register; 0x00000226 */
volatile PERBSTR _PERB;                                    /* Port B Pull Device Enable Register; 0x00000227 */
volatile PPSASTR _PPSA;                                    /* Port A Polarity Select Register; 0x00000228 */
volatile PPSBSTR _PPSB;                                    /* Port B Polarity Select Register; 0x00000229 */
volatile RDRCSTR _RDRC;                                    /* Port C Reduced Drive Register; 0x0000025A */
volatile RDRDSTR _RDRD;                                    /* Port D Reduced Drive Register; 0x0000025B */
volatile FCLKDIVSTR _FCLKDIV;                              /* Flash Clock Divider Register; 0x00000380 */
volatile FSECSTR _FSEC;                                    /* Flash Security Register; 0x00000381 */
volatile FCCOBIXSTR _FCCOBIX;                              /* Flash CCOB Index Register; 0x00000382 */
volatile FPSTATSTR _FPSTAT;                                /* Flash Protection Status Register; 0x00000383 */
volatile FCNFGSTR _FCNFG;                                  /* Flash Configuration Register; 0x00000384 */
volatile FERCNFGSTR _FERCNFG;                              /* Flash Error Configuration Register; 0x00000385 */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register; 0x00000386 */
volatile FERSTATSTR _FERSTAT;                              /* Flash Error Status Register; 0x00000387 */
volatile FPROTSTR _FPROT;                                  /* P-Flash Protection Register; 0x00000388 */
volatile DFPROTSTR _DFPROT;                                /* D-Flash Protection Register; 0x00000389 */
volatile FOPTSTR _FOPT;                                    /* Flash Option Register; 0x0000038A */
volatile ECCSTATSTR _ECCSTAT;                              /* ECC Status Register; 0x000003C0 */
volatile ECCIESTR _ECCIE;                                  /* ECC Interrupt Enable Register; 0x000003C1 */
volatile ECCIFSTR _ECCIF;                                  /* ECC Interrupt Flag Register; 0x000003C2 */
volatile ECCDPTRHSTR _ECCDPTRH;                            /* ECC Debug Point Register High; 0x000003C7 */
volatile ECCDPTRMSTR _ECCDPTRM;                            /* ECC Debug Point Register Middle; 0x000003C8 */
volatile ECCDPTRLSTR _ECCDPTRL;                            /* ECC Debug Point Register Low; 0x000003C9 */
volatile ECCDESTR _ECCDE;                                  /* ECC Debug ECC; 0x000003CE */
volatile ECCDCMDSTR _ECCDCMD;                              /* ECC Debug Comamnd; 0x000003CF */
volatile CPMURFLGSTR _CPMURFLG;                            /* CPMU Reset Flags Register; 0x000006C3 */
volatile CPMUSYNRSTR _CPMUSYNR;                            /* CPMU Synthesizer Register; 0x000006C4 */
volatile CPMUREFDIVSTR _CPMUREFDIV;                        /* CPMU Reference Divider Register; 0x000006C5 */
volatile CPMUPOSTDIVSTR _CPMUPOSTDIV;                      /* CPMU Post Divider Register; 0x000006C6 */
volatile CPMUIFLGSTR _CPMUIFLG;                            /* CPMU Interrupt Flags Register; 0x000006C7 */
volatile CPMUINTSTR _CPMUINT;                              /* CPMU Interrupt Enable Register; 0x000006C8 */
volatile CPMUCLKSSTR _CPMUCLKS;                            /* CPMU Clock Select Register; 0x000006C9 */
volatile CPMUPLLSTR _CPMUPLL;                              /* CPMU PLL Control Register; 0x000006CA */
volatile CPMURTISTR _CPMURTI;                              /* CPMU RTI Control Register; 0x000006CB */
volatile CPMUCOPSTR _CPMUCOP;                              /* CPMU COP Control Register; 0x000006CC */
volatile CPMUARMCOPSTR _CPMUARMCOP;                        /* CPMU COP Timer Arm/Reset Register; 0x000006CF */
volatile CPMULVCTLSTR _CPMULVCTL;                          /* Low Voltage Control Register; 0x000006D1 */
volatile CPMUAPICTLSTR _CPMUAPICTL;                        /* Autonomous Periodical Interrupt Control Register; 0x000006D2 */
volatile CPMUACLKTRSTR _CPMUACLKTR;                        /* Autonomous Clock Trimming Register; 0x000006D3 */
volatile CPMUOSCSTR _CPMUOSC;                              /* CPMU Oscillator Register; 0x000006DA */
volatile CPMUPROTSTR _CPMUPROT;                            /* CPMUV1 Protection Register; 0x000006DB */
volatile CPMUOSC2STR _CPMUOSC2;                            /* CPMU Oscillator Register 2; 0x000006DE */
volatile SPICR1STR _SPICR1;                                /* SPI  Control Register 1; 0x00000780 */
volatile SPICR2STR _SPICR2;                                /* SPI  Control Register 2; 0x00000781 */
volatile SPIBRSTR _SPIBR;                                  /* SPI  Baud Rate Register; 0x00000782 */
volatile SPISRSTR _SPISR;                                  /* SPI  Status Register; 0x00000783 */
volatile D2DCTL0STR _D2DCTL0;                              /* D2D Control Register 0; 0x000007F0 */
volatile D2DCTL1STR _D2DCTL1;                              /* D2D Control Register 1; 0x000007F1 */
volatile D2DSTAT0STR _D2DSTAT0;                            /* D2D Status Register 0; 0x000007F2 */
volatile D2DSTAT1STR _D2DSTAT1;                            /* D2D Status Register 1; 0x000007F3 */
volatile CANCTL0STR _CANCTL0;                              /* MSCAN Control 0 Register; 0x00000800 */
volatile CANCTL1STR _CANCTL1;                              /* MSCAN Control 1 Register; 0x00000801 */
volatile CANBTR0STR _CANBTR0;                              /* MSCAN Bus Timing Register 0; 0x00000802 */
volatile CANBTR1STR _CANBTR1;                              /* MSCAN Bus Timing Register 1; 0x00000803 */
volatile CANRFLGSTR _CANRFLG;                              /* MSCAN Receiver Flag Register; 0x00000804 */
volatile CANRIERSTR _CANRIER;                              /* MSCAN Receiver Interrupt Enable Register; 0x00000805 */
volatile CANTFLGSTR _CANTFLG;                              /* MSCAN Transmitter Flag Register; 0x00000806 */
volatile CANTIERSTR _CANTIER;                              /* MSCAN Transmitter Interrupt Enable Register; 0x00000807 */
volatile CANTARQSTR _CANTARQ;                              /* MSCAN Transmitter Message Abort Request; 0x00000808 */
volatile CANTAAKSTR _CANTAAK;                              /* MSCAN Transmitter Message Abort Acknowledge; 0x00000809 */
volatile CANTBSELSTR _CANTBSEL;                            /* MSCAN Transmit Buffer Selection; 0x0000080A */
volatile CANIDACSTR _CANIDAC;                              /* MSCAN Identifier Acceptance Control Register; 0x0000080B */
volatile CANMISCSTR _CANMISC;                              /* MSCAN Miscellaneous Register; 0x0000080D */
volatile CANRXERRSTR _CANRXERR;                            /* MSCAN Receive Error Counter Register; 0x0000080E */
volatile CANTXERRSTR _CANTXERR;                            /* MSCAN Transmit Error Counter Register; 0x0000080F */
volatile CANIDAR0STR _CANIDAR0;                            /* MSCAN Identifier Acceptance Register 0; 0x00000810 */
volatile CANIDAR1STR _CANIDAR1;                            /* MSCAN Identifier Acceptance Register 1; 0x00000811 */
volatile CANIDAR2STR _CANIDAR2;                            /* MSCAN Identifier Acceptance Register 2; 0x00000812 */
volatile CANIDAR3STR _CANIDAR3;                            /* MSCAN Identifier Acceptance Register 3; 0x00000813 */
volatile CANIDMR0STR _CANIDMR0;                            /* MSCAN Identifier Mask Register 0; 0x00000814 */
volatile CANIDMR1STR _CANIDMR1;                            /* MSCAN Identifier Mask Register 1; 0x00000815 */
volatile CANIDMR2STR _CANIDMR2;                            /* MSCAN Identifier Mask Register 2; 0x00000816 */
volatile CANIDMR3STR _CANIDMR3;                            /* MSCAN Identifier Mask Register 3; 0x00000817 */
volatile CANIDAR4STR _CANIDAR4;                            /* MSCAN Identifier Acceptance Register 4; 0x00000818 */
volatile CANIDAR5STR _CANIDAR5;                            /* MSCAN Identifier Acceptance Register 5; 0x00000819 */
volatile CANIDAR6STR _CANIDAR6;                            /* MSCAN Identifier Acceptance Register 6; 0x0000081A */
volatile CANIDAR7STR _CANIDAR7;                            /* MSCAN Identifier Acceptance Register 7; 0x0000081B */
volatile CANIDMR4STR _CANIDMR4;                            /* MSCAN Identifier Mask Register 4; 0x0000081C */
volatile CANIDMR5STR _CANIDMR5;                            /* MSCAN Identifier Mask Register 5; 0x0000081D */
volatile CANIDMR6STR _CANIDMR6;                            /* MSCAN Identifier Mask Register 6; 0x0000081E */
volatile CANIDMR7STR _CANIDMR7;                            /* MSCAN Identifier Mask Register 7; 0x0000081F */
volatile CANRXIDR0STR _CANRXIDR0;                          /* MSCAN Receive Identifier Register 0; 0x00000820 */
volatile CANRXIDR1STR _CANRXIDR1;                          /* MSCAN Receive Identifier Register 1; 0x00000821 */
volatile CANRXIDR2STR _CANRXIDR2;                          /* MSCAN Receive Identifier Register 2; 0x00000822 */
volatile CANRXIDR3STR _CANRXIDR3;                          /* MSCAN Receive Identifier Register 3; 0x00000823 */
volatile CANRXDSR0STR _CANRXDSR0;                          /* MSCAN Receive Data Segment Register 0; 0x00000824 */
volatile CANRXDSR1STR _CANRXDSR1;                          /* MSCAN Receive Data Segment Register 1; 0x00000825 */
volatile CANRXDSR2STR _CANRXDSR2;                          /* MSCAN Receive Data Segment Register 2; 0x00000826 */
volatile CANRXDSR3STR _CANRXDSR3;                          /* MSCAN Receive Data Segment Register 3; 0x00000827 */
volatile CANRXDSR4STR _CANRXDSR4;                          /* MSCAN Receive Data Segment Register 4; 0x00000828 */
volatile CANRXDSR5STR _CANRXDSR5;                          /* MSCAN Receive Data Segment Register 5; 0x00000829 */
volatile CANRXDSR6STR _CANRXDSR6;                          /* MSCAN Receive Data Segment Register 6; 0x0000082A */
volatile CANRXDSR7STR _CANRXDSR7;                          /* MSCAN Receive Data Segment Register 7; 0x0000082B */
volatile CANRXDLRSTR _CANRXDLR;                            /* MSCAN Receive Data Length Register; 0x0000082C */
volatile CANTXIDR0STR _CANTXIDR0;                          /* MSCAN Transmit Identifier Register 0; 0x00000830 */
volatile CANTXIDR1STR _CANTXIDR1;                          /* MSCAN Transmit Identifier Register 1; 0x00000831 */
volatile CANTXIDR2STR _CANTXIDR2;                          /* MSCAN Transmit Identifier Register 2; 0x00000832 */
volatile CANTXIDR3STR _CANTXIDR3;                          /* MSCAN Transmit Identifier Register 3; 0x00000833 */
volatile CANTXDSR0STR _CANTXDSR0;                          /* MSCAN Transmit Data Segment Register 0; 0x00000834 */
volatile CANTXDSR1STR _CANTXDSR1;                          /* MSCAN Transmit Data Segment Register 1; 0x00000835 */
volatile CANTXDSR2STR _CANTXDSR2;                          /* MSCAN Transmit Data Segment Register 2; 0x00000836 */
volatile CANTXDSR3STR _CANTXDSR3;                          /* MSCAN Transmit Data Segment Register 3; 0x00000837 */
volatile CANTXDSR4STR _CANTXDSR4;                          /* MSCAN Transmit Data Segment Register 4; 0x00000838 */
volatile CANTXDSR5STR _CANTXDSR5;                          /* MSCAN Transmit Data Segment Register 5; 0x00000839 */
volatile CANTXDSR6STR _CANTXDSR6;                          /* MSCAN Transmit Data Segment Register 6; 0x0000083A */
volatile CANTXDSR7STR _CANTXDSR7;                          /* MSCAN Transmit Data Segment Register 7; 0x0000083B */
volatile CANTXDLRSTR _CANTXDLR;                            /* MSCAN Transmit Data Length Register; 0x0000083C */
volatile CANTXTBPRSTR _CANTXTBPR;                          /* MSCAN Transmit Buffer Priority; 0x0000083D */
volatile B_INT_VECTSTR _B_INT_VECT;                        /* Interrupt vector register; 0x00000E0A */
volatile B_WD_SRSTR _B_WD_SR;                              /* Watchdog status register; 0x00000E12 */
volatile B_WD_RRSTR _B_WD_RR;                              /* Watchdog rearm register; 0x00000E14 */
volatile B_SCIC1STR _B_SCIC1;                              /* SCI Control Register 1; 0x00000E1A */
volatile B_SCIC2STR _B_SCIC2;                              /* SCI Control Register 2; 0x00000E1B */
volatile B_SCIS1STR _B_SCIS1;                              /* SCI Status Register 1; 0x00000E1C */
volatile B_SCIS2STR _B_SCIS2;                              /* SCI Status Register 2; 0x00000E1D */
volatile B_SCIC3STR _B_SCIC3;                              /* SCI Control Register 3; 0x00000E1E */
volatile B_SCIDSTR _B_SCID;                                /* SCI Data Register; 0x00000E1F */
volatile B_TIOSSTR _B_TIOS;                                /* Timer Input Capture/Output Compare Select; 0x00000E20 */
volatile B_CFORCSTR _B_CFORC;                              /* Timer Compare Force Register; 0x00000E21 */
volatile B_OC3MSTR _B_OC3M;                                /* Output Compare 3 Mask Register; 0x00000E22 */
volatile B_OC3DSTR _B_OC3D;                                /* Output Compare 3 Data Register; 0x00000E23 */
volatile B_TSCR1STR _B_TSCR1;                              /* Timer System Control Register1; 0x00000E26 */
volatile B_TTOVSTR _B_TTOV;                                /* Timer Toggle On Overflow Register; 0x00000E27 */
volatile B_TCTL1STR _B_TCTL1;                              /* Timer Control Register 1; 0x00000E28 */
volatile B_TCTL2STR _B_TCTL2;                              /* Timer Control Register 2; 0x00000E29 */
volatile B_TIESTR _B_TIE;                                  /* Timer Interrupt Enable Register; 0x00000E2A */
volatile B_TSCR2STR _B_TSCR2;                              /* Timer System Control Register 2; 0x00000E2B */
volatile B_TFLG1STR _B_TFLG1;                              /* Main Timer Interrupt Flag 1; 0x00000E2C */
volatile B_TFLG2STR _B_TFLG2;                              /* Main Timer Interrupt Flag 2; 0x00000E2D */
volatile B_LTC_SRSTR _B_LTC_SR;                            /* Life Time Counter status register; 0x00000E3A */
volatile B_GPIO_PUCSTR _B_GPIO_PUC;                        /* GPIO pull up configuration; 0x00000E42 */
volatile B_GPIO_DATASTR _B_GPIO_DATA;                      /* GPIO port data register; 0x00000E43 */
volatile B_GPIO_IN1STR _B_GPIO_IN1;                        /* Port 1 input configuration; 0x00000E44 */
volatile B_GPIO_OUT1STR _B_GPIO_OUT1;                      /* Port 1 output configuration; 0x00000E45 */
volatile B_GPIO_IN2STR _B_GPIO_IN2;                        /* Port 2 input configuration; 0x00000E46 */
volatile B_GPIO_OUT2STR _B_GPIO_OUT2;                      /* Port 2 output configuration; 0x00000E47 */
volatile B_GPIO_IN3STR _B_GPIO_IN3;                        /* Port 3 input configuration; 0x00000E48 */
volatile B_GPIO_OUT3STR _B_GPIO_OUT3;                      /* Port 3 output configuration; 0x00000E49 */
volatile B_GPIO_IN4STR _B_GPIO_IN4;                        /* Port 4 input configuration; 0x00000E4A */
volatile B_GPIO_VSENSESTR _B_GPIO_VSENSE;                  /* GPIO Vsense Configuration; 0x00000E4B */
volatile B_GPIO_TSENSESTR _B_GPIO_TSENSE;                  /* GPIO Tsense Configuration; 0x00000E4C */
volatile B_LIN_TXSTR _B_LIN_TX;                            /* LIN transmit line definition; 0x00000E54 */
volatile B_LIN_RXSTR _B_LIN_RX;                            /* LIN receive line definition; 0x00000E55 */
volatile B_ACQ_DECSTR _B_ACQ_DEC;                          /* Decimation Rate; 0x00000E60 */
volatile B_ACQ_GAINSTR _B_ACQ_GAIN;                        /* PGA gain; 0x00000E62 */
volatile B_ACQ_GCBSTR _B_ACQ_GCB;                          /* PGA gain; 0x00000E63 */
volatile B_ACQ_LPFCSTR _B_ACQ_LPFC;                        /* Low pass filter coefficient number; 0x00000E6E */
volatile B_ACQ_THFSTR _B_ACQ_THF;                          /* Low power current threshold filtering period; 0x00000E72 */
volatile B_ACQ_CTHSTR _B_ACQ_CTH;                          /* Low power current threshold; 0x00000E76 */
volatile B_COMP_SRSTR _B_COMP_SR;                          /* Compensation status register; 0x00000EA2 */
volatile B_COMP_TFSTR _B_COMP_TF;                          /* Temperature filtering period; 0x00000EA3 */
volatile B_COMP_VOSTR _B_COMP_VO;                          /* Offset voltage compensation; 0x00000EAA */
volatile B_COMP_IOSTR _B_COMP_IO;                          /* Offset current compensation window; 0x00000EAB */
volatile B_COMP_ITOSTR _B_COMP_ITO;                        /* Internal temperature offset compensation; 0x00000ED0 */
volatile B_COMP_ITGSTR _B_COMP_ITG;                        /* Internal temperature gain compensation; 0x00000ED1 */
volatile B_COMP_ETOSTR _B_COMP_ETO;                        /* External temperature offset compensation; 0x00000ED2 */
volatile B_COMP_ETGSTR _B_COMP_ETG;                        /* External temperature gain compensation; 0x00000ED3 */
volatile B_TRIM_BG0HSTR _B_TRIM_BG0H;                      /* Trim bandgap 0 high; 0x00000EE0 */
volatile B_TRIM_BG0LSTR _B_TRIM_BG0L;                      /* Trim bandgap 0 low; 0x00000EE1 */
volatile B_TRIM_BG1HSTR _B_TRIM_BG1H;                      /* Trim bandgap 1 high; 0x00000EE2 */
volatile B_TRIM_BG1LSTR _B_TRIM_BG1L;                      /* Trim bandgap 1 low; 0x00000EE3 */
volatile B_TRIM_OSCHSTR _B_TRIM_OSCH;                      /* Trim LP oscillator high; 0x00000EE4 */
volatile B_TRIM_OSCLSTR _B_TRIM_OSCL;                      /* Trim LP oscillator low; 0x00000EE5 */
volatile NB_INT_VECTSTR _NB_INT_VECT;                      /* Interrupt vector register; 0x00000F0A */
volatile NB_WD_SRSTR _NB_WD_SR;                            /* Watchdog status register; 0x00000F12 */
volatile NB_WD_RRSTR _NB_WD_RR;                            /* Watchdog rearm register; 0x00000F14 */
volatile NB_SCIC1STR _NB_SCIC1;                            /* SCI Control Register 1; 0x00000F1A */
volatile NB_SCIC2STR _NB_SCIC2;                            /* SCI Control Register 2; 0x00000F1B */
volatile NB_SCIS1STR _NB_SCIS1;                            /* SCI Status Register 1; 0x00000F1C */
volatile NB_SCIS2STR _NB_SCIS2;                            /* SCI Status Register 2; 0x00000F1D */
volatile NB_SCIC3STR _NB_SCIC3;                            /* SCI Control Register 3; 0x00000F1E */
volatile NB_SCIDSTR _NB_SCID;                              /* SCI Data Register; 0x00000F1F */
volatile NB_TIOSSTR _NB_TIOS;                              /* Timer Input Capture/Output Compare Select; 0x00000F20 */
volatile NB_CFORCSTR _NB_CFORC;                            /* Timer Compare Force Register; 0x00000F21 */
volatile NB_OC3MSTR _NB_OC3M;                              /* Output Compare 3 Mask Register; 0x00000F22 */
volatile NB_OC3DSTR _NB_OC3D;                              /* Output Compare 3 Data Register; 0x00000F23 */
volatile NB_TSCR1STR _NB_TSCR1;                            /* Timer System Control Register1; 0x00000F26 */
volatile NB_TTOVSTR _NB_TTOV;                              /* Timer Toggle On Overflow Register; 0x00000F27 */
volatile NB_TCTL1STR _NB_TCTL1;                            /* Timer Control Register 1; 0x00000F28 */
volatile NB_TCTL2STR _NB_TCTL2;                            /* Timer Control Register 2; 0x00000F29 */
volatile NB_TIESTR _NB_TIE;                                /* Timer Interrupt Enable Register; 0x00000F2A */
volatile NB_TSCR2STR _NB_TSCR2;                            /* Timer System Control Register 2; 0x00000F2B */
volatile NB_TFLG1STR _NB_TFLG1;                            /* Main Timer Interrupt Flag 1; 0x00000F2C */
volatile NB_TFLG2STR _NB_TFLG2;                            /* Main Timer Interrupt Flag 2; 0x00000F2D */
volatile NB_LTC_SRSTR _NB_LTC_SR;                          /* Life Time Counter status register; 0x00000F3A */
volatile NB_GPIO_PUCSTR _NB_GPIO_PUC;                      /* GPIO pull up configuration; 0x00000F42 */
volatile NB_GPIO_DATASTR _NB_GPIO_DATA;                    /* GPIO port data register; 0x00000F43 */
volatile NB_GPIO_IN1STR _NB_GPIO_IN1;                      /* Port 1 input configuration; 0x00000F44 */
volatile NB_GPIO_OUT1STR _NB_GPIO_OUT1;                    /* Port 1 output configuration; 0x00000F45 */
volatile NB_GPIO_IN2STR _NB_GPIO_IN2;                      /* Port 2 input configuration; 0x00000F46 */
volatile NB_GPIO_OUT2STR _NB_GPIO_OUT2;                    /* Port 2 output configuration; 0x00000F47 */
volatile NB_GPIO_IN3STR _NB_GPIO_IN3;                      /* Port 3 input configuration; 0x00000F48 */
volatile NB_GPIO_OUT3STR _NB_GPIO_OUT3;                    /* Port 3 output configuration; 0x00000F49 */
volatile NB_GPIO_IN4STR _NB_GPIO_IN4;                      /* Port 4 input configuration; 0x00000F4A */
volatile NB_GPIO_VSENSESTR _NB_GPIO_VSENSE;                /* GPIO Vsense Configuration; 0x00000F4B */
volatile NB_GPIO_TSENSESTR _NB_GPIO_TSENSE;                /* GPIO Tsense Configuration; 0x00000F4C */
volatile NB_LIN_TXSTR _NB_LIN_TX;                          /* LIN transmit line definition; 0x00000F54 */
volatile NB_LIN_RXSTR _NB_LIN_RX;                          /* LIN receive line definition; 0x00000F55 */
volatile NB_ACQ_DECSTR _NB_ACQ_DEC;                        /* Decimation Rate; 0x00000F60 */
volatile NB_ACQ_GAINSTR _NB_ACQ_GAIN;                      /* PGA gain; 0x00000F62 */
volatile NB_ACQ_GCBSTR _NB_ACQ_GCB;                        /* PGA gain; 0x00000F63 */
volatile NB_ACQ_LPFCSTR _NB_ACQ_LPFC;                      /* Low pass filter coefficient number; 0x00000F6E */
volatile NB_ACQ_THFSTR _NB_ACQ_THF;                        /* Low power current threshold filtering period; 0x00000F72 */
volatile NB_ACQ_CTHSTR _NB_ACQ_CTH;                        /* Low power current threshold; 0x00000F76 */
volatile NB_COMP_SRSTR _NB_COMP_SR;                        /* Compensation status register; 0x00000FA2 */
volatile NB_COMP_TFSTR _NB_COMP_TF;                        /* Temperature filtering period; 0x00000FA3 */
volatile NB_COMP_VOSTR _NB_COMP_VO;                        /* Offset voltage compensation; 0x00000FAA */
volatile NB_COMP_IOSTR _NB_COMP_IO;                        /* Offset current compensation window; 0x00000FAB */
volatile NB_COMP_ITOSTR _NB_COMP_ITO;                      /* Internal temperature offset compensation; 0x00000FD0 */
volatile NB_COMP_ITGSTR _NB_COMP_ITG;                      /* Internal temperature gain compensation; 0x00000FD1 */
volatile NB_COMP_ETOSTR _NB_COMP_ETO;                      /* External temperature offset compensation; 0x00000FD2 */
volatile NB_COMP_ETGSTR _NB_COMP_ETG;                      /* External temperature gain compensation; 0x00000FD3 */
volatile NB_TRIM_BG0HSTR _NB_TRIM_BG0H;                    /* Trim bandgap 0 high; 0x00000FE0 */
volatile NB_TRIM_BG0LSTR _NB_TRIM_BG0L;                    /* Trim bandgap 0 low; 0x00000FE1 */
volatile NB_TRIM_BG1HSTR _NB_TRIM_BG1H;                    /* Trim bandgap 1 high; 0x00000FE2 */
volatile NB_TRIM_BG1LSTR _NB_TRIM_BG1L;                    /* Trim bandgap 1 low; 0x00000FE3 */
volatile NB_TRIM_OSCHSTR _NB_TRIM_OSCH;                    /* Trim LP oscillator high; 0x00000FE4 */
volatile NB_TRIM_OSCLSTR _NB_TRIM_OSCL;                    /* Trim LP oscillator low; 0x00000FE5 */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile IVBRSTR _IVBR;                                    /* Interrupt Vector Base Register; 0x00000010 */
volatile MMCECSTR _MMCEC;                                  /* Error code register; 0x00000080 */
volatile MMCCCRSTR _MMCCCR;                                /* Captured S12ZCPU Condition Code Register Low; 0x00000082 */
volatile DBGTBSTR _DBGTB;                                  /* Debug Trace Buffer Register; 0x00000104 */
volatile FCCOB0STR _FCCOB0;                                /* Flash Common Command Object Register; 0x0000038C */
volatile FCCOB1STR _FCCOB1;                                /* Flash Common Command Object Register; 0x0000038E */
volatile FCCOB2STR _FCCOB2;                                /* Flash Common Command Object Register; 0x00000390 */
volatile FCCOB3STR _FCCOB3;                                /* Flash Common Command Object Register; 0x00000392 */
volatile FCCOB4STR _FCCOB4;                                /* Flash Common Command Object Register; 0x00000394 */
volatile FCCOB5STR _FCCOB5;                                /* Flash Common Command Object Register; 0x00000396 */
volatile ECCDDSTR _ECCDD;                                  /* ECC Debug Data; 0x000003CC */
volatile CPMUAPIRSTR _CPMUAPIR;                            /* Autonomous Periodical Interrupt Rate Register; 0x000006D4 */
volatile CPMUIRCTRIMSTR _CPMUIRCTRIM;                      /* CPMU IRC1M Trim Registers; 0x000006D8 */
volatile SPIDRSTR _SPIDR;                                  /* SPI  Data Register; 0x00000784 */
volatile D2DADRSTR _D2DADR;                                /* D2D Address Buffer Register; 0x000007F4 */
volatile D2DDATASTR _D2DDATA;                              /* D2D Data Buffer Register; 0x000007F6 */
volatile CANRXTSRSTR _CANRXTSR;                            /* MSCAN Receive Time Stamp Register; 0x0000082E */
volatile CANTXTSRSTR _CANTXTSR;                            /* MSCAN Transmit Time Stamp Register; 0x0000083E */
volatile B_PCR_CTLSTR _B_PCR_CTL;                          /* PCR Control Register; 0x00000E00 */
volatile B_PCR_SRSTR _B_PCR_SR;                            /* PCR Status Register; 0x00000E02 */
volatile B_PCR_PRESCSTR _B_PCR_PRESC;                      /* PCR 1ms prescaler; 0x00000E04 */
volatile B_PCR_WUESTR _B_PCR_WUE;                          /* Wake Up Enable Register; 0x00000E06 */
volatile B_INT_SRCSTR _B_INT_SRC;                          /* Interrupt source register; 0x00000E08 */
volatile B_INT_MSKSTR _B_INT_MSK;                          /* Interrupt mask register; 0x00000E0C */
volatile B_TRIM_ALFSTR _B_TRIM_ALF;                        /* Trim for accurate 1ms low freq clock; 0x00000E0E */
volatile B_WD_CTLSTR _B_WD_CTL;                            /* Watchdog control register; 0x00000E10 */
volatile B_SCIBDSTR _B_SCIBD;                              /* SCI Baud Rate Register; 0x00000E18 */
volatile B_TCNTSTR _B_TCNT;                                /* Timer Count Register; 0x00000E24 */
volatile B_TC0STR _B_TC0;                                  /* Timer Input Capture/Output Compare Register 0; 0x00000E2E */
volatile B_TC1STR _B_TC1;                                  /* Timer Input Capture/Output Compare Register 1; 0x00000E30 */
volatile B_TC2STR _B_TC2;                                  /* Timer Input Capture/Output Compare Register 2; 0x00000E32 */
volatile B_TC3STR _B_TC3;                                  /* Timer Input Capture/Output Compare Register 3; 0x00000E34 */
volatile B_LTC_CTLSTR _B_LTC_CTL;                          /* Life Time Counter control register; 0x00000E38 */
volatile B_LTC_CNT1STR _B_LTC_CNT1;                        /* Life Time Counter Register 1; 0x00000E3C */
volatile B_LTC_CNT0STR _B_LTC_CNT0;                        /* Life Time Counter Register 0; 0x00000E3E */
volatile B_GPIO_CTLSTR _B_GPIO_CTL;                        /* GPIO control register; 0x00000E40 */
volatile B_LIN_CTLSTR _B_LIN_CTL;                          /* LIN control register; 0x00000E50 */
volatile B_LIN_SRSTR _B_LIN_SR;                            /* LIN status register; 0x00000E52 */
volatile B_ACQ_CTLSTR _B_ACQ_CTL;                          /* Acquisition control register; 0x00000E58 */
volatile B_ACQ_SRSTR _B_ACQ_SR;                            /* Acquisition status register; 0x00000E5A */
volatile B_ACQ_ACC1STR _B_ACQ_ACC1;                        /* Acquisition chain control 1; 0x00000E5C */
volatile B_ACQ_ACC0STR _B_ACQ_ACC0;                        /* Acquisition chain control 0; 0x00000E5E */
volatile B_ACQ_ITEMPSTR _B_ACQ_ITEMP;                      /* Internal temperature measurement result; 0x00000E64 */
volatile B_ACQ_ETEMPSTR _B_ACQ_ETEMP;                      /* External temperature measurement result; 0x00000E66 */
volatile B_ACQ_CURR1STR _B_ACQ_CURR1;                      /* Current measurement result 16Bit; 0x00000E68 */
volatile B_ACQ_CURR0STR _B_ACQ_CURR0;                      /* Current measurement result; 0x00000E6A */
volatile B_ACQ_VOLTSTR _B_ACQ_VOLT;                        /* Voltage measurement result; 0x00000E6C */
volatile B_ACQ_TCMPSTR _B_ACQ_TCMP;                        /* Low power trigger current measurement period; 0x00000E70 */
volatile B_ACQ_CVCRSTR _B_ACQ_CVCR;                        /* I and V chopper control register; 0x00000E74 */
volatile B_LPF_A0STR _B_LPF_A0;                            /* Low Pass Filter Coefficient A0; 0x00000E80 */
volatile B_LPF_A1STR _B_LPF_A1;                            /* Low Pass Filter Coefficient A1; 0x00000E82 */
volatile B_LPF_A2STR _B_LPF_A2;                            /* Low Pass Filter Coefficient A2; 0x00000E84 */
volatile B_LPF_A3STR _B_LPF_A3;                            /* Low Pass Filter Coefficient A3; 0x00000E86 */
volatile B_LPF_A4STR _B_LPF_A4;                            /* Low Pass Filter Coefficient A4; 0x00000E88 */
volatile B_LPF_A5STR _B_LPF_A5;                            /* Low Pass Filter Coefficient A5; 0x00000E8A */
volatile B_LPF_A6STR _B_LPF_A6;                            /* Low Pass Filter Coefficient A6; 0x00000E8C */
volatile B_LPF_A7STR _B_LPF_A7;                            /* Low Pass Filter Coefficient A7; 0x00000E8E */
volatile B_LPF_A8STR _B_LPF_A8;                            /* Low Pass Filter Coefficient A8; 0x00000E90 */
volatile B_LPF_A9STR _B_LPF_A9;                            /* Low Pass Filter Coefficient A9; 0x00000E92 */
volatile B_LPF_A10STR _B_LPF_A10;                          /* Low Pass Filter Coefficient A10; 0x00000E94 */
volatile B_LPF_A11STR _B_LPF_A11;                          /* Low Pass Filter Coefficient A11; 0x00000E96 */
volatile B_LPF_A12STR _B_LPF_A12;                          /* Low Pass Filter Coefficient A12; 0x00000E98 */
volatile B_LPF_A13STR _B_LPF_A13;                          /* Low Pass Filter Coefficient A13; 0x00000E9A */
volatile B_LPF_A14STR _B_LPF_A14;                          /* Low Pass Filter Coefficient A14; 0x00000E9C */
volatile B_LPF_A15STR _B_LPF_A15;                          /* Low Pass Filter Coefficient A15; 0x00000E9E */
volatile B_COMP_CTLSTR _B_COMP_CTL;                        /* Compensation control register; 0x00000EA0 */
volatile B_COMP_TMAXSTR _B_COMP_TMAX;                      /* Max temp before recalibration; 0x00000EA4 */
volatile B_COMP_TMINSTR _B_COMP_TMIN;                      /* Min temp before recalibration; 0x00000EA6 */
volatile B_COMP_VSGSTR _B_COMP_VSG;                        /* Gain voltage compensation vsense channel; 0x00000EAC */
volatile B_COMP_TVSGSTR _B_COMP_TVSG;                      /* Voltage Gain temp compensation; 0x00000EAE */
volatile B_COMP_IG4STR _B_COMP_IG4;                        /* Gain Current Compensation 4; 0x00000EB0 */
volatile B_COMP_TIG4STR _B_COMP_TIG4;                      /* Current Gain temp compensation; 0x00000EB2 */
volatile B_COMP_IG16STR _B_COMP_IG16;                      /* Gain Current Compensation 16; 0x00000EB4 */
volatile B_COMP_TIG16STR _B_COMP_TIG16;                    /* Current Gain temp compensation; 0x00000EB6 */
volatile B_COMP_IG64STR _B_COMP_IG64;                      /* Gain Current Compensation 64; 0x00000EB8 */
volatile B_COMP_TIG64STR _B_COMP_TIG64;                    /* Current Gain temp compensation; 0x00000EBA */
volatile B_COMP_IG256STR _B_COMP_IG256;                    /* Gain Current Compensation 256; 0x00000EBC */
volatile B_COMP_TIG256STR _B_COMP_TIG256;                  /* Current Gain temp compensation; 0x00000EBE */
volatile B_COMP_PGAO4STR _B_COMP_PGAO4;                    /* Offset PGA compensation 4; 0x00000EC0 */
volatile B_COMP_PGAO16STR _B_COMP_PGAO16;                  /* Offset PGA compensation 16; 0x00000EC4 */
volatile B_COMP_PGAO64STR _B_COMP_PGAO64;                  /* Offset PGA compensation 64; 0x00000EC8 */
volatile B_COMP_PGAO256STR _B_COMP_PGAO256;                /* Offset PGA compensation 256; 0x00000ECC */
volatile NB_PCR_CTLSTR _NB_PCR_CTL;                        /* PCR Control Register; 0x00000F00 */
volatile NB_PCR_SRSTR _NB_PCR_SR;                          /* PCR Status Register; 0x00000F02 */
volatile NB_PCR_PRESCSTR _NB_PCR_PRESC;                    /* PCR 1ms prescaler; 0x00000F04 */
volatile NB_PCR_WUESTR _NB_PCR_WUE;                        /* Wake Up Enable Register; 0x00000F06 */
volatile NB_INT_SRCSTR _NB_INT_SRC;                        /* Interrupt source register; 0x00000F08 */
volatile NB_INT_MSKSTR _NB_INT_MSK;                        /* Interrupt mask register; 0x00000F0C */
volatile NB_TRIM_ALFSTR _NB_TRIM_ALF;                      /* Trim for accurate 1ms low freq clock; 0x00000F0E */
volatile NB_WD_CTLSTR _NB_WD_CTL;                          /* Watchdog control register; 0x00000F10 */
volatile NB_SCIBDSTR _NB_SCIBD;                            /* SCI Baud Rate Register; 0x00000F18 */
volatile NB_TCNTSTR _NB_TCNT;                              /* Timer Count Register; 0x00000F24 */
volatile NB_TC0STR _NB_TC0;                                /* Timer Input Capture/Output Compare Register 0; 0x00000F2E */
volatile NB_TC1STR _NB_TC1;                                /* Timer Input Capture/Output Compare Register 1; 0x00000F30 */
volatile NB_TC2STR _NB_TC2;                                /* Timer Input Capture/Output Compare Register 2; 0x00000F32 */
volatile NB_TC3STR _NB_TC3;                                /* Timer Input Capture/Output Compare Register 3; 0x00000F34 */
volatile NB_LTC_CTLSTR _NB_LTC_CTL;                        /* Life Time Counter control register; 0x00000F38 */
volatile NB_LTC_CNT1STR _NB_LTC_CNT1;                      /* Life Time Counter Register 1; 0x00000F3C */
volatile NB_LTC_CNT0STR _NB_LTC_CNT0;                      /* Life Time Counter Register 0; 0x00000F3E */
volatile NB_GPIO_CTLSTR _NB_GPIO_CTL;                      /* GPIO control register; 0x00000F40 */
volatile NB_LIN_CTLSTR _NB_LIN_CTL;                        /* LIN control register; 0x00000F50 */
volatile NB_LIN_SRSTR _NB_LIN_SR;                          /* LIN status register; 0x00000F52 */
volatile NB_ACQ_CTLSTR _NB_ACQ_CTL;                        /* Acquisition control register; 0x00000F58 */
volatile NB_ACQ_SRSTR _NB_ACQ_SR;                          /* Acquisition status register; 0x00000F5A */
volatile NB_ACQ_ACC1STR _NB_ACQ_ACC1;                      /* Acquisition chain control 1; 0x00000F5C */
volatile NB_ACQ_ACC0STR _NB_ACQ_ACC0;                      /* Acquisition chain control 0; 0x00000F5E */
volatile NB_ACQ_ITEMPSTR _NB_ACQ_ITEMP;                    /* Internal temperature measurement result; 0x00000F64 */
volatile NB_ACQ_ETEMPSTR _NB_ACQ_ETEMP;                    /* External temperature measurement result; 0x00000F66 */
volatile NB_ACQ_CURR1STR _NB_ACQ_CURR1;                    /* Current measurement result 16Bit; 0x00000F68 */
volatile NB_ACQ_CURR0STR _NB_ACQ_CURR0;                    /* Current measurement result; 0x00000F6A */
volatile NB_ACQ_VOLTSTR _NB_ACQ_VOLT;                      /* Voltage measurement result; 0x00000F6C */
volatile NB_ACQ_TCMPSTR _NB_ACQ_TCMP;                      /* Low power trigger current measurement period; 0x00000F70 */
volatile NB_ACQ_CVCRSTR _NB_ACQ_CVCR;                      /* I and V chopper control register; 0x00000F74 */
volatile NB_LPF_A0STR _NB_LPF_A0;                          /* Low Pass Filter Coefficient A0; 0x00000F80 */
volatile NB_LPF_A1STR _NB_LPF_A1;                          /* Low Pass Filter Coefficient A1; 0x00000F82 */
volatile NB_LPF_A2STR _NB_LPF_A2;                          /* Low Pass Filter Coefficient A2; 0x00000F84 */
volatile NB_LPF_A3STR _NB_LPF_A3;                          /* Low Pass Filter Coefficient A3; 0x00000F86 */
volatile NB_LPF_A4STR _NB_LPF_A4;                          /* Low Pass Filter Coefficient A4; 0x00000F88 */
volatile NB_LPF_A5STR _NB_LPF_A5;                          /* Low Pass Filter Coefficient A5; 0x00000F8A */
volatile NB_LPF_A6STR _NB_LPF_A6;                          /* Low Pass Filter Coefficient A6; 0x00000F8C */
volatile NB_LPF_A7STR _NB_LPF_A7;                          /* Low Pass Filter Coefficient A7; 0x00000F8E */
volatile NB_LPF_A8STR _NB_LPF_A8;                          /* Low Pass Filter Coefficient A8; 0x00000F90 */
volatile NB_LPF_A9STR _NB_LPF_A9;                          /* Low Pass Filter Coefficient A9; 0x00000F92 */
volatile NB_LPF_A10STR _NB_LPF_A10;                        /* Low Pass Filter Coefficient A10; 0x00000F94 */
volatile NB_LPF_A11STR _NB_LPF_A11;                        /* Low Pass Filter Coefficient A11; 0x00000F96 */
volatile NB_LPF_A12STR _NB_LPF_A12;                        /* Low Pass Filter Coefficient A12; 0x00000F98 */
volatile NB_LPF_A13STR _NB_LPF_A13;                        /* Low Pass Filter Coefficient A13; 0x00000F9A */
volatile NB_LPF_A14STR _NB_LPF_A14;                        /* Low Pass Filter Coefficient A14; 0x00000F9C */
volatile NB_LPF_A15STR _NB_LPF_A15;                        /* Low Pass Filter Coefficient A15; 0x00000F9E */
volatile NB_COMP_CTLSTR _NB_COMP_CTL;                      /* Compensation control register; 0x00000FA0 */
volatile NB_COMP_TMAXSTR _NB_COMP_TMAX;                    /* Max temp before recalibration; 0x00000FA4 */
volatile NB_COMP_TMINSTR _NB_COMP_TMIN;                    /* Min temp before recalibration; 0x00000FA6 */
volatile NB_COMP_VSGSTR _NB_COMP_VSG;                      /* Gain voltage compensation vsense channel; 0x00000FAC */
volatile NB_COMP_TVSGSTR _NB_COMP_TVSG;                    /* Voltage Gain temp compensation; 0x00000FAE */
volatile NB_COMP_IG4STR _NB_COMP_IG4;                      /* Gain Current Compensation 4; 0x00000FB0 */
volatile NB_COMP_TIG4STR _NB_COMP_TIG4;                    /* Current Gain temp compensation; 0x00000FB2 */
volatile NB_COMP_IG16STR _NB_COMP_IG16;                    /* Gain Current Compensation 16; 0x00000FB4 */
volatile NB_COMP_TIG16STR _NB_COMP_TIG16;                  /* Current Gain temp compensation; 0x00000FB6 */
volatile NB_COMP_IG64STR _NB_COMP_IG64;                    /* Gain Current Compensation 64; 0x00000FB8 */
volatile NB_COMP_TIG64STR _NB_COMP_TIG64;                  /* Current Gain temp compensation; 0x00000FBA */
volatile NB_COMP_IG256STR _NB_COMP_IG256;                  /* Gain Current Compensation 256; 0x00000FBC */
volatile NB_COMP_TIG256STR _NB_COMP_TIG256;                /* Current Gain temp compensation; 0x00000FBE */
volatile NB_COMP_PGAO4STR _NB_COMP_PGAO4;                  /* Offset PGA compensation 4; 0x00000FC0 */
volatile NB_COMP_PGAO16STR _NB_COMP_PGAO16;                /* Offset PGA compensation 16; 0x00000FC4 */
volatile NB_COMP_PGAO64STR _NB_COMP_PGAO64;                /* Offset PGA compensation 64; 0x00000FC8 */
volatile NB_COMP_PGAO256STR _NB_COMP_PGAO256;              /* Offset PGA compensation 256; 0x00000FCC */


/* * * * *  32-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PARTIDSTR _PARTID;                                /* Part ID Register; 0x00000000 */
volatile B_ACQ_AHTHSTR _B_ACQ_AHTH;                        /* Low power Ah counter threshold; 0x00000E78 */
volatile B_ACQ_AHCSTR _B_ACQ_AHC;                          /* Low power Ah counter; 0x00000E7C */
volatile NB_ACQ_AHTHSTR _NB_ACQ_AHTH;                      /* Low power Ah counter threshold; 0x00000F78 */
volatile NB_ACQ_AHCSTR _NB_ACQ_AHC;                        /* Low power Ah counter; 0x00000F7C */


/* * * * *  24-BIT ADDRESS REGISTERS  * * * * * * * * * * * * * * * * * * * * * * */
volatile void* volatile MMCPC;                             /* Captured S12ZCPU Program Counter Low; 0x00000087 */
volatile void* volatile DBGAA;                             /* Debug Comparator A Address Register Low; 0x00000117 */
volatile void* volatile DBGBA;                             /* Debug Comparator B Address Register Low; 0x00000127 */
volatile void* volatile DBGCA;                             /* Debug Comparator C Address Register Low; 0x00000137 */
volatile void* volatile DBGDA;                             /* Debug Comparator D Address Register Low; 0x00000147 */
volatile void* volatile ECCDPTR;                           /* ECC Debug Point Register Low; 0x000003C9 */



/*lint -restore */

/* EOF */
