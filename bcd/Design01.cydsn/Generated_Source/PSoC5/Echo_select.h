/*******************************************************************************
* File Name: Echo_select.h  
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

#if !defined(CY_PINS_Echo_select_H) /* Pins Echo_select_H */
#define CY_PINS_Echo_select_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Echo_select_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Echo_select__PORT == 15 && ((Echo_select__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Echo_select_Write(uint8 value);
void    Echo_select_SetDriveMode(uint8 mode);
uint8   Echo_select_ReadDataReg(void);
uint8   Echo_select_Read(void);
void    Echo_select_SetInterruptMode(uint16 position, uint16 mode);
uint8   Echo_select_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Echo_select_SetDriveMode() function.
     *  @{
     */
        #define Echo_select_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Echo_select_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Echo_select_DM_RES_UP          PIN_DM_RES_UP
        #define Echo_select_DM_RES_DWN         PIN_DM_RES_DWN
        #define Echo_select_DM_OD_LO           PIN_DM_OD_LO
        #define Echo_select_DM_OD_HI           PIN_DM_OD_HI
        #define Echo_select_DM_STRONG          PIN_DM_STRONG
        #define Echo_select_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Echo_select_MASK               Echo_select__MASK
#define Echo_select_SHIFT              Echo_select__SHIFT
#define Echo_select_WIDTH              2u

/* Interrupt constants */
#if defined(Echo_select__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Echo_select_SetInterruptMode() function.
     *  @{
     */
        #define Echo_select_INTR_NONE      (uint16)(0x0000u)
        #define Echo_select_INTR_RISING    (uint16)(0x0001u)
        #define Echo_select_INTR_FALLING   (uint16)(0x0002u)
        #define Echo_select_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Echo_select_INTR_MASK      (0x01u) 
#endif /* (Echo_select__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Echo_select_PS                     (* (reg8 *) Echo_select__PS)
/* Data Register */
#define Echo_select_DR                     (* (reg8 *) Echo_select__DR)
/* Port Number */
#define Echo_select_PRT_NUM                (* (reg8 *) Echo_select__PRT) 
/* Connect to Analog Globals */                                                  
#define Echo_select_AG                     (* (reg8 *) Echo_select__AG)                       
/* Analog MUX bux enable */
#define Echo_select_AMUX                   (* (reg8 *) Echo_select__AMUX) 
/* Bidirectional Enable */                                                        
#define Echo_select_BIE                    (* (reg8 *) Echo_select__BIE)
/* Bit-mask for Aliased Register Access */
#define Echo_select_BIT_MASK               (* (reg8 *) Echo_select__BIT_MASK)
/* Bypass Enable */
#define Echo_select_BYP                    (* (reg8 *) Echo_select__BYP)
/* Port wide control signals */                                                   
#define Echo_select_CTL                    (* (reg8 *) Echo_select__CTL)
/* Drive Modes */
#define Echo_select_DM0                    (* (reg8 *) Echo_select__DM0) 
#define Echo_select_DM1                    (* (reg8 *) Echo_select__DM1)
#define Echo_select_DM2                    (* (reg8 *) Echo_select__DM2) 
/* Input Buffer Disable Override */
#define Echo_select_INP_DIS                (* (reg8 *) Echo_select__INP_DIS)
/* LCD Common or Segment Drive */
#define Echo_select_LCD_COM_SEG            (* (reg8 *) Echo_select__LCD_COM_SEG)
/* Enable Segment LCD */
#define Echo_select_LCD_EN                 (* (reg8 *) Echo_select__LCD_EN)
/* Slew Rate Control */
#define Echo_select_SLW                    (* (reg8 *) Echo_select__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Echo_select_PRTDSI__CAPS_SEL       (* (reg8 *) Echo_select__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Echo_select_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Echo_select__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Echo_select_PRTDSI__OE_SEL0        (* (reg8 *) Echo_select__PRTDSI__OE_SEL0) 
#define Echo_select_PRTDSI__OE_SEL1        (* (reg8 *) Echo_select__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Echo_select_PRTDSI__OUT_SEL0       (* (reg8 *) Echo_select__PRTDSI__OUT_SEL0) 
#define Echo_select_PRTDSI__OUT_SEL1       (* (reg8 *) Echo_select__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Echo_select_PRTDSI__SYNC_OUT       (* (reg8 *) Echo_select__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Echo_select__SIO_CFG)
    #define Echo_select_SIO_HYST_EN        (* (reg8 *) Echo_select__SIO_HYST_EN)
    #define Echo_select_SIO_REG_HIFREQ     (* (reg8 *) Echo_select__SIO_REG_HIFREQ)
    #define Echo_select_SIO_CFG            (* (reg8 *) Echo_select__SIO_CFG)
    #define Echo_select_SIO_DIFF           (* (reg8 *) Echo_select__SIO_DIFF)
#endif /* (Echo_select__SIO_CFG) */

/* Interrupt Registers */
#if defined(Echo_select__INTSTAT)
    #define Echo_select_INTSTAT            (* (reg8 *) Echo_select__INTSTAT)
    #define Echo_select_SNAP               (* (reg8 *) Echo_select__SNAP)
    
	#define Echo_select_0_INTTYPE_REG 		(* (reg8 *) Echo_select__0__INTTYPE)
	#define Echo_select_1_INTTYPE_REG 		(* (reg8 *) Echo_select__1__INTTYPE)
#endif /* (Echo_select__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Echo_select_H */


/* [] END OF FILE */
