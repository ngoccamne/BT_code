/*
 * ring_buffer.c
 */ 

#include "ring_buffer.h"

void ring_buffer_init(volatile ring_buffer_t* rb)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		rb->in = 0;
		rb->out = 0;
		rb->count = 0;
	}
}

uint8_t ring_buffer_count(volatile ring_buffer_t* rb)
{
	return rb->count;
}

bool ring_buffer_full(volatile ring_buffer_t* rb)
{
	return (rb->count == (uint8_t)RBUFFER_SIZE);
}

bool ring_buffer_empty(volatile ring_buffer_t* rb)
{
	return (rb->count == 0);
}

bool ring_buffer_push(char data, volatile ring_buffer_t* rb)
{
	if (1 == ring_buffer_full(&rb))
	{
		return 0;
	}
	*(rb->buffer + rb->in) = data;
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		rb->in = (rb->in + 1) & ((uint8_t)RBUFFER_SIZE - 1);
		rb->count++;
	}
	return 1;
}

char ring_buffer_pop(volatile ring_buffer_t* rb)
{
	char data = *(rb->buffer + rb->out);
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		rb->out = (rb->out + 1) & ((uint8_t)RBUFFER_SIZE - 1);
		rb->count--;
	}
	return data;
}

