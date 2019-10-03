//#define CYDEV_HEAP_SIZE 0x200

#include <stdio.h>
#include "project.h"
#include "string.h"

extern void move_forward();
extern void move_backward();
extern void turn_clock();
extern void turn_anti();
extern void stop();
extern void Sense();

extern CY_ISR(Timer_1_ISR_Handler);
