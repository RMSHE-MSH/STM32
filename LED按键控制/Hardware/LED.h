#include <stdint.h>
#include "stm32f10x.h"

#ifndef __LED_H__
#define __LED_H__

class LED{
private:
    GPIO_TypeDef* GPIOX;
    uint16_t GPIO_PIN;
    uint32_t RCC_APB2Periph;
public:
    //初始化连接LED的Pin口(GPIOx, GPIO_Pin);
    void LED_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

    //设置连接LED的Pin口的电平(Set_PIN_ElectricalLevel = 0 or 1);
    void LED_Set(bool Set_PIN_ElectricalLevel = false);

    //获取连接LED的Pin口的状态;
    uint8_t LED_GetState();
};

#endif