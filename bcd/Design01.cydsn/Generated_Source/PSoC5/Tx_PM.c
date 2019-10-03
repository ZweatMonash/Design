/*******************************************************************************
* File Name: Tx_PM.c
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

#include "Tx.h"


Tx_BACKUP_STRUCT Tx_backup;


/*******************************************************************************
* Function Name: Tx_SaveConfig
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
*  Tx_backup - used to save component configuration and non-
*  retention registers before enter sleep mode.
*
*******************************************************************************/
void Tx_SaveConfig(void) 
{
    Tx_backup.count = Tx_COUNT_REG;
}


/*******************************************************************************
* Function Name: Tx_Sleep
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
void Tx_Sleep(void) 
{
    if(0u != (Tx_AUX_CONTROL_REG & Tx_COUNTER_START))
    {
        Tx_backup.enableState = 1u;
        Tx_Stop();
    }
    else
    {
        Tx_backup.enableState = 0u;
    }

    Tx_SaveConfig();
}


/*******************************************************************************
* Function Name: Tx_RestoreConfig
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
*  Tx_backup - used to save component configuration and
*  non-retention registers before exit sleep mode.
*
*******************************************************************************/
void Tx_RestoreConfig(void) 
{
    Tx_COUNT_REG = Tx_backup.count;
}


/*******************************************************************************
* Function Name: Tx_Wakeup
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
void Tx_Wakeup(void) 
{
    Tx_RestoreConfig();

    /* Restore enable state */
    if (Tx_backup.enableState != 0u)
    {
        Tx_Enable();
    }
}


/* [] END OF FILE */
