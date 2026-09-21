/*
 * app_led.h
 */ 

#ifndef APP_LED_H_
#define APP_LED_H_

#include "bsp_button.h"
#include "bsp_led.h"
#include "app_button.h"

#define		LED_ON		1
#define		LED_OFF		0

void app_led_init();
void app_led_update();

#endif