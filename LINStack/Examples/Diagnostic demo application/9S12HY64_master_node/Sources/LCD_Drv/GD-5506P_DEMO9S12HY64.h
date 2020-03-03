/********************************************************************** 
GD5506P LCD Glass Segment Mapping for DEMO9S12HY64                
************************************************************************/

#include <MC9S12HY64.h>     /* derivative information */

//
// Definitions here are HW dependent, based on which LCD pins are connected to which
// MCU pins.  This list is generated from an excel spreadsheet and is based upon the
// pin connections of the DEMO9S12HY64 board from Axiom.
//  Last Updated on 39766
//


#define SEG_P40      LCDRAM19_FP39BP3     // ODO[ODO]
#define SEG_P41      LCDRAM19_FP39BP2     // ODO[TRIP A]
#define SEG_P42      LCDRAM19_FP39BP1     // ODO[TRIP B]
#define SEG_P      LCDRAM19_FP39BP0     // Gear IndP
#define SEG_8A      LCDRAM19_FP38BP3     // ODO[5]
#define SEG_8F      LCDRAM19_FP38BP2     // ODO[5]
#define SEG_8E      LCDRAM19_FP38BP1     // ODO[5]
#define SEG_8D      LCDRAM19_FP38BP0     // ODO[5]
#define SEG_8B      LCDRAM18_FP37BP3     // ODO[5]
#define SEG_8G      LCDRAM18_FP37BP2     // ODO[5]
#define SEG_8C      LCDRAM18_FP37BP1     // ODO[5]
#define SEG_R      LCDRAM18_FP37BP0     // Gear IndR
#define SEG_9A      LCDRAM18_FP36BP3     // ODO[4]
#define SEG_9F      LCDRAM18_FP36BP2     // ODO[4]
#define SEG_9E      LCDRAM18_FP36BP1     // ODO[4]
#define SEG_9D      LCDRAM18_FP36BP0     // ODO[4]
#define SEG_9B      LCDRAM17_FP35BP3     // ODO[4]
#define SEG_9G      LCDRAM17_FP35BP2     // ODO[4]
#define SEG_9C      LCDRAM17_FP35BP1     // ODO[4]
#define SEG_N      LCDRAM17_FP35BP0     // Gear IndN
#define SEG_10A      LCDRAM17_FP34BP3     // ODO[3]
#define SEG_10F      LCDRAM17_FP34BP2     // ODO[3]
#define SEG_10E      LCDRAM17_FP34BP1     // ODO[3]
#define SEG_10D      LCDRAM17_FP34BP0     // ODO[3]
#define SEG_10B      LCDRAM16_FP33BP3     // ODO[3]
#define SEG_10G      LCDRAM16_FP33BP2     // ODO[3]
#define SEG_10C      LCDRAM16_FP33BP1     // ODO[3]
#define SEG_D      LCDRAM16_FP33BP0     // Gear IndD
#define SEG_11A      LCDRAM16_FP32BP3     // ODO[2]
#define SEG_11F      LCDRAM16_FP32BP2     // ODO[2]
#define SEG_11E      LCDRAM16_FP32BP1     // ODO[2]
#define SEG_11D      LCDRAM16_FP32BP0     // ODO[2]
#define SEG_11B      LCDRAM15_FP31BP3     // ODO[2]
#define SEG_11G      LCDRAM15_FP31BP2     // ODO[2]
#define SEG_11C      LCDRAM15_FP31BP1     // ODO[2]
#define SEG_3      LCDRAM15_FP31BP0     // Gear Ind3
#define SEG_12A      LCDRAM15_FP30BP3     // ODO[1]
#define SEG_12F      LCDRAM15_FP30BP2     // ODO[1]
#define SEG_12E      LCDRAM15_FP30BP1     // ODO[1]
#define SEG_12D      LCDRAM15_FP30BP0     // ODO[1]
#define SEG_12B      LCDRAM14_FP29BP3     // ODO[1]
#define SEG_12G      LCDRAM14_FP29BP2     // ODO[1]
#define SEG_12C      LCDRAM14_FP29BP1     // ODO[1]
#define SEG_R4      LCDRAM14_FP29BP0     // ODO[DEC]
#define SEG_13A      LCDRAM14_FP28BP3     // ODO[0]
#define SEG_13F      LCDRAM14_FP28BP2     // ODO[0]
#define SEG_13E      LCDRAM14_FP28BP1     // ODO[0]
#define SEG_13D      LCDRAM14_FP28BP0     // ODO[0]
#define SEG_13B      LCDRAM13_FP27BP3     // ODO[0]
#define SEG_13G      LCDRAM13_FP27BP2     // ODO[0]
#define SEG_13C      LCDRAM13_FP27BP1     // ODO[0]
#define SEG_2      LCDRAM13_FP27BP0     // Gear Ind2
#define SEG_P33      LCDRAM13_FP26BP3     // Gallons
#define SEG_P34      LCDRAM13_FP26BP2     // ODO[MILES]
#define SEG_P35      LCDRAM13_FP26BP1     // ODO[KM]
#define SEG_1      LCDRAM13_FP26BP0     // Gear Ind1
#define SEG_P32      LCDRAM12_FP25BP3     // Liters
#define SEG_P36      LCDRAM12_FP25BP2     // Cruise
#define SEG_P37      LCDRAM12_FP25BP1     // Traction
#define SEG_P39      LCDRAM12_FP25BP0     // Low Press
#define SEG_P28      LCDRAM12_FP24BP3     // MPG
#define SEG_P30      LCDRAM12_FP24BP2     // L/100km
#define SEG_S5      LCDRAM12_FP24BP1     // Gear IndNumbers
#define SEG_S4      LCDRAM12_FP24BP0     // ENGAGED
#define SEG_P29      LCDRAM11_FP23BP3     // MPH
#define SEG_P31      LCDRAM11_FP23BP2     // km/h
#define SEG_P27      LCDRAM11_FP23BP1     // Remaining
#define SEG_S3      LCDRAM11_FP23BP0     // OFF
#define SEG_7D      LCDRAM11_FP22BP3     // Clock/Mileage[0]
#define SEG_7C      LCDRAM11_FP22BP2     // Clock/Mileage[0]
#define SEG_7B      LCDRAM11_FP22BP1     // Clock/Mileage[0]
#define SEG_7A      LCDRAM11_FP22BP0     // Clock/Mileage[0]
#define SEG_R3      LCDRAM10_FP21BP3     // Clock/Mileage[DEC]
#define SEG_7E      LCDRAM10_FP21BP2     // Clock/Mileage[0]
#define SEG_7G      LCDRAM10_FP21BP1     // Clock/Mileage[0]
#define SEG_7F      LCDRAM10_FP21BP0     // Clock/Mileage[0]
#define SEG_6D      LCDRAM10_FP20BP3     // Clock/Mileage[1]
#define SEG_6C      LCDRAM10_FP20BP2     // Clock/Mileage[1]
#define SEG_6B      LCDRAM10_FP20BP1     // Clock/Mileage[1]
#define SEG_6A      LCDRAM10_FP20BP0     // Clock/Mileage[1]
#define SEG_R2      LCDRAM0_FP0BP3     // Clock/Mileage[Colon]
#define SEG_6E      LCDRAM0_FP0BP2     // Clock/Mileage[1]
#define SEG_6G      LCDRAM0_FP0BP1     // Clock/Mileage[1]
#define SEG_6F      LCDRAM0_FP0BP0     // Clock/Mileage[1]
#define SEG_5C      LCDRAM0_FP1BP3     // Clock/Mileage[2]
#define SEG_5B      LCDRAM0_FP1BP2     // Clock/Mileage[2]
#define SEG_P25      LCDRAM0_FP1BP1     // Clock/Mileage[Distance]
#define SEG_P24      LCDRAM0_FP1BP0     // Clock/Mileage[Fuel]
#define SEG_5D      LCDRAM1_FP2BP3     // Clock/Mileage[2]
#define SEG_5G      LCDRAM1_FP2BP2     // Clock/Mileage[2]
#define SEG_5A      LCDRAM1_FP2BP1     // Clock/Mileage[2]
#define SEG_P26      LCDRAM1_FP2BP0     // Clock/Mileage[Used]
#define SEG_PM      LCDRAM1_FP3BP3     // Clock/Mileage[PM]
#define SEG_5E      LCDRAM1_FP3BP2     // Clock/Mileage[2]
#define SEG_5F      LCDRAM1_FP3BP1     // Clock/Mileage[2]
#define SEG_P21      LCDRAM1_FP3BP0     // Freescale Logo
#define SEG_AM      LCDRAM2_FP4BP3     // Clock/Mileage[AM]
#define SEG_4C      LCDRAM2_FP4BP2     // Clock/Mileage[3]
#define SEG_4B      LCDRAM2_FP4BP1     // Clock/Mileage[3]
#define SEG_T9      LCDRAM2_FP4BP0     // CompassNE
#define SEG_4D      LCDRAM2_FP5BP3     // Clock/Mileage[3]
#define SEG_4G      LCDRAM2_FP5BP2     // Clock/Mileage[3]
#define SEG_4A      LCDRAM2_FP5BP1     // Clock/Mileage[3]
#define SEG_P14      LCDRAM2_FP5BP0     // VoltageLabel
#define SEG_4E      LCDRAM3_FP6BP3     // Clock/Mileage[3]
#define SEG_4F      LCDRAM3_FP6BP2     // Clock/Mileage[3]
#define SEG_P23      LCDRAM3_FP6BP1     // Clock/Mileage[Inst]
#define SEG_P22      LCDRAM3_FP6BP0     // Clock/Mileage[Avg]
#define SEG_P17      LCDRAM3_FP7BP3     // VoltageBar [3]
#define SEG_P18      LCDRAM3_FP7BP2     // VoltageBar [2]
#define SEG_P19      LCDRAM3_FP7BP1     // VoltageBar [1]
#define SEG_P20      LCDRAM3_FP7BP0     // VoltageBar [0]
#define SEG_T6      LCDRAM4_FP8BP3     // CompassNW
#define SEG_T8      LCDRAM4_FP8BP2     // CompassSE
#define SEG_T5      LCDRAM4_FP8BP1     // CompassE
#define SEG_T2      LCDRAM4_FP8BP0     // CompassN
#define SEG_T4      LCDRAM4_FP9BP3     // CompassW
#define SEG_T3      LCDRAM4_FP9BP2     // CompassS
#define SEG_T7      LCDRAM4_FP9BP1     // CompassSW
#define SEG_T1      LCDRAM4_FP9BP0     // CompassRing
#define SEG_P16      LCDRAM5_FP10BP3     // VoltageBar [4]
#define SEG_P15      LCDRAM5_FP10BP2     // VoltageBar [5]
#define SEG_P11      LCDRAM5_FP10BP1     // TemperatureBar [4]
#define SEG_P12      LCDRAM5_FP10BP0     // TemperatureBar [5]
#define SEG_P5      LCDRAM5_FP11BP3     // Temperature[Engine]
#define SEG_P10      LCDRAM5_FP11BP2     // TemperatureBar [3]
#define SEG_F      LCDRAM5_FP11BP1     // Temperature[F]
#define SEG_C      LCDRAM5_FP11BP0     // Temperature[C]
#define SEG_3D      LCDRAM6_FP12BP3     // Temperature[0]
#define SEG_3C      LCDRAM6_FP12BP2     // Temperature[0]
#define SEG_3B      LCDRAM6_FP12BP1     // Temperature[0]
#define SEG_3A      LCDRAM6_FP12BP0     // Temperature[0]
#define SEG_R1      LCDRAM6_FP13BP3     // Temperature[DEC]
#define SEG_3E      LCDRAM6_FP13BP2     // Temperature[0]
#define SEG_3G      LCDRAM6_FP13BP1     // Temperature[0]
#define SEG_3F      LCDRAM6_FP13BP0     // Temperature[0]
#define SEG_2D      LCDRAM7_FP14BP3     // Temperature[1]
#define SEG_2C      LCDRAM7_FP14BP2     // Temperature[1]
#define SEG_2B      LCDRAM7_FP14BP1     // Temperature[1]
#define SEG_2A      LCDRAM7_FP14BP0     // Temperature[1]
#define SEG_P6      LCDRAM7_FP15BP3     // Temperature[Temp]
#define SEG_2E      LCDRAM7_FP15BP2     // Temperature[1]
#define SEG_2G      LCDRAM7_FP15BP1     // Temperature[1]
#define SEG_2F      LCDRAM7_FP15BP0     // Temperature[1]
#define SEG_1D      LCDRAM8_FP16BP3     // Temperature[2]
#define SEG_1C      LCDRAM8_FP16BP2     // Temperature[2]
#define SEG_1B      LCDRAM8_FP16BP1     // Temperature[2]
#define SEG_1A      LCDRAM8_FP16BP0     // Temperature[2]
#define SEG_S2      LCDRAM8_FP17BP3     // Temperature[Outside]
#define SEG_1E      LCDRAM8_FP17BP2     // Temperature[2]
#define SEG_1G      LCDRAM8_FP17BP1     // Temperature[2]
#define SEG_1F      LCDRAM8_FP17BP0     // Temperature[2]
#define SEG_P9      LCDRAM9_FP18BP3     // TemperatureBar [2]
#define SEG_P8      LCDRAM9_FP18BP2     // TemperatureBar [1]
#define SEG_P7      LCDRAM9_FP18BP1     // TemperatureBar [0]
#define SEG_P4      LCDRAM9_FP18BP0     // Temperature[Inside]
#define SEG_S1      LCDRAM9_FP19BP3     // JellyfishBody
#define SEG_P3      LCDRAM9_FP19BP2     // JellyfishTentacles
#define SEG_P2      LCDRAM9_FP19BP1     // JellyfishLabel
#define SEG_P1      LCDRAM9_FP19BP0     // JellyfishPart Num
