#include "dishwasher.h"

OneWire  ds(7);  // on pin 10 (a 4.7K resistor is necessary)

void setup(void)
{
	Serial.begin(9600);
	pinMode(7, OUTPUT);
	pinMode(8, INPUT_PULLUP);
}

void loop(void)
{
	Serial.println(digitalRead(pin));
}
