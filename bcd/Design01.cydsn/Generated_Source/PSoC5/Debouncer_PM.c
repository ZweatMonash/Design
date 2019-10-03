/*******************************************************************************
* File Name: Debouncer_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Debouncer.h"

static Debouncer_backupStruct Debouncer_backup;


/*******************************************************************************
* Function Name: Debouncer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Debouncer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Debouncer_SaveConfig(void) 
{
    #if (!Debouncer_UsingFixedFunction)
        Debouncer_backup.TimerUdb = Debouncer_ReadCounter();
        Debouncer_backup.InterruptMaskValue = Debouncer_STATUS_MASK;
        #if (Debouncer_UsingHWCaptureCounter)
            Debouncer_backup.TimerCaptureCounter = Debouncer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Debouncer_UDB_CONTROL_REG_REMOVED)
            Debouncer_backup.TimerControlRegister = Debouncer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Debouncer_RestoreConfig
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
* Global variables:
*  Debouncer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Debouncer_RestoreConfig(void) 
{   
    #if (!Debouncer_UsingFixedFunction)

        Debouncer_WriteCounter(Debouncer_backup.TimerUdb);
        Debouncer_STATUS_MASK =Debouncer_backup.InterruptMaskValue;
        #if (Debouncer_UsingHWCaptureCounter)
            Debouncer_SetCaptureCount(Debouncer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Debouncer_UDB_CONTROL_REG_REMOVED)
            Debouncer_WriteControlRegister(Debouncer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Debouncer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Debouncer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Debouncer_Sleep(void) 
{
    #if(!Debouncer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Debouncer_CTRL_ENABLE == (Debouncer_CONTROL & Debouncer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Debouncer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Debouncer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Debouncer_Stop();
    Debouncer_SaveConfig();
}


/*******************************************************************************
* Function Name: Debouncer_Wakeup
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
*  Debouncer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Debouncer_Wakeup(void) 
{
    Debouncer_RestoreConfig();
    #if(!Debouncer_UDB_CONTROL_REG_REMOVED)
        if(Debouncer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Debouncer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
