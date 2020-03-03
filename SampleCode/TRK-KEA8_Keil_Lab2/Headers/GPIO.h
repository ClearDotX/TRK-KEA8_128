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


#define OUTPUT  1
#define INPUT	0

#define CONFIG_PIN_AS_GPIO(port,register_number,mode)    XCONFIG_PIN_AS_GPIO(port,register_number,mode)
#define XCONFIG_PIN_AS_GPIO(port,register_number,mode)   (mode == 0) ? (port->PDDR |= 0 << register_number) : (port->PDDR |= 1 << register_number) 

#define ENABLE_INPUT(port,pin_number) 					XENABLE_INPUT(port,pin_number)
#define XENABLE_INPUT(port,pin_number)					port->PIDR ^= 1<<pin_number

#define ENABLE_PULLUP(port,pin_number) 					XENABLE_PULLUP(port,pin_number) 	
#define XENABLE_PULLUP(port,pin_number) 				PORT->PUEL |= 1<<pin_number

#define OUTPUT_SET(port,register_num)					XOUTPUT_SET(port,register_num)
#define XOUTPUT_SET(port,register_num)				port->PSOR |=1<<register_num

#define OUTPUT_CLEAR(port,register_num)				XOUTPUT_CLEAR(port,register_num)		
#define XOUTPUT_CLEAR(port,register_num)			port->PCOR |=1<<register_num

#define OUTPUT_TOGGLE(port,register_num)			XOUTPUT_TOGGLE(port,register_num)
#define XOUTPUT_TOGGLE(port,register_num)			port->PTOR |=1<<register_num

#define READ_INPUT(port,port_pin)							XREAD_INPUT(port,port_pin)
#define XREAD_INPUT(port,port_pin)					  (port->PDIR & GPIO_PDIR_PDI(1<<port_pin))
                
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
PTC5
};

/*******************************************************************************
* Global Functions
********************************************************************************/


#endif /* GPIO_H_ */
