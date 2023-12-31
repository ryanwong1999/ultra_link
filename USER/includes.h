#ifndef __INCLUDES_H
#define __INCLUDES_H


/*
*********************************************************************************************************
*                                        STANDARD LIBRARIES
*********************************************************************************************************
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>


/*********************************************************************************************************
                                          FreeRTOS include 
*********************************************************************************************************/
#include "FreeRTOS.h"
#include "task.h"


/*
*********************************************************************************************************
*                                          STM32  SYSTEM
*********************************************************************************************************
*/
#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"	
#include "croutine.h"
//#include "malloc.h"	 


/*
*********************************************************************************************************
*                                            STM32  BSP
*********************************************************************************************************
*/
#include "bsp_adc.h"
#include "bsp_cap.h"
#include "bsp_gpio.h"
#include "bsp_iic.h"
#include "bsp_iwdg.h"
#include "bsp_pwm.h"
#include "bsp_rs485.h"
#include "bsp_tim.h"
#include "bsp_usart.h"
#include "bsp_oled.h"
#include "bsp_lcd.h"
#include "bsp_lcd_init.h"


/*
*********************************************************************************************************
*                                            STM32  APP
*********************************************************************************************************
*/
#include "app_task.h" 
#include "app_24cxx.h"
#include "app_usart.h" 
#include "app_cap.h" 
#include "app_exit.h" 
#include "app_system.h" 
#include "app_tim.h" 
#include "app_key.h" 
#include "app_menu.h" 
#include "app_mytime.h" 



#endif
