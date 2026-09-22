/*
 * app_button.c
 */ 

#include "app_button.h"

static button_state state = BUTTON_RELEASED;
static uint32_t	button_timer;

void app_button_init()
{
	bsp_button_init(BUTTON_PORT_ID, BUTTON_PIN_ID);
}

void app_button_update(void)
{
	switch (state)
	{
		case BUTTON_RELEASED:
			if (bsp_button_get_state(BUTTON_PORT_ID, BUTTON_PIN_ID) == BUTTON_PRESSED)
			{
				state = BUTTON_PRESSED_DEBOUNCE;
				timer_set_ms(&button_timer, 20);
			}
		break;
		
		case BUTTON_PRESSED_DEBOUNCE:
			if (bsp_button_get_state(BUTTON_PORT_ID, BUTTON_PIN_ID) == BUTTON_RELEASED)
			{
				state = BUTTON_RELEASED;
			}
			else if (TIME_EXPIRED == is_timer_expire(&button_timer))
			{
				state = BUTTON_PRESSED;
			}
		break;
		
		case BUTTON_PRESSED:
			if (bsp_button_get_state(BUTTON_PORT_ID, BUTTON_PIN_ID) == BUTTON_RELEASED)
			{
				state = BUTTON_RELEASED_DEBOUNCE;
				timer_set_ms(&button_timer, 20);
			}
		break;
		
		case BUTTON_RELEASED_DEBOUNCE:
			if (bsp_button_get_state(BUTTON_PORT_ID, BUTTON_PIN_ID) == BUTTON_PRESSED)
			{
				state = BUTTON_PRESSED;
			}
			else if (TIME_EXPIRED == is_timer_expire(&button_timer))
			{
				state = BUTTON_RELEASED;
			}
		break;
		
		default:
		break;
	}
}

uint8_t app_button_get_state(void)
{
	switch (state)
	{
		case BUTTON_RELEASED:
		case BUTTON_PRESSED_DEBOUNCE:
			return BUTTON_RELEASED;
		case BUTTON_PRESSED:
		case BUTTON_RELEASED_DEBOUNCE:
			return BUTTON_PRESSED;
		default:
			return BUTTON_RELEASED;
	}
}
