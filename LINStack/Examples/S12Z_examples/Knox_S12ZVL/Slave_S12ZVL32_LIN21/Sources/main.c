#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "lin.h"

#define SW2 PTS_PTS0

#define setRegBit(reg, bit)                                     (reg |= reg##_##bit##_##MASK)
#define clrRegBit(reg, bit)                                     (reg &= ~reg##_##bit##_##MASK)
#define getRegBit(reg, bit)                                     (reg & reg##_##bit##_##MASK)
#define setReg(reg, val)                                        (reg = (word)(val))
#define getReg(reg)                                             (reg)
#define setRegBits(reg, mask)                                   (reg |= (word)(mask))
#define getRegBits(reg, mask)                                   (reg & (word)(mask))
#define clrRegBits(reg, mask)                                   (reg &= (word)(~(mask)))
#define setRegBitGroup(reg, bits, val)                          (reg = (word)((reg & ~reg##_##bits##_##MASK) | ((val) << reg##_##bits##_##BITNUM)))
#define getRegBitGroup(reg, bits)                               ((reg & reg##_##bits##_##MASK) >> reg##_##bits##_##BITNUM)
#define setRegMask(reg, maskAnd, maskOr)                        (reg = (word)((getReg(reg) & ~(maskAnd)) | (maskOr)))
#define setRegBitVal(reg, bit, val)                             ((val) == 0 ? (reg &= ~reg##_##bit##_##MASK) : (reg |= reg##_##bit##_##MASK))
#define changeRegBits(reg, mask)                                (reg ^= (mask))
#define changeRegBit(reg, bit)                                  (reg ^= reg##_##bit##_##MASK)

/******************************************************************/
/* Uniform multiplatform peripheral access macros - 16 bit access */
/******************************************************************/
#define setReg16Bit(RegName, BitName)                           (RegName |= RegName##_##BitName##_##MASK)
#define clrReg16Bit(RegName, BitName)                           (RegName &= ~(word)RegName##_##BitName##_##MASK)
#define invertReg16Bit(RegName, BitName)                        (RegName ^= RegName##_##BitName##_##MASK)
#define testReg16Bit(RegName, BitName)                          (RegName & RegName##_##BitName##_##MASK)

/* Whole peripheral register access macros */
#define setReg16(RegName, val)                                  (RegName = (word)(val))
#define getReg16(RegName)                                       (RegName)

/* Bits peripheral register access macros */
#define testReg16Bits(RegName, GetMask)                         (RegName & (GetMask))
#define clrReg16Bits(RegName, ClrMask)                          (RegName &= (word)(~(word)(ClrMask)))
#define setReg16Bits(RegName, SetMask)                          (RegName |= (word)(SetMask))
#define invertReg16Bits(RegName, InvMask)                       (RegName ^= (word)(InvMask))
#define clrSetReg16Bits(RegName, ClrMask, SetMask)              (RegName = (RegName & (~(word)(ClrMask))) | (word)(SetMask))
#define seqClrSetReg16Bits(RegName, BitsMask, BitsVal)          ((RegName &= ~(~(word)(BitsVal) & (word)(BitsMask))),\
                                                                (RegName |= (word)(BitsVal) & (word)(BitsMask)) )
#define seqSetClrReg16Bits(RegName, BitsMask, BitsVal)          ((RegName |= (word)(BitsVal) & (word)(BitsMask)),\
                                                                (RegName &= ~(~(word)(BitsVal) & (word)(BitsMask))) )
#define seqResetSetReg16Bits(RegName, BitsMask, BitsVal)        ((RegName &= ~(word)(BitsMask)),\
                                                                (RegName |= (word)(BitsVal) & (word)(BitsMask)) )
#define clrReg16BitsByOne(RegName, ClrMask, BitsMask)           (RegName &= (word)(ClrMask) & (word)(BitsMask))

