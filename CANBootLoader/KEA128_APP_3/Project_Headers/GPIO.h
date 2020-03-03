/*
 * GPIO.h
 *
 *  Created on: Sep 24, 2013
 *      Author: B46911
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "derivative.h"

#define PORT_A  A
#define PORT_B  A
#define PORT_C  A
#define PORT_D  A

#define PORT_E	B
#define PORT_F	B
#define PORT_G	B
#define PORT_H	B


#define OUTPUT  1
#define INPUT	0

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

#endif /* GPIO_H_ */
