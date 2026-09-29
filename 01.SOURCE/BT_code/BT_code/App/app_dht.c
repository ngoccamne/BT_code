 /*
 * app_dht.c
 */ 

#include "app_dht.h"
#include "bsp_dht.h"
#include "sys_time.h"

static dht11_t dht;
static uint32_t last_read_time;

static float temp = 0;
static float humid = 0;

void app_dht_init(void)
{
	bsp_dht_init();
	last_read_time = get_sys_time_ms();
}

void app_dht_update(void)
{
	if(get_sys_time_ms() - last_read_time >= 2000)
	{
		if(dht11_read(&dht, 100) == SUCCESS)
		{
			temp = dht.temp;
			humid = dht.humid;
		}
		last_read_time = get_sys_time_ms();
	}
}

float app_dht_get_temp(void)
{
	return temp;
}

float app_dht_get_humid(void)
{
	return humid;
}