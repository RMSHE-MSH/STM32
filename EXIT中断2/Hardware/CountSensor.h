#ifndef __COUNTSENSOR_H__
#define __COUNTSENSOR_H__
//中断信号 -> GPIO -> AFIO -> EXIT -> NVIC -> CPU;

#include <stdint.h>
#include "stm32f10x.h"


/*
这里根据您使用的GPIO_Pin来选择外部中断线对应的中断函数;
EXTI Line 15..10      EXTI15_10_IRQHandler
EXTI Line 9..5        EXTI9_5_IRQHandler
EXTI Line 0           EXTI0_IRQHandler
EXTI Line 1           EXTI1_IRQHandler
EXTI Line 2           EXTI2_IRQHandler
EXTI Line 3           EXTI3_IRQHandler

例1: GPIO_Pin_13 对应 EXTI Line 15..10 应将下方改为: #define COUNT_SENSOR_IRQHandler EXTI15_10_IRQHandler
例2: GPIO_Pin_1 对应 EXTI Line 1 应将下方改为: #define COUNT_SENSOR_IRQHandler EXTI1_IRQHandler
*/
#define COUNT_SENSOR_IRQHandler EXTI1_IRQHandler    //中断函数(中断函数的名字是由STM32汇编启动程序指定的,不可更改)


//初始化连接LED的Pin口(GPIOx, GPIO_Pin, EXTI_Trigger = 默认下降沿触发中断, NVIC_PriorityGroup = 默认为2位抢占2位响应);
void Sensor_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, EXTITrigger_TypeDef EXTI_Trigger, uint32_t _NVIC_PriorityGroup);

 //获取传感器计数次数;
uint16_t CountSensor_Get();


#endif