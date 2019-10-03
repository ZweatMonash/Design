/*******************************************************************************
* File Name: triggerr2.h  
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

#if !defined(CY_PINS_triggerr2_H) /* Pins triggerr2_H */
#define CY_PINS_triggerr2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "triggerr2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 triggerr2__PORT == 15 && ((triggerr2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    triggerr2_Write(uint8 value);
void    triggerr2_SetDriveMode(uint8 mode);
uint8   triggerr2_ReadDataReg(void);
uint8   triggerr2_Read(void);
void    triggerr2_SetInterruptMode(uint16 position, uint16 mode);
uint8   triggerr2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the triggerr2_SetDriveMode() function.
     *  @{
     */
        #define triggerr2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define triggerr2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define triggerr2_DM_RES_UP          PIN_DM_RES_UP
        #define triggerr2_DM_RES_DWN         PIN_DM_RES_DWN
        #define triggerr2_DM_OD_LO           PIN_DM_OD_LO
        #define triggerr2_DM_OD_HI           PIN_DM_OD_HI
        #define triggerr2_DM_STRONG          PIN_DM_STRONG
        #define triggerr2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define triggerr2_MASK               triggerr2__MASK
#define triggerr2_SHIFT              triggerr2__SHIFT
#define triggerr2_WIDTH              1u

/* Interrupt constants */
#if defined(triggerr2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in triggerr2_SetInterruptMode() function.
     *  @{
     */
        #define triggerr2_INTR_NONE      (uint16)(0x0000u)
        #define triggerr2_INTR_RISING    (uint16)(0x0001u)
        #define triggerr2_INTR_FALLING   (uint16)(0x0002u)
        #define triggerr2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define triggerr2_INTR_MASK      (0x01u) 
#endif /* (triggerr2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define triggerr2_PS                     (* (reg8 *) triggerr2__PS)
/* Data Register */
#define triggerr2_DR                     (* (reg8 *) triggerr2__DR)
/* Port Number */
#define triggerr2_PRT_NUM                (* (reg8 *) triggerr2__PRT) 
/* Connect to Analog Globals */                                                  
#define triggerr2_AG                     (* (reg8 *) triggerr2__AG)                       
/* Analog MUX bux enable */
#define triggerr2_AMUX                   (* (reg8 *) triggerr2__AMUX) 
/* Bidirectional Enable */                                                        
#define triggerr2_BIE                    (* (reg8 *) triggerr2__BIE)
/* Bit-mask for Aliased Register Access */
#define triggerr2_BIT_MASK               (* (reg8 *) triggerr2__BIT_MASK)
/* Bypass Enable */
#define triggerr2_BYP                    (* (reg8 *) triggerr2__BYP)
/* Port wide control signals */                                                   
#define triggerr2_CTL                    (* (reg8 *) triggerr2__CTL)
/* Drive Modes */
#define triggerr2_DM0                    (* (reg8 *) triggerr2__DM0) 
#define triggerr2_DM1                    (* (reg8 *) triggerr2__DM1)
#define triggerr2_DM2                    (* (reg8 *) triggerr2__DM2) 
/* Input Buffer Disable Override */
#define triggerr2_INP_DIS                (* (reg8 *) triggerr2__INP_DIS)
/* LCD Common or Segment Drive */
#define triggerr2_LCD_COM_SEG            (* (reg8 *) triggerr2__LCD_COM_SEG)
/* Enable Segment LCD */
#define triggerr2_LCD_EN                 (* (reg8 *) triggerr2__LCD_EN)
/* Slew Rate Control */
#define triggerr2_SLW                    (* (reg8 *) triggerr2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define triggerr2_PRTDSI__CAPS_SEL       (* (reg8 *) triggerr2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define triggerr2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) triggerr2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define triggerr2_PRTDSI__OE_SEL0        (* (reg8 *) triggerr2__PRTDSI__OE_SEL0) 
#define triggerr2_PRTDSI__OE_SEL1        (* (reg8 *) triggerr2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define triggerr2_PRTDSI__OUT_SEL0       (* (reg8 *) triggerr2__PRTDSI__OUT_SEL0) 
#define triggerr2_PRTDSI__OUT_SEL1       (* (reg8 *) triggerr2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define triggerr2_PRTDSI__SYNC_OUT       (* (reg8 *) triggerr2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(triggerr2__SIO_CFG)
    #define triggerr2_SIO_HYST_EN        (* (reg8 *) triggerr2__SIO_HYST_EN)
    #define triggerr2_SIO_REG_HIFREQ     (* (reg8 *) triggerr2__SIO_REG_HIFREQ)
    #define triggerr2_SIO_CFG            (* (reg8 *) triggerr2__SIO_CFG)
    #define triggerr2_SIO_DIFF           (* (reg8 *) triggerr2__SIO_DIFF)
#endif /* (triggerr2__SIO_CFG) */

/* Interrupt Registers */
#if defined(triggerr2__INTSTAT)
    #define triggerr2_INTSTAT            (* (reg8 *) triggerr2__INTSTAT)
    #define triggerr2_SNAP               (* (reg8 *) triggerr2__SNAP)
    
	#define triggerr2_0_INTTYPE_REG 		(* (reg8 *) triggerr2__0__INTTYPE)
#endif /* (triggerr2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_triggerr2_H */


/* [] END OF FILE */
