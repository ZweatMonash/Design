#include "header.h"
#include "math.h"
#include "stdlib.h"
#include "header01.h"

uint16 right_count;
uint16 left_count;
char UART_str[40];
float distance[10];
//47
//char UART_str[100];
char a_text[9];
//extern int obst_detect;
void turn_anti(int degree)
{
    right_count = 0;
   Control_Reg_1_Write(0); 
   dir_rw_Write(0);
   dir_lw_Write(1);
   degree=degree*1385/90;
   while(right_count <= degree){
       right_count = Counter_right_ReadCounter();
       left_count = Counter_left_ReadCounter();
       sprintf(UART_str,"Right Count %d  Left Count %d \n",right_count,left_count);
      // UART_1_PutString(UART_str);
        
        if(right_count >= degree){
            Control_Reg_1_Write(1);
            break;
        }  
    }
}


     

void light(){
LED_Write(1);
CyDelay(1000);
LED_Write(0);
}

void path_plan(){//////////////////////////////////////////////////////////////////////////////////////////////////
   begin:
    //Sense();
    
     if (obst_detect == 1){
        turn_clock();
    }
    else
    {
        move_forward(500);
    }
    //CyDelay(4000);
    goto begin;

}
void turn_clock(int degree)
{
    right_count = 0;
   Control_Reg_1_Write(1);
   Control_Reg_1_Write(0);
   dir_rw_Write(1);
   dir_lw_Write(0);

   right_count = Counter_right_ReadCounter();
   left_count = Counter_left_ReadCounter();
   //sprintf(UART_str,"Right Count %d  Left Count %d \n",right_count,left_count);
   //UART_1_PutString(UART_str);
    degree=degree/90*1325;
     while(right_count< degree)
    {
        right_count = Counter_right_ReadCounter();
        left_count = Counter_left_ReadCounter();
       if (right_count>= degree){
            Control_Reg_1_Write(1);
            break;
        }
     }
     
}


void move_forward(int value)
{
   right_count = 0;
   Control_Reg_1_Write(1);
   Control_Reg_1_Write(0);
   dir_rw_Write(0);
   dir_lw_Write(0);
   
    while(right_count <= value){
       right_count = Counter_right_ReadCounter();
       left_count = Counter_left_ReadCounter();
       sprintf(UART_str,"Right Count %d  Left Count %d \n",right_count,left_count);
      // UART_1_PutString(UART_str);
        
        if(right_count >= value){
            Control_Reg_1_Write(1);
            break;
        }
    } 

    
}
   


void stop()
{
   Control_Reg_1_Write(1);
}

void move_backward(int value)
{
   right_count = 0;
   Control_Reg_1_Write(1);
   Control_Reg_1_Write(0);
   dir_rw_Write(1);
   dir_lw_Write(1);
   
    while(right_count <= value){
       right_count = Counter_right_ReadCounter();
       left_count = Counter_left_ReadCounter();
       sprintf(UART_str,"Right Count %d  Left Count %d \n",right_count,left_count);
      // UART_1_PutString(UART_str);
        
        if(right_count >= value){
            Control_Reg_1_Write(1);
            break;
        }
    } 
}

void correct_direction(){
float *a=Sense1();
    for (int i=0;i<10;i++){
        distance[i]=*(a+i);
        sprintf(a_text,"%f printhere",distance[i]);
        UART_1_PutString(a_text);
    }
while (distance[1]-distance[0]>0.3|distance[1]-distance[0]<-0.3){
if (distance[1]>distance[0])
{
    turn_clock(5);
}
else if (distance[1]>distance[0]){
    turn_anti(5);
}
else break;}
}