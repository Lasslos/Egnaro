#pragma once
#include <main.h>
#include <config.h>
#include <Arduino.h>
#include <control_switch_state.h>
#include <auto_mode.h>


// 0 is off, 1 is auto, 2 is on
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  controlSwitchState();

  switch (switch_state)
  {
  case 0:
    digitalWrite(LED_PIN, LOW);  
    break;
  case 1:
    autoMode();
    break;
  case 2:
    digitalWrite(LED_PIN, HIGH);
    break;
  default:
    break;
  }
}
