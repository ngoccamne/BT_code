/*
 * app_uart.c
 *
 */ 
#include "app_uart.h"
#include <stdio.h>
#include <stdint.h>

static char app_rx_buffer[APP_BUFFER_SIZE];
static uint8_t app_rx_count = 0;

void app_uart_init(void)
{
	#ifdef UART0_ENABLE
		bsp_uart0_init();
	#endif

	#ifdef UART1_ENABLE
		bsp_uart1_init();
	#endif
}

void app_uart_process_received_data(const char* data)
{
	#ifdef UART0_ENABLE
	
	uart0_send_string(data);
	uart0_send_string("\r\n");
	
	#endif
	
	#ifdef UART1_ENABLE
	
	uart1_send_string(data);
	uart1_send_string("\r\n");
	
	#endif
}

void app_uart_update(void)
{
	#ifdef UART0_ENABLE
	
	while (uart0_rx_count() > 0)
	{
		char c = uart0_read_char();
		
		if (c == '\r' || c == '\n')
		{
			app_rx_buffer[app_rx_count] = '\0';
			app_uart_process_received_data(app_rx_buffer);
			app_rx_count = 0;
		}
		else
		{
			if (app_rx_count < APP_BUFFER_SIZE - 1)
			{
				app_rx_buffer[app_rx_count] = c;
				app_rx_count++;
			}
			else
			{
				app_rx_count = 0;
			}
		}
	}
	#endif
}