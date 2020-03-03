/*^^^^^^^^^^^^^^^^      LCD Configuration                        ^^^^^^^^^^^^^^^^^^^^^^^^*/
#define _LCDBACKPLANES                    (2)    // # of backplanes  

//#define _LCDCLKPSL                      (6)    //  Clock divider to generate the LCD Waveforms
#define _LCDCLKPSL                        (5)    //  Clock divider to generate the LCD Waveforms


#define _LCDCPSEL                         (1)    //0 -- Resistor network   1 -- Charge pump  
#define _LCDVSUPPLY                       (1)    //0  --  VLL2 from VDD    1 -- VLL3 from VDD  2 -- VLL1 from VLCD  3 -- VLL3 external or from VIREG

#define _LCDLOADADJUST                    (3)    //Charge Pump = 1       0 -- 8000 pf 1 -- 6000 pf  2 -- 4000 pf  3 -- 2000 pf
                                                 //Resistor network = 0  0 -- 2000 pf 1 -- 4000 pf  2 -- 8000 pf  3 -- 8000 pf 

#define _LCDFRAMEINTERRUPT                (0)    //0 Disabel  Interrupt 1 Enable aLCD interrupt that coincides with the LCD frame frequency

#define _LCDBLINKRATE                     LCD_BLINK_PERIOD_1HZ    //Blink frequecy preescaler  any number between 0-7

/*^^^^^^^^^^^^^^^^      LCD Hardware Connection 			 ^^^^^^^^^^^^^^^^^^^^^^^^*/
#define _CHARNUM                          (5)    // Number of alphanumerics on the custom glass
#define _LCDTYPE                          (4)    //Number of LCDWF  nedded  to drive one alphanumeric 

#define EnableLCDpins(RegNum,Mask)	      LCDPEN##RegNum = Mask
#define EnableBackplane(RegNum, LCDn)	    LCDBPEN##RegNum##_BPEN##LCDn  = 1    
#define SetBackplane(ComNum, LCDn)	      LCDWF##LCDn  = (1 <<  (##ComNum+ 4##)) | (1 <<  (##ComNum##))
#define CharacterPlace(LCDn)        			LCDWF##LCDn
#define MapSegment(BitNumber)  			      (1<<(##BitNumber##))
#define SymbolON(LCDn,BitNumber)          LCDWF##LCDn   |=  (1<<(BitNumber)) | (1<<(BitNumber + 4))
#define SymbolOFF(LCDn,BitNumber)         LCDWF##LCDn   &=  ~((1<<(BitNumber)) | (1<<(BitNumber + 4)))
//#define SymbolBlink(LCDn, BitNumber)      LCDWF##LCDn   ^=  (1<<BitNumber)
#define SymbolBlink(LCDn, BitNumber)      LCDWF##LCDn   &=  ~(1<<(BitNumber + 4))

/*Gives the properties to work like an LCD pin to the LCDn  connected  to the custom glass
param: RegNum -- Number of register to write     LCDpin --- LCDn pin number  that its connected example */
#define LCD_PEN0                              EnableLCDpins (0,255)
#define LCD_PEN1                              EnableLCDpins (1,255)
#define LCD_PEN2                              EnableLCDpins (2,255)
#define LCD_PEN3                              EnableLCDpins (3,63)

/* Enable the LCD pin like a Backplane functionality  
param: RegNum -- Number of register to write     LCDpin --- LCDn pin number that the Backplane it's connected */
#define   EnableCom1                      EnableBackplane (5, 40)
#define   EnableCom2                      EnableBackplane (5, 41)

/* Give the mask to the Backplane     
param: ComNum -- COM number     LCDpin --- LCDn number of pin that its connected example */

#define   SetCom1        SetBackplane (0, 40)
#define   SetCom2        SetBackplane (1, 41)

/* This macro defines the LDCWavefroms directions needed to write the Characters      
param:  LCDpin --- LCDn number of pin that its connected */
#define   Char1a        CharacterPlace (4)  // LCD Pin 5
#define   Char1b        CharacterPlace (5)  // LCD Pin 6
#define   Char1c        CharacterPlace (6)  // LCD Pin 7
#define   Char1d        CharacterPlace (7)  // LCD Pin 8
 
