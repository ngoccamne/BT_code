/*
 * bsp_button.h
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_

#include <stdint.h>

#define BUTTON_PRESSED   0u
#define BUTTON_RELEASED  1u

uint8_t (uint8_t port_num, uint8_t pin_num);
void bsp_button_init(uint8_t port_num, uint8_t pin_num);

#endif 