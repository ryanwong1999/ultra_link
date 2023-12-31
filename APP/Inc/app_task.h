#ifndef __APP_TASK_H__
#define __APP_TASK_H__
#include "includes.h"

#ifdef   APP_TASK_GLOBALS  //当编译app_task.c文件时，因为在app_task.c文件的最开始定义了APP_TASK_GLOBALS，因此将 APP_TASK_EXT定义为空，而当编译其他.C文件时，因为没有定义该宏，所以将APP_TASK_EXT 定义为 extern 
												   //这样就实现了直接在.h文件中定义全局变量
#define  APP_TASK_EXT
#else
#define  APP_TASK_EXT  extern
#endif

extern u8 isKeyUp;
extern u8 isKeyDown;
extern u8 isKeyBack;
extern u8 isKeyEnter;

/**************************************任务句柄*************************************/
APP_TASK_EXT TaskHandle_t Start_Task_Handler;
APP_TASK_EXT TaskHandle_t Cammand_Task_Handler;
APP_TASK_EXT TaskHandle_t Err_Task_Handler;
APP_TASK_EXT TaskHandle_t Test_Task_Handler;
APP_TASK_EXT TaskHandle_t Led_Task_Handler;
APP_TASK_EXT TaskHandle_t Display_Task_Handler;
APP_TASK_EXT TaskHandle_t Key_Task_Handler;


/**********************************设置任务优先级***********************************/
#define START_TASK_PRIO		   		3 
#define DISPLAY_TASK_PRIO       4
#define TEST_TASK_PRIO    			5
#define LED_TASK_PRIO		     		6  
#define ERR_TASK_PRIO        		7
#define CAMMAND_TASK_PRIO    		8
#define KEY_TASK_PRIO      		  9		//按键任务优先级设置为最高


/**********************************设置任务堆栈大小*********************************/
#define START_STK_SIZE 		   		64  
#define ERR_STK_SIZE 		     		256 
#define TEST_STK_SIZE        		256
#define CAMMAND_STK_SIZE     		256
#define LED_STK_SIZE 		     		256 
#define DISPLAY_STK_SIZE  			512
#define KEY_STK_SIZE  		      256


/*************************************任务堆栈**************************************/
APP_TASK_EXT StackType_t START_TASK_STK[START_STK_SIZE];
APP_TASK_EXT StackType_t ERR_TASK_STK[ERR_STK_SIZE];
APP_TASK_EXT StackType_t TEST_TASK_STK[TEST_STK_SIZE];
APP_TASK_EXT StackType_t CAMMAND_TASK_STK[CAMMAND_STK_SIZE];
APP_TASK_EXT StackType_t LED_TASK_STK[LED_STK_SIZE];
APP_TASK_EXT StackType_t DISPLAY_TASK_STK[DISPLAY_STK_SIZE];
APP_TASK_EXT StackType_t KEY_TASK_STK[KEY_STK_SIZE];


/***********************************任务函数声明*************************************/
void Start_Task(void *p_arg);	
void Err_Handle_Task(void *p_arg);    //异常任务处理函数
void Cammand_Task(void *p_arg);    		//命令处理函数
void Test_Task(void *p_arg);					//测试任务
void LED_Task(void *p_arg);     			//led测试函数
void Display_Task(void *pvParameters);	
void Key_Task(void *pvParameters);

#endif