#include "includes.h" 

/**
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up = 1;	//�������ɿ���־
	if(mode) key_up = 1;  //֧������		  
	if(key_up && (KEY_UPUP == 0 || KEY_DOWN == 0 || KEY_BACK == 0 || KEY_ENTER == 0))
	{
		delay_ms(10);//ȥ���� 
		key_up = 0;
		if(KEY_UPUP == 0)
			return KEY_UP_PRES;
		else if(KEY_DOWN == 0)
			return KEY_DOWN_PRES;
		else if(KEY_BACK == 0)
			return KEY_BACK_PRES; 
		else if(KEY_ENTER == 0)
			return KEY_ENTER_PRES; 
	}
	else if(KEY_UPUP == 1 && KEY_DOWN == 1 && KEY_BACK == 1 && KEY_ENTER == 1)
		key_up = 1; 	     
	return 0;// �ް�������
}
**/

u8 isKeyUp = 0;
u8 isKeyDown = 0;
u8 isKeyBack = 0;
u8 isKeyEnter = 0;

void KeyUp()
{
	if(isKeyUp == 0)
		isKeyUp=1;
}

void KeyDown()
{
	if(isKeyDown == 0)
		isKeyDown=1;
}

void KeyBack()
{
	if(isKeyBack == 0)
		isKeyBack=1;
}

void KeyEnter()
{
	if(isKeyEnter == 0)
		isKeyEnter=1;
}


void KeyScan()
{
	static int keyCount = 0;
	static int keyState = 0;
	if (KEY_UP == 0 && keyState == 0) //��������
	{
		keyCount++;
		if (keyCount > 2 && KEY_UP == 0 && keyState == 0) //�����������ӳ�10ms�����ý���
		{
			KeyUp();
			keyState = 1;
		}
	}
	else if (KEY_DOWN == 0 && keyState == 0)
	{
		keyCount++;
		if (keyCount > 2 && KEY_DOWN == 0 && keyState == 0)
		{
			KeyDown();
			keyState = 1;
		}
	}
	else if (KEY_BACK == 0 && keyState == 0)
	{
		keyCount++;
		if (keyCount > 2 && KEY_BACK == 0 && keyState == 0)
		{
			KeyBack();
			keyState = 1;
		}
	}
	else if (KEY_ENTER == 0 && keyState == 0)
	{
		keyCount++;
		if (keyCount > 2 && KEY_ENTER == 0 && keyState == 0)
		{
			KeyEnter();
			keyState = 1;
		}
	}
	else if (KEY_UP == 1 && KEY_DOWN == 1 && KEY_BACK == 1 && KEY_ENTER == 1 && keyState == 1) //�����а���������̧��״̬��״̬ˢ��
	{
		keyCount = 0;
		keyState = 0;
	}
}