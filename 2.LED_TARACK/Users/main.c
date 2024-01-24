#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/XUNJI/xunji.h"
UART_HandleTypeDef g_uart1_handle;  /* UART句柄 */

int main(void)
{
    HAL_Init();                              /* 初始化HAL库 */
    SystemClock_Config();      /* 设置时钟, 72Mhz */
    delay_init(72);                          /* 延时初始化 */
    led_init();                              /* LED初始化 */
    xunji_init();                              /* XUNJI初始化 */
	  usart_init(115200);   
    while(1)
    { 
		
			
			if(xunji_scan())
			{
				if(g_usart1_rx_flag==1)
				{
						HAL_UART_Transmit(&g_uart1_handle,(uint8_t*)g_rx_buffer,1,1000);
					
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);
				}
				
			}
      else 
			{
				HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
			}
    }
}

