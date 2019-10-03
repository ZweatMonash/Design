/*******************************************************************************
* File Name: Counter_left_PM.c  
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

#include "Counter_left.h"

static Counter_left_backupStruct Counter_left_backup;


/*******************************************************************************
* Function Name: Counter_left_SaveConfig
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
*  Counter_left_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Counter_left_SaveConfig(void) 
{
    #if (!Counter_left_UsingFixedFunction)

        Counter_left_backup.CounterUdb = Counter_left_ReadCounter();

        #if(!Counter_left_ControlRegRemoved)
            Counter_left_backup.CounterControlRegister = Counter_left_ReadControlRegister();
        #endif /* (!Counter_left_ControlRegRemoved) */

    #endif /* (!Counter_left_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_left_RestoreConfig
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
*  Counter_left_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_left_RestoreConfig(void) 
{      
    #if (!Counter_left_UsingFixedFunction)

       Counter_left_WriteCounter(Counter_left_backup.CounterUdb);

        #if(!Counter_left_ControlRegRemoved)
            Counter_left_WriteControlRegister(Counter_left_backup.CounterControlRegister);
        #endif /* (!Counter_left_ControlRegRemoved) */

    #endif /* (!Counter_left_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_left_Sleep
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
*  Counter_left_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Counter_left_Sleep(void) 
{
    #if(!Counter_left_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Counter_left_CTRL_ENABLE == (Counter_left_CONTROL & Counter_left_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Counter_left_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Counter_left_backup.CounterEnableState = 0u;
        }
    #else
        Counter_left_backup.CounterEnableState = 1u;
        if(Counter_left_backup.CounterEnableState != 0u)
        {
            Counter_left_backup.CounterEnableState = 0u;
        }
    #endif /* (!Counter_left_ControlRegRemoved) */
    
    Counter_left_Stop();
    Counter_left_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_left_Wakeup
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
*  Counter_left_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_left_Wakeup(void) 
{
    Counter_left_RestoreConfig();
    #if(!Counter_left_ControlRegRemoved)
        if(Counter_left_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Counter_left_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Counter_left_ControlRegRemoved) */
    
}


/* [] END OF FILE */
