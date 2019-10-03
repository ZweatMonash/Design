/*******************************************************************************
* File Name: OneSecTimer.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_OneSecTimer_H)
#define CY_PWM_OneSecTimer_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 OneSecTimer_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define OneSecTimer_Resolution                     (16u)
#define OneSecTimer_UsingFixedFunction             (0u)
#define OneSecTimer_DeadBandMode                   (0u)
#define OneSecTimer_KillModeMinTime                (0u)
#define OneSecTimer_KillMode                       (0u)
#define OneSecTimer_PWMMode                        (0u)
#define OneSecTimer_PWMModeIsCenterAligned         (0u)
#define OneSecTimer_DeadBandUsed                   (0u)
#define OneSecTimer_DeadBand2_4                    (0u)

#if !defined(OneSecTimer_PWMUDB_genblk8_stsreg__REMOVED)
    #define OneSecTimer_UseStatus                  (1u)
#else
    #define OneSecTimer_UseStatus                  (0u)
#endif /* !defined(OneSecTimer_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(OneSecTimer_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define OneSecTimer_UseControl                 (1u)
#else
    #define OneSecTimer_UseControl                 (0u)
#endif /* !defined(OneSecTimer_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define OneSecTimer_UseOneCompareMode              (1u)
#define OneSecTimer_MinimumKillTime                (1u)
#define OneSecTimer_EnableMode                     (0u)

#define OneSecTimer_CompareMode1SW                 (0u)
#define OneSecTimer_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define OneSecTimer__B_PWM__DISABLED 0
#define OneSecTimer__B_PWM__ASYNCHRONOUS 1
#define OneSecTimer__B_PWM__SINGLECYCLE 2
#define OneSecTimer__B_PWM__LATCHED 3
#define OneSecTimer__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define OneSecTimer__B_PWM__DBMDISABLED 0
#define OneSecTimer__B_PWM__DBM_2_4_CLOCKS 1
#define OneSecTimer__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define OneSecTimer__B_PWM__ONE_OUTPUT 0
#define OneSecTimer__B_PWM__TWO_OUTPUTS 1
#define OneSecTimer__B_PWM__DUAL_EDGE 2
#define OneSecTimer__B_PWM__CENTER_ALIGN 3
#define OneSecTimer__B_PWM__DITHER 5
#define OneSecTimer__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define OneSecTimer__B_PWM__LESS_THAN 1
#define OneSecTimer__B_PWM__LESS_THAN_OR_EQUAL 2
#define OneSecTimer__B_PWM__GREATER_THAN 3
#define OneSecTimer__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define OneSecTimer__B_PWM__EQUAL 0
#define OneSecTimer__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!OneSecTimer_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!OneSecTimer_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!OneSecTimer_PWMModeIsCenterAligned) */
        #if (OneSecTimer_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (OneSecTimer_UseStatus) */

        /* Backup for Deadband parameters */
        #if(OneSecTimer_DeadBandMode == OneSecTimer__B_PWM__DBM_256_CLOCKS || \
            OneSecTimer_DeadBandMode == OneSecTimer__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(OneSecTimer_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (OneSecTimer_KillModeMinTime) */

        /* Backup control register */
        #if(OneSecTimer_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (OneSecTimer_UseControl) */

    #endif /* (!OneSecTimer_UsingFixedFunction) */

}OneSecTimer_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    OneSecTimer_Start(void) ;
void    OneSecTimer_Stop(void) ;

#if (OneSecTimer_UseStatus || OneSecTimer_UsingFixedFunction)
    void  OneSecTimer_SetInterruptMode(uint8 interruptMode) ;
    uint8 OneSecTimer_ReadStatusRegister(void) ;
#endif /* (OneSecTimer_UseStatus || OneSecTimer_UsingFixedFunction) */

#define OneSecTimer_GetInterruptSource() OneSecTimer_ReadStatusRegister()

#if (OneSecTimer_UseControl)
    uint8 OneSecTimer_ReadControlRegister(void) ;
    void  OneSecTimer_WriteControlRegister(uint8 control)
          ;
#endif /* (OneSecTimer_UseControl) */

#if (OneSecTimer_UseOneCompareMode)
   #if (OneSecTimer_CompareMode1SW)
       void    OneSecTimer_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (OneSecTimer_CompareMode1SW) */
#else
    #if (OneSecTimer_CompareMode1SW)
        void    OneSecTimer_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (OneSecTimer_CompareMode1SW) */
    #if (OneSecTimer_CompareMode2SW)
        void    OneSecTimer_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (OneSecTimer_CompareMode2SW) */
