/****************************************************************************** 
* 
* Freescale Semiconductor Inc. 
* (c) Copyright 2008-2009 Freescale Semiconductor, Inc. 
* ALL RIGHTS RESERVED. 
* 
***************************************************************************//*! 
* 
* @file      HY64_master_state.c 
* 
* @author    FPT Software
*  
* @version   1.0 
*  
* @date      December-9-2010 
*  
* @brief     
* 
******************************************************************************/
#include "HY64_master_state.h"
#include "diagnostic_service_slave.h"
#include "lcddrv.h"  
#include "lin_cfg.h"
#include "lin_lin21tl_api.h" 
#include "mcu_init.h"

#define SECOND_NUM 400
#define DIGIT_OFF_DISP_EN 1
#define POINTER_DISP_EN 1
#define ARR_SHIFT_DIRECTION 1

void delay_ms(l_u16 ms)
{
		volatile l_u16 i,j;
		for(i = ms ; i > 0 ; --i)
		{
				for (j = 1000; j > 0 ; j--)
				{
						;
				}
		}
}

void Compass_on_disp() 
{
	// Compass Defines
	COMP_RING = ON;
	COMP_N	  = ON;
	COMP_S    = ON;
	COMP_E	  = ON;
	COMP_W	  = ON;
	COMP_NE	  = ON;
	COMP_NW	  = ON;
	COMP_SE	  = ON;
	COMP_SW	  = ON;
}

void Compass_off_disp() 
{
	// Compass Defines
	COMP_RING = OFF;
	COMP_N	  = OFF;
	COMP_S    = OFF;
	COMP_E	  = OFF;
	COMP_W	  = OFF;
	COMP_NE	  = OFF;
	COMP_NW	  = OFF;
	COMP_SE	  = OFF;
	COMP_SW	  = OFF;
}

void byte_seperation(l_u8 data, l_u8* lower_byte, l_u8* upper_byte)
{
	*lower_byte = data & 0x0F;
	*upper_byte = (data >> 4) & 0x0F;
}

void byte_disp(l_u8 order, l_u8 data)	 
{
		l_u8 lower_byte, upper_byte;
		
		lower_byte = data & 0x0F;
	  upper_byte = (data >> 4) & 0x0F;	  
	  
		HEX_disp(order, upper_byte);	
		HEX_disp(order + 1, lower_byte);	
}

void state_disp(l_u8 state)
{
		Set_Digit_1(DIGIT_OFF);
		byte_disp(2,state); 
}

void HEX_disp(l_u8 order, l_u8 data)
{
	switch (order)
	{
	  	case 1:
	  			Set_Digit_1(data);
	  			break;
	  	case 2:
	  			Set_Digit_2(data);
	  			break;
	  	case 3:
	  			Set_Digit_3(data);
	  			break;		
			case 4:
	  			Set_Digit_4(data);
	  			break;	  			
			case 5:
	  			Set_Digit_5(data);
	  			break;	  				  			
			case 6:
	  			Set_Digit_6(data);
	  			break;	  				  			
			case 7:
	  			Set_Digit_7(data);
	  			break;	  				  			
	  	case 8:
	  			Set_Digit_8(data);
	  			break;
	  	case 9:
	  			Set_Digit_9(data);
	  			break;
	  	case 10:
	  			Set_Digit_10(data);
	  			break;		
			case 11:
	  			Set_Digit_11(data);
	  			break;	  			
			case 12:
	  			Set_Digit_12(data);
	  			break;	  				  			
	  	case 13:
	  			Set_Digit_13(data);
	  			break;	  				  					
			default:
	  			break;	  				  			
	}		
}

void __byte_disp(l_u8 order, l_u8 *data)	 
{
		l_u8 lower_byte, upper_byte;
	  
		lower_byte = *data & 0x0F;
	    upper_byte = (*data >> 4) & 0x0F;
		if (data == (l_u8*)0) 
		{
			HEX_disp(order, DIGIT_OFF);	
			HEX_disp(order + 1, DIGIT_OFF);	
		}
		else
		{
			HEX_disp(order, upper_byte);	
			HEX_disp(order + 1, lower_byte);	
		} 
}

