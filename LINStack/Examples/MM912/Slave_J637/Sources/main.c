#include <hidef.h>              /* common defines and macros */
#include "derivative.h"         /* derivative-specific definitions */
#include "mm912j637.h"
#include "lin.h"
#include "lin_lld_sci.h"
  
#if _TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_
#include "lin_lin21tl_api.h"
#endif

/* Setup internal oscciclator */
#define VCOFRQ 0x40           /* 00xx.xxxx (0x00) if 32MHz <= fVCO <= 48MHz             */
                              /* 01xx.xxxx (0x40) if 48MHz <  fVCO <= 64MHz  (default)  */
                              /* 10xx.xxxx (0x80) reserved                              */
                              /* 11xx.xxxx (0xC0) reserved                              */
                                                                                  
#define SYNDIV 0x1F           /* fVCO = 2 x fREF x (SYNDIV + 1)                   */
                              /* fREF is automatically trimmed to 1MHz            */
                              /* xx01.1111 (0x1F) default results in fVCO = 64MHz */
      
#define POSTDIV 0x00          /* fPLL = fVCO / (POSTDIV + 1) if PLL is locked                         */
                              /* fPLL = fVCO / 4 if PLL is not locked                                 */
                              /* xxx0.0011 (0x03) default results in fPLL = 16MHz (with default fVCO) */
                              /* fPLL = fCORE                                                         */
                              /* fBUS = fPLL / 2 (Default 8MHz)                                       */
                              
/* Setup slew rate */ 
#define SRS 0       /* 19.2kBit */
// #define SRS 1    /* 9.6kBit  */
// #define SRS 2    /* 100kBit  */
// #define SRS 3    /* 19.2kBit */

#define LIN_EN 4    /* Enable LIN                                         */
#define LVSD1 8     /* low voltage operation (not compliant to SAE J2602) */

#define ON  0
#define OFF 1

#define LED1  PORTA_PA6
#define LED2  PORTA_PA7

#define SW1   PORTA_PA4
#define SW2   PORTA_PA5

void D2Dinit(char clkdiv){
  D2DCTL1  = 0x8F;                  /* D2DIE=1; TIMOUT[3:0] = 15 (max timeout) */
  D2DCTL0  = 0xE0 | (clkdiv&0x03);  /* D2D Enable, 8Bit, Stop in Wait, D2DCLK=BUS */
  D2DSTAT0 = 0x80;                  /* Clear D2D Errors */
}

void EntryPoint(void)
{
  /* ### MC9S12P128_80 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* DIRECT: DP15=0,DP14=0,DP13=0,DP12=0,DP11=0,DP10=0,DP9=0,DP8=0 */
  DIRECT=0;                   
  /* IVBR: IVB_ADDR=255 */
  // IVBR=255;                   
                          
  /* CPMUINT: RTIE=0,LOCKIE=0,OSCIE=0 */          
  CPMUINT = 0;             
  /* CPMULVCTL: LVIE=0 */                         
  CPMULVCTL_LVIE = 0;            
  /* CPMUCOP: WCOP=0,RSBCK=0,WRTMASK=0,??=0,??=0,CR2=0,CR1=0,CR0=0 */
  CPMUCOP= 0;                  
}

void CRGinit(void){
  /* CPMUPROT: ??=0,??=0,??=1,??=0,??=0,??=1,??=1,PROT=0 */
  CPMUPROT = 38;               /* Disable protection of clock configuration registers */ 
  /* CPMUCLKS: PSTP=0 */
  CPMUCLKS_PSTP = 0;            
  /* CPMUCLKS: PLLSEL=1 */
  CPMUCLKS_PLLSEL = 1;          /* Enable the PLL to allow write to divider registers */ 

  CPMUSYNR = VCOFRQ | SYNDIV;   /* Set CPMUSYNR          fVCO = 64MHz */
  
  CPMUPOSTDIV = POSTDIV&0x1F;   /* Set CPMUPOSTDIV       fPLL = 64MHz   / fBUS = 32MHz */

  CPMUPLL = 0;                  /* Enable protection of clock configuration registers */ 
  while (!CPMUFLG_LOCK);        /* Wait for PLL Lock to set. */
  
  /* CPMUPROT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,PROT=0 */
  CPMUPROT = 0;                 /* Enable protection of clock configuration registers */ 
}

