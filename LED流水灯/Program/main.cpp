#include "stm32f10x.h"
#include "Delay.h"

int main(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;   //GPIO设为推挽输出模式;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_All;        //设置所有Pin口为推挽输出;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;  //设置GPIO速度;
    
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    int time = 100;
    while(true){
        GPIO_Write(GPIOA, ~0x0001);  //"~0x0001": 按位取反(因为LED是低电平点亮);
        Delay_ms(time);
        GPIO_Write(GPIOA, ~0x0002);
        Delay_ms(time);
        GPIO_Write(GPIOA, ~0x0004);
        Delay_ms(time);
        GPIO_Write(GPIOA, ~0x0008);
        Delay_ms(time);
        GPIO_Write(GPIOA, ~0x0010);
        Delay_ms(time);
        GPIO_Write(GPIOA, ~0x0020);
        Delay_ms(time);
        GPIO_Write(GPIOA, ~0x0040);
        Delay_ms(time);
        GPIO_Write(GPIOA, ~0x0080);
        Delay_ms(time);
        GPIO_Write(GPIOA, ~0x0100);
        Delay_ms(time);
    }
    
}