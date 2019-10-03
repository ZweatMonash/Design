/*******************************************************************************
* File Name: FreqCount_INT.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_FreqCount_INT_H)
#define CY_ISR_FreqCount_INT_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void FreqCount_INT_Start(void);
void FreqCount_INT_StartEx(cyisraddress address);
void FreqCount_INT_Stop(void);

CY_ISR_PROTO(FreqCount_INT_Interrupt);

void FreqCount_INT_SetVector(cyisraddress address);
cyisraddress FreqCount_INT_GetVector(void);

void FreqCount_INT_SetPriority(uint8 priority);
uint8 FreqCount_INT_GetPriority(void);

void FreqCount_INT_Enable(void);
uint8 FreqCount_INT_GetState(void);
void FreqCount_INT_Disable(void);

void FreqCount_INT_SetPending(void);
void FreqCount_INT_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the FreqCount_INT ISR. */
#define FreqCount_INT_INTC_VECTOR            ((reg32 *) FreqCount_INT__INTC_VECT)

/* Address of the FreqCount_INT ISR priority. */
#define FreqCount_INT_INTC_PRIOR             ((reg8 *) FreqCount_INT__INTC_PRIOR_REG)

/* Priority of the FreqCount_INT interrupt. */
#define FreqCount_INT_INTC_PRIOR_NUMBER      FreqCount_INT__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable FreqCount_INT interrupt. */
#define FreqCount_INT_INTC_SET_EN            ((reg32 *) FreqCount_INT__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the FreqCount_INT interrupt. */
#define FreqCount_INT_INTC_CLR_EN            ((reg32 *) FreqCount_INT__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the FreqCount_INT interrupt state to pending. */
#define FreqCount_INT_INTC_SET_PD            ((reg32 *) FreqCount_INT__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the FreqCount_INT interrupt. */
#define FreqCount_INT_INTC_CLR_PD            ((reg32 *) FreqCount_INT__INTC_CLR_PD_REG)


#endif /* CY_ISR_FreqCount_INT_H */


/* [] END OF FILE */
