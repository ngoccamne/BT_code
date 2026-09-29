/*
 * bsp_lcd.h
 */ 
#ifndef BSP_LCD_H_
#define BSP_LCD_H_

#include <stdint.h>
#include "gpio.h"
#include <avr/io.h>

#define LCD_PORT				PORTA
#define LCD_CONTROL_PORT		PORTA
#define LCD_DDR					DDRA
#define LCD_CONTROL_DDR			DDRA
#define RS						PA0
#define RW						PA1
#define E						PA2
#define D4						PA4
#define D5						PA5
#define D6						PA6
#define D7						PA7

void bsp_lcd_init(void);
void lcd_rs_high(void);
void lcd_rs_low(void);
void lcd_en_high(void);
void lcd_en_low(void);
void lcd_write_bus4(uint8_t nibble);
void lcd_delay_ms(uint16_t ms);
void lcd_delay_us(uint16_t us);

#endif /* BSP_LCD_H_ */