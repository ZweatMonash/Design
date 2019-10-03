/*******************************************************************************
* File Name: Start_switch.h  
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

#if !defined(CY_PINS_Start_switch_H) /* Pins Start_switch_H */
#define CY_PINS_Start_switch_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Start_switch_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Start_switch__PORT == 15 && ((Start_switch__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Start_switch_Write(uint8 value);
void    Start_switch_SetDriveMode(uint8 mode);
uint8   Start_switch_ReadDataReg(void);
uint8   Start_switch_Read(void);
void    Start_switch_SetInterruptMode(uint16 position, uint16 mode);
uint8   Start_switch_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Start_switch_SetDriveMode() function.
     *  @{
     */
        #define Start_switch_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Start_switch_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Start_switch_DM_RES_UP          PIN_DM_RES_UP
        #define Start_switch_DM_RES_DWN         PIN_DM_RES_DWN
        #define Start_switch_DM_OD_LO           PIN_DM_OD_LO
        #define Start_switch_DM_OD_HI           PIN_DM_OD_HI
        #define Start_switch_DM_STRONG          PIN_DM_STRONG
        #define Start_switch_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Start_switch_MASK               Start_switch__MASK
#define Start_switch_SHIFT              Start_switch__SHIFT
#define Start_switch_WIDTH              1u

/* Interrupt constants */
#if defined(Start_switch__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Start_switch_SetInterruptMode() function.
     *  @{
     */
        #define Start_switch_INTR_NONE      (uint16)(0x0000u)
        #define Start_switch_INTR_RISING    (uint16)(0x0001u)
        #define Start_switch_INTR_FALLING   (uint16)(0x0002u)
        #define Start_switch_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Start_switch_INTR_MASK      (0x01u) 
#endif /* (Start_switch__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Start_switch_PS                     (* (reg8 *) Start_switch__PS)
/* Data Register */
#define Start_switch_DR                     (* (reg8 *) Start_switch__DR)
/* Port Number */
#define Start_switch_PRT_NUM                (* (reg8 *) Start_switch__PRT) 
/* Connect to Analog Globals */                                                  
#define Start_switch_AG                     (* (reg8 *) Start_switch__AG)                       
/* Analog MUX bux enable */
#define Start_switch_AMUX                   (* (reg8 *) Start_switch__AMUX) 
/* Bidirectional Enable */                                                        
#define Start_switch_BIE                    (* (reg8 *) Start_switch__BIE)
/* Bit-mask for Aliased Register Access */
#define Start_switch_BIT_MASK               (* (reg8 *) Start_switch__BIT_MASK)
/* Bypass Enable */
#define Start_switch_BYP                    (* (reg8 *) Start_switch__BYP)
/* Port wide control signals */                                                   
#define Start_switch_CTL                    (* (reg8 *) Start_switch__CTL)
/* Drive Modes */
#define Start_switch_DM0                    (* (reg8 *) Start_switch__DM0) 
#define Start_switch_DM1                    (* (reg8 *) Start_switch__DM1)
#define Start_switch_DM2                    (* (reg8 *) Start_switch__DM2) 
/* Input Buffer Disable Override */
#define Start_switch_INP_DIS                (* (reg8 *) Start_switch__INP_DIS)
/* LCD Common or Segment Drive */
#define Start_switch_LCD_COM_SEG            (* (reg8 *) Start_switch__LCD_COM_SEG)
/* Enable Segment LCD */
#define Start_switch_LCD_EN                 (* (reg8 *) Start_switch__LCD_EN)
/* Slew Rate Control */
#define Start_switch_SLW                    (* (reg8 *) Start_switch__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Start_switch_PRTDSI__CAPS_SEL       (* (reg8 *) Start_switch__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Start_switch_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Start_switch__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Start_switch_PRTDSI__OE_SEL0        (* (reg8 *) Start_switch__PRTDSI__OE_SEL0) 
#define Start_switch_PRTDSI__OE_SEL1        (* (reg8 *) Start_switch__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Start_switch_PRTDSI__OUT_SEL0       (* (reg8 *) Start_switch__PRTDSI__OUT_SEL0) 
#define Start_switch_PRTDSI__OUT_SEL1       (* (reg8 *) Start_switch__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Start_switch_PRTDSI__SYNC_OUT       (* (reg8 *) Start_switch__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Start_switch__SIO_CFG)
    #define Start_switch_SIO_HYST_EN        (* (reg8 *) Start_switch__SIO_HYST_EN)
    #define Start_switch_SIO_REG_HIFREQ     (* (reg8 *) Start_switch__SIO_REG_HIFREQ)
    #define Start_switch_SIO_CFG            (* (reg8 *) Start_switch__SIO_CFG)
    #define Start_switch_SIO_DIFF           (* (reg8 *) Start_switch__SIO_DIFF)
#endif /* (Start_switch__SIO_CFG) */

/* Interrupt Registers */
#if defined(Start_switch__INTSTAT)
    #define Start_switch_INTSTAT            (* (reg8 *) Start_switch__INTSTAT)
    #define Start_switch_SNAP               (* (reg8 *) Start_switch__SNAP)
    
	#define Start_switch_0_INTTYPE_REG 		(* (reg8 *) Start_switch__0__INTTYPE)
#endif /* (Start_switch__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Start_switch_H */


/* [] END OF FILE */
