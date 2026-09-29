/*
 * bsp_dht.c
 */ 

#include "app_dht.h"
#include <util/delay.h>
#include "board.h"
#include "gpio.h"

void bsp_dht_init(void)
{
	GPIO_setupPinDirection(DHT_PORT, DHT_DATA_PIN, PIN_INPUT);
	GPIO_writePort(DHT_PORT, 1);
}

//MCU control DHT
void bsp_dht_set_output(void)
{
	GPIO_setupPinDirection(DHT_PORT, DHT_DATA_PIN, PIN_OUTPUT);
}

//DHT send data to MCU 
void bsp_dht_set_input(void)
{
	GPIO_setupPinDirection(DHT_PORT, DHT_DATA_PIN, PIN_INPUT);
	GPIO_writePort(DHT_PORT, 1);
}

void dht_write_low(void)
{
	bsp_dht_set_output();
	GPIO_writePin(DHT_PORT, DHT_DATA_PIN, LOGIC_LOW);
}

void dht_write_high(void)
{
	bsp_dht_set_output();
	GPIO_writePin(DHT_PORT, DHT_DATA_PIN, LOGIC_HIGH);
}

