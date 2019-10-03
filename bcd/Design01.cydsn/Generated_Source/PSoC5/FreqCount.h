/*******************************************************************************
* File Name: FreqCount.h  
* Version 3.0
*
*  Description:
*   Contains the function prototypes and constants available to the counter
*   user module.
*
*   Note:
*    None
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
    
#if !defined(CY_COUNTER_FreqCount_H)
#define CY_COUNTER_FreqCount_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 FreqCount_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Counter_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Error message for removed FreqCount_CounterUDB_sCTRLReg_ctrlreg through optimization */
#ifdef FreqCount_CounterUDB_sCTRLReg_ctrlreg__REMOVED
    #error Counter_v3_0 detected with a constant 0 for the enable, a \
                                constant 0 for the count or constant 1 for \
                                the reset. This will prevent the component from\
                                operating.
#endif /* FreqCount_CounterUDB_sCTRLReg_ctrlreg__REMOVED */


/**************************************
*           Parameter Defaults        
**************************************/

#define FreqCount_Resolution            16u
#define FreqCount_UsingFixedFunction    0u
#define FreqCount_ControlRegRemoved     0u
#define FreqCount_COMPARE_MODE_SOFTWARE 1u
#define FreqCount_CAPTURE_MODE_SOFTWARE 0u
#define FreqCount_RunModeUsed           0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Mode API Support
 * Backup structure for Sleep Wake up operations
 *************************************************************************/
typedef struct
{
    uint8 CounterEnableState; 
    uint16 CounterUdb;         /* Current Counter Value */

    #if (!FreqCount_ControlRegRemoved)
        uint8 CounterControlRegister;               /* Counter Control Register */
    #endif /* (!FreqCount_ControlRegRemoved) */

}FreqCount_backupStruct;


/**************************************
 *  Function Prototypes
 *************************************/
void    FreqCount_Start(void) ;
void    FreqCount_Stop(void) ;
void    FreqCount_SetInterruptMode(uint8 interruptsMask) ;
uint8   FreqCount_ReadStatusRegister(void) ;
#define FreqCount_GetInterruptSource() FreqCount_ReadStatusRegister()
#if(!FreqCount_ControlRegRemoved)
    uint8   FreqCount_ReadControlRegister(void) ;
    void    FreqCount_WriteControlRegister(uint8 control) \
        ;
#endif /* (!FreqCount_ControlRegRemoved) */
#if (!(FreqCount_UsingFixedFunction && (CY_PSOC5A)))
    void    FreqCount_WriteCounter(uint16 counter) \
            ; 
#endif /* (!(FreqCount_UsingFixedFunction && (CY_PSOC5A))) */
uint16  FreqCount_ReadCounter(void) ;
uint16  FreqCount_ReadCapture(void) ;
void    FreqCount_WritePeriod(uint16 period) \
    ;
uint16  FreqCount_ReadPeriod( void ) ;
#if (!FreqCount_UsingFixedFunction)
    void    FreqCount_WriteCompare(uint16 compare) \
        ;
    uint16  FreqCount_ReadCompare( void ) \
        ;
#endif /* (!FreqCount_UsingFixedFunction) */

#if (FreqCount_COMPARE_MODE_SOFTWARE)
    void    FreqCount_SetCompareMode(uint8 compareMode) ;
#endif /* (FreqCount_COMPARE_MODE_SOFTWARE) */
#if (FreqCount_CAPTURE_MODE_SOFTWARE)
    void    FreqCount_SetCaptureMode(uint8 captureMode) ;
#endif /* (FreqCount_CAPTURE_MODE_SOFTWARE) */
void FreqCount_ClearFIFO(void)     ;
void FreqCount_Init(void)          ;
void FreqCount_Enable(void)        ;
void FreqCount_SaveConfig(void)    ;
void FreqCount_RestoreConfig(void) ;
void FreqCount_Sleep(void)         ;
void FreqCount_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Counter__CompareModes, Used in Compare Mode retained for backward compatibility of tests*/
#define FreqCount__B_COUNTER__LESS_THAN 1
#define FreqCount__B_COUNTER__LESS_THAN_OR_EQUAL 2
#define FreqCount__B_COUNTER__EQUAL 0
#define FreqCount__B_COUNTER__GREATER_THAN 3
#define FreqCount__B_COUNTER__GREATER_THAN_OR_EQUAL 4
#define FreqCount__B_COUNTER__SOFTWARE 5

