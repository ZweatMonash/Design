/*******************************************************************************
* File Name: Pulse_Square.h  
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

#if !defined(CY_PINS_Pulse_Square_H) /* Pins Pulse_Square_H */
#define CY_PINS_Pulse_Square_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pulse_Square_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pulse_Square__PORT == 15 && ((Pulse_Square__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pulse_Square_Write(uint8 value);
void    Pulse_Square_SetDriveMode(uint8 mode);
uint8   Pulse_Square_ReadDataReg(void);
uint8   Pulse_Square_Read(void);
void    Pulse_Square_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pulse_Square_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pulse_Square_SetDriveMode() function.
     *  @{
     */
        #define Pulse_Square_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pulse_Square_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pulse_Square_DM_RES_UP          PIN_DM_RES_UP
        #define Pulse_Square_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pulse_Square_DM_OD_LO           PIN_DM_OD_LO
        #define Pulse_Square_DM_OD_HI           PIN_DM_OD_HI
        #define Pulse_Square_DM_STRONG          PIN_DM_STRONG
        #define Pulse_Square_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pulse_Square_MASK               Pulse_Square__MASK
#define Pulse_Square_SHIFT              Pulse_Square__SHIFT
#define Pulse_Square_WIDTH              1u

/* Interrupt constants */
#if defined(Pulse_Square__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pulse_Square_SetInterruptMode() function.
     *  @{
     */
        #define Pulse_Square_INTR_NONE      (uint16)(0x0000u)
        #define Pulse_Square_INTR_RISING    (uint16)(0x0001u)
        #define Pulse_Square_INTR_FALLING   (uint16)(0x0002u)
        #define Pulse_Square_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pulse_Square_INTR_MASK      (0x01u) 
#endif /* (Pulse_Square__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pulse_Square_PS                     (* (reg8 *) Pulse_Square__PS)
/* Data Register */
#define Pulse_Square_DR                     (* (reg8 *) Pulse_Square__DR)
/* Port Number */
#define Pulse_Square_PRT_NUM                (* (reg8 *) Pulse_Square__PRT) 
/* Connect to Analog Globals */                                                  
#define Pulse_Square_AG                     (* (reg8 *) Pulse_Square__AG)                       
/* Analog MUX bux enable */
#define Pulse_Square_AMUX                   (* (reg8 *) Pulse_Square__AMUX) 
/* Bidirectional Enable */                                                        
#define Pulse_Square_BIE                    (* (reg8 *) Pulse_Square__BIE)
/* Bit-mask for Aliased Register Access */
#define Pulse_Square_BIT_MASK               (* (reg8 *) Pulse_Square__BIT_MASK)
/* Bypass Enable */
#define Pulse_Square_BYP                    (* (reg8 *) Pulse_Square__BYP)
/* Port wide control signals */                                                   
#define Pulse_Square_CTL                    (* (reg8 *) Pulse_Square__CTL)
/* Drive Modes */
#define Pulse_Square_DM0                    (* (reg8 *) Pulse_Square__DM0) 
#define Pulse_Square_DM1                    (* (reg8 *) Pulse_Square__DM1)
#define Pulse_Square_DM2                    (* (reg8 *) Pulse_Square__DM2) 
/* Input Buffer Disable Override */
#define Pulse_Square_INP_DIS                (* (reg8 *) Pulse_Square__INP_DIS)
/* LCD Common or Segment Drive */
#define Pulse_Square_LCD_COM_SEG            (* (reg8 *) Pulse_Square__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pulse_Square_LCD_EN                 (* (reg8 *) Pulse_Square__LCD_EN)
/* Slew Rate Control */
#define Pulse_Square_SLW                    (* (reg8 *) Pulse_Square__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pulse_Square_PRTDSI__CAPS_SEL       (* (reg8 *) Pulse_Square__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pulse_Square_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pulse_Square__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pulse_Square_PRTDSI__OE_SEL0        (* (reg8 *) Pulse_Square__PRTDSI__OE_SEL0) 
#define Pulse_Square_PRTDSI__OE_SEL1        (* (reg8 *) Pulse_Square__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pulse_Square_PRTDSI__OUT_SEL0       (* (reg8 *) Pulse_Square__PRTDSI__OUT_SEL0) 
#define Pulse_Square_PRTDSI__OUT_SEL1       (* (reg8 *) Pulse_Square__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pulse_Square_PRTDSI__SYNC_OUT       (* (reg8 *) Pulse_Square__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pulse_Square__SIO_CFG)
    #define Pulse_Square_SIO_HYST_EN        (* (reg8 *) Pulse_Square__SIO_HYST_EN)
    #define Pulse_Square_SIO_REG_HIFREQ     (* (reg8 *) Pulse_Square__SIO_REG_HIFREQ)
    #define Pulse_Square_SIO_CFG            (* (reg8 *) Pulse_Square__SIO_CFG)
    #define Pulse_Square_SIO_DIFF           (* (reg8 *) Pulse_Square__SIO_DIFF)
#endif /* (Pulse_Square__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pulse_Square__INTSTAT)
    #define Pulse_Square_INTSTAT            (* (reg8 *) Pulse_Square__INTSTAT)
    #define Pulse_Square_SNAP               (* (reg8 *) Pulse_Square__SNAP)
    
	#define Pulse_Square_0_INTTYPE_REG 		(* (reg8 *) Pulse_Square__0__INTTYPE)
#endif /* (Pulse_Square__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pulse_Square_H */


/* [] END OF FILE */
