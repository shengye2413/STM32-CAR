#ifndef __USART_PC__
#define __USART_PC__
#include "stm32f4xx.h"

void usart1_init(void);
uint8_t ReceiveDataByte(USART_TypeDef* USARTx);
void SendDataByte(USART_TypeDef* USARTx,char ch);
#endif