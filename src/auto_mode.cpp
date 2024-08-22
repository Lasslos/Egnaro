// Sets LED according to some rules.
#include <Arduino.h>
#include <config.h>
#include <auto_mode.h>
#include <neopixel.h>

int motionStatePrevious = LOW;

void autoMode()
{

  int sensorValue = analogRead(LDR);
  int motionStateCurrent = digitalRead(MOTION_SENSOR);

  if (motionStatePrevious != LOW or motionStateCurrent != HIGH) {
    led_off();
  } else if (sensorValue > 200) {
    led_off();
  } else {
    led_on();
  }

  motionStatePrevious = motionStateCurrent;
}