/********************************************************************** 
GD5506P LCD Glass DIGIT Segment Mapping for DEMO9S12HY64                
************************************************************************/
//
// These defines provide easier to read code to turn segments on/off for specific digits in specifc LCD locations.
// Because each segment of each LCD digit may map to any LCD RAM bit location, this provides regular definition of 
// how to display any given digit in any given location.  This must be used in conjunction with GD-5506P.h for the hardware in use.
//  Last Updated on 39763
//


// Fuel / Clock Label Defines
#define	AVG			SEG_P22
#define	INST			SEG_P23
#define	FUEL			SEG_P24
#define	DISTANCE		SEG_P25
#define	USED			SEG_P26
#define	REMAINING	SEG_P27
#define	AM				SEG_AM
#define	PM				SEG_PM
#define	MPG			SEG_P28
#define	MPH			SEG_P29
#define	LPK			SEG_P30
#define	KPH			SEG_P31
#define	LITERS		SEG_P32
#define	GALLONS		SEG_P33
#define	CLK_COLON	SEG_R2
#define	FUEL_DEC		SEG_R3

// Cruise / Traction / TPMS Label Defines
#define	CRUISE		SEG_P36
#define	TRACTION		SEG_P37
#define	TPMS			SEG_P39
#define	ENGAGED		SEG_S4
#define	TRAC_OFF		SEG_S3

#define	ODO			SEG_P40
#define 	TRIPA			SEG_P41
#define	TRIPB			SEG_P42
#define	ODO_DEC		SEG_R4
#define	MI				SEG_P34
#define	KM				SEG_P35

// Temperature Label Defines
#define INSIDE			SEG_P4
#define ENGINE			SEG_P5
#define TEMP			SEG_P6
#define OUTSIDE		SEG_S2
#define TEMP_DEC		SEG_R1
#define DEG_C			SEG_C
#define DEG_F			SEG_F
#define SYS_V			SEG_P14

// Temperature Bar Defines
#define TEMP_BAR_1	SEG_P7
#define TEMP_BAR_2	SEG_P8
#define TEMP_BAR_3	SEG_P9
#define TEMP_BAR_4	SEG_P10
#define TEMP_BAR_5	SEG_P11
#define TEMP_BAR_6	SEG_P12

// Voltage Bar Defines
#define VOLT_BAR_1	SEG_P20
#define VOLT_BAR_2	SEG_P19
#define VOLT_BAR_3	SEG_P18
#define VOLT_BAR_4	SEG_P17
#define VOLT_BAR_5	SEG_P16
#define VOLT_BAR_6	SEG_P15

// Gear Shift Defines
#define GEARS			SEG_S5
#define GEAR_P			SEG_P
#define GEAR_R			SEG_R
#define GEAR_N			SEG_N
#define GEAR_D			SEG_D
#define GEAR_3			SEG_3
#define GEAR_2			SEG_2
#define GEAR_1			SEG_1

// Compass Defines
#define COMP_RING		SEG_T1
#define COMP_N			SEG_T2
#define COMP_S			SEG_T3
#define COMP_E			SEG_T5
#define COMP_W			SEG_T4
#define COMP_NE		SEG_T9
#define COMP_NW		SEG_T6
#define COMP_SE		SEG_T8
#define COMP_SW		SEG_T7


// Temperature Display Digits - Position 1
#define     display_pos_1_value_off   SEG_1A=OFF; SEG_1B=OFF; SEG_1C=OFF; SEG_1D=OFF; SEG_1E=OFF; SEG_1F=OFF; SEG_1G=OFF; 
#define     display_pos_1_value_dash  SEG_1A=OFF; SEG_1B=OFF; SEG_1C=OFF; SEG_1D=OFF; SEG_1E=OFF; SEG_1F=OFF; SEG_1G=ON; 
#define     display_pos_1_value_0     SEG_1A=ON; SEG_1B=ON; SEG_1C=ON; SEG_1D=ON; SEG_1E=ON; SEG_1F=ON; SEG_1G=OFF; 
#define     display_pos_1_value_1     SEG_1A=OFF; SEG_1B=ON; SEG_1C=ON; SEG_1D=OFF; SEG_1E=OFF; SEG_1F=OFF; SEG_1G=OFF; 
#define     display_pos_1_value_2     SEG_1A=ON; SEG_1B=ON; SEG_1C=OFF; SEG_1D=ON; SEG_1E=ON; SEG_1F=OFF; SEG_1G=ON; 
#define     display_pos_1_value_3     SEG_1A=ON; SEG_1B=ON; SEG_1C=ON; SEG_1D=ON; SEG_1E=OFF; SEG_1F=OFF; SEG_1G=ON; 
#define     display_pos_1_value_4     SEG_1A=OFF; SEG_1B=ON; SEG_1C=ON; SEG_1D=OFF; SEG_1E=OFF; SEG_1F=ON; SEG_1G=ON; 
#define     display_pos_1_value_5     SEG_1A=ON; SEG_1B=OFF; SEG_1C=ON; SEG_1D=ON; SEG_1E=OFF; SEG_1F=ON; SEG_1G=ON; 
#define     display_pos_1_value_6     SEG_1A=ON; SEG_1B=OFF; SEG_1C=ON; SEG_1D=ON; SEG_1E=ON; SEG_1F=ON; SEG_1G=ON; 
#define     display_pos_1_value_7     SEG_1A=ON; SEG_1B=ON; SEG_1C=ON; SEG_1D=OFF; SEG_1E=OFF; SEG_1F=ON; SEG_1G=OFF; 
#define     display_pos_1_value_8     SEG_1A=ON; SEG_1B=ON; SEG_1C=ON; SEG_1D=ON; SEG_1E=ON; SEG_1F=ON; SEG_1G=ON; 
#define     display_pos_1_value_9     SEG_1A=ON; SEG_1B=ON; SEG_1C=ON; SEG_1D=ON; SEG_1E=OFF; SEG_1F=ON; SEG_1G=ON; 
#define     display_pos_1_value_A     SEG_1A=ON; SEG_1B=ON; SEG_1C=ON; SEG_1D=OFF; SEG_1E=ON; SEG_1F=ON; SEG_1G=ON; 
#define     display_pos_1_value_B     SEG_1A=OFF; SEG_1B=OFF; SEG_1C=ON; SEG_1D=ON; SEG_1E=ON; SEG_1F=ON; SEG_1G=ON; 
#define     display_pos_1_value_C     SEG_1A=ON; SEG_1B=OFF; SEG_1C=OFF; SEG_1D=ON; SEG_1E=ON; SEG_1F=ON; SEG_1G=OFF; 
#define     display_pos_1_value_D     SEG_1A=OFF; SEG_1B=ON; SEG_1C=ON; SEG_1D=ON; SEG_1E=ON; SEG_1F=OFF; SEG_1G=ON; 
#define     display_pos_1_value_E     SEG_1A=ON; SEG_1B=OFF; SEG_1C=OFF; SEG_1D=ON; SEG_1E=ON; SEG_1F=ON; SEG_1G=ON; 
#define     display_pos_1_value_F     SEG_1A=ON; SEG_1B=OFF; SEG_1C=OFF; SEG_1D=OFF; SEG_1E=ON; SEG_1F=ON; SEG_1G=ON; 
#define     display_pos_1_value_X     SEG_1A=OFF; SEG_1B=OFF; SEG_1C=OFF; SEG_1D=OFF; SEG_1E=OFF; SEG_1F=OFF; SEG_1G=ON; 

