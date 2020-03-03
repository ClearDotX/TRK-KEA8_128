#include "sci_v5.h"
#include <hidef.h>

/**
* @var static tSCI *pSCI
*/
static tSCI          *__pSCI = (tSCI*)SCI0_ADDR;

static tSCI          *pSCI = (tSCI*)SCI0_ADDR;



void SCI_init(l_u16 baudrate){
  word tmp;   
  tmp = (l_u16)(8000000/baudrate/16);
  SCIBD = tmp; 
  // __pSCI->scibdh.byte	= (l_u8)(tmp>>8);
  //  __pSCI->scibdl.byte	= (l_u8)tmp&0xff;	  
}


void __SCI_init(l_u16 baudrate){
  l_u16 tmp;
  
  /* Initialize SCI */
  /* Set baud rate */
  pSCI->scisr2.byte = 0x00;
  tmp = (l_u16)(MCU_BUS_FREQ/baudrate/16); 
  pSCI->scibdh.byte	= (l_u8)(tmp>>8);
  pSCI->scibdl.byte	= tmp&0xff;
	
  /*Disable SCI in wait mode and enable bit count after stop bit */
  pSCI->scicr1.byte = (SCICR1_ILT_MASK | SCICR1_SCISWAI_MASK);
  /* Enable use of 13bit breaks and SCI frame for LIN */
  pSCI->scisr2.byte  = (SCISR2_AMAP_MASK | SCISR2_BRK13_MASK);
  /* Enable mismatch error detection */
  pSCI->sciasr1.byte = SCIASR1_BERRIF_MASK;
  /* Enable bit error interrupt and break detect flags */
  pSCI->sciacr1.byte = (SCIACR1_BERRIE_MASK | SCIACR1_BKDIE_MASK);
  /* Enable break detect circuit and timing bit error detection at 9th time stick */ 
  pSCI->sciacr2.byte = (SCIACR2_BERRM0_MASK | SCIACR2_BKDFE_MASK);
  /* Enable tranceiver interrupt */
  pSCI->scicr2.byte  = (SCICR2_TE_MASK | SCICR2_RE_MASK | SCICR2_RIE_MASK);    

}