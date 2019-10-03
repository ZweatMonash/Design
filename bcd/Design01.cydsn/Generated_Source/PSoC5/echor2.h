/*******************************************************************************
* File Name: echor2.h  
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

#if !defined(CY_PINS_echor2_H) /* Pins echor2_H */
#define CY_PINS_echor2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "echor2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 echor2__PORT == 15 && ((echor2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    echor2_Write(uint8 value);
void    echor2_SetDriveMode(uint8 mode);
uint8   echor2_ReadDataReg(void);
uint8   echor2_Read(void);
void    echor2_SetInterruptMode(uint16 position, uint16 mode);
uint8   echor2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the echor2_SetDriveMode() function.
     *  @{
     */
        #define echor2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define echor2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define echor2_DM_RES_UP          PIN_DM_RES_UP
        #define echor2_DM_RES_DWN         PIN_DM_RES_DWN
        #define echor2_DM_OD_LO           PIN_DM_OD_LO
        #define echor2_DM_OD_HI           PIN_DM_OD_HI
        #define echor2_DM_STRONG          PIN_DM_STRONG
        #define echor2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define echor2_MASK               echor2__MASK
#define echor2_SHIFT              echor2__SHIFT
#define echor2_WIDTH              1u

/* Interrupt constants */
#if defined(echor2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in echor2_SetInterruptMode() function.
     *  @{
     */
        #define echor2_INTR_NONE      (uint16)(0x0000u)
        #define echor2_INTR_RISING    (uint16)(0x0001u)
        #define echor2_INTR_FALLING   (uint16)(0x0002u)
        #define echor2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define echor2_INTR_MASK      (0x01u) 
#endif /* (echor2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define echor2_PS                     (* (reg8 *) echor2__PS)
/* Data Register */
#define echor2_DR                     (* (reg8 *) echor2__DR)
/* Port Number */
#define echor2_PRT_NUM                (* (reg8 *) echor2__PRT) 
/* Connect to Analog Globals */                                                  
#define echor2_AG                     (* (reg8 *) echor2__AG)                       
/* Analog MUX bux enable */
#define echor2_AMUX                   (* (reg8 *) echor2__AMUX) 
/* Bidirectional Enable */                                                        
#define echor2_BIE                    (* (reg8 *) echor2__BIE)
/* Bit-mask for Aliased Register Access */
#define echor2_BIT_MASK               (* (reg8 *) echor2__BIT_MASK)
/* Bypass Enable */
#define echor2_BYP                    (* (reg8 *) echor2__BYP)
/* Port wide control signals */                                                   
#define echor2_CTL                    (* (reg8 *) echor2__CTL)
/* Drive Modes */
#define echor2_DM0                    (* (reg8 *) echor2__DM0) 
#define echor2_DM1                    (* (reg8 *) echor2__DM1)
#define echor2_DM2                    (* (reg8 *) echor2__DM2) 
/* Input Buffer Disable Override */
#define echor2_INP_DIS                (* (reg8 *) echor2__INP_DIS)
/* LCD Common or Segment Drive */
#define echor2_LCD_COM_SEG            (* (reg8 *) echor2__LCD_COM_SEG)
/* Enable Segment LCD */
#define echor2_LCD_EN                 (* (reg8 *) echor2__LCD_EN)
/* Slew Rate Control */
#define echor2_SLW                    (* (reg8 *) echor2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define echor2_PRTDSI__CAPS_SEL       (* (reg8 *) echor2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define echor2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) echor2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define echor2_PRTDSI__OE_SEL0        (* (reg8 *) echor2__PRTDSI__OE_SEL0) 
#define echor2_PRTDSI__OE_SEL1        (* (reg8 *) echor2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define echor2_PRTDSI__OUT_SEL0       (* (reg8 *) echor2__PRTDSI__OUT_SEL0) 
#define echor2_PRTDSI__OUT_SEL1       (* (reg8 *) echor2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define echor2_PRTDSI__SYNC_OUT       (* (reg8 *) echor2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(echor2__SIO_CFG)
    #define echor2_SIO_HYST_EN        (* (reg8 *) echor2__SIO_HYST_EN)
    #define echor2_SIO_REG_HIFREQ     (* (reg8 *) echor2__SIO_REG_HIFREQ)
    #define echor2_SIO_CFG            (* (reg8 *) echor2__SIO_CFG)
    #define echor2_SIO_DIFF           (* (reg8 *) echor2__SIO_DIFF)
#endif /* (echor2__SIO_CFG) */

/* Interrupt Registers */
#if defined(echor2__INTSTAT)
    #define echor2_INTSTAT            (* (reg8 *) echor2__INTSTAT)
    #define echor2_SNAP               (* (reg8 *) echor2__SNAP)
    
	#define echor2_0_INTTYPE_REG 		(* (reg8 *) echor2__0__INTTYPE)
#endif /* (echor2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_echor2_H */


/* [] END OF FILE */
