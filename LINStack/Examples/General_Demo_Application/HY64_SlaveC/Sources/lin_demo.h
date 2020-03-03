#ifndef _LIN_DEMO_H_
#define _LIN_DEMO_H_

#include <mc9s12hy64.h>

#define SW1      PT1AD_PT1AD4
#define SW2      PT1AD_PT1AD5
#define SW3      PT1AD_PT1AD6
#define SW4      PT1AD_PT1AD7

#define LED1					PTR_PTR0
#define LED2					PTR_PTR1
#define LED3					PTR_PTR2
#define LED4					PTR_PTR3

#define OFF		1
#define ON		0

void init_demo(void);
void init_atd_ch0(void);

#endif