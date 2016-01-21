/******************** (C) COPYRIGHT 2013 **************************
 * 文件名  ：main.c
 * 描述    ：PC0连接到key2，PC0配置为IO输入模式， ，
 *           LED2=DS2状态取反。         
 * 实验平台：STM32开发板
 * 库版本  ：ST3.5.0
 *	   
**********************************************************************************/

#include "stm32f10x.h"
#include "led.h"
#include "key.h"  

/**
  * @brief  Main program.
  * @param  None
  * @retval : None
  */
int main(void)
{ 
	/* config the sysclock to 72m */      
  SystemInit();

	/* config the led */
	LED_GPIO_Config();
	LED1( ON );
	/*config key*/
	Key_GPIO_Config();


  while(1)                            
  {	   
 	if( Key_Scan(GPIOC,GPIO_Pin_0) == KEY_ON  )
	{
			/*LED2-DS2反转*/
		   	GPIO_WriteBit(GPIOE, GPIO_Pin_6, 
		             (BitAction)((1-GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_6))));
	}   
  }
}

/******************* (C) COPYRIGHT 2013 *****END OF FILE****/