// Temperature Display Digits - Position 2
#define     display_pos_2_value_off   SEG_2A=OFF; SEG_2B=OFF; SEG_2C=OFF; SEG_2D=OFF; SEG_2E=OFF; SEG_2F=OFF; SEG_2G=OFF; 
#define     display_pos_2_value_dash  SEG_2A=OFF; SEG_2B=OFF; SEG_2C=OFF; SEG_2D=OFF; SEG_2E=OFF; SEG_2F=OFF; SEG_2G=ON; 
#define     display_pos_2_value_0     SEG_2A=ON; SEG_2B=ON; SEG_2C=ON; SEG_2D=ON; SEG_2E=ON; SEG_2F=ON; SEG_2G=OFF; 
#define     display_pos_2_value_1     SEG_2A=OFF; SEG_2B=ON; SEG_2C=ON; SEG_2D=OFF; SEG_2E=OFF; SEG_2F=OFF; SEG_2G=OFF; 
#define     display_pos_2_value_2     SEG_2A=ON; SEG_2B=ON; SEG_2C=OFF; SEG_2D=ON; SEG_2E=ON; SEG_2F=OFF; SEG_2G=ON; 
#define     display_pos_2_value_3     SEG_2A=ON; SEG_2B=ON; SEG_2C=ON; SEG_2D=ON; SEG_2E=OFF; SEG_2F=OFF; SEG_2G=ON; 
#define     display_pos_2_value_4     SEG_2A=OFF; SEG_2B=ON; SEG_2C=ON; SEG_2D=OFF; SEG_2E=OFF; SEG_2F=ON; SEG_2G=ON; 
#define     display_pos_2_value_5     SEG_2A=ON; SEG_2B=OFF; SEG_2C=ON; SEG_2D=ON; SEG_2E=OFF; SEG_2F=ON; SEG_2G=ON; 
#define     display_pos_2_value_6     SEG_2A=ON; SEG_2B=OFF; SEG_2C=ON; SEG_2D=ON; SEG_2E=ON; SEG_2F=ON; SEG_2G=ON; 
#define     display_pos_2_value_7     SEG_2A=ON; SEG_2B=ON; SEG_2C=ON; SEG_2D=OFF; SEG_2E=OFF; SEG_2F=ON; SEG_2G=OFF; 
#define     display_pos_2_value_8     SEG_2A=ON; SEG_2B=ON; SEG_2C=ON; SEG_2D=ON; SEG_2E=ON; SEG_2F=ON; SEG_2G=ON; 
#define     display_pos_2_value_9     SEG_2A=ON; SEG_2B=ON; SEG_2C=ON; SEG_2D=ON; SEG_2E=OFF; SEG_2F=ON; SEG_2G=ON; 
#define     display_pos_2_value_A     SEG_2A=ON;  SEG_2B=ON;  SEG_2C=ON;  SEG_2D=OFF; SEG_2E=ON; SEG_2F=ON; SEG_2G=ON; 
#define     display_pos_2_value_B     SEG_2A=OFF; SEG_2B=OFF; SEG_2C=ON;  SEG_2D=ON;  SEG_2E=ON; SEG_2F=ON; SEG_2G=ON; 
#define     display_pos_2_value_C     SEG_2A=ON;  SEG_2B=OFF; SEG_2C=OFF; SEG_2D=ON;  SEG_2E=ON; SEG_2F=ON; SEG_2G=OFF; 
#define     display_pos_2_value_D     SEG_2A=OFF; SEG_2B=ON;  SEG_2C=ON;  SEG_2D=ON;  SEG_2E=ON; SEG_2F=OFF;SEG_2G=ON; 
#define     display_pos_2_value_E     SEG_2A=ON;  SEG_2B=OFF; SEG_2C=OFF; SEG_2D=ON;  SEG_2E=ON; SEG_2F=ON; SEG_2G=ON; 
#define     display_pos_2_value_F     SEG_2A=ON;  SEG_2B=OFF; SEG_2C=OFF; SEG_2D=OFF; SEG_2E=ON; SEG_2F=ON; SEG_2G=ON; 
#define     display_pos_2_value_X     SEG_2A=OFF; SEG_2B=OFF; SEG_2C=OFF; SEG_2D=OFF; SEG_2E=OFF; SEG_2F=OFF; SEG_2G=ON; 

// Temperature Display Digits - Position 3
#define     display_pos_3_value_off   SEG_3A=OFF; SEG_3B=OFF; SEG_3C=OFF; SEG_3D=OFF; SEG_3E=OFF; SEG_3F=OFF; SEG_3G=OFF; 
#define     display_pos_3_value_dash  SEG_3A=OFF; SEG_3B=OFF; SEG_3C=OFF; SEG_3D=OFF; SEG_3E=OFF; SEG_3F=OFF; SEG_3G=ON; 
#define     display_pos_3_value_0     SEG_3A=ON; SEG_3B=ON; SEG_3C=ON; SEG_3D=ON; SEG_3E=ON; SEG_3F=ON; SEG_3G=OFF; 
#define     display_pos_3_value_1     SEG_3A=OFF; SEG_3B=ON; SEG_3C=ON; SEG_3D=OFF; SEG_3E=OFF; SEG_3F=OFF; SEG_3G=OFF; 
#define     display_pos_3_value_2     SEG_3A=ON; SEG_3B=ON; SEG_3C=OFF; SEG_3D=ON; SEG_3E=ON; SEG_3F=OFF; SEG_3G=ON; 
#define     display_pos_3_value_3     SEG_3A=ON; SEG_3B=ON; SEG_3C=ON; SEG_3D=ON; SEG_3E=OFF; SEG_3F=OFF; SEG_3G=ON; 
#define     display_pos_3_value_4     SEG_3A=OFF; SEG_3B=ON; SEG_3C=ON; SEG_3D=OFF; SEG_3E=OFF; SEG_3F=ON; SEG_3G=ON; 
#define     display_pos_3_value_5     SEG_3A=ON; SEG_3B=OFF; SEG_3C=ON; SEG_3D=ON; SEG_3E=OFF; SEG_3F=ON; SEG_3G=ON; 
#define     display_pos_3_value_6     SEG_3A=ON; SEG_3B=OFF; SEG_3C=ON; SEG_3D=ON; SEG_3E=ON; SEG_3F=ON; SEG_3G=ON; 
#define     display_pos_3_value_7     SEG_3A=ON; SEG_3B=ON; SEG_3C=ON; SEG_3D=OFF; SEG_3E=OFF; SEG_3F=ON; SEG_3G=OFF; 
#define     display_pos_3_value_8     SEG_3A=ON; SEG_3B=ON; SEG_3C=ON; SEG_3D=ON; SEG_3E=ON; SEG_3F=ON; SEG_3G=ON; 
#define     display_pos_3_value_9     SEG_3A=ON; SEG_3B=ON; SEG_3C=ON; SEG_3D=ON; SEG_3E=OFF; SEG_3F=ON; SEG_3G=ON; 
#define     display_pos_3_value_A     SEG_3A=ON;  SEG_3B=ON;  SEG_3C=ON;  SEG_3D=OFF; SEG_3E=ON; SEG_3F=ON; SEG_3G=ON; 
#define     display_pos_3_value_B     SEG_3A=OFF; SEG_3B=OFF; SEG_3C=ON;  SEG_3D=ON;  SEG_3E=ON; SEG_3F=ON; SEG_3G=ON; 
#define     display_pos_3_value_C     SEG_3A=ON;  SEG_3B=OFF; SEG_3C=OFF; SEG_3D=ON;  SEG_3E=ON; SEG_3F=ON; SEG_3G=OFF; 
#define     display_pos_3_value_D     SEG_3A=OFF; SEG_3B=ON;  SEG_3C=ON;  SEG_3D=ON;  SEG_3E=ON; SEG_3F=OFF;SEG_3G=ON; 
#define     display_pos_3_value_E     SEG_3A=ON;  SEG_3B=OFF; SEG_3C=OFF; SEG_3D=ON;  SEG_3E=ON; SEG_3F=ON; SEG_3G=ON; 
#define     display_pos_3_value_F     SEG_3A=ON;  SEG_3B=OFF; SEG_3C=OFF; SEG_3D=OFF; SEG_3E=ON; SEG_3F=ON; SEG_3G=ON; 
#define     display_pos_3_value_X     SEG_3A=OFF; SEG_3B=OFF; SEG_3C=OFF; SEG_3D=OFF; SEG_3E=OFF; SEG_3F=OFF; SEG_3G=ON; 

