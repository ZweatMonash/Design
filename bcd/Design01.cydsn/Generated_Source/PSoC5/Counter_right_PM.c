/*******************************************************************************
* File Name: Counter_right_PM.c  
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

#include "Counter_right.h"

static Counter_right_backupStruct Counter_right_backup;


/*******************************************************************************
* Function Name: Counter_right_SaveConfig
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
*  Counter_right_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Counter_right_SaveConfig(void) 
{
    #if (!Counter_right_UsingFixedFunction)

        Counter_right_backup.CounterUdb = Counter_right_ReadCounter();

        #if(!Counter_right_ControlRegRemoved)
            Counter_right_backup.CounterControlRegister = Counter_right_ReadControlRegister();
        #endif /* (!Counter_right_ControlRegRemoved) */

    #endif /* (!Counter_right_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_right_RestoreConfig
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
*  Counter_right_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_right_RestoreConfig(void) 
{      
    #if (!Counter_right_UsingFixedFunction)

       Counter_right_WriteCounter(Counter_right_backup.CounterUdb);

        #if(!Counter_right_ControlRegRemoved)
            Counter_right_WriteControlRegister(Counter_right_backup.CounterControlRegister);
        #endif /* (!Counter_right_ControlRegRemoved) */

    #endif /* (!Counter_right_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_right_Sleep
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
*  Counter_right_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Counter_right_Sleep(void) 
{
    #if(!Counter_right_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Counter_right_CTRL_ENABLE == (Counter_right_CONTROL & Counter_right_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Counter_right_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Counter_right_backup.CounterEnableState = 0u;
        }
    #else
        Counter_right_backup.CounterEnableState = 1u;
        if(Counter_right_backup.CounterEnableState != 0u)
        {
            Counter_right_backup.CounterEnableState = 0u;
        }
    #endif /* (!Counter_right_ControlRegRemoved) */
    
    Counter_right_Stop();
    Counter_right_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_right_Wakeup
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
*  Counter_right_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_right_Wakeup(void) 
{
    Counter_right_RestoreConfig();
    #if(!Counter_right_ControlRegRemoved)
        if(Counter_right_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Counter_right_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Counter_right_ControlRegRemoved) */
    
}


/* [] END OF FILE */
