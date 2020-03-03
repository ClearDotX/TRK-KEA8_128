/********************************************************************** 

Filename : lcddrv.c

Description:  Performs user friendly initialization 
              of LCD Control Register 0 and 1. Source file
              initializes LCD duty cycle and bias.  By
              providing the program with your desired frame
              frequency and given oscillator frequency, this
              program calculates the correct clock divider.
              User is also capable of enabling special modes
              like Pseudostop or Wait modes.  Front plane start
              and stop points are also entered. Finally, the 
              program enables the LCD to the on state. 
              
              Additional routines provide the user with the 
              ability to turn on and off all the LCD segments.
                
************************************************************************/

#include <mc9s12hy64.h>     /* derivative information */
#include "lcddrv.h"

extern void time_Delay(int);

extern char * LCD_pos[NUMRAMREGS_FORGLASS];
extern char  LCD_position;


// Type declarations for LCD data display types

// --- Temperature Display Group ---
extern enum t_temp_type{inside_temp,outside_temp,engine_temp} temp_type;   // Temperature type being displayed
extern enum t_temp_scale{C,F} temp_scale;                                   // Temperature scale being displayed
// --- Compass Display Group ---
extern enum t_compass_direction {N,NE,E,SE,S,SW,W,NW } direction;  // Compass direction displayed

// --- Odometer Display Group ---
//extern enum t_odo_type {ODO,TRIP_A,TRIP_B} odo_type;
//extern enum t_odo_scale{Mi,Km} odo_scale;

// --- Clock/Mileage Display Group ---
// extern enum t_mileage_type {AVG,INST,FUEL,DISTANCE,USED,REMAINING} mileage_type;
// extern enum t_clock_type {AM,PM} clock_type;
// extern enum t_fuel_type {G,MPG,MPH,L,LPK,KPH} fuel_type;

// --- Transmission Display Group ---

extern enum t_transmission_gear {Park,Reverse,Neutral,Drive,Third,Second,First} gear;  // Gear selection

// --- Cruise/TCS/TPMS Display Group ---
 
 
 
 
//*************************************
// Internal Funtions
//*************************************

//=======================================================
//=======================================================
void Config_Clk_Source(){	//Configure LCD clock
      LCDCR0_LCLK = 2;		//Divide input clk by 4096 = 61Hz
  }

//=======================================================
//=======================================================
void Set_LCDCR1_Reg()
  {
  #if LCDINWAIT 
      LCDCR1_LCDSWAI = 0;
  #else
      LCDCR1_LCDSWAI = 1;
  #endif
  }

//=======================================================
//=======================================================
void Set_Bias(){

	//Configure LCD duty & bias
	#ifdef D1B1
		LCDCR0_BIAS = 0;		//Bias = 1/1
	#endif    
	#ifdef D2B2
		LCDCR0_BIAS = 0;		//Bias = 1/2
	#endif    
	#ifdef D2B3
		LCDCR0_BIAS = 1;		//Bias = 1/3
	#endif    			  	
	#ifdef D3B3
		LCDCR0_BIAS = 1;		//Bias = 1/3
	#endif    
	#ifdef D4B3
		LCDCR0_BIAS = 1;		//Bias = 1/3
	#endif    
}					


//=======================================================
//=======================================================
void Set_Duty(){

	//Configure LCD duty & bias
	#ifdef D1B1
		LCDCR0_DUTY = 1;		//Duty = 1/1
	#endif    
	#ifdef D2B2
		LCDCR0_DUTY = 2;		//Duty = 1/2
	#endif    
	#ifdef D2B3
		LCDCR0_DUTY = 3;		//Duty = 1/2
	#endif    			  	
	#ifdef D3B3
		LCDCR0_DUTY = 3;		//Duty = 1/3
	#endif    
	#ifdef D4B3
		LCDCR0_DUTY = 0;		//Duty = 1/4
	#endif    
}					


//=======================================================

//=======================================================
void Enable_FP()
  {               //Enable all segments
  FPENR0 = 0xFF;	//Segments 0..7
  FPENR1 = 0xFF;	//Segments 8..15
  FPENR2 = 0xFF;	//Segments 16..23
  FPENR3 = 0xFF;	//Segments 24..31
  FPENR4 = 0xFF;	//Segments 32..39
  }


 //*************************************
 //External Funtions
 //*************************************
//=======================================================
//=======================================================
//=======================================================

//=======================================================
//void ENABLE_BLINK(byte cmd_enable){
//	LCDBCTL_BLINK = cmd_enable;
//}

//=======================================================
void Enable_LCD(byte cmd_enable){
	LCDCR0_LCDEN = cmd_enable;
}

//=======================================================
void LCD_Init() 
  {
	Config_Clk_Source();				// set input clk divider
	Set_LCDCR1_Reg();					// configure operation in stop/wait
	Set_Duty();							// set to 1/4 duty ratio
	Set_Bias();							//	set to 1/3 bias ration	
	Enable_FP();						// enable Frontplanes
	Enable_LCD(ON);					// Enable LCD
  }

//=======================================================
//=======================================================
void LCD_RAM_Set_All(){
	byte i;
	for (i=0; i < NUMRAMREGS_FORGLASS; i++){
		*LCD_pos[i] =  0xF;			// next LCD RAM position
	}
}

//=======================================================
//=======================================================
void LCD_RAM_Clear_All(){
	byte i;
	for (i=0; i < NUMRAMREGS_FORGLASS; i++){
		*LCD_pos[i] =  0x0;
	}
}

//--------------------------------------------------------------------


//=======================================
void Set_Logo(byte FSL_logo, byte HY_64_Part_Num, byte Jellyfish_Name, byte Jellyfish_Body, byte Jellyfish_Tentacles) 
  {
  SEG_P21 = FSL_logo;                 //Set LCDRAM for Freescale Logo
  SEG_P1  = HY_64_Part_Num;           //Set LCDRAM for Part Number
  SEG_P2  = Jellyfish_Name;           //Set LCDRAM for Part Name
  SEG_S1  = Jellyfish_Body;           //Set LCDRAM for Part Graphic 1
  SEG_P3  = Jellyfish_Tentacles;      //Set LCDRAM for Part Graphic 2
  }