// Clock Display Digits - Position 4
#define     display_pos_4_value_off   SEG_4A=OFF; SEG_4B=OFF; SEG_4C=OFF; SEG_4D=OFF; SEG_4E=OFF; SEG_4F=OFF; SEG_4G=OFF; 
#define     display_pos_4_value_dash  SEG_4A=OFF; SEG_4B=OFF; SEG_4C=OFF; SEG_4D=OFF; SEG_4E=OFF; SEG_4F=OFF; SEG_4G=ON; 
#define     display_pos_4_value_0     SEG_4A=ON; SEG_4B=ON; SEG_4C=ON; SEG_4D=ON; SEG_4E=ON; SEG_4F=ON; SEG_4G=OFF; 
#define     display_pos_4_value_1     SEG_4A=OFF; SEG_4B=ON; SEG_4C=ON; SEG_4D=OFF; SEG_4E=OFF; SEG_4F=OFF; SEG_4G=OFF; 
#define     display_pos_4_value_2     SEG_4A=ON; SEG_4B=ON; SEG_4C=OFF; SEG_4D=ON; SEG_4E=ON; SEG_4F=OFF; SEG_4G=ON; 
#define     display_pos_4_value_3     SEG_4A=ON; SEG_4B=ON; SEG_4C=ON; SEG_4D=ON; SEG_4E=OFF; SEG_4F=OFF; SEG_4G=ON; 
#define     display_pos_4_value_4     SEG_4A=OFF; SEG_4B=ON; SEG_4C=ON; SEG_4D=OFF; SEG_4E=OFF; SEG_4F=ON; SEG_4G=ON; 
#define     display_pos_4_value_5     SEG_4A=ON; SEG_4B=OFF; SEG_4C=ON; SEG_4D=ON; SEG_4E=OFF; SEG_4F=ON; SEG_4G=ON; 
#define     display_pos_4_value_6     SEG_4A=ON; SEG_4B=OFF; SEG_4C=ON; SEG_4D=ON; SEG_4E=ON; SEG_4F=ON; SEG_4G=ON; 
#define     display_pos_4_value_7     SEG_4A=ON; SEG_4B=ON; SEG_4C=ON; SEG_4D=OFF; SEG_4E=OFF; SEG_4F=ON; SEG_4G=OFF; 
#define     display_pos_4_value_8     SEG_4A=ON; SEG_4B=ON; SEG_4C=ON; SEG_4D=ON; SEG_4E=ON; SEG_4F=ON; SEG_4G=ON; 
#define     display_pos_4_value_9     SEG_4A=ON; SEG_4B=ON; SEG_4C=ON; SEG_4D=ON; SEG_4E=OFF; SEG_4F=ON; SEG_4G=ON; 
#define     display_pos_4_value_A     SEG_4A=ON;  SEG_4B=ON;  SEG_4C=ON;  SEG_4D=OFF; SEG_4E=ON; SEG_4F=ON; SEG_4G=ON; 
#define     display_pos_4_value_B     SEG_4A=OFF; SEG_4B=OFF; SEG_4C=ON;  SEG_4D=ON;  SEG_4E=ON; SEG_4F=ON; SEG_4G=ON; 
#define     display_pos_4_value_C     SEG_4A=ON;  SEG_4B=OFF; SEG_4C=OFF; SEG_4D=ON;  SEG_4E=ON; SEG_4F=ON; SEG_4G=OFF; 
#define     display_pos_4_value_D     SEG_4A=OFF; SEG_4B=ON;  SEG_4C=ON;  SEG_4D=ON;  SEG_4E=ON; SEG_4F=OFF;SEG_4G=ON; 
#define     display_pos_4_value_E     SEG_4A=ON;  SEG_4B=OFF; SEG_4C=OFF; SEG_4D=ON;  SEG_4E=ON; SEG_4F=ON; SEG_4G=ON; 
#define     display_pos_4_value_F     SEG_4A=ON;  SEG_4B=OFF; SEG_4C=OFF; SEG_4D=OFF; SEG_4E=ON; SEG_4F=ON; SEG_4G=ON; 
#define     display_pos_4_value_X     SEG_4A=OFF; SEG_4B=OFF; SEG_4C=OFF; SEG_4D=OFF; SEG_4E=OFF; SEG_4F=OFF; SEG_4G=ON; 

