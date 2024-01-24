

#ifndef __USART_H
#define __USART_H

#include "stdio.h"
#include "./SYSTEM/sys/sys.h"

//UART_HandleTypeDef g_uartl_handle;
extern UART_HandleTypeDef g_uart1_handle;  /* UART句柄 */
extern uint8_t g_rx_buffer[1];  /* HAL库使用的串口接收缓冲 */
extern uint8_t g_usart1_rx_flag ;
void usart_init(uint32_t bound);

#endif


