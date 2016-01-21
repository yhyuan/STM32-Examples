/******************** (C) COPYRIGHT 2013 **************************
 * 文件名  ：main.c
 * 描述    ：PD12配置为输入模式，按下K2 LED1 -- DS1 翻转状态，按键为扫描模式        
 * 实验平台：STM32开发板
 * 库版本  ：ST3.5.0
 *
**********************************************************************************/
#include "stm32f10x.h" 
#include "led.h"
#include "key.h"  

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main(void)
{	
	/* config the led */
	LED_GPIO_Config();
	LED1( ON );

	/*config key*/
	Key_GPIO_Config();	
	
	while(1)                            
	{	   
		if( Key_Scan(GPIOD,GPIO_Pin_12) == KEY_ON  )
		{
			if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_12)!= KEY_ON)
			{
				/*LED1-DS1反转*/
				GPIO_WriteBit(GPIOE, GPIO_Pin_5, 
					(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_5))));
			}
		}   
	}
}


/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