// Clock Display Digits - Position 5
#define     display_pos_5_value_off   SEG_5A=OFF; SEG_5B=OFF; SEG_5C=OFF; SEG_5D=OFF; SEG_5E=OFF; SEG_5F=OFF; SEG_5G=OFF; 
#define     display_pos_5_value_dash  SEG_5A=OFF; SEG_5B=OFF; SEG_5C=OFF; SEG_5D=OFF; SEG_5E=OFF; SEG_5F=OFF; SEG_5G=ON; 
#define     display_pos_5_value_0     SEG_5A=ON; SEG_5B=ON; SEG_5C=ON; SEG_5D=ON; SEG_5E=ON; SEG_5F=ON; SEG_5G=OFF; 
#define     display_pos_5_value_1     SEG_5A=OFF; SEG_5B=ON; SEG_5C=ON; SEG_5D=OFF; SEG_5E=OFF; SEG_5F=OFF; SEG_5G=OFF; 
#define     display_pos_5_value_2     SEG_5A=ON; SEG_5B=ON; SEG_5C=OFF; SEG_5D=ON; SEG_5E=ON; SEG_5F=OFF; SEG_5G=ON; 
#define     display_pos_5_value_3     SEG_5A=ON; SEG_5B=ON; SEG_5C=ON; SEG_5D=ON; SEG_5E=OFF; SEG_5F=OFF; SEG_5G=ON; 
#define     display_pos_5_value_4     SEG_5A=OFF; SEG_5B=ON; SEG_5C=ON; SEG_5D=OFF; SEG_5E=OFF; SEG_5F=ON; SEG_5G=ON; 
#define     display_pos_5_value_5     SEG_5A=ON; SEG_5B=OFF; SEG_5C=ON; SEG_5D=ON; SEG_5E=OFF; SEG_5F=ON; SEG_5G=ON; 
#define     display_pos_5_value_6     SEG_5A=ON; SEG_5B=OFF; SEG_5C=ON; SEG_5D=ON; SEG_5E=ON; SEG_5F=ON; SEG_5G=ON; 
#define     display_pos_5_value_7     SEG_5A=ON; SEG_5B=ON; SEG_5C=ON; SEG_5D=OFF; SEG_5E=OFF; SEG_5F=ON; SEG_5G=OFF; 
#define     display_pos_5_value_8     SEG_5A=ON; SEG_5B=ON; SEG_5C=ON; SEG_5D=ON; SEG_5E=ON; SEG_5F=ON; SEG_5G=ON; 
#define     display_pos_5_value_9     SEG_5A=ON; SEG_5B=ON; SEG_5C=ON; SEG_5D=ON; SEG_5E=OFF; SEG_5F=ON; SEG_5G=ON; 
#define     display_pos_5_value_A     SEG_5A=ON;  SEG_5B=ON;  SEG_5C=ON;  SEG_5D=OFF; SEG_5E=ON; SEG_5F=ON; SEG_5G=ON; 
#define     display_pos_5_value_B     SEG_5A=OFF; SEG_5B=OFF; SEG_5C=ON;  SEG_5D=ON;  SEG_5E=ON; SEG_5F=ON; SEG_5G=ON; 
#define     display_pos_5_value_C     SEG_5A=ON;  SEG_5B=OFF; SEG_5C=OFF; SEG_5D=ON;  SEG_5E=ON; SEG_5F=ON; SEG_5G=OFF; 
#define     display_pos_5_value_D     SEG_5A=OFF; SEG_5B=ON;  SEG_5C=ON;  SEG_5D=ON;  SEG_5E=ON; SEG_5F=OFF;SEG_5G=ON; 
#define     display_pos_5_value_E     SEG_5A=ON;  SEG_5B=OFF; SEG_5C=OFF; SEG_5D=ON;  SEG_5E=ON; SEG_5F=ON; SEG_5G=ON; 
#define     display_pos_5_value_F     SEG_5A=ON;  SEG_5B=OFF; SEG_5C=OFF; SEG_5D=OFF; SEG_5E=ON; SEG_5F=ON; SEG_5G=ON; 
#define     display_pos_5_value_X     SEG_5A=OFF; SEG_5B=OFF; SEG_5C=OFF; SEG_5D=OFF; SEG_5E=OFF; SEG_5F=OFF; SEG_5G=ON; 

// Clock Display Digits - Position 6
#define     display_pos_6_value_off   SEG_6A=OFF; SEG_6B=OFF; SEG_6C=OFF; SEG_6D=OFF; SEG_6E=OFF; SEG_6F=OFF; SEG_6G=OFF; 
#define     display_pos_6_value_dash  SEG_6A=OFF; SEG_6B=OFF; SEG_6C=OFF; SEG_6D=OFF; SEG_6E=OFF; SEG_6F=OFF; SEG_6G=ON; 
#define     display_pos_6_value_0     SEG_6A=ON; SEG_6B=ON; SEG_6C=ON; SEG_6D=ON; SEG_6E=ON; SEG_6F=ON; SEG_6G=OFF; 
#define     display_pos_6_value_1     SEG_6A=OFF; SEG_6B=ON; SEG_6C=ON; SEG_6D=OFF; SEG_6E=OFF; SEG_6F=OFF; SEG_6G=OFF; 
#define     display_pos_6_value_2     SEG_6A=ON; SEG_6B=ON; SEG_6C=OFF; SEG_6D=ON; SEG_6E=ON; SEG_6F=OFF; SEG_6G=ON; 
#define     display_pos_6_value_3     SEG_6A=ON; SEG_6B=ON; SEG_6C=ON; SEG_6D=ON; SEG_6E=OFF; SEG_6F=OFF; SEG_6G=ON; 
#define     display_pos_6_value_4     SEG_6A=OFF; SEG_6B=ON; SEG_6C=ON; SEG_6D=OFF; SEG_6E=OFF; SEG_6F=ON; SEG_6G=ON; 
#define     display_pos_6_value_5     SEG_6A=ON; SEG_6B=OFF; SEG_6C=ON; SEG_6D=ON; SEG_6E=OFF; SEG_6F=ON; SEG_6G=ON; 
#define     display_pos_6_value_6     SEG_6A=ON; SEG_6B=OFF; SEG_6C=ON; SEG_6D=ON; SEG_6E=ON; SEG_6F=ON; SEG_6G=ON; 
#define     display_pos_6_value_7     SEG_6A=ON; SEG_6B=ON; SEG_6C=ON; SEG_6D=OFF; SEG_6E=OFF; SEG_6F=ON; SEG_6G=OFF; 
#define     display_pos_6_value_8     SEG_6A=ON; SEG_6B=ON; SEG_6C=ON; SEG_6D=ON; SEG_6E=ON; SEG_6F=ON; SEG_6G=ON; 
#define     display_pos_6_value_9     SEG_6A=ON; SEG_6B=ON; SEG_6C=ON; SEG_6D=ON; SEG_6E=OFF; SEG_6F=ON; SEG_6G=ON; 
#define     display_pos_6_value_A     SEG_6A=ON;  SEG_6B=ON;  SEG_6C=ON;  SEG_6D=OFF; SEG_6E=ON; SEG_6F=ON; SEG_6G=ON; 
#define     display_pos_6_value_B     SEG_6A=OFF; SEG_6B=OFF; SEG_6C=ON;  SEG_6D=ON;  SEG_6E=ON; SEG_6F=ON; SEG_6G=ON; 
#define     display_pos_6_value_C     SEG_6A=ON;  SEG_6B=OFF; SEG_6C=OFF; SEG_6D=ON;  SEG_6E=ON; SEG_6F=ON; SEG_6G=OFF; 
#define     display_pos_6_value_D     SEG_6A=OFF; SEG_6B=ON;  SEG_6C=ON;  SEG_6D=ON;  SEG_6E=ON; SEG_6F=OFF;SEG_6G=ON; 
#define     display_pos_6_value_E     SEG_6A=ON;  SEG_6B=OFF; SEG_6C=OFF; SEG_6D=ON;  SEG_6E=ON; SEG_6F=ON; SEG_6G=ON; 
#define     display_pos_6_value_F     SEG_6A=ON;  SEG_6B=OFF; SEG_6C=OFF; SEG_6D=OFF; SEG_6E=ON; SEG_6F=ON; SEG_6G=ON; 
#define     display_pos_6_value_X     SEG_6A=OFF; SEG_6B=OFF; SEG_6C=OFF; SEG_6D=OFF; SEG_6E=OFF; SEG_6F=OFF; SEG_6G=ON; 

