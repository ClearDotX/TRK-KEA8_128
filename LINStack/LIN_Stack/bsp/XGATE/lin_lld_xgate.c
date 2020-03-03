/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup XGATE_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      bsp/XGATE/lin_lld_xgate.c
*
* @author    FPT Software
*
* @brief     XGATE low level functions
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20090408     v1.0    First version
 *
 *****************************************************************************/

#include "lin_lld_xgate.h"
#include "xlin_sci.h"
#include "lin_hw_cfg.h"
#include "lin_common_proto.h"

#pragma MESSAGE DISABLE C4800 /* Disable warning message with ID C4800 */
/***** GLOBLE VARIABLES *****/


#if LIN_MODE == _SLAVE_MODE_
/***** Data shared between S12X and XGATE *****/
#pragma DATA_SEG SHARED_DATA /* Define a specific segment to store the data */
/**
* @var xlin_interrupt lin_interrupt
* lin interrupt
*/
volatile xlin_interrupt lin_interrupt;
/**
* @var xlin_request lin_request
* lin request
*/
volatile xlin_request lin_request;
/**
* @var l_u8 lin_channel
* lin channel
*/
volatile  l_u8 lin_channel;


/***** EXTERN GLOBLE VAR *****/

/**
* @var tSCI *pSCI
* SCI
*/
volatile tSCI          *pSCI = (tSCI*)SCI_ADDR;

/**
* @var l_u8 ifc
* lin interface
*/
volatile l_u8          ifc = 0xFF;
/**
* @var l_u8 state
* lin state
*/
volatile l_u8          state = UNINIT;
/**
* @var lin_status l_status
* lin status
*/
volatile lin_status    l_status;
/**
* @var l_u8 cnt_byte
* lin count byte
*/
volatile l_u8          cnt_byte = 0;
/**
* @var l_u8 *ptr
* l_u8 pointer
*/
volatile l_u8          *ptr = 0;
/**
* @var l_u8 current_id
* lin current id
*/
volatile l_u8          current_id = 0x00;
/**
* @var l_u8 *response_buffer
* lin response buffer pointer
*/
l_u8          *response_buffer = 0;
/**
* @var l_u8 pid
* lin product id
*/
volatile l_u8          pid = 0x80;
/**
* @var l_u16 tbit
* lin tbit
*/
volatile l_u16         tbit = 0;
/**
* @var l_u16 frame_timeout_cnt
* lin time out counter
*/
volatile l_u16         frame_timeout_cnt = 0;
/**
* @var l_u16 res_frame_timeout_cnt
* lin response frame timeout counter
*/
volatile l_u16         res_frame_timeout_cnt = 0;
/**
* @var l_u16 idle_timeout_cnt
* lin idle time out counter
*/
volatile l_u16         idle_timeout_cnt = 0;
/**
* @var l_u8 byte_rec
* lin byte_rec
*/
volatile l_u8 byte_rec = 0;

extern l_u8 lin_lld_response_buffer[10];
extern const lin_hardware_name lin_virtual_ifc;

#pragma DATA_SEG DEFAULT /* Return to default data segment */

void lin_lld_setup_xgate
(
)
{
    /* initialize the XGATE vector block and
     * set the XGVBR register to its start address
     */
    XGVBR = (unsigned int)(void*__far)(XGATE_VectorTable - XGATE_VECTOR_OFFSET);
#if _SCI0_ == 1
    /* switch SCIn interrupt to XGATE */
    ROUTE_INTERRUPT(SCI0_VEC, 0x81); /* RQST = 1 and PRIO = 1 */
#endif /* End (_SCI0_ == 1) */

#if _SCI1_ == 1
    ROUTE_INTERRUPT(SCI1_VEC, 0x81); /* RQST = 1 and PRIO = 1 */
#endif /* End (_SCI0_ == 1) */

#if _SCI2_ == 1
    ROUTE_INTERRUPT(SCI2_VEC, 0x81); /* RQST = 1 and PRIO = 1 */
#endif /* End (_SCI0_ == 1) */

#if _SCI3_ == 1
    ROUTE_INTERRUPT(SCI3_VEC, 0x81); /* RQST = 1 and PRIO = 1 */
#endif /* End (_SCI0_ == 1) */

#if _SCI4_ == 1
    ROUTE_INTERRUPT(SCI4_VEC, 0x81); /* RQST = 1 and PRIO = 1 */
#endif /* End (_SCI0_ == 1) */

#if _SCI5_ == 1
    ROUTE_INTERRUPT(SCI5_VEC, 0x81); /* RQST = 1 and PRIO = 1 */
#endif /* End (_SCI0_ == 1) */

    /* switch PIT0 interrupt to XGATE */
    ROUTE_INTERRUPT(PIT0_VEC, 0x81); /* RQST = 1 and PRIO = 1 */

    /* switch software trigger 0 interrupt to XGATE */
    ROUTE_INTERRUPT(SOFTWARETRIGGER0_VEC, 0x82); /* RQST = 1 and PRIO = 1 */

    /* enable XGATE mode and interrupts */
    XGMCTL = 0xFBC1; /* XGE | XGFRZ | XGIE */

    XGSWT = 0x0101;
}

