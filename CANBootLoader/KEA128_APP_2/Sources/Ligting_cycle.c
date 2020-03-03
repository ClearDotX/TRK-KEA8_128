
/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2014 Freescale Semiconductor, Inc.
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
* @file Lighting_cycle.c
*
* @author Freescale Auto FAE
*
* @version 1
*
* @date sept. 25, 2014
*
* @brief app without Interrupt 
*
*******************************************************************************/

#include "common.h"
#include "ics.h"
#include "rtc.h"
#include "gpio.h"
#include "sysinit.h"
#include "start.h"

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Constants and macros
******************************************************************************/

/******************************************************************************
* Local types
******************************************************************************/

/******************************************************************************
* Local function prototypes
******************************************************************************/

/******************************************************************************
* Local variables
******************************************************************************/

/******************************************************************************
* Local functions
******************************************************************************/
int main (void);
void Dlyms(int tick);
/******************************************************************************
* Global functions
******************************************************************************/

/********************************************************************/
int main (void)
{
    /* Perform processor initialization */
    sysinit();
    cpu_identify();

    LED0_Init();
    LED1_Init();
    LED2_Init();
    LED3_Init();
    LED0_On();
    LED1_On();
    LED2_On();
    LED3_On();
    
    while(1){
    	LED0_Toggle();
    	Dlyms(1000);
    	LED1_Toggle();
    	Dlyms(1000);
    	LED2_Toggle();
    	Dlyms(1000);
    	LED3_Toggle();
    	Dlyms(1000);
    }
}

/*****************************************************************************//*!
*
* @brief callback routine of RTC driver which does what you want to do at 
*        every RTC period.
*        
* @param  none
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/

void Dlyms(int tick) {          
    int i,j,k=0;
    
    for (i=0;i<tick;i++) {
        for (j=0;j<300;j++) {
            k++;
        }
    }
}
/********************************************************************/
