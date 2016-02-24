

void setup()
{
	Serial.begin(9600);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
}

void loop()
{
	while(1)
	{

		digitalWrite(5, LOW);
		Serial.println("digitalWrite(5, LOW);");
		digitalWrite(6, LOW);
		Serial.println("digitalWrite(6, LOW);");
		digitalWrite(7, LOW);
		Serial.println("digitalWrite(7, LOW);");
		digitalWrite(8, LOW);
		Serial.println("digitalWrite(8, LOW);");
		digitalWrite(9, LOW);
		Serial.println("digitalWrite(9, LOW);");
		digitalWrite(10, LOW);
		Serial.println("igitalWrite(10, LOW);");
		digitalWrite(11, LOW);
		Serial.println("igitalWrite(11, LOW);");
		digitalWrite(12, LOW);
		delay(1000);

		digitalWrite(5, HIGH);
		Serial.println("igitalWrite(5, HIGH);");
		digitalWrite(6, HIGH);
		Serial.println("igitalWrite(6, HIGH);");
		digitalWrite(7, HIGH);
		Serial.println("igitalWrite(7, HIGH);");
		digitalWrite(8, HIGH);
		Serial.println("igitalWrite(8, HIGH);");
		digitalWrite(9, HIGH);
		Serial.println("igitalWrite(9, HIGH);");
		digitalWrite(10, HIGH);
		Serial.println("dgitalWrite(10, HIGH);");
		digitalWrite(11, HIGH);
		Serial.println("dgitalWrite(11, HIGH);");
		digitalWrite(12, HIGH);
	}Serial.println("dgitalWrite(12, HIGH);");
}
