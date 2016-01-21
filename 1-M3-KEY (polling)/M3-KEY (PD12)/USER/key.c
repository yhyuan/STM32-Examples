/******************** (C) COPYRIGHT 2013 ***************************
 * 文件名  ：key.c
 * 描述    ：按键应用函数库         
 * 实验平台：STM32开发板
 * 硬件连接：-------------------------
 *          | PD12 - key1              |
 *          | PC0 - key2(本实验没用到)|
 *          |                         |
 *           -------------------------
 * 库版本  ：ST3.5.0
 *	 
**********************************************************************************/
#include "key.h" 

 /*
 * 函数名： Delay
 * 描述  ：不精确的延时
 * 输入  ：延时参数，
 * 输出  ：无
 */
 void Delay(__IO u32 nCount)
{
	for(; nCount != 0; nCount--);
} 

 /*
 * 函数名：Key_GPIO_Config
 * 描述  ：配置按键用到的I/O口
 * 输入  ：无
 * 输出  ：无
 */
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启按键端口（PD12）的时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	
	GPIO_Init(GPIOD, &GPIO_InitStructure);
}

 /*
 * 函数名：Key_Scan
 * 描述  ：检测是否有按键按下
 * 输入  ：GPIOx：x 可以是 A，B，C，D或者 E
 *		     GPIO_Pin：待读取的端口位 	
 * 输出  ：KEY_OFF(没按下按键)、KEY_ON（按下按键）
 */
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,u16 GPIO_Pin)
{			
	/*检测是否有按键按下 */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON ) 
	{	   
		/*延时消抖*/
		Delay(10*1000*72);  // 10ms		
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  
		{	 
			/*等待按键释放 */
			while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);   
			return 	KEY_ON;	 
		}
		else
			return KEY_OFF;
	}
	else
		return KEY_OFF;
}
/******************* (C) COPYRIGHT 2013 *****END OF FILE****/
