/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2009 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup demo_application_for_diagnostic
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      LL64_init.c
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Jan-21-2011 
*
* @brief     Common initialization for LL64
*
******************************************************************************/

#include "LL64_init.h"

void cpu_init(void)
{
  /* ### MC9S08LL64_80 "Cpu" init code ... */ 
  /* Common initialization of the write once registers */
  /* SOPT1: COPE=0,COPT=1,STOPE=1,??=0,??=0,??=0,BKGDPE=1,RSTPE=1 */
  setReg8(SOPT1, 0x63);                 
  /* SPMSC1: LVDF=0,LVDACK=0,LVDIE=0,LVDRE=1,LVDSE=1,LVDE=0,BGBDS=1,BGBE=0 */
  setReg8(SPMSC1, 0x1A);                
  /* SPMSC2: LPR=0,LPRS=0,LPWUI=0,??=0,PPDF=0,PPDACK=0,PPDE=1,PPDC=0 */
  setReg8(SPMSC2, 0x02);                
  /* SPMSC3: LVDV=0,LVWV=0,LVWIE=0 */
  clrReg8Bits(SPMSC3, 0x38);            
  /*  System clock initialization */
  if (*(unsigned char*)0xFFAF != 0xFF) { /* Test if the device trim value is stored on the specified address */
    ICSTRM = *(unsigned char*)0xFFAF;  /* Initialize ICSTRM register from a non volatile memory */
    ICSSC = (unsigned char)((*(unsigned char*)0xFFAE) & (unsigned char)0x01); /* Initialize ICSSC register from a non volatile memory */
  }
  /* ICSC1: CLKS=0,RDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  setReg8(ICSC1, 0x06);                /* Initialization of the ICS control register 1 */ 
  /* ICSC2: BDIV=0,RANGE=0,HGO=0,LP=0,EREFS=1,ERCLKEN=1,EREFSTEN=1 */
  setReg8(ICSC2, 0x07);                /* Initialization of the ICS control register 2 */ 
  while(!ICSSC_IREFST) {               /* Wait until the source of reference clock is internal clock */
  }
  /* ICSSC: DRST_DRS=0,DMX32=0 */
  clrReg8Bits(ICSSC, 0xE0);            /* Initialization of the ICS status and control */ 
  while((ICSSC & 0xC0) != 0x00) {      /* Wait until the FLL switches to Low range DCO mode */
  }    
  /* SCGC1: VREF2=0,TPM2=0,TPM1=1,ADC=1,VREF1=0,IIC=0,SCI2=0,SCI1=1 */
  setReg8(SCGC1, 0x31);                 
  /* SCGC2: DBG=1,FLS=1,IRQ=1,KBI=1,ACMP=0,TOD=1,LCD=1,SPI=0 */
  setReg8(SCGC2, 0xF6);                   
  /* Common initialization of the CPU registers */  
  /* PTCD: PTCD5=1,PTCD4=1,PTCD3=1,PTCD2=1,PTCD1=1 */
//  setReg8Bits(PTCD, 0x3E);                                                        /* PTCPE: PTCPE7=1,PTCPE5=0,PTCPE4=0,PTCPE3=0,PTCPE2=0 */
//  clrSetReg8Bits(PTCPE, 0x3C, 0x80);    
//  /* PTCDD: PTCDD7=0,PTCDD5=1,PTCDD4=1,PTCDD3=1,PTCDD2=1,PTCDD1=1,PTCDD0=0 */
//  clrSetReg8Bits(PTCDD, 0x81, 0x3E);      
//  /* PTBD: PTBD7=1,PTBD6=1,PTBD5=0,PTBD4=1 */
//  clrSetReg8Bits(PTBD, 0x20, 0xD0);     
//  /* PTBPE: PTBPE5=1 */
//  setReg8Bits(PTBPE, 0x20);             
//  /* PTBDD: PTBDD7=1,PTBDD6=1,PTBDD5=1,PTBDD4=1 */  
//  setReg8Bits(PTBDD, 0xF0);               
//  /* PTAPE: PTAPE7=1,PTAPE6=1, PTAPE4=1 */
//    PTAPE |= (unsigned char)0xD0;                                   
//  /* PTASE: PTASE7=0,PTASE6=0,PTASE5=0,PTASE4=0,PTASE3=0,PTASE2=0,PTASE1=0,PTASE0=0 */
//    PTASE = 0xFF;                                          
//  /* PTBSE: PTBSE7=0,PTBSE6=0,PTBSE5=0,PTBSE4=0,PTBSE2=0,PTBSE1=0,PTBSE0=0 */
//  clrReg8Bits(PTBSE, 0xF7);             
//  /* PTCSE: PTCSE7=0,PTCSE6=0,PTCSE5=0,PTCSE4=0,PTCSE3=0,PTCSE2=0,PTCSE1=0,PTCSE0=0 */
//  setReg8(PTCSE, 0x00);                 
//  /* PTDSE: PTDSE7=0,PTDSE6=0,PTDSE5=0,PTDSE4=0,PTDSE3=0,PTDSE2=0,PTDSE1=0,PTDSE0=0 */    
//  setReg8(PTDSE, 0x00);                 
//  /* PTESE: PTESE7=0,PTESE6=0,PTESE5=0,PTESE4=0,PTESE3=0,PTESE2=0,PTESE1=0,PTESE0=0 */  
//  setReg8(PTESE, 0x00);                     
//  /* PTADS: PTADS7=1,PTADS6=1,PTADS5=1,PTADS4=1,PTADS3=1,PTADS2=1,PTADS1=1,PTADS0=1 */
//    PTADS = 0x00;                                      
//  /* PTBDS: PTBDS7=0,PTBDS6=0,PTBDS5=0,PTBDS4=0,??=0,PTBDS2=1,PTBDS1=1,PTBDS0=1 */
//  setReg8(PTBDS, 0x07);                 
//  /* PTCDS: PTCDS7=1,PTCDS6=1,PTCDS5=1,PTCDS4=1,PTCDS3=0,PTCDS2=0,PTCDS1=1,PTCDS0=1 */
//  setReg8(PTCDS, 0xF3);                 
//  /* PTDDS: PTDDS7=1,PTDDS6=1,PTDDS5=1,PTDDS4=1,PTDDS3=1,PTDDS2=1,PTDDS1=1,PTDDS0=1 */
//  setReg8(PTDDS, 0xFF);                 
//  /* PTEDS: PTEDS7=1,PTEDS6=1,PTEDS5=1,PTEDS4=1,PTEDS3=1,PTEDS2=1,PTEDS1=1,PTEDS0=1 */
//  setReg8(PTEDS, 0xFF);                 
//  /* PTAD: PTAD5=1 */
//  setReg8Bits(PTAD, 0x20);              
//  /* PTADD: PTADD5=1 */
//  setReg8Bits(PTADD, 0x20);   
//  clrReg8Bits(PTADD, 0x00);          
  /* ### Shared modules init code ... */ 
    /* SCGC1: VREF2=1,TPM2=1,TPM1=1,ADC=1,VREF1=1,IIC=1,SCI2=1,SCI1=1 */
  SCGC1 = 0xFF;                                      
  /* SCGC2: DBG=1,FLS=1,IRQ=1,KBI=1,ACMP=1,TOD=1,LCD=1,SPI=1 */
  SCGC2 = 0xFF;                                       
}

