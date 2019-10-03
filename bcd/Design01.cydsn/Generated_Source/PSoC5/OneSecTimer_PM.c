/*******************************************************************************
* File Name: OneSecTimer_PM.c
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

#include "OneSecTimer.h"

static OneSecTimer_backupStruct OneSecTimer_backup;


/*******************************************************************************
* Function Name: OneSecTimer_SaveConfig
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
*  OneSecTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void OneSecTimer_SaveConfig(void) 
{

    #if(!OneSecTimer_UsingFixedFunction)
        #if(!OneSecTimer_PWMModeIsCenterAligned)
            OneSecTimer_backup.PWMPeriod = OneSecTimer_ReadPeriod();
        #endif /* (!OneSecTimer_PWMModeIsCenterAligned) */
        OneSecTimer_backup.PWMUdb = OneSecTimer_ReadCounter();
        #if (OneSecTimer_UseStatus)
            OneSecTimer_backup.InterruptMaskValue = OneSecTimer_STATUS_MASK;
        #endif /* (OneSecTimer_UseStatus) */

        #if(OneSecTimer_DeadBandMode == OneSecTimer__B_PWM__DBM_256_CLOCKS || \
            OneSecTimer_DeadBandMode == OneSecTimer__B_PWM__DBM_2_4_CLOCKS)
            OneSecTimer_backup.PWMdeadBandValue = OneSecTimer_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(OneSecTimer_KillModeMinTime)
             OneSecTimer_backup.PWMKillCounterPeriod = OneSecTimer_ReadKillTime();
        #endif /* (OneSecTimer_KillModeMinTime) */

        #if(OneSecTimer_UseControl)
            OneSecTimer_backup.PWMControlRegister = OneSecTimer_ReadControlRegister();
        #endif /* (OneSecTimer_UseControl) */
    #endif  /* (!OneSecTimer_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: OneSecTimer_RestoreConfig
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
*  OneSecTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void OneSecTimer_RestoreConfig(void) 
{
        #if(!OneSecTimer_UsingFixedFunction)
            #if(!OneSecTimer_PWMModeIsCenterAligned)
                OneSecTimer_WritePeriod(OneSecTimer_backup.PWMPeriod);
            #endif /* (!OneSecTimer_PWMModeIsCenterAligned) */

            OneSecTimer_WriteCounter(OneSecTimer_backup.PWMUdb);

            #if (OneSecTimer_UseStatus)
                OneSecTimer_STATUS_MASK = OneSecTimer_backup.InterruptMaskValue;
            #endif /* (OneSecTimer_UseStatus) */

            #if(OneSecTimer_DeadBandMode == OneSecTimer__B_PWM__DBM_256_CLOCKS || \
                OneSecTimer_DeadBandMode == OneSecTimer__B_PWM__DBM_2_4_CLOCKS)
                OneSecTimer_WriteDeadTime(OneSecTimer_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(OneSecTimer_KillModeMinTime)
                OneSecTimer_WriteKillTime(OneSecTimer_backup.PWMKillCounterPeriod);
            #endif /* (OneSecTimer_KillModeMinTime) */

            #if(OneSecTimer_UseControl)
                OneSecTimer_WriteControlRegister(OneSecTimer_backup.PWMControlRegister);
            #endif /* (OneSecTimer_UseControl) */
        #endif  /* (!OneSecTimer_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: OneSecTimer_Sleep
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
*  OneSecTimer_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void OneSecTimer_Sleep(void) 
{
    #if(OneSecTimer_UseControl)
        if(OneSecTimer_CTRL_ENABLE == (OneSecTimer_CONTROL & OneSecTimer_CTRL_ENABLE))
        {
            /*Component is enabled */
            OneSecTimer_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            OneSecTimer_backup.PWMEnableState = 0u;
        }
    #endif /* (OneSecTimer_UseControl) */

    /* Stop component */
    OneSecTimer_Stop();

    /* Save registers configuration */
    OneSecTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: OneSecTimer_Wakeup
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
*  OneSecTimer_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void OneSecTimer_Wakeup(void) 
{
     /* Restore registers values */
    OneSecTimer_RestoreConfig();

    if(OneSecTimer_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        OneSecTimer_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
