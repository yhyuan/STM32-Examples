/******************** (C) COPYRIGHT 2011    ********************
 * 文件名  ：main.c
 * 描述    ：STM32内部温度测试，测试信息通过USART1打印在电脑的超级终端。
 *          
 * 实验平台：STM32开发板
 * 库版本  ：ST3.5.0
 * 
**********************************************************************************/	
#include "stm32f10x.h"
#include "usart1.h"
#include "tempad.h"

/* ADC1转换的电压值通过MDA方式传到sram*/
extern __IO u16 ADC_ConvertedValue;


/*计算后的温度值*/
 u16 Current_Temp;	 

 
/* 软件延时	*/
void Delay(__IO u32 nCount)
{
  for(; nCount != 0; nCount--);
} 

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  : 无
 * 输出  ：无
 */
int main(void)
{  
		 
 /* USART1 config 115200 8-N-1 */
  	USART1_Config();

	Temp_ADC1_Init();

	printf("\r\n 这是一个内部温度传感器实验 \r\n");
	printf( "\r\n Print current Temperature  \r\n");	

  while (1)
  { 

	Delay(0xffffee);      // 延时 
	
	//计算方法1            	                 									  
 	 //Current_Temp= (1.43- ADC_ConvertedValue*3.3/4096)*1000 / 4.3+ 25 ;
	
	//计算方法2
	Current_Temp=(V25-ADC_ConvertedValue)/AVG_SLOPE+25;	

	//10进制显示
	printf("\r\n The current temperature= %3d ℃\r\n", Current_Temp);	      
 	 
	//16进制显示 						 
 	// printf("\r\n The current temperature= %04x \r\n", Current_Temp);		 
  }
}
/******************* (C) COPYRIGHT 2011  *****END OF FILE****/ 