void __five_first_byte_array_disp(l_u8 length, l_u8 **dat)
{		
		l_u8 i ;
		if (length > BYTE_DISP_NUMBER) length = BYTE_DISP_NUMBER;
		for (i = 0; i < length ; i++)
		{
			  __byte_disp( BYTE_DISP_ORDER +(i<<1), dat[i] );
		}
		i = (i << 1) + BYTE_DISP_ORDER;
		for (i; i <= 13; i++)
				HEX_disp(i, DIGIT_OFF);			
}
/*
void __array_shift(l_u8 length, l_u8 **dat)
{
		l_u8* tmp = *dat;
		l_u8 i;
		for (i = 0; i < length - 1 ; i ++)
				*dat[i] = *dat[i+1];
		*dat[length-1] = *tmp;
}
*/
void __array_shift_right(l_u8 length, l_u8 **dat)
{
		l_u8* tmp = dat[length - 1];
		while (length > 1)
		{	
		   length --;  	  
		   dat[length] = dat[length-1];
		}		
		dat[0] = tmp;
}

void __array_shift_left(l_u8 length, l_u8 **dat)
{
		l_u8* tmp = dat[0];
		l_u8  i;
		for (i = 0; i < length - 1; i++ ) {
		  dat[i] = dat[i+1];
		}
		dat[length - 1] = tmp;
}


#if (POINTER_DISP_EN)
void array_disp(l_u8 current_state, l_u16 length, l_u8 *dat)
{
		l_u8* disp_arr[MAX_LENGTH_DIAG_SERVICE];
		l_u8  disp_arr_length = length + BYTE_DISP_NUMBER ;
		int i;
		
		for (i = 0; i < length; i++)		
				disp_arr[i] = &dat[i];			
/**/
    if (current_state == IO_CONTROL_SET_REQ)
        disp_arr[length-1] = (unsigned char*)&io_control_status;			
/**/				
		for (i = length; i < disp_arr_length; i++)
				disp_arr[i] = (l_u8*)0;
		for (i = 0; i < BYTE_DISP_NUMBER ; i++)
		{
#if (ARR_SHIFT_DIRECTION == 0)
				__array_shift_right(disp_arr_length, disp_arr);
#else
        __array_shift_right(disp_arr_length, disp_arr);
#endif				
		}
				
		while (state == current_state)
		{
		    update_signal();
		 		__five_first_byte_array_disp(disp_arr_length, disp_arr );	
		 		if (disp_arr_length < BYTE_DISP_NUMBER)
		 			{
		 					break;
		 			}
		 		else
		 			{
#if (ARR_SHIFT_DIRECTION == 0)	 			
							__array_shift_right(disp_arr_length,disp_arr);
#else
              __array_shift_left(disp_arr_length,disp_arr);
#endif							
		 					delay_ms(SECOND_NUM);
		 			}
		}				
}
#endif

void normal_state_disp(void)
{		   
/* Set state = NORMALL_STATE */
		 state_disp(NORMALL_STATE);
/*-------------------*/		 	
		 byte_disp(8,0x00);
		 byte_disp(10,0x00);
		 byte_disp(12,0x00);
		 
		 PTR = 0x0F;
/* Set LI0_FrontLeftDoorSignal*/
/* Read LI0_FrontLeftDoorSignal */		 			 
		 LI0_FrontLeftDoorSignal_dat = l_u8_rd(LI0_FrontLeftDoorSignal);    
		 byte_disp(4,LI0_FrontLeftDoorSignal_dat);
		 
/* Set LI0_RearLeftDoorSignal*/
		 LI0_RearLeftDoorSignal_dat = l_u8_rd(LI0_RearLeftDoorSignal);    		      
		 byte_disp(6,LI0_RearLeftDoorSignal_dat);	 
}
void Set_digit_dash_4_to_13(void)
{
     unsigned char i;
		 for (i = 4; i<=13; i++)
		 {
   			  HEX_disp(i, DIGIT_DASH);			/* waiting slave's response.....*/
   	 }		  
}
/* Class II - read serial number disp */

/*------------------------------------------------------------------------------------------------
*														SERIAL NUMBER READ SERVICE
*------------------------------------------------------------------------------------------------*/

void read_serial_number_disp(void)  /*state = 0x20*/	
{ 
		 state_disp(SERIAL_NUMBER_READ_SEND_REQ);
/*---Set service ID --------*/		 
		 master_req_dat[0] = 0x22;
		 master_req_dat[1] = 0x00;
		 master_req_dat[2] = 0x92;
/*---Display service ID --------*/		 		 
		 master_req_length = 0x03;
		 array_disp(SERIAL_NUMBER_READ_SEND_REQ, master_req_length,(l_u8*)master_req_dat);
}

