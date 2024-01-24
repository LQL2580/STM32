#include "./BSP/LED/led.h"

void led_init(void)
{

    GPIO_InitTypeDef gpio_init_led={0};
	
		__HAL_RCC_GPIOC_CLK_ENABLE();
	
		gpio_init_led.Pin= GPIO_PIN_13;
		gpio_init_led.Mode= GPIO_MODE_OUTPUT_PP;
		gpio_init_led.Pull= GPIO_NOPULL;
		gpio_init_led.Speed= GPIO_SPEED_FREQ_LOW;
	
		HAL_GPIO_Init(GPIOC, &gpio_init_led);
	
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
 //HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);		

}


