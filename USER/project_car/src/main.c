#include "main.h"
#include "led.h"
#include "motor.h"
#include "exti_key.h"
#include "car.h"
#include "stdio.h"
#include "usart_PC.h"
#include "bluetooth.h"
#include "infrared.h"
/*int main(void)
{
	led_init();
	beep_init();
	car_init();
	motor_init();
	//TIM3_Init();
	//exti_key_init();
	while(1)
	{
		infrared_init();
		car_infrared();
	}
	return 0;

}

//

int fputc(int c,FILE * stream)
{
	SendDataByte(USART1,c&0xff);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	return c;
}

int main(void)
{
	led_init();
	beep_init();
	usart1_init();	
	uint8_t res;
	printf("%s\n","hello");
	while(1)
	{
		//
		//delay(0x999999);
		res = ReceiveDataByte(USART1);
		if(res == '1')  led_on();
		else if(res == '2') beep_on();
	}
	return 0;
}

*/

//重定义fputc，以便能使用printf函数
int fputc(int c,FILE * stream)
{
	SendDataByte(USART1,c&0xff);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	return c;
}

int main(void)
{
	led_init();
	beep_init();
	motor_init();
	infrared_init();
	//car_init();
	usart1_init();	
	bluetooth_init();
	uint8_t res,ch;
	while(1)
	{
		//delay(0x999999);
		printf("%s\n","hello");
		res = ReceiveDataByte(USART1);
		if(res == '1')  led_on();
		else if(res == '2') led_off();
		else if(res == '3') beep_on();
		else if(res == '4') beep_off();
	
	}
	return 0;
}