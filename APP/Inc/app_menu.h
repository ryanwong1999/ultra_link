#ifndef __APP_MENU_H
#define __APP_MENU_H

struct MenuProperty_t
{
	u8 MenuLen;//��ǰ�˵�ҳ�˵�����
	u8 scrollBarLen;//����������,���ڶ����õ�16SIZE���ַ�������һ���˵�ҳ����ĸ��˵�������˵���������Ϊ1
};

//�˵��ṹ��
struct Menu_t{
	struct MenuProperty_t *MenuProperty;
	u8 displayString[15];//��ǰ�˵����ַ�
	void (*func1) (void);//��ǰ�˵��Ĺ��ܺ���
	void (*func2) (void);//��ǰ�˵��Ĺ��ܺ���
	struct Menu_t *fatherMenu;//��ǰ�˵��ĸ����˵�
	struct Menu_t *childrenMenu;//��ǰ�˵����Ӽ��˵�	
};

extern uint16_t count1,count2,count3,count4,count5;



#endif