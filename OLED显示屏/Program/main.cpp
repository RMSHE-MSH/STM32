#include "stm32f10x.h"
#include "Delay.h"
#include "GPIO.h"
#include "OLED.h"

GPIO PA8,PA3;

int main(void){
    OLED_Init();
    
    OLED_ShowString(1,2, "HelloWorld!");
    while(true){
    }
}