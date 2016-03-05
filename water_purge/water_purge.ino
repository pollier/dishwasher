void setup(void)
{
	Serial.begin(9600);
	pinMode(5, OUTPUT);
}
void loop(void)
{
	digitalWrite(5, LOW);
	delay(35000);
	digitalWrite(5, HIGH);
}
