/*******************************************************************************
* File Name: EchoTimer.h
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

#if !defined(CY_TIMER_EchoTimer_H)
#define CY_TIMER_EchoTimer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 EchoTimer_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define EchoTimer_Resolution                 24u
#define EchoTimer_UsingFixedFunction         0u
#define EchoTimer_UsingHWCaptureCounter      0u
#define EchoTimer_SoftwareCaptureMode        0u
#define EchoTimer_SoftwareTriggerMode        0u
#define EchoTimer_UsingHWEnable              0u
#define EchoTimer_EnableTriggerMode          0u
#define EchoTimer_InterruptOnCaptureCount    0u
#define EchoTimer_RunModeUsed                0u
#define EchoTimer_ControlRegRemoved          0u

#if defined(EchoTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define EchoTimer_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (EchoTimer_UsingFixedFunction)
    #define EchoTimer_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define EchoTimer_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End EchoTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!EchoTimer_UsingFixedFunction)

        uint32 TimerUdb;
        uint8 InterruptMaskValue;
        #if (EchoTimer_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!EchoTimer_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}EchoTimer_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    EchoTimer_Start(void) ;
void    EchoTimer_Stop(void) ;

void    EchoTimer_SetInterruptMode(uint8 interruptMode) ;
uint8   EchoTimer_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define EchoTimer_GetInterruptSource() EchoTimer_ReadStatusRegister()

#if(!EchoTimer_UDB_CONTROL_REG_REMOVED)
    uint8   EchoTimer_ReadControlRegister(void) ;
    void    EchoTimer_WriteControlRegister(uint8 control) ;
#endif /* (!EchoTimer_UDB_CONTROL_REG_REMOVED) */

uint32  EchoTimer_ReadPeriod(void) ;
void    EchoTimer_WritePeriod(uint32 period) ;
uint32  EchoTimer_ReadCounter(void) ;
void    EchoTimer_WriteCounter(uint32 counter) ;
uint32  EchoTimer_ReadCapture(void) ;
void    EchoTimer_SoftwareCapture(void) ;

#if(!EchoTimer_UsingFixedFunction) /* UDB Prototypes */
    #if (EchoTimer_SoftwareCaptureMode)
        void    EchoTimer_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!EchoTimer_UsingFixedFunction) */

    #if (EchoTimer_SoftwareTriggerMode)
        void    EchoTimer_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (EchoTimer_SoftwareTriggerMode) */

    #if (EchoTimer_EnableTriggerMode)
        void    EchoTimer_EnableTrigger(void) ;
        void    EchoTimer_DisableTrigger(void) ;
    #endif /* (EchoTimer_EnableTriggerMode) */


    #if(EchoTimer_InterruptOnCaptureCount)
        void    EchoTimer_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (EchoTimer_InterruptOnCaptureCount) */

    #if (EchoTimer_UsingHWCaptureCounter)
        void    EchoTimer_SetCaptureCount(uint8 captureCount) ;
        uint8   EchoTimer_ReadCaptureCount(void) ;
    #endif /* (EchoTimer_UsingHWCaptureCounter) */

    void EchoTimer_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void EchoTimer_Init(void)          ;
void EchoTimer_Enable(void)        ;
void EchoTimer_SaveConfig(void)    ;
void EchoTimer_RestoreConfig(void) ;
void EchoTimer_Sleep(void)         ;
void EchoTimer_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define EchoTimer__B_TIMER__CM_NONE 0
#define EchoTimer__B_TIMER__CM_RISINGEDGE 1
#define EchoTimer__B_TIMER__CM_FALLINGEDGE 2
#define EchoTimer__B_TIMER__CM_EITHEREDGE 3
#define EchoTimer__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define EchoTimer__B_TIMER__TM_NONE 0x00u
#define EchoTimer__B_TIMER__TM_RISINGEDGE 0x04u
#define EchoTimer__B_TIMER__TM_FALLINGEDGE 0x08u
#define EchoTimer__B_TIMER__TM_EITHEREDGE 0x0Cu
#define EchoTimer__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define EchoTimer_INIT_PERIOD             99999u
#define EchoTimer_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << EchoTimer_CTRL_CAP_MODE_SHIFT))
#define EchoTimer_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << EchoTimer_CTRL_TRIG_MODE_SHIFT))
#if (EchoTimer_UsingFixedFunction)
    #define EchoTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << EchoTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << EchoTimer_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define EchoTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << EchoTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << EchoTimer_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << EchoTimer_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (EchoTimer_UsingFixedFunction) */
