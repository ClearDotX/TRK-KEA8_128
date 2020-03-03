#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "MCU_init.h"
#include "SCI_driver.h"
#include "lin.h"
#include "diagnostic_service_slave.h"

byte LED_value = 0xFF;
extern unsigned char io_control_status;
l_u8 POT_current_value = 0x00;
l_u8 POT_previous_value = 0xFF;

//volatile l_signal_handle slave_signal_handle = LI0_FrontLeftDoorSignal;
volatile l_u8* slave_sig_data = &POT_current_value;

byte SW_flag = SW_MASK;
void main(void) {
  l_u8 ret;
   
  /* Clock & common registers initialization */
  MCU_init();
  /* SCI configuration */
  SCI_config();  
  /* Enable Interrupt */
  ret = (l_u8)l_sys_init();
  ret = (l_u8)l_ifc_init(LI0);  
  ld_init();
  
  EnableInterrupts;
  for(;;) {
    _FEED_COP(); /* feeds the dog */                
    /* Update LED_value */
    if (SW_flag != SW_MASK){
      update_LED_value();
      io_control_status =(((byte)~LED_value) >> 4)&0x0F;
    }
    PTT = LED_value;                                  
    /* Check diagnostic service */    
    POT_current_value = update_POT_value();
    if (POT_current_value != POT_previous_value){          
        SCI_send(POT_current_value);
        POT_previous_value = POT_current_value;        
    } 
    /* Check diagnostic service*/    
    slave_task();  
  } /* loop forever */
  /* please make sure that you never leave main */
}

#ifndef ISR
  #define ISR(ivn, x) interrupt ivn void x(void)
#endif
#pragma CODE_SEG NON_BANKED

ISR(VectorNumber_Vportad, PORTAD_INT) 
{
   /* Capture interrupt flag */
   SW_flag = PTI1AD  ; 
   /* Clear interrupt flag */
   PIF1AD |= SW_MASK   ;  
   /* Disable SW interrupt */ 
   PIE1AD &= ~SW_MASK   ;  
}

#pragma CODE_SEG DEFAULT
