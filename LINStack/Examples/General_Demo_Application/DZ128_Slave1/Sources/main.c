#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "lin.h"
#include "lin_demo.h"

void cpu_init(void) { 
  /* Clears COP Watchdog timeout*/
  SOPT1 = 0x00;  
  
  /* Selects FEE MCG mode (IREFS=0, CLKS=00, RDIV=11) */
  MCGC1 = 0x38;
  /* BDIV=01 LP=0 and selects external high frequency crystal clock */ 		                
  MCGC2 = 0x76;
  /* PLLS=0  */
  MCGC3 = 0x00;
  /* Waits until the initialization cycle of the external crystal clock is completed */
  while(!(MCGSC&0x02)) ;
  
  /* Attention!!!: Bus frequence = 8MHz */
      
  /* Sets TJA1020 LIN transceiver in normal mode operation (NSLP HIGH) */
  /* PTE4 -> NSLP */
  PTED = 0x10;
  PTEDD = 0x10;   
}


l_u16 potential_value;
void main(void) {
  l_u8 ret, led_control;
  l_u16 LIN_word_status;
  
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
    l_u8_wr(LI0_Cluster1Potentiometer1, (l_u8)potential_value);
    
    /* Check if the goto sleep command sent by master node */
    LIN_word_status = l_ifc_read_status(LI0);
    /* The word status is presented below 
      --------------------Word status------------------------------
      |15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
               |             | | | | | | | |-- Error in response 
               |             | | | | | | |---- Successful tranfer
               |             | | | | | |------ Overun 
               |             | | | | |-------- Goto sleep
               |             | | | |---------- Bus activity   
               |             | | |------------ Event trigger collision   
               |             | |-------------- Save configuration   
               |             |---------------- 0
               |------------------------------ Las frame PID   */ 
    /* Check if any update from LIN word status*/
    if(LIN_word_status != 0){
     /* Check if the LIN bus in the sleep mode */ 
      if((LIN_word_status>>3)&0x01){
        LED3 = ON;
        /* Press PTA4 to wakeup LIN node */
        if (!PTAD_PTAD4){    
        /* Call wakeup function */
        l_ifc_wake_up(LI0);  
       }
      }else{
        LED3 = OFF;
      }
    }
      
  } /* loop forever */
  /* please make sure that you never leave main */
}