// Clock Display Digits - Position 7
#define     display_pos_7_value_off   SEG_7A=OFF; SEG_7B=OFF; SEG_7C=OFF; SEG_7D=OFF; SEG_7E=OFF; SEG_7F=OFF; SEG_7G=OFF; 	
#define     display_pos_7_value_dash  SEG_7A=OFF; SEG_7B=OFF; SEG_7C=OFF; SEG_7D=OFF; SEG_7E=OFF; SEG_7F=OFF; SEG_7G=ON; 
#define     display_pos_7_value_0     SEG_7A=ON; SEG_7B=ON; SEG_7C=ON; SEG_7D=ON; SEG_7E=ON; SEG_7F=ON; SEG_7G=OFF; 
#define     display_pos_7_value_1     SEG_7A=OFF; SEG_7B=ON; SEG_7C=ON; SEG_7D=OFF; SEG_7E=OFF; SEG_7F=OFF; SEG_7G=OFF; 
#define     display_pos_7_value_2     SEG_7A=ON; SEG_7B=ON; SEG_7C=OFF; SEG_7D=ON; SEG_7E=ON; SEG_7F=OFF; SEG_7G=ON; 
#define     display_pos_7_value_3     SEG_7A=ON; SEG_7B=ON; SEG_7C=ON; SEG_7D=ON; SEG_7E=OFF; SEG_7F=OFF; SEG_7G=ON; 
#define     display_pos_7_value_4     SEG_7A=OFF; SEG_7B=ON; SEG_7C=ON; SEG_7D=OFF; SEG_7E=OFF; SEG_7F=ON; SEG_7G=ON; 
#define     display_pos_7_value_5     SEG_7A=ON; SEG_7B=OFF; SEG_7C=ON; SEG_7D=ON; SEG_7E=OFF; SEG_7F=ON; SEG_7G=ON; 
#define     display_pos_7_value_6     SEG_7A=ON; SEG_7B=OFF; SEG_7C=ON; SEG_7D=ON; SEG_7E=ON; SEG_7F=ON; SEG_7G=ON; 
#define     display_pos_7_value_7     SEG_7A=ON; SEG_7B=ON; SEG_7C=ON; SEG_7D=OFF; SEG_7E=OFF; SEG_7F=ON; SEG_7G=OFF; 
#define     display_pos_7_value_8     SEG_7A=ON; SEG_7B=ON; SEG_7C=ON; SEG_7D=ON; SEG_7E=ON; SEG_7F=ON; SEG_7G=ON; 
#define     display_pos_7_value_9     SEG_7A=ON; SEG_7B=ON; SEG_7C=ON; SEG_7D=ON; SEG_7E=OFF; SEG_7F=ON; SEG_7G=ON; 
#define     display_pos_7_value_A     SEG_7A=ON;  SEG_7B=ON;  SEG_7C=ON;  SEG_7D=OFF; SEG_7E=ON; SEG_7F=ON; SEG_7G=ON; 
#define     display_pos_7_value_B     SEG_7A=OFF; SEG_7B=OFF; SEG_7C=ON;  SEG_7D=ON;  SEG_7E=ON; SEG_7F=ON; SEG_7G=ON; 
#define     display_pos_7_value_C     SEG_7A=ON;  SEG_7B=OFF; SEG_7C=OFF; SEG_7D=ON;  SEG_7E=ON; SEG_7F=ON; SEG_7G=OFF; 
#define     display_pos_7_value_D     SEG_7A=OFF; SEG_7B=ON;  SEG_7C=ON;  SEG_7D=ON;  SEG_7E=ON; SEG_7F=OFF;SEG_7G=ON; 
#define     display_pos_7_value_E     SEG_7A=ON;  SEG_7B=OFF; SEG_7C=OFF; SEG_7D=ON;  SEG_7E=ON; SEG_7F=ON; SEG_7G=ON; 
#define     display_pos_7_value_F     SEG_7A=ON;  SEG_7B=OFF; SEG_7C=OFF; SEG_7D=OFF; SEG_7E=ON; SEG_7F=ON; SEG_7G=ON; 
#define     display_pos_7_value_X     SEG_7A=OFF; SEG_7B=OFF; SEG_7C=OFF; SEG_7D=OFF; SEG_7E=OFF; SEG_7F=OFF; SEG_7G=ON; 

// Clock Display Digits - Position 8
#define     display_pos_8_value_off   SEG_8A=OFF; SEG_8B=OFF; SEG_8C=OFF; SEG_8D=OFF; SEG_8E=OFF; SEG_8F=OFF; SEG_8G=OFF; 
#define     display_pos_8_value_dash  SEG_8A=OFF; SEG_8B=OFF; SEG_8C=OFF; SEG_8D=OFF; SEG_8E=OFF; SEG_8F=OFF; SEG_8G=ON; 
#define     display_pos_8_value_0     SEG_8A=ON; SEG_8B=ON; SEG_8C=ON; SEG_8D=ON; SEG_8E=ON; SEG_8F=ON; SEG_8G=OFF; 
#define     display_pos_8_value_1     SEG_8A=OFF; SEG_8B=ON; SEG_8C=ON; SEG_8D=OFF; SEG_8E=OFF; SEG_8F=OFF; SEG_8G=OFF; 
#define     display_pos_8_value_2     SEG_8A=ON; SEG_8B=ON; SEG_8C=OFF; SEG_8D=ON; SEG_8E=ON; SEG_8F=OFF; SEG_8G=ON; 
#define     display_pos_8_value_3     SEG_8A=ON; SEG_8B=ON; SEG_8C=ON; SEG_8D=ON; SEG_8E=OFF; SEG_8F=OFF; SEG_8G=ON; 
#define     display_pos_8_value_4     SEG_8A=OFF; SEG_8B=ON; SEG_8C=ON; SEG_8D=OFF; SEG_8E=OFF; SEG_8F=ON; SEG_8G=ON; 
#define     display_pos_8_value_5     SEG_8A=ON; SEG_8B=OFF; SEG_8C=ON; SEG_8D=ON; SEG_8E=OFF; SEG_8F=ON; SEG_8G=ON; 
#define     display_pos_8_value_6     SEG_8A=ON; SEG_8B=OFF; SEG_8C=ON; SEG_8D=ON; SEG_8E=ON; SEG_8F=ON; SEG_8G=ON; 
#define     display_pos_8_value_7     SEG_8A=ON; SEG_8B=ON; SEG_8C=ON; SEG_8D=OFF; SEG_8E=OFF; SEG_8F=ON; SEG_8G=OFF; 
#define     display_pos_8_value_8     SEG_8A=ON; SEG_8B=ON; SEG_8C=ON; SEG_8D=ON; SEG_8E=ON; SEG_8F=ON; SEG_8G=ON; 
#define     display_pos_8_value_9     SEG_8A=ON; SEG_8B=ON; SEG_8C=ON; SEG_8D=ON; SEG_8E=OFF; SEG_8F=ON; SEG_8G=ON; 
#define     display_pos_8_value_A     SEG_8A=ON;  SEG_8B=ON;  SEG_8C=ON;  SEG_8D=OFF; SEG_8E=ON; SEG_8F=ON; SEG_8G=ON; 
#define     display_pos_8_value_B     SEG_8A=OFF; SEG_8B=OFF; SEG_8C=ON;  SEG_8D=ON;  SEG_8E=ON; SEG_8F=ON; SEG_8G=ON; 
#define     display_pos_8_value_C     SEG_8A=ON;  SEG_8B=OFF; SEG_8C=OFF; SEG_8D=ON;  SEG_8E=ON; SEG_8F=ON; SEG_8G=OFF; 
#define     display_pos_8_value_D     SEG_8A=OFF; SEG_8B=ON;  SEG_8C=ON;  SEG_8D=ON;  SEG_8E=ON; SEG_8F=OFF;SEG_8G=ON; 
#define     display_pos_8_value_E     SEG_8A=ON;  SEG_8B=OFF; SEG_8C=OFF; SEG_8D=ON;  SEG_8E=ON; SEG_8F=ON; SEG_8G=ON; 
#define     display_pos_8_value_F     SEG_8A=ON;  SEG_8B=OFF; SEG_8C=OFF; SEG_8D=OFF; SEG_8E=ON; SEG_8F=ON; SEG_8G=ON; 
#define     display_pos_8_value_X     SEG_8A=OFF; SEG_8B=OFF; SEG_8C=OFF; SEG_8D=OFF; SEG_8E=OFF; SEG_8F=OFF; SEG_8G=ON; 

