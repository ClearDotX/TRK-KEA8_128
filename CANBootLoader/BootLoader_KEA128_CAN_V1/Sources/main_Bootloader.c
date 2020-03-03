
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
* @file BootLooder_KEA128_CAN_V1.c
*
* @author Freescale Auto FAE
*
* @version 1
*
* @date Sept. 25, 2014
*
* @brief KEA128 CAN Bootloader 
*
*******************************************************************************/
#include "common.h"
#include "ics.h"
#include "rtc.h"
#include "sim.h"
#include "mscan.h"
#include "mscan_api.h"
#include "sysinit.h"
/******************************************************************************
* Constants and macros
******************************************************************************/
//Bootloader protocol
#define FLASH_SECTOR_SIZE			512							  /*!< FTMRH sector size*/

#define  SPASS       0
#define  SERR        1
#define  SFileStart  2
#define  SFileEnd    3

#define  DOWN_LINK             0xFF  
#define  DOWN_LINE_END         0xFE
#define  DOWN_FILE_END         0xFD

#define  UP_READY              0xC3
#define  UP_BUSY               0xC2
#define  UP_PRGEND             0xC1
#define  UP_ERR                0x00  

#define  _STA_NOT_LINKED       0x00  
#define  _STA_LINKED           0x01
#define  _STA_PRGEND           0x02 

#define NODE_ID1			   0x60
#define NODE_ID2			   0x64

/* define MACRO for filter,here define a dual filter to receive 
   extend and standard frame from ID(NODE_ID2&NODE_ID3) */
#define CAN_IDAR0			NODE_ID2<<21
#define CAN_IDMR0			0x1|(uint32_t)0x18<<16 /* received all standard and extend frame from ID(NODE_ID2) */
//receive all data
#define CAN_IDMR0			0xffffffff 

/******************************************************************************
* Global variables
******************************************************************************/
uint8_t _New_CANRx_Data;
uint32_t uNewAppSize = 0, uCurrSize, uDoneSize = 0;
uint8_t Sline[128];
uint8_t STATE;
uint8_t pSln=0; 
uint8_t  u8flashProgramDataBuff[64];
uint32_t sectorNumber=0;

/******************************************************************************
* Local types
******************************************************************************/
typedef struct 
{
    uint8_t dtlen;         /*!< Set  Identifier Acceptance Mode */
    uint32_t addr;			/*!< 4 byte align  */
    uint32_t data[20];			/*!< MSCAN Identifier Acceptance Register n of First Bank */
}SRecord_t;
//SRecord_t TASK = {0x13,0x4000,{0x00300020,0x31090000,0xC9080000,0xC9080000,}};
//SRecord_t TASK = {0x17,0x4000,{0x00300020,0x31090000,0xC9080000,0xC9080000,0xC9080000,}};
SRecord_t srcd;

/******************************************************************************
* Local function prototypes
******************************************************************************/
/******************************************************************************
* The function work for changing S19 
******************************************************************************/
uint8_t SRcdCvt(uint8_t * line, SRecord_t *srcd_t) 
{   
	uint8_t  stype,adrlen,slength,sdata,sdtlen,oddflag=0;
    uint8_t  checksum = 0;
    uint16_t  i;
    uint8_t  *sbuffer;
    
    if(*line!='S') {
        srcd_t->dtlen=0;      
		    return SERR;
    }
		
    line++;
    stype = *line - '0';	

		if(stype == 0) {
        srcd_t->dtlen=0;
        return SFileStart;
		}
		else if(stype>6) {
        srcd_t->dtlen=0;
        return SFileEnd;
		}
		else {
			  adrlen=stype+1;  //adrlen is the number of bytes of addr. 16bit@2B, 24bit@3B, 32bit@4B

			  line++;
        slength=hex2value(line);   //the bytes number of addr. data & checksum 

        sdtlen=slength-adrlen-1;   //data length in bytes
        if(sdtlen&0x01) {          //odd number of bytes
            oddflag=1;             //the last byte will be trancated and processed later
        }
        
        srcd_t->dtlen = (uint8_t)(slength-adrlen-1);  //data len in byte, 
                                                      
        checksum+=slength;

        line+=2;
      
			  for(srcd_t->addr=0,i=0; i<adrlen; i++,line=line+2) {
			      sdata=hex2value(line);
				    srcd_t->addr = (srcd_t->addr<<8) + sdata;
				    checksum+=sdata;
			  }
        
		    sbuffer=(uint8_t *)&(srcd_t->data[0]);

			  for(i=0; i<srcd_t->dtlen; i++) {
			      sdata=hex2value(line);
				    line+=2;
				    *((uint8_t*)(sbuffer+i))=sdata;
				    checksum+=sdata;
				    u8flashProgramDataBuff[i]=sdata;
		    }
		}
		
// line point to last byte (which has not been processed) now, the SRecord checksum is immediately after the last byte
    if(oddflag) {                   
        sdata = hex2value(line);
        srcd_t->data[srcd_t->dtlen++]=(((uint16_t)sdata)<<8)|0x00FF;  //e.g. 0x8a -> 0x8aff
		    checksum+=sdata;
        line+=2;  
    }

		if ( checksum+hex2value(line) == 0xFF ) 		
		    return SPASS;
		else
		    return SERR;
}
/* By one byte*/
int hex2value(uint8_t *p)
{   uint8_t k,i;

    k=*p;
    p++;
    i=*p;
    p++;

    if(k>='0' && k<='9')
        k=k-'0';
    else
        k=k-'A'+10;
    
    if(i>='0' && i<='9')
        i=i-'0';
    else
        i=i-'A'+10;
    
    return k*16+i;
}
/******************************************************************************
* Delay time 
******************************************************************************/
void Dlyms(int tick) {          
    int i,j,k=0;
    
    for (i=0;i<tick;i++) {
        for (j=0;j<300;j++) {
            k++;
        }
    }
}
/******************************************************************************
* send NewAppData to buffer, and get the current code size
******************************************************************************/
uint32_t GetNewAppData(uint8_t *pDes)
{
	uint32_t *p = (uint32_t *)pDes;
	uint32_t i, u32Data;
	for (i=0; i<uNewAppSize/4; i++)
		{
			*p++  = srcd.data[i];
		}
}

