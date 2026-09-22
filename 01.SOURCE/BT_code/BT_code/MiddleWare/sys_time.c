/*
 * sys_time.c
 */ 

#include "sys_time.h"
#include "bsp_timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>

static volatile uint32_t sys_count = 0;

void sys_time_init(void)
{
	bsp_timer1_init();
}

void sys_time_update(void)
{
	sys_count++;
}

uint32_t get_sys_time_ms(void)
{
	uint32_t t;
	uint8_t sreg = SREG;
	cli();
	t = sys_count;
	SREG = sreg;

	return t;
}

void timer_set_ms(uint32_t *timer, uint32_t val)
{
	*timer = get_sys_time_ms() + val;
}

uint8_t is_timer_expire(uint32_t *timer)
{
	if ((int32_t)(get_sys_time_ms() - *timer) >= 0)
	{
		return TIME_EXPIRED;
	}
	return TIME_NOT_EXPIRED;
}


