/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2009 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup demo_application_for_diagnostic
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      main.c
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Dec-24-2009 
*
* @brief     Demo application for classIII
*
******************************************************************************/

#include "diagnostic_service_slave.h"
#include "derivative.h" /* include peripheral declarations */
#include "MCU_init.h"

/* DEFINITION */
#define MASTER_REQ_LENGTH_MAX   20

extern byte LED_value;
unsigned long serial_number = SERIAL_NUBER_INT; 					/* for read & write serial_number services */
unsigned char io_control_status = IO_CONTROL_STATUS_INT;  /* for read & set io */
unsigned int session_control_P3 = SESSION_CONTROL_P3;     /* for session control service */
unsigned int session_control_P3Ex = SESSION_CONTROL_P3Ex; /* for session control service */

unsigned char DtcStatusByte = DTCSTATUSBTYE_INT			; 				/* for fault memory */
unsigned char DtcFormatIdentifier = DTCFORMATIDENTIFER_INT;   /* for fault memory */
unsigned char CountDtc = COUNTDTC_INT;						  					/* for fault memory */

/**/
typedef void (*PT2FUNCTION_DEF)(void);
#define _DIAG_SERVICES_DEMO_NUM		5
PT2FUNCTION_DEF funcArr[_DIAG_SERVICES_DEMO_NUM] = 
{
	&diagsrv_read_data_by_identifier,
//	&diagsrv_write_data_by_identifier
	&diagsrv_session_control,
	&diagsrv_io_control_by_identifier,
	&diagsrv_fault_memory_read,
	&diagsrv_fault_memory_clear		
};

unsigned char diagServiceFlag[_DIAG_SERVICES_DEMO_NUM] =
{
	 DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER,
//	 DIAGSRV_WRITE_DATA_BY_IDENTIFIER_ORDER
	 DIAGSRV_SESSION_CONTROL_ORDER,
	 DIAGSRV_IO_CONTROL_BY_IDENTIFIER_ORDER,
	 DIAGSRV_FAULT_MEMORY_READ_ORDER,   
	 DIAGSRV_FAULT_MEMORY_CLEAR_ORDER          
};

/**/
volatile l_u8 master_req_dat[MASTER_REQ_LENGTH_MAX];
volatile l_u16 master_req_length;

volatile l_u8 slave_resp_dat[MASTER_REQ_LENGTH_MAX];
volatile l_u16 slave_resp_length;