// Clock Display Digits - Position 9
#define     display_pos_9_value_off   SEG_9A=OFF; SEG_9B=OFF; SEG_9C=OFF; SEG_9D=OFF; SEG_9E=OFF; SEG_9F=OFF; SEG_9G=OFF; 
#define     display_pos_9_value_dash  SEG_9A=OFF; SEG_9B=OFF; SEG_9C=OFF; SEG_9D=OFF; SEG_9E=OFF; SEG_9F=OFF; SEG_9G=ON; 
#define     display_pos_9_value_0     SEG_9A=ON; SEG_9B=ON; SEG_9C=ON; SEG_9D=ON; SEG_9E=ON; SEG_9F=ON; SEG_9G=OFF; 
#define     display_pos_9_value_1     SEG_9A=OFF; SEG_9B=ON; SEG_9C=ON; SEG_9D=OFF; SEG_9E=OFF; SEG_9F=OFF; SEG_9G=OFF; 
#define     display_pos_9_value_2     SEG_9A=ON; SEG_9B=ON; SEG_9C=OFF; SEG_9D=ON; SEG_9E=ON; SEG_9F=OFF; SEG_9G=ON; 
#define     display_pos_9_value_3     SEG_9A=ON; SEG_9B=ON; SEG_9C=ON; SEG_9D=ON; SEG_9E=OFF; SEG_9F=OFF; SEG_9G=ON; 
#define     display_pos_9_value_4     SEG_9A=OFF; SEG_9B=ON; SEG_9C=ON; SEG_9D=OFF; SEG_9E=OFF; SEG_9F=ON; SEG_9G=ON; 
#define     display_pos_9_value_5     SEG_9A=ON; SEG_9B=OFF; SEG_9C=ON; SEG_9D=ON; SEG_9E=OFF; SEG_9F=ON; SEG_9G=ON; 
#define     display_pos_9_value_6     SEG_9A=ON; SEG_9B=OFF; SEG_9C=ON; SEG_9D=ON; SEG_9E=ON; SEG_9F=ON; SEG_9G=ON; 
#define     display_pos_9_value_7     SEG_9A=ON; SEG_9B=ON; SEG_9C=ON; SEG_9D=OFF; SEG_9E=OFF; SEG_9F=ON; SEG_9G=OFF; 
#define     display_pos_9_value_8     SEG_9A=ON; SEG_9B=ON; SEG_9C=ON; SEG_9D=ON; SEG_9E=ON; SEG_9F=ON; SEG_9G=ON; 
#define     display_pos_9_value_9     SEG_9A=ON; SEG_9B=ON; SEG_9C=ON; SEG_9D=ON; SEG_9E=OFF; SEG_9F=ON; SEG_9G=ON; 
#define     display_pos_9_value_A     SEG_9A=ON;  SEG_9B=ON;  SEG_9C=ON;  SEG_9D=OFF; SEG_9E=ON; SEG_9F=ON; SEG_9G=ON; 
#define     display_pos_9_value_B     SEG_9A=OFF; SEG_9B=OFF; SEG_9C=ON;  SEG_9D=ON;  SEG_9E=ON; SEG_9F=ON; SEG_9G=ON; 
#define     display_pos_9_value_C     SEG_9A=ON;  SEG_9B=OFF; SEG_9C=OFF; SEG_9D=ON;  SEG_9E=ON; SEG_9F=ON; SEG_9G=OFF; 
#define     display_pos_9_value_D     SEG_9A=OFF; SEG_9B=ON;  SEG_9C=ON;  SEG_9D=ON;  SEG_9E=ON; SEG_9F=OFF;SEG_9G=ON; 
#define     display_pos_9_value_E     SEG_9A=ON;  SEG_9B=OFF; SEG_9C=OFF; SEG_9D=ON;  SEG_9E=ON; SEG_9F=ON; SEG_9G=ON; 
#define     display_pos_9_value_F     SEG_9A=ON;  SEG_9B=OFF; SEG_9C=OFF; SEG_9D=OFF; SEG_9E=ON; SEG_9F=ON; SEG_9G=ON; 
#define     display_pos_9_value_X     SEG_9A=OFF; SEG_9B=OFF; SEG_9C=OFF; SEG_9D=OFF; SEG_9E=OFF; SEG_9F=OFF; SEG_9G=ON; 

// Clock Display Digits - Position 10
#define     display_pos_10_value_off   SEG_10A=OFF; SEG_10B=OFF; SEG_10C=OFF; SEG_10D=OFF; SEG_10E=OFF; SEG_10F=OFF; SEG_10G=OFF; 
#define     display_pos_10_value_dash  SEG_10A=OFF; SEG_10B=OFF; SEG_10C=OFF; SEG_10D=OFF; SEG_10E=OFF; SEG_10F=OFF; SEG_10G=ON; 
#define     display_pos_10_value_0     SEG_10A=ON; SEG_10B=ON; SEG_10C=ON; SEG_10D=ON; SEG_10E=ON; SEG_10F=ON; SEG_10G=OFF; 
#define     display_pos_10_value_1     SEG_10A=OFF; SEG_10B=ON; SEG_10C=ON; SEG_10D=OFF; SEG_10E=OFF; SEG_10F=OFF; SEG_10G=OFF; 
#define     display_pos_10_value_2     SEG_10A=ON; SEG_10B=ON; SEG_10C=OFF; SEG_10D=ON; SEG_10E=ON; SEG_10F=OFF; SEG_10G=ON; 
#define     display_pos_10_value_3     SEG_10A=ON; SEG_10B=ON; SEG_10C=ON; SEG_10D=ON; SEG_10E=OFF; SEG_10F=OFF; SEG_10G=ON; 
#define     display_pos_10_value_4     SEG_10A=OFF; SEG_10B=ON; SEG_10C=ON; SEG_10D=OFF; SEG_10E=OFF; SEG_10F=ON; SEG_10G=ON; 
#define     display_pos_10_value_5     SEG_10A=ON; SEG_10B=OFF; SEG_10C=ON; SEG_10D=ON; SEG_10E=OFF; SEG_10F=ON; SEG_10G=ON; 
#define     display_pos_10_value_6     SEG_10A=ON; SEG_10B=OFF; SEG_10C=ON; SEG_10D=ON; SEG_10E=ON; SEG_10F=ON; SEG_10G=ON; 
#define     display_pos_10_value_7     SEG_10A=ON; SEG_10B=ON; SEG_10C=ON; SEG_10D=OFF; SEG_10E=OFF; SEG_10F=ON; SEG_10G=OFF; 
#define     display_pos_10_value_8     SEG_10A=ON; SEG_10B=ON; SEG_10C=ON; SEG_10D=ON; SEG_10E=ON; SEG_10F=ON; SEG_10G=ON; 
#define     display_pos_10_value_9     SEG_10A=ON; SEG_10B=ON; SEG_10C=ON; SEG_10D=ON; SEG_10E=OFF; SEG_10F=ON; SEG_10G=ON; 
#define     display_pos_10_value_A     SEG_10A=ON;  SEG_10B=ON;  SEG_10C=ON;  SEG_10D=OFF; SEG_10E=ON; SEG_10F=ON; SEG_10G=ON; 
#define     display_pos_10_value_B     SEG_10A=OFF; SEG_10B=OFF; SEG_10C=ON;  SEG_10D=ON;  SEG_10E=ON; SEG_10F=ON; SEG_10G=ON; 
#define     display_pos_10_value_C     SEG_10A=ON;  SEG_10B=OFF; SEG_10C=OFF; SEG_10D=ON;  SEG_10E=ON; SEG_10F=ON; SEG_10G=OFF; 
#define     display_pos_10_value_D     SEG_10A=OFF; SEG_10B=ON;  SEG_10C=ON;  SEG_10D=ON;  SEG_10E=ON; SEG_10F=OFF;SEG_10G=ON; 
#define     display_pos_10_value_E     SEG_10A=ON;  SEG_10B=OFF; SEG_10C=OFF; SEG_10D=ON;  SEG_10E=ON; SEG_10F=ON; SEG_10G=ON; 
#define     display_pos_10_value_F     SEG_10A=ON;  SEG_10B=OFF; SEG_10C=OFF; SEG_10D=OFF; SEG_10E=ON; SEG_10F=ON; SEG_10G=ON; 
#define     display_pos_10_value_X     SEG_10A=OFF; SEG_10B=OFF; SEG_10C=OFF; SEG_10D=OFF; SEG_10E=OFF; SEG_10F=OFF; SEG_10G=ON; 

