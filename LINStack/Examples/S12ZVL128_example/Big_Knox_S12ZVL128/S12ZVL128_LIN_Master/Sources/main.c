#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "lin.h"

#define SW2 PTP_PTP2


#define MOTOR_SELECTION_INCREASE  1
#define MOTOR_SELECTION_DECREASE  2
#define MOTOR_SELECTION_STOP      3

#define MOTOR1_OVER_TEMP   200
#define MOTOR1_MAX_TEMP   100
#define MOTOR1_MIN_TEMP   20


#define LED2_ENABLE     (DDRP_DDRP3 = 1)            /*Enable PP3*/
#define LED2_DISABLE    (DDRP_DDRP3 = 0)            /*Disable PP3*/
#define LED2_ON         (PTP_PTP3 = 0)              /*Set PP3*/
#define LED2_OFF        (PTP_PTP3 = 1)              /*Clear PP3*/
#define LED2_TOGGLE     (PTP_PTP3 = ~ PTP_PTP3)     /*Toggle PP3*/

/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0;
l_u8 Motor1_temp;

void Timer0_channel3_Init(void){
    TIM0TIOS_IOS3 = 1;      /* Enable Channel 3 as Output Compare */
    TIM0TIE_C3I = 1;        /* Enable Channel 3 interrupt */
    TIM0TC3 = 62500;        /* Set counter as 2.5ms timing */
}
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


void main(void)
{

  EnableInterrupts;
  /* include your code here */
  PLL_init();
  Init_PIM();
  GPIO_Init();
  Init_LIN();
  l_sys_init();
  l_ifc_init(LI0);
  l_sch_set(LI0, LI0_NormalTable,0);
  Timer0_channel3_Init();

  for(;;)
  {
        __RESET_WATCHDOG(); /* feeds the dog */
        /* Add source code here */
        /* .... */
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
                /* Turn-off LED2 */
                LED2_OFF;
            }
            else
            {
                /* Request to increase motor speed if user request */
                l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_INCREASE);
                /* Turn-on LED2 */
                LED2_ON;
            }
        }
    } /* loop forever */
    /* please make sure that you never leave main */
}

/* Interrupt routine for LIN application for every 2.5ms */
interrupt VectorNumber_Vtim0ch3 void TIMER0_CHANNEL3_ISR()
{
    if (LIN_counter>=2)
    {
        /* Activate LIN frame transfer for every 5ms */
        l_sch_tick(LI0);
        /* Reset counter */
        LIN_counter = 0;
    }

    LIN_counter++;
    /* Clear timer 0 channel 3 interrupt flag */
    TIM0TFLG1 = TIM0TFLG1_C3F_MASK;
    TIM0TC3   = (TIM0TC3 + 20000) & 0xFFFF;
}   /*TIM0 chan3*/
