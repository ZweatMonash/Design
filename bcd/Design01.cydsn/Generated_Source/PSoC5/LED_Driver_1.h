/*******************************************************************************
* File Name: LED_Driver_1.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values and API definition for the
*  LED Driver Component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_LED_Driver_LED_Driver_1_H)
#define CY_LED_Driver_LED_Driver_1_H


/***************************************
*   Conditional Compilation Parameters
***************************************/
#define LED_Driver_1_BRIGHTNESS_EN                (0u)
#define LED_Driver_1_COM_DRIVE                    (0u)
#define LED_Driver_1_SEG_DRIVE                    (0u)
#define LED_Driver_1_NUM_COM                      (4u)
#define LED_Driver_1_NUM_SEG                      (7u)
#define LED_Driver_1_TWO_NUM_COM                  ((uint8)((uint8)LED_Driver_1_NUM_COM << 1u))

/* Error message for removed commons control register through optimization */
#ifdef LED_Driver_1_Com_Driver_Sync_ctrl_reg__REMOVED
    #error LED_Driver_v1_10 requires all the signals from the commons terminal to be connected to pins.
#endif /* LED_Driver_1_Com_Driver_Sync_ctrl_reg__REMOVED */

/* Error message for removed segments control registers through optimization */
#if defined LED_Driver_1_Seg_Driver_L_Sync_ctrl_reg__REMOVED || \
defined LED_Driver_1_Seg_Driver_M_Sync_ctrl_reg__REMOVED || \
defined LED_Driver_1_Seg_Driver_H_Sync_ctrl_reg__REMOVED
    #error LED_Driver_v1_10 requires all the signals from the segments terminal to be connected to pins.
#endif /* LED_Driver_1_Seg_Driver_L_Sync_ctrl_reg__REMOVED */


/***************************************
*   Header files
***************************************/
#include <LED_Driver_1_Com_Driver.h>
#include <LED_Driver_1_Seg_Driver_L.h>
#if (LED_Driver_1_NUM_SEG > 8u)
    #include <LED_Driver_1_Seg_Driver_M.h>
#endif /* Segment_M control register */
#if (LED_Driver_1_NUM_SEG > 16u)
    #include <LED_Driver_1_Seg_Driver_H.h>
#endif /* Segment_H control register */

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#ifndef CY_PSOC5A
    #error Component LED_Driver_v1_10 requires cy_boot v3.0 or later
#endif /* CY_PSOC5A */


/***************************************
*        Structure Definitions
***************************************/
typedef struct
{
    uint8 ledEnableState;
    /* Backup the segment values when going to sleep. (Stop() clears the buffers) */
    uint8 segLBackup[LED_Driver_1_NUM_COM];
    #if (LED_Driver_1_NUM_SEG > 8u) 
        uint8 segMBackup[LED_Driver_1_NUM_COM];
    #endif /* (LED_Driver_1_NUM_SEG > 8u) */
    #if (LED_Driver_1_NUM_SEG > 16u) 
        uint8 segHBackup[LED_Driver_1_NUM_COM];
    #endif /* (LED_Driver_1_NUM_SEG > 16u) */
}LED_Driver_1_backupStruct;


/***************************************
*        Function Prototypes
***************************************/
void LED_Driver_1_Init(void)                       ;
void LED_Driver_1_Enable(void)                     ;
void LED_Driver_1_Start(void)                      ;
void LED_Driver_1_Stop(void)                       ;
void LED_Driver_1_SetDisplayRAM(uint8 value, uint8 position) 
                                                        ;
void LED_Driver_1_SetRC(uint8 row, uint8 column)    ;
void LED_Driver_1_ClearRC(uint8 row, uint8 column)  ;
void LED_Driver_1_ToggleRC(uint8 row, uint8 column) ;
uint8 LED_Driver_1_GetRC(uint8 row, uint8 column)   ;
void LED_Driver_1_ClearDisplay(uint8 position)      ;
void LED_Driver_1_ClearDisplayAll(void)             ;
void LED_Driver_1_Write7SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void LED_Driver_1_Write7SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void LED_Driver_1_WriteString7Seg(char8 const character[], uint8 position)
                                                        ;
void LED_Driver_1_PutChar7Seg(char8 character , uint8 position)
                                                        ;