//=======================================
void  Set_Volt_Bar(byte local_st, byte local_bars) {
  
  char i;
  byte  temp_array[6];
  
  if (local_st == ON)   //Set LCDRAM
    {
    SEG_P14 = 1;  //Turn on Voltage label
		                                                      //fill icon bars 1-6 as requested 
    for (i=0; i < 6; i++)          {temp_array[i] = OFF;} // Clear buffer
    for (i=0; i < local_bars; i++) {temp_array[i] = ON;}  // Fill up to requested value
    
	  SEG_P20 = temp_array[0];	 //icon bars 1-6
    SEG_P19 = temp_array[1];
    SEG_P18 = temp_array[2];
    SEG_P17 = temp_array[3];
    SEG_P16 = temp_array[4];      
    SEG_P15 = temp_array[5];      
    }
  else		
    {
    SEG_P14 = OFF;  //Turn off Voltage label
    SEG_P20 = OFF;	//icon bars 1-6
    SEG_P19 = OFF;
    SEG_P18 = OFF;
    SEG_P17 = OFF;
    SEG_P16 = OFF;      
    SEG_P15 = OFF;      
    }
} 

//=======================================
void  Set_Temp_Bar(byte local_st, byte local_bars) {
  
	char i;
	byte  temp_array[6];
      
	if (local_st == ON){				// Set LCDRAM
		SEG_P6 = ON;					// Turn on Temperature label
											// fill icon bars 1-6 as requested 
		for (i=0; i < 6; i++)            {temp_array[i] = OFF;}	// Clear buffer
		for (i=0; i < local_bars; i++) {temp_array[i] = ON;}	// Fill up to requested value
    
		SEG_P7  = temp_array[0];	// icon bars 1-6
		SEG_P8  = temp_array[1];
		SEG_P9  = temp_array[2];
		SEG_P10 = temp_array[3];
  		SEG_P11 = temp_array[4];      
		SEG_P12 = temp_array[5];      
    } else {
		SEG_P6  = OFF;					// Turn off Temperature label
		SEG_P7  = OFF;					// icon bars 1-6
		SEG_P8  = OFF;	
		SEG_P9  = OFF;
		SEG_P10 = OFF;
  		SEG_P11 = OFF;
  		SEG_P12 = OFF;      
	}
} 


//=======================================
void  Set_Temp_Segs(enum t_temp_type temp_types, enum t_temp_scale temp_scales, char degree_st){ 

	SEG_P4 = OFF;						// all tempsegs off
	SEG_S2 = OFF;
	SEG_P5 = OFF;
	SEG_C  = OFF;
	SEG_F  = OFF;

	switch (temp_types){ 
		case inside_temp:   SEG_P4 = ON;  break;	// "INSIDE"  label
		case outside_temp:  SEG_S2 = ON;  break;	// "OUTSIDE" label
		case engine_temp:   SEG_P5 = ON;  break;	// "ENGINE"  label
	}

	SEG_P6 = ON;   		  			// "TEMP" label

	if(degree_st == ON){
		if(temp_scales == C)  
			SEG_C = ON; 
		else SEG_F = ON;				// "C" or "F"
	}
}


//=======================================
void  Set_Temp_Digits(word temp_value) 
  {
  
  tU08  DIGIT_POS_1,DIGIT_POS_2,DIGIT_POS_3;    // Temporary values for each of the 3 positions
  
  // ----- Set temp value display here.....
  // Dealing with digit positions 1,2, & 3, given 8 bit value
 
  DIGIT_POS_1 = (tU08) temp_value/100;   // Digit 1 = temp_value/100

  switch(DIGIT_POS_1) 
    {
    case 0: display_pos_1_value_0   break;
    case 1: display_pos_1_value_1   break;
    case 2: display_pos_1_value_2   break;
    case 3: display_pos_1_value_3   break;
    case 4: display_pos_1_value_4   break;
    case 5: display_pos_1_value_5   break;
    case 6: display_pos_1_value_6   break;
    case 7: display_pos_1_value_7   break;
    case 8: display_pos_1_value_8   break;
    case 9: display_pos_1_value_9   break;
    }
  
  DIGIT_POS_2 = (tU08) (temp_value - 100*DIGIT_POS_1)/10;   // Digit 2 = (temp_value - 100*DIGIT1)/10

  switch(DIGIT_POS_2) 
    {
    case 0: display_pos_2_value_0   break;
    case 1: display_pos_2_value_1   break;
    case 2: display_pos_2_value_2   break;
    case 3: display_pos_2_value_3   break;
    case 4: display_pos_2_value_4   break;
    case 5: display_pos_2_value_5   break;
    case 6: display_pos_2_value_6   break;
    case 7: display_pos_2_value_7   break;
    case 8: display_pos_2_value_8   break;
    case 9: display_pos_2_value_9   break;
    }

  DIGIT_POS_3 = (tU08) (temp_value - (100*DIGIT_POS_1) - (10*DIGIT_POS_2));   // Digit 3 = (temp_value - (100*DIGIT1) - (10*DIGIT2))

  switch(DIGIT_POS_3) 
    {
    case 0: display_pos_3_value_0   break;
    case 1: display_pos_3_value_1   break;
    case 2: display_pos_3_value_2   break;
    case 3: display_pos_3_value_3   break;
    case 4: display_pos_3_value_4   break;
    case 5: display_pos_3_value_5   break;
    case 6: display_pos_3_value_6   break;
    case 7: display_pos_3_value_7   break;
    case 8: display_pos_3_value_8   break;
    case 9: display_pos_3_value_9   break;
    }
  }



//=======================================
void  Set_Compass(byte local_st, enum t_compass_direction directions){ 

	// -------------- Clear all compass segments
	SEG_T1 = OFF;				// compass surround ring
	SEG_T2 = OFF;				// N
	SEG_T9 = OFF;				// NE
	SEG_T5 = OFF;				// E
	SEG_T8 = OFF;				// SE
	SEG_T3 = OFF;				// S
	SEG_T7 = OFF;				// SW
	SEG_T4 = OFF;				// W
	SEG_T6 = OFF;				// NW

	if (local_st == ON){

		SEG_T1  = ON;				// compass surround ring on
		switch(directions){ 
			case N : SEG_T2 = ON; break;	// turn on compass direction pointer
			case NE: SEG_T9 = ON; break;
			case E : SEG_T5 = ON; break;
			case SE: SEG_T8 = ON; break;
			case S : SEG_T3 = ON; break;
			case SW: SEG_T7 = ON; break;
			case W : SEG_T4 = ON; break;
			case NW: SEG_T6 = ON; break;
		}
	} else {
		SEG_T1  = 0;  // compass surround ring off
	}
} 


