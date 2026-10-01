/*
 * test_runner.c
 *
 * Created: 10/1/2026 10:17:27 AM
 *  Author: NGOC CAM
 */ 

#include <stdio.h>
#include "ring_buffer.h"

extern void test_init_ring_buffer(void);
extern void test_push_ring_buffer(void);
extern void test_pop_ring_buffer(void);

int main() {
	printf("--- BAT DAU KIEM THU RING BUFFER ---\n");
	
	test_init_ring_buffer();
	test_push_ring_buffer();
	test_pop_ring_buffer();
	
	printf("--- KET THUC KIEM THU ---\n");
	return 0;
}