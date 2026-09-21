/*
 * app_button.c
 */ 

#include "app_button.h"

void app_button_init(uint8_t port_num, uint8_t pin_num)
{
	bsp_button_init(port_num, pin_num);
}

uint8_t app_button_get_state(uint8_t port_num, uint8_t pin_num)
{
	if (bsp_button_get_state(port_num, pin_num))
	{
		return BUTTON_RELEASED;
	}
	else
	{
		return BUTTON_PRESSED;
	}
}