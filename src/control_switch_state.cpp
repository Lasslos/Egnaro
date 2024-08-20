#include <control_switch_state.h>
#include <config.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

void writeState(const int& state, LiquidCrystal_I2C& lcd) {
  lcd.clear();
  lcd.setCursor(0, 0); // Erstes Argument: Spalte, zweites: Zeile
  switch (state)
  {
  case 0:
    lcd.print("Off");
    break;
  case 1:
    lcd.print("Auto");
    break;
  case 2:
    lcd.print("On");
    break;
  default:
    break;
  }
}

bool can_switch = true;

void controlSwitchState(int &state, LiquidCrystal_I2C& lcd) {
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