#endif /* (OneSecTimer_UseOneCompareMode) */

#if (!OneSecTimer_UsingFixedFunction)
    uint16   OneSecTimer_ReadCounter(void) ;
    uint16 OneSecTimer_ReadCapture(void) ;

    #if (OneSecTimer_UseStatus)
            void OneSecTimer_ClearFIFO(void) ;
    #endif /* (OneSecTimer_UseStatus) */

    void    OneSecTimer_WriteCounter(uint16 counter)
            ;
#endif /* (!OneSecTimer_UsingFixedFunction) */

void    OneSecTimer_WritePeriod(uint16 period)
        ;
uint16 OneSecTimer_ReadPeriod(void) ;

#if (OneSecTimer_UseOneCompareMode)
    void    OneSecTimer_WriteCompare(uint16 compare)
            ;
    uint16 OneSecTimer_ReadCompare(void) ;
#else
    void    OneSecTimer_WriteCompare1(uint16 compare)
            ;
    uint16 OneSecTimer_ReadCompare1(void) ;
    void    OneSecTimer_WriteCompare2(uint16 compare)
            ;
    uint16 OneSecTimer_ReadCompare2(void) ;
#endif /* (OneSecTimer_UseOneCompareMode) */


#if (OneSecTimer_DeadBandUsed)
    void    OneSecTimer_WriteDeadTime(uint8 deadtime) ;
    uint8   OneSecTimer_ReadDeadTime(void) ;
#endif /* (OneSecTimer_DeadBandUsed) */

#if ( OneSecTimer_KillModeMinTime)
    void OneSecTimer_WriteKillTime(uint8 killtime) ;
    uint8 OneSecTimer_ReadKillTime(void) ;
#endif /* ( OneSecTimer_KillModeMinTime) */

void OneSecTimer_Init(void) ;
void OneSecTimer_Enable(void) ;
void OneSecTimer_Sleep(void) ;
void OneSecTimer_Wakeup(void) ;
void OneSecTimer_SaveConfig(void) ;
void OneSecTimer_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define OneSecTimer_INIT_PERIOD_VALUE          (999u)
#define OneSecTimer_INIT_COMPARE_VALUE1        (499u)
#define OneSecTimer_INIT_COMPARE_VALUE2        (63u)
#define OneSecTimer_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(1u <<   \
                                                    OneSecTimer_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    OneSecTimer_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    OneSecTimer_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    OneSecTimer_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define OneSecTimer_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  OneSecTimer_CTRL_CMPMODE2_SHIFT)
#define OneSecTimer_DEFAULT_COMPARE1_MODE      (uint8)((uint8)3u <<  OneSecTimer_CTRL_CMPMODE1_SHIFT)
#define OneSecTimer_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (OneSecTimer_UsingFixedFunction)
   #define OneSecTimer_PERIOD_LSB              (*(reg16 *) OneSecTimer_PWMHW__PER0)
   #define OneSecTimer_PERIOD_LSB_PTR          ( (reg16 *) OneSecTimer_PWMHW__PER0)
   #define OneSecTimer_COMPARE1_LSB            (*(reg16 *) OneSecTimer_PWMHW__CNT_CMP0)
   #define OneSecTimer_COMPARE1_LSB_PTR        ( (reg16 *) OneSecTimer_PWMHW__CNT_CMP0)
   #define OneSecTimer_COMPARE2_LSB            (0x00u)
   #define OneSecTimer_COMPARE2_LSB_PTR        (0x00u)
   #define OneSecTimer_COUNTER_LSB             (*(reg16 *) OneSecTimer_PWMHW__CNT_CMP0)
   #define OneSecTimer_COUNTER_LSB_PTR         ( (reg16 *) OneSecTimer_PWMHW__CNT_CMP0)
   #define OneSecTimer_CAPTURE_LSB             (*(reg16 *) OneSecTimer_PWMHW__CAP0)
   #define OneSecTimer_CAPTURE_LSB_PTR         ( (reg16 *) OneSecTimer_PWMHW__CAP0)
   #define OneSecTimer_RT1                     (*(reg8 *)  OneSecTimer_PWMHW__RT1)
   #define OneSecTimer_RT1_PTR                 ( (reg8 *)  OneSecTimer_PWMHW__RT1)

