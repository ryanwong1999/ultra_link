#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)			 {p->BSRR = i;}		//����Ϊ�ߵ�ƽ
#define digitalLo(p,i)			 {p->BRR  = i;}		//����͵�ƽ
#define digitalToggle(p,i)	 {p->ODR ^= i;}		//�����ת״̬	 

#define LED_PORT_CLK					RCC_APB2Periph_GPIOC
#define LED_PORT							GPIOC
#define LED_PIN								GPIO_Pin_13

#define LED_TOGGLE						digitalToggle(LED_PORT, LED_PIN)
#define LED_OFF								GPIO_SetBits(LED_PORT, LED_PIN)
#define LED_ON								GPIO_ResetBits(LED_PORT, LED_PIN)


void LED_Init(void);//��ʼ��		

#endif