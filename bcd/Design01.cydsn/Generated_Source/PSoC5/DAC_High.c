/*******************************************************************************
* File Name: DAC_High.c  
* Version 1.90
*
* Description:
*  This file provides the source code to the API for the 8-bit Voltage DAC 
*  (VDAC8) User Module.
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "DAC_High.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 DAC_High_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 DAC_High_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static DAC_High_backupStruct DAC_High_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: DAC_High_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void DAC_High_Init(void) 
{
    DAC_High_CR0 = (DAC_High_MODE_V );

    /* Set default data source */
    #if(DAC_High_DEFAULT_DATA_SRC != 0 )
        DAC_High_CR1 = (DAC_High_DEFAULT_CNTL | DAC_High_DACBUS_ENABLE) ;
    #else
        DAC_High_CR1 = (DAC_High_DEFAULT_CNTL | DAC_High_DACBUS_DISABLE) ;
    #endif /* (DAC_High_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(DAC_High_DEFAULT_STRB != 0)
        DAC_High_Strobe |= DAC_High_STRB_EN ;
    #endif/* (DAC_High_DEFAULT_STRB != 0) */

    /* Set default range */
    DAC_High_SetRange(DAC_High_DEFAULT_RANGE); 

    /* Set default speed */
    DAC_High_SetSpeed(DAC_High_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: DAC_High_Enable
********************************************************************************
* Summary:
*  Enable the VDAC8
* 
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void DAC_High_Enable(void) 
{
    DAC_High_PWRMGR |= DAC_High_ACT_PWR_EN;
    DAC_High_STBY_PWRMGR |= DAC_High_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(DAC_High_restoreVal == 1u) 
        {
             DAC_High_CR0 = DAC_High_backup.data_value;
             DAC_High_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: DAC_High_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  Power: Sets power level between off (0) and (3) high power
*
* Return:
*  void 
*
* Global variables:
*  DAC_High_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void DAC_High_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(DAC_High_initVar == 0u)
    { 
        DAC_High_Init();
        DAC_High_initVar = 1u;
    }

    /* Enable power to DAC */
    DAC_High_Enable();

    /* Set default value */
    DAC_High_SetValue(DAC_High_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: DAC_High_Stop
********************************************************************************
*
* Summary:
*  Powers down DAC to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void DAC_High_Stop(void) 
{
    /* Disble power to DAC */
    DAC_High_PWRMGR &= (uint8)(~DAC_High_ACT_PWR_EN);
    DAC_High_STBY_PWRMGR &= (uint8)(~DAC_High_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        DAC_High_backup.data_value = DAC_High_CR0;
        DAC_High_CR0 = DAC_High_CUR_MODE_OUT_OFF;
        DAC_High_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: DAC_High_SetSpeed
********************************************************************************
*
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void DAC_High_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    DAC_High_CR0 &= (uint8)(~DAC_High_HS_MASK);
    DAC_High_CR0 |=  (speed & DAC_High_HS_MASK);
}


/*******************************************************************************
* Function Name: DAC_High_SetRange
********************************************************************************
*
* Summary:
*  Set one of three current ranges.
*
* Parameters:
*  Range: Sets one of Three valid ranges.
*
* Return:
*  void 
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void DAC_High_SetRange(uint8 range) 
{
    DAC_High_CR0 &= (uint8)(~DAC_High_RANGE_MASK);      /* Clear existing mode */
    DAC_High_CR0 |= (range & DAC_High_RANGE_MASK);      /*  Set Range  */
    DAC_High_DacTrim();
}


/*******************************************************************************
* Function Name: DAC_High_SetValue
********************************************************************************
*
* Summary:
*  Set 8-bit DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  void 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void DAC_High_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 DAC_High_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    DAC_High_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        DAC_High_Data = value;
        CyExitCriticalSection(DAC_High_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: DAC_High_DacTrim
********************************************************************************
*
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  range:  1V or 4V range.  See constants.
*
* Return:
*  void
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void DAC_High_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((DAC_High_CR0 & DAC_High_RANGE_MASK) >> 2) + DAC_High_TRIM_M7_1V_RNG_OFFSET;
    DAC_High_TR = CY_GET_XTND_REG8((uint8 *)(DAC_High_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
