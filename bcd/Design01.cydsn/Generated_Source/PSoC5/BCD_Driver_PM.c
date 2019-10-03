/*******************************************************************************
* File Name: BCD_Driver_PM.c
* Version 1.10
*
* Description:
*  This file provides the power management source code to API for the
*  LED_Driver component.
*
* Note:
*  None
*
*******************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "BCD_Driver.h"
static BCD_Driver_backupStruct BCD_Driver_backup;


/*******************************************************************************
* Function Name: BCD_Driver_Sleep
********************************************************************************
*
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void BCD_Driver_Sleep(void) 
{
    uint8 i;
    
    /* Store the component enable state */
    BCD_Driver_backup.ledEnableState = BCD_Driver_enableVar;
    
    /* Save the segment buffers */
    for(i = 0u; i < BCD_Driver_NUM_COM; i++)
    {
        BCD_Driver_backup.segLBackup[i] = BCD_Driver_segLBuffer[i];
        #if (BCD_Driver_NUM_SEG > 8u) 
            BCD_Driver_backup.segMBackup[i] = BCD_Driver_segMBuffer[i];
        #endif /* (BCD_Driver_NUM_SEG > 8u) */
        #if (BCD_Driver_NUM_SEG > 16u) 
            BCD_Driver_backup.segHBackup[i] = BCD_Driver_segHBuffer[i];
        #endif /* (BCD_Driver_NUM_SEG > 16u) */
    }
    
    BCD_Driver_Stop();
}


/*******************************************************************************
* Function Name: BCD_Driver_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void BCD_Driver_Wakeup(void) 
{
    uint8 i;
    
    /* Restore the segment buffers */
    for(i = 0u; i < BCD_Driver_NUM_COM; i++)
    {
        BCD_Driver_segLBuffer[i] = BCD_Driver_backup.segLBackup[i];
        #if (BCD_Driver_NUM_SEG > 8u) 
            BCD_Driver_segMBuffer[i] = BCD_Driver_backup.segMBackup[i];
        #endif /* (BCD_Driver_NUM_SEG > 8u) */
        #if (BCD_Driver_NUM_SEG > 16u) 
            BCD_Driver_segHBuffer[i] = BCD_Driver_backup.segHBackup[i];
        #endif /* (BCD_Driver_NUM_SEG > 16u) */
    }
    
    if(BCD_Driver_backup.ledEnableState == BCD_Driver_ENABLED)
    {
        /* Enable the component */
        BCD_Driver_Enable();
    }
}


/* [] END OF FILE */

