#ifndef __APP_TASK_H__
#define __APP_TASK_H__
#include "includes.h"

#ifdef   APP_TASK_GLOBALS  //当编译app_task.c文件时，因为在app_task.c文件的最开始定义了APP_TASK_GLOBALS，因此将 APP_TASK_EXT定义为空，而当编译其他.C文件时，因为没有定义该宏，所以将APP_TASK_EXT 定义为 extern 
												   //这样就实现了直接在.h文件中定义全局变量
#define  APP_TASK_EXT
#else
#define  APP_TASK_EXT  extern
#endif


/**************************************任务句柄*************************************/
APP_TASK_EXT TaskHandle_t Start_Task_Handler;
APP_TASK_EXT TaskHandle_t Cammand_Task_Handler;
APP_TASK_EXT TaskHandle_t Err_Task_Handler;
APP_TASK_EXT TaskHandle_t Test_Task_Handler;
APP_TASK_EXT TaskHandle_t Led_Task_Handler;


/**********************************设置任务优先级***********************************/
#define START_TASK_PRIO		   		3 
#define CAMMAND_TASK_PRIO    		4
#define ERR_TASK_PRIO        		5
#define TEST_TASK_PRIO    			8
#define LED_TASK_PRIO		     		30  


/**********************************设置任务堆栈大小*********************************/
#define START_STK_SIZE 		   		128  
#define ERR_STK_SIZE 		     		128 
#define TEST_STK_SIZE        		128
#define CAMMAND_STK_SIZE     		128
#define LED_STK_SIZE 		     		128 


/*************************************任务堆栈**************************************/
APP_TASK_EXT StackType_t START_TASK_STK[START_STK_SIZE];
APP_TASK_EXT StackType_t ERR_TASK_STK[ERR_STK_SIZE];
APP_TASK_EXT StackType_t TEST_TASK_STK[TEST_STK_SIZE];
APP_TASK_EXT StackType_t CAMMAND_TASK_STK[CAMMAND_STK_SIZE];
APP_TASK_EXT StackType_t LED_TASK_STK[LED_STK_SIZE];


/***********************************任务函数声明*************************************/
void Start_Task(void *p_arg);	
void Err_Handle_Task(void *p_arg);    //异常任务处理函数
void Cammand_Task(void *p_arg);    		//命令处理函数
void Test_Task(void *p_arg);					//测试任务
void LED_Task(void *p_arg);     			//led测试函数

#endif