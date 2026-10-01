/*
 * bsp_uart.c
 */ 
#include "bsp_uart.h"
#include "uart.h"

void bsp_uart_init(void)
{
	uart_init();
}

void _putchar(char character)
{
	uart_transmit(character);
}