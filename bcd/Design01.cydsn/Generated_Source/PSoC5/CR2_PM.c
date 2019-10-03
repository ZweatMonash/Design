/*******************************************************************************
* File Name: CR2_PM.c
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

#include "CR2.h"

/* Check for removal by optimization */
#if !defined(CR2_Sync_ctrl_reg__REMOVED)

static CR2_BACKUP_STRUCT  CR2_backup = {0u};

    
/*******************************************************************************
* Function Name: CR2_SaveConfig
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
void CR2_SaveConfig(void) 
{
    CR2_backup.controlState = CR2_Control;
}


/*******************************************************************************
* Function Name: CR2_RestoreConfig
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
void CR2_RestoreConfig(void) 
{
     CR2_Control = CR2_backup.controlState;
}


/*******************************************************************************
* Function Name: CR2_Sleep
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
void CR2_Sleep(void) 
{
    CR2_SaveConfig();
}


/*******************************************************************************
* Function Name: CR2_Wakeup
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
void CR2_Wakeup(void)  
{
    CR2_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
