int drain_pump = 13;                 // LED connected to digital pin 13
int cycle_pump = 13;                 // LED connected to digital pin 13
int heat = 13;                 // LED connected to digital pin 13
int vanne = 13;                 // LED connected to digital pin 13
int ledPin = 46;                 // LED connected to digital pin 13

void setup()
{
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
}

void loop()
{
  digitalWrite(ledPin, HIGH);   // sets the LED on
  delay(1000);                  // waits for a second
  digitalWrite(ledPin, LOW);    // sets the LED off
  delay(1000);                  // waits for a second
}
