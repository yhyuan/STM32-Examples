/******************** (C) COPYRIGHT 2013 **************************
 * 文件名  ：main.c
 * 描述    ：LED1以300ms的频率闪烁(定时器 TIM3 产生定时)。        
 * 实验平台： STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：  
 * 论坛    ： 
 * 淘宝    ：http://gomcu.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "led.h" 
#include "Time_test.h"

volatile u32 time; // ms 计时变量

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无	
 */
int main(void)
{
	/* 配置系统时钟为 72M */  
	SystemInit();

	/* led 端口配置 */ 
	LED_GPIO_Config();

	/* TIM2 定时配置 */
	TIM2_NVIC_Configuration();
  TIM2_Configuration();

	/* TIM2 开始计时 */
	START_TIME;
	
  while(1)
  {
    if ( time == 1000 ) /* 1s 时间到 */
    {
      time = 0;
			/* LED1 取反 */      
			GPIO_WriteBit(GPIOE, GPIO_Pin_5, 
		               (BitAction)((1-GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_5)))); 
    }        
  }
}
/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
