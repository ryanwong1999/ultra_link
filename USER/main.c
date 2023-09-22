#include "includes.h" 

/**
 * @description: *****************************������ʼ*****************************
 */
static void Initializer(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
	LED_Init();
}

int main(void)
{
	taskENTER_CRITICAL();		//�����ٽ���
	
	Initializer();
		
	//������ʼ����
	//������ �������� �����ջ��С ������� �������ȼ� ������
	xTaskCreate((TaskFunction_t )Start_Task,            //������
							(const char*    )"Start_Task",          //��������
							(uint16_t       )START_STK_SIZE,        //�����ջ��С
							(void*          )NULL,                  //���ݸ��������Ĳ���
							(UBaseType_t    )START_TASK_PRIO,       //�������ȼ�
							(TaskHandle_t*  )&Start_Task_Handler);	//������  

	taskEXIT_CRITICAL();		//�˳��ٽ���	
  vTaskStartScheduler();	//�����������			
	while(1);
}


