/******************** (C) COPYRIGHT 2012 **************************
 * 文件名  ：main.c
 * 描述    ：LED流水灯，频率可调……         
 * 实验平台：STM32开发板
 * 库版本  ：ST3.5.0
 *	
**********************************************************************************/
#include "stm32f10x.h"
#include "led.h"

//#define    MI_ERR    (-2)

void Delay(__IO u32 nCount);

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main(void)
{	
	/* LED 端口初始化 */
	LED_GPIO_Config();

	while (1)
	{
		LED1( ON );			  // 亮
		Delay(0x0FFFEF);
		LED1( OFF );		  // 灭
		
		LED2( ON );
		Delay(0x0FFFEF);
		LED2( OFF );  		
	
	}
}

void Delay(__IO u32 nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
} 


/******************* (C) COPYRIGHT 2012 *****END OF FILE************/
