#include "dishwasher.h"
#define PIN_HEAT	8

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
