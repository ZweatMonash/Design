/*******************************************************************************
* File Name: Echo_select.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Echo_select_ALIASES_H) /* Pins Echo_select_ALIASES_H */
#define CY_PINS_Echo_select_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Echo_select_0			(Echo_select__0__PC)
#define Echo_select_0_INTR	((uint16)((uint16)0x0001u << Echo_select__0__SHIFT))

#define Echo_select_1			(Echo_select__1__PC)
#define Echo_select_1_INTR	((uint16)((uint16)0x0001u << Echo_select__1__SHIFT))

#define Echo_select_INTR_ALL	 ((uint16)(Echo_select_0_INTR| Echo_select_1_INTR))

#endif /* End Pins Echo_select_ALIASES_H */


/* [] END OF FILE */
