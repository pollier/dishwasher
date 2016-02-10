#include "dishwasher.h"

OneWire  ds(7);  // on pin 10 (a 4.7K resistor is necessary)

void setup(void)
{
	Serial.begin(9600);
	pinMode(PIN_HEAT, OUTPUT);
	pinMode(PIN_PRESSION, INPUT_PULLUP);
	pinMode(PIN_PORTE, INPUT_PULLUP);
}

void loop(void)
{
	uptime();
	porte_check();
	Serial.println("1");
	temp_serial();
	Serial.println("2");
}
