/*
 * uart.h
 *
 * Created: 9/8/2026 2:33:47 PM
 *  Author: NGOC CAM
 */ 
#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void uart_init();
void uart_transmit(uint8_t data);
uint8_t uart_receive();
void uart_send_string(const char *str);

#endif /* UART_H_ */