#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)			 {p->BSRR = i;}		//����Ϊ�ߵ�ƽ
#define digitalLo(p,i)			 {p->BRR  = i;}		//����͵�ƽ
#define digitalToggle(p,i)	 {p->ODR ^= i;}		//�����ת״̬	 

#define LED_PORT_CLK					RCC_APB2Periph_GPIOC
#define LED_PORT							GPIOC
#define LED_PIN								GPIO_Pin_13

#define LED_TOGGLE						digitalToggle	(LED_PORT, LED_PIN)
#define LED_OFF								GPIO_SetBits	(LED_PORT, LED_PIN)
#define LED_ON								GPIO_ResetBits(LED_PORT, LED_PIN)

#define I2CPORT								GPIOB					//����IO�ӿ�
#define I2C_SCL								GPIO_Pin_6		//����IO�ӿ�
#define I2C_SDA								GPIO_Pin_7		//����IO�ӿ�

#define KEY_UP_PORT_CLK				RCC_APB2Periph_GPIOB   //����̵�����������
#define KEY_UP_PORT						GPIOB
#define KEY_UP_PIN						GPIO_Pin_8

#define KEY_DOWN_PORT_CLK			RCC_APB2Periph_GPIOB   //����̵�����������
#define KEY_DOWN_PORT					GPIOB
#define KEY_DOWN_PIN					GPIO_Pin_4

#define KEY_BACK_PORT_CLK			RCC_APB2Periph_GPIOB   //����̵�����������
#define KEY_BACK_PORT					GPIOB
#define KEY_BACK_PIN					GPIO_Pin_5

#define KEY_ENTER_PORT_CLK		RCC_APB2Periph_GPIOB   //����̵�����������
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


void LED_Init(void);				//��ʼ��		
void I2C_GPIO_Init(void);
void Key_Init(void);

#endif