void lin_lld_xgate_init
(
    /* [IN] LIN interface name */
    l_ifc_handle iii
)
{

    l_u16 tmp;
    /* Set interface number */
    lin_request.iii = iii;

    /* Initialize xlin_interrupt */
    lin_interrupt.ifc = (l_u8)iii;
    /* Assign semaphore id */
    lin_interrupt.semaphore_id = (l_u8)iii;



    /* Config */
    ifc = (l_u8)iii;
    //response_buffer = lin_lld_response_buffer;
    /* Set SCI is Master or Slave */
    tbit = (l_u16)(1000000/LIN_BAUD_RATE);

    /* Initialize SCI */
    /* Set baud rate */
    pSCI->scisr2.byte = 0x00;
    tmp = MCU_BUS_FREQ/LIN_BAUD_RATE/16;
    pSCI->scibdh.byte = (l_u8)(tmp >> 8);
    pSCI->scibdl.byte   = tmp&0xff;

    /* Disable SCI in wait mode and enable bit count after stop bit */
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


    /* Request go to IDLE to Xgate */
    lin_request.channel = (lin_hardware_name)0;
    lin_request.task_request = XLIN_REQ_GOTO_IDLE;
    /* Trigger Xgate execution */
    while((1 == (XGSWT&0x0001)))
    {};
    XGSWT = 0x0101;
    response_buffer = lin_lld_response_buffer;
}

void lin_lld_xgate_deinit
(
)
{

    /* Set to Uninitialized */
    state = UNINIT;

    lin_lld_xgate_int_disable();
}

void lin_lld_xgate_tx_wake_up
(
)
{
    if ((state == IDLE) || (state == SLEEP_MODE))
    {
        /* Send wake signal byte = 0x80 */
        pSCI->scidrl.byte = SCIDRH_R8_MASK;
        /* Set Lin state to idle */

        /* Request go to IDLE to Xgate */
        lin_request.channel = (lin_hardware_name)0;
        lin_request.task_request = XLIN_REQ_GOTO_IDLE;

        /* Trigger Xgate execution */
        while(1 == (XGSWT&0x0001))
        {};
        XGSWT = 0x0101;
    }
}

void lin_lld_xgate_int_enable
(
)
{
    /* Can't enable in interrupt context */
    if ((state == PROC_CALLBACK) || (state == UNINIT) || (state == SLEEP_MODE))
    {
        return;
    }
    /* Enable SCI Channel */
    pSCI->scicr2.byte |= (SCICR2_RE_MASK | SCICR2_RIE_MASK);
    /* Enable Timeout */
}

void lin_lld_xgate_int_disable
(
)
{
    /* Can't disable in interrupt context */
    if ((state == PROC_CALLBACK) || (state == UNINIT) || (state == SLEEP_MODE))
    {
        return;
    }

    while(state != IDLE)
    {}
    /* Disable SCI Channel */
    pSCI->scicr2.byte &= ~(SCICR2_RE_MASK | SCICR2_RIE_MASK);

}


void lin_lld_xgate_ignore_response
(
)
{
    /* Request go to IDLE to Xgate */
    lin_request.channel = (lin_hardware_name)0;
    lin_request.task_request = XLIN_REQ_GOTO_IDLE;
    /* Trigger Xgate execution */
    while(1 == (XGSWT&0x0001))
    {};
    XGSWT = 0x0101;
}

