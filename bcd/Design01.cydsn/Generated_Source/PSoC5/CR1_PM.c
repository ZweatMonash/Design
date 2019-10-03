/*******************************************************************************
* File Name: CR1_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "CR1.h"

/* Check for removal by optimization */
#if !defined(CR1_Sync_ctrl_reg__REMOVED)

static CR1_BACKUP_STRUCT  CR1_backup = {0u};

    
/*******************************************************************************
* Function Name: CR1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CR1_SaveConfig(void) 
{
    CR1_backup.controlState = CR1_Control;
}


/*******************************************************************************
* Function Name: CR1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void CR1_RestoreConfig(void) 
{
     CR1_Control = CR1_backup.controlState;
}


/*******************************************************************************
* Function Name: CR1_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CR1_Sleep(void) 
{
    CR1_SaveConfig();
}


/*******************************************************************************
* Function Name: CR1_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CR1_Wakeup(void)  
{
    CR1_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
