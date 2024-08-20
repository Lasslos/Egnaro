#include <control_switch_state.h>
#include <config.h>
#include <Arduino.h>
#include <U8g2lib.h>  // Display-Library
#include <Wire.h>     // IIC-Library

void writeState(const int& state, U8G2_SSD1306_128X64_NONAME_1_SW_I2C& display) {
  String text = "";
  switch (state)
  {
  case 0:
    text = "Off";
    break;
  case 1:
    text = "Auto";
    break;
  case 2:
    text = "On";
    break;
  default:
    break;
  }
  /* Beginn Picture-Loop */
  display.firstPage();  // Initialisierung Picture-Loop
  do {
    /* Hier Anzeigeinhalt frei definieren */
    display.setFont(u8g2_font_ncenB14_tr);  // optional: gewünschte Schriftart
    display.drawStr(0, 20, text);
  } while (display.nextPage());  // Sobald Inhalt angezeigt: Verlassen der Schleife
  /* Ende Picture-Loop */
}

bool can_switch = true;

void controlSwitchState(int &state, U8G2_SSD1306_128X64_NONAME_1_SW_I2C& lcd) {
  int pressedState = !digitalRead(BUTTON);
  if (!pressedState) {
    can_switch = true;
    return;
  }
  if (!can_switch) {
    return;
  }
  can_switch = false;
  state++;
  state = state % 3;
  writeState(state, lcd);
}

