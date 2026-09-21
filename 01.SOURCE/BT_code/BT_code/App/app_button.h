/*
 * app_button.h
 */ 

#ifndef APP_BUTTON_H_
#define APP_BUTTON_H_

#include "bsp_button.h"
#include "bsp_led.h"

#define		BUTTON_PRESSED		1
#define		BUTTON_RELEASED 	0

void app_button_init();
void app_button_update(void);
uint8_t app_button_get_state(void);

#endif