#include "lin_demo.h"

void init_demo()
{
  /*Configue for Switch */  
  PTADD = 0x00;
  PTAPE = 0xF0;
  
  /* Configue for LED */
  PTADD_PTADD3 = 1;
  PTCDD_PTCDD0 = 1;
  
  PTDDD_PTDDD0 = 1;
  PTDDD_PTDDD1 = 1;
  PTDDD_PTDDD2 = 1;
  PTDDD_PTDDD3 = 1;
  PTDDD_PTDDD4 = 1;
  
  LED1 = OFF;
  LED2 = OFF;
}

void adc_init()
{
  /* select channel 1 */
  ADCCFG = 0;
  APCTL1 = 0x03;
  ADCSC2 = 0x10;
  ADCSC1 = 0x21;
}