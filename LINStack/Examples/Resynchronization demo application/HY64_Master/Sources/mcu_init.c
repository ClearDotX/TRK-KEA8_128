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
* @file      mcu_init.c
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Dec-24-2009 
*
* @brief     initialization function for HY64 MCU
*
******************************************************************************/
#include "mcu_init.h"
//#include "HY64_master_state.h"
#include <hidef.h>					// common defines and macros
#include <mc9s12hy64.h>				// derivative information
#include "lcddrv.h"					// lcd driver functions
#include "lin_lin21tl_api.h"

void port_config(void){
  //***** CORE PORTS ******* 
  // core interrupts  
  	IRQCR = 0;		// IRQ only responds to falling edge   
  								//	- note IRQE is write once  								
    //include this line to clear the X-bit in order to enable the XIRQ function     
    //  asm ANDCC #~BIT6;	
  	RDRIV = ALL_REDUCED_DRIVE;	// drive level 					// core ports reduced drive  
  	PUCR 	= ALL_PULLS_ON; 		// Enable Pull devices 	// Note: only pull-ups available on core ports  
    // configure port data and direction    
    // PORT R
  	PPSR 	= ALL_PULLED_UP;			// Configure Pull-polarity  
  	PERR 	= ALL_PULLS_ON;         // Enable Pull devices  
    //	RDRR 	= ALL_REDUCED_DRIVE;    // drive level  
  	PTR 	= 0x0F;						// PTR[7:4] low, PTR[3:0] high  
  	DDRR 	= 0x0F;						// PTR[3:0] output  
    // PORT T  
    PPST 	= ALL_PULLED_DOWN;      // Configure Pull-polarity  
  	PERT 	= ALL_PULLS_ON;         // Enable Pull devices
  	RDRT 	= ALL_REDUCED_DRIVE;    // drive level  
  	PTT  	= ALL_LOW;              // port data  
  	DDRT 	= ALL_INPUTS;           // port direction  
  	
/**********************************************************
*	PORT AD SETUP
*
*	configure port as input w/ pull-ups enabled,  
*	key-wakeup enabled on PT1AD[7:4] for PBSW use
*  NOTE: to use the digital input function the ATDDIEN bit must be set  
*
*	NOTE: ATD port pull-ups are active for both digital and 
*	analog inputs !  
***********************************************************/
	PER1AD 	= ALL_PULLS_ON;		// Port AD Pull Enable  
//	RDR1AD 	= ALL_REDUCED_DRIVE;	// Port AD Reduced Drive Register
	PT1AD 	= ALL_LOW;				// Port AD I/O Register
	DDR1AD 	= ALL_INPUTS;			// Port AD Data Direction Register
	PIE1AD	= 0xF0;					// enable Port AD interrupts on PT1AD[7:4]
	PIF1AD	= 0xF0;					// clear spurious interrupts
	ATDDIEN	= 0xF0;					// enable PT1AD[7:4] as digital input

}


void TIM1_init(void) 
{
  /* Initialize TIM timer */
  /* Timer functions normally */
  TIM1_TSCR1 = 0x00;                
  /* Disable timer */
  TIM1_OCPD = 128;           
  /* Clock select bits: Div. by 64 clock enabled with pin low level */
  TIM1_PACTL = 12;           
  /* Timer output compare */
  TIM1_OC7M = 128;           
  /* Output Compare Select Timer 7 */
  TIM1_TIOS = 128;           
  /* Define an output associated OC7 */
  TIM1_TCTL1 = 192;          
  /* Enable toggle output compare pin */
  TIM1_TTOV = 128;
  /* Enable Hardware interrupt request */
  TIM1_TSCR2 = 0x8F; // f(timer) =  8M/128 = 0.0625M = 62.5Khz
  /* Enable Output Compare */
  TIM1_TFLG1 = 255;              
  /* Enable tim7 */
  TIM1_TIE = 128;
  /* Set timer period = 0.5s */
  TIM1_TC7 = 0x3F; // 0x0C35 ;
  TIM1_TSCR1 = 128;    
}

