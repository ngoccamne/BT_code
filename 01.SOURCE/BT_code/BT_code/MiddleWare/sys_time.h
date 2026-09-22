/*
 * sys_time.h
 */ 

#ifndef SYS_TIME_H_
#define SYS_TIME_H_

#include <stdint.h>

#define		TIME_EXPIRED		1
#define		TIME_NOT_EXPIRED	0

void sys_time_init(void);
uint32_t get_sys_time_ms(void);
void timer_set_ms(uint32_t *timer, uint32_t val);  
uint8_t is_timer_expire(uint32_t *timer);

#endif