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
* @file      MCU_init.c
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Feb-9-2011 
*
* @brief     Initialization for G128 
*
******************************************************************************/

#include "MCU_init.h"

extern byte LED_value;
extern byte SW_flag;

void MCU_init(void)
{
  /* ### MC9S12G128_100 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /*  System clock initialization */
  /* CPMUPROT: PROT=0 */
//  CPMUPROT = 0x26U;                    /* Disable protection of clock configuration registers */
//  /* CPMUCLKS: PSTP=0 */
//  CPMUCLKS &= (unsigned char)~(unsigned char)0x40U;                     
//  /* CPMUCLKS: PLLSEL=1 */
//  CPMUCLKS |= (unsigned char)0x80U;    /* Enable the PLL to allow write to divider registers */
//  /* CPMUSYNR: VCOFRQ1=0,VCOFRQ0=1,SYNDIV5=0,SYNDIV4=1,SYNDIV3=1,SYNDIV2=0,SYNDIV1=0,SYNDIV0=0 */
//  CPMUSYNR = 0x58U;                    /* Set the multiplier register */
//  /* CPMUPOSTDIV: POSTDIV4=0,POSTDIV3=0,POSTDIV2=0,POSTDIV1=1,POSTDIV0=1 */
//  CPMUPOSTDIV = 0x03U;                 /* Set the post divider register */
//  /* CPMUPLL: FM1=0,FM0=0 */
//  CPMUPLL = 0x00U;                     /* Set the PLL frequency modulation */

  /* ### MC9S12G128_100 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /*  System clock initialization */
  /* CPMUPROT: PROT=0 */
  CPMUPROT = 0x26U;                    /* Disable protection of clock configuration registers */
  /* CPMUCLKS: PSTP=0 */
  CPMUCLKS &= (unsigned char)~(unsigned char)0x40U;                     
  /* CPMUCLKS: PLLSEL=1 */
  CPMUCLKS |= (unsigned char)0x80U;    /* Enable the PLL to allow write to divider registers */
  /* CPMUSYNR: VCOFRQ1=0,VCOFRQ0=0,SYNDIV5=0,SYNDIV4=1,SYNDIV3=0,SYNDIV2=1,SYNDIV1=1,SYNDIV0=1 */
  CPMUSYNR = 0x17U;                    /* Set the multiplier register */
  /* CPMUPOSTDIV: POSTDIV4=0,POSTDIV3=0,POSTDIV2=0,POSTDIV1=1,POSTDIV0=0 */
  CPMUPOSTDIV = 0x02U;                 /* Set the post divider register */
  /* CPMUPLL: FM1=0,FM0=0 */
  CPMUPLL = 0x00U;                     /* Set the PLL frequency modulation */
  
  while(CPMUFLG_LOCK == 0U) {          /* Wait until the PLL is within the desired tolerance of the target frequency */
  }
  /* CPMUPROT: PROT=0 */
  CPMUPROT = 0x00U;                    /* Enable protection of clock configuration registers */
  /* CPMUCOP: RSBCK=0,WRTMASK=0 */
  CPMUCOP &= (unsigned char)~(unsigned char)0x60U;                     
  /* Common initialization of the CPU registers */
  /* CPMUINT: LOCKIE=0,OSCIE=0 */
  CPMUINT &= (unsigned char)~(unsigned char)0x12U;                     
  /* CPMULVCTL: LVIE=0 */
  CPMULVCTL &= (unsigned char)~(unsigned char)0x02U;                     
  /* IRQCR: IRQEN=0 */
  IRQCR &= (unsigned char)~(unsigned char)0x40U;                     
  /* ATDDIEN: IEN7=1,IEN6=1,IEN5=1,IEN4=1 */
  ATDDIEN |= 0xF0U;                                  
  /* ### Init_GPIO init code */
    /* Enable interrupts */
  /* PIE1AD: PIE1AD7=0,PIE1AD6=0,PIE1AD5=0,PIE1AD4=0,PIE1AD3=0,PIE1AD2=0,PIE1AD1=0,PIE1AD0=0 */
  PIE1AD = 0xF0U;                                      
    /* Clear interrupt flags */
  /* PIF1AD: PIF1AD7=1,PIF1AD6=1,PIF1AD5=1,PIF1AD4=1,PIF1AD3=1,PIF1AD2=1,PIF1AD1=1,PIF1AD0=1 */
  PIF1AD = 0xFFU;                                      
  /* PPS1AD: PPS1AD7=0,PPS1AD6=0,PPS1AD5=0,PPS1AD4=0 */
  PPS1AD &= (unsigned char)~(unsigned char)0xF0U;                     
  /* PER1AD: PER1AD7=1,PER1AD6=1,PER1AD5=1,PER1AD4=1 */
  PER1AD |= (unsigned char)0xF0U;                      
  /* DDR1AD: DDR1AD7=0,DDR1AD6=0,DDR1AD5=0,DDR1AD4=0 */
  DDR1AD &= (unsigned char)~(unsigned char)0xF0U;                     
  /* ### Init_GPIO init code */
  /* PTT: PTT7=1,PTT6=1,PTT5=1,PTT4=1 */
  PTT |= (unsigned char)0xF0U;                      
  /* DDRT: DDRT7=1,DDRT6=1,DDRT5=1,DDRT4=1 */
  DDRT |= (unsigned char)0xF0U;                      
  /* ### Init_ADC init code */
  /* Initialization of the ADC module */
  /* ATDDIEN: IEN11=0,IEN10=0,IEN9=0,IEN8=0,IEN7=0,IEN6=0,IEN5=0,IEN4=0,IEN3=0,IEN2=0,IEN1=0,IEN0=0 */
  ATDDIEN |= 0xF001U;                            
  /* ATDCTL0: WRAP3=1,WRAP2=1,WRAP1=1,WRAP0=1 */
  ATDCTL0 = 0x0FU;                                      
  /* ATDCTL1: ETRIGSEL=0,SRES1=0,SRES0=0,SMP_DIS=0,ETRIGCH3=1,ETRIGCH2=1,ETRIGCH1=1,ETRIGCH0=1 */
  ATDCTL1 = 0x0FU;                                      
  /* ATDCTL3: DJM=1,S8C=0,S4C=0,S2C=0,S1C=1,FIFO=1,FRZ1=0,FRZ0=0 */
  ATDCTL3 = 0x8CU;                                      
  /* ATDCTL4: SMP2=0,SMP1=0,SMP0=0,PRS4=0,PRS3=1,PRS2=0,PRS1=1,PRS0=0 */
  ATDCTL4 = 0x0AU;                                      
  /* ATDCTL2: AFFC=1,ICLKSTP=0,ETRIGLE=0,ETRIGP=0,ETRIGE=0,ASCIE=0,ACMPIE=0 */
  ATDCTL2 = 0x40U;                                      
  /* ATDCTL5: SC=0,SCAN=1,MULT=0,CD=0,CC=0,CB=0,CA=0 */
  ATDCTL5 = 0x20U;                                      
  /* ### */
  /* Initial interrupt priority */
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  asm CLI;                             /* Enable interrupts */
  /*lint -restore Enable MISRA rule (1.1) checking. */
} /*MCU_init*/


