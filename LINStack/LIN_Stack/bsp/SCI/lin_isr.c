/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2016 Freescale Semiconductor, Inc.
* Copyright 2016-2017 NXP
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup SCI_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      bsp/SCI/lin_isr.c
*
* @author    FPT Software
*
* @brief     Interrupt service routine used in LIN driver
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 *
 * 20101027     v1.0    First version
 * 20111005     v1.1    Updated hardware support, multi timers
 * 20111121     v1.2  Updated interrupt service routine for 9S12J637
 * 20140728     v1.3    Add AUTOBAUD feature
 *
 *****************************************************************************/
#include "lin_hw_cfg.h"
#include "lin_lld_timesrv.h"
#include "lin_lld_sci.h"

#if AUTOBAUD == 1 /* AUTOBAUD feature applicible for S12Z MCU family*/
#include "lin_lld_autobaud.h"

extern l_u16 lin_max_frame_res_timeout_val_autobaud[8];
volatile l_bool stop_flag = 0;
l_u16 dTbit[5] = {0};

#endif /* End (1==AUTOBAUD) */

#if defined(_MC9S12I32_H)
#include "analog_die_reg.h"

volatile unsigned char sci_isr_flag = 0;
volatile unsigned char j = 0;
volatile unsigned char i=0;
volatile unsigned char ivr = 0;
volatile unsigned char scis = 0;
volatile unsigned char isrhi =0;
volatile unsigned char isrlo = 0;

#pragma CODE_SEG NON_BANKED

interrupt void D2D_ISR(void)
{
    ivr = IVR;
    isrhi = ISRhi;
    isrlo = ISRlo;
    scis = SCIS1;

    if(isrhi&0x01)
    {
        sci_isr_flag = 1;
        scis = SCIS1;

        lin_lld_sci_rx_isr();
        /* remove interrupt flag */
        SCIS1 = scis;
    }
    else if(isrlo&0x40)
    {
        lin_lld_sci_err_isr();
    }
    else if (isrlo&0x10)
    {
        lin_lld_sci_timeout();
        /* Write 1 to TFLG1 C3F to clear C3F flag*/
        TFLG1 |= 0x08;
    }
}

#pragma CODE_SEG DEFAULT

#elif defined (_MC9S12I128_H)
#include "mm912j637.h"

#pragma CODE_SEG NON_BANKED

void _D2DERR(void);     /* 0xFFF4 D2DI Error Interrupt            */
void _D2D(void);        /* 0xFFF2 D2DI External Error Interrupt   */

#pragma TRAP_PROC
void _dummyISR( void )
{
    /* endless loop */
    for(;;);
}

#pragma TRAP_PROC
void _D2D(void)
{
    volatile l_u8 reg_temp = 0x00;
    reg_temp = INT_VECT;
    switch (reg_temp)
    {
        case 0x04:
            _TFLG1.Bits.C0F = 1;
            break;

        case 0x07:
            _TFLG1.Bits.C3F = 1;
            lin_lld_timer_isr();
            break;

        case 0x9:
            lin_lld_sci_err_isr();
            break;

        case 0xB:
            lin_lld_sci_rx_isr();
            break;

        default:
            break;
    }
}

#pragma CODE_SEG DEFAULT

#elif defined (_MM9Z1J638_H)
#include "mm9z1j638.h"

interrupt _D2D(void);

interrupt _D2D(void)
{
    volatile l_u8 reg_temp = 0x00;
    reg_temp = B_INT_VECT;
    switch (reg_temp)
    {
        case 0x04:
            B_TFLG1_C0F = 1;
            break;

        case 0x07:
            B_TFLG1_C3F = 1;
            lin_lld_timer_isr();
            break;

        case 0x9:
        #if (LIN_MODE == _SLAVE_MODE_)
            lin_lld_sci_err_isr();
        #else
            lin_lld_sci_err_isr(SCI0);
        #endif
            break;

        case 0xB:
        #if (LIN_MODE == _SLAVE_MODE_)
            lin_lld_sci_rx_isr();
        #else
            lin_lld_sci_rx_isr(SCI0);
        #endif
            break;

        default:
            break;
    }
}

