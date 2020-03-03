#include "lin_demo.h"

void init_demo(void)
{
  /* configure LED */
  PTCDD = 0x03;
  PTCD_PTCD0 = OFF;
  PTCD_PTCD1 = OFF;
  
  /* configure PTA2 and PTA3 as SW1 and SW2 */
  PTADD_PTADD2 = 0x0;
  PTADD_PTADD3 = 0x0;
  PTAPE_PTAPE2 = 0x1;
  PTAPE_PTAPE3 = 0x1;  
}

void adc_init()
{
  /* select channel 1 */
  ADCCFG = 0;
  APCTL1 = 0x03;
  ADCSC2 = 0x10;
  ADCSC1 = 0x20;
}