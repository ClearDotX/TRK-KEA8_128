#include <hidef.h>      /* common defines and macros */
#include <MC9S12XEP100.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12xep100"

#include "lin.h"
#include "demo_init.h"


volatile l_u8* slave_sig_data;

void main(void) {
  l_u8 ret;
  l_u8 i;

  PeriphInit();
  init_timer_tim7();

  EnableInterrupts;
  
  ret = (l_u8) l_sys_init();
  ret = (l_u8) l_ifc_init(LI1);
  
  slave_sig_data = &i;
  *slave_sig_data = 0x55;
  
  for(;;) { 
     slave_task();
  }
}