#pragma CODE_SEG DEFAULT

#else

/**
* @def ISR(ivn, x)
* Call function <B>x</B> with interrupt vector number is <B>ivn</B>
*/
#define ISR(ivn, x) interrupt ivn void x(void)

#if ((SCI_VERSION == SCI_V5) || (SCI_VERSION == SCI_V6))
/* Change vector number define */
#if (NUM_OF_SCI_CHANNEL == 1) && (!defined(_MC9S12GN32_H)) && (!defined(_MC9S12ZVMA_H))
#define VectorNumber_Vsci0              VectorNumber_Vsci
#define SCI0_INT                        SCI_INT
#endif /* End (NUM_OF_SCI_CHANNEL == 1) && !defined(_MC9S12GN32_H) */
/* End Change vector number define */
#if ((!defined(_MC9S12ZVML128_H)) && (!defined(_MC9S12ZVL32_H))&&(!defined(_MC9S12ZVML31_H)))
#pragma CODE_SEG __NEAR_SEG NON_BANKED /* Define a specific segment to store the code */
#endif /*End if ((!defined(_MC9S12ZVML128_H)) && (!defined(_MC9S12ZVL32_H))&&(!defined(_MC9S12ZVML31_H)))*/

#if _SCI0_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void ISR(VectorNumber_Vsci0, SCI0_INT)
* @brief interrupt service routine for SCI0 receiver
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI0 receiver
*
* @see #lin_lld_sci_isr
*//*END*----------------------------------------------------------------------*/
void SCI0_INT(void);
ISR(VectorNumber_Vsci0, SCI0_INT)
{
#if LIN_MODE == _SLAVE_MODE_
    lin_lld_sci_isr();
#else
    lin_lld_sci_isr(SCI0);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}
#endif /* End (_SCI0_ == 1) */

#if _SCI1_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void ISR(VectorNumber_Vsci1, SCI1_INT)
* @brief interrupt service routine for SCI1 receiver
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI1 receiver
*
* @see #lin_lld_sci_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci1, SCI1_INT)
{
#if LIN_MODE == _SLAVE_MODE_
    lin_lld_sci_isr();
#else
    lin_lld_sci_isr(SCI1);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}
#endif /* End (_SCI1_ == 1) */

#if _SCI2_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void ISR(VectorNumber_Vsci2, SCI2_INT)
* @brief interrupt service routine for SCI2 receiver
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI2 receiver
*
* @see #lin_lld_sci_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci2, SCI2_INT)
{
#if LIN_MODE == _SLAVE_MODE_
    lin_lld_sci_isr();
#else
    lin_lld_sci_isr(SCI2);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}
#endif /* End (_SCI2_ == 1) */

#if _SCI3_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void ISR(VectorNumber_Vsci3, SCI3_INT)
* @brief interrupt service routine for SCI3 receiver
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI3 receiver
*
* @see #lin_lld_sci_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci3, SCI3_INT)
{
#if LIN_MODE == _SLAVE_MODE_
    lin_lld_sci_isr();
#else
    lin_lld_sci_isr(SCI3);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}
#endif /* End (_SCI3_ == 1)*/

#if _SCI4_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void ISR(VectorNumber_Vsci4, SCI4_INT)
* @brief interrupt service routine for SCI4 receiver
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI4 receiver
*
* @see #lin_lld_sci_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci4, SCI4_INT)
{
#if LIN_MODE == _SLAVE_MODE_
    lin_lld_sci_isr();
#else
    lin_lld_sci_isr(SCI4);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}
#endif /* End (_SCI4_ ==1) */

#if _SCI5_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void ISR(VectorNumber_Vsci5, SCI5_INT)
* @brief interrupt service routine for SCI5 receiver
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI5 receiver
*
* @see #lin_lld_sci_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci5, SCI5_INT)
{
#if LIN_MODE == _SLAVE_MODE_
    lin_lld_sci_isr();
#else
    lin_lld_sci_isr(SCI5);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}
