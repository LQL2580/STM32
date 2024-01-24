#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/XUNJI/xunji.h"
#include "./BSP/TIMER/gtim.h"


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
			
		  delay_ms(10);
		
    }
}




