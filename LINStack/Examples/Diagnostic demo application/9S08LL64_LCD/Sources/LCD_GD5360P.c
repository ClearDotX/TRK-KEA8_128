#include "derivative.h" /* include peripheral declarations */
#include "LCD_GD5360P.h"

#include <hidef.h>

unsigned char bLCD_CharPosition;


byte *bpaPlace [ ] =
{
(unsigned char *)&Char1a,		  // LCD4 ---  Pin:5   LCDnAddress=4      bLCD_CharPosition = 0x00
 (unsigned char *)&Char1b,		// LCD5 ---  Pin:6   LCDnAddress=5      bLCD_CharPosition = 0x01
 (unsigned char *)&Char1c,		// LCD6 ---  Pin:7   LCDnAddress=6      bLCD_CharPosition = 0x02
 (unsigned char *)&Char1d,   	// LCD7 ---  Pin:8   LCDnAddress=7      bLCD_CharPosition = 0x03
 (unsigned char *)&Char2a,		// LCD13 --- Pin:10  LCDnAddress=13     bLCD_CharPosition = 0x04
 (unsigned char *)&Char2b,   	// LCD14 --- Pin:11  LCDnAddress=14     bLCD_CharPosition = 0x05
 (unsigned char *)&Char2c,   	// LCD15 --- Pin:12  LCDnAddress=15     bLCD_CharPosition = 0x06
 (unsigned char *)&Char2d,   	// LCD16 --- Pin:13  LCDnAddress=16     bLCD_CharPosition = 0x07
 (unsigned char *)&Char3a,		// LCD17 --- Pin:14  LCDnAddress=17     bLCD_CharPosition = 0x08
 (unsigned char *)&Char3b,  	// LCD18 --- Pin:17  LCDnAddress=18     bLCD_CharPosition = 0x09
 (unsigned char *)&Char3c,  	// LCD19 --- Pin:18  LCDnAddress=19     bLCD_CharPosition = 0x0A
 (unsigned char *)&Char3d,		// LCD20 --- Pin:19  LCDnAddress=20     bLCD_CharPosition = 0x0B
 (unsigned char *)&Char4a,		// LCD29 --- Pin:25  LCDnAddress=29     bLCD_CharPosition = 0x0C
 (unsigned char *)&Char4b,   	// LCD28 --- Pin:24  LCDnAddress=29     bLCD_CharPosition = 0x0D
 (unsigned char *)&Char4c,		// LCD27 --- Pin:23  LCDnAddress=28     bLCD_CharPosition = 0x0E
 (unsigned char *)&Char4d,   	// LCD26 --- Pin:22  LCDnAddress=26     bLCD_CharPosition = 0x0F
 (unsigned char *)&Char5a,		// LCD39 --- Pin:28  LCDnAddress=29     bLCD_CharPosition = 0x10
 (unsigned char *)&Char5b,		// LCD38 --- Pin:27  LCDnAddress=30     bLCD_CharPosition = 0x11
 (unsigned char *)&Char5c,		// LCD30 --- Pin:26  LCDnAddress=38     bLCD_CharPosition = 0x12
 (unsigned char *)&Char5d,		// LCD26 --- Pin:22  LCDnAddress=39     bLCD_CharPosition = 0x13
};


