/*******************************************************************************
* File Name: Compare.c
* Version 2.0
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Analog Comparator User Module.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_COMP_Compare_H) 
#define CY_COMP_Compare_H

#include "cytypes.h"
#include "CyLib.h"
#include "cyfitter.h" 


#define Compare_RECALMODE (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Comp_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*       Type defines
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
   /* uint8 compCRReg; */
}Compare_backupStruct;

#if (CY_PSOC5A)
    /* Stop API changes for PSoC5A */
    typedef struct
    {
        uint8 compCRReg;
    }   Compare_LOWPOWER_BACKUP_STRUCT;
#endif /* CY_PSOC5A */

/* component init state */
extern uint8 Compare_initVar;


/**************************************
*        Function Prototypes 
**************************************/

void    Compare_Start(void)                  ;
void    Compare_Stop(void)                   ;
void    Compare_SetSpeed(uint8 speed)        ;
uint8   Compare_GetCompare(void)             ;
uint16  Compare_ZeroCal(void)                ;
void    Compare_LoadTrim(uint16 trimVal)     ;
void Compare_Init(void)                      ; 
void Compare_Enable(void)                    ;
void Compare_SaveConfig(void)                ;
void Compare_RestoreConfig(void)             ;
void Compare_Sleep(void)                     ;
void Compare_Wakeup(void)                    ;
/* Below APIs are valid only for PSoC3, PSoC5LP silicons.*/
#if (CY_PSOC3 || CY_PSOC5LP) 
    void Compare_PwrDwnOverrideEnable(void)  ;
    void Compare_PwrDwnOverrideDisable(void) ;
#endif /* CY_PSOC3 || CY_PSOC5LP */


/**************************************
*           API Constants        
**************************************/

/* Power constants for SetSpeed() function */
#define Compare_SLOWSPEED   (0x00u)
#define Compare_HIGHSPEED   (0x01u)
#define Compare_LOWPOWER    (0x02u)


/**************************************
*           Parameter Defaults        
**************************************/

#define Compare_DEFAULT_SPEED       (0u) 
#define Compare_DEFAULT_HYSTERESIS  (0u)
#define Compare_DEFAULT_POLARITY    (0u)
#define Compare_DEFAULT_BYPASS_SYNC (1u)
#define Compare_DEFAULT_PWRDWN_OVRD (0u)


/**************************************
*             Registers        
**************************************/
#define Compare_CR_REG            (* (reg8 *) Compare_ctComp__CR )               /* Config register */
#define Compare_CR_PTR            (  (reg8 *) Compare_ctComp__CR )
#define Compare_CLK_REG           (* (reg8 *) Compare_ctComp__CLK )  /* Comp clock control register */
#define Compare_CLK_PTR           (  (reg8 *) Compare_ctComp__CLK )
#define Compare_SW0_REG           (* (reg8 *) Compare_ctComp__SW0 )            /* Routing registers */
#define Compare_SW0_PTR           (  (reg8 *) Compare_ctComp__SW0 )
#define Compare_SW2_REG           (* (reg8 *) Compare_ctComp__SW2 )
#define Compare_SW2_PTR           (  (reg8 *) Compare_ctComp__SW2 )
#define Compare_SW3_REG           (* (reg8 *) Compare_ctComp__SW3 )
#define Compare_SW3_PTR           (  (reg8 *) Compare_ctComp__SW3 )
#define Compare_SW4_REG           (* (reg8 *) Compare_ctComp__SW4 )
#define Compare_SW4_PTR           (  (reg8 *) Compare_ctComp__SW4 )
#define Compare_SW6_REG           (* (reg8 *) Compare_ctComp__SW6 )
#define Compare_SW6_PTR           (  (reg8 *) Compare_ctComp__SW6 )

/* Trim registers */
/* PSoC5A */
#if (CY_PSOC5A)
    #define Compare_TR_REG        (* (reg8 *) Compare_ctComp__TR )                /* Trim registers */
    #define Compare_TR_PTR        (  (reg8 *) Compare_ctComp__TR )
#endif /* CY_PSOC5A */

/* PSoC3, PSoC5LP or later */
#if (CY_PSOC3 || CY_PSOC5LP) 
    #define Compare_TR0_REG       (* (reg8 *) Compare_ctComp__TR0 )/* Trim register for P-type load */
    #define Compare_TR0_PTR       (  (reg8 *) Compare_ctComp__TR0 ) 
    #define Compare_TR1_REG       (* (reg8 *) Compare_ctComp__TR1 )/* Trim register for N-type load */
    #define Compare_TR1_PTR       (  (reg8 *) Compare_ctComp__TR1 ) 
