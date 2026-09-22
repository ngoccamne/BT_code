/*
 * lcd.h
 */ 

#ifndef LCD1602_H_
#define LCD1602_H_

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

void lcd_init();
void lcd_send_command(uint8_t cmd);
void lcd_send_data(uint8_t data);
void lcd_clear(void);
void lcd_home(void);
void lcd_put_char(char c);
void lcd_put_string(const char *s);
void lcd_set_cursor(uint8_t col, uint8_t row);

#endif /* LCD1602_H_ */