void LED_Driver_1_Write7SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void LED_Driver_1_Write7SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void LED_Driver_1_Write14SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void LED_Driver_1_Write14SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void LED_Driver_1_WriteString14Seg(char8 const character[], uint8 position)
                                                        ;
void LED_Driver_1_PutChar14Seg(char8 character , uint8 position)
                                                        ;
void LED_Driver_1_Write14SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void LED_Driver_1_Write14SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void LED_Driver_1_Write16SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void LED_Driver_1_Write16SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void LED_Driver_1_WriteString16Seg(char8 const character[], uint8 position)
                                                        ;
void LED_Driver_1_PutChar16Seg(char8 character , uint8 position)
                                                        ;
void LED_Driver_1_Write16SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void LED_Driver_1_Write16SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void LED_Driver_1_PutDecimalPoint(uint8 dp, uint8 position)
                                                        ;
uint8 LED_Driver_1_GetDecimalPoint(uint8 position)  ;
uint8 LED_Driver_1_EncodeNumber7Seg(uint8 number)   ;
uint8 LED_Driver_1_EncodeChar7Seg(char8 input)      ;
uint16 LED_Driver_1_EncodeNumber14Seg(uint8 number) ;
uint16 LED_Driver_1_EncodeChar14Seg(char8 input)    ;
uint16 LED_Driver_1_EncodeNumber16Seg(uint8 number) ;
uint16 LED_Driver_1_EncodeChar16Seg(char8 input)    ;
void LED_Driver_1_SetBrightness(uint8 bright, uint8 position)
                                                        ;
uint8 LED_Driver_1_GetBrightness(uint8 position)    ;
void LED_Driver_1_Sleep(void)                       ;
void LED_Driver_1_Wakeup(void)                      ;


/***************************************
*           Global Variables
***************************************/
extern uint8 LED_Driver_1_initVar;
extern uint8 LED_Driver_1_enableVar;

/* Buffers used to hold the display(segment) values to be transferred to the control registers */
extern uint8 LED_Driver_1_segLBuffer[LED_Driver_1_NUM_COM];
#if (LED_Driver_1_NUM_SEG > 8u) 
    extern uint8 LED_Driver_1_segMBuffer[LED_Driver_1_NUM_COM];
#endif /* (LED_Driver_1_NUM_SEG > 8u) */
#if (LED_Driver_1_NUM_SEG > 16u) 
    extern uint8 LED_Driver_1_segHBuffer[LED_Driver_1_NUM_COM];
#endif /* (LED_Driver_1_NUM_SEG > 16u) */


/***************************************
*           API Constants
***************************************/

/* Related to conditional compilation */
#define LED_Driver_1_HIGH                   (0x01u)
#define LED_Driver_1_ENABLED                (0x01u)

/* Number of DMA channels */
#if (LED_Driver_1_BRIGHTNESS_EN == LED_Driver_1_ENABLED)
    #define LED_Driver_1_CHANNEL_LIMIT      (0x03u)
#else
    #define LED_Driver_1_CHANNEL_LIMIT      (0x02u)
#endif /* (LED_Driver_1_BRIGHTNESS_EN == LED_Driver_1_ENABLED) */

/* Defines related to sign extraction for number displays */
#define LED_Driver_1_SIGNED                 (0x01u)
#define LED_Driver_1_UNSIGNED               (0x00u)
#define LED_Driver_1_ZERO_NEG               ((int32)0x00000000)

/* Brightness control defines */
#define LED_Driver_1_INIT_BRIGHT            (0xFFu)

/* Segment display defines */
#if(LED_Driver_1_SEG_DRIVE == LED_Driver_1_HIGH)
    #define LED_Driver_1_CLEAR              (0x00u)
    #define LED_Driver_1_CLEAR_16           ((uint16)0x0000u)
    #define LED_Driver_1_ZERO_7CHAR         (0x3Fu)
    #define LED_Driver_1_ZERO_14CHAR        ((uint16)0x243Fu)
    #define LED_Driver_1_ZERO_16CHAR        ((uint16)0x90FFu)
#else
    #define LED_Driver_1_CLEAR              (0xFFu)
    #define LED_Driver_1_CLEAR_16           ((uint16)0xFFFFu)
    #define LED_Driver_1_ZERO_7CHAR         (0xC0u)
    #define LED_Driver_1_ZERO_14CHAR        ((uint16)0xDBC0u)
    #define LED_Driver_1_ZERO_16CHAR        ((uint16)0x6F00u)