const byte baAlphanumeric [ ] =
{
	 (  SEGA  ), (  SEGB +  SEGF ),  (  SEGC + !SEGG ),  (  SEGD +  SEGE ),          //Char = 0,   offset=0
	 ( !SEGA  ), (  SEGB + !SEGF ),  (  SEGC + !SEGG ),  ( !SEGD + !SEGE ),          //Char = 1,   offset=4
	 (  SEGA  ), (  SEGB + !SEGF ),  ( !SEGC +  SEGG ),  (  SEGD +  SEGE ),          //Char = 2,   offset=8
	 (  SEGA  ), (  SEGB + !SEGF ),  (  SEGC +  SEGG ),  (  SEGD + !SEGE ),          //Char = 3,   offset=12
	 ( !SEGA  ), (  SEGB +  SEGF ),  (  SEGC +  SEGG ),  ( !SEGD + !SEGE ),          //Char = 4,   offset=16
	 (  SEGA  ), ( !SEGB +  SEGF ),  (  SEGC +  SEGG ),  (  SEGD + !SEGE ),          //Char = 5,   offset=20
	 (  SEGA  ), ( !SEGB +  SEGF ),  (  SEGC +  SEGG ),  (  SEGD +  SEGE ),          //Char = 6,   offset=24
	 (  SEGA  ), (  SEGB + !SEGF ),  (  SEGC + !SEGG ),  ( !SEGD + !SEGE ),          //Char = 7,   offset=28
	 (  SEGA  ), (  SEGB +  SEGF ),  (  SEGC +  SEGG ),  (  SEGD +  SEGE ),          //Char = 8,   offset=32
	 (  SEGA  ), (  SEGB +  SEGF ),  (  SEGC +  SEGG ),  ( !SEGD + !SEGE ),          //Char = 9,   offset=36
	 ( !SEGA  ), ( !SEGB + !SEGF ),  ( !SEGC + !SEGG ),  ( !SEGD + !SEGE ),          //Char = :    offset=40
	 ( !SEGA  ), ( !SEGB + !SEGF ),  ( !SEGC + !SEGG ),  ( !SEGD + !SEGE ),          //Char = ;    offset=44
	 (  SEGA  ), ( !SEGB +  SEGF ),  ( !SEGC +  SEGG ),  ( !SEGD + !SEGE ),          //Char = <    offset=48
	 (  SEGA  ), ( !SEGB + !SEGF ),  ( !SEGC +  SEGG ),  ( !SEGD + !SEGE ),          //Char = =    offset=52
	 (  SEGA  ), (  SEGB + !SEGF ),  ( !SEGC +  SEGG ),  ( !SEGD + !SEGE ),          //Char = >    offset=56
	 (  SEGA  ), (  SEGB +  SEGF ),  ( !SEGC +  SEGG ),  ( !SEGD + !SEGE ),          //Char = ?    offset=60
	 (  SEGA  ), (  SEGB +  SEGF ),  ( !SEGC +  SEGG ),  ( !SEGD + !SEGE ),          //Char = @,   offset=64
	 (  SEGA  ), (  SEGB +  SEGF ),  (  SEGC +  SEGG ),  ( !SEGD +  SEGE ),          //Char = A,   offset=68
	 ( !SEGA  ), ( !SEGB +  SEGF ),  (  SEGC +  SEGG ),  (  SEGD +  SEGE ),          //Char = B,   offset=72
	 (  SEGA  ), ( !SEGB +  SEGF ),  ( !SEGC + !SEGG ),  (  SEGD +  SEGE ),          //Char = C,   offset=76
	 ( !SEGA  ), (  SEGB + !SEGF ),  (  SEGC +  SEGG ),  (  SEGD +  SEGE ),          //Char = D,   offset=80
	 (  SEGA  ), ( !SEGB +  SEGF ),  ( !SEGC +  SEGG ),  (  SEGD +  SEGE ),          //Char = E,   offset=84
	 (  SEGA  ), ( !SEGB +  SEGF ),  ( !SEGC +  SEGG ),  ( !SEGD +  SEGE ),          //Char = F,   offset=88
	 ( !SEGA  ), ( !SEGB + !SEGF ),  ( !SEGC + !SEGG ),  ( !SEGD + !SEGE ),          //Char = G,   offset=92
	 ( !SEGA  ), (  SEGB +  SEGF ),  (  SEGC +  SEGG ),  ( !SEGD +  SEGE ),          //Char = H,   offset=96
	 ( !SEGA  ), ( !SEGB +  SEGF ),  ( !SEGC + !SEGG ),  ( !SEGD +  SEGE ),          //Char = I,   offset=100
	 ( !SEGA  ), (  SEGB + !SEGF ),  (  SEGC + !SEGG ),  (  SEGD + !SEGE ),          //Char = J,   offset=104
	 ( !SEGA  ), ( !SEGB + !SEGF ),  ( !SEGC + !SEGG ),  ( !SEGD + !SEGE ),          //Char = K,   offset=108
	 ( !SEGA  ), ( !SEGB +  SEGF ),  ( !SEGC + !SEGG ),  (  SEGD +  SEGE ),          //Char = L,   offset=112
	 ( !SEGA  ), ( !SEGB + !SEGF ),  ( !SEGC + !SEGG ),  ( !SEGD + !SEGE ),          //Char = M,   offset=116
	 ( !SEGA  ), ( !SEGB + !SEGF ),  (  SEGC +  SEGG ),  ( !SEGD +  SEGE ),          //Char = N,   offset=120
	 ( !SEGA  ), ( !SEGB + !SEGF ),  (  SEGC +  SEGG ),  (  SEGD +  SEGE ),          //Char = O,   offset=124
	 (  SEGA  ), (  SEGB +  SEGF ),  ( !SEGC +  SEGG ),  ( !SEGD +  SEGE ),          //Char = P,   offset=128
	 (  SEGA  ), (  SEGB +  SEGF ),  (  SEGC + !SEGG ),  (  SEGD +  SEGE ),          //Char = Q,   offset=132
	 ( !SEGA  ), ( !SEGB + !SEGF ),  ( !SEGC +  SEGG ),  ( !SEGD +  SEGE ),          //Char = R,   offset=136
	 (  SEGA  ), ( !SEGB +  SEGF ),  (  SEGC +  SEGG ),  (  SEGD + !SEGE ),          //Char = S,   offset=140
	 ( !SEGA  ), ( !SEGB + !SEGF ),  ( !SEGC + !SEGG ),  ( !SEGD + !SEGE ),          //Char = T,   offset=144
	 ( !SEGA  ), (  SEGB +  SEGF ),  (  SEGC + !SEGG ),  (  SEGD +  SEGE ),          //Char = U,   offset=148
} ;


