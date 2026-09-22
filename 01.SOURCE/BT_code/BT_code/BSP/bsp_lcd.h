/*
 * bsp_lcd.h
 */ 
#ifndef BSP_LCD_H_
#define BSP_LCD_H_

#include <stdint.h>

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

#endif /* BSP_LCD_H_ */