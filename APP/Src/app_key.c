#include "includes.h" 

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