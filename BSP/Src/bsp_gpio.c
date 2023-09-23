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

//I2C接口初始化
void I2C_GPIO_Init(void)
{ 
	GPIO_InitTypeDef  GPIO_InitStructure; 	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);       
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE); 	//启动I2C功能 
  GPIO_InitStructure.GPIO_Pin = I2C_SCL | I2C_SDA; 			//选择端口号                      
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD; 			//选择IO接口工作方式       
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 		//设置IO接口速度（2/10/50MHz）    
	GPIO_Init(I2CPORT, &GPIO_InitStructure);
}