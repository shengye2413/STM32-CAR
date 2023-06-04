#include<led.h>
void beep_init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
    //GPIO初始化结构体配置
    GPIO_InitTypeDef p;
    p.GPIO_Pin = GPIO_Pin_8;
    //引脚编号8
    p.GPIO_Mode=GPIO_Mode_OUT;
    //输出模式
    p.GPIO_Speed=GPIO_Speed_50MHz;
    p.GPIO_OType=GPIO_OType_PP;
    p.GPIO_PuPd=GPIO_PuPd_NOPULL;
    //不拉
    GPIO_Init(GPIOF,&p);
    //初始化GPIO
    GPIO_ResetBits(GPIOF,GPIO_Pin_8);
    //初始设立为关
}
void beep_on(void)
{
    GPIO_SetBits(GPIOF,GPIO_Pin_8);
}
void beep_off(void)
{
    GPIO_ResetBits(GPIOF,GPIO_Pin_8);
}