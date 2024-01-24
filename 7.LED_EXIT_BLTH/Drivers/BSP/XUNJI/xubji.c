#include "./BSP/XUNJI/xunji.h"
#include "./SYSTEM/delay/delay.h"

void xunji_init(void)
{

    GPIO_InitTypeDef gpio_init_xunji={0};
	
		__HAL_RCC_GPIOA_CLK_ENABLE();
	
		gpio_init_xunji.Pin= GPIO_PIN_8;
		gpio_init_xunji.Mode= GPIO_MODE_INPUT;
		gpio_init_xunji.Pull= GPIO_PULLUP ;
	
		HAL_GPIO_Init(GPIOA, &gpio_init_xunji);

}
uint8_t xunji_scan(void)
{
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8)==0)
	{
		delay_ms(10);
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8)==0)
		{
			return 1;
		}
	
	}
	return 0;
	
}
