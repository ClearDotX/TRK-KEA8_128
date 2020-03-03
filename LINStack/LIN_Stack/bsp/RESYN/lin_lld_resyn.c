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
* @file            lin_lld_resyn.c
*
* @author        FPT Software
*
* @brief         Resynch for Slave (Only SCI version 4)
*
******************************************************************************/

/******************************************************************************
 *
 * History:
 *
 * 20101027         v1.0        First version
 *
 *****************************************************************************/

#include "lin.h"
#include "lin_lld_resyn.h"

#if (__RESYN_EN == 1)
/**
* @var l_u16 timer_value
* @details
*
 */
l_u16    timer_value    = 0;
/**
* @var volatile static l_u16 DeltaTrim
* @details
*
 */
volatile static l_u16             DeltaTrim;
/**
* @var volatile static l_u8 PositiveCorr;
* @details
*
 */
volatile static l_u8                PositiveCorr;
/**
* @var l_u8 MaxTrimValue
* @var l_u8 MinTrimValue
* @details
*
 */
volatile static l_u8                MaxTrimValue, MinTrimValue;

void initTrimSaturation(void)
{
    l_u16 curTrimValue = _TRMREG;

    MaxTrimValue = curTrimValue + MAX_TRM_CORR;
    if (MaxTrimValue < curTrimValue)
    {
        MaxTrimValue = MAX_TRM;
    }

    MinTrimValue = curTrimValue - MAX_TRM_CORR;
    if (MinTrimValue > curTrimValue)
    {
        MinTrimValue = MIN_TRM;
    }
}

void compTrimCorrection()
{
    l_u16 tmp;
    if (timer_value > F_DEV_FACTOR)
    {
        /* Need to decrease Freq ->increase trim value */
        PositiveCorr = 1;
        tmp = (unsigned int)(timer_value-F_DEV_FACTOR);
    }
    else
    {
        /* Need to increase Freq ->decrease trim value */
        PositiveCorr = 0;
        tmp = (unsigned int)(F_DEV_FACTOR-timer_value);
    }
    DeltaTrim = (unsigned int)(tmp*CORR_FACTOR);
}

void ApplyTrimReg()
{
    if (DeltaTrim > MIN_CORR)
    {
        l_u8 newTrim;
        if (PositiveCorr)
        {
            newTrim = _TRMREG + (unsigned char)DeltaTrim;
            if ((newTrim < _TRMREG) || (newTrim > MaxTrimValue))
            {
                newTrim = MaxTrimValue;
            }
        }
        else
        {
            newTrim = _TRMREG - (unsigned char)DeltaTrim;
            if ((newTrim > _TRMREG) || (newTrim < MinTrimValue))
            {
                newTrim = MinTrimValue;
            }
        }
        /* Apply correction */
        _TRMREG = newTrim;
    }
}
#endif /* End Enable resych */
/* End of File */

/**
 * @}
 */