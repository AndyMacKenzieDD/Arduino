#define potPin 0
#define ledPin 11

void setup() 
{
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  analogWrite(ledPin, map(analogRead(potPin), 0, 1023, 0, 255));
}
