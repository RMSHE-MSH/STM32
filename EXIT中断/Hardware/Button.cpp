#include "Button.h"

void BUTTON::Button_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
    //GPIO信息送入类属性;
    GPIOX = GPIOx;
    GPIO_PIN = GPIO_Pin;
    
    //根据选择的GPIO开启对应的时钟;
    if (GPIOX == GPIOA) RCC_APB2Periph = RCC_APB2Periph_GPIOA;
    if (GPIOX == GPIOB) RCC_APB2Periph = RCC_APB2Periph_GPIOB;
    if (GPIOX == GPIOC) RCC_APB2Periph = RCC_APB2Periph_GPIOC;
    if (GPIOX == GPIOD) RCC_APB2Periph = RCC_APB2Periph_GPIOD;
    if (GPIOX == GPIOE) RCC_APB2Periph = RCC_APB2Periph_GPIOE;
    if (GPIOX == GPIOF) RCC_APB2Periph = RCC_APB2Periph_GPIOF;
    if (GPIOX == GPIOG) RCC_APB2Periph = RCC_APB2Periph_GPIOG;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);
    
    //初始化对应的GPIO_pin;
    
    GPIO_InitTypeDef GPIO_InitStruct;               //定义GPIO初始化结构体;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;      //GPIO设为上拉输入模式(读取按键);
    GPIO_InitStruct.GPIO_Pin = GPIO_PIN;            //指定输入的Pin口;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;  //设置GPIO速度(输入模式下无效);
    
    GPIO_Init(GPIOX, &GPIO_InitStruct);             //初始化GPIO;
}

bool BUTTON::Button_GetState(bool Refer_ElectricalLevel){
    //当按钮按下后抬起,返回true;
    if(GPIO_ReadInputDataBit(GPIOX, GPIO_PIN) == Refer_ElectricalLevel){
        Delay_ms(20);//延时20ms消抖;
        while(GPIO_ReadInputDataBit(GPIOX, GPIO_PIN) == Refer_ElectricalLevel);
        Delay_ms(20);//延时20ms消抖;
        
        return true;
    }
    return false;
}