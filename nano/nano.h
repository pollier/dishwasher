#ifndef		NANO_H
#define		NANO_H

#define		RINCAGE			0

#define		PIN_LEVEL		0
#define		PIN_HEAT		8
#define		PIN_VANNE		6
#define		PIN_PUMP_CYCLE	7
#define		PIN_PUMP_PURGE	5
#define		PIN_THERMOSTAT	3
#define		PIN_PORTE		2

enum states
{
  THERMO,
  HEAT,
  CYCLE,
  LEVEL,
  VANNE,
  PURGE,
  PORTE
};

#endif
