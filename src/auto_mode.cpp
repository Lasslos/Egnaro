// Sets LED according to some rules.
#include <Arduino.h>
#include <config.h>
#include <auto_mode.h>


void autoMode() {

    int sensorValue = analogRead(LDR);
    if(sensorValue>512)
    {
      digitalWrite(LED_PIN,HIGH);
    }
    else
    {
      digitalWrite(LED_PIN, LOW);
      delay(50);
    }
  
}