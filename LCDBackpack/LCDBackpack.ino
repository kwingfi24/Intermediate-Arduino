#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16.2);
int val=0;
int buttonState;
int buttonno;

void setup() {
pinMode(13, INPUT);
lcd.init();
lcd.backlight();
lcd.setCursor(0, 0);
lcd.print("Button Presses");
}

void loop() {
buttonState = digitalRead(13);
if (buttonState == HIGH)&&(buttonno=1)){
val++;
butoonno=0;
lcd.setCursor(0, 1);
lcd.print(val);
}
}