#define   Char2a        CharacterPlace (14)  // LCD Pin 10
#define   Char2b        CharacterPlace (15)  // LCD Pin 11
#define   Char2c        CharacterPlace (16)  // LCD Pin 12
#define   Char2d        CharacterPlace (17)  // LCD Pin 13
#define   Char3a        CharacterPlace (18)  // LCD Pin 14
 
 
#define   Char3b        CharacterPlace (21)  // LCD Pin 17
#define   Char3c        CharacterPlace (22)  // LCD Pin 18
#define   Char3d        CharacterPlace (23)  // LCD Pin 19
 
 
#define   Char4a        CharacterPlace (29)  // LCD Pin 25
#define   Char4b        CharacterPlace (28)  // LCD Pin 24
#define   Char4c        CharacterPlace (27)  // LCD Pin 23
#define   Char4d        CharacterPlace (26)  // LCD Pin 22
#define   Char5a        CharacterPlace (39)  // LCD Pin 28
#define   Char5b        CharacterPlace (38)  // LCD Pin 27
#define   Char5c        CharacterPlace (30)  // LCD Pin 26
#define   Char5d        CharacterPlace (26)  // LCD Pin 22

/* Define Waveforms used for the Symbols */

#define _LCD_MONDAY_WF 		  LCDWF0
#define _LCD_ONE_WF 			  LCDWF0
#define _LCD_BATTERY_WF 		LCDWF1
#define _LCD_BAT1_WF 			  LCDWF1
#define _LCD_BAT3_WF 			  LCDWF2
#define _LCD_BAT2_WF 			  LCDWF2
#define _LCD_BAT4_WF			  LCDWF3
#define _LCD_TUESDAY_WF 		LCDWF4
#define _LCD_WEDNESDAY_WF   LCDWF13
#define _LCD_COLON_WF       LCDWF13
#define _LCD_THURSDAY_WF 		LCDWF14
#define _LCD_FRIDAY_WF 			LCDWF18
#define _LCD_HEAT_WF 			  LCDWF19
#define _LCD_SATURDAY_WF 		LCDWF19
#define _LCD_COOL_WF 			  LCDWF20
#define _LCD_SUNDAY_WF 		  LCDWF20
#define _LCD_AM_WF 			    LCDWF24
#define _LCD_PM_WF 			    LCDWF24
#define _LCD_FLTR_WF 			  LCDWF25 
#define _LCD_HOLD_WF 			  LCDWF25

/* Define bit number to turn on the symbols */
#define _LCD_MONDAY_BIT_NUMBER 		  0
#define _LCD_ONE_BIT_NUMBER 			  1
#define _LCD_BATTERY_BIT_NUMBER 		0
#define _LCD_BAT1_BIT_NUMBER 			  1
#define _LCD_BAT3_BIT_NUMBER 			  0
#define _LCD_BAT2_BIT_NUMBER 			  1
#define _LCD_BAT4_BIT_NUMBER			  0
#define _LCD_TUESDAY_BIT_NUMBER 		0
#define _LCD_WEDNESDAY_BIT_NUMBER   0
#define _LCD_COLON_BIT_NUMBER       1
#define _LCD_THURSDAY_BIT_NUMBER 		0
#define _LCD_FRIDAY_BIT_NUMBER 			0
#define _LCD_HEAT_BIT_NUMBER 			  0
#define _LCD_SATURDAY_BIT_NUMBER 		1
#define _LCD_COOL_BIT_NUMBER 			  0
#define _LCD_SUNDAY_BIT_NUMBER 		  1
#define _LCD_AM_BIT_NUMBER 			    0
#define _LCD_PM_BIT_NUMBER 			    1
#define _LCD_FLTR_BIT_NUMBER 			  0
#define _LCD_HOLD_BIT_NUMBER 			  1


