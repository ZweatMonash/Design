/*******************************************************************************
* File Name: BCD.h
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

#if !defined(CY_LED_Driver_BCD_H)
#define CY_LED_Driver_BCD_H


/***************************************
*   Conditional Compilation Parameters
***************************************/
#define BCD_BRIGHTNESS_EN                (0u)
#define BCD_COM_DRIVE                    (0u)
#define BCD_SEG_DRIVE                    (0u)
#define BCD_NUM_COM                      (4u)
#define BCD_NUM_SEG                      (7u)
#define BCD_TWO_NUM_COM                  ((uint8)((uint8)BCD_NUM_COM << 1u))

/* Error message for removed commons control register through optimization */
#ifdef BCD_Com_Driver_Sync_ctrl_reg__REMOVED
    #error LED_Driver_v1_10 requires all the signals from the commons terminal to be connected to pins.
#endif /* BCD_Com_Driver_Sync_ctrl_reg__REMOVED */

/* Error message for removed segments control registers through optimization */
#if defined BCD_Seg_Driver_L_Sync_ctrl_reg__REMOVED || \
defined BCD_Seg_Driver_M_Sync_ctrl_reg__REMOVED || \
defined BCD_Seg_Driver_H_Sync_ctrl_reg__REMOVED
    #error LED_Driver_v1_10 requires all the signals from the segments terminal to be connected to pins.
#endif /* BCD_Seg_Driver_L_Sync_ctrl_reg__REMOVED */


/***************************************
*   Header files
***************************************/
#include <BCD_Com_Driver.h>
#include <BCD_Seg_Driver_L.h>
#if (BCD_NUM_SEG > 8u)
    #include <BCD_Seg_Driver_M.h>
#endif /* Segment_M control register */
#if (BCD_NUM_SEG > 16u)
    #include <BCD_Seg_Driver_H.h>
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
    uint8 segLBackup[BCD_NUM_COM];
    #if (BCD_NUM_SEG > 8u) 
        uint8 segMBackup[BCD_NUM_COM];
    #endif /* (BCD_NUM_SEG > 8u) */
    #if (BCD_NUM_SEG > 16u) 
        uint8 segHBackup[BCD_NUM_COM];
    #endif /* (BCD_NUM_SEG > 16u) */
}BCD_backupStruct;


/***************************************
*        Function Prototypes
***************************************/
void BCD_Init(void)                       ;
void BCD_Enable(void)                     ;
void BCD_Start(void)                      ;
void BCD_Stop(void)                       ;
void BCD_SetDisplayRAM(uint8 value, uint8 position) 
                                                        ;
void BCD_SetRC(uint8 row, uint8 column)    ;
void BCD_ClearRC(uint8 row, uint8 column)  ;
void BCD_ToggleRC(uint8 row, uint8 column) ;
uint8 BCD_GetRC(uint8 row, uint8 column)   ;
void BCD_ClearDisplay(uint8 position)      ;
void BCD_ClearDisplayAll(void)             ;
void BCD_Write7SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void BCD_Write7SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void BCD_WriteString7Seg(char8 const character[], uint8 position)
                                                        ;
void BCD_PutChar7Seg(char8 character , uint8 position)
                                                        ;
void BCD_Write7SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void BCD_Write7SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void BCD_Write14SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void BCD_Write14SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void BCD_WriteString14Seg(char8 const character[], uint8 position)
                                                        ;
void BCD_PutChar14Seg(char8 character , uint8 position)
                                                        ;
void BCD_Write14SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void BCD_Write14SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void BCD_Write16SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void BCD_Write16SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void BCD_WriteString16Seg(char8 const character[], uint8 position)
                                                        ;
void BCD_PutChar16Seg(char8 character , uint8 position)
                                                        ;
void BCD_Write16SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void BCD_Write16SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void BCD_PutDecimalPoint(uint8 dp, uint8 position)
                                                        ;
uint8 BCD_GetDecimalPoint(uint8 position)  ;
uint8 BCD_EncodeNumber7Seg(uint8 number)   ;
uint8 BCD_EncodeChar7Seg(char8 input)      ;
uint16 BCD_EncodeNumber14Seg(uint8 number) ;
uint16 BCD_EncodeChar14Seg(char8 input)    ;
uint16 BCD_EncodeNumber16Seg(uint8 number) ;
uint16 BCD_EncodeChar16Seg(char8 input)    ;
void BCD_SetBrightness(uint8 bright, uint8 position)
                                                        ;
uint8 BCD_GetBrightness(uint8 position)    ;
void BCD_Sleep(void)                       ;
void BCD_Wakeup(void)                      ;


/***************************************
*           Global Variables
***************************************/
extern uint8 BCD_initVar;
extern uint8 BCD_enableVar;

/* Buffers used to hold the display(segment) values to be transferred to the control registers */
extern uint8 BCD_segLBuffer[BCD_NUM_COM];
#if (BCD_NUM_SEG > 8u) 
    extern uint8 BCD_segMBuffer[BCD_NUM_COM];
#endif /* (BCD_NUM_SEG > 8u) */
#if (BCD_NUM_SEG > 16u) 
    extern uint8 BCD_segHBuffer[BCD_NUM_COM];