#endif /* CY_PSOC3 || CY_PSOC5LP */

#define Compare_WRK_REG           (* (reg8 *) Compare_ctComp__WRK )    /* Working register - output */
#define Compare_WRK_PTR           (  (reg8 *) Compare_ctComp__WRK )
#define Compare_PWRMGR_REG        (* (reg8 *) Compare_ctComp__PM_ACT_CFG )  /* Active Power manager */
#define Compare_PWRMGR_PTR        (  (reg8 *) Compare_ctComp__PM_ACT_CFG )
#define Compare_STBY_PWRMGR_REG   (* (reg8 *) Compare_ctComp__PM_STBY_CFG )/* Standby Power manager */
#define Compare_STBY_PWRMGR_PTR   (  (reg8 *) Compare_ctComp__PM_STBY_CFG )

/*      Trim Locations      */
#define Compare_ctComp__TRIM__TR0_HS_PTR     ((void CYFAR *) Compare_ctComp__TRIM__TR0_HS)
#define Compare_ctComp__TRIM__TR0_HS_REG     CY_GET_XTND_REG8(Compare_ctComp__TRIM__TR0_HS_PTR)
#if (CY_PSOC3 || CY_PSOC5LP)
    #define Compare_ctComp__TRIM__TR1_HS_PTR ((void CYFAR *) Compare_ctComp__TRIM__TR1_HS)
    #define Compare_ctComp__TRIM__TR1_HS_REG CY_GET_XTND_REG8(Compare_ctComp__TRIM__TR1_HS_PTR)
#endif /* (CY_PSOC3 || CY_PSOC5LP) */
#define Compare_ctComp__TRIM__TR0_LS_PTR     ((void CYFAR *) ((uint32)Compare_ctComp__TRIM__TR0 + 1u))
#define Compare_ctComp__TRIM__TR0_LS_REG     CY_GET_XTND_REG8(Compare_ctComp__TRIM__TR0_LS_PTR)
#if (CY_PSOC3 || CY_PSOC5LP)
    #define Compare_ctComp__TRIM__TR1_LS_PTR ((void CYFAR *) ((uint32)Compare_ctComp__TRIM__TR1 + 1u))
    #define Compare_ctComp__TRIM__TR1_LS_REG CY_GET_XTND_REG8(Compare_ctComp__TRIM__TR1_LS_PTR)
#endif /* CY_PSOC3 || CY_PSOC5LP */


/***************************************
*  Registers definitions
* for backward capability        
***************************************/
#define Compare_CR                (* (reg8 *) Compare_ctComp__CR )               /* Config register */
#define Compare_CLK               (* (reg8 *) Compare_ctComp__CLK )  /* Comp clock control register */
#define Compare_SW0               (* (reg8 *) Compare_ctComp__SW0 )            /* Routing registers */
#define Compare_SW2               (* (reg8 *) Compare_ctComp__SW2 )
#define Compare_SW3               (* (reg8 *) Compare_ctComp__SW3 )
#define Compare_SW4               (* (reg8 *) Compare_ctComp__SW4 )
#define Compare_SW6               (* (reg8 *) Compare_ctComp__SW6 )

/* Trim registers */
/* PSoC5A */
#if (CY_PSOC5A)
    #define Compare_TR            (* (reg8 *) Compare_ctComp__TR )                /* Trim registers */
#endif /* CY_PSOC5A */

/* PSoC3, PSoC5LP or later */
#if (CY_PSOC3 || CY_PSOC5LP) 
    #define Compare_TR0           (* (reg8 *) Compare_ctComp__TR0 )/* Trim register for P-type load */
    #define Compare_TR1           (* (reg8 *) Compare_ctComp__TR1 )/* Trim register for N-type load */
#endif /* CY_PSOC3 || CY_PSOC5LP */

#define Compare_WRK               (* (reg8 *) Compare_ctComp__WRK )    /* Working register - output */
#define Compare_PWRMGR            (* (reg8 *) Compare_ctComp__PM_ACT_CFG )  /* Active Power manager */
#define Compare_STBY_PWRMGR       (* (reg8 *) Compare_ctComp__PM_STBY_CFG )/* Standby Power manager */