/* Turns on the  segment that its dedicated to write one Symbol     
param:  LCDpin --- LCDn number of pin that its connected   BitNumber -- COM Number that turns on that Symbol */
#define _LCD_MONDAY_ON SymbolON(0,0)
#define _LCD_BATTERY_ON SymbolON(1,0)
#define _LCD_BAT3_ON SymbolON(2,0)
#define _LCD_BAT4_ON SymbolON(3,0)
#define _LCD_TUESDAY_ON SymbolON(4,0)
#define _LCD_WEDNESDAY_ON SymbolON(13,0)
#define _LCD_THURSDAY_ON SymbolON(14,0)
#define _LCD_FRIDAY_ON SymbolON(18,0)
#define _LCD_COOL_ON SymbolON(19,0)
#define _LCD_HEAT_ON SymbolON(20,0)
#define _LCD_AM_ON SymbolON(24,0)
#define _LCD_FLTR_ON SymbolON(25,0)
#define _LCD_BAT1_ON SymbolON(1,1)
#define _LCD_BAT2_ON SymbolON(2,1)
#define _LCD_COLON_ON SymbolON(13,1)
#define _LCD_SATURDAY_ON SymbolON(19,1)
#define _LCD_SUNDAY_ON SymbolON(20,1)
#define _LCD_PM_ON SymbolON(24,1)
#define _LCD_HOLD_ON SymbolON(25,1)


/* Turns off the  segment   that its dedicated to write one Symbol     
param:  LCDpin --- LCDn number of pin that its connected   BitNumber -- COM Number that turns off that Symbol */
#define   _LCD_MONDAY_OFF        SymbolOFF(0,0)
#define   _LCD_BATTERY_OFF       SymbolOFF(1,0)
#define   _LCD_BAT3_OFF          SymbolOFF(2,0)
#define   _LCD_BAT4_OFF          SymbolOFF(3,0)
#define   _LCD_TUESDAY_OFF       SymbolOFF(4,0)
#define   _LCD_WEDNESDAY_OFF     SymbolOFF(13,0)
#define   _LCD_THURSDAY_OFF      SymbolOFF(14,0)
#define   _LCD_FRIDAY_OFF        SymbolOFF(18,0)
#define   _LCD_COOL_OFF          SymbolOFF(20,0)
#define   _LCD_HEAT_OFF          SymbolOFF(19,0)
#define   _LCD_AM_OFF            SymbolOFF(24,0)
#define   _LCD_FLTR_OFF          SymbolOFF(25,0)
#define   _LCD_BAT1_OFF          SymbolOFF(1,1)
#define   _LCD_BAT2_OFF          SymbolOFF(2,1)
#define   _LCD_COLON_OFF         SymbolOFF(13,1)
#define   _LCD_SATURDAY_OFF      SymbolOFF(19,1)
#define   _LCD_SUNDAY_OFF        SymbolOFF(20,1)
#define   _LCD_PM_OFF            SymbolOFF(24,1)
#define   _LCD_HOLD_OFF          SymbolOFF(25,1)

/* Blinks the  segment that its dedicated to write one Symbol     
param:  LCDpin --- LCDn number of pin that its connected   BitNumber -- COM Number that will Blink off that Symbol */
#define   _LCD_MONDAY_Blink 		SymbolBlink(0,0)
#define   _LCD_ONE_Blink 			  SymbolBlink(0,1)
#define   _LCD_BATTERY_Blink 		SymbolBlink(1,0)
#define   _LCD_BAT1_Blink		 	  SymbolBlink(1,1)
#define   _LCD_BAT3_Blink 			SymbolBlink(2,0)
#define   _LCD_BAT2_Blink 			SymbolBlink(2,1)
#define   _LCD_BAT4_Blink 			SymbolBlink(3,0)
#define   _LCD_TUESDAY_Blink 		SymbolBlink(4,0)
#define   _LCD_WEDNESDAY_Blink  SymbolBlink(13,0)
#define   _LCD_COLON_Blink      SymbolBlink(13,1)
#define   _LCD_THURSDAY_Blink 	SymbolBlink(14,0)
#define   _LCD_FRIDAY_Blink 		SymbolBlink(18,0)
#define   _LCD_HEAT_Blink 			SymbolBlink(19,0)
#define   _LCD_SATURDAY_Blink 	SymbolBlink(19,1)
#define   _LCD_COOL_Blink 			SymbolBlink(20,0)
#define   _LCD_SUNDAY_Blink 		SymbolBlink(20,1)
#define   _LCD_AM_Blink 			  SymbolBlink(24,0)
#define   _LCD_PM_Blink 			  SymbolBlink(24,1)
#define   _LCD_FLTR_Blink 			SymbolBlink(25,0)
#define   _LCD_HOLD_Blink 			SymbolBlink(25,1)

