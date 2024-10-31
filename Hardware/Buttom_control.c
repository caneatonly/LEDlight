# include "stm32f10x.h"
#include "Buttom_control.h"

void Buttom_Init(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void Buttom_read(void)
{
    static uint8_t button0_state = 0;
    static uint8_t button1_state = 0;

    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
    {
        // Debounce delay
        for (volatile int i = 0; i < 10000; i++);
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
        {
            button0_state = !button0_state;
            if (button0_state)
            {
                GPIO_SetBits(GPIOA, GPIO_Pin_0);
            }
            else
            {
                GPIO_ResetBits(GPIOA, GPIO_Pin_0);
            }
            // Wait for button release
            while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0);
        }
    }

    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
    {
        // Debounce delay
        for (volatile int i = 0; i < 10000; i++);
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
        {
            button1_state = !button1_state;
            if (button1_state)
            {
                GPIO_SetBits(GPIOA, GPIO_Pin_1);
            }
            else
            {
                GPIO_ResetBits(GPIOA, GPIO_Pin_1);
            }
            // Wait for button release
            while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0);
        }
    }
}
