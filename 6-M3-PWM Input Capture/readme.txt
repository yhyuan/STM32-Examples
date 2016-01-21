|------------------------------------------------------------
|注：该例程裁剪于官方例程，已经在 M3工程模板中编译成功，  | 
 
--------------------------------------------------------------
以下是该例程的官方描述（为方便理解，fire已修改过）								   
--------------------------------------------------------------
/**
  @page TIM_PWM_Input TIM_PWM_Input
  
  @verbatim
  ******************** (C) COPYRIGHT 2009 STMicroelectronics *******************
  * @file TIM/PWM_Input/readme.txt 
  * @author  MCD Application Team
  * @version  V3.0.0
  * @date  04/06/2009
  * @brief  Description of the TIM PWM_Input example.
  ******************************************************************************
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  ******************************************************************************
   @endverbatim

@par Example Description 

This example shows how to use the TIM peripheral to measure the frequency and 
duty cycle of an external signal.

The TIMxCLK frequency is set to 72 MHz, the Prescaler is 0 so the TIM2 counter 
clock is 72 MHz. so the minimum frequency value to measure is 1100 Hz.
TIM2 is configured in PWM Input Mode: the external signal is connected to 
TIM2 Channel2 used as input pin.
To measure the frequency and the duty cycle we use the TIM2 CC2 interrupt request,
so In the TIM2_IRQHandler routine, the frequency and the duty cycle of the external 
signal are computed. 
The "Frequency" variable contains the external signal frequency:
Frequency = TIM2 counter clock / TIM2_CCR2 in Hz, 
The "DutyCycle" variable contains the external signal duty cycle:
DutyCycle = (TIM2_CCR1*100)/(TIM2_CCR2) in %.

@par Directory contents 

  - TIM/PWM_Input/stm32f10x_conf.h  Library Configuration file
  - TIM/PWM_Input/stm32f10x_it.c    Interrupt handlers
  - TIM/PWM_Input/stm32f10x_it.h    Interrupt handlers header file
  - TIM/PWM_Input/main.c            Main program 


  - Connect the external signal to measure to the TIM2 CH2 pin (PA.01).
  - 将外部的需要测量的信号连接到TIM2 CH2 pin (PA.01)即可测量， M3开
  - 发板中已经留有 PA.01 的端子接口，可方便用户连接外部信号。  
  
@par How to use it ? 

In order to make the program work, you must do the following:
- Create a project and setup all project configuration
- Add the required Library files:
  - stm32f10x_gpio.c 
  - stm32f10x_rcc.c 
  - stm32f10x_tim.c  
  - misc.c
  - system_stm32f10x.c     


@note
 - Low-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 16 and 32 Kbytes.
 - Medium-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 32 and 128 Kbytes.
 - High-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 256 and 512 Kbytes.
   
 * <h3><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h3>
 */
