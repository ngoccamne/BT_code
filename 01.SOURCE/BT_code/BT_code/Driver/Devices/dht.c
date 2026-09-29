/*
 * dht.c
 */ 
#include "board.h"
#include "dht.h"
#include "uart.h"
#include <util/delay.h>

int wait_for_state(int state, int timeout_us)
{
	int count = 0;
	while (1)
	{
 
		int current_state = (GPIO_readPin(DHT_PORT, DHT_DATA_PIN) != 0) ? 1 : 0;
		
		if (current_state == state) break; 
		
		if (count >= timeout_us) return FAIL;
		
		count += 2;
		_delay_us(2);
	}
	return count;
}

int dht11_read(dht11_t *dht11, int time_out)
{
	int time_high = 0;
	int time_low = 0;
	uint8_t data[5] = {0, 0, 0, 0, 0};
	
	bsp_dht_set_output();
	dht_write_low();
	_delay_ms(20);       
	bsp_dht_set_input();  
	
	if (wait_for_state(0, 100) == FAIL) return FAIL; 
	if (wait_for_state(1, 100) == FAIL) return FAIL; 
	if (wait_for_state(0, 100) == FAIL) return FAIL; 
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			time_low = wait_for_state(1, 100);  
			time_high = wait_for_state(0, 120); 
			
			if (time_low == FAIL || time_high == FAIL) 
			{
				return FAIL;
			}
			
			if (time_high > time_low)
			{
				data[i] |= (1 << (7 - j));
			}
		}
	}

	uint8_t crc = data[0] + data[1] + data[2] + data[3];
	
	if (crc == data[4])
	{
		dht11->humid = data[0] + (float)data[1] / 10.0;
		dht11->temp = data[2] + (float)data[3] / 10.0;
		return SUCCESS;
	}
	
	return FAIL;
}