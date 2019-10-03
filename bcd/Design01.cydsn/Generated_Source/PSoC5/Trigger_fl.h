/*******************************************************************************
* File Name: Trigger_fl.h  
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

#if !defined(CY_PINS_Trigger_fl_H) /* Pins Trigger_fl_H */
#define CY_PINS_Trigger_fl_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Trigger_fl_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Trigger_fl__PORT == 15 && ((Trigger_fl__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Trigger_fl_Write(uint8 value);
void    Trigger_fl_SetDriveMode(uint8 mode);
uint8   Trigger_fl_ReadDataReg(void);
uint8   Trigger_fl_Read(void);
void    Trigger_fl_SetInterruptMode(uint16 position, uint16 mode);
uint8   Trigger_fl_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Trigger_fl_SetDriveMode() function.
     *  @{
     */
        #define Trigger_fl_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Trigger_fl_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Trigger_fl_DM_RES_UP          PIN_DM_RES_UP
        #define Trigger_fl_DM_RES_DWN         PIN_DM_RES_DWN
        #define Trigger_fl_DM_OD_LO           PIN_DM_OD_LO
        #define Trigger_fl_DM_OD_HI           PIN_DM_OD_HI
        #define Trigger_fl_DM_STRONG          PIN_DM_STRONG
        #define Trigger_fl_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Trigger_fl_MASK               Trigger_fl__MASK
#define Trigger_fl_SHIFT              Trigger_fl__SHIFT
#define Trigger_fl_WIDTH              1u

/* Interrupt constants */
#if defined(Trigger_fl__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Trigger_fl_SetInterruptMode() function.
     *  @{
     */
        #define Trigger_fl_INTR_NONE      (uint16)(0x0000u)
        #define Trigger_fl_INTR_RISING    (uint16)(0x0001u)
        #define Trigger_fl_INTR_FALLING   (uint16)(0x0002u)
        #define Trigger_fl_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Trigger_fl_INTR_MASK      (0x01u) 
#endif /* (Trigger_fl__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Trigger_fl_PS                     (* (reg8 *) Trigger_fl__PS)
/* Data Register */
#define Trigger_fl_DR                     (* (reg8 *) Trigger_fl__DR)
/* Port Number */
#define Trigger_fl_PRT_NUM                (* (reg8 *) Trigger_fl__PRT) 
/* Connect to Analog Globals */                                                  
#define Trigger_fl_AG                     (* (reg8 *) Trigger_fl__AG)                       
/* Analog MUX bux enable */
#define Trigger_fl_AMUX                   (* (reg8 *) Trigger_fl__AMUX) 
/* Bidirectional Enable */                                                        
#define Trigger_fl_BIE                    (* (reg8 *) Trigger_fl__BIE)
/* Bit-mask for Aliased Register Access */
#define Trigger_fl_BIT_MASK               (* (reg8 *) Trigger_fl__BIT_MASK)
/* Bypass Enable */
#define Trigger_fl_BYP                    (* (reg8 *) Trigger_fl__BYP)
/* Port wide control signals */                                                   
#define Trigger_fl_CTL                    (* (reg8 *) Trigger_fl__CTL)
/* Drive Modes */
#define Trigger_fl_DM0                    (* (reg8 *) Trigger_fl__DM0) 
#define Trigger_fl_DM1                    (* (reg8 *) Trigger_fl__DM1)
#define Trigger_fl_DM2                    (* (reg8 *) Trigger_fl__DM2) 
/* Input Buffer Disable Override */
#define Trigger_fl_INP_DIS                (* (reg8 *) Trigger_fl__INP_DIS)
/* LCD Common or Segment Drive */
#define Trigger_fl_LCD_COM_SEG            (* (reg8 *) Trigger_fl__LCD_COM_SEG)
/* Enable Segment LCD */
#define Trigger_fl_LCD_EN                 (* (reg8 *) Trigger_fl__LCD_EN)
/* Slew Rate Control */
#define Trigger_fl_SLW                    (* (reg8 *) Trigger_fl__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Trigger_fl_PRTDSI__CAPS_SEL       (* (reg8 *) Trigger_fl__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Trigger_fl_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Trigger_fl__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Trigger_fl_PRTDSI__OE_SEL0        (* (reg8 *) Trigger_fl__PRTDSI__OE_SEL0) 
#define Trigger_fl_PRTDSI__OE_SEL1        (* (reg8 *) Trigger_fl__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Trigger_fl_PRTDSI__OUT_SEL0       (* (reg8 *) Trigger_fl__PRTDSI__OUT_SEL0) 
#define Trigger_fl_PRTDSI__OUT_SEL1       (* (reg8 *) Trigger_fl__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Trigger_fl_PRTDSI__SYNC_OUT       (* (reg8 *) Trigger_fl__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Trigger_fl__SIO_CFG)
    #define Trigger_fl_SIO_HYST_EN        (* (reg8 *) Trigger_fl__SIO_HYST_EN)
    #define Trigger_fl_SIO_REG_HIFREQ     (* (reg8 *) Trigger_fl__SIO_REG_HIFREQ)
    #define Trigger_fl_SIO_CFG            (* (reg8 *) Trigger_fl__SIO_CFG)
    #define Trigger_fl_SIO_DIFF           (* (reg8 *) Trigger_fl__SIO_DIFF)
#endif /* (Trigger_fl__SIO_CFG) */

/* Interrupt Registers */
#if defined(Trigger_fl__INTSTAT)
    #define Trigger_fl_INTSTAT            (* (reg8 *) Trigger_fl__INTSTAT)
    #define Trigger_fl_SNAP               (* (reg8 *) Trigger_fl__SNAP)
    
	#define Trigger_fl_0_INTTYPE_REG 		(* (reg8 *) Trigger_fl__0__INTTYPE)
#endif /* (Trigger_fl__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Trigger_fl_H */


/* [] END OF FILE */
