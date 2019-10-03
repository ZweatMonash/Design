/*******************************************************************************
* File Name: Compare.c
* Version 2.0
*
* Description:
*  This file provides the power management source code APIs for the
*  Comparator.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Compare.h"

static Compare_backupStruct Compare_backup;


/*******************************************************************************
* Function Name: Compare_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
*******************************************************************************/
void Compare_SaveConfig(void) 
{
    /* Empty since all are system reset for retention flops */
}


/*******************************************************************************
* Function Name: Compare_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
********************************************************************************/
void Compare_RestoreConfig(void) 
{
    /* Empty since all are system reset for retention flops */    
}


/*******************************************************************************
* Function Name: Compare_Sleep
********************************************************************************
*
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
* Global variables:
*  Compare_backup.enableState:  Is modified depending on the enable 
*   state of the block before entering sleep mode.
*
*******************************************************************************/
void Compare_Sleep(void) 
{
    /* Save Comp's enable state */    
    if(Compare_ACT_PWR_EN == (Compare_PWRMGR & Compare_ACT_PWR_EN))
    {
        /* Comp is enabled */
        Compare_backup.enableState = 1u;
    }
    else
    {
        /* Comp is disabled */
        Compare_backup.enableState = 0u;
    }    
    
    Compare_Stop();
    Compare_SaveConfig();
}


/*******************************************************************************
* Function Name: Compare_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Compare_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Compare_Wakeup(void) 
{
    Compare_RestoreConfig();
    
    if(Compare_backup.enableState == 1u)
    {
        /* Enable Comp's operation */
        Compare_Enable();

    } /* Do nothing if Comp was disabled before */ 
}


/* [] END OF FILE */
