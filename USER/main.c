#include "includes.h" 

void RCC_Configuration(void);

/**
 * @description: *****************************������ʼ*****************************
 */
static void Initializer(void)
{
	SystemInit();								//System init.
	RCC_Configuration(); 				//ʱ������
	delay_init();	 							//Delay init.
//	Timer_Init();								//��ʼ����ʱ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	uart_init(9600);	 					//���ڳ�ʼ��Ϊ9600
	Key_Init();
	LED_Init();
	OLED_Init();  								//OLED����ʼ��
//	TIM4_CH1_PWM_Init(2000,720);//PWMƵ��=72000000/2000/720=50hz=20ms
	MenuInit();
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

//RCCʱ�ӵ�����  
void RCC_Configuration(void)
{ 
	ErrorStatus HSEStartUpStatus;   
	RCC_DeInit();              /* RCC system reset(for debug purpose) RCC�Ĵ����ָ���ʼ��ֵ*/   
	RCC_HSEConfig(RCC_HSE_ON); /* Enable HSE ʹ���ⲿ���پ���*/   
	HSEStartUpStatus = RCC_WaitForHSEStartUp(); /* Wait till HSE is ready �ȴ��ⲿ���پ���ʹ�����*/   
	if(HSEStartUpStatus == SUCCESS)
	{
		/*����PLLʱ��Դ����Ƶϵ��*/   
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9); //RCC_PLLMul_x��ö��2~16���Ǳ�Ƶֵ����HSE=8MHZ,RCC_PLLMul_9ʱPLLCLK=72MHZ   
		/*����AHBʱ�ӣ�HCLK��*/   
		RCC_HCLKConfig(RCC_SYSCLK_Div1); //RCC_SYSCLK_Div1����AHBʱ�� = ϵͳʱ��(SYSCLK) = 72MHZ���ⲿ����8HMZ��   
		/*ע��˴������ã����ʹ��SYSTICK����ʱ���򣬴�ʱSYSTICK(Cortex System timer)=HCLK/8=9MHZ*/   
		RCC_PCLK1Config(RCC_HCLK_Div2); //���õ���AHBʱ�ӣ�PCLK1��,RCC_HCLK_Div2����APB1ʱ�� = HCLK/2 = 36MHZ���ⲿ����8HMZ��   
		RCC_PCLK2Config(RCC_HCLK_Div1); //���ø���AHBʱ�ӣ�PCLK2��,RCC_HCLK_Div1����APB2ʱ�� = HCLK = 72MHZ���ⲿ����8HMZ��   
		/*ע��AHB��Ҫ�����ⲿ�洢��ʱ�ӡ�APB2����AD��I/O���߼�TIM������1��APB1����DA��USB��SPI��I2C��CAN������2��3��4��5����ͨTIM */  
		FLASH_SetLatency(FLASH_Latency_2); //����FLASH�洢����ʱʱ��������   
		/*FLASHʱ���ӳټ������ڣ��ȴ�����ͬ��������   
		�Ƽ����յ�Ƭ��ϵͳ����Ƶ�ʣ�
		0��24MHzʱ��ȡLatency_0��   
		24��48MHzʱ��ȡLatency_1��   
		48~72MHzʱ��ȡLatency_2*/   
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable); //ѡ��FLASHԤȡָ�����ģʽ��Ԥȡָ����ʹ��   
		RCC_PLLCmd(ENABLE);	//ʹ��PLL
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); //�ȴ�PLL����ȶ�   
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); //ѡ��SYSCLKʱ��ԴΪPLL
		while(RCC_GetSYSCLKSource() != 0x08); //�ȴ�PLL��ΪSYSCLKʱ��Դ   
	}  
	/*��ʼʹ�ܳ�������Ҫʹ�õ�����ʱ��*/   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |   
	RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE, ENABLE); //APB2����ʱ��ʹ��      
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); //APB1����ʱ��ʹ��  
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);   
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);   	 
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);    
}  