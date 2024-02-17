#include "startup_main.h"
#include "bsp_delay.h"
#include "usart.h"

extern uint8_t rx_buffer[1];

void startup_main(void)
{
	bsp_delay.f1.Init(72);
  HAL_UART_Receive_IT(&huart1,rx_buffer,1);
	
#if isRTOS==0    	//如果是裸机开发
	for(;;)  //等同于while(true)
	{
		

	}
#endif
}