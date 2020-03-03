/* Based on CPU DB MC9S12ZVL32_48, version 3.00.000 (RegistersPrg V2.33) */
/* DataSheet : MC9S12ZVLRMV1 Rev. 0.09 December 10, 2012 */

#include <mc9s12zvl32.h>

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
volatile DBGDCTLSTR _DBGDCTL;                              /* Debug Comparator D Control Register; 0x00000140 */
volatile DBGDAHSTR _DBGDAH;                                /* Debug Comparator D Address Register High; 0x00000145 */
volatile DBGDAMSTR _DBGDAM;                                /* Debug Comparator D Address Register Middle; 0x00000146 */
volatile DBGDALSTR _DBGDAL;                                /* Debug Comparator D Address Register Low; 0x00000147 */
volatile MODRR0STR _MODRR0;                                /* Module Routing Register 0; 0x00000200 */
volatile MODRR1STR _MODRR1;                                /* Module Routing Register 1; 0x00000201 */
volatile MODRR2STR _MODRR2;                                /* Module Routing Register 2; 0x00000202 */
volatile MODRR3STR _MODRR3;                                /* Module Routing Register 3; 0x00000203 */
volatile MODRR4STR _MODRR4;                                /* Module Routing Register 4; 0x00000204 */
volatile ECLKCTLSTR _ECLKCTL;                              /* ECLK Control Register; 0x00000208 */
volatile IRQCRSTR _IRQCR;                                  /* Interrupt Control Register; 0x00000209 */
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
volatile OCPEPSTR _OCPEP;                                  /* Port P Over-Current Protection Enable Register; 0x000002F9 */
volatile OCIEPSTR _OCIEP;                                  /* Port P Over-Current Interrupt Enable Register; 0x000002FA */
volatile OCIFPSTR _OCIFP;                                  /* Port P Over-Current Interrupt Flag Register; 0x000002FB */
volatile RDRPSTR _RDRP;                                    /* Port P Reduced Drive Register; 0x000002FD */
volatile PTJSTR _PTJ;                                      /* Port J Data Register; 0x00000310 */
volatile PTIJSTR _PTIJ;                                    /* Port J Input Register; 0x00000311 */
volatile DDRJSTR _DDRJ;                                    /* Port J Data Direction Register; 0x00000312 */
volatile PERJSTR _PERJ;                                    /* Port J Pull Device Enable Register; 0x00000313 */
volatile PPSJSTR _PPSJ;                                    /* Port J Polarity Select Register; 0x00000314 */
volatile WOMJSTR _WOMJ;                                    /* Port J Wired-Or Mode Register; 0x0000031F */
volatile PTILSTR _PTIL;                                    /* Port L Input Register; 0x00000331 */
volatile PPSLSTR _PPSL;                                    /* Port L Polarity Select Register; 0x00000334 */
volatile PIELSTR _PIEL;                                    /* Port L Interrupt Enable Register; 0x00000336 */
volatile PIFLSTR _PIFL;                                    /* Port L Interrupt Flag Register; 0x00000337 */
volatile DIENLSTR _DIENL;                                  /* Port LDigital Input Enable Register; 0x0000033C */
volatile PTALSTR _PTAL;                                    /* Port L Analog Access Register; 0x0000033D */
volatile PIRLSTR _PIRL;                                    /* Port L Input Divider Ratio Selection Register; 0x0000033E */
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
volatile PWMCLKABSTR _PWMCLKAB;                            /* PWM Clock Select Register; 0x00000486 */
volatile PWMSCLASTR _PWMSCLA;                              /* PWM Scale A Register; 0x00000488 */
volatile PWMSCLBSTR _PWMSCLB;                              /* PWM Scale B Register; 0x00000489 */
volatile TIM0TIOSSTR _TIM0TIOS;                            /* Timer Input Capture/Output Compare Select; 0x000005C0 */
volatile TIM0CFORCSTR _TIM0CFORC;                          /* Timer Compare Force Register; 0x000005C1 */
volatile TIM0TSCR1STR _TIM0TSCR1;                          /* Timer System Control Register1; 0x000005C6 */
volatile TIM0TTOVSTR _TIM0TTOV;                            /* Timer Toggle On Overflow Register; 0x000005C7 */
volatile TIM0TCTL1STR _TIM0TCTL1;                          /* Timer Control Register 1; 0x000005C8 */
volatile TIM0TCTL2STR _TIM0TCTL2;                          /* Timer Control Register 2; 0x000005C9 */
volatile TIM0TCTL3STR _TIM0TCTL3;                          /* Timer Control Register 3; 0x000005CA */
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
volatile IIC0IBADSTR _IIC0IBAD;                            /* IIC Address Register; 0x000007C0 */
volatile IIC0IBFDSTR _IIC0IBFD;                            /* IIC Frequency Divider Register; 0x000007C1 */
volatile IIC0IBCRSTR _IIC0IBCR;                            /* IIC Control Register; 0x000007C2 */
volatile IIC0IBSRSTR _IIC0IBSR;                            /* IIC Status Register; 0x000007C3 */
volatile IIC0IBDRSTR _IIC0IBDR;                            /* IIC Data I/O Register; 0x000007C4 */
volatile IIC0IBCR2STR _IIC0IBCR2;                          /* IIC Control Register 2; 0x000007C5 */
volatile LP0DRSTR _LP0DR;                                  /* Port LP Data Register; 0x00000980 */
volatile LP0CRSTR _LP0CR;                                  /* LIN Control Register; 0x00000981 */
volatile LP0SLRMSTR _LP0SLRM;                              /* LIN Slew Rate Register; 0x00000983 */
volatile LP0SRSTR _LP0SR;                                  /* LIN Status Register; 0x00000985 */
volatile LP0IESTR _LP0IE;                                  /* LIN Interrupt Enable Register; 0x00000986 */
volatile LP0IFSTR _LP0IF;                                  /* LIN Interrupt Flags Register; 0x00000987 */
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
volatile MMCCCRSTR _MMCCCR;                                /* Captured S12ZCPU Condition Code Register Low; 0x00000082 */
volatile PTADSTR _PTAD;                                    /* Port AD Data Register; 0x00000280 */
volatile PTIADSTR _PTIAD;                                  /* Port AD Input Register; 0x00000282 */
volatile DDRADSTR _DDRAD;                                  /* Port AD Data Direction Register; 0x00000284 */
volatile PERADSTR _PERAD;                                  /* Port AD Pull Up Enable Register; 0x00000286 */
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
volatile PWMCNT01STR _PWMCNT01;                            /* PWM Channel Counter 01 Register; 0x0000048C */
volatile PWMCNT23STR _PWMCNT23;                            /* PWM Channel Counter 23 Register; 0x0000048E */
volatile PWMCNT45STR _PWMCNT45;                            /* PWM Channel Counter 45 Register; 0x00000490 */
volatile PWMCNT67STR _PWMCNT67;                            /* PWM Channel Counter 67 Register; 0x00000492 */
volatile PWMPER01STR _PWMPER01;                            /* PWM Channel Period 01 Register; 0x00000494 */
volatile PWMPER23STR _PWMPER23;                            /* PWM Channel Period 23 Register; 0x00000496 */
volatile PWMPER45STR _PWMPER45;                            /* PWM Channel Period 45 Register; 0x00000498 */
volatile PWMPER67STR _PWMPER67;                            /* PWM Channel Period 67 Register; 0x0000049A */
volatile PWMDTY01STR _PWMDTY01;                            /* PWM Channel Duty 01 Register; 0x0000049C */
volatile PWMDTY23STR _PWMDTY23;                            /* PWM Channel Duty 23 Register; 0x0000049E */
volatile PWMDTY45STR _PWMDTY45;                            /* PWM Channel Duty 45 Register; 0x000004A0 */
volatile PWMDTY67STR _PWMDTY67;                            /* PWM Channel Duty 67 Register; 0x000004A2 */
volatile TIM0TCNTSTR _TIM0TCNT;                            /* Timer Count Register; 0x000005C4 */
volatile TIM0TC0STR _TIM0TC0;                              /* Timer Input Capture/Output Compare Register 0; 0x000005D0 */
volatile TIM0TC1STR _TIM0TC1;                              /* Timer Input Capture/Output Compare Register 1; 0x000005D2 */
volatile TIM0TC2STR _TIM0TC2;                              /* Timer Input Capture/Output Compare Register 2; 0x000005D4 */
volatile TIM0TC3STR _TIM0TC3;                              /* Timer Input Capture/Output Compare Register 3; 0x000005D6 */
volatile TIM0TC4STR _TIM0TC4;                              /* Timer Input Capture/Output Compare Register 4; 0x000005D8 */
volatile TIM0TC5STR _TIM0TC5;                              /* Timer Input Capture/Output Compare Register 5; 0x000005DA */
volatile ADC0CTLSTR _ADC0CTL;                              /* ADC0 Control Register; 0x00000600 */
volatile ADC0CONIESTR _ADC0CONIE;                          /* ADC0 Conversion Interrupt Enable Register; 0x0000060A */
volatile ADC0CONIFSTR _ADC0CONIF;                          /* ADC0 Conversion Interrupt Flag Register; 0x0000060C */
volatile ADC0IMDRISTR _ADC0IMDRI;                          /* ADC0 Intermediate Result Information Register; 0x0000060E */
volatile CPMUAPIRSTR _CPMUAPIR;                            /* Autonomous Periodical Interrupt Rate Register; 0x000006D4 */
volatile CPMUIRCTRIMSTR _CPMUIRCTRIM;                      /* CPMU IRC1M Trim Registers; 0x000006D8 */
volatile SCI0BDSTR _SCI0BD;                                /* SCI 0 Baud Rate Register; 0x00000700 */
volatile SCI1BDSTR _SCI1BD;                                /* SCI 1 Baud Rate Register; 0x00000710 */
volatile SPI0DRSTR _SPI0DR;                                /* SPI 0 Data Register; 0x00000784 */
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


/* * * * *  24-BIT ADDRESS REGISTERS  * * * * * * * * * * * * * * * * * * * * * * */
volatile void* volatile MMCPC;                             /* Captured S12ZCPU Program Counter Low; 0x00000087 */
volatile void* volatile DBGAA;                             /* Debug Comparator A Address Register Low; 0x00000117 */
volatile void* volatile DBGBA;                             /* Debug Comparator B Address Register Low; 0x00000127 */
volatile void* volatile DBGDA;                             /* Debug Comparator D Address Register Low; 0x00000147 */
volatile void* volatile ECCDPTR;                           /* ECC Debug Point Register Low; 0x000003C9 */
volatile void* volatile ADC0CBP;                           /* ADC0 Command Base Pointer Register 0; 0x000003C9 */
volatile void* volatile ADC0RBP;                           /* ADC0 Result Base Pointer Register 0; 0x000003C9 */



/*lint -restore */

/* EOF */
