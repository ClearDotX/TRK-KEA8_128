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
* @file      diagnostic_service_slave.c
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Dec-24-2009
*
* @brief     diagnostic functions for master node
*
******************************************************************************/
/*diagnostic service for master - HY64*/

#include "diagnostic_service_slave.h"
#include "HY64_master_state.h"
#include "lcddrv.h"

/**/

/* diagnostic services class II */

void diagsrv_read_data_by_identifier(void)
{
  /* Implement code of this service here */
   /* get all data from queue */
  ld_receive_message(LI0, (l_u16*)&slave_resp_length, (l_u8*)&NAD, (l_u8*)slave_resp_dat);

  if ( (slave_resp_dat[0] == 0x62) && (slave_resp_dat[1] == 0x00) && (slave_resp_dat[2] == 0x92) )
  { /* Diagnostic service: read serial number*/
	    receiv_response_flag = SERIAL_NUMBER_READ_RECEIV;
		    serial_number  = (unsigned long)slave_resp_dat[3] << 24;
        serial_number |= (unsigned long)slave_resp_dat[4] << 16;
        serial_number |= (unsigned long)slave_resp_dat[5] << 8;
        serial_number |= (unsigned long)slave_resp_dat[6] ;
  }
  else if ( (slave_resp_dat[0] == 0x62) && (slave_resp_dat[1] == 0x00) && (slave_resp_dat[2] == 0x80) )
  { /* Diagnostic service: io_control_read*/
	    io_control_status = slave_resp_dat[3];
	    receiv_response_flag = IO_CONTROL_READ_RECEIV;
  }
  //}
  /*clear diagnostic flag */
  //lin_diag_services_flag[DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER] = 0;
  diag_clear_flag(LI0,LI0_DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER);
}

void diagsrv_write_data_by_identifier(void)
{
  /* Implement code of this service here */
  /* get all data from queue */
  ld_receive_message(LI0, (l_u16*)&slave_resp_length, (l_u8*)&NAD, (l_u8*)slave_resp_dat);
  receiv_response_flag = SERIAL_NUMBER_WRITE_RECEIV;
  /*clear diagnostic flag */
  //lin_diag_services_flag[DIAGSRV_WRITE_DATA_BY_IDENTIFIER_ORDER] = 0;
  diag_clear_flag(LI0,LI0_DIAGSRV_WRITE_DATA_BY_IDENTIFIER_ORDER);
}


void diagsrv_session_control(void)
{
  /* Implement code of this service here */
  ld_receive_message(LI0, (l_u16*)&slave_resp_length, (l_u8*)&NAD, (l_u8*)slave_resp_dat);
  receiv_response_flag = SESSION_CONTROL_RECEIV;
  /*clear diagnostic flag */
  //lin_diag_services_flag[DIAGSRV_SESSION_CONTROL_ORDER] = 0;
  diag_clear_flag(LI0, LI0_DIAGSRV_SESSION_CONTROL_ORDER);
}
void diagsrv_io_control_by_identifier(void)
{
  /* Implement code of this service here */
  ld_receive_message(LI0, (l_u16*)&slave_resp_length, (l_u8*)&NAD, (l_u8*)slave_resp_dat);
  receiv_response_flag = IO_CONTROL_SET_RECEIV;
  /*clear diagnostic flag */
  //lin_diag_services_flag[DIAGSRV_IO_CONTROL_BY_IDENTIFIER_ORDER] = 0;
  diag_clear_flag(LI0, LI0_DIAGSRV_IO_CONTROL_BY_IDENTIFIER_ORDER);
}
void diagsrv_fault_memory_read(void)
{
  /* Implement code of this service here */
  ld_receive_message(LI0, (l_u16*)&slave_resp_length, (l_u8*)&NAD, (l_u8*)slave_resp_dat);
  receiv_response_flag = FAULT_MEMORY_READ_RECEIV;
  /*clear diagnostic flag */
  //lin_diag_services_flag[DIAGSRV_FAULT_MEMORY_READ_ORDER] = 0;
  diag_clear_flag(LI0, LI0_DIAGSRV_FAULT_MEMORY_READ_ORDER);
}
void diagsrv_fault_memory_clear(void)
{
  /* Implement code of this service here */
  ld_receive_message(LI0, (l_u16*)&slave_resp_length, (l_u8*)&NAD, (l_u8*)slave_resp_dat);
  receiv_response_flag = FAULT_MEMORY_CLEAR_RECEIV;
  /*clear diagnostic flag */
  //lin_diag_services_flag[DIAGSRV_FAULT_MEMORY_CLEAR_ORDER] = 0;
  diag_clear_flag(LI0, LI0_DIAGSRV_FAULT_MEMORY_CLEAR_ORDER);
}

/**
* @}
*/
