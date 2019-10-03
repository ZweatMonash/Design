/*******************************************************************************
* File Name: CR_Time_up_Isr.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_CR_Time_up_Isr_H) /* CY_CONTROL_REG_CR_Time_up_Isr_H */
#define CY_CONTROL_REG_CR_Time_up_Isr_H

#include "cyfitter.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} CR_Time_up_Isr_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    CR_Time_up_Isr_Write(uint8 control) ;
uint8   CR_Time_up_Isr_Read(void) ;

void CR_Time_up_Isr_SaveConfig(void) ;
void CR_Time_up_Isr_RestoreConfig(void) ;
void CR_Time_up_Isr_Sleep(void) ; 
void CR_Time_up_Isr_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define CR_Time_up_Isr_Control        (* (reg8 *) CR_Time_up_Isr_Sync_ctrl_reg__CONTROL_REG )
#define CR_Time_up_Isr_Control_PTR    (  (reg8 *) CR_Time_up_Isr_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_CR_Time_up_Isr_H */


/* [] END OF FILE */
