/*
 * BT_code.c
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include "app_button.h"
#include "app_led.h"

int main(void)
{
	app_button_init(BUTTON_PORT_ID, BUTTON_PIN_ID);
	app_led_init(LED_PORT_ID, LED_PIN_ID);
	uint8_t button_state;
	
    while (1) 
    {
		button_state = app_button_get_state(BUTTON_PORT_ID, BUTTON_PIN_ID);
		app_led_update(LED_PORT_ID, LED_PIN_ID, button_state);
    }
}

