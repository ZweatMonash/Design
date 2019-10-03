#include <stdio.h>
#include "project.h"
#include "string.h"
#include "header01.h"

//#include "movement.c"
CY_ISR(Timer_1_ISR_Handler);
CY_ISR(Key_ISR_Handler);
char UART_str[100];
char a_text[9];
int state = 0;
float distance[10];
//int obst_detect=0;
CY_ISR(Key_ISR_Handler){
    UART_1_PutString("Button press deteced. \n");
    state++;
    
    sprintf(a_text,"%d",state);   
    a_text[4] = '\0';
    UART_1_PutString(a_text);
    return;
}


int main(void)
{
    
    
    CyGlobalIntEnable;
    
    UART_1_Start();
   
    isr_Key_StartEx(Key_ISR_Handler);
    Counter_right_Start();
    Counter_left_Start();
    Counter_lift_Start();
    IDAC8_1_Start();
    VDAC8_1_Start();
    TIA_1_Start();
    ADC_DelSig_1_Start();    
    PWM_lw_Start();
    PWM_rw_Start();
    PWM_lift_Start();
    PWM_1_Start();
    Timer_1_Start();
    Control_Reg_1_Write(1);
    Control_Reg_2_Write(1);
  
    UART_1_PutString("Program started\n");
    Control_Reg_3_Write(1);
   
    while(state <= 2)
    {   
        
        if(state >= 2)
        {
            isr_1_StartEx(Timer_1_ISR_Handler);
            UART_1_PutString("Button press deteced.\n");
            break;
        }
        
    }
    
    float *a =Sense1();
//    for (int i=0;i<10;i++){
//        distance[i]=*(a+i);
//        sprintf(a_text,"%f printhere",distance[i]);
//        UART_1_PutString(a_text);
//    }
//    
}

