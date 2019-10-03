/*******************************************************************************
* File Name: BCD_PM.c
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

#include "BCD.h"
static BCD_backupStruct BCD_backup;


/*******************************************************************************
* Function Name: BCD_Sleep
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
void BCD_Sleep(void) 
{
    uint8 i;
    
    /* Store the component enable state */
    BCD_backup.ledEnableState = BCD_enableVar;
    
    /* Save the segment buffers */
    for(i = 0u; i < BCD_NUM_COM; i++)
    {
        BCD_backup.segLBackup[i] = BCD_segLBuffer[i];
        #if (BCD_NUM_SEG > 8u) 
            BCD_backup.segMBackup[i] = BCD_segMBuffer[i];
        #endif /* (BCD_NUM_SEG > 8u) */
        #if (BCD_NUM_SEG > 16u) 
            BCD_backup.segHBackup[i] = BCD_segHBuffer[i];
        #endif /* (BCD_NUM_SEG > 16u) */
    }
    
    BCD_Stop();
}


/*******************************************************************************
* Function Name: BCD_Wakeup
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
void BCD_Wakeup(void) 
{
    uint8 i;
    
    /* Restore the segment buffers */
    for(i = 0u; i < BCD_NUM_COM; i++)
    {
        BCD_segLBuffer[i] = BCD_backup.segLBackup[i];
        #if (BCD_NUM_SEG > 8u) 
            BCD_segMBuffer[i] = BCD_backup.segMBackup[i];
        #endif /* (BCD_NUM_SEG > 8u) */
        #if (BCD_NUM_SEG > 16u) 
            BCD_segHBuffer[i] = BCD_backup.segHBackup[i];
        #endif /* (BCD_NUM_SEG > 16u) */
    }
    
    if(BCD_backup.ledEnableState == BCD_ENABLED)
    {
        /* Enable the component */
        BCD_Enable();
    }
}


/* [] END OF FILE */

