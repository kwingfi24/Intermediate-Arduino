#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);
int ledPin = 6;
int potPin = A0;
void setup()
{
	pinMode(ledPin, OUTPUT);
	pinMode(potPin, INPUT);
	lcd.init();
	lcd.backlight();
	lcd.begin(16, 2);
	
	
}

void loop()
{
	int potValue = analogRead(potPin);
	analogWrite(ledPin, potValue);
	delay(100);
	lcd.setCursor(0, 0);
	lcd.print(potValue);
	lcd.print("                ");
}
