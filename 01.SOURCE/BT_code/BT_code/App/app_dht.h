/*
 * app_dht.h
 */ 

#ifndef APP_DHT_H_
#define APP_DHT_H_

#include "dht.h"

void app_dht_init(void);
void app_dht_update(void);
float app_dht_get_temp(void);
float app_dht_get_humid(void);

#endif