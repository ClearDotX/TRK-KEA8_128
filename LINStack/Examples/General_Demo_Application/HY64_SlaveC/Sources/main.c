#include <hidef.h>      /* common defines and macros */
#include <mc9s12hy64.h>     /* derivative information */

#include "lin.h"
#include "lin_demo.h"

void cpu_init(void){

	CPMUSYNR_SYNDIV = 0x03;		// pll feedback = vcoclk/8
	CPMUSYNR_VCOFRQ = 0x01;		// fvco set to 48 - 64MHz output
	CPMUPOSTDIV_POSTDIV = 0x03;	// core clk = fvco/4

	CPMUREFDIV_REFFRQ = 0x02;	// pll input set to 6 - 12 MHz
	CPMUREFDIV_REFDIV = 0x00;	// pll input is ext osc
	CPMUOSC_OSCE = 1;				// enable ext OSC
	while(!CPMUFLG_UPOSC || !CPMUFLG_LOCK);
										// wait for ext osc to stabilize and pll to lock
	CPMUFLG = 0xFF;				// clear CMPMU int flags - not needed but good practice
}

l_u8 potential;
void main(void) {
          
  /* put your own code here */
  l_u8 ret,led_control;
  EnableInterrupts;
  cpu_init();
 
  init_demo();
  init_atd_ch0();
  
  ret = l_sys_init();
  ret = l_ifc_init(LI0);

  
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
    potential = ATDDR0L;
    l_u8_wr(LI0_Cluster2PotentiometerC, potential);
  } /* wait forever */
  /* please make sure that you never leave this function */
}
