/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2013 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
***************************************************************************//*!
*
* @file ics.h
*
* @author Freescale
*
* @version 0.0.1
*
* @date Jun. 25, 2013
*
* @brief header file for Internal Clock Source utilities. 
*
*******************************************************************************
*
* provide APIs for accessing internal clock source (ICS)
******************************************************************************/

#ifndef ICS_H_
#define ICS_H_
#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
* Includes
******************************************************************************/

/******************************************************************************
* Constants
******************************************************************************/
/* 
 * ICS clock mode
 */
/******************************************************************************
* define ICS clock modes
*
*//*! @addtogroup ics_clock_mode
* @{
*******************************************************************************/
 
/*!
 * @brief clock mode constants definition.
 *
 */
enum
{
    ICS_CLK_MODE_FEI = 1,       /*!< FEI mode */
    ICS_CLK_MODE_FEE,           /*!< FEE mode */
    ICS_CLK_MODE_FEE_OSC,       /*!< FEE mode with external active oscillator */    
    ICS_CLK_MODE_FBE,           /*!< FBE mode */
    ICS_CLK_MODE_FBE_OSC,       /*!< FBE mode with external active oscillator */    
    ICS_CLK_MODE_FBI,           /*!< FBI mode */
    ICS_CLK_MODE_FBILP,         /*!< FBILP mode */    
    ICS_CLK_MODE_FBELP,         /*!< FBELP mode */        
};
/*! @} End of ics_clock_mode                                                    					*/

/******************************************************************************
* Macros
******************************************************************************/


/******************************************************************************
* define ICS API list
*
*//*! @addtogroup ics_api_list
* @{
*******************************************************************************/
      
/*****************************************************************************//*!
   *
   * @brief switch clock mode from current to new mode.
   *
   *  The clock mode macros are as follows:
   *      FEI, FBI, FEE, FBE, FBILP, FBELP, FEE_OSC, FBE_OSC
   *    where FEE_OSC, FBE_OSC can not be used as current mode. The valid combinationS of 
   *    <CurMode, NewMode> pair are as follows:      
   *    <FEI,FEE>, <FEI,FBI>, <FEI,FBE>, <FEI,FBE_OSC>, <FEI,FEE_OSC>, <FEE,FEI>,
   *    <FEE,FBI>, <FEE,FBE>, <FBI,FBE>, <FBI,FEE>, <FBI,FBILP>, <FBI,FEI>,
   *    <FBE,FBI>, <FBE,FEE>, <FBE,FEI>, <FBE,FBELP>, <FBELP,FBE>, <FBILP,FBI>.
   *    
   * @param[in] CurMode   current clock mode macro
   * @param[in] NewMode   new clock mode macro
   * @param[in] clkFreq     reference clock frequency
   *       
   * @return none
   * @warning FEE_OSC, FBE_OSC can not be used as current mode
   *
   * @ Pass/ Fail criteria: none
   *****************************************************************************/

#define ICS_SwitchMode(CurMode, NewMode, clkFreq)   CurMode##_to_##NewMode(clkFreq)
       
/*! @} End of ics_api_list                                                    					*/

/*!****************************************************************************
* Types
******************************************************************************/
    
/* OSC configuration structure 
 */  
/******************************************************************************
* define OSC configuration structure
*
*//*! @addtogroup osc_config_type
* @{
*******************************************************************************/
 
/*!
 * @brief OSC configuration type.
 *
 */
typedef struct
{
	uint8_t bRange      : 1;        /*!< 1: high range, 0: low range */
	uint8_t bGain       : 1;        /*!< 1: high gain, 0: low gain */
	uint8_t bEnable     : 1;        /*!< 1: enable XOSC, 0: disable XOSC */
	uint8_t bStopEnable : 1;        /*!< 1: stop enable, 0: stop disable */
	uint8_t bIsCryst    : 1;        /*!< 1: crystal input, 0: active clock input */
	uint8_t bWaitInit   : 1;        /*!< 1: wait till XOSC init done, 0: no wait */
} OSC_ConfigType, *OSC_ConfigPtr;
/*! @} End of osc_config_type                                                    					*/


