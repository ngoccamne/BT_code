/*
 * app_lcd.h
 */ 
#ifndef APP_LCD_H_
#define APP_LCD_H_

#include "bsp_button.h"
#include "app_button.h"
#include "lcd.h"
#include "bsp_lcd.h"
#include "app_dht.h"

typedef enum{
	TEMP_DISPLAY,
	HUMID_DISPLAY,
	} lcd_state_t;
	
void app_lcd_init(void);
void app_lcd_update(void);

#endif