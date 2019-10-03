/*******************************************************************************
* File Name: Tx.h
* Version 1.0
*
* Description:
*  This header file contains registers and constants associated with the
*  Count7 component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_COUNT7_Tx_H)
#define CY_COUNT7_Tx_H

#include "cyfitter.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))
    #include "cytypes.h"
    #include "CyLib.h"
#else
    #include "syslib/cy_syslib.h"
#endif


/***************************************
* Function Prototypes
***************************************/
void  Tx_Init(void) ;
void  Tx_Enable(void) ;
void  Tx_Start(void) ;
void  Tx_Stop(void) ;
void  Tx_WriteCounter(uint8 count) ;
uint8 Tx_ReadCounter(void) ;
void  Tx_WritePeriod(uint8 period) ;
uint8 Tx_ReadPeriod(void) ;
void  Tx_SaveConfig(void) ;
void  Tx_RestoreConfig(void) ;
void  Tx_Sleep(void) ;
void  Tx_Wakeup(void) ;


/***************************************
*     Data Struct Definitions
***************************************/
/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    uint8 count;
} Tx_BACKUP_STRUCT;


/***************************************
*           Global Variables
***************************************/
extern Tx_BACKUP_STRUCT Tx_backup;
extern uint8 Tx_initVar;


/***************************************
* Initial Parameter
***************************************/
#define Tx_INITIAL_PERIOD               (10u)


/***************************************
* Registers
***************************************/
#define Tx_COUNT_REG                    (*(reg8 *) Tx_Counter7__COUNT_REG)
#define Tx_COUNT_PTR                    ( (reg8 *) Tx_Counter7__COUNT_REG)
#define Tx_PERIOD_REG                   (*(reg8 *) Tx_Counter7__PERIOD_REG)
#define Tx_PERIOD_PTR                   ( (reg8 *) Tx_Counter7__PERIOD_REG)
#define Tx_AUX_CONTROL_REG              (*(reg8 *) Tx_Counter7__CONTROL_AUX_CTL_REG)
#define Tx_AUX_CONTROL_PTR              ( (reg8 *) Tx_Counter7__CONTROL_AUX_CTL_REG)


/***************************************
* Register Constants
***************************************/
#define Tx_COUNTER_START                (0x20u)

/* This constant is used to mask the TC bit (bit#7) in the Count register */
#define Tx_COUNT_7BIT_MASK              (0x7Fu)


#endif /* CY_COUNT7_Tx_H */


/* [] END OF FILE */
