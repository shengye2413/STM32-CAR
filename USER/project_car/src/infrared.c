#include "infrared.h"
#include "bluetooth.h"
#include "motor.h"
#include "usart_PC.h"
#include "car.h"
// CAMERE 7  --->PG15
// CAMERE 8  --->PC6
void infrared_init(void)
{
	//1.打开对应GPIO口线的分组时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG | RCC_AHB1Periph_GPIOC, ENABLE);
	//2.对应GPIO口的配置
    GPIO_InitTypeDef p;
    p.GPIO_Pin = GPIO_Pin_15; 
    p.GPIO_Mode = GPIO_Mode_IN;//输入模式
    p.GPIO_Speed = GPIO_Speed_50MHz;
    p.GPIO_OType = GPIO_OType_PP;//推挽输出
    p.GPIO_PuPd =  GPIO_PuPd_NOPULL;//不拉
    GPIO_Init(GPIOG, &p);

    p.GPIO_Pin = GPIO_Pin_6; 
    GPIO_Init(GPIOC, &p);
}
void car_infrared(void)
{
	uint8_t left,right;
	//while(1)
	//{
        left  = GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15);
	    right = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
		if(left == 1 && right == 1) motor_stop();
		else if(left == 1 && right == 0) motor_right();
        else if (left == 0 && right == 1) motor_left();
        else if (left ==0 && right ==0) motor_on();
	//} 
}