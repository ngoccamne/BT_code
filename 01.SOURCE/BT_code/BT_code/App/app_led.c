/*
 * app_led.c
 */ 

#include "app_led.h"

void app_led_init()
{
	bsp_led_init(LED_PORT_ID, LED_PIN_ID);
}

void app_led_update()
{
	uint8_t button_state = app_button_get_state();
	
	if (BUTTON_PRESSED == button_state)
	{
		bsp_led_on(LED_PORT_ID, LED_PIN_ID);
	}
	else if (BUTTON_RELEASED == button_state)
	{
		bsp_led_off(LED_PORT_ID, LED_PIN_ID);
	}
}