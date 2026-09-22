/*
 * bsp_timer.c
 */ 

#include "board.h"
#include "bsp_timer.h"
#include "sys_time.h"

#include <avr/io.h>
#include <avr/interrupt.h>

void bsp_timer1_init(void)
{
	uint8_t sreg = SREG;
	cli();
	
	TCCR1A = 0x00;
	TCCR1B = 0x00;
	TCNT1  = 0x0000;
	
	TCCR1B |= (1u << WGM12);
	OCR1A = (uint16_t)(F_CPU / 64UL / 1000UL - 1UL); //124 => 1ms
	
	//Enable Compare Match A interrupt for Timer1
	#if defined(TIMSK1)
	TIMSK1 |= (1u << OCIE1A);
	#else
	TIMSK  |= (1u << OCIE1A);
	#endif
	
	//Prescaler = 64
	TCCR1B |= (1u << CS11) | (1u << CS10);
	
	SREG = sreg;
}

ISR(TIMER1_COMPA_vect)
{
	sys_time_update();
}
