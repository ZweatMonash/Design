/*******************************************************************************
* File Name: SensorOut.h  
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

#if !defined(CY_PINS_SensorOut_H) /* Pins SensorOut_H */
#define CY_PINS_SensorOut_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SensorOut_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SensorOut__PORT == 15 && ((SensorOut__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SensorOut_Write(uint8 value);
void    SensorOut_SetDriveMode(uint8 mode);
uint8   SensorOut_ReadDataReg(void);
uint8   SensorOut_Read(void);
void    SensorOut_SetInterruptMode(uint16 position, uint16 mode);
uint8   SensorOut_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SensorOut_SetDriveMode() function.
     *  @{
     */
        #define SensorOut_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SensorOut_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SensorOut_DM_RES_UP          PIN_DM_RES_UP
        #define SensorOut_DM_RES_DWN         PIN_DM_RES_DWN
        #define SensorOut_DM_OD_LO           PIN_DM_OD_LO
        #define SensorOut_DM_OD_HI           PIN_DM_OD_HI
        #define SensorOut_DM_STRONG          PIN_DM_STRONG
        #define SensorOut_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SensorOut_MASK               SensorOut__MASK
#define SensorOut_SHIFT              SensorOut__SHIFT
#define SensorOut_WIDTH              1u

/* Interrupt constants */
#if defined(SensorOut__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SensorOut_SetInterruptMode() function.
     *  @{
     */
        #define SensorOut_INTR_NONE      (uint16)(0x0000u)
        #define SensorOut_INTR_RISING    (uint16)(0x0001u)
        #define SensorOut_INTR_FALLING   (uint16)(0x0002u)
        #define SensorOut_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SensorOut_INTR_MASK      (0x01u) 
#endif /* (SensorOut__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SensorOut_PS                     (* (reg8 *) SensorOut__PS)
/* Data Register */
#define SensorOut_DR                     (* (reg8 *) SensorOut__DR)
/* Port Number */
#define SensorOut_PRT_NUM                (* (reg8 *) SensorOut__PRT) 
/* Connect to Analog Globals */                                                  
#define SensorOut_AG                     (* (reg8 *) SensorOut__AG)                       
/* Analog MUX bux enable */
#define SensorOut_AMUX                   (* (reg8 *) SensorOut__AMUX) 
/* Bidirectional Enable */                                                        
#define SensorOut_BIE                    (* (reg8 *) SensorOut__BIE)
/* Bit-mask for Aliased Register Access */
#define SensorOut_BIT_MASK               (* (reg8 *) SensorOut__BIT_MASK)
/* Bypass Enable */
#define SensorOut_BYP                    (* (reg8 *) SensorOut__BYP)
/* Port wide control signals */                                                   
#define SensorOut_CTL                    (* (reg8 *) SensorOut__CTL)
/* Drive Modes */
#define SensorOut_DM0                    (* (reg8 *) SensorOut__DM0) 
#define SensorOut_DM1                    (* (reg8 *) SensorOut__DM1)
#define SensorOut_DM2                    (* (reg8 *) SensorOut__DM2) 
/* Input Buffer Disable Override */
#define SensorOut_INP_DIS                (* (reg8 *) SensorOut__INP_DIS)
/* LCD Common or Segment Drive */
#define SensorOut_LCD_COM_SEG            (* (reg8 *) SensorOut__LCD_COM_SEG)
/* Enable Segment LCD */
#define SensorOut_LCD_EN                 (* (reg8 *) SensorOut__LCD_EN)
/* Slew Rate Control */
#define SensorOut_SLW                    (* (reg8 *) SensorOut__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SensorOut_PRTDSI__CAPS_SEL       (* (reg8 *) SensorOut__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SensorOut_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SensorOut__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SensorOut_PRTDSI__OE_SEL0        (* (reg8 *) SensorOut__PRTDSI__OE_SEL0) 
#define SensorOut_PRTDSI__OE_SEL1        (* (reg8 *) SensorOut__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SensorOut_PRTDSI__OUT_SEL0       (* (reg8 *) SensorOut__PRTDSI__OUT_SEL0) 
#define SensorOut_PRTDSI__OUT_SEL1       (* (reg8 *) SensorOut__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SensorOut_PRTDSI__SYNC_OUT       (* (reg8 *) SensorOut__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SensorOut__SIO_CFG)
    #define SensorOut_SIO_HYST_EN        (* (reg8 *) SensorOut__SIO_HYST_EN)
    #define SensorOut_SIO_REG_HIFREQ     (* (reg8 *) SensorOut__SIO_REG_HIFREQ)
    #define SensorOut_SIO_CFG            (* (reg8 *) SensorOut__SIO_CFG)
    #define SensorOut_SIO_DIFF           (* (reg8 *) SensorOut__SIO_DIFF)
#endif /* (SensorOut__SIO_CFG) */

/* Interrupt Registers */
#if defined(SensorOut__INTSTAT)
    #define SensorOut_INTSTAT            (* (reg8 *) SensorOut__INTSTAT)
    #define SensorOut_SNAP               (* (reg8 *) SensorOut__SNAP)
    
	#define SensorOut_0_INTTYPE_REG 		(* (reg8 *) SensorOut__0__INTTYPE)
#endif /* (SensorOut__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SensorOut_H */


/* [] END OF FILE */