const byte baNumeric [ ] = 
{ // SEGA    SEGB        SEGF    SEGG        SEGE    SEGC        SEGD
	(  SEG1 +  SEG2 ),  (  SEG1 + !SEG2 ),  (  SEG1 +  SEG2 ),  (  SEG1 ),          //Char = 0,   offset=0
	( !SEG1 +  SEG2 ),  ( !SEG1 + !SEG2 ),  ( !SEG1 +  SEG2 ),  ( !SEG1 ),          //Char = 1,   offset=4
	(  SEG1 +  SEG2 ),  ( !SEG1 +  SEG2 ),  (  SEG1 + !SEG2 ),  (  SEG1 ),          //Char = 2,   offset=8
	(  SEG1 +  SEG2 ),  ( !SEG1 +  SEG2 ),  ( !SEG1 +  SEG2 ),  (  SEG1 ),          //Char = 3,   offset=12
	( !SEG1 +  SEG2 ),  (  SEG1 +  SEG2 ),  ( !SEG1 +  SEG2 ),  ( !SEG1 ),          //Char = 4,   offset=16
	(  SEG1 + !SEG2 ),  (  SEG1 +  SEG2 ),  ( !SEG1 +  SEG2 ),  (  SEG1 ),          //Char = 5,   offset=20
	(  SEG1 + !SEG2 ),  (  SEG1 +  SEG2 ),  (  SEG1 +  SEG2 ),  (  SEG1 ),          //Char = 6,   offset=24
	(  SEG1 +  SEG2 ),  ( !SEG1 + !SEG2 ),  ( !SEG1 +  SEG2 ),  ( !SEG1 ),          //Char = 7,   offset=28
	(  SEG1 +  SEG2 ),  (  SEG1 +  SEG2 ),  (  SEG1 +  SEG2 ),  (  SEG1 ),          //Char = 8,   offset=32
	(  SEG1 +  SEG2 ),  (  SEG1 +  SEG2 ),  ( !SEG1 +  SEG2 ),  ( !SEG1 ),          //Char = 9,   offset=36
	( !SEG1 + !SEG2 ),  ( !SEG1 + !SEG2 ),  ( !SEG1 + !SEG2 ),  ( !SEG1 ),          //Char = :,   offset=40
	(  SEG1 +  SEG2 ),  (  SEG1 + !SEG2 ),  (  SEG1 +  SEG2 ),  (  SEG1 ),          //Char = ;,   offset=0
	( !SEG1 +  SEG2 ),  ( !SEG1 + !SEG2 ),  ( !SEG1 +  SEG2 ),  ( !SEG1 ),          //Char = <,   offset=4
	(  SEG1 +  SEG2 ),  ( !SEG1 +  SEG2 ),  (  SEG1 + !SEG2 ),  (  SEG1 ),          //Char = =,   offset=8
	(  SEG1 +  SEG2 ),  ( !SEG1 +  SEG2 ),  ( !SEG1 +  SEG2 ),  (  SEG1 ),          //Char = >,   offset=12
	( !SEG1 +  SEG2 ),  (  SEG1 +  SEG2 ),  ( !SEG1 +  SEG2 ),  ( !SEG1 ),          //Char = ?,   offset=16
	(  SEG1 + !SEG2 ),  (  SEG1 +  SEG2 ),  ( !SEG1 +  SEG2 ),  (  SEG1 ),          //Char = @,   offset=20
	(  SEG1 +  SEG2 ),  (  SEG1 +  SEG2 ),  (  SEG1 +  SEG2 ),  ( !SEG1 ),          //Char = A,   offset=24
	( !SEG1 + !SEG2 ),  (  SEG1 +  SEG2 ),  (  SEG1 +  SEG2 ),  (  SEG1 ),          //Char = B,   offset=28
	(  SEG1 + !SEG2 ),  (  SEG1 + !SEG2 ),  (  SEG1 + !SEG2 ),  (  SEG1 ),          //Char = C,   offset=32
	( !SEG1 +  SEG2 ),  ( !SEG1 +  SEG2 ),  (  SEG1 +  SEG2 ),  (  SEG1 ),          //Char = D,   offset=36
	(  SEG1 + !SEG2 ),  (  SEG1 +  SEG2 ),  (  SEG1 + !SEG2 ),  (  SEG1 ),          //Char = E,   offset=40
	(  SEG1 + !SEG2 ),  (  SEG1 +  SEG2 ),  (  SEG1 + !SEG2 ),  ( !SEG1 ),          //Char = F,   offset=0
};


