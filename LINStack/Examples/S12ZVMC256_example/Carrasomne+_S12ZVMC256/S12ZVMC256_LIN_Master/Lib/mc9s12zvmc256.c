/* Based on CPU DB MC9S12ZVMC256_80, version 3.00.000 (RegistersPrg V2.33) */
/* DataSheet : Rev. 2.0E 06 FEB 2015 */

#include <mc9s12zvmc256.h>

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
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
volatile MODRR0STR _MODRR0;                                /* Module Routing Register 0; 0x00000200 */
volatile MODRR1STR _MODRR1;                                /* Module Routing Register 1; 0x00000201 */
volatile MODRR2STR _MODRR2;                                /* Module Routing Register 2; 0x00000202 */
volatile ECLKCTLSTR _ECLKCTL;                              /* ECLK Control Register; 0x00000208 */
volatile IRQCRSTR _IRQCR;                                  /* Interrupt Control Register; 0x00000209 */
volatile PIMMISCSTR _PIMMISC;                              /* PIM Miscellaneous Register; 0x0000020A */
volatile PTESTR _PTE;                                      /* Port E Data Register; 0x00000260 */
volatile PTIESTR _PTIE;                                    /* Port E Input Register; 0x00000262 */
volatile DDRESTR _DDRE;                                    /* Port E Data Direction Register; 0x00000264 */
volatile PERESTR _PERE;                                    /* Port E Pull Device Enable Register; 0x00000266 */
volatile PPSESTR _PPSE;                                    /* Port E Polarity Select Register; 0x00000268 */
volatile PTTSTR _PTT;                                      /* Port T Data Register; 0x000002C0 */
volatile PTITSTR _PTIT;                                    /* Port T Input Register; 0x000002C1 */
volatile DDRTSTR _DDRT;                                    /* Port T Data Direction Register; 0x000002C2 */
volatile PERTSTR _PERT;                                    /* Port T Pull Device Enable Register; 0x000002C3 */
volatile PPSTSTR _PPST;                                    /* Port T Polarity Select Register; 0x000002C4 */
volatile PTSSTR _PTS;                                      /* Port S Data Register; 0x000002D0 */
volatile PTISSTR _PTIS;                                    /* Port S Input Register; 0x000002D1 */
volatile DDRSSTR _DDRS;                                    /* Port S Data Direction Register; 0x000002D2 */
volatile PERSSTR _PERS;                                    /* Port S Pull Device Enable Register; 0x000002D3 */
volatile PPSSSTR _PPSS;                                    /* Port S Polarity Select Register; 0x000002D4 */
volatile PIESSTR _PIES;                                    /* Port S Interrupt Enable Register; 0x000002D6 */
volatile PIFSSTR _PIFS;                                    /* Port S Interrupt Flag Register; 0x000002D7 */
volatile WOMSSTR _WOMS;                                    /* Port S Wired-Or Mode Register; 0x000002DF */
volatile PTPSTR _PTP;                                      /* Port P Data Register; 0x000002F0 */
volatile PTIPSTR _PTIP;                                    /* Port P Input Register; 0x000002F1 */
volatile DDRPSTR _DDRP;                                    /* Port P Data Direction Register; 0x000002F2 */
volatile PERPSTR _PERP;                                    /* Port P Pull Device Enable Register; 0x000002F3 */
volatile PPSPSTR _PPSP;                                    /* Port P Polarity Select Register; 0x000002F4 */
volatile PIEPSTR _PIEP;                                    /* Port P Interrupt Enable Register; 0x000002F6 */
volatile PIFPSTR _PIFP;                                    /* Port P Interrupt Flag Register; 0x000002F7 */
volatile RDRPSTR _RDRP;                                    /* Port P Reduced Drive Register; 0x000002FD */
volatile PTILSTR _PTIL;                                    /* Port L Input Register; 0x00000331 */
volatile PTPSLSTR _PTPSL;                                  /* Port L Pull Select Register; 0x00000333 */
volatile PPSLSTR _PPSL;                                    /* Port L Polarity Select Register; 0x00000334 */
volatile PIELSTR _PIEL;                                    /* Port L Interrupt Enable Register; 0x00000336 */
volatile PIFLSTR _PIFL;                                    /* Port L Interrupt Flag Register; 0x00000337 */
volatile PTABYPLSTR _PTABYPL;                              /* Port L ADC Bypass Register; 0x0000033A */
volatile PTADIRLSTR _PTADIRL;                              /* Port L ADC Direct Register; 0x0000033B */
volatile DIENLSTR _DIENL;                                  /* Port LDigital Input Enable Register; 0x0000033C */
volatile PTAENLSTR _PTAENL;                                /* Port L ADC Connection Enable Register; 0x0000033D */
volatile PIRLSTR _PIRL;                                    /* Port L Input Divider Ratio Selection Register; 0x0000033E */
volatile PTTELSTR _PTTEL;                                  /* Port L Test Enable Register; 0x0000033F */
volatile FCLKDIVSTR _FCLKDIV;                              /* Flash Clock Divider Register; 0x00000380 */
volatile FSECSTR _FSEC;                                    /* Flash Security Register; 0x00000381 */
volatile FCCOBIXSTR _FCCOBIX;                              /* Flash CCOB Index Register; 0x00000382 */
volatile FPSTATSTR _FPSTAT;                                /* Flash Protection Status Register; 0x00000383 */
volatile FCNFGSTR _FCNFG;                                  /* Flash Configuration Register; 0x00000384 */
volatile FERCNFGSTR _FERCNFG;                              /* Flash Error Configuration Register; 0x00000385 */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register; 0x00000386 */
volatile FERSTATSTR _FERSTAT;                              /* Flash Error Status Register; 0x00000387 */
volatile FPROTSTR _FPROT;                                  /* P-Flash Protection Register; 0x00000388 */
volatile DFPROTSTR _DFPROT;                                /* EEPROM Protection Register; 0x00000389 */
volatile FOPTSTR _FOPT;                                    /* Flash Option Register; 0x0000038A */
volatile ECCSTATSTR _ECCSTAT;                              /* ECC Status Register; 0x000003C0 */
volatile ECCIESTR _ECCIE;                                  /* ECC Interrupt Enable Register; 0x000003C1 */
volatile ECCIFSTR _ECCIF;                                  /* ECC Interrupt Flag Register; 0x000003C2 */
volatile ECCDPTRHSTR _ECCDPTRH;                            /* ECC Debug Pointer Register High; 0x000003C7 */
volatile ECCDPTRMSTR _ECCDPTRM;                            /* ECC Debug Pointer Register Middle; 0x000003C8 */
volatile ECCDPTRLSTR _ECCDPTRL;                            /* ECC Debug Pointer Register Low; 0x000003C9 */
volatile ECCDESTR _ECCDE;                                  /* ECC Debug ECC; 0x000003CE */
volatile ECCDCMDSTR _ECCDCMD;                              /* ECC Debug Comamnd; 0x000003CF */
volatile TIM1TIOSSTR _TIM1TIOS;                            /* Timer Input Capture/Output Compare Select; 0x00000400 */
volatile TIM1CFORCSTR _TIM1CFORC;                          /* Timer Compare Force Register; 0x00000401 */
volatile TIM1TSCR1STR _TIM1TSCR1;                          /* Timer System Control Register1; 0x00000406 */
volatile TIM1TTOVSTR _TIM1TTOV;                            /* Timer Toggle On Overflow Register; 0x00000407 */
volatile TIM1TCTL2STR _TIM1TCTL2;                          /* Timer Control Register 2; 0x00000409 */
volatile TIM1TCTL4STR _TIM1TCTL4;                          /* Timer Control Register 4; 0x0000040B */
volatile TIM1TIESTR _TIM1TIE;                              /* Timer Interrupt Enable Register; 0x0000040C */
volatile TIM1TSCR2STR _TIM1TSCR2;                          /* Timer System Control Register 2; 0x0000040D */
volatile TIM1TFLG1STR _TIM1TFLG1;                          /* Main Timer Interrupt Flag 1; 0x0000040E */
volatile TIM1TFLG2STR _TIM1TFLG2;                          /* Main Timer Interrupt Flag 2; 0x0000040F */
volatile TIM1OCPDSTR _TIM1OCPD;                            /* Output Compare Pin Disconnect Register; 0x0000042C */
volatile TIM1PTPSRSTR _TIM1PTPSR;                          /* Precision Timer Prescaler Select Register; 0x0000042E */
volatile PWMESTR _PWME;                                    /* PWM Enable Register; 0x00000480 */
volatile PWMPOLSTR _PWMPOL;                                /* PWM Polarity Register; 0x00000481 */
volatile PWMCLKSTR _PWMCLK;                                /* PWM Clock Select Register; 0x00000482 */
volatile PWMPRCLKSTR _PWMPRCLK;                            /* PWM Prescale Clock Select Register; 0x00000483 */
volatile PWMCAESTR _PWMCAE;                                /* PWM Center Align Enable Register; 0x00000484 */
volatile PWMCTLSTR _PWMCTL;                                /* PWM Control Register; 0x00000485 */
volatile PWMCLKABSTR _PWMCLKAB;                            /* PWM Clock A/B Select Register; 0x00000486 */
volatile PWMSCLASTR _PWMSCLA;                              /* PWM Scale A Register; 0x00000488 */
volatile PWMSCLBSTR _PWMSCLB;                              /* PWM Scale B Register; 0x00000489 */
volatile PWMCNT0STR _PWMCNT0;                              /* PWM Channel Counter 0 Register; 0x0000048C */
volatile PWMCNT1STR _PWMCNT1;                              /* PWM Channel Counter 1 Register; 0x0000048D */
volatile PWMCNT2STR _PWMCNT2;                              /* PWM Channel Counter 2 Register; 0x0000048E */
volatile PWMCNT3STR _PWMCNT3;                              /* PWM Channel Counter 3 Register; 0x0000048F */
volatile PWMCNT4STR _PWMCNT4;                              /* PWM Channel Counter 4 Register; 0x00000490 */
volatile PWMCNT5STR _PWMCNT5;                              /* PWM Channel Counter 5 Register; 0x00000491 */
volatile PWMCNT6STR _PWMCNT6;                              /* PWM Channel Counter 6 Register; 0x00000492 */
volatile PWMCNT7STR _PWMCNT7;                              /* PWM Channel Counter 7 Register; 0x00000493 */
volatile PWMPER0STR _PWMPER0;                              /* PWM Channel Period 0 Register; 0x00000494 */
volatile PWMPER1STR _PWMPER1;                              /* PWM Channel Period 1 Register; 0x00000495 */
volatile PWMPER2STR _PWMPER2;                              /* PWM Channel Period 2 Register; 0x00000496 */
volatile PWMPER3STR _PWMPER3;                              /* PWM Channel Period 3 Register; 0x00000497 */
volatile PWMPER4STR _PWMPER4;                              /* PWM Channel Period 4 Register; 0x00000498 */
volatile PWMPER5STR _PWMPER5;                              /* PWM Channel Period 5 Register; 0x00000499 */
volatile PWMPER6STR _PWMPER6;                              /* PWM Channel Period 6 Register; 0x0000049A */
volatile PWMPER7STR _PWMPER7;                              /* PWM Channel Period 7 Register; 0x0000049B */
volatile PWMDTY0STR _PWMDTY0;                              /* PWM Channel Duty 0 Register; 0x0000049C */
volatile PWMDTY1STR _PWMDTY1;                              /* PWM Channel Duty 1 Register; 0x0000049D */
volatile PWMDTY2STR _PWMDTY2;                              /* PWM Channel Duty 2 Register; 0x0000049E */
volatile PWMDTY3STR _PWMDTY3;                              /* PWM Channel Duty 3 Register; 0x0000049F */
volatile PWMDTY4STR _PWMDTY4;                              /* PWM Channel Duty 4 Register; 0x000004A0 */
volatile PWMDTY5STR _PWMDTY5;                              /* PWM Channel Duty 5 Register; 0x000004A1 */
volatile PWMDTY6STR _PWMDTY6;                              /* PWM Channel Duty 6 Register; 0x000004A2 */
volatile PWMDTY7STR _PWMDTY7;                              /* PWM Channel Duty 7 Register; 0x000004A3 */
volatile PMFCFG0STR _PMFCFG0;                              /* PMF Configure 0 Register; 0x00000500 */
volatile PMFCFG1STR _PMFCFG1;                              /* PMF Configure 1 Register; 0x00000501 */
volatile PMFCFG2STR _PMFCFG2;                              /* PMF Configure 2 Register; 0x00000502 */
volatile PMFCFG3STR _PMFCFG3;                              /* PMF Configure 3 Register; 0x00000503 */
volatile PMFFENSTR _PMFFEN;                                /* PMF Fault Enable Register; 0x00000504 */
volatile PMFFMODSTR _PMFFMOD;                              /* PMF Fault Mode Register; 0x00000505 */
volatile PMFFIESTR _PMFFIE;                                /* PMF Fault Interrupt Enable Register; 0x00000506 */
volatile PMFFIFSTR _PMFFIF;                                /* PMF Fault Interrupt Flag Register; 0x00000507 */
volatile PMFQSMP0STR _PMFQSMP0;                            /* PMF Fault Qualifying Samples Register 0; 0x00000508 */
volatile PMFQSMP1STR _PMFQSMP1;                            /* PMF Fault Qualifying Samples Register 1; 0x00000509 */
volatile PMFOUTCSTR _PMFOUTC;                              /* PMF Output Control Register; 0x0000050C */
volatile PMFOUTBSTR _PMFOUTB;                              /* PMF Output Control Bit Register; 0x0000050D */
volatile PMFDTMSSTR _PMFDTMS;                              /* PMF Deadtime Sample Register; 0x0000050E */
volatile PMFCCTLSTR _PMFCCTL;                              /* PMF Correction Control Register; 0x0000050F */
volatile PMFROIESTR _PMFROIE;                              /* PMF Reload Overrun Interrupt Enable Register; 0x0000051C */
volatile PMFROIFSTR _PMFROIF;                              /* PMF Interrupt Flag Register; 0x0000051D */
volatile PMFICCTLSTR _PMFICCTL;                            /* PMF Internal Correction Control Register; 0x0000051E */
volatile PMFCINVSTR _PMFCINV;                              /* PMF Compare Invert Register; 0x0000051F */
volatile PMFENCASTR _PMFENCA;                              /* PMF Enable Control A Register; 0x00000520 */
volatile PMFFQCASTR _PMFFQCA;                              /* PMF Frequency Control A Register; 0x00000521 */
volatile PMFENCBSTR _PMFENCB;                              /* PMF Enable Control B Register; 0x00000528 */
volatile PMFFQCBSTR _PMFFQCB;                              /* PMF Frequency Control B Register; 0x00000529 */
volatile PMFENCCSTR _PMFENCC;                              /* PMF Enable Control C Register; 0x00000530 */
volatile PMFFQCCSTR _PMFFQCC;                              /* PMF Frequency Control C Register; 0x00000531 */
volatile PMFDMP0STR _PMFDMP0;                              /* PMF Disable Mapping Register 0; 0x00000538 */
volatile PMFDMP1STR _PMFDMP1;                              /* PMF Disable Mapping Register 1; 0x00000539 */
volatile PMFDMP2STR _PMFDMP2;                              /* PMF Disable Mapping Register 2; 0x0000053A */
volatile PMFDMP3STR _PMFDMP3;                              /* PMF Disable Mapping Register 3; 0x0000053B */
volatile PMFDMP4STR _PMFDMP4;                              /* PMF Disable Mapping Register 4; 0x0000053C */
volatile PMFDMP5STR _PMFDMP5;                              /* PMF Disable Mapping Register 5; 0x0000053D */
volatile PMFOUTFSTR _PMFOUTF;                              /* PMF Output Control on Fault Register; 0x0000053E */
volatile PTUESTR _PTUE;                                    /* PTU Enable Register; 0x00000580 */
volatile PTUCSTR _PTUC;                                    /* PTU Module Control Register; 0x00000581 */
volatile PTUIEHSTR _PTUIEH;                                /* PTU Interrupt Enable Register High; 0x00000582 */
volatile PTUIELSTR _PTUIEL;                                /* PTU Interrupt Enable Register Low; 0x00000583 */
volatile PTUIFHSTR _PTUIFH;                                /* PTU Interrupt Flag Register High; 0x00000584 */
volatile PTUIFLSTR _PTUIFL;                                /* PTU Interrupt Flag Register Low; 0x00000585 */
volatile TG0LISTSTR _TG0LIST;                              /* Trigger Generator 0 List Register; 0x00000586 */
volatile TG0TNUMSTR _TG0TNUM;                              /* Trigger Generator 0 Trigger Number Register; 0x00000587 */
volatile TG0TVHSTR _TG0TVH;                                /* Trigger Generator 0 Trigger Value; 0x00000588 */
volatile TG0TVLSTR _TG0TVL;                                /* Trigger Generator 0 Trigger Value; 0x00000589 */
volatile TG1LISTSTR _TG1LIST;                              /* Trigger Generator 1 List Register; 0x0000058A */
volatile TG1TNUMSTR _TG1TNUM;                              /* Trigger Generator 1 Trigger Number Register; 0x0000058B */
volatile TG1TVHSTR _TG1TVH;                                /* Trigger Generator 1 Trigger Value; 0x0000058C */
volatile TG1TVLSTR _TG1TVL;                                /* Trigger Generator 1 Trigger Value; 0x0000058D */
volatile PTUCNTHSTR _PTUCNTH;                              /* PTU Counter Register; 0x0000058E */
volatile PTUCNTLSTR _PTUCNTL;                              /* PTU Counter Register; 0x0000058F */
volatile PTUPTRHSTR _PTUPTRH;                              /* PTU Pointer Register; 0x00000591 */
volatile PTUPTRMSTR _PTUPTRM;                              /* PTU Pointer Register; 0x00000592 */
volatile PTUPTRLSTR _PTUPTRL;                              /* PTU Pointer Register; 0x00000593 */
volatile TG0L0IDXSTR _TG0L0IDX;                            /* Trigger Generator 0 List 0 Index Register; 0x00000594 */
volatile TG0L1IDXSTR _TG0L1IDX;                            /* Trigger Generator 0 List 1 Index Register; 0x00000595 */
volatile TG1L0IDXSTR _TG1L0IDX;                            /* Trigger Generator 1 List 0 Index Register; 0x00000596 */
volatile TG1L1IDXSTR _TG1L1IDX;                            /* Trigger Generator 1 List 1 Index Register; 0x00000597 */
volatile PTUDEBUGSTR _PTUDEBUG;                            /* PTU Debug Register; 0x0000059F */
volatile TIM0TIOSSTR _TIM0TIOS;                            /* Timer Input Capture/Output Compare Select; 0x000005C0 */
volatile TIM0CFORCSTR _TIM0CFORC;                          /* Timer Compare Force Register; 0x000005C1 */
volatile TIM0TSCR1STR _TIM0TSCR1;                          /* Timer System Control Register1; 0x000005C6 */
volatile TIM0TTOVSTR _TIM0TTOV;                            /* Timer Toggle On Overflow Register; 0x000005C7 */
volatile TIM0TCTL2STR _TIM0TCTL2;                          /* Timer Control Register 2; 0x000005C9 */
volatile TIM0TCTL4STR _TIM0TCTL4;                          /* Timer Control Register 4; 0x000005CB */
volatile TIM0TIESTR _TIM0TIE;                              /* Timer Interrupt Enable Register; 0x000005CC */
volatile TIM0TSCR2STR _TIM0TSCR2;                          /* Timer System Control Register 2; 0x000005CD */
volatile TIM0TFLG1STR _TIM0TFLG1;                          /* Main Timer Interrupt Flag 1; 0x000005CE */
volatile TIM0TFLG2STR _TIM0TFLG2;                          /* Main Timer Interrupt Flag 2; 0x000005CF */
volatile TIM0OCPDSTR _TIM0OCPD;                            /* Output Compare Pin Disconnect Register; 0x000005EC */
volatile TIM0PTPSRSTR _TIM0PTPSR;                          /* Precision Timer Prescaler Select Register; 0x000005EE */
volatile ADC0STSSTR _ADC0STS;                              /* ADC0 Status Register; 0x00000602 */
volatile ADC0TIMSTR _ADC0TIM;                              /* ADC0 Timing Register; 0x00000603 */
volatile ADC0FMTSTR _ADC0FMT;                              /* ADC0 Format Register; 0x00000604 */
volatile ADC0FLWCTLSTR _ADC0FLWCTL;                        /* ADC0 Conversion Flow Control Register; 0x00000605 */
volatile ADC0EIESTR _ADC0EIE;                              /* ADC0 Error Interrupt Enable Register; 0x00000606 */
volatile ADC0IESTR _ADC0IE;                                /* ADC0 Interrupt Enable Register; 0x00000607 */
volatile ADC0EIFSTR _ADC0EIF;                              /* ADC0 Error Interrupt Flag Register; 0x00000608 */
volatile ADC0IFSTR _ADC0IF;                                /* ADC0 Interrupt Flag Register; 0x00000609 */
volatile ADC0EOLRISTR _ADC0EOLRI;                          /* ADC0 End Of List Result Information Register; 0x00000610 */
volatile ADC0CIDXSTR _ADC0CIDX;                            /* ADC0 Command Index Register; 0x0000061C */
volatile ADC0CBP_0STR _ADC0CBP_0;                          /* ADC0 Command Base Pointer Register 0; 0x0000061D */
volatile ADC0CBP_1STR _ADC0CBP_1;                          /* ADC0 Command Base Pointer Register 1; 0x0000061E */
volatile ADC0CBP_2STR _ADC0CBP_2;                          /* ADC0 Command Base Pointer Register 2; 0x0000061F */
volatile ADC0RIDXSTR _ADC0RIDX;                            /* ADC0 Result Index Register; 0x00000620 */
volatile ADC0RBP_0STR _ADC0RBP_0;                          /* ADC0 Result Base Pointer Register 0; 0x00000621 */
volatile ADC0RBP_1STR _ADC0RBP_1;                          /* ADC0 Result Base Pointer Register 1; 0x00000622 */
volatile ADC0RBP_2STR _ADC0RBP_2;                          /* ADC0 Result Base Pointer Register 2; 0x00000623 */
volatile ADC0CROFF0STR _ADC0CROFF0;                        /* ADC0 Command and Result Offset Register 0; 0x00000624 */
volatile ADC0CROFF1STR _ADC0CROFF1;                        /* ADC0 Command and Result Offset Register 1; 0x00000625 */
volatile ADC1STSSTR _ADC1STS;                              /* ADC1 Status Register; 0x00000642 */
volatile ADC1TIMSTR _ADC1TIM;                              /* ADC1 Timing Register; 0x00000643 */
volatile ADC1FMTSTR _ADC1FMT;                              /* ADC1 Format Register; 0x00000644 */
volatile ADC1FLWCTLSTR _ADC1FLWCTL;                        /* ADC1 Conversion Flow Control Register; 0x00000645 */
volatile ADC1EIESTR _ADC1EIE;                              /* ADC1 Error Interrupt Enable Register; 0x00000646 */
volatile ADC1IESTR _ADC1IE;                                /* ADC1 Interrupt Enable Register; 0x00000647 */
volatile ADC1EIFSTR _ADC1EIF;                              /* ADC1 Error Interrupt Flag Register; 0x00000648 */
volatile ADC1IFSTR _ADC1IF;                                /* ADC1 Interrupt Flag Register; 0x00000649 */
volatile ADC1EOLRISTR _ADC1EOLRI;                          /* ADC1 End Of List Result Information Register; 0x00000650 */
volatile ADC1CIDXSTR _ADC1CIDX;                            /* ADC1 Command Index Register; 0x0000065C */
volatile ADC1CBP_0STR _ADC1CBP_0;                          /* ADC1 Command Base Pointer Register 0; 0x0000065D */
volatile ADC1CBP_1STR _ADC1CBP_1;                          /* ADC1 Command Base Pointer Register 1; 0x0000065E */
volatile ADC1CBP_2STR _ADC1CBP_2;                          /* ADC1 Command Base Pointer Register 2; 0x0000065F */
volatile ADC1RIDXSTR _ADC1RIDX;                            /* ADC1 Result Index Register; 0x00000660 */
volatile ADC1RBP_0STR _ADC1RBP_0;                          /* ADC1 Result Base Pointer Register 0; 0x00000661 */
volatile ADC1RBP_1STR _ADC1RBP_1;                          /* ADC1 Result Base Pointer Register 1; 0x00000662 */
volatile ADC1RBP_2STR _ADC1RBP_2;                          /* ADC1 Result Base Pointer Register 2; 0x00000663 */
volatile ADC1CROFF0STR _ADC1CROFF0;                        /* ADC1 Command and Result Offset Register 0; 0x00000664 */
volatile ADC1CROFF1STR _ADC1CROFF1;                        /* ADC1 Command and Result Offset Register 1; 0x00000665 */
volatile GDUESTR _GDUE;                                    /* GDU Module Enable Register; 0x000006A0 */
volatile GDUCTRSTR _GDUCTR;                                /* GDU Control Register; 0x000006A1 */
volatile GDUIESTR _GDUIE;                                  /* GDU Interrupt Enable Register; 0x000006A2 */
volatile GDUDSESTR _GDUDSE;                                /* GDU Desaturation Error Flag Register; 0x000006A3 */
volatile GDUSTATSTR _GDUSTAT;                              /* GDU Status Register; 0x000006A4 */
volatile GDUSRCSTR _GDUSRC;                                /* GDU Slew Rate Control Register; 0x000006A5 */
volatile GDUFSTR _GDUF;                                    /* GDU Flag Register; 0x000006A6 */
volatile GDUCLK1STR _GDUCLK1;                              /* GDU Clock Control Register 1; 0x000006A7 */
volatile GDUBCLSTR _GDUBCL;                                /* GDU Boost Current Limit Register; 0x000006A8 */
volatile GDUPHMUXSTR _GDUPHMUX;                            /* GDU Phase Mux Register; 0x000006A9 */
volatile GDUCSOSTR _GDUCSO;                                /* GDU Current Sense Offset Register; 0x000006AA */
volatile GDUDSLVLSTR _GDUDSLVL;                            /* GDU Desaturation Level Register; 0x000006AB */
volatile GDUPHLSTR _GDUPHL;                                /* GDU Phase Log Register; 0x000006AC */
volatile GDUCLK2STR _GDUCLK2;                              /* GDU Clock Control Register 2; 0x000006AD */
volatile GDUOC0STR _GDUOC0;                                /* GDU Overcurrent Register 0; 0x000006AE */
volatile GDUOC1STR _GDUOC1;                                /* GDU Overcurrent Register 1; 0x000006AF */
volatile GDUCTR1STR _GDUCTR1;                              /* GDU Control Register 1; 0x000006B0 */
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
volatile CPMUHTCTLSTR _CPMUHTCTL;                          /* High Temperature Control Register; 0x000006D0 */
volatile CPMULVCTLSTR _CPMULVCTL;                          /* Low Voltage Control Register; 0x000006D1 */
volatile CPMUAPICTLSTR _CPMUAPICTL;                        /* Autonomous Periodical Interrupt Control Register; 0x000006D2 */
volatile CPMUACLKTRSTR _CPMUACLKTR;                        /* Autonomous Clock Trimming Register; 0x000006D3 */
volatile CPMUHTTRSTR _CPMUHTTR;                            /* High Temperature Trimming Register; 0x000006D7 */
volatile CPMUOSCSTR _CPMUOSC;                              /* CPMU Oscillator Register; 0x000006DA */
volatile CPMUPROTSTR _CPMUPROT;                            /* CPMUV1 Protection Register; 0x000006DB */
volatile CPMUVREGCTLSTR _CPMUVREGCTL;                      /* Voltage Regulator Control Register; 0x000006DD */
volatile CPMUOSC2STR _CPMUOSC2;                            /* CPMU Oscillator Register 2; 0x000006DE */
volatile BATESTR _BATE;                                    /* BATS Module Enable Register; 0x000006F0 */
volatile BATSRSTR _BATSR;                                  /* BATS Module Status Register; 0x000006F1 */
volatile BATIESTR _BATIE;                                  /* BATS Interrupt Enable Register; 0x000006F2 */
volatile BATIFSTR _BATIF;                                  /* BATS Interrupt Flag Register; 0x000006F3 */
volatile SCI0ACR2STR _SCI0ACR2;                            /* SCI 0 Alternative Control Register 2; 0x00000702 */
volatile SCI0CR2STR _SCI0CR2;                              /* SCI 0 Control Register 2; 0x00000703 */
volatile SCI0SR1STR _SCI0SR1;                              /* SCI 0 Status Register 1; 0x00000704 */
volatile SCI0SR2STR _SCI0SR2;                              /* SCI 0 Status Register 2; 0x00000705 */
volatile SCI0DRHSTR _SCI0DRH;                              /* SCI 0 Data Register High; 0x00000706 */
volatile SCI0DRLSTR _SCI0DRL;                              /* SCI 0 Data Register Low; 0x00000707 */
volatile SCI1ACR2STR _SCI1ACR2;                            /* SCI 1 Alternative Control Register 2; 0x00000712 */
volatile SCI1CR2STR _SCI1CR2;                              /* SCI 1 Control Register 2; 0x00000713 */
volatile SCI1SR1STR _SCI1SR1;                              /* SCI 1 Status Register 1; 0x00000714 */
volatile SCI1SR2STR _SCI1SR2;                              /* SCI 1 Status Register 2; 0x00000715 */
volatile SCI1DRHSTR _SCI1DRH;                              /* SCI 1 Data Register High; 0x00000716 */
volatile SCI1DRLSTR _SCI1DRL;                              /* SCI 1 Data Register Low; 0x00000717 */
volatile SPI0CR1STR _SPI0CR1;                              /* SPI 0 Control Register 1; 0x00000780 */
volatile SPI0CR2STR _SPI0CR2;                              /* SPI 0 Control Register 2; 0x00000781 */
volatile SPI0BRSTR _SPI0BR;                                /* SPI 0 Baud Rate Register; 0x00000782 */
volatile SPI0SRSTR _SPI0SR;                                /* SPI 0 Status Register; 0x00000783 */
volatile CAN0CTL0STR _CAN0CTL0;                            /* MSCAN0 Control 0 Register; 0x00000800 */
volatile CAN0CTL1STR _CAN0CTL1;                            /* MSCAN0 Control 1 Register; 0x00000801 */
volatile CAN0BTR0STR _CAN0BTR0;                            /* MSCAN0 Bus Timing Register 0; 0x00000802 */
volatile CAN0BTR1STR _CAN0BTR1;                            /* MSCAN0 Bus Timing Register 1; 0x00000803 */
volatile CAN0RFLGSTR _CAN0RFLG;                            /* MSCAN0 Receiver Flag Register; 0x00000804 */
volatile CAN0RIERSTR _CAN0RIER;                            /* MSCAN0 Receiver Interrupt Enable Register; 0x00000805 */
volatile CAN0TFLGSTR _CAN0TFLG;                            /* MSCAN0 Transmitter Flag Register; 0x00000806 */
volatile CAN0TIERSTR _CAN0TIER;                            /* MSCAN0 Transmitter Interrupt Enable Register; 0x00000807 */
volatile CAN0TARQSTR _CAN0TARQ;                            /* MSCAN0 Transmitter Message Abort Request; 0x00000808 */
volatile CAN0TAAKSTR _CAN0TAAK;                            /* MSCAN0 Transmitter Message Abort Acknowledge; 0x00000809 */
volatile CAN0TBSELSTR _CAN0TBSEL;                          /* MSCAN0 Transmit Buffer Selection; 0x0000080A */
volatile CAN0IDACSTR _CAN0IDAC;                            /* MSCAN0 Identifier Acceptance Control Register; 0x0000080B */
volatile CAN0MISCSTR _CAN0MISC;                            /* MSCAN0 Miscellaneous Register; 0x0000080D */
volatile CAN0RXERRSTR _CAN0RXERR;                          /* MSCAN0 Receive Error Counter Register; 0x0000080E */
volatile CAN0TXERRSTR _CAN0TXERR;                          /* MSCAN0 Transmit Error Counter Register; 0x0000080F */
volatile CAN0IDAR0STR _CAN0IDAR0;                          /* MSCAN0 Identifier Acceptance Register 0; 0x00000810 */
volatile CAN0IDAR1STR _CAN0IDAR1;                          /* MSCAN0 Identifier Acceptance Register 1; 0x00000811 */
volatile CAN0IDAR2STR _CAN0IDAR2;                          /* MSCAN0 Identifier Acceptance Register 2; 0x00000812 */
volatile CAN0IDAR3STR _CAN0IDAR3;                          /* MSCAN0 Identifier Acceptance Register 3; 0x00000813 */
volatile CAN0IDMR0STR _CAN0IDMR0;                          /* MSCAN0 Identifier Mask Register 0; 0x00000814 */
volatile CAN0IDMR1STR _CAN0IDMR1;                          /* MSCAN0 Identifier Mask Register 1; 0x00000815 */
volatile CAN0IDMR2STR _CAN0IDMR2;                          /* MSCAN0 Identifier Mask Register 2; 0x00000816 */
volatile CAN0IDMR3STR _CAN0IDMR3;                          /* MSCAN0 Identifier Mask Register 3; 0x00000817 */
volatile CAN0IDAR4STR _CAN0IDAR4;                          /* MSCAN0 Identifier Acceptance Register 4; 0x00000818 */
volatile CAN0IDAR5STR _CAN0IDAR5;                          /* MSCAN0 Identifier Acceptance Register 5; 0x00000819 */
volatile CAN0IDAR6STR _CAN0IDAR6;                          /* MSCAN0 Identifier Acceptance Register 6; 0x0000081A */
volatile CAN0IDAR7STR _CAN0IDAR7;                          /* MSCAN0 Identifier Acceptance Register 7; 0x0000081B */
volatile CAN0IDMR4STR _CAN0IDMR4;                          /* MSCAN0 Identifier Mask Register 4; 0x0000081C */
volatile CAN0IDMR5STR _CAN0IDMR5;                          /* MSCAN0 Identifier Mask Register 5; 0x0000081D */
volatile CAN0IDMR6STR _CAN0IDMR6;                          /* MSCAN0 Identifier Mask Register 6; 0x0000081E */
volatile CAN0IDMR7STR _CAN0IDMR7;                          /* MSCAN0 Identifier Mask Register 7; 0x0000081F */
volatile CAN0RXIDR0STR _CAN0RXIDR0;                        /* MSCAN0 Receive Identifier Register 0; 0x00000820 */
volatile CAN0RXIDR1STR _CAN0RXIDR1;                        /* MSCAN0 Receive Identifier Register 1; 0x00000821 */
volatile CAN0RXIDR2STR _CAN0RXIDR2;                        /* MSCAN0 Receive Identifier Register 2; 0x00000822 */
volatile CAN0RXIDR3STR _CAN0RXIDR3;                        /* MSCAN0 Receive Identifier Register 3; 0x00000823 */
volatile CAN0RXDSR0STR _CAN0RXDSR0;                        /* MSCAN0 Receive Data Segment Register 0; 0x00000824 */
volatile CAN0RXDSR1STR _CAN0RXDSR1;                        /* MSCAN0 Receive Data Segment Register 1; 0x00000825 */
volatile CAN0RXDSR2STR _CAN0RXDSR2;                        /* MSCAN0 Receive Data Segment Register 2; 0x00000826 */
volatile CAN0RXDSR3STR _CAN0RXDSR3;                        /* MSCAN0 Receive Data Segment Register 3; 0x00000827 */
volatile CAN0RXDSR4STR _CAN0RXDSR4;                        /* MSCAN0 Receive Data Segment Register 4; 0x00000828 */
volatile CAN0RXDSR5STR _CAN0RXDSR5;                        /* MSCAN0 Receive Data Segment Register 5; 0x00000829 */
volatile CAN0RXDSR6STR _CAN0RXDSR6;                        /* MSCAN0 Receive Data Segment Register 6; 0x0000082A */
volatile CAN0RXDSR7STR _CAN0RXDSR7;                        /* MSCAN0 Receive Data Segment Register 7; 0x0000082B */
volatile CAN0RXDLRSTR _CAN0RXDLR;                          /* MSCAN0 Receive Data Length Register; 0x0000082C */
volatile CAN0TXIDR0STR _CAN0TXIDR0;                        /* MSCAN0 Transmit Identifier Register 0; 0x00000830 */
volatile CAN0TXIDR1STR _CAN0TXIDR1;                        /* MSCAN0 Transmit Identifier Register 1; 0x00000831 */
volatile CAN0TXIDR2STR _CAN0TXIDR2;                        /* MSCAN0 Transmit Identifier Register 2; 0x00000832 */
volatile CAN0TXIDR3STR _CAN0TXIDR3;                        /* MSCAN0 Transmit Identifier Register 3; 0x00000833 */
volatile CAN0TXDSR0STR _CAN0TXDSR0;                        /* MSCAN0 Transmit Data Segment Register 0; 0x00000834 */
volatile CAN0TXDSR1STR _CAN0TXDSR1;                        /* MSCAN0 Transmit Data Segment Register 1; 0x00000835 */
volatile CAN0TXDSR2STR _CAN0TXDSR2;                        /* MSCAN0 Transmit Data Segment Register 2; 0x00000836 */
volatile CAN0TXDSR3STR _CAN0TXDSR3;                        /* MSCAN0 Transmit Data Segment Register 3; 0x00000837 */
volatile CAN0TXDSR4STR _CAN0TXDSR4;                        /* MSCAN0 Transmit Data Segment Register 4; 0x00000838 */
volatile CAN0TXDSR5STR _CAN0TXDSR5;                        /* MSCAN0 Transmit Data Segment Register 5; 0x00000839 */
volatile CAN0TXDSR6STR _CAN0TXDSR6;                        /* MSCAN0 Transmit Data Segment Register 6; 0x0000083A */
volatile CAN0TXDSR7STR _CAN0TXDSR7;                        /* MSCAN0 Transmit Data Segment Register 7; 0x0000083B */
volatile CAN0TXDLRSTR _CAN0TXDLR;                          /* MSCAN0 Transmit Data Length Register; 0x0000083C */
volatile CAN0TXTBPRSTR _CAN0TXTBPR;                        /* MSCAN0 Transmit Buffer Priority; 0x0000083D */
volatile CPDRSTR _CPDR;                                    /* Port CP Data Register; 0x00000990 */
volatile CPCRSTR _CPCR;                                    /* CAN Physical Layer Control Register; 0x00000991 */
volatile CPSRSTR _CPSR;                                    /* CAN Physical Layer Status Register; 0x00000993 */
volatile CPIESTR _CPIE;                                    /* CAN Physical Layer Interrupt Enable Register; 0x00000996 */
volatile CPIFSTR _CPIF;                                    /* CAN Physical Layer Interrupt Flag Register; 0x00000997 */
/* NVFPROT - macro for reading non volatile register       Non Volatile P-Flash Protection Register; 0x00FFFE0C */
/* Tip for register initialization in the user code:  const byte NVFPROT_INIT @0x00FFFE0C = <NVFPROT_INITVAL>; */
/* NVDFPROT - macro for reading non volatile register      Non Volatile D-Flash Protection Register; 0x00FFFE0D */
/* Tip for register initialization in the user code:  const byte NVDFPROT_INIT @0x00FFFE0D = <NVDFPROT_INITVAL>; */
/* NVFOPT - macro for reading non volatile register        Non Volatile Flash Option Register; 0x00FFFE0E */
/* Tip for register initialization in the user code:  const byte NVFOPT_INIT @0x00FFFE0E = <NVFOPT_INITVAL>; */
/* NVFSEC - macro for reading non volatile register        Non Volatile Flash Security Register; 0x00FFFE0F */
/* Tip for register initialization in the user code:  const byte NVFSEC_INIT @0x00FFFE0F = <NVFSEC_INITVAL>; */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile IVBRSTR _IVBR;                                    /* Interrupt Vector Base Register; 0x00000010 */
volatile MMCECSTR _MMCEC;                                  /* Error code register; 0x00000080 */
volatile MMCCCRSTR _MMCCCR;                                /* Captured S12ZCPU Condition Code Register; 0x00000082 */
volatile DBGTBSTR _DBGTB;                                  /* Debug Trace Buffer Register; 0x00000104 */
volatile PTADSTR _PTAD;                                    /* Port AD Data Register; 0x00000280 */
volatile PTIADSTR _PTIAD;                                  /* Port AD Input Register; 0x00000282 */
volatile DDRADSTR _DDRAD;                                  /* Port AD Data Direction Register; 0x00000284 */
volatile PERADSTR _PERAD;                                  /* Port AD Pull Device Enable Register; 0x00000286 */
volatile PPSADSTR _PPSAD;                                  /* Port AD Polarity Select Register; 0x00000288 */
volatile PIEADSTR _PIEAD;                                  /* Port AD Interrupt Enable Register; 0x0000028C */
volatile PIFADSTR _PIFAD;                                  /* Port AD Interrupt Flag Register; 0x0000028E */
volatile DIENADSTR _DIENAD;                                /* Digital Input Enable Register; 0x00000298 */
volatile FCCOB0STR _FCCOB0;                                /* Flash Common Command Object Register; 0x0000038C */
volatile FCCOB1STR _FCCOB1;                                /* Flash Common Command Object Register; 0x0000038E */
volatile FCCOB2STR _FCCOB2;                                /* Flash Common Command Object Register; 0x00000390 */
volatile FCCOB3STR _FCCOB3;                                /* Flash Common Command Object Register; 0x00000392 */
volatile FCCOB4STR _FCCOB4;                                /* Flash Common Command Object Register; 0x00000394 */
volatile FCCOB5STR _FCCOB5;                                /* Flash Common Command Object Register; 0x00000396 */
volatile ECCDDSTR _ECCDD;                                  /* ECC Debug Data; 0x000003CC */
volatile TIM1TCNTSTR _TIM1TCNT;                            /* Timer Count Register; 0x00000404 */
volatile TIM1TC0STR _TIM1TC0;                              /* Timer Input Capture/Output Compare Register 0; 0x00000410 */
volatile TIM1TC1STR _TIM1TC1;                              /* Timer Input Capture/Output Compare Register 1; 0x00000412 */
volatile PMFVAL0STR _PMFVAL0;                              /* PMF Value 0 Register; 0x00000510 */
volatile PMFVAL1STR _PMFVAL1;                              /* PMF Value 1 Register; 0x00000512 */
volatile PMFVAL2STR _PMFVAL2;                              /* PMF Value 2 Register; 0x00000514 */
volatile PMFVAL3STR _PMFVAL3;                              /* PMF Value 3 Register; 0x00000516 */
volatile PMFVAL4STR _PMFVAL4;                              /* PMF Value 4 Register; 0x00000518 */
volatile PMFVAL5STR _PMFVAL5;                              /* PMF Value 5 Register; 0x0000051A */
volatile PMFCNTASTR _PMFCNTA;                              /* PMF counter A Register; 0x00000522 */
volatile PMFMODASTR _PMFMODA;                              /* PMF modulo counter A Register; 0x00000524 */
volatile PMFDTMASTR _PMFDTMA;                              /* PMF deadtime A Register; 0x00000526 */
volatile PMFCNTBSTR _PMFCNTB;                              /* PMF counter B Register; 0x0000052A */
volatile PMFMODBSTR _PMFMODB;                              /* PMF modulo counter B Register; 0x0000052C */
volatile PMFDTMBSTR _PMFDTMB;                              /* PMF deadtime B Register; 0x0000052E */
volatile PMFCNTCSTR _PMFCNTC;                              /* PMF counter C Register; 0x00000532 */
volatile PMFMODCSTR _PMFMODC;                              /* PMF modulo counter C Register; 0x00000534 */
volatile PMFDTMCSTR _PMFDTMC;                              /* PMF deadtime C Register; 0x00000536 */
volatile TIM0TCNTSTR _TIM0TCNT;                            /* Timer Count Register; 0x000005C4 */
volatile TIM0TC0STR _TIM0TC0;                              /* Timer Input Capture/Output Compare Register 0; 0x000005D0 */
volatile TIM0TC1STR _TIM0TC1;                              /* Timer Input Capture/Output Compare Register 1; 0x000005D2 */
volatile TIM0TC2STR _TIM0TC2;                              /* Timer Input Capture/Output Compare Register 2; 0x000005D4 */
volatile TIM0TC3STR _TIM0TC3;                              /* Timer Input Capture/Output Compare Register 3; 0x000005D6 */
volatile ADC0CTLSTR _ADC0CTL;                              /* ADC0 Control Register; 0x00000600 */
volatile ADC0CONIESTR _ADC0CONIE;                          /* ADC0 Conversion Interrupt Enable Register; 0x0000060A */
volatile ADC0CONIFSTR _ADC0CONIF;                          /* ADC0 Conversion Interrupt Flag Register; 0x0000060C */
volatile ADC0IMDRISTR _ADC0IMDRI;                          /* ADC0 Intermediate Result Information Register; 0x0000060E */
volatile ADC1CTLSTR _ADC1CTL;                              /* ADC1 Control Register; 0x00000640 */
volatile ADC1CONIESTR _ADC1CONIE;                          /* ADC1 Conversion Interrupt Enable Register; 0x0000064A */
volatile ADC1CONIFSTR _ADC1CONIF;                          /* ADC1 Conversion Interrupt Flag Register; 0x0000064C */
volatile ADC1IMDRISTR _ADC1IMDRI;                          /* ADC1 Intermediate Result Information Register; 0x0000064E */
volatile CPMUAPIRSTR _CPMUAPIR;                            /* Autonomous Periodical Interrupt Rate Register; 0x000006D4 */
volatile CPMUIRCTRIMSTR _CPMUIRCTRIM;                      /* CPMU IRC1M Trim Registers; 0x000006D8 */
volatile SCI0BDSTR _SCI0BD;                                /* SCI 0 Baud Rate Register; 0x00000700 */
volatile SCI1BDSTR _SCI1BD;                                /* SCI 1 Baud Rate Register; 0x00000710 */
volatile SPI0DRSTR _SPI0DR;                                /* SPI 0 Data Register; 0x00000784 */
volatile CAN0RXTSRSTR _CAN0RXTSR;                          /* MSCAN0 Receive Time Stamp Register; 0x0000082E */
volatile CAN0TXTSRSTR _CAN0TXTSR;                          /* MSCAN0 Transmit Time Stamp Register; 0x0000083E */
/* BAKEY0 - macro for reading non volatile register        Backdoor Comparison Key 0; 0x00FFFE00 */
/* Tip for register initialization in the user code:  const byte BAKEY0_INIT @0x00FFFE00 = <BAKEY0_INITVAL>; */
/* BAKEY1 - macro for reading non volatile register        Backdoor Comparison Key 1; 0x00FFFE02 */
/* Tip for register initialization in the user code:  const byte BAKEY1_INIT @0x00FFFE02 = <BAKEY1_INITVAL>; */
/* BAKEY2 - macro for reading non volatile register        Backdoor Comparison Key 2; 0x00FFFE04 */
/* Tip for register initialization in the user code:  const byte BAKEY2_INIT @0x00FFFE04 = <BAKEY2_INITVAL>; */
/* BAKEY3 - macro for reading non volatile register        Backdoor Comparison Key 3; 0x00FFFE06 */
/* Tip for register initialization in the user code:  const byte BAKEY3_INIT @0x00FFFE06 = <BAKEY3_INITVAL>; */
/* PROTKEY - macro for reading non volatile register       Non Volatile Protection Override Comparison Key; 0x00FFFE08 */
/* Tip for register initialization in the user code:  const byte PROTKEY_INIT @0x00FFFE08 = <PROTKEY_INITVAL>; */


/* * * * *  32-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PARTIDSTR _PARTID;                                /* Part ID Register; 0x00000000 */
volatile ADC0CMDSTR _ADC0CMD;                              /* ADC0 Command Register; 0x00000614 */
volatile ADC1CMDSTR _ADC1CMD;                              /* ADC1 Command Register; 0x00000654 */


/* * * * *  24-BIT ADDRESS REGISTERS  * * * * * * * * * * * * * * * * * * * * * * */
volatile void* volatile MMCPC;                             /* Captured S12ZCPU Program Counter Low; 0x00000087 */
volatile void* volatile DBGAA;                             /* Debug Comparator A Address Register Low; 0x00000117 */
volatile void* volatile DBGBA;                             /* Debug Comparator B Address Register Low; 0x00000127 */
volatile void* volatile DBGCA;                             /* Debug Comparator C Address Register Low; 0x00000137 */
volatile void* volatile DBGDA;                             /* Debug Comparator D Address Register Low; 0x00000147 */
volatile void* volatile ECCDPTR;                           /* ECC Debug Pointer Register Low; 0x000003C9 */
volatile void* volatile PTUPTR;                            /* PTU Pointer Register; 0x00000593 */



/*lint -restore */

/* EOF */
