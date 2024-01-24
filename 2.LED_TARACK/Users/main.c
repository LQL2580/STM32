#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/XUNJI/xunji.h"
UART_HandleTypeDef g_uart1_handle;  /* UART��� */

int main(void)
{
    HAL_Init();                              /* ��ʼ��HAL�� */
    SystemClock_Config();      /* ����ʱ��, 72Mhz */
    delay_init(72);                          /* ��ʱ��ʼ�� */
    led_init();                              /* LED��ʼ�� */
    xunji_init();                              /* XUNJI��ʼ�� */
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

