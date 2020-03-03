#include "led_matrix.h"
#include <MC9S12XEP100.h>

const unsigned char LED_Table[16][5] = {
  0x3E, 0x45, 0x49, 0x51, 0x3E,       // 0
  0x00, 0x21, 0x7F, 0x01, 0x00,       // 1
  0x21, 0x43, 0x45, 0x49, 0x31,       // 2
  0x42, 0x41, 0x51, 0x69, 0x46,       // 3
  0x0C, 0x14, 0x24, 0x7F, 0x04,       // 4
  0x72, 0x51, 0x51, 0x51, 0x4E,       // 5
  0x1E, 0x29, 0x49, 0x49, 0x06,       // 6
  0x40, 0x47, 0x48, 0x50, 0x60,       // 7
  0x36, 0x49, 0x49, 0x49, 0x36,       // 8
  0x30, 0x49, 0x49, 0x4A, 0x3C,       // 9
  0x3F, 0x44, 0x44, 0x44, 0x3F,       // A
  0x7F, 0x49, 0x49, 0x49, 0x36,       // B
  0x3E, 0x41, 0x41, 0x41, 0x22,       // C
  0x7F, 0x41, 0x41, 0x22, 0x1C,       // D
  0x7F, 0x49, 0x49, 0x49, 0x41,       // E
  0x7F, 0x48, 0x48, 0x48, 0x40        // F
};

const unsigned char led[5] ={0xEF, 0xF7, 0xFB, 0xFD, 0xFE};

void led_matrix_init()
{
  PORTA = 0x7F;
  PORTC = 0x00;
  PORTD = 0x00;
  
  DDRA = 0x7F;
  DDRC = 0x1F;
  DDRD = 0x1F;
}

void display_digit(unsigned char val)
{
  unsigned char i, val_high, val_low;
  unsigned int j;
  val_high = val >> 4;
  val_low = val & 0x0F;
   
   for(i=0; i<10; i++){ /* display data to Led Matrix */
      PORTA = 0x00;
      if(i<=4) {
          PORTC = 0xFF;
          PORTD = led[i];
          PORTA = LED_Table[val_high][i];
      } else {
          PORTD = 0xFF;
          PORTC = led[i-5];
          PORTA = LED_Table[val_low][i-5];
      }              
      for(j=0;j<650;j++){;}            
   } /* end for */
}

/* End of file */