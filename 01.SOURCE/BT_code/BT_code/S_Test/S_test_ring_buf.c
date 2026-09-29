/*
 * S_test_ring_buf.c
 *
 * Created: 9/29/2026 11:59:06 PM
 *  Author: HTSang
 */ 

#include <stdio.h>
#include <stdbool.h>
#include "../MiddleWare/ring_buffer.h"

// Bi?n toàn c?c ph?c v? test
ring_buffer_t my_rb;

void run_ring_buffer_tests(void) {
	printf("\n--- BAT DAU KIEM THU RING BUFFER ---\n");

	// ----------------------------------------------------
	// Test Case 1: Kh?i t?o Ring Buffer
	// ----------------------------------------------------
	ring_buffer_init(&my_rb);
	printf("TC1 - Khoi tao: ");
	if (ring_buffer_empty(&my_rb) && !ring_buffer_full(&my_rb) && ring_buffer_count(&my_rb) == 0) {
		printf("PASS\n");
		} else {
		printf("FAIL\n");
	}

	// ----------------------------------------------------
	// Test Case 2: Push d? li?u vào buffer (ch?a ??y)
	// ----------------------------------------------------
	printf("TC2 - Push 3 phan tu: ");
	ring_buffer_push('A', &my_rb);
	ring_buffer_push('B', &my_rb);
	ring_buffer_push('C', &my_rb);
	
	if (ring_buffer_count(&my_rb) == 3 && !ring_buffer_full(&my_rb) && !ring_buffer_empty(&my_rb)) {
		printf("PASS (Count = %d)\n", ring_buffer_count(&my_rb));
		} else {
		printf("FAIL\n");
	}

	// ----------------------------------------------------
	// Test Case 3: Push ti?p ?? tràn/??y buffer (RBUFFER_SIZE = 4)
	// ----------------------------------------------------
	printf("TC3 - Push tiep de fill day: ");
	ring_buffer_push('D', &my_rb); // Thêm ph?n t? th? 4 -> ??y
	bool push_overflow = ring_buffer_push('E', &my_rb); // Th? thêm ph?n t? th? 5 (K? v?ng tr? v? false)

	if (ring_buffer_full(&my_rb) && (push_overflow == false) && ring_buffer_count(&my_rb) == 4) {
		printf("PASS (Buffer da day, khong cho push them)\n");
		} else {
		printf("FAIL\n");
	}

	// ----------------------------------------------------
	// Test Case 4: Pop d? li?u ra và ki?m tra tính ?úng ??n (FIFO)
	// ----------------------------------------------------
	printf("TC4 - Pop kiem tra thu tu FIFO: ");
	char c1 = ring_buffer_pop(&my_rb); // K? v?ng 'A'
	char c2 = ring_buffer_pop(&my_rb); // K? v?ng 'B'
	
	if (c1 == 'A' && c2 == 'B' && ring_buffer_count(&my_rb) == 2) {
		printf("PASS (Nhan dung 'A' va 'B')\n");
		} else {
		printf("FAIL (Nhan sai: %c, %c)\n", c1, c2);
	}

	// ----------------------------------------------------
	// Test Case 5: Pop h?t s?ch d? li?u và ki?m tra xem có báo Empty không
	// ----------------------------------------------------
	printf("TC5 - Pop het va kiem tra Empty: ");
	ring_buffer_pop(&my_rb); // B?c 'C'
	ring_buffer_pop(&my_rb); // B?c 'D' -> Buffer tr?ng hoàn toàn
	
	char c_empty = ring_buffer_pop(&my_rb);

	if (ring_buffer_empty(&my_rb) && ring_buffer_count(&my_rb) == 0) {
		printf("PASS (Buffer da trong)\n");
		} else {
		printf("FAIL\n");
	}

	printf("--- KET THUC KIEM THU ---\n\n");
}

int main(void) {
	run_ring_buffer_tests();

	while (1) {
	}
}
