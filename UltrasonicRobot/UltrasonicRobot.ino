#include <Servo.h>
#include <Servo.h>
Servo myservo1;
Servo myservo2;
/* Ultrasonic sensor Pins:
-VCC: +5VDC
-Trig : Trigger (INPUT) - Pin 2
-Echo: Echo (OUTPUT) - Pin 3
-GND: GND
Servo Pins:
-Servo 1 (Yellow) - Pin 13
-Servo 2 (Orange) - Pin 9     
*/
const int trigPin = 2; // Trigger
const int echoPin = 3; // Echo
#define MAX_DISTANCE 200
long duration;
int distance;
int dst;
int switchPin = 6;
int switchState = 1;
int ledPin = 7;
void setup()
{
	myservo1.attach(13);
	myservo2.attach(9);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	pinMode(ledPin, OUTPUT);
	pinMode(switchPin, INPUT);
	Serial.begin(9600);
}

void loop()
{
	(digitalWrite(ledPin, HIGH));
	dst = getDistance();
	Serial.println(dst);
	delay(100);
	if (dst <= 5)
	{
		myservo1.write(20);
		myservo2.write(160);
	}
	if ((dst > 5) && (dst < 12))
	{
		myservo1.write(45);
		myservo2.write(135);
	}
	if (dst >= 12 && dst < 20)
	{
		myservo1.write(70);
		myservo2.write(110);
	}
	if (dst >= 20)
	{
		myservo1.write(88);
		myservo2.write(88);
	}
}

int getDistance()
{
	digitalWrite(trigPin, LOW);
	delayMicroseconds(5);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	pinMode(echoPin, INPUT);
	duration = pulseIn(echoPin, HIGH);
	distance = (duration/2) /29.1;
	return distance;
}
