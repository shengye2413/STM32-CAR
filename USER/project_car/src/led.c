#include "led.h"
#include "time.h"
void led_init(void)
{
	 //1.打开对应GPIO口线的分组时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF | RCC_AHB1Periph_GPIOE, ENABLE);
    //2.对应GPIO口的配置
    GPIO_InitTypeDef p;
    p.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; //PF9,10
    p.GPIO_Mode = GPIO_Mode_OUT;//输出模式
    p.GPIO_Speed = GPIO_Speed_50MHz;
    p.GPIO_OType = GPIO_OType_PP;//推挽输出
    p.GPIO_PuPd =  GPIO_PuPd_NOPULL;//不拉
    GPIO_Init(GPIOF, &p);
    GPIO_SetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10); //置1 灯灭
    p.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14; //PF9
    GPIO_Init(GPIOE, &p);
    GPIO_SetBits(GPIOE,GPIO_Pin_13 | GPIO_Pin_14); //置1 灯灭

}

/*void led_on(void)
{
	GPIO_ResetBits(GPIOF,GPIO_Pin_9); //置0，灯亮
    GPIO_ResetBits(GPIOF,GPIO_Pin_10);//置0，灯亮
    GPIO_ResetBits(GPIOE,GPIO_Pin_13); //置0，灯亮
    GPIO_ResetBits(GPIOE,GPIO_Pin_14);//置0，灯亮
}*/
//void delay(uint32_t delay_time)
//{
   // while (delay_time--);
//}
//void led_on(void)
//{    
//    GPIO_ResetBits(GPIOF,GPIO_Pin_9);
//    delay(800);
//    GPIO_SetBits(GPIOF,GPIO_Pin_9); 
//    GPIO_ResetBits(GPIOF,GPIO_Pin_10);
//    delay(800);
//    GPIO_SetBits(GPIOF,GPIO_Pin_10);
//    GPIO_ResetBits(GPIOE,GPIO_Pin_13); 
//    delay(800);
//    GPIO_SetBits(GPIOE,GPIO_Pin_13); 
//    GPIO_ResetBits(GPIOE,GPIO_Pin_14);
//    delay(800);
//    GPIO_SetBits(GPIOE,GPIO_Pin_14); 
//}
void led_pao(void)
{
    while (1)
    {
        GPIO_ResetBits(GPIOF,GPIO_Pin_9);
	    delay(0x666666);
	    GPIO_SetBits(GPIOF,GPIO_Pin_9);
    
	    GPIO_ResetBits(GPIOF,GPIO_Pin_10);
	    delay(0x666666);
	    GPIO_SetBits(GPIOF,GPIO_Pin_10);
    
	    GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	    delay(0x666666);
	    GPIO_SetBits(GPIOE,GPIO_Pin_13);
    
	    GPIO_ResetBits(GPIOE,GPIO_Pin_14);
	    delay(0x666666);
	    GPIO_SetBits(GPIOE,GPIO_Pin_14);
    }
}
void led_off(void)
{
    GPIO_SetBits(GPIOF,GPIO_Pin_9); 
    GPIO_SetBits(GPIOF,GPIO_Pin_10);
    GPIO_SetBits(GPIOE,GPIO_Pin_13);
    GPIO_SetBits(GPIOE,GPIO_Pin_14);
}
void led_on(void)
{
    GPIO_ResetBits(GPIOF,GPIO_Pin_9); 
    GPIO_ResetBits(GPIOF,GPIO_Pin_10);
    GPIO_ResetBits(GPIOE,GPIO_Pin_13);
    GPIO_ResetBits(GPIOE,GPIO_Pin_14);
}