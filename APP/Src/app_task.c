#define APP_TASK_GLOBALS	 //����ȫ�ֱ���˽�к꣬������.c�ļ�û�ж���ú�
#include "includes.h" 

u8 isKeyUp = 0;
u8 isKeyDown = 0;
u8 isKeyBack = 0;
u8 isKeyEnter = 0;

void Start_Task(void *pvParameters)
{
	taskENTER_CRITICAL();           //�����ٽ���

	xTaskCreate((TaskFunction_t )Cammand_Task,            	//������
							(const char*    )"Cammand_Task",          	//��������
							(uint16_t       )CAMMAND_STK_SIZE,        	//�����ջ��С
							(void*          )NULL,                			//���ݸ��������Ĳ���
							(UBaseType_t    )CAMMAND_TASK_PRIO,       	//�������ȼ�
							(TaskHandle_t*  )&Cammand_Task_Handler);		//������  				
										 
	xTaskCreate((TaskFunction_t )Err_Handle_Task,           //������
							(const char*    )"Err_Handle_Task",         //��������
							(uint16_t       )ERR_STK_SIZE,        			//�����ջ��С
							(void*          )NULL,                			//���ݸ��������Ĳ���
							(UBaseType_t    )ERR_TASK_PRIO,       			//�������ȼ�
							(TaskHandle_t*  )&Err_Task_Handler);				//������  		

	xTaskCreate((TaskFunction_t )Test_Task,            			//������
							(const char*    )"Test_Task",          			//��������
							(uint16_t       )TEST_STK_SIZE,        			//�����ջ��С
							(void*          )NULL,                			//���ݸ��������Ĳ���
							(UBaseType_t    )TEST_TASK_PRIO,       			//�������ȼ�
							(TaskHandle_t*  )&Test_Task_Handler);				//������  

	xTaskCreate((TaskFunction_t )LED_Task,            			//������
							(const char*    )"LED_Task",          			//��������
							(uint16_t       )LED_STK_SIZE,        			//�����ջ��С
							(void*          )NULL,                			//���ݸ��������Ĳ���
							(UBaseType_t    )LED_TASK_PRIO,       			//�������ȼ�
							(TaskHandle_t*  )&Led_Task_Handler);				//������
			
	xTaskCreate((TaskFunction_t )Display_Task,            	//������
							(const char*    )"Display_Task",          	//��������
							(uint16_t       )DISPLAY_STK_SIZE,        	//�����ջ��С
							(void*          )NULL,                  		//���ݸ��������Ĳ���
							(UBaseType_t    )DISPLAY_TASK_PRIO,       	//�������ȼ�
							(TaskHandle_t*  )&Display_Task_Handler);   	//������									
	
	xTaskCreate((TaskFunction_t )Key_Task,            			//������
							(const char*    )"Key_Task",          			//��������
							(uint16_t       )KEY_STK_SIZE,        			//�����ջ��С
							(void*          )NULL,                  		//���ݸ��������Ĳ���
							(UBaseType_t    )KEY_TASK_PRIO,       			//�������ȼ�
							(TaskHandle_t*  )&Key_Task_Handler);   			//������
							
	vTaskDelete(Start_Task_Handler);	//ɾ����ʼ����
	taskEXIT_CRITICAL();            	//�˳��ٽ���
}

/************************************************/
//�������ܣ��쳣����������
//���������
//����ֵ��
//��ע��
/************************************************/
void Err_Handle_Task(void *p_arg)
{
	while(1)
	{

		vTaskDelay(500);
	}
}


/************************************************/
//�������ܣ����������
//���������
//����ֵ��
//��ע��
/************************************************/
u8 t;
u8 len;	
u16 times = 0; 
void Cammand_Task(void *p_arg)
{
	while(1)
	{		
		if(USART_RX_STA & 0x8000)
		{					   
			len = USART_RX_STA & 0x3fff;				//�õ��˴ν��յ������ݳ���
			printf("\r\n�����͵���ϢΪ:\r\n");
			for(t=0; t<len; t++)
			{
				USART1->DR = USART_RX_BUF[t];
				while((USART1->SR & 0X40) == 0);	//�ȴ����ͽ���
			}
			printf("\r\n\r\n");									//���뻻��
			USART_RX_STA = 0;
		}
		else
		{
			times++;
			if(times % 5000 == 0)
			{
				printf("\r\nALIENTEK MiniSTM32������ ����ʵ��\r\n");
				printf("����ԭ��@ALIENTEK\r\n\r\n\r\n");
			}
			if(times % 200 == 0)
				printf("����������,�Իس�������\r\n");  
			delay_ms(10);   
		}
		vTaskDelay(10);
	}
}

/************************************************/
//�������ܣ���ʾ����
//���������
//����ֵ��
//��ע��
/************************************************/
void Display_Task(void *p_arg)
{
	while(1)
	{
		count1++;
		count2++;
		count3++;
		count4++;
		MenuControl();
		GuiDataDisplayRefresh();
		vTaskDelay(10);
	}
}

/************************************************/
//�������ܣ���������������
//���������
//����ֵ��
//��ע��
/************************************************/
void Key_Task(void *p_arg)
{
	int t = 0;
	while(1)
	{
		t = KEY_Scan(0);		//�õ���ֵ
		switch(t)
		{				 
			case KEY_UP_PRES:
				isKeyUp = 1;
				break;
			case KEY_DOWN_PRES:
				isKeyDown = 1;
				break;
			case KEY_BACK_PRES:
				isKeyBack = 1;
				break;
			case KEY_ENTER_PRES:
			  isKeyEnter = 1;
				break;
			default:
				delay_ms(10);	
		}
		vTaskDelay(10);
	}
}

/************************************************/
//�������ܣ���������
//���������
//����ֵ��
//��ע��
/************************************************/
void Test_Task(void *p_arg)
{
	while(1)
	{		
	
		vTaskDelay(500);
	}
}


/************************************************/
//�������ܣ�led��������
//���������
//����ֵ��
//��ע��
/************************************************/
void LED_Task(void *p_arg)
{
	while(1)
	{
		LED_TOGGLE;
		vTaskDelay(500);
	}  
}

