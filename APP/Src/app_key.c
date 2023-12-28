#include "includes.h" 

/**
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up = 1;	//按键按松开标志
	if(mode) key_up = 1;  //支持连按		  
	if(key_up && (KEY_UPUP == 0 || KEY_DOWN == 0 || KEY_BACK == 0 || KEY_ENTER == 0))
	{
		delay_ms(10);//去抖动 
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
	return 0;// 无按键按下
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
	if (KEY_UP == 0 && keyState == 0) //按键按下
	{
		keyCount++;
		if (keyCount > 2 && KEY_UP == 0 && keyState == 0) //加两次类似延迟10ms，不好解释
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
	else if (KEY_UP == 1 && KEY_DOWN == 1 && KEY_BACK == 1 && KEY_ENTER == 1 && keyState == 1) //当所有按键都处于抬起状态，状态刷新
	{
		keyCount = 0;
		keyState = 0;
	}
}