void read_serial_number_send_req(void)
{
		 /* If press SW2 */	
		 receiv_response_flag = SERIAL_NUMBER_READ_SEND;		 
		 diag_read_data_by_identifier(LI0, REAR_LEFT_DOOR_NAD,(l_u8*)(master_req_dat+1));
}

void read_serial_number_wait_resp_disp(void)
{
		 /* Set state = 0x21 */	   		
		 state_disp(SERIAL_NUMBER_READ_RESP);
		 /* Waiting response ... */		
		 Set_digit_dash_4_to_13();
}

void read_serial_number_resp_disp(void)
{
     /* Display state: serial number read response*/		 
		 state_disp(SERIAL_NUMBER_READ_RESP);		 
 		 array_disp(SERIAL_NUMBER_READ_RESP, slave_resp_length,(l_u8*)slave_resp_dat);		 
}

void read_serial_number_wait_resp(void)		/* state = 0x21*/
{
     /* Send request */     
     read_serial_number_send_req();
     /* Waiting response ....*/     
	   if (receiv_response_flag == SERIAL_NUMBER_READ_SEND)
		 {
		 		 read_serial_number_wait_resp_disp();		 		 
		 }
     while ( (receiv_response_flag == SERIAL_NUMBER_READ_SEND) && 
             (state == SERIAL_NUMBER_READ_RESP) )   /* wait until receive slave's response */
     {  
         if(diag_get_flag(LI0, LI0_DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER))
         {
      			diagsrv_read_data_by_identifier();      			
    	   }
     }
     /* Display data response */
     if (receiv_response_flag == SERIAL_NUMBER_READ_RECEIV)
     		read_serial_number_resp_disp();	
}


/*------------------------------------------------------------------------------------------------
*														SERIAL NUMBER WRITE SERVICE
*------------------------------------------------------------------------------------------------*/
void write_serial_number_disp(void) /*state = SERIAL_NUMBER_WRITE_SEND_REQ*/	
{
		 state_disp(SERIAL_NUMBER_WRITE_SEND_REQ);
/*--- Set service ID --------*/		 
		 master_req_dat[0] = 0x2E;
		 master_req_dat[1] = 0x00;
		 master_req_dat[2] = 0x92;
		 
		 master_req_dat[3] = (l_u8)((serial_number & 0xFF000000) >> 24);
		 master_req_dat[4] = (l_u8)((serial_number & 0x00FF0000) >> 16);
		 master_req_dat[5] = (l_u8)((serial_number & 0x0000FF00) >> 8);
		 master_req_dat[6] = (l_u8)((serial_number & 0x000000FF)) ;
/*--- Display service ID --------*/		 		 
		 master_req_length = 0x07;
		 array_disp(SERIAL_NUMBER_WRITE_SEND_REQ, master_req_length,(l_u8*)master_req_dat);
}

void write_serial_number_send_req(void)
{
		 /* If press SW2 */	
		 receiv_response_flag = SERIAL_NUMBER_WRITE_SEND;
		 diag_write_data_by_identifier(LI0, REAR_LEFT_DOOR_NAD, master_req_length - 1, (l_u8 *const)(master_req_dat+1));
}
void write_serial_number_wait_resp_disp(void)
{
		 /* state Display = SERIAL_NUMBER_WRITE_RESP */	   		
		 state_disp(SERIAL_NUMBER_WRITE_RESP);
		 /* Waiting response ... */		
		 Set_digit_dash_4_to_13();
}

void write_serial_number_resp_disp(void)
{
/* Display state: serial number read response*/		 
		 state_disp(SERIAL_NUMBER_WRITE_RESP);		 
 		 array_disp(SERIAL_NUMBER_WRITE_RESP, slave_resp_length,(l_u8*)slave_resp_dat);		 
}

