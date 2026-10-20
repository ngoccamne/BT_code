/*
 * uart.h
 */ 
#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void uart_init(uint32_t baud_rate, uint32_t cpu_freq);
void uart_transmit(uint8_t data);
uint8_t uart_receive();
void uart_send_string(const char *str);
void uart0_tx_interrupt_enable(void);
void uart1_tx_interrupt_enable(void);

#endif /* UART_H_ */