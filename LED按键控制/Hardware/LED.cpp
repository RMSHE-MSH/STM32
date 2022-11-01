#include "LED.h"

void LED::LED_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
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
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;   //GPIO设为推挽输出模式;
    GPIO_InitStruct.GPIO_Pin = GPIO_PIN;            //指定连接LED的Pin口;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;  //设置GPIO速度;
    
    GPIO_Init(GPIOX, &GPIO_InitStruct);             //初始化GPIO;
}

void LED::LED_Set(bool Set_PIN_ElectricalLevel){
    //设置连接LED的GPIO电平;
    if (Set_PIN_ElectricalLevel == true) GPIO_SetBits(GPIOX, GPIO_PIN); else GPIO_ResetBits(GPIOX, GPIO_PIN); 
}

uint8_t LED::LED_GetState(){return GPIO_ReadOutputDataBit(GPIOX, GPIO_PIN);};