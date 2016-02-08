#include "dishwasher.h"

void	chauffe(int minutes)
{
	static unsigned long	offset = 0;
	static unsigned long	len = 0;
	float					temp;
	temp = temp_float();
	Serial.println(temp);
	if (!offset && !len)
	{
		offset = millis();
		Serial.print("offset :");
		Serial.println(offset);
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
