#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "lin.h"


#define MOTOR_SELECTION_INCREASE 1
#define MOTOR_SELECTION_DECREASE 2
#define MOTOR_SELECTION_STOP   3

#define LED2_ENABLE     (DDRP_DDRP3 = 1)            /*Enable PP3*/
#define LED2_DISABLE    (DDRP_DDRP3 = 0)            /*Disable PP3*/
#define LED2_ON         (PTP_PTP3 = 0)              /*Set PP3*/
#define LED2_OFF        (PTP_PTP3 = 1)              /*Clear PP3*/
#define LED2_TOGGLE     (PTP_PTP3 = ~ PTP_PTP3)     /*Toggle PP3*/

/* Global variables */
l_u8 LIN_counter = 0, LED_counter = 0;
l_u8 Motor1_temp = 30;
l_u8 Motor1_Selection;


//inits the pll
void PLL_init()
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
    /* configure PLL reference clock (REFCLK) for usage with Oscillator */
    /* OSC=4MHz divide by 4 (3+1) = 1MHz, REFCLK range 1MHz to 2 MHz (REFFRQ[1:0] = 00) */
    CPMUREFDIV = 0x07;
    /* enable external Oscillator, switch PLL reference clock (REFCLK) to OSC */
    CPMUOSC = 0x80;
    /* multiply REFCLK = 1MHz by 2*(24+1)*1MHz = 50MHz */
    /* VCO range 48 to 80 MHz (VCOFRQ[1:0] = 01) */
    CPMUSYNR = 0x58;
    /* clear all flags, especially LOCKIF and OSCIF */
    CPMUIFLG = 0xFF;
    /* put your code to loop and wait for the LOCKIF and OSCIF or */
    /* poll CPMUIFLG register until both UPOSC and LOCK status are “1” */
    /* that is CPMIFLG == 0x1B */
}

void Init_PIM(void){

    MODRR0 = (MODRR0_S0L0RR_MASK && 0b000) | (MODRR0_SCI1RR_MASK);
}

/*Init LIN physical */
void Init_LIN(void){
    LP0CR_LPE = 1;       // Enable LIN Phy
    LP0CR_LPPUE = 1;     // Pull up to strong signal
    LP0SLRM = 0x01;
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
    LED2_ENABLE; /* Enable LED2 */
    LED2_OFF;   /* Turn-off LED2 */
}


void main(void) {

    EnableInterrupts;
    /* include your code here */
    PLL_init();
    Init_PIM();
    GPIO_Init();
    Init_LIN();
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
                  /*---------- add code here to stop motor ------------*/
                 Motor1_temp++;
                 /* Turn-on LED2 */
                 LED2_ON;
             }
             if (Motor1_Selection == MOTOR_SELECTION_DECREASE)
             {
                 /*---------- add code here to stop motor ------------*/
                 Motor1_temp--;
                 /* Turn-off LED2 */
                 LED2_OFF;
             }
        }

    } /* loop forever */
    /* please make sure that you never leave main */
}
