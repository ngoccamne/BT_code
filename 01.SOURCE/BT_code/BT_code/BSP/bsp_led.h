/*
 * bsp_led.h
 */ 

#ifndef BSP_LED_H_
#define BSP_LED_H_

#include "gpio.h"

#define LED_PORT_ID		PORTB_ID
#define LED_PIN_ID		PIN0_ID

void bsp_led_on(uint8_t port_num, uint8_t pin_num);
void bsp_led_off(uint8_t port_num, uint8_t pin_num);
void bsp_led_init(uint8_t port_num, uint8_t pin_num);

#endif 