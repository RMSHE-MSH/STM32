#include "CountSensor.h"
uint16_t CountSensor_Count;


//初始化GPIO;
void GPIO_init(GPIO_TypeDef* GPIOX, uint16_t GPIO_PIN){
    uint32_t RCC_APB2Periph;
    
    //根据选择的GPIO开启对应的时钟;
    if (GPIOX == GPIOA) RCC_APB2Periph = RCC_APB2Periph_GPIOA;
    if (GPIOX == GPIOB) RCC_APB2Periph = RCC_APB2Periph_GPIOB;
    if (GPIOX == GPIOC) RCC_APB2Periph = RCC_APB2Periph_GPIOC;
    if (GPIOX == GPIOD) RCC_APB2Periph = RCC_APB2Periph_GPIOD;
    if (GPIOX == GPIOE) RCC_APB2Periph = RCC_APB2Periph_GPIOE;
    if (GPIOX == GPIOF) RCC_APB2Periph = RCC_APB2Periph_GPIOF;
    if (GPIOX == GPIOG) RCC_APB2Periph = RCC_APB2Periph_GPIOG;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph | RCC_APB2Periph_AFIO, ENABLE);//开启GPIO与AFIO时钟;
    
    //初始化对应的GPIO_pin;
    GPIO_InitTypeDef GPIO_InitStruct;                   //定义GPIO初始化结构体;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;  //设置GPIO模式为浮空输入;
    GPIO_InitStruct.GPIO_Pin = GPIO_PIN;                //指定连接LED的Pin口;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;      //设置GPIO速度;
    
    GPIO_Init(GPIOX, &GPIO_InitStruct);                 //初始化GPIO;
}

//初始化AFIO;
void AFIO_init(GPIO_TypeDef* GPIOX, uint16_t GPIO_PIN){
    uint8_t GPIO_PortSource, GPIO_PinSource;
    
    //选择输入AFIO的GPIO组;
    if (GPIOX == GPIOA) GPIO_PortSource = GPIO_PortSourceGPIOA;
    if (GPIOX == GPIOB) GPIO_PortSource = GPIO_PortSourceGPIOB;
    if (GPIOX == GPIOC) GPIO_PortSource = GPIO_PortSourceGPIOC;
    if (GPIOX == GPIOD) GPIO_PortSource = GPIO_PortSourceGPIOD;
    if (GPIOX == GPIOE) GPIO_PortSource = GPIO_PortSourceGPIOE;
    if (GPIOX == GPIOF) GPIO_PortSource = GPIO_PortSourceGPIOF;
    if (GPIOX == GPIOG) GPIO_PortSource = GPIO_PortSourceGPIOG;
    
    //选择输入AFIO的GPIO_Pin;
    if (GPIO_PIN == GPIO_Pin_0) GPIO_PinSource = GPIO_PinSource0;
    if (GPIO_PIN == GPIO_Pin_1) GPIO_PinSource = GPIO_PinSource1;
    if (GPIO_PIN == GPIO_Pin_2) GPIO_PinSource = GPIO_PinSource2;
    if (GPIO_PIN == GPIO_Pin_3) GPIO_PinSource = GPIO_PinSource3;
    if (GPIO_PIN == GPIO_Pin_4) GPIO_PinSource = GPIO_PinSource4;
    if (GPIO_PIN == GPIO_Pin_5) GPIO_PinSource = GPIO_PinSource5;
    if (GPIO_PIN == GPIO_Pin_6) GPIO_PinSource = GPIO_PinSource6;
    if (GPIO_PIN == GPIO_Pin_7) GPIO_PinSource = GPIO_PinSource7;
    if (GPIO_PIN == GPIO_Pin_8) GPIO_PinSource = GPIO_PinSource8;
    if (GPIO_PIN == GPIO_Pin_9) GPIO_PinSource = GPIO_PinSource9;
    if (GPIO_PIN == GPIO_Pin_10) GPIO_PinSource = GPIO_PinSource10;
    if (GPIO_PIN == GPIO_Pin_11) GPIO_PinSource = GPIO_PinSource11;
    if (GPIO_PIN == GPIO_Pin_12) GPIO_PinSource = GPIO_PinSource12;
    if (GPIO_PIN == GPIO_Pin_13) GPIO_PinSource = GPIO_PinSource13;
    if (GPIO_PIN == GPIO_Pin_14) GPIO_PinSource = GPIO_PinSource14;
    if (GPIO_PIN == GPIO_Pin_15) GPIO_PinSource = GPIO_PinSource15;
    
    //设置GPIO_Pin中断线(AFIO设置中断输入引脚);
    GPIO_EXTILineConfig(GPIO_PortSource, GPIO_PinSource);   
}