/* diagnostic services class II */ 
#if ( (_DIAG_CLASS_SUPPORT_ == _DIAG_CLASS_II_) || (_DIAG_CLASS_SUPPORT_ == _DIAG_CLASS_III_) ) 
void diagsrv_read_data_by_identifier(void)
{
  /* Implement code of this service here */    
  /* get data from queue to data */
  ld_receive_message((l_u16*)&master_req_length, (l_u8*)master_req_dat);
	slave_resp_dat[0] = master_req_dat[0] + 0x40;
	slave_resp_dat[1] = master_req_dat[1];
	slave_resp_dat[2] = master_req_dat[2];  
  /* process data */

  if ( (master_req_dat[0] == 0x22) && (master_req_dat[1] == 0x00) && (master_req_dat[2] == 0x92) )
	{ /* Diagnostic service: read serial number*/	
			slave_resp_dat[3] = (l_u8) ((serial_number & 0xFF000000) >> 24);
  		slave_resp_dat[4] = (l_u8) ((serial_number & 0x00FF0000) >> 16);
  		slave_resp_dat[5] = (l_u8) ((serial_number & 0x0000FF00) >> 8);
  		slave_resp_dat[6] = (l_u8) (serial_number &  0x000000FF);
  		slave_resp_length = 0x07; 			
  }

#if (_DIAG_CLASS_SUPPORT_ == _DIAG_CLASS_III_)  
	else if ( (master_req_dat[0] == 0x22) && (master_req_dat[1] == 0x00) && (master_req_dat[2] == 0x80) )
	{
			slave_resp_dat[3] = io_control_status;
			slave_resp_length = 0x04;
	}		   	
#endif /* (_DIAG_CLASS_SUPPORT_ == _DIAG_CLASS_III_) */   	
  /* send a message to master */
  ld_send_message((l_u16)slave_resp_length, (l_u8*)slave_resp_dat);  
  /*clear diagnostic flag */
  //lin_diag_services_flag[DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER] = 0;
  diag_clear_flag(DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER);
}
void diagsrv_write_data_by_identifier(void)
{
  ld_receive_message((l_u16*)&master_req_length, (l_u8*)master_req_dat);  
  /* process data */
  serial_number  =  (unsigned long)master_req_dat[master_req_length - 1];
  serial_number |= ((unsigned long)master_req_dat[master_req_length - 2] << 8 );
  serial_number |= ((unsigned long)master_req_dat[master_req_length - 3] << 16 );
  serial_number |= ((unsigned long)master_req_dat[master_req_length - 4] << 24 );
  
  slave_resp_dat[0] = master_req_dat[0] + 0x40;
  slave_resp_dat[1] = master_req_dat[1];
  slave_resp_dat[2] = master_req_dat[2];
  slave_resp_length = 0x03;
  /* send a message to master */
  ld_send_message((l_u16)slave_resp_length,(l_u8*) slave_resp_dat);  
  /*clear diagnostic flag */
  diag_clear_flag(DIAGSRV_WRITE_DATA_BY_IDENTIFIER_ORDER);
}
#endif /* (_DIAG_CLASS_SUPPORT_ == _DIAG_CLASS_II_) */
#if (_DIAG_CLASS_SUPPORT_ == _DIAG_CLASS_III_)  
void diagsrv_session_control(void)
{	
	ld_receive_message((l_u16*)&master_req_length,(l_u8*)master_req_dat);  
  /* process data */
    slave_resp_dat[0] = master_req_dat[0] + 0x40;
	slave_resp_dat[1] = master_req_dat[1];
	slave_resp_dat[2] = master_req_dat[2];
	slave_resp_dat[3] = (session_control_P3 & 0xFF00) >> 8;
	slave_resp_dat[4] = (session_control_P3 & 0x00FF);
	slave_resp_dat[5] = (session_control_P3Ex & 0xFF00) >> 8;
	slave_resp_dat[6] = (session_control_P3Ex & 0x00FF);
  slave_resp_length = 0x07;  
  /* send a message to master */
  ld_send_message((l_u16)slave_resp_length, (l_u8*)slave_resp_dat);  
  /*clear diagnostic flag */
  diag_clear_flag(DIAGSRV_SESSION_CONTROL_ORDER);
}
void diagsrv_io_control_by_identifier(void)
{	
	/* process recieved data from master request */
	ld_receive_message((l_u16*)&master_req_length, (l_u8*)master_req_dat);  
	io_control_status = master_req_dat[4];
	LED_value = ((byte)~io_control_status) << 4; /*ToanLN*/
  /* Display Led inidcator*/	
  //   PTCD = ( (~io_control_status) << 2);
  /* send response to master */
  slave_resp_dat[0] = master_req_dat[0] + 0x40;
	slave_resp_dat[1] = master_req_dat[1];
	slave_resp_dat[2] = master_req_dat[2];  
	slave_resp_dat[3] = master_req_dat[3];  
	slave_resp_dat[4] = io_control_status;
	slave_resp_length = 0x05;    	
	/* send a message to master */
  ld_send_message((l_u16)slave_resp_length, (l_u8*)slave_resp_dat);  
  /*clear diagnostic flag */
  diag_clear_flag(DIAGSRV_IO_CONTROL_BY_IDENTIFIER_ORDER);
}
void diagsrv_fault_memory_read(void)
{
  ld_receive_message((l_u16*)&master_req_length,(l_u8*)master_req_dat);  
  /* Implement code of this service here */
  slave_resp_dat[0] = master_req_dat[0] + 0x40;
	slave_resp_dat[1] = master_req_dat[1];
	slave_resp_dat[2] = master_req_dat[2];  
	slave_resp_dat[3] = DtcStatusByte;
	slave_resp_dat[4] = DtcFormatIdentifier;
	slave_resp_dat[5] = CountDtc;
	slave_resp_length = 0x06;	
  /* send a message to master */
  ld_send_message((l_u16)slave_resp_length,(l_u8*)slave_resp_dat);  
  /*clear diagnostic flag */
  lin_diag_services_flag[DIAGSRV_FAULT_MEMORY_READ_ORDER] = 0;
}
void diagsrv_fault_memory_clear(void)
{
  ld_receive_message((l_u16*)&master_req_length,(l_u8*)master_req_dat);  
  /* Implement code of this service here */
  slave_resp_dat[0] = master_req_dat[0] + 0x40;
	slave_resp_dat[1] = master_req_dat[1];
	slave_resp_dat[2] = master_req_dat[2];
	slave_resp_length = 0x03;
  /* Implement code of this service here */
  ld_send_message((l_u16)slave_resp_length, (l_u8*)slave_resp_dat);
  /*clear diagnostic flag */
  diag_clear_flag(DIAGSRV_FAULT_MEMORY_CLEAR_ORDER);
  //lin_diag_services_flag[DIAGSRV_FAULT_MEMORY_CLEAR_ORDER] = 0;
}
#endif /* (_DIAG_CLASS_SUPPORT_ == _DIAG_CLASS_III_) */

//extern volatile l_signal_handle slave_signal_handle;
extern volatile l_u8* slave_sig_data;
extern volatile unsigned char sw_flag;


void slave_task()
{
  unsigned char i = 0x00;	
  unsigned char data;

  /* Send signal to master */
  l_u8_wr(LI0_FrontLeftDoorSignal, *slave_sig_data);   /* POT value */
  
  /* Implement demo diagnostic service */
  for (i = 0; i < _DIAG_SERVICES_DEMO_NUM; i++)
  {
    	if (diag_get_flag(diagServiceFlag[i]))
	    {
		    funcArr[i]();			 		
	    }	
  }
}

/**
* @}
*/