/*******************************************************************************
* File Name: CR_fing_out_en_PM.c
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

#include "CR_fing_out_en.h"

/* Check for removal by optimization */
#if !defined(CR_fing_out_en_Sync_ctrl_reg__REMOVED)

static CR_fing_out_en_BACKUP_STRUCT  CR_fing_out_en_backup = {0u};

    
/*******************************************************************************
* Function Name: CR_fing_out_en_SaveConfig
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
void CR_fing_out_en_SaveConfig(void) 
{
    CR_fing_out_en_backup.controlState = CR_fing_out_en_Control;
}


/*******************************************************************************
* Function Name: CR_fing_out_en_RestoreConfig
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
void CR_fing_out_en_RestoreConfig(void) 
{
     CR_fing_out_en_Control = CR_fing_out_en_backup.controlState;
}


/*******************************************************************************
* Function Name: CR_fing_out_en_Sleep
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
void CR_fing_out_en_Sleep(void) 
{
    CR_fing_out_en_SaveConfig();
}


/*******************************************************************************
* Function Name: CR_fing_out_en_Wakeup
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
void CR_fing_out_en_Wakeup(void)  
{
    CR_fing_out_en_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
