/*
 * app_led.h
 */ 

#ifndef APP_LED_H_
#define APP_LED_H_

#include "bsp_button.h"
#include "bsp_led.h"

#define		LED_ON		1
#define		LED_OFF		0

void app_led_init(uint8_t port_num, uint8_t pin_num);
void app_led_update(uint8_t port_num, uint8_t pin_num, uint8_t state);

#endif