/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
#include "lin.h"
/**********************************************************************************************
* Constants and macros
**********************************************************************************************/
#define LED0_TOGGLE		OUTPUT_TOGGLE(PORT_C,16)
#define LED1_TOGGLE		OUTPUT_TOGGLE(PORT_C,17)
#define LED2_TOGGLE		OUTPUT_TOGGLE(PORT_C,18)
#define LED3_TOGGLE		OUTPUT_TOGGLE(PORT_C,19)

#define LED0_OFF		OUTPUT_CLEAR(PORT_C,16);
#define LED1_OFF		OUTPUT_CLEAR(PORT_C,17);
#define LED2_OFF		OUTPUT_CLEAR(PORT_C,18);
#define LED3_OFF		OUTPUT_CLEAR(PORT_C,19);

#define LED0_ON			OUTPUT_SET(PORT_C,16);
#define LED1_ON			OUTPUT_SET(PORT_C,17);
#define LED2_ON			OUTPUT_SET(PORT_C,18);
#define LED3_ON			OUTPUT_SET(PORT_C,19);

#define OUTPUT  1
#define INPUT	0

#define PORT_A  A
#define PORT_B  A
#define PORT_C  A
#define PORT_D  A

#define PORT_E	B
#define PORT_F	B
#define PORT_G	B
#define PORT_H	B

#define CONFIG_PIN_AS_GPIO(port,register_number,mode)    XCONFIG_PIN_AS_GPIO(port,register_number,mode)
#define XCONFIG_PIN_AS_GPIO(port,register_number,mode)   (mode == 0) ? (GPIO##port##_PDDR |= 0 << register_number) : (GPIO##port##_PDDR |= 1 << register_number) 

#define ENABLE_INPUT(port,pin_number) 					XENABLE_INPUT(port,pin_number)
#define XENABLE_INPUT(port,pin_number)					GPIO##port##_PIDR ^= 1<<pin_number

#define ENABLE_PULLUP(port,pin_number) 					XENABLE_PULLUP(port,pin_number) 	
#define XENABLE_PULLUP(port,pin_number) 				PORT_PUE0 |= PORT_PUE0_PT##port##PE##pin_number##_MASK 

#define OUTPUT_SET(port,register_num)				XOUTPUT_SET(port,register_num)
#define XOUTPUT_SET(port,register_num)				GPIO##port##_PSOR |=1<<register_num

#define OUTPUT_CLEAR(port,register_num)				XOUTPUT_CLEAR(port,register_num)		
#define XOUTPUT_CLEAR(port,register_num)			GPIO##port##_PCOR |=1<<register_num

#define OUTPUT_TOGGLE(port,register_num)			XOUTPUT_TOGGLE(port,register_num)
#define XOUTPUT_TOGGLE(port,register_num)			GPIO##port##_PTOR |=1<<register_num

#define MOTOR_SELECTION_INCREASE  1
#define MOTOR_SELECTION_DECREASE  2
#define MOTOR_SELECTION_STOP      3

#define MOTOR1_OVER_TEMP   200
#define MOTOR1_MAX_TEMP   100
#define MOTOR1_MIN_TEMP   30

