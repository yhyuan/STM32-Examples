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
#include "led.h"

 extern uint8_t SendBuff[SENDBUFF_SIZE];
 uint16_t i;


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
	DMA_Config();
	LED_GPIO_Config();
	

  /*填充将要发送的数据*/
 for(i=0;i<SENDBUFF_SIZE;i++)
   	{
		SendBuff[i]	 = 0xff;
   }

 /*串口向 DMA发出请求 */
 USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);	

  /*在DMA尚未传送完成时，cpu继续执行main函数中的代码*/
  /*点亮了LED灯*/
/*而同时DMA在向串口运送数据，当DMA发送完成时，在中断函数关闭LED灯 */


	LED1(ON);


	while(1);
}
/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