/*Give the apropiate mask to set one segment of the display
param: BitNumber  -- Number of bit that needs to be turn on*/ 
#define  SEG1         MapSegment (0)
#define  SEG2         MapSegment (1)
#define  SEG5         MapSegment (4)
#define  SEG6         MapSegment (5)
    
#define SEGA		SEG2
#define SEGB		SEG1
#define SEGC		SEG1
#define SEGD		SEG1
#define SEGD2		SEG2
#define SEGE		SEG2
#define SEGF    SEG2
#define SEGG		SEG2
      
 /*All segments ON */
#define WF0ON  		( LCDWF0 = 3 )
#define WF1ON 		( LCDWF1 = 3 )
#define WF2ON 		( LCDWF2 = 3 )
#define WF3ON 		( LCDWF3 = 3 )
#define WF4ON 		( LCDWF4 = 3 )
#define WF5ON 		( LCDWF5 = 3 )
#define WF6ON 		( LCDWF6 = 3 )
#define WF7ON 		( LCDWF7 = 3 )
#define WF13ON		( LCDWF13 = 3 )
#define WF14ON		( LCDWF14 = 3 )
#define WF15ON		( LCDWF15 = 3 )
#define WF16ON		( LCDWF16 = 3 )
#define WF17ON		( LCDWF17 = 3 )
#define WF18ON		( LCDWF18 = 3 )
#define WF19ON		( LCDWF19 = 3 )
#define WF20ON		( LCDWF20 = 3 )
#define WF21ON		( LCDWF21 = 3 )
#define WF22ON		( LCDWF22 = 3 )
#define WF23ON		( LCDWF23 = 3 )
#define WF24ON		( LCDWF24 = 3 )
#define WF25ON		( LCDWF25 = 3 )
#define WF26ON		( LCDWF26 = 3 )
#define WF27ON		( LCDWF27 = 3 )
#define WF28ON		( LCDWF28 = 3 )
#define WF29ON		( LCDWF29 = 3 )
#define WF30ON		( LCDWF30 = 3 )
#define WF38ON		( LCDWF38 = 3 )
#define WF39ON		( LCDWF39 = 3 )

 /*All segments OFF */
#define WF0OFF		( LCDWF0 = 0)
#define WF1OFF		( LCDWF1 = 0 )
#define WF2OFF		( LCDWF2 = 0 )
#define WF3OFF		( LCDWF3 = 0 )
#define WF4OFF		( LCDWF4 = 0 )
#define WF5OFF		( LCDWF5 = 0)
#define WF6OFF		( LCDWF6 = 0 )
#define WF7OFF		( LCDWF7 = 0 )
#define WF13OFF		( LCDWF13= 0 )
#define WF14OFF		( LCDWF14= 0 )
#define WF15OFF		( LCDWF15 = 0 )
#define WF16OFF		( LCDWF16 = 0 )
#define WF17OFF		( LCDWF17 = 0 )
#define WF18OFF		( LCDWF18 = 0 )
#define WF19OFF		( LCDWF19 = 0 )
#define WF20OFF		( LCDWF20 = 0 )
#define WF21OFF		( LCDWF21 = 0 )
#define WF22OFF		( LCDWF22 = 0 )
#define WF23OFF		( LCDWF23 = 0 )
#define WF24OFF		( LCDWF24 = 0 )
#define WF25OFF		( LCDWF25 = 0)
#define WF26OFF		( LCDWF26 = 0 )
#define WF27OFF		( LCDWF27 = 0 )
#define WF28OFF		( LCDWF28 = 0 )
#define WF29OFF		( LCDWF29 = 0 )
#define WF30OFF		( LCDWF30 = 0 )
#define WF38OFF		( LCDWF38 = 0 )
#define WF39OFF		( LCDWF39 = 0 )

