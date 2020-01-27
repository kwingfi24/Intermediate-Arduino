#include "Arduino.h"
#define WLED	13

void setup()
 {
  pinMode(WLED, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
    analogWrite(WLED, 0);  
    Serial.print("x");
    delay(1000);                   
    analogWrite(WLED, 255);   
    Serial.print("o");
    delay(1000);               
}