void mcuInit(void){
  EntryPoint();
  CRGinit();                    /* Clock Generator Init fCORE = 64MHz, fBUS = 32MHz */
  D2Dinit(0);                   /* D2D Init, D2DCLK = BUSCLK = 32MHz                */

  if (PCR_CTL&0x0003){          /* Check if Wake Up */
    /* PCR_CTL = 0x4340;   // Goto Normal Mode (OPM=00) */
    PCR_CTL = 0x0300;         /* Goto Normal Mode (OPM=00) */
    while (!(PCR_SRH&0x01));  /* Wait for Clock Domain Change */
    PCR_SR  = 0xFFFF;         /* Clear PCR_SR */
    //pcrsr1 = pcrsr2;
  }
  else{                       /* Else "POR" no wait needed.             */
    //PCR_CTL = 0x4340;       /* Goto Normal Mode (OPM=00), enable UVI  */
    PCR_CTL = 0x0300;         /* Goto Normal Mode (OPM=00)              */
    PCR_SR  = 0xFFFF;         /* Clear PCR_SR                           */
  }
   
  WD_CTL = 0x0700;              /* Disable Analog Die Watchdog   */
  
  INT_MSK = 0xFF3F;             /* Disable all interrupt mask */
  _INT_MSK.Bits.CH3M = 0;       /* Enable interrupt mask for Timer channel 3 */
  _INT_MSK.Bits.RXM = 0;        /* Enable SCI RX interrupt mask */
  _INT_MSK.Bits.ERRM = 0;       /* Enable SCI Error interrupt mask */
    
}

void periphInit(void){
    EnableInterrupts;      /* Enable MCU IRQ */
    GPIO_CTL = 0x0;
}

void Init_LIN_Slave(void){  
  LIN_CTL = 0xF00 | LVSD1 | LIN_EN | SRS ;   /* 19.2kBaud   + enable LIN module + LVSD */
  LIN_TX = 1 ;                               /* connection to SCI for TX               */
  LIN_RX = 1 ;                               /* connection to SCI for RX               */
  
  /* PA[6,7]: ouput, PA[0:5]: input */
  DDRA |= 0xC0;
  DDRA &= ~0x38;
  
  PORTA &= ~0xC0;
    
  LIN_SRH = 0xFF;             /* Clear Flags */
  _PCR_WUE.Bits.WULIN = 1;    /* LIN Wakeup Enable */
}

void main(void) {
  /* put your own code here */
  l_u16 i,j;
  l_u8 ret = 0;
  
  mcuInit(); 
  Init_LIN_Slave();
  ret = l_sys_init();
  ret = l_ifc_init(LI0); 
  periphInit();
  
  #if _TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_
  ld_init();
  #endif  
 
  for(;;) {
    if (SLEEP_MODE == lin_lld_get_state()){
        LED1 = ON;
    }else{
        LED1 = OFF;
    } 
    
    /* Specify whether Driver is idle */
    if (IDLE == lin_lld_get_state()){
        LED2 = ON;
    }else{
        LED2 = OFF;
    }
    
    /* Event trigger frame - only one updated */
    if(SW1) {
      l_u8_wr(LI0_Motor1ErrorValue, 34);
    } 

    /* Test wake-up */
    if(SW2) {
      for(i = 0; i < 60000; i++)
        for (j = 0; j < 20; j++);
      l_ifc_wake_up(LI0);
      for(i = 0; i < 50000; i++)
        for (j = 0; j < 20; j++);
      l_ifc_wake_up(LI0);
      for(i = 0; i < 50000; i++)  // diagnostics class 1       
      /* for(i = 0; i < 30000; i++) */  // diagnostic class 2 and 3 
        for (j = 0; j < 20; j++);
      l_ifc_wake_up(LI0);
     }

    #if _TL_FRAME_SUPPORT_ == _TL_MULTI_FRAME_
    if(diag_get_flag(DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER)){
      l_u16 req_len = 0;
      l_u8 req_data[10];
      diag_clear_flag(DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER);
      /* process data */
      ld_receive_message(&req_len, req_data);
      req_data[0] += 0x40;
      /* send response */
      ld_send_message(10, req_data);
    }
    #endif    
  } /* loop forever */
  /* please make sure that you never leave main */
}