void lin_lld_xgate_set_low_power_mode
(
)
{
    /* Configure Hw code */

    /* Set Lin status = receiving data */
    state = SLEEP_MODE;
}

void lin_lld_xgate_rx_response
(
    /* [IN] Length of response data expect to wait */
    l_u8  msg_length
)
{
    /* Put response length and pointer of response buffer into descriptor */
    lin_lld_response_buffer[0] = msg_length;
    cnt_byte = 0;
    byte_rec = 0;
    /* Set Lin status = receiving data */
    state = RECV_DATA;
}

void lin_lld_xgate_tx_response
(
)
{
    /* calculate checksum */
    lin_lld_response_buffer[lin_lld_response_buffer[0]+1] = lin_checksum(lin_lld_response_buffer, pid );
    cnt_byte = 1;
    /* Send First byte */
    pSCI->scidrl.byte = lin_lld_response_buffer[1];
    /* Set LIN Status */
    state = SEND_DATA;
}

l_u8 lin_lld_xgate_get_status
(
)
{
    return l_status.byte;
}


l_u8 lin_lld_xgate_get_state
(
)
{
    return state;
}

void lin_lld_xgate_timeout
(
    void
)
{
    xlin_interrupt* lint_p;

    /* Get xlin_interrupt */
    lint_p = (xlin_interrupt*)&lin_interrupt;
    switch(lint_p->event_id)
    {
        case LIN_LLD_BUS_ACTIVITY_TIMEOUT:
        case LIN_LLD_NODATA_TIMEOUT:

            lin_pid_response_callback_handler((lin_lld_event_id)lint_p->event_id, (l_u8)lint_p->current_pid);

            break;

        default:
            ;
    }

}

void lin_lld_xgate_isr
(
)
{
    xlin_interrupt* lint_p;
    l_u16 sem_mask;

    /* Get xlin_interrupt */
    lint_p = (xlin_interrupt*)&lin_interrupt;
    response_buffer = lin_lld_response_buffer;


    switch(lint_p->event_id)
    {
        case LIN_LLD_PID_OK:
            lin_pid_response_callback_handler(lint_p->event_id, lint_p->current_pid);

            /* clear semaphore */
            sem_mask = 0x0100 << lint_p->semaphore_id;
            XGSEM &= ~sem_mask;
            break;
        case LIN_LLD_TX_COMPLETED:
        case LIN_LLD_RX_COMPLETED:

        case LIN_LLD_PID_ERR:
        case LIN_LLD_FRAME_ERR:
        case LIN_LLD_CHECKSUM_ERR:
        case LIN_LLD_READBACK_ERR:
            /* handle interrupt */
            lin_pid_response_callback_handler(lint_p->event_id, lint_p->current_pid);
            break;
        default:
            ;
    }
}

#endif /* End (LIN_MODE == _SLAVE_MODE_) */



#if LIN_MODE == _MASTER_MODE_

/***** Data shared between S12X and XGATE *****/
#pragma DATA_SEG SHARED_DATA /* Define a specific segment to store the data */
/**
* @var xlin_interrupt lin_interrupt
* lin interrupt
*/
volatile xlin_interrupt lin_interrupt[NUM_OF_SCI_CHANNEL];
/**
* @var xlin_request lin_request
* lin request
*/
volatile xlin_request lin_request;
/**
* @var l_u8 lin_channel
* lin channel
*/
volatile l_u8 lin_channel;
/**
* @var l_u8 byte_rec
* lin byte_rec
*/
volatile l_u8 byte_rec;
#pragma DATA_SEG DEFAULT /* Return to default data segment */

/***** EXTERN GLOBLE VAR *****/

extern lin_node lin_node_descrs[NUM_OF_SCI_CHANNEL];

/***** EXTERN FUNCTION *****/

extern void lin_pid_response_callback_handler(l_ifc_handle iii, lin_lld_event_id event_id, l_u8 pid);


/**** API ****/

