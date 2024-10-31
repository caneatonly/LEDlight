# include "stm32f10x.h"
# include "Delay.h"
# include "LED_control.h"
# include "Buttom_control.h"
//
int main(void)
{
  LED_Init();
  Buttom_Init();
  
  while (1)
  {
    Buttom_read();
  }

}