/* Bit group peripheral register access macros */
#define testReg16BitGroup(RegName, GroupName)                   (RegName & RegName##_##GroupName##_##MASK)
#define getReg16BitGroupVal(RegName, GroupName)                 ((RegName & RegName##_##GroupName##_##MASK) >> RegName##_##GroupName##_##BITNUM)
#define setReg16BitGroupVal(RegName, GroupName, GroupVal)       (RegName = (RegName & ~(word)RegName##_##GroupName##_##MASK) | (((word)(GroupVal)) << RegName##_##GroupName##_##BITNUM))
#define seqClrSetReg16BitGroupVal(RegName,GroupName,GroupVal)   ((RegName &= ~(~(((word)(GroupVal)) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK)),\
                                                                (RegName |= (((word)(GroupVal)) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK) )
#define seqSetClrReg16BitGroupVal(RegName,GroupName,GroupVal)   ((RegName |= (((word)(GroupVal)) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK),\
                                                                (RegName &= ~(~(((word)(GroupVal)) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK)) )
#define seqResetSetReg16BitGroupVal(RegName,GroupName,GroupVal) ((RegName &= ~(word)RegName##_##GroupName##_##MASK),\
                                                                (RegName |= (((word)(GroupVal)) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK) )

/*****************************************************************/
/* Uniform multiplatform peripheral access macros - 8 bit access */
/*****************************************************************/
#define setReg8Bit(RegName, BitName)                             (RegName |= RegName##_##BitName##_##MASK)
#define clrReg8Bit(RegName, BitName)                             (RegName &= (byte)~(byte)RegName##_##BitName##_##MASK)
#define invertReg8Bit(RegName, BitName)                          (RegName ^= RegName##_##BitName##_##MASK)
#define testReg8Bit(RegName, BitName)                            (RegName & RegName##_##BitName##_##MASK)

/* Whole peripheral register access macros */
#define setReg8(RegName, val)                                    (RegName = (byte)(val))
#define getReg8(RegName)                                         (RegName)

/* Bits peripheral register access macros */
#define testReg8Bits(RegName, GetMask)                           (RegName & (GetMask))
#define clrReg8Bits(RegName, ClrMask)                            (RegName &= (byte)(~(byte)(ClrMask)))
#define setReg8Bits(RegName, SetMask)                            (RegName |= (byte)(SetMask))
#define invertReg8Bits(RegName, InvMask)                         (RegName ^= (byte)(InvMask))
#define clrSetReg8Bits(RegName, ClrMask, SetMask)                (RegName = (RegName & ((byte)(~(byte)(ClrMask)))) | (byte)(SetMask))
#define seqClrSetReg8Bits(RegName, BitsMask, BitsVal)            ((RegName &= (byte)~((byte)~((byte)(BitsVal)) & ((byte)(BitsMask)))),\
                                                                 (RegName |= ((byte)(BitsVal)) & ((byte)(BitsMask))) )
#define seqSetClrReg8Bits(RegName, BitsMask, BitsVal)            ((RegName |= (byte)(BitsVal) & (byte)(BitsMask)),\
                                                                 (RegName &= (byte)~((byte)~((byte)(BitsVal)) & (byte)(BitsMask))) )
#define seqResetSetReg8Bits(RegName, BitsMask, BitsVal)          ((RegName &= (byte)~((byte)(BitsMask))),\
                                                                 (RegName |= (byte)(BitsVal) & (byte)(BitsMask)) )
#define clrReg8BitsByOne(RegName, ClrMask, BitsMask)             (RegName &= (byte)(ClrMask) & (byte)(BitsMask))

