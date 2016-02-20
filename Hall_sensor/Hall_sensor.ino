int const sensorPin = 12;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin,INPUT_PULLUP);
  }

void loop()
{
  Serial.println(digitalRead(sensorPin));
}
