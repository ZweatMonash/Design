/*******************************************************************************
* File Name: Trigger_fr.h  
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

#if !defined(CY_PINS_Trigger_fr_H) /* Pins Trigger_fr_H */
#define CY_PINS_Trigger_fr_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Trigger_fr_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Trigger_fr__PORT == 15 && ((Trigger_fr__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Trigger_fr_Write(uint8 value);
void    Trigger_fr_SetDriveMode(uint8 mode);
uint8   Trigger_fr_ReadDataReg(void);
uint8   Trigger_fr_Read(void);
void    Trigger_fr_SetInterruptMode(uint16 position, uint16 mode);
uint8   Trigger_fr_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Trigger_fr_SetDriveMode() function.
     *  @{
     */
        #define Trigger_fr_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Trigger_fr_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Trigger_fr_DM_RES_UP          PIN_DM_RES_UP
        #define Trigger_fr_DM_RES_DWN         PIN_DM_RES_DWN
        #define Trigger_fr_DM_OD_LO           PIN_DM_OD_LO
        #define Trigger_fr_DM_OD_HI           PIN_DM_OD_HI
        #define Trigger_fr_DM_STRONG          PIN_DM_STRONG
        #define Trigger_fr_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Trigger_fr_MASK               Trigger_fr__MASK
#define Trigger_fr_SHIFT              Trigger_fr__SHIFT
#define Trigger_fr_WIDTH              1u

/* Interrupt constants */
#if defined(Trigger_fr__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Trigger_fr_SetInterruptMode() function.
     *  @{
     */
        #define Trigger_fr_INTR_NONE      (uint16)(0x0000u)
        #define Trigger_fr_INTR_RISING    (uint16)(0x0001u)
        #define Trigger_fr_INTR_FALLING   (uint16)(0x0002u)
        #define Trigger_fr_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Trigger_fr_INTR_MASK      (0x01u) 
#endif /* (Trigger_fr__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Trigger_fr_PS                     (* (reg8 *) Trigger_fr__PS)
/* Data Register */
#define Trigger_fr_DR                     (* (reg8 *) Trigger_fr__DR)
/* Port Number */
#define Trigger_fr_PRT_NUM                (* (reg8 *) Trigger_fr__PRT) 
/* Connect to Analog Globals */                                                  
#define Trigger_fr_AG                     (* (reg8 *) Trigger_fr__AG)                       
/* Analog MUX bux enable */
#define Trigger_fr_AMUX                   (* (reg8 *) Trigger_fr__AMUX) 
/* Bidirectional Enable */                                                        
#define Trigger_fr_BIE                    (* (reg8 *) Trigger_fr__BIE)
/* Bit-mask for Aliased Register Access */
#define Trigger_fr_BIT_MASK               (* (reg8 *) Trigger_fr__BIT_MASK)
/* Bypass Enable */
#define Trigger_fr_BYP                    (* (reg8 *) Trigger_fr__BYP)
/* Port wide control signals */                                                   
#define Trigger_fr_CTL                    (* (reg8 *) Trigger_fr__CTL)
/* Drive Modes */
#define Trigger_fr_DM0                    (* (reg8 *) Trigger_fr__DM0) 
#define Trigger_fr_DM1                    (* (reg8 *) Trigger_fr__DM1)
#define Trigger_fr_DM2                    (* (reg8 *) Trigger_fr__DM2) 
/* Input Buffer Disable Override */
#define Trigger_fr_INP_DIS                (* (reg8 *) Trigger_fr__INP_DIS)
/* LCD Common or Segment Drive */
#define Trigger_fr_LCD_COM_SEG            (* (reg8 *) Trigger_fr__LCD_COM_SEG)
/* Enable Segment LCD */
#define Trigger_fr_LCD_EN                 (* (reg8 *) Trigger_fr__LCD_EN)
/* Slew Rate Control */
#define Trigger_fr_SLW                    (* (reg8 *) Trigger_fr__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Trigger_fr_PRTDSI__CAPS_SEL       (* (reg8 *) Trigger_fr__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Trigger_fr_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Trigger_fr__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Trigger_fr_PRTDSI__OE_SEL0        (* (reg8 *) Trigger_fr__PRTDSI__OE_SEL0) 
#define Trigger_fr_PRTDSI__OE_SEL1        (* (reg8 *) Trigger_fr__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Trigger_fr_PRTDSI__OUT_SEL0       (* (reg8 *) Trigger_fr__PRTDSI__OUT_SEL0) 
#define Trigger_fr_PRTDSI__OUT_SEL1       (* (reg8 *) Trigger_fr__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Trigger_fr_PRTDSI__SYNC_OUT       (* (reg8 *) Trigger_fr__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Trigger_fr__SIO_CFG)
    #define Trigger_fr_SIO_HYST_EN        (* (reg8 *) Trigger_fr__SIO_HYST_EN)
    #define Trigger_fr_SIO_REG_HIFREQ     (* (reg8 *) Trigger_fr__SIO_REG_HIFREQ)
    #define Trigger_fr_SIO_CFG            (* (reg8 *) Trigger_fr__SIO_CFG)
    #define Trigger_fr_SIO_DIFF           (* (reg8 *) Trigger_fr__SIO_DIFF)
#endif /* (Trigger_fr__SIO_CFG) */

/* Interrupt Registers */
#if defined(Trigger_fr__INTSTAT)
    #define Trigger_fr_INTSTAT            (* (reg8 *) Trigger_fr__INTSTAT)
    #define Trigger_fr_SNAP               (* (reg8 *) Trigger_fr__SNAP)
    
	#define Trigger_fr_0_INTTYPE_REG 		(* (reg8 *) Trigger_fr__0__INTTYPE)
#endif /* (Trigger_fr__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Trigger_fr_H */


/* [] END OF FILE */
