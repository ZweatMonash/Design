//
//#define CYDEV_HEAP_SIZE 0x200
//
//#include <project.h>
//#include "math.h"
//#include "stdlib.h"
//#include "stdio.h"
//#include "string.h"
//
//uint16 count = 0;
//float distance = 0;
//char distance_str[100];
//float jaja = 23.0;
//
//CY_ISR(Timer_1_ISR_Handler){
//    Timer_1_ReadStatusRegister(); //Clears interrupt and stop interrupts from firing successively
//    count = Timer_1_ReadCounter();//    distance = (65535 - count)/58;
//    
//    sprintf(distance_str,"The distance is %.3f centimeters.",distance);
//    
//    UART_1_PutString(distance_str);
//    UART_1_PutString("\n");
//    if(distance < 5.0)
//        LED_Write(1);
//       else
//        LED_Write(0);
//        
//    
//}
//
//int main()
//{
//    /* Prepare components */
//    CyGlobalIntEnable;
//    Timer_1_Start();
//    UART_1_Start();
//    isr_1_StartEx(Timer_1_ISR_Handler);
//    for (;;)
//    {  
//       while(Echo_Pin_Read() == 0){
//           Trigger_Write(1);
//           CyDelayUs(10);
//           Trigger_Write(0);
//           
//        }
//       
//        CyDelay(100);
//    }
//}
//
///* [] END OF FILE */
//