// Clock Display Digits - Position 11
#define     display_pos_11_value_off	SEG_11A=OFF; SEG_11B=OFF; SEG_11C=OFF; SEG_11D=OFF; SEG_11E=OFF; SEG_11F=OFF; SEG_11G=OFF; 
#define     display_pos_11_value_dash  SEG_11A=OFF; SEG_11B=OFF; SEG_11C=OFF; SEG_11D=OFF; SEG_11E=OFF; SEG_11F=OFF; SEG_11G=ON; 
#define     display_pos_11_value_0     SEG_11A=ON; SEG_11B=ON; SEG_11C=ON; SEG_11D=ON; SEG_11E=ON; SEG_11F=ON; SEG_11G=OFF; 
#define     display_pos_11_value_1     SEG_11A=OFF; SEG_11B=ON; SEG_11C=ON; SEG_11D=OFF; SEG_11E=OFF; SEG_11F=OFF; SEG_11G=OFF; 
#define     display_pos_11_value_2     SEG_11A=ON; SEG_11B=ON; SEG_11C=OFF; SEG_11D=ON; SEG_11E=ON; SEG_11F=OFF; SEG_11G=ON; 
#define     display_pos_11_value_3     SEG_11A=ON; SEG_11B=ON; SEG_11C=ON; SEG_11D=ON; SEG_11E=OFF; SEG_11F=OFF; SEG_11G=ON; 
#define     display_pos_11_value_4     SEG_11A=OFF; SEG_11B=ON; SEG_11C=ON; SEG_11D=OFF; SEG_11E=OFF; SEG_11F=ON; SEG_11G=ON; 
#define     display_pos_11_value_5     SEG_11A=ON; SEG_11B=OFF; SEG_11C=ON; SEG_11D=ON; SEG_11E=OFF; SEG_11F=ON; SEG_11G=ON; 
#define     display_pos_11_value_6     SEG_11A=ON; SEG_11B=OFF; SEG_11C=ON; SEG_11D=ON; SEG_11E=ON; SEG_11F=ON; SEG_11G=ON; 
#define     display_pos_11_value_7     SEG_11A=ON; SEG_11B=ON; SEG_11C=ON; SEG_11D=OFF; SEG_11E=OFF; SEG_11F=ON; SEG_11G=OFF; 
#define     display_pos_11_value_8     SEG_11A=ON; SEG_11B=ON; SEG_11C=ON; SEG_11D=ON; SEG_11E=ON; SEG_11F=ON; SEG_11G=ON; 
#define     display_pos_11_value_9     SEG_11A=ON; SEG_11B=ON; SEG_11C=ON; SEG_11D=ON; SEG_11E=OFF; SEG_11F=ON; SEG_11G=ON; 
#define     display_pos_11_value_A     SEG_11A=ON;  SEG_11B=ON;  SEG_11C=ON;  SEG_11D=OFF; SEG_11E=ON; SEG_11F=ON; SEG_11G=ON; 
#define     display_pos_11_value_B     SEG_11A=OFF; SEG_11B=OFF; SEG_11C=ON;  SEG_11D=ON;  SEG_11E=ON; SEG_11F=ON; SEG_11G=ON; 
#define     display_pos_11_value_C     SEG_11A=ON;  SEG_11B=OFF; SEG_11C=OFF; SEG_11D=ON;  SEG_11E=ON; SEG_11F=ON; SEG_11G=OFF; 
#define     display_pos_11_value_D     SEG_11A=OFF; SEG_11B=ON;  SEG_11C=ON;  SEG_11D=ON;  SEG_11E=ON; SEG_11F=OFF;SEG_11G=ON; 
#define     display_pos_11_value_E     SEG_11A=ON;  SEG_11B=OFF; SEG_11C=OFF; SEG_11D=ON;  SEG_11E=ON; SEG_11F=ON; SEG_11G=ON; 
#define     display_pos_11_value_F     SEG_11A=ON;  SEG_11B=OFF; SEG_11C=OFF; SEG_11D=OFF; SEG_11E=ON; SEG_11F=ON; SEG_11G=ON; 
#define     display_pos_11_value_X     SEG_11A=OFF; SEG_11B=OFF; SEG_11C=OFF; SEG_11D=OFF; SEG_11E=OFF; SEG_11F=OFF; SEG_11G=ON; 

