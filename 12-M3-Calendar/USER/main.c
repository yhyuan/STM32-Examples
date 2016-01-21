/******************** (C) COPYRIGHT 2013 **************************
 * 文件名  ：main.c
 * 描述    ：超强的日历，支持农历，24节气几乎所有日历的功能 日历时间以1970年为元年，
 *           用32bit的时间寄存器可以运行到2100年左右。         
 * 实验平台： STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：  
 * 论坛    ： 
 * 淘宝    ：http://gomcu.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"
#include "rtc.h"


/*时间结构体*/
struct rtc_time systmtime;


/**
  * @brief  Main program.
  * @param  None
  * @retval : None
  */
int main()
{
			
	  	/* 配置RTC秒中断优先级 */
	  NVIC_Configuration();
	  USART1_Config();
	  RTC_CheckAndConfig(&systmtime);

	
	  /* Display time in infinite loop */
	  Time_Show(&systmtime);
}




/******************* (C) COPYRIGHT 2013 *****END OF FILE************/

