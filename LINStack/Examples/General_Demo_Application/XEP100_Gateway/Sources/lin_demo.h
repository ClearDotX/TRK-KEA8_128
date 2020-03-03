#ifndef _LIN_DEMO_H_
#define _LIN_DEMO_H_

#include <MC9S12XEP100.h>

#define LED1					PORTB_PB0
#define LED2					PORTB_PB1
#define LED3					PORTB_PB2
#define LED4					PORTB_PB3

#define ON            1
#define OFF           0

#define SW1           PORTB_PB4
#define SW2           PORTB_PB5
#define SW3           PORTB_PB6
#define SW4           PORTB_PB7

void init_demo(void);
void tim_init(void);
void init_sci6(void);
void free_counter_init(void);
void freecntr_enable(void);
void freecntr_disable(void);
#endif