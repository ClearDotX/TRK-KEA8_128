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
* @file      diagnostic_service_slave.h
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
#ifndef _DIAGNOSTIC_SERVICE_SLAVE_H_
#define _DIAGNOSTIC_SERVICE_SLAVE_H_

#include "lin_commontl_api.h"
#include "lin.h"
#include "lin_lin21tl_api.h"
 
void diagsrv_read_data_by_identifier(void);
void diagsrv_write_data_by_identifier(void);
void diagsrv_session_control(void);
void diagsrv_io_control_by_identifier(void);
void diagsrv_fault_memory_read(void);
void diagsrv_fault_memory_clear(void);
//#endif /*End (_DIAG_CLASS_SUPPORT_ == _DIAG_CLASS_III_) */

#endif /* End _DIAGNOSTIC_SERVICE_SLAVE_H_ */
/**
* @}
*/
