/*
 * avr_compat.h
 *
 * Created: 9/30/2026 12:49:09 AM
 *  Author: HTSang
 */ 


#ifndef AVR_COMPAT_H
#define AVR_COMPAT_H

#define ATOMIC_RESTORESTATE 0

#define ATOMIC_BLOCK(type) \
	for (int _atomic_once = 0; _atomic_once < 1; _atomic_once++)

#endif