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
	app_button_init();
	app_led_init();
	
    while (1) 
    {
		app_button_update();
		app_led_update();
    }
}

