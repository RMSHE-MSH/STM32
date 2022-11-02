#include "stm32f10x.h"
#include "Delay.h"
#include "GPIO.h"

GPIO PA8,PA3;

int main(void){
    PA8.GPIO_init(GPIOA,GPIO_Pin_8);
    PA3.GPIO_init(GPIOA,GPIO_Pin_3);
    
    while(true){
        PA8.GPIO_SetPin(0);
        PA3.GPIO_SetPin(1);
        Delay_ms(1000);
        
        PA8.GPIO_SetPin(1);
        PA3.GPIO_SetPin(0);
        Delay_ms(100);   
    }
}