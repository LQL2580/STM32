#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/XUNJI/xunji.h"

//uint8_t g_rx_buffer[1];
//extern UART_HandleTypeDef g_uart1_handle;  /* UART��� */
//extern uint8_t g_usart1_rx_flag ;
//uint8_t g_rx_buffer[1];  /* HAL��ʹ�õĴ��ڽ��ջ��� */

int main(void)
{
    HAL_Init();                              /* ��ʼ��HAL�� */
    SystemClock_Config();      /* ����ʱ��, 72Mhz */
    delay_init(72);                          /* ��ʱ��ʼ�� */
    led_init();                              /* LED��ʼ�� */
    xunji_init();                              /* XUNJI��ʼ�� */
	  usart_init(115200);   
	
	
	
	printf("???????:\r\n");
    while(1)
    { 
		
			*g_rx_buffer = 10;
		
				delay_ms(10);
				
    }
}




