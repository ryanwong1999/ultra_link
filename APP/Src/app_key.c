#include "includes.h" 

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