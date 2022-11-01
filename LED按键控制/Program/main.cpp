#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "Button.h"

LED L0,L1;
BUTTON K0;

int main(void){
    L0.LED_init(GPIOA, GPIO_Pin_3);
    L1.LED_init(GPIOA, GPIO_Pin_2);
    
    K0.Button_init(GPIOC,GPIO_Pin_13);
    
    while(true){
        if(K0.Button_GetState() == true) {
            if(L0.LED_GetState() == 0) L0.LED_Set(1); else L0.LED_Set(0);
        }
    }
}