/*******************************************************************************
* File Name: Debouncer.h
* Version 2.80
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_TIMER_Debouncer_H)
#define CY_TIMER_Debouncer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Debouncer_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define Debouncer_Resolution                 8u
#define Debouncer_UsingFixedFunction         1u
#define Debouncer_UsingHWCaptureCounter      0u
#define Debouncer_SoftwareCaptureMode        0u
#define Debouncer_SoftwareTriggerMode        0u
#define Debouncer_UsingHWEnable              0u
#define Debouncer_EnableTriggerMode          0u
#define Debouncer_InterruptOnCaptureCount    0u
#define Debouncer_RunModeUsed                0u
#define Debouncer_ControlRegRemoved          0u

#if defined(Debouncer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define Debouncer_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (Debouncer_UsingFixedFunction)
    #define Debouncer_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define Debouncer_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End Debouncer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!Debouncer_UsingFixedFunction)

        uint8 TimerUdb;
        uint8 InterruptMaskValue;
        #if (Debouncer_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!Debouncer_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}Debouncer_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    Debouncer_Start(void) ;
void    Debouncer_Stop(void) ;

void    Debouncer_SetInterruptMode(uint8 interruptMode) ;
uint8   Debouncer_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define Debouncer_GetInterruptSource() Debouncer_ReadStatusRegister()

#if(!Debouncer_UDB_CONTROL_REG_REMOVED)
    uint8   Debouncer_ReadControlRegister(void) ;
    void    Debouncer_WriteControlRegister(uint8 control) ;
#endif /* (!Debouncer_UDB_CONTROL_REG_REMOVED) */

uint8  Debouncer_ReadPeriod(void) ;
void    Debouncer_WritePeriod(uint8 period) ;
uint8  Debouncer_ReadCounter(void) ;
void    Debouncer_WriteCounter(uint8 counter) ;
uint8  Debouncer_ReadCapture(void) ;
void    Debouncer_SoftwareCapture(void) ;

#if(!Debouncer_UsingFixedFunction) /* UDB Prototypes */
    #if (Debouncer_SoftwareCaptureMode)
        void    Debouncer_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!Debouncer_UsingFixedFunction) */

    #if (Debouncer_SoftwareTriggerMode)
        void    Debouncer_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (Debouncer_SoftwareTriggerMode) */

    #if (Debouncer_EnableTriggerMode)
        void    Debouncer_EnableTrigger(void) ;
        void    Debouncer_DisableTrigger(void) ;
    #endif /* (Debouncer_EnableTriggerMode) */


    #if(Debouncer_InterruptOnCaptureCount)
        void    Debouncer_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (Debouncer_InterruptOnCaptureCount) */

    #if (Debouncer_UsingHWCaptureCounter)
        void    Debouncer_SetCaptureCount(uint8 captureCount) ;
        uint8   Debouncer_ReadCaptureCount(void) ;
    #endif /* (Debouncer_UsingHWCaptureCounter) */

    void Debouncer_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void Debouncer_Init(void)          ;
void Debouncer_Enable(void)        ;
void Debouncer_SaveConfig(void)    ;
void Debouncer_RestoreConfig(void) ;
void Debouncer_Sleep(void)         ;
void Debouncer_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define Debouncer__B_TIMER__CM_NONE 0
#define Debouncer__B_TIMER__CM_RISINGEDGE 1
#define Debouncer__B_TIMER__CM_FALLINGEDGE 2
#define Debouncer__B_TIMER__CM_EITHEREDGE 3
#define Debouncer__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define Debouncer__B_TIMER__TM_NONE 0x00u
#define Debouncer__B_TIMER__TM_RISINGEDGE 0x04u
#define Debouncer__B_TIMER__TM_FALLINGEDGE 0x08u
#define Debouncer__B_TIMER__TM_EITHEREDGE 0x0Cu
#define Debouncer__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define Debouncer_INIT_PERIOD             255u
#define Debouncer_INIT_CAPTURE_MODE       ((uint8)((uint8)1u << Debouncer_CTRL_CAP_MODE_SHIFT))
#define Debouncer_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << Debouncer_CTRL_TRIG_MODE_SHIFT))
#if (Debouncer_UsingFixedFunction)
    #define Debouncer_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << Debouncer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << Debouncer_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define Debouncer_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << Debouncer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Debouncer_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Debouncer_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (Debouncer_UsingFixedFunction) */
