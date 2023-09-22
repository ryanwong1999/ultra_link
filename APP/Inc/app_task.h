#ifndef __APP_TASK_H__
#define __APP_TASK_H__
#include "includes.h"

#ifdef   APP_TASK_GLOBALS  //������app_task.c�ļ�ʱ����Ϊ��app_task.c�ļ����ʼ������APP_TASK_GLOBALS����˽� APP_TASK_EXT����Ϊ�գ�������������.C�ļ�ʱ����Ϊû�ж���ú꣬���Խ�APP_TASK_EXT ����Ϊ extern 
												   //������ʵ����ֱ����.h�ļ��ж���ȫ�ֱ���
#define  APP_TASK_EXT
#else
#define  APP_TASK_EXT  extern
#endif


/**************************************������*************************************/
APP_TASK_EXT TaskHandle_t Start_Task_Handler;
APP_TASK_EXT TaskHandle_t Cammand_Task_Handler;
APP_TASK_EXT TaskHandle_t Err_Task_Handler;
APP_TASK_EXT TaskHandle_t Test_Task_Handler;
APP_TASK_EXT TaskHandle_t Led_Task_Handler;


/**********************************�����������ȼ�***********************************/
#define START_TASK_PRIO		   		3 
#define CAMMAND_TASK_PRIO    		4
#define ERR_TASK_PRIO        		5
#define TEST_TASK_PRIO    			8
#define LED_TASK_PRIO		     		30  


/**********************************���������ջ��С*********************************/
#define START_STK_SIZE 		   		128  
#define ERR_STK_SIZE 		     		128 
#define TEST_STK_SIZE        		128
#define CAMMAND_STK_SIZE     		128
#define LED_STK_SIZE 		     		128 


/*************************************�����ջ**************************************/
APP_TASK_EXT StackType_t START_TASK_STK[START_STK_SIZE];
APP_TASK_EXT StackType_t ERR_TASK_STK[ERR_STK_SIZE];
APP_TASK_EXT StackType_t TEST_TASK_STK[TEST_STK_SIZE];
APP_TASK_EXT StackType_t CAMMAND_TASK_STK[CAMMAND_STK_SIZE];
APP_TASK_EXT StackType_t LED_TASK_STK[LED_STK_SIZE];


/***********************************����������*************************************/
void Start_Task(void *p_arg);	
void Err_Handle_Task(void *p_arg);    //�쳣��������
void Cammand_Task(void *p_arg);    		//�������
void Test_Task(void *p_arg);					//��������
void LED_Task(void *p_arg);     			//led���Ժ���

#endif