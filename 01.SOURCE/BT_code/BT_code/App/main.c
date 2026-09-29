/*
 * BT_code.c
 */ 

#include "board.h"
#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "app_button.h"
#include "app_led.h"
#include "sys_time.h"
#include "lcd.h"
#include "app_dht.h"

int main(void)
{
	sys_time_init();
	
	printf("HELLO SANG");
	
	
	app_button_init();
	app_led_init();
	// uart_init();
	app_dht_init();
	app_lcd_init();
	sei();
	
    while (1) 
    {
		app_dht_update();
		app_button_update();
		app_led_update();
		app_lcd_update();
    }
}