//=======================================
void  Set_Odo_Digits(tU16 odo_value){
//void  Set_Odo_Digits(tU16 odo_value) 
//void Set_Odo_Digits(byte val8,byte val9,byte val10,byte val11,byte val12,byte val13){

	tU08  DIGIT_POS_8,DIGIT_POS_9,DIGIT_POS_10,DIGIT_POS_11,DIGIT_POS_12,DIGIT_POS_13;    // Temporary values for each of the 6 positions
	
	
	DIGIT_POS_8 = (tU08) (odo_value)/100000;				// 100,000s digit
	switch(DIGIT_POS_8)
	{ 
		case 0: display_pos_8_value_0   break;
		case 1: display_pos_8_value_1   break;
		case 2: display_pos_8_value_2   break;
		case 3: display_pos_8_value_3   break;
		case 4: display_pos_8_value_4   break;
		case 5: display_pos_8_value_5   break;
 		case 6: display_pos_8_value_6   break;
		case 7: display_pos_8_value_7   break;
		case 8: display_pos_8_value_8   break;
		case 9: display_pos_8_value_9   break;
	}
  
	DIGIT_POS_9 = (tU08) (odo_value-100000*DIGIT_POS_8)/10000;   // 10,000s digit
	switch(DIGIT_POS_9){ 
  		case 0: display_pos_9_value_0   break;
		case 1: display_pos_9_value_1   break;
		case 2: display_pos_9_value_2   break;
		case 3: display_pos_9_value_3   break;
		case 4: display_pos_9_value_4   break;
		case 5: display_pos_9_value_5   break;
		case 6: display_pos_9_value_6   break;
		case 7: display_pos_9_value_7   break;
		case 8: display_pos_9_value_8   break;
		case 9: display_pos_9_value_9   break;
	}

	DIGIT_POS_10 = (tU08) (odo_value-(100000*DIGIT_POS_8)-(10000*DIGIT_POS_9))/1000;   // 1,000s digit
	switch(DIGIT_POS_10){    
		case 0: display_pos_10_value_0   break;
		case 1: display_pos_10_value_1   break;
		case 2: display_pos_10_value_2   break;
		case 3: display_pos_10_value_3   break;
		case 4: display_pos_10_value_4   break;
		case 5: display_pos_10_value_5   break;
		case 6: display_pos_10_value_6   break;
		case 7: display_pos_10_value_7   break;
		case 8: display_pos_10_value_8   break;
		case 9: display_pos_10_value_9   break;
	}

	DIGIT_POS_11 = (tU08) (odo_value-(100000*DIGIT_POS_8)-(10000*DIGIT_POS_9)-(1000*DIGIT_POS_10))/100;   // 100s digit
	switch(DIGIT_POS_11){    
		case 0: display_pos_11_value_0   break;
		case 1: display_pos_11_value_1   break;
		case 2: display_pos_11_value_2   break;
		case 3: display_pos_11_value_3   break;
		case 4: display_pos_11_value_4   break;
		case 5: display_pos_11_value_5   break;
		case 6: display_pos_11_value_6   break;
		case 7: display_pos_11_value_7   break;
		case 8: display_pos_11_value_8   break;
		case 9: display_pos_11_value_9   break;
	}
  
	DIGIT_POS_12 = (tU08) (odo_value-(100000*DIGIT_POS_8)-(10000*DIGIT_POS_9)-(1000*DIGIT_POS_10)-(100*DIGIT_POS_11))/10;   // 10s digit
	switch(DIGIT_POS_12){ 
		case 0: display_pos_12_value_0   break;
		case 1: display_pos_12_value_1   break;
		case 2: display_pos_12_value_2   break;
		case 3: display_pos_12_value_3   break;
		case 4: display_pos_12_value_4   break;
		case 5: display_pos_12_value_5   break;
		case 6: display_pos_12_value_6   break;
		case 7: display_pos_12_value_7   break;
		case 8: display_pos_12_value_8   break;
		case 9: display_pos_12_value_9   break;
	}

	DIGIT_POS_13 = (tU08) (odo_value-(100000*DIGIT_POS_8)-(10000*DIGIT_POS_9)-(1000*DIGIT_POS_10)-(100*DIGIT_POS_11)-(10*DIGIT_POS_12));   // 1s digit
	switch(DIGIT_POS_13){ 
		case 0: display_pos_13_value_0   break;
		case 1: display_pos_13_value_1   break;
		case 2: display_pos_13_value_2   break;
		case 3: display_pos_13_value_3   break;
		case 4: display_pos_13_value_4   break;
		case 5: display_pos_13_value_5   break;
		case 6: display_pos_13_value_6   break;
		case 7: display_pos_13_value_7   break;
		case 8: display_pos_13_value_8   break;
		case 9: display_pos_13_value_9   break;
	}
}


/**********************************************************
*	display Fuel / Clock digits and indicator text
*
*	input		-	count value
*
**********************************************************/

