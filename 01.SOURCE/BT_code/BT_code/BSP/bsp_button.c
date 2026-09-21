/*
 * bsp_button.c
 */ 

#include "bsp_button.h"

uint8_t bsp_button_get_state(uint8_t port_num, uint8_t pin_num)
{
	return GPIO_readPin(port_num, pin_num);
}

void bsp_button_init(uint8_t port_num, uint8_t pin_num)
{
	GPIO_setupPinDirection(port_num, pin_num, PIN_INPUT);
	GPIO_writePort(port_num, LOGIC_HIGH);
}