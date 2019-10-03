/*******************************************************************************
* File Name: triggerr1.h  
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

#if !defined(CY_PINS_triggerr1_H) /* Pins triggerr1_H */
#define CY_PINS_triggerr1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "triggerr1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 triggerr1__PORT == 15 && ((triggerr1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    triggerr1_Write(uint8 value);
void    triggerr1_SetDriveMode(uint8 mode);
uint8   triggerr1_ReadDataReg(void);
uint8   triggerr1_Read(void);
void    triggerr1_SetInterruptMode(uint16 position, uint16 mode);
uint8   triggerr1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the triggerr1_SetDriveMode() function.
     *  @{
     */
        #define triggerr1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define triggerr1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define triggerr1_DM_RES_UP          PIN_DM_RES_UP
        #define triggerr1_DM_RES_DWN         PIN_DM_RES_DWN
        #define triggerr1_DM_OD_LO           PIN_DM_OD_LO
        #define triggerr1_DM_OD_HI           PIN_DM_OD_HI
        #define triggerr1_DM_STRONG          PIN_DM_STRONG
        #define triggerr1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define triggerr1_MASK               triggerr1__MASK
#define triggerr1_SHIFT              triggerr1__SHIFT
#define triggerr1_WIDTH              1u

/* Interrupt constants */
#if defined(triggerr1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in triggerr1_SetInterruptMode() function.
     *  @{
     */
        #define triggerr1_INTR_NONE      (uint16)(0x0000u)
        #define triggerr1_INTR_RISING    (uint16)(0x0001u)
        #define triggerr1_INTR_FALLING   (uint16)(0x0002u)
        #define triggerr1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define triggerr1_INTR_MASK      (0x01u) 
#endif /* (triggerr1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define triggerr1_PS                     (* (reg8 *) triggerr1__PS)
/* Data Register */
#define triggerr1_DR                     (* (reg8 *) triggerr1__DR)
/* Port Number */
#define triggerr1_PRT_NUM                (* (reg8 *) triggerr1__PRT) 
/* Connect to Analog Globals */                                                  
#define triggerr1_AG                     (* (reg8 *) triggerr1__AG)                       
/* Analog MUX bux enable */
#define triggerr1_AMUX                   (* (reg8 *) triggerr1__AMUX) 
/* Bidirectional Enable */                                                        
#define triggerr1_BIE                    (* (reg8 *) triggerr1__BIE)
/* Bit-mask for Aliased Register Access */
#define triggerr1_BIT_MASK               (* (reg8 *) triggerr1__BIT_MASK)
/* Bypass Enable */
#define triggerr1_BYP                    (* (reg8 *) triggerr1__BYP)
/* Port wide control signals */                                                   
#define triggerr1_CTL                    (* (reg8 *) triggerr1__CTL)
/* Drive Modes */
#define triggerr1_DM0                    (* (reg8 *) triggerr1__DM0) 
#define triggerr1_DM1                    (* (reg8 *) triggerr1__DM1)
#define triggerr1_DM2                    (* (reg8 *) triggerr1__DM2) 
/* Input Buffer Disable Override */
#define triggerr1_INP_DIS                (* (reg8 *) triggerr1__INP_DIS)
/* LCD Common or Segment Drive */
#define triggerr1_LCD_COM_SEG            (* (reg8 *) triggerr1__LCD_COM_SEG)
/* Enable Segment LCD */
#define triggerr1_LCD_EN                 (* (reg8 *) triggerr1__LCD_EN)
/* Slew Rate Control */
#define triggerr1_SLW                    (* (reg8 *) triggerr1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define triggerr1_PRTDSI__CAPS_SEL       (* (reg8 *) triggerr1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define triggerr1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) triggerr1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define triggerr1_PRTDSI__OE_SEL0        (* (reg8 *) triggerr1__PRTDSI__OE_SEL0) 
#define triggerr1_PRTDSI__OE_SEL1        (* (reg8 *) triggerr1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define triggerr1_PRTDSI__OUT_SEL0       (* (reg8 *) triggerr1__PRTDSI__OUT_SEL0) 
#define triggerr1_PRTDSI__OUT_SEL1       (* (reg8 *) triggerr1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define triggerr1_PRTDSI__SYNC_OUT       (* (reg8 *) triggerr1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(triggerr1__SIO_CFG)
    #define triggerr1_SIO_HYST_EN        (* (reg8 *) triggerr1__SIO_HYST_EN)
    #define triggerr1_SIO_REG_HIFREQ     (* (reg8 *) triggerr1__SIO_REG_HIFREQ)
    #define triggerr1_SIO_CFG            (* (reg8 *) triggerr1__SIO_CFG)
    #define triggerr1_SIO_DIFF           (* (reg8 *) triggerr1__SIO_DIFF)
#endif /* (triggerr1__SIO_CFG) */

/* Interrupt Registers */
#if defined(triggerr1__INTSTAT)
    #define triggerr1_INTSTAT            (* (reg8 *) triggerr1__INTSTAT)
    #define triggerr1_SNAP               (* (reg8 *) triggerr1__SNAP)
    
	#define triggerr1_0_INTTYPE_REG 		(* (reg8 *) triggerr1__0__INTTYPE)
#endif /* (triggerr1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_triggerr1_H */


/* [] END OF FILE */
