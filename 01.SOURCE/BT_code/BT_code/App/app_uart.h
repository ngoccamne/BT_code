/*
 * app_uart.h
 *
 */ 
#ifndef APP_UART_H_
#define APP_UART_H_

#include "bsp_uart.h"
#include "uart.h"

#define APP_BUFFER_SIZE		16	

void app_uart_init(void);
void app_uart_update(void);

#endif	