#ifndef __MOTOR_H__
#define __MOTOR_H__
#include "stm32f4xx.h"
void motor_right(void);
void motor_left(void);
void motor_back(void);
void motor_stop(void);
void motor_on(void);
void delay(unsigned int time);
#endif