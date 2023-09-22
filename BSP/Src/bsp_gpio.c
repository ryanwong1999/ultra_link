#include "includes.h" 
  
//LED IO初始化
void LED_Init(void)
{    	 
  GPIO_InitTypeDef	GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(LED_PORT_CLK, ENABLE);			//使能GPIOC时钟

  //GPIOC13初始化设置
  GPIO_InitStructure.GPIO_Pin = LED_PIN;						//LED对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//普通输出模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//100MHz
  GPIO_Init(LED_PORT, &GPIO_InitStructure);					//初始化GPIO

	LED_OFF;
}
