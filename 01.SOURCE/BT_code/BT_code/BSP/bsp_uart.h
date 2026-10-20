/*
 * bsp_uart.h
 */ 
#ifndef BSP_UART_H_
#define BSP_UART_H_

#include <stdint.h>
#include "ring_buffer.h"
#include "board.h"

#define	UART0_ENABLE
#define	UART1_ENABLE

typedef struct{
	volatile ring_buffer_t rb_rx;
	volatile ring_buffer_t rb_tx;
	volatile uint8_t uart_error;
} uart_t;

void bsp_uart0_init(void);
void uart0_send_char(char c);
void uart0_send_string(const char* str);
uint8_t uart0_rx_count(void);
char uart0_read_char(void);

void bsp_uart1_init(void);
void uart1_send_char(char c);
void uart1_send_string(const char* str);
uint8_t uart1_rx_count(void);
char uart1_read_char(void);

void _putchar(char character);

#endif