void lin_lld_setup_xgate
(
)
{
    /* initialize the XGATE vector block and
       set the XGVBR register to its start address */
    XGVBR = (unsigned int)(void*__far)(XGATE_VectorTable - XGATE_VECTOR_OFFSET);

#if _SCI0_ == 1
    /* switch SCIn interrupt to XGATE */
    ROUTE_INTERRUPT(SCI0_VEC, 0x81); /* RQST = 1 and PRIO = 1 */
#endif /* End (_SCI0_ == 1) */

#if _SCI1_ == 1
    ROUTE_INTERRUPT(SCI1_VEC, 0x81); /* RQST = 1 and PRIO = 1 */
#endif /* End (_SCI0_ == 1) */

#if _SCI2_ == 1
    ROUTE_INTERRUPT(SCI2_VEC, 0x81); /* RQST = 1 and PRIO = 1 */
#endif /* End (_SCI0_ == 1) */

#if _SCI3_ == 1
    ROUTE_INTERRUPT(SCI3_VEC, 0x81); /* RQST = 1 and PRIO = 1 */
#endif /* End (_SCI0_ == 1) */

#if _SCI4_ == 1
    ROUTE_INTERRUPT(SCI4_VEC, 0x81); /* RQST = 1 and PRIO = 1 */
#endif /* End (_SCI0_ == 1) */

#if _SCI5_ == 1
    ROUTE_INTERRUPT(SCI5_VEC, 0x81); /* RQST = 1 and PRIO = 1 */
#endif /* End (_SCI0_ == 1) */


    /* switch PIT0 interrupt to XGATE */
    ROUTE_INTERRUPT(PIT0_VEC, 0x81); /* RQST = 1 and PRIO = 1 */

    /* switch software trigger 0 interrupt to XGATE */
    ROUTE_INTERRUPT(SOFTWARETRIGGER0_VEC, 0x82); /* RQST = 1 and PRIO = 1 */

    /* enable XGATE mode and interrupts */
    XGMCTL = 0xFBC1; /* XGE | XGFRZ | XGIE */

}

void lin_lld_xgate_init
(
    /* [IN] sci channel name */
    sci_channel_name  channel,
    /* [IN] LIN interface name */
    l_ifc_handle iii
)
{
    const lin_configuration *lconf_p;
    register lin_node *lnode_p;
    l_u16 tmp;

    /* Get lin configuration descriptor */
    lconf_p = &lin_ifc_configuration[iii];

    /* Set interface number */
    lin_request.iii = iii;

    /* Initialize xlin_interrupt */
    lin_interrupt[channel].ifc = (l_u8)iii;
    /* Assign semaphore id */
    lin_interrupt[channel].semaphore_id = (l_u8)iii;


    /* Get Lin node description */
    lnode_p = &lin_node_descrs[channel];

    /* Config */
    lnode_p->ifc = (l_u8)iii;
    //lnode_p->response_buffer = lin_lld_response_buffer[0];
    /* Set SCI is Master or Slave */
    lnode_p->func = (l_bool)lconf_p->function; ;
    /* Set check sum mode */
    //lnode_p->checksum_mode = (l_u8)lreq_p->checksum_mode;
    lnode_p->tbit = (l_u16)(1000000/lconf_p->baud_rate);

    /* Set baud rate */
    lnode_p->pSCI->scisr2.byte = 0x00;
    tmp = (l_u16)(MCU_BUS_FREQ/lconf_p->baud_rate/16);
    lnode_p->pSCI->scibdh.byte    = (l_u8)(tmp >> 8);
    lnode_p->pSCI->scibdl.byte  = tmp&0xff;

    /* Disable SCI in wait mode and enable bit count after stop bit */
    lnode_p->pSCI->scicr1.byte = (SCICR1_ILT_MASK | SCICR1_SCISWAI_MASK);
    /* Enable use of 13bit breaks and SCI frame for LIN */
    lnode_p->pSCI->scisr2.byte  = (SCISR2_AMAP_MASK | SCISR2_BRK13_MASK);
    /* Enable mismatch error detection */
    lnode_p->pSCI->sciasr1.byte = SCIASR1_BERRIF_MASK;
    /* Enable bit error interrupt and break detect flags */
    lnode_p->pSCI->sciacr1.byte = (SCIACR1_BERRIE_MASK | SCIACR1_BKDIE_MASK);
    /* Enable break detect circuit and timing bit error detection at 9th time stick */
    lnode_p->pSCI->sciacr2.byte = (SCIACR2_BERRM0_MASK | SCIACR2_BKDFE_MASK);
    /* Enable tranceiver interrupt */
    lnode_p->pSCI->scicr2.byte = (SCICR2_TE_MASK | SCICR2_RE_MASK | SCICR2_RIE_MASK);


    /* Request to Xgate */
    XLIN_REQ(channel, XLIN_REQ_GOTO_IDLE);
    /* Trigger Xgate execution */
    while(1 == (XGSWT&0x0001))
    {};
    XGSWT = 0x0101;
    lnode_p->response_buffer = lin_lld_response_buffer[0];
}

