/*******************************************************************************
* File Name: Pulse_Counter.c  
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

#include "Pulse_Counter.h"

uint8 Pulse_Counter_initVar = 0u;


/*******************************************************************************
* Function Name: Pulse_Counter_Init
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
void Pulse_Counter_Init(void) 
{
        #if (!Pulse_Counter_UsingFixedFunction && !Pulse_Counter_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!Pulse_Counter_UsingFixedFunction && !Pulse_Counter_ControlRegRemoved) */
        
        #if(!Pulse_Counter_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 Pulse_Counter_interruptState;
        #endif /* (!Pulse_Counter_UsingFixedFunction) */
        
        #if (Pulse_Counter_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            Pulse_Counter_CONTROL &= Pulse_Counter_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                Pulse_Counter_CONTROL2 &= ((uint8)(~Pulse_Counter_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                Pulse_Counter_CONTROL3 &= ((uint8)(~Pulse_Counter_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (Pulse_Counter_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                Pulse_Counter_CONTROL |= Pulse_Counter_ONESHOT;
            #endif /* (Pulse_Counter_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            Pulse_Counter_CONTROL2 |= Pulse_Counter_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            Pulse_Counter_RT1 &= ((uint8)(~Pulse_Counter_RT1_MASK));
            Pulse_Counter_RT1 |= Pulse_Counter_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            Pulse_Counter_RT1 &= ((uint8)(~Pulse_Counter_SYNCDSI_MASK));
            Pulse_Counter_RT1 |= Pulse_Counter_SYNCDSI_EN;

        #else
            #if(!Pulse_Counter_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = Pulse_Counter_CONTROL & ((uint8)(~Pulse_Counter_CTRL_CMPMODE_MASK));
            Pulse_Counter_CONTROL = ctrl | Pulse_Counter_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = Pulse_Counter_CONTROL & ((uint8)(~Pulse_Counter_CTRL_CAPMODE_MASK));
            
            #if( 0 != Pulse_Counter_CAPTURE_MODE_CONF)
                Pulse_Counter_CONTROL = ctrl | Pulse_Counter_DEFAULT_CAPTURE_MODE;
            #else
                Pulse_Counter_CONTROL = ctrl;
            #endif /* 0 != Pulse_Counter_CAPTURE_MODE */ 
            
            #endif /* (!Pulse_Counter_ControlRegRemoved) */
        #endif /* (Pulse_Counter_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!Pulse_Counter_UsingFixedFunction)
            Pulse_Counter_ClearFIFO();
        #endif /* (!Pulse_Counter_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        Pulse_Counter_WritePeriod(Pulse_Counter_INIT_PERIOD_VALUE);
        #if (!(Pulse_Counter_UsingFixedFunction && (CY_PSOC5A)))
            Pulse_Counter_WriteCounter(Pulse_Counter_INIT_COUNTER_VALUE);
        #endif /* (!(Pulse_Counter_UsingFixedFunction && (CY_PSOC5A))) */
        Pulse_Counter_SetInterruptMode(Pulse_Counter_INIT_INTERRUPTS_MASK);
        
        #if (!Pulse_Counter_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)Pulse_Counter_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            Pulse_Counter_WriteCompare(Pulse_Counter_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Pulse_Counter_interruptState = CyEnterCriticalSection();
            
            Pulse_Counter_STATUS_AUX_CTRL |= Pulse_Counter_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(Pulse_Counter_interruptState);
            
        #endif /* (!Pulse_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Pulse_Counter_Enable
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
void Pulse_Counter_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (Pulse_Counter_UsingFixedFunction)
        Pulse_Counter_GLOBAL_ENABLE |= Pulse_Counter_BLOCK_EN_MASK;
        Pulse_Counter_GLOBAL_STBY_ENABLE |= Pulse_Counter_BLOCK_STBY_EN_MASK;
    #endif /* (Pulse_Counter_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!Pulse_Counter_ControlRegRemoved || Pulse_Counter_UsingFixedFunction)
        Pulse_Counter_CONTROL |= Pulse_Counter_CTRL_ENABLE;                
    #endif /* (!Pulse_Counter_ControlRegRemoved || Pulse_Counter_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: Pulse_Counter_Start
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
*  Pulse_Counter_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Pulse_Counter_Start(void) 
{
    if(Pulse_Counter_initVar == 0u)
    {
        Pulse_Counter_Init();
        
        Pulse_Counter_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    Pulse_Counter_Enable();        
}


/*******************************************************************************
* Function Name: Pulse_Counter_Stop
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
void Pulse_Counter_Stop(void) 
{
    /* Disable Counter */
    #if(!Pulse_Counter_ControlRegRemoved || Pulse_Counter_UsingFixedFunction)
        Pulse_Counter_CONTROL &= ((uint8)(~Pulse_Counter_CTRL_ENABLE));        
    #endif /* (!Pulse_Counter_ControlRegRemoved || Pulse_Counter_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (Pulse_Counter_UsingFixedFunction)
        Pulse_Counter_GLOBAL_ENABLE &= ((uint8)(~Pulse_Counter_BLOCK_EN_MASK));
        Pulse_Counter_GLOBAL_STBY_ENABLE &= ((uint8)(~Pulse_Counter_BLOCK_STBY_EN_MASK));
    #endif /* (Pulse_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Pulse_Counter_SetInterruptMode
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
void Pulse_Counter_SetInterruptMode(uint8 interruptsMask) 
{
    Pulse_Counter_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: Pulse_Counter_ReadStatusRegister
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
uint8   Pulse_Counter_ReadStatusRegister(void) 
{
    return Pulse_Counter_STATUS;
}


#if(!Pulse_Counter_ControlRegRemoved)
/*******************************************************************************
* Function Name: Pulse_Counter_ReadControlRegister
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
uint8   Pulse_Counter_ReadControlRegister(void) 
{
    return Pulse_Counter_CONTROL;
}


/*******************************************************************************
* Function Name: Pulse_Counter_WriteControlRegister
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
void    Pulse_Counter_WriteControlRegister(uint8 control) 
{
    Pulse_Counter_CONTROL = control;
}

#endif  /* (!Pulse_Counter_ControlRegRemoved) */


#if (!(Pulse_Counter_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: Pulse_Counter_WriteCounter
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
void Pulse_Counter_WriteCounter(uint8 counter) \
                                   
{
    #if(Pulse_Counter_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (Pulse_Counter_GLOBAL_ENABLE & Pulse_Counter_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        Pulse_Counter_GLOBAL_ENABLE |= Pulse_Counter_BLOCK_EN_MASK;
        CY_SET_REG16(Pulse_Counter_COUNTER_LSB_PTR, (uint16)counter);
        Pulse_Counter_GLOBAL_ENABLE &= ((uint8)(~Pulse_Counter_BLOCK_EN_MASK));
    #else
        CY_SET_REG8(Pulse_Counter_COUNTER_LSB_PTR, counter);
    #endif /* (Pulse_Counter_UsingFixedFunction) */
}
#endif /* (!(Pulse_Counter_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: Pulse_Counter_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint8) The present value of the counter.
*
*******************************************************************************/
uint8 Pulse_Counter_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(Pulse_Counter_UsingFixedFunction)
		(void)CY_GET_REG16(Pulse_Counter_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(Pulse_Counter_COUNTER_LSB_PTR_8BIT);
	#endif/* (Pulse_Counter_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(Pulse_Counter_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Pulse_Counter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(Pulse_Counter_STATICCOUNT_LSB_PTR));
    #endif /* (Pulse_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Pulse_Counter_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) Present Capture value.
*
*******************************************************************************/
uint8 Pulse_Counter_ReadCapture(void) 
{
    #if(Pulse_Counter_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Pulse_Counter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(Pulse_Counter_STATICCOUNT_LSB_PTR));
    #endif /* (Pulse_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Pulse_Counter_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint8) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void Pulse_Counter_WritePeriod(uint8 period) 
{
    #if(Pulse_Counter_UsingFixedFunction)
        CY_SET_REG16(Pulse_Counter_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG8(Pulse_Counter_PERIOD_LSB_PTR, period);
    #endif /* (Pulse_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Pulse_Counter_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint8) Present period value.
*
*******************************************************************************/
uint8 Pulse_Counter_ReadPeriod(void) 
{
    #if(Pulse_Counter_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Pulse_Counter_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG8(Pulse_Counter_PERIOD_LSB_PTR));
    #endif /* (Pulse_Counter_UsingFixedFunction) */
}


#if (!Pulse_Counter_UsingFixedFunction)
/*******************************************************************************
* Function Name: Pulse_Counter_WriteCompare
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
void Pulse_Counter_WriteCompare(uint8 compare) \
                                   
{
    #if(Pulse_Counter_UsingFixedFunction)
        CY_SET_REG16(Pulse_Counter_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG8(Pulse_Counter_COMPARE_LSB_PTR, compare);
    #endif /* (Pulse_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Pulse_Counter_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint8) Present compare value.
*
*******************************************************************************/
uint8 Pulse_Counter_ReadCompare(void) 
{
    return (CY_GET_REG8(Pulse_Counter_COMPARE_LSB_PTR));
}


#if (Pulse_Counter_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Pulse_Counter_SetCompareMode
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
void Pulse_Counter_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    Pulse_Counter_CONTROL &= ((uint8)(~Pulse_Counter_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    Pulse_Counter_CONTROL |= compareMode;
}
#endif  /* (Pulse_Counter_COMPARE_MODE_SOFTWARE) */


#if (Pulse_Counter_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Pulse_Counter_SetCaptureMode
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
void Pulse_Counter_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    Pulse_Counter_CONTROL &= ((uint8)(~Pulse_Counter_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    Pulse_Counter_CONTROL |= ((uint8)((uint8)captureMode << Pulse_Counter_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (Pulse_Counter_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: Pulse_Counter_ClearFIFO
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
void Pulse_Counter_ClearFIFO(void) 
{

    while(0u != (Pulse_Counter_ReadStatusRegister() & Pulse_Counter_STATUS_FIFONEMP))
    {
        (void)Pulse_Counter_ReadCapture();
    }

}
#endif  /* (!Pulse_Counter_UsingFixedFunction) */


/* [] END OF FILE */

