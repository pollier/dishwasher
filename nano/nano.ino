#include "nano.h"

void	setup()
{
	Serial.begin(115200);
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

void	heat_on()
{
	digitalWrite(PIN_HEAT, LOW);
	debug_serial(1, HEAT);
}
void	heat_off()
{
	digitalWrite(PIN_HEAT, HIGH);
	debug_serial(0, HEAT);
}

void	cycle_on()
{
	digitalWrite(PIN_PUMP_CYCLE, LOW);
	debug_serial(1, CYCLE);
}
void	cycle_off()
{
	digitalWrite(PIN_PUMP_CYCLE, HIGH);
	debug_serial(0, CYCLE);
}

void	purge_on()
{
	digitalWrite(PIN_PUMP_PURGE, LOW);
	debug_serial(1, PURGE);
}
void	purge_off()
{
	digitalWrite(PIN_PUMP_PURGE, HIGH);
	debug_serial(0, PURGE);
}

boolean	check_level()
{
	int		retour_read = 0;
	retour_read = analogRead(PIN_LEVEL);
	if(retour_read > 100)
	{
		debug_serial(1, LEVEL);
		return true;
	}
	else
	{
		debug_serial(0, LEVEL);
		return false;
	}
}

boolean	check_thermostat()
{
	if(digitalRead(PIN_THERMOSTAT))
	{
		debug_serial(1, LEVEL);
		return true;
	}
	debug_serial(0, LEVEL);
	return false;
}

void	debug_serial(boolean value, int flag)
{
	static boolean		heat	= 0;
	static boolean		thermo	= 0;
	static boolean		cycle	= 0;
	static boolean		vanne	= 0;
	static boolean		purge	= 0;
	static boolean		level	= 0;
	static boolean		porte	= 0;
	boolean				print	= 0;
	unsigned long		uptime	= 0;
	unsigned long		uptime2	= 0;

	if(flag == HEAT && heat != value)
	{
		heat = value;
		print = 1;
	}
	else if(flag == THERMO && thermo != value)
	{
		thermo = value;
		print = 1;
	}
	else if(flag == CYCLE && cycle != value)
	{
		cycle = value;
		print = 1;
	}
	else if(flag == VANNE && vanne != value)
	{
		vanne = value;
		print = 1;
	}
	else if(flag == PURGE && purge != value)
	{
		purge = value;
		print = 1;
	}
	else if(flag == LEVEL && level != value)
	{
		level = value;
		print = 1;
	}
	else if(flag == PORTE && porte != value)
	{
		porte = value;
		print = 1;
	}

	if(print)
	{
		Serial.println("\n\n");
		Serial.print("Chauffe :\t");
		Serial.println(heat ? "TRUE" : "FALSE");
		Serial.print("Thermostat :\t");
		Serial.println(thermo ? "TRUE" : "FALSE");
		Serial.print("Cycle :\t\t");
		Serial.println(cycle ? "TRUE" : "FALSE");
		Serial.print("Vanne :\t\t");
		Serial.println(vanne ? "TRUE" : "FALSE");
		Serial.print("Purge :\t\t");
		Serial.println(purge ? "TRUE" : "FALSE");
		Serial.print("Porte :\t\t");
		Serial.println(porte ? "TRUE" : "FALSE");
		Serial.print("Level :\t\t");
		Serial.println(level ? "TRUE" : "FALSE");
		Serial.print("\n");
		Serial.print("Uptime : ");
		uptime2 = millis();
		uptime = uptime2 / 1000;
		Serial.print(uptime / 60);
		Serial.print(" minutes ");
		Serial.print(uptime % 60);
		Serial.print((uptime % 60) > 1 ? " secondes " : " seconde ");
		Serial.print(uptime2 % 1000);
		Serial.println(" ms");
	}
}

void	fillwater()
{
	while(!check_level())
	{
		digitalWrite(PIN_VANNE, LOW);
		debug_serial(1, VANNE);
	}
	digitalWrite(PIN_VANNE, HIGH);
	debug_serial(0, VANNE);
}

void	chauffe()
{
	// if(check_thermostat() && check_level())
	if(check_thermostat())
	{
		heat_on();
		cycle_on();
	}
	else
	{
		heat_off();

		if(check_level())
		{
			cycle_on();
		}
		else
		{
			cycle_off();
		}
	}
}

long	check_porte()
{
	unsigned long enter = millis();
	if(digitalRead(PIN_PORTE))
	{
		while(digitalRead(PIN_PORTE))
		{
			digitalWrite(PIN_HEAT, HIGH);
			debug_serial(0, HEAT);
			digitalWrite(PIN_PUMP_CYCLE, HIGH);
			debug_serial(0, CYCLE);
			digitalWrite(PIN_PUMP_PURGE, HIGH);
			debug_serial(0, PURGE);
			digitalWrite(PIN_VANNE, HIGH);
			debug_serial(0, VANNE);
			debug_serial(1, PORTE);
		}
		delay(2000);
		debug_serial(0, PORTE);
		return (millis() - enter);
	}
	return (0);
}

void	stop()
{
	Serial.println("Fini !");
	Serial.println("Fini !");
	Serial.println("Fini !");

	while(1)
	{
		delay(100000);
	}
}

void	loop()
{
	unsigned long	start;
	unsigned long	current;
	unsigned long	duree_lavage = 2400000;
	unsigned long	duree_rincage = 300000;

	fillwater();
	delay(1000);
	start = millis();
	while(1)
	{
		duree_lavage += check_porte();
		chauffe();
		current = millis();
		if(current - start > duree_lavage)
		break;
	}
	heat_off();
	cycle_off();
	purge_on();
	delay(20000);
	purge_off();
	while(RINCAGE)
	{
		duree_rincage += check_porte();
		chauffe();
		current = millis();
		if(current - start > duree_rincage)
		break;
	}
	if(RINCAGE)
	{
		heat_off();
		cycle_off();
		purge_on();
		delay(20000);
		purge_off();
	}
	stop();
}
