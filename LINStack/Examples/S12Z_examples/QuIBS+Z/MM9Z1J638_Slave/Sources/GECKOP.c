#include "GECKOP.h"
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <math.h>
#include "Defines.h"
void GECKOP_SetNormalMode(){
	B_PCR_CTL = 0x0300;
}

void GECKOP_SetStopMode(){
	DisableInterrupts		// Disable interrupts (for MCU full stop)
	B_PCR_CTL = 0x0301; 	// Geckop goes into stop mode.
	__asm (ANDCC #127); 	// Clear CCR bit S to allow stop mode
	EnableInterrupts
	__asm stop;				// MCU goes into full stop mode
}

void GECKOP_SetSleepMode(){
	DisableInterrupts		// Disable interrupts (for MCU full stop)
	B_PCR_CTL = 0x0302; 	// Geckop goes into stop mode.
	__asm (ANDCC #127); 	// Clear CCR bit S to allow stop mode
	EnableInterrupts
	__asm stop;				// MCU goes into full stop mode
}

unsigned char GECKOP_GetCurrentMode(){
	return B_PCR_CTL_OPM;
}

unsigned char GECKOP_IsHWRST(){
	return B_PCR_SR_HWRF;	
}

void GECKOP_Reset(){
	B_PCR_CTL = 0x2020;		//HWRM & HWR set to 1
}

/***********************************************************
*              LOAD TRIM VALUES FROM IFR                   *
***********************************************************/ 

void GECKOP_LoadTrim(char vchain)
{
    unsigned int i ;
  
   //Load all trims values
 
    B_TRIM_BG0H   = TrimmData[0]; 
    B_TRIM_BG0L   = TrimmData[1]; 
 

    B_TRIM_BG1H  = TrimmData[2]; 
    B_TRIM_BG1L  = TrimmData[3]; 
 
    B_TRIM_OSCH   = TrimmData[4]; 
    B_TRIM_OSCL   = TrimmData[5]; 
    
  // Load all COMP_IG  
  
    B_COMP_IG4 = (((TrimmData[6]&0x00ff)<<8))|(TrimmData[7]&0x00ff);
    B_COMP_TIG4 = (((TrimmData[8]&0x00ff)<<8))|(TrimmData[9]&0x00ff);

    B_COMP_IG16 = (((TrimmData[10]&0x00ff)<<8))|(TrimmData[11]&0x00ff);
    B_COMP_TIG16 = (((TrimmData[12]&0x00ff)<<8))|(TrimmData[13]&0x00ff);
  
    B_COMP_IG64 = (((TrimmData[14]&0x00ff)<<8))|(TrimmData[15]&0x00ff);
    B_COMP_TIG64 = (((TrimmData[16]&0x00ff)<<8))|(TrimmData[17]&0x00ff);
  
    B_COMP_IG256 = (((TrimmData[18]&0x00ff)<<8))|(TrimmData[19]&0x00ff);
    B_COMP_TIG256 = (((TrimmData[20]&0x00ff)<<8))|(TrimmData[21]&0x00ff);
   
   //Load all COMP Vsense
    switch (vchain) {
         
    case 1:     //VSENSE1
    	B_COMP_VO    = TrimmData[23]; 
    	i = 31;
      break;
      
    case 2:     //VSENSE2
    	B_COMP_VO    = TrimmData[24]; 
    	i = 35;
      break;        
      
    case 3:     //VSENSE3
    	B_COMP_VO    = TrimmData[25]; 
    	i = 39; 
      break;
      
    case 4:     //VSENSE_EXT
    	B_COMP_VO    = TrimmData[26]; 
    	i = 43; 
      break;  
      
    default:    //VSENSE0 by default    
    	B_COMP_VO    = TrimmData[22]; 
    	i = 27;
      break;  
      
  }
  
  B_COMP_VSG = (((TrimmData[i]&0x00ff)<<8))|(TrimmData[i+1]&0x00ff);
  B_COMP_TVSG = (((TrimmData[i+2]&0x00ff)<<8))|(TrimmData[i+3]&0x00ff);
  
  //Load all COMP Tsense
  B_COMP_ITO = TrimmData[47];  
  B_COMP_ITG = TrimmData[48];   
} 

void GECKOP_Timer10msInit(void)
{
  /* Initialization of TC0 only */
  
  /* TSCR1: TEN=0,TFFCA=0 */  // Disable Timer 
  _B_TSCR1.Bits.TEN =0 ;              
  _B_TSCR1.Bits.TFFCA =0 ;   
        
  /* TIOS: IOS0=1 */        // Select Output Compare            
  _B_TIOS.Bits.IOS0 = 1; 
  
  /* TCTL1: OM0=0,OL0=0 */   // Timer Disconnected from Output pin
  _B_TCTL1.Bits.OM0 =0; 
  _B_TCTL1.Bits.OL0 =0;
  
  /* TCTL2: EDG0A=0,EDG0B=0 */  // Timer Capture Disable
  _B_TCTL2.Bits.EDG0A =0; 
  _B_TCTL2.Bits.EDG0B =0;   
                 
  /* TTOV: TOV7=0,TOV0=0 */    // Toggle pin Overflow disabled
  _B_TTOV.Bits.TOV0 =0;     
  _B_TTOV.Bits.TOV3 =0;                
             
  /* TSCR2: TOI=0,TCRE=1,PR2=0,PR1=1,PR0=0 */   
  _B_TSCR2.Bits.TOI =0; 
  _B_TSCR2.Bits.TCRE =0;    // Timer counter Reset by successfull OC on channel 3 ONLY 
  _B_TSCR2.Bits.PR0 =1;     // TimerClk / 2  : 32MHz / 4 / 2 = 4 MHz  
  _B_TSCR2.Bits.PR1 =0;
  _B_TSCR2.Bits.PR2 =0;  
  
  /* TFLG1: C3F=0,C2F=0,C1F=0,C0F=1 */     // Clear Flags in case already set
  _B_TFLG1.Bits.C0F=1; 
                  
  /* TIE: C0I=1 */
  _B_TIE.Bits.C0I = 1;      // Enable Interrupt            
            
  /* TC0: BIT15=1,BIT14=0,BIT13=0,BIT12=1,BIT11=1,BIT10=1,BIT9=0,BIT8=0,BIT7=0,BIT6=1,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  B_TC0 = 40960;           /* Store given value to the compare register for 10 ms Periodical Interrupt */ 
 /* Common peripheral initialization - ENABLE */
  /* TSCR1: TEN=1 */
  _B_TSCR1.Bits.TEN =1 ;     // Enable Timer          
}

