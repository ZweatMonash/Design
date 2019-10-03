/*******************************************************************************
* File Name: DAC_High_PM.c  
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

#include "DAC_High.h"

static DAC_High_backupStruct DAC_High_backup;


/*******************************************************************************
* Function Name: DAC_High_SaveConfig
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
void DAC_High_SaveConfig(void) 
{
    if (!((DAC_High_CR1 & DAC_High_SRC_MASK) == DAC_High_SRC_UDB))
    {
        DAC_High_backup.data_value = DAC_High_Data;
    }
}


/*******************************************************************************
* Function Name: DAC_High_RestoreConfig
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
void DAC_High_RestoreConfig(void) 
{
    if (!((DAC_High_CR1 & DAC_High_SRC_MASK) == DAC_High_SRC_UDB))
    {
        if((DAC_High_Strobe & DAC_High_STRB_MASK) == DAC_High_STRB_EN)
        {
            DAC_High_Strobe &= (uint8)(~DAC_High_STRB_MASK);
            DAC_High_Data = DAC_High_backup.data_value;
            DAC_High_Strobe |= DAC_High_STRB_EN;
        }
        else
        {
            DAC_High_Data = DAC_High_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: DAC_High_Sleep
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
*  DAC_High_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void DAC_High_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(DAC_High_ACT_PWR_EN == (DAC_High_PWRMGR & DAC_High_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        DAC_High_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        DAC_High_backup.enableState = 0u;
    }
    
    DAC_High_Stop();
    DAC_High_SaveConfig();
}


/*******************************************************************************
* Function Name: DAC_High_Wakeup
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
*  DAC_High_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void DAC_High_Wakeup(void) 
{
    DAC_High_RestoreConfig();
    
    if(DAC_High_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        DAC_High_Enable();

        /* Restore the data register */
        DAC_High_SetValue(DAC_High_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
