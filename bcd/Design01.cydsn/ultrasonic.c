#include "header.h"
#include <math.h>
#include "stdlib.h"
//#include "header01.h"

float count = 0.0;
float distance;
char distance_str[100];
int obst_detect = 0;
int array;
float distancearray[10];

extern CY_ISR(Timer_1_ISR_Handler){
    //UART_1_PutString("\n ISR \n");
    Timer_1_ReadStatusRegister(); //Clears interrupt and stop interrupts from firing successively
    count = Timer_1_ReadCounter();
    distance = (65535.0 - count)/58.0;
    distancearray[array]=distance;
    sprintf(distance_str,"The distance is %d %.3f centimeters.\n",array,distance);
    
    UART_1_PutString(distance_str);
    distance=0;
//    if(distance[array] < 20){
//        //LED_Write(1);
//        obst_detect = 1;
//    }
//       else{
//        LED_Write(0);
//        obst_detect = 0;
//    }
    
    CyDelay(200);    
    isr_1_ClearPending();
}

float *Sense1()
{
    
    Control_Reg_4_Write(0);
    CyDelay(100);
    array=0;
    UART_1_PutString("Sensing front left\n");
    Trigger_fl_Write(1);
    CyDelayUs(10);
    Trigger_fl_Write(0);
    CyDelay(1000);
    
    
    Control_Reg_4_Write(1);
    CyDelay(100);
    array=1;
    UART_1_PutString("Sensing front right\n");
    Trigger_fr_Write(1);
    CyDelayUs(10);
    Trigger_fr_Write(0);
    CyDelay(1000);
   
    Control_Reg_4_Write(2);
    CyDelay(100);
    array=2;
    UART_1_PutString("Sensing back left\n");
    Trigger_l_Write(1);
    CyDelayUs(10);
    Trigger_l_Write(0);
    CyDelay(1000);
  
    Control_Reg_4_Write(3);
    CyDelay(100);
    array=3;
    UART_1_PutString("Sensing back right\n");
    Trigger_r_Write(1);
    CyDelayUs(10);
    Trigger_r_Write(0);
    CyDelay(1000);
    
    
    return distancearray;      
}