#include "lin_demo.h"

void init_demo()
{
  // configure port data and direction  
  // PORT A  
  PT1AD  = 0x00;    
  DDR1AD   =0x00;
  PER1AD = 0xFF;
  ATDDIEN = 0xF0;     // enable PT1AD[7:4] as digital input

	PPSR 	= 0x00;			// Configure Pull-polarity  
	PERR 	= 0xFF;         // Enable Pull devices  
	PTR 	= 0x0F;						// PTR[7:4] low, PTR[3:0] high  
	DDRR 	= 0x0F;						// PTR[3:0] output
  
  LED1 = OFF;
  LED2 = OFF;
  LED3 = OFF;
  LED4 = OFF;
}

void init_atd_ch0(void){

	ATDCTL1 = 0x00;				// 8-bit results, select AN0
	ATDCTL3 = 0xA0;				//	right justify results, 4 conversions per sequence
	ATDCTL4 = 0x00;				// fATDCLK = 2.67MHz, 4 clks per sample
	ATDCTL5 = 0x20;				// continuous conversion
	ATDSTAT0_SCF = 0x01;			// clear conversion complete flag
}