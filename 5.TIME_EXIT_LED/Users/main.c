#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/TIMER/timer.h"


int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
    SystemClock_Config();   /* 设置时钟, 72Mhz */
    delay_init(72);                     /* 延时初始化 */
    led_init();                         /* LED初始化 */
	  btim_timx_int_init(2000-1,7200-1);
    while(1)
    { 
				
    }
}



