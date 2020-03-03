#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */


#include "MC9S08EL32.h"
#include "lin.h"
#include "lin_demo.h"

l_u16 potential_value;

void main(void) 
{
  l_u8 led_control = 0;
  
  
  EnableInterrupts; /* enable interrupts */
  /* include your code here */
  SOPT1 = 0x20;
  /* Enable LVD */
  SPMSC1 = 0x34;
  
  ICSTRM = *(unsigned char*)0xFFAF;
  ICSSC = *(unsigned char*)0xFFAE;
  ICSC1 = 0x06;
  ICSC2_BDIV  = 0;

  (void)l_sys_init();
  (void)l_ifc_init(LI0);

  init_demo();
  adc_init(); 

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
    l_u8_wr(LI0_Cluster1Potentiometer2, (l_u8)potential_value);
  } /* loop forever */
}


