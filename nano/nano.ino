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

boolean	check_level()
{
	int		retour_read = 0;
	retour_read = analogRead(PIN_LEVEL);
	if(retour_read > 100)
	{
		return true;
	}
	return false;
}

void	fillwater()
{
	while(!check_level())
	{
		digitalWrite(PIN_VANNE, LOW);
	}
	digitalWrite(PIN_VANNE, HIGH);
}

void	chauffe(float t_target)
{
	static	long	last_time = 0;
	long			current_time;
	float			mesure = 0;current_time = millis();
	getTemperature(&mesure, (current_time - last_time > 750));
	if(current_time - last_time > 750 && mesure)
	{
		Serial.print("Temperature :\t");
		Serial.println(mesure);
	}
	if(current_time - last_time > 1000)
	{
		Serial.println("\n\n");
		Serial.print("HEAT target :\t");
		Serial.println(t_target);
		Serial.print("Thermostat :\t");
		Serial.println(digitalRead(PIN_THERMOSTAT));
	}
	if(!digitalRead(PIN_THERMOSTAT) || !check_level())
	{
		digitalWrite(PIN_HEAT, HIGH);
		if(check_level())
		{
			digitalWrite(PIN_PUMP_CYCLE, HIGH);
			if(current_time - last_time > 1000)
			{
				Serial.println("Cycle\t\toff");
			}
		}
		if(current_time - last_time > 1000)
		{
			Serial.println("Heat\t\toff");
		}
	}
	else
	{
		if(current_time - last_time > 1000)
		{
			Serial.println("Heat\t\ton");
			Serial.println("Cycle\t\ton");
			Serial.print("Level : \t");
			Serial.println(check_level());
		}
		digitalWrite(PIN_HEAT, LOW);
		digitalWrite(PIN_PUMP_CYCLE, LOW);
	}
	if(current_time - last_time > 1000)
	{
		last_time = millis();
	}
}

void	purge()
{
	Serial.println("purge");
	digitalWrite(PIN_PUMP_PURGE, LOW);
	delay(20000);
	digitalWrite(PIN_PUMP_PURGE, HIGH);
}

void	check_porte()
{
	long	last_time = 0;
	long	current_time = 0;last_time = millis();
	if(digitalRead(PIN_PORTE))
	{
		while(digitalRead(PIN_PORTE))
		{
			digitalWrite(PIN_HEAT, HIGH);
			digitalWrite(PIN_PUMP_CYCLE, HIGH);
			digitalWrite(PIN_PUMP_PURGE, HIGH);
			digitalWrite(PIN_VANNE, HIGH);
			current_time = millis();
			if(current_time - last_time > 1000)
			{
				Serial.println("Porte ouverte !!!");
				last_time = millis();
			}	}
		delay(2000);
	}
}

void	stop()
{
	while(1)
	{
		Serial.println("Fini !");
		delay(1000);
	}
}

void	loop()
{
	long	start;
	long	current;
	fillwater();
	Serial.println("full water");
	delay(1000);
	start = millis();
	while(1)
	{
		check_porte();
		chauffe(60);
		current = millis();
		if(current - start > 2400000)
		break;
	}
	digitalWrite(PIN_HEAT, HIGH);
	digitalWrite(PIN_PUMP_CYCLE, HIGH);
	digitalWrite(PIN_VANNE, HIGH);
	purge();
	stop();
}