void lin_lld_xgate_deinit
(
    /* [IN] sci channel name */
    sci_channel_name  channel
)
{
    register lin_node *lnode_p;

    /* Get Lin node description */
    lnode_p = (lin_node *)&lin_node_descrs[channel];
    /* Set to Uninitialized */
    lnode_p->state = UNINIT;
}

void lin_lld_xgate_tx_header
(
    /* [IN] sci channel name */
    sci_channel_name  channel,
    /* [IN] pid to send out */
    l_u8  msg_id
)
{
    lin_node *lnode_p;
    /* Set interface number, lin func, baudrate, and buffer pointer */

    lnode_p = (lin_node *)&lin_node_descrs[channel];
    /* Check the SCI is Master ? */
    if (lnode_p->func)
    {
        return;
    }
    /* Make PID and put PID into the ongoing buffer */
    lnode_p->current_id = msg_id;
    lnode_p->pid = lin_process_parity(msg_id, MAKE_PARITY);
    /* Set LIN Status */
    lnode_p->state = SEND_BREAK;
    /* Send Break */
    lnode_p->pSCI->scicr2.byte |= SCICR2_SBK_MASK;
    lnode_p->pSCI->scicr2.byte &= ~SCICR2_SBK_MASK;
}

void lin_lld_xgate_tx_wake_up
(
    /* [IN] sci channel name */
    sci_channel_name  channel
)
{
    lin_node *lnode_p;
    /* Get Lin node description */
    lnode_p = (lin_node *)&lin_node_descrs[channel];

    if ((lnode_p->state == IDLE) || (lnode_p->state == SLEEP_MODE))
    {
        /* Send wake signal byte = 0x80 */
        lnode_p->pSCI->scidrl.byte = 0x80;

        /* Set Lin state to idle */
        XLIN_REQ(channel, XLIN_REQ_GOTO_IDLE);
        /* Trigger Xgate execution */
        while(1 == (XGSWT&0x0001))
        {};
        XGSWT = 0x0101;
    }
}

void lin_lld_xgate_int_enable
(
    /* [IN] sci channel name */
    sci_channel_name  channel
)
{
    lin_node *lnode_p;

    /* Get Lin node description */
    lnode_p = (lin_node *)&lin_node_descrs[channel];

    /* Can't enable in interrupt context */
    if ((lnode_p->state == PROC_CALLBACK) || (lnode_p->state == UNINIT) || (lnode_p->state == SLEEP_MODE))
    {
        return;
    }

    /* Enable SCI Channel */
    lnode_p->pSCI->scicr2.byte |= (SCICR2_TE_MASK | SCICR2_RE_MASK | SCICR2_RIE_MASK);
}

void lin_lld_xgate_int_disable
(
    /* [IN] sci channel name */
    sci_channel_name  channel
)
{
    lin_node *lnode_p;

    /* Get Lin node description */
    lnode_p = (lin_node *)&lin_node_descrs[channel];

    /* Can't disable in interrupt context */
    if ((lnode_p->state == PROC_CALLBACK) || (lnode_p->state == UNINIT) || (lnode_p->state == SLEEP_MODE))
    {
        return;
    }

    while(lnode_p->state != IDLE);

    /* Disable SCI Channel */
    lnode_p->pSCI->scicr2.byte &= ~(SCICR2_TE_MASK | SCICR2_RE_MASK | SCICR2_RIE_MASK);

}

