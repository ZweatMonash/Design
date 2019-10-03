/*******************************************************************************
* File Name: Limit.h  
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

#if !defined(CY_PINS_Limit_H) /* Pins Limit_H */
#define CY_PINS_Limit_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Limit_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Limit__PORT == 15 && ((Limit__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Limit_Write(uint8 value);
void    Limit_SetDriveMode(uint8 mode);
uint8   Limit_ReadDataReg(void);
uint8   Limit_Read(void);
void    Limit_SetInterruptMode(uint16 position, uint16 mode);
uint8   Limit_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Limit_SetDriveMode() function.
     *  @{
     */
        #define Limit_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Limit_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Limit_DM_RES_UP          PIN_DM_RES_UP
        #define Limit_DM_RES_DWN         PIN_DM_RES_DWN
        #define Limit_DM_OD_LO           PIN_DM_OD_LO
        #define Limit_DM_OD_HI           PIN_DM_OD_HI
        #define Limit_DM_STRONG          PIN_DM_STRONG
        #define Limit_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Limit_MASK               Limit__MASK
#define Limit_SHIFT              Limit__SHIFT
#define Limit_WIDTH              1u

/* Interrupt constants */
#if defined(Limit__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Limit_SetInterruptMode() function.
     *  @{
     */
        #define Limit_INTR_NONE      (uint16)(0x0000u)
        #define Limit_INTR_RISING    (uint16)(0x0001u)
        #define Limit_INTR_FALLING   (uint16)(0x0002u)
        #define Limit_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Limit_INTR_MASK      (0x01u) 
#endif /* (Limit__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Limit_PS                     (* (reg8 *) Limit__PS)
/* Data Register */
#define Limit_DR                     (* (reg8 *) Limit__DR)
/* Port Number */
#define Limit_PRT_NUM                (* (reg8 *) Limit__PRT) 
/* Connect to Analog Globals */                                                  
#define Limit_AG                     (* (reg8 *) Limit__AG)                       
/* Analog MUX bux enable */
#define Limit_AMUX                   (* (reg8 *) Limit__AMUX) 
/* Bidirectional Enable */                                                        
#define Limit_BIE                    (* (reg8 *) Limit__BIE)
/* Bit-mask for Aliased Register Access */
#define Limit_BIT_MASK               (* (reg8 *) Limit__BIT_MASK)
/* Bypass Enable */
#define Limit_BYP                    (* (reg8 *) Limit__BYP)
/* Port wide control signals */                                                   
#define Limit_CTL                    (* (reg8 *) Limit__CTL)
/* Drive Modes */
#define Limit_DM0                    (* (reg8 *) Limit__DM0) 
#define Limit_DM1                    (* (reg8 *) Limit__DM1)
#define Limit_DM2                    (* (reg8 *) Limit__DM2) 
/* Input Buffer Disable Override */
#define Limit_INP_DIS                (* (reg8 *) Limit__INP_DIS)
/* LCD Common or Segment Drive */
#define Limit_LCD_COM_SEG            (* (reg8 *) Limit__LCD_COM_SEG)
/* Enable Segment LCD */
#define Limit_LCD_EN                 (* (reg8 *) Limit__LCD_EN)
/* Slew Rate Control */
#define Limit_SLW                    (* (reg8 *) Limit__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Limit_PRTDSI__CAPS_SEL       (* (reg8 *) Limit__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Limit_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Limit__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Limit_PRTDSI__OE_SEL0        (* (reg8 *) Limit__PRTDSI__OE_SEL0) 
#define Limit_PRTDSI__OE_SEL1        (* (reg8 *) Limit__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Limit_PRTDSI__OUT_SEL0       (* (reg8 *) Limit__PRTDSI__OUT_SEL0) 
#define Limit_PRTDSI__OUT_SEL1       (* (reg8 *) Limit__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Limit_PRTDSI__SYNC_OUT       (* (reg8 *) Limit__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Limit__SIO_CFG)
    #define Limit_SIO_HYST_EN        (* (reg8 *) Limit__SIO_HYST_EN)
    #define Limit_SIO_REG_HIFREQ     (* (reg8 *) Limit__SIO_REG_HIFREQ)
    #define Limit_SIO_CFG            (* (reg8 *) Limit__SIO_CFG)
    #define Limit_SIO_DIFF           (* (reg8 *) Limit__SIO_DIFF)
#endif /* (Limit__SIO_CFG) */

/* Interrupt Registers */
#if defined(Limit__INTSTAT)
    #define Limit_INTSTAT            (* (reg8 *) Limit__INTSTAT)
    #define Limit_SNAP               (* (reg8 *) Limit__SNAP)
    
	#define Limit_0_INTTYPE_REG 		(* (reg8 *) Limit__0__INTTYPE)
#endif /* (Limit__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Limit_H */


/* [] END OF FILE */
