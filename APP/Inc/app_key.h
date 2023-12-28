#ifndef __APP_KEY_H
#define __APP_KEY_H

#define KEY_UPUP  	GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)		//��ȡ����
#define KEY_DOWN		GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)		//��ȡ����
#define KEY_BACK		GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)		//��ȡ����
#define KEY_ENTER		GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9)		//��ȡ����

#define KEY_UP_PRES			1
#define KEY_DOWN_PRES		2  
#define KEY_BACK_PRES		3 
#define KEY_ENTER_PRES	4

u8 KEY_Scan(u8 mode);  	//����ɨ�躯��		


void KeyScan(void);

#endif