void MCU_init(void)
{
  /* ### MC9S08LL64_80 "Cpu" init code ... */
  /*  PE initialization code after reset */

  /* Common initialization of the write once registers */
  /* SOPT1: COPE=0,COPT=1,STOPE=0,BKGDPE=1,RSTPE=1 */
  SOPT1 = 0x43;                                      
  /* SPMSC1: LVDF=0,LVDACK=0,LVDIE=0,LVDRE=1,LVDSE=1,LVDE=1,BGBDS=0,BGBE=0 */
  SPMSC1 = 0x1C;                                      
  /* SPMSC2: LPR=0,LPRS=0,LPWUI=0,PPDF=0,PPDACK=0,PPDE=1,PPDC=0 */
  SPMSC2 = 0x02;                                      
  /* SPMSC3: LVDV=0,LVWV=0,LVWIE=0 */
  SPMSC3 &= (unsigned char)~0x38;                     
  /*  System clock initialization */
  if (*(unsigned char*far)0xFFAF != 0xFF) { /* Test if the device trim value is stored on the specified address */
    ICSTRM = *(unsigned char*far)0xFFAF; /* Initialize ICSTRM register from a non volatile memory */
    ICSSC = (unsigned char)((*(unsigned char*far)0xFFAE) & (unsigned char)0x01); /* Initialize ICSSC register from a non volatile memory */
  }
  /* ICSC1: CLKS=0,RDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  ICSC1 = 0x06;                        /* Initialization of the ICS control register 1 */
  /* ICSC2: BDIV=0,RANGE=0,HGO=0,LP=0,EREFS=0,ERCLKEN=0,EREFSTEN=0 */
  ICSC2 = 0x00;                        /* Initialization of the ICS control register 2 */
  while(!ICSSC_IREFST) {               /* Wait until the source of reference clock is internal clock */
  }
  /* ICSSC: DRST_DRS=0,DMX32=0 */
  ICSSC &= (unsigned char)~0xE0;       /* Initialization of the ICS status and control */
  while((ICSSC & 0xC0) != 0x00) {      /* Wait until the FLL switches to Low range DCO mode */
  }
  /* SCGC1: VREF2=1,TPM2=1,TPM1=1,ADC=1,VREF1=1,IIC=1,SCI2=1,SCI1=1 */
  SCGC1 = 0xFF;                                      
  /* SCGC2: DBG=1,FLS=1,IRQ=1,KBI=1,ACMP=1,TOD=1,LCD=1,SPI=1 */
  SCGC2 = 0xFF;                                      
  /* Common initialization of the CPU registers */
  /* PTASE: PTASE7=1,PTASE6=1,PTASE5=1,PTASE4=1,PTASE3=1,PTASE2=1,PTASE1=1,PTASE0=1 */
  PTASE = 0xFF;                                      
  /* PTBSE: PTBSE7=1,PTBSE6=1,PTBSE5=1,PTBSE4=1,PTBSE2=1,PTBSE1=1,PTBSE0=1 */
  PTBSE |= (unsigned char)0xF7;                      
  /* PTCSE: PTCSE7=1,PTCSE6=1,PTCSE5=1,PTCSE4=1,PTCSE3=1,PTCSE2=1,PTCSE1=1,PTCSE0=1 */
  PTCSE = 0xFF;                                      
  /* PTDSE: PTDSE7=1,PTDSE6=1,PTDSE5=1,PTDSE4=1,PTDSE3=1,PTDSE2=1,PTDSE1=1,PTDSE0=1 */
  PTDSE = 0xFF;                                      
  /* PTESE: PTESE7=1,PTESE6=1,PTESE5=1,PTESE4=1,PTESE3=1,PTESE2=1,PTESE1=1,PTESE0=1 */
  PTESE = 0xFF;                                      
  /* PTADS: PTADS7=0,PTADS6=0,PTADS5=0,PTADS4=0,PTADS3=0,PTADS2=0,PTADS1=0,PTADS0=0 */
  PTADS = 0x00;                                      
  /* PTBDS: PTBDS7=0,PTBDS6=0,PTBDS5=0,PTBDS4=0,PTBDS2=0,PTBDS1=0,PTBDS0=0 */
  PTBDS = 0x00;                                      
  /* PTCDS: PTCDS7=0,PTCDS6=0,PTCDS5=0,PTCDS4=0,PTCDS3=0,PTCDS2=0,PTCDS1=0,PTCDS0=0 */
  PTCDS = 0x00;                                      
  /* PTDDS: PTDDS7=0,PTDDS6=0,PTDDS5=0,PTDDS4=0,PTDDS3=0,PTDDS2=0,PTDDS1=0,PTDDS0=0 */
  PTDDS = 0x00;                                      
  /* PTEDS: PTEDS7=0,PTEDS6=0,PTEDS5=0,PTEDS4=0,PTEDS3=0,PTEDS2=0,PTEDS1=0,PTEDS0=0 */
//  PTEDS = 0x00; 
  setReg8(PTESE, 0x00);    
  setReg8(PTEDS, 0xFF);  
  setReg8(PTDSE, 0x00); 
  setReg8(PTDDS, 0xFF);                 
                                                                                     
} /*MCU_init*/

