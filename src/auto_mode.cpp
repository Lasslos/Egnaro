// Sets LED according to some rules.
#include <Arduino.h>
#include <config.h>
#include <auto_mode.h>
#include <neopixel.h>


void autoMode() {

    int sensorValue = analogRead(LDR);
    Serial.println(sensorValue);
    if(sensorValue<300 or sensorValue<2000&&sensorValue>1400)
    {
      led_on();
    }
    else
    {
      led_off();
    }
  delay(50);
}