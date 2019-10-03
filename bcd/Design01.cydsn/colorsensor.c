#include "project.h"
#include "string.h"
#include "math.h"

#define CYDEV_HEAP_SIZE 0x200
#define REPETITION 200


void colorloop();
void calibration();

//Main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void colorloop(){
    R_Write(0);
    G_Write(0);
    B_Write(0);
    
    int ADCResult[3];
    int max_intensity = 0;
    int max_index = 0;
    char UARTstr[128];
    calibration();
    for(int count = 0; count < 3; count++)
    {   
        switch(count){
            case(0)://R
                Pin_1_Write(1);/////////////////
                CyDelay(500);
                ADCResult[count] = abs(ADC_DelSig_1_CountsTo_mVolts(ADC_DelSig_1_Read32()));
                Pin_1_Write(0);
                break;
            
            case(1)://G
                Pin_2_Write(1);
                CyDelay(500);
                ADCResult[count] = abs(ADC_DelSig_1_CountsTo_mVolts(ADC_DelSig_1_Read32()));
                Pin_2_Write(0);
                break;
            
            case(2)://B
                Pin_3_Write(1);
                CyDelay(500);
                ADCResult[count] = abs(ADC_DelSig_1_CountsTo_mVolts(ADC_DelSig_1_Read32())) + 5;
                Pin_3_Write(0);
                break;            
       
        }
    }
   
    
    for(int i = 0;i < 3; i++)
    {
        if(ADCResult[i] > max_intensity)
        {
            max_index = i;
            max_intensity = ADCResult[i];
        }
    }
    
    sprintf(UARTstr,"0: Red %d\n1: Green %d\n2: Blue %d\n The color index is %d and the intensity is %d\n",ADCResult[0],ADCResult[1],ADCResult[2],max_index,max_intensity);
    
    switch(max_index){
        case(0):
            R_Write(1);
            break;
            case(1):
            G_Write(1);
            break;
            case(2):
            B_Write(1);
            break;
            default:
             R_Write(0);
             G_Write(0);
             B_Write(0);
            break;
       }
    
    
    
    UART_1_PutString(UARTstr);
    
}

void calibration(){

    int current_val = 10000;
    int absResult[255];
    int calibrated;
    int index;
    char UARTstr[128];
    
    int32 ADCResult;
    
    
    for(int i = 0; i < 255; i++)
    {
        IDAC8_1_SetValue(i);
        ADCResult = ADC_DelSig_1_CountsTo_mVolts(ADC_DelSig_1_Read32());
        absResult[i] = abs(ADCResult);
        
        if(absResult[i] < current_val)
        {
            current_val = absResult[i];
        }
        else if(absResult[i] > current_val)
        {
            index = i-1;
            calibrated = current_val;
            break;
        }
       sprintf(UARTstr,"current = %d uA\n",i*8);
       UART_1_PutString(UARTstr);
    }
    
    sprintf(UARTstr,"index = %d, lowest result = %d mV\n",index,calibrated);
    UART_1_PutString(UARTstr);
    IDAC8_1_SetValue(current_val);
    UART_1_PutString("Calibration is DONE. \n\n");
    CyDelay(1000);
    return;
}