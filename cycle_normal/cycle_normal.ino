#include	"dishwasher.h"

void setup(void)
{
	Serial.begin(9600);
	pinMode(PIN_PRESSION, INPUT_PULLUP);
	pinMode(PIN_HEAT, OUTPUT);
	pinMode(PIN_PUMP_PURGE, OUTPUT);
	pinMode(PIN_PUMP_CYCLE, OUTPUT);
	pinMode(PIN_DISPENSER, OUTPUT);
	pinMode(PIN_VANNE, OUTPUT);
	pinMode(PIN_PORTE, INPUT_PULLUP);
}

void loop(void)
{
	float  temp = 0;
  get_temperature(&temp);
  Serial.println(temp);
}
