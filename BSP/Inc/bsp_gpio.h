#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)			 {p->BSRR = i;}		//设置为高电平
#define digitalLo(p,i)			 {p->BRR  = i;}		//输出低电平
#define digitalToggle(p,i)	 {p->ODR ^= i;}		//输出反转状态	 

#define LED_PORT_CLK					RCC_APB2Periph_GPIOC
#define LED_PORT							GPIOC
#define LED_PIN								GPIO_Pin_13

#define LED_TOGGLE						digitalToggle(LED_PORT, LED_PIN)
#define LED_OFF								GPIO_SetBits(LED_PORT, LED_PIN)
#define LED_ON								GPIO_ResetBits(LED_PORT, LED_PIN)

#define I2CPORT								GPIOB					//定义IO接口
#define I2C_SCL								GPIO_Pin_6		//定义IO接口
#define I2C_SDA								GPIO_Pin_7		//定义IO接口


void LED_Init(void);				//初始化		
void I2C_GPIO_Init(void);

#endif