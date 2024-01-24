#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/XUNJI/xunji.h"

//uint8_t g_rx_buffer[1];
//extern UART_HandleTypeDef g_uart1_handle;  /* UART句柄 */
//extern uint8_t g_usart1_rx_flag ;
//uint8_t g_rx_buffer[1];  /* HAL库使用的串口接收缓冲 */

int main(void)
{
    HAL_Init();                              /* 初始化HAL库 */
    SystemClock_Config();      /* 设置时钟, 72Mhz */
    delay_init(72);                          /* 延时初始化 */
    led_init();                              /* LED初始化 */
    xunji_init();                              /* XUNJI初始化 */
	  usart_init(115200);   
	
	
	
	printf("???????:\r\n");
    while(1)
    { 
		
			*g_rx_buffer = 10;
		
				delay_ms(10);
				
    }
}




