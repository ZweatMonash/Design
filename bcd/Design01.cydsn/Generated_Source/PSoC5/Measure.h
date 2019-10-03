/*******************************************************************************
* File Name: Measure.h  
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

#if !defined(CY_PINS_Measure_H) /* Pins Measure_H */
#define CY_PINS_Measure_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Measure_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Measure__PORT == 15 && ((Measure__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Measure_Write(uint8 value);
void    Measure_SetDriveMode(uint8 mode);
uint8   Measure_ReadDataReg(void);
uint8   Measure_Read(void);
void    Measure_SetInterruptMode(uint16 position, uint16 mode);
uint8   Measure_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Measure_SetDriveMode() function.
     *  @{
     */
        #define Measure_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Measure_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Measure_DM_RES_UP          PIN_DM_RES_UP
        #define Measure_DM_RES_DWN         PIN_DM_RES_DWN
        #define Measure_DM_OD_LO           PIN_DM_OD_LO
        #define Measure_DM_OD_HI           PIN_DM_OD_HI
        #define Measure_DM_STRONG          PIN_DM_STRONG
        #define Measure_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Measure_MASK               Measure__MASK
#define Measure_SHIFT              Measure__SHIFT
#define Measure_WIDTH              1u

/* Interrupt constants */
#if defined(Measure__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Measure_SetInterruptMode() function.
     *  @{
     */
        #define Measure_INTR_NONE      (uint16)(0x0000u)
        #define Measure_INTR_RISING    (uint16)(0x0001u)
        #define Measure_INTR_FALLING   (uint16)(0x0002u)
        #define Measure_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Measure_INTR_MASK      (0x01u) 
#endif /* (Measure__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Measure_PS                     (* (reg8 *) Measure__PS)
/* Data Register */
#define Measure_DR                     (* (reg8 *) Measure__DR)
/* Port Number */
#define Measure_PRT_NUM                (* (reg8 *) Measure__PRT) 
/* Connect to Analog Globals */                                                  
#define Measure_AG                     (* (reg8 *) Measure__AG)                       
/* Analog MUX bux enable */
#define Measure_AMUX                   (* (reg8 *) Measure__AMUX) 
/* Bidirectional Enable */                                                        
#define Measure_BIE                    (* (reg8 *) Measure__BIE)
/* Bit-mask for Aliased Register Access */
#define Measure_BIT_MASK               (* (reg8 *) Measure__BIT_MASK)
/* Bypass Enable */
#define Measure_BYP                    (* (reg8 *) Measure__BYP)
/* Port wide control signals */                                                   
#define Measure_CTL                    (* (reg8 *) Measure__CTL)
/* Drive Modes */
#define Measure_DM0                    (* (reg8 *) Measure__DM0) 
#define Measure_DM1                    (* (reg8 *) Measure__DM1)
#define Measure_DM2                    (* (reg8 *) Measure__DM2) 
/* Input Buffer Disable Override */
#define Measure_INP_DIS                (* (reg8 *) Measure__INP_DIS)
/* LCD Common or Segment Drive */
#define Measure_LCD_COM_SEG            (* (reg8 *) Measure__LCD_COM_SEG)
/* Enable Segment LCD */
#define Measure_LCD_EN                 (* (reg8 *) Measure__LCD_EN)
/* Slew Rate Control */
#define Measure_SLW                    (* (reg8 *) Measure__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Measure_PRTDSI__CAPS_SEL       (* (reg8 *) Measure__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Measure_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Measure__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Measure_PRTDSI__OE_SEL0        (* (reg8 *) Measure__PRTDSI__OE_SEL0) 
#define Measure_PRTDSI__OE_SEL1        (* (reg8 *) Measure__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Measure_PRTDSI__OUT_SEL0       (* (reg8 *) Measure__PRTDSI__OUT_SEL0) 
#define Measure_PRTDSI__OUT_SEL1       (* (reg8 *) Measure__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Measure_PRTDSI__SYNC_OUT       (* (reg8 *) Measure__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Measure__SIO_CFG)
    #define Measure_SIO_HYST_EN        (* (reg8 *) Measure__SIO_HYST_EN)
    #define Measure_SIO_REG_HIFREQ     (* (reg8 *) Measure__SIO_REG_HIFREQ)
    #define Measure_SIO_CFG            (* (reg8 *) Measure__SIO_CFG)
    #define Measure_SIO_DIFF           (* (reg8 *) Measure__SIO_DIFF)
#endif /* (Measure__SIO_CFG) */

/* Interrupt Registers */
#if defined(Measure__INTSTAT)
    #define Measure_INTSTAT            (* (reg8 *) Measure__INTSTAT)
    #define Measure_SNAP               (* (reg8 *) Measure__SNAP)
    
	#define Measure_0_INTTYPE_REG 		(* (reg8 *) Measure__0__INTTYPE)
#endif /* (Measure__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Measure_H */


/* [] END OF FILE */