#endif /* (BCD_NUM_SEG > 16u) */


/***************************************
*           API Constants
***************************************/

/* Related to conditional compilation */
#define BCD_HIGH                   (0x01u)
#define BCD_ENABLED                (0x01u)

/* Number of DMA channels */
#if (BCD_BRIGHTNESS_EN == BCD_ENABLED)
    #define BCD_CHANNEL_LIMIT      (0x03u)
#else
    #define BCD_CHANNEL_LIMIT      (0x02u)
#endif /* (BCD_BRIGHTNESS_EN == BCD_ENABLED) */

/* Defines related to sign extraction for number displays */
#define BCD_SIGNED                 (0x01u)
#define BCD_UNSIGNED               (0x00u)
#define BCD_ZERO_NEG               ((int32)0x00000000)

/* Brightness control defines */
#define BCD_INIT_BRIGHT            (0xFFu)

/* Segment display defines */
#if(BCD_SEG_DRIVE == BCD_HIGH)
    #define BCD_CLEAR              (0x00u)
    #define BCD_CLEAR_16           ((uint16)0x0000u)
    #define BCD_ZERO_7CHAR         (0x3Fu)
    #define BCD_ZERO_14CHAR        ((uint16)0x243Fu)
    #define BCD_ZERO_16CHAR        ((uint16)0x90FFu)
#else
    #define BCD_CLEAR              (0xFFu)
    #define BCD_CLEAR_16           ((uint16)0xFFFFu)
    #define BCD_ZERO_7CHAR         (0xC0u)
    #define BCD_ZERO_14CHAR        ((uint16)0xDBC0u)
    #define BCD_ZERO_16CHAR        ((uint16)0x6F00u)
#endif /* (BCD_SEG_DRIVE == BCD_HIGH) */

/* Shifts and 4-bit operation mask */
#define BCD_SHIFT_NIBBLE           (0x04u)
#define BCD_NIBBLE_MASK            (0x0Fu)
#define BCD_SHIFT_BYTE             (0x08u)

/* ASCII table access defines */
#define BCD_SEG_ASCII_OFFSET       (0x02u)
#define BCD_SEG_ASCII_LIM_HI       (0x08u)
#define BCD_SEG_ASCII_LIM_LO       (0x01u)

/* Decimal point defines */
#define BCD_DEC_POINT              (0x07u)
#define BCD_DEC_POINT_MASK         (0x01u)
#if(BCD_SEG_DRIVE == BCD_HIGH)
    #define BCD_DEC_POINT_VALUE    (0x80u)
#else
    #define BCD_DEC_POINT_VALUE    (0x7Fu)
#endif /* (BCD_SEG_DRIVE == BCD_HIGH) */

/* 7-seg position to register mapping defines */
#define BCD_SEG_REG_LOW            (0x00u)
#define BCD_SEG_REG_MID            (0x01u)
#define BCD_SEG_REG_HIGH           (0x02u)

/* Segment display alignment defines */
#define BCD_RIGHT_ALIGN            (0x00u)
#define BCD_LEFT_ALIGN             (0x01u)
#define BCD_ZERO_PAD               (0x02u)


/***************************************
*           Registers
***************************************/
#define BCD_CONTROL_REG_BASE       (CYDEV_PERIPH_BASE)
#define BCD_SRAM_BASE              (CYDEV_SRAM_BASE)

#define BCD_COM_CONTROL_PTR        (BCD_Com_Driver_Control_PTR)
#define BCD_SEG_L_CONTROL_PTR      (BCD_Seg_Driver_L_Control_PTR)

#if (BCD_NUM_SEG > 8u)
    #define BCD_SEG_M_CONTROL_PTR  (BCD_Seg_Driver_M_Control_PTR)
#endif /* (BCD_NUM_SEG > 8u) */
#if (BCD_NUM_SEG > 16u)
    #define BCD_SEG_H_CONTROL_PTR  (BCD_Seg_Driver_H_Control_PTR)
#endif /* (BCD_NUM_SEG > 16u) */


/***************************************
*           UDB PWM Registers
***************************************/
/* Control register */
#define BCD_CONTROL_REG            (*(reg8 *) BCD_bLED_PWM_CtlReg__CONTROL_REG)
#define BCD_CONTROL_PTR            ( (reg8 *) BCD_bLED_PWM_CtlReg__CONTROL_REG)

/* Counter register */
#define BCD_COUNTER_REG            (*(reg8 *) BCD_bLED_PWM_PwmDP_u0__A1_REG)
#define BCD_COUNTER_PTR            ((reg8 *) BCD_bLED_PWM_PwmDP_u0__A1_REG)
/* Compare value buffer */
#define BCD_COMPARE_REG            (*(reg8 *) BCD_bLED_PWM_PwmDP_u0__D0_REG)
#define BCD_COMPARE_PTR            ((reg8 *) BCD_bLED_PWM_PwmDP_u0__D0_REG)


/***************************************
*          Register Constants
***************************************/
/* Control Register Enable/Disable. Also use for BCD_enableVar */
#define BCD_CTRL_ENABLE            (0x01u)
#define BCD_CTRL_DISABLE           (0x00u)

#endif /* CY_LED_Driver_BCD_H Header File */


/* [] END OF FILE */
