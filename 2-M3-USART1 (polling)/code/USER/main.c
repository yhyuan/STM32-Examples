/******************** (C) COPYRIGHT 2013 **************************
 * 文件名  ：main.c
 * 描述    ：将c库中的printf()函数实现到串口1(USART1)。这样我们就可以用printf()将
 *           调试信息通过串口打印到电脑上。         
 * 实验平台：STM32开发板
 * 库版本  ：ST3.5.0
 *	   
**********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main(void)
{	
	/* USART1 config 115200 8-N-1 */
	USART1_Config();
	
	printf("\r\n this is a printf demo \r\n");

	printf("\r\n 欢迎使用STM32-M3实验板:) \r\n");
		
	USART1_printf(USART1, "\r\n This is a USART1_printf demo \r\n");
	
	USART1_printf(USART1, "\r\n ("__DATE__ " - " __TIME__ ") \r\n");

	for(;;)
	{
		
	}
}
/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
