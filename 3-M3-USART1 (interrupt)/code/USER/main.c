/******************** (C) COPYRIGHT 2013 **************************
 * �ļ���  ��main.c
 * ����    ��ͨ�����Եĳ����ն���Ƭ���������ݣ���Ƭ�������յ������ݷ��ص��ԣ�
 *         ������ʾ�ڳ����ն��ϡ��õ��Ǵ���1���жϷ�ʽ��         
 * ʵ��ƽ̨��STM32������
 * ��汾  ��ST3.5.0
 *

*********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{	
	/* USART1 config 115200 8-N-1 */
	USART1_Config();
	NVIC_Configuration();

	printf("\r\n this is a USART Interrupt demo \r\n");

	printf("\r\n***************����ʵ��--�����ж�ʵ��****************\r\n");
	printf("\r\n����:ʹ�ó����ն������ԱȽϺ�,�ڳ����ն�����һϵ���ַ���\r\n ��Ƭ�����յ��Լ�֮��ֱ�ӽ����յ����ַ���ԭ����ӡ����\r\n");
	printf("\r\n�뿪ʼ�����ַ���:\r\n");

	for(;;)
	{
		
	}
}
/******************* (C) COPYRIGHT 2013 *****END OF FILE************/