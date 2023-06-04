#include "bluetooth.h"
#include "motor.h"
#include "usart_PC.h"
#include "car.h"
#include "infrared.h"
// Rx2  --- PA3
// Tx2  --- PA2
void bluetooth_init(void)
{
	USART_InitTypeDef u;
	NVIC_InitTypeDef ic;
	//1.GPIO初始化
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能
	GPIO_InitTypeDef p;
	p.GPIO_Mode = GPIO_Mode_AF;
	p.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	p.GPIO_Speed = GPIO_Speed_50MHz;
	p.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &p);
	//指定GPIO口具体的复用功能
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2,GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3,GPIO_AF_USART2);
	
	//2.usart配置
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);//使能
	
	u.USART_BaudRate = 9600;//波特率
	u.USART_Mode = USART_Mode_Rx | USART_Mode_Tx ;//全双工
	u.USART_Parity = USART_Parity_No ;//无校验位
	u.USART_HardwareFlowControl = USART_HardwareFlowControl_None ;//无硬件流控
	u.USART_WordLength = USART_WordLength_8b ;//数据位长度8
	u.USART_StopBits = USART_StopBits_1;//1bit停止位
	USART_Init(USART2, &u);

	//有很多种产生中断的方式（），但是你的中断函数只有一个
	USART_ITConfig(USART2,USART_IT_RXNE, ENABLE); //指定中断事件：USART_IT_RXNE：接收数据寄存器不为空，即有数据来产生中断
	//2.NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//确定抢占优先级占2bit
	
	ic.NVIC_IRQChannel = USART2_IRQn ;//中断请求通道
	ic.NVIC_IRQChannelPreemptionPriority = 2;//抢占优先级
	ic.NVIC_IRQChannelSubPriority = 2;//子优先级（响应优先级）
	ic.NVIC_IRQChannelCmd = ENABLE; //cmd
	NVIC_Init(&ic);

	//3.串口cmd
	USART_Cmd(USART2, ENABLE);
}


//中断实现 
//串口2连接蓝牙，
void USART2_IRQHandler(void)
{
	char ch;
	if(USART_GetITStatus(USART2, USART_IT_RXNE) == SET)
	{
		//中断逻辑
		ch = ReceiveDataByte(USART2);//获取蓝牙模块发来的数据
		printf("%c\n",ch);//将串口2收到的数据打印到串口1上
		if(ch == '1') motor_on();
		if(ch == '2') motor_stop();
		if(ch == '3') motor_back();
		if(ch == '4') motor_left();
		if(ch == '5') motor_right();
		if(ch == '6') 
		{
			while (1)
			{
				car_infrared();
				//无法退出循环（待解决）
			}
		}
		if(ch == '7') beep_on();
		if(ch == '8') beep_off();
		if(ch == '9') led_on();
		if(ch == '0') led_off();
		
	}
	USART_ClearITPendingBit(USART2, USART_IT_RXNE);
}

void SendData(USART_TypeDef* USARTx,unsigned char buf[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		USART_SendData(USARTx, buf[i]);
	}
	//while(USART_GetFlagStatus(USARTx, USART_FLAG_RXNE) == RESET);//死等，等它发送数据完成
}