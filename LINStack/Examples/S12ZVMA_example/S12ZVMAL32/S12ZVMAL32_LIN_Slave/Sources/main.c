#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "lin.h"

#define MOTOR_SELECTION_INCREASE 1
#define MOTOR_SELECTION_DECREASE 2
#define MOTOR_SELECTION_STOP   3

/* Note that LED2 is PWMLED2 on S12ZVMA Validation Board */
#define LED2_ENABLE     (DDRP_DDRP0 = 1)            /*Enable PP0*/
#define LED2_DISABLE    (DDRP_DDRP0 = 0)            /*Disable PP0*/
#define LED2_ON         (PTP_PTP0 = 1)              /*Set PP0*/
#define LED2_OFF        (PTP_PTP0 = 0)              /*Clear PP0*/
#define LED2_TOGGLE     (PTP_PTP0 = ~ PTP_PTP0)     /*Toggle PP0*/

/* Global variables */
l_u8 Motor1_temp = 30;
l_u8 Motor1_Selection;

/********************************************************************************************
 * FUNCTION PROTOTYPES
 *******************************************************************************************/
void CPMU_Init(void);
void GPIO_Init(void);

/********************************************************************************************
 * CODE
 *******************************************************************************************/
void main(void)
{

    CPMU_Init();
    GPIO_Init();
    EnableInterrupts;
    l_sys_init();
    l_ifc_init(LI0);

    for(;;)
    {
        __RESET_WATCHDOG(); /* feeds the dog */
        /* Add source code here */
        /* .... */
        /* Check if temp signal is updated */
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

/********************************************************************************************
*
* @brief    CPMU_Init initializes core clock frequency
* @param    none
* @return   none
*
*********************************************************************************************/
void CPMU_Init()
{
    /* Procedure proposed by to setup PLL and Oscillator */
    /* example for OSC = 4 MHz and Bus Clock = 25MHz, That is VCOCLK = 50MHz */
    /* Initialize */
    /* PLL Clock = 50 MHz, divide by one */
    CPMUPOSTDIV = 0x00;
    /* Generally: Whenever changing PLL reference clock (REFCLK) frequency to a higher value */
    /* it is recommended to write CPMUSYNR = 0x00 in order to stay within specified */
    /* maximum frequency of the MCU */
    CPMUSYNR = 0x00;
    /* Use Internal clock 1Mhz*/
    CPMUOSC = 0x00;
    /* multiply REFCLK = 1MHz by 2*(24+1)*1MHz = 50MHz */
    /* VCO range 48 to 80 MHz (VCOFRQ[1:0] = 01) */
    CPMUSYNR = 0x58;
    /* clear all flags, especially LOCKIF and OSCIF */
    CPMUIFLG = 0xFF;
}

/***********************************************************************************************
*
* @brief    GPIO_Init - Initialize the pins for input/output
* @param    none
* @return   none
*
************************************************************************************************/
void GPIO_Init()
{
    /* Enable LED2 */
    LED2_ENABLE;
    /* Turn-off LED2 */
    LED2_OFF;
}
