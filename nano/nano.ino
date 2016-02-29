#include "nano.h"

void	setup()
{
	Serial.begin(9600);
	pinMode(PIN_HEAT, OUTPUT);
	digitalWrite(PIN_HEAT, HIGH);

	pinMode(PIN_VANNE, OUTPUT);
	digitalWrite(PIN_VANNE, HIGH);

	pinMode(PIN_PUMP_PURGE, OUTPUT);
	digitalWrite(PIN_PUMP_PURGE, HIGH);

	pinMode(PIN_PUMP_CYCLE, OUTPUT);
	digitalWrite(PIN_PUMP_CYCLE, HIGH);

	pinMode(PIN_THERMOSTAT, INPUT_PULLUP);
	pinMode(PIN_PORTE, INPUT_PULLUP);
}

void	fillwater()
{
	while
}

void	chauffe(float t_target)
{
	Serial.print("HEAT target : ");
	Serial.println(t_target);
}

void	start_cycle()
{
	Serial.println("cycle");
}

void	purge()
{
	Serial.println("purge");
}

bool	check_water_level()
{

}

void	loop()
{
	Serial.println("Debut du programme dans 3 secondes");
	delay(3000);

	fillwater();
	start_cycle();
	chauffe(60.5);
	purge();
	while(1)
	{

	}
}
