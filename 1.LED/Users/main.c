
#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

#include "./BSP/LED/led.h"
                     

int main(void)
{
    HAL_Init();     	/* 初始化HAL库 */

    sys_stm32_clock_init(RCC_PLL_MUL9);     /* 设置时钟, 72Mhz */
 
    SystemClock_Config();       /* 延时初始化 */
	
    led_init();     /* LED初始化 */
	
    while(1)
    { 
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2, GPIO_PIN_SET);   
			/* PB5置1 */         
        delay_ms(200);
			
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2, GPIO_PIN_RESET);
			/* PB5置0 */       
        delay_ms(200); 
			//HAL_GPIO_TogglePin(GPIOB,RTC_OUTPUT_REMAP_PC13);
			//delay_ms(500); 
    }
}



