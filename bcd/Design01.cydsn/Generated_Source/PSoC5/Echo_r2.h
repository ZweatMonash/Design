/*******************************************************************************
* File Name: Echo_r2.h  
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

#if !defined(CY_PINS_Echo_r2_H) /* Pins Echo_r2_H */
#define CY_PINS_Echo_r2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Echo_r2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Echo_r2__PORT == 15 && ((Echo_r2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Echo_r2_Write(uint8 value);
void    Echo_r2_SetDriveMode(uint8 mode);
uint8   Echo_r2_ReadDataReg(void);
uint8   Echo_r2_Read(void);
void    Echo_r2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Echo_r2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Echo_r2_SetDriveMode() function.
     *  @{
     */
        #define Echo_r2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Echo_r2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Echo_r2_DM_RES_UP          PIN_DM_RES_UP
        #define Echo_r2_DM_RES_DWN         PIN_DM_RES_DWN
        #define Echo_r2_DM_OD_LO           PIN_DM_OD_LO
        #define Echo_r2_DM_OD_HI           PIN_DM_OD_HI
        #define Echo_r2_DM_STRONG          PIN_DM_STRONG
        #define Echo_r2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Echo_r2_MASK               Echo_r2__MASK
#define Echo_r2_SHIFT              Echo_r2__SHIFT
#define Echo_r2_WIDTH              1u

/* Interrupt constants */
#if defined(Echo_r2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Echo_r2_SetInterruptMode() function.
     *  @{
     */
        #define Echo_r2_INTR_NONE      (uint16)(0x0000u)
        #define Echo_r2_INTR_RISING    (uint16)(0x0001u)
        #define Echo_r2_INTR_FALLING   (uint16)(0x0002u)
        #define Echo_r2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Echo_r2_INTR_MASK      (0x01u) 
#endif /* (Echo_r2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Echo_r2_PS                     (* (reg8 *) Echo_r2__PS)
/* Data Register */
#define Echo_r2_DR                     (* (reg8 *) Echo_r2__DR)
/* Port Number */
#define Echo_r2_PRT_NUM                (* (reg8 *) Echo_r2__PRT) 
/* Connect to Analog Globals */                                                  
#define Echo_r2_AG                     (* (reg8 *) Echo_r2__AG)                       
/* Analog MUX bux enable */
#define Echo_r2_AMUX                   (* (reg8 *) Echo_r2__AMUX) 
/* Bidirectional Enable */                                                        
#define Echo_r2_BIE                    (* (reg8 *) Echo_r2__BIE)
/* Bit-mask for Aliased Register Access */
#define Echo_r2_BIT_MASK               (* (reg8 *) Echo_r2__BIT_MASK)
/* Bypass Enable */
#define Echo_r2_BYP                    (* (reg8 *) Echo_r2__BYP)
/* Port wide control signals */                                                   
#define Echo_r2_CTL                    (* (reg8 *) Echo_r2__CTL)
/* Drive Modes */
#define Echo_r2_DM0                    (* (reg8 *) Echo_r2__DM0) 
#define Echo_r2_DM1                    (* (reg8 *) Echo_r2__DM1)
#define Echo_r2_DM2                    (* (reg8 *) Echo_r2__DM2) 
/* Input Buffer Disable Override */
#define Echo_r2_INP_DIS                (* (reg8 *) Echo_r2__INP_DIS)
/* LCD Common or Segment Drive */
#define Echo_r2_LCD_COM_SEG            (* (reg8 *) Echo_r2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Echo_r2_LCD_EN                 (* (reg8 *) Echo_r2__LCD_EN)
/* Slew Rate Control */
#define Echo_r2_SLW                    (* (reg8 *) Echo_r2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Echo_r2_PRTDSI__CAPS_SEL       (* (reg8 *) Echo_r2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Echo_r2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Echo_r2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Echo_r2_PRTDSI__OE_SEL0        (* (reg8 *) Echo_r2__PRTDSI__OE_SEL0) 
#define Echo_r2_PRTDSI__OE_SEL1        (* (reg8 *) Echo_r2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Echo_r2_PRTDSI__OUT_SEL0       (* (reg8 *) Echo_r2__PRTDSI__OUT_SEL0) 
#define Echo_r2_PRTDSI__OUT_SEL1       (* (reg8 *) Echo_r2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Echo_r2_PRTDSI__SYNC_OUT       (* (reg8 *) Echo_r2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Echo_r2__SIO_CFG)
    #define Echo_r2_SIO_HYST_EN        (* (reg8 *) Echo_r2__SIO_HYST_EN)
    #define Echo_r2_SIO_REG_HIFREQ     (* (reg8 *) Echo_r2__SIO_REG_HIFREQ)
    #define Echo_r2_SIO_CFG            (* (reg8 *) Echo_r2__SIO_CFG)
    #define Echo_r2_SIO_DIFF           (* (reg8 *) Echo_r2__SIO_DIFF)
#endif /* (Echo_r2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Echo_r2__INTSTAT)
    #define Echo_r2_INTSTAT            (* (reg8 *) Echo_r2__INTSTAT)
    #define Echo_r2_SNAP               (* (reg8 *) Echo_r2__SNAP)
    
	#define Echo_r2_0_INTTYPE_REG 		(* (reg8 *) Echo_r2__0__INTTYPE)
#endif /* (Echo_r2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Echo_r2_H */


/* [] END OF FILE */