/*      Trim Locations      */
#define Compare_HS_TRIM_TR0        CY_GET_XTND_REG8(Compare_ctComp__TRIM__TR0_HS_PTR)
#if (CY_PSOC3 || CY_PSOC5LP)
    #define Compare_HS_TRIM_TR1    CY_GET_XTND_REG8(Compare_ctComp__TRIM__TR1_HS_PTR)
#endif /* (CY_PSOC3 || CY_PSOC5LP) */
#define Compare_LS_TRIM_TR0        CY_GET_XTND_REG8(Compare_ctComp__TRIM__TR0_LS_PTR)
#if (CY_PSOC3 || CY_PSOC5LP)
    #define Compare_LS_TRIM_TR1    CY_GET_XTND_REG8(Compare_ctComp__TRIM__TR1_LS_PTR)
#endif /* CY_PSOC3 || CY_PSOC5LP */


/**************************************
*       Register Constants        
**************************************/

/* CR (Comp Control Register)             */
#define Compare_CFG_MODE_MASK      (0x78u)
#define Compare_FILTER_ON          (0x40u)
#define Compare_HYST_OFF           (0x20u)
#define Compare_CAL_ON             (0x10u)
#define Compare_MX_AO              (0x08u)
#define Compare_PWRDWN_OVRD        (0x04u)

#define Compare_PWR_MODE_SHIFT     (0x00u)
#define Compare_PWR_MODE_MASK      ((uint8)(0x03u << Compare_PWR_MODE_SHIFT))
#define Compare_PWR_MODE_SLOW      ((uint8)(0x00u << Compare_PWR_MODE_SHIFT))
#define Compare_PWR_MODE_FAST      ((uint8)(0x01u << Compare_PWR_MODE_SHIFT))
#define Compare_PWR_MODE_ULOW      ((uint8)(0x02u << Compare_PWR_MODE_SHIFT))

/* CLK (Comp Clock Control Register)      */
#define Compare_BYPASS_SYNC        (0x10u)
#define Compare_SYNC_CLK_EN        (0x08u)
#define Compare_SYNCCLK_MASK       (Compare_BYPASS_SYNC | Compare_SYNC_CLK_EN)

/* SW3 Routing Register definitions */
#define Compare_CMP_SW3_INPCTL_MASK (0x09u)   /* SW3 bits for inP routing control */

/* TR (Comp Trim Register)     */
#define Compare_DEFAULT_CMP_TRIM    (0x00u)

/* PSoC5A */
#if (CY_PSOC5A)
    #define Compare_CMP_TRIM1_DIR   (0x08u)   /* Trim direction for N-type load for offset calibration */
    #define Compare_CMP_TRIM1_MASK  (0x07u)   /* Trim for N-type load for offset calibration */
    #define Compare_CMP_TRIM2_DIR   (0x80u)   /* Trim direction for P-type load for offset calibration */
    #define Compare_CMP_TRIM2_MASK  (0x70u)   /* Trim for P-type load for offset calibration */
#endif /* CY_PSOC5A */

/* PSoC3, PSoC5LP or later */
#if (CY_PSOC3 || CY_PSOC5LP)
    #define Compare_CMP_TR0_DIR     (0x10u)   /* Trim direction for N-type load for offset calibration */
    #define Compare_CMP_TR0_MASK    (0x0Fu)   /* Trim for N-type load for offset calibration */
    #define Compare_CMP_TR1_DIR     (0x10u)   /* Trim direction for P-type load for offset calibration */
    #define Compare_CMP_TR1_MASK    (0x07u)   /* Trim for P-type load for offset calibration */ 
#endif /* CY_PSOC3 || CY_PSOC5LP */


/* WRK (Comp output working register)     */ 
#define Compare_CMP_OUT_MASK       Compare_ctComp__WRK_MASK /* Specific comparator out mask */

/* PM_ACT_CFG7 (Active Power Mode CFG Register)     */ 
#define Compare_ACT_PWR_EN         Compare_ctComp__PM_ACT_MSK /* Power enable mask */

/* PM_STBY_CFG7 (Standby Power Mode CFG Register)     */ 
#define Compare_STBY_PWR_EN        Compare_ctComp__PM_STBY_MSK /* Standby Power enable mask */

#if (CY_PSOC5A)
    /* For stop API changes mask to make the COMP register CR to 0X00  */
    #define Compare_COMP_REG_CLR   (0x00u)
#endif /* CY_PSOC5A */

#endif /* CY_COMP_Compare_H */


/* [] END OF FILE */