void vfnLCD_Init(){
   /* LCDC0: SOURCE=0 */
  clrReg8Bits(LCDC0, 0x40);             
  /* LCDRVC: RVEN=1,??=0,??=0,??=0,RVTRIM3=0,RVTRIM2=0,RVTRIM1=0,RVTRIM0=0 */
  setReg8(LCDRVC, 0x80);                
  /* LCDSUPPLY: CPSEL=1,HREFSEL=0,LADJ1=0,LADJ0=0,??=0,BBYPASS=0,VSUPPLY1=1,VSUPPLY0=1 */
  setReg8(LCDSUPPLY, 0x83);             
  /* LCDC1: LCDIEN=0,??=0,??=0,??=0,??=0,FCDEN=0,LCDWAI=0,LCDSTP=0 */
  setReg8(LCDC1, 0x00);                 
  /* LCDC0: LCDEN=0,SOURCE=0,LCLK2=1,LCLK1=0,LCLK0=0,DUTY2=0,DUTY1=0,DUTY0=1 */
  setReg8(LCDC0, 0x21);                 
  /* LCDBCTL: BLINK=0,ALT=0,BLANK=0,??=0,BMODE=1,BRATE2=1,BRATE1=0,BRATE0=0 */
  setReg8(LCDBCTL, 0x0C);               
  /* LCDPEN0: PEN7=1,PEN6=1,PEN5=1,PEN4=1,PEN3=1,PEN2=1,PEN1=1,PEN0=1 */
  setReg8(LCDPEN0, 0xFF);               
  /* LCDBPEN0: BPEN7=0,BPEN6=0,BPEN5=0,BPEN4=0,BPEN3=0,BPEN2=0,BPEN1=0,BPEN0=0 */
  setReg8(LCDBPEN0, 0x00);              
  /* LCDPEN1: PEN15=1,PEN14=1,PEN13=1,PEN12=0,PEN11=0,PEN10=0,PEN9=0,PEN8=0 */
  setReg8(LCDPEN1, 0xE0);               
  /* LCDBPEN1: BPEN15=0,BPEN14=0,BPEN13=0,BPEN12=0,BPEN11=0,BPEN10=0,BPEN9=0,BPEN8=0 */
  setReg8(LCDBPEN1, 0x00);              
  /* LCDPEN2: PEN23=1,PEN22=1,PEN21=1,PEN20=1,PEN19=1,PEN18=1,PEN17=1,PEN16=1 */
  setReg8(LCDPEN2, 0xFF);               
  /* LCDBPEN2: BPEN23=0,BPEN22=0,BPEN21=0,BPEN20=0,BPEN19=0,BPEN18=0,BPEN17=0,BPEN16=0 */
  setReg8(LCDBPEN2, 0x00);              
  /* LCDPEN3: PEN31=0,PEN30=1,PEN29=1,PEN28=1,PEN27=1,PEN26=1,PEN25=1,PEN24=1 */
  setReg8(LCDPEN3, 0x7F);               
  /* LCDBPEN3: BPEN31=0,BPEN30=0,BPEN29=0,BPEN28=0,BPEN27=0,BPEN26=0,BPEN25=0,BPEN24=0 */
  setReg8(LCDBPEN3, 0x00);              
  /* LCDPEN4: PEN39=1,PEN38=1,PEN37=0,PEN36=0,PEN35=0,PEN34=0,PEN33=0,PEN32=0 */
  setReg8(LCDPEN4, 0xC0);               
  /* LCDBPEN4: BPEN39=0,BPEN38=0,BPEN37=0,BPEN36=0,BPEN35=0,BPEN34=0,BPEN33=0,BPEN32=0 */
  setReg8(LCDBPEN4, 0x00);              
  /* LCDPEN5: ??=0,??=0,??=0,??=0,PEN43=0,PEN42=0,PEN41=1,PEN40=1 */
  setReg8(LCDPEN5, 0x03);               
  /* LCDBPEN5: ??=0,??=0,??=0,??=0,BPEN43=0,BPEN42=0,BPEN41=1,BPEN40=1 */
  setReg8(LCDBPEN5, 0x03);              
  /* LCDWF40: BPHLCD40=0,BPGLCD40=0,BPFLCD40=0,BPELCD40=0,BPDLCD40=0,BPCLCD40=0,BPBLCD40=0,BPALCD40=1 */
  setReg8(LCDWF40, 0x01);               
  /* LCDWF41: BPHLCD41=0,BPGLCD41=0,BPFLCD41=0,BPELCD41=0,BPDLCD41=0,BPCLCD41=0,BPBLCD41=1,BPALCD41=0 */
  setReg8(LCDWF41, 0x02);               
  /* LCDS: LCDIF=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  setReg8(LCDS, 0x80);                  
  /* LCDC0: LCDEN=1 */
  setReg8Bits(LCDC0, 0x80); 
}

