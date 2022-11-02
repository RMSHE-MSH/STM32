#include <stdint.h>
#include "stm32f10x.h"

#ifndef __GPIO_H__
#define __GPIO_H__

class GPIO{
private:
    GPIO_TypeDef* GPIOX;
    uint16_t GPIO_PIN;
    uint32_t RCC_APB2Periph;

    GPIO_InitTypeDef GPIO_InitStruct;   //定义GPIO初始化结构体;
public:
    //初始化GPIO口(GPIOx, GPIO_Pin, GPIO_Mode = 默认推挽输出, GPIO_Speed = 默认50MHz);
    void GPIO_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef GPIO_Mode = GPIO_Mode_Out_PP, GPIOSpeed_TypeDef GPIO_Speed = GPIO_Speed_50MHz);

    //设置GPIO_Pin口的电平,默认低电平(Set_PIN_ElectricalLevel = 0 or 1);
    void GPIO_SetPin(bool Set_PIN_ElectricalLevel = false);

    //获取GPIO_Pin口的电平状态(低电平返回0);
    uint8_t GPIO_GetPinState();
};

#endif