/*******************************************************************************
* File Name: servo.h  
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

#if !defined(CY_PINS_servo_H) /* Pins servo_H */
#define CY_PINS_servo_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "servo_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 servo__PORT == 15 && ((servo__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    servo_Write(uint8 value);
void    servo_SetDriveMode(uint8 mode);
uint8   servo_ReadDataReg(void);
uint8   servo_Read(void);
void    servo_SetInterruptMode(uint16 position, uint16 mode);
uint8   servo_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the servo_SetDriveMode() function.
     *  @{
     */
        #define servo_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define servo_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define servo_DM_RES_UP          PIN_DM_RES_UP
        #define servo_DM_RES_DWN         PIN_DM_RES_DWN
        #define servo_DM_OD_LO           PIN_DM_OD_LO
        #define servo_DM_OD_HI           PIN_DM_OD_HI
        #define servo_DM_STRONG          PIN_DM_STRONG
        #define servo_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define servo_MASK               servo__MASK
#define servo_SHIFT              servo__SHIFT
#define servo_WIDTH              1u

/* Interrupt constants */
#if defined(servo__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in servo_SetInterruptMode() function.
     *  @{
     */
        #define servo_INTR_NONE      (uint16)(0x0000u)
        #define servo_INTR_RISING    (uint16)(0x0001u)
        #define servo_INTR_FALLING   (uint16)(0x0002u)
        #define servo_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define servo_INTR_MASK      (0x01u) 
#endif /* (servo__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define servo_PS                     (* (reg8 *) servo__PS)
/* Data Register */
#define servo_DR                     (* (reg8 *) servo__DR)
/* Port Number */
#define servo_PRT_NUM                (* (reg8 *) servo__PRT) 
/* Connect to Analog Globals */                                                  
#define servo_AG                     (* (reg8 *) servo__AG)                       
/* Analog MUX bux enable */
#define servo_AMUX                   (* (reg8 *) servo__AMUX) 
/* Bidirectional Enable */                                                        
#define servo_BIE                    (* (reg8 *) servo__BIE)
/* Bit-mask for Aliased Register Access */
#define servo_BIT_MASK               (* (reg8 *) servo__BIT_MASK)
/* Bypass Enable */
#define servo_BYP                    (* (reg8 *) servo__BYP)
/* Port wide control signals */                                                   
#define servo_CTL                    (* (reg8 *) servo__CTL)
/* Drive Modes */
#define servo_DM0                    (* (reg8 *) servo__DM0) 
#define servo_DM1                    (* (reg8 *) servo__DM1)
#define servo_DM2                    (* (reg8 *) servo__DM2) 
/* Input Buffer Disable Override */
#define servo_INP_DIS                (* (reg8 *) servo__INP_DIS)
/* LCD Common or Segment Drive */
#define servo_LCD_COM_SEG            (* (reg8 *) servo__LCD_COM_SEG)
/* Enable Segment LCD */
#define servo_LCD_EN                 (* (reg8 *) servo__LCD_EN)
/* Slew Rate Control */
#define servo_SLW                    (* (reg8 *) servo__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define servo_PRTDSI__CAPS_SEL       (* (reg8 *) servo__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define servo_PRTDSI__DBL_SYNC_IN    (* (reg8 *) servo__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define servo_PRTDSI__OE_SEL0        (* (reg8 *) servo__PRTDSI__OE_SEL0) 
#define servo_PRTDSI__OE_SEL1        (* (reg8 *) servo__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define servo_PRTDSI__OUT_SEL0       (* (reg8 *) servo__PRTDSI__OUT_SEL0) 
#define servo_PRTDSI__OUT_SEL1       (* (reg8 *) servo__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define servo_PRTDSI__SYNC_OUT       (* (reg8 *) servo__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(servo__SIO_CFG)
    #define servo_SIO_HYST_EN        (* (reg8 *) servo__SIO_HYST_EN)
    #define servo_SIO_REG_HIFREQ     (* (reg8 *) servo__SIO_REG_HIFREQ)
    #define servo_SIO_CFG            (* (reg8 *) servo__SIO_CFG)
    #define servo_SIO_DIFF           (* (reg8 *) servo__SIO_DIFF)
#endif /* (servo__SIO_CFG) */

/* Interrupt Registers */
#if defined(servo__INTSTAT)
    #define servo_INTSTAT            (* (reg8 *) servo__INTSTAT)
    #define servo_SNAP               (* (reg8 *) servo__SNAP)
    
	#define servo_0_INTTYPE_REG 		(* (reg8 *) servo__0__INTTYPE)
#endif /* (servo__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_servo_H */


/* [] END OF FILE */
