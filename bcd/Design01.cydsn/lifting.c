#include "header.h"
#include "math.h"
#include "stdlib.h"
#include "header01.h"
#include "string.h"
#include "project.h"
/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/* [] END OF FILE */
char UART_str[40];
void lift_up()
{
   int lift_count=0;
   Control_Reg_2_Write(1);
   Control_Reg_2_Write(0);
   
   dir_lift_Write(0);
test1:
   lift_count = Counter_lift_ReadCounter();
   sprintf(UART_str,"lift Count %d\n",lift_count);
   UART_1_PutString(UART_str);
    
     if(lift_count >= 10000)
    {
        Control_Reg_2_Write(1);
    }
    else goto test1;
     
}

void lift_down()
{
   int lift_count=0;
   Control_Reg_2_Write(1);
   Control_Reg_2_Write(0);
   
   dir_lift_Write(1);
test1:
   lift_count = Counter_lift_ReadCounter();
   sprintf(UART_str,"lift Count %d\n",lift_count);
   UART_1_PutString(UART_str);
    
     if(lift_count >= 10000)
    {
        Control_Reg_2_Write(1);
    }
    else goto test1;
     
}