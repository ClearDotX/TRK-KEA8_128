/*
 * LCD.h
 *
 *  Created on: Feb 13, 2012
 *      Author: B40150
 */

#ifndef LCD_H_
#define LCD_H_


/*******************************************************************************
* Includes
********************************************************************************/

#include "derivative.h"

/*******************************************************************************
* Macros
********************************************************************************/


#define SEG_C1F        LCDRAM0_FP0BP0           //Clock 1
#define SEG_C1G        LCDRAM0_FP0BP1           //Clock 1
#define SEG_C1E        LCDRAM0_FP0BP2           //Clock 1
#define SEG_C1D        LCDRAM0_FP0BP3           //Clock 1
#define SEG_C1A        LCDRAM0_FP1BP0           //Clock 1
#define SEG_C1B        LCDRAM0_FP1BP1           //Clock 1
#define SEG_C1C        LCDRAM0_FP1BP2           //Clock 1
#define SEG_AVG        LCDRAM0_FP1BP3           //Average
#define SEG_C2F        LCDRAM1_FP2BP0           //Clock 2
#define SEG_C2G        LCDRAM1_FP2BP1           //Clock 2
#define SEG_C2E        LCDRAM1_FP2BP2           //Clock 2
#define SEG_C2D        LCDRAM1_FP2BP3           //Clock 2
#define SEG_C2A        LCDRAM1_FP3BP0           //Clock 2
#define SEG_C2B        LCDRAM1_FP3BP1           //Clock 2
#define SEG_C2C        LCDRAM1_FP3BP2           //Clock 2
#define SEG_CHKENG     LCDRAM1_FP3BP3           //Check Service Logo
#define SEG_C3F        LCDRAM2_FP4BP0           //Clock 3
#define SEG_C3G        LCDRAM2_FP4BP1           //Clock 3
#define SEG_C3E        LCDRAM2_FP4BP2           //Clock 3
#define SEG_C3D        LCDRAM2_FP4BP3           //Clock 3
#define SEG_C3A        LCDRAM2_FP5BP0           //Clock 3
#define SEG_C3B        LCDRAM2_FP5BP1           //Clock 3
#define SEG_C3C        LCDRAM2_FP5BP2           //Clock 3
#define SEG_24H        LCDRAM2_FP5BP3           //24H on clock
#define SEG_C4F        LCDRAM3_FP6BP0           //Clock 4
#define SEG_C4G        LCDRAM3_FP6BP1           //Clock 4
#define SEG_C4E        LCDRAM3_FP6BP2           //Clock 4
#define SEG_C4D        LCDRAM3_FP6BP3           //Clock 4
#define SEG_C4A        LCDRAM3_FP7BP0           //Clock 4
#define SEG_C4B        LCDRAM3_FP7BP1           //Clock 4
#define SEG_C4C        LCDRAM3_FP7BP2           //Clock 4
#define SEG_CCOL       LCDRAM3_FP7BP3           //Clock collons
#define SEG_C5F        LCDRAM4_FP8BP0           //Clock 5
#define SEG_C5G        LCDRAM4_FP8BP1           //Clock 5
#define SEG_C5E        LCDRAM4_FP8BP2           //Clock 5
#define SEG_C5D        LCDRAM4_FP8BP3           //Clock 5
#define SEG_C5A        LCDRAM4_FP9BP0           //Clock 5
#define SEG_C5B        LCDRAM4_FP9BP1           //Clock 5
#define SEG_C5C        LCDRAM4_FP9BP2           //Clock 5
#define SEG_PM         LCDRAM4_FP9BP3           //PM on clock
#define SEG_C6F        LCDRAM5_FP10BP0           //Clock 6
#define SEG_C6G        LCDRAM5_FP10BP1           //Clock 6
#define SEG_C6E        LCDRAM5_FP10BP2           //Clock 6
#define SEG_C6D        LCDRAM5_FP10BP3           //Clock 6
#define SEG_C6A        LCDRAM5_FP11BP0           //Clock 6
#define SEG_C6B        LCDRAM5_FP11BP1           //Clock 6
#define SEG_C6C        LCDRAM5_FP11BP2           //Clock 6
#define SEG_AM         LCDRAM5_FP11BP3           //AM on clock
#define SEG_D1F        LCDRAM6_FP12BP0           //Data 1
#define SEG_D1G        LCDRAM6_FP12BP1           //Data 1
#define SEG_D1E        LCDRAM6_FP12BP2           //Data 1
#define SEG_D1D        LCDRAM6_FP12BP3           //Data 1
#define SEG_D1A        LCDRAM6_FP13BP0           //Data 1
#define SEG_D1B        LCDRAM6_FP13BP1           //Data 1
#define SEG_D1C        LCDRAM6_FP13BP2           //Data 1
#define SEG_ET         LCDRAM6_FP13BP3           //Estimated travel logo
#define SEG_D2F        LCDRAM7_FP14BP0           //Data 2
#define SEG_D2G        LCDRAM7_FP14BP1           //Data 2
#define SEG_D2E        LCDRAM7_FP14BP2           //Data 2
#define SEG_D2D        LCDRAM7_FP14BP3           //Data 2
#define SEG_D2A        LCDRAM7_FP15BP0           //Data 2
#define SEG_D2B        LCDRAM7_FP15BP1           //Data 2
#define SEG_D2C        LCDRAM7_FP15BP2           //Data 2
#define SEG_DCOL       LCDRAM7_FP15BP3           //Data collon
#define SEG_D3F        LCDRAM8_FP16BP0           //Data 3
#define SEG_D3G        LCDRAM8_FP16BP1           //Data 3
#define SEG_D3E        LCDRAM8_FP16BP2           //Data 3
#define SEG_D3D        LCDRAM8_FP16BP3           //Data 3
#define SEG_D3A        LCDRAM8_FP17BP0           //Data 3
#define SEG_D3B        LCDRAM8_FP17BP1           //Data 3
#define SEG_D3C        LCDRAM8_FP17BP2           //Data 3
#define SEG_DP         LCDRAM8_FP17BP3           //Data Point
#define SEG_D4F        LCDRAM9_FP18BP0           //Data 4
#define SEG_D4G        LCDRAM9_FP18BP1           //Data 4
#define SEG_D4E        LCDRAM9_FP18BP2           //Data 4
#define SEG_D4D        LCDRAM9_FP18BP3           //Data 4
#define SEG_D4A        LCDRAM9_FP19BP0           //Data 4
#define SEG_D4B        LCDRAM9_FP19BP1           //Data 4
#define SEG_D4C        LCDRAM9_FP19BP2           //Data 4
#define SEG_ECOMODE    LCDRAM9_FP19BP3           //EcoMode Logo
#define SEG_HLINE      LCDRAM10_FP20BP0           //Horizontal division line
#define SEG_KMH        LCDRAM10_FP20BP1           //Kilometers per hour
#define SEG_KML        LCDRAM10_FP20BP2           //Kilometers per liter
#define SEG_GP         LCDRAM10_FP20BP3           //Gas Pump
#define SEG_FSL        LCDRAM10_FP21BP0           //Freescale logo
#define SEG_F          LCDRAM10_FP21BP1           //Full F
#define SEG_SBARS      LCDRAM10_FP21BP2           //Fuel level sidebars
#define SEG_E          LCDRAM10_FP21BP3           //Empty E
#define SEG_B7         LCDRAM11_FP22BP0           //Bar 7
#define SEG_B6         LCDRAM11_FP22BP1           //Bar 6
#define SEG_B5         LCDRAM11_FP22BP2           //Bar 5
#define SEG_B4         LCDRAM11_FP22BP3           //Bar 4
#define SEG_B0         LCDRAM11_FP23BP0           //Bar 0
#define SEG_B1         LCDRAM11_FP23BP1           //Bar 1
#define SEG_B2         LCDRAM11_FP23BP2           //Bar 2
#define SEG_B3         LCDRAM11_FP23BP3           //Bar 3
#define SEG_C          LCDRAM12_FP24BP0           //Centigrades logo
#define SEG_O6C        LCDRAM12_FP24BP1           //Odo 6
#define SEG_O6B        LCDRAM12_FP24BP2           //Odo 6
#define SEG_O6A        LCDRAM12_FP24BP3           //Odo 6
#define SEG_O6D        LCDRAM12_FP25BP0           //Odo 6
#define SEG_O6E        LCDRAM12_FP25BP1           //Odo 6
#define SEG_O6G        LCDRAM12_FP25BP2           //Odo 6
#define SEG_O6F        LCDRAM12_FP25BP3           //Odo 6
#define SEG_OP         LCDRAM13_FP26BP0           //Odo point
#define SEG_O5C        LCDRAM13_FP26BP1           //Odo 5
#define SEG_O5B        LCDRAM13_FP26BP2           //Odo 5
#define SEG_O5A        LCDRAM13_FP26BP3           //Odo 5
#define SEG_O5D        LCDRAM13_FP27BP0           //Odo 5
#define SEG_O5E        LCDRAM13_FP27BP1           //Odo 5
#define SEG_O5G        LCDRAM13_FP27BP2           //Odo 5
#define SEG_O5F        LCDRAM13_FP27BP3           //Odo 5
#define SEG_KM         LCDRAM14_FP28BP0           //KM in odo
#define SEG_O4C        LCDRAM14_FP28BP1           //Odo 4
#define SEG_O4B        LCDRAM14_FP28BP2           //Odo 4
#define SEG_O4A        LCDRAM14_FP28BP3           //Odo 4
#define SEG_O4D        LCDRAM14_FP29BP0           //Odo 4
#define SEG_O4E        LCDRAM14_FP29BP1           //Odo 4
#define SEG_O4G        LCDRAM14_FP29BP2           //Odo 4
#define SEG_O4F        LCDRAM14_FP29BP3           //Odo 4
#define SEG_TOZ        LCDRAM15_FP30BP0           //TO ZERO in odo
#define SEG_O3C        LCDRAM15_FP30BP1           //Odo 3
#define SEG_O3B        LCDRAM15_FP30BP2           //Odo 3
#define SEG_O3A        LCDRAM15_FP30BP3           //Odo 3
#define SEG_O3D        LCDRAM15_FP31BP0           //Odo 3
#define SEG_O3E        LCDRAM15_FP31BP1           //Odo 3
#define SEG_O3G        LCDRAM15_FP31BP2           //Odo 3
#define SEG_O3F        LCDRAM15_FP31BP3           //Odo 3
#define SEG_RANGE      LCDRAM16_FP32BP0           //RANGE in odo
#define SEG_O2C        LCDRAM16_FP32BP1           //Odo 2
#define SEG_O2B        LCDRAM16_FP32BP2           //Odo 2
#define SEG_O2A        LCDRAM16_FP32BP3           //Odo 2
#define SEG_O2D        LCDRAM16_FP33BP0           //Odo 2
#define SEG_O2E        LCDRAM16_FP33BP1           //Odo 2
#define SEG_O2G        LCDRAM16_FP33BP2           //Odo 2
#define SEG_O2F        LCDRAM16_FP33BP3           //Odo 2
#define SEG_TEMP       LCDRAM17_FP34BP0           //TEMP in odo
#define SEG_O1C        LCDRAM17_FP34BP1           //Odo 1
#define SEG_O1B        LCDRAM17_FP34BP2           //Odo 1
#define SEG_O1A        LCDRAM17_FP34BP3           //Odo 1
#define SEG_O1D        LCDRAM17_FP35BP0           //Odo 1
#define SEG_O1E        LCDRAM17_FP35BP1           //Odo 1
#define SEG_O1G        LCDRAM17_FP35BP2           //Odo 1
#define SEG_O1F        LCDRAM17_FP35BP3           //Odo 1
#define SEG_ODO        LCDRAM18_FP36BP0           //ODO in odo
#define SEG_B          LCDRAM18_FP36BP1           //Trip B
#define SEG_A          LCDRAM18_FP36BP2           //Trip A
#define SEG_TRIP       LCDRAM18_FP36BP3           //TRIM in odo
#define SEG_GC         LCDRAM18_FP37BP0           //Gear
#define SEG_GJ         LCDRAM18_FP37BP1           //Gear
#define SEG_GB         LCDRAM18_FP37BP2           //Gear
#define SEG_GI         LCDRAM18_FP37BP3           //Gear
#define SEG_GD         LCDRAM19_FP38BP0           //Gear
#define SEG_GK         LCDRAM19_FP38BP1           //Gear
#define SEG_GG         LCDRAM19_FP38BP2           //Gear
#define SEG_GH         LCDRAM19_FP38BP3           //Gear
#define SEG_VLINE      LCDRAM19_FP39BP0           //Vertical division line
#define SEG_GE         LCDRAM19_FP39BP1           //Gear
#define SEG_GF         LCDRAM19_FP39BP2           //Gear
#define SEG_GA         LCDRAM19_FP39BP3           //Gear