void SCI2_init(void) {
  /* SCI2C2: TIE=0,TCIE=0,RIE=0,ILIE=0,TE=0,RE=0,RWU=0,SBK=0 */
  SCI2C2 = 0x00;                       /* Disable the SCI2 module */
  (void)(SCI2S1 == 0);                 /* Dummy read of the SCI2S1 register to clear flags */
  (void)(SCI2D == 0);                  /* Dummy read of the SCI2D register to clear flags */
  /* SCI2S2: LBKDIF=1,RXEDGIF=1,RXINV=0,RWUID=0,BRK13=1,LBKDE=0,RAF=0 */
  SCI2S2 = 0xC4;                                      
  /* SCI2BDH: LBKDIE=1,RXEDGIE=0,SBR12=0,SBR11=0,SBR10=0,SBR9=0,SBR8=0 */
  SCI2BDH = 0x00;                                      
  /* SCI2BDL: SBR7=0,SBR6=0,SBR5=0,SBR4=1,SBR3=1,SBR2=0,SBR1=1,SBR0=1 */
  SCI2BDL = 0x1B;  //0x24;// 0x1B;//0x1B;                                      
  /* SCI2C1: LOOPS=1,SCISWAI=0,RSRC=1,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  SCI2C1 = 0xA0;                                      
  /* SCI2C3: R8=0,T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
  SCI2C3 = 0x00;                                      
  /* SCI2C2: TIE=0,TCIE=0,RIE=1,ILIE=0,TE=1,RE=1,RWU=0,SBK=0 */
  SCI2C2 = 0x0C;                                      
}

void LED_init(void) {
  PTCDD = (0x0F << 2);
  PTCD  = 0xFF;  
  /* ### */
}