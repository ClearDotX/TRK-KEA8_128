#include <hidef.h>      /* common defines and macros */
/* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12xep100"
#include <MC9S12XEP100.h>


#include "lin.h"
#include "lin_demo.h"
#include "led_matrix.h"
#include "stdio.h"

#define GOTO_SLEEP_DURATION   10
#define WAKEUP_DURATION       21

#define CLUSTER1_ACTIVE_REQUEST           0
#define CLUSTER2_ACTIVE_REQUEST           1
#define CLUSTER1_CLUSTER2_ACTIVE_REQUEST  2
#define CLUSTER1_CLUSTER2_DISABLE         3

extern l_u8 count;

/* Main entrt of application */
void main(void) {
  l_u8 ret,mode, led_control1 = 0, control1 = 0, control2 = 0, control3 = 0, control4 = 0, led_control2 = 0;
  l_u8 slave1info, sw4 = 0;
  l_u16 i,j, counter = 0;
  l_u8 data[4] = {0xAA, 0xAA, 0xAA, 0xAA};
  l_u16 LIN1_word_status=0, LIN2_word_status=0;
  
  /* put your own code here */
  EnableInterrupts;
  
  /* Main bus freq = 40Mhz, Please select Fosc = 4Mhz (OSC_SEL = Crytal) */
  init_sci6();
  init_demo();
  free_counter_init();
  tim_init();
  
  /* Lin application here */
  /* Lin Master */
  ret = l_sys_init();
  ret = l_ifc_init(LI0);
  ret = l_ifc_init(LI1);
  ret = l_ifc_init(LI2);
  l_sch_set(LI1, LI1_LIN_NULL_SCHEDULE, 0);
  l_sch_set(LI2, LI2_LIN_NULL_SCHEDULE, 0);
  (void)printf("LIN is starting ...\n");
  
  for(;;){
      /* check signal form Master node */
      if (l_flg_tst(LI0_ClusterIdentifier_flag)){
        l_flg_clr(LI0_ClusterIdentifier_flag);
        mode = l_u8_rd(LI0_ClusterIdentifier);
        /* Set mode for 2 cluster */
        switch(mode){
          /* Only Cluster1 Active */
          case CLUSTER1_ACTIVE_REQUEST:
            if(0 == control1){
              control2 = 0;
              l_sch_set(LI1, LI1_NormalTable, 0); 
              l_sch_set(LI2, LI2_LIN_NULL_SCHEDULE, 0);
              (void)printf("Master node requested only cluster 1 active\n");
            } else{
              l_u8_wr(LI1_SlaveIdentifier, (l_u8)((control1-1)%4));
              (void)printf("Control LED of Cluster1 from Master node\n");
            }
            control1++;
            LED1 = ON;
            LED2 = OFF;
            break;
          /* Only Cluster2 Active */
          case CLUSTER2_ACTIVE_REQUEST:
            if (0 == control2){
              (void)printf("Master node requested only cluster 2 active\n");
              l_sch_set(LI1, LI1_LIN_NULL_SCHEDULE, 0);
              l_sch_set(LI2, LI2_NormalTable, 0);
              control1 = 0;
            } else {
              l_u8_wr(LI2_SlaveIdentifier, (l_u8)((control2-1)%4));
              (void)printf("Control LED of Cluster2 from Master node\n");
            }
            control2++;
            LED1 = OFF;
            LED2 = ON;
            break;
          /* Both Cluster1 and Cluster2 active */
          case CLUSTER1_CLUSTER2_ACTIVE_REQUEST: 
            l_sch_set(LI1, LI1_NormalTable, 0);
            l_sch_set(LI2, LI2_NormalTable, 0);
            (void)printf("Master node requested cluster1 and cluster2 active\n");
            control1++;
            control2++;
            LED1 = ON;
            LED2 = ON;
            break;
          /* Both Cluster1 and Cluster2 inactive */
          case CLUSTER1_CLUSTER2_DISABLE:
            l_sch_set(LI1, LI1_LIN_NULL_SCHEDULE, 0);
            l_sch_set(LI2, LI2_LIN_NULL_SCHEDULE, 0); 
            (void)printf("Master node requested cluster1 and cluster2 inactive\n");
            control1 = 0;
            control2 = 0;
            LED1 = OFF;
            LED2 = OFF;
            break;
          default:
            break;
        }
      }
      /* Control led of slaves in Cluster 1 */
      if(!SW1){
        (void)printf("Control LED of Cluster1 from GateWay\n");
        for(i = 0; i<60000;i++){
          for(j = 0; j<10;j++);
        };
        l_u8_wr(LI1_SlaveIdentifier, (led_control2%4));
        led_control2++;
      }
      /* Control led of slaves in Cluster 2 */
      if(!SW2){
        (void)printf("Control LED of Cluster2 from GateWay\n");
        for(i = 0; i<60000;i++){
          for(j = 0; j<10;j++);
        };
        l_u8_wr(LI2_SlaveIdentifier, (led_control1%4));
        led_control1++;
      }
      /* Reset LED of all slaves */
      if (!SW3) {
        (void)printf("Reset Leds of all slave \n");
        for(i = 0; i<60000;i++){
          for(j = 0; j<10;j++);
        };
        l_u8_wr(LI2_ResetSignal, 6);
        l_u8_wr(LI1_ResetSignal, 6);
      }
      
     /* Update Potentiometer value of Slave2 */
     if (l_flg_tst(LI1_Cluster1Slave2Info_flag)){
        l_flg_clr(LI1_Cluster1Slave2Info_flag);
        slave1info = l_u8_rd(LI1_Cluster1Potentiometer2);
        if (4 == counter){
          (void)printf("Potentiometer value of Slave2 = %d\n", slave1info);
        }
     }
     /* Update Potentiometer value of Slave1 */
     if (l_flg_tst(LI1_Cluster1Slave1Info_flag)){
        l_flg_clr(LI1_Cluster1Slave1Info_flag);
        slave1info = l_u8_rd(LI1_Cluster1Potentiometer1);
        if (4 == counter){
          (void)printf("Potentiometer value of Slave1 = %d\n", slave1info);
        }
    }
    /* Update Potentiometer value of SlaveA */
     if (l_flg_tst(LI2_Cluster2SlaveAInfo_flag)){
        l_flg_clr(LI2_Cluster2SlaveAInfo_flag);
        slave1info = l_u8_rd(LI2_Cluster2PotentiometerA);
        if (4 == counter){
          (void)printf("Potentiometer value of SlaveA = %d\n", slave1info);
        }
     }
     /* Update Potentiometer value of SlaveB */
     if (l_flg_tst(LI2_Cluster2SlaveBInfo_flag)){
        l_flg_clr(LI2_Cluster2SlaveBInfo_flag);
        slave1info = l_u8_rd(LI2_Cluster2PotentiometerB);
        if (4 == counter){
          (void)printf("Potentiometer value of SlaveB = %d\n", slave1info);
        }
     }
     /* Update Potentiometer value of SlaveC */
     if (l_flg_tst(LI2_Cluster2SlaveCInfo_flag)){
        l_flg_clr(LI2_Cluster2SlaveCInfo_flag);
        slave1info = l_u8_rd(LI2_Cluster2PotentiometerC);
        if (4 == counter){
          (void)printf("Potentiometer value of SlaveC = %d\n", slave1info);
        }
     }
      /*===========================================================
      ================Goto sleep/Wakeup demo ======================
      =============================================================*/
      
      /* Use the button PB4 in the EVB board to demonstrate goto sleep/wakeup feedture */
      if (!SW4){
        for(i = 0; i<60000;i++){
          for(j = 0; j<10;j++);
        };
        if (0 == (sw4%2)){
          (void)printf("Enable free counter for test goto sleep\n");
          l_sch_set(LI1, LI1_PeriodicalWakeupTable, 0);
          l_sch_set(LI2, LI2_PeriodicalWakeupTable, 0);
          count = 10;
          freecntr_enable();
        } else {
          (void)printf("Disable free counter\n");
          control1 = 0;
          control2 = 0;
          l_sch_set(LI1, LI1_LIN_NULL_SCHEDULE, 0);
          l_sch_set(LI2, LI2_LIN_NULL_SCHEDULE, 0);
          count = 10;
          freecntr_disable();
        }
        sw4++;
      }
      
     /* Send goto sleep command */
     if (GOTO_SLEEP_DURATION == count){
      (void)printf("Send goto sleep command\n");
      l_ifc_goto_sleep(LI2);
      l_ifc_goto_sleep(LI1);
      count++;
     }
     /* Run Periodical Wakeup table */
     if (WAKEUP_DURATION == count){
      (void)printf("Run Periodical Wakeup table\n");
      l_sch_set(LI1, LI1_PeriodicalWakeupTable, 0);
      l_sch_set(LI2, LI2_PeriodicalWakeupTable, 0);
      count = 0;
     }
     counter++;
     if (5 == counter){
      counter = 0;
     }
     /* Check if any sleep mode on two cluster by reading the LIN word status */
     LIN1_word_status = l_ifc_read_status(LI1);
     LIN2_word_status = l_ifc_read_status(LI2);
     
     if (LIN1_word_status != 0){
       if((LIN1_word_status>>3)&0x0001){
         LED3 = ON;    /* cluster1 bus is in sleep mode */
       }else{
         LED3 = OFF;   /* cluster1 bus is in wakeup mode */
       }
     }
     
     if (LIN2_word_status != 0){
       if((LIN2_word_status>>3)&0x0001){
         LED4 = ON;    /* cluster2 bus is in sleep mode */
       }else{
         LED4 = OFF;   /* cluster2 bus is in wakeup mode */
       }
     }
  }/* please make sure that you never leave this function */
}
