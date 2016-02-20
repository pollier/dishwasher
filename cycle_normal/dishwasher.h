#ifndef		dishwasher_h
#define		dishwasher_h

#define		PIN_PRESSION	3
#define		PIN_HEAT		2
#define		PIN_PUMP_PURGE	4
#define		PIN_PUMP_CYCLE	5
#define		PIN_DISPENSER	6
#define		PIN_VANNE	   	7
#define		PIN_PORTE	   	8
#define		PIN_ONEWIRE		9
#define   DS18B20       0x28     // Adresse 1-Wire du DS18B20

void		porte_check();
void		chauffe(unsigned long secondes)

#endif
