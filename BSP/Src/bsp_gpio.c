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

//I2C�ӿڳ�ʼ��
void I2C_GPIO_Init(void)
{ 
	GPIO_InitTypeDef  GPIO_InitStructure; 	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);       
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE); 	//����I2C���� 
  GPIO_InitStructure.GPIO_Pin = I2C_SCL | I2C_SDA; 			//ѡ��˿ں�                      
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD; 			//ѡ��IO�ӿڹ�����ʽ       
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 		//����IO�ӿ��ٶȣ�2/10/50MHz��    
	GPIO_Init(I2CPORT, &GPIO_InitStructure);
}