#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"

#ifndef __BUTTON_H__
#define __BUTTON_H__

class BUTTON{
private:
    GPIO_TypeDef* GPIOX;
    uint16_t GPIO_PIN;
    uint32_t RCC_APB2Periph;
public:
    //初始化连接按键的Pin口(GPIOx, GPIO_Pin);
    void Button_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

    //获取按键状态,当按键按下后抬起函数返回true;
    bool Button_GetState(bool Refer_ElectricalLevel = 1);
    //Refer_ElectricalLevel(参考电平);
    //按键一端(A)连接GPIO_PIN,令一端(B)接低电平或高电平;
    //(B)的电平状态则为这里参考电平的值;
};

#endif