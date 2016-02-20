// #include "dishwasher.h"
//
// void	chauffe(unsigned long secondes)
// {
// 	static unsigned long	start_time = 0;
// 	static unsigned long	len = 0;
// 	if(digitalRead(PIN_PRESSION))
// 	{
// 		if(secondes && start_time && len && millis() < (start_time + len))
// 		{
// 			digitalWrite(PIN_HEAT, LOW);
// 		}
// 		else
// 		{
// 			digitalWrite(PIN_HEAT, HIGH);
// 		}
// 	}
// }
