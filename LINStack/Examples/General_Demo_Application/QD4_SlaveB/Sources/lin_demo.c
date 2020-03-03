#include "lin_demo.h"
#include <MC9S08QD4.h>

void init_demo()
{
    /** KBI Set Up foe SW1 & SW2 */
  KBIPE_KBIPE2 =1; /* Enable Keyboard Pin */                                  
  KBIPE_KBIPE3 =1; /* Enable Keyboard Pin */                                  

  
  KBISC_KBIE =  1;  /* Enable Keyboard Interrupts */
  KBISC_KBACK = 1;  /* Clear Pending Keyboard Interrupts */
  
  PTAPE_PTAPE2 = 1; /* Enable Pullup for Keyboard pin */
  
  PTADD_PTADD3 = 1;
}

void init_adc()
{
  /* select channel 1 */
  ADCCFG = 0;
  APCTL1 = 0x01;
  ADCSC2 = 0x10;
  ADCSC1 = 0x20;
}