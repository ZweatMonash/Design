/*******************************************************************************
* File Name: BCD_Driver_ClkInternal.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_BCD_Driver_ClkInternal_H)
#define CY_CLOCK_BCD_Driver_ClkInternal_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void BCD_Driver_ClkInternal_Start(void) ;
void BCD_Driver_ClkInternal_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void BCD_Driver_ClkInternal_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void BCD_Driver_ClkInternal_StandbyPower(uint8 state) ;
void BCD_Driver_ClkInternal_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 BCD_Driver_ClkInternal_GetDividerRegister(void) ;
void BCD_Driver_ClkInternal_SetModeRegister(uint8 modeBitMask) ;
void BCD_Driver_ClkInternal_ClearModeRegister(uint8 modeBitMask) ;
uint8 BCD_Driver_ClkInternal_GetModeRegister(void) ;
void BCD_Driver_ClkInternal_SetSourceRegister(uint8 clkSource) ;
uint8 BCD_Driver_ClkInternal_GetSourceRegister(void) ;
#if defined(BCD_Driver_ClkInternal__CFG3)
void BCD_Driver_ClkInternal_SetPhaseRegister(uint8 clkPhase) ;
uint8 BCD_Driver_ClkInternal_GetPhaseRegister(void) ;
#endif /* defined(BCD_Driver_ClkInternal__CFG3) */

#define BCD_Driver_ClkInternal_Enable()                       BCD_Driver_ClkInternal_Start()
#define BCD_Driver_ClkInternal_Disable()                      BCD_Driver_ClkInternal_Stop()
#define BCD_Driver_ClkInternal_SetDivider(clkDivider)         BCD_Driver_ClkInternal_SetDividerRegister(clkDivider, 1u)
#define BCD_Driver_ClkInternal_SetDividerValue(clkDivider)    BCD_Driver_ClkInternal_SetDividerRegister((clkDivider) - 1u, 1u)
#define BCD_Driver_ClkInternal_SetMode(clkMode)               BCD_Driver_ClkInternal_SetModeRegister(clkMode)
#define BCD_Driver_ClkInternal_SetSource(clkSource)           BCD_Driver_ClkInternal_SetSourceRegister(clkSource)
#if defined(BCD_Driver_ClkInternal__CFG3)
#define BCD_Driver_ClkInternal_SetPhase(clkPhase)             BCD_Driver_ClkInternal_SetPhaseRegister(clkPhase)
#define BCD_Driver_ClkInternal_SetPhaseValue(clkPhase)        BCD_Driver_ClkInternal_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(BCD_Driver_ClkInternal__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define BCD_Driver_ClkInternal_CLKEN              (* (reg8 *) BCD_Driver_ClkInternal__PM_ACT_CFG)
#define BCD_Driver_ClkInternal_CLKEN_PTR          ((reg8 *) BCD_Driver_ClkInternal__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define BCD_Driver_ClkInternal_CLKSTBY            (* (reg8 *) BCD_Driver_ClkInternal__PM_STBY_CFG)
#define BCD_Driver_ClkInternal_CLKSTBY_PTR        ((reg8 *) BCD_Driver_ClkInternal__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define BCD_Driver_ClkInternal_DIV_LSB            (* (reg8 *) BCD_Driver_ClkInternal__CFG0)
#define BCD_Driver_ClkInternal_DIV_LSB_PTR        ((reg8 *) BCD_Driver_ClkInternal__CFG0)
#define BCD_Driver_ClkInternal_DIV_PTR            ((reg16 *) BCD_Driver_ClkInternal__CFG0)

/* Clock MSB divider configuration register. */
#define BCD_Driver_ClkInternal_DIV_MSB            (* (reg8 *) BCD_Driver_ClkInternal__CFG1)
#define BCD_Driver_ClkInternal_DIV_MSB_PTR        ((reg8 *) BCD_Driver_ClkInternal__CFG1)

/* Mode and source configuration register */
#define BCD_Driver_ClkInternal_MOD_SRC            (* (reg8 *) BCD_Driver_ClkInternal__CFG2)
#define BCD_Driver_ClkInternal_MOD_SRC_PTR        ((reg8 *) BCD_Driver_ClkInternal__CFG2)

#if defined(BCD_Driver_ClkInternal__CFG3)
/* Analog clock phase configuration register */
#define BCD_Driver_ClkInternal_PHASE              (* (reg8 *) BCD_Driver_ClkInternal__CFG3)
#define BCD_Driver_ClkInternal_PHASE_PTR          ((reg8 *) BCD_Driver_ClkInternal__CFG3)
#endif /* defined(BCD_Driver_ClkInternal__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define BCD_Driver_ClkInternal_CLKEN_MASK         BCD_Driver_ClkInternal__PM_ACT_MSK
#define BCD_Driver_ClkInternal_CLKSTBY_MASK       BCD_Driver_ClkInternal__PM_STBY_MSK

/* CFG2 field masks */
#define BCD_Driver_ClkInternal_SRC_SEL_MSK        BCD_Driver_ClkInternal__CFG2_SRC_SEL_MASK
#define BCD_Driver_ClkInternal_MODE_MASK          (~(BCD_Driver_ClkInternal_SRC_SEL_MSK))

#if defined(BCD_Driver_ClkInternal__CFG3)
/* CFG3 phase mask */
#define BCD_Driver_ClkInternal_PHASE_MASK         BCD_Driver_ClkInternal__CFG3_PHASE_DLY_MASK
#endif /* defined(BCD_Driver_ClkInternal__CFG3) */

#endif /* CY_CLOCK_BCD_Driver_ClkInternal_H */


/* [] END OF FILE */
