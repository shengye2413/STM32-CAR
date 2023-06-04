#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__
#include "stm32f4xx.h"

void bluetooth_init(void);
void SendData(USART_TypeDef* USARTx,unsigned char sbuf[],int len);
#endif