void  Set_Fuel_Clock_Digits(tU16 count){

	tU08  DIGIT_POS_4,DIGIT_POS_5,DIGIT_POS_6,DIGIT_POS_7;    // Temporary values for each of the 6 positions
	
		
	DIGIT_POS_4 = (tU08) (count/1000);   // 1,000s digit
	switch(DIGIT_POS_4){    
		case 0: display_pos_4_value_0   break;
		case 1: display_pos_4_value_1   break;
		case 2: display_pos_4_value_2   break;
		case 3: display_pos_4_value_3   break;
		case 4: display_pos_4_value_4   break;
		case 5: display_pos_4_value_5   break;
		case 6: display_pos_4_value_6   break;
		case 7: display_pos_4_value_7   break;
		case 8: display_pos_4_value_8   break;
		case 9: display_pos_4_value_9   break;
	}

	DIGIT_POS_5 = (tU08) (count-(1000*DIGIT_POS_4))/100;   // 100s digit
	switch(DIGIT_POS_5){    
		case 0: display_pos_5_value_0   break;
		case 1: display_pos_5_value_1   break;
		case 2: display_pos_5_value_2   break;
		case 3: display_pos_5_value_3   break;
		case 4: display_pos_5_value_4   break;
		case 5: display_pos_5_value_5   break;
		case 6: display_pos_5_value_6   break;
		case 7: display_pos_5_value_7   break;
		case 8: display_pos_5_value_8   break;
		case 9: display_pos_5_value_9   break;
	}
  
	DIGIT_POS_6 = (tU08) (count-(1000*DIGIT_POS_4)-(100*DIGIT_POS_5))/10;   // 10s digit
	switch(DIGIT_POS_6){ 
		case 0: display_pos_6_value_0   break;
		case 1: display_pos_6_value_1   break;
		case 2: display_pos_6_value_2   break;
		case 3: display_pos_6_value_3   break;
		case 4: display_pos_6_value_4   break;
		case 5: display_pos_6_value_5   break;
		case 6: display_pos_6_value_6   break;
		case 7: display_pos_6_value_7   break;
		case 8: display_pos_6_value_8   break;
		case 9: display_pos_6_value_9   break;
	}

	DIGIT_POS_7 = (tU08) (count-(1000*DIGIT_POS_4)-(100*DIGIT_POS_5)-(10*DIGIT_POS_6));   // 1s digit
	switch(DIGIT_POS_7){ 
		case 0: display_pos_7_value_0   break;
		case 1: display_pos_7_value_1   break;
		case 2: display_pos_7_value_2   break;
		case 3: display_pos_7_value_3   break;
		case 4: display_pos_7_value_4   break;
		case 5: display_pos_7_value_5   break;
		case 6: display_pos_7_value_6   break;
		case 7: display_pos_7_value_7   break;
		case 8: display_pos_7_value_8   break;
		case 9: display_pos_7_value_9   break;
	}
}


/**********************************************************
* set_fuel_clock_indicators
*
*	turn on selected Fuel / Clock indicator label
*
*	input		- 	label to turn on
*
**********************************************************/
void Set_Fuel_Clock_Labels(byte label){

	Fuel_Clk_Labels_All_Off();					// Fuel / Clock indicators all off

	switch((label) & 0x0F){
		case 0:	AVG 		 = ON;	break;	// AVG label on
		case 1:	INST		 = ON;	break;	// INST label on
		case 2:	FUEL		 = ON;	break;	// FUEL label on
		case 3:	DISTANCE	 = ON;	break;	// DISTANCE label on	
		case 4:	USED		 = ON;	break;	// USED label on
		case 5:	REMAINING = ON;	break;	// REMAINING label on
		case 6:	MPG		 = ON;	break;	// MPG label on
		case 7:	MPH		 = ON;	break;	// MPH label on	
		case 8:	LPK		 = ON;	break;	// L/100km label on
		case 9:	KPH		 = ON;	break;	// km/h label on
		case 10:	GALLONS	 = ON;	break;	// GALLONS label on
		case 11:	LITERS	 = ON;	break;	// LITERS label on	
		case 12:	AM			 = ON;	break;	// AM label on
		case 13:	PM			 = ON;	break;	// PM label on	
		case 14:	CLK_COLON = ON;
					FUEL_DEC	 = ON;	break;	// COLON / DECIMAL labels on	
		case 15:	Fuel_Clk_Labels_All_On(); break;	// all labels on	
	}
}


/**********************************************************
*	fuel_clk_labels_on
*
*	turns all Fuel / Clock indicators off
*
**********************************************************/
void Fuel_Clk_Labels_All_On(void){
	
	AVG			= ON;
	INST			= ON;
	FUEL			= ON;
	DISTANCE		= ON;
	USED 			= ON;
	REMAINING	= ON;
	MPG			= ON;
	MPH			= ON;
	LPK			= ON;
	KPH			= ON;
	GALLONS		= ON;
	LITERS		= ON;
	AM				= ON;
	PM				= ON;
}


/**********************************************************
*	turn Fuel / Clock digits and indicator labels off
*
*	input		-	none
*
**********************************************************/

void  Set_Odo_Digits_Off(void){
	
	display_pos_8_value_off;		// digit 4 off
	display_pos_9_value_off;		// digit 5 off
	display_pos_10_value_off;		// digit 6 off
	display_pos_11_value_off;		// digit 7 off
	display_pos_12_value_off;		// digit 7 off
	display_pos_13_value_off;		// digit 7 off
}


/**********************************************************
*	fuel_clk_labels_off
*
*	turns all Fuel / Clock indicators off
*
**********************************************************/
void Fuel_Clk_Labels_All_Off(void){
	
	AVG			= OFF;
	INST			= OFF;
	FUEL			= OFF;
	DISTANCE		= OFF;
	USED 			= OFF;
	REMAINING	= OFF;
	MPG			= OFF;
	MPH			= OFF;
	LPK			= OFF;
	KPH			= OFF;
	GALLONS		= OFF;
	LITERS		= OFF;
	AM				= OFF;
	PM				= OFF;
	CLK_COLON	= OFF;
	FUEL_DEC		= OFF;
}


/**********************************************************
*	Set_FC_Labels_All_Off
*
*	turns all Fuel / Clock indicators off
*
**********************************************************/
void Set_FC_Labels_All_Off(void){
	
	ODO			= OFF;
	TRIPA			= OFF;
	TRIPB			= OFF;
	ODO_DEC		= OFF;
	MI 			= OFF;
	KM				= OFF;
}


/**********************************************************
*	turn Fuel / Clock digits and indicator labels off
*
*	input		-	none
*
**********************************************************/

void  Set_Fuel_Clock_Digits_Off(void){
	
	Fuel_Clk_Labels_All_Off();		// turn off Fuel/Clock lables off
	display_pos_4_value_off;		// digit 4 off
	display_pos_5_value_off;		// digit 5 off
	display_pos_6_value_off;		// digit 6 off
	display_pos_7_value_off;		// digit 7 off
}


/**********************************************************
*	Set_Compass_All_Off
*
*	turns all Temp indicators & digits off
*
**********************************************************/
void Set_Compass_All_Off(void){
	COMP_RING	= OFF;
	COMP_N		= OFF;
	COMP_S		= OFF;
	COMP_E		= OFF;
	COMP_W		= OFF;
	COMP_NE		= OFF;
	COMP_NW		= OFF;
	COMP_SE		= OFF;
	COMP_SW		= OFF;
}


