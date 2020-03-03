#ifndef __LCD_GD5360P__
  #define __LCD_GD5360P__

  #include "GD5360P.h"
  #include "FslTypes.h"
  #include "derivative.h" /* include peripheral declarations */
  #include "PE_Types.h"
  #include "PE_Error.h"
  #include "PE_Const.h"
    
  /*~|~|~|~|~|~|~|~|~|~|~|~|~|~  LCD  Control Register 0  ~|~|~|~|~|~|~|~|~|~|~|~|~*/
  /*~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|*/

  #define _LCDENABLE           (0)                 //0 All frontplanes and backplanes are disable
                                                   //1 LCD module is enable
  #define _LCDCLKSOURCE        (0)                 // 0 -- External clock       1 --  Alternate clock
  #define  _LCDDUTY            (_LCDBACKPLANES-1)  //# of Backplanes 

  /*~|~|~|~|~|~|~|~|~|~|~|~|~|~  LCD  Control Register 1  ~|~|~|~|~|~|~|~|~|~|~|~|~|*/
  /*~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|*/
  #define _LCDFULLCPLDIRIVE       (0)     // 0 GPIO shared with the LCD. Inputs levels and internal pullup reference to VDD
                                          // 1 If VSUPPLY=11and RVEN=0. Inputs levels and internal pullup reference to VLL3
  #define _LCDWAITMODE            (0)     // 0 Allows the LCD driver and charge pump to conitnue running during wait mode
                                          // 1 Disable the LCD when the MCU goes into wait mode
  #define _LCDSTOPMODE            (0)     // 0 Allows the LCD driver and charge pump to conitnue running during stop2 or stop3
                                          // 1 Disable the LCD when and charge pump when the MCU goes into stop2 or stop3                                                               

  /*~|~|~|~|~|~|~|~|~|~|~|~|~|~  LCD  Voltage Supply Register  ~|~|~|~|~|~|~|~|~|~|~|~*/
  /*~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|*/
  #define _LCDHIGHREF              (0)      //0 Divide input VIREG=1.0v
                                            //1 Do not divide the input VIREG=1.67v
  #define _LCDBBYPASS              (1)      //Determines wheter the internal LCD op amp buffer is bypassed
                                            //0 Buffered mode
                                            //1 Unbuffered mode
                              
  /*~|~|~|~|~|~|~|~|~|~|~|~|~|~  LCD  Regulated Voltage Control |~|~|~|~|~|~|~|~|~|~*/
  /*~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|*/
  //#define _LCDCONTRAST             (1)       //Contrast by software   0 -- Disable    1-- Enable
  #define _LCDCONTRAST             (0)       //Contrast by software   0 -- Disable    1-- Enable
  #define _LVLCONTRAST             (0)       //Any number between 0  and 15, if the number is bigger the glass get darker

  /*~|~|~|~|~|~|~|~|~|~|~|~|~|~  LCD  Blink Control Register ~|~|~|~|~|~|~|~|~|~|~|~*/
  /*~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|*/
  #define _LCDBLINKCONTROL         (1)  //0 Disable blink mode
                                        //1 Enable blink mode
  #define _LCDALTMODE              (0)  //0 Normal display 
                                        //1 Alternate display for 4 backplanes or less the LCD backplane sequencer changes to otuput an alternate display
  #define _LCDBLANKDISP            (0)  //0 Do not blank display
                                        //1 Blank display if you put it in 0 the text before blank is manteined     
  #define _LCDBLINKMODE            (1)  //0 Display blank during the blink period 
                                        //1 Display alternate displat during blink period (Ignored if duty is 5 or greater)
  
  #define _LCDBLINKPERIOD          LCD_BLINK_PERIOD_1HZ


  /*{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{        Macros            }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}*/
  /*{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{   ----------------------------  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}*/
  #define LCDBCTL_INIT       (LCDBCTL = (_LCDBLINKCONTROL<<7) | (_LCDALTMODE<<6) | (_LCDBLANKDISP<<5)  | (_LCDBLINKMODE<<3) | (_LCDBLINKPERIOD))  
  #define LCDC1_INIT         (LCDC1 = (_LCDFRAMEINTERRUPT<<7) | (_LCDFULLCPLDIRIVE<<2)   | (_LCDWAITMODE<<1) | (_LCDSTOPMODE) )
  #define LCDRVC_INIT        (LCDRVC= (_LCDCONTRAST<<7) |   (_LVLCONTRAST))    
  //#define LCDSUPPLY_INIT     (LCDSUPPLY = (_LCDCPSEL<<7)  | (_LCDHIGHREF<<6)   | (_LCDLOADADJUST<<5) | (_LCDBBYPASS<<2)  | (_LCDVSUPPLY)) 
  #define LCDSUPPLY_INIT     (LCDSUPPLY = (_LCDCPSEL<<7)  | (_LCDHIGHREF<<6)   | (_LCDLOADADJUST<<4) | (_LCDBBYPASS<<2)  | (_LCDVSUPPLY)) 
  #define LCDC0_INIT         (LCDC0 = (_LCDENABLE<<7) | (_LCDCLKSOURCE<<6) | (_LCDCLKPSL<<3) | (_LCDDUTY))  
  #define LCDENABLE          (LCDC0_LCDEN=1)
  #define LCDDISABLE         (LCDC0_LCDEN=0)
  /*{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{        Functions        }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}*/
  /*{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{   ----------------------------  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}*/
  #define LCD_SET_CURSOR(x)  bLCD_CharPosition = x*_LCDTYPE     
  
  #define LCD_BLINK_PERIOD_8HZ       0
  #define LCD_BLINK_PERIOD_4HZ       1
  #define LCD_BLINK_PERIOD_2HZ       2
  #define LCD_BLINK_PERIOD_1HZ       3
  #define LCD_BLINK_PERIOD_0_5HZ     4
  #define LCD_BLINK_PERIOD_0_25HZ    5
  #define LCD_BLINK_PERIOD_0_13HZ    6
  #define LCD_BLINK_PERIOD_0_06HZ    7
  
  
  #define vfnLCD_SetBlink(Period)    LCDBCTL = LCDBCTL_BLINK_MASK | LCDBCTL_BMODE_MASK | Period
  #define vfnLCD_DisableBlink        LCDBCTL = 0

  /*||||||||||||||||||||||       vfnLCD_Init            ||||||||||||||||||||||
  brief:  Initialize all the registers on the mcu module 
  param:  void                            return:  void    						*/  
  void vfnLCD_Init  (void);

  /*||||||||||||||||||||||       vfnLCD_EnablePins   ||||||||||||||||||||
  brief: Enable all the pins of the mcu directly connected to the  LCD on use
  param:  void                            return:  void    						*/  
  void vfnEnablePins (void);

   /*||||||||||||||||||||||       vfnLCD_Enab leBackplanes ||||||||||||||
  brief: Enable the function of Backplane in the pin
  param:  void                            return:  void     						*/  
  void vfnEnableBackplanes (void);

  /*||||||||||||||||||||||       vfnLCD_Home            ||||||||||||||||||||||
  brief:  Reset the counter to the first position
  */  
  void vfnLCD_Home (void);

   /*||||||||||||||||||||||       vfnLCD_Write_Char   ||||||||||||||||||||||
  brief:  Writes one char after the last character was write
  param:  UINT8 --- Ascii to write                            return:  void    
  */
  void vfnLCD_Write_Char (unsigned char lbValue);


   /*||||||||||||||||||||||       vfnLCD_Write_Msg    ||||||||||||||||||||||
  brief:  Writes one message on the LCD   if the message is longer than the number of character  is send to the Scroll function
  param:  pointer to UINT8  --- the first character  on the array to write
  param: UINT8 --- the numbers of characterts to write      				
  return:  void    													*/
  void  vfnLCD_Write_Msg (unsigned char *lbpMessage, unsigned char lbSize );
  
  /*||||||||||||||||||||||       vfnLCD_WriteAlternateMsg    ||||||||||||||||||||||
  brief:  Writes one message on alternate LCD waveforms (use for blink mode); if the message is longer than the number of character  is send to the Scroll function
  param:  pointer to UINT8  --- the first character  on the array to write
  param: UINT8 --- the numbers of characterts to write      				
  return:  void    													*/
  void vfnLCD_ClearAlternateMsg(unsigned char lbSize);
   

   /*||||||||||||||||||||||       vfnLCD_All_Segments_ON   ||||||||||||||||||||||
  brief: sequences through Turning on all the segments on the LCD  on for a bit then off
  return:  void    
  */ 
  void vfnLCD_Step_All_Segments (unsigned char count) ;
  
   /*||||||||||||||||||||||       vfnLCD_All_Segments_ON   ||||||||||||||||||||||
  brief: Turns on all the segments on the LCD
  param:  UINT8 pointer --- the first character  on the array to write
  param: UINT8 --- the size of the character  
  return:  void    
  */
  void vfnLCD_All_Segments_ON (void);
  
   /*||||||||||||||||||||||       vfnLCD_All_Segments_OFF   ||||||||||||||||||||||
  brief: Turns off all the segments on the LCD
  param:  byte pointer --- the first character  on the array to write
  param: byte --- the size of the character  
  return:  void    
  */
  void vfnLCD_All_Segments_OFF (void);
 
  /* ||||||||||||||||||||||       SetAlpha                  ||||||||||||||||||||||
  brief: Set the alpha/numeric character on the display
  param:  byte pointer to the charater to write to
  param: data to be displayed in ASCII 
  return:  void
  */
 
  void SetAlpha(char alphanum, char data);
  
  /* ||||||||||||||||||||||       SetNumber                  ||||||||||||||||||||||
  brief: Set the numeric character on the display
  param:  byte pointer to the charater to write to
  param: data to be displayed in ASCII 
  return:  void
  */
 
  void SetNumber(char order, unsigned char data);

  extern unsigned char bLCD_CharPosition; 

#endif