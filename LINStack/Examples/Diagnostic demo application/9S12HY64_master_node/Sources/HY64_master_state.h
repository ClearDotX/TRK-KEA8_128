#ifndef _HY64_master_state
#define _HY64_master_state

#include "lin.h"
#include "mcu_init.h"



/* DEFINITION */
#define REAR_LEFT_DOOR_NAD    0x12
#define FRONT_LEFT_DOOR_NAD   0x11
//const l_u8 FRONT_LEFT_DOOR_NAD = 0x0A;
//const l_u8 REAR_LEFT_DOOR_NAD  = 0x0B;
#define MAX_LENGTH_DIAG_SERVICE 20

#define _SERIAL_NUMBER				0x25675431
#define _DOOR_STATUS					0x00
#define _DTC_STATUS_BYTE			0x0A

#define BYTE_DISP_NUMBER			3
#define BYTE_DISP_ORDER       8
/* Class II (XEP100)*/

/**/
#define SERIAL_NUMBER_READ_SEND	  	0x01
#define SERIAL_NUMBER_READ_RECEIV  	0x02

#define SERIAL_NUMBER_WRITE_SEND	0x03
#define SERIAL_NUMBER_WRITE_RECEIV	0x04

#define IO_CONTROL_READ_SEND		0x05
#define IO_CONTROL_READ_RECEIV		0x06

#define IO_CONTROL_SET_SEND			0x07
#define IO_CONTROL_SET_RECEIV		0x08

#define SESSION_CONTROL_SEND		0x09
#define SESSION_CONTROL_RECEIV    0x0A

#define FAULT_MEMORY_READ_SEND			0x0B
#define FAULT_MEMORY_READ_RECEIV		0x0C

#define FAULT_MEMORY_CLEAR_SEND		0x0D
#define FAULT_MEMORY_CLEAR_RECEIV		0x0E	

#define DIAGNOSTIC_SERVICE_RESET    0x00

/**/
#define NORMALL_STATE				0x00

/*Class II*/
#define SERIAL_NUMBER_READ_SEND_REQ  		 0x20  
#define SERIAL_NUMBER_READ_RESP		 		 0x21

#define SERIAL_NUMBER_WRITE_SEND_REQ 		 0x22
#define SERIAL_NUMBER_WRITE_RESP		 	 0x23
/*Class III*/
#define IO_CONTROL_READ_REQ					 0x30
#define IO_CONTROL_READ_RESP				 0x31

#define IO_CONTROL_SET_REQ					 0x32
#define IO_CONTROL_SET_RESP					 0x33

#define SESSION_CONTROL_REQ					 0x34
#define SESSION_CONTROL_RESP				 0x35

#define FAULT_MEMORY_CLEAR_REQ			 	 0x38
#define FAULT_MEMORY_CLEAR_RESP			 	 0x39

#define FAULT_MEMORY_READ_REQ			 	 0x36
#define FAULT_MEMORY_READ_RESP			 	 0x37

	 
#define DIAG_CLASSII_STATE_MASK  		 	 0x20
#define DIAG_CLASSIII_STATE_MASK		 	 0x30

#define DIAG_REQ_SEND_STATE_MASK     		 0x01
/**/

/* common variable */
extern volatile l_u8 receiv_response_flag;
extern volatile l_u8 state;
extern volatile l_u8 LI0_FrontLeftDoorSignal_dat;
extern volatile l_u8 LI0_RearLeftDoorSignal_dat;
extern volatile l_u8 change_state_flag;
extern volatile unsigned long serial_number;
extern volatile l_u8 io_control_status; /*Led indicator*/
/*---------------------------------------------------------------*/
extern volatile l_u8 slave_resp_dat[MAX_LENGTH_DIAG_SERVICE];
extern volatile l_u16 slave_resp_length;

extern volatile l_u8 master_req_dat[MAX_LENGTH_DIAG_SERVICE];
extern volatile l_u16 master_req_length;

extern volatile l_u8 NAD;

/* Function protype */

/* common Function*/
void delay_ms(l_u16 ms);
void HEX_disp(l_u8 order, l_u8 data);
void byte_seperation(l_u8 data, l_u8* lower_byte, l_u8* upper_byte);
void byte_disp(l_u8 order, l_u8 data);
void state_disp(l_u8 state);
void five_first_byte_array_disp(l_u8 length, l_u8 *dat);
void array_shift(l_u8 length, l_u8 *dat);
void array_disp(l_u8 current_state, l_u16 length, l_u8 *dat);



void normal_state_disp(void);

/*Class II - read serial number*/
void read_serial_number_disp(void);
void read_serial_number_send_req(void);
void read_serial_number_wait_resp(void);
void read_serial_number_wait_resp_disp(void);

/*Class II - write serial number*/
void write_serial_number_wait_resp(void);
void write_serial_number_wait_resp_disp(void);
void write_serial_number_disp(void);
void write_serial_number_send_req(void);

//--------------------------------------------------------------------------------------------------
/* Class III - io control read */
void io_control_read_disp(void);
void io_control_read_send_req(void);
void io_control_read_wait_resp(void);
void io_control_read_wait_resp_disp(void);

/* Class III - io control set */
void io_control_set_disp(void);
void io_control_set_send_req(void);
void io_control_set_wait_resp(void);
void io_control_set_wait_resp_disp(void);

//--------------------------------------------------------------------------------------------------
/* Class III - session control set */
void session_control_disp(void);
void session_control_send_req(void);
void session_control_wait_resp(void);
void session_control_wait_resp_disp(void);

/* Class III - FAULT_MEMORY_CLEAR */
void fault_memory_clear_disp(void);
void fault_memory_clear_send_req(void);
void fault_memory_clear_wait_resp(void);
void fault_memory_clear_wait_resp_disp(void);

/* Class III - FAULT_MEMORY_ */
void fault_memory_read_disp(void);
void fault_memory_read_send_req(void);
void fault_memory_read_wait_resp(void);
void fault_memory_read_wait_resp_disp(void);

/*------------------------------------------------------------------------------------------------------*/

#endif