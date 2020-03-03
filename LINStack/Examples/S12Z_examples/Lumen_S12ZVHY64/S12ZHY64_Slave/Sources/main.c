#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "lin.h"
#include "LCD.h"
#define SW1 PTT_PTT3

#define MOTOR_SELECTION_INCREASE 1
#define MOTOR_SELECTION_DECREASE 2
#define MOTOR_SELECTION_STOP   3

/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0, Temp_counter =0;
l_u8 Motor1_temp = 30U;
l_u8 Motor1_Selection;

void Timer0_channel3_Init(void)
{
    /*Configure the timer*/
    /* Enable Channel 3 as Output Compare */
    TIM0TIOS_IOS3 = 1;
    /* Enable Channel 3 interrupt */
    TIM0TIE_C3I = 1;
    /* Set counter as 2.5ms timing */
    TIM0TC3 = 20000;
}


void Init_CPMU()
{
    CPMUREFDIV_REFDIV = 0;
    CPMUREFDIV_REFFRQ = 0;
    CPMUSYNR_SYNDIV = 15;
    CPMUSYNR_VCOFRQ = 0;
    CPMUPOSTDIV_POSTDIV = 1;
    while (CPMUIFLG_LOCK == 0)
    {}
    /*Clear PORF and LVRF */
    CPMURFLG  = 0x60;
}

void main(void) {
    l_u8 ret;
    l_u8 j;
    l_u16 i;
    Init_CPMU();
    EnableInterrupts;
    DDRJ_DDRJ3 = 1;
    DDRT_DDRT3 = 0;
    PTIT_PTIT3 = 1;
    /*Enable RTC clock for LCD*/
    /* Choose RTCCLK is from OSCCLK_32K */
    RTCCTL2 |= 1 << RTCCTL2_CLKSRC_BITNUM;
        			
    /*Enable RTC clock for LCD*/
    RTCCTL1 |= RTCCTL1_RTCEN_MASK;
    
    /* Configures the LCD controller for 4x40 operation */
    LCD_Init();
    /* LIN system initilization */
    ret = l_sys_init();
    /* LIN interface initilization */
    ret = l_ifc_init(LI0);
    /* Display temperature mode */
    setTempMode();
    /* Initilize timer channel 3 for temperature change */
    Timer0_channel3_Init();

    for (;;) {
        /* Check if temp signal is updated */
        if (l_flg_tst_LI0_Motor1Selection_flag())
        {
            /* Clear this flag... */
            l_flg_clr_LI0_Motor1Selection_flag();
            /* Store selection data */
            Motor1_Selection = l_u8_rd_LI0_Motor1Selection();
            SetG(Motor1_Selection);
            /* The application will change Motor selection in case
            the temperature is greater than maximum value to release motor power*/
            l_u8_wr_LI0_Motor1Temp(Motor1_temp);
            /* Check if power off motor due to high temperature */
            if (Motor1_Selection == MOTOR_SELECTION_STOP)
            {
                /*---------- add code here to stop motor ------------*/
                Motor1_temp = 25; /* Ambiance temperature */
            }
        }
    }
}
/* Interrupt routine for LIN application for every 2.5ms */
interrupt VectorNumber_Vtim0ch3 void TIMER0_CHANNEL3_ISR()
{
    if (LIN_counter>=2)
    {
        /* Reset counter */
        LIN_counter = 0;
        Temp_counter++;
        if (10000<Temp_counter)
        {
            Temp_counter = 0;
        }
    }

    if (LED_counter>=100)
    {
        if (Motor1_Selection == MOTOR_SELECTION_INCREASE)
        {
            Motor1_temp++;
        }
        else if (Motor1_Selection == MOTOR_SELECTION_DECREASE)
        {
            Motor1_temp--;
        }
        /* Reset counter */
        LED_counter = 0;
    }
    SetOdo(Motor1_temp);
    LIN_counter++;
    LED_counter++;
    /* Clear Timer 0 Channel 3 interrupt flag*/
    TIM0TFLG1 = TIM0TFLG1_C3F_MASK;
    TIM0TC3   = (TIM0TC3 + 20000) & 0xFFFF;
}   /*TIM0 chan3*/