#else
   #if (OneSecTimer_Resolution == 8u) /* 8bit - PWM */

       #if(OneSecTimer_PWMModeIsCenterAligned)
           #define OneSecTimer_PERIOD_LSB      (*(reg8 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define OneSecTimer_PERIOD_LSB_PTR  ((reg8 *)   OneSecTimer_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define OneSecTimer_PERIOD_LSB      (*(reg8 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define OneSecTimer_PERIOD_LSB_PTR  ((reg8 *)   OneSecTimer_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (OneSecTimer_PWMModeIsCenterAligned) */

       #define OneSecTimer_COMPARE1_LSB        (*(reg8 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define OneSecTimer_COMPARE1_LSB_PTR    ((reg8 *)   OneSecTimer_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define OneSecTimer_COMPARE2_LSB        (*(reg8 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define OneSecTimer_COMPARE2_LSB_PTR    ((reg8 *)   OneSecTimer_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define OneSecTimer_COUNTERCAP_LSB      (*(reg8 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define OneSecTimer_COUNTERCAP_LSB_PTR  ((reg8 *)   OneSecTimer_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define OneSecTimer_COUNTER_LSB         (*(reg8 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define OneSecTimer_COUNTER_LSB_PTR     ((reg8 *)   OneSecTimer_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define OneSecTimer_CAPTURE_LSB         (*(reg8 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define OneSecTimer_CAPTURE_LSB_PTR     ((reg8 *)   OneSecTimer_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(OneSecTimer_PWMModeIsCenterAligned)
               #define OneSecTimer_PERIOD_LSB      (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define OneSecTimer_PERIOD_LSB_PTR  ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define OneSecTimer_PERIOD_LSB      (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define OneSecTimer_PERIOD_LSB_PTR  ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (OneSecTimer_PWMModeIsCenterAligned) */

            #define OneSecTimer_COMPARE1_LSB       (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define OneSecTimer_COMPARE1_LSB_PTR   ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define OneSecTimer_COMPARE2_LSB       (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define OneSecTimer_COMPARE2_LSB_PTR   ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define OneSecTimer_COUNTERCAP_LSB     (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define OneSecTimer_COUNTERCAP_LSB_PTR ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define OneSecTimer_COUNTER_LSB        (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define OneSecTimer_COUNTER_LSB_PTR    ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define OneSecTimer_CAPTURE_LSB        (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define OneSecTimer_CAPTURE_LSB_PTR    ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(OneSecTimer_PWMModeIsCenterAligned)
               #define OneSecTimer_PERIOD_LSB      (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define OneSecTimer_PERIOD_LSB_PTR  ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define OneSecTimer_PERIOD_LSB      (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define OneSecTimer_PERIOD_LSB_PTR  ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (OneSecTimer_PWMModeIsCenterAligned) */

            #define OneSecTimer_COMPARE1_LSB       (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define OneSecTimer_COMPARE1_LSB_PTR   ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define OneSecTimer_COMPARE2_LSB       (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define OneSecTimer_COMPARE2_LSB_PTR   ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define OneSecTimer_COUNTERCAP_LSB     (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define OneSecTimer_COUNTERCAP_LSB_PTR ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define OneSecTimer_COUNTER_LSB        (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define OneSecTimer_COUNTER_LSB_PTR    ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define OneSecTimer_CAPTURE_LSB        (*(reg16 *) OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define OneSecTimer_CAPTURE_LSB_PTR    ((reg16 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define OneSecTimer_AUX_CONTROLDP1          (*(reg8 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define OneSecTimer_AUX_CONTROLDP1_PTR      ((reg8 *)   OneSecTimer_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (OneSecTimer_Resolution == 8) */

   #define OneSecTimer_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define OneSecTimer_AUX_CONTROLDP0          (*(reg8 *)  OneSecTimer_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define OneSecTimer_AUX_CONTROLDP0_PTR      ((reg8 *)   OneSecTimer_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (OneSecTimer_UsingFixedFunction) */

#if(OneSecTimer_KillModeMinTime )
    #define OneSecTimer_KILLMODEMINTIME        (*(reg8 *)  OneSecTimer_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define OneSecTimer_KILLMODEMINTIME_PTR    ((reg8 *)   OneSecTimer_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (OneSecTimer_KillModeMinTime ) */