/* Enumerated Type Counter_CompareModes */
#define FreqCount_CMP_MODE_LT 1u
#define FreqCount_CMP_MODE_LTE 2u
#define FreqCount_CMP_MODE_EQ 0u
#define FreqCount_CMP_MODE_GT 3u
#define FreqCount_CMP_MODE_GTE 4u
#define FreqCount_CMP_MODE_SOFTWARE_CONTROLLED 5u

/* Enumerated Type B_Counter__CaptureModes, Used in Capture Mode retained for backward compatibility of tests*/
#define FreqCount__B_COUNTER__NONE 0
#define FreqCount__B_COUNTER__RISING_EDGE 1
#define FreqCount__B_COUNTER__FALLING_EDGE 2
#define FreqCount__B_COUNTER__EITHER_EDGE 3
#define FreqCount__B_COUNTER__SOFTWARE_CONTROL 4

/* Enumerated Type Counter_CompareModes */
#define FreqCount_CAP_MODE_NONE 0u
#define FreqCount_CAP_MODE_RISE 1u
#define FreqCount_CAP_MODE_FALL 2u
#define FreqCount_CAP_MODE_BOTH 3u
#define FreqCount_CAP_MODE_SOFTWARE_CONTROLLED 4u


/***************************************
 *  Initialization Values
 **************************************/
#define FreqCount_CAPTURE_MODE_CONF       1u
#define FreqCount_INIT_PERIOD_VALUE       65534u
#define FreqCount_INIT_COUNTER_VALUE      0u
#if (FreqCount_UsingFixedFunction)
#define FreqCount_INIT_INTERRUPTS_MASK    ((uint8)((uint8)0u << FreqCount_STATUS_ZERO_INT_EN_MASK_SHIFT))
#else
#define FreqCount_INIT_COMPARE_VALUE      65534u
#define FreqCount_INIT_INTERRUPTS_MASK ((uint8)((uint8)0u << FreqCount_STATUS_ZERO_INT_EN_MASK_SHIFT) | \
        ((uint8)((uint8)0u << FreqCount_STATUS_CAPTURE_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << FreqCount_STATUS_CMP_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << FreqCount_STATUS_OVERFLOW_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << FreqCount_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT)))
#define FreqCount_DEFAULT_COMPARE_MODE    5u

#if( 0 != FreqCount_CAPTURE_MODE_CONF)
    #define FreqCount_DEFAULT_CAPTURE_MODE    ((uint8)((uint8)1u << FreqCount_CTRL_CAPMODE0_SHIFT))
#else    
    #define FreqCount_DEFAULT_CAPTURE_MODE    (1u )
#endif /* ( 0 != FreqCount_CAPTURE_MODE_CONF) */

#endif /* (FreqCount_UsingFixedFunction) */


/**************************************
 *  Registers
 *************************************/
