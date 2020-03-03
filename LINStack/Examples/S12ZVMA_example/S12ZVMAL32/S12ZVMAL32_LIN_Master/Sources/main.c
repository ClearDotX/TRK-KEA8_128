#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "lin.h"

#define MOTOR_SELECTION_INCREASE  1
#define MOTOR_SELECTION_DECREASE  2
#define MOTOR_SELECTION_STOP      3

#define MOTOR1_OVER_TEMP   200
#define MOTOR1_MAX_TEMP   100
#define MOTOR1_MIN_TEMP   20

/* Note that LED2 is PWMLED2 on S12ZVMA Validation Board */
#define LED2_ENABLE     (DDRP_DDRP0 = 1)            /*Enable PP0*/
#define LED2_DISABLE    (DDRP_DDRP0 = 0)            /*Disable PP0*/
#define LED2_ON         (PTP_PTP0 = 1)              /*Set PP0*/
#define LED2_OFF        (PTP_PTP0 = 0)              /*Clear PP0*/
#define LED2_TOGGLE     (PTP_PTP0 = ~ PTP_PTP0)     /*Toggle PP0*/

/* Global variables */
l_u8 LIN_counter =0;
l_u8 Motor1_temp;

/********************************************************************************************
 * FUNCTION PROTOTYPES
 *******************************************************************************************/
void Timer1_channel1_Init(void);
void CPMU_Init(void);
void GPIO_Init(void);
void TIMER1_CHANNEL1_ISR(void);

/********************************************************************************************
 * CODE
 *******************************************************************************************/
void main(void)
{

    EnableInterrupts;
    CPMU_Init();
    GPIO_Init();
    /*Enable LIN Pullup Resistor for Master Node */
    LP0CR_LPPUE = 1U;
    /* Configure LIN Physical with slew rate for 9600bps*/
    LP0SLRM_LPSLR = 0x01U;
    /*Initialize LIN Physical */
    LP0CR_LPE = 1U;
    l_sys_init();
    l_ifc_init(LI0);
    l_sch_set(LI0, LI0_NormalTable,0);
    Timer1_channel1_Init();

    for(;;)
    {
        __RESET_WATCHDOG(); /* feeds the dog */
        /* Add source code here */

        if (l_flg_tst_LI0_Motor1Temp_flag())
        {
            /* Clear this flag... */
            l_flg_clr_LI0_Motor1Temp_flag();
            /* Store temperature data */
            Motor1_temp = l_u8_rd_LI0_Motor1Temp();
            /* The application will change Motor selection in case
               the temperature is greater than maximum value to release motor power */
            if (MOTOR1_OVER_TEMP<Motor1_temp)
            {
               /* Request stop motor by power off */
               l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_STOP);

            }
            else if ((MOTOR1_MAX_TEMP<Motor1_temp)&(MOTOR1_OVER_TEMP > Motor1_temp))
            {
               /* Request to reduce motor speed */
               l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_DECREASE);
               LED2_OFF;
            }
            else
            {
               /* Request to increase motor speed if user request */
               l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_INCREASE);
               LED2_ON;
            }
        }
    } /* loop forever */
  /* please make sure that you never leave main */
}

/********************************************************************************************
*
* @brief    Timer1_channel1_Init initializes channel 1 in Output Compare Mode
            Timer 1 was initialized in l_sys_init()
* @param    none
* @return   none
*
*********************************************************************************************/
void Timer1_channel1_Init(void)
{
    /*Configure the timer*/
    /* Enable Channel 1 as Output Compare */
    TIM1TIOS_IOS1 = 1;
    /* Enable Channel 1 interrupt */
    TIM1TIE_C1I = 1;
    /* Set counter as 2.5ms timing */
    TIM1TC1 = (MCU_BUS_FREQ/10000)*25;
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

/***********************************************************************************************
*
* @brief    TIMER1_CHANNEL1_ISR - Interrupt handler for Timer 1 channel 1
*           Interrupt frequency is 2.5ms
* @param    none
* @return   none
*
************************************************************************************************/
interrupt VectorNumber_Vtim1ch1 void TIMER1_CHANNEL1_ISR()
{
    if (LIN_counter>=2)
    {
        /* Activate LIN frame transfer for every 5ms */
        l_sch_tick(LI0);
        /* Reset counter */
        LIN_counter = 0;
    }

    LIN_counter++;
    /* Clear timer 1 channel 1 interrupt flag */
    TIM1TFLG1 = TIM1TFLG1_C1F_MASK;
    TIM1TC1   = (TIM1TC1 + (MCU_BUS_FREQ/10000)*25) & 0xFFFF;
}   /*TIM1 chan1*/
