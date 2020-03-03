#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "lin.h"
#include "lin_demo.h"

#define CLUSTER1_ACTIVE_REQUEST           0
#define CLUSTER2_ACTIVE_REQUEST           1
#define CLUSTER1_CLUSTER2_ACTIVE_REQUEST  2
#define CLUSTER1_CLUSTER2_DISABLE         3

void press_delay()
{
  l_u16 i,j;
  for(i = 0; i<20000;i++){
    for(j = 0;j<10;j++);
  }
}

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


l_u8 pids[4]={0x01,0x02,0x03,0x04};
l_u8 data_id[5];
l_u8 counter = 0;

void main(void) {
  l_u8 ret;
  l_u8 data[4] = {0xAA, 0xAA, 0xAA, 0xAA};
  
  
  EnableInterrupts; /* enable interrupts */
  /* include your code here */

  cpu_init();
  rtc_int();
  
  PTADD = 0x00;
  PTAPE = 0xF0;
  /* Lin Application */
  /* Master function */
  
  ret = (l_u8)l_sys_init();
  ret = (l_u8)l_ifc_init(LI0);
  
  l_sch_set(LI0, LI0_NormalTable, 0); // For test Sporadic frame

 
  for(;;) {
    if (!PTAD_PTAD4) {   /* Press PTA4 */
      press_delay();
      l_u8_wr(LI0_ClusterIdentifier, CLUSTER1_ACTIVE_REQUEST);
    }
    if (!PTAD_PTAD5) {   /* Press PTA4 */
      press_delay();
      l_u8_wr(LI0_ClusterIdentifier, CLUSTER2_ACTIVE_REQUEST);
    }
    if (!PTAD_PTAD6) {   /* Press PTA4 */
      press_delay();
      l_u8_wr(LI0_ClusterIdentifier, CLUSTER1_CLUSTER2_ACTIVE_REQUEST);
    }
    if (!PTAD_PTAD7) {   /* Press PTA4 */
      press_delay();
      l_u8_wr(LI0_ClusterIdentifier, CLUSTER1_CLUSTER2_DISABLE);
    }    
  /* please make sure that you never leave main */
  }
}

