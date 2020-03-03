#ifndef _LIN_DEMO_H_
#define _LIN_DEMO_H_

#include <MC9S08DZ128.h>

#define LED1 PTAD_PTAD3
#define LED2 PTCD_PTCD0

#define LED3 PTDD_PTDD0
#define LED4 PTDD_PTDD1
#define LED5 PTDD_PTDD2
#define LED6 PTDD_PTDD3
#define LED7 PTDD_PTDD4

#define ON    0x00
#define OFF   0x01

void init_demo(void);
void adc_init(void);

#endif