/*
 * dht.h
 */ 

#ifndef DHT11_H_
#define DHT11_H_

#include "bsp_dht.h"
#include <util/delay.h>

#define		SUCCESS		0
#define		FAIL		1
typedef struct 
{
	float temp;
	float humid;
} dht11_t;

int wait_for_state(int state, int timeout_us);
void hold_low(int hold_time_us);
int dht11_read(dht11_t *dht11, int time_out);

#endif 