#if (FreqCount_UsingFixedFunction)
    #define FreqCount_STATICCOUNT_LSB     (*(reg16 *) FreqCount_CounterHW__CAP0 )
    #define FreqCount_STATICCOUNT_LSB_PTR ( (reg16 *) FreqCount_CounterHW__CAP0 )
    #define FreqCount_PERIOD_LSB          (*(reg16 *) FreqCount_CounterHW__PER0 )
    #define FreqCount_PERIOD_LSB_PTR      ( (reg16 *) FreqCount_CounterHW__PER0 )
    /* MODE must be set to 1 to set the compare value */
    #define FreqCount_COMPARE_LSB         (*(reg16 *) FreqCount_CounterHW__CNT_CMP0 )
    #define FreqCount_COMPARE_LSB_PTR     ( (reg16 *) FreqCount_CounterHW__CNT_CMP0 )
    /* MODE must be set to 0 to get the count */
    #define FreqCount_COUNTER_LSB         (*(reg16 *) FreqCount_CounterHW__CNT_CMP0 )
    #define FreqCount_COUNTER_LSB_PTR     ( (reg16 *) FreqCount_CounterHW__CNT_CMP0 )
    #define FreqCount_RT1                 (*(reg8 *) FreqCount_CounterHW__RT1)
    #define FreqCount_RT1_PTR             ( (reg8 *) FreqCount_CounterHW__RT1)
