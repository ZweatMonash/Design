/*******************************************************************************
* File Name: Pulse_Count_PM.c
* Version 1.0
*
* Description:
*  This file provides Low power mode APIs for Count7 component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Pulse_Count.h"


Pulse_Count_BACKUP_STRUCT Pulse_Count_backup;


/*******************************************************************************
* Function Name: Pulse_Count_SaveConfig
********************************************************************************
*
* Summary:
*  This function saves the component configuration and non-retention registers.
*  This function is called by the Count7_Sleep() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  Pulse_Count_backup - used to save component configuration and non-
*  retention registers before enter sleep mode.
*
*******************************************************************************/
void Pulse_Count_SaveConfig(void) 
{
    Pulse_Count_backup.count = Pulse_Count_COUNT_REG;
}


/*******************************************************************************
* Function Name: Pulse_Count_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for low power mode
*  operation. The Count7_Sleep() API saves the current component state using
*  Count7_SaveConfig() and disables the counter.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Pulse_Count_Sleep(void) 
{
    if(0u != (Pulse_Count_AUX_CONTROL_REG & Pulse_Count_COUNTER_START))
    {
        Pulse_Count_backup.enableState = 1u;
        Pulse_Count_Stop();
    }
    else
    {
        Pulse_Count_backup.enableState = 0u;
    }

    Pulse_Count_SaveConfig();
}


/*******************************************************************************
* Function Name: Pulse_Count_RestoreConfig
********************************************************************************
*
* Summary:
*  This function restores the component configuration and non-retention
*  registers. This function is called by the Count7_Wakeup() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  Pulse_Count_backup - used to save component configuration and
*  non-retention registers before exit sleep mode.
*
*******************************************************************************/
void Pulse_Count_RestoreConfig(void) 
{
    Pulse_Count_COUNT_REG = Pulse_Count_backup.count;
}


/*******************************************************************************
* Function Name: Pulse_Count_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when
*  Count7_Sleep() was called. The Count7_Wakeup() function calls the
*  Count7_RestoreConfig() function to restore the configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Pulse_Count_Wakeup(void) 
{
    Pulse_Count_RestoreConfig();

    /* Restore enable state */
    if (Pulse_Count_backup.enableState != 0u)
    {
        Pulse_Count_Enable();
    }
}


/* [] END OF FILE */
