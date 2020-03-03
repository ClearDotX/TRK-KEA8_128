/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2008-2015 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
******************************************************************************/
/**************************************************************************//**
* @addtogroup resync_group
* @{
******************************************************************************/
/**************************************************************************//**
*
* @file      lin_lld_resyn.h
*
* @author    FPT Software
*
* @brief     Resynch for Slave (Only SCI version 4)
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 *
 * 20101027     v1.0    First version
 *
 *****************************************************************************/


#ifndef __LIN_LLD_RESYN
#define __LIN_LLD_RESYN

#include "lin_hw_cfg.h"
#include "lin_cfg.h"

#if (LIN_MODE == _SLAVE_MODE_)
#if defined(_MC9S08DZ128_H)
#define _TRMREG     MCGTRM
#elif defined(_MC9S08DZ60_H)
#define _TRMREG     MCGTRM
#elif defined(_MC9S08MP16_H)
#define _FTMTIMER
#define _TRMREG     ICSTRM
#define TPM2CNTH    FTM2CNTH
#define TPM2CNTL        FTM2CNTL
#define TPM2SC          FTM2SC
#define TPM2MOD         FTM2MOD

#elif defined(_MC9S08EL32_H)
#define _TRMREG     ICSTRM

#elif defined(_MC9S08SG32_H)
#define _TRMREG     ICSTRM

#elif defined(_MC9S08LL64_H)
#define _TRMREG     ICSTRM
#endif /* End if defined (_MC9S08DZ128_H) */
#endif /* End (LIN_MODE == _SLAVE_MODE_) */

#if (__RESYN_EN == 1)

#define __RESYN_TEST_EN 0 /* 1 - if enable store sample for test, 0 if disable - ToanLN */

#if (RESYN_TIMER_PRESCALER == 128)
#define F_DEV_FACTOR                (unsigned int)(LIN_PRESCALER)
#define CORR_FACTOR             250/F_DEV_FACTOR
#else
#define F_DEV_FACTOR                (unsigned int)((128 * LIN_PRESCALER) / RESYN_TIMER_PRESCALER)
#define CORR_FACTOR             (250/F_DEV_FACTOR)
#endif

#define MIN_FREQ_CORR    0.5                   /* minimum frequency deviation for a trim correction, in % */
#define TRIM_RES_INV     2.5                   /* Resolution of trim = 0.4% */

#define MIN_CORR         (unsigned char)(MIN_FREQ_CORR*TRIM_RES_INV  )
#define ICS_MAX_DEV      45                     /* Maximum allowed ICS frequency deviation, in % */
#define MAX_TRM_CORR     (unsigned char)(ICS_MAX_DEV*TRIM_RES_INV)  /* Maximum trim correction, assuming a 0.2% frequency deviation per _TRMREG bit */
#define MAX_TRM          255
#define MIN_TRM          0
#define FALLING_EDGE_NUM_DEF 5

#define START_RESYN_MASK 0x01
#define FIN_RESYN_MASK   0x20
#define STOP_RESYN_MASK  0x00


#if (RESYN_TIMER_PRESCALER == 1)
#define TPM2SC_DEF 0x08
#endif

#if (RESYN_TIMER_PRESCALER == 2)
#define TPM2SC_DEF 0x09
#endif

#if (RESYN_TIMER_PRESCALER == 4)
#define TPM2SC_DEF 0x0A
#endif

#if (RESYN_TIMER_PRESCALER == 8)
#define TPM2SC_DEF 0x0B
#endif

#if (RESYN_TIMER_PRESCALER == 16)
#define TPM2SC_DEF 0x0C
#endif

#if (RESYN_TIMER_PRESCALER == 32)
#define TPM2SC_DEF 0x0D
#endif

#if (RESYN_TIMER_PRESCALER == 64)
#define TPM2SC_DEF 0x0E
#endif

#if (RESYN_TIMER_PRESCALER == 128)
#define TPM2SC_DEF 0x0F
#endif

#if (RESYN_TIMER_PRESCALER == 0x00)
#define TPM2SC_DEF 0x0F
#endif
/**
* @def TPM_CH2_store()
* @details
*      Store timer value
*/
#define TPM_CH2_store()             TPM2SC   = 0x00;                      \
                              timer_value = TPM2CNTH ;              \
                              timer_value = timer_value <<8 ;       \
                              timer_value = timer_value | TPM2CNTL



/**
* @def TPM_CH2_enable()
* @details
*      Enable timer TPM channel 2
*/
#define TPM_CH2_enable()            TPM2CNTH = 0x00;            \
                                                            TPM2CNTL = 0x00;      \
                                                            TPM2SC   = TPM2SC_DEF
/**
* @def TPM_CH2_init()
* @details
*      Init timer TPM channel 2
*/
#define TPM_CH2_init()          TPM2SC = 0x00;              \
                                                            TPM2MOD = 0x00;             \
                                                            (void)(TPM2SC == 0);    \
                                                            TPM2SC = TPM2SC_DEF

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void initTrimSaturation (void)
* @brief initialization the max and min value for TRIM register
*
* @return void
*
* @SDD_ID
* @endif
*
* @local_var
*   -# <B>#l_u16</B> <I>curTrimValue</I>
*
* @static_global_var
*   -# <B>#MaxTrimValue</B>
*   -# <B>#MinTrimValue</B>
*
* @details
*
*//*END*----------------------------------------------------------------------*/
void initTrimSaturation(void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void compTrimCorrection (void)
* @brief Calculate the value which TRIM reg need to change
*
* @return void
*
* @SDD_ID
* @endif
*
* @local_var
*   -# <B>#l_u16</B> <I>tmp</I>
*
* @static_global_var
*   -# <B>#timer_value</B>
*   -# <B>#PositiveCorr</B>
*   -# <B>#DeltaTrim</B>
*
* @details
*
*//*END*----------------------------------------------------------------------*/
void compTrimCorrection(void);

/*FUNCTION*--------------------------------------------------------------*//**
* @fn void ApplyTrimReg (void)
* @brief Change the TRIM register
*
* @return void
*
* @SDD_ID
* @endif
*
* @local_var
*   -# <B>#l_u8</B> <I>newTrim</I>
*
* @static_global_var
*   -# <B>#PositiveCorr</B>
*   -# <B>#MaxTrimValue</B>
*   -# <B>#MinTrimValue</B>
* @details
*
*//*END*----------------------------------------------------------------------*/
void ApplyTrimReg(void);


#endif /* End (__RESYN_EN == 1) */
#endif /* End __LIN_LLD_RESYN */

/**
* @}
*/
