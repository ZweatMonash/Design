/*******************************************************************************
* File Name: PWM_lw_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_lw.h"

static PWM_lw_backupStruct PWM_lw_backup;


/*******************************************************************************
* Function Name: PWM_lw_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_lw_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_lw_SaveConfig(void) 
{

    #if(!PWM_lw_UsingFixedFunction)
        #if(!PWM_lw_PWMModeIsCenterAligned)
            PWM_lw_backup.PWMPeriod = PWM_lw_ReadPeriod();
        #endif /* (!PWM_lw_PWMModeIsCenterAligned) */
        PWM_lw_backup.PWMUdb = PWM_lw_ReadCounter();
        #if (PWM_lw_UseStatus)
            PWM_lw_backup.InterruptMaskValue = PWM_lw_STATUS_MASK;
        #endif /* (PWM_lw_UseStatus) */

        #if(PWM_lw_DeadBandMode == PWM_lw__B_PWM__DBM_256_CLOCKS || \
            PWM_lw_DeadBandMode == PWM_lw__B_PWM__DBM_2_4_CLOCKS)
            PWM_lw_backup.PWMdeadBandValue = PWM_lw_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_lw_KillModeMinTime)
             PWM_lw_backup.PWMKillCounterPeriod = PWM_lw_ReadKillTime();
        #endif /* (PWM_lw_KillModeMinTime) */

        #if(PWM_lw_UseControl)
            PWM_lw_backup.PWMControlRegister = PWM_lw_ReadControlRegister();
        #endif /* (PWM_lw_UseControl) */
    #endif  /* (!PWM_lw_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_lw_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_lw_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_lw_RestoreConfig(void) 
{
        #if(!PWM_lw_UsingFixedFunction)
            #if(!PWM_lw_PWMModeIsCenterAligned)
                PWM_lw_WritePeriod(PWM_lw_backup.PWMPeriod);
            #endif /* (!PWM_lw_PWMModeIsCenterAligned) */

            PWM_lw_WriteCounter(PWM_lw_backup.PWMUdb);

            #if (PWM_lw_UseStatus)
                PWM_lw_STATUS_MASK = PWM_lw_backup.InterruptMaskValue;
            #endif /* (PWM_lw_UseStatus) */

            #if(PWM_lw_DeadBandMode == PWM_lw__B_PWM__DBM_256_CLOCKS || \
                PWM_lw_DeadBandMode == PWM_lw__B_PWM__DBM_2_4_CLOCKS)
                PWM_lw_WriteDeadTime(PWM_lw_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_lw_KillModeMinTime)
                PWM_lw_WriteKillTime(PWM_lw_backup.PWMKillCounterPeriod);
            #endif /* (PWM_lw_KillModeMinTime) */

            #if(PWM_lw_UseControl)
                PWM_lw_WriteControlRegister(PWM_lw_backup.PWMControlRegister);
            #endif /* (PWM_lw_UseControl) */
        #endif  /* (!PWM_lw_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_lw_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_lw_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_lw_Sleep(void) 
{
    #if(PWM_lw_UseControl)
        if(PWM_lw_CTRL_ENABLE == (PWM_lw_CONTROL & PWM_lw_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_lw_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_lw_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_lw_UseControl) */

    /* Stop component */
    PWM_lw_Stop();

    /* Save registers configuration */
    PWM_lw_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_lw_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_lw_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_lw_Wakeup(void) 
{
     /* Restore registers values */
    PWM_lw_RestoreConfig();

    if(PWM_lw_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_lw_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
