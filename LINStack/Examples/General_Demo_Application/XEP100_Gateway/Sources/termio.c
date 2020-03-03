/*****************************************************
  Demo files: Terminal port definition
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

/************************************************************************
   This example shows how to access a virtual on chip IO.
   Calls for terminal output is done via on chip SCI.
**************************************************************************/

#include <hidef.h>
#include <termio.h>

#ifdef __ELF_OBJECT_FILE_FORMAT__
  #define HIWAVE  1  /* only HI-WAVE can handle ELF/Dwarf object files */
#elif defined(__H8_500__)
  #define HIWAVE  0  /* H8/500 simulator not available in HI-WAVE yet */
#elif defined(__MWERKS__) && !defined(__HIWARE__)
  #define HIWAVE  0  /* LT not applicable for CW */
#else
  #define HIWAVE  1  /* set to one for HI-WAVE, to zero for HI-CROSS Simulators/Debuggers */
#endif

#if defined(__HC16__) && (defined(__SMALL__) || defined(__MEDIUM__))
  /* NOTE: For the HC16 CPU, this module must be compiled with command line
           option "-Cp0" telling the compiler that the data page will be page 0,
           thus enabling it to generate efficient access code for the on-chip
           I/O. */
  #pragma OPTION ADD "-Cp0"
#endif

/* if the testterm.wnd terminal emulation is used. Currently only the HC12 supports
   the on-chip terminal emulation (terminal.wnd) with HI-WAVE */
#define TEST_TERM   ((HIWAVE && (!defined(__HC12__)) && (!defined(__XGATE__))  && (!defined(__ST7__)) && (!defined(__XA__))) || defined(__HC11__))

#if !(defined(__MWERKS__) && !defined(__HIWARE__)) /* LT not applicable for CW */
typedef volatile struct {
  #if TEST_TERM
    unsigned char BAUD;
    unsigned char SCCR1;
    unsigned char SCCR2;
    unsigned char SCSR;
    unsigned char SCDR;
  #elif defined(__HC12__) || defined(__XGATE__)
    unsigned char SCxBDH;
    unsigned char SCxBDL;
    unsigned char SCxCR1;
    unsigned char SCxCR2;
    unsigned char SCxSR1;
    unsigned char SCxSR2;
    unsigned char SCxDRH;
    unsigned char SCxDRL;
  #elif (defined(__HC16__) || defined(__M68K__))
    unsigned int SCCR0;
    unsigned int SCCR1;
    unsigned int SCSR;
    unsigned int SCDR;
  #elif defined(__H8_500__)  /* H8/532 serial communication unit */
    unsigned char SMR;    /* Serial Mode Register   */
    unsigned char BRR;    /* Bit Rate Register      */
    unsigned char SCR;    /* Serial Control Register*/
    unsigned char TxBuf;  /* Transmit Data Register */
    unsigned char SSR;    /* Serial Status Register */    
    unsigned char RxBuf;  /* Receive Data Register  */
  #elif defined(__XA__)  
    unsigned char S0CON;  
    unsigned char S0STAT; 
    unsigned char _filler[62];
    unsigned char S0BUF;
  #elif defined(__ST7__)
    unsigned char SCISR; 
    unsigned char SCIDR; 
    unsigned char SCIBRR;
    unsigned char SCICR1;
    unsigned char SCICR2;  
  #else
    #error "unknown architecture"
  #endif
} SCIStruct;
#endif /* #if !(defined(__MWERKS__) && !defined(__HIWARE__)) */

#if defined(__HCS12__) || defined(_HCS12) || defined(__XGATE__)
  #define SCI_ADDR 0x0330
#elif defined(__XA__)
  #define SCI_ADDR 0x420  
#elif defined(__HC12__)
  #define SCI_ADDR 0x00c0
#elif defined(__ST7__)
  #define SCI_ADDR 0x0050
#else
  #if HIWAVE
    /* testterm.wnd */
    #define SCI_ADDR 0x200
  #else
    #if defined(__HC11__)
      #define SCI_ADDR 0x102B
    #elif defined(__HC16__)
      #define SCI_ADDR 0xFFC08
    #elif defined(__M68K__)
      #define SCI_ADDR 0xFFFC08
    #elif defined(__H8_500__)
      #define SCI_ADDR 0xFFD8
    #endif
  #endif
  #endif

#if 1 || __STDC__  /* ANSI does not allow the '@' */
  #if defined(__HC05__) || defined(__HC08__) || defined(__ST7__) || defined(__ST19X__)
    #define  SCI (*((volatile SCIStruct* __far)(SCI_ADDR)))
  #elif defined(__RS08__)
    #define  SCI (*((volatile SCIStruct* __paged)(CONVERT_TO_PAGED(SCI_ADDR))))
  #else
    #define  SCI (*((volatile SCIStruct*)(SCI_ADDR))) 
  #endif
#else  /* use the language extension '@': easier debugging! */
  #ifdef __XA__
    #pragma DATA_SEG DIRECT sfr
  #endif
  SCIStruct SCI @SCI_ADDR;
  #ifdef __XA__
    #pragma DATA_SEG DEFAULT
  #endif  
