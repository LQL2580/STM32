
#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

#include "./BSP/LED/led.h"
                     

int main(void)
{
    HAL_Init();     	/* ��ʼ��HAL�� */

    sys_stm32_clock_init(RCC_PLL_MUL9);     /* ����ʱ��, 72Mhz */
 
    SystemClock_Config();       /* ��ʱ��ʼ�� */
	
    led_init();     /* LED��ʼ�� */
	
    while(1)
    { 
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2, GPIO_PIN_SET);   
			/* PB5��1 */         
        delay_ms(200);
			
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2, GPIO_PIN_RESET);
			/* PB5��0 */       
        delay_ms(200); 
			//HAL_GPIO_TogglePin(GPIOB,RTC_OUTPUT_REMAP_PC13);
			//delay_ms(500); 
    }
}