/**********************************************************
*	Set_Temp_Labels_All_Off
*
*	turns all Temperature Indicator Labels, Temp & Volt Bars,
*	& Temp Digits off
*
**********************************************************/
void Set_Temp_Labels_All_Off(void){
	
	INSIDE		= OFF;
	OUTSIDE		= OFF;
	ENGINE		= OFF;
	TEMP			= OFF;
	TEMP_DEC		= OFF;
	DEG_C			= OFF;
	DEG_F			= OFF;
	SYS_V			= OFF;
	
	TEMP_BAR_1	= OFF;
	TEMP_BAR_2	= OFF;
	TEMP_BAR_3	= OFF;
	TEMP_BAR_4	= OFF;
	TEMP_BAR_5	= OFF;
	TEMP_BAR_6	= OFF;

	VOLT_BAR_1	= OFF;
	VOLT_BAR_2	= OFF;
	VOLT_BAR_3	= OFF;
	VOLT_BAR_4	= OFF;
	VOLT_BAR_5	= OFF;
	VOLT_BAR_6	= OFF;
	
	display_pos_1_value_off;		// digit 1 off
	display_pos_2_value_off;		// digit 2 off
	display_pos_3_value_off;		// digit 3 off
}


/**********************************************************
*	Set_Gear_Labels_All_Off
*
*	turns all Temp indicators & digits off
*
**********************************************************/
void Set_Gear_Labels_All_Off(void){
	GEARS			= OFF;
	GEAR_P		= OFF;
	GEAR_R		= OFF;
	GEAR_N		= OFF;
	GEAR_D		= OFF;
	GEAR_3		= OFF;
	GEAR_2		= OFF;
	GEAR_1		= OFF;
}


/**********************************************************
*	Set_Temp_Bar_All_OFF
*
*	set all voltage bars off
*
**********************************************************/
void Set_Temp_Bar_All_OFF(void){
	
	TEMP_BAR_1 = OFF;	
	TEMP_BAR_2 = OFF;	
	TEMP_BAR_3 = OFF;	
	TEMP_BAR_4 = OFF;	
	TEMP_BAR_5 = OFF;	
	TEMP_BAR_6 = OFF;	
}


/**********************************************************
*	Set_Volt_Bar_All_OFF
*
*	set all voltage bars off
*
**********************************************************/
void Set_Volt_Bar_All_OFF(void){
	
	VOLT_BAR_1 = OFF;	
	VOLT_BAR_2 = OFF;	
	VOLT_BAR_3 = OFF;	
	VOLT_BAR_4 = OFF;	
	VOLT_BAR_5 = OFF;	
	VOLT_BAR_6 = OFF;	
}


//=======================================
void  Set_Gear (char local_st, enum t_transmission_gear gears){

	if(SEG_S5==OFF) SEG_S5 = ON;	// Turn on PRND321 segment if not already on
  
	// -------------- Clear all transmission segments
	SEG_P = OFF;
	SEG_R = OFF;
	SEG_N = OFF;
	SEG_D = OFF;
	SEG_3 = OFF;
	SEG_2 = OFF;
	SEG_1 = OFF; 

	if (local_st == ON){
		switch(gears){
			case Park     : SEG_P = ON; break;	// Turn on selected gear indicator
			case Reverse  : SEG_R = ON; break;
			case Neutral  : SEG_N = ON; break;
			case Drive    : SEG_D = ON; break;
			case Third    : SEG_3 = ON; break;
			case Second   : SEG_2 = ON; break;
			case First    : SEG_1 = ON; break;
		}
	}
}


/**********************************************************\
*	Set_Trip
*
*	turn TRIP A/B label on or off
*
*	input		- state, 0 = off, 1 = on
*				  trip, 	0 = TRIPA, 1 = TRIPB
*
**********************************************************/
void Set_Trip(byte state, byte trip){
	
	if(state){						// if enabled, turn on selected TRIP indicator
		if(trip) TRIPA = ON;
			else TRIPB = ON;
	} else {							// turn of both trip indicators
		TRIPA = OFF;
		TRIPB = OFF;
	}
}


/**********************************************************\
*	Set_Mi_Km
*
*	turn MILES or KM label on or off
*
*	input		- state, 0 = off, 1 = on
*				  trip, 	0 = TRIPA, 1 = TRIPB
*
**********************************************************/
void Set_Mi_Km(byte state, byte sc){
	
	if(state){						// if enabled, turn on selected scale indicator
		if(sc) MI = ON;
			else KM = ON;
	} else {							// turn of both scale indicators
		MI = OFF;
		KM = OFF;
	}
}


/**********************************************************\
*	Set_Cruise
*
*	turn on cruise label on or off
*
*	input		- state, 0 = off, 1 = on
*
**********************************************************/
void Set_Cruise(byte state){
	
	if(state) CRUISE = ON;			// turn on cruise label if required
	else CRUISE = OFF;				// turn off cruise label
}


/**********************************************************\
*	Set_Cruise_State
*
*	turn on cruise state label
*
*	input		-	state, 0 = off, 1 = on
*
**********************************************************/
void Set_Cruise_State(byte state){
	
	if(state) ENGAGED = ON;			// turn on cruise state label if required
	else ENGAGED = OFF;				// turn off cruise state label
}


/**********************************************************\
*	Set_Traction
*
*	turn on traction label on or off
*
*	input		- state, 0 = off, 1 = on
*
**********************************************************/
void Set_Traction(byte state){
	
	if(state) TRACTION = ON;		// turn on traction label if required
	else TRACTION = OFF;				// turn off traction label
}


/**********************************************************\
*	Set_Traction_State
*
*	turn on traction state label
*
*	input		-	state, 0 = off, 1 = on
*
**********************************************************/
void Set_Traction_State(byte state){
	

	if(state) TRAC_OFF = ON;		// turn on traction state label if required
	else TRAC_OFF = OFF;				// turn off traction state label
}


/**********************************************************\
*	Set_TPMS_State
*
*	turn on TPMS state label
*
*	input		-	state, 0 = off, 1 = on
*
**********************************************************/
void Set_TPMS_State(byte state){
	
	if(state) TPMS = ON;				// turn on TMPS label if required
	else TPMS = OFF;					// turn off TPMS label
}

