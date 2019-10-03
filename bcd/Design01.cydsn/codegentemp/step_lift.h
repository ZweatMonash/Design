/*******************************************************************************
* File Name: step_lift.h  
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

#if !defined(CY_PINS_step_lift_H) /* Pins step_lift_H */
#define CY_PINS_step_lift_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "step_lift_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 step_lift__PORT == 15 && ((step_lift__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    step_lift_Write(uint8 value);
void    step_lift_SetDriveMode(uint8 mode);
uint8   step_lift_ReadDataReg(void);
uint8   step_lift_Read(void);
void    step_lift_SetInterruptMode(uint16 position, uint16 mode);
uint8   step_lift_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the step_lift_SetDriveMode() function.
     *  @{
     */
        #define step_lift_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define step_lift_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define step_lift_DM_RES_UP          PIN_DM_RES_UP
        #define step_lift_DM_RES_DWN         PIN_DM_RES_DWN
        #define step_lift_DM_OD_LO           PIN_DM_OD_LO
        #define step_lift_DM_OD_HI           PIN_DM_OD_HI
        #define step_lift_DM_STRONG          PIN_DM_STRONG
        #define step_lift_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define step_lift_MASK               step_lift__MASK
#define step_lift_SHIFT              step_lift__SHIFT
#define step_lift_WIDTH              1u

/* Interrupt constants */
#if defined(step_lift__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in step_lift_SetInterruptMode() function.
     *  @{
     */
        #define step_lift_INTR_NONE      (uint16)(0x0000u)
        #define step_lift_INTR_RISING    (uint16)(0x0001u)
        #define step_lift_INTR_FALLING   (uint16)(0x0002u)
        #define step_lift_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define step_lift_INTR_MASK      (0x01u) 
#endif /* (step_lift__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define step_lift_PS                     (* (reg8 *) step_lift__PS)
/* Data Register */
#define step_lift_DR                     (* (reg8 *) step_lift__DR)
/* Port Number */
#define step_lift_PRT_NUM                (* (reg8 *) step_lift__PRT) 
/* Connect to Analog Globals */                                                  
#define step_lift_AG                     (* (reg8 *) step_lift__AG)                       
/* Analog MUX bux enable */
#define step_lift_AMUX                   (* (reg8 *) step_lift__AMUX) 
/* Bidirectional Enable */                                                        
#define step_lift_BIE                    (* (reg8 *) step_lift__BIE)
/* Bit-mask for Aliased Register Access */
#define step_lift_BIT_MASK               (* (reg8 *) step_lift__BIT_MASK)
/* Bypass Enable */
#define step_lift_BYP                    (* (reg8 *) step_lift__BYP)
/* Port wide control signals */                                                   
#define step_lift_CTL                    (* (reg8 *) step_lift__CTL)
/* Drive Modes */
#define step_lift_DM0                    (* (reg8 *) step_lift__DM0) 
#define step_lift_DM1                    (* (reg8 *) step_lift__DM1)
#define step_lift_DM2                    (* (reg8 *) step_lift__DM2) 
/* Input Buffer Disable Override */
#define step_lift_INP_DIS                (* (reg8 *) step_lift__INP_DIS)
/* LCD Common or Segment Drive */
#define step_lift_LCD_COM_SEG            (* (reg8 *) step_lift__LCD_COM_SEG)
/* Enable Segment LCD */
#define step_lift_LCD_EN                 (* (reg8 *) step_lift__LCD_EN)
/* Slew Rate Control */
#define step_lift_SLW                    (* (reg8 *) step_lift__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define step_lift_PRTDSI__CAPS_SEL       (* (reg8 *) step_lift__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define step_lift_PRTDSI__DBL_SYNC_IN    (* (reg8 *) step_lift__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define step_lift_PRTDSI__OE_SEL0        (* (reg8 *) step_lift__PRTDSI__OE_SEL0) 
#define step_lift_PRTDSI__OE_SEL1        (* (reg8 *) step_lift__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define step_lift_PRTDSI__OUT_SEL0       (* (reg8 *) step_lift__PRTDSI__OUT_SEL0) 
#define step_lift_PRTDSI__OUT_SEL1       (* (reg8 *) step_lift__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define step_lift_PRTDSI__SYNC_OUT       (* (reg8 *) step_lift__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(step_lift__SIO_CFG)
    #define step_lift_SIO_HYST_EN        (* (reg8 *) step_lift__SIO_HYST_EN)
    #define step_lift_SIO_REG_HIFREQ     (* (reg8 *) step_lift__SIO_REG_HIFREQ)
    #define step_lift_SIO_CFG            (* (reg8 *) step_lift__SIO_CFG)
    #define step_lift_SIO_DIFF           (* (reg8 *) step_lift__SIO_DIFF)
#endif /* (step_lift__SIO_CFG) */

/* Interrupt Registers */
#if defined(step_lift__INTSTAT)
    #define step_lift_INTSTAT            (* (reg8 *) step_lift__INTSTAT)
    #define step_lift_SNAP               (* (reg8 *) step_lift__SNAP)
    
	#define step_lift_0_INTTYPE_REG 		(* (reg8 *) step_lift__0__INTTYPE)
#endif /* (step_lift__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_step_lift_H */


/* [] END OF FILE */
