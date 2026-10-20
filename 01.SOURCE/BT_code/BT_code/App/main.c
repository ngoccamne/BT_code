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
#include "app_uart.h"

int main(void)
{
	sys_time_init();
	app_button_init();
	app_led_init();
	app_uart_init();
	app_dht_init();
	app_lcd_init();
	sei();
	
    while (1) 
    {
		//app_dht_update();
		//app_button_update();
		//app_led_update();
		//app_lcd_update();
		app_uart_update();
    }
}

