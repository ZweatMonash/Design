/*******************************************************************************
* File Name: Vneg.h  
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

#if !defined(CY_PINS_Vneg_H) /* Pins Vneg_H */
#define CY_PINS_Vneg_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Vneg_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Vneg__PORT == 15 && ((Vneg__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Vneg_Write(uint8 value);
void    Vneg_SetDriveMode(uint8 mode);
uint8   Vneg_ReadDataReg(void);
uint8   Vneg_Read(void);
void    Vneg_SetInterruptMode(uint16 position, uint16 mode);
uint8   Vneg_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Vneg_SetDriveMode() function.
     *  @{
     */
        #define Vneg_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Vneg_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Vneg_DM_RES_UP          PIN_DM_RES_UP
        #define Vneg_DM_RES_DWN         PIN_DM_RES_DWN
        #define Vneg_DM_OD_LO           PIN_DM_OD_LO
        #define Vneg_DM_OD_HI           PIN_DM_OD_HI
        #define Vneg_DM_STRONG          PIN_DM_STRONG
        #define Vneg_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Vneg_MASK               Vneg__MASK
#define Vneg_SHIFT              Vneg__SHIFT
#define Vneg_WIDTH              1u

/* Interrupt constants */
#if defined(Vneg__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Vneg_SetInterruptMode() function.
     *  @{
     */
        #define Vneg_INTR_NONE      (uint16)(0x0000u)
        #define Vneg_INTR_RISING    (uint16)(0x0001u)
        #define Vneg_INTR_FALLING   (uint16)(0x0002u)
        #define Vneg_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Vneg_INTR_MASK      (0x01u) 
#endif /* (Vneg__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vneg_PS                     (* (reg8 *) Vneg__PS)
/* Data Register */
#define Vneg_DR                     (* (reg8 *) Vneg__DR)
/* Port Number */
#define Vneg_PRT_NUM                (* (reg8 *) Vneg__PRT) 
/* Connect to Analog Globals */                                                  
#define Vneg_AG                     (* (reg8 *) Vneg__AG)                       
/* Analog MUX bux enable */
#define Vneg_AMUX                   (* (reg8 *) Vneg__AMUX) 
/* Bidirectional Enable */                                                        
#define Vneg_BIE                    (* (reg8 *) Vneg__BIE)
/* Bit-mask for Aliased Register Access */
#define Vneg_BIT_MASK               (* (reg8 *) Vneg__BIT_MASK)
/* Bypass Enable */
#define Vneg_BYP                    (* (reg8 *) Vneg__BYP)
/* Port wide control signals */                                                   
#define Vneg_CTL                    (* (reg8 *) Vneg__CTL)
/* Drive Modes */
#define Vneg_DM0                    (* (reg8 *) Vneg__DM0) 
#define Vneg_DM1                    (* (reg8 *) Vneg__DM1)
#define Vneg_DM2                    (* (reg8 *) Vneg__DM2) 
/* Input Buffer Disable Override */
#define Vneg_INP_DIS                (* (reg8 *) Vneg__INP_DIS)
/* LCD Common or Segment Drive */
#define Vneg_LCD_COM_SEG            (* (reg8 *) Vneg__LCD_COM_SEG)
/* Enable Segment LCD */
#define Vneg_LCD_EN                 (* (reg8 *) Vneg__LCD_EN)
/* Slew Rate Control */
#define Vneg_SLW                    (* (reg8 *) Vneg__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Vneg_PRTDSI__CAPS_SEL       (* (reg8 *) Vneg__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Vneg_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Vneg__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Vneg_PRTDSI__OE_SEL0        (* (reg8 *) Vneg__PRTDSI__OE_SEL0) 
#define Vneg_PRTDSI__OE_SEL1        (* (reg8 *) Vneg__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Vneg_PRTDSI__OUT_SEL0       (* (reg8 *) Vneg__PRTDSI__OUT_SEL0) 
#define Vneg_PRTDSI__OUT_SEL1       (* (reg8 *) Vneg__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Vneg_PRTDSI__SYNC_OUT       (* (reg8 *) Vneg__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Vneg__SIO_CFG)
    #define Vneg_SIO_HYST_EN        (* (reg8 *) Vneg__SIO_HYST_EN)
    #define Vneg_SIO_REG_HIFREQ     (* (reg8 *) Vneg__SIO_REG_HIFREQ)
    #define Vneg_SIO_CFG            (* (reg8 *) Vneg__SIO_CFG)
    #define Vneg_SIO_DIFF           (* (reg8 *) Vneg__SIO_DIFF)
#endif /* (Vneg__SIO_CFG) */

/* Interrupt Registers */
#if defined(Vneg__INTSTAT)
    #define Vneg_INTSTAT            (* (reg8 *) Vneg__INTSTAT)
    #define Vneg_SNAP               (* (reg8 *) Vneg__SNAP)
    
	#define Vneg_0_INTTYPE_REG 		(* (reg8 *) Vneg__0__INTTYPE)
#endif /* (Vneg__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Vneg_H */


/* [] END OF FILE */
