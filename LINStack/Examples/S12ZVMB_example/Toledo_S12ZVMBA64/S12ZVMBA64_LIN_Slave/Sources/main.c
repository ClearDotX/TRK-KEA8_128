#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "lin.h"

#define MOTOR_SELECTION_INCREASE 1
#define MOTOR_SELECTION_DECREASE 2
#define MOTOR_SELECTION_STOP   3

/* Note that LED0 is PWMLED0 on S12ZVMB Validation Board */
#define LED0_ENABLE     (DDRE_DDRE0 = 1)            /*Enable PE0*/
#define LED0_DISABLE    (DDRE_DDRE0 = 0)            /*Disable PE0*/
#define LED0_ON         (PTE_PTE0 = 1)              /*Set PE0*/
#define LED0_OFF        (PTE_PTE0 = 0)              /*Clear PE0*/
#define LED0_TOGGLE     (PTE_PTE0 = ~ PTE_PTE0)     /*Toggle PE0*/

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
    /* include your code here */
    CPMU_Init();
    GPIO_Init();
    EnableInterrupts;
    l_sys_init();
    l_ifc_init(LI0);

    for(;;)
    {
        /* feeds the dog */
        __RESET_WATCHDOG();
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
                 LED0_ON;

            }
            if (Motor1_Selection == MOTOR_SELECTION_DECREASE)
            {
                 Motor1_temp--;
                 LED0_OFF;
            }
        }
    } /* loop forever */
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
    /* Enable LED0 */
    LED0_ENABLE;
    /* Turn-off LED0 */
    LED0_OFF;
}