/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0;
l_u8 Motor1_temp;
/***********************************************************************************************
*
* @brief    CLK_Init - Initialize the clocks to run at 20 MHz from the 10Mhz external XTAL
* @param    none
* @return   none
*
************************************************************************************************/  
void Clk_Init()
{
	ICS_C1|=ICS_C1_IRCLKEN_MASK; 		/* Enable the internal reference clock*/ 
	ICS_C3= 0x90;						/* Reference clock frequency = 39.0625 KHz*/		
	while(!(ICS_S & ICS_S_LOCK_MASK));   /* Wait for PLL lock, now running at 40 MHz (1024 * 39.0625Khz) */		
    ICS_C2|=ICS_C2_BDIV(1)  ; 			/*BDIV=2, Bus clock = 20 MHz*/
	ICS_S |= ICS_S_LOCK_MASK ; 			/* Clear Loss of lock sticky bit */	
		

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
		CONFIG_PIN_AS_GPIO(PORT_C,16,OUTPUT); /* Configure LED 0 (PTC0) as an output */
		CONFIG_PIN_AS_GPIO(PORT_C,17,OUTPUT); /* Configure LED 1 (PTC1) as an output */
		CONFIG_PIN_AS_GPIO(PORT_C,18,OUTPUT); /* Configure LED 2 (PTC2) as an output */
		CONFIG_PIN_AS_GPIO(PORT_C,19,OUTPUT); /* Configure LED 3 (PTC3) as an output */
		
		CONFIG_PIN_AS_GPIO(PORT_D,24,INPUT); /* Configure BTN0 (PTD0) as an input */	
		CONFIG_PIN_AS_GPIO(PORT_D,25,INPUT); /* Configure BTN1 (PTD1) as an input */
		ENABLE_INPUT(PORT_D,24);			 /* Enable input SW1*/	
		ENABLE_INPUT(PORT_D,25);			/*  Enable input SW2*/
		
		LED0_OFF;							/* Turn off LED0 */
		LED1_OFF;							/* Turn off LED1 */
		LED2_OFF;							/* Turn off LED2 */
		LED3_OFF;							/* Turn off LED3 */
        
        CONFIG_PIN_AS_GPIO(PORT_B,10,OUTPUT); /* Configure pin control LIN transceiver enable as an output */
		CONFIG_PIN_AS_GPIO(PORT_B,11,OUTPUT); /* Configure pin control LIN transceiver wakeup as an output */
		OUTPUT_SET(PORT_B,10);                /* Enable LIN transceiver */
		OUTPUT_CLEAR(PORT_B,11);              /* Disable wakeup LIN transceiver */
}
/***********************************************************************************************
*
* @brief   lin_application_timer_FTM0 - Initialize the timer for LIN application
* @param    none
* @return   none
*
************************************************************************************************/
void lin_application_timer_FTM0()
{
	SIM_SCGC |= SIM_SCGC_FTM0_MASK; /* Enable Clock for FTM0 */			
	FTM0_SC |= FTM_SC_PS(7);	/* Select Preescaler in this case 128. 20 Mhz /128 =156.25 Khz. */ 
									/* Counter increase by one every 6.4 us */		
		/* Enable Channle 0*/
	FTM0_C0SC |= FTM_CnSC_CHIE_MASK; /* Enable channel 0 interrupt */
	FTM0_C0SC |= FTM_CnSC_MSA_MASK;  /* Channel as Output compare mode */			
		/*Select interrupt frequency*/
	FTM0_C0V = FTM_CnV_VAL(391) ;	 	/* Interrupt every 2.5ms */	

	FTM0_SC |= FTM_SC_CLKS(1); /*FTM0 use system clock*/
				
		/* Set the ICPR and ISER registers accordingly */
	NVIC_ICPR |= 1 << ((INT_FTM0-16)%32);
	NVIC_ISER |= 1 << ((INT_FTM0-16)%32);
}

void main(void)
{
    l_u8 ret;
    l_u8 j, vector_number;
    l_u16 i =0,k=0;
    Clk_Init();
    GPIO_Init();
    ret = l_sys_init();

    ret = l_ifc_init(LI0);
    lin_application_timer_FTM0();
    l_sch_set(LI0, LI0_NormalTable, 0);
    vector_number = INT_UART0 -16;

	NVIC_ICPR |= 1 << (vector_number%32);
	NVIC_ISER |= 1 << (vector_number%32);
	
	k = l_u16_rd_LI0_MotorSpeed();
	
    for (;;){    	
    	if (l_flg_tst_LI0_Motor1Temp_flag()){
    			/* Clear this flag... */
    			l_flg_clr_LI0_Motor1Temp_flag();
    			/* Store temperature data */
    			Motor1_temp = l_u8_rd_LI0_Motor1Temp();
    			/* The application will change Motor selection in case 
    			   the temperature is greater than maximum value to release motor power
    			   This will be transfered by unconditional frame type in LIN bus */
    			if (MOTOR1_OVER_TEMP<Motor1_temp) {
    			  /* Request stop motor by power off */
    				LED1_ON;
    				LED2_ON;    				
    			   l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_STOP);
    			} else if ((MOTOR1_MAX_TEMP<Motor1_temp)&(MOTOR1_OVER_TEMP > Motor1_temp)){
    			  /* Request to reduce motor speed */
    			  l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_DECREASE);  
    			  LED1_OFF;
    			  LED2_ON;
    			  }
    			else {
    			  /* Request to increase motor speed if user request */
    			  l_u8_wr_LI0_Motor1Selection(MOTOR_SELECTION_INCREASE);
    			  LED1_ON;
    			  LED2_OFF;    			  
    			}
    	   }
    	    
    } /* loop forever */
    	  /* please make sure that you never leave main */
}


void FTM0_IRQHandler()
  { 	
    if (1==((FTM0_C0SC & FTM_CnSC_CHF_MASK)>>FTM_CnSC_CHF_SHIFT) )  /* If the CHF of the channel is equal to 0 */
  	{
  		(void)FTM0_C0SC;  							/* Read to clear flag */
  		FTM0_C0SC ^= FTM_CnSC_CHF_MASK;  			/* Clear flag */
  		FTM0_C0V = FTM0_C0V + 391 ; /* Refresh interrupt period */
  		
  		if (LIN_counter>=2){
  		    /* Activate LIN frame transfer for every 5ms */
  		    l_sch_tick(LI0); 
  		    /* Reset counter */
  		    LIN_counter = 0;
  		  }
  	  if (LED_counter>=50){
  	    /* Toggle LED for LIN transmission */
  	    /* Reset counter */
  		LED0_TOGGLE;
  	    LED_counter = 0;
  	  }
	  LIN_counter++;
	  LED_counter++;
  		
  	}
  }
