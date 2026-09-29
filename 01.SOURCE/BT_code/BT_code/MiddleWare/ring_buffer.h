/*
 * ring_buffer.h
 */ 

#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#ifdef _WIN32
#include "../S_Test/avr_compat.h"
#else
#include <util/atomic.h>
#endif

#include <stdbool.h>
#include <stdint.h>

#define RBUFFER_SIZE  4
#define FULL          0
#define AVAILABLE     1
#define EMPTY         2

typedef struct {
	volatile char    buffer[RBUFFER_SIZE];
	volatile uint8_t in;
	volatile uint8_t out;
	volatile uint8_t count;
} ring_buffer_t;

void ring_buffer_init(volatile ring_buffer_t* rb);
uint8_t ring_buffer_count(volatile ring_buffer_t* rb);
bool ring_buffer_full(volatile ring_buffer_t* rb);
bool ring_buffer_empty(volatile ring_buffer_t* rb);
bool ring_buffer_push(char data, volatile ring_buffer_t* rb);
char ring_buffer_pop(volatile ring_buffer_t* rb);

#endif