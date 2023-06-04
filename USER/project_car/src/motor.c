#include "motor.h"
#include "stm32f4xx.h"
void motor_init()
{
	//camera3 -->PB7
	//camera4 -->PD6
	//camera5 -->PA4
	//camera6 -->PD7
	//1.打开对应GPIO口线的分组时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOD  , ENABLE);
	//2.对应GPIO口的配置
    GPIO_InitTypeDef p;
    p.GPIO_Pin = GPIO_Pin_7; 
    p.GPIO_Mode = GPIO_Mode_OUT;//输出模式
    p.GPIO_Speed = GPIO_Speed_50MHz;
    p.GPIO_OType = GPIO_OType_PP;//推挽输出
    p.GPIO_PuPd =  GPIO_PuPd_NOPULL;//不拉
    GPIO_Init(GPIOB, &p);

    p.GPIO_Pin = GPIO_Pin_6; 
    GPIO_Init(GPIOD, &p);

    p.GPIO_Pin = GPIO_Pin_4; 
    GPIO_Init(GPIOA, &p);

    p.GPIO_Pin = GPIO_Pin_7; 
    GPIO_Init(GPIOD, &p);
    
    //电机的初始状态
    GPIO_ResetBits(GPIOB,GPIO_Pin_7); //置0 
    GPIO_ResetBits(GPIOD,GPIO_Pin_6); //置0 右轮
    
    GPIO_ResetBits(GPIOA,GPIO_Pin_4); //置0 
    GPIO_ResetBits(GPIOD,GPIO_Pin_7); //置0 左轮
	
}

void delay(unsigned int time)
{
	for(;time>0;time--)
	{

	}
}
void motor_on(void)
{
	//左边动
	GPIO_ResetBits(GPIOB,GPIO_Pin_7); //置0 
	GPIO_SetBits(GPIOD,GPIO_Pin_6); //置1 
	//右边动
	GPIO_SetBits(GPIOA,GPIO_Pin_4); //置1
	GPIO_ResetBits(GPIOD,GPIO_Pin_7); //置0
	//delay(10000);
	//motor_stop();
	//delay(20000);


}//向前走

void motor_stop(void)
{
	//电机的初始状态
	GPIO_ResetBits(GPIOB,GPIO_Pin_7); //置0 
	GPIO_ResetBits(GPIOD,GPIO_Pin_6); //置0 

	GPIO_ResetBits(GPIOA,GPIO_Pin_4); //置0 
	GPIO_ResetBits(GPIOD,GPIO_Pin_7); //置0 

}//停止

void motor_back(void)
{
	
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
	GPIO_ResetBits(GPIOD,GPIO_Pin_6);
	//左边动
	GPIO_ResetBits(GPIOA,GPIO_Pin_4); 
	GPIO_SetBits(GPIOD,GPIO_Pin_7); 
	//右边动
}//向后退

void motor_right(void)
{
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_4); //置0 
	GPIO_SetBits(GPIOD,GPIO_Pin_7); //置1
	//右边轮子不动
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_7); //置0 
	GPIO_SetBits(GPIOD,GPIO_Pin_6); //置1 
	//左边轮子向前
	//delay(10000);
	//motor_stop();
	//delay(20000);
}//向右

void motor_left(void)
{
	
	GPIO_SetBits(GPIOB,GPIO_Pin_7); //置1
	GPIO_ResetBits(GPIOD,GPIO_Pin_6); //置0 
	//左边轮子不动
	
	GPIO_SetBits(GPIOA,GPIO_Pin_4); //置1
	GPIO_ResetBits(GPIOD,GPIO_Pin_7); //置0
	//右边轮子向前1
	//delay(10000);
	//motor_stop();
	//delay(20000);
}//向左