#else
    
    #if (FreqCount_Resolution <= 8u) /* 8-bit Counter */
    
        #define FreqCount_STATICCOUNT_LSB     (*(reg8 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__F0_REG )
        #define FreqCount_STATICCOUNT_LSB_PTR ( (reg8 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__F0_REG )
        #define FreqCount_PERIOD_LSB          (*(reg8 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__D0_REG )
        #define FreqCount_PERIOD_LSB_PTR      ( (reg8 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__D0_REG )
        #define FreqCount_COMPARE_LSB         (*(reg8 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__D1_REG )
        #define FreqCount_COMPARE_LSB_PTR     ( (reg8 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__D1_REG )
        #define FreqCount_COUNTER_LSB         (*(reg8 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__A0_REG )  
        #define FreqCount_COUNTER_LSB_PTR     ( (reg8 *)\
            FreqCount_CounterUDB_sC16_counterdp_u0__A0_REG )
    
    #elif(FreqCount_Resolution <= 16u) /* 16-bit Counter */
        #if(CY_PSOC3) /* 8-bit address space */ 
            #define FreqCount_STATICCOUNT_LSB     (*(reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__F0_REG )
            #define FreqCount_STATICCOUNT_LSB_PTR ( (reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__F0_REG )
            #define FreqCount_PERIOD_LSB          (*(reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__D0_REG )
            #define FreqCount_PERIOD_LSB_PTR      ( (reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__D0_REG )
            #define FreqCount_COMPARE_LSB         (*(reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__D1_REG )
            #define FreqCount_COMPARE_LSB_PTR     ( (reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__D1_REG )
            #define FreqCount_COUNTER_LSB         (*(reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__A0_REG )  
            #define FreqCount_COUNTER_LSB_PTR     ( (reg16 *)\
                FreqCount_CounterUDB_sC16_counterdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define FreqCount_STATICCOUNT_LSB     (*(reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__16BIT_F0_REG )
            #define FreqCount_STATICCOUNT_LSB_PTR ( (reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__16BIT_F0_REG )
            #define FreqCount_PERIOD_LSB          (*(reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__16BIT_D0_REG )
            #define FreqCount_PERIOD_LSB_PTR      ( (reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__16BIT_D0_REG )
            #define FreqCount_COMPARE_LSB         (*(reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__16BIT_D1_REG )
            #define FreqCount_COMPARE_LSB_PTR     ( (reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__16BIT_D1_REG )
            #define FreqCount_COUNTER_LSB         (*(reg16 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__16BIT_A0_REG )  
            #define FreqCount_COUNTER_LSB_PTR     ( (reg16 *)\
                FreqCount_CounterUDB_sC16_counterdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */   
    #elif(FreqCount_Resolution <= 24u) /* 24-bit Counter */
        
        #define FreqCount_STATICCOUNT_LSB     (*(reg32 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__F0_REG )
        #define FreqCount_STATICCOUNT_LSB_PTR ( (reg32 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__F0_REG )
        #define FreqCount_PERIOD_LSB          (*(reg32 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__D0_REG )
        #define FreqCount_PERIOD_LSB_PTR      ( (reg32 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__D0_REG )
        #define FreqCount_COMPARE_LSB         (*(reg32 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__D1_REG )
        #define FreqCount_COMPARE_LSB_PTR     ( (reg32 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__D1_REG )
        #define FreqCount_COUNTER_LSB         (*(reg32 *) \
            FreqCount_CounterUDB_sC16_counterdp_u0__A0_REG )  
        #define FreqCount_COUNTER_LSB_PTR     ( (reg32 *)\
            FreqCount_CounterUDB_sC16_counterdp_u0__A0_REG )
    
    #else /* 32-bit Counter */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define FreqCount_STATICCOUNT_LSB     (*(reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__F0_REG )
            #define FreqCount_STATICCOUNT_LSB_PTR ( (reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__F0_REG )
            #define FreqCount_PERIOD_LSB          (*(reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__D0_REG )
            #define FreqCount_PERIOD_LSB_PTR      ( (reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__D0_REG )
            #define FreqCount_COMPARE_LSB         (*(reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__D1_REG )
            #define FreqCount_COMPARE_LSB_PTR     ( (reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__D1_REG )
            #define FreqCount_COUNTER_LSB         (*(reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__A0_REG )  
            #define FreqCount_COUNTER_LSB_PTR     ( (reg32 *)\
                FreqCount_CounterUDB_sC16_counterdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define FreqCount_STATICCOUNT_LSB     (*(reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__32BIT_F0_REG )
            #define FreqCount_STATICCOUNT_LSB_PTR ( (reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__32BIT_F0_REG )
            #define FreqCount_PERIOD_LSB          (*(reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__32BIT_D0_REG )
            #define FreqCount_PERIOD_LSB_PTR      ( (reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__32BIT_D0_REG )
            #define FreqCount_COMPARE_LSB         (*(reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__32BIT_D1_REG )
            #define FreqCount_COMPARE_LSB_PTR     ( (reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__32BIT_D1_REG )
            #define FreqCount_COUNTER_LSB         (*(reg32 *) \
                FreqCount_CounterUDB_sC16_counterdp_u0__32BIT_A0_REG )  
            #define FreqCount_COUNTER_LSB_PTR     ( (reg32 *)\
                FreqCount_CounterUDB_sC16_counterdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */   
    #endif

	#define FreqCount_COUNTER_LSB_PTR_8BIT     ( (reg8 *)\
                FreqCount_CounterUDB_sC16_counterdp_u0__A0_REG )
				
    #define FreqCount_AUX_CONTROLDP0 \
        (*(reg8 *) FreqCount_CounterUDB_sC16_counterdp_u0__DP_AUX_CTL_REG)
    
    #define FreqCount_AUX_CONTROLDP0_PTR \
        ( (reg8 *) FreqCount_CounterUDB_sC16_counterdp_u0__DP_AUX_CTL_REG)
    
    #if (FreqCount_Resolution == 16 || FreqCount_Resolution == 24 || FreqCount_Resolution == 32)
       #define FreqCount_AUX_CONTROLDP1 \
           (*(reg8 *) FreqCount_CounterUDB_sC16_counterdp_u1__DP_AUX_CTL_REG)
       #define FreqCount_AUX_CONTROLDP1_PTR \
           ( (reg8 *) FreqCount_CounterUDB_sC16_counterdp_u1__DP_AUX_CTL_REG)
    #endif /* (FreqCount_Resolution == 16 || FreqCount_Resolution == 24 || FreqCount_Resolution == 32) */
    
    #if (FreqCount_Resolution == 24 || FreqCount_Resolution == 32)
       #define FreqCount_AUX_CONTROLDP2 \
           (*(reg8 *) FreqCount_CounterUDB_sC16_counterdp_u2__DP_AUX_CTL_REG)
       #define FreqCount_AUX_CONTROLDP2_PTR \
           ( (reg8 *) FreqCount_CounterUDB_sC16_counterdp_u2__DP_AUX_CTL_REG)
    #endif /* (FreqCount_Resolution == 24 || FreqCount_Resolution == 32) */
    
    #if (FreqCount_Resolution == 32)
       #define FreqCount_AUX_CONTROLDP3 \
           (*(reg8 *) FreqCount_CounterUDB_sC16_counterdp_u3__DP_AUX_CTL_REG)
       #define FreqCount_AUX_CONTROLDP3_PTR \
           ( (reg8 *) FreqCount_CounterUDB_sC16_counterdp_u3__DP_AUX_CTL_REG)
    #endif /* (FreqCount_Resolution == 32) */

