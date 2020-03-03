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
* @file      main.c
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Jan-21-2011 
*
* @brief     Display the POT & IO status on LCD & LED
*
******************************************************************************/

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "LL64_init.h"
#include "LCD_GD5360P.h"

void main(void) {
  unsigned char POT_value;
  /* Clock & common register initialization */
  cpu_init();
  SCI2_init();  
  /* LCD Initialization */
  vfnLCD_Init();
  vfnLCD_All_Segments_OFF();     
  /* enable interrupts */
  EnableInterrupts;   
  SetNumber(2, 0x11);  
  for(;;) {
    /* feeds the dog */
    __RESET_WATCHDOG();
    /* Check SCI receiver flag*/ 
    if (SCI2S1 & SCI2S1_RDRF_MASK) {       
        (void)(SCI2S1 == 0x00);	
        POT_value =  SCI2D;
        /* Update POT value from G128 board */
        SetNumber(4, POT_value);
    }   
  } /* loop forever */
  /* please make sure that you never leave main */
}
