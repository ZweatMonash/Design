/*******************************************************************************
* File Name: FreqCount.c  
* Version 3.0
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
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

uint8 FreqCount_initVar = 0u;


/*******************************************************************************
* Function Name: FreqCount_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void FreqCount_Init(void) 
{
        #if (!FreqCount_UsingFixedFunction && !FreqCount_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!FreqCount_UsingFixedFunction && !FreqCount_ControlRegRemoved) */
        
        #if(!FreqCount_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 FreqCount_interruptState;
        #endif /* (!FreqCount_UsingFixedFunction) */
        
        #if (FreqCount_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            FreqCount_CONTROL &= FreqCount_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                FreqCount_CONTROL2 &= ((uint8)(~FreqCount_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                FreqCount_CONTROL3 &= ((uint8)(~FreqCount_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (FreqCount_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                FreqCount_CONTROL |= FreqCount_ONESHOT;
            #endif /* (FreqCount_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            FreqCount_CONTROL2 |= FreqCount_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            FreqCount_RT1 &= ((uint8)(~FreqCount_RT1_MASK));
            FreqCount_RT1 |= FreqCount_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            FreqCount_RT1 &= ((uint8)(~FreqCount_SYNCDSI_MASK));
            FreqCount_RT1 |= FreqCount_SYNCDSI_EN;

        #else
            #if(!FreqCount_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = FreqCount_CONTROL & ((uint8)(~FreqCount_CTRL_CMPMODE_MASK));
            FreqCount_CONTROL = ctrl | FreqCount_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = FreqCount_CONTROL & ((uint8)(~FreqCount_CTRL_CAPMODE_MASK));
            
            #if( 0 != FreqCount_CAPTURE_MODE_CONF)
                FreqCount_CONTROL = ctrl | FreqCount_DEFAULT_CAPTURE_MODE;
            #else
                FreqCount_CONTROL = ctrl;
            #endif /* 0 != FreqCount_CAPTURE_MODE */ 
            
            #endif /* (!FreqCount_ControlRegRemoved) */
        #endif /* (FreqCount_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!FreqCount_UsingFixedFunction)
            FreqCount_ClearFIFO();
        #endif /* (!FreqCount_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        FreqCount_WritePeriod(FreqCount_INIT_PERIOD_VALUE);
        #if (!(FreqCount_UsingFixedFunction && (CY_PSOC5A)))
            FreqCount_WriteCounter(FreqCount_INIT_COUNTER_VALUE);
        #endif /* (!(FreqCount_UsingFixedFunction && (CY_PSOC5A))) */
        FreqCount_SetInterruptMode(FreqCount_INIT_INTERRUPTS_MASK);
        
        #if (!FreqCount_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)FreqCount_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            FreqCount_WriteCompare(FreqCount_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            FreqCount_interruptState = CyEnterCriticalSection();
            
            FreqCount_STATUS_AUX_CTRL |= FreqCount_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(FreqCount_interruptState);
            
        #endif /* (!FreqCount_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: FreqCount_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void FreqCount_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (FreqCount_UsingFixedFunction)
        FreqCount_GLOBAL_ENABLE |= FreqCount_BLOCK_EN_MASK;
        FreqCount_GLOBAL_STBY_ENABLE |= FreqCount_BLOCK_STBY_EN_MASK;
    #endif /* (FreqCount_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!FreqCount_ControlRegRemoved || FreqCount_UsingFixedFunction)
        FreqCount_CONTROL |= FreqCount_CTRL_ENABLE;                
    #endif /* (!FreqCount_ControlRegRemoved || FreqCount_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: FreqCount_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  FreqCount_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void FreqCount_Start(void) 
{
    if(FreqCount_initVar == 0u)
    {
        FreqCount_Init();
        
        FreqCount_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    FreqCount_Enable();        
}


/*******************************************************************************
* Function Name: FreqCount_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void FreqCount_Stop(void) 
{
    /* Disable Counter */
    #if(!FreqCount_ControlRegRemoved || FreqCount_UsingFixedFunction)
        FreqCount_CONTROL &= ((uint8)(~FreqCount_CTRL_ENABLE));        
    #endif /* (!FreqCount_ControlRegRemoved || FreqCount_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (FreqCount_UsingFixedFunction)
        FreqCount_GLOBAL_ENABLE &= ((uint8)(~FreqCount_BLOCK_EN_MASK));
        FreqCount_GLOBAL_STBY_ENABLE &= ((uint8)(~FreqCount_BLOCK_STBY_EN_MASK));
    #endif /* (FreqCount_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: FreqCount_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void FreqCount_SetInterruptMode(uint8 interruptsMask) 
{
    FreqCount_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: FreqCount_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   FreqCount_ReadStatusRegister(void) 
{
    return FreqCount_STATUS;
}


#if(!FreqCount_ControlRegRemoved)
/*******************************************************************************
* Function Name: FreqCount_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   FreqCount_ReadControlRegister(void) 
{
    return FreqCount_CONTROL;
}


/*******************************************************************************
* Function Name: FreqCount_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    FreqCount_WriteControlRegister(uint8 control) 
{
    FreqCount_CONTROL = control;
}

#endif  /* (!FreqCount_ControlRegRemoved) */


#if (!(FreqCount_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: FreqCount_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void FreqCount_WriteCounter(uint16 counter) \
                                   
{
    #if(FreqCount_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (FreqCount_GLOBAL_ENABLE & FreqCount_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        FreqCount_GLOBAL_ENABLE |= FreqCount_BLOCK_EN_MASK;
        CY_SET_REG16(FreqCount_COUNTER_LSB_PTR, (uint16)counter);
        FreqCount_GLOBAL_ENABLE &= ((uint8)(~FreqCount_BLOCK_EN_MASK));
    #else
        CY_SET_REG16(FreqCount_COUNTER_LSB_PTR, counter);
    #endif /* (FreqCount_UsingFixedFunction) */
}
#endif /* (!(FreqCount_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: FreqCount_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint16) The present value of the counter.
*
*******************************************************************************/
uint16 FreqCount_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(FreqCount_UsingFixedFunction)
		(void)CY_GET_REG16(FreqCount_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(FreqCount_COUNTER_LSB_PTR_8BIT);
	#endif/* (FreqCount_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(FreqCount_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(FreqCount_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(FreqCount_STATICCOUNT_LSB_PTR));
    #endif /* (FreqCount_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: FreqCount_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint16) Present Capture value.
*
*******************************************************************************/
uint16 FreqCount_ReadCapture(void) 
{
    #if(FreqCount_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(FreqCount_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(FreqCount_STATICCOUNT_LSB_PTR));
    #endif /* (FreqCount_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: FreqCount_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint16) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void FreqCount_WritePeriod(uint16 period) 
{
    #if(FreqCount_UsingFixedFunction)
        CY_SET_REG16(FreqCount_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG16(FreqCount_PERIOD_LSB_PTR, period);
    #endif /* (FreqCount_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: FreqCount_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint16) Present period value.
*
*******************************************************************************/
uint16 FreqCount_ReadPeriod(void) 
{
    #if(FreqCount_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(FreqCount_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(FreqCount_PERIOD_LSB_PTR));
    #endif /* (FreqCount_UsingFixedFunction) */
}


#if (!FreqCount_UsingFixedFunction)
/*******************************************************************************
* Function Name: FreqCount_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void FreqCount_WriteCompare(uint16 compare) \
                                   
{
    #if(FreqCount_UsingFixedFunction)
        CY_SET_REG16(FreqCount_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG16(FreqCount_COMPARE_LSB_PTR, compare);
    #endif /* (FreqCount_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: FreqCount_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint16) Present compare value.
*
*******************************************************************************/
uint16 FreqCount_ReadCompare(void) 
{
    return (CY_GET_REG16(FreqCount_COMPARE_LSB_PTR));
}


#if (FreqCount_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: FreqCount_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void FreqCount_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    FreqCount_CONTROL &= ((uint8)(~FreqCount_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    FreqCount_CONTROL |= compareMode;
}
#endif  /* (FreqCount_COMPARE_MODE_SOFTWARE) */


#if (FreqCount_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: FreqCount_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void FreqCount_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    FreqCount_CONTROL &= ((uint8)(~FreqCount_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    FreqCount_CONTROL |= ((uint8)((uint8)captureMode << FreqCount_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (FreqCount_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: FreqCount_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void FreqCount_ClearFIFO(void) 
{

    while(0u != (FreqCount_ReadStatusRegister() & FreqCount_STATUS_FIFONEMP))
    {
        (void)FreqCount_ReadCapture();
    }

}
#endif  /* (!FreqCount_UsingFixedFunction) */


/* [] END OF FILE */

