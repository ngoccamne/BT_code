/*
 * bsp_uart.c
 */ 
#include "bsp_uart.h"
#include "uart.h"
#include "ring_buffer.h"

#ifdef UART0_ENABLE
	uart_t	uart0;
	uart_t	*p_uart0 = &uart0;
#endif

#ifdef UART1_ENABLE
uart_t	uart1;
uart_t	*p_uart1 = &uart1;
#endif


void _putchar(char character)
{
	uart_transmit(character);
}

#ifdef UART0_ENABLE

void bsp_uart0_init(void)
{
	ring_buffer_init(&uart0.rb_tx);
	ring_buffer_init(&uart0.rb_rx);
	uart_init(9600, F_CPU);
}

void uart0_send_char(char c)
{
		while(ring_buffer_full(&uart0.rb_tx));
		ring_buffer_push(c, &uart0.rb_tx);
		uart0_tx_interrupt_enable();
}

void uart0_send_string(const char* str)
{
	while (*str)
	{
		uart0_send_char(*str++);
	}
}

uint8_t uart0_rx_count(void)
{
	ring_buffer_count(&uart0.rb_rx);
}

char uart0_read_char(void)
{
	while (!(ring_buffer_empty(&uart0.rb_rx)))
	{
		return ring_buffer_pop(&uart0.rb_rx);
	}
}

ISR(USART0_RX_vect)
{
	char data = UDR0;
	if (!(ring_buffer_full(&uart0.rb_rx)))
	{
		ring_buffer_push(data, &uart0.rb_rx);
	}
}
 ISR(USART0_UDRE_vect)
 {
	 if (!(ring_buffer_empty(&uart0.rb_tx)))
	 {
		 UDR0 = ring_buffer_pop(&uart0.rb_tx);
	 }
	 else
	 {
		 uart0_tx_interrupt_enable();
	 }
 }

#endif

#ifdef UART1_ENABLE

void bsp_uart1_init(void)
{
	ring_buffer_init(&uart1.rb_tx);
	ring_buffer_init(&uart1.rb_rx);
	uart_init(9600, F_CPU);
}

void uart1_send_char(char c)
{
	while(ring_buffer_full(&uart1.rb_tx));
	ring_buffer_push(c, &uart1.rb_tx);
	uart1_tx_interrupt_enable();
}

void uart1_send_string(const char* str)
{
	while (*str)
	{
		uart1_send_char(*str++);
	}
}

uint8_t uart1_rx_count(void)
{
	ring_buffer_count(&uart1.rb_rx);
}

char uart1_read_char(void)
{
	while (!(ring_buffer_empty(&uart1.rb_rx)))
	{
		return ring_buffer_pop(&uart1.rb_rx);
	}
}

ISR(USART1_RX_vect)
{
	char data = UDR1;
	if (!(ring_buffer_full(&uart1.rb_rx)))
	{
		ring_buffer_push(data, &uart1.rb_rx);
	}
}
ISR(USART1_UDRE_vect)
{
	if (!(ring_buffer_empty(&uart1.rb_tx)))
	{
		UDR1 = ring_buffer_pop(&uart1.rb_tx);
	}
	else
	{
		uart1_tx_interrupt_enable();
	}
}

#endif



