#define red 9
#define green 10
#define blue 11
#define button 8
#define pot 0

bool lastButton = LOW;
bool currentButton = LOW;
int currentColor = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(button, INPUT);
  pinMode(pot, INPUT);
  
  randomSeed(analogRead(1));
}

void loop() 
{
  /*
  analogWrite(red, random(255));
  analogWrite(green, random(255));
  analogWrite(blue, random(255));

  delay(100);
  */
  
  bool currentButton = debounce(lastButton);
  
  if(currentButton != lastButton && currentButton == HIGH)
  {
    currentColor++;
    if(currentColor == 3) currentColor = 0;
  }
  lastButton = currentButton;

  if(currentColor == 0)
  {
    analogWrite(red, map(analogRead(pot), 0, 1023, 0, 255));
  }
  else if(currentColor == 1)
  {
    analogWrite(green, map(analogRead(pot), 0, 1023, 0, 255));
  }
  else if(currentColor == 2)
  {
    analogWrite(blue, map(analogRead(pot), 0, 1023, 0, 255));
  }
}

bool debounce(bool last)
{
  bool current = digitalRead(button);
  if(last != current)
  {
    delay(5);
    current = digitalRead(button);
  }
  return current;
}
