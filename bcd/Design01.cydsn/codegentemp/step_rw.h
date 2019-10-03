/*******************************************************************************
* File Name: step_rw.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_step_rw_H) /* Pins step_rw_H */
#define CY_PINS_step_rw_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "step_rw_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 step_rw__PORT == 15 && ((step_rw__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    step_rw_Write(uint8 value);
void    step_rw_SetDriveMode(uint8 mode);
uint8   step_rw_ReadDataReg(void);
uint8   step_rw_Read(void);
void    step_rw_SetInterruptMode(uint16 position, uint16 mode);
uint8   step_rw_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the step_rw_SetDriveMode() function.
     *  @{
     */
        #define step_rw_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define step_rw_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define step_rw_DM_RES_UP          PIN_DM_RES_UP
        #define step_rw_DM_RES_DWN         PIN_DM_RES_DWN
        #define step_rw_DM_OD_LO           PIN_DM_OD_LO
        #define step_rw_DM_OD_HI           PIN_DM_OD_HI
        #define step_rw_DM_STRONG          PIN_DM_STRONG
        #define step_rw_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define step_rw_MASK               step_rw__MASK
#define step_rw_SHIFT              step_rw__SHIFT
#define step_rw_WIDTH              1u

/* Interrupt constants */
#if defined(step_rw__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in step_rw_SetInterruptMode() function.
     *  @{
     */
        #define step_rw_INTR_NONE      (uint16)(0x0000u)
        #define step_rw_INTR_RISING    (uint16)(0x0001u)
        #define step_rw_INTR_FALLING   (uint16)(0x0002u)
        #define step_rw_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define step_rw_INTR_MASK      (0x01u) 
#endif /* (step_rw__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define step_rw_PS                     (* (reg8 *) step_rw__PS)
/* Data Register */
#define step_rw_DR                     (* (reg8 *) step_rw__DR)
/* Port Number */
#define step_rw_PRT_NUM                (* (reg8 *) step_rw__PRT) 
/* Connect to Analog Globals */                                                  
#define step_rw_AG                     (* (reg8 *) step_rw__AG)                       
/* Analog MUX bux enable */
#define step_rw_AMUX                   (* (reg8 *) step_rw__AMUX) 
/* Bidirectional Enable */                                                        
#define step_rw_BIE                    (* (reg8 *) step_rw__BIE)
/* Bit-mask for Aliased Register Access */
#define step_rw_BIT_MASK               (* (reg8 *) step_rw__BIT_MASK)
/* Bypass Enable */
#define step_rw_BYP                    (* (reg8 *) step_rw__BYP)
/* Port wide control signals */                                                   
#define step_rw_CTL                    (* (reg8 *) step_rw__CTL)
/* Drive Modes */
#define step_rw_DM0                    (* (reg8 *) step_rw__DM0) 
#define step_rw_DM1                    (* (reg8 *) step_rw__DM1)
#define step_rw_DM2                    (* (reg8 *) step_rw__DM2) 
/* Input Buffer Disable Override */
#define step_rw_INP_DIS                (* (reg8 *) step_rw__INP_DIS)
/* LCD Common or Segment Drive */
#define step_rw_LCD_COM_SEG            (* (reg8 *) step_rw__LCD_COM_SEG)
/* Enable Segment LCD */
#define step_rw_LCD_EN                 (* (reg8 *) step_rw__LCD_EN)
/* Slew Rate Control */
#define step_rw_SLW                    (* (reg8 *) step_rw__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define step_rw_PRTDSI__CAPS_SEL       (* (reg8 *) step_rw__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define step_rw_PRTDSI__DBL_SYNC_IN    (* (reg8 *) step_rw__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define step_rw_PRTDSI__OE_SEL0        (* (reg8 *) step_rw__PRTDSI__OE_SEL0) 
#define step_rw_PRTDSI__OE_SEL1        (* (reg8 *) step_rw__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define step_rw_PRTDSI__OUT_SEL0       (* (reg8 *) step_rw__PRTDSI__OUT_SEL0) 
#define step_rw_PRTDSI__OUT_SEL1       (* (reg8 *) step_rw__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define step_rw_PRTDSI__SYNC_OUT       (* (reg8 *) step_rw__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(step_rw__SIO_CFG)
    #define step_rw_SIO_HYST_EN        (* (reg8 *) step_rw__SIO_HYST_EN)
    #define step_rw_SIO_REG_HIFREQ     (* (reg8 *) step_rw__SIO_REG_HIFREQ)
    #define step_rw_SIO_CFG            (* (reg8 *) step_rw__SIO_CFG)
    #define step_rw_SIO_DIFF           (* (reg8 *) step_rw__SIO_DIFF)
#endif /* (step_rw__SIO_CFG) */

/* Interrupt Registers */
#if defined(step_rw__INTSTAT)
    #define step_rw_INTSTAT            (* (reg8 *) step_rw__INTSTAT)
    #define step_rw_SNAP               (* (reg8 *) step_rw__SNAP)
    
	#define step_rw_0_INTTYPE_REG 		(* (reg8 *) step_rw__0__INTTYPE)
#endif /* (step_rw__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_step_rw_H */


/* [] END OF FILE */
