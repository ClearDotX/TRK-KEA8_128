#ifndef _DIAGNOSTIC_SERVICE_SLAVE_H_
#define _DIAGNOSTIC_SERVICE_SLAVE_H_

#include "lin_commontl_api.h"
#include "lin.h"
#include "lin_lin21tl_api.h"
/*------------------------------------------*/
#define SERIAL_NUBER_INT 			0x00
#define IO_CONTROL_STATUS_INT 0x00
#define SESSION_CONTROL_P3		0x01F4
#define SESSION_CONTROL_P3Ex  0x09C4
#define DTCSTATUSBTYE_INT			 0x00
#define DTCFORMATIDENTIFER_INT 0x01
#define COUNTDTC_INT					 0x00
/*------------------------------------------*/
/* diagnostic services class II */
void diagsrv_read_data_by_identifier(void);
void diagsrv_write_data_by_identifier(void);
void diagsrv_session_control(void);
void diagsrv_io_control_by_identifier(void);
void diagsrv_fault_memory_read(void);
void diagsrv_fault_memory_clear(void);
void slave_task(void);
#endif /* End _DIAGNOSTIC_SERVICE_SLAVE_H_ */