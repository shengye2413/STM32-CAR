#include<motor.h>
#include<car.h>
void car_init()
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOE,ENABLE);
	//GPIO初始化结构体配置
	GPIO_InitTypeDef p;
	p.GPIO_Pin = GPIO_Pin_0;//引脚编号0
	p.GPIO_Mode = GPIO_Mode_IN;//输入模式
	p.GPIO_Speed = GPIO_Speed_50MHz;
	p.GPIO_OType = GPIO_OType_PP;
	p.GPIO_PuPd = GPIO_PuPd_NOPULL; //不拉
    p.GPIO_Pin=GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_Init(GPIOA, &p);
    GPIO_Init(GPIOE, &p); //初始化GPIO

	//1.2 SYSCFG配置 --》设置GPIO口线与中断线的映射关系
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_SYSCFG, ENABLE);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);//选择PA0作为外部中断的输入引脚
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource2);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);
	//1.3 中断初始化
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_EXTIT, ENABLE);//中断使能
	EXTI_InitTypeDef exti;
	exti.EXTI_Line = EXTI_Line0;
    //外部中断线
	exti.EXTI_Mode = EXTI_Mode_Interrupt; //中断模式
	exti.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿触发
	exti.EXTI_LineCmd = ENABLE; //cmd
	EXTI_Init(&exti);
    exti.EXTI_Line = EXTI_Line2;
	EXTI_Init(&exti);
    exti.EXTI_Line = EXTI_Line3;
	EXTI_Init(&exti);
    exti.EXTI_Line = EXTI_Line4; 
	EXTI_Init(&exti);

	//2.NVIC的配置
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//确定抢占优先级占2bit
	NVIC_InitTypeDef ic;
	ic.NVIC_IRQChannel = EXTI0_IRQn;//中断请求通道
	ic.NVIC_IRQChannelPreemptionPriority = 2;//抢占优先级
	ic.NVIC_IRQChannelSubPriority = 2;//子优先级（响应优先级）
	ic.NVIC_IRQChannelCmd = ENABLE; //cmd
	
	NVIC_Init(&ic);
    ic.NVIC_IRQChannel = EXTI2_IRQn;
    NVIC_Init(&ic);
    ic.NVIC_IRQChannel = EXTI3_IRQn;
    NVIC_Init(&ic);
    ic.NVIC_IRQChannel = EXTI4_IRQn;
    NVIC_Init(&ic);

}
//中断处理函数   ---》中断向量表
void EXTI0_IRQHandler(void)
{
	if(EXTI_GetFlagStatus(EXTI_Line0) == SET) //中断标志位 
	{
	//中断处理逻辑..
		motor_on();
	}
	EXTI_ClearFlag(EXTI_Line0); //清除中断标志位
} 
void EXTI2_IRQHandler(void)
{
	if(EXTI_GetFlagStatus(EXTI_Line2) == SET) //中断标志位 
	{
	//中断处理逻辑..
		motor_stop();
	}
	EXTI_ClearFlag(EXTI_Line2); //清除中断标志位
} 
void EXTI3_IRQHandler(void)
{
	if(EXTI_GetFlagStatus(EXTI_Line3) == SET) //中断标志位 
	{
	//中断处理逻辑..
		motor_right();
	}
	EXTI_ClearFlag(EXTI_Line3); //清除中断标志位
} 
void EXTI4_IRQHandler(void)
{
	if(EXTI_GetFlagStatus(EXTI_Line4) == SET) //中断标志位 
	{
	//中断处理逻辑..
		motor_left();
	}
	EXTI_ClearFlag(EXTI_Line4); //清除中断标志位
}