void write_serial_number_wait_resp(void)		/* state = 0x21*/
{  
     /* Send request */     
     write_serial_number_send_req();
     /* Waiting response ....*/     
	   if (receiv_response_flag == SERIAL_NUMBER_WRITE_SEND)
		 {
		 		 write_serial_number_wait_resp_disp();		 		 
		 }
     while ( (receiv_response_flag == SERIAL_NUMBER_WRITE_SEND) && 
             (state == SERIAL_NUMBER_WRITE_RESP) )   /* wait until receive slave's response  */
     {  
         //if(lin_diag_services_flag[DIAGSRV_WRITE_DATA_BY_IDENTIFIER_ORDER])
         if(diag_get_flag(LI0,LI0_DIAGSRV_WRITE_DATA_BY_IDENTIFIER_ORDER))
         {
      			 diagsrv_write_data_by_identifier();      			
    	   }
     }
     /* Display data response */
     if (receiv_response_flag == SERIAL_NUMBER_WRITE_RECEIV)
         write_serial_number_resp_disp();	
}
/*------------------------------------------------------------------------------------------------
*------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------------------
*														IO CONTROL READ SERVICE
*------------------------------------------------------------------------------------------------*/
void io_control_read_disp(void){ /*state = IO_CONTROL_READ_REQ*/	
		 state_disp(IO_CONTROL_READ_REQ);
/*---Set service ID --------*/		 
		 master_req_dat[0] = 0x22;
		 master_req_dat[1] = 0x00;
		 master_req_dat[2] = 0x80;
/*---Display service ID --------*/		 		 
		 master_req_length = 0x03;
		 array_disp(IO_CONTROL_READ_REQ, master_req_length, (l_u8*)master_req_dat);
}

void io_control_read_send_req(void)
{
		 /* If press SW2 */	
		 receiv_response_flag = IO_CONTROL_READ_SEND;		 
		 diag_read_data_by_identifier(LI0, FRONT_LEFT_DOOR_NAD, (l_u8*)(master_req_dat+1));
}
void io_control_read_wait_resp_disp(void)
{
		 /* state Display = SERIAL_NUMBER_WRITE_RESP */	   		
		 state_disp(IO_CONTROL_READ_RESP);
		 /* Waiting response ... */		
		 Set_digit_dash_4_to_13();
}

void io_control_read_resp_disp(void)
{
     /* Display state: */		 
		 state_disp(IO_CONTROL_READ_RESP);		 
 		 array_disp(IO_CONTROL_READ_RESP, slave_resp_length, (l_u8*)slave_resp_dat);		 
 		 /* Display LED indicator: */
     PTR = ~io_control_status;
}

void io_control_read_wait_resp(void)		/* state = 0x21*/
{  
     /* Send request */     
     io_control_read_send_req();
     /* Waiting response ....*/     
	   if (receiv_response_flag == IO_CONTROL_READ_SEND)
		 {
		 		 io_control_read_wait_resp_disp();		 		 
		 }
     while ( (receiv_response_flag == IO_CONTROL_READ_SEND) && 
             (state == IO_CONTROL_READ_RESP) )   /* wait until receive slave's response  */
     {  
    				 //if(lin_diag_services_flag[DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER])
    				 if(diag_get_flag(LI0, LI0_DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER))
    				 {
      			     diagsrv_read_data_by_identifier();
    				 }
     }
     /* Display data response */
     if (receiv_response_flag == IO_CONTROL_READ_RECEIV)
         io_control_read_resp_disp();	
}
/*------------------------------------------------------------------------------------------------
*------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------------------
*														IO CONTROL SET SERVICE
*------------------------------------------------------------------------------------------------*/
void io_control_set_disp(void)   /*state = IO_CONTROL_SET_REQ*/	
{     
		 state_disp(IO_CONTROL_SET_REQ);
/*---Set service ID --------*/		 
		 master_req_dat[0] = 0x2F;
		 master_req_dat[1] = 0x00;
		 master_req_dat[2] = 0x80;
		 master_req_dat[3] = 0x03;
//		 master_req_dat[4] = io_control_status;
/*---Display service ID --------*/		 		 
		 master_req_length = 0x05;
		 array_disp(IO_CONTROL_SET_REQ, (l_u16)master_req_length, (l_u8*)master_req_dat);
		 master_req_dat[4] = io_control_status;
}

void io_control_set_send_req(void)
{
		 /* If press SW2 */	
		 receiv_response_flag = IO_CONTROL_SET_SEND;		 
		 diag_IO_control(LI0, FRONT_LEFT_DOOR_NAD, (l_u16)master_req_length-1, (l_u8* const)(master_req_dat+1));
}
void io_control_set_wait_resp_disp(void)
{
		 /* state Display = SERIAL_NUMBER_WRITE_RESP */	   		
		 state_disp(IO_CONTROL_SET_RESP);
		 /* Waiting response ... */		
		 Set_digit_dash_4_to_13();
}