#if(OneSecTimer_DeadBandMode == OneSecTimer__B_PWM__DBM_256_CLOCKS)
    #define OneSecTimer_DEADBAND_COUNT         (*(reg8 *)  OneSecTimer_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define OneSecTimer_DEADBAND_COUNT_PTR     ((reg8 *)   OneSecTimer_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define OneSecTimer_DEADBAND_LSB_PTR       ((reg8 *)   OneSecTimer_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define OneSecTimer_DEADBAND_LSB           (*(reg8 *)  OneSecTimer_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(OneSecTimer_DeadBandMode == OneSecTimer__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (OneSecTimer_UsingFixedFunction)
        #define OneSecTimer_DEADBAND_COUNT         (*(reg8 *)  OneSecTimer_PWMHW__CFG0)
        #define OneSecTimer_DEADBAND_COUNT_PTR     ((reg8 *)   OneSecTimer_PWMHW__CFG0)
        #define OneSecTimer_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << OneSecTimer_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define OneSecTimer_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define OneSecTimer_DEADBAND_COUNT         (*(reg8 *)  OneSecTimer_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define OneSecTimer_DEADBAND_COUNT_PTR     ((reg8 *)   OneSecTimer_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define OneSecTimer_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << OneSecTimer_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define OneSecTimer_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (OneSecTimer_UsingFixedFunction) */
#endif /* (OneSecTimer_DeadBandMode == OneSecTimer__B_PWM__DBM_256_CLOCKS) */



#if (OneSecTimer_UsingFixedFunction)
    #define OneSecTimer_STATUS                 (*(reg8 *) OneSecTimer_PWMHW__SR0)
    #define OneSecTimer_STATUS_PTR             ((reg8 *) OneSecTimer_PWMHW__SR0)
    #define OneSecTimer_STATUS_MASK            (*(reg8 *) OneSecTimer_PWMHW__SR0)
    #define OneSecTimer_STATUS_MASK_PTR        ((reg8 *) OneSecTimer_PWMHW__SR0)
    #define OneSecTimer_CONTROL                (*(reg8 *) OneSecTimer_PWMHW__CFG0)
    #define OneSecTimer_CONTROL_PTR            ((reg8 *) OneSecTimer_PWMHW__CFG0)
    #define OneSecTimer_CONTROL2               (*(reg8 *) OneSecTimer_PWMHW__CFG1)
    #define OneSecTimer_CONTROL3               (*(reg8 *) OneSecTimer_PWMHW__CFG2)
    #define OneSecTimer_GLOBAL_ENABLE          (*(reg8 *) OneSecTimer_PWMHW__PM_ACT_CFG)
    #define OneSecTimer_GLOBAL_ENABLE_PTR      ( (reg8 *) OneSecTimer_PWMHW__PM_ACT_CFG)
    #define OneSecTimer_GLOBAL_STBY_ENABLE     (*(reg8 *) OneSecTimer_PWMHW__PM_STBY_CFG)
    #define OneSecTimer_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) OneSecTimer_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define OneSecTimer_BLOCK_EN_MASK          (OneSecTimer_PWMHW__PM_ACT_MSK)
    #define OneSecTimer_BLOCK_STBY_EN_MASK     (OneSecTimer_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define OneSecTimer_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define OneSecTimer_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define OneSecTimer_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define OneSecTimer_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define OneSecTimer_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define OneSecTimer_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define OneSecTimer_CTRL_ENABLE            (uint8)((uint8)0x01u << OneSecTimer_CTRL_ENABLE_SHIFT)
    #define OneSecTimer_CTRL_RESET             (uint8)((uint8)0x01u << OneSecTimer_CTRL_RESET_SHIFT)
    #define OneSecTimer_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << OneSecTimer_CTRL_CMPMODE2_SHIFT)
    #define OneSecTimer_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << OneSecTimer_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define OneSecTimer_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define OneSecTimer_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << OneSecTimer_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define OneSecTimer_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define OneSecTimer_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define OneSecTimer_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define OneSecTimer_STATUS_TC_INT_EN_MASK_SHIFT            (OneSecTimer_STATUS_TC_SHIFT - 4u)
    #define OneSecTimer_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define OneSecTimer_STATUS_CMP1_INT_EN_MASK_SHIFT          (OneSecTimer_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define OneSecTimer_STATUS_TC              (uint8)((uint8)0x01u << OneSecTimer_STATUS_TC_SHIFT)
    #define OneSecTimer_STATUS_CMP1            (uint8)((uint8)0x01u << OneSecTimer_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define OneSecTimer_STATUS_TC_INT_EN_MASK              (uint8)((uint8)OneSecTimer_STATUS_TC >> 4u)
    #define OneSecTimer_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)OneSecTimer_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define OneSecTimer_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define OneSecTimer_RT1_MASK              (uint8)((uint8)0x03u << OneSecTimer_RT1_SHIFT)
    #define OneSecTimer_SYNC                  (uint8)((uint8)0x03u << OneSecTimer_RT1_SHIFT)
    #define OneSecTimer_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define OneSecTimer_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << OneSecTimer_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define OneSecTimer_SYNCDSI_EN            (uint8)((uint8)0x0Fu << OneSecTimer_SYNCDSI_SHIFT)


