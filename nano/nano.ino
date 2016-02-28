#include "nano.h"

void setup()
{
	Serial.begin(9600);
	pinMode(PIN_LEVEL, INPUT_PULLUP);
	pinMode(PIN_HEAT, OUTPUT);
	digitalWrite(PIN_HEAT, HIGH);
	pinMode(PIN_VANNE, OUTPUT);
	digitalWrite(PIN_VANNE, HIGH);
	pinMode(PIN_PUMP_PURGE, OUTPUT);
	digitalWrite(PIN_PUMP_PURGE, HIGH);
	pinMode(PIN_PUMP_CYCLE, OUTPUT);
	digitalWrite(PIN_PUMP_CYCLE, HIGH);
}

void loop()
{
	Serial.println("Debut du programme dans 3 secondes");
	delay(3000);
	while(1)
	{
		Serial.print("Niveau d'eau :");
		Serial.println(digitalRead(PIN_LEVEL));
		digitalWrite(PIN_PUMP_CYCLE, LOW);
		digitalWrite(PIN_HEAT, LOW);
		delay(1800000);
		digitalWrite(PIN_HEAT, HIGH);
		digitalWrite(PIN_PUMP_PURGE, HIGH);
		delay(5000);

	}
}