void vfnLCD_Home (void)
{
  bLCD_CharPosition =  0;
}

 
void  vfnLCD_Write_Msg (unsigned char *lbpMessage, unsigned char lbSize )
{
  do
  {
    vfnLCD_Write_Char (*lbpMessage);
    lbpMessage ++;     
   }while (--lbSize);

}

void vfnLCD_ClearAlternateMsg(unsigned char lbSize)
{
  unsigned char *lbpLCDWF;

  if (bLCD_CharPosition < 0x0c)
  {
    while (lbSize--)
    {
      unsigned char lbCounter = _LCDTYPE - 1;
      
      lbpLCDWF = bpaPlace[bLCD_CharPosition++];
      *lbpLCDWF &= 0x1f;
      while (lbCounter--)
      {
        lbpLCDWF = bpaPlace[bLCD_CharPosition++];
        *lbpLCDWF &= 0x0f;
      }
    }
  }
  else
  {
    lbSize *= _LCDTYPE;
    while (lbSize--)
    {
			lbpLCDWF = bpaPlace[bLCD_CharPosition++];
			*lbpLCDWF &= 0x0f;
    }
    
  }
}

void vfnLCD_Write_Char (unsigned char lbValue)
{
  unsigned char *lbpLCDWF;
  unsigned char lbCounter = _LCDTYPE;
  unsigned char lbBackup = 1;
          
  lbValue = (lbValue-'0')*_LCDTYPE;

  if (bLCD_CharPosition == _CHARNUM*_LCDTYPE )	 	//Check if the place to write is an alphanumeric that exist
  {
  	bLCD_CharPosition = 0;
  }

         
         
  if (bLCD_CharPosition < 0x0C ) 
  {
	  while (lbCounter--)
	  {
		  if (lbCounter == 3)
		  {
  			lbpLCDWF = bpaPlace[bLCD_CharPosition];
  			lbBackup &= *lbpLCDWF;
  			*lbpLCDWF = (lbBackup + baAlphanumeric[lbValue]) + ((lbBackup + baAlphanumeric[lbValue]) << 4);
  		}
  		else 
  		{
  			lbpLCDWF = bpaPlace[bLCD_CharPosition];
  			*lbpLCDWF = baAlphanumeric[lbValue] + (baAlphanumeric[lbValue] << 4);
  		}
  		lbValue++;
  		bLCD_CharPosition++;
		}

  }
  else
  {
    while (lbCounter--)
    {
  		if (bLCD_CharPosition == 0x13)
  		{
  			lbpLCDWF = bpaPlace[bLCD_CharPosition];
  			*lbpLCDWF |= (baNumeric[lbValue] * 2) + ((baNumeric[lbValue] * 2)<<4);
  		}
  		else 
  		{
  			lbpLCDWF = bpaPlace[bLCD_CharPosition];
  			*lbpLCDWF = baNumeric[lbValue] + (baNumeric[lbValue] << 4);
  		}
  		lbValue++;
  		bLCD_CharPosition++;
    }
  }
}
void vfnLCD_Step_All_Segments (unsigned char count) {
 int s;
 	DisableInterrupts;	

 for (s=0x00;s<count;s++){
  
 _LCD_Time1_ON ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Time1_OFF   ; 
 _LCD_Char1a_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char1a_OFF  ; 
 _LCD_Char1b_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char1b_OFF  ; 
 _LCD_Char1c_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char1c_OFF  ; 
 _LCD_Char1d_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char1d_OFF  ; 
 _LCD_Char1e_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char1e_OFF  ; 
 _LCD_Char1f_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char1f_OFF  ; 
 _LCD_Char1g_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char1g_OFF  ; 
 _LCD_Char2a_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char2a_OFF  ; 
 _LCD_Char2b_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char2b_OFF  ; 
 _LCD_Char2c_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char2c_OFF  ; 
 _LCD_Char2d_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char2d_OFF  ; 
 _LCD_Char2e_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char2e_OFF  ; 
 _LCD_Char2f_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char2f_OFF  ; 
 _LCD_Char2g_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char2g_OFF  ; 
 _LCD_Char3a_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char3a_OFF  ; 
 _LCD_Char3b_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char3b_OFF  ; 
 _LCD_Char3c_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char3c_OFF  ; 
 _LCD_Char3d_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char3d_OFF  ; 
 _LCD_Char3e_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char3e_OFF  ; 
 _LCD_Chra3f_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Chra3f_OFF  ; 
 _LCD_Char3g_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char3g_OFF  ; 
 _LCD_Char4a_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char4a_OFF  ; 
 _LCD_Char4b_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char4b_OFF  ; 
 _LCD_Char4c_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char4c_OFF  ; 
 _LCD_Char4d_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char4d_OFF  ; 
 _LCD_Char4e_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char4e_OFF  ; 
 _LCD_Char4f_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char4f_OFF  ; 
 _LCD_Char4g_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char4g_OFF  ; 
 _LCD_Char5a_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char5a_OFF  ; 
 _LCD_Char5b_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char5b_OFF  ; 
 _LCD_Char5c_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char5c_OFF  ; 
 _LCD_Char5d_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char5d_OFF  ; 
 _LCD_Char5e_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char5e_OFF  ; 
 _LCD_Char5f_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char5f_OFF  ; 
 _LCD_Char5g_ON;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_Char5g_OFF  ; 
 _LCD_MONDAY_ON 		 ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_MONDAY_OFF 	  ;
 _LCD_TUESDAY_ON 	   ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_TUESDAY_OFF 	  ;
 _LCD_WEDNESDAY_ON   ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_WEDNESDAY_OFF  ;
 _LCD_THURSDAY_ON 	 ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_THURSDAY_OFF   ;
 _LCD_FRIDAY_ON 		 ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_FRIDAY_OFF 	  ;
 _LCD_SATURDAY_ON 	 ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_SATURDAY_OFF   ;
 _LCD_SUNDAY_ON 		 ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_SUNDAY_OFF 	  ;
 _LCD_BATTERY_ON 	   ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_BATTERY_OFF 	  ;
 _LCD_BAT1_ON 			 ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_BAT1_OFF		 	  ;
 _LCD_BAT2_ON 			 ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_BAT2_OFF 		  ;
 _LCD_BAT3_ON 			 ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_BAT3_OFF 		  ;
 _LCD_BAT4_ON			   ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_BAT4_OFF 		  ;
 _LCD_COLON_ON       ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_COLON_OFF      ;
 _LCD_HEAT_ON 			 ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_HEAT_OFF 		  ;
 _LCD_COOL_ON 			 ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_COOL_OFF 		  ;
 _LCD_AM_ON 			   ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_AM_OFF 			  ;
 _LCD_PM_ON 			   ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_PM_OFF 			  ;
 _LCD_FLTR_ON 			 ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_FLTR_OFF 		  ;
 _LCD_HOLD_ON 			 ;  while(TODSC_QSECF == 0);   TODSC_QSECIE = 1;  _LCD_HOLD_OFF 		  ;
 
 }
	EnableInterrupts;
                                      
}                                     
void vfnLCD_All_Segments_ON (void)    
{                                     
   WF0ON ;
   WF1ON ;  
   WF2ON ;
   WF3ON ;
   WF4ON ;
   WF5ON ;
   WF6ON ;  
   WF7ON ;
   WF13ON;
   WF14ON;
   WF15ON;
   WF16ON;  
   WF17ON;
   WF18ON;
   WF19ON;
   WF20ON;
   WF21ON;  
   WF22ON;
   WF23ON;
   WF24ON;
   WF25ON;
   WF26ON;  
   WF27ON;
   WF28ON;
   WF29ON;
   WF30ON;
   WF38ON;  
   WF39ON;
}