/**********************************************************
*	Set_Status_Labels
*
*	turn Cruise / Traction / TPMS status labels on and off
*
**********************************************************/
void Set_Status_Labels(byte label){
	
	Set_Cruise_State(OFF);								// set labels off
	Set_Traction_State(OFF);
	Set_TPMS_State(OFF);
	

	switch(label){
		case 0:	Set_Cruise_State(ON);	break;	// set cruise state to on
		case 1:	Set_Traction_State(ON); 		break;	// set traction state to on
		case 2:	Set_TPMS_State(ON);		break;	// set tpms state to on 
	}
}


/*********************************************************
* 
* The following functions provide individual control of 
* digits 1 - 13.  Digit displays value passed in funtion call 
*
**********************************************************/
void Set_Digit_1(byte value){

	byte DIGIT_POS_1;

	DIGIT_POS_1 = value;
	switch(DIGIT_POS_1)
	{ 
		case 0x00: display_pos_1_value_0   break;
		case 0x01: display_pos_1_value_1   break;
		case 0x02: display_pos_1_value_2   break;
		case 0x03: display_pos_1_value_3   break;
		case 0x04: display_pos_1_value_4   break;
		case 0x05: display_pos_1_value_5   break;
 		case 0x06: display_pos_1_value_6   break;
		case 0x07: display_pos_1_value_7   break;
		case 0x08: display_pos_1_value_8   break;
		case 0x09: display_pos_1_value_9   break;
		case 0x0A: display_pos_1_value_A   break;
		case 0x0B: display_pos_1_value_B   break;
    case 0x0C: display_pos_1_value_C   break;
    case 0x0D: display_pos_1_value_D   break;
    case 0x0E: display_pos_1_value_E   break;	
    case 0x0F: display_pos_1_value_F   break;
    case DIGIT_OFF: display_pos_1_value_off break;
    default: 	 display_pos_1_value_X   break;		
	}
}
void Set_Digit_2(byte value){

	byte DIGIT_POS_2;

	DIGIT_POS_2 = value;
	switch(DIGIT_POS_2)
	{ 
		case 0x00: display_pos_2_value_0   break;
		case 0x01: display_pos_2_value_1   break;
		case 0x02: display_pos_2_value_2   break;
		case 0x03: display_pos_2_value_3   break;
		case 0x04: display_pos_2_value_4   break;
		case 0x05: display_pos_2_value_5   break;
 		case 0x06: display_pos_2_value_6   break;
		case 0x07: display_pos_2_value_7   break;
		case 0x08: display_pos_2_value_8   break;
		case 0x09: display_pos_2_value_9   break;
		case 0x0A: display_pos_2_value_A   break;
		case 0x0B: display_pos_2_value_B   break;
    case 0x0C: display_pos_2_value_C   break;
    case 0x0D: display_pos_2_value_D   break;
    case 0x0E: display_pos_2_value_E   break;	
    case 0x0F: display_pos_2_value_F   break;		
	  case DIGIT_OFF: display_pos_2_value_off break;    	
    default: 	 display_pos_2_value_X   break;		    	
	}
}
void Set_Digit_3(byte value){

	byte DIGIT_POS_3;

	DIGIT_POS_3 = value;
	switch(DIGIT_POS_3)
	{ 
		case 0x00: display_pos_3_value_0   break;
		case 0x01: display_pos_3_value_1   break;
		case 0x02: display_pos_3_value_2   break;
		case 0x03: display_pos_3_value_3   break;
		case 0x04: display_pos_3_value_4   break;
		case 0x05: display_pos_3_value_5   break;
 		case 0x06: display_pos_3_value_6   break;
		case 0x07: display_pos_3_value_7   break;
		case 0x08: display_pos_3_value_8   break;
		case 0x09: display_pos_3_value_9   break;
		case 0x0A: display_pos_3_value_A   break;
		case 0x0B: display_pos_3_value_B   break;
    case 0x0C: display_pos_3_value_C   break;
    case 0x0D: display_pos_3_value_D   break;
    case 0x0E: display_pos_3_value_E   break;	
    case 0x0F: display_pos_3_value_F   break;	
		case DIGIT_OFF: display_pos_3_value_off break;    	    	
    default: 	 display_pos_3_value_X   break;			
	}
}
void Set_Digit_4(byte value){

	byte DIGIT_POS_4;

	DIGIT_POS_4 = value;
	switch(DIGIT_POS_4)
	{ 
		case 0x00: display_pos_4_value_0   break;
		case 0x01: display_pos_4_value_1   break;
		case 0x02: display_pos_4_value_2   break;
		case 0x03: display_pos_4_value_3   break;
		case 0x04: display_pos_4_value_4   break;
		case 0x05: display_pos_4_value_5   break;
 		case 0x06: display_pos_4_value_6   break;
		case 0x07: display_pos_4_value_7   break;
		case 0x08: display_pos_4_value_8   break;
		case 0x09: display_pos_4_value_9   break;
		case 0x0A: display_pos_4_value_A   break;
		case 0x0B: display_pos_4_value_B   break;
    case 0x0C: display_pos_4_value_C   break;
    case 0x0D: display_pos_4_value_D   break;
    case 0x0E: display_pos_4_value_E   break;
    case 0x0F: display_pos_4_value_F   break;
    case DIGIT_OFF: display_pos_4_value_off break;    	    	    	
    default: 	 display_pos_4_value_X   break;					
	}
}

void Set_Digit_5(byte value){

	byte DIGIT_POS_5;

	DIGIT_POS_5 = value;
	switch(DIGIT_POS_5)
	{ 
		case 0x00: display_pos_5_value_0   break;
		case 0x01: display_pos_5_value_1   break;
		case 0x02: display_pos_5_value_2   break;
		case 0x03: display_pos_5_value_3   break;
		case 0x04: display_pos_5_value_4   break;
		case 0x05: display_pos_5_value_5   break;
 		case 0x06: display_pos_5_value_6   break;
		case 0x07: display_pos_5_value_7   break;
		case 0x08: display_pos_5_value_8   break;
		case 0x09: display_pos_5_value_9   break;
		case 0x0A: display_pos_5_value_A   break;
		case 0x0B: display_pos_5_value_B   break;
    case 0x0C: display_pos_5_value_C   break;
    case 0x0D: display_pos_5_value_D   break;
    case 0x0E: display_pos_5_value_E   break;	
    case 0x0F: display_pos_5_value_F   break;		
		case DIGIT_OFF: display_pos_5_value_off break;    	    	    	
    default: 	 display_pos_5_value_X   break;		
	}
}

