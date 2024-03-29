/*******************************************************************************
* File Name: Timer_Four_Sec_PM.c
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

#include "Timer_Four_Sec.h"

static Timer_Four_Sec_backupStruct Timer_Four_Sec_backup;


/*******************************************************************************
* Function Name: Timer_Four_Sec_SaveConfig
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
*  Timer_Four_Sec_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_Four_Sec_SaveConfig(void) 
{
    #if (!Timer_Four_Sec_UsingFixedFunction)
        Timer_Four_Sec_backup.TimerUdb = Timer_Four_Sec_ReadCounter();
        Timer_Four_Sec_backup.InterruptMaskValue = Timer_Four_Sec_STATUS_MASK;
        #if (Timer_Four_Sec_UsingHWCaptureCounter)
            Timer_Four_Sec_backup.TimerCaptureCounter = Timer_Four_Sec_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_Four_Sec_UDB_CONTROL_REG_REMOVED)
            Timer_Four_Sec_backup.TimerControlRegister = Timer_Four_Sec_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_Four_Sec_RestoreConfig
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
*  Timer_Four_Sec_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Four_Sec_RestoreConfig(void) 
{   
    #if (!Timer_Four_Sec_UsingFixedFunction)

        Timer_Four_Sec_WriteCounter(Timer_Four_Sec_backup.TimerUdb);
        Timer_Four_Sec_STATUS_MASK =Timer_Four_Sec_backup.InterruptMaskValue;
        #if (Timer_Four_Sec_UsingHWCaptureCounter)
            Timer_Four_Sec_SetCaptureCount(Timer_Four_Sec_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_Four_Sec_UDB_CONTROL_REG_REMOVED)
            Timer_Four_Sec_WriteControlRegister(Timer_Four_Sec_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_Four_Sec_Sleep
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
*  Timer_Four_Sec_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_Four_Sec_Sleep(void) 
{
    #if(!Timer_Four_Sec_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_Four_Sec_CTRL_ENABLE == (Timer_Four_Sec_CONTROL & Timer_Four_Sec_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_Four_Sec_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_Four_Sec_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_Four_Sec_Stop();
    Timer_Four_Sec_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_Four_Sec_Wakeup
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
*  Timer_Four_Sec_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Four_Sec_Wakeup(void) 
{
    Timer_Four_Sec_RestoreConfig();
    #if(!Timer_Four_Sec_UDB_CONTROL_REG_REMOVED)
        if(Timer_Four_Sec_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_Four_Sec_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
