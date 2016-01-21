/******************** (C) COPYRIGHT 2013 **************************
 * 文件名  ：main.c
 * 描述    ：CRC(冗余校验)实验。将数组中数通过单片机内部的CRC校验电路产生的CRC校验
 *           码通过USART1(串口1)在电脑上的超级终端打印出来。         
 * 实验平台：STM32开发板
 * 库版本  ：ST3.5.0
 * 
**********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"
#include "crc.h" 

extern __IO uint32_t CRCValue;
/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main(void)
{
	uint8_t i = 0;
		
	/* USART1 config 115200 8-N-1 */
	USART1_Config();
	
	/* 使能CRC时钟 */
	CRC_Config();
	
	printf("\r\n 这是一个 CRC(循环冗余校验)实验 \r\n");
	
	/* Compute the CRC of "DataBuffer" */
	for(i=0; i<BUFFER_SIZE; i++ ) 
	{
		CRCValue = CRC_CalcBlockCRC((uint32_t *)DataBuffer, BUFFER_SIZE);
		printf("\r\n32-bit CRC 校验码为:0X%X\r\n", CRCValue);
	}
	printf("\r\nCRC(循环冗余校验)测试成功\r\n");

	for(;;)
	{
		
	}
}
/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