void vfnLCD_All_Segments_OFF (void)
{              
     WF0OFF;
     WF1OFF;  
     WF2OFF;
     WF3OFF;
     WF4OFF;
     WF5OFF;
     WF6OFF;  
     WF7OFF;
     WF13OFF;
     WF14OFF;
     WF15OFF;
     WF16OFF;  
     WF17OFF;
     WF18OFF;
     WF19OFF;
     WF20OFF;
     WF21OFF;  
     WF22OFF;
     WF23OFF;
     WF24OFF;
     WF25OFF;
     WF26OFF;  
     WF27OFF;
     WF28OFF;
     WF29OFF;
     WF30OFF;
     WF38OFF;  
     WF39OFF;
}

 void SetAlpha(char alphanum, char data){
   
 switch(alphanum) {
 
  case 1:
  bLCD_CharPosition = 0x00;
  vfnLCD_Write_Char (data) ;
  break;
  
  case 2:
  bLCD_CharPosition = 0x04;
  vfnLCD_Write_Char (data);
  break;

  case 3:
  bLCD_CharPosition = 0x08;
  vfnLCD_Write_Char (data) ;
  break;
  
  case 4:
  bLCD_CharPosition = 0x0c;
  vfnLCD_Write_Char (data);
  break;
  
  case 5:
  bLCD_CharPosition = 0x10;
  vfnLCD_Write_Char (data) ;
  break;


  case 6:
  asm nop;
  break;
  
  case 7:
  asm   nop;
  break;
  
  case 8:
  asm nop
  break;
  
  case 9:
  asm nop
  break;
  
default:
                             
      break;
 }
 }
 
void SetNumber(char order, unsigned char data){
  unsigned char low, high;
  
  low = data & 0x0F;
  high = (data &0xF0) >> 4;

  if (high < 10 ){
     SetAlpha(order , high + 48);
  } else {
     SetAlpha(order , high + 55); 
  }
    
  if (low < 10 ){
     SetAlpha(order + 1 , low + 48);
  } else {
     SetAlpha(order + 1, low + 55); 
  }
 
}
 