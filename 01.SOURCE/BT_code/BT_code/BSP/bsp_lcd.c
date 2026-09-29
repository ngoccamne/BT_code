/*
 * bsp_lcd.c
 */

#include "board.h"
#include "bsp_lcd.h"
#include <util/delay.h>

static inline void bsp_lcd_force_write_mode(void)
{
	LCD_CONTROL_PORT &= ~(1u << RW);
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
	LCD_CONTROL_PORT |= (1u << RS);
}

void lcd_rs_low(void)
{
	bsp_lcd_force_write_mode();
	LCD_CONTROL_PORT &= ~(1u << RS);
}

void lcd_en_high(void)
{
	bsp_lcd_force_write_mode();
	LCD_CONTROL_PORT |= (1u << E);
}

void lcd_en_low(void)
{
	bsp_lcd_force_write_mode();
	LCD_CONTROL_PORT &= ~(1u << E);
}

void lcd_write_bus4(uint8_t nibble)
{
	bsp_lcd_force_write_mode();
	
	if (nibble & 0x01)
		LCD_PORT |= (1u << D4);
	else
		LCD_PORT &= ~(1u << D4);
		
	if (nibble & 0x02)
		LCD_PORT |= (1u << D5);
	else
		LCD_PORT &= ~(1u << D5);
	
	if (nibble & 0x04)
		LCD_PORT |= (1u << D6);
	else
		LCD_PORT &= ~(1u << D6);

	if (nibble & 0x08)
		LCD_PORT |= (1u << D7);
	else
		LCD_PORT &= ~(1u << D7);
}

void lcd_delay_ms(uint16_t ms)
{
	while (ms > 0)
	{
		_delay_ms(1); 
		ms--;
	}
}

void lcd_delay_us(uint16_t us)
{
	while (us > 0)
	{
		_delay_us(1); 
		us--;
	}
}