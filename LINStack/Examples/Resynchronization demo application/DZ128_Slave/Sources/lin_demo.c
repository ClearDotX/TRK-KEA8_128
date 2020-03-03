#include "lin_demo.h"

void cpu_init(void) { 
  /* Init bus frequency as 16Mhz */
  
  /* Clears COP Watchdog timeout*/
  SOPT1 = 0x00;
  SOPT2 = 0x00;  
  
  /* SPMSC1: LVWF=0,LVWACK=0,LVWIE=0,LVDRE=1,LVDSE=1,LVDE=1,??=0,BGBE=0 */
  SPMSC1 = 0x1C;                
  /* SPMSC2: ??=0,??=0,LVDV=0,LVWV=0,PPDF=0,PPDACK=0,??=0,PPDC=0 */
  SPMSC2 = 0x00;                
  /*  System clock initialization */
  MCGTRM = *(unsigned char*)0xFFAF;    /* Initialize MCGTRM register from a non volatile memory */
  MCGSC = *(unsigned char*)0xFFAE;     /* Initialize MCGSC register from a non volatile memory */
  /* MCGC2: BDIV=0,RANGE=0,HGO=0,LP=0,EREFS=0,ERCLKEN=0,EREFSTEN=0 */
  MCGC2 = 0x00;                /* Set MCGC2 register */ 
  /* MCGC1: CLKS=0,RDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  MCGC1= 0x06;                /* Set MCGC1 register */ 
  /* MCGC3: LOLIE=0,PLLS=0,CME=0,DIV32=0,VDIV=1 */
  MCGC3= 0x01;                /* Set MCGC3 register */ 
  /* MCGT: ??=0,??=0,DMX32=0,??=0,??=0,??=0,??=0,DRST_DRS=1 */
  MCGT= 0x01;                 /* Set MCGT register */ 
  PTED = 0x10;
  PTEDD = 0x10;   
}

void __cpu_init(void) { 
  /* Clears COP Watchdog timeout*/
  SOPT1 = 0x00;  
  
  /* Selects FEE MCG mode (IREFS=0, CLKS=00, RDIV=11) */
  MCGC1 = 0x38;
  /* BDIV=01 LP=0 and selects external high frequency crystal clock */ 		                
  MCGC2 = 0x76;
  /* PLLS=0  */
  MCGC3 = 0x00;
  
  if (*(unsigned char*far)0xFFAF != 0xFF) { /* Test if the device trim value is stored on the specified address */
    MCGTRM = *(unsigned char*far)0xFFAF; /* Initialize MCGTRM register from a non volatile memory */
    MCGSC = *(unsigned char*far)0xFFAE; /* Initialize MCGSC register from a non volatile memory */
  }
  /* Waits until the initialization cycle of the external crystal clock is completed */
  while(!(MCGSC&0x02)) ;
  
  /* Attention!!!: Bus frequence = 8MHz */
      
  /* Sets TJA1020 LIN transceiver in normal mode operation (NSLP HIGH) */
  /* PTE4 -> NSLP */
  PTED = 0x10;
  PTEDD = 0x10;   
}

void init_demo()
{
 /* Configue for LED */
  PTDDD = 0xFF;  
}

void adc_init()
{
  /* select channel 1 */
  ADCCFG = 0;
  APCTL1 = 0x03;
  ADCSC2 = 0x10;
  ADCSC1 = 0x21;
}





