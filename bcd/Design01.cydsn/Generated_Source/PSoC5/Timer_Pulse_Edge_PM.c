/*******************************************************************************
* File Name: Timer_Pulse_Edge_PM.c
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

#include "Timer_Pulse_Edge.h"

static Timer_Pulse_Edge_backupStruct Timer_Pulse_Edge_backup;


/*******************************************************************************
* Function Name: Timer_Pulse_Edge_SaveConfig
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
*  Timer_Pulse_Edge_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_Pulse_Edge_SaveConfig(void) 
{
    #if (!Timer_Pulse_Edge_UsingFixedFunction)
        Timer_Pulse_Edge_backup.TimerUdb = Timer_Pulse_Edge_ReadCounter();
        Timer_Pulse_Edge_backup.InterruptMaskValue = Timer_Pulse_Edge_STATUS_MASK;
        #if (Timer_Pulse_Edge_UsingHWCaptureCounter)
            Timer_Pulse_Edge_backup.TimerCaptureCounter = Timer_Pulse_Edge_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_Pulse_Edge_UDB_CONTROL_REG_REMOVED)
            Timer_Pulse_Edge_backup.TimerControlRegister = Timer_Pulse_Edge_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_Pulse_Edge_RestoreConfig
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
*  Timer_Pulse_Edge_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Pulse_Edge_RestoreConfig(void) 
{   
    #if (!Timer_Pulse_Edge_UsingFixedFunction)

        Timer_Pulse_Edge_WriteCounter(Timer_Pulse_Edge_backup.TimerUdb);
        Timer_Pulse_Edge_STATUS_MASK =Timer_Pulse_Edge_backup.InterruptMaskValue;
        #if (Timer_Pulse_Edge_UsingHWCaptureCounter)
            Timer_Pulse_Edge_SetCaptureCount(Timer_Pulse_Edge_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_Pulse_Edge_UDB_CONTROL_REG_REMOVED)
            Timer_Pulse_Edge_WriteControlRegister(Timer_Pulse_Edge_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_Pulse_Edge_Sleep
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
*  Timer_Pulse_Edge_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_Pulse_Edge_Sleep(void) 
{
    #if(!Timer_Pulse_Edge_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_Pulse_Edge_CTRL_ENABLE == (Timer_Pulse_Edge_CONTROL & Timer_Pulse_Edge_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_Pulse_Edge_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_Pulse_Edge_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_Pulse_Edge_Stop();
    Timer_Pulse_Edge_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_Pulse_Edge_Wakeup
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
*  Timer_Pulse_Edge_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Pulse_Edge_Wakeup(void) 
{
    Timer_Pulse_Edge_RestoreConfig();
    #if(!Timer_Pulse_Edge_UDB_CONTROL_REG_REMOVED)
        if(Timer_Pulse_Edge_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_Pulse_Edge_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