void io_control_set_resp_disp(void)
{
     /* Display state: */		 
		 state_disp(IO_CONTROL_SET_RESP);		 
 		 array_disp(IO_CONTROL_SET_RESP, slave_resp_length, (l_u8*)slave_resp_dat);		 
}

void io_control_set_wait_resp(void)		/* state = 0x21*/
{  
     /* Send request */     
     io_control_set_send_req();
     /* Waiting response ....*/     
	   if (receiv_response_flag == IO_CONTROL_SET_SEND)
		 {
		 		 io_control_set_wait_resp_disp();		 		 
		 }
     while ( (receiv_response_flag == IO_CONTROL_SET_SEND) && 
             (state == IO_CONTROL_SET_RESP) )   /* wait until receive slave's response  */
     {  
    			 //if(lin_diag_services_flag[DIAGSRV_IO_CONTROL_BY_IDENTIFIER_ORDER])
    			 if(diag_get_flag(LI0, LI0_DIAGSRV_IO_CONTROL_BY_IDENTIFIER_ORDER))
    			 {
      				diagsrv_io_control_by_identifier();
    			 }
     }
     /* Display data response */
     if (receiv_response_flag == IO_CONTROL_SET_RECEIV)
         io_control_set_resp_disp();	
}
/*------------------------------------------------------------------------------------------------
*------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------
*														SESSION CONTROL DEFAULT START SERVICE
*------------------------------------------------------------------------------------------------*/
void session_control_disp(void){ /*state = IO_CONTROL_SET_REQ*/	
		 state_disp(SESSION_CONTROL_REQ);
/*---Set service ID --------*/		 
		 master_req_dat[0] = 0x10;
		 master_req_dat[1] = 0x01;
/*---Display service ID --------*/		 		 
		 master_req_length = 0x02;
		 array_disp(SESSION_CONTROL_REQ, master_req_length, (l_u8*)master_req_dat);
}

void session_control_send_req(void)
{
		 /* If press SW2 */	
		 receiv_response_flag = SESSION_CONTROL_SEND;		 
		 diag_session_control(LI0, FRONT_LEFT_DOOR_NAD, (l_u16)master_req_length-1, (l_u8* const)(master_req_dat+1));
}

void session_control_wait_resp_disp(void)
{
		 /* state Display = SESSION_CONTROL_RESP */	   		
		 state_disp(SESSION_CONTROL_RESP);
		 /* Waiting response ... */		
		 Set_digit_dash_4_to_13();
}

void session_control_resp_disp(void)
{
     /* Display state: */		 
		 state_disp(SESSION_CONTROL_RESP);		 
 		 array_disp(SESSION_CONTROL_RESP, slave_resp_length, (l_u8*)slave_resp_dat);		 
}

void session_control_wait_resp(void)		/* state = 0x21*/
{  
     /* Send request */     
     session_control_send_req();
     /* Waiting response ....*/     
	   if (receiv_response_flag == SESSION_CONTROL_SEND)
		 {
		 		 session_control_wait_resp_disp();		 		 
		 }
     while ( (receiv_response_flag == SESSION_CONTROL_SEND) && 
             (state == SESSION_CONTROL_RESP) )   /* wait until receive slave's response  */
     {  
    					if (diag_get_flag(LI0, LI0_DIAGSRV_SESSION_CONTROL_ORDER))
    					{
      					 	diagsrv_session_control();
    					}
     }
     /* Display data response */
     if (receiv_response_flag == SESSION_CONTROL_RECEIV)
         session_control_resp_disp();	
}
/*------------------------------------------------------------------------------------------------
*------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------
*														FAULT MEMORY CLEAR ALL SERVICE
*------------------------------------------------------------------------------------------------*/
void fault_memory_clear_disp(void)    /*state = FAULT_MEMORY_CLEAR_REQ*/	
{ 
		 state_disp(FAULT_MEMORY_CLEAR_REQ);
/*---Set service ID --------*/		 
		 master_req_dat[0] = 0x14;
		 master_req_dat[1] = 0xff;
		 master_req_dat[2] = 0xff;
		 master_req_dat[3] = 0xff;
/*---Display service ID --------*/		 		 
		 master_req_length = 0x04;
		 array_disp(FAULT_MEMORY_CLEAR_REQ, master_req_length, (l_u8*)master_req_dat);
}

void fault_memory_clear_send_req(void)
{
		 /* If press SW2 */	
		 receiv_response_flag = FAULT_MEMORY_CLEAR_SEND;		 
		 diag_fault_memory_clear(LI0, FRONT_LEFT_DOOR_NAD, master_req_length-1, (l_u8* const)(master_req_dat+1));
}

