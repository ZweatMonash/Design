/*******************************************************************************
* File Name: Com.h  
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

#if !defined(CY_PINS_Com_H) /* Pins Com_H */
#define CY_PINS_Com_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Com_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Com__PORT == 15 && ((Com__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Com_Write(uint8 value);
void    Com_SetDriveMode(uint8 mode);
uint8   Com_ReadDataReg(void);
uint8   Com_Read(void);
void    Com_SetInterruptMode(uint16 position, uint16 mode);
uint8   Com_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Com_SetDriveMode() function.
     *  @{
     */
        #define Com_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Com_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Com_DM_RES_UP          PIN_DM_RES_UP
        #define Com_DM_RES_DWN         PIN_DM_RES_DWN
        #define Com_DM_OD_LO           PIN_DM_OD_LO
        #define Com_DM_OD_HI           PIN_DM_OD_HI
        #define Com_DM_STRONG          PIN_DM_STRONG
        #define Com_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Com_MASK               Com__MASK
#define Com_SHIFT              Com__SHIFT
#define Com_WIDTH              4u

/* Interrupt constants */
#if defined(Com__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Com_SetInterruptMode() function.
     *  @{
     */
        #define Com_INTR_NONE      (uint16)(0x0000u)
        #define Com_INTR_RISING    (uint16)(0x0001u)
        #define Com_INTR_FALLING   (uint16)(0x0002u)
        #define Com_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Com_INTR_MASK      (0x01u) 
#endif /* (Com__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Com_PS                     (* (reg8 *) Com__PS)
/* Data Register */
#define Com_DR                     (* (reg8 *) Com__DR)
/* Port Number */
#define Com_PRT_NUM                (* (reg8 *) Com__PRT) 
/* Connect to Analog Globals */                                                  
#define Com_AG                     (* (reg8 *) Com__AG)                       
/* Analog MUX bux enable */
#define Com_AMUX                   (* (reg8 *) Com__AMUX) 
/* Bidirectional Enable */                                                        
#define Com_BIE                    (* (reg8 *) Com__BIE)
/* Bit-mask for Aliased Register Access */
#define Com_BIT_MASK               (* (reg8 *) Com__BIT_MASK)
/* Bypass Enable */
#define Com_BYP                    (* (reg8 *) Com__BYP)
/* Port wide control signals */                                                   
#define Com_CTL                    (* (reg8 *) Com__CTL)
/* Drive Modes */
#define Com_DM0                    (* (reg8 *) Com__DM0) 
#define Com_DM1                    (* (reg8 *) Com__DM1)
#define Com_DM2                    (* (reg8 *) Com__DM2) 
/* Input Buffer Disable Override */
#define Com_INP_DIS                (* (reg8 *) Com__INP_DIS)
/* LCD Common or Segment Drive */
#define Com_LCD_COM_SEG            (* (reg8 *) Com__LCD_COM_SEG)
/* Enable Segment LCD */
#define Com_LCD_EN                 (* (reg8 *) Com__LCD_EN)
/* Slew Rate Control */
#define Com_SLW                    (* (reg8 *) Com__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Com_PRTDSI__CAPS_SEL       (* (reg8 *) Com__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Com_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Com__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Com_PRTDSI__OE_SEL0        (* (reg8 *) Com__PRTDSI__OE_SEL0) 
#define Com_PRTDSI__OE_SEL1        (* (reg8 *) Com__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Com_PRTDSI__OUT_SEL0       (* (reg8 *) Com__PRTDSI__OUT_SEL0) 
#define Com_PRTDSI__OUT_SEL1       (* (reg8 *) Com__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Com_PRTDSI__SYNC_OUT       (* (reg8 *) Com__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Com__SIO_CFG)
    #define Com_SIO_HYST_EN        (* (reg8 *) Com__SIO_HYST_EN)
    #define Com_SIO_REG_HIFREQ     (* (reg8 *) Com__SIO_REG_HIFREQ)
    #define Com_SIO_CFG            (* (reg8 *) Com__SIO_CFG)
    #define Com_SIO_DIFF           (* (reg8 *) Com__SIO_DIFF)
#endif /* (Com__SIO_CFG) */

/* Interrupt Registers */
#if defined(Com__INTSTAT)
    #define Com_INTSTAT            (* (reg8 *) Com__INTSTAT)
    #define Com_SNAP               (* (reg8 *) Com__SNAP)
    
	#define Com_0_INTTYPE_REG 		(* (reg8 *) Com__0__INTTYPE)
	#define Com_1_INTTYPE_REG 		(* (reg8 *) Com__1__INTTYPE)
	#define Com_2_INTTYPE_REG 		(* (reg8 *) Com__2__INTTYPE)
	#define Com_3_INTTYPE_REG 		(* (reg8 *) Com__3__INTTYPE)
#endif /* (Com__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Com_H */


/* [] END OF FILE */
