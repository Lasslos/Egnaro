// Sets LED according to some rules.
#include <Arduino.h>
#include <config.h>
#include <auto_mode.h>

int motionStatePrevious = LOW;

void autoMode()
{

  int sensorValue = analogRead(LDR);
  int motionStateCurrent = digitalRead(MOTION_SENSOR);

  if (motionStatePrevious != LOW or motionStateCurrent != HIGH) {
    digitalWrite(LED_PIN, LOW);
  } else if (sensorValue > 200) {
    digitalWrite(LED_PIN, LOW);
  } else {
    digitalWrite(LED_PIN, HIGH);
  }

  motionStatePrevious = motionStateCurrent;
}