#endif /* End (_SCI5_ == 1) */
#endif /* End (SCI_VERSION == SCI_V5) */

#if (SCI_VERSION == SCI_V4)
/* Change vectorNumber define */
#if (NUM_OF_SCI_CHANNEL == 1)

#define VectorNumber_Vsci1tx VectorNumber_Vscitx
#define VectorNumber_Vsci1rx VectorNumber_Vscirx
#define VectorNumber_Vsci1err VectorNumber_Vscierr

#endif
/* End Change vectorNumber define */

#pragma CODE_SEG __NEAR_SEG NON_BANKED /* Define a specific segment to store the code */

#if _SCI0_ == 1
#if defined(_MC9S08RN60_H)
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI1_TX_INT (void)
* @brief interrupt service routine for SCI0 transmiter
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI0 transmiter
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci0tx, SCI0_TX_INT)
{
}

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI1_RX_INT(void)
* @brief interrupt service routine for SCI0 receiver
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI0 receiver
*
* @see #lin_lld_sci_rx_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci0rx, SCI0_RX_INT)
{
#if (LIN_MODE == _SLAVE_MODE_)
    lin_lld_sci_rx_isr();
#else
    lin_lld_sci_rx_isr(SCI0);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI1_ERR_INT( void )
* @brief interrupt service routine for SCI0 error
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI0 error
*
* @see #lin_lld_sci_rx_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci0err, SCI0_ERR_INT)
{
#if (LIN_MODE == _SLAVE_MODE_)
    lin_lld_sci_err_isr();
#else
    lin_lld_sci_err_isr(SCI0);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}
#else
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI1_TX_INT (void)
* @brief interrupt service routine for SCI0 transmiter
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI0 transmiter
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci1tx, SCI1_TX_INT)
{

}

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI1_RX_INT(void)
* @brief interrupt service routine for SCI0 receiver
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI0 receiver
*
* @see #lin_lld_sci_rx_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci1rx, SCI1_RX_INT)
{
#if (LIN_MODE == _SLAVE_MODE_)
    lin_lld_sci_rx_isr();
#else
    lin_lld_sci_rx_isr(SCI0);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI1_ERR_INT( void )
* @brief interrupt service routine for SCI0 error
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI0 error
*
* @see #lin_lld_sci_rx_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci1err, SCI1_ERR_INT)
{
#if (LIN_MODE == _SLAVE_MODE_)
    lin_lld_sci_err_isr();
#else
    lin_lld_sci_err_isr(SCI0);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}
#endif /* defined(_MC9S08RN60_H) */
#endif /* End _SCI0_ == 1 */


#if _SCI1_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI2_TX_INT (void)
* @brief interrupt service routine for SCI1 transmiter
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI1 transmiter
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci2tx, SCI2_TX_INT)
{

}

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI2_RX_INT (void)
* @brief interrupt service routine for SCI1 receiver
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI1 receiver
*
* @see #lin_lld_sci_rx_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci2rx, SCI2_RX_INT)
{
#if LIN_MODE == _SLAVE_MODE_
    lin_lld_sci_rx_isr();
#else
    lin_lld_sci_rx_isr(SCI1);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI2_ERR_INT (void)
* @brief interrupt service routine for SCI1 error
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI1 error
*
* @see #lin_lld_sci_rx_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci2err, SCI2_ERR_INT)
{
#if LIN_MODE == _SLAVE_MODE_
    lin_lld_sci_err_isr();
#else
    lin_lld_sci_err_isr(SCI1);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}
#endif /* End _SCI1_ == 1 */
#endif /*   End (SCI_VERSION == SCI_V4) */

#if (SCI_VERSION == SCI_V2)
#pragma CODE_SEG __NEAR_SEG NON_BANKED /* Define a specific segment to store the code */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI_RX_INT (void )
* @brief interrupt service routine for SCI0
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI0
*
* @see #lin_lld_xgate_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci1rx, SCI_RX_INT)
{
#if (LIN_MODE == _SLAVE_MODE_)
    lin_lld_sci_rx_isr();
#else
    lin_lld_sci_rx_isr(SCI0);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI_ERR_INT(void)
* @brief interrupt service routine for SCI0
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI0
*
* @see #lin_lld_xgate_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci1err, SCI_ERR_INT)
{
#if (LIN_MODE == _SLAVE_MODE_)
    lin_lld_sci_err_isr();
#else
    lin_lld_sci_err_isr(SCI0);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
}
#endif /* End (SCI_VERSION == SCI_V2) */


#if (_MCU_ == _S12X_)
#ifdef MULTI_TIMER_MODE
#if (_PIT0_ == 1)
ISR(VectorNumber_Vpit0, PIT0_TIMER_ISR)
{
    lin_lld_timer_isr(PIT0_INDEX);
    __asm
    {
        MOVB #$01,PITTF
    }
}
#endif /* (_PIT0_ == 1) */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void PIT1_TIMER_ISR (void)
* @brief interrupt interrupt service routine for PIT1
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for PIT1
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
#if (_PIT1_ == 1)
/****CONGTH****/
ISR(VectorNumber_Vpit1, PIT1_TIMER_ISR)
{
    lin_lld_timer_isr(PIT1_INDEX);
    __asm
    {
        MOVB #$02,PITTF
    }
}
#endif  /* (_PIT1_ == 1) */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void PIT2_TIMER_ISR (void)
* @brief interrupt interrupt service routine for PIT2
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for PIT2
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
#if (_PIT2_ == 1)
ISR(VectorNumber_Vpit2, PIT2_TIMER_ISR)
{
    lin_lld_timer_isr(PIT2_INDEX);
    __asm
    {
        MOVB #$04,PITTF
    }
}
#endif  /* (_PIT2_ == 1) */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void PIT3_TIMER_ISR (void)
* @brief interrupt interrupt service routine for PIT3
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for PIT3
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
#if (_PIT3_ == 1)
ISR(VectorNumber_Vpit3, PIT3_TIMER_ISR)
{
    lin_lld_timer_isr(PIT3_INDEX);
    __asm
    {
        MOVB #$08,PITTF
    }
}
#endif /* (_PIT3_ == 1) */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void PIT4_TIMER_ISR (void)
* @brief interrupt interrupt service routine for PIT4
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for PIT4
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
#if (_PIT4_ == 1)
/****CONGTH****/
ISR(VectorNumber_Vpit4, PIT4_TIMER_ISR)
{
    lin_lld_timer_isr(PIT4_INDEX);
    __asm
    {
        MOVB #$10,PITTF
    }
}
#endif  /* End (_PIT4_ == 1) */


/*FUNCTION*--------------------------------------------------------------*//**
* @fn void PIT5_TIMER_ISR (void)
* @brief interrupt interrupt service routine for PIT5
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for PIT5
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/

#if (_PIT5_ == 1)
/****CONGTH****/
ISR(VectorNumber_Vpit5, PIT5_TIMER_ISR)
{
    lin_lld_timer_isr(PIT5_INDEX);
    __asm
    {
        MOVB #$20,PITTF
    }
}
#endif  /* End (_PIT6_ == 1) */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void PIT6_TIMER_ISR (void)
* @brief interrupt interrupt service routine for PIT6
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for PIT6
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
#if (_PIT6_ == 1)
/****CONGTH****/
ISR(VectorNumber_Vpit6, PIT6_TIMER_ISR)
{
    lin_lld_timer_isr(PIT6_INDEX);
    __asm
    {
        MOVB #$40,PITTF
    }
}
#endif  /* End (_PIT6_ == 1) */

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void PIT7_TIMER_ISR (void)
* @brief interrupt interrupt service routine for PIT7
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for PIT7
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
#if (_PIT7_ == 1)
/****CONGTH****/
ISR(VectorNumber_Vpit7, PIT7_TIMER_ISR)
{
    lin_lld_timer_isr(PIT7_INDEX);
    __asm
    {
        MOVB #$80,PITTF
    }
}
#endif  /* End (_PIT7_ == 1) */

#else /* Else MULTI_TIMER_MODE */
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void PIT0_TIMER_ISR (void)
* @brief interrupt interrupt service routine for PIT0
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for PIT0
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vpit0, PIT0_TIMER_ISR)
{
    lin_lld_timer_isr();
    PITTF_PTF0 = 1;
}

#endif /* End MULTI_TIMER_MODE */
#endif /* End (_MCU_ == _S12X_) */

#if (_MCU_ == _S12_)
#if defined(_MC9S12XHY256_H) || defined(_MC9S12HY64_H)
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void TIM0CH7_TIMER_ISR (void)
* @brief interrupt interrupt service routine for TIM0
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for TIM0
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vtim0ch7, TIM0CH7_TIMER_ISR)
{
    lin_lld_timer_isr();
    /* Reset interrupt request flag */
    TIM0_TFLG1 = 128;
}
#endif /* End for 9S12XHY256 and 9S12HY64 */

