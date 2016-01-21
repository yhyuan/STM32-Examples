/******************** (C) COPYRIGHT 2013 **************************
 * 文件名  ：main.c
 * 描述    ：获取CPU的96bit ID 和 flash的大小，并通过USART1从超级终端打印出来。
 *           从串口可看到信息：
 *           芯片的唯一ID为: 43038438-33324332-547EFF39
 *           芯片flash的容量为: 512K         
 * 实验平台：STM32开发板
 * 库版本  ：ST3.5.0
 *

**********************************************************************************/
#include "stm32f10x.h"
#include "chipid.h"
#include "usart1.h"

extern uint32_t ChipUniqueID[3];
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

	/* to get the chipid and put it in ChipUniqueID[3] */
	Get_ChipID();	
	
	/* printf the chipid */
	printf("\r\n芯片的唯一ID为: %X-%X-%X\r\n",
	        ChipUniqueID[0],ChipUniqueID[1],ChipUniqueID[2]);
	
	/* printf the flash memory amount */
	printf("\r\n芯片flash的容量为: %dK \r\n", *(__IO u16 *)(0X1FFFF7E0));

	for(;;)
	{
		
	}
}
/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
