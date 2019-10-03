/*******************************************************************************
* File Name: PWM_rw_PM.c
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

#include "PWM_rw.h"

static PWM_rw_backupStruct PWM_rw_backup;


/*******************************************************************************
* Function Name: PWM_rw_SaveConfig
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
*  PWM_rw_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_rw_SaveConfig(void) 
{

    #if(!PWM_rw_UsingFixedFunction)
        #if(!PWM_rw_PWMModeIsCenterAligned)
            PWM_rw_backup.PWMPeriod = PWM_rw_ReadPeriod();
        #endif /* (!PWM_rw_PWMModeIsCenterAligned) */
        PWM_rw_backup.PWMUdb = PWM_rw_ReadCounter();
        #if (PWM_rw_UseStatus)
            PWM_rw_backup.InterruptMaskValue = PWM_rw_STATUS_MASK;
        #endif /* (PWM_rw_UseStatus) */

        #if(PWM_rw_DeadBandMode == PWM_rw__B_PWM__DBM_256_CLOCKS || \
            PWM_rw_DeadBandMode == PWM_rw__B_PWM__DBM_2_4_CLOCKS)
            PWM_rw_backup.PWMdeadBandValue = PWM_rw_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_rw_KillModeMinTime)
             PWM_rw_backup.PWMKillCounterPeriod = PWM_rw_ReadKillTime();
        #endif /* (PWM_rw_KillModeMinTime) */

        #if(PWM_rw_UseControl)
            PWM_rw_backup.PWMControlRegister = PWM_rw_ReadControlRegister();
        #endif /* (PWM_rw_UseControl) */
    #endif  /* (!PWM_rw_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_rw_RestoreConfig
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
*  PWM_rw_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_rw_RestoreConfig(void) 
{
        #if(!PWM_rw_UsingFixedFunction)
            #if(!PWM_rw_PWMModeIsCenterAligned)
                PWM_rw_WritePeriod(PWM_rw_backup.PWMPeriod);
            #endif /* (!PWM_rw_PWMModeIsCenterAligned) */

            PWM_rw_WriteCounter(PWM_rw_backup.PWMUdb);

            #if (PWM_rw_UseStatus)
                PWM_rw_STATUS_MASK = PWM_rw_backup.InterruptMaskValue;
            #endif /* (PWM_rw_UseStatus) */

            #if(PWM_rw_DeadBandMode == PWM_rw__B_PWM__DBM_256_CLOCKS || \
                PWM_rw_DeadBandMode == PWM_rw__B_PWM__DBM_2_4_CLOCKS)
                PWM_rw_WriteDeadTime(PWM_rw_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_rw_KillModeMinTime)
                PWM_rw_WriteKillTime(PWM_rw_backup.PWMKillCounterPeriod);
            #endif /* (PWM_rw_KillModeMinTime) */

            #if(PWM_rw_UseControl)
                PWM_rw_WriteControlRegister(PWM_rw_backup.PWMControlRegister);
            #endif /* (PWM_rw_UseControl) */
        #endif  /* (!PWM_rw_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_rw_Sleep
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
*  PWM_rw_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_rw_Sleep(void) 
{
    #if(PWM_rw_UseControl)
        if(PWM_rw_CTRL_ENABLE == (PWM_rw_CONTROL & PWM_rw_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_rw_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_rw_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_rw_UseControl) */

    /* Stop component */
    PWM_rw_Stop();

    /* Save registers configuration */
    PWM_rw_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_rw_Wakeup
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
*  PWM_rw_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_rw_Wakeup(void) 
{
     /* Restore registers values */
    PWM_rw_RestoreConfig();

    if(PWM_rw_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_rw_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
