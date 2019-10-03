/*******************************************************************************
* File Name: DAC_Fing_In_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "DAC_Fing_In.h"

static DAC_Fing_In_backupStruct DAC_Fing_In_backup;


/*******************************************************************************
* Function Name: DAC_Fing_In_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void DAC_Fing_In_SaveConfig(void) 
{
    if (!((DAC_Fing_In_CR1 & DAC_Fing_In_SRC_MASK) == DAC_Fing_In_SRC_UDB))
    {
        DAC_Fing_In_backup.data_value = DAC_Fing_In_Data;
    }
}


/*******************************************************************************
* Function Name: DAC_Fing_In_RestoreConfig
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
*******************************************************************************/
void DAC_Fing_In_RestoreConfig(void) 
{
    if (!((DAC_Fing_In_CR1 & DAC_Fing_In_SRC_MASK) == DAC_Fing_In_SRC_UDB))
    {
        if((DAC_Fing_In_Strobe & DAC_Fing_In_STRB_MASK) == DAC_Fing_In_STRB_EN)
        {
            DAC_Fing_In_Strobe &= (uint8)(~DAC_Fing_In_STRB_MASK);
            DAC_Fing_In_Data = DAC_Fing_In_backup.data_value;
            DAC_Fing_In_Strobe |= DAC_Fing_In_STRB_EN;
        }
        else
        {
            DAC_Fing_In_Data = DAC_Fing_In_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: DAC_Fing_In_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  DAC_Fing_In_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void DAC_Fing_In_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(DAC_Fing_In_ACT_PWR_EN == (DAC_Fing_In_PWRMGR & DAC_Fing_In_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        DAC_Fing_In_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        DAC_Fing_In_backup.enableState = 0u;
    }
    
    DAC_Fing_In_Stop();
    DAC_Fing_In_SaveConfig();
}


/*******************************************************************************
* Function Name: DAC_Fing_In_Wakeup
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
*  DAC_Fing_In_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void DAC_Fing_In_Wakeup(void) 
{
    DAC_Fing_In_RestoreConfig();
    
    if(DAC_Fing_In_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        DAC_Fing_In_Enable();

        /* Restore the data register */
        DAC_Fing_In_SetValue(DAC_Fing_In_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
