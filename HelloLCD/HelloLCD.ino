#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int time=0;

void setup()
{
	lcd.begin(16, 2);
	lcd.setCursor(0, 0);
    lcd.print("Hello World");
}
	

void loop()
{
	time = millis();	
	lcd.setCursor(0, 1);
	lcd.print(time/1000);
}

