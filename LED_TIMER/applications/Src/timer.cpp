#include "timer.h"
#include "tim.h"

void  TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htim3);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM3)
	{
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
	}
	
}