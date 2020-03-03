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
#include "sci_v5.h"
#include "lcddrv.h"  
#include "lin.h"
#include "lin_lld_sci.h"

extern lin_node lin_node_descrs[NUM_OF_SCI_CHANNEL];
/* ---------------- Start main ---------------- */
#define FLAG_DISABLE 0x00
#define FLAG_ENABLE 0x01

volatile l_u8 state = 0x00;
volatile l_u8 LI0_FrontLeftDoorSignal_dat = 0x00;
volatile l_u8 LI0_RearLeftDoorSignal_dat =  0x00;

volatile l_u8 LI0_FrontToMasterSignal_dat = 0x00;
volatile l_u8 LI0_RearToMasterSignal_dat = 0x00;

volatile unsigned int baudrate = 9600 ; 

volatile unsigned char baudrate_flag = 0x00;
volatile unsigned char KBI_flag = 0x00;


void mySciInit(l_u16 newbaudrate){
  l_u16 tmp;
  lin_node *lnode_p; 
  tSCI* _pSCI;
  lin_configuration *lconf_p;
  
  lnode_p = (lin_node *)&lin_node_descrs[0];
  _pSCI = lnode_p->pSCI;
  lconf_p = (lin_configuration *)&lin_ifc_configuration[LI0];
  
  /* Config */
  lnode_p->ifc=(l_u8)LI0;
  lnode_p->response_buffer=lconf_p->response_buffer;
  /* Set SCI is Master or Slave */
  lnode_p->func=(l_bool)lconf_p->function;
  lnode_p->tbit=(l_u16)(1000000/newbaudrate);
  
  /* Initialize SCI */
  /* Set baud rate */
  _pSCI->scisr2.byte = 0x00;
  tmp = (l_u16)(MCU_BUS_FREQ/newbaudrate/16); 
  _pSCI->scibdh.byte	= (l_u8)(tmp>>8);
	_pSCI->scibdl.byte	= tmp&0xff;

  /* Disable SCI in wait mode and enable bit count after stop bit */
  _pSCI->scicr1.byte = (SCICR1_ILT_MASK | SCICR1_SCISWAI_MASK);
  /* Enable use of 13bit breaks and SCI frame for LIN */
  _pSCI->scisr2.byte  = (SCISR2_AMAP_MASK | SCISR2_BRK13_MASK);
  /* Enable mismatch error detection */
  _pSCI->sciasr1.byte = SCIASR1_BERRIF_MASK;
  /* Enable bit error interrupt and break detect flags */
  _pSCI->sciacr1.byte = (SCIACR1_BERRIE_MASK | SCIACR1_BKDIE_MASK);
  /* Enable break detect circuit and timing bit error detection at 9th time stick */ 
  _pSCI->sciacr2.byte = (SCIACR2_BERRM0_MASK | SCIACR2_BKDFE_MASK);
  /* Enable tranceiver interrupt */
  _pSCI->scicr2.byte = (SCICR2_TE_MASK | SCICR2_RE_MASK | SCICR2_RIE_MASK);
    
  /* Enter IDLE state */
  lin_goto_idle_state(0); 
}
void main(void) {
  l_u8 ret;
  l_u8 tst_dat = 0x01;
  
/* Initialization */    
  clk_init();
  port_config();
  TIM1_init();  
  LCD_Init();		  
  
  ret = l_sys_init();
  ret = l_ifc_init(LI0);
    
  l_sch_set(LI0, LI0_NormalTable , 0);
  
  EnableInterrupts;
  
/* state display */  
  for (;;) 
  {
    state_machine();     
    dec_disp(8, baudrate);
    l_u8_wr(LI0_MasterToFront,tst_dat);
    l_u8_wr(LI0_MasterToRear,tst_dat);
    
    LI0_FrontToMasterSignal_dat = l_u8_rd(LI0_FrontToMasterSignal);
    LI0_RearToMasterSignal_dat  = l_u8_rd(LI0_RearToMasterSignal);
    
    if (LI0_FrontToMasterSignal_dat != tst_dat){
        LED1 = 0;
        LED2 = 0;
    } else {
        LED1 = 1; // OFF
        LED2 = 1;    
    }
    
    if (LI0_RearToMasterSignal_dat != tst_dat){
        LED3 = 0;
        LED4 = 0;
    } else {
        LED3 = 1; // OFF
        LED4 = 1;    
    }
    
    


    if(KBI_flag == FLAG_ENABLE){
    
      while(!SW1){ // SW1 pressed
        baudrate++;
        dec_disp(8, baudrate);
        delay(6);
      }
	    while(!SW2){   // SW2 pressed 
	      baudrate--;
	      dec_disp(8, baudrate);
	      delay(6);
	    }
	  
	    /* Clear KBI_flag*/
	    KBI_flag = FLAG_DISABLE;
	  
      /* Enable KBI interrupt*/
	    PIE1AD	= 0xF0;					// enable Port AD interrupts on PT1AD[7:4]
 	
    }
	
    if (baudrate_flag == FLAG_ENABLE){
        /* Init SCI baudrate */
        DisableInterrupts;  
        lin_lld_sci_deinit(0);      
        mySciInit(baudrate);        
        delay(100);
        l_sch_set(LI0, LI0_NormalTable , 0);
        EnableInterrupts;

        /*Clear baudrate_flag */        
        baudrate_flag = FLAG_DISABLE;
        
        if (tst_dat != 0xFF){
            tst_dat ++ ;
        } else {
            tst_dat = 0x01;
        }
                
    }  
  } 
   
}


#define ISR(ivn, x) interrupt ivn void x(void)

#pragma CODE_SEG __NEAR_SEG NON_BANKED /* Define a specific segment to store the code */

ISR(VectorNumber_Vtim1ch7, TIM1CH7_TIMER_ISR) {
  (void)l_sch_tick(LI0);
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
  /*Disable KBI interrupt*/
	PIE1AD	= 0x00;					// disable Port AD interrupts on PT1AD[7:4]
  /* Clear KBI interrupt flag */
	PIF1AD	= 0xF0;					// clear spurious interrupts
	/*Enable  KBI_flag*/
	KBI_flag = FLAG_ENABLE;
	
	
  /* Enable baudrate_flag*/
  baudrate_flag = FLAG_ENABLE;
	
}

#pragma CODE_SEG __NEAR_SEG DEFAULT /* Define a specific segment to store the code */ 

/**
* @}
*/