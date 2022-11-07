#include "stm32f10x.h"
#include "Delay.h"
#include "GPIO.h"
#include "OLED.h"

OLED S1;
GPIO PA8,PA3;

int main(void){
    S1.OLED_Init(GPIOB,GPIO_Pin_8,GPIO_Pin_9);
    
    S1.OLED_ShowString(1,2, "RMSHE");
    while(true){
    }
}