/*******************************************************************************
* File Name: Echo_f.h  
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

#if !defined(CY_PINS_Echo_f_H) /* Pins Echo_f_H */
#define CY_PINS_Echo_f_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Echo_f_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Echo_f__PORT == 15 && ((Echo_f__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Echo_f_Write(uint8 value);
void    Echo_f_SetDriveMode(uint8 mode);
uint8   Echo_f_ReadDataReg(void);
uint8   Echo_f_Read(void);
void    Echo_f_SetInterruptMode(uint16 position, uint16 mode);
uint8   Echo_f_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Echo_f_SetDriveMode() function.
     *  @{
     */
        #define Echo_f_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Echo_f_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Echo_f_DM_RES_UP          PIN_DM_RES_UP
        #define Echo_f_DM_RES_DWN         PIN_DM_RES_DWN
        #define Echo_f_DM_OD_LO           PIN_DM_OD_LO
        #define Echo_f_DM_OD_HI           PIN_DM_OD_HI
        #define Echo_f_DM_STRONG          PIN_DM_STRONG
        #define Echo_f_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Echo_f_MASK               Echo_f__MASK
#define Echo_f_SHIFT              Echo_f__SHIFT
#define Echo_f_WIDTH              1u

/* Interrupt constants */
#if defined(Echo_f__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Echo_f_SetInterruptMode() function.
     *  @{
     */
        #define Echo_f_INTR_NONE      (uint16)(0x0000u)
        #define Echo_f_INTR_RISING    (uint16)(0x0001u)
        #define Echo_f_INTR_FALLING   (uint16)(0x0002u)
        #define Echo_f_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Echo_f_INTR_MASK      (0x01u) 
#endif /* (Echo_f__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Echo_f_PS                     (* (reg8 *) Echo_f__PS)
/* Data Register */
#define Echo_f_DR                     (* (reg8 *) Echo_f__DR)
/* Port Number */
#define Echo_f_PRT_NUM                (* (reg8 *) Echo_f__PRT) 
/* Connect to Analog Globals */                                                  
#define Echo_f_AG                     (* (reg8 *) Echo_f__AG)                       
/* Analog MUX bux enable */
#define Echo_f_AMUX                   (* (reg8 *) Echo_f__AMUX) 
/* Bidirectional Enable */                                                        
#define Echo_f_BIE                    (* (reg8 *) Echo_f__BIE)
/* Bit-mask for Aliased Register Access */
#define Echo_f_BIT_MASK               (* (reg8 *) Echo_f__BIT_MASK)
/* Bypass Enable */
#define Echo_f_BYP                    (* (reg8 *) Echo_f__BYP)
/* Port wide control signals */                                                   
#define Echo_f_CTL                    (* (reg8 *) Echo_f__CTL)
/* Drive Modes */
#define Echo_f_DM0                    (* (reg8 *) Echo_f__DM0) 
#define Echo_f_DM1                    (* (reg8 *) Echo_f__DM1)
#define Echo_f_DM2                    (* (reg8 *) Echo_f__DM2) 
/* Input Buffer Disable Override */
#define Echo_f_INP_DIS                (* (reg8 *) Echo_f__INP_DIS)
/* LCD Common or Segment Drive */
#define Echo_f_LCD_COM_SEG            (* (reg8 *) Echo_f__LCD_COM_SEG)
/* Enable Segment LCD */
#define Echo_f_LCD_EN                 (* (reg8 *) Echo_f__LCD_EN)
/* Slew Rate Control */
#define Echo_f_SLW                    (* (reg8 *) Echo_f__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Echo_f_PRTDSI__CAPS_SEL       (* (reg8 *) Echo_f__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Echo_f_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Echo_f__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Echo_f_PRTDSI__OE_SEL0        (* (reg8 *) Echo_f__PRTDSI__OE_SEL0) 
#define Echo_f_PRTDSI__OE_SEL1        (* (reg8 *) Echo_f__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Echo_f_PRTDSI__OUT_SEL0       (* (reg8 *) Echo_f__PRTDSI__OUT_SEL0) 
#define Echo_f_PRTDSI__OUT_SEL1       (* (reg8 *) Echo_f__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Echo_f_PRTDSI__SYNC_OUT       (* (reg8 *) Echo_f__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Echo_f__SIO_CFG)
    #define Echo_f_SIO_HYST_EN        (* (reg8 *) Echo_f__SIO_HYST_EN)
    #define Echo_f_SIO_REG_HIFREQ     (* (reg8 *) Echo_f__SIO_REG_HIFREQ)
    #define Echo_f_SIO_CFG            (* (reg8 *) Echo_f__SIO_CFG)
    #define Echo_f_SIO_DIFF           (* (reg8 *) Echo_f__SIO_DIFF)
#endif /* (Echo_f__SIO_CFG) */

/* Interrupt Registers */
#if defined(Echo_f__INTSTAT)
    #define Echo_f_INTSTAT            (* (reg8 *) Echo_f__INTSTAT)
    #define Echo_f_SNAP               (* (reg8 *) Echo_f__SNAP)
    
	#define Echo_f_0_INTTYPE_REG 		(* (reg8 *) Echo_f__0__INTTYPE)
#endif /* (Echo_f__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Echo_f_H */


/* [] END OF FILE */
