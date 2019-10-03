/*******************************************************************************
* File Name: Seg.h  
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

#if !defined(CY_PINS_Seg_H) /* Pins Seg_H */
#define CY_PINS_Seg_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Seg_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Seg__PORT == 15 && ((Seg__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Seg_Write(uint8 value);
void    Seg_SetDriveMode(uint8 mode);
uint8   Seg_ReadDataReg(void);
uint8   Seg_Read(void);
void    Seg_SetInterruptMode(uint16 position, uint16 mode);
uint8   Seg_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Seg_SetDriveMode() function.
     *  @{
     */
        #define Seg_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Seg_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Seg_DM_RES_UP          PIN_DM_RES_UP
        #define Seg_DM_RES_DWN         PIN_DM_RES_DWN
        #define Seg_DM_OD_LO           PIN_DM_OD_LO
        #define Seg_DM_OD_HI           PIN_DM_OD_HI
        #define Seg_DM_STRONG          PIN_DM_STRONG
        #define Seg_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Seg_MASK               Seg__MASK
#define Seg_SHIFT              Seg__SHIFT
#define Seg_WIDTH              7u

/* Interrupt constants */
#if defined(Seg__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Seg_SetInterruptMode() function.
     *  @{
     */
        #define Seg_INTR_NONE      (uint16)(0x0000u)
        #define Seg_INTR_RISING    (uint16)(0x0001u)
        #define Seg_INTR_FALLING   (uint16)(0x0002u)
        #define Seg_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Seg_INTR_MASK      (0x01u) 
#endif /* (Seg__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Seg_PS                     (* (reg8 *) Seg__PS)
/* Data Register */
#define Seg_DR                     (* (reg8 *) Seg__DR)
/* Port Number */
#define Seg_PRT_NUM                (* (reg8 *) Seg__PRT) 
/* Connect to Analog Globals */                                                  
#define Seg_AG                     (* (reg8 *) Seg__AG)                       
/* Analog MUX bux enable */
#define Seg_AMUX                   (* (reg8 *) Seg__AMUX) 
/* Bidirectional Enable */                                                        
#define Seg_BIE                    (* (reg8 *) Seg__BIE)
/* Bit-mask for Aliased Register Access */
#define Seg_BIT_MASK               (* (reg8 *) Seg__BIT_MASK)
/* Bypass Enable */
#define Seg_BYP                    (* (reg8 *) Seg__BYP)
/* Port wide control signals */                                                   
#define Seg_CTL                    (* (reg8 *) Seg__CTL)
/* Drive Modes */
#define Seg_DM0                    (* (reg8 *) Seg__DM0) 
#define Seg_DM1                    (* (reg8 *) Seg__DM1)
#define Seg_DM2                    (* (reg8 *) Seg__DM2) 
/* Input Buffer Disable Override */
#define Seg_INP_DIS                (* (reg8 *) Seg__INP_DIS)
/* LCD Common or Segment Drive */
#define Seg_LCD_COM_SEG            (* (reg8 *) Seg__LCD_COM_SEG)
/* Enable Segment LCD */
#define Seg_LCD_EN                 (* (reg8 *) Seg__LCD_EN)
/* Slew Rate Control */
#define Seg_SLW                    (* (reg8 *) Seg__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Seg_PRTDSI__CAPS_SEL       (* (reg8 *) Seg__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Seg_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Seg__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Seg_PRTDSI__OE_SEL0        (* (reg8 *) Seg__PRTDSI__OE_SEL0) 
#define Seg_PRTDSI__OE_SEL1        (* (reg8 *) Seg__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Seg_PRTDSI__OUT_SEL0       (* (reg8 *) Seg__PRTDSI__OUT_SEL0) 
#define Seg_PRTDSI__OUT_SEL1       (* (reg8 *) Seg__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Seg_PRTDSI__SYNC_OUT       (* (reg8 *) Seg__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Seg__SIO_CFG)
    #define Seg_SIO_HYST_EN        (* (reg8 *) Seg__SIO_HYST_EN)
    #define Seg_SIO_REG_HIFREQ     (* (reg8 *) Seg__SIO_REG_HIFREQ)
    #define Seg_SIO_CFG            (* (reg8 *) Seg__SIO_CFG)
    #define Seg_SIO_DIFF           (* (reg8 *) Seg__SIO_DIFF)
#endif /* (Seg__SIO_CFG) */

/* Interrupt Registers */
#if defined(Seg__INTSTAT)
    #define Seg_INTSTAT            (* (reg8 *) Seg__INTSTAT)
    #define Seg_SNAP               (* (reg8 *) Seg__SNAP)
    
	#define Seg_0_INTTYPE_REG 		(* (reg8 *) Seg__0__INTTYPE)
	#define Seg_1_INTTYPE_REG 		(* (reg8 *) Seg__1__INTTYPE)
	#define Seg_2_INTTYPE_REG 		(* (reg8 *) Seg__2__INTTYPE)
	#define Seg_3_INTTYPE_REG 		(* (reg8 *) Seg__3__INTTYPE)
	#define Seg_4_INTTYPE_REG 		(* (reg8 *) Seg__4__INTTYPE)
	#define Seg_5_INTTYPE_REG 		(* (reg8 *) Seg__5__INTTYPE)
	#define Seg_6_INTTYPE_REG 		(* (reg8 *) Seg__6__INTTYPE)
#endif /* (Seg__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Seg_H */


/* [] END OF FILE */
