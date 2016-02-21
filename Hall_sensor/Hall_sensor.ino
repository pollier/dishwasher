#define		PIN_SENSOR	12
#define		PIN_LED		8

void setup()
{
	Serial.begin(9600);
	pinMode(PIN_SENSOR,INPUT_PULLUP);
	pinMode(13, OUTPUT);

}

void loop()
{
	digitalWrite(13, HIGH);
	if(digitalRead(PIN_SENSOR))
	{
		Serial.println("NULL");
		digitalWrite(PIN_LED, LOW);
	}
	else
	{
		Serial.println("1");
		digitalWrite(PIN_LED, HIGH);
	}
	delay(250);
}
