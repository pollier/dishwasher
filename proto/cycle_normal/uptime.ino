#include "dishwasher.h"

void	uptime()
{
	Serial.print(" uptime : ");
	Serial.print(millis() / 1000);
	Serial.println(" seconds");
}
