/*
 * app_lcd.c
 */ 

#include "app_lcd.h"

static lcd_state_t state = TEMP_DISPLAY;
static lcd_state_t last_state;
char lcd_buffer[17];
float old_temp = -1.0;
float new_temp = 0;
float old_humid = -1.0;
float new_humid = 0;

void app_lcd_init(void)
{
	bsp_lcd_init();
	lcd_init();
}

void app_lcd_update(void){
	switch(state)
	{
		case TEMP_DISPLAY:
		if (app_button_get_state() == BUTTON_PRESSED)
		{
			state = HUMID_DISPLAY;
			last_state = TEMP_DISPLAY;
		}
		else if (HUMID_DISPLAY == last_state)
		{
			new_temp = app_dht_get_temp();
			lcd_clear();
			sprintf(lcd_buffer, "Temp: %d C  ",(int)new_temp);
			lcd_set_cursor(0, 0);
			lcd_put_string(lcd_buffer);
			old_temp = new_temp;
			last_state = TEMP_DISPLAY;
		}
		else
		{
			new_temp = app_dht_get_temp();
			if (new_temp != old_temp)
			{
				lcd_clear();
				sprintf(lcd_buffer, "Temp: %d C  ",(int)new_temp);
				lcd_set_cursor(0, 0);
				lcd_put_string(lcd_buffer);
				old_temp = new_temp;
			}
		}
		break;
		
		case HUMID_DISPLAY:
		if (app_button_get_state() == BUTTON_PRESSED)
		{
			state = TEMP_DISPLAY;
			last_state = HUMID_DISPLAY;
		}
		else if (TEMP_DISPLAY == last_state)
		{
			new_humid = app_dht_get_humid();
			lcd_clear();
			sprintf(lcd_buffer, "Hum: %d %%  ",(int)new_humid);
			lcd_set_cursor(0, 1);
			lcd_put_string(lcd_buffer);
			old_humid = new_humid;
			last_state = HUMID_DISPLAY;
		}
		else
		{
			new_humid = app_dht_get_humid();
			if (new_humid != old_humid)
			{
				lcd_clear();
				sprintf(lcd_buffer, "Hum: %d %%  ",(int)new_humid);
				lcd_set_cursor(0, 1);
				lcd_put_string(lcd_buffer);
				old_humid = new_humid;
			}
		}
		break;
	}
}