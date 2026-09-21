/*
 * bsp_led.h
 */ 

#ifndef LED_H_
#define LED_H_

#include "gpio.h"

#define LED_PORT_ID		PORTB_ID
#define LED_PIN_ID		PIN0_ID

bsp_led_on(uint8_t port_num, uint8_t pin_num);
bsp_led_off(uint8_t port_num, uint8_t pin_num);
bsp_led_init(uint8_t port_num, uint8_t pin_num);

#endif 