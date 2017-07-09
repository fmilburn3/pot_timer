/*
 * Varies the flashing period of the onboard red LED using a potentiometer
 * attached to a MSP430G2553.  Tested with Energia V17.
 */
 
const int potPin = 7;  
const int minTime = 500;
const int maxTime = 10000;
unsigned long waitTime = 0;
unsigned long startTime = 0;
int ledState = HIGH;

void setup()
{
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  startTime = millis();  
  digitalWrite(RED_LED, ledState);
}

void loop()
{
  waitTime = map(analogRead(potPin), 0, 1023, minTime, maxTime);
  if ((startTime + waitTime) <= millis())
  {
    Serial.println(waitTime);
    ledState = !ledState;
    startTime = millis();
    digitalWrite(RED_LED, ledState);
  }
}  
