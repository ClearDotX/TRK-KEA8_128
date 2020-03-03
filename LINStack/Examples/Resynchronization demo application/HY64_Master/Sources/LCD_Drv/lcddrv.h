/************************************************************

Filename : lcddrv.h

Description: LCD driver header file defining external
             function and structure prototypes.
Purpose: This file is to be used in conjuction with 
         the LCD low level driver.  File should be 
         included in and compiled with the LCD application
         program
*************************************************************/
#include "mcu_init.h"
#include "GD-5506P_DEMO9S12HY64.h"
#include "LCD_digit_display_defines.h"

//=====================
//Constant Variables
//======================
//Glass paramters
#define	NUMALPASEGS_ONGLASS		9
#define	NUMREGSPERSEG_ONGLASS	2		//register per segment
#define	NUMRAMREGS_FORGLASS		20		//register per segment
#define	LCD_ALPNUM_SETMASK		0x37


//Labels
#define SEGONOFF		OFF
#define SEGBLINKEN	ON

//===========================
//LCD power configuration
//===========================
#define LCDPWR_VDD    1
#define LCDPWR_VLCD   0
#define LCDPWR_VLLLN  0

//===========================
// DIGIT VALUE DISPLAY
//===========================

#define DIGIT_OFF			0xFF
#define DIGIT_DASH		0xFE
#define DIGIT_0				0x00
#define DIGIT_1				0x01
#define DIGIT_2				0x02
#define DIGIT_3				0x03
#define DIGIT_4				0x04
#define DIGIT_5				0x05
#define DIGIT_6				0x06
#define DIGIT_7				0x07
#define DIGIT_8				0x08
#define DIGIT_9				0x09
#define DIGIT_A				0x0A
#define DIGIT_B				0x0B
#define DIGIT_C 			0x0C
#define DIGIT_D				0x0D
#define DIGIT_E				0x0E
#define DIGIT_F				0x0F


#if  LCDPWR_VLCD
    //configure mode 
    #define DOUBLERMODE    0		//typical for 3V glass
    #define TRIPLERMODE    1		//typical for 3V glass
    
    //Buffer mode setting if using TRIPLERMODE and LCDPWR_VLCD
    #if		TRIPLERMODE
      #define LCDBUFFERSTATE	ON//OFF//     
		#endif 
#endif

#if  LCDPWR_VDD 
    #define VDDTOVLL2_2V		0		//need nominal VDD=2V; 3V LCD glass; doubler mode = LCDCPMS=0
    
    #define VDDTOVLL2_3D3V		1		//need nominal VDD=3.3V; 5V LCD glass; tripler mode = LCDCPMS=1
    #define VDDTOVLL3_3V		0		//need nominal VDD=3V; 3V LCD glass; doubler mode = LCDCPMS=0
    
#endif

//===========================
//Define LCD duty cycle 
//===========================

//#define D1B1		1
//#define D2B2		1
//#define D2B3		1
#define D4B3		1


//===========================
//Define Blink Rate 
//===========================
#define BLINKFACTOR    2        // Not used...
#define BLINKALLSEGQ  NO        // Not used...

//===========================
// LCD interrupt
//===========================
#define LCDINTEN ON             // Not used
 
//===========================
// LCD low power modes
//===========================
#define LCDINSTP3   ON          // not used
#define LCDINWAIT   OFF

//===========================
// Function Prototypes
//===========================
void	LCD_Init(void);
void	Enable_LCD(byte);
void	LCD_RAM_Set_All(void)  ;
void	LCD_RAM_Clear_All(void); 

void	Set_Logo(byte logo, byte pn, byte name, byte body, byte tentacles); 
void	Set_Volt_Bar(byte v, byte numbars); 

void	Set_Temp_Bar(byte t, byte numbars);
void	Set_Temp_Segs(enum t_temp_type temp_types, enum t_temp_scale temp_scales, char col4);
void	Set_Temp_Digits(word temp_value);

void	Set_Compass(byte t, enum t_compass_direction directions);
void	Set_Odo_Digits(unsigned int odo_value);
void	Set_Gear(char t, enum t_transmission_gear gears);


void	Fuel_Clk_Labels_All_Off(void);
void	Fuel_Clk_Labels_All_On(void);

