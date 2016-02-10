#ifndef		dishwasher_h
#define		dishwasher_h
#include	<OneWire.h>

#define		PIN_HEAT		8
#define		PIN_PRESSION	8
#define		PIN_PORTE		6

float		temp_float();
void		chauffe(int minutes);
void		porte_check();

#endif
