/*
 * bsp_dht.h
 */ 

#ifndef BSP_DHT_H_
#define BSP_DHT_H_

#include <avr/io.h>
#include "gpio.h"

#define		DHT_PORT		PORTC_ID
#define		DHT_DDRC		DDRC
#define		DHT_DATA_PIN	PIN0_ID 

void bsp_dht_init(void);
void bsp_dht_set_output(void);
void bsp_dht_set_input(void);
void dht_write_low(void);
void dht_write_high(void);

#endif