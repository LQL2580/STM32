

#ifndef __USART_H
#define __USART_H

#include "stdio.h"
#include "./SYSTEM/sys/sys.h"

extern UART_HandleTypeDef g_uart1_handle;

extern uint8_t g_usart1_rx_flag ;

extern uint8_t g_rx_buffer[1];  /* HAL��ʹ�õĴ��ڽ��ջ��� */

void usart_init(uint32_t bound);

#endif