void fault_memory_clear_wait_resp_disp(void)
{
		 /* state Display = SESSION_CONTROL_RESP */	   		
		 state_disp(FAULT_MEMORY_CLEAR_RESP);
		 /* Waiting response ... */		
		 Set_digit_dash_4_to_13();
}

void fault_memory_clear_resp_disp(void)
{
     /* Display state: */		 
		 state_disp(FAULT_MEMORY_CLEAR_RESP);		 
 		 array_disp(FAULT_MEMORY_CLEAR_RESP, slave_resp_length, (l_u8*)slave_resp_dat);		 
}

void fault_memory_clear_wait_resp(void)		/* state = 0x21*/
{  
     /* Send request */     
     fault_memory_clear_send_req();
     /* Waiting response ....*/     
	   if (receiv_response_flag == FAULT_MEMORY_CLEAR_SEND)
		 {
		 		 fault_memory_clear_wait_resp_disp();		 		 
		 }
     while ( (receiv_response_flag == FAULT_MEMORY_CLEAR_SEND) && 
             (state == FAULT_MEMORY_CLEAR_RESP) )   /* wait until receive slave's response  */
     {  
    			  //if(lin_diag_services_flag[DIAGSRV_FAULT_MEMORY_CLEAR_ORDER])
    			  if(diag_get_flag(LI0, LI0_DIAGSRV_FAULT_MEMORY_CLEAR_ORDER))
    			  {
      				 diagsrv_fault_memory_clear();
    				}
     }
     /* Display data response */
     if (receiv_response_flag == FAULT_MEMORY_CLEAR_RECEIV)
         fault_memory_clear_resp_disp();	
}
/*------------------------------------------------------------------------------------------------
*------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------
*														FAULT MEMORY READ NUMBER SERVICE
*------------------------------------------------------------------------------------------------*/
void fault_memory_read_disp(void)    /*state = FAULT_MEMORY_CLEAR_REQ*/	
{ 
		 state_disp(FAULT_MEMORY_READ_REQ);
/*---Set service ID --------*/		 
		 master_req_dat[0] = 0x19;
		 master_req_dat[1] = 0x01;
		 master_req_dat[2] = _DTC_STATUS_BYTE;
/*---Display service ID --------*/		 		 
		 master_req_length = 0x03;
		 array_disp(FAULT_MEMORY_READ_REQ, master_req_length, (l_u8*)master_req_dat);
}

void fault_memory_read_send_req(void)
{
		 /* If press SW2 */	
		 receiv_response_flag = FAULT_MEMORY_READ_SEND;
		 diag_fault_memory_read(LI0, FRONT_LEFT_DOOR_NAD, master_req_length-1, (l_u8* const)(master_req_dat+1));
}

void fault_memory_read_wait_resp_disp(void)
{
		 /* state Display = SESSION_CONTROL_RESP */	   		
		 state_disp(FAULT_MEMORY_READ_RESP);
		 /* Waiting response ... */		
		 Set_digit_dash_4_to_13();
}

void fault_memory_read_resp_disp(void)
{
     /* Display state: */		 
		 state_disp(FAULT_MEMORY_READ_RESP);		 
 		 array_disp(FAULT_MEMORY_READ_RESP, slave_resp_length, (l_u8*)slave_resp_dat);		 
}

void fault_memory_read_wait_resp(void)		/* state = 0x21*/
{  
     /* Send request */     
     fault_memory_read_send_req();
     /* Waiting response ....*/     
	   if (receiv_response_flag == FAULT_MEMORY_READ_SEND)
		 {
		 		 fault_memory_read_wait_resp_disp();		 		 
		 }
     while ( (receiv_response_flag == FAULT_MEMORY_READ_SEND) && 
             (state == FAULT_MEMORY_READ_RESP) )   /* wait until receive slave's response  */
     {  
    			  //if(lin_diag_services_flag[DIAGSRV_FAULT_MEMORY_READ_ORDER])
    			  if(diag_get_flag(LI0, LI0_DIAGSRV_FAULT_MEMORY_READ_ORDER))
    			  {
      				 diagsrv_fault_memory_read();
    				}
     }
     /* Display data response */
     if (receiv_response_flag == FAULT_MEMORY_READ_RECEIV)
         fault_memory_read_resp_disp();	
}

/**
* @}
*/
