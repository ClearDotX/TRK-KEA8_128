/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
***************************************************************************//*!
*
* @file kexx_config.h
*
* @author Freescale
*
* @version 0.0.1
*
* @date Jun 25, 2013
*
* @brief library and board configuration code. 
*
*******************************************************************************
*
* NOTE:
*	printf call may occupy a lot of memory (around 1924 bytes), so please
*	consider your code size before using printf.
******************************************************************************/

#ifndef _KExx_CONFIG_H_
#define _KExx_CONFIG_H_

/******************************************************************************
* Includes
******************************************************************************/
#include <stdint.h>
/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros
******************************************************************************/


//#define     TEST_ON_EVB           /*!< if running on freedom board, this line must be commented */
#define TRIM_IRC                    /*!< trim internal reference clock */
#define SPI0_PINREMAP               /*!< remap SPI0 pins to alternative pins */

/*! define print system log */      
/* NOTE: for RAM version, comment it */
//#define PRINT_SYS_LOG             /*!< this macro prints system log information */

#if     !defined(BOOT_LOADER)
    #define PRINT_SYS_LOG           /*!< this macro prints system log information */
#endif

/* define output bus clock */
//#define OUTPUT_BUSCLK             /*!< this macro allows output of bus clock */
#define ICS_TRIM_VALUE  0x4C        /*!< trim IRC to 39.0625KHz and FLL output=40MHz */

#if defined(TEST_ON_EVB)

    /*! define what clock mode at startup on EVB board
     * if USE_FEE is not defined by commenting out the following line, 
     * then it will use FEI mode which is default mode 
     * after reset  
     */
    //#define USE_FEE                       /*!< use FEE clock mode */
    #define USE_FEE_OSC                     /*!< use FEE clock mode with external active oscillator */
    //#define USE_FEI                       /*!< use FEI clock mode */

    /* define external crystal frequency */
    //#define EXT_CLK_FREQ_KHZ	32          /* in KHz */
    //#define EXT_CLK_FREQ_KHZ	4000        /* in KHz */
    #define EXT_CLK_FREQ_KHZ	8000        /* in KHz */
    //#define EXT_CLK_FREQ_KHZ	10000       /* in KHz */

    //#define CRYST_HIGH_GAIN
    //#define XOSC_STOP_ENABLE

    /* define SCI port # to be used */
    #define TERM_PORT   UART0               /*!< UART0 is used on KEA8 EVB board */

#else
    /*! define what clock mode at startup on freedom board
     * if USE_FEE is not defined by commenting out the following line, 
     * then it will use FEI mode which is default mode 
     * after reset.  
     */
    #define USE_FEE                         /*!< use FEE clock mode */
    //#define USE_FEE_OSC                   /*!< use FEE clock mode with external active oscillator */
    //#define USE_FEI                       /*!< use FEI clock mode */

    /*! define external crystal frequency. */
    //#define EXT_CLK_FREQ_KHZ	32          /* in KHz */
    //#define EXT_CLK_FREQ_KHZ	4000        /* in KHz */
    //#define EXT_CLK_FREQ_KHZ	8000        /* in KHz */
    #define EXT_CLK_FREQ_KHZ	10000       /* in KHz */

    /*! define UART port # to be used */
    #define TERM_PORT   UART0               /*!< UART0 is used on TRK-KEA8 board */

#endif

    /* define BUS clock in HZ */
    #if	defined(USE_FEI)
        #define  BUS_CLK_HZ		20000000L
    #elif  (EXT_CLK_FREQ_KHZ == 20000)
        #define  BUS_CLK_HZ		20000000L
    #elif  (EXT_CLK_FREQ_KHZ == 10000)
        #define  BUS_CLK_HZ		20000000L
    #elif  (EXT_CLK_FREQ_KHZ == 8000)
        #define  BUS_CLK_HZ		16000000L
    #elif  (EXT_CLK_FREQ_KHZ == 4000)
        #define  BUS_CLK_HZ		16000000L
    #elif  (EXT_CLK_FREQ_KHZ == 32)
        #define  BUS_CLK_HZ		16777216L
    #else   
        #define  BUS_CLK_HZ		20000000L
    #endif

    /*! define UART baud rate */
    #define UART_PRINT_BITRATE              115200      /*! UART bit rate */

/*! USER LED definitions */
/*! LED maps 
 * LED0  <----> PTC0
 * LED1  <----> PTC1
 * LED2  <----> PTC2
 * LED3  <----> PTC3 
 */
#define LED0_Init()				GPIOA->PDDR |= (1<<16)    /*! RED Light */
#define LED0_Toggle()		    GPIOA->PTOR = (1<<16)
#define LED0_On()		        GPIOA->PSOR = (1<<16)
#define LED0_Off()		        GPIOA->PCOR = (1<<16)

#define LED1_Init()				GPIOA->PDDR |= (1<<17)    /*! Green */
#define LED1_Toggle()		    GPIOA->PTOR = (1<<17)
#define LED1_On()		        GPIOA->PSOR = (1<<17)
#define LED1_Off()		        GPIOA->PCOR = (1<<17)

#define LED2_Init()				GPIOA->PDDR |= (1<<18)  /*! Blue */
#define LED2_Toggle()		    GPIOA->PTOR = (1<<18)
#define LED2_On()		        GPIOA->PSOR = (1<<18)
#define LED2_Off()		        GPIOA->PCOR = (1<<18)

#define LED3_Init()				GPIOA->PDDR |= (1<<19)  /*! Blue */
#define LED3_Toggle()		    GPIOA->PTOR = (1<<19)
#define LED3_On()		        GPIOA->PSOR = (1<<19)
#define LED3_Off()		        GPIOA->PCOR = (1<<19)

/******************************************************************************
* Types
******************************************************************************/


/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/

#endif /* _KExx_CONFIG_H_ */
