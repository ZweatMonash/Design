/*******************************************************************************
* File Name: Buzzer_Timer_PM.c
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

#include "Buzzer_Timer.h"

static Buzzer_Timer_backupStruct Buzzer_Timer_backup;


/*******************************************************************************
* Function Name: Buzzer_Timer_SaveConfig
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
*  Buzzer_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Buzzer_Timer_SaveConfig(void) 
{
    #if (!Buzzer_Timer_UsingFixedFunction)
        Buzzer_Timer_backup.TimerUdb = Buzzer_Timer_ReadCounter();
        Buzzer_Timer_backup.InterruptMaskValue = Buzzer_Timer_STATUS_MASK;
        #if (Buzzer_Timer_UsingHWCaptureCounter)
            Buzzer_Timer_backup.TimerCaptureCounter = Buzzer_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Buzzer_Timer_UDB_CONTROL_REG_REMOVED)
            Buzzer_Timer_backup.TimerControlRegister = Buzzer_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Buzzer_Timer_RestoreConfig
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
*  Buzzer_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Buzzer_Timer_RestoreConfig(void) 
{   
    #if (!Buzzer_Timer_UsingFixedFunction)

        Buzzer_Timer_WriteCounter(Buzzer_Timer_backup.TimerUdb);
        Buzzer_Timer_STATUS_MASK =Buzzer_Timer_backup.InterruptMaskValue;
        #if (Buzzer_Timer_UsingHWCaptureCounter)
            Buzzer_Timer_SetCaptureCount(Buzzer_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Buzzer_Timer_UDB_CONTROL_REG_REMOVED)
            Buzzer_Timer_WriteControlRegister(Buzzer_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Buzzer_Timer_Sleep
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
*  Buzzer_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Buzzer_Timer_Sleep(void) 
{
    #if(!Buzzer_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Buzzer_Timer_CTRL_ENABLE == (Buzzer_Timer_CONTROL & Buzzer_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Buzzer_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Buzzer_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Buzzer_Timer_Stop();
    Buzzer_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Buzzer_Timer_Wakeup
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
*  Buzzer_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Buzzer_Timer_Wakeup(void) 
{
    Buzzer_Timer_RestoreConfig();
    #if(!Buzzer_Timer_UDB_CONTROL_REG_REMOVED)
        if(Buzzer_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Buzzer_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
