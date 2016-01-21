/******************** (C) COPYRIGHT 2012 **************************
 * 文件名  ：main.c
 * 描述    ：I2C EEPROM(AT24C02)测试，测试信息通过USART1打印在电脑的超级终端。
 *         
 * 实验平台：STM32开发板
 * 库版本  ：ST3.5.0
 *
**********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"
#include "i2c_ee.h"

#define  EEP_Firstpage      0x00
u8 I2c_Buf_Write[256];
u8 I2c_Buf_Read[256];
void I2C_Test(void);

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 * 返回  ：无
 */
int main(void)
{  
	/* 配置系统时钟为 72M */      
  //SystemInit();;

  /* 串口1初始化 */
	USART1_Config();

	/* I2C 外设初(AT24C02)始化 */
	I2C_EE_Init();

	USART1_printf(USART1, "\r\n 这是一个I2C外设(AT24C02)读写测试例程 \r\n");
	USART1_printf(USART1, "\r\n ("__DATE__ " - " __TIME__ ") \r\n");
	 	 
	I2C_Test();

  while (1)
  {      
  }
}

/*
 * 函数名：I2C_EE_Test
 * 描述  ：I2C(AT24C02)读写测试。
 * 输入  ：无
 * 输出  ：无
 * 返回  ：无
 */
void I2C_Test(void)
{
	u16 i;

	printf("写入的数据\n\r");
    
	for ( i=0; i<=255; i++ ) //填充缓冲
  {   
    I2c_Buf_Write[i] = i;

    printf("0x%02X ", I2c_Buf_Write[i]);
    if(i%16 == 15)    
        printf("\n\r");    
   }

  //将I2c_Buf_Write中顺序递增的数据写入EERPOM中 
	I2C_EE_BufferWrite( I2c_Buf_Write, EEP_Firstpage, 256);	 
  
  printf("\n\r读出的数据\n\r");
  //将EEPROM读出数据顺序保持到I2c_Buf_Read中 
	I2C_EE_BufferRead(I2c_Buf_Read, EEP_Firstpage, 256); 

  //将I2c_Buf_Read中的数据通过串口打印
	for (i=0; i<256; i++)
	{	
		if(I2c_Buf_Read[i] != I2c_Buf_Write[i])
		{
			printf("0x%02X ", I2c_Buf_Read[i]);
			printf("错误:I2C EEPROM写入与读出的数据不一致\n\r");
			return;
		}
    printf("0x%02X ", I2c_Buf_Read[i]);
    if(i%16 == 15)    
        printf("\n\r");
    
	}
  printf("I2C(AT24C02)读写测试成功\n\r");
}
/******************* (C) COPYRIGHT 2012  *****END OF FILE************/
