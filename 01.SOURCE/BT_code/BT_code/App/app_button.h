/*
 * app_button.h
 */ 

#ifndef APP_BUTTON_H_
#define APP_BUTTON_H_

#include "bsp_button.h"
#include "bsp_led.h"
#include "sys_time.h"

typedef enum {
	BUTTON_PRESSED,
	BUTTON_RELEASED,
	BUTTON_PRESSED_DEBOUNCE,
	BUTTON_RELEASED_DEBOUNCE
} button_state;

void app_button_init();
void app_button_update(void);
uint8_t app_button_get_state(void);

#endif