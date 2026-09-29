/*
 * uart.c
 *
 * Created: 9/8/2026 2:33:37 PM
 *  Author: NGOC CAM
 */ 

#include "uart.h"

void uart_init(uint32_t baud_rate, uint32_t cpu_freq)
{
	//PHAT VA THU; 8 BIT; NO PARITY BIT; 1 STOP BIT; 
	
	uint16_t ubrr_value = (cpu_freq / (16UL * baud_rate)) - 1;
 
    UBRR0H = (uint8_t)(ubrr_value >> 8);
    UBRR0L = (uint8_t)ubrr_value;

	UCSR0B = (1 << RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_transmit(uint8_t data)
{
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

uint8_t uart_receive()
{
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

void uart_send_string(const char *str)
{
	while (*str)
	{
		uart_transmit(*str++);
	}
}