//初始化EXTI;
EXTI_InitTypeDef EXTI_InitStruct;//EXTI初始化结构体;
void EXTI_init(uint16_t GPIO_PIN,  EXTITrigger_TypeDef EXTI_Trigger){
    //选择输入EXTI的外部中断线;
    if (GPIO_PIN == GPIO_Pin_0) EXTI_InitStruct.EXTI_Line = EXTI_Line0;
    if (GPIO_PIN == GPIO_Pin_1) EXTI_InitStruct.EXTI_Line = EXTI_Line1;
    if (GPIO_PIN == GPIO_Pin_2) EXTI_InitStruct.EXTI_Line = EXTI_Line2;
    if (GPIO_PIN == GPIO_Pin_3) EXTI_InitStruct.EXTI_Line = EXTI_Line3;
    if (GPIO_PIN == GPIO_Pin_4) EXTI_InitStruct.EXTI_Line = EXTI_Line4;
    if (GPIO_PIN == GPIO_Pin_5) EXTI_InitStruct.EXTI_Line = EXTI_Line5;
    if (GPIO_PIN == GPIO_Pin_6) EXTI_InitStruct.EXTI_Line = EXTI_Line6;
    if (GPIO_PIN == GPIO_Pin_7) EXTI_InitStruct.EXTI_Line = EXTI_Line7;
    if (GPIO_PIN == GPIO_Pin_8) EXTI_InitStruct.EXTI_Line = EXTI_Line8;
    if (GPIO_PIN == GPIO_Pin_9) EXTI_InitStruct.EXTI_Line = EXTI_Line9;
    if (GPIO_PIN == GPIO_Pin_10) EXTI_InitStruct.EXTI_Line = EXTI_Line10;
    if (GPIO_PIN == GPIO_Pin_11) EXTI_InitStruct.EXTI_Line = EXTI_Line11;
    if (GPIO_PIN == GPIO_Pin_12) EXTI_InitStruct.EXTI_Line = EXTI_Line12;
    if (GPIO_PIN == GPIO_Pin_13) EXTI_InitStruct.EXTI_Line = EXTI_Line13;
    if (GPIO_PIN == GPIO_Pin_14) EXTI_InitStruct.EXTI_Line = EXTI_Line14;
    if (GPIO_PIN == GPIO_Pin_15) EXTI_InitStruct.EXTI_Line = EXTI_Line15;

    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;    //设置EXTI_Mode为中断模式;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger;        //EXIT对应中断线(GPIO_Pin)触发方式(默认下降沿触发);
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;              //EXIT(外部)中断使能;
    
    EXTI_Init(&EXTI_InitStruct);                        //初始化EXTI;
}

//初始化NVIC;
void NVIC_init(uint16_t GPIO_PIN, uint32_t _NVIC_PriorityGroup){
    uint32_t NVIC_PriorityGroup;                //NVIC_PriorityGroup_2: 默认为2位抢占2位响应
    NVIC_InitTypeDef NVIC_InitStruct;           //NVIC初始化结构体;
    
    
    //设置NVIC分组(默认为2位抢占2位响应)(注意芯片只能设置一种全局分组);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup);   
    
    //选择外部中断通道;
    uint8_t NVIC_IRQChannel;
    if (GPIO_PIN == GPIO_Pin_0) NVIC_IRQChannel = EXTI0_IRQn;
    if (GPIO_PIN == GPIO_Pin_1) NVIC_IRQChannel = EXTI1_IRQn;
    if (GPIO_PIN == GPIO_Pin_2) NVIC_IRQChannel = EXTI2_IRQn;
    if (GPIO_PIN == GPIO_Pin_3) NVIC_IRQChannel = EXTI3_IRQn;
    if (GPIO_PIN == GPIO_Pin_4) NVIC_IRQChannel = EXTI4_IRQn;
    if (GPIO_PIN == GPIO_Pin_5) NVIC_IRQChannel = EXTI9_5_IRQn;
    if (GPIO_PIN == GPIO_Pin_6) NVIC_IRQChannel = EXTI9_5_IRQn;
    if (GPIO_PIN == GPIO_Pin_7) NVIC_IRQChannel = EXTI9_5_IRQn;
    if (GPIO_PIN == GPIO_Pin_8) NVIC_IRQChannel = EXTI9_5_IRQn;
    if (GPIO_PIN == GPIO_Pin_9) NVIC_IRQChannel = EXTI9_5_IRQn;
    if (GPIO_PIN == GPIO_Pin_10) NVIC_IRQChannel = EXTI15_10_IRQn;
    if (GPIO_PIN == GPIO_Pin_11) NVIC_IRQChannel = EXTI15_10_IRQn;
    if (GPIO_PIN == GPIO_Pin_12) NVIC_IRQChannel = EXTI15_10_IRQn;
    if (GPIO_PIN == GPIO_Pin_13) NVIC_IRQChannel = EXTI15_10_IRQn;
    if (GPIO_PIN == GPIO_Pin_14) NVIC_IRQChannel = EXTI15_10_IRQn;
    if (GPIO_PIN == GPIO_Pin_15) NVIC_IRQChannel = EXTI15_10_IRQn;
    
    NVIC_InitStruct.NVIC_IRQChannel = NVIC_IRQChannel;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;  //指定抢占优先级(默认为1);
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;         //指定响应优先级(默认为1);
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;            //中断通道使能;
    
    NVIC_Init(&NVIC_InitStruct);                            //初始化NVIC;
}

//初始化连接LED的Pin口(GPIOx, GPIO_Pin, EXTI_Trigger = 默认下降沿触发中断, NVIC_PriorityGroup = 默认为2位抢占2位响应);
void Sensor_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, EXTITrigger_TypeDef EXTI_Trigger, uint32_t _NVIC_PriorityGroup){
    GPIO_init(GPIOx, GPIO_Pin); 
    AFIO_init(GPIOx, GPIO_Pin);
    EXTI_init(GPIO_Pin,EXTI_Trigger);
    NVIC_init(GPIO_Pin, _NVIC_PriorityGroup);
}

//获取传感器计数次数;
uint16_t CountSensor_Get(){return CountSensor_Count;}

//中断函数;
void COUNT_SENSOR_IRQHandler(void){
    //中断标志位判断(判断中断信号是否是指定引脚发出,是则清空中断标志位);
    if (EXTI_GetITStatus(EXTI_InitStruct.EXTI_Line) != RESET) {
        ++CountSensor_Count;
        EXTI_ClearITPendingBit(EXTI_InitStruct.EXTI_Line);//清空中断标志位;
    }
}