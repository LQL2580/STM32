#include "./BSP/TIMER/gtim.h"
#include "./SYSTEM/sys/sys.h"


TIM_HandleTypeDef g_timx_pwm_chy_handle;
/*输出初始化*/
void gtim_timx_pwm_chy_init(uint16_t arr,uint16_t psc)
{
	  TIM_OC_InitTypeDef timx_oc_pwm_chy = {0};
	
		g_timx_pwm_chy_handle.Instance = TIM2;
		g_timx_pwm_chy_handle.Init.Prescaler = psc;
		g_timx_pwm_chy_handle.Init.Period = arr;
		g_timx_pwm_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP ;
	
		HAL_TIM_PWM_Init(&g_timx_pwm_chy_handle);
		
		timx_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;
		timx_oc_pwm_chy.Pulse = arr / 2;
		timx_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_LOW;
		HAL_TIM_PWM_ConfigChannel(&g_timx_pwm_chy_handle,&timx_oc_pwm_chy,TIM_CHANNEL_3);
	
		HAL_TIM_PWM_Start(&g_timx_pwm_chy_handle,TIM_CHANNEL_3);


}
/*msp初始化*/
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
		if(htim->Instance == TIM2)
		{	
			GPIO_InitTypeDef gpio_init_struct={0};
			
			__HAL_RCC_GPIOB_CLK_ENABLE();
			__HAL_RCC_TIM2_CLK_ENABLE();
			
			gpio_init_struct.Pin = GPIO_PIN_10;
			gpio_init_struct.Mode = GPIO_MODE_AF_PP;
			gpio_init_struct.Pull = GPIO_PULLUP;
			gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH ;
			
			HAL_GPIO_Init(GPIOB,&gpio_init_struct);
			
			__HAL_RCC_AFIO_CLK_ENABLE();
			__HAL_AFIO_REMAP_TIM2_PARTIAL_2();
		
		}
		
}

