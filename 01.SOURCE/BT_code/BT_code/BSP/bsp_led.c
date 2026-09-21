/*
 * bsp_led.c
 */ 

#include "bsp_led.h"

void bsp_led_on(uint8_t port_num, uint8_t pin_num)
{
	GPIO_writePin(port_num, pin_num, LOGIC_HIGH);
}

void bsp_led_off(uint8_t port_num, uint8_t pin_num)
{
	GPIO_writePin(port_num, pin_num, LOGIC_LOW);
}

void bsp_led_init(uint8_t port_num, uint8_t pin_num)
{
	GPIO_setupPinDirection(port_num, pin_num, PIN_OUTPUT);
	bsp_led_off(port_num, pin_num);
}