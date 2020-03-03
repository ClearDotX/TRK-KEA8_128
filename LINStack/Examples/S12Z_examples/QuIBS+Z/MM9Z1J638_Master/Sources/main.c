#include <hidef.h> /* for EnableInterrupts macro */
#include "GECKOP.h"
#include "derivative.h" /* include peripheral declarations */
#include "QUIBs.h"
#include "Defines.h"
#include "CPMU.h"
#include "lin.h"
#include "lin_lld_sci.h"
#if _TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_
#include "lin_lin21tl_api.h"
#endif

#define EXTERNAL_TRAN 1

#define MOTOR_SELECTION_INCREASE  1
#define MOTOR_SELECTION_DECREASE  2
#define MOTOR_SELECTION_STOP      3

#define MOTOR1_OVER_TEMP   200
#define MOTOR1_MAX_TEMP   100
#define MOTOR1_MIN_TEMP   20

/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0;
l_u8 Motor1_temp;

#define SRS 1     

#define LIN_EN 4   /* Enable LIN */ 
#define LVSD 8     /* low voltage operation (not compliant to SAE J2602) */
void Init_LIN_Slave(void);
void Init_LIN_Slave() {
#if EXTERNAL_TRAN
    /* Init pads */
    B_GPIO_CTL = 0x2626; /*PTB2 - IN     PTB1 - OUT*/
    B_GPIO_PUC = 0x00; /* NO Pull-Ups/Downs */
    B_GPIO_IN1 = 0x00;
    B_GPIO_OUT1 = 0x04; /* PTB1 as Tx */
    B_GPIO_IN2 = 0x04; /*PTB2 as Rx */
    B_GPIO_OUT2 = 0x00;
#else
    /* SCI clock = D2D clock / 1 */
    B_SCIC1_DPD0 = 1;
    B_SCIC1_DPD1 = 1;
    B_LIN_SR = 0x4000; /* clear TXDOM flag */
    B_LIN_CTL = 0x0F00 | B_LIN_CTL_LVSD_MASK | B_LIN_CTL_EN_MASK | SRS; /* 19.2kBaud   + enable LIN module + LVSD */
    B_LIN_SR = 0x4000; /* clear TXDOM flag */

    B_LIN_TX = 1; /* connection to SCI for TX */
    B_LIN_RX = 1; /* connection to SCI for RX */ 
    B_LIN_SRH = 0xFF; /* Clear Flags */
    
#endif
    
    /* disable current/voltage measurement */
    B_INT_MSKL_CVMM = 1;
}
#define LED0 PTA_PTA6

#define SW0 PTB_PTA7

/* Current ISSUE: Before flash the project, please RESTART the board by POWER OFF then ON. */
void main(void) {
    unsigned int i,j;
    l_u8 ret;
    /* Init QUIBs basics */
    QUIBs_Init();

    /* load trim */
    GECKOP_LoadTrim(2);
    Init_LIN_Slave();

    ret = l_sys_init();
    ret = l_ifc_init(LI0);
    l_sch_set(LI0, LI0_NormalTable, 0);
    
#if _TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_
    ld_init();
#endif

    DDRA |= DDRA_DDRA6_MASK; // PTA6 as output LED
    DDRA = DDRA & (~(DDRA_DDRA7_MASK)); //PTA7 as input SW
    PTA_PTA6 = 1;

    EnableInterrupts;
    for (;;) {
    	for (i = 0; i < 4000; i++);
    	l_sch_tick(LI0);
        if (!PTA_PTA7) {
            for (i = 0; i < 60000; i++)
                for (j = 0; j < 20; j++);
            /* LIN bus has been in the sleep mode */
            l_ifc_wake_up(LI0);
        }
        if (l_flg_tst_LI0_Motor1Temp_flag()){
       		/* Clear this flag... */
       		l_flg_clr_LI0_Motor1Temp_flag();
       		/* Store temperature data */
       		Motor1_temp = l_u8_rd_LI0_Motor1Temp();
       		/* The application will change Motor selection in case 
       		   the temperature is greater than maximum value to release motor power
       		   This will be transfered by sporadic frame type in LIN bus */
       		if (MOTOR1_OVER_TEMP<Motor1_temp) {
       		  /* Request stop motor by power off */
       		   l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_STOP);
       		} else if ((MOTOR1_MAX_TEMP<Motor1_temp)&(MOTOR1_OVER_TEMP > Motor1_temp)){
       		  /* Request to reduce motor speed */
       		  l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_DECREASE);  
       		} else {
       		  /* Request to increase motor speed if user request */
       		  l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_INCREASE);
       		}
           }
        /* Check if Motor speed signal has been changed. */
    } /* loop forever */
    /* please make sure that you never leave main */

}
