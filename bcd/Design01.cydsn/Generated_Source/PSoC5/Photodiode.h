/*******************************************************************************
* File Name: Photodiode.h  
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

#if !defined(CY_PINS_Photodiode_H) /* Pins Photodiode_H */
#define CY_PINS_Photodiode_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Photodiode_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Photodiode__PORT == 15 && ((Photodiode__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Photodiode_Write(uint8 value);
void    Photodiode_SetDriveMode(uint8 mode);
uint8   Photodiode_ReadDataReg(void);
uint8   Photodiode_Read(void);
void    Photodiode_SetInterruptMode(uint16 position, uint16 mode);
uint8   Photodiode_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Photodiode_SetDriveMode() function.
     *  @{
     */
        #define Photodiode_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Photodiode_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Photodiode_DM_RES_UP          PIN_DM_RES_UP
        #define Photodiode_DM_RES_DWN         PIN_DM_RES_DWN
        #define Photodiode_DM_OD_LO           PIN_DM_OD_LO
        #define Photodiode_DM_OD_HI           PIN_DM_OD_HI
        #define Photodiode_DM_STRONG          PIN_DM_STRONG
        #define Photodiode_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Photodiode_MASK               Photodiode__MASK
#define Photodiode_SHIFT              Photodiode__SHIFT
#define Photodiode_WIDTH              1u

/* Interrupt constants */
#if defined(Photodiode__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Photodiode_SetInterruptMode() function.
     *  @{
     */
        #define Photodiode_INTR_NONE      (uint16)(0x0000u)
        #define Photodiode_INTR_RISING    (uint16)(0x0001u)
        #define Photodiode_INTR_FALLING   (uint16)(0x0002u)
        #define Photodiode_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Photodiode_INTR_MASK      (0x01u) 
#endif /* (Photodiode__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Photodiode_PS                     (* (reg8 *) Photodiode__PS)
/* Data Register */
#define Photodiode_DR                     (* (reg8 *) Photodiode__DR)
/* Port Number */
#define Photodiode_PRT_NUM                (* (reg8 *) Photodiode__PRT) 
/* Connect to Analog Globals */                                                  
#define Photodiode_AG                     (* (reg8 *) Photodiode__AG)                       
/* Analog MUX bux enable */
#define Photodiode_AMUX                   (* (reg8 *) Photodiode__AMUX) 
/* Bidirectional Enable */                                                        
#define Photodiode_BIE                    (* (reg8 *) Photodiode__BIE)
/* Bit-mask for Aliased Register Access */
#define Photodiode_BIT_MASK               (* (reg8 *) Photodiode__BIT_MASK)
/* Bypass Enable */
#define Photodiode_BYP                    (* (reg8 *) Photodiode__BYP)
/* Port wide control signals */                                                   
#define Photodiode_CTL                    (* (reg8 *) Photodiode__CTL)
/* Drive Modes */
#define Photodiode_DM0                    (* (reg8 *) Photodiode__DM0) 
#define Photodiode_DM1                    (* (reg8 *) Photodiode__DM1)
#define Photodiode_DM2                    (* (reg8 *) Photodiode__DM2) 
/* Input Buffer Disable Override */
#define Photodiode_INP_DIS                (* (reg8 *) Photodiode__INP_DIS)
/* LCD Common or Segment Drive */
#define Photodiode_LCD_COM_SEG            (* (reg8 *) Photodiode__LCD_COM_SEG)
/* Enable Segment LCD */
#define Photodiode_LCD_EN                 (* (reg8 *) Photodiode__LCD_EN)
/* Slew Rate Control */
#define Photodiode_SLW                    (* (reg8 *) Photodiode__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Photodiode_PRTDSI__CAPS_SEL       (* (reg8 *) Photodiode__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Photodiode_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Photodiode__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Photodiode_PRTDSI__OE_SEL0        (* (reg8 *) Photodiode__PRTDSI__OE_SEL0) 
#define Photodiode_PRTDSI__OE_SEL1        (* (reg8 *) Photodiode__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Photodiode_PRTDSI__OUT_SEL0       (* (reg8 *) Photodiode__PRTDSI__OUT_SEL0) 
#define Photodiode_PRTDSI__OUT_SEL1       (* (reg8 *) Photodiode__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Photodiode_PRTDSI__SYNC_OUT       (* (reg8 *) Photodiode__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Photodiode__SIO_CFG)
    #define Photodiode_SIO_HYST_EN        (* (reg8 *) Photodiode__SIO_HYST_EN)
    #define Photodiode_SIO_REG_HIFREQ     (* (reg8 *) Photodiode__SIO_REG_HIFREQ)
    #define Photodiode_SIO_CFG            (* (reg8 *) Photodiode__SIO_CFG)
    #define Photodiode_SIO_DIFF           (* (reg8 *) Photodiode__SIO_DIFF)
#endif /* (Photodiode__SIO_CFG) */

/* Interrupt Registers */
#if defined(Photodiode__INTSTAT)
    #define Photodiode_INTSTAT            (* (reg8 *) Photodiode__INTSTAT)
    #define Photodiode_SNAP               (* (reg8 *) Photodiode__SNAP)
    
	#define Photodiode_0_INTTYPE_REG 		(* (reg8 *) Photodiode__0__INTTYPE)
#endif /* (Photodiode__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Photodiode_H */


/* [] END OF FILE */