#if defined(_MC9S12P128_H) || defined(_MC9S12XS128_H) || defined(_MC9S12XS256_H) || defined(_MC9S12G128_H) || defined(_MC9S12G240_H)
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void TIM0_TIMER_ISR (void)
* @brief interrupt interrupt service routine for TIM timer
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for TIM timer
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vtimch7, TIM0_TIMER_ISR)
{
    lin_lld_timer_isr();
    TFLG1_C7F = 1;
}
#endif /* End for 9S12P128, 9S12XS128, 9S12XS256 and 9S12G128 */

#if (defined(_MC9S12VR64_H)||defined(_MC9S12VR32_H))
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void TIM0_TIMER_ISR (void)
* @brief interrupt interrupt service routine for TIM timer
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for TIM timer
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vtimch0, TIM_TIMER_ISR)
{
    lin_lld_timer_isr();
    /* Write 1 to TFLG1 C0F bit to clear this C0F flag*/
    TFLG1 = TFLG1_C0F_MASK;
    TC0   = (TC0 + ((MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD) ) & 0xFFFF;
}

#endif /* End if (defined(_MC9S12VR64_H)||defined(_MC9S12VR32_H)) */

#if defined(_MC9S12GN32_H) || defined(_MC9S12G64_H)
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void TIM0_TIMER_ISR (void)
* @brief interrupt interrupt service routine for TIM timer
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for TIM timer
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vtimch0, TIM_TIMER_ISR)
{
    lin_lld_timer_isr();
    /* Write 1 to TFLG1 C0F bit to clear this C0F flag*/
    TFLG1 = TFLG1_C0F_MASK;
    TC0   = (TC0 + ((MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD) ) & 0xFFFF;
}

#endif /* End defined(_MC9S12GN32_H) || defined(_MC9S12G64_H) */

#if (defined(_MC9S12VR64_H) || defined(_MC9S12VR32_H) || defined(_MC9S12VRP64_H) || defined(_MC9S12VRP48_H))
    #if (_SCI0_)
    void LinPhy_ISR(void);
    ISR(VectorNumber_Vlinphy, LinPhy_ISR)
    {
        /* Clear over current interrupt flag */
        if(LPIF_LPOCIF == 1)
        {
            LPIF_LPOCIF = 1;
        }
    }
    #endif /* END SCI0 */
#endif /* END if defined(_MC9S12VR64_H) || defined(_MC9S12VR32_H) || defined(_MC9S12VRP64_H) || defined(_MC9S12VRP48_H) */

#if (defined(_MC9S12ZVML128_H) || defined(_MC9S12ZVL32_H)||defined(_MC9S12ZVHY64_H)||defined(_MC9S12ZVH128_H)\
    ||defined(_MC9S12ZVML31_H)||defined(_MC9S12ZVMC256_H)||defined(_MC9S12ZVL128_H) ||defined(_MC9S12ZVMB_H))
