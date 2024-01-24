/**
 ****************************************************************************************************
 * @file        usart.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-20
 * @brief       串口初始化代码(一般是串口1)，支持printf
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 STM32F103开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 * 修改说明
 * V1.0 20211103
 * 第一次发布
 *
 ****************************************************************************************************
 */



#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"

#define UART_NVIC_ENABLE 0

uint8_t g_usart1_rx_flag;
uint8_t g_rx_buffer[1];  /* HAL库使用的串口接收缓冲 */
//uint8_t g_rx_buffer[1];  /* HAL库使用的串口接收缓冲 */

//uint8_t g_rx_buffer[1];  /* HAL库使用的串口接收缓冲 */

UART_HandleTypeDef g_uart1_handle;  /* UART句柄 */


void usart_init(uint32_t baudrate)
{
    /*UART 初始化设置*/
    g_uart1_handle.Instance = USART1;                                       /* USART_UX */
    g_uart1_handle.Init.BaudRate = baudrate;                                  /* 波特率 */
    g_uart1_handle.Init.WordLength = UART_WORDLENGTH_8B;                      /* 字长为8位数据格式 */
    g_uart1_handle.Init.StopBits = UART_STOPBITS_1;                           /* 一个停止位 */
    g_uart1_handle.Init.Parity = UART_PARITY_NONE;                            /* 无奇偶校验位 */
    g_uart1_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;                      /* 无硬件流控 */
    g_uart1_handle.Init.Mode = UART_MODE_TX_RX;                               /* 收发模式 */
    HAL_UART_Init(&g_uart1_handle);                                           /* HAL_UART_Init()会使能UART1 */

}

/**
 * @brief       UART底层初始化函数
 * @param       huart: UART句柄类型指针
 * @note        此函数会被HAL_UART_Init()调用
 *              完成时钟使能，引脚配置，中断配置
 * @retval      无
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef gpio_init_struct={0};

    if (huart->Instance == USART1)                            /* 如果是串口1，进行串口1 MSP初始化 */
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










