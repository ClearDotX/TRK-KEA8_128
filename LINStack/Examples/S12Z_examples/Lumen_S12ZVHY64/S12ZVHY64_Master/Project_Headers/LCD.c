/*
 * LCD.c
 *
 *  Created on: Feb 13, 2012
 *      Author: B40150
 */


#include "LCD.h"


void SetC1(char in);
void SetC2(char in);   
void SetC3(char in);  
void SetC4(char in);  
void SetC5(char in);  
void SetC6(char in);  
void SetO1(char in);  
void SetO2(char in);  
void SetO3(char in);  
void SetO4(char in);  
void SetO5(char in);  
void SetO6(char in);

/**********************************************************************************************
* Global functions
**********************************************************************************************/

/***********************************************************************************************
*
* @brief    LCD_Init   Initializes the Liquid Crystal Display Module
* @param    none
* @return   none
*
************************************************************************************************/  

void LCD_Init(){
		 //Configure LCD clock
	LCDCR0_LCLK = 0;	  //Divide clk by 4096 = 61Hz  
	LCDCR1_LCDSWAI = 1;   //LCD in Wait
	LCDCR0_DUTY = 0;	  //Duty = 1/4
	LCDCR0_BIAS = 1;	  //Bias = 1/3
	
	/* Enable Frontplanes */  
	LCDFPENR0 = 0xFF;	//Segments 0..7
	LCDFPENR1 = 0xFF;	//Segments 8..15
	LCDFPENR2 = 0xFF;	//Segments 16..23
	LCDFPENR3 = 0xFF;	//Segments 24..31
	LCDFPENR4 = 0xFF;	//Segments 32..39
	
	LCDCR0_LCDEN = 1;    // Enable LCD
	
	SEG_HLINE = 1;   /*Set Lines*/
	SEG_VLINE = 1;   /*Set Lines*/
}


 void SetD1(char in)
   {
   switch(in)
     {
       case 0: D1_0; break;
       case 1: D1_1; break;
       case 2: D1_2; break;
       case 3: D1_3; break;
       case 4: D1_4; break;
       case 5: D1_5; break;
       case 6: D1_6; break;
       case 7: D1_7; break;
       case 8: D1_8; break;
       case 9: D1_9; break;
       case 10: D1_B; break;
     }  
   }
   
 void SetD2(char in)
   {
   switch(in)
     {
       case 0: D2_0; break;
       case 1: D2_1; break;
       case 2: D2_2; break;
       case 3: D2_3; break;
       case 4: D2_4; break;
       case 5: D2_5; break;
       case 6: D2_6; break;
       case 7: D2_7; break;
       case 8: D2_8; break;
       case 9: D2_9; break;
       case 10: D2_B; break;
     }  
   }  
   
 void SetD3(char in)
   {
   switch(in)
     {
       case 0: D3_0; break;
       case 1: D3_1; break;
       case 2: D3_2; break;
       case 3: D3_3; break;
       case 4: D3_4; break;
       case 5: D3_5; break;
       case 6: D3_6; break;
       case 7: D3_7; break;
       case 8: D3_8; break;
       case 9: D3_9; break;
       case 10: D3_B; break;
     }          
   }  
   
 void SetD4(char in)
   {
   switch(in)
     {
       case 0: D4_0; break;
       case 1: D4_1; break;
       case 2: D4_2; break;
       case 3: D4_3; break;
       case 4: D4_4; break;
       case 5: D4_5; break;
       case 6: D4_6; break;
       case 7: D4_7; break;
       case 8: D4_8; break;
       case 9: D4_9; break;
       case 10: D4_B; break;
     }  
   }  
   

 void SetC1(char in)
   {
   switch(in)
     {
       case 0: C1_0; break;
       case 1: C1_1; break;
       case 2: C1_2; break;
       case 3: C1_3; break;
       case 4: C1_4; break;
       case 5: C1_5; break;
       case 6: C1_6; break;
       case 7: C1_7; break;
       case 8: C1_8; break;
       case 9: C1_9; break;
     }  
   }
     

 void SetC2(char in)
   {
   switch(in)
     {
       case 0: C2_0; break;
       case 1: C2_1; break;
       case 2: C2_2; break;
       case 3: C2_3; break;
       case 4: C2_4; break;
       case 5: C2_5; break;
       case 6: C2_6; break;
       case 7: C2_7; break;
       case 8: C2_8; break;
       case 9: C2_9; break;
     }  
   }  
    
 void SetC3(char in)
   {
   switch(in)
     {
       case 0: C3_0; break;
       case 1: C3_1; break;
       case 2: C3_2; break;
       case 3: C3_3; break;
       case 4: C3_4; break;
       case 5: C3_5; break;
       case 6: C3_6; break;
       case 7: C3_7; break;
       case 8: C3_8; break;
       case 9: C3_9; break;
     }  
   }  
   
 void SetC4(char in)
   {
   switch(in)
     {
       case 0: C4_0; break;
       case 1: C4_1; break;
       case 2: C4_2; break;
       case 3: C4_3; break;
       case 4: C4_4; break;
       case 5: C4_5; break;
       case 6: C4_6; break;
       case 7: C4_7; break;
       case 8: C4_8; break;
       case 9: C4_9; break;
     }  
   }  
   
 void SetC5(char in)
   {
   switch(in)
     {
       case 0: C5_0; break;
       case 1: C5_1; break;
       case 2: C5_2; break;
       case 3: C5_3; break;
       case 4: C5_4; break;
       case 5: C5_5; break;
       case 6: C5_6; break;
       case 7: C5_7; break;
       case 8: C5_8; break;
       case 9: C5_9; break;
     }  
   }  
   
 void SetC6(char in)
   {
   switch(in)
     {
       case 0: C6_0; break;
       case 1: C6_1; break;
       case 2: C6_2; break;
       case 3: C6_3; break;
       case 4: C6_4; break;
       case 5: C6_5; break;
       case 6: C6_6; break;
       case 7: C6_7; break;
       case 8: C6_8; break;
       case 9: C6_9; break;
     }  
   } 
   
   
 void SetClk(char h, char m, char s)
   {
      SetC6(s % 10);
      s /= 10;
      SetC5(s % 10);     

      SetC4(m % 10);
      m /= 10;
      SetC3(m % 10);
      
      SetC2(h % 10);
      h /= 10;
      SetC1(h % 10);     
   }  
    
   
 void SetO1(char in)
   {
   switch(in)
     {
       case 0: O1_0; break;
       case 1: O1_1; break;
       case 2: O1_2; break;
       case 3: O1_3; break;
       case 4: O1_4; break;
       case 5: O1_5; break;
       case 6: O1_6; break;
       case 7: O1_7; break;
       case 8: O1_8; break;
       case 9: O1_9; break;
     }  
   }  
   
 void SetO2(char in)
   {
   switch(in)
     {
       case 0: O2_0; break;
       case 1: O2_1; break;
       case 2: O2_2; break;
       case 3: O2_3; break;
       case 4: O2_4; break;
       case 5: O2_5; break;
       case 6: O2_6; break;
       case 7: O2_7; break;
       case 8: O2_8; break;
       case 9: O2_9; break;
     }  
   }    
   
 void SetO3(char in)
   {
   switch(in)
     {
       case 0: O3_0; break;
       case 1: O3_1; break;
       case 2: O3_2; break;
       case 3: O3_3; break;
       case 4: O3_4; break;
       case 5: O3_5; break;
       case 6: O3_6; break;
       case 7: O3_7; break;
       case 8: O3_8; break;
       case 9: O3_9; break;
     }  
   }    
   
 void SetO4(char in)
   {
   switch(in)
     {
       case 0: O4_0; break;
       case 1: O4_1; break;
       case 2: O4_2; break;
       case 3: O4_3; break;
       case 4: O4_4; break;
       case 5: O4_5; break;
       case 6: O4_6; break;
       case 7: O4_7; break;
       case 8: O4_8; break;
       case 9: O4_9; break;
     }  
   }    
   
 void SetO5(char in)
   {
   switch(in)
     {
       case 0: O5_0; break;
       case 1: O5_1; break;
       case 2: O5_2; break;
       case 3: O5_3; break;
       case 4: O5_4; break;
       case 5: O5_5; break;
       case 6: O5_6; break;
       case 7: O5_7; break;
       case 8: O5_8; break;
       case 9: O5_9; break;
     }  
   }    
   
 void SetO6(char in)
   {
   switch(in)
     {
       case 0: O6_0; break;
       case 1: O6_1; break;
       case 2: O6_2; break;
       case 3: O6_3; break;
       case 4: O6_4; break;
       case 5: O6_5; break;
       case 6: O6_6; break;
       case 7: O6_7; break;
       case 8: O6_8; break;
       case 9: O6_9; break;
     }  
   } 

   
 void SetOdo(long in)
   {
      //SetO6(in % 10);
      //in /= 10;
      //SetO5(in % 10);
      //in /= 10;
      SetO4(in % 10);
      in /= 10;
      SetO3(in % 10);
      in /= 10;
      SetO2(in % 10);
      in /= 10;
      SetO1(in % 10);                          
   }

 void SetData(long in, char leadZero)
   {
     
		SetD4(in % 10);
		if(!leadZero)
		{
	    	if(in/10 == 0)
	    	{
	    		SetD3(10);
	    		SetD2(10);
	    		SetD1(10);
	    		return;
	    	}
		}
		in /= 10;

		SetD3(in % 10);
		if(!leadZero)
		{
	    	if(in/10 == 0)
	    	{	    
	    		SetD2(10);
	    		SetD1(10);
	    		return;
	    	}
		}		
		in /= 10;
		
		SetD2(in % 10);
		if(!leadZero)
		{
	    	if(in/10 == 0)
	    	{
	    		SetD1(10);
	    		return;
	    	}
		}		
		
		in /= 10;
		SetD1(in % 10);    	          	        
   }
   
 void SetG(char in)
   {
   switch(in)
     {
       case 0:  G_0; break;
       case 1:  G_1; break;
       case 2:  G_2; break;
       case 3:  G_3; break;
       case 4:  G_4; break;
       case 5:  G_5; break;
       case 6:  G_6; break;
       case 7:  G_7; break;
       case 8:  G_8; break;
       case 9:  G_9; break;
       case 10: G_P; break;
       case 11: G_R; break;
       case 12: G_N; break;
       case 13: G_D; break;
     }  
   }      
   
 void setBar(char in, char accumulate)
   {
   if(accumulate)
     {
     switch(in)
       {
         case 0: SEG_B0 = 0; SEG_B1 = 0;  SEG_B2 = 0;  SEG_B3 = 0;  SEG_B4 = 0;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 1; SEG_F = 0; break;
         case 1: SEG_B0 = 1; SEG_B1 = 0;  SEG_B2 = 0;  SEG_B3 = 0;  SEG_B4 = 0;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 2: SEG_B0 = 1; SEG_B1 = 1;  SEG_B2 = 0;  SEG_B3 = 0;  SEG_B4 = 0;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 3: SEG_B0 = 1; SEG_B1 = 1;  SEG_B2 = 1;  SEG_B3 = 0;  SEG_B4 = 0;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 4: SEG_B0 = 1; SEG_B1 = 1;  SEG_B2 = 1;  SEG_B3 = 1;  SEG_B4 = 0;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 5: SEG_B0 = 1; SEG_B1 = 1;  SEG_B2 = 1;  SEG_B3 = 1;  SEG_B4 = 1;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 6: SEG_B0 = 1; SEG_B1 = 1;  SEG_B2 = 1;  SEG_B3 = 1;  SEG_B4 = 1;  SEG_B5 = 1;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 7: SEG_B0 = 1; SEG_B1 = 1;  SEG_B2 = 1;  SEG_B3 = 1;  SEG_B4 = 1;  SEG_B5 = 1;  SEG_B6 = 1;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 8: SEG_B0 = 1; SEG_B1 = 1;  SEG_B2 = 1;  SEG_B3 = 1;  SEG_B4 = 1;  SEG_B5 = 1;  SEG_B6 = 1;  SEG_B7 = 1; SEG_E = 0; SEG_F = 1; break;
       }    
     }
   else
     {
     switch(in)
       {
         case 0: SEG_B0 = 0; SEG_B1 = 0;  SEG_B2 = 0;  SEG_B3 = 0;  SEG_B4 = 0;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 1; SEG_F = 0; break;
         case 1: SEG_B0 = 1; SEG_B1 = 0;  SEG_B2 = 0;  SEG_B3 = 0;  SEG_B4 = 0;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 2: SEG_B0 = 0; SEG_B1 = 1;  SEG_B2 = 0;  SEG_B3 = 0;  SEG_B4 = 0;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 3: SEG_B0 = 0; SEG_B1 = 0;  SEG_B2 = 1;  SEG_B3 = 0;  SEG_B4 = 0;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 4: SEG_B0 = 0; SEG_B1 = 0;  SEG_B2 = 0;  SEG_B3 = 1;  SEG_B4 = 0;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 5: SEG_B0 = 0; SEG_B1 = 0;  SEG_B2 = 0;  SEG_B3 = 0;  SEG_B4 = 1;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 6: SEG_B0 = 0; SEG_B1 = 0;  SEG_B2 = 0;  SEG_B3 = 0;  SEG_B4 = 0;  SEG_B5 = 1;  SEG_B6 = 0;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 7: SEG_B0 = 0; SEG_B1 = 0;  SEG_B2 = 0;  SEG_B3 = 0;  SEG_B4 = 0;  SEG_B5 = 0;  SEG_B6 = 1;  SEG_B7 = 0; SEG_E = 0; SEG_F = 0; break;
         case 8: SEG_B0 = 0; SEG_B1 = 0;  SEG_B2 = 0;  SEG_B3 = 0;  SEG_B4 = 0;  SEG_B5 = 0;  SEG_B6 = 0;  SEG_B7 = 1; SEG_E = 0; SEG_F = 1; break;
       }        
     }  
   }


   
 void setEcoMode(char in){SEG_ECOMODE=in;}
 void setCheckService(char in){SEG_CHKENG=in;}
 void setGasIndicators(char in){SEG_GP=in; SEG_SBARS=in;}
 void setFreescale(char in){SEG_FSL=in; SEG_AVG = in;}
 void setOdoMode()
   {
   SEG_ODO=1;
   SEG_KM = 1;
   SEG_OP = 1;  
   SEG_TRIP = 0;
   SEG_A = 0;
   SEG_B = 0;
   SEG_RANGE = 0;
   SEG_TEMP = 0;
   SEG_C = 0;
   SEG_TOZ = 0;
   }
   
 void setTripAMode()
   {
   SEG_ODO=0;
   SEG_KM = 1;
   SEG_OP = 1;  
   SEG_TRIP = 1;  
   SEG_A = 1;
   SEG_B = 0;
   SEG_RANGE = 0;
   SEG_TEMP = 0;
   SEG_C = 0;
   SEG_TOZ = 0;
   }

 void setTripBMode()
   {
   SEG_ODO=0;
   SEG_KM = 1;
   SEG_OP = 1;  
   SEG_TRIP = 1;  
   SEG_A = 0;
   SEG_B = 1;
   SEG_RANGE = 0;
   SEG_TEMP = 0;
   SEG_C = 0;
   SEG_TOZ = 0;  
   }
   
 void setTempMode()
   {
	 	 SEG_ODO=1;
	    SEG_KM = 0;
	    SEG_OP = 1;  
	    SEG_TRIP = 1;
	    SEG_A = 1;
	    SEG_B = 0;
	    SEG_RANGE =0;
	    SEG_TEMP = 1;
	    SEG_C = 0;
	    SEG_TOZ = 0;
   }  
   
 void setRangeMode()
   {
   SEG_ODO=0;
   SEG_KM = 1;
   SEG_OP = 1;  
   SEG_TRIP = 0;  
   SEG_A = 0;
   SEG_B = 0;
   SEG_RANGE = 1;
   SEG_TEMP = 0;
   SEG_C = 0;
   SEG_TOZ = 1; 
   
   }  
   
 void setSpeedMode()
   {
   SEG_DCOL = 0;
   SEG_DP = 0;
   SEG_KMH = 1;
   SEG_KML = 0;
   SEG_ET = 0;
   }
   
 void setETMode()
   {
   SEG_DCOL = 1;
   SEG_DP = 0;
   SEG_KMH = 0;
   SEG_KML = 0;
   SEG_ET = 1;
   }
 
 void setFuelEfficiencyMode()
   {
   SEG_DCOL = 0;
   SEG_DP = 1;
   SEG_KMH = 0;
   SEG_KML = 1;
   SEG_ET = 0;
   }  
   
 void setAMMode(){SEG_AM=1; SEG_PM=0; SEG_24H=0; SEG_CCOL = 1;}
 void setPMMode(){SEG_AM=0; SEG_PM=1; SEG_24H=0; SEG_CCOL = 1;}
 void set24HMode(){SEG_AM=0; SEG_PM=0; SEG_24H=1; SEG_CCOL = 1;}


void SetClk_Blink(void)
  {
	 C1_B;
	 C2_B;
	 C3_B;
	 C4_B;
	 C5_B;
	 C6_B;
	 SEG_CCOL = 0;     //clock colons
  } 
