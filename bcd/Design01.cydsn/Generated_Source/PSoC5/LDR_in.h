/*******************************************************************************
* File Name: LDR_in.h  
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

#if !defined(CY_PINS_LDR_in_H) /* Pins LDR_in_H */
#define CY_PINS_LDR_in_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LDR_in_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LDR_in__PORT == 15 && ((LDR_in__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LDR_in_Write(uint8 value);
void    LDR_in_SetDriveMode(uint8 mode);
uint8   LDR_in_ReadDataReg(void);
uint8   LDR_in_Read(void);
void    LDR_in_SetInterruptMode(uint16 position, uint16 mode);
uint8   LDR_in_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LDR_in_SetDriveMode() function.
     *  @{
     */
        #define LDR_in_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LDR_in_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LDR_in_DM_RES_UP          PIN_DM_RES_UP
        #define LDR_in_DM_RES_DWN         PIN_DM_RES_DWN
        #define LDR_in_DM_OD_LO           PIN_DM_OD_LO
        #define LDR_in_DM_OD_HI           PIN_DM_OD_HI
        #define LDR_in_DM_STRONG          PIN_DM_STRONG
        #define LDR_in_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LDR_in_MASK               LDR_in__MASK
#define LDR_in_SHIFT              LDR_in__SHIFT
#define LDR_in_WIDTH              1u

/* Interrupt constants */
#if defined(LDR_in__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LDR_in_SetInterruptMode() function.
     *  @{
     */
        #define LDR_in_INTR_NONE      (uint16)(0x0000u)
        #define LDR_in_INTR_RISING    (uint16)(0x0001u)
        #define LDR_in_INTR_FALLING   (uint16)(0x0002u)
        #define LDR_in_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LDR_in_INTR_MASK      (0x01u) 
#endif /* (LDR_in__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LDR_in_PS                     (* (reg8 *) LDR_in__PS)
/* Data Register */
#define LDR_in_DR                     (* (reg8 *) LDR_in__DR)
/* Port Number */
#define LDR_in_PRT_NUM                (* (reg8 *) LDR_in__PRT) 
/* Connect to Analog Globals */                                                  
#define LDR_in_AG                     (* (reg8 *) LDR_in__AG)                       
/* Analog MUX bux enable */
#define LDR_in_AMUX                   (* (reg8 *) LDR_in__AMUX) 
/* Bidirectional Enable */                                                        
#define LDR_in_BIE                    (* (reg8 *) LDR_in__BIE)
/* Bit-mask for Aliased Register Access */
#define LDR_in_BIT_MASK               (* (reg8 *) LDR_in__BIT_MASK)
/* Bypass Enable */
#define LDR_in_BYP                    (* (reg8 *) LDR_in__BYP)
/* Port wide control signals */                                                   
#define LDR_in_CTL                    (* (reg8 *) LDR_in__CTL)
/* Drive Modes */
#define LDR_in_DM0                    (* (reg8 *) LDR_in__DM0) 
#define LDR_in_DM1                    (* (reg8 *) LDR_in__DM1)
#define LDR_in_DM2                    (* (reg8 *) LDR_in__DM2) 
/* Input Buffer Disable Override */
#define LDR_in_INP_DIS                (* (reg8 *) LDR_in__INP_DIS)
/* LCD Common or Segment Drive */
#define LDR_in_LCD_COM_SEG            (* (reg8 *) LDR_in__LCD_COM_SEG)
/* Enable Segment LCD */
#define LDR_in_LCD_EN                 (* (reg8 *) LDR_in__LCD_EN)
/* Slew Rate Control */
#define LDR_in_SLW                    (* (reg8 *) LDR_in__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LDR_in_PRTDSI__CAPS_SEL       (* (reg8 *) LDR_in__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LDR_in_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LDR_in__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LDR_in_PRTDSI__OE_SEL0        (* (reg8 *) LDR_in__PRTDSI__OE_SEL0) 
#define LDR_in_PRTDSI__OE_SEL1        (* (reg8 *) LDR_in__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LDR_in_PRTDSI__OUT_SEL0       (* (reg8 *) LDR_in__PRTDSI__OUT_SEL0) 
#define LDR_in_PRTDSI__OUT_SEL1       (* (reg8 *) LDR_in__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LDR_in_PRTDSI__SYNC_OUT       (* (reg8 *) LDR_in__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LDR_in__SIO_CFG)
    #define LDR_in_SIO_HYST_EN        (* (reg8 *) LDR_in__SIO_HYST_EN)
    #define LDR_in_SIO_REG_HIFREQ     (* (reg8 *) LDR_in__SIO_REG_HIFREQ)
    #define LDR_in_SIO_CFG            (* (reg8 *) LDR_in__SIO_CFG)
    #define LDR_in_SIO_DIFF           (* (reg8 *) LDR_in__SIO_DIFF)
#endif /* (LDR_in__SIO_CFG) */

/* Interrupt Registers */
#if defined(LDR_in__INTSTAT)
    #define LDR_in_INTSTAT            (* (reg8 *) LDR_in__INTSTAT)
    #define LDR_in_SNAP               (* (reg8 *) LDR_in__SNAP)
    
	#define LDR_in_0_INTTYPE_REG 		(* (reg8 *) LDR_in__0__INTTYPE)
#endif /* (LDR_in__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LDR_in_H */


/* [] END OF FILE */
