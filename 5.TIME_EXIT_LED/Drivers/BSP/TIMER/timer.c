#include "./BSP/TIMER/timer.h"
#include "./BSP/LED/led.h"

TIM_HandleTypeDef g_timx_handle;
//zdcsh//
void btim_timx_int_init(uint16_t arr,uint16_t psc)
{	
	g_timx_handle.Instance=TIM3;
	g_timx_handle.Init.Prescaler=psc;
	g_timx_handle.Init.Period=arr;
	HAL_TIM_Base_Init(&g_timx_handle);
	
	HAL_TIM_Base_Start_IT(&g_timx_handle);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM3)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();
		HAL_NVIC_SetPriority(TIM3_IRQn,1,3);
		HAL_NVIC_EnableIRQ(TIM3_IRQn);
	}
	
}

void  TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&g_timx_handle);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM3)
	{
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
	}
	
}



