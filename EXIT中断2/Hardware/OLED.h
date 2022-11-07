#include <stdint.h>
#include "OLED_Font.h"
#include "stm32f10x.h"

#ifndef __OLED_H__
#define __OLED_H__

class OLED{
private:
    GPIO_TypeDef* GPIOx;
    uint16_t SCL, SDA;
    uint32_t RCC_APB2Periph;
    GPIO_InitTypeDef GPIO_InitStructure;
private:
    void OLED_I2C_Init(void);
    void OLED_W_SCL(int x);
    void OLED_W_SDA(int x);
    void OLED_I2C_Start(void);
    void OLED_I2C_Stop(void);
    void OLED_I2C_SendByte(uint8_t Byte);
    void OLED_WriteCommand(uint8_t Command);
    void OLED_WriteData(uint8_t Data);
    void OLED_SetCursor(uint8_t Y, uint8_t X);
    uint32_t OLED_Pow(uint32_t X, uint32_t Y);
public:
    void OLED_Init(GPIO_TypeDef* GPIOX, uint16_t GPIO_Pin_SCL,uint16_t GPIO_Pin_SDA);
    void OLED_Clear(void);
    void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
    void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
    void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
    void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
    void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
    void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
};

#endif