#endif

char TERMIO_GetChar(void) {
  /* receives character from the terminal channel */
  #if TEST_TERM
    while (!(SCI.SCSR & 0x20)){}; /* wait for input */
    /* NOTE: when using simulator you may want to open the 'TestTerm' component */
    return SCI.SCDR; 
  #elif defined(__HC12__) || defined(__XGATE__)
    while (!(SCI.SCxSR1 & 0x20)){}; /* wait for input */
    /* NOTE: when using simulator you may want to open the 'Terminal' component */
    return SCI.SCxDRL;
  #elif defined(__ST7__)
    while ((SCI.SCISR & 0x20) == 0){}; /* wait for input */
    /* NOTE: when using simulator you may want to open the 'Terminal' component */
    return SCI.SCIDR;
  #elif (defined(__HC16__) || defined(__M68K__))
    while (!(SCI.SCSR & 0x40)){}; /* wait for input */
    return SCI.SCDR;
  #elif defined(__H8_500__)
    char ch;
  
    while (!(SCI.SSR & 0x40)) {}; /* wait for receive data register full */
    ch = SCI.RxBuf;
    SCI.SSR &= 0xBF;  /* clear RDRF bit */
    return ch;
  #elif defined(__XA__)
    while (!(SCI.S0CON & 0x01)){}; /* wait for input */
    SCI.S0CON &= 0xFE;
    return SCI.S0BUF;     
  #elif defined(__MWERKS__) && !defined(__HIWARE__) /* LT not applicable for CW */
  #else
    #error "unknown architecture"
  #endif
}

void TERMIO_PutChar(char ch) {
  /* sends a character to the terminal channel */
  #if TEST_TERM
    while (!(SCI.SCSR & 0x80)) {};    /* wait for output buffer empty */
    SCI.SCDR = ch;
  #elif defined(__HC12__) || defined(__XGATE__)
    while (!(SCI.SCxSR1 & 0x80)) {};  /* wait for output buffer empty */
    SCI.SCxDRL = ch;
  #elif defined(__ST7__)
    while ((SCI.SCISR & 0x80) == 0) {};  /* wait for output buffer empty */
    SCI.SCIDR = ch;
  #elif (defined(__HC16__) || defined(__M68K__))
    while (!(SCI.SCSR & 0x100)) {};    /* wait for output buffer empty */ 
    SCI.SCDR = ch;
  #elif defined(__H8_500__)  
    while (!(SCI.SSR & 0x80)) {}; /* wait for transmit data register empty */
    SCI.TxBuf = ch;
    SCI.SSR &= 0x7F;  /* clear TDRE bit */
  #elif defined(__XA__)  
    while (!(SCI.S0CON & 0x02)) {};  /* wait for output buffer empty */
    SCI.S0CON &= 0xFD;     
    SCI.S0BUF = ch;     
  #elif defined(__MWERKS__) && !defined(__HIWARE__)  /* LT not applicable for CW */
  #else
    #error "unknown architecture"
  #endif
}

void TERMIO_Init(void) {
  /* initializes the communication channel */ 
  #if TEST_TERM
    SCI.BAUD  = 0x30;     /* baud rate 9600 at 8 MHz */
    SCI.SCCR2 = 0x0C;     /* 8 bit, TE and RE set */
    SCI.SCSR |= 0x80;     /* output buffer empty */
  #elif defined(__HC12__) || defined(__XGATE__)
    #if 0
      SCI.SCxBDL  =   52;   /* baud rate 9600 at 8 MHz */
    #else   
      SCI.SCxBDL  =   1;    /* for the simulator we use this small divisor to speed up the output. On hardware please use the real value. */
    #endif   
    SCI.SCxCR2 = 0x0C;    /* 8 bit, TE and RE set */   
  #elif defined(__ST7__)
    SCI.SCIBRR= 0b11001001; /* Set Baudrate */
    SCI.SCICR2= 0b00001100; /* TE: Transmitter Enabled + RE: Receiver Enabled */
  #elif (defined(__HC16__) || defined(__M68K__))
    SCI.SCCR0 = 55;       /**** Select baud rate 9600 */
    SCI.SCCR1 = 0x000C;   /**** 8 bit, TE and RE set */
  #elif defined(__H8_500__)
    SCI.SMR = 8;    /* 00001000: 8 bits per character, no parity, 2 stop bit, access to buffer and IER */
    SCI.BRR = 32;   /* Baud rate 9600 */
    SCI.SCR = 0x30; /* 00110000: disable Tx and Rx interrupt */
  #elif defined(__XA__)
    SCI.S0CON  = 0x12; /* UART0 mode 0 (shift register): Baud rate = osc / 16 ; reception enabled */
    SCI.S0STAT = 0x00; /* NB: XA SFRs IO simulation simulates only this mode. */
  #elif defined(__MWERKS__) && !defined(__HIWARE__)  /* LT not applicable for CW */
  #else
    #error "unknown architecture"
  #endif
}


