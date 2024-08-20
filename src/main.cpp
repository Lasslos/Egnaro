#include <Arduino.h>
#include <control_switch_state.cpp>
#include <auto_mode.cpp>

#define LED_PIN 32

// 0 is off, 1 is auto, 2 is on
int switch_state = 2;

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
