/*******************************************************************************
* File Name: FreqCount_PM.c  
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

#include "FreqCount.h"

static FreqCount_backupStruct FreqCount_backup;


/*******************************************************************************
* Function Name: FreqCount_SaveConfig
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
*  FreqCount_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void FreqCount_SaveConfig(void) 
{
    #if (!FreqCount_UsingFixedFunction)

        FreqCount_backup.CounterUdb = FreqCount_ReadCounter();

        #if(!FreqCount_ControlRegRemoved)
            FreqCount_backup.CounterControlRegister = FreqCount_ReadControlRegister();
        #endif /* (!FreqCount_ControlRegRemoved) */

    #endif /* (!FreqCount_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: FreqCount_RestoreConfig
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
*  FreqCount_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void FreqCount_RestoreConfig(void) 
{      
    #if (!FreqCount_UsingFixedFunction)

       FreqCount_WriteCounter(FreqCount_backup.CounterUdb);

        #if(!FreqCount_ControlRegRemoved)
            FreqCount_WriteControlRegister(FreqCount_backup.CounterControlRegister);
        #endif /* (!FreqCount_ControlRegRemoved) */

    #endif /* (!FreqCount_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: FreqCount_Sleep
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
*  FreqCount_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void FreqCount_Sleep(void) 
{
    #if(!FreqCount_ControlRegRemoved)
        /* Save Counter's enable state */
        if(FreqCount_CTRL_ENABLE == (FreqCount_CONTROL & FreqCount_CTRL_ENABLE))
        {
            /* Counter is enabled */
            FreqCount_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            FreqCount_backup.CounterEnableState = 0u;
        }
    #else
        FreqCount_backup.CounterEnableState = 1u;
        if(FreqCount_backup.CounterEnableState != 0u)
        {
            FreqCount_backup.CounterEnableState = 0u;
        }
    #endif /* (!FreqCount_ControlRegRemoved) */
    
    FreqCount_Stop();
    FreqCount_SaveConfig();
}


/*******************************************************************************
* Function Name: FreqCount_Wakeup
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
*  FreqCount_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void FreqCount_Wakeup(void) 
{
    FreqCount_RestoreConfig();
    #if(!FreqCount_ControlRegRemoved)
        if(FreqCount_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            FreqCount_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!FreqCount_ControlRegRemoved) */
    
}


/* [] END OF FILE */
