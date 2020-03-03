#include "CPMU.h"
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CPMU_INTERNAL_OSC 'i'
#define CPMU_EXTERNAL_OSC 'e'

#define CPMU_IRC_FREQ	1000000

//register setting
#define CPMU_D2DCTL0_INIT	0xC0	//D2DEN = 1 / D2DCW = 1 / D2DSWAI = 1
#define CPMU_D2DCTL1_INIT	0x8F;	//D2DIE = interrupts enabled / TIMOUT = maximal timeout



unsigned char CPMU_IsPLLlocked(){
	return (CPMUIFLG & 0x08);		//returns 0 if NOT locked and 1 if PLL locked
}

//Function uses PLL as a clock source by default 

void CPMU_InitBusCLK(){
	
		CPMUOSC = 0x00;		//Set internal oscillator -> OSCE=0		
		CPMUSYNR = 0x40 | 0x1F;		// set 32 MHz
		CPMUPOSTDIV = 0;			
}

void CPMU_InitD2DCLK(unsigned char divisionFac){
	
	switch(divisionFac){ 
		case 1 : D2DCTL0 = CPMU_D2DCTL0_INIT; break;			//fd2d = fbus
		case 2 : D2DCTL0 = CPMU_D2DCTL0_INIT | 0x01; break;		//fd2d = fbus/2
		case 3 : D2DCTL0 = CPMU_D2DCTL0_INIT | 0x02; break;		//fd2d = fbus/3
		default: D2DCTL0 = CPMU_D2DCTL0_INIT | 0x03; break;		//fd2d = fbus/4
	}

	D2DCTL1 = CPMU_D2DCTL1_INIT;	//enable interrupts & set maximal timeout
	D2DSTAT0 = 0x80;				//clear D2D errors	
	
	
}