/* ICS configuration structure
 */
/******************************************************************************
* define ICS configuration structure
*
*//*! @addtogroup ics_config_type
* @{
*******************************************************************************/
 
/*!
 * @brief ICS configuration type.
 * @see   OSC_ConfigType
 */
typedef struct
{
   uint8_t    u8ClkMode;        /*!< clock mode to be switched */
   uint8_t    bLPEnable;        /*!< low power mode enable */
   uint32_t   u32ClkFreq;       /*!< reference clock frequency in KHz; use value 32 for 31.25KHz to 39.0625KHz */  
   OSC_ConfigType  oscConfig;   /*!< OSC configuration */
} ICS_ConfigType ;

/*! @} End of ics_config_type                                                    					*/


   
/******************************************************************************
* Global variables
******************************************************************************/


/******************************************************************************
* define ICS API list
*
*//*! @addtogroup ics_api_list
* @{
*******************************************************************************/

/*!
 * inline functions
 */
/*****************************************************************************//*!
*
* @brief enable interrupt.
*        
* @param   none
*
* @return none
* @ Pass/ Fail criteria: none
* @see    ICS_DisableInt
*****************************************************************************/
__STATIC_INLINE void ICS_EnableInt(void)
{
    ICS->C4 |= (ICS_C4_LOLIE_MASK);    
}

/*****************************************************************************//*!
*
* @brief disable interrupt.
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
* @see    ICS_EnableInt
*****************************************************************************/
__STATIC_INLINE void ICS_DisableInt(void)
{
    ICS->C4 &= ~(ICS_C4_LOLIE_MASK);    
}

/*****************************************************************************//*!
*
* @brief enable clock monitor.
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
* @see    ICS_DisableClockMonitor
*****************************************************************************/
__STATIC_INLINE void ICS_EnableClockMonitor(void)
{
    ICS->C4 |= (ICS_C4_CME_MASK);    
}

/*****************************************************************************//*!
*
* @brief disable clock monitor.
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
* @see    ICS_EnableClockMonitor
*****************************************************************************/
__STATIC_INLINE void ICS_DisableClockMonitor(void)
{
    ICS->C4 &= ~(ICS_C4_CME_MASK);    
}

/*****************************************************************************//*!
   *
   * @brief set bus divider BDIV bit field.
   *        
   * @param[in] busDivide   -- BDIV value
   * @return  depends on commands
   * @ Pass/ Fail criteria:  
   *****************************************************************************/
__STATIC_INLINE void ICS_SetBusDivider(uint8_t u8BusDivide)
{
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(u8BusDivide);
}
/*! @} End of ics_api_list                                                    					*/


/******************************************************************************
* define OSC API list
*
*//*! @addtogroup osc_api_list
* @{
*******************************************************************************/


