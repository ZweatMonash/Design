/*******************************************************************************
* File Name: CR3_PM.c
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

#include "CR3.h"

/* Check for removal by optimization */
#if !defined(CR3_Sync_ctrl_reg__REMOVED)

static CR3_BACKUP_STRUCT  CR3_backup = {0u};

    
/*******************************************************************************
* Function Name: CR3_SaveConfig
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
void CR3_SaveConfig(void) 
{
    CR3_backup.controlState = CR3_Control;
}


/*******************************************************************************
* Function Name: CR3_RestoreConfig
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
void CR3_RestoreConfig(void) 
{
     CR3_Control = CR3_backup.controlState;
}


/*******************************************************************************
* Function Name: CR3_Sleep
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
void CR3_Sleep(void) 
{
    CR3_SaveConfig();
}


/*******************************************************************************
* Function Name: CR3_Wakeup
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
void CR3_Wakeup(void)  
{
    CR3_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