/******************************************************************************
* protect bootloader section from 0 to 3FFF.
******************************************************************************/
void Flash_bootloader_protect(void)
{
	//Flash Protection Operation Enable
	FTMRE->FPROT |= FTMRE_FPROT_FPOPEN_MASK;
	//Flash Protection Higher Address Range Disable
	FTMRE->FPROT |= FTMRE_FPROT_FPHDIS_MASK;
	//Flash Protection Lower Address Range Disable
	FTMRE->FPROT &= ~FTMRE_FPROT_FPLDIS_MASK;
	//Flash Protection Lower Address Size, from 0 to 0x3FFF
	FTMRE->FPROT |= FTMRE_FPROT_FPLS_MASK;
}


/******************************************************************************
* Local variables
******************************************************************************/


/******************************************************************************
* Local functions
******************************************************************************/
//int main (void);

typedef void(*JumpToPtr)(void);

/******************************************************************************
* Global functions
******************************************************************************/
int main (void)
{
    MSCAN_ConfigType sMSCANConfig = {0};
    ItemInfoType     sCANTxItemInfo;
    MSCAN_FrameType  sRxFrameInfo;
    uint8_t i;

    /*flash part*/
    uint16_t retError=0;
    uint32_t *pNewAppEntry = 0x4004;
    JumpToPtr	pJumpTo;
    
    /* Perform processor initialization */
	sysinit();

    LED0_Init();        
    LED1_Init();        
    LED2_Init();  
    LED3_Init();
    LED0_Off();
    LED1_Off();
    LED2_Off();
    LED3_Off();

    MSCAN_GlobeVaribleInit(MSCAN);
    
    SIM->PINSEL1 |= SIM_PINSEL1_MSCANPS_MASK;   //select MSCAN pin out
    //Initialize the MSCAN information
    sMSCANConfig.sBaudRateSetting.SJW = BAUD_RATE_SJW;
    sMSCANConfig.sBaudRateSetting.BRP = BAUD_RATE_BRP;
    sMSCANConfig.sBaudRateSetting.SAMP = BAUD_RATE_SAMP;//0
	sMSCANConfig.sBaudRateSetting.TSEG1= BAUD_RATE_TSEG1;
	sMSCANConfig.sBaudRateSetting.TSEG2= BAUD_RATE_TSEG2;
	sMSCANConfig.u32IDAR0 = (CAN_IDAR0);
	sMSCANConfig.u32IDMR0 = (CAN_IDMR0);
	sMSCANConfig.u8IDARMode = ID_ACCEPT_MODE_TWO32;
	CAN_Init(MSCAN,&sMSCANConfig);

	//Initialize the Tx information
	sCANTxItemInfo.bIsExtOrStand = 0;
	sCANTxItemInfo.bIsRemoteFrame = 0;
	sCANTxItemInfo.ID_Type.ID = NODE_ID1;
	sCANTxItemInfo.u32DataLength = 1;
	sCANTxItemInfo.u8BPR = 0x80;
	
	STATE = _STA_NOT_LINKED;   //Initialise the state indicator
	Flash_bootloader_protect();
	
	for(i=0; i<255; i++) {   // wait about 500ms for Bootload link request from host
		CAN_ReadOneFramefromBufferQueue(&sRxFrameInfo);
		if((_New_CANRx_Data!=0)&&(sRxFrameInfo.DSR[0]==DOWN_LINK)) {
		            _New_CANRx_Data = 0;
		            STATE = _STA_LINKED;
		break;
		}
		else {
		     	Dlyms(2);
		    }
	}
	if(STATE == _STA_NOT_LINKED){
    	  //disable MSCAN
		   CAN_DeInit(MSCAN); 
		   NVIC_DisableIRQ(MSCAN_RX_IRQn); 
		   NVIC_DisableIRQ(MSCAN_TX_IRQn);
		  //Jump to app
		   pJumpTo = *pNewAppEntry;
		   pJumpTo();
		   while(1)
		   {
		    	  i++;
		   }
		  }
		
    while(1)
    {
    	_New_CANRx_Data = CAN_ReadOneFramefromBufferQueue(&sRxFrameInfo);
    	
        while(_New_CANRx_Data)
        {
        	_New_CANRx_Data = 0;     	      
        switch (sRxFrameInfo.DSR[0])
        {
        case DOWN_LINK:
        	sCANTxItemInfo.u8DataBuff[0]=UP_READY;
        	CAN_TransmitItemByInt(MSCAN,&sCANTxItemInfo,&sCAN_TxBuff);
        	break;
        	
        case DOWN_LINE_END:        	      	
        	sCANTxItemInfo.u8DataBuff[0]=UP_BUSY;
        	CAN_TransmitItemByInt(MSCAN,&sCANTxItemInfo,&sCAN_TxBuff);
        	
        	//write sline to Flash
        	SRcdCvt(&Sline[0], &srcd);
//        	SrcdAlign4W(&srcd);
//        	SrcdProg(&srcd);
        	
        	//Init Flash
        	retError |= FLASH_Init(20000000);
        	uNewAppSize = srcd.dtlen; //  16 byte
        	if (uNewAppSize)
        	{
        		if(srcd.addr/FLASH_SECTOR_SIZE != sectorNumber)
        		{
        		retError |= FLASH_EraseSector((srcd.addr/FLASH_SECTOR_SIZE)*FLASH_SECTOR_SIZE);	
        		retError |= FLASH_EraseVerifySection((srcd.addr/FLASH_SECTOR_SIZE)*FLASH_SECTOR_SIZE, 128);//512/4
        		sectorNumber = srcd.addr/FLASH_SECTOR_SIZE;
        		}
        		else
        		{
        		}
        		GetNewAppData(u8flashProgramDataBuff);
        		retError |= FLASH_Program(srcd.addr,&u8flashProgramDataBuff[0],uNewAppSize);
        	}
        	
        	if (retError)
        		LED3_On();
        	else
        		LED2_Toggle();
        	pSln = 0;
        	sCANTxItemInfo.u8DataBuff[0]=UP_READY;
        	CAN_TransmitItemByInt(MSCAN,&sCANTxItemInfo,&sCAN_TxBuff);
        	break;
        	
        case DOWN_FILE_END:
        	sCANTxItemInfo.u8DataBuff[0]=UP_PRGEND;
        	CAN_TransmitItemByInt(MSCAN,&sCANTxItemInfo,&sCAN_TxBuff);
        	STATE=_STA_PRGEND;
        	while(MSCAN->CANTFLG!= 0x7);
        break;
        	
        default:                // Srecord data received
        	//store RxFrame into Sline
        	for (i=0; i< sRxFrameInfo.DLR; i++) 
        	{
        		Sline[pSln++]=sRxFrameInfo.DSR[i];
        	}
        	sCANTxItemInfo.u8DataBuff[0]=UP_READY;
        	CAN_TransmitItemByInt(MSCAN,&sCANTxItemInfo,&sCAN_TxBuff);
        	break; 
        }
        
        if (STATE==_STA_PRGEND)
        {
        	//disable MSCAN
        	CAN_DeInit(MSCAN);
        	NVIC_DisableIRQ(MSCAN_RX_IRQn); 
        	NVIC_DisableIRQ(MSCAN_TX_IRQn); 
        	LED2_Off();
        	LED3_Off();
        	//Jump to app
        	pJumpTo = *pNewAppEntry;
        	pJumpTo();
        	while(1)
        	{
        		i++;
        	}
        }
      }           
    } 
}

