/*******************************************************************************
* File Name: dir_rw.h  
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

#if !defined(CY_PINS_dir_rw_H) /* Pins dir_rw_H */
#define CY_PINS_dir_rw_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "dir_rw_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 dir_rw__PORT == 15 && ((dir_rw__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    dir_rw_Write(uint8 value);
void    dir_rw_SetDriveMode(uint8 mode);
uint8   dir_rw_ReadDataReg(void);
uint8   dir_rw_Read(void);
void    dir_rw_SetInterruptMode(uint16 position, uint16 mode);
uint8   dir_rw_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the dir_rw_SetDriveMode() function.
     *  @{
     */
        #define dir_rw_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define dir_rw_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define dir_rw_DM_RES_UP          PIN_DM_RES_UP
        #define dir_rw_DM_RES_DWN         PIN_DM_RES_DWN
        #define dir_rw_DM_OD_LO           PIN_DM_OD_LO
        #define dir_rw_DM_OD_HI           PIN_DM_OD_HI
        #define dir_rw_DM_STRONG          PIN_DM_STRONG
        #define dir_rw_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define dir_rw_MASK               dir_rw__MASK
#define dir_rw_SHIFT              dir_rw__SHIFT
#define dir_rw_WIDTH              1u

/* Interrupt constants */
#if defined(dir_rw__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in dir_rw_SetInterruptMode() function.
     *  @{
     */
        #define dir_rw_INTR_NONE      (uint16)(0x0000u)
        #define dir_rw_INTR_RISING    (uint16)(0x0001u)
        #define dir_rw_INTR_FALLING   (uint16)(0x0002u)
        #define dir_rw_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define dir_rw_INTR_MASK      (0x01u) 
#endif /* (dir_rw__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define dir_rw_PS                     (* (reg8 *) dir_rw__PS)
/* Data Register */
#define dir_rw_DR                     (* (reg8 *) dir_rw__DR)
/* Port Number */
#define dir_rw_PRT_NUM                (* (reg8 *) dir_rw__PRT) 
/* Connect to Analog Globals */                                                  
#define dir_rw_AG                     (* (reg8 *) dir_rw__AG)                       
/* Analog MUX bux enable */
#define dir_rw_AMUX                   (* (reg8 *) dir_rw__AMUX) 
/* Bidirectional Enable */                                                        
#define dir_rw_BIE                    (* (reg8 *) dir_rw__BIE)
/* Bit-mask for Aliased Register Access */
#define dir_rw_BIT_MASK               (* (reg8 *) dir_rw__BIT_MASK)
/* Bypass Enable */
#define dir_rw_BYP                    (* (reg8 *) dir_rw__BYP)
/* Port wide control signals */                                                   
#define dir_rw_CTL                    (* (reg8 *) dir_rw__CTL)
/* Drive Modes */
#define dir_rw_DM0                    (* (reg8 *) dir_rw__DM0) 
#define dir_rw_DM1                    (* (reg8 *) dir_rw__DM1)
#define dir_rw_DM2                    (* (reg8 *) dir_rw__DM2) 
/* Input Buffer Disable Override */
#define dir_rw_INP_DIS                (* (reg8 *) dir_rw__INP_DIS)
/* LCD Common or Segment Drive */
#define dir_rw_LCD_COM_SEG            (* (reg8 *) dir_rw__LCD_COM_SEG)
/* Enable Segment LCD */
#define dir_rw_LCD_EN                 (* (reg8 *) dir_rw__LCD_EN)
/* Slew Rate Control */
#define dir_rw_SLW                    (* (reg8 *) dir_rw__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define dir_rw_PRTDSI__CAPS_SEL       (* (reg8 *) dir_rw__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define dir_rw_PRTDSI__DBL_SYNC_IN    (* (reg8 *) dir_rw__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define dir_rw_PRTDSI__OE_SEL0        (* (reg8 *) dir_rw__PRTDSI__OE_SEL0) 
#define dir_rw_PRTDSI__OE_SEL1        (* (reg8 *) dir_rw__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define dir_rw_PRTDSI__OUT_SEL0       (* (reg8 *) dir_rw__PRTDSI__OUT_SEL0) 
#define dir_rw_PRTDSI__OUT_SEL1       (* (reg8 *) dir_rw__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define dir_rw_PRTDSI__SYNC_OUT       (* (reg8 *) dir_rw__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(dir_rw__SIO_CFG)
    #define dir_rw_SIO_HYST_EN        (* (reg8 *) dir_rw__SIO_HYST_EN)
    #define dir_rw_SIO_REG_HIFREQ     (* (reg8 *) dir_rw__SIO_REG_HIFREQ)
    #define dir_rw_SIO_CFG            (* (reg8 *) dir_rw__SIO_CFG)
    #define dir_rw_SIO_DIFF           (* (reg8 *) dir_rw__SIO_DIFF)
#endif /* (dir_rw__SIO_CFG) */

/* Interrupt Registers */
#if defined(dir_rw__INTSTAT)
    #define dir_rw_INTSTAT            (* (reg8 *) dir_rw__INTSTAT)
    #define dir_rw_SNAP               (* (reg8 *) dir_rw__SNAP)
    
	#define dir_rw_0_INTTYPE_REG 		(* (reg8 *) dir_rw__0__INTTYPE)
#endif /* (dir_rw__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_dir_rw_H */


/* [] END OF FILE */