void clk_init(void){

	CPMUSYNR_SYNDIV = 0x03;		// pll feedback = vcoclk/8
	CPMUSYNR_VCOFRQ = 0x01;		// fvco set to 48 - 64MHz output
	CPMUPOSTDIV_POSTDIV = 0x03;	// core clk = fvco/4

	CPMUREFDIV_REFFRQ = 0x02;	// pll input set to 6 - 12 MHz
	CPMUREFDIV_REFDIV = 0x00;	// pll input is ext osc
	CPMUOSC_OSCE = 1;				// enable ext OSC
	while(!CPMUFLG_UPOSC || !CPMUFLG_LOCK);
    										// wait for ext osc to stabilize and pll to lock
	CPMUFLG = 0xFF;				// clear CMPMU int flags - not needed but good practice
}


extern volatile l_u8 LI0_FrontLeftDoorSignal_dat;
extern volatile l_u8 LI0_RearLeftDoorSignal_dat;
extern volatile l_u8 LI0_FrontToMasterSignal_dat;
extern volatile l_u8 LI0_RearToMasterSignal_dat;

void state_machine(void)
{
     LI0_FrontLeftDoorSignal_dat = l_u8_rd(LI0_FrontLeftDoorSignal);    
		 byte_disp(4,LI0_FrontLeftDoorSignal_dat);		  
		 LI0_RearLeftDoorSignal_dat = l_u8_rd(LI0_RearLeftDoorSignal);    		      
		 byte_disp(6,LI0_RearLeftDoorSignal_dat);		 
}


void byte_disp(l_u8 order, l_u8 data)	 
{
		l_u8 lower_byte, upper_byte;
		
		lower_byte = data & 0x0F;
	  upper_byte = (data >> 4) & 0x0F;	  
	  
		HEX_disp(order, upper_byte);	
		HEX_disp(order + 1, lower_byte);	
}

void dec_disp(l_u8 order, l_u16 data) {
    l_u8 i;
    l_u16 symbol = 0;
    l_u16 remain = data;
    l_u16 divisor = 10000;
    
    symbol = remain/divisor;
    remain -= (divisor * symbol);    
    HEX_disp(order,(l_u8)symbol);
    
    for(i=1; i<5; i++){
        divisor /= 10;      
        symbol = remain/divisor;
        remain -= (divisor*symbol);   
        order++;
        HEX_disp(order,(l_u8)symbol);
    } 
}

void HEX_disp(l_u8 order, l_u8 data)
{
	switch (order)
	{
	  	case 1:
	  			Set_Digit_1(data);
	  			break;
	  	case 2:
	  			Set_Digit_2(data);
	  			break;
	  	case 3:
	  			Set_Digit_3(data);
	  			break;		
			case 4:
	  			Set_Digit_4(data);
	  			break;	  			
			case 5:
	  			Set_Digit_5(data);
	  			break;	  				  			
			case 6:
	  			Set_Digit_6(data);
	  			break;	  				  			
			case 7:
	  			Set_Digit_7(data);
	  			break;	  				  			
	  	case 8:
	  			Set_Digit_8(data);
	  			break;
	  	case 9:
	  			Set_Digit_9(data);
	  			break;
	  	case 10:
	  			Set_Digit_10(data);
	  			break;		
			case 11:
	  			Set_Digit_11(data);
	  			break;	  			
			case 12:
	  			Set_Digit_12(data);
	  			break;	  				  			
	  	case 13:
	  			Set_Digit_13(data);
	  			break;	  				  					
			default:
	  			break;	  				  			
	}		
} 


void delay(unsigned int ms){
    volatile unsigned int i, j;
    for (i=0; i<ms; i++){
        for(j=0; j<1000; j++);
    }
}
/**
* @}
*/
