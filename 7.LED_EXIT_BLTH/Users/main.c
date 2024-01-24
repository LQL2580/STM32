#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/XUNJI/xunji.h"
#include "./BSP/TIMER/gtim.h"


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
			
		  delay_ms(10);
		
    }
}




