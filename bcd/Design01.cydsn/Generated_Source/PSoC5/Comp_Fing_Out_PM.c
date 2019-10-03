/*******************************************************************************
* File Name: Comp_Fing_Out.c
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

#include "Comp_Fing_Out.h"

static Comp_Fing_Out_backupStruct Comp_Fing_Out_backup;


/*******************************************************************************
* Function Name: Comp_Fing_Out_SaveConfig
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
void Comp_Fing_Out_SaveConfig(void) 
{
    /* Empty since all are system reset for retention flops */
}


/*******************************************************************************
* Function Name: Comp_Fing_Out_RestoreConfig
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
void Comp_Fing_Out_RestoreConfig(void) 
{
    /* Empty since all are system reset for retention flops */    
}


/*******************************************************************************
* Function Name: Comp_Fing_Out_Sleep
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
*  Comp_Fing_Out_backup.enableState:  Is modified depending on the enable 
*   state of the block before entering sleep mode.
*
*******************************************************************************/
void Comp_Fing_Out_Sleep(void) 
{
    /* Save Comp's enable state */    
    if(Comp_Fing_Out_ACT_PWR_EN == (Comp_Fing_Out_PWRMGR & Comp_Fing_Out_ACT_PWR_EN))
    {
        /* Comp is enabled */
        Comp_Fing_Out_backup.enableState = 1u;
    }
    else
    {
        /* Comp is disabled */
        Comp_Fing_Out_backup.enableState = 0u;
    }    
    
    Comp_Fing_Out_Stop();
    Comp_Fing_Out_SaveConfig();
}


/*******************************************************************************
* Function Name: Comp_Fing_Out_Wakeup
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
*  Comp_Fing_Out_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Comp_Fing_Out_Wakeup(void) 
{
    Comp_Fing_Out_RestoreConfig();
    
    if(Comp_Fing_Out_backup.enableState == 1u)
    {
        /* Enable Comp's operation */
        Comp_Fing_Out_Enable();

    } /* Do nothing if Comp was disabled before */ 
}


/* [] END OF FILE */
