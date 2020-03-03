#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "lin.h"

#define MOTOR_SELECTION_INCREASE 1
#define MOTOR_SELECTION_DECREASE 2
#define MOTOR_SELECTION_STOP   3

/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0;
l_u8 Motor1_temp = 30;
l_u8 Motor1_Selection;

void Init_CPMU()
{
    // Wait for stable supply after power up
    while (GDUF_GLVLSF)
    {
        GDUF_GLVLSF = 1;
    }

    CPMUREFDIV_REFDIV = 0;
    CPMUREFDIV_REFFRQ = 0;
    CPMUSYNR_SYNDIV = 15;
    CPMUSYNR_VCOFRQ = 0;
    CPMUPOSTDIV_POSTDIV = 1;

    while (CPMUIFLG_LOCK == 0)
    {}

    //Clear PORF and LVRF
    CPMURFLG  = 0x60;
}
void Init_PIM(void){

    MODRR0 = (MODRR0_S0LRR_MASK && 0b000) | (MODRR0_SCI1RR_MASK);
}

/*Init LIN physical */
void Init_LIN(void){
    LP0CR_LPE = 1;       // Enable LIN Phy
    LP0CR_LPPUE = 1;     // Pull up to strong signal
    //LPSLRM = 0x01;
    LP0SLRM = 0x01;
}

void main(void)
{
    EnableInterrupts;
    /* include your code here */
    Init_CPMU();
    Init_PIM();
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
            the temperature is greater than maximum value to release motor power
            This will be transfered by sporadic frame type in LIN bus */
            l_u8_wr_LI0_Motor1Temp(Motor1_temp);
            /* Check if power off motor due to high temperature */
            if (Motor1_Selection == MOTOR_SELECTION_STOP)
            {
                /*---------- add code here to stop motor ------------*/
            }
        }
    } /* loop forever */
}

