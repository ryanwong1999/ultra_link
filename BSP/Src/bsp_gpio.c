#include "includes.h" 
  
//LED IO��ʼ��
void LED_Init(void)
{    	 
  GPIO_InitTypeDef	GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(LED_PORT_CLK, ENABLE);			//ʹ��GPIOCʱ��

  //GPIOC13��ʼ������
  GPIO_InitStructure.GPIO_Pin = LED_PIN;						//LED��ӦIO��
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//��ͨ���ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//100MHz
  GPIO_Init(LED_PORT, &GPIO_InitStructure);					//��ʼ��GPIO

	LED_OFF;
}
