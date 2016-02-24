void setup()
{
	Serial.begin(9600);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, INPUT_PULLUP);
	pinMode(13, OUTPUT);
	digitalWrite(4, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(6, HIGH);
	digitalWrite(7, HIGH);
	digitalWrite(8, HIGH);
	digitalWrite(9, HIGH);
	digitalWrite(10, HIGH);
	digitalWrite(11, HIGH);
	digitalWrite(13, LOW);
}

void chauffe(int secondes, bool test, unsigned long offset)
{
	static unsigned long	len;
	static unsigned long	start;
	unsigned long		current;
	if(test)
	{
		start = millis();
		len = secondes * 1000;
	}
	current = millis();
	if(current < (start + len + offset))
	{
		Serial.println(offset);
		digitalWrite(4, LOW);
	}
	else
	{
		Serial.println(offset);
		digitalWrite(4, HIGH);
	}
}

void loop()
{
	unsigned long start = 1;
	unsigned long offset = 0;
	unsigned long tmp;
	unsigned long tmp2;
	while(1)
	{
		tmp2 = millis();
		while(!digitalRead(12))
		{
			digitalWrite(4, HIGH);
			digitalWrite(5, HIGH);
			digitalWrite(6, HIGH);
			digitalWrite(7, HIGH);
			digitalWrite(8, HIGH);
			digitalWrite(9, HIGH);
			digitalWrite(10, HIGH);
			digitalWrite(11, HIGH);
			digitalWrite(13, HIGH);
			Serial.println("Porte Ouverte");
			delay(1000);
		}
		tmp = millis();
		offset += tmp - tmp2;
		digitalWrite(13, LOW);
		Serial.println(offset);
		Serial.println(millis());
		chauffe(25, start, offset);
		delay(200);
		if(start)
			start = 0;
	}
}
