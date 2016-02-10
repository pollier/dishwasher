#include "dishwasher.h"

void	porte_check()
{
	if(digitalRead(PIN_PORTE))
	{
		return;
	}
	else
	{
		delay(100);
		porte_check();
	}
}