/* Bit group peripheral register access macros */
#define testReg8BitGroup(RegName, GroupName)                     (RegName & RegName##_##GroupName##_##MASK)
#define getReg8BitGroupVal(RegName, GroupName)                   ((RegName & RegName##_##GroupName##_##MASK) >> RegName##_##GroupName##_##BITNUM)
#define setReg8BitGroupVal(RegName, GroupName, GroupVal)         (RegName = (RegName & (byte)~(byte)RegName##_##GroupName##_##MASK) | (byte)(((byte)(GroupVal)) << RegName##_##GroupName##_##BITNUM))
#define seqClrSetReg8BitGroupVal(RegName,GroupName,GroupVal)     ((RegName &= (byte)~((byte)~(byte)(((byte)(GroupVal)) << RegName##_##GroupName##_##BITNUM) & (byte)RegName##_##GroupName##_##MASK)),\
                                                                 (RegName |= (byte)(((byte)(GroupVal)) << RegName##_##GroupName##_##BITNUM) & (byte)RegName##_##GroupName##_##MASK) )
#define seqSetClrReg8BitGroupVal(RegName,GroupName,GroupVal)     ((RegName |= (byte)(((byte)(GroupVal)) << RegName##_##GroupName##_##BITNUM) & (byte)RegName##_##GroupName##_##MASK),\
                                                                 (RegName &= (byte)~((byte)~(byte)(((byte)(GroupVal)) << RegName##_##GroupName##_##BITNUM) & (byte)RegName##_##GroupName##_##MASK)) )
#define seqResetSetReg8BitGroupVal(RegName,GroupName,GroupVal)   ((RegName &= (byte)~(byte)RegName##_##GroupName##_##MASK),\
                                                                 (RegName |= (byte)(((byte)(GroupVal)) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK) )

void cpu_init(void) {
    /* ### MC9S12ZVL32_48 "Cpu" init code ... */
    /*  PE initialization code after reset */
    /* IVBR: IVB_ADDR=0x7FFF,??=0 */
    setReg16(IVBR, 0xFFFEU);
    /* ECLKCTL: NECLK=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
    setReg8(ECLKCTL, 0x80U);
    /*  System clock initialization */
    /* CPMUPROT: ??=0,??=0,??=1,??=0,??=0,??=1,??=1,PROT=0 */
    setReg8(CPMUPROT, 0x26U);
    /* Disable protection of clock configuration registers */
    /* CPMUCLKS: PSTP=0 */
    clrReg8Bits(CPMUCLKS, 0x40U);
    /* CPMUCLKS: PLLSEL=1 */
    setReg8Bits(CPMUCLKS, 0x80U);
    /* Enable the PLL to allow write to divider registers */
    /* CPMUPOSTDIV: ??=0,??=0,??=0,POSTDIV4=0,POSTDIV3=0,POSTDIV2=0,POSTDIV1=0,POSTDIV0=1 */
    setReg8(CPMUPOSTDIV, 0x01U);
    /* Set the post divider register */
    /* Whenever changing PLL reference clock (REFCLK) frequency to a higher value
     it is recommended to write CPMUSYNR = 0x00 in order to stay within specified
     maximum frequency of the MCU */
    /* CPMUSYNR: VCOFRQ1=0,VCOFRQ0=0,SYNDIV5=0,SYNDIV4=0,SYNDIV3=0,SYNDIV2=0,SYNDIV1=0,SYNDIV0=0 */
    setReg8(CPMUSYNR, 0x00U);
    /* Set the multiplier register */
    /* CPMUREFDIV: REFFRQ1=0,REFFRQ0=1,??=0,??=0,REFDIV3=0,REFDIV2=0,REFDIV1=0,REFDIV0=0 */
    setReg8(CPMUREFDIV, 0x40U);
    /* Set the divider register */
    /* CPMUOSC2: ??=0,??=0,??=0,??=0,??=0,??=0,OMRE=1,OSCMOD=0 */
    setReg8(CPMUOSC2, 0x02U);
    /* Configure external oscillator options */
    /* CPMUOSC: OSCE=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
    setReg8(CPMUOSC, 0x80U);
    /* Enable the oscillator */
    /* CPMUPLL: ??=0,??=0,FM1=0,FM0=0,??=0,??=0,??=0,??=0 */
    setReg8(CPMUPLL, 0x00U);
    /* Set the PLL frequency modulation */
    /* CPMUSYNR: VCOFRQ1=0,VCOFRQ0=0,SYNDIV5=0,SYNDIV4=0,SYNDIV3=0,SYNDIV2=0,SYNDIV1=1,SYNDIV0=1 */
    setReg8(CPMUSYNR, 0x03U);
    /* Set the multiplier register */
    while (CPMUIFLG_UPOSC == 0U) { /* Wait until the oscillator is qualified by the PLL */
    }
    /* CPMUPROT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,PROT=0 */
    setReg8(CPMUPROT, 0x00U);
    /* Enable protection of clock configuration registers */
    /* CPMUCOP: RSBCK=0,WRTMASK=0 */
    clrReg8Bits(CPMUCOP, 0x60U);
    /* CPMUHTCTL: ??=0,??=0,VSEL=0,??=0,HTE=0,HTDS=0,HTIE=0,HTIF=0 */
    setReg8(CPMUHTCTL, 0x00U);
    /* CPMUVREGCTL: ??=0,??=0,??=0,??=0,??=0,??=0,EXTXON=0,INTXON=1 */
    setReg8(CPMUVREGCTL, 0x01U);
}
#define MOTOR_SELECTION_INCREASE 1
#define MOTOR_SELECTION_DECREASE 2
#define MOTOR_SELECTION_STOP   3

/* Global variables */
l_u8 LIN_counter =0, LED_counter = 0, Temp_counter =0;
l_u8 Motor1_temp;
l_u8 Motor1_Selection;

void test_init(void) {
    /* PIEP: PIEP7=0,PIEP6=0,PIEP5=0,PIEP4=0,PIEP3=0,PIEP2=0,PIEP1=0,PIEP0=0 */
    setReg8(PIEP, 0x00U);
    /* PTP: PTP7=0,PTP6=0,PTP5=0,PTP4=0,PTP3=0,PTP2=0,PTP1=0,PTP0=0 */
    setReg8(PTP, 0x00U);
    /* PPSP: PPSP7=1,PPSP6=1,PPSP5=1,PPSP4=1,PPSP3=1,PPSP2=1,PPSP1=1,PPSP0=1 */
    setReg8(PPSP, 0xFFU);
    /* PERP: PERP7=1,PERP6=1,PERP5=1,PERP4=1,PERP3=1,PERP2=1,PERP1=1,PERP0=1 */
    setReg8(PERP, 0xFFU);
    /* DDRP: DDRP7=1,DDRP6=1,DDRP5=1,DDRP4=1,DDRP3=1,DDRP2=1,DDRP1=1,DDRP0=1 */
    setReg8(DDRP, 0xFFU);
    /* CPMUINT: LOCKIE=0,OSCIE=0 */
    clrReg8Bits(CPMUINT, 0x12U);
    /* CPMULVCTL: LVIE=0 */
    clrReg8Bits(CPMULVCTL, 0x02U);
    /* ECCIE: SBEEIE=0 */
    clrReg8Bits(ECCIE, 0x01U);
    /* ECCDCMD: ECCDRR=0 */
    clrReg8Bits(ECCDCMD, 0x80U);
    /* RDRP: RDRP7=0,RDRP5=0,RDRP3=0,RDRP1=0 */
    clrReg8Bits(RDRP, 0xAAU);
    /* IRQCR: IRQEN=0 */
    clrReg8Bits(IRQCR, 0x40U);
}

void main(void) {
    l_u8 ret;
    l_u8 j;
    l_u16 i;
    l_u8 temp;
    cpu_init();
    test_init();
    EnableInterrupts;
    PTIS_PTIS0 = 1; /* Enable SW2 button */
    DDRS_DDRS0 = 0; 
    
    ret = l_sys_init();
    ret = l_ifc_init(LI0);

    for (;;) {
	    /* Check if temp signal is updated */
      if (l_flg_tst_LI0_Motor1Selection_flag()){
          /* Clear this flag... */
          l_flg_clr_LI0_Motor1Selection_flag();
          /* Store selection data */
          Motor1_Selection = l_u8_rd_LI0_Motor1Selection();
          /* The application will change Motor selection in case 
           the temperature is greater than maximum value to release motor power
           This will be transfered by sporadic frame type in LIN bus */
         l_u8_wr_LI0_Motor1Temp(Motor1_temp); 
         /* Check if power off motor due to high temperature */
         if (Motor1_Selection == MOTOR_SELECTION_STOP) {
         /*---------- add code here to stop motor ------------*/    
        	 Motor1_temp = 25; /* Ambiance temperature */
         }      
      }
    } /* loop forever */
    /* please make sure that you never leave main */

}
