/*******************************************************************************
* File Name: PWM_lift_PM.c
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

#include "PWM_lift.h"

static PWM_lift_backupStruct PWM_lift_backup;


/*******************************************************************************
* Function Name: PWM_lift_SaveConfig
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
*  PWM_lift_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_lift_SaveConfig(void) 
{

    #if(!PWM_lift_UsingFixedFunction)
        #if(!PWM_lift_PWMModeIsCenterAligned)
            PWM_lift_backup.PWMPeriod = PWM_lift_ReadPeriod();
        #endif /* (!PWM_lift_PWMModeIsCenterAligned) */
        PWM_lift_backup.PWMUdb = PWM_lift_ReadCounter();
        #if (PWM_lift_UseStatus)
            PWM_lift_backup.InterruptMaskValue = PWM_lift_STATUS_MASK;
        #endif /* (PWM_lift_UseStatus) */

        #if(PWM_lift_DeadBandMode == PWM_lift__B_PWM__DBM_256_CLOCKS || \
            PWM_lift_DeadBandMode == PWM_lift__B_PWM__DBM_2_4_CLOCKS)
            PWM_lift_backup.PWMdeadBandValue = PWM_lift_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_lift_KillModeMinTime)
             PWM_lift_backup.PWMKillCounterPeriod = PWM_lift_ReadKillTime();
        #endif /* (PWM_lift_KillModeMinTime) */

        #if(PWM_lift_UseControl)
            PWM_lift_backup.PWMControlRegister = PWM_lift_ReadControlRegister();
        #endif /* (PWM_lift_UseControl) */
    #endif  /* (!PWM_lift_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_lift_RestoreConfig
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
*  PWM_lift_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_lift_RestoreConfig(void) 
{
        #if(!PWM_lift_UsingFixedFunction)
            #if(!PWM_lift_PWMModeIsCenterAligned)
                PWM_lift_WritePeriod(PWM_lift_backup.PWMPeriod);
            #endif /* (!PWM_lift_PWMModeIsCenterAligned) */

            PWM_lift_WriteCounter(PWM_lift_backup.PWMUdb);

            #if (PWM_lift_UseStatus)
                PWM_lift_STATUS_MASK = PWM_lift_backup.InterruptMaskValue;
            #endif /* (PWM_lift_UseStatus) */

            #if(PWM_lift_DeadBandMode == PWM_lift__B_PWM__DBM_256_CLOCKS || \
                PWM_lift_DeadBandMode == PWM_lift__B_PWM__DBM_2_4_CLOCKS)
                PWM_lift_WriteDeadTime(PWM_lift_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_lift_KillModeMinTime)
                PWM_lift_WriteKillTime(PWM_lift_backup.PWMKillCounterPeriod);
            #endif /* (PWM_lift_KillModeMinTime) */

            #if(PWM_lift_UseControl)
                PWM_lift_WriteControlRegister(PWM_lift_backup.PWMControlRegister);
            #endif /* (PWM_lift_UseControl) */
        #endif  /* (!PWM_lift_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_lift_Sleep
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
*  PWM_lift_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_lift_Sleep(void) 
{
    #if(PWM_lift_UseControl)
        if(PWM_lift_CTRL_ENABLE == (PWM_lift_CONTROL & PWM_lift_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_lift_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_lift_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_lift_UseControl) */

    /* Stop component */
    PWM_lift_Stop();

    /* Save registers configuration */
    PWM_lift_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_lift_Wakeup
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
*  PWM_lift_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_lift_Wakeup(void) 
{
     /* Restore registers values */
    PWM_lift_RestoreConfig();

    if(PWM_lift_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_lift_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