#define Debouncer_INIT_CAPTURE_COUNT      (2u)
#define Debouncer_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << Debouncer_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (Debouncer_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define Debouncer_STATUS         (*(reg8 *) Debouncer_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Debouncer_STATUS_MASK    (*(reg8 *) Debouncer_TimerHW__SR0 )
    #define Debouncer_CONTROL        (*(reg8 *) Debouncer_TimerHW__CFG0)
    #define Debouncer_CONTROL2       (*(reg8 *) Debouncer_TimerHW__CFG1)
    #define Debouncer_CONTROL2_PTR   ( (reg8 *) Debouncer_TimerHW__CFG1)
    #define Debouncer_RT1            (*(reg8 *) Debouncer_TimerHW__RT1)
    #define Debouncer_RT1_PTR        ( (reg8 *) Debouncer_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Debouncer_CONTROL3       (*(reg8 *) Debouncer_TimerHW__CFG2)
        #define Debouncer_CONTROL3_PTR   ( (reg8 *) Debouncer_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Debouncer_GLOBAL_ENABLE  (*(reg8 *) Debouncer_TimerHW__PM_ACT_CFG)
    #define Debouncer_GLOBAL_STBY_ENABLE  (*(reg8 *) Debouncer_TimerHW__PM_STBY_CFG)

    #define Debouncer_CAPTURE_LSB         (* (reg16 *) Debouncer_TimerHW__CAP0 )
    #define Debouncer_CAPTURE_LSB_PTR       ((reg16 *) Debouncer_TimerHW__CAP0 )
    #define Debouncer_PERIOD_LSB          (* (reg16 *) Debouncer_TimerHW__PER0 )
    #define Debouncer_PERIOD_LSB_PTR        ((reg16 *) Debouncer_TimerHW__PER0 )
    #define Debouncer_COUNTER_LSB         (* (reg16 *) Debouncer_TimerHW__CNT_CMP0 )
    #define Debouncer_COUNTER_LSB_PTR       ((reg16 *) Debouncer_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define Debouncer_BLOCK_EN_MASK                     Debouncer_TimerHW__PM_ACT_MSK
    #define Debouncer_BLOCK_STBY_EN_MASK                Debouncer_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define Debouncer_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define Debouncer_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define Debouncer_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define Debouncer_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define Debouncer_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define Debouncer_CTRL_ENABLE                        ((uint8)((uint8)0x01u << Debouncer_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Debouncer_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define Debouncer_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << Debouncer_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define Debouncer_CTRL_MODE_SHIFT                 0x01u
        #define Debouncer_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << Debouncer_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define Debouncer_CTRL_RCOD_SHIFT        0x02u
        #define Debouncer_CTRL_ENBL_SHIFT        0x00u
        #define Debouncer_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define Debouncer_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << Debouncer_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define Debouncer_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << Debouncer_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define Debouncer_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << Debouncer_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define Debouncer_CTRL_RCOD       ((uint8)((uint8)0x03u << Debouncer_CTRL_RCOD_SHIFT))
        #define Debouncer_CTRL_ENBL       ((uint8)((uint8)0x80u << Debouncer_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Debouncer_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define Debouncer_RT1_MASK                        ((uint8)((uint8)0x03u << Debouncer_RT1_SHIFT))
    #define Debouncer_SYNC                            ((uint8)((uint8)0x03u << Debouncer_RT1_SHIFT))
    #define Debouncer_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define Debouncer_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << Debouncer_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define Debouncer_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << Debouncer_SYNCDSI_SHIFT))

    #define Debouncer_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << Debouncer_CTRL_MODE_SHIFT))
    #define Debouncer_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << Debouncer_CTRL_MODE_SHIFT))
    #define Debouncer_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << Debouncer_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Debouncer_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Debouncer_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Debouncer_STATUS_TC_INT_MASK_SHIFT        (Debouncer_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Debouncer_STATUS_CAPTURE_INT_MASK_SHIFT   (Debouncer_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define Debouncer_STATUS_TC                       ((uint8)((uint8)0x01u << Debouncer_STATUS_TC_SHIFT))
    #define Debouncer_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << Debouncer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define Debouncer_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << Debouncer_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define Debouncer_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << Debouncer_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define Debouncer_STATUS              (* (reg8 *) Debouncer_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define Debouncer_STATUS_MASK         (* (reg8 *) Debouncer_TimerUDB_rstSts_stsreg__MASK_REG)
    #define Debouncer_STATUS_AUX_CTRL     (* (reg8 *) Debouncer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Debouncer_CONTROL             (* (reg8 *) Debouncer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(Debouncer_Resolution <= 8u) /* 8-bit Timer */
        #define Debouncer_CAPTURE_LSB         (* (reg8 *) Debouncer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define Debouncer_CAPTURE_LSB_PTR       ((reg8 *) Debouncer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define Debouncer_PERIOD_LSB          (* (reg8 *) Debouncer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define Debouncer_PERIOD_LSB_PTR        ((reg8 *) Debouncer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define Debouncer_COUNTER_LSB         (* (reg8 *) Debouncer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define Debouncer_COUNTER_LSB_PTR       ((reg8 *) Debouncer_TimerUDB_sT8_timerdp_u0__A0_REG )
    #elif(Debouncer_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define Debouncer_CAPTURE_LSB         (* (reg16 *) Debouncer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define Debouncer_CAPTURE_LSB_PTR       ((reg16 *) Debouncer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define Debouncer_PERIOD_LSB          (* (reg16 *) Debouncer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define Debouncer_PERIOD_LSB_PTR        ((reg16 *) Debouncer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define Debouncer_COUNTER_LSB         (* (reg16 *) Debouncer_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define Debouncer_COUNTER_LSB_PTR       ((reg16 *) Debouncer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define Debouncer_CAPTURE_LSB         (* (reg16 *) Debouncer_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define Debouncer_CAPTURE_LSB_PTR       ((reg16 *) Debouncer_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define Debouncer_PERIOD_LSB          (* (reg16 *) Debouncer_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define Debouncer_PERIOD_LSB_PTR        ((reg16 *) Debouncer_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define Debouncer_COUNTER_LSB         (* (reg16 *) Debouncer_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
            #define Debouncer_COUNTER_LSB_PTR       ((reg16 *) Debouncer_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(Debouncer_Resolution <= 24u)/* 24-bit Timer */
        #define Debouncer_CAPTURE_LSB         (* (reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define Debouncer_CAPTURE_LSB_PTR       ((reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define Debouncer_PERIOD_LSB          (* (reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define Debouncer_PERIOD_LSB_PTR        ((reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define Debouncer_COUNTER_LSB         (* (reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define Debouncer_COUNTER_LSB_PTR       ((reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define Debouncer_CAPTURE_LSB         (* (reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define Debouncer_CAPTURE_LSB_PTR       ((reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define Debouncer_PERIOD_LSB          (* (reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define Debouncer_PERIOD_LSB_PTR        ((reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define Debouncer_COUNTER_LSB         (* (reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define Debouncer_COUNTER_LSB_PTR       ((reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define Debouncer_CAPTURE_LSB         (* (reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define Debouncer_CAPTURE_LSB_PTR       ((reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define Debouncer_PERIOD_LSB          (* (reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define Debouncer_PERIOD_LSB_PTR        ((reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define Debouncer_COUNTER_LSB         (* (reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
            #define Debouncer_COUNTER_LSB_PTR       ((reg32 *) Debouncer_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define Debouncer_COUNTER_LSB_PTR_8BIT       ((reg8 *) Debouncer_TimerUDB_sT8_timerdp_u0__A0_REG )
    
    #if (Debouncer_UsingHWCaptureCounter)
        #define Debouncer_CAP_COUNT              (*(reg8 *) Debouncer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Debouncer_CAP_COUNT_PTR          ( (reg8 *) Debouncer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Debouncer_CAPTURE_COUNT_CTRL     (*(reg8 *) Debouncer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define Debouncer_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) Debouncer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (Debouncer_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define Debouncer_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define Debouncer_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define Debouncer_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define Debouncer_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define Debouncer_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define Debouncer_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << Debouncer_CTRL_INTCNT_SHIFT))
    #define Debouncer_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << Debouncer_CTRL_TRIG_MODE_SHIFT))
    #define Debouncer_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << Debouncer_CTRL_TRIG_EN_SHIFT))
    #define Debouncer_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << Debouncer_CTRL_CAP_MODE_SHIFT))
    #define Debouncer_CTRL_ENABLE                    ((uint8)((uint8)0x01u << Debouncer_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define Debouncer_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define Debouncer_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define Debouncer_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define Debouncer_STATUS_TC_INT_MASK_SHIFT       Debouncer_STATUS_TC_SHIFT
    #define Debouncer_STATUS_CAPTURE_INT_MASK_SHIFT  Debouncer_STATUS_CAPTURE_SHIFT
    #define Debouncer_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define Debouncer_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define Debouncer_STATUS_FIFOFULL_INT_MASK_SHIFT Debouncer_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define Debouncer_STATUS_TC                      ((uint8)((uint8)0x01u << Debouncer_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define Debouncer_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << Debouncer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Debouncer_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << Debouncer_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Debouncer_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << Debouncer_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define Debouncer_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << Debouncer_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define Debouncer_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << Debouncer_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Debouncer_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << Debouncer_STATUS_FIFOFULL_SHIFT))

    #define Debouncer_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define Debouncer_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define Debouncer_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define Debouncer_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define Debouncer_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define Debouncer_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_TIMER_Debouncer_H */


/* [] END OF FILE */