void TIMchan2_ISR(void);
ISR(VectorNumber_Vtim0ch2, TIMchan2_ISR)
{
    lin_lld_timer_isr();
    /* Write 1 to TFLG1 C2F bit to clear this C2F flag*/
    TIM0TFLG1 = TIM0TFLG1_C2F_MASK;
    TIM0TC2   = (TIM0TC2 + ((MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD) ) & 0xFFFF;
}
#endif /* End if (defined(_MC9S12ZVML128_H) || defined(_MC9S12ZVL32_H)||defined(_MC9S12ZVHY64_H)||defined(_MC9S12ZVH128_H)||defined(_MC9S12ZVML31_H)) */

#if ( defined(_MC9S12ZVL32_H) || defined(_MC9S12ZVL128_H) || \
defined(_MC9S12ZVMA_H) || defined(_MC9S12ZVMB_H))
#if (_SCI0_)

void LinPhy_ISR(void);
ISR(VectorNumber_Vlinphy0, LinPhy_ISR)
{
    /* Clear over current interrupt flag */
    if(LP0IF_LPOCIF == 1)
    {
        LP0IF_LPOCIF = 1;
    }
}
#endif /* END SCI0 */
#endif /* END ifdef _MC9S12ZVL32_H */

#if (defined(_MC9S12ZVC64_H))
ISR(VectorNumber_Vtim1ch2, TIMchan2_ISR)
{
    lin_lld_timer_isr();
    /* Write 1 to TFLG1 C2F bit to clear this C2F flag*/
    TIM0TFLG1 = TIM0TFLG1_C2F_MASK;
    TIM1TC2   = (TIM1TC2 + ((MCU_BUS_FREQ/500000)*TIME_BASE_PERIOD) ) & 0xFFFF;
}
#endif

