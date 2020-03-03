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

#define OUTPUT_SET(port,register_num)				XOUTPUT_SET(port,register_num)
#define XOUTPUT_SET(port,register_num)				GPIO##port##_PSOR |=1<<register_num

#define OUTPUT_CLEAR(port,register_num)				XOUTPUT_CLEAR(port,register_num)		
#define XOUTPUT_CLEAR(port,register_num)			GPIO##port##_PCOR |=1<<register_num

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
	CONFIG_PIN_AS_GPIO(PORT_C,20,INPUT); /* Configure BTN0 (PTC4) as an input */	
	CONFIG_PIN_AS_GPIO(PORT_C,21,INPUT); /* Configure BTN1 (PTC5) as an input */
    
    CONFIG_PIN_AS_GPIO(PORT_B,10,OUTPUT); /* Configure pin control LIN transceiver enable as an output */
    CONFIG_PIN_AS_GPIO(PORT_B,11,OUTPUT); /* Configure pin control LIN transceiver wakeup as an output */
    OUTPUT_SET(PORT_B,10);                /* Enable LIN transceiver */
    OUTPUT_CLEAR(PORT_B,11);              /* Disable wakeup LIN transceiver */
}
void main(void)
{
    l_u8 ret;
    l_u8 j, vector_number;
    l_u16 i;
    Clk_Init();
    GPIO_Init();
    //ret = l_sys_init();
    ret = l_ifc_init(LI0);
    
    vector_number = INT_UART0 -16;
    
	NVIC_ICPR |= 1 << (vector_number%32);
	NVIC_ISER |= 1 << (vector_number%32);
    for (;;){
    	if (l_flg_tst_LI0_sig_MotorQuery1_flag()){
    		l_flg_clr_LI0_sig_MotorQuery1_flag();
    	/* Create application here...*/
    	}

    }
}
