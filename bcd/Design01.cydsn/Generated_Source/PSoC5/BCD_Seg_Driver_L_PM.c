/*******************************************************************************
* File Name: BCD_Seg_Driver_L_PM.c
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

#include "BCD_Seg_Driver_L.h"

/* Check for removal by optimization */
#if !defined(BCD_Seg_Driver_L_Sync_ctrl_reg__REMOVED)

static BCD_Seg_Driver_L_BACKUP_STRUCT  BCD_Seg_Driver_L_backup = {0u};

    
/*******************************************************************************
* Function Name: BCD_Seg_Driver_L_SaveConfig
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
void BCD_Seg_Driver_L_SaveConfig(void) 
{
    BCD_Seg_Driver_L_backup.controlState = BCD_Seg_Driver_L_Control;
}


/*******************************************************************************
* Function Name: BCD_Seg_Driver_L_RestoreConfig
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
void BCD_Seg_Driver_L_RestoreConfig(void) 
{
     BCD_Seg_Driver_L_Control = BCD_Seg_Driver_L_backup.controlState;
}


/*******************************************************************************
* Function Name: BCD_Seg_Driver_L_Sleep
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
void BCD_Seg_Driver_L_Sleep(void) 
{
    BCD_Seg_Driver_L_SaveConfig();
}


/*******************************************************************************
* Function Name: BCD_Seg_Driver_L_Wakeup
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
void BCD_Seg_Driver_L_Wakeup(void)  
{
    BCD_Seg_Driver_L_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