void	Set_Fuel_Clock_Digits(unsigned int fuel_val);
void	Set_Fuel_Clock_Labels(byte label);
void	Set_Cruise_State(byte state);
void	Set_Cruise(byte state);
void	Set_Cruise_State(byte state);
void	Set_Traction(byte state);
void	Set_Traction_State(byte state);
void	Set_TPMS_State(byte state);
void	Set_Status_Labels(byte label);
void	Set_Fuel_Clock_Digits_Off(void);
void	Set_Odo_Digits_Off(void);
void	Set_FC_Labels_All_Off(void);
void	Set_Odo(byte state);

void Set_Volt_Bar_All_OFF(void);
void Set_Temp_Bar_All_OFF(void);
void Set_Temp_Labels_All_Off(void);
void Set_Gear_Labels_All_Off(void);
void Set_Compass_All_Off(void);

void	Set_Digit_1(byte value);
void	Set_Digit_2(byte value);
void	Set_Digit_3(byte value);
void	Set_Digit_4(byte value);
void	Set_Digit_5(byte value);
void	Set_Digit_6(byte value);
void	Set_Digit_7(byte value);
void	Set_Digit_8(byte value);
void	Set_Digit_9(byte value);
void	Set_Digit_10(byte value);
void	Set_Digit_11(byte value);
void	Set_Digit_12(byte value);
void	Set_Digit_13(byte value);

void Display_On(void);

//----- old functions ------
void  SET_POWERSAVE(char lcdramm, char p); 
void  SET_TIMESEGS(byte lcdramm, byte am, byte pm, byte k3);
void  SET_DMMLABLES(char lcdramm, char kwatt, char volt,char amp,char om) ;
void  SET_COLONS(char lcdramm, char col1, char col2, char col3, char dt) ;
void  SET_DECIMALS(char lcdramm, char dt1,char dt2,char dt3,char dt4,char dt5,char dt6,char dt7,char dt8, char dt9); 
void  SET_MENU(char lcdramm,  char lab1, char lab2, char lab3, char lab4, char lab5, char lab6, char lab7); 

void SET_ALL_ALPNUM(char lcdramm);  
void CLEAR_ALL_ALPNUM(char lcdramm);  
void output_strg_lcd(unsigned char *string, unsigned char length); 
void Scroll_String(unsigned char *string, byte local_len); 

//----- old functions ------


/*
//=====================
//Other Variables
//======================//Not Delay is based in bus clock//adjust as necessary
#if FBE_32KHZ
  #define  SCROLL_Delay   4
  #define  CLEAR_Delay    2
#elif FEE_32K8BUS
  #define  SCROLL_Delay   60
  #define  CLEAR_Delay    20
#elif FEE_32K16BUS
  #define  SCROLL_Delay   60
  #define  CLEAR_Delay    20
#elif FEI_8MBUS
  #define  SCROLL_Delay   60
  #define  CLEAR_Delay    20
#endif

*/
/*  LCD uses internal IRC1M clock only on HY64
//===========================
//LCD clock source selection   //if OFF the LCD is clocked via the bus clock
//============================
#if FBE_32KHZ
  #define EXTERNALCLK			YES  
#elif FEE_32K8BUS
  #define EXTERNALCLK			YES  
#elif FEE_32K16BUS
  #define EXTERNALCLK			YES  
#elif FEI_8MBUS
  #define EXTERNALCLK			NO  
#endif


#if   EXTERNALCLK			 //LCD clock off EXTERNALCLK//must be 32.768 source
    #define LCDCLK_ADJ			0 //SYS_CLOCK/32768 - 1
#else  
    #if  SYS_CLOCK < 100000 
        #define LCDCLK_16			0
        #define LCDCLK_ADJ			SYS_CLOCK/32768 - 1
    #else
        #define LCDCLK_16			1
        #define LCDCLK_ADJ			SYS_CLOCK/32768/16 - 1
    #endif    
#endif 
*/

/*
//===========================
//Define LCD duty cycle 
//===========================
#define DUTY1BY2        0
#define DUTY1BY3        0
#define DUTY1BY4        1
#if DUTY1BY2			 //format = FF = Frame Frequency
      // 1/2 Duty Cycle 
      #define D2FF128D08         0
      #define D2FF64D04          0
      #define D2FF32D02          0
      #define D2FF16D01          0
#elif	 DUTY1BY3
      // 1/3 Duty Cycle 
      #define D3FF170D77         0
      #define D3FF85D38          0
      #define D3FF42D69          0
      #define D3FF29D34          0
#elif	 DUTY1BY4
      // 1/4 Duty Cycle 
      #define D4FF128D08         0
      #define D4FF64D04          1			 //64Hz
      #define D4FF32D02          0			 //32Hz
      #define D4FF16D01          0
#endif
*/