void init_demo(void)
{
   /* Initialization for LED */ 
   DDRT = 0xF0; 
   /* Initialization for SW */
      /* Disable interrupts */
  /* PIE1AD: PIE1AD7=0,PIE1AD6=0,PIE1AD5=0,PIE1AD4=0,PIE1AD3=0,PIE1AD2=0,PIE1AD1=0,PIE1AD0=0 */
  PIE1AD = 0x00U;                                      
    /* Clear interrupt flags */
  /* PIF1AD: PIF1AD7=1,PIF1AD6=1,PIF1AD5=1,PIF1AD4=1,PIF1AD3=1,PIF1AD2=1,PIF1AD1=1,PIF1AD0=1 */
  PIF1AD = 0xFFU;                                      
  /* PPS1AD: PPS1AD7=0,PPS1AD6=0,PPS1AD5=0,PPS1AD4=0 */
  PPS1AD &= (unsigned char)~(unsigned char)0xF0U;                     
  /* PER1AD: PER1AD7=1,PER1AD6=1,PER1AD5=1,PER1AD4=1 */
//  PER1AD |= (unsigned char)0xF0U;                      
  /* DDR1AD: DDR1AD7=0,DDR1AD6=0,DDR1AD5=0,DDR1AD4=0 */
  DDR1AD &= (unsigned char)~(unsigned char)0xF0U;                     
  /* ### */
   
   
   PER1AD |= SW_MASK; /* Enable pull device */   
   PPS1AD &= (~SW_MASK); /* falling edge */ 
   DDR1AD &= (~SW_MASK); /* input */  
   PIE1AD |= SW_MASK   ;  /* enable interrupt*/   
   PIF1AD |= SW_MASK   ;  /* clear interrupt flag */   
}

void delay(int ms) {
  volatile int i , j;
  for (j = ms; j > 0; j--)
   for (i = 1000; i > 0; i--);
}


byte update_POT_value(void){
  unsigned char data_num ;
  word *ADC_REG_DAT_BASE_ADDR;
   
  do{
      // Wait for conversion to complete 
      if (ATDSTAT2 != 0x00)
         break;
  }while (ATDSTAT0_SCF == 1); 
  ATDSTAT0_SCF = 1;   
  data_num = ATDSTAT0 & 0x0F;
  ADC_REG_DAT_BASE_ADDR = &ATDDR0 + data_num ;         
  return ((byte)(*ADC_REG_DAT_BASE_ADDR & 0xFF));      
}

void update_LED_value(void){
   if ( (SW_flag & PTI1AD_PTI1AD4_MASK) == 0) /* if (SW1 is pressed)*/
   {  
       while ((PTI1AD & PTI1AD_PTI1AD4_MASK) == 0);
       while ((PTI1AD & PTI1AD_PTI1AD4_MASK) == 0);
       LED_value ^= SW1_MASK;       
   }
   
   if ((SW_flag & PTI1AD_PTI1AD5_MASK) == 0) /* if (SW2 is pressed)*/
   {  
       while ((PTI1AD & PTI1AD_PTI1AD5_MASK) == 0);
       while ((PTI1AD & PTI1AD_PTI1AD5_MASK) == 0);
       LED_value ^= SW2_MASK;       
   }
   
   if ((SW_flag & PTI1AD_PTI1AD6_MASK) == 0) /* if (SW3 is pressed)*/
   {  
       while ((PTI1AD & PTI1AD_PTI1AD6_MASK) == 0);
       while ((PTI1AD & PTI1AD_PTI1AD6_MASK) == 0);
       LED_value ^= SW3_MASK;       
   }
   
   if ((SW_flag & PTI1AD_PTI1AD7_MASK) == 0) /* if (SW4 is pressed)*/
   {  
       while ((PTI1AD & PTI1AD_PTI1AD7_MASK) == 0);
       while ((PTI1AD & PTI1AD_PTI1AD7_MASK) == 0);
       LED_value ^= SW4_MASK;       
   } 
   SW_flag = SW_MASK;
   PIE1AD |= SW_MASK   ;  /* enable interrupt*/   
   delay(5);
}