#endif  /* (FreqCount_UsingFixedFunction) */

#if (FreqCount_UsingFixedFunction)
    #define FreqCount_STATUS         (*(reg8 *) FreqCount_CounterHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define FreqCount_STATUS_MASK             (*(reg8 *) FreqCount_CounterHW__SR0 )
    #define FreqCount_STATUS_MASK_PTR         ( (reg8 *) FreqCount_CounterHW__SR0 )
    #define FreqCount_CONTROL                 (*(reg8 *) FreqCount_CounterHW__CFG0)
    #define FreqCount_CONTROL_PTR             ( (reg8 *) FreqCount_CounterHW__CFG0)
    #define FreqCount_CONTROL2                (*(reg8 *) FreqCount_CounterHW__CFG1)
    #define FreqCount_CONTROL2_PTR            ( (reg8 *) FreqCount_CounterHW__CFG1)
    #if (CY_PSOC3 || CY_PSOC5LP)
        #define FreqCount_CONTROL3       (*(reg8 *) FreqCount_CounterHW__CFG2)
        #define FreqCount_CONTROL3_PTR   ( (reg8 *) FreqCount_CounterHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define FreqCount_GLOBAL_ENABLE           (*(reg8 *) FreqCount_CounterHW__PM_ACT_CFG)
    #define FreqCount_GLOBAL_ENABLE_PTR       ( (reg8 *) FreqCount_CounterHW__PM_ACT_CFG)
    #define FreqCount_GLOBAL_STBY_ENABLE      (*(reg8 *) FreqCount_CounterHW__PM_STBY_CFG)
    #define FreqCount_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) FreqCount_CounterHW__PM_STBY_CFG)
    

    /********************************
    *    Constants
    ********************************/

    /* Fixed Function Block Chosen */
    #define FreqCount_BLOCK_EN_MASK          FreqCount_CounterHW__PM_ACT_MSK
    #define FreqCount_BLOCK_STBY_EN_MASK     FreqCount_CounterHW__PM_STBY_MSK 
    
    /* Control Register Bit Locations */    
    /* As defined in Register Map, part of TMRX_CFG0 register */
    #define FreqCount_CTRL_ENABLE_SHIFT      0x00u
    #define FreqCount_ONESHOT_SHIFT          0x02u
    /* Control Register Bit Masks */
    #define FreqCount_CTRL_ENABLE            ((uint8)((uint8)0x01u << FreqCount_CTRL_ENABLE_SHIFT))         
    #define FreqCount_ONESHOT                ((uint8)((uint8)0x01u << FreqCount_ONESHOT_SHIFT))

    /* Control2 Register Bit Masks */
    /* Set the mask for run mode */
    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        #define FreqCount_CTRL_MODE_SHIFT        0x01u    
        #define FreqCount_CTRL_MODE_MASK         ((uint8)((uint8)0x07u << FreqCount_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Use CFG2 Mode bits to set run mode */
        #define FreqCount_CTRL_MODE_SHIFT        0x00u    
        #define FreqCount_CTRL_MODE_MASK         ((uint8)((uint8)0x03u << FreqCount_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    /* Set the mask for interrupt (raw/status register) */
    #define FreqCount_CTRL2_IRQ_SEL_SHIFT     0x00u
    #define FreqCount_CTRL2_IRQ_SEL          ((uint8)((uint8)0x01u << FreqCount_CTRL2_IRQ_SEL_SHIFT))     
    
    /* Status Register Bit Locations */
    #define FreqCount_STATUS_ZERO_SHIFT      0x07u  /* As defined in Register Map, part of TMRX_SR0 register */ 

    /* Status Register Interrupt Enable Bit Locations */
    #define FreqCount_STATUS_ZERO_INT_EN_MASK_SHIFT      (FreqCount_STATUS_ZERO_SHIFT - 0x04u)

    /* Status Register Bit Masks */                           
    #define FreqCount_STATUS_ZERO            ((uint8)((uint8)0x01u << FreqCount_STATUS_ZERO_SHIFT))

    /* Status Register Interrupt Bit Masks*/
    #define FreqCount_STATUS_ZERO_INT_EN_MASK       ((uint8)((uint8)FreqCount_STATUS_ZERO >> 0x04u))
    
    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define FreqCount_RT1_SHIFT            0x04u
    #define FreqCount_RT1_MASK             ((uint8)((uint8)0x03u << FreqCount_RT1_SHIFT))  /* Sync TC and CMP bit masks */
    #define FreqCount_SYNC                 ((uint8)((uint8)0x03u << FreqCount_RT1_SHIFT))
    #define FreqCount_SYNCDSI_SHIFT        0x00u
    #define FreqCount_SYNCDSI_MASK         ((uint8)((uint8)0x0Fu << FreqCount_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    #define FreqCount_SYNCDSI_EN           ((uint8)((uint8)0x0Fu << FreqCount_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    
