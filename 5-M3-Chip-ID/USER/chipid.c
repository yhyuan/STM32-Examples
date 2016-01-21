/******************** (C) COPYRIGHT 2013 ***************************
 * 文件名  ：chipid.c
 * 描述    ：获取CPU的ID函数，每个芯片都有唯一的 96_bit unique ID         
 * 实验平台： STM32开发板
 * 硬件连接：-----------------
 *          |                 |
 *          |       无        |
 *          |                 |
 *           -----------------
 * 库版本  ：ST3.5.0

**********************************************************************************/
#include "chipid.h"

uint32_t ChipUniqueID[3];

/*
 * 函数名：Get_ChipID
 * 描述  ：获取芯片ID
 * 输入  ：无
 * 输出  ：无
 */
void Get_ChipID(void)
{
	ChipUniqueID[0] = *(__IO u32 *)(0X1FFFF7F0); // 高字节
	ChipUniqueID[1] = *(__IO u32 *)(0X1FFFF7EC); // 
	ChipUniqueID[2] = *(__IO u32 *)(0X1FFFF7E8); // 低字节
}


/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
