#include <Servo.h>
Servo myservo;
/* Ultrasonic sensor Pins:
-VCC: +5VDC
-Trig : Trigger (INPUT) - Pin13
-Echo: Echo (OUTPUT) - Pin 11
-GND: GND */
const int trigPin = 2; // Trigger
const int echoPin = 3; // Echo
#define MAX_DISTANCE 200
long duration;
int distance;
int dst;
void setup()
{
	myservo.attach(6);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	Serial.begin(9600);
}

void loop()
{
	dst = getDistance();
	Serial.println(dst);
	delay(100);
	if ((dst>0) && (dst < 5))
	{
		//Serial.println("<5");
		myservo.write(151);
	}
	if (dst >= 5 && dst < 10)
	{
		//Serial.println("<10");
		myservo.write(60);
	}
	if (dst >= 10)
	{
		//Serial.println(">10");
		myservo.write(90);
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