#define D1_B    {SEG_D1A = 0;  SEG_D1B = 0;  SEG_D1C = 0;  SEG_D1D = 0;  SEG_D1E = 0;  SEG_D1F = 0;  SEG_D1G = 0; }
#define D1_0    {SEG_D1A = 1;  SEG_D1B = 1;  SEG_D1C = 1;  SEG_D1D = 1;  SEG_D1E = 1;  SEG_D1F = 1;  SEG_D1G = 0; }
#define D1_1    {SEG_D1A = 0;  SEG_D1B = 1;  SEG_D1C = 1;  SEG_D1D = 0;  SEG_D1E = 0;  SEG_D1F = 0;  SEG_D1G = 0; }
#define D1_2    {SEG_D1A = 1;  SEG_D1B = 1;  SEG_D1C = 0;  SEG_D1D = 1;  SEG_D1E = 1;  SEG_D1F = 0;  SEG_D1G = 1; }
#define D1_3    {SEG_D1A = 1;  SEG_D1B = 1;  SEG_D1C = 1;  SEG_D1D = 1;  SEG_D1E = 0;  SEG_D1F = 0;  SEG_D1G = 1; }
#define D1_4    {SEG_D1A = 0;  SEG_D1B = 1;  SEG_D1C = 1;  SEG_D1D = 0;  SEG_D1E = 0;  SEG_D1F = 1;  SEG_D1G = 1; }
#define D1_5    {SEG_D1A = 1;  SEG_D1B = 0;  SEG_D1C = 1;  SEG_D1D = 1;  SEG_D1E = 0;  SEG_D1F = 1;  SEG_D1G = 1; }
#define D1_6    {SEG_D1A = 1;  SEG_D1B = 0;  SEG_D1C = 1;  SEG_D1D = 1;  SEG_D1E = 1;  SEG_D1F = 1;  SEG_D1G = 1; }
#define D1_7    {SEG_D1A = 1;  SEG_D1B = 1;  SEG_D1C = 1;  SEG_D1D = 0;  SEG_D1E = 0;  SEG_D1F = 0;  SEG_D1G = 0; }
#define D1_8    {SEG_D1A = 1;  SEG_D1B = 1;  SEG_D1C = 1;  SEG_D1D = 1;  SEG_D1E = 1;  SEG_D1F = 1;  SEG_D1G = 1; }
#define D1_9    {SEG_D1A = 1;  SEG_D1B = 1;  SEG_D1C = 1;  SEG_D1D = 0;  SEG_D1E = 0;  SEG_D1F = 1;  SEG_D1G = 1; }
#define D2_B    {SEG_D2A = 0;  SEG_D2B = 0;  SEG_D2C = 0;  SEG_D2D = 0;  SEG_D2E = 0;  SEG_D2F = 0;  SEG_D2G = 0; }
#define D2_0    {SEG_D2A = 1;  SEG_D2B = 1;  SEG_D2C = 1;  SEG_D2D = 1;  SEG_D2E = 1;  SEG_D2F = 1;  SEG_D2G = 0; }
#define D2_1    {SEG_D2A = 0;  SEG_D2B = 1;  SEG_D2C = 1;  SEG_D2D = 0;  SEG_D2E = 0;  SEG_D2F = 0;  SEG_D2G = 0; }
#define D2_2    {SEG_D2A = 1;  SEG_D2B = 1;  SEG_D2C = 0;  SEG_D2D = 1;  SEG_D2E = 1;  SEG_D2F = 0;  SEG_D2G = 1; }
#define D2_3    {SEG_D2A = 1;  SEG_D2B = 1;  SEG_D2C = 1;  SEG_D2D = 1;  SEG_D2E = 0;  SEG_D2F = 0;  SEG_D2G = 1; }
#define D2_4    {SEG_D2A = 0;  SEG_D2B = 1;  SEG_D2C = 1;  SEG_D2D = 0;  SEG_D2E = 0;  SEG_D2F = 1;  SEG_D2G = 1; }
#define D2_5    {SEG_D2A = 1;  SEG_D2B = 0;  SEG_D2C = 1;  SEG_D2D = 1;  SEG_D2E = 0;  SEG_D2F = 1;  SEG_D2G = 1; }
#define D2_6    {SEG_D2A = 1;  SEG_D2B = 0;  SEG_D2C = 1;  SEG_D2D = 1;  SEG_D2E = 1;  SEG_D2F = 1;  SEG_D2G = 1; }
#define D2_7    {SEG_D2A = 1;  SEG_D2B = 1;  SEG_D2C = 1;  SEG_D2D = 0;  SEG_D2E = 0;  SEG_D2F = 0;  SEG_D2G = 0; }
#define D2_8    {SEG_D2A = 1;  SEG_D2B = 1;  SEG_D2C = 1;  SEG_D2D = 1;  SEG_D2E = 1;  SEG_D2F = 1;  SEG_D2G = 1; }
#define D2_9    {SEG_D2A = 1;  SEG_D2B = 1;  SEG_D2C = 1;  SEG_D2D = 0;  SEG_D2E = 0;  SEG_D2F = 1;  SEG_D2G = 1; }
#define D3_B    {SEG_D3A = 0;  SEG_D3B = 0;  SEG_D3C = 0;  SEG_D3D = 0;  SEG_D3E = 0;  SEG_D3F = 0;  SEG_D3G = 0; }
#define D3_0    {SEG_D3A = 1;  SEG_D3B = 1;  SEG_D3C = 1;  SEG_D3D = 1;  SEG_D3E = 1;  SEG_D3F = 1;  SEG_D3G = 0; }
#define D3_1    {SEG_D3A = 0;  SEG_D3B = 1;  SEG_D3C = 1;  SEG_D3D = 0;  SEG_D3E = 0;  SEG_D3F = 0;  SEG_D3G = 0; }
#define D3_2    {SEG_D3A = 1;  SEG_D3B = 1;  SEG_D3C = 0;  SEG_D3D = 1;  SEG_D3E = 1;  SEG_D3F = 0;  SEG_D3G = 1; }
#define D3_3    {SEG_D3A = 1;  SEG_D3B = 1;  SEG_D3C = 1;  SEG_D3D = 1;  SEG_D3E = 0;  SEG_D3F = 0;  SEG_D3G = 1; }
#define D3_4    {SEG_D3A = 0;  SEG_D3B = 1;  SEG_D3C = 1;  SEG_D3D = 0;  SEG_D3E = 0;  SEG_D3F = 1;  SEG_D3G = 1; }
#define D3_5    {SEG_D3A = 1;  SEG_D3B = 0;  SEG_D3C = 1;  SEG_D3D = 1;  SEG_D3E = 0;  SEG_D3F = 1;  SEG_D3G = 1; }
#define D3_6    {SEG_D3A = 1;  SEG_D3B = 0;  SEG_D3C = 1;  SEG_D3D = 1;  SEG_D3E = 1;  SEG_D3F = 1;  SEG_D3G = 1; }
#define D3_7    {SEG_D3A = 1;  SEG_D3B = 1;  SEG_D3C = 1;  SEG_D3D = 0;  SEG_D3E = 0;  SEG_D3F = 0;  SEG_D3G = 0; }
#define D3_8    {SEG_D3A = 1;  SEG_D3B = 1;  SEG_D3C = 1;  SEG_D3D = 1;  SEG_D3E = 1;  SEG_D3F = 1;  SEG_D3G = 1; }
#define D3_9    {SEG_D3A = 1;  SEG_D3B = 1;  SEG_D3C = 1;  SEG_D3D = 0;  SEG_D3E = 0;  SEG_D3F = 1;  SEG_D3G = 1; }
#define D4_B    {SEG_D4A = 0;  SEG_D4B = 0;  SEG_D4C = 0;  SEG_D4D = 0;  SEG_D4E = 0;  SEG_D4F = 0;  SEG_D4G = 0; }
#define D4_0    {SEG_D4A = 1;  SEG_D4B = 1;  SEG_D4C = 1;  SEG_D4D = 1;  SEG_D4E = 1;  SEG_D4F = 1;  SEG_D4G = 0; }
#define D4_1    {SEG_D4A = 0;  SEG_D4B = 1;  SEG_D4C = 1;  SEG_D4D = 0;  SEG_D4E = 0;  SEG_D4F = 0;  SEG_D4G = 0; }
#define D4_2    {SEG_D4A = 1;  SEG_D4B = 1;  SEG_D4C = 0;  SEG_D4D = 1;  SEG_D4E = 1;  SEG_D4F = 0;  SEG_D4G = 1; }
#define D4_3    {SEG_D4A = 1;  SEG_D4B = 1;  SEG_D4C = 1;  SEG_D4D = 1;  SEG_D4E = 0;  SEG_D4F = 0;  SEG_D4G = 1; }
#define D4_4    {SEG_D4A = 0;  SEG_D4B = 1;  SEG_D4C = 1;  SEG_D4D = 0;  SEG_D4E = 0;  SEG_D4F = 1;  SEG_D4G = 1; }
#define D4_5    {SEG_D4A = 1;  SEG_D4B = 0;  SEG_D4C = 1;  SEG_D4D = 1;  SEG_D4E = 0;  SEG_D4F = 1;  SEG_D4G = 1; }
#define D4_6    {SEG_D4A = 1;  SEG_D4B = 0;  SEG_D4C = 1;  SEG_D4D = 1;  SEG_D4E = 1;  SEG_D4F = 1;  SEG_D4G = 1; }
#define D4_7    {SEG_D4A = 1;  SEG_D4B = 1;  SEG_D4C = 1;  SEG_D4D = 0;  SEG_D4E = 0;  SEG_D4F = 0;  SEG_D4G = 0; }
#define D4_8    {SEG_D4A = 1;  SEG_D4B = 1;  SEG_D4C = 1;  SEG_D4D = 1;  SEG_D4E = 1;  SEG_D4F = 1;  SEG_D4G = 1; }
#define D4_9    {SEG_D4A = 1;  SEG_D4B = 1;  SEG_D4C = 1;  SEG_D4D = 0;  SEG_D4E = 0;  SEG_D4F = 1;  SEG_D4G = 1; }
#define C1_B    {SEG_C1A = 0;  SEG_C1B = 0;  SEG_C1C = 0;  SEG_C1D = 0;  SEG_C1E = 0;  SEG_C1F = 0;  SEG_C1G = 0; }
#define C1_0    {SEG_C1A = 1;  SEG_C1B = 1;  SEG_C1C = 1;  SEG_C1D = 1;  SEG_C1E = 1;  SEG_C1F = 1;  SEG_C1G = 0; }
#define C1_1    {SEG_C1A = 0;  SEG_C1B = 1;  SEG_C1C = 1;  SEG_C1D = 0;  SEG_C1E = 0;  SEG_C1F = 0;  SEG_C1G = 0; }
#define C1_2    {SEG_C1A = 1;  SEG_C1B = 1;  SEG_C1C = 0;  SEG_C1D = 1;  SEG_C1E = 1;  SEG_C1F = 0;  SEG_C1G = 1; }
#define C1_3    {SEG_C1A = 1;  SEG_C1B = 1;  SEG_C1C = 1;  SEG_C1D = 1;  SEG_C1E = 0;  SEG_C1F = 0;  SEG_C1G = 1; }
#define C1_4    {SEG_C1A = 0;  SEG_C1B = 1;  SEG_C1C = 1;  SEG_C1D = 0;  SEG_C1E = 0;  SEG_C1F = 1;  SEG_C1G = 1; }
#define C1_5    {SEG_C1A = 1;  SEG_C1B = 0;  SEG_C1C = 1;  SEG_C1D = 1;  SEG_C1E = 0;  SEG_C1F = 1;  SEG_C1G = 1; }
#define C1_6    {SEG_C1A = 1;  SEG_C1B = 0;  SEG_C1C = 1;  SEG_C1D = 1;  SEG_C1E = 1;  SEG_C1F = 1;  SEG_C1G = 1; }
#define C1_7    {SEG_C1A = 1;  SEG_C1B = 1;  SEG_C1C = 1;  SEG_C1D = 0;  SEG_C1E = 0;  SEG_C1F = 0;  SEG_C1G = 0; }
#define C1_8    {SEG_C1A = 1;  SEG_C1B = 1;  SEG_C1C = 1;  SEG_C1D = 1;  SEG_C1E = 1;  SEG_C1F = 1;  SEG_C1G = 1; }
#define C1_9    {SEG_C1A = 1;  SEG_C1B = 1;  SEG_C1C = 1;  SEG_C1D = 0;  SEG_C1E = 0;  SEG_C1F = 1;  SEG_C1G = 1; }
#define C2_B    {SEG_C2A = 0;  SEG_C2B = 0;  SEG_C2C = 0;  SEG_C2D = 0;  SEG_C2E = 0;  SEG_C2F = 0;  SEG_C2G = 0; }
#define C2_0    {SEG_C2A = 1;  SEG_C2B = 1;  SEG_C2C = 1;  SEG_C2D = 1;  SEG_C2E = 1;  SEG_C2F = 1;  SEG_C2G = 0; }
#define C2_1    {SEG_C2A = 0;  SEG_C2B = 1;  SEG_C2C = 1;  SEG_C2D = 0;  SEG_C2E = 0;  SEG_C2F = 0;  SEG_C2G = 0; }
#define C2_2    {SEG_C2A = 1;  SEG_C2B = 1;  SEG_C2C = 0;  SEG_C2D = 1;  SEG_C2E = 1;  SEG_C2F = 0;  SEG_C2G = 1; }
#define C2_3    {SEG_C2A = 1;  SEG_C2B = 1;  SEG_C2C = 1;  SEG_C2D = 1;  SEG_C2E = 0;  SEG_C2F = 0;  SEG_C2G = 1; }
#define C2_4    {SEG_C2A = 0;  SEG_C2B = 1;  SEG_C2C = 1;  SEG_C2D = 0;  SEG_C2E = 0;  SEG_C2F = 1;  SEG_C2G = 1; }
#define C2_5    {SEG_C2A = 1;  SEG_C2B = 0;  SEG_C2C = 1;  SEG_C2D = 1;  SEG_C2E = 0;  SEG_C2F = 1;  SEG_C2G = 1; }
#define C2_6    {SEG_C2A = 1;  SEG_C2B = 0;  SEG_C2C = 1;  SEG_C2D = 1;  SEG_C2E = 1;  SEG_C2F = 1;  SEG_C2G = 1; }
#define C2_7    {SEG_C2A = 1;  SEG_C2B = 1;  SEG_C2C = 1;  SEG_C2D = 0;  SEG_C2E = 0;  SEG_C2F = 0;  SEG_C2G = 0; }
#define C2_8    {SEG_C2A = 1;  SEG_C2B = 1;  SEG_C2C = 1;  SEG_C2D = 1;  SEG_C2E = 1;  SEG_C2F = 1;  SEG_C2G = 1; }
#define C2_9    {SEG_C2A = 1;  SEG_C2B = 1;  SEG_C2C = 1;  SEG_C2D = 0;  SEG_C2E = 0;  SEG_C2F = 1;  SEG_C2G = 1; }
#define C3_B    {SEG_C3A = 0;  SEG_C3B = 0;  SEG_C3C = 0;  SEG_C3D = 0;  SEG_C3E = 0;  SEG_C3F = 0;  SEG_C3G = 0; }
#define C3_0    {SEG_C3A = 1;  SEG_C3B = 1;  SEG_C3C = 1;  SEG_C3D = 1;  SEG_C3E = 1;  SEG_C3F = 1;  SEG_C3G = 0; }
#define C3_1    {SEG_C3A = 0;  SEG_C3B = 1;  SEG_C3C = 1;  SEG_C3D = 0;  SEG_C3E = 0;  SEG_C3F = 0;  SEG_C3G = 0; }
#define C3_2    {SEG_C3A = 1;  SEG_C3B = 1;  SEG_C3C = 0;  SEG_C3D = 1;  SEG_C3E = 1;  SEG_C3F = 0;  SEG_C3G = 1; }
#define C3_3    {SEG_C3A = 1;  SEG_C3B = 1;  SEG_C3C = 1;  SEG_C3D = 1;  SEG_C3E = 0;  SEG_C3F = 0;  SEG_C3G = 1; }
#define C3_4    {SEG_C3A = 0;  SEG_C3B = 1;  SEG_C3C = 1;  SEG_C3D = 0;  SEG_C3E = 0;  SEG_C3F = 1;  SEG_C3G = 1; }
#define C3_5    {SEG_C3A = 1;  SEG_C3B = 0;  SEG_C3C = 1;  SEG_C3D = 1;  SEG_C3E = 0;  SEG_C3F = 1;  SEG_C3G = 1; }
#define C3_6    {SEG_C3A = 1;  SEG_C3B = 0;  SEG_C3C = 1;  SEG_C3D = 1;  SEG_C3E = 1;  SEG_C3F = 1;  SEG_C3G = 1; }
#define C3_7    {SEG_C3A = 1;  SEG_C3B = 1;  SEG_C3C = 1;  SEG_C3D = 0;  SEG_C3E = 0;  SEG_C3F = 0;  SEG_C3G = 0; }
#define C3_8    {SEG_C3A = 1;  SEG_C3B = 1;  SEG_C3C = 1;  SEG_C3D = 1;  SEG_C3E = 1;  SEG_C3F = 1;  SEG_C3G = 1; }
#define C3_9    {SEG_C3A = 1;  SEG_C3B = 1;  SEG_C3C = 1;  SEG_C3D = 0;  SEG_C3E = 0;  SEG_C3F = 1;  SEG_C3G = 1; }
#define C4_B    {SEG_C4A = 0;  SEG_C4B = 0;  SEG_C4C = 0;  SEG_C4D = 0;  SEG_C4E = 0;  SEG_C4F = 0;  SEG_C4G = 0; }
#define C4_0    {SEG_C4A = 1;  SEG_C4B = 1;  SEG_C4C = 1;  SEG_C4D = 1;  SEG_C4E = 1;  SEG_C4F = 1;  SEG_C4G = 0; }
#define C4_1    {SEG_C4A = 0;  SEG_C4B = 1;  SEG_C4C = 1;  SEG_C4D = 0;  SEG_C4E = 0;  SEG_C4F = 0;  SEG_C4G = 0; }
#define C4_2    {SEG_C4A = 1;  SEG_C4B = 1;  SEG_C4C = 0;  SEG_C4D = 1;  SEG_C4E = 1;  SEG_C4F = 0;  SEG_C4G = 1; }
#define C4_3    {SEG_C4A = 1;  SEG_C4B = 1;  SEG_C4C = 1;  SEG_C4D = 1;  SEG_C4E = 0;  SEG_C4F = 0;  SEG_C4G = 1; }
#define C4_4    {SEG_C4A = 0;  SEG_C4B = 1;  SEG_C4C = 1;  SEG_C4D = 0;  SEG_C4E = 0;  SEG_C4F = 1;  SEG_C4G = 1; }
#define C4_5    {SEG_C4A = 1;  SEG_C4B = 0;  SEG_C4C = 1;  SEG_C4D = 1;  SEG_C4E = 0;  SEG_C4F = 1;  SEG_C4G = 1; }
#define C4_6    {SEG_C4A = 1;  SEG_C4B = 0;  SEG_C4C = 1;  SEG_C4D = 1;  SEG_C4E = 1;  SEG_C4F = 1;  SEG_C4G = 1; }
#define C4_7    {SEG_C4A = 1;  SEG_C4B = 1;  SEG_C4C = 1;  SEG_C4D = 0;  SEG_C4E = 0;  SEG_C4F = 0;  SEG_C4G = 0; }
#define C4_8    {SEG_C4A = 1;  SEG_C4B = 1;  SEG_C4C = 1;  SEG_C4D = 1;  SEG_C4E = 1;  SEG_C4F = 1;  SEG_C4G = 1; }
#define C4_9    {SEG_C4A = 1;  SEG_C4B = 1;  SEG_C4C = 1;  SEG_C4D = 0;  SEG_C4E = 0;  SEG_C4F = 1;  SEG_C4G = 1; }
#define C5_B    {SEG_C5A = 0;  SEG_C5B = 0;  SEG_C5C = 0;  SEG_C5D = 0;  SEG_C5E = 0;  SEG_C5F = 0;  SEG_C5G = 0; }
#define C5_0    {SEG_C5A = 1;  SEG_C5B = 1;  SEG_C5C = 1;  SEG_C5D = 1;  SEG_C5E = 1;  SEG_C5F = 1;  SEG_C5G = 0; }
#define C5_1    {SEG_C5A = 0;  SEG_C5B = 1;  SEG_C5C = 1;  SEG_C5D = 0;  SEG_C5E = 0;  SEG_C5F = 0;  SEG_C5G = 0; }
#define C5_2    {SEG_C5A = 1;  SEG_C5B = 1;  SEG_C5C = 0;  SEG_C5D = 1;  SEG_C5E = 1;  SEG_C5F = 0;  SEG_C5G = 1; }
#define C5_3    {SEG_C5A = 1;  SEG_C5B = 1;  SEG_C5C = 1;  SEG_C5D = 1;  SEG_C5E = 0;  SEG_C5F = 0;  SEG_C5G = 1; }
#define C5_4    {SEG_C5A = 0;  SEG_C5B = 1;  SEG_C5C = 1;  SEG_C5D = 0;  SEG_C5E = 0;  SEG_C5F = 1;  SEG_C5G = 1; }
#define C5_5    {SEG_C5A = 1;  SEG_C5B = 0;  SEG_C5C = 1;  SEG_C5D = 1;  SEG_C5E = 0;  SEG_C5F = 1;  SEG_C5G = 1; }
#define C5_6    {SEG_C5A = 1;  SEG_C5B = 0;  SEG_C5C = 1;  SEG_C5D = 1;  SEG_C5E = 1;  SEG_C5F = 1;  SEG_C5G = 1; }
#define C5_7    {SEG_C5A = 1;  SEG_C5B = 1;  SEG_C5C = 1;  SEG_C5D = 0;  SEG_C5E = 0;  SEG_C5F = 0;  SEG_C5G = 0; }
#define C5_8    {SEG_C5A = 1;  SEG_C5B = 1;  SEG_C5C = 1;  SEG_C5D = 1;  SEG_C5E = 1;  SEG_C5F = 1;  SEG_C5G = 1; }
#define C5_9    {SEG_C5A = 1;  SEG_C5B = 1;  SEG_C5C = 1;  SEG_C5D = 0;  SEG_C5E = 0;  SEG_C5F = 1;  SEG_C5G = 1; }
#define C6_B    {SEG_C6A = 0;  SEG_C6B = 0;  SEG_C6C = 0;  SEG_C6D = 0;  SEG_C6E = 0;  SEG_C6F = 0;  SEG_C6G = 0; }
#define C6_0    {SEG_C6A = 1;  SEG_C6B = 1;  SEG_C6C = 1;  SEG_C6D = 1;  SEG_C6E = 1;  SEG_C6F = 1;  SEG_C6G = 0; }
#define C6_1    {SEG_C6A = 0;  SEG_C6B = 1;  SEG_C6C = 1;  SEG_C6D = 0;  SEG_C6E = 0;  SEG_C6F = 0;  SEG_C6G = 0; }
#define C6_2    {SEG_C6A = 1;  SEG_C6B = 1;  SEG_C6C = 0;  SEG_C6D = 1;  SEG_C6E = 1;  SEG_C6F = 0;  SEG_C6G = 1; }
#define C6_3    {SEG_C6A = 1;  SEG_C6B = 1;  SEG_C6C = 1;  SEG_C6D = 1;  SEG_C6E = 0;  SEG_C6F = 0;  SEG_C6G = 1; }
#define C6_4    {SEG_C6A = 0;  SEG_C6B = 1;  SEG_C6C = 1;  SEG_C6D = 0;  SEG_C6E = 0;  SEG_C6F = 1;  SEG_C6G = 1; }
#define C6_5    {SEG_C6A = 1;  SEG_C6B = 0;  SEG_C6C = 1;  SEG_C6D = 1;  SEG_C6E = 0;  SEG_C6F = 1;  SEG_C6G = 1; }
#define C6_6    {SEG_C6A = 1;  SEG_C6B = 0;  SEG_C6C = 1;  SEG_C6D = 1;  SEG_C6E = 1;  SEG_C6F = 1;  SEG_C6G = 1; }
#define C6_7    {SEG_C6A = 1;  SEG_C6B = 1;  SEG_C6C = 1;  SEG_C6D = 0;  SEG_C6E = 0;  SEG_C6F = 0;  SEG_C6G = 0; }
#define C6_8    {SEG_C6A = 1;  SEG_C6B = 1;  SEG_C6C = 1;  SEG_C6D = 1;  SEG_C6E = 1;  SEG_C6F = 1;  SEG_C6G = 1; }
#define C6_9    {SEG_C6A = 1;  SEG_C6B = 1;  SEG_C6C = 1;  SEG_C6D = 0;  SEG_C6E = 0;  SEG_C6F = 1;  SEG_C6G = 1; }
#define O1_0    {SEG_O1A = 1;  SEG_O1B = 1;  SEG_O1C = 1;  SEG_O1D = 1;  SEG_O1E = 1;  SEG_O1F = 1;  SEG_O1G = 0; }
#define O1_1    {SEG_O1A = 0;  SEG_O1B = 1;  SEG_O1C = 1;  SEG_O1D = 0;  SEG_O1E = 0;  SEG_O1F = 0;  SEG_O1G = 0; }
#define O1_2    {SEG_O1A = 1;  SEG_O1B = 1;  SEG_O1C = 0;  SEG_O1D = 1;  SEG_O1E = 1;  SEG_O1F = 0;  SEG_O1G = 1; }
#define O1_3    {SEG_O1A = 1;  SEG_O1B = 1;  SEG_O1C = 1;  SEG_O1D = 1;  SEG_O1E = 0;  SEG_O1F = 0;  SEG_O1G = 1; }
#define O1_4    {SEG_O1A = 0;  SEG_O1B = 1;  SEG_O1C = 1;  SEG_O1D = 0;  SEG_O1E = 0;  SEG_O1F = 1;  SEG_O1G = 1; }
#define O1_5    {SEG_O1A = 1;  SEG_O1B = 0;  SEG_O1C = 1;  SEG_O1D = 1;  SEG_O1E = 0;  SEG_O1F = 1;  SEG_O1G = 1; }
#define O1_6    {SEG_O1A = 1;  SEG_O1B = 0;  SEG_O1C = 1;  SEG_O1D = 1;  SEG_O1E = 1;  SEG_O1F = 1;  SEG_O1G = 1; }
#define O1_7    {SEG_O1A = 1;  SEG_O1B = 1;  SEG_O1C = 1;  SEG_O1D = 0;  SEG_O1E = 0;  SEG_O1F = 0;  SEG_O1G = 0; }
#define O1_8    {SEG_O1A = 1;  SEG_O1B = 1;  SEG_O1C = 1;  SEG_O1D = 1;  SEG_O1E = 1;  SEG_O1F = 1;  SEG_O1G = 1; }
#define O1_9    {SEG_O1A = 1;  SEG_O1B = 1;  SEG_O1C = 1;  SEG_O1D = 0;  SEG_O1E = 0;  SEG_O1F = 1;  SEG_O1G = 1; }
#define O2_0    {SEG_O2A = 1;  SEG_O2B = 1;  SEG_O2C = 1;  SEG_O2D = 1;  SEG_O2E = 1;  SEG_O2F = 1;  SEG_O2G = 0; }
#define O2_1    {SEG_O2A = 0;  SEG_O2B = 1;  SEG_O2C = 1;  SEG_O2D = 0;  SEG_O2E = 0;  SEG_O2F = 0;  SEG_O2G = 0; }
#define O2_2    {SEG_O2A = 1;  SEG_O2B = 1;  SEG_O2C = 0;  SEG_O2D = 1;  SEG_O2E = 1;  SEG_O2F = 0;  SEG_O2G = 1; }
#define O2_3    {SEG_O2A = 1;  SEG_O2B = 1;  SEG_O2C = 1;  SEG_O2D = 1;  SEG_O2E = 0;  SEG_O2F = 0;  SEG_O2G = 1; }
#define O2_4    {SEG_O2A = 0;  SEG_O2B = 1;  SEG_O2C = 1;  SEG_O2D = 0;  SEG_O2E = 0;  SEG_O2F = 1;  SEG_O2G = 1; }
#define O2_5    {SEG_O2A = 1;  SEG_O2B = 0;  SEG_O2C = 1;  SEG_O2D = 1;  SEG_O2E = 0;  SEG_O2F = 1;  SEG_O2G = 1; }
#define O2_6    {SEG_O2A = 1;  SEG_O2B = 0;  SEG_O2C = 1;  SEG_O2D = 1;  SEG_O2E = 1;  SEG_O2F = 1;  SEG_O2G = 1; }
#define O2_7    {SEG_O2A = 1;  SEG_O2B = 1;  SEG_O2C = 1;  SEG_O2D = 0;  SEG_O2E = 0;  SEG_O2F = 0;  SEG_O2G = 0; }
#define O2_8    {SEG_O2A = 1;  SEG_O2B = 1;  SEG_O2C = 1;  SEG_O2D = 1;  SEG_O2E = 1;  SEG_O2F = 1;  SEG_O2G = 1; }
#define O2_9    {SEG_O2A = 1;  SEG_O2B = 1;  SEG_O2C = 1;  SEG_O2D = 0;  SEG_O2E = 0;  SEG_O2F = 1;  SEG_O2G = 1; }
#define O3_0    {SEG_O3A = 1;  SEG_O3B = 1;  SEG_O3C = 1;  SEG_O3D = 1;  SEG_O3E = 1;  SEG_O3F = 1;  SEG_O3G = 0; }
#define O3_1    {SEG_O3A = 0;  SEG_O3B = 1;  SEG_O3C = 1;  SEG_O3D = 0;  SEG_O3E = 0;  SEG_O3F = 0;  SEG_O3G = 0; }
#define O3_2    {SEG_O3A = 1;  SEG_O3B = 1;  SEG_O3C = 0;  SEG_O3D = 1;  SEG_O3E = 1;  SEG_O3F = 0;  SEG_O3G = 1; }
#define O3_3    {SEG_O3A = 1;  SEG_O3B = 1;  SEG_O3C = 1;  SEG_O3D = 1;  SEG_O3E = 0;  SEG_O3F = 0;  SEG_O3G = 1; }
#define O3_4    {SEG_O3A = 0;  SEG_O3B = 1;  SEG_O3C = 1;  SEG_O3D = 0;  SEG_O3E = 0;  SEG_O3F = 1;  SEG_O3G = 1; }
#define O3_5    {SEG_O3A = 1;  SEG_O3B = 0;  SEG_O3C = 1;  SEG_O3D = 1;  SEG_O3E = 0;  SEG_O3F = 1;  SEG_O3G = 1; }
#define O3_6    {SEG_O3A = 1;  SEG_O3B = 0;  SEG_O3C = 1;  SEG_O3D = 1;  SEG_O3E = 1;  SEG_O3F = 1;  SEG_O3G = 1; }
#define O3_7    {SEG_O3A = 1;  SEG_O3B = 1;  SEG_O3C = 1;  SEG_O3D = 0;  SEG_O3E = 0;  SEG_O3F = 0;  SEG_O3G = 0; }
#define O3_8    {SEG_O3A = 1;  SEG_O3B = 1;  SEG_O3C = 1;  SEG_O3D = 1;  SEG_O3E = 1;  SEG_O3F = 1;  SEG_O3G = 1; }
#define O3_9    {SEG_O3A = 1;  SEG_O3B = 1;  SEG_O3C = 1;  SEG_O3D = 0;  SEG_O3E = 0;  SEG_O3F = 1;  SEG_O3G = 1; }
#define O4_0    {SEG_O4A = 1;  SEG_O4B = 1;  SEG_O4C = 1;  SEG_O4D = 1;  SEG_O4E = 1;  SEG_O4F = 1;  SEG_O4G = 0; }
#define O4_1    {SEG_O4A = 0;  SEG_O4B = 1;  SEG_O4C = 1;  SEG_O4D = 0;  SEG_O4E = 0;  SEG_O4F = 0;  SEG_O4G = 0; }
#define O4_2    {SEG_O4A = 1;  SEG_O4B = 1;  SEG_O4C = 0;  SEG_O4D = 1;  SEG_O4E = 1;  SEG_O4F = 0;  SEG_O4G = 1; }
#define O4_3    {SEG_O4A = 1;  SEG_O4B = 1;  SEG_O4C = 1;  SEG_O4D = 1;  SEG_O4E = 0;  SEG_O4F = 0;  SEG_O4G = 1; }
#define O4_4    {SEG_O4A = 0;  SEG_O4B = 1;  SEG_O4C = 1;  SEG_O4D = 0;  SEG_O4E = 0;  SEG_O4F = 1;  SEG_O4G = 1; }
#define O4_5    {SEG_O4A = 1;  SEG_O4B = 0;  SEG_O4C = 1;  SEG_O4D = 1;  SEG_O4E = 0;  SEG_O4F = 1;  SEG_O4G = 1; }
#define O4_6    {SEG_O4A = 1;  SEG_O4B = 0;  SEG_O4C = 1;  SEG_O4D = 1;  SEG_O4E = 1;  SEG_O4F = 1;  SEG_O4G = 1; }
#define O4_7    {SEG_O4A = 1;  SEG_O4B = 1;  SEG_O4C = 1;  SEG_O4D = 0;  SEG_O4E = 0;  SEG_O4F = 0;  SEG_O4G = 0; }
#define O4_8    {SEG_O4A = 1;  SEG_O4B = 1;  SEG_O4C = 1;  SEG_O4D = 1;  SEG_O4E = 1;  SEG_O4F = 1;  SEG_O4G = 1; }
#define O4_9    {SEG_O4A = 1;  SEG_O4B = 1;  SEG_O4C = 1;  SEG_O4D = 0;  SEG_O4E = 0;  SEG_O4F = 1;  SEG_O4G = 1; }
#define O5_0    {SEG_O5A = 1;  SEG_O5B = 1;  SEG_O5C = 1;  SEG_O5D = 1;  SEG_O5E = 1;  SEG_O5F = 1;  SEG_O5G = 0; }
#define O5_1    {SEG_O5A = 0;  SEG_O5B = 1;  SEG_O5C = 1;  SEG_O5D = 0;  SEG_O5E = 0;  SEG_O5F = 0;  SEG_O5G = 0; }
#define O5_2    {SEG_O5A = 1;  SEG_O5B = 1;  SEG_O5C = 0;  SEG_O5D = 1;  SEG_O5E = 1;  SEG_O5F = 0;  SEG_O5G = 1; }
#define O5_3    {SEG_O5A = 1;  SEG_O5B = 1;  SEG_O5C = 1;  SEG_O5D = 1;  SEG_O5E = 0;  SEG_O5F = 0;  SEG_O5G = 1; }
#define O5_4    {SEG_O5A = 0;  SEG_O5B = 1;  SEG_O5C = 1;  SEG_O5D = 0;  SEG_O5E = 0;  SEG_O5F = 1;  SEG_O5G = 1; }
#define O5_5    {SEG_O5A = 1;  SEG_O5B = 0;  SEG_O5C = 1;  SEG_O5D = 1;  SEG_O5E = 0;  SEG_O5F = 1;  SEG_O5G = 1; }
#define O5_6    {SEG_O5A = 1;  SEG_O5B = 0;  SEG_O5C = 1;  SEG_O5D = 1;  SEG_O5E = 1;  SEG_O5F = 1;  SEG_O5G = 1; }
#define O5_7    {SEG_O5A = 1;  SEG_O5B = 1;  SEG_O5C = 1;  SEG_O5D = 0;  SEG_O5E = 0;  SEG_O5F = 0;  SEG_O5G = 0; }
#define O5_8    {SEG_O5A = 1;  SEG_O5B = 1;  SEG_O5C = 1;  SEG_O5D = 1;  SEG_O5E = 1;  SEG_O5F = 1;  SEG_O5G = 1; }
#define O5_9    {SEG_O5A = 1;  SEG_O5B = 1;  SEG_O5C = 1;  SEG_O5D = 0;  SEG_O5E = 0;  SEG_O5F = 1;  SEG_O5G = 1; }
#define O6_0    {SEG_O6A = 1;  SEG_O6B = 1;  SEG_O6C = 1;  SEG_O6D = 1;  SEG_O6E = 1;  SEG_O6F = 1;  SEG_O6G = 0; }
#define O6_1    {SEG_O6A = 0;  SEG_O6B = 1;  SEG_O6C = 1;  SEG_O6D = 0;  SEG_O6E = 0;  SEG_O6F = 0;  SEG_O6G = 0; }
#define O6_2    {SEG_O6A = 1;  SEG_O6B = 1;  SEG_O6C = 0;  SEG_O6D = 1;  SEG_O6E = 1;  SEG_O6F = 0;  SEG_O6G = 1; }
#define O6_3    {SEG_O6A = 1;  SEG_O6B = 1;  SEG_O6C = 1;  SEG_O6D = 1;  SEG_O6E = 0;  SEG_O6F = 0;  SEG_O6G = 1; }
#define O6_4    {SEG_O6A = 0;  SEG_O6B = 1;  SEG_O6C = 1;  SEG_O6D = 0;  SEG_O6E = 0;  SEG_O6F = 1;  SEG_O6G = 1; }
#define O6_5    {SEG_O6A = 1;  SEG_O6B = 0;  SEG_O6C = 1;  SEG_O6D = 1;  SEG_O6E = 0;  SEG_O6F = 1;  SEG_O6G = 1; }
#define O6_6    {SEG_O6A = 1;  SEG_O6B = 0;  SEG_O6C = 1;  SEG_O6D = 1;  SEG_O6E = 1;  SEG_O6F = 1;  SEG_O6G = 1; }
#define O6_7    {SEG_O6A = 1;  SEG_O6B = 1;  SEG_O6C = 1;  SEG_O6D = 0;  SEG_O6E = 0;  SEG_O6F = 0;  SEG_O6G = 0; }
#define O6_8    {SEG_O6A = 1;  SEG_O6B = 1;  SEG_O6C = 1;  SEG_O6D = 1;  SEG_O6E = 1;  SEG_O6F = 1;  SEG_O6G = 1; }
#define O6_9    {SEG_O6A = 1;  SEG_O6B = 1;  SEG_O6C = 1;  SEG_O6D = 0;  SEG_O6E = 0;  SEG_O6F = 1;  SEG_O6G = 1; }
#define G_0     {SEG_GA = 1;  SEG_GB = 1;  SEG_GC = 1;  SEG_GD = 1;  SEG_GE = 1;  SEG_GF = 1;  SEG_GG = 0; SEG_GH = 0; SEG_GI = 0; SEG_GJ = 0; SEG_GK = 0;}
#define G_1     {SEG_GA = 0;  SEG_GB = 1;  SEG_GC = 1;  SEG_GD = 0;  SEG_GE = 0;  SEG_GF = 0;  SEG_GG = 0; SEG_GH = 0; SEG_GI = 0; SEG_GJ = 0; SEG_GK = 0;}
#define G_2     {SEG_GA = 1;  SEG_GB = 1;  SEG_GC = 0;  SEG_GD = 1;  SEG_GE = 1;  SEG_GF = 0;  SEG_GG = 1; SEG_GH = 0; SEG_GI = 0; SEG_GJ = 0; SEG_GK = 0;}
#define G_3     {SEG_GA = 1;  SEG_GB = 1;  SEG_GC = 1;  SEG_GD = 1;  SEG_GE = 0;  SEG_GF = 0;  SEG_GG = 1; SEG_GH = 0; SEG_GI = 0; SEG_GJ = 0; SEG_GK = 0;}
#define G_4     {SEG_GA = 0;  SEG_GB = 1;  SEG_GC = 1;  SEG_GD = 0;  SEG_GE = 0;  SEG_GF = 1;  SEG_GG = 1; SEG_GH = 0; SEG_GI = 0; SEG_GJ = 0; SEG_GK = 0;}
#define G_5     {SEG_GA = 1;  SEG_GB = 0;  SEG_GC = 1;  SEG_GD = 1;  SEG_GE = 0;  SEG_GF = 1;  SEG_GG = 1; SEG_GH = 0; SEG_GI = 0; SEG_GJ = 0; SEG_GK = 0;}
#define G_6     {SEG_GA = 1;  SEG_GB = 0;  SEG_GC = 1;  SEG_GD = 1;  SEG_GE = 1;  SEG_GF = 1;  SEG_GG = 1; SEG_GH = 0; SEG_GI = 0; SEG_GJ = 0; SEG_GK = 0;}
#define G_7     {SEG_GA = 1;  SEG_GB = 1;  SEG_GC = 1;  SEG_GD = 0;  SEG_GE = 0;  SEG_GF = 0;  SEG_GG = 0; SEG_GH = 0; SEG_GI = 0; SEG_GJ = 0; SEG_GK = 0;}
#define G_8     {SEG_GA = 1;  SEG_GB = 1;  SEG_GC = 1;  SEG_GD = 1;  SEG_GE = 1;  SEG_GF = 1;  SEG_GG = 1; SEG_GH = 0; SEG_GI = 0; SEG_GJ = 0; SEG_GK = 0;}
#define G_9     {SEG_GA = 1;  SEG_GB = 1;  SEG_GC = 1;  SEG_GD = 0;  SEG_GE = 0;  SEG_GF = 1;  SEG_GG = 1; SEG_GH = 0; SEG_GI = 0; SEG_GJ = 0; SEG_GK = 0;}
#define G_P     {SEG_GA = 1;  SEG_GB = 1;  SEG_GC = 0;  SEG_GD = 0;  SEG_GE = 1;  SEG_GF = 1;  SEG_GG = 1; SEG_GH = 0; SEG_GI = 0; SEG_GJ = 0; SEG_GK = 0;}
#define G_R     {SEG_GA = 1;  SEG_GB = 1;  SEG_GC = 0;  SEG_GD = 0;  SEG_GE = 1;  SEG_GF = 1;  SEG_GG = 1; SEG_GH = 0; SEG_GI = 0; SEG_GJ = 1; SEG_GK = 0;}
#define G_N     {SEG_GA = 0;  SEG_GB = 1;  SEG_GC = 1;  SEG_GD = 0;  SEG_GE = 1;  SEG_GF = 1;  SEG_GG = 0; SEG_GH = 1; SEG_GI = 0; SEG_GJ = 1; SEG_GK = 0;}
#define G_D     {SEG_GA = 1;  SEG_GB = 1;  SEG_GC = 1;  SEG_GD = 1;  SEG_GE = 0;  SEG_GF = 0;  SEG_GG = 0; SEG_GH = 0; SEG_GI = 1; SEG_GJ = 0; SEG_GK = 1;}




/******************************************************************************
* Prototypes
********************************************************************************/

/*******************************************************************************
*
* @brief    function prototypes
* @param    none
* @return   none
*
********************************************************************************/   

void LCD_Init(void);
void SetD1(char in);
void SetD2(char in);
void SetD3(char in);
void SetD4(char in);
void SetClk(char h, char m, char s);
void SetOdo(long in);
void SetData(long in, char leadZero);
void SetG(char in);
void setBar(char in, char accumulate);
void setEcoMode(char in);
void setCheckService(char in);
void setGasIndicators(char in);
void setFreescale(char in);
void setOdoMode(void);
void setTripAMode(void);
void setTripBMode(void);
void setTempMode(void);
void setRangeMode(void);
void setSpeedMode(void);
void setETMode(void);
void setFuelEfficiencyMode(void);
void setAMMode(void);
void setPMMode(void);
void set24HMode(void);
void SetClk_Blink(void);


#endif /* LCD_H_ */
