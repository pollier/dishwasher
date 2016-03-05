#include "test.h"

void setup(void)
{
	Serial.begin(9600);
	pinMode(PIN_THERMOSTAT, INPUT_PULLUP);
	pinMode(PIN_PORTE, INPUT_PULLUP);

	pinMode(PIN_HEAT, OUTPUT);
	digitalWrite(PIN_HEAT, HIGH);

	pinMode(PIN_PUMP_PURGE, OUTPUT);
	digitalWrite(PIN_PUMP_PURGE, HIGH);

	pinMode(PIN_PUMP_CYCLE, OUTPUT);
	digitalWrite(PIN_PUMP_CYCLE, HIGH);

	pinMode(PIN_VANNE, OUTPUT);
	digitalWrite(PIN_VANNE, HIGH);
}

void loop(void)
{
	// digitalWrite(PIN_HEAT, LOW);
	// Serial.println("PIN_HEAT : LOW");
	// delay(1000);
	// digitalWrite(PIN_HEAT, HIGH);
	// Serial.println("PIN_HEAT : HIGH");
	//
	// digitalWrite(PIN_PUMP_PURGE, LOW);
	// Serial.println("PIN_PUMP_PURGE : LOW");
	// delay(1000);
	// digitalWrite(PIN_PUMP_PURGE, HIGH);
	// Serial.println("PIN_PUMP_PURGE : HIGH");
	//
	// digitalWrite(PIN_PUMP_CYCLE, LOW);
	// Serial.println("PIN_PUMP_CYCLE : LOW");
	// delay(1000);
	// digitalWrite(PIN_PUMP_CYCLE, HIGH);
	// Serial.println("PIN_PUMP_CYCLE : HIGH");
	//
	// digitalWrite(PIN_VANNE, LOW);
	// Serial.println("PIN_VANNE : LOW");
	// delay(1000);
	// digitalWrite(PIN_VANNE, HIGH);
	// Serial.println("PIN_VANNE : HIGH");
		Serial.print("Level : ");
		Serial.println(analogRead(PIN_LEVEL));
		delay(500);
}
