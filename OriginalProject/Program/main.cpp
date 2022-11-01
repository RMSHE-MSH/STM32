#include "stm32f10x.h"                  // Device header

void delay_us(uint32_t delay_us){
  volatile unsigned int num;
  volatile unsigned int t;

  for (num = 0; num < delay_us; num++){
    t = 11;
    while (t != 0)t--;
  }
}
void delay_ms(uint16_t delay_ms){
  volatile unsigned int num;
  for (num = 0; num < delay_ms; num++){
    delay_us(1000);
  }
}


int main(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    
    GPIO_Init(GPIOC, &GPIO_InitStruct);
    
    while(true){
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        delay_ms(1000);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delay_ms(1000);
    }
    
}