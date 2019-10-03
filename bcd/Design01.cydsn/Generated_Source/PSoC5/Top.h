/*******************************************************************************
* File Name: Top.h  
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

#if !defined(CY_PINS_Top_H) /* Pins Top_H */
#define CY_PINS_Top_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Top_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Top__PORT == 15 && ((Top__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Top_Write(uint8 value);
void    Top_SetDriveMode(uint8 mode);
uint8   Top_ReadDataReg(void);
uint8   Top_Read(void);
void    Top_SetInterruptMode(uint16 position, uint16 mode);
uint8   Top_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Top_SetDriveMode() function.
     *  @{
     */
        #define Top_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Top_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Top_DM_RES_UP          PIN_DM_RES_UP
        #define Top_DM_RES_DWN         PIN_DM_RES_DWN
        #define Top_DM_OD_LO           PIN_DM_OD_LO
        #define Top_DM_OD_HI           PIN_DM_OD_HI
        #define Top_DM_STRONG          PIN_DM_STRONG
        #define Top_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Top_MASK               Top__MASK
#define Top_SHIFT              Top__SHIFT
#define Top_WIDTH              1u

/* Interrupt constants */
#if defined(Top__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Top_SetInterruptMode() function.
     *  @{
     */
        #define Top_INTR_NONE      (uint16)(0x0000u)
        #define Top_INTR_RISING    (uint16)(0x0001u)
        #define Top_INTR_FALLING   (uint16)(0x0002u)
        #define Top_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Top_INTR_MASK      (0x01u) 
#endif /* (Top__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Top_PS                     (* (reg8 *) Top__PS)
/* Data Register */
#define Top_DR                     (* (reg8 *) Top__DR)
/* Port Number */
#define Top_PRT_NUM                (* (reg8 *) Top__PRT) 
/* Connect to Analog Globals */                                                  
#define Top_AG                     (* (reg8 *) Top__AG)                       
/* Analog MUX bux enable */
#define Top_AMUX                   (* (reg8 *) Top__AMUX) 
/* Bidirectional Enable */                                                        
#define Top_BIE                    (* (reg8 *) Top__BIE)
/* Bit-mask for Aliased Register Access */
#define Top_BIT_MASK               (* (reg8 *) Top__BIT_MASK)
/* Bypass Enable */
#define Top_BYP                    (* (reg8 *) Top__BYP)
/* Port wide control signals */                                                   
#define Top_CTL                    (* (reg8 *) Top__CTL)
/* Drive Modes */
#define Top_DM0                    (* (reg8 *) Top__DM0) 
#define Top_DM1                    (* (reg8 *) Top__DM1)
#define Top_DM2                    (* (reg8 *) Top__DM2) 
/* Input Buffer Disable Override */
#define Top_INP_DIS                (* (reg8 *) Top__INP_DIS)
/* LCD Common or Segment Drive */
#define Top_LCD_COM_SEG            (* (reg8 *) Top__LCD_COM_SEG)
/* Enable Segment LCD */
#define Top_LCD_EN                 (* (reg8 *) Top__LCD_EN)
/* Slew Rate Control */
#define Top_SLW                    (* (reg8 *) Top__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Top_PRTDSI__CAPS_SEL       (* (reg8 *) Top__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Top_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Top__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Top_PRTDSI__OE_SEL0        (* (reg8 *) Top__PRTDSI__OE_SEL0) 
#define Top_PRTDSI__OE_SEL1        (* (reg8 *) Top__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Top_PRTDSI__OUT_SEL0       (* (reg8 *) Top__PRTDSI__OUT_SEL0) 
#define Top_PRTDSI__OUT_SEL1       (* (reg8 *) Top__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Top_PRTDSI__SYNC_OUT       (* (reg8 *) Top__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Top__SIO_CFG)
    #define Top_SIO_HYST_EN        (* (reg8 *) Top__SIO_HYST_EN)
    #define Top_SIO_REG_HIFREQ     (* (reg8 *) Top__SIO_REG_HIFREQ)
    #define Top_SIO_CFG            (* (reg8 *) Top__SIO_CFG)
    #define Top_SIO_DIFF           (* (reg8 *) Top__SIO_DIFF)
#endif /* (Top__SIO_CFG) */

/* Interrupt Registers */
#if defined(Top__INTSTAT)
    #define Top_INTSTAT            (* (reg8 *) Top__INTSTAT)
    #define Top_SNAP               (* (reg8 *) Top__SNAP)
    
	#define Top_0_INTTYPE_REG 		(* (reg8 *) Top__0__INTTYPE)
#endif /* (Top__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Top_H */


/* [] END OF FILE */