/*****************************************************************************//*!
*
* @brief enable OSC.
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
__STATIC_INLINE void OSC_Enable(void)
{
    OSC->CR |= (OSC_CR_OSCEN_MASK);    
}

/*****************************************************************************//*!
*
* @brief disable OSC.
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
__STATIC_INLINE void OSC_Disable(void)
{
    OSC->CR &= ~(OSC_CR_OSCEN_MASK);    
}


/*****************************************************************************//*!
*
* @brief set low range of oscillator.
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
__STATIC_INLINE void OSC_SetLowRange(void)
{
    OSC->CR &= ~(OSC_CR_RANGE_MASK);    
}

/*!***************************************************************************//*!
+FUNCTION----------------------------------------------------------------
* @function name: OSC_SetHighRange
*
* @brief set high range of oscillator
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
__STATIC_INLINE void OSC_SetHighRange(void)
{
    OSC->CR |= (OSC_CR_RANGE_MASK);    
}


/*****************************************************************************//*!
*
* @brief set high gain of oscillator.
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
__STATIC_INLINE void OSC_SetHighGain(void)
{
    OSC->CR |= (OSC_CR_HGO_MASK);    
}

/*****************************************************************************//*!
*
* @brief set low gain of oscillator.
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
__STATIC_INLINE void OSC_SetLowGain(void)
{
    OSC->CR &= ~(OSC_CR_HGO_MASK);    
}


/*****************************************************************************//*!
*
* @brief select crystal as clock source.
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
__STATIC_INLINE void OSC_SelectCrystal(void)
{
    OSC->CR |= (OSC_CR_OSCOS_MASK);    
}


/*****************************************************************************//*!
*
* @brief select active clock as clock source
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
__STATIC_INLINE void OSC_SelectClock(void)
{
    OSC->CR &= ~(OSC_CR_OSCOS_MASK);    
}

/*****************************************************************************//*!
*
* @brief enable OSC in stop mode.
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
__STATIC_INLINE void OSC_ActiveInStop(void)
{
    OSC->CR |= (OSC_CR_OSCSTEN_MASK);    
}

/*****************************************************************************//*!
*
* @brief disable OSC in stop mode.
*        
* @param   none
*
* @return none
*
* @ Pass/ Fail criteria: none
*****************************************************************************/
__STATIC_INLINE void OSC_InactiveInStop(void)
{
    OSC->CR &= ~(OSC_CR_OSCSTEN_MASK);    
}

/*! @} End of osc_api_list                                                    					*/


/******************************************************************************
* Global functions
******************************************************************************/

void ICS_Init(ICS_ConfigType *pConfig);
void ICS_DeInit(void);
void ICS_SetClkDivider(uint32_t u32ClkFreqKHz);
void ICS_Trim(uint16 u16TrimValue);
void OSC_Init(OSC_ConfigType *pConfig);
void OSC_DeInit(void);

/* inline functions */
void ICS_DisableClockMonitor(void);
void ICS_DisableInt(void);
void ICS_EnableClockMonitor(void);
void ICS_EnableInt(void);
void ICS_SetBusDivider(uint8_t u8BusDivide);
void OSC_ActiveInStop(void);
void OSC_Enable(void);
void OSC_Disable(void);
void OSC_InactiveInStop(void);
void OSC_SelectClock(void);
void OSC_SelectCrystal(void);
void OSC_SetHighGain(void);
void OSC_SetHighRange(void);
void OSC_SetLowGain(void);
void OSC_SetLowRange(void);

/* do not touch the following functions */
void FEI_to_FEE(ICS_ConfigType *pConfig);
void FEI_to_FBI(ICS_ConfigType *pConfig);
void FEI_to_FBE(ICS_ConfigType *pConfig);
void FEE_to_FBI(ICS_ConfigType *pConfig);
void FEE_to_FEI(ICS_ConfigType *pConfig);
void FEE_to_FBE(ICS_ConfigType *pConfig);
void FBE_to_FEE(ICS_ConfigType *pConfig);
void FBE_to_FEI(ICS_ConfigType *pConfig);
void FBE_to_FBI(ICS_ConfigType *pConfig);
void FBE_to_FBELP(ICS_ConfigType *pConfig);
void FBI_to_FEI(ICS_ConfigType *pConfig);
void FBI_to_FBE(ICS_ConfigType *pConfig);
void FBI_to_FEE(ICS_ConfigType *pConfig);
void FBI_to_FBILP(ICS_ConfigType *pConfig);
void FBILP_to_FBI(ICS_ConfigType *pConfig);
void FBELP_to_FBE(ICS_ConfigType *pConfig);
void FEI_to_FBE_OSC(ICS_ConfigType *pConfig);
void FEI_to_FEE_OSC(ICS_ConfigType *pConfig);
#ifdef __cplusplus
}
#endif
#endif /* ICS_H_ */
