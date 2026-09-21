/*
 * app_led.c
 */ 

#include "app_led.h"

void app_led_init(uint8_t port_num, uint8_t pin_num)
{
	bsp_led_init(port_num, pin_num);
}

void app_led_update(uint8_t port_num, uint8_t pin_num, uint8_t state)
{
	if (state == LED_ON)
	{
		bsp_led_on(port_num, pin_num);
	}
	else
	{
		bsp_led_off(port_num, pin_num);
	}
}