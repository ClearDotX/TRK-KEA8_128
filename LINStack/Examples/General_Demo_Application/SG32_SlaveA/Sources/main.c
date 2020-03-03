#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <MC9S08SG32.h>

#include "lin.h"
#include "lin_demo.h"

void cpu_init(void) {
  /* Clears COP Watchdog timeout*/
  SOPT1 = 0x00;
  
  /* set the bus clock to 16M, FEI mode */
  ICSC1_CLKS  = 0;
  ICSC1_IREFS = 1;
  ICSC1_RDIV  = 0;
  ICSC2_BDIV  = 0;
  ICSTRM      = 0x96;
}

l_u16 potential_value;
void main(void) {
  l_u8 ret, led_control;
  
  EnableInterrupts; /* enable interrupts */
  /* include your code here */

  cpu_init();
  adc_init();
  init_demo();
  /* Lin Application */
  /* Slave function */
  ret = (l_u8)l_sys_init();
  ret = (l_u8)l_ifc_init(LI0);
 
  for(;;) {
    if (l_flg_tst(LI0_LedControl_flag)){
      l_flg_clr(LI0_LedControl_flag);
      led_control = l_u8_rd(LI0_SlaveIdentifier);
      switch(led_control){
        case 0:
          LED1 = ON;
          LED2 = ON;
          break;
        case 1:
          LED1 = OFF;
          LED2 = ON;
          break;
        case 2:
          LED1 = ON;
          LED2 = OFF;
          break;
        case 3:
          LED1 = OFF;
          LED2 = OFF;
          break;
        default:
          break;
      }
    }
    if (l_flg_tst(LI0_ResetFrame_flag)){
      l_flg_clr(LI0_ResetFrame_flag);
      LED1 = OFF;
      LED2 = OFF;
    }
    potential_value = (ADCRH << 8) | ADCRL;
    l_u8_wr(LI0_Cluster2PotentiometerA, (l_u8)potential_value);
  } /* loop forever */
  /* please make sure that you never leave main */
}
