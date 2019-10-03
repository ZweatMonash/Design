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
#include "header.h"
#include "math.h"
#include "stdlib.h"
#include "header01.h"

void gripper_open(){
PWM_1_Start();
PWM_1_WriteCompare(22);
CyDelay(1000);
//PWM_1_Sleep();
}

void gripper_close(){
PWM_1_Start();
PWM_1_WriteCompare(25);
CyDelay(1000);
//PWM_1_Sleep();
}
/* [] END OF FILE */
