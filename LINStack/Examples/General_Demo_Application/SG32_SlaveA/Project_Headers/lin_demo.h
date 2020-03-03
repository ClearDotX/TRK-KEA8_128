#ifndef _LIN_DEMO_H_
#define _LIN_DEMO_H_

#include "MC9S08SG32.h"

/* Define for LED */
#define LED1 PTCD_PTCD0
#define LED2 PTCD_PTCD1
#define ON   0x00
#define OFF  0x01   

/* Define for Switch */
#define SW1 PTAD_PTAD2
#define SW2 PTAD_PTAD3

void init_demo(void);
void adc_init(void);

#endif /* End _LIN_DEMO_H_ */