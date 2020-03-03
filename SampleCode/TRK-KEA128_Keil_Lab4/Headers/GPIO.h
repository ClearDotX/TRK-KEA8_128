/*
 * GPIO.h
 *
 *  Created on: Sep 24, 2013
 *      Author: B46911
 */

#ifndef GPIO_H_
#define GPIO_H_

/*******************************************************************************
* Includes
*******************************************************************************/
#include "derivative.h"


/*******************************************************************************
* Constants
********************************************************************************/


/*******************************************************************************
* Macros
********************************************************************************/
#define PTA  GPIOA
#define PTB  GPIOA
#define PTC  GPIOA
#define PTD  GPIOA

#define PTE	GPIOB
#define PTF	GPIOB
#define PTG	GPIOB
#define PTH	GPIOB

#define PTI	GPIOC

#define OUTPUT  1
#define INPUT	0

#define CONFIG_PIN_AS_GPIO(port,port_pin,mode)    XCONFIG_PIN_AS_GPIO(port,port_pin,mode)
#define XCONFIG_PIN_AS_GPIO(port,port_pin,mode)   (mode == 0) ? (port->PDDR |= 0 << port_pin) : (port->PDDR |= 1 << port_pin) 

#define ENABLE_INPUT(port,port_pin) 					XENABLE_INPUT(port,port_pin)
#define XENABLE_INPUT(port,port_pin)					port->PIDR ^= 1<<port_pin

#define ENABLE_PULLUP(port,port_pin) 					XENABLE_PULLUP(port,port_pin) 	
#define XENABLE_PULLUP(port,port_pin) 				if(port==GPIOA){PORT->PUE0 |= 1<<port_pin;} else if(port==GPIOB){PORT->PUE1|=1<<port_pin;} else {PORT->PUE2|=1<<port_pin;}

#define OUTPUT_SET(port,register_num)					XOUTPUT_SET(port,register_num)
#define XOUTPUT_SET(port,register_num)				port->PSOR |=1<<register_num

#define OUTPUT_CLEAR(port,register_num)				XOUTPUT_CLEAR(port,register_num)		
#define XOUTPUT_CLEAR(port,register_num)			port->PCOR |=1<<register_num

#define OUTPUT_TOGGLE(port,register_num)			XOUTPUT_TOGGLE(port,register_num)
#define XOUTPUT_TOGGLE(port,register_num)			port->PTOR |=1<<register_num

#define READ_INPUT(port,port_pin)							XREAD_INPUT(port,port_pin)
#define XREAD_INPUT(port,port_pin)					(port->PDIR & GPIO_PDIR_PDI(1<<port_pin))	
                
/*******************************************************************************
* Types
********************************************************************************/


/*******************************************************************************
* Variables
********************************************************************************/


/*******************************************************************************
* Global Variables
********************************************************************************/

enum GPIOA_Register {
PTA0,	
PTA1,
PTA2,
PTA3,
PTA4,
PTA5,
PTA6,
PTA7,
PTB0,	
PTB1,
PTB2,
PTB3,
PTB4,
PTB5,
PTB6,
PTB7,
PTC0,	
PTC1,
PTC2,
PTC3,
PTC4,
PTC5,
PTC6,
PTC7,
PTD0,	
PTD1,
PTD2,
PTD3,
PTD4,
PTD5,
PTD6,
PTD7,
};

enum GPIOB_Register {
PTE0,	
PTE1,
PTE2,
PTE3,
PTE4,
PTE5,
PTE6,
PTE7,
PTF0,	
PTF1,
PTF2,
PTF3,
PTF4,
PTF5,
PTF6,
PTF7,
PTG0,	
PTG1,
PTG2,
PTG3,
PTG4,
PTG5,
PTG6,
PTG7,
PTH0,	
PTH1,
PTH2,
PTH3,
PTH4,
PTH5,
PTH6,
PTH7,
};

enum GPIOC_Register {
PTI0,	
PTI1,
PTI2,
PTI3,
PTI4,
PTI5,
PTI6,
};


/*******************************************************************************
* Global Functions
********************************************************************************/


#endif /* GPIO_H_ */
