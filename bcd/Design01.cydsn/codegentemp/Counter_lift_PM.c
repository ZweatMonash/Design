/*******************************************************************************
* File Name: Counter_lift_PM.c  
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

#include "Counter_lift.h"

static Counter_lift_backupStruct Counter_lift_backup;


/*******************************************************************************
* Function Name: Counter_lift_SaveConfig
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
*  Counter_lift_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Counter_lift_SaveConfig(void) 
{
    #if (!Counter_lift_UsingFixedFunction)

        Counter_lift_backup.CounterUdb = Counter_lift_ReadCounter();

        #if(!Counter_lift_ControlRegRemoved)
            Counter_lift_backup.CounterControlRegister = Counter_lift_ReadControlRegister();
        #endif /* (!Counter_lift_ControlRegRemoved) */

    #endif /* (!Counter_lift_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_lift_RestoreConfig
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
*  Counter_lift_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_lift_RestoreConfig(void) 
{      
    #if (!Counter_lift_UsingFixedFunction)

       Counter_lift_WriteCounter(Counter_lift_backup.CounterUdb);

        #if(!Counter_lift_ControlRegRemoved)
            Counter_lift_WriteControlRegister(Counter_lift_backup.CounterControlRegister);
        #endif /* (!Counter_lift_ControlRegRemoved) */

    #endif /* (!Counter_lift_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_lift_Sleep
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
*  Counter_lift_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Counter_lift_Sleep(void) 
{
    #if(!Counter_lift_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Counter_lift_CTRL_ENABLE == (Counter_lift_CONTROL & Counter_lift_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Counter_lift_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Counter_lift_backup.CounterEnableState = 0u;
        }
    #else
        Counter_lift_backup.CounterEnableState = 1u;
        if(Counter_lift_backup.CounterEnableState != 0u)
        {
            Counter_lift_backup.CounterEnableState = 0u;
        }
    #endif /* (!Counter_lift_ControlRegRemoved) */
    
    Counter_lift_Stop();
    Counter_lift_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_lift_Wakeup
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
*  Counter_lift_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_lift_Wakeup(void) 
{
    Counter_lift_RestoreConfig();
    #if(!Counter_lift_ControlRegRemoved)
        if(Counter_lift_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Counter_lift_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Counter_lift_ControlRegRemoved) */
    
}


/* [] END OF FILE */
