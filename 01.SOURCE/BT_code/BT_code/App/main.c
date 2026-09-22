/*
 * BT_code.c
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "app_button.h"
#include "app_led.h"
#include "sys_time.h"

int main(void)
{
	sys_time_init();
	app_button_init();
	app_led_init();
	sei();
	
    while (1) 
    {
		app_button_update();
		app_led_update();
    }
}