#define   _LCD_Char1a_OFF SymbolOFF(4,1)
#define   _LCD_Time1_OFF SymbolOFF(0,1)
#define   _LCD_Char1f_OFF SymbolOFF(5,1)
#define   _LCD_Char1g_OFF SymbolOFF(6,1)
#define   _LCD_Char1b_OFF SymbolOFF(5,0)
#define   _LCD_Char1c_OFF SymbolOFF(6,0)
#define   _LCD_Char1d_OFF SymbolOFF(7,0)
#define   _LCD_Char1e_OFF SymbolOFF(7,1)
#define   _LCD_Char2a_OFF SymbolOFF(14,1)
#define   _LCD_Char2b_OFF SymbolOFF(15,0)
#define   _LCD_Char2c_OFF SymbolOFF(16,0)
#define   _LCD_Char2c_OFF SymbolOFF(16,0)
#define   _LCD_Char2d_OFF SymbolOFF(17,0)
#define   _LCD_Char2e_OFF SymbolOFF(17,1)
#define   _LCD_Char2f_OFF SymbolOFF(15,1)
#define   _LCD_Char2g_OFF SymbolOFF(16,1)
#define   _LCD_Char3a_OFF SymbolOFF(18,1)
#define   _LCD_Char3b_OFF SymbolOFF(21,0)
#define   _LCD_Char3c_OFF SymbolOFF(22,0)
#define   _LCD_Char3d_OFF SymbolOFF(23,0)
#define   _LCD_Char3e_OFF SymbolOFF(23,1)
#define   _LCD_Chra3f_OFF SymbolOFF(21,1)
#define   _LCD_Char3g_OFF SymbolOFF(22,1)
#define   _LCD_Char4a_OFF SymbolOFF(29,0)
#define   _LCD_Char4b_OFF SymbolOFF(29,1)
#define   _LCD_Char4c_OFF SymbolOFF(27,1)
#define   _LCD_Char4d_OFF SymbolOFF(26,0)
#define   _LCD_Char4e_OFF SymbolOFF(27,0)
#define   _LCD_Char4f_OFF SymbolOFF(28,0)
#define   _LCD_Char4g_OFF SymbolOFF(28,1)
#define   _LCD_Char5a_OFF SymbolOFF(39,0)
#define   _LCD_Char5b_OFF SymbolOFF(39,1)
#define   _LCD_Char5c_OFF SymbolOFF(30,1)
#define   _LCD_Char5d_OFF SymbolOFF(26,1)
#define   _LCD_Char5e_OFF SymbolOFF(30,0)
#define   _LCD_Char5f_OFF SymbolOFF(38,0)
#define   _LCD_Char5g_OFF SymbolOFF(38,1)

#define _LCD_Char1a_ON SymbolON(4,1)
#define _LCD_Time1_ON SymbolON(0,1)
#define _LCD_Char1f_ON SymbolON(5,1)
#define _LCD_Char1g_ON SymbolON(6,1)
#define _LCD_Char1b_ON SymbolON(5,0)
#define _LCD_Char1c_ON SymbolON(6,0)
#define _LCD_Char1d_ON SymbolON(7,0)
#define _LCD_Char1e_ON SymbolON(7,1)
#define _LCD_Char2a_ON SymbolON(14,1)
#define _LCD_Char2b_ON SymbolON(15,0)
#define _LCD_Char2c_ON SymbolON(16,0)
#define _LCD_Char2d_ON SymbolON(17,0)
#define _LCD_Char2e_ON SymbolON(17,1)
#define _LCD_Char2f_ON SymbolON(15,1)
#define _LCD_Char2g_ON SymbolON(16,1)
#define _LCD_Char3a_ON SymbolON(18,1)
#define _LCD_Char3b_ON SymbolON(21,0)
#define _LCD_Char3c_ON SymbolON(22,0)
#define _LCD_Char3d_ON SymbolON(23,0)
#define _LCD_Char3e_ON SymbolON(23,1)
#define _LCD_Chra3f_ON SymbolON(21,1)
#define _LCD_Char3g_ON SymbolON(22,1)
#define _LCD_Char4a_ON SymbolON(29,0)
#define _LCD_Char4b_ON SymbolON(29,1)
#define _LCD_Char4c_ON SymbolON(27,1)
#define _LCD_Char4d_ON SymbolON(26,0)
#define _LCD_Char4e_ON SymbolON(27,0)
#define _LCD_Char4f_ON SymbolON(28,0)
#define _LCD_Char4g_ON SymbolON(28,1)
#define _LCD_Char5a_ON SymbolON(39,0)
#define _LCD_Char5b_ON SymbolON(39,1)
#define _LCD_Char5c_ON SymbolON(30,1)
#define _LCD_Char5d_ON SymbolON(26,1)
#define _LCD_Char5e_ON SymbolON(30,0)
#define _LCD_Char5f_ON SymbolON(38,0)
#define _LCD_Char5g_ON SymbolON(38,1)