#if (defined(_MC9S12ZVMA_H)||defined(_MC9S12VRP64_H)||defined(_MC9S12VRP48_H))
void TIM1chan0_ISR(void);
ISR(VectorNumber_Vtim1ch0, TIM1chan0_ISR)
{
    lin_lld_timer_isr();
    /* Write 1 to TFLG1 C0F bit to clear this C0F flag*/
    TIM1TFLG1 = TIM1TFLG1_C0F_MASK;
    TIM1TC0   = (TIM1TC0 + ((MCU_BUS_FREQ/1000000)*TIME_BASE_PERIOD) ) & 0xFFFF;
}
#endif /* End if (defined(_MC9S12ZVMA_H))||defined(_MC9S12VRP64_H)||defined(_MC9S12VRP48_H)) */


#if (AUTOBAUD == 1)
void TIM_Input_capture_ISR(void);
void AutobaudTimerValEval(void)
{
    l_u8 i;

    /* Clear interrupt flag */
    CLEAR_TIMER_CHANNEL_INTERRUPT_FLAG;

    if ((0 == stop_flag) && (autobaud_tmr_capture_index  < 5))
    {

        autobaud_tmr_capture[autobaud_tmr_capture_index]=TIMER_CNT_REG;
        /* Calculate 2xTbit time for the second and later capture */
        if (autobaud_tmr_capture_index > 0)
        {
            i = autobaud_tmr_capture_index - 1;
            dTbit[i] = autobaud_tmr_capture[i+1] - autobaud_tmr_capture[i];
            /* Check if 2xTbit time satisfy valid conditions:
             * 1. The following 2xTbit must be +/-14% of the 2xTbit right before it
             * 2. And it is in the acceptable ranges of master baud rate of 19200 bps or 9600 bps
             */
            if ((dTbit[i] < DBIT_DURATION_MIN_19200) ||
                ((dTbit[i] > DBIT_DURATION_MAX_19200) && (dTbit[i] < DBIT_DURATION_MIN_9600)) ||
                (dTbit[i] > DBIT_DURATION_MAX_9600))
            {
                stop_flag = 1;
                /* do not capture */
                TIMER_CONTROL_EDG = 0;
                TIMER_INT_ENA = 0;
                lin_goto_idle_state();
                return;
            }else
            {
                if (i > 0)
                {
                    if ((dTbit[i] < ((100 - BIT_RATE_TOLERANCE_UNSYNC) * (dTbit[i-1] / 100))) || (dTbit[i] > ((100 + BIT_RATE_TOLERANCE_UNSYNC) * (dTbit[i-1] / 100))))
                    {
                        stop_flag = 2;
                        /* do not capture */
                        TIMER_CONTROL_EDG = 0;
                        TIMER_INT_ENA = 0;
                        lin_goto_idle_state();
                        return;
                    }
                }
            }
        }
         autobaud_tmr_capture_index ++;
    }
    /* Adjust the baud rate if there is no error in SYNC BYTE */
    if ((autobaud_tmr_capture_index > 4) && (stop_flag == 0))
    {
        if (dTbit[i] >= DBIT_DURATION_MIN_9600)
        {
            autobaud_current = 9600;
        }else
        {
            autobaud_current = 19200;
        }
        lin_lld_sci_init_autobaud(autobaud_current);
        /* Disable interrupt from timer channel */
        TIMER_CONTROL_EDG = 0;
        TIMER_INT_ENA = 0;
    }
    return;
}

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void TIM_Input_capture_ISR (void)
* @brief timer interrupt service routine for AUTOBAUD feature
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt interrupt service routine for TIM timer
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
#if (defined(_MC9S12ZVML128_H)||defined(_MC9S12ZVML31_H) ||defined(_MC9S12ZVL32_H)\
    ||defined(_MC9S12ZVL128_H)||defined(_MC9S12ZVMC256_H) || defined(_MC9S12ZVMB_H))
