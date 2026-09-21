/*
 * bsp_button.h
 */ 

#ifndef BSP_BUTTON_H_
#define BSP_BUTTON_H_

#include <stdint.h>
#include "gpio.h"

#define BUTTON_PORT_ID		PORTA_ID
#define BUTTON_PIN_ID		PIN0_ID

uint8_t bsp_button_get_state(uint8_t port_num, uint8_t pin_num);
void bsp_button_init(uint8_t port_num, uint8_t pin_num);

#endif 