/*
 * app_button.h
 */ 

#ifndef APP_BUTTON_H_
#define APP_BUTTON_H_

#include "bsp_button.h"
#include "bsp_led.h"

#define		BUTTON_PRESSED		1
#define		BUTTON_RELEASED 	0

void app_button_init(uint8_t port_num, uint8_t pin_num);
uint8_t app_button_get_state(uint8_t port_num, uint8_t pin_num);

#endif