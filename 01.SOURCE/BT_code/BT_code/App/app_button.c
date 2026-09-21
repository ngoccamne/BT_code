/*
 * app_button.c
 */ 

#include "app_button.h"

static uint8_t state = BUTTON_RELEASED;

void app_button_init()
{
	bsp_button_init(BUTTON_PORT_ID, BUTTON_PIN_ID);
}

void app_button_update(void)
{
	if (bsp_button_get_state(BUTTON_PORT_ID, BUTTON_PIN_ID))
	{
		state = BUTTON_RELEASED;
	}
	else
	{
		state = BUTTON_PRESSED;
	}
}

uint8_t app_button_get_state(void)
{
	return state;
}