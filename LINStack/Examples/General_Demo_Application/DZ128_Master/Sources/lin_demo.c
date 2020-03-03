#include "lin_demo.h"
#include "lin.h"

#define TIMER_PRESCALER   2
/* Init timer with period 2.5ms */
l_u8 timer_count = 0;
void rtc_int()
{
  RTCSC_RTCPS = 0x08;
  RTCSC_RTCLKS = 0x00;
  RTCMOD = 1;
  RTCSC_RTIE = 1;
}

/* Timer interrupt to periodically call LIN application*/
interrupt VectorNumber_Vrtc void rtc_isr()
{ 
    main_application_5ms();
    RTCSC_RTIF = 1;

}

/*LIN application to call schedule tick function */
void main_application_5ms(void){
  if (timer_count>=TIMER_PRESCALER){
    (void)l_sch_tick(LI0);
    /* Add more application code here ... */
    timer_count = 0;
  }
  timer_count++;
}