#define EchoTimer_INIT_CAPTURE_COUNT      (2u)
#define EchoTimer_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << EchoTimer_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (EchoTimer_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define EchoTimer_STATUS         (*(reg8 *) EchoTimer_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define EchoTimer_STATUS_MASK    (*(reg8 *) EchoTimer_TimerHW__SR0 )
    #define EchoTimer_CONTROL        (*(reg8 *) EchoTimer_TimerHW__CFG0)
    #define EchoTimer_CONTROL2       (*(reg8 *) EchoTimer_TimerHW__CFG1)
    #define EchoTimer_CONTROL2_PTR   ( (reg8 *) EchoTimer_TimerHW__CFG1)
    #define EchoTimer_RT1            (*(reg8 *) EchoTimer_TimerHW__RT1)
    #define EchoTimer_RT1_PTR        ( (reg8 *) EchoTimer_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define EchoTimer_CONTROL3       (*(reg8 *) EchoTimer_TimerHW__CFG2)
        #define EchoTimer_CONTROL3_PTR   ( (reg8 *) EchoTimer_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define EchoTimer_GLOBAL_ENABLE  (*(reg8 *) EchoTimer_TimerHW__PM_ACT_CFG)
    #define EchoTimer_GLOBAL_STBY_ENABLE  (*(reg8 *) EchoTimer_TimerHW__PM_STBY_CFG)

    #define EchoTimer_CAPTURE_LSB         (* (reg16 *) EchoTimer_TimerHW__CAP0 )
    #define EchoTimer_CAPTURE_LSB_PTR       ((reg16 *) EchoTimer_TimerHW__CAP0 )
    #define EchoTimer_PERIOD_LSB          (* (reg16 *) EchoTimer_TimerHW__PER0 )
    #define EchoTimer_PERIOD_LSB_PTR        ((reg16 *) EchoTimer_TimerHW__PER0 )
    #define EchoTimer_COUNTER_LSB         (* (reg16 *) EchoTimer_TimerHW__CNT_CMP0 )
    #define EchoTimer_COUNTER_LSB_PTR       ((reg16 *) EchoTimer_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define EchoTimer_BLOCK_EN_MASK                     EchoTimer_TimerHW__PM_ACT_MSK
    #define EchoTimer_BLOCK_STBY_EN_MASK                EchoTimer_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define EchoTimer_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define EchoTimer_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define EchoTimer_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define EchoTimer_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define EchoTimer_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define EchoTimer_CTRL_ENABLE                        ((uint8)((uint8)0x01u << EchoTimer_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define EchoTimer_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define EchoTimer_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << EchoTimer_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define EchoTimer_CTRL_MODE_SHIFT                 0x01u
        #define EchoTimer_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << EchoTimer_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define EchoTimer_CTRL_RCOD_SHIFT        0x02u
        #define EchoTimer_CTRL_ENBL_SHIFT        0x00u
        #define EchoTimer_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define EchoTimer_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << EchoTimer_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define EchoTimer_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << EchoTimer_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define EchoTimer_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << EchoTimer_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define EchoTimer_CTRL_RCOD       ((uint8)((uint8)0x03u << EchoTimer_CTRL_RCOD_SHIFT))
        #define EchoTimer_CTRL_ENBL       ((uint8)((uint8)0x80u << EchoTimer_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define EchoTimer_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define EchoTimer_RT1_MASK                        ((uint8)((uint8)0x03u << EchoTimer_RT1_SHIFT))
    #define EchoTimer_SYNC                            ((uint8)((uint8)0x03u << EchoTimer_RT1_SHIFT))
    #define EchoTimer_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define EchoTimer_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << EchoTimer_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define EchoTimer_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << EchoTimer_SYNCDSI_SHIFT))

    #define EchoTimer_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << EchoTimer_CTRL_MODE_SHIFT))
    #define EchoTimer_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << EchoTimer_CTRL_MODE_SHIFT))
    #define EchoTimer_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << EchoTimer_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define EchoTimer_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define EchoTimer_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define EchoTimer_STATUS_TC_INT_MASK_SHIFT        (EchoTimer_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define EchoTimer_STATUS_CAPTURE_INT_MASK_SHIFT   (EchoTimer_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define EchoTimer_STATUS_TC                       ((uint8)((uint8)0x01u << EchoTimer_STATUS_TC_SHIFT))
    #define EchoTimer_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << EchoTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define EchoTimer_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << EchoTimer_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define EchoTimer_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << EchoTimer_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define EchoTimer_STATUS              (* (reg8 *) EchoTimer_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define EchoTimer_STATUS_MASK         (* (reg8 *) EchoTimer_TimerUDB_rstSts_stsreg__MASK_REG)
    #define EchoTimer_STATUS_AUX_CTRL     (* (reg8 *) EchoTimer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define EchoTimer_CONTROL             (* (reg8 *) EchoTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(EchoTimer_Resolution <= 8u) /* 8-bit Timer */
        #define EchoTimer_CAPTURE_LSB         (* (reg8 *) EchoTimer_TimerUDB_sT24_timerdp_u0__F0_REG )
        #define EchoTimer_CAPTURE_LSB_PTR       ((reg8 *) EchoTimer_TimerUDB_sT24_timerdp_u0__F0_REG )
        #define EchoTimer_PERIOD_LSB          (* (reg8 *) EchoTimer_TimerUDB_sT24_timerdp_u0__D0_REG )
        #define EchoTimer_PERIOD_LSB_PTR        ((reg8 *) EchoTimer_TimerUDB_sT24_timerdp_u0__D0_REG )
        #define EchoTimer_COUNTER_LSB         (* (reg8 *) EchoTimer_TimerUDB_sT24_timerdp_u0__A0_REG )
        #define EchoTimer_COUNTER_LSB_PTR       ((reg8 *) EchoTimer_TimerUDB_sT24_timerdp_u0__A0_REG )
    #elif(EchoTimer_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define EchoTimer_CAPTURE_LSB         (* (reg16 *) EchoTimer_TimerUDB_sT24_timerdp_u0__F0_REG )
            #define EchoTimer_CAPTURE_LSB_PTR       ((reg16 *) EchoTimer_TimerUDB_sT24_timerdp_u0__F0_REG )
            #define EchoTimer_PERIOD_LSB          (* (reg16 *) EchoTimer_TimerUDB_sT24_timerdp_u0__D0_REG )
            #define EchoTimer_PERIOD_LSB_PTR        ((reg16 *) EchoTimer_TimerUDB_sT24_timerdp_u0__D0_REG )
            #define EchoTimer_COUNTER_LSB         (* (reg16 *) EchoTimer_TimerUDB_sT24_timerdp_u0__A0_REG )
            #define EchoTimer_COUNTER_LSB_PTR       ((reg16 *) EchoTimer_TimerUDB_sT24_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define EchoTimer_CAPTURE_LSB         (* (reg16 *) EchoTimer_TimerUDB_sT24_timerdp_u0__16BIT_F0_REG )
            #define EchoTimer_CAPTURE_LSB_PTR       ((reg16 *) EchoTimer_TimerUDB_sT24_timerdp_u0__16BIT_F0_REG )
            #define EchoTimer_PERIOD_LSB          (* (reg16 *) EchoTimer_TimerUDB_sT24_timerdp_u0__16BIT_D0_REG )
            #define EchoTimer_PERIOD_LSB_PTR        ((reg16 *) EchoTimer_TimerUDB_sT24_timerdp_u0__16BIT_D0_REG )
            #define EchoTimer_COUNTER_LSB         (* (reg16 *) EchoTimer_TimerUDB_sT24_timerdp_u0__16BIT_A0_REG )
            #define EchoTimer_COUNTER_LSB_PTR       ((reg16 *) EchoTimer_TimerUDB_sT24_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(EchoTimer_Resolution <= 24u)/* 24-bit Timer */
        #define EchoTimer_CAPTURE_LSB         (* (reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__F0_REG )
        #define EchoTimer_CAPTURE_LSB_PTR       ((reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__F0_REG )
        #define EchoTimer_PERIOD_LSB          (* (reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__D0_REG )
        #define EchoTimer_PERIOD_LSB_PTR        ((reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__D0_REG )
        #define EchoTimer_COUNTER_LSB         (* (reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__A0_REG )
        #define EchoTimer_COUNTER_LSB_PTR       ((reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define EchoTimer_CAPTURE_LSB         (* (reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__F0_REG )
            #define EchoTimer_CAPTURE_LSB_PTR       ((reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__F0_REG )
            #define EchoTimer_PERIOD_LSB          (* (reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__D0_REG )
            #define EchoTimer_PERIOD_LSB_PTR        ((reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__D0_REG )
            #define EchoTimer_COUNTER_LSB         (* (reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__A0_REG )
            #define EchoTimer_COUNTER_LSB_PTR       ((reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define EchoTimer_CAPTURE_LSB         (* (reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__32BIT_F0_REG )
            #define EchoTimer_CAPTURE_LSB_PTR       ((reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__32BIT_F0_REG )
            #define EchoTimer_PERIOD_LSB          (* (reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__32BIT_D0_REG )
            #define EchoTimer_PERIOD_LSB_PTR        ((reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__32BIT_D0_REG )
            #define EchoTimer_COUNTER_LSB         (* (reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__32BIT_A0_REG )
            #define EchoTimer_COUNTER_LSB_PTR       ((reg32 *) EchoTimer_TimerUDB_sT24_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define EchoTimer_COUNTER_LSB_PTR_8BIT       ((reg8 *) EchoTimer_TimerUDB_sT24_timerdp_u0__A0_REG )
    
    #if (EchoTimer_UsingHWCaptureCounter)
        #define EchoTimer_CAP_COUNT              (*(reg8 *) EchoTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define EchoTimer_CAP_COUNT_PTR          ( (reg8 *) EchoTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define EchoTimer_CAPTURE_COUNT_CTRL     (*(reg8 *) EchoTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define EchoTimer_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) EchoTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (EchoTimer_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define EchoTimer_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define EchoTimer_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define EchoTimer_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define EchoTimer_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define EchoTimer_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define EchoTimer_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << EchoTimer_CTRL_INTCNT_SHIFT))
    #define EchoTimer_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << EchoTimer_CTRL_TRIG_MODE_SHIFT))
    #define EchoTimer_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << EchoTimer_CTRL_TRIG_EN_SHIFT))
    #define EchoTimer_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << EchoTimer_CTRL_CAP_MODE_SHIFT))
    #define EchoTimer_CTRL_ENABLE                    ((uint8)((uint8)0x01u << EchoTimer_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define EchoTimer_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define EchoTimer_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define EchoTimer_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define EchoTimer_STATUS_TC_INT_MASK_SHIFT       EchoTimer_STATUS_TC_SHIFT
    #define EchoTimer_STATUS_CAPTURE_INT_MASK_SHIFT  EchoTimer_STATUS_CAPTURE_SHIFT
    #define EchoTimer_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define EchoTimer_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define EchoTimer_STATUS_FIFOFULL_INT_MASK_SHIFT EchoTimer_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define EchoTimer_STATUS_TC                      ((uint8)((uint8)0x01u << EchoTimer_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define EchoTimer_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << EchoTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define EchoTimer_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << EchoTimer_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define EchoTimer_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << EchoTimer_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define EchoTimer_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << EchoTimer_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define EchoTimer_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << EchoTimer_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define EchoTimer_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << EchoTimer_STATUS_FIFOFULL_SHIFT))

    #define EchoTimer_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define EchoTimer_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define EchoTimer_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define EchoTimer_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define EchoTimer_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define EchoTimer_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_TIMER_EchoTimer_H */


/* [] END OF FILE */
