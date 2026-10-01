/*
 * test_ring_buffer.c
 */ 

#include "ring_buffer.h"
#include <stddef.h> 
#include <stdio.h>  
#include "test_ring_buffer.h"

void test_init_ring_buffer(void)
{
	ring_buffer_t rbuffer;
	ring_buffer_init(&rbuffer);
	
	if (0 != rbuffer.count)
	{
		printf("TEST FAILED at init ring buffer: count = 0\n");
	}
	
	if (0 != rbuffer.in)
	{
		printf("TEST FAILED at init ring buffer: in = 0\n");
	}
	
	if (0 != rbuffer.out)
	{
		printf("TEST FAILED at init ring buffer: out not 0\n");
	}
	
	if (ring_buffer_full(&rbuffer))
	{
		printf("TEST FAILED at init ring buffer: Ring buffer is full!\n");
	}
	
	if (!ring_buffer_empty(&rbuffer))
	{
		printf("TEST FAILED at init ring buffer: Ring buffer is not empty!\n");
	}
}

void test_push_ring_buffer(void)
{
	ring_buffer_t rbuffer;
	ring_buffer_init(&rbuffer);
	
	if (ring_buffer_push('3', &rbuffer) != 1)
	{
		printf("TEST FAILED at push data ring buffer for the first time!\n");
	}
	
	if (ring_buffer_push('3', &rbuffer) != 1)
	{
		printf("TEST FAILED at push data ring buffer for the second time!\n");
	}
	
	if (ring_buffer_push('3', &rbuffer) != 1)
	{
		printf("TEST FAILED at push data ring buffer for the third time!\n");
	}
	
	if (ring_buffer_push('3', &rbuffer) != 1)
	{
		printf("TEST FAILED at push data ring buffer for the fourth time!\n");
	}
	
	if (RBUFFER_SIZE != rbuffer.count)
	{
		printf("TEST FAILED at push data ring buffer: count\n");
	}
	
	if (0 != rbuffer.out)
	{
		printf("TEST FAILED at push data ring buffer: out1 = 0\n");
	}
	
	if (0 != rbuffer.in)
	{
		printf("TEST FAILED at push data ring buffer: in1 = 0\n");
	}
	
	if (ring_buffer_push('3', &rbuffer) != 0)
	{
		printf("TEST FAILED at push data ring buffer for the fifth time!\n");
	}
	
	if (0 != rbuffer.out)
	{
		printf("TEST FAILED at push data ring buffer: out2 = 0\n");
	}
	
	if (0 != rbuffer.in)
	{
		printf("TEST FAILED at push data ring buffer: in2 = 0\n");
	}
	
	if (!ring_buffer_full(&rbuffer))
	{
		printf("TEST FAILED at push data ring buffer: Ring buffer is available!\n");
	}
	
	if (ring_buffer_empty(&rbuffer))
	{
		printf("TEST FAILED at push data ring buffer: Ring buffer is empty!\n");
	}
}

void test_pop_ring_buffer(void)
{
	ring_buffer_t rbuffer;
	ring_buffer_init(&rbuffer);
	
	if (ring_buffer_push('3', &rbuffer) != 1)
	{
		printf("TEST FAILED at pop data ring buffer for the first time!\n");
	}
	
	if (ring_buffer_push('2', &rbuffer) != 1)
	{
		printf("TEST FAILED at pop data ring buffer for the second time!\n");
	}
	
	if (ring_buffer_push('1', &rbuffer) != 1)
	{
		printf("TEST FAILED at pop data ring buffer for the third time!\n");
	}
	
	char rb_data = ring_buffer_pop(&rbuffer);
	if (rb_data != '3')
	{
		printf("TEST FAILED at pop data ring buffer for the first time!\n");
	}
	
	if (rbuffer.count != 2)
	{
		printf("TEST FAILED at pop data ring buffer: count\n");
	}
	
	if (rbuffer.out != 1)
	{
		printf("TEST FAILED at pop data ring buffer: out1\n");
	}
	
	if (rbuffer.in != 3)
	{
		printf("TEST FAILED at pop data ring buffer: in\n");
	}
	
	rb_data = ring_buffer_pop(&rbuffer);
	if (rb_data != '2')
	{
		printf("TEST FAILED at pop data ring buffer for the second time!\n");
	}
	
	rb_data = ring_buffer_pop(&rbuffer);
	if (rb_data != '1')
	{
		printf("TEST FAILED at push data ring buffer for the third time!\n");
	}
	
	if (rbuffer.out != 3)
	{
		printf("TEST FAILED at pop data ring buffer: out2\n");
	}
	
	if (ring_buffer_empty(&rbuffer) != 1)
	{
		printf("TEST FAILED at pop data ring buffer: empty\n");
	}
	
	if (ring_buffer_full(&rbuffer) != 0)
	{
		printf("TEST FAILED at pop data ring buffer: not full\n");
	}
	
	rb_data = ring_buffer_pop(&rbuffer);
	if (rb_data != 0)
	{
		printf("TEST FAILED at pop data ring buffer when empty\n");
	}
	
	if (ring_buffer_empty(&rbuffer) != 1)
	{
		printf("TEST FAILED at pop data ring buffer: empty\n");
	}
	
	if (ring_buffer_full(&rbuffer) != 0)
	{
		printf("TEST FAILED at pop data ring buffer: not full\n");
	}
}