// Clock Display Digits - Position 12
#define     display_pos_12_value_off   SEG_12A=OFF; SEG_12B=OFF; SEG_12C=OFF; SEG_12D=OFF; SEG_12E=OFF; SEG_12F=OFF; SEG_12G=OFF;
#define     display_pos_12_value_dash  SEG_12A=OFF; SEG_12B=OFF; SEG_12C=OFF; SEG_12D=OFF; SEG_12E=OFF; SEG_12F=OFF; SEG_12G=ON; 
#define     display_pos_12_value_0     SEG_12A=ON; SEG_12B=ON; SEG_12C=ON; SEG_12D=ON; SEG_12E=ON; SEG_12F=ON; SEG_12G=OFF; 
#define     display_pos_12_value_1     SEG_12A=OFF; SEG_12B=ON; SEG_12C=ON; SEG_12D=OFF; SEG_12E=OFF; SEG_12F=OFF; SEG_12G=OFF; 
#define     display_pos_12_value_2     SEG_12A=ON; SEG_12B=ON; SEG_12C=OFF; SEG_12D=ON; SEG_12E=ON; SEG_12F=OFF; SEG_12G=ON; 
#define     display_pos_12_value_3     SEG_12A=ON; SEG_12B=ON; SEG_12C=ON; SEG_12D=ON; SEG_12E=OFF; SEG_12F=OFF; SEG_12G=ON; 
#define     display_pos_12_value_4     SEG_12A=OFF; SEG_12B=ON; SEG_12C=ON; SEG_12D=OFF; SEG_12E=OFF; SEG_12F=ON; SEG_12G=ON; 
#define     display_pos_12_value_5     SEG_12A=ON; SEG_12B=OFF; SEG_12C=ON; SEG_12D=ON; SEG_12E=OFF; SEG_12F=ON; SEG_12G=ON; 
#define     display_pos_12_value_6     SEG_12A=ON; SEG_12B=OFF; SEG_12C=ON; SEG_12D=ON; SEG_12E=ON; SEG_12F=ON; SEG_12G=ON; 
#define     display_pos_12_value_7     SEG_12A=ON; SEG_12B=ON; SEG_12C=ON; SEG_12D=OFF; SEG_12E=OFF; SEG_12F=ON; SEG_12G=OFF; 
#define     display_pos_12_value_8     SEG_12A=ON; SEG_12B=ON; SEG_12C=ON; SEG_12D=ON; SEG_12E=ON; SEG_12F=ON; SEG_12G=ON; 
#define     display_pos_12_value_9     SEG_12A=ON; SEG_12B=ON; SEG_12C=ON; SEG_12D=ON; SEG_12E=OFF; SEG_12F=ON; SEG_12G=ON; 
#define     display_pos_12_value_A     SEG_12A=ON;  SEG_12B=ON;  SEG_12C=ON;  SEG_12D=OFF; SEG_12E=ON; SEG_12F=ON; SEG_12G=ON; 
#define     display_pos_12_value_B     SEG_12A=OFF; SEG_12B=OFF; SEG_12C=ON;  SEG_12D=ON;  SEG_12E=ON; SEG_12F=ON; SEG_12G=ON; 
#define     display_pos_12_value_C     SEG_12A=ON;  SEG_12B=OFF; SEG_12C=OFF; SEG_12D=ON;  SEG_12E=ON; SEG_12F=ON; SEG_12G=OFF; 
#define     display_pos_12_value_D     SEG_12A=OFF; SEG_12B=ON;  SEG_12C=ON;  SEG_12D=ON;  SEG_12E=ON; SEG_12F=OFF;SEG_12G=ON; 
#define     display_pos_12_value_E     SEG_12A=ON;  SEG_12B=OFF; SEG_12C=OFF; SEG_12D=ON;  SEG_12E=ON; SEG_12F=ON; SEG_12G=ON; 
#define     display_pos_12_value_F     SEG_12A=ON;  SEG_12B=OFF; SEG_12C=OFF; SEG_12D=OFF; SEG_12E=ON; SEG_12F=ON; SEG_12G=ON; 
#define     display_pos_12_value_X     SEG_12A=OFF; SEG_12B=OFF; SEG_12C=OFF; SEG_12D=OFF; SEG_12E=OFF; SEG_12F=OFF; SEG_12G=ON; 

// Clock Display Digits - Position 13
#define     display_pos_13_value_off   SEG_13A=OFF; SEG_13B=OFF; SEG_13C=OFF; SEG_13D=OFF; SEG_13E=OFF; SEG_13F=OFF; SEG_13G=OFF; 
#define     display_pos_13_value_dash  SEG_13A=OFF; SEG_13B=OFF; SEG_13C=OFF; SEG_13D=OFF; SEG_13E=OFF; SEG_13F=OFF; SEG_13G=ON; 
#define     display_pos_13_value_0     SEG_13A=ON; SEG_13B=ON; SEG_13C=ON; SEG_13D=ON; SEG_13E=ON; SEG_13F=ON; SEG_13G=OFF; 
#define     display_pos_13_value_1     SEG_13A=OFF; SEG_13B=ON; SEG_13C=ON; SEG_13D=OFF; SEG_13E=OFF; SEG_13F=OFF; SEG_13G=OFF; 
#define     display_pos_13_value_2     SEG_13A=ON; SEG_13B=ON; SEG_13C=OFF; SEG_13D=ON; SEG_13E=ON; SEG_13F=OFF; SEG_13G=ON; 
#define     display_pos_13_value_3     SEG_13A=ON; SEG_13B=ON; SEG_13C=ON; SEG_13D=ON; SEG_13E=OFF; SEG_13F=OFF; SEG_13G=ON; 
#define     display_pos_13_value_4     SEG_13A=OFF; SEG_13B=ON; SEG_13C=ON; SEG_13D=OFF; SEG_13E=OFF; SEG_13F=ON; SEG_13G=ON; 
#define     display_pos_13_value_5     SEG_13A=ON; SEG_13B=OFF; SEG_13C=ON; SEG_13D=ON; SEG_13E=OFF; SEG_13F=ON; SEG_13G=ON; 
#define     display_pos_13_value_6     SEG_13A=ON; SEG_13B=OFF; SEG_13C=ON; SEG_13D=ON; SEG_13E=ON; SEG_13F=ON; SEG_13G=ON; 
#define     display_pos_13_value_7     SEG_13A=ON; SEG_13B=ON; SEG_13C=ON; SEG_13D=OFF; SEG_13E=OFF; SEG_13F=ON; SEG_13G=OFF; 
#define     display_pos_13_value_8     SEG_13A=ON; SEG_13B=ON; SEG_13C=ON; SEG_13D=ON; SEG_13E=ON; SEG_13F=ON; SEG_13G=ON; 
#define     display_pos_13_value_9     SEG_13A=ON; SEG_13B=ON; SEG_13C=ON; SEG_13D=ON; SEG_13E=OFF; SEG_13F=ON; SEG_13G=ON; 
#define     display_pos_13_value_A     SEG_13A=ON;  SEG_13B=ON;  SEG_13C=ON;  SEG_13D=OFF; SEG_13E=ON; SEG_13F=ON; SEG_13G=ON; 
#define     display_pos_13_value_B     SEG_13A=OFF; SEG_13B=OFF; SEG_13C=ON;  SEG_13D=ON;  SEG_13E=ON; SEG_13F=ON; SEG_13G=ON; 
#define     display_pos_13_value_C     SEG_13A=ON;  SEG_13B=OFF; SEG_13C=OFF; SEG_13D=ON;  SEG_13E=ON; SEG_13F=ON; SEG_13G=OFF; 
#define     display_pos_13_value_D     SEG_13A=OFF; SEG_13B=ON;  SEG_13C=ON;  SEG_13D=ON;  SEG_13E=ON; SEG_13F=OFF;SEG_13G=ON; 
#define     display_pos_13_value_E     SEG_13A=ON;  SEG_13B=OFF; SEG_13C=OFF; SEG_13D=ON;  SEG_13E=ON; SEG_13F=ON; SEG_13G=ON; 
#define     display_pos_13_value_F     SEG_13A=ON;  SEG_13B=OFF; SEG_13C=OFF; SEG_13D=OFF; SEG_13E=ON; SEG_13F=ON; SEG_13G=ON; 
#define     display_pos_13_value_X     SEG_13A=OFF; SEG_13B=OFF; SEG_13C=OFF; SEG_13D=OFF; SEG_13E=OFF; SEG_13F=OFF; SEG_13G=ON; 
