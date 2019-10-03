/*******************************************************************************
* File Name: out10.h  
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

#if !defined(CY_PINS_out10_H) /* Pins out10_H */
#define CY_PINS_out10_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "out10_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 out10__PORT == 15 && ((out10__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    out10_Write(uint8 value);
void    out10_SetDriveMode(uint8 mode);
uint8   out10_ReadDataReg(void);
uint8   out10_Read(void);
void    out10_SetInterruptMode(uint16 position, uint16 mode);
uint8   out10_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the out10_SetDriveMode() function.
     *  @{
     */
        #define out10_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define out10_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define out10_DM_RES_UP          PIN_DM_RES_UP
        #define out10_DM_RES_DWN         PIN_DM_RES_DWN
        #define out10_DM_OD_LO           PIN_DM_OD_LO
        #define out10_DM_OD_HI           PIN_DM_OD_HI
        #define out10_DM_STRONG          PIN_DM_STRONG
        #define out10_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define out10_MASK               out10__MASK
#define out10_SHIFT              out10__SHIFT
#define out10_WIDTH              1u

/* Interrupt constants */
#if defined(out10__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in out10_SetInterruptMode() function.
     *  @{
     */
        #define out10_INTR_NONE      (uint16)(0x0000u)
        #define out10_INTR_RISING    (uint16)(0x0001u)
        #define out10_INTR_FALLING   (uint16)(0x0002u)
        #define out10_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define out10_INTR_MASK      (0x01u) 
#endif /* (out10__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define out10_PS                     (* (reg8 *) out10__PS)
/* Data Register */
#define out10_DR                     (* (reg8 *) out10__DR)
/* Port Number */
#define out10_PRT_NUM                (* (reg8 *) out10__PRT) 
/* Connect to Analog Globals */                                                  
#define out10_AG                     (* (reg8 *) out10__AG)                       
/* Analog MUX bux enable */
#define out10_AMUX                   (* (reg8 *) out10__AMUX) 
/* Bidirectional Enable */                                                        
#define out10_BIE                    (* (reg8 *) out10__BIE)
/* Bit-mask for Aliased Register Access */
#define out10_BIT_MASK               (* (reg8 *) out10__BIT_MASK)
/* Bypass Enable */
#define out10_BYP                    (* (reg8 *) out10__BYP)
/* Port wide control signals */                                                   
#define out10_CTL                    (* (reg8 *) out10__CTL)
/* Drive Modes */
#define out10_DM0                    (* (reg8 *) out10__DM0) 
#define out10_DM1                    (* (reg8 *) out10__DM1)
#define out10_DM2                    (* (reg8 *) out10__DM2) 
/* Input Buffer Disable Override */
#define out10_INP_DIS                (* (reg8 *) out10__INP_DIS)
/* LCD Common or Segment Drive */
#define out10_LCD_COM_SEG            (* (reg8 *) out10__LCD_COM_SEG)
/* Enable Segment LCD */
#define out10_LCD_EN                 (* (reg8 *) out10__LCD_EN)
/* Slew Rate Control */
#define out10_SLW                    (* (reg8 *) out10__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define out10_PRTDSI__CAPS_SEL       (* (reg8 *) out10__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define out10_PRTDSI__DBL_SYNC_IN    (* (reg8 *) out10__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define out10_PRTDSI__OE_SEL0        (* (reg8 *) out10__PRTDSI__OE_SEL0) 
#define out10_PRTDSI__OE_SEL1        (* (reg8 *) out10__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define out10_PRTDSI__OUT_SEL0       (* (reg8 *) out10__PRTDSI__OUT_SEL0) 
#define out10_PRTDSI__OUT_SEL1       (* (reg8 *) out10__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define out10_PRTDSI__SYNC_OUT       (* (reg8 *) out10__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(out10__SIO_CFG)
    #define out10_SIO_HYST_EN        (* (reg8 *) out10__SIO_HYST_EN)
    #define out10_SIO_REG_HIFREQ     (* (reg8 *) out10__SIO_REG_HIFREQ)
    #define out10_SIO_CFG            (* (reg8 *) out10__SIO_CFG)
    #define out10_SIO_DIFF           (* (reg8 *) out10__SIO_DIFF)
#endif /* (out10__SIO_CFG) */

/* Interrupt Registers */
#if defined(out10__INTSTAT)
    #define out10_INTSTAT            (* (reg8 *) out10__INTSTAT)
    #define out10_SNAP               (* (reg8 *) out10__SNAP)
    
	#define out10_0_INTTYPE_REG 		(* (reg8 *) out10__0__INTTYPE)
#endif /* (out10__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_out10_H */


/* [] END OF FILE */
