#define ledPin 11
#define switchPin 8
#define smallSwitchPin 7

int lastButton = LOW;
int currentButton = LOW;
int ledLevel = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(smallSwitchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  currentButton = Check(lastButton);

  switch(currentButton)
  {
    case 1:
    {
      if(lastButton != 1) ledLevel += 51;
      break;
    }
    case 2:
    {
      if(lastButton != 2) ledLevel -= 51;
      break;
    }
  }

  lastButton = currentButton;
  
  if(ledLevel > 255) ledLevel = 255;
  if(ledLevel < 0) ledLevel = 0;

  analogWrite(ledPin, ledLevel);
}

int Check(int lastButton)
{
  if(digitalRead(switchPin) == HIGH)
  {
    delay(5);
    if(digitalRead(switchPin) == HIGH && lastButton != 1) return 1;
  }
  else if(digitalRead(smallSwitchPin) == HIGH)
  {
    delay(5);
    if(digitalRead(smallSwitchPin) == HIGH && lastButton != 2) return 2;
  }
  else
  {
    return 0;
  }
}
