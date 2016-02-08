#ifndef		dishwasher_h
#define		dishwasher_h
#include	<OneWire.h>

#define		PIN_HEAT		8
#define		PIN_PRESSION	8

void		temp_serial();
float		temp_float();
void		chauffe(int minutes);
#endif
