void setup(void)
{
	Serial.begin(9600);
	pinMode(8, OUTPUT);
}
void loop(void)
{
	digitalWrite(8, LOW);
	delay(35000);
	digitalWrite(8, HIGH);
}
