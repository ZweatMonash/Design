/*******************************************************************************
* File Name: Pulse_Counter_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Pulse_Counter.h"

static Pulse_Counter_backupStruct Pulse_Counter_backup;


/*******************************************************************************
* Function Name: Pulse_Counter_SaveConfig
********************************************************************************
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
*  Pulse_Counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Pulse_Counter_SaveConfig(void) 
{
    #if (!Pulse_Counter_UsingFixedFunction)

        Pulse_Counter_backup.CounterUdb = Pulse_Counter_ReadCounter();

        #if(!Pulse_Counter_ControlRegRemoved)
            Pulse_Counter_backup.CounterControlRegister = Pulse_Counter_ReadControlRegister();
        #endif /* (!Pulse_Counter_ControlRegRemoved) */

    #endif /* (!Pulse_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Pulse_Counter_RestoreConfig
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
*  Pulse_Counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Pulse_Counter_RestoreConfig(void) 
{      
    #if (!Pulse_Counter_UsingFixedFunction)

       Pulse_Counter_WriteCounter(Pulse_Counter_backup.CounterUdb);

        #if(!Pulse_Counter_ControlRegRemoved)
            Pulse_Counter_WriteControlRegister(Pulse_Counter_backup.CounterControlRegister);
        #endif /* (!Pulse_Counter_ControlRegRemoved) */

    #endif /* (!Pulse_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Pulse_Counter_Sleep
********************************************************************************
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
*  Pulse_Counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Pulse_Counter_Sleep(void) 
{
    #if(!Pulse_Counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Pulse_Counter_CTRL_ENABLE == (Pulse_Counter_CONTROL & Pulse_Counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Pulse_Counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Pulse_Counter_backup.CounterEnableState = 0u;
        }
    #else
        Pulse_Counter_backup.CounterEnableState = 1u;
        if(Pulse_Counter_backup.CounterEnableState != 0u)
        {
            Pulse_Counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!Pulse_Counter_ControlRegRemoved) */
    
    Pulse_Counter_Stop();
    Pulse_Counter_SaveConfig();
}


/*******************************************************************************
* Function Name: Pulse_Counter_Wakeup
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
*  Pulse_Counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Pulse_Counter_Wakeup(void) 
{
    Pulse_Counter_RestoreConfig();
    #if(!Pulse_Counter_ControlRegRemoved)
        if(Pulse_Counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Pulse_Counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Pulse_Counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
