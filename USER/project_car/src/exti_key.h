#ifndef _EXTI_KEY_H_
#define _EXTI_KEY_H_
#include "stm32f4xx.h"
void exti_key_init(void);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
#endif
