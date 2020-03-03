#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "lin.h"
#include "lin_demo.h"

l_u8 potential_value;
void main(void) 
{   
  /* include your code here */

  l_u8 led_control;
  
  SOPT1 = 0x52;
  SPMSC1 = 0x1C;
  SPMSC2 = 0x00;
  ICSTRM = *(unsigned char*)0xFFAF;    /* Initialize ICSTRM register from a non volatile memory */
  ICSSC = *(unsigned char*)0xFFAE;     /* Initialize ICSSC register from a non volatile memory */
  ICSC1 = 0x06;
  ICSC2 = 0x00;

  PTAPE = 0x0C;
  PTASE &= ~0x1F;
  PTADS |= 0x1F;
  
  init_demo();
  init_adc();
  
  (void)l_ifc_init(LI0);
  EnableInterrupts; /* enable interrupts */

  for(;;) {
    if (l_flg_tst(LI0_LedControl_flag)){
      l_flg_clr(LI0_LedControl_flag);
      led_control = l_u8_rd(LI0_SlaveIdentifier);
      LED1 = led_control & 0x01;
    }
    if (l_flg_tst(LI0_ResetFrame_flag)){
      l_flg_clr(LI0_ResetFrame_flag);
      LED1 = OFF;
    }
    potential_value = (ADCRH << 8) | ADCRL;
    l_u8_wr(LI0_Cluster2PotentiometerB, potential_value);
    
  }
}