void Set_Digit_6(byte value){

	byte DIGIT_POS_6;

	DIGIT_POS_6 = value;
	switch(DIGIT_POS_6)
	{ 
		case 0x00: display_pos_6_value_0   break;
		case 0x01: display_pos_6_value_1   break;
		case 0x02: display_pos_6_value_2   break;
		case 0x03: display_pos_6_value_3   break;
		case 0x04: display_pos_6_value_4   break;
		case 0x05: display_pos_6_value_5   break;
 		case 0x06: display_pos_6_value_6   break;
		case 0x07: display_pos_6_value_7   break;
		case 0x08: display_pos_6_value_8   break;
		case 0x09: display_pos_6_value_9   break;
		case 0x0A: display_pos_6_value_A   break;
		case 0x0B: display_pos_6_value_B   break;
    case 0x0C: display_pos_6_value_C   break;
    case 0x0D: display_pos_6_value_D   break;
    case 0x0E: display_pos_6_value_E   break;	
    case 0x0F: display_pos_6_value_F   break;		
    case DIGIT_OFF: display_pos_6_value_off break;    	    	
    default: 	 display_pos_6_value_X   break;	
	}
}

void Set_Digit_7(byte value){

	byte DIGIT_POS_7;

	DIGIT_POS_7 = value;
	switch(DIGIT_POS_7)
	{ 
		case 0x00: display_pos_7_value_0   break;
		case 0x01: display_pos_7_value_1   break;
		case 0x02: display_pos_7_value_2   break;
		case 0x03: display_pos_7_value_3   break;
		case 0x04: display_pos_7_value_4   break;
		case 0x05: display_pos_7_value_5   break;
 		case 0x06: display_pos_7_value_6   break;
		case 0x07: display_pos_7_value_7   break;
		case 0x08: display_pos_7_value_8   break;
		case 0x09: display_pos_7_value_9   break;
		case 0x0A: display_pos_7_value_A   break;
		case 0x0B: display_pos_7_value_B   break;
    case 0x0C: display_pos_7_value_C   break;
    case 0x0D: display_pos_7_value_D   break;
    case 0x0E: display_pos_7_value_E   break;	
    case 0x0F: display_pos_7_value_F   break;		
    case DIGIT_OFF: display_pos_7_value_off break;
    default: 	 display_pos_7_value_X   break;	 	
	}
}

void Set_Digit_8(byte value){

	byte DIGIT_POS_8;

	DIGIT_POS_8 = value;
	switch(DIGIT_POS_8)
	{ 
		case 0x00: display_pos_8_value_0   break;
		case 0x01: display_pos_8_value_1   break;
		case 0x02: display_pos_8_value_2   break;
		case 0x03: display_pos_8_value_3   break;
		case 0x04: display_pos_8_value_4   break;
		case 0x05: display_pos_8_value_5   break;
 		case 0x06: display_pos_8_value_6   break;
		case 0x07: display_pos_8_value_7   break;
		case 0x08: display_pos_8_value_8   break;
		case 0x09: display_pos_8_value_9   break;
		case 0x0A: display_pos_8_value_A   break;
		case 0x0B: display_pos_8_value_B   break;
    case 0x0C: display_pos_8_value_C   break;
    case 0x0D: display_pos_8_value_D   break;
    case 0x0E: display_pos_8_value_E   break;	
    case 0x0F: display_pos_8_value_F   break;
    case DIGIT_OFF: display_pos_8_value_off break;    	    		
    default: 	 display_pos_8_value_X   break;	 	
	}
}


void Set_Digit_9(byte value){

	byte DIGIT_POS_9;

	DIGIT_POS_9 = value;
	switch(DIGIT_POS_9)
	{ 
		case 0x00: display_pos_9_value_0   break;
		case 0x01: display_pos_9_value_1   break;
		case 0x02: display_pos_9_value_2   break;
		case 0x03: display_pos_9_value_3   break;
		case 0x04: display_pos_9_value_4   break;
		case 0x05: display_pos_9_value_5   break;
 		case 0x06: display_pos_9_value_6   break;
		case 0x07: display_pos_9_value_7   break;
		case 0x08: display_pos_9_value_8   break;
		case 0x09: display_pos_9_value_9   break;
		case 0x0A: display_pos_9_value_A   break;
		case 0x0B: display_pos_9_value_B   break;
    case 0x0C: display_pos_9_value_C   break;
    case 0x0D: display_pos_9_value_D   break;
    case 0x0E: display_pos_9_value_E   break;	
    case 0x0F: display_pos_9_value_F   break;
    case DIGIT_OFF: display_pos_9_value_off break;    	    		
    default: 	 display_pos_9_value_X   break;	

	}
}


void Set_Digit_10(byte value){

	byte DIGIT_POS_10;

	DIGIT_POS_10 = value;
	switch(DIGIT_POS_10)
	{ 
		case 0x00: display_pos_10_value_0   break;
		case 0x01: display_pos_10_value_1   break;
		case 0x02: display_pos_10_value_2   break;
		case 0x03: display_pos_10_value_3   break;
		case 0x04: display_pos_10_value_4   break;
		case 0x05: display_pos_10_value_5   break;
 		case 0x06: display_pos_10_value_6   break;
		case 0x07: display_pos_10_value_7   break;
		case 0x08: display_pos_10_value_8   break;
		case 0x09: display_pos_10_value_9   break;
		case 0x0A: display_pos_10_value_A   break;
		case 0x0B: display_pos_10_value_B   break;
    case 0x0C: display_pos_10_value_C   break;
    case 0x0D: display_pos_10_value_D   break;
    case 0x0E: display_pos_10_value_E   break;	
    case 0x0F: display_pos_10_value_F   break;
    case DIGIT_OFF: display_pos_10_value_off break;    	    		    	
    default: 	 display_pos_10_value_X   break;	    	
	}
}


