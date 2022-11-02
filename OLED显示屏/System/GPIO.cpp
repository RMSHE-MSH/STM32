#include "GPIO.h"

void GPIO::GPIO_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef GPIO_Mode, GPIOSpeed_TypeDef GPIO_Speed){
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
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode;    //GPIO设为推挽输出模式;
    GPIO_InitStruct.GPIO_Pin = GPIO_PIN;      //指定连接LED的Pin口;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed;  //设置GPIO速度;
    
    GPIO_Init(GPIOX, &GPIO_InitStruct);       //初始化GPIO;
}

void GPIO::GPIO_SetPin(bool Set_PIN_ElectricalLevel){
    //设置GPIO电平;
    if (Set_PIN_ElectricalLevel == true) GPIO_SetBits(GPIOX, GPIO_PIN); else GPIO_ResetBits(GPIOX, GPIO_PIN); 
}

uint8_t GPIO::GPIO_GetPinState(){return GPIO_ReadOutputDataBit(GPIOX, GPIO_PIN);};//读取输出寄存器位电平状态;