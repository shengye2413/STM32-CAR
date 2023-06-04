#include "usart_PC.h"
#include "stm32f4xx.h"
/*void usart1_init(void)
{
	//1.GPIO初始化
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能
	GPIO_InitTypeDef p;
	p.GPIO_Mode = GPIO_Mode_AF;
	p.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	p.GPIO_Speed = GPIO_Speed_50MHz;
	p.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &p);
	//指定GPIO口具体的复用功能
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9,GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10,GPIO_AF_USART1);
	
	//2.usart配置
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);//使能
	USART_InitTypeDef u;
	u.USART_BaudRate = 9600;//波特率
	u.USART_Mode = USART_Mode_Rx | USART_Mode_Tx ;//全双工
	u.USART_Parity = USART_Parity_No ;//无校验位
	u.USART_HardwareFlowControl = USART_HardwareFlowControl_None ;//无硬件流控
	u.USART_WordLength = USART_WordLength_8b ;//数据位长度8
	u.USART_StopBits = USART_StopBits_1;//1bit停止位
	USART_Init(USART1, &u);

	//3.串口cmd
	USART_Cmd(USART1, ENABLE);
	
}



uint8_t ReceiveDataByte(USART_TypeDef* USARTx)
{
	while(USART_GetFlagStatus(USARTx, USART_FLAG_RXNE) == RESET);
	return USART_ReceiveData(USARTx);
}



void SendDataByte(USART_TypeDef* USARTx,char ch)
{
	USART_SendData(USARTx, ch);
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET); //死等，等它发送数据完成
}
*/

void usart1_init(void)
{
	//1.GPIO初始化
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能
	GPIO_InitTypeDef p;
	p.GPIO_Mode = GPIO_Mode_AF;
	p.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	p.GPIO_Speed = GPIO_Speed_50MHz;
	p.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &p);
	//指定GPIO口具体的复用功能
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9,GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10,GPIO_AF_USART1);
	
	//2.usart配置
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);//使能
	USART_InitTypeDef u;
	u.USART_BaudRate = 9600;//波特率
	u.USART_Mode = USART_Mode_Rx | USART_Mode_Tx ;//全双工
	u.USART_Parity = USART_Parity_No ;//无校验位
	u.USART_HardwareFlowControl = USART_HardwareFlowControl_None ;//无硬件流控
	u.USART_WordLength = USART_WordLength_8b ;//数据位长度8
	u.USART_StopBits = USART_StopBits_1;//1bit停止位
	USART_Init(USART1, &u);

	//3.串口cmd
	USART_Cmd(USART1, ENABLE);
	
}



uint8_t ReceiveDataByte(USART_TypeDef* USARTx)
{
	while(USART_GetFlagStatus(USARTx, USART_FLAG_RXNE) == RESET);
	return USART_ReceiveData(USARTx);
}



void SendDataByte(USART_TypeDef* USARTx,char ch)
{
	USART_SendData(USARTx, ch);
	//while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET); //死等，等它发送数据完成
}