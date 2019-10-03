/*******************************************************************************
* File Name: Isr_Fing_Out.h
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
#if !defined(CY_ISR_Isr_Fing_Out_H)
#define CY_ISR_Isr_Fing_Out_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Isr_Fing_Out_Start(void);
void Isr_Fing_Out_StartEx(cyisraddress address);
void Isr_Fing_Out_Stop(void);

CY_ISR_PROTO(Isr_Fing_Out_Interrupt);

void Isr_Fing_Out_SetVector(cyisraddress address);
cyisraddress Isr_Fing_Out_GetVector(void);

void Isr_Fing_Out_SetPriority(uint8 priority);
uint8 Isr_Fing_Out_GetPriority(void);

void Isr_Fing_Out_Enable(void);
uint8 Isr_Fing_Out_GetState(void);
void Isr_Fing_Out_Disable(void);

void Isr_Fing_Out_SetPending(void);
void Isr_Fing_Out_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Isr_Fing_Out ISR. */
#define Isr_Fing_Out_INTC_VECTOR            ((reg32 *) Isr_Fing_Out__INTC_VECT)

/* Address of the Isr_Fing_Out ISR priority. */
#define Isr_Fing_Out_INTC_PRIOR             ((reg8 *) Isr_Fing_Out__INTC_PRIOR_REG)

/* Priority of the Isr_Fing_Out interrupt. */
#define Isr_Fing_Out_INTC_PRIOR_NUMBER      Isr_Fing_Out__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Isr_Fing_Out interrupt. */
#define Isr_Fing_Out_INTC_SET_EN            ((reg32 *) Isr_Fing_Out__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Isr_Fing_Out interrupt. */
#define Isr_Fing_Out_INTC_CLR_EN            ((reg32 *) Isr_Fing_Out__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Isr_Fing_Out interrupt state to pending. */
#define Isr_Fing_Out_INTC_SET_PD            ((reg32 *) Isr_Fing_Out__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Isr_Fing_Out interrupt. */
#define Isr_Fing_Out_INTC_CLR_PD            ((reg32 *) Isr_Fing_Out__INTC_CLR_PD_REG)


#endif /* CY_ISR_Isr_Fing_Out_H */


/* [] END OF FILE */
