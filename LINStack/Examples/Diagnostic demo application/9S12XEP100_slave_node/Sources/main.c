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
* @brief     Demo application for RearLeftDoor Node
*
******************************************************************************/

#include <hidef.h>      /* common defines and macros */
#include <MC9S12XEP100.h>     /* derivative information */
#include "periphral_init.h"
#pragma LINK_INFO DERIVATIVE "mc9s12xep100"

#include "periphral_init.h"
#include "lin.h"
#include "diagnostic_service_slave.h"

volatile l_u8* slave_sig_data;

void main(void) 
{
  l_u8 ret;
  l_u8 i;        
  /* put your own code here */  
  //CPU_init();  
  PeriphInit();
  init_timer_tim7();
  EnableInterrupts; /* enable interrupts */ 
   
  ret = (l_u8)l_sys_init();
  ret = (l_u8)l_ifc_init(LI1);
  ld_init();
  slave_sig_data = &i;
  *slave_sig_data = 0x55;
  for (;;)  {    
     slave_task();    
  }
}

/**
* @}
*/
