/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2009 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup demo_application_for_diagnostic
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      mcu_init.h
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Dec-24-2009 
*
* @brief     initialization function for HY64 MCU
*
******************************************************************************/

#ifndef _mcu_init
#define _mcu_init

#define SW1						PT1AD_PT1AD4
#define SW2						PT1AD_PT1AD5
#define SW3						PT1AD_PT1AD6
#define SW4						PT1AD_PT1AD7

#define LED1					PTR_PTR0
#define LED2					PTR_PTR1
#define LED3					PTR_PTR2
#define LED4					PTR_PTR3

#define ON            0x01
#define OFF           0x00

#define ALL_FULL_DRIVE		0x00   
#define ALL_REDUCED_DRIVE	0xFF
#define ALL_PULLS_OFF		  0x00
#define ALL_PULLS_ON			0xFF
#define ALL_PULLED_UP		  0x00   
#define ALL_PULLED_DOWN		0xFF
#define ALL_INPUTS			  0x00
#define ALL_OUTPUTS			  0xFF	
#define ALL_LOW				    0x00
#define ALL_HIGH				  0xFF

#define KEY_WAKEUP_EN()			ATDDIEN	= 0xF0	 /* enable PT1AD[7:4] as digital input */
#define KEY_WAKEUP_DISABLE()    ATDDIEN	&= 0x0F


typedef unsigned char   tU08;   /**< unsigned 8 bit definition */

/**
* @var typedef unsigned char tU16
* unsigned 16 bits definition
*/
typedef unsigned short    tU16;   /**< unsigned 16 bit definition */

/**
* @var typedef unsigned long tU32
* unsigned 32 bits definition
*/
typedef unsigned long   tU32;   /**< unsigned 32 bit definition */

/**
* @var typedef unsigned char tS08
* signed 32 bits definition
*/
typedef signed char     tS08;   /**< signed 8 bit definition */

/**
* @var typedef signed int      tS16
* signed 16 bits definition
*/
typedef signed short      tS16;   /**< signed 16 bit definition */

/**
* @var typedef signed long      tS32
* signed 32 bits definition
*/
typedef signed long     tS32;   /**< signed 32 bit definition */

typedef void (*PT2FUNCTION_DEF)(void);  

void port_config(void);
void clk_init(void);
/* void ADC_config(void); not implemented */
void TIM1_init(void);
void init_atd_ch0(void);
void kbi_isr_func(void);
void update_signal(void);
unsigned char read_atd_ch0(void);
void state_machine(void);
#endif
/**
* @}
*/