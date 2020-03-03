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
* @file      demo_init.c
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Feb-23-2011 
*
* @brief     
*
******************************************************************************/

#include "demo_init.h"
#include <hidef.h>      /* common defines and macros */
#include "mc9s12xep100.h"     /* derivative information */
#include "lin.h"

const unsigned char flash_security  @0xFF0F = 0xFE;
unsigned char LED_display_col=9;
unsigned char LED_matrix_data[NUM_COLS];
unsigned char LED_sync_refresh;

const unsigned char hexnum_table[][5] = {
  0x3E, 0x45, 0x49, 0x51, 0x3E,       // 0
  0x00, 0x21, 0x7F, 0x01, 0x00,       // 1
  0x21, 0x43, 0x45, 0x49, 0x31,       // 2
  0x42, 0x41, 0x51, 0x69, 0x46,       // 3
  0x0C, 0x14, 0x24, 0x7F, 0x04,       // 4
  0x72, 0x51, 0x51, 0x51, 0x4E,       // 5
  0x1E, 0x29, 0x49, 0x49, 0x06,       // 6
  0x40, 0x47, 0x48, 0x50, 0x60,       // 7
  0x36, 0x49, 0x49, 0x49, 0x36,       // 8
  0x30, 0x49, 0x49, 0x4A, 0x3C,       // 9
  0x3F, 0x44, 0x44, 0x44, 0x3F,       // A
  0x7F, 0x49, 0x49, 0x49, 0x36,       // B
  0x3E, 0x41, 0x41, 0x41, 0x22,       // C
  0x7F, 0x41, 0x41, 0x22, 0x1C,       // D
  0x7F, 0x49, 0x49, 0x49, 0x41,       // E
  0x7F, 0x48, 0x48, 0x48, 0x40        // F
};

/////////////////////////////////////////////////////////////////////////////////////////
// PeriphInit
// --------------------------------------------------------------------------------------
// Initializes various registers and peripherals
/////////////////////////////////////////////////////////////////////////////////////////
void PeriphInit(void)
{
  // Configures PA[6..0] port as output  
  PORTA = 0x7F;                                                    
  DDRA = 0x7F;                        

  // Configures PB[3..0] as output and PB[7..4] as input
  PORTB = 0x00;                                   
  DDRB = 0x0F;                                    
    
  // Enables pull-ups on PB port
  PUCR |= 0x02;                                   

  // Configures PC[4..0] port as output
  PORTC = 0x00;                                   
  DDRC = 0x1F;                                    

  // Configures PD[4..0] port as output
  PORTD = 0x00;                                   
  DDRD = 0x1F;                                    

  // Configures the ATD peripheral
  // 8 bit data resolution
  ATD0CTL1 = 0x10; 
  // Left justified data, 2 conversion sequence and non-FIFO mode
  ATD0CTL3 = 0x13;
  // fBUS=2MHz, fATDCLK = 1 MHz (PRESCLAER = 0) Select 24 Sample Time
  ATD0CTL4 = 0xE0;
  EnableInterrupts;  
}


void init_timer_tim7(void)
{
  /* Initialize TIM timer */
  /* Timer functions normally */
  TIM_TSCR1 = 8;                
  /* Clock select bits: Div. by 64 clock enabled with pin low level */
  TIM_PACTL = 12;           
  /* Timer output compare */
  TIM_OC7M = 128;           
  /* Output Compare Select Timer 7 */
  TIM_TIOS = 128;           
  /* Define an output associated OC7 */
  TIM_TCTL1 = 192;          
  /* Enable toggle output compare pin */
  TIM_TTOV = 128;
  /* Enable Hardware interrupt request */
  TIM_TSCR2 = 136;          
  /* Enable Output Compare */
  TIM_TFLG1 = 255;              
  /* Enable tim7 */
  TIM_TIE = 128;
  /* Set timer period */
  TIM_TC7 = 1000;
  TIM_TSCR1 = 128;
}


/////////////////////////////////////////////////////////////////////////////////////////
// disp_hex_value
// --------------------------------------------------------------------------------------
// Outputs a 2-digit hex value on the displays 
/////////////////////////////////////////////////////////////////////////////////////////
void disp_hex_value(unsigned char value)
{
  unsigned char i;

  while(!LED_sync_refresh)
    ;
  for(i=0; i<5; i++){
    LED_matrix_data[i] = hexnum_table[value >> 4][i];
    LED_matrix_data[5 + i] = hexnum_table[value & 0x0F][i];
  }
  LED_sync_refresh = 0;
} 


extern volatile l_u8* slave_sig_data;  

unsigned char POT_data;
unsigned char* led_matrix_dat = &POT_data;

void slave_task(void)
{
	slave_sig_data = &POT_data;	
	for (;;)
	{       
		/* Send signal to master */
    ATD0CTL5 = 0x1A;     
    while(!(ATD0STAT0 & 0x80)); 
    
    POT_data = ATD0DR0H; 
    led_matrix_dat = &POT_data;                   
		
		l_u8_wr(LI1_RearLeftDoorSignal, *slave_sig_data);
		l_u8_wr(LI1_RearToMasterSignal, (l_u8)l_u8_rd(LI1_MasterToRear) );
    /* Display on Led matrix*/    
    disp_hex_value(*led_matrix_dat);       
	}
}


#pragma CODE_SEG __NEAR_SEG NON_BANKED

#define ISR(ivn,x) interrupt ivn void x(void)

ISR(VectorNumber_Vtimch7, TIM0_TIMER_ISR)
{
  PORTC = 0xFF;
  PORTD = 0xFF;
  PORTA = LED_matrix_data[NUM_COLS - LED_display_col - 1];

  if(LED_display_col < 5)
    PORTC = ~(0x01 << LED_display_col);
  else
    PORTD = ~(0x01 << (LED_display_col - 5));  
  if(++LED_display_col >= NUM_COLS){
    LED_display_col = 0;    
    LED_sync_refresh = 1;
  }
/* Clear timer flag*/  
  TIM_TFLG1_C7F = 1; 
}
#pragma CODE_SEG DEFAULT    
/**
* @}
*/

