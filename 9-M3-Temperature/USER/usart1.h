#ifndef __USART1_H
#define	__USART1_H

#include "stm32f10x.h"
#include <stdio.h>

void USART1_Config(void);				//关于串口USART1的配置
int fputc(int ch, FILE *f);			//想要使用printf()函数，把printf()重新定向到串口中
void USART1_printf(USART_TypeDef *USARTx, uint8_t *Data,...);  //格式化输出，类似于C库中的printf，但这里没有用到C库
			  //里面有函数itoa（）	 里面的“...”是不确定里面的数据的个数，可以写多个
#endif /* __USART1_H */	
