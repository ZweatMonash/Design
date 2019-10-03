/*******************************************************************************
* File Name: Isr_High_Thres.h
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
#if !defined(CY_ISR_Isr_High_Thres_H)
#define CY_ISR_Isr_High_Thres_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Isr_High_Thres_Start(void);
void Isr_High_Thres_StartEx(cyisraddress address);
void Isr_High_Thres_Stop(void);

CY_ISR_PROTO(Isr_High_Thres_Interrupt);

void Isr_High_Thres_SetVector(cyisraddress address);
cyisraddress Isr_High_Thres_GetVector(void);

void Isr_High_Thres_SetPriority(uint8 priority);
uint8 Isr_High_Thres_GetPriority(void);

void Isr_High_Thres_Enable(void);
uint8 Isr_High_Thres_GetState(void);
void Isr_High_Thres_Disable(void);

void Isr_High_Thres_SetPending(void);
void Isr_High_Thres_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Isr_High_Thres ISR. */
#define Isr_High_Thres_INTC_VECTOR            ((reg32 *) Isr_High_Thres__INTC_VECT)

/* Address of the Isr_High_Thres ISR priority. */
#define Isr_High_Thres_INTC_PRIOR             ((reg8 *) Isr_High_Thres__INTC_PRIOR_REG)

/* Priority of the Isr_High_Thres interrupt. */
#define Isr_High_Thres_INTC_PRIOR_NUMBER      Isr_High_Thres__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Isr_High_Thres interrupt. */
#define Isr_High_Thres_INTC_SET_EN            ((reg32 *) Isr_High_Thres__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Isr_High_Thres interrupt. */
#define Isr_High_Thres_INTC_CLR_EN            ((reg32 *) Isr_High_Thres__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Isr_High_Thres interrupt state to pending. */
#define Isr_High_Thres_INTC_SET_PD            ((reg32 *) Isr_High_Thres__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Isr_High_Thres interrupt. */
#define Isr_High_Thres_INTC_CLR_PD            ((reg32 *) Isr_High_Thres__INTC_CLR_PD_REG)


#endif /* CY_ISR_Isr_High_Thres_H */


/* [] END OF FILE */
