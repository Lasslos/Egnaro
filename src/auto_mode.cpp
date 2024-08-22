// Sets LED according to some rules.
#include <Arduino.h>
#include <config.h>
#include <auto_mode.h>
#include <neopixel.h>

int moveCounter = 0;

void autoMode()
{

  int sensorValue = analogRead(LDR);
  int motionStateCurrent = digitalRead(MOTION_SENSOR);

  if (motionStateCurrent == HIGH) {
    moveCounter = 100;
  }

  Serial.println("AutoMode:");
  Serial.println(sensorValue);
  Serial.println(moveCounter);

  if (moveCounter == 0) {
    led_off();
  } else if (sensorValue > 200) {
    moveCounter--;
    led_off();
  } else {
    moveCounter--;
    led_on();
  }
}