#else
    #define OneSecTimer_STATUS                (*(reg8 *)   OneSecTimer_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define OneSecTimer_STATUS_PTR            ((reg8 *)    OneSecTimer_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define OneSecTimer_STATUS_MASK           (*(reg8 *)   OneSecTimer_PWMUDB_genblk8_stsreg__MASK_REG)
    #define OneSecTimer_STATUS_MASK_PTR       ((reg8 *)    OneSecTimer_PWMUDB_genblk8_stsreg__MASK_REG)
    #define OneSecTimer_STATUS_AUX_CTRL       (*(reg8 *)   OneSecTimer_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define OneSecTimer_CONTROL               (*(reg8 *)   OneSecTimer_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define OneSecTimer_CONTROL_PTR           ((reg8 *)    OneSecTimer_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define OneSecTimer_CTRL_ENABLE_SHIFT      (0x07u)
    #define OneSecTimer_CTRL_RESET_SHIFT       (0x06u)
    #define OneSecTimer_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define OneSecTimer_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define OneSecTimer_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define OneSecTimer_CTRL_ENABLE            (uint8)((uint8)0x01u << OneSecTimer_CTRL_ENABLE_SHIFT)
    #define OneSecTimer_CTRL_RESET             (uint8)((uint8)0x01u << OneSecTimer_CTRL_RESET_SHIFT)
    #define OneSecTimer_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << OneSecTimer_CTRL_CMPMODE2_SHIFT)
    #define OneSecTimer_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << OneSecTimer_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define OneSecTimer_STATUS_KILL_SHIFT          (0x05u)
    #define OneSecTimer_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define OneSecTimer_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define OneSecTimer_STATUS_TC_SHIFT            (0x02u)
    #define OneSecTimer_STATUS_CMP2_SHIFT          (0x01u)
    #define OneSecTimer_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define OneSecTimer_STATUS_KILL_INT_EN_MASK_SHIFT          (OneSecTimer_STATUS_KILL_SHIFT)
    #define OneSecTimer_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (OneSecTimer_STATUS_FIFONEMPTY_SHIFT)
    #define OneSecTimer_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (OneSecTimer_STATUS_FIFOFULL_SHIFT)
    #define OneSecTimer_STATUS_TC_INT_EN_MASK_SHIFT            (OneSecTimer_STATUS_TC_SHIFT)
    #define OneSecTimer_STATUS_CMP2_INT_EN_MASK_SHIFT          (OneSecTimer_STATUS_CMP2_SHIFT)
    #define OneSecTimer_STATUS_CMP1_INT_EN_MASK_SHIFT          (OneSecTimer_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define OneSecTimer_STATUS_KILL            (uint8)((uint8)0x00u << OneSecTimer_STATUS_KILL_SHIFT )
    #define OneSecTimer_STATUS_FIFOFULL        (uint8)((uint8)0x01u << OneSecTimer_STATUS_FIFOFULL_SHIFT)
    #define OneSecTimer_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << OneSecTimer_STATUS_FIFONEMPTY_SHIFT)
    #define OneSecTimer_STATUS_TC              (uint8)((uint8)0x01u << OneSecTimer_STATUS_TC_SHIFT)
    #define OneSecTimer_STATUS_CMP2            (uint8)((uint8)0x01u << OneSecTimer_STATUS_CMP2_SHIFT)
    #define OneSecTimer_STATUS_CMP1            (uint8)((uint8)0x01u << OneSecTimer_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define OneSecTimer_STATUS_KILL_INT_EN_MASK            (OneSecTimer_STATUS_KILL)
    #define OneSecTimer_STATUS_FIFOFULL_INT_EN_MASK        (OneSecTimer_STATUS_FIFOFULL)
    #define OneSecTimer_STATUS_FIFONEMPTY_INT_EN_MASK      (OneSecTimer_STATUS_FIFONEMPTY)
    #define OneSecTimer_STATUS_TC_INT_EN_MASK              (OneSecTimer_STATUS_TC)
    #define OneSecTimer_STATUS_CMP2_INT_EN_MASK            (OneSecTimer_STATUS_CMP2)
    #define OneSecTimer_STATUS_CMP1_INT_EN_MASK            (OneSecTimer_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define OneSecTimer_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define OneSecTimer_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define OneSecTimer_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define OneSecTimer_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define OneSecTimer_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* OneSecTimer_UsingFixedFunction */

#endif  /* CY_PWM_OneSecTimer_H */


/* [] END OF FILE */
