#define APP_TASK_GLOBALS	 //定义全局变量私有宏，即其他.c文件没有定义该宏
#include "includes.h" 

void Start_Task(void *pvParameters)
{
	taskENTER_CRITICAL();           //进入临界区

	xTaskCreate((TaskFunction_t )Cammand_Task,            	//任务函数
							(const char*    )"Cammand_Task",          	//任务名称
							(uint16_t       )CAMMAND_STK_SIZE,        	//任务堆栈大小
							(void*          )NULL,                			//传递给任务函数的参数
							(UBaseType_t    )CAMMAND_TASK_PRIO,       	//任务优先级
							(TaskHandle_t*  )&Cammand_Task_Handler);		//任务句柄  				
										 
	xTaskCreate((TaskFunction_t )Err_Handle_Task,           //任务函数
							(const char*    )"Err_Handle_Task",         //任务名称
							(uint16_t       )ERR_STK_SIZE,        			//任务堆栈大小
							(void*          )NULL,                			//传递给任务函数的参数
							(UBaseType_t    )ERR_TASK_PRIO,       			//任务优先级
							(TaskHandle_t*  )&Err_Task_Handler);				//任务句柄  		

	xTaskCreate((TaskFunction_t )Test_Task,            			//任务函数
							(const char*    )"Test_Task",          			//任务名称
							(uint16_t       )TEST_STK_SIZE,        			//任务堆栈大小
							(void*          )NULL,                			//传递给任务函数的参数
							(UBaseType_t    )TEST_TASK_PRIO,       			//任务优先级
							(TaskHandle_t*  )&Test_Task_Handler);				//任务句柄  

							
	xTaskCreate((TaskFunction_t )LED_Task,            			//任务函数
							(const char*    )"LED_Task",          			//任务名称
							(uint16_t       )LED_STK_SIZE,        			//任务堆栈大小
							(void*          )NULL,                			//传递给任务函数的参数
							(UBaseType_t    )LED_TASK_PRIO,       			//任务优先级
							(TaskHandle_t*  )&Led_Task_Handler);				//任务句柄
							
	vTaskDelete(Start_Task_Handler);	//删除开始任务
	taskEXIT_CRITICAL();            	//退出临界区
}

/************************************************/
//函数功能：异常任务处理任务
//输入参数：
//返回值：
//备注：
/************************************************/
void Err_Handle_Task(void *p_arg)
{
	while(1)
	{

		vTaskDelay(500);
	}
}


/************************************************/
//函数功能：命令处理任务
//输入参数：
//返回值：
//备注：
/************************************************/
			
u8 t;
u8 len;	
u16 times=0; 
void Cammand_Task(void *p_arg)
{
	while(1)
	{		
		if(USART_RX_STA&0x8000)
		{					   
			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			printf("\r\n您发送的消息为:\r\n");
			for(t=0;t<len;t++)
			{
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0);//等待发送结束
			}
			printf("\r\n\r\n");//插入换行
			USART_RX_STA=0;
		}
		else
		{
			times++;
			if(times%5000==0)
			{
				printf("\r\nALIENTEK MiniSTM32开发板 串口实验\r\n");
				printf("正点原子@ALIENTEK\r\n\r\n\r\n");
			}
			if(times%200==0)printf("请输入数据,以回车键结束\r\n");  
			delay_ms(10);   
		}
		vTaskDelay(10);
	}
}


/************************************************/
//函数功能：测试任务
//输入参数：
//返回值：
//备注：
/************************************************/
void Test_Task(void *p_arg)
{
	while(1)
	{		
	
		vTaskDelay(500);
	}
}


/************************************************/
//函数功能：led控制任务
//输入参数：
//返回值：
//备注：
/************************************************/
void LED_Task(void *p_arg)
{
	while(1)
	{
		LED_TOGGLE;
		vTaskDelay(500);
	}  
}

