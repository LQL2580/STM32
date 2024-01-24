/**
 ****************************************************************************************************
 * @file        usart.c
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-20
 * @brief       ���ڳ�ʼ������(һ���Ǵ���1)��֧��printf
 * @license     Copyright (c) 2020-2032, ������������ӿƼ����޹�˾
 ****************************************************************************************************
 * @attention
 *
 * ʵ��ƽ̨:����ԭ�� STM32F103������
 * ������Ƶ:www.yuanzige.com
 * ������̳:www.openedv.com
 * ��˾��ַ:www.alientek.com
 * �����ַ:openedv.taobao.com
 *
 * �޸�˵��
 * V1.0 20211103
 * ��һ�η���
 *
 ****************************************************************************************************
 */



#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"

#define UART_NVIC_ENABLE 0

uint8_t g_usart1_rx_flag;
uint8_t g_rx_buffer[1];  /* HAL��ʹ�õĴ��ڽ��ջ��� */
//uint8_t g_rx_buffer[1];  /* HAL��ʹ�õĴ��ڽ��ջ��� */

//uint8_t g_rx_buffer[1];  /* HAL��ʹ�õĴ��ڽ��ջ��� */

UART_HandleTypeDef g_uart1_handle;  /* UART��� */


void usart_init(uint32_t baudrate)
{
    /*UART ��ʼ������*/
    g_uart1_handle.Instance = USART1;                                       /* USART_UX */
    g_uart1_handle.Init.BaudRate = baudrate;                                  /* ������ */
    g_uart1_handle.Init.WordLength = UART_WORDLENGTH_8B;                      /* �ֳ�Ϊ8λ���ݸ�ʽ */
    g_uart1_handle.Init.StopBits = UART_STOPBITS_1;                           /* һ��ֹͣλ */
    g_uart1_handle.Init.Parity = UART_PARITY_NONE;                            /* ����żУ��λ */
    g_uart1_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;                      /* ��Ӳ������ */
    g_uart1_handle.Init.Mode = UART_MODE_TX_RX;                               /* �շ�ģʽ */
    HAL_UART_Init(&g_uart1_handle);                                           /* HAL_UART_Init()��ʹ��UART1 */

}

/**
 * @brief       UART�ײ��ʼ������
 * @param       huart: UART�������ָ��
 * @note        �˺����ᱻHAL_UART_Init()����
 *              ���ʱ��ʹ�ܣ��������ã��ж�����
 * @retval      ��
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef gpio_init_struct={0};

    if (huart->Instance == USART1)                            /* ����Ǵ���1�����д���1 MSP��ʼ�� */
    {
       __HAL_RCC_USART1_CLK_ENABLE();
			 __HAL_RCC_GPIOA_CLK_ENABLE();
			
			
		gpio_init_struct.Pin= GPIO_PIN_9;
		gpio_init_struct.Mode= GPIO_MODE_AF_PP;  
		gpio_init_struct.Pull= GPIO_NOPULL;
		gpio_init_struct.Speed= GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&gpio_init_struct);
			
		gpio_init_struct.Pin= GPIO_PIN_10;
		gpio_init_struct.Mode= GPIO_MODE_AF_INPUT;  
		gpio_init_struct.Pull=GPIO_PULLUP; 
		gpio_init_struct.Speed= GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&gpio_init_struct);

			
    }
		
}










