#include <NewPing.h>
#define TRIGGER_PIN 11
#define ECHO_PIN 13
#define MAX_DISTANCE 100
int buttonpin = 9;
int buttonState = LOW;
NewPing myHC_SR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup()
{
	Serial.begin(9600);
	pinMode(buttonpin, INPUT);
}
 
void loop()
{
	buttonState=digitalRead(buttonpin);
	if (buttonState == HIGH)
	{
    Serial.println(myHC_SR04.ping_cm());
	delay(50);
	}
	if (buttonState == LOW)
{
	Serial.println("Push the button");
	delay(50);
}
 
}   
