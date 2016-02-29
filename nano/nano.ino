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

OneWire ds(PIN_ONEWIRE); // Création de l'objet OneWire ds

void	getTemperature(float *temp, boolean iter)
{
	byte data[9], addr[8];
	// data : Données lues depuis le scratchpad
	// addr : adresse du module 1-Wire détecté

	if (!ds.search(addr))
	{
		// Recherche un module 1-Wire
		ds.reset_search();    // Réinitialise la recherche de module
		return;         // Retourne une erreur
	}

	if (OneWire::crc8(addr, 7) != addr[7]) // Vérifie que l'adresse a été correctement reçue
	return;                        // Si le message est corrompu on retourne une erreur

	if (addr[0] != DS18B20) // Vérifie qu'il s'agit bien d'un DS18B20
	return;         // Si ce n'est pas le cas on retourne une erreur

	ds.reset();             // On reset le bus 1-Wire
	ds.select(addr);        // On sélectionne le DS18B20

	ds.write(0x44, 1);      // On lance une prise de mesure de température

	if(!iter)
	{
		return;
	}
	else
	{
		delay(800);
	}
	ds.reset();             // On reset le bus 1-Wire
	ds.select(addr);        // On sélectionne le DS18B20
	ds.write(0xBE);         // On envoie une demande de lecture du scratchpad

	for (byte i = 0; i < 9; i++) // On lit le scratchpad
	data[i] = ds.read();       // Et on stock les octets reçus

	// Calcul de la température en degré Celsius
	*temp = ((data[1] << 8) | data[0]) * 0.0625;

	// Pas d'erreur
	return;
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
	long			tmp;
	float			mesure = 0;

	tmp = millis();
	getTemperature(&mesure, (last_time - tmp > 750));
	if(last_time - tmp > 750 && mesure)
	{
		Serial.print("Temperature :\t");
		Serial.println(mesure);
	}
	if(last_time - tmp > 1000)
	{
		Serial.print("HEAT target :\t");
		Serial.println(t_target);
		Serial.print("Thermostat :\t");
		Serial.println(digitalRead(PIN_THERMOSTAT));
	}

	if(digitalRead(PIN_THERMOSTAT) || check_level() || mesure > t_target)
	{
		digitalWrite(PIN_HEAT, HIGH);
		if(check_level())
		{
			digitalWrite(PIN_PUMP_CYCLE, HIGH);
			if(last_time - tmp > 1000)
			{
				Serial.println("Cycle off");
			}
		}
		if(last_time - tmp > 1000)
		{
			Serial.println("Heat off");
		}
	}

	else
	{
		if(last_time - tmp > 1000)
		{
			Serial.println("Heat on");
		}
		digitalWrite(PIN_HEAT, LOW);
		digitalWrite(PIN_PUMP_CYCLE, LOW);
	}

	last_time = millis();
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
	long	tmp = 0;

	last_time = millis();
	while(digitalRead(PIN_PORTE))
	{
		digitalWrite(PIN_HEAT, HIGH);
		digitalWrite(PIN_PUMP_CYCLE, HIGH);
		digitalWrite(PIN_PUMP_PURGE, HIGH);
		digitalWrite(PIN_VANNE, HIGH);
		tmp = millis();
		if(last_time - tmp > 1000)
		{
			Serial.println("Porte ouverte !!!");
			last_time = millis();
		}
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
	Serial.println("Debut du programme dans 3 secondes");
	delay(3000);
	fillwater();
	Serial.println("full water");
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