#else /* !FreqCount_UsingFixedFunction */
    #define FreqCount_STATUS               (* (reg8 *) FreqCount_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define FreqCount_STATUS_PTR           (  (reg8 *) FreqCount_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define FreqCount_STATUS_MASK          (* (reg8 *) FreqCount_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define FreqCount_STATUS_MASK_PTR      (  (reg8 *) FreqCount_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define FreqCount_STATUS_AUX_CTRL      (*(reg8 *) FreqCount_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define FreqCount_STATUS_AUX_CTRL_PTR  ( (reg8 *) FreqCount_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define FreqCount_CONTROL              (* (reg8 *) FreqCount_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )
    #define FreqCount_CONTROL_PTR          (  (reg8 *) FreqCount_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )


    /********************************
    *    Constants
    ********************************/
    /* Control Register Bit Locations */
    #define FreqCount_CTRL_CAPMODE0_SHIFT    0x03u       /* As defined by Verilog Implementation */
    #define FreqCount_CTRL_RESET_SHIFT       0x06u       /* As defined by Verilog Implementation */
    #define FreqCount_CTRL_ENABLE_SHIFT      0x07u       /* As defined by Verilog Implementation */
    /* Control Register Bit Masks */
    #define FreqCount_CTRL_CMPMODE_MASK      0x07u 
    #define FreqCount_CTRL_CAPMODE_MASK      0x03u  
    #define FreqCount_CTRL_RESET             ((uint8)((uint8)0x01u << FreqCount_CTRL_RESET_SHIFT))  
    #define FreqCount_CTRL_ENABLE            ((uint8)((uint8)0x01u << FreqCount_CTRL_ENABLE_SHIFT)) 

    /* Status Register Bit Locations */
    #define FreqCount_STATUS_CMP_SHIFT       0x00u       /* As defined by Verilog Implementation */
    #define FreqCount_STATUS_ZERO_SHIFT      0x01u       /* As defined by Verilog Implementation */
    #define FreqCount_STATUS_OVERFLOW_SHIFT  0x02u       /* As defined by Verilog Implementation */
    #define FreqCount_STATUS_UNDERFLOW_SHIFT 0x03u       /* As defined by Verilog Implementation */
    #define FreqCount_STATUS_CAPTURE_SHIFT   0x04u       /* As defined by Verilog Implementation */
    #define FreqCount_STATUS_FIFOFULL_SHIFT  0x05u       /* As defined by Verilog Implementation */
    #define FreqCount_STATUS_FIFONEMP_SHIFT  0x06u       /* As defined by Verilog Implementation */
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define FreqCount_STATUS_CMP_INT_EN_MASK_SHIFT       FreqCount_STATUS_CMP_SHIFT       
    #define FreqCount_STATUS_ZERO_INT_EN_MASK_SHIFT      FreqCount_STATUS_ZERO_SHIFT      
    #define FreqCount_STATUS_OVERFLOW_INT_EN_MASK_SHIFT  FreqCount_STATUS_OVERFLOW_SHIFT  
    #define FreqCount_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT FreqCount_STATUS_UNDERFLOW_SHIFT 
    #define FreqCount_STATUS_CAPTURE_INT_EN_MASK_SHIFT   FreqCount_STATUS_CAPTURE_SHIFT   
    #define FreqCount_STATUS_FIFOFULL_INT_EN_MASK_SHIFT  FreqCount_STATUS_FIFOFULL_SHIFT  
    #define FreqCount_STATUS_FIFONEMP_INT_EN_MASK_SHIFT  FreqCount_STATUS_FIFONEMP_SHIFT  
    /* Status Register Bit Masks */                
    #define FreqCount_STATUS_CMP             ((uint8)((uint8)0x01u << FreqCount_STATUS_CMP_SHIFT))  
    #define FreqCount_STATUS_ZERO            ((uint8)((uint8)0x01u << FreqCount_STATUS_ZERO_SHIFT)) 
    #define FreqCount_STATUS_OVERFLOW        ((uint8)((uint8)0x01u << FreqCount_STATUS_OVERFLOW_SHIFT)) 
    #define FreqCount_STATUS_UNDERFLOW       ((uint8)((uint8)0x01u << FreqCount_STATUS_UNDERFLOW_SHIFT)) 
    #define FreqCount_STATUS_CAPTURE         ((uint8)((uint8)0x01u << FreqCount_STATUS_CAPTURE_SHIFT)) 
    #define FreqCount_STATUS_FIFOFULL        ((uint8)((uint8)0x01u << FreqCount_STATUS_FIFOFULL_SHIFT))
    #define FreqCount_STATUS_FIFONEMP        ((uint8)((uint8)0x01u << FreqCount_STATUS_FIFONEMP_SHIFT))
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define FreqCount_STATUS_CMP_INT_EN_MASK            FreqCount_STATUS_CMP                    
    #define FreqCount_STATUS_ZERO_INT_EN_MASK           FreqCount_STATUS_ZERO            
    #define FreqCount_STATUS_OVERFLOW_INT_EN_MASK       FreqCount_STATUS_OVERFLOW        
    #define FreqCount_STATUS_UNDERFLOW_INT_EN_MASK      FreqCount_STATUS_UNDERFLOW       
    #define FreqCount_STATUS_CAPTURE_INT_EN_MASK        FreqCount_STATUS_CAPTURE         
    #define FreqCount_STATUS_FIFOFULL_INT_EN_MASK       FreqCount_STATUS_FIFOFULL        
    #define FreqCount_STATUS_FIFONEMP_INT_EN_MASK       FreqCount_STATUS_FIFONEMP         
    

    /* StatusI Interrupt Enable bit Location in the Auxilliary Control Register */
    #define FreqCount_STATUS_ACTL_INT_EN     0x10u /* As defined for the ACTL Register */
    
    /* Datapath Auxillary Control Register definitions */
    #define FreqCount_AUX_CTRL_FIFO0_CLR         0x01u   /* As defined by Register map */
    #define FreqCount_AUX_CTRL_FIFO1_CLR         0x02u   /* As defined by Register map */
    #define FreqCount_AUX_CTRL_FIFO0_LVL         0x04u   /* As defined by Register map */
    #define FreqCount_AUX_CTRL_FIFO1_LVL         0x08u   /* As defined by Register map */
    #define FreqCount_STATUS_ACTL_INT_EN_MASK    0x10u   /* As defined for the ACTL Register */
    
#endif /* FreqCount_UsingFixedFunction */

#endif  /* CY_COUNTER_FreqCount_H */


/* [] END OF FILE */

