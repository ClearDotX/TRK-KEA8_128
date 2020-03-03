#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "lin.h"

#define MOTOR_SELECTION_INCREASE 1
#define MOTOR_SELECTION_DECREASE 2
#define MOTOR_SELECTION_STOP   3

/* Note that LED2 is PWMLED2 on S12ZVMA Validation Board */
#define LED2_ENABLE     (DDRP_DDRP2 = 1)            /*Enable PP0*/
#define LED2_DISABLE    (DDRP_DDRP2 = 0)            /*Disable PP0*/
#define LED2_ON         (PTP_PTP2 = 1)              /*Set PP0*/
#define LED2_OFF        (PTP_PTP2 = 0)              /*Clear PP0*/
#define LED2_TOGGLE     (PTP_PTP2 = ~ PTP_PTP0)     /*Toggle PP0*/

/* Global variables */
l_u8 Motor1_temp = 30;
l_u8 Motor1_Selection;

void CPMU_Init();
void main(void) {
  LED2_ENABLE;
  CPMU_Init();
  EnableInterrupts;
  l_sys_init();
  l_ifc_init(LI0);

  for(;;) {
    if (l_flg_tst_LI0_Motor1Selection_flag())
    {
        /* Clear this flag... */
        l_flg_clr_LI0_Motor1Selection_flag();
        /* Store selection data */
        Motor1_Selection = l_u8_rd_LI0_Motor1Selection();
        /* The application will change Motor selection in case
        the temperature is greater than maximum value to release motor power */
        l_u8_wr_LI0_Motor1Temp(Motor1_temp);
        /* Check if power off motor due to high temperature */
        if (Motor1_Selection == MOTOR_SELECTION_STOP)
        {
            /*---------- add code here to stop motor ------------*/

        }
        if (Motor1_Selection == MOTOR_SELECTION_INCREASE)
        {
             Motor1_temp++;
             LED2_ON;
        }
        if (Motor1_Selection == MOTOR_SELECTION_DECREASE)
        {
             Motor1_temp--;
             LED2_OFF;
        }
    }
  } /* loop forever */
  /* please make sure that you never leave main */
}


 void CPMU_Init()
 {
    /* Set input of PLL is 1Mhz */
    /* Choose internal clock for PLL */
    CPMUOSC_OSCE = 0;

    /* Set reference divider is 4 */
    CPMUREFDIV_REFDIV = 0x03;
    /* REFCLK Frequency in ranges of 1-2Mhz */
    CPMUREFDIV_REFFRQ = 0x00;

    /* Set output clock of PLL is 48Mhz */
    /* VCOCLK Frequency in range of 32-48Mhz */
    CPMUSYNR_VCOFRQ =   0x00;
    /* fVCO = 2 * fREF * (SYNDIV + 1) */
    CPMUSYNR_SYNDIV =  0x17;
    /* Core clock = PLL clock devide by one */
    CPMUPOSTDIV = 0x00;
    /* Wait for PLL stable */
    while(!CPMUFLG_LOCK );
    /* Clear all flag */
    CPMUFLG = 0xFF;
 }