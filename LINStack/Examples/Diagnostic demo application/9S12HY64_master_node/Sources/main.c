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
* @date      Dec-24-2009 
*
* @brief     Demo application for classIII
*
******************************************************************************/

#include <hidef.h>      /* common defines and macros */
#include <mc9s12hy64.h>     /* derivative information */
#include "mcu_init.h"
#include "HY64_master_state.h"
#include "diagnostic_service_slave.h"
#include "lcddrv.h"  
//#include "lin.h"

/* ---------------- Start main ---------------- */
volatile l_u8 state = 0x00;
volatile l_u8 receiv_response_flag = 0x00;
volatile l_u8 LI0_FrontLeftDoorSignal_dat = 0x00;
volatile l_u8 LI0_RearLeftDoorSignal_dat =  0x00;
volatile l_u8 io_control_status = _DOOR_STATUS; /*Led indicator*/
volatile l_u8 slave_resp_dat[MAX_LENGTH_DIAG_SERVICE];
volatile l_u16 slave_resp_length;

volatile l_u8 master_req_dat[MAX_LENGTH_DIAG_SERVICE];
volatile l_u16 master_req_length;

volatile l_u8 NAD;


volatile unsigned long serial_number = _SERIAL_NUMBER; 

void main(void) {
  l_u8 ret;
/* Initialization */    
  clk_init();
  port_config();
  TIM1_init();
  init_atd_ch0();
  LCD_Init();		  
  
  ret = l_sys_init();
  ret = l_ifc_init(LI0);
  
  l_sch_set(LI0, LI0_NormalTable , 0);
  ld_init(LI0);  
  EnableInterrupts;
  
/* state display */  
  for (;;) 
  {
    state_machine();
  }  
}


#define ISR(ivn, x) interrupt ivn void x(void)

#pragma CODE_SEG __NEAR_SEG NON_BANKED /* Define a specific segment to store the code */
ISR(VectorNumber_Vatd, ATD_READ_POT) {
  io_control_status = read_atd_ch0();
  ATDSTAT0_SCF = 1; 
}

ISR(VectorNumber_Vtim1ch7, TIM1CH7_TIMER_ISR) {
  l_u8 ret;
  ret = l_sch_tick(LI0);
  TIM1_TFLG1 = 128;                     /* Reset interrupt request flag */
}
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG __NEAR_SEG NON_BANKED /* Define a specific segment to store the code */ 
interrupt VectorNumber_Vportad void kbi_isr(void)
{
  kbi_isr_func();
}
#pragma CODE_SEG __NEAR_SEG DEFAULT /* Define a specific segment to store the code */ 

void kbi_isr_func(void){
	byte int_flag = 0;
	byte st = 0, n = 0;
	
	//DisableInterrupts;
	PIE1AD = 0x00;
	
	int_flag = (PIF1AD >> 4);		// capture interrupt status and shift to low nibble
	PIF1AD = 0xF0;						// clear PBSW interrutps

	while(st<0x08){
		if(SW1 && SW2 && SW3 && SW4){ 
			st ++;						// incr count if all PBSW's high
		} else st = 0;
	}
  	
	//EnableInterrupts;
	PIE1AD = 0xF0;
	
	if(int_flag & 0x01) st = 1;	// SW1 pressed
	if(int_flag & 0x02) st = 2;	// SW2 pressed 
	if(int_flag & 0x04) st = 3;	// SW3 pressed
	if(int_flag & 0x08) st = 4;	// SW4 pressed 
	  
	switch(st)
	{
		case 1:	/* state = normal state */
					state = NORMALL_STATE;
					TRIPA = OFF;
					TRIPB = OFF;	
					break;

		case 2: /* Diagnostic class II */	
		      TRIPB = ON;
		      TRIPA = OFF;
					if ( ( (state & DIAG_CLASSII_STATE_MASK) == DIAG_CLASSII_STATE_MASK) && 
					     (state < SERIAL_NUMBER_WRITE_SEND_REQ) )
					{
					   if (state & DIAG_REQ_SEND_STATE_MASK) 
					   {
					     state = state + 1;
					   } 
					   else
					   {
					     state = state + 2;
					   }						      						      
					}						
					else
					{	
					    state = SERIAL_NUMBER_READ_SEND_REQ;
					}	
					break;
		case 3:	/* Diagnostic class III */
		      TRIPA = ON;
		      TRIPB = OFF;
		      if ( ( (state & DIAG_CLASSIII_STATE_MASK) == DIAG_CLASSIII_STATE_MASK) &&
		           (state < FAULT_MEMORY_CLEAR_REQ) ) 
					{
					   if (state & DIAG_REQ_SEND_STATE_MASK) 
					   {
					     state = state + 1;
					   } 
					   else
					   {
					     state = state + 2;
					   }						      						      
					}						
					else
					{	
					   state = IO_CONTROL_READ_REQ;
					}					
					break;					
		case 4:											
					if ( 
					        (!(state & DIAG_REQ_SEND_STATE_MASK) )  
					   ) 
					{
					  /* Check diagnostic service status is idle - linhnv1 */
					  if(ld_is_ready(LI0) == LD_SERVICE_IDLE){
					    state = state + 1;					
					  }
					}					  					      				
					break;
	}
	
}

#pragma CODE_SEG __NEAR_SEG DEFAULT /* Define a specific segment to store the code */ 

/**
* @}
*/