ISR(VectorNumber_Vtim0ch3, TIM_Input_capture_ISR)
{
    AutobaudTimerValEval();
}
#endif
/* End if (defined(_MC9S12ZVML128_H)||defined(_MC9S12ZVML31_H)||defined(_MC9S12ZVL32_H) */
/* ||defined(_MC9S12ZVL128_H)||defined(_MC9S12ZVMC256_H) || defined(_MC9S12ZVMB_H)) */

#if (defined(_MC9S12ZVH128_H))
ISR(VectorNumber_Vtim1ch0, TIM_Input_capture_ISR)
{
    AutobaudTimerValEval();
}
#endif /* End (defined(_MC9S12ZVH128_H)*/

#if (defined(_MC9S12VR64_H)||defined(_MC9S12VR32_H))
ISR(VectorNumber_Vtimch3, TIM_Input_capture_ISR)
{
    AutobaudTimerValEval();
}
#endif /* End if (defined(_MC9S12VR64_H)||defined(_MC9S12VR32_H))*/

#if (defined(_MC9S12ZVMA_H)||defined(_MC9S12VRP64_H)||defined(_MC9S12VRP48_H))
ISR(VectorNumber_Vtim1ch1, TIM_Input_capture_ISR)
{
    AutobaudTimerValEval();
}
#endif /* End if (defined(_MC9S12ZVMA_H))*/

#endif /* End (AUTOBAUD == 1)*/

#endif /* End (_MCU_ == _S12_) */

#if (_MCU_ == _S08_)
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void TPM1_TIMER_ISR(void)
* @brief interrupt service routine for TPM1/ FTM timer
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for TPM1/ FTM timer
*
* @see #lin_lld_timer_isr
*//*END*----------------------------------------------------------------------*/
#if defined(_MC9S08RN60_H)

ISR(VectorNumber_Vmtim0, TPM1_TIMER_ISR)
{
    /* CH0F = 0 */
    MTIM0_SC &= ~MTIM0_SC_TOF_MASK;
    lin_lld_timer_isr();
}
#else
ISR(VectorNumber_Vtpm1ch0, TPM1_TIMER_ISR)
{
    /* CH0F = 0 */
    TPM1C0SC &= ~TPM1C0SC_CH0F_MASK;
    lin_lld_timer_isr();
}
#endif /* End defined(_MC9S08RN60_H)*/
#endif /* End (_MCU_ == _S08_) */

#if ((!defined(_MC9S12ZVML128_H))&&(!defined(_MC9S12ZVML31_H)))
#pragma CODE_SEG DEFAULT /* Return to default code segment */
#endif /* End if ((!defined(_MC9S12ZVML128_H))&&(!defined(_MC9S12ZVML31_H))) */

#endif /* End defined(_MC9S12I32_H) */
/**
* @}
*/



