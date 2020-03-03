#include "QUIBs.h"
#include "CPMU.h"
#include "GECKOP.h"
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
/*
 * QUIBs.c
 *
 *  Created on: Oct 4, 2012
 *      Author: B35993
 */


void QUIBs_Init(){
    int i;
    unsigned char p_array[10];
	double fbus = 0.0;	
	double fd2d = 0.0;
	
	CPMUCOP    = 0x00;     // Disable MCU COP			watchdog
	CPMUINT    = 0x00;     // Disable MCU int			interrupts
	IVBR       = 0xFFFE;   // @ register base
	
	CPMU_InitBusCLK();					//Internal osc, 32 Mhz
	while(!CPMU_IsPLLlocked());						//Wait until the PLL is locked
	
	
	D2DCTL1  = 0x8F;  // D2DIE=1; TIMOUT[3:0] = 15 (max timeout)  
	D2DCTL0  = 0xC0;  // D2D Enable, 8Bit, !Stop in Wait, D2DCLK=BUS
	D2DSTAT0 = 0x80;  // Clear D2D Errors
	
	
	/* Gecko+ init */
	B_WD_CTL = 0x0700;   // Disable Analog Die Watchdog
	B_ACQ_SRH        = 0xFF;     // Clear the CVMI flags (current voltage measurement interrupt flag)
	
	/* Enable Wake-Ups */
	B_PCR_WUE_WULIN = 1;    // LIN Wakeup Enable
	CPMU_InitD2DCLK(1);
}

