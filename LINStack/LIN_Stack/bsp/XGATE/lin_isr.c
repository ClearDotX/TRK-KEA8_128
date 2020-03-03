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
* @file      bsp/XGATE/lin_isr.c
*
* @author    FPT Software
*
* @brief     LIN SCI interrupt in XGATE
*
******************************************************************************/
/******************************************************************************
 *
 * History:
 *
 * 20090408     v1.0    First version
 *
 *****************************************************************************/

#include "reg_s12x.h"
#include "lin_hw_cfg.h"

#include "lin_lld_timesrv.h"
#include "lin_lld_xgate.h"

/**
* @def ISR(ivn, x)
* Call function <B>x</B> with interrupt vector number is <B>ivn</B>
*/
#define ISR(ivn, x) interrupt ivn void x(void)

#pragma CODE_SEG __NEAR_SEG NON_BANKED /* Define a specific segment to store the code */

#if _SCI0_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI0_INT (void)
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
ISR(VectorNumber_Vsci0, SCI0_INT)
{

#if (LIN_MODE == _SLAVE_MODE_)
    lin_lld_xgate_isr();
#else
    lin_lld_xgate_isr(SCI0);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
    /*Clear the xgate channel flag! */
#ifdef _MC9S12XF512_H
    XGIF_6F_60_XGIF_6B=1;
#else
    XGIF1_XGIF_6B=1;
#endif
}
#endif  /* End (_SCI0_ == 1) */

#if _SCI1_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI1_INT (void)
* @brief interrupt service routine for SCI1
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI1
*
* @see #lin_lld_xgate_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci1, SCI1_INT)
{
#if (LIN_MODE == _SLAVE_MODE_)
    lin_lld_xgate_isr();
#else
    lin_lld_xgate_isr(SCI1);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
    /*Clear the xgate channel flag! */
#ifdef _MC9S12XF512_H
    XGIF_6F_60_XGIF_6A=1;
#else
    XGIF1_XGIF_6A=1;
#endif
}
#endif /* End (_SCI1_ == 1) */

#if _SCI2_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI2_INT (void)
* @brief interrupt service routine for SCI2
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI2
*
* @see #lin_lld_xgate_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci2, SCI2_INT)
{
#if (LIN_MODE == _SLAVE_MODE_)
    lin_lld_xgate_isr();
#else
    lin_lld_xgate_isr(SCI2);
    /*Clear the xgate channel flag! */
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
    XGIF3_XGIF_45=1;
}
#endif /* End (_SCI2_ == 1) */

#if _SCI3_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI3_INT (void)
* @brief interrupt service routine for SCI3
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI3
*
* @see #lin_lld_xgate_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci3, SCI3_INT)
{
#if (LIN_MODE == _SLAVE_MODE_)
    lin_lld_xgate_isr();
#else
    lin_lld_xgate_isr(SCI3);
    /*Clear the xgate channel flag! */
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
    XGIF3_XGIF_44=1;
}
#endif

#if _SCI4_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI4_INT (void)
* @brief interrupt service routine for SCI4
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI4
*
* @see #lin_lld_xgate_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci4, SCI4_INT)
{
#if (LIN_MODE == _SLAVE_MODE_)
    lin_lld_xgate_isr();
#else
    lin_lld_xgate_isr(SCI4);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
    /*Clear the xgate channel flag! */
    XGIF3_XGIF_43=1;
}
#endif

#if _SCI5_ == 1
/*FUNCTION*--------------------------------------------------------------*//**
* @fn void SCI5_INT (void)
* @brief interrupt service routine for SCI5
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for SCI5
*
* @see #lin_lld_xgate_isr
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vsci5, SCI5_INT)
{
#if (LIN_MODE == _SLAVE_MODE_)
    lin_lld_xgate_isr();
#else
    lin_lld_xgate_isr(SCI5);
#endif /* End (LIN_MODE == _SLAVE_MODE_) */
    /*Clear the xgate channel flag! */
    XGIF3_XGIF_42=1;
}
#endif

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void PIT0_TIMER_ISR (void)
* @brief interrupt service routine for PIT0
*
* @return #void
*
* @SDD_ID N/A
* @endif
*
* @details
*   interrupt service routine for PIT0
*
* @see #lin_lld_xgate_timeout
*//*END*----------------------------------------------------------------------*/
ISR(VectorNumber_Vpit0, PIT0_TIMER_ISR)
{

    lin_lld_xgate_timeout();
#ifdef _MC9S12XF512_H
    XGIF_3F_30_XGIF_3D=1;
#else
    XGIF4_XGIF_3D=1;
#endif
}

#pragma CODE_SEG DEFAULT /* Return to default code segment */
/**
* @}
*/
