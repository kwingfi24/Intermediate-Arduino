int ledPin = 7;
int photoPin1 = 2;
int photoPin2 = 3;
boolean state = 0;
void setup()
{
	Serial.begin(9600);
	pinMode(photoPin1, INPUT_PULLUP);
	pinMode(photoPin2, INPUT_PULLUP);
	pinMode(ledPin, OUTPUT);
	attachInterrupt(digitalPinToInterrupt(3), on, RISING);
	attachInterrupt(digitalPinToInterrupt(2), off, FALLING);
}

void loop()
{
	Serial.print(state);
	delay(200);
}

void on()
{
	digitalWrite(ledPin, HIGH);
	state++;
}

void off()
{
	digitalWrite(ledPin, LOW);
}
