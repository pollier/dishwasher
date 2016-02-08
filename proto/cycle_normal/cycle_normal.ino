#include "dishwasher.h"
#define PIN_HEAT	8
// OneWire DS18S20, DS18B20, DS1822 Temperature Example
//
// http://www.pjrc.com/teensy/td_libs_OneWire.html
//
// The DallasTemperature library can do all this work for you!
// http://milesburton.com/Dallas_Temperature_Control_Library
OneWire  ds(10);  // on pin 10 (a 4.7K resistor is necessary)

void	chauffe(int minutes)
{
	static unsigned long	offset = 0;
	static unsigned long	len = 0;
	float					temp;
	temp = temp_float();
	if (!offset && !len)
	{
		offset = millis();
		len = minutes * 3600 * 1000;
	}
	if ((len + offset) < millis())
	{
		if (temp < 65)
		{
			digitalWrite(PIN_HEAT, LOW);
		}
		else
		{
			digitalWrite(PIN_HEAT, HIGH);
		}
	}
}
void setup(void)
{
	Serial.begin(9600);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
}

void loop(void)
{
	digitalWrite(7, HIGH);
	digitalWrite(8, HIGH);
	delay(100);
	Serial.println(millis());
	digitalWrite(7, LOW);
	delay(200);
	digitalWrite(8, LOW);
	delay(200);
	temp_serial();
}
