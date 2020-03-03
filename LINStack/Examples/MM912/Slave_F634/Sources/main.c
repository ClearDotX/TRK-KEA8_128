#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "analog_die_reg.h"
#include "lin_lld_sci.h"
#include "lin.h"


#define SW1   0
#define SW2   0
void system_init(void)
  {
    while(!CRGFLG_LOCKST){  }; // wait until FLL locked
    DDRA_DDRA1 = 1; // for debug only
    DDRA_DDRA0 = 1; // for debug only
    
    EnableInterrupts;
    // setting up the D2D interface

    D2DCTL1 = 0x8F;    // 0b1111 timeouts can be inserted by target, ext interrupt enabled
    
    D2DCTL0_D2DEN = 1; // enable D2D (needed to be enabled after wrote all settings  before !!!)
    LINR = 4;  // enable LIN module
      
  }/*--------------------------------------------------------*/
#if _TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_
ld_init();
#endif

void main(void) {
  /* put your own code here */
 l_u16 i; 
 l_u16 LIN_word_status;
 l_u8 j, ret;

  system_init();
  ret = l_sys_init();
	ret = l_ifc_init(LI0);


  for(;;) {
    _FEED_COP(); /* feeds the dog */
        /* Test wake-up */
        /* Send a cluster of wakeup signal */
    if(SW2) {
      LIN_word_status = l_ifc_read_status(LI0);
      /* Check if LIN in the sleep mode then wakeup */
      if((LIN_word_status>>3)&0x01)    {
          for(i = 0; i < 60000; i++)
            for (j = 0; j < 20; j++);
          l_ifc_wake_up(LI0);
          for(i = 0; i < 50000; i++)
            for (j = 0; j < 20; j++);
          l_ifc_wake_up(LI0);
          for(i = 0; i < 50000; i++)  // diagnostics class 1       
            for (j = 0; j < 20; j++);
          l_ifc_wake_up(LI0);
      }
     }
      /* Test goto sleep */
    
    #if _TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_
    if(diag_get_flag(DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER)){
      l_u16 req_len = 0;
      l_u8 req_data[10];
      diag_clear_flag(DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER);
      /* process data */
      ld_receive_message(&req_len, req_data);
      req_data[0] += 0x40;
      /* send response */
      ld_send_message(10, req_data);
    }
    #endif 
  } /* loop forever */
  /* please make sure that you never leave main */
}