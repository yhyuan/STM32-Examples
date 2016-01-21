

#ifndef __RTC_H
#define	__RTC_H


#include "stm32f10x.h"
#include "calendar.h"
#include "date.h"
#include "usart1.h"

/* 如果定义了下面这个宏的话,PC13就会输出频率为RTC Clock/64的时钟 */   
//#define RTCClockOutput_Enable  /* RTC Clock/64 is output on tamper pin(PC.13) */

void NVIC_Configuration(void);
void RTC_Configuration(void);
void Time_Regulate(struct rtc_time *tm);
void Time_Adjust(struct rtc_time *tm);
void Time_Display(uint32_t TimeVar,struct rtc_time *tm);
void Time_Show(struct rtc_time *tm);
static uint8_t USART_Scanf(uint32_t value);
void RTC_CheckAndConfig(struct rtc_time *tm);

#endif /* __XXX_H */
