#include "stm32f10x.h"
#include "Delay.h"
#include "GPIO.h"
#include "OLED.h"
#include "bsp_led.h"
extern "C"{
#include "EXIT_it.h"
}

OLED S1;

int main(void){
    LED_GPIO_Config();

    S1.OLED_Init(GPIOB,GPIO_Pin_8,GPIO_Pin_9);
    EXIT_it_init(GPIOA, GPIO_Pin_1, EXTI_Trigger_Falling, NVIC_PriorityGroup_2);
    

    S1.OLED_ShowString(1,2, "Count:");
    while(true){
        
    }
}