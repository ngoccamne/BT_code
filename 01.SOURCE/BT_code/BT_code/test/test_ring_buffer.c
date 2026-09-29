/*
 * test_ring_buffer.c
 */ 

#include "ring_buffer.h"
#include "stddef.h"
#include <stdio.h>


void test_init_ring_buffer(void)
{
	ring_buffer_t rbuffer;
	ring_buffer_init(&rbuffer);
	
	if (0 == rbuffer.count)
	{
		printf("TEST PASSED at init ring buffer: count = 0");
	}
	else
	{
		printf("TEST FAILED at init ring buffer: count not 0");
	}
	
	if (0 == rbuffer.in)
	{
		printf("TEST PASSED at init ring buffer: in = 0");
	}
	else
	{
		printf("TEST FAILED at init ring buffer: in not 0");
	}
	
	if (0 == rbuffer.out)
	{
		printf("TEST PASSED at init ring buffer: out = 0");
	}
	else
	{
		printf("TEST FAILED at init ring buffer: out not 0");
	}
	
	if (ring_buffer_full(&rbuffer))
	{
		printf("TEST FAILED at init ring buffer: Ring buffer is full!");
	}
	
	if (ring_buffer_empty(&rbuffer))
	{
		printf("TEST PASSED at init ring buffer: Ring buffer is empty!");
	}
}

void test_push_ring_buffer(void)
{
	ring_buffer_t rbuffer;
	ring_buffer_init(&rbuffer);
	
	if (ring_buffer_push('3', &rbuffer) == 1)
	{
		printf("TEST PASSED at push data ring buffer for the first time!");
	}
	else
	{
		printf("TEST FAILED at push data ring buffer for the first time!");
	}
	
	if (ring_buffer_push('3', &rbuffer) == 1)
	{
		printf("TEST PASSED at push data ring buffer for the second time!");
	}
	else
	{
		printf("TEST FAILED at push data ring buffer for the second time!");
	}
	
	if (ring_buffer_push('3', &rbuffer) == 1)
	{
		printf("TEST PASSED at push data ring buffer for the third time!");
	}
	else
	{
		printf("TEST FAILED at push data ring buffer for the third time!");
	}
	
	if (ring_buffer_push('3', &rbuffer) == 1)
	{
		printf("TEST PASSED at push data ring buffer for the fourth time!");
	}
	else
	{
		printf("TEST FAILED at push data ring buffer for the fourth time!");
	}
	
	if (RBUFFER_SIZE == rbuffer.count)
	{
		printf("TEST PASSED at push data ring buffer: count");
	}
	else
	{
		printf("TEST FAILED at push data ring buffer: count");
	}
	
	if (0 == rbuffer.out)
	{
		printf("TEST PASSED at push data ring buffer: out1 = 0");
	}
	else
	{
		printf("TEST FAILED at push data ring buffer: out1 = 0");
	}
	
	if (0 == rbuffer.in)
	{
		printf("TEST PASSED at push data ring buffer: in1 = 0");
	}
	else
	{
		printf("TEST FAILED at push data ring buffer: in1 = 0");
	}
	
	if (ring_buffer_push('3', &rbuffer) == 0)
	{
		printf("TEST PASSED at push data ring buffer for the fifth time!");
	}
	else
	{
		printf("TEST FAILED at push data ring buffer for the fifth time!");
	}
	
	if (0 == rbuffer.out)
	{
		printf("TEST PASSED at push data ring buffer: out2 = 0");
	}
	else
	{
		printf("TEST FAILED at push data ring buffer: out2 = 0");
	}
	
	if (0 == rbuffer.in)
	{
		printf("TEST PASSED at push data ring buffer: in2 = 0");
	}
	else
	{
		printf("TEST FAILED at push data ring buffer: in2 = 0");
	}
	
	if (ring_buffer_full(&rbuffer))
	{
		printf("TEST PASSED at push data ring buffer: Ring buffer is full!");
	}
	else
	{
		printf("TEST FAILED at push data ring buffer: Ring buffer is available!");
	}
	
	if (ring_buffer_empty(&rbuffer))
	{
		printf("TEST FAILED at push data ring buffer: Ring buffer is empty!");
	}
	else
	{
		printf("TEST PASSED at push data ring buffer: Ring buffer is not empty!");
	}
}

void test_pop_ring_buffer(void)
{
	ring_buffer_t rbuffer;
	ring_buffer_init(&rbuffer);
}