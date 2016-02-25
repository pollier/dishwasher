void setup(void)
{
	Serial.begin(9600);
	pinMode(2, INPUT_PULLUP);
}
void loop(void)
{
	Serial.println(digitalRead(2));
	// delay(100);
}