void lin_lld_xgate_ignore_response (sci_channel_name  channel)
{
    /* Request to Xgate to go to IDLE state */
    XLIN_REQ(channel, XLIN_REQ_GOTO_IDLE);
    /* Trigger Xgate execution */
    while(1 == (XGSWT&0x0001))
    {};
    XGSWT = 0x0101;
}

void lin_lld_xgate_set_low_power_mode
(
    /* [IN] sci channel name */
    sci_channel_name  channel
)
{
    lin_node *lnode_p;

    /* Get Lin node description */
    lnode_p = (lin_node *)&lin_node_descrs[channel];

    /* Set LIN Status */
    lnode_p->state = SLEEP_MODE;
}

void lin_lld_xgate_tx_response
(
    /* [IN] sci channel name */
    sci_channel_name  channel
)
{
    lin_node *lnode_p;

    /* Get Lin node description */
    lnode_p = (lin_node *)&lin_node_descrs[channel];
    lnode_p->response_buffer = lin_lld_response_buffer[lnode_p->ifc];
    /* calculate checksum */
    lnode_p->response_buffer[*(lnode_p->response_buffer)+1] = lin_checksum(lnode_p->response_buffer, (l_u8)lnode_p->pid);
    lnode_p->cnt_byte = 1;
    /* Send First byte */
    lnode_p->pSCI->scidrl.byte = lnode_p->response_buffer[1];
    /* Set LIN Status */
    lnode_p->state = SEND_DATA;

}

void lin_lld_xgate_rx_response
(
    sci_channel_name  channel,
    l_u8 msg_length
)
{
    register lin_node *lnode_p;

    /* Get Lin node description */
    lnode_p = (lin_node *)&lin_node_descrs[channel];
    /* Put response length and pointer of response buffer into descriptor */
    lnode_p->cnt_byte = 0;
    lin_lld_response_buffer[lnode_p->ifc][0] = msg_length;
    byte_rec = 0;

    /* Set Lin status = receiving data */
    lnode_p->state = RECV_DATA;
}

l_u8 lin_lld_xgate_get_status
(
    /* [IN] sci channel name */
    sci_channel_name  channel
)
{
    lin_node *lnode_p;
    /* Get lin node description */
    lnode_p = &lin_node_descrs[channel];

    return lnode_p->l_status.byte;
}


l_u8 lin_lld_xgate_get_state(sci_channel_name  channel)
{
    lin_node *lnode_p;
    /* Get lin node description */
    lnode_p = &lin_node_descrs[channel];

    return lnode_p->state;
}

void lin_lld_xgate_timeout
(
    void
)
{
    xlin_interrupt* lint_p;

    /* Get xlin_interrupt */
    lint_p = (xlin_interrupt*)&lin_interrupt[lin_channel];
    switch(lint_p->event_id)
    {
        case LIN_LLD_BUS_ACTIVITY_TIMEOUT:
        case LIN_LLD_NODATA_TIMEOUT:

            lin_pid_response_callback_handler((l_ifc_handle)lint_p->ifc, lint_p->event_id, lint_p->current_pid);

            break;

        default:
            break;
    }

}

void lin_lld_xgate_isr (sci_channel_name  channel)
{
    xlin_interrupt* lint_p;
    l_u16 sem_mask;

    /* Get xlin_interrupt */
    lint_p = (xlin_interrupt*)&lin_interrupt[channel];
    switch(lint_p->event_id)
    {
        case LIN_LLD_PID_OK:
            lin_pid_response_callback_handler((l_ifc_handle)lint_p->ifc, lint_p->event_id, lint_p->current_pid);

            /* clear semaphore */
            sem_mask = 0x0100 << lint_p->semaphore_id;
            XGSEM &= ~sem_mask;
            break;
        case LIN_LLD_TX_COMPLETED:
        case LIN_LLD_RX_COMPLETED:
        case LIN_LLD_PID_ERR:
        case LIN_LLD_FRAME_ERR:
        case LIN_LLD_CHECKSUM_ERR:
        case LIN_LLD_READBACK_ERR:
            /* handle interrupt */
            lin_pid_response_callback_handler((l_ifc_handle)lint_p->ifc, lint_p->event_id, lint_p->current_pid);
            break;
        default:
            ;
    }
}

#endif /* End (LIN_MODE == _MASTER_MODE_) */
/**
 * @}
 */
