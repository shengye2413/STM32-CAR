#include<key.h>
#include<led.h>

void key_init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOE,ENABLE);
    //GPIO初始化结构体配置
    GPIO_InitTypeDef p;
    p.GPIO_Pin=GPIO_Pin_0;
    p.GPIO_Mode=GPIO_Mode_IN;
    //输入模式
    p.GPIO_Speed=GPIO_Speed_50MHz;
    p.GPIO_OType=GPIO_OType_PP;
    p.GPIO_PuPd=GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA,&p);
    //不拉
    p.GPIO_Pin=GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
    GPIO_Init(GPIOE,&p);
}
void key_check(void)
{
    uint8_t key0,key1,key2,key3;
    key0=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
    key1=GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2);
    key2=GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3);
    key3=GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4);
    if(key0==0)
    {
        led_on();
    }
    else if(key1==0)
    {
        led_off();
    }
    else if(key2==0)
    {
        beep_on(); 
    }
    else if(key3==0)
    {
        beep_off();
    }
    
}