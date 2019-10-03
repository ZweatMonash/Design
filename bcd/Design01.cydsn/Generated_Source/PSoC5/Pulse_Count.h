/*******************************************************************************
* File Name: Pulse_Count.h
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

#if !defined(CY_COUNT7_Pulse_Count_H)
#define CY_COUNT7_Pulse_Count_H

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
void  Pulse_Count_Init(void) ;
void  Pulse_Count_Enable(void) ;
void  Pulse_Count_Start(void) ;
void  Pulse_Count_Stop(void) ;
void  Pulse_Count_WriteCounter(uint8 count) ;
uint8 Pulse_Count_ReadCounter(void) ;
void  Pulse_Count_WritePeriod(uint8 period) ;
uint8 Pulse_Count_ReadPeriod(void) ;
void  Pulse_Count_SaveConfig(void) ;
void  Pulse_Count_RestoreConfig(void) ;
void  Pulse_Count_Sleep(void) ;
void  Pulse_Count_Wakeup(void) ;


/***************************************
*     Data Struct Definitions
***************************************/
/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    uint8 count;
} Pulse_Count_BACKUP_STRUCT;


/***************************************
*           Global Variables
***************************************/
extern Pulse_Count_BACKUP_STRUCT Pulse_Count_backup;
extern uint8 Pulse_Count_initVar;


/***************************************
* Initial Parameter
***************************************/
#define Pulse_Count_INITIAL_PERIOD               (1u)


/***************************************
* Registers
***************************************/
#define Pulse_Count_COUNT_REG                    (*(reg8 *) Pulse_Count_Counter7__COUNT_REG)
#define Pulse_Count_COUNT_PTR                    ( (reg8 *) Pulse_Count_Counter7__COUNT_REG)
#define Pulse_Count_PERIOD_REG                   (*(reg8 *) Pulse_Count_Counter7__PERIOD_REG)
#define Pulse_Count_PERIOD_PTR                   ( (reg8 *) Pulse_Count_Counter7__PERIOD_REG)
#define Pulse_Count_AUX_CONTROL_REG              (*(reg8 *) Pulse_Count_Counter7__CONTROL_AUX_CTL_REG)
#define Pulse_Count_AUX_CONTROL_PTR              ( (reg8 *) Pulse_Count_Counter7__CONTROL_AUX_CTL_REG)


/***************************************
* Register Constants
***************************************/
#define Pulse_Count_COUNTER_START                (0x20u)

/* This constant is used to mask the TC bit (bit#7) in the Count register */
#define Pulse_Count_COUNT_7BIT_MASK              (0x7Fu)


#endif /* CY_COUNT7_Pulse_Count_H */


/* [] END OF FILE */
