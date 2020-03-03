#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "lin.h"
#include "lin_demo.h"

l_u8 potential_value;



void main(void) {
  l_u8 ret;
    
  cpu_init();  
  adc_init();
  init_demo();
  EnableInterrupts; /* enable interrupts */
  
  /* Lin Application */
  /* Slave function */
  ret = (l_u8)l_sys_init();
  ret = (l_u8)l_ifc_init(LI0);
 
  for(;;) { 
    if((ADCSC1 & ADCSC1_COCO_MASK) == ADCSC1_COCO_MASK){    
       potential_value = (l_u8)ADCRL;
       l_u8_wr(LI0_FrontLeftDoorSignal, (l_u8)potential_value);         
       PTDD = ~potential_value;                       
    } 
    
    //updated signal
    ret = (l_u8)l_u8_rd(LI0_MasterToFront);
    l_u8_wr(LI0_FrontToMasterSignal, ret );  
  }
}