void Set_Digit_11(byte value){

	byte DIGIT_POS_11;

	DIGIT_POS_11 = value;
	switch(DIGIT_POS_11)
	{ 
		case 0x00: display_pos_11_value_0   break;
		case 0x01: display_pos_11_value_1   break;
		case 0x02: display_pos_11_value_2   break;
		case 0x03: display_pos_11_value_3   break;
		case 0x04: display_pos_11_value_4   break;
		case 0x05: display_pos_11_value_5   break;
 		case 0x06: display_pos_11_value_6   break;
		case 0x07: display_pos_11_value_7   break;
		case 0x08: display_pos_11_value_8   break;
		case 0x09: display_pos_11_value_9   break;
		case 0x0A: display_pos_11_value_A   break;
		case 0x0B: display_pos_11_value_B   break;
    case 0x0C: display_pos_11_value_C   break;
    case 0x0D: display_pos_11_value_D   break;
    case 0x0E: display_pos_11_value_E   break;	
    case 0x0F: display_pos_11_value_F   break;
    case DIGIT_OFF: display_pos_11_value_off break;    	    		    	    	
    default: 	 display_pos_11_value_X   break;	    	
	}
}


void Set_Digit_12(byte value){

	byte DIGIT_POS_12;

	DIGIT_POS_12 = value;
	switch(DIGIT_POS_12)
	{ 
		case 0x00: display_pos_12_value_0   break;
		case 0x01: display_pos_12_value_1   break;
		case 0x02: display_pos_12_value_2   break;
		case 0x03: display_pos_12_value_3   break;
		case 0x04: display_pos_12_value_4   break;
		case 0x05: display_pos_12_value_5   break;
 		case 0x06: display_pos_12_value_6   break;
		case 0x07: display_pos_12_value_7   break;
		case 0x08: display_pos_12_value_8   break;
		case 0x09: display_pos_12_value_9   break;
		case 0x0A: display_pos_12_value_A   break;
		case 0x0B: display_pos_12_value_B   break;
    case 0x0C: display_pos_12_value_C   break;
    case 0x0D: display_pos_12_value_D   break;
    case 0x0E: display_pos_12_value_E   break;	
    case 0x0F: display_pos_12_value_F   break;
    case DIGIT_OFF: display_pos_12_value_off break;    	    		    	    		
    default: 	 display_pos_12_value_X   break;	    	
	}
}


void Set_Digit_13(byte value){

	byte DIGIT_POS_13;

	DIGIT_POS_13 = value;
	switch(DIGIT_POS_13)
	{ 
		case 0x00: display_pos_13_value_0   break;
		case 0x01: display_pos_13_value_1   break;
		case 0x02: display_pos_13_value_2   break;
		case 0x03: display_pos_13_value_3   break;
		case 0x04: display_pos_13_value_4   break;
		case 0x05: display_pos_13_value_5   break;
 		case 0x06: display_pos_13_value_6   break;
		case 0x07: display_pos_13_value_7   break;
		case 0x08: display_pos_13_value_8   break;
		case 0x09: display_pos_13_value_9   break;
		case 0x0A: display_pos_13_value_A   break;
		case 0x0B: display_pos_13_value_B   break;
    case 0x0C: display_pos_13_value_C   break;
    case 0x0D: display_pos_13_value_D   break;
    case 0x0E: display_pos_13_value_E   break;	
    case 0x0F: display_pos_13_value_F   break;
    case DIGIT_OFF: display_pos_13_value_off break;    	    		    	    		
    default: 	 display_pos_13_value_X   break;	    	
	}
}


/*********************************************************
* 	Display_On
* 
*	turn on all elements of display
**********************************************************/
void Display_On(){

	display_pos_1_value_8;
	display_pos_2_value_8;
	display_pos_3_value_8;
	display_pos_4_value_8;
	display_pos_5_value_8;
	display_pos_6_value_8;
	display_pos_7_value_8;
	display_pos_8_value_8;
	display_pos_9_value_8;
	display_pos_10_value_8;
	display_pos_11_value_8;
	display_pos_12_value_8;
	display_pos_13_value_8;
	
	Fuel_Clk_Labels_All_On();
	
	INSIDE = ON;
	OUTSIDE = ON;
	ENGINE = ON;
	TEMP = ON;
	TEMP_DEC = ON;
	DEG_C = ON;
	DEG_F = ON;
	SYS_V = ON;
	
	
	GEARS = ON;
	GEAR_P = ON;
	GEAR_R = ON;
	GEAR_N = ON;
	GEAR_D = ON;
	GEAR_3 = ON;
	GEAR_2 = ON;
	GEAR_1 = ON;
	
	CRUISE = ON;
	TRACTION = ON;
	TPMS = ON;
	ENGAGED = ON;
	TRAC_OFF = ON;
	
	ODO = ON;
	TRIPA = ON;
	TRIPB = ON;
	ODO_DEC = ON;
	MI = ON;
	KM = ON;
	
	COMP_RING = ON;
	COMP_N = ON;
	COMP_S = ON;
	COMP_E = ON;
	COMP_W = ON;
	COMP_NE = ON;
	COMP_NW = ON;
	COMP_SE = ON;
	COMP_SW = ON;
}

void Display_Off(){

	display_pos_1_value_off;
	display_pos_2_value_off;
	display_pos_3_value_off;
	display_pos_4_value_off;
	display_pos_5_value_off;
	display_pos_6_value_off;
	display_pos_7_value_off;
	display_pos_8_value_off;
	display_pos_9_value_off;
	display_pos_10_value_off;
	display_pos_11_value_off;
	display_pos_12_value_off;
	display_pos_13_value_off;
	
	Fuel_Clk_Labels_All_Off();
	
	INSIDE = OFF;
	OUTSIDE = OFF;
	ENGINE = OFF;
	TEMP = OFF;
	TEMP_DEC = OFF;
	DEG_C = OFF;
	DEG_F = OFF;
	SYS_V = OFF;
	
	
	GEARS =  OFF;
	GEAR_P = OFF;
	GEAR_R = OFF;
	GEAR_N = OFF;
	GEAR_D = OFF;
	GEAR_3 = OFF;
	GEAR_2 = OFF;
	GEAR_1 = OFF;
	
	CRUISE = 		OFF;
	TRACTION =  OFF;
	TPMS = 			OFF;
	ENGAGED = 	OFF;
	TRAC_OFF = 	OFF;
	
	ODO = 		OFF;
	TRIPA = 	OFF;
	TRIPB = 	OFF;
	ODO_DEC = OFF;
	MI = OFF;
	KM = OFF;
	
	COMP_RING = 	OFF;
	COMP_N =		  OFF;
	COMP_S = 			OFF;
	COMP_E = 			OFF;
	COMP_W = 			OFF;
	COMP_NE = 		OFF;
	COMP_NW = 		OFF;
	COMP_SE = 		OFF;
	COMP_SW = 		OFF;
}