/*******************************************************************************
* File Name: R_7.h  
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

#if !defined(CY_PINS_R_7_H) /* Pins R_7_H */
#define CY_PINS_R_7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "R_7_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 R_7__PORT == 15 && ((R_7__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    R_7_Write(uint8 value);
void    R_7_SetDriveMode(uint8 mode);
uint8   R_7_ReadDataReg(void);
uint8   R_7_Read(void);
void    R_7_SetInterruptMode(uint16 position, uint16 mode);
uint8   R_7_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the R_7_SetDriveMode() function.
     *  @{
     */
        #define R_7_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define R_7_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define R_7_DM_RES_UP          PIN_DM_RES_UP
        #define R_7_DM_RES_DWN         PIN_DM_RES_DWN
        #define R_7_DM_OD_LO           PIN_DM_OD_LO
        #define R_7_DM_OD_HI           PIN_DM_OD_HI
        #define R_7_DM_STRONG          PIN_DM_STRONG
        #define R_7_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define R_7_MASK               R_7__MASK
#define R_7_SHIFT              R_7__SHIFT
#define R_7_WIDTH              1u

/* Interrupt constants */
#if defined(R_7__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in R_7_SetInterruptMode() function.
     *  @{
     */
        #define R_7_INTR_NONE      (uint16)(0x0000u)
        #define R_7_INTR_RISING    (uint16)(0x0001u)
        #define R_7_INTR_FALLING   (uint16)(0x0002u)
        #define R_7_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define R_7_INTR_MASK      (0x01u) 
#endif /* (R_7__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define R_7_PS                     (* (reg8 *) R_7__PS)
/* Data Register */
#define R_7_DR                     (* (reg8 *) R_7__DR)
/* Port Number */
#define R_7_PRT_NUM                (* (reg8 *) R_7__PRT) 
/* Connect to Analog Globals */                                                  
#define R_7_AG                     (* (reg8 *) R_7__AG)                       
/* Analog MUX bux enable */
#define R_7_AMUX                   (* (reg8 *) R_7__AMUX) 
/* Bidirectional Enable */                                                        
#define R_7_BIE                    (* (reg8 *) R_7__BIE)
/* Bit-mask for Aliased Register Access */
#define R_7_BIT_MASK               (* (reg8 *) R_7__BIT_MASK)
/* Bypass Enable */
#define R_7_BYP                    (* (reg8 *) R_7__BYP)
/* Port wide control signals */                                                   
#define R_7_CTL                    (* (reg8 *) R_7__CTL)
/* Drive Modes */
#define R_7_DM0                    (* (reg8 *) R_7__DM0) 
#define R_7_DM1                    (* (reg8 *) R_7__DM1)
#define R_7_DM2                    (* (reg8 *) R_7__DM2) 
/* Input Buffer Disable Override */
#define R_7_INP_DIS                (* (reg8 *) R_7__INP_DIS)
/* LCD Common or Segment Drive */
#define R_7_LCD_COM_SEG            (* (reg8 *) R_7__LCD_COM_SEG)
/* Enable Segment LCD */
#define R_7_LCD_EN                 (* (reg8 *) R_7__LCD_EN)
/* Slew Rate Control */
#define R_7_SLW                    (* (reg8 *) R_7__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define R_7_PRTDSI__CAPS_SEL       (* (reg8 *) R_7__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define R_7_PRTDSI__DBL_SYNC_IN    (* (reg8 *) R_7__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define R_7_PRTDSI__OE_SEL0        (* (reg8 *) R_7__PRTDSI__OE_SEL0) 
#define R_7_PRTDSI__OE_SEL1        (* (reg8 *) R_7__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define R_7_PRTDSI__OUT_SEL0       (* (reg8 *) R_7__PRTDSI__OUT_SEL0) 
#define R_7_PRTDSI__OUT_SEL1       (* (reg8 *) R_7__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define R_7_PRTDSI__SYNC_OUT       (* (reg8 *) R_7__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(R_7__SIO_CFG)
    #define R_7_SIO_HYST_EN        (* (reg8 *) R_7__SIO_HYST_EN)
    #define R_7_SIO_REG_HIFREQ     (* (reg8 *) R_7__SIO_REG_HIFREQ)
    #define R_7_SIO_CFG            (* (reg8 *) R_7__SIO_CFG)
    #define R_7_SIO_DIFF           (* (reg8 *) R_7__SIO_DIFF)
#endif /* (R_7__SIO_CFG) */

/* Interrupt Registers */
#if defined(R_7__INTSTAT)
    #define R_7_INTSTAT            (* (reg8 *) R_7__INTSTAT)
    #define R_7_SNAP               (* (reg8 *) R_7__SNAP)
    
	#define R_7_0_INTTYPE_REG 		(* (reg8 *) R_7__0__INTTYPE)
#endif /* (R_7__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_R_7_H */


/* [] END OF FILE */