#endif /* (LED_Driver_1_SEG_DRIVE == LED_Driver_1_HIGH) */

/* Shifts and 4-bit operation mask */
#define LED_Driver_1_SHIFT_NIBBLE           (0x04u)
#define LED_Driver_1_NIBBLE_MASK            (0x0Fu)
#define LED_Driver_1_SHIFT_BYTE             (0x08u)

/* ASCII table access defines */
#define LED_Driver_1_SEG_ASCII_OFFSET       (0x02u)
#define LED_Driver_1_SEG_ASCII_LIM_HI       (0x08u)
#define LED_Driver_1_SEG_ASCII_LIM_LO       (0x01u)

/* Decimal point defines */
#define LED_Driver_1_DEC_POINT              (0x07u)
#define LED_Driver_1_DEC_POINT_MASK         (0x01u)
#if(LED_Driver_1_SEG_DRIVE == LED_Driver_1_HIGH)
    #define LED_Driver_1_DEC_POINT_VALUE    (0x80u)
#else
    #define LED_Driver_1_DEC_POINT_VALUE    (0x7Fu)
#endif /* (LED_Driver_1_SEG_DRIVE == LED_Driver_1_HIGH) */

/* 7-seg position to register mapping defines */
#define LED_Driver_1_SEG_REG_LOW            (0x00u)
#define LED_Driver_1_SEG_REG_MID            (0x01u)
#define LED_Driver_1_SEG_REG_HIGH           (0x02u)

/* Segment display alignment defines */
#define LED_Driver_1_RIGHT_ALIGN            (0x00u)
#define LED_Driver_1_LEFT_ALIGN             (0x01u)
#define LED_Driver_1_ZERO_PAD               (0x02u)


/***************************************
*           Registers
***************************************/
#define LED_Driver_1_CONTROL_REG_BASE       (CYDEV_PERIPH_BASE)
#define LED_Driver_1_SRAM_BASE              (CYDEV_SRAM_BASE)

#define LED_Driver_1_COM_CONTROL_PTR        (LED_Driver_1_Com_Driver_Control_PTR)
#define LED_Driver_1_SEG_L_CONTROL_PTR      (LED_Driver_1_Seg_Driver_L_Control_PTR)

#if (LED_Driver_1_NUM_SEG > 8u)
    #define LED_Driver_1_SEG_M_CONTROL_PTR  (LED_Driver_1_Seg_Driver_M_Control_PTR)
#endif /* (LED_Driver_1_NUM_SEG > 8u) */
#if (LED_Driver_1_NUM_SEG > 16u)
    #define LED_Driver_1_SEG_H_CONTROL_PTR  (LED_Driver_1_Seg_Driver_H_Control_PTR)
#endif /* (LED_Driver_1_NUM_SEG > 16u) */


/***************************************
*           UDB PWM Registers
***************************************/
/* Control register */
#define LED_Driver_1_CONTROL_REG            (*(reg8 *) LED_Driver_1_bLED_PWM_CtlReg__CONTROL_REG)
#define LED_Driver_1_CONTROL_PTR            ( (reg8 *) LED_Driver_1_bLED_PWM_CtlReg__CONTROL_REG)

/* Counter register */
#define LED_Driver_1_COUNTER_REG            (*(reg8 *) LED_Driver_1_bLED_PWM_PwmDP_u0__A1_REG)
#define LED_Driver_1_COUNTER_PTR            ((reg8 *) LED_Driver_1_bLED_PWM_PwmDP_u0__A1_REG)
/* Compare value buffer */
#define LED_Driver_1_COMPARE_REG            (*(reg8 *) LED_Driver_1_bLED_PWM_PwmDP_u0__D0_REG)
#define LED_Driver_1_COMPARE_PTR            ((reg8 *) LED_Driver_1_bLED_PWM_PwmDP_u0__D0_REG)


/***************************************
*          Register Constants
***************************************/
/* Control Register Enable/Disable. Also use for LED_Driver_1_enableVar */
#define LED_Driver_1_CTRL_ENABLE            (0x01u)
#define LED_Driver_1_CTRL_DISABLE           (0x00u)

#endif /* CY_LED_Driver_LED_Driver_1_H Header File */


/* [] END OF FILE */
