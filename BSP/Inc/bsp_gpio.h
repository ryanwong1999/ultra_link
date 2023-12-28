#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)			 {p->BSRR = i;}		//设置为高电平
#define digitalLo(p,i)			 {p->BRR  = i;}		//输出低电平
#define digitalToggle(p,i)	 {p->ODR ^= i;}		//输出反转状态	 

#define LED_PORT_CLK					RCC_APB2Periph_GPIOC
#define LED_PORT							GPIOC
#define LED_PIN								GPIO_Pin_13

#define LED_TOGGLE						digitalToggle	(LED_PORT, LED_PIN)
#define LED_OFF								GPIO_SetBits	(LED_PORT, LED_PIN)
#define LED_ON								GPIO_ResetBits(LED_PORT, LED_PIN)

#define I2CPORT								GPIOB					//定义IO接口
#define I2C_SCL								GPIO_Pin_6		//定义IO接口
#define I2C_SDA								GPIO_Pin_7		//定义IO接口

#define KEY_UP_PORT_CLK				RCC_APB2Periph_GPIOB   //输出继电器控制引脚
#define KEY_UP_PORT						GPIOB
#define KEY_UP_PIN						GPIO_Pin_8

#define KEY_DOWN_PORT_CLK			RCC_APB2Periph_GPIOB   //输出继电器控制引脚
#define KEY_DOWN_PORT					GPIOB
#define KEY_DOWN_PIN					GPIO_Pin_4

#define KEY_BACK_PORT_CLK			RCC_APB2Periph_GPIOB   //输出继电器控制引脚
#define KEY_BACK_PORT					GPIOB
#define KEY_BACK_PIN					GPIO_Pin_5

#define KEY_ENTER_PORT_CLK		RCC_APB2Periph_GPIOB   //输出继电器控制引脚
#define KEY_ENTER_PORT				GPIOB
#define KEY_ENTER_PIN					GPIO_Pin_9

#define key1 PBin(4)
#define key2 PBin(5)
#define key3 PBin(8)
#define key4 PBin(9)

#define KEY_UP      key3
#define KEY_DOWN    key1
#define KEY_BACK    key2
#define KEY_ENTER   key4 


void LED_Init(void);				//初始化		
void I2C_GPIO_Init(void);
void Key_Init(void);

#endif