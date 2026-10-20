/*
 * test_ring_buffer.c
 */ 

#include "../../MiddleWare/ring_buffer.h"
#include <stddef.h>
#include <stdio.h> 

void test_init_ring_buffer(void)
{
    ring_buffer_t rbuffer;
    ring_buffer_init(&rbuffer);
    int fail_count = 0;
    
    if (0 != rbuffer.count) {
        printf("TEST FAILED at init: count != 0\n");
        fail_count++;
    }
    if (0 != rbuffer.in) {
        printf("TEST FAILED at init: in != 0\n");
        fail_count++;
    }
    if (0 != rbuffer.out) {
        printf("TEST FAILED at init: out != 0\n");
        fail_count++;
    }
    if (ring_buffer_full(&rbuffer)) {
        printf("TEST FAILED at init: Ring buffer is full!\n");
        fail_count++;
    }
    if (!ring_buffer_empty(&rbuffer)) {
        printf("TEST FAILED at init: Ring buffer is not empty!\n");
        fail_count++;
    }
    
    if (fail_count == 0) {
        printf("TEST PASSED: Init Ring Buffer - SUCCESS\n");
    }
}

void test_push_ring_buffer(void)
{
    ring_buffer_t rbuffer;
    ring_buffer_init(&rbuffer);
    int i;
    int fail_count = 0;
    
    for (i = 0; i < RBUFFER_SIZE; i++) {
        if (ring_buffer_push('A' + (i % 26), &rbuffer) != 1) {
            printf("TEST FAILED at push data: Failed at push #%d\n", i + 1);
            fail_count++;
        }
    }
    
    if (RBUFFER_SIZE != rbuffer.count) {
        printf("TEST FAILED at push data: count != RBUFFER_SIZE\n");
        fail_count++;
    }
    if (!ring_buffer_full(&rbuffer)) {
        printf("TEST FAILED at push data: Ring buffer is not full!\n");
        fail_count++;
    }
    if (ring_buffer_empty(&rbuffer)) {
        printf("TEST FAILED at push data: Ring buffer is empty!\n");
        fail_count++;
    }
    
    if (ring_buffer_push('X', &rbuffer) != 0) {
        printf("TEST FAILED at push data: Over-push succeeded (It should fail)!\n");
        fail_count++;
    }
    
    if (0 != rbuffer.in) {
        printf("TEST FAILED at push data: 'in' pointer did not wrap to 0\n");
        fail_count++;
    }
    
    if (fail_count == 0) {
        printf("TEST PASSED: Push and Full State - SUCCESS\n");
    }
}

void test_pop_ring_buffer(void)
{
    ring_buffer_t rbuffer;
    ring_buffer_init(&rbuffer);
    int i;
    int fail_count = 0;
    
    for (i = 0; i < RBUFFER_SIZE; i++) {
        ring_buffer_push('A' + (i % 26), &rbuffer);
    }

    for (i = 0; i < RBUFFER_SIZE; i++) {
        char rb_data = ring_buffer_pop(&rbuffer);
        if (rb_data != 'A' + (i % 26)) {
            printf("TEST FAILED at pop data: Incorrect value popped at #%d\n", i + 1);
            fail_count++;
        }
    }
    
    if (0 != rbuffer.count) {
        printf("TEST FAILED at pop data: count != 0 after full pop\n");
        fail_count++;
    }
    if (!ring_buffer_empty(&rbuffer)) {
        printf("TEST FAILED at pop data: Ring buffer is not empty!\n");
        fail_count++;
    }
    if (ring_buffer_full(&rbuffer)) {
        printf("TEST FAILED at pop data: Ring buffer is full!\n");
        fail_count++;
    }
    
    char rb_data_empty = ring_buffer_pop(&rbuffer);
    if (rb_data_empty != 0) {
        printf("TEST FAILED at pop data: Pop when empty did not return 0\n");
        fail_count++;
    }
    
    if (0 != rbuffer.out) {
        printf("TEST FAILED at pop data: 'out' pointer did not wrap to 0\n");
        fail_count++;
    }
    
    if (fail_count == 0) {
        printf("TEST PASSED: Pop and Empty State - SUCCESS\n");
    }
}

void test_wrap_around_ring_buffer(void)
{
    ring_buffer_t rbuffer;
    ring_buffer_init(&rbuffer);
    int i;
    int fail_count = 0;

    for (i = 0; i < RBUFFER_SIZE * 2; i++) {
        if (ring_buffer_push('X', &rbuffer) != 1) {
            printf("TEST FAILED at wrap around: Push failed at step %d\n", i);
            fail_count++;
        }
     
        char val = ring_buffer_pop(&rbuffer);
        if (val != 'X') {
            printf("TEST FAILED at wrap around: Pop wrong value at step %d\n", i);
            fail_count++;
        }
    }
    
    if (rbuffer.count != 0 || !ring_buffer_empty(&rbuffer)) {
        printf("TEST FAILED at wrap around: Buffer state corrupted after wrap-around\n");
        fail_count++;
    }
    
    if (fail_count == 0) {
        printf("TEST PASSED: Continuous Wrap Around - SUCCESS\n");
    }
}

//int main(void) {
	//
	//printf("========== STARTING RING BUFFER TEST ==========\n");
	//
	//test_init_ring_buffer();
	//test_push_ring_buffer();
	//test_pop_ring_buffer();
	//test_wrap_around_ring_buffer();
//
	//printf("============= TEST FINISHED =============\n");
	//
	//while (1) {
	//}
//}