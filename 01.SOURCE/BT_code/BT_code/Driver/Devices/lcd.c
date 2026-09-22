/*
 * lcd.c
 */ 

#include "lcd.h"

#ifndef LCD_WEAK
#if defined(__GNUC__)
#define LCD_WEAK __attribute__((weak))
#elif defined(__ICCARM__) || defined(__CC_ARM) || defined(__ARMCC_VERSION)
#define LCD_WEAK __weak
#else
#define LCD_WEAK
#warning "Weak attribute not supported on this compiler, overriding may not work as expected"
#endif
#endif

LCD_WEAK void lcd_rs_high(void) { (void)0; }
LCD_WEAK void lcd_rs_low(void)  { (void)0; }
LCD_WEAK void lcd_en_high(void) { (void)0; }
LCD_WEAK void lcd_en_low(void)  { (void)0; }

LCD_WEAK void lcd_write_bus4(uint8_t nibble)
{
	(void)nibble;
}

static void lcd_pulse_enable(void)
{
	lcd_en_high();
	lcd_delay_us(1);
	lcd_en_low();
	lcd_delay_us(50);
}

static void lcd_write_4bits(uint8_t nibble)
{
	lcd_write_bus4(nibble & 0x0F);
	lcd_pulse_enable();
}

static void lcd_send(uint8_t value, uint8_t isData)
{
	if (isData)
	{
		lcd_rs_high(); //data
	}
	else
	{
		lcd_rs_low(); //command
	}
	
	lcd_write_4bits(value >> 4); //send high nibble
	lcd_write_4bits(value & 0x0F); //send low nibble
	
	if (!isData && (value == 0x01u || value == 0x02u))
	{
		lcd_delay_ms(2);
	}
}

void lcd_send_command(uint8_t cmd)
{
	lcd_send(cmd, 0u);
}

void lcd_send_data(uint8_t data)
{
	lcd_send(data, 1u);
}

void lcd_init(void) {
	lcd_delay_ms(40);
	lcd_rs_low();
	lcd_en_low();
	
	lcd_write_4bits(0x03u);
	lcd_delay_ms(5);

	lcd_write_4bits(0x03u);
	lcd_delay_us(150);

	lcd_write_4bits(0x03u);
	lcd_delay_us(150);
	
	lcd_write_4bits(0x02u);
	lcd_delay_us(150);
	
	lcd_send_command(0x28u);
	lcd_send_command(0x0Cu);
	lcd_send_command(0x06u);
	lcd_send_command(0x01u);
}

void lcd_clear(void)
{
	lcd_send_command(0x01u);
}

void lcd_home(void)
{
	lcd_send_command(0x02u);
}

void lcd_put_char(char c)
{
	lcd_send_data((uint8_t)c);
}

void lcd_put_string(const char *s)
{
	if (s == 0) return;

	while (*s != '\0') {
		lcd_put_char(*s++);
	}
}

void lcd_set_cursor(uint8_t col, uint8_t row)
{
	uint8_t addr;
	
	if (col > 15u)
	{
		col = 15u;
	}
	
	switch(row)
	{
		case 0u:
		addr = 0x00u + col;
		break;
		case 1u:
		default:
		addr = 0x40u + col;
		break;
	}
	
	lcd_send_command(0x80u | addr);
}