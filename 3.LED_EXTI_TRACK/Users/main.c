#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/ZHONGDUAN/zhongduan.h"

int main(void)
{
    HAL_Init();                              /* ��ʼ��HAL�� */
    SystemClock_Config();      /* ����ʱ��, 72Mhz */
    delay_init(72);                          /* ��ʱ��ʼ�� */
       led_init();                      
                             
	  exit_init();

    while(1)
    { 
			
			
		    //HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
    		
    }
}

