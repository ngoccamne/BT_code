/*
 * bsp_lcd.c
 */

#include "board.h"
#include "bsp_lcd.h"
#include <avr/io.h>
#include <util/delay.h>

static inline void bsp_lcd_set_bit(volatile uint8_t *port, uint8_t bit)
{
	*port |= (1u << bit);
}

static inline void bsp_lcd_clear_bit(volatile uint8_t *port, uint8_t bit)
{
	*port &= ~(1u << bit);
}

static inline void bsp_lcd_force_write_mode(void)
{
	bsp_lcd_clear_bit(&LCD_CONTROL_PORT, RW);
}

void bsp_lcd_init(void)
{
	LCD_CONTROL_DDR	|= (1u << RS) | (1u << RW) | (1u << E);
	LCD_DDR |= (1u << D4) | (1u << D5) | (1u << D6) | (1u << D7);
	
	LCD_CONTROL_PORT &= ~((1u << RS) | (1u << RW) | (1u << E));
	LCD_PORT &= ~((1u << D4) | (1u << D5) | (1u << D6) | (1u << D7));
}

void lcd_rs_high(void)
{
	bsp_lcd_force_write_mode();
	bsp_lcd_set_bit(&LCD_CONTROL_PORT, RS);
}

void lcd_rs_low(void)
{
	bsp_lcd_force_write_mode();
	bsp_lcd_clear_bit(&LCD_CONTROL_PORT, RS);
}

void lcd_en_high(void)
{
	bsp_lcd_force_write_mode();
	bsp_lcd_set_bit(&LCD_CONTROL_PORT, E);
}

void lcd_en_low(void)
{
	bsp_lcd_force_write_mode();
	bsp_lcd_clear_bit(&LCD_CONTROL_PORT, E);
}

void lcd_write_bus4(uint8_t nibble)
{
	bsp_lcd_force_write_mode();
	if (nibble & 0x01)
		bsp_lcd_set_bit(&LCD_PORT, D4);
	else
		bsp_lcd_clear_bit(&LCD_PORT, D4);
		
	if (nibble & 0x02)
		bsp_lcd_set_bit(&LCD_PORT, D5);
	else
		bsp_lcd_clear_bit(&LCD_PORT, D5);
	
	if (nibble & 0x03)
		bsp_lcd_set_bit(&LCD_PORT, D6);
	else
		bsp_lcd_clear_bit(&LCD_PORT, D6);

	if (nibble & 0x04)
		bsp_lcd_set_bit(&LCD_PORT, D7);
	else
		bsp_lcd_clear_bit(&LCD_PORT, D7);
}

void lcd_delay_ms(uint32_t ms)
{
	_delay_ms(ms);
}

void lcd_delay_us(uint32_t us)
{
	_delay_us(us);
}