#include <main.h>
#include <config.h>
#include <Arduino.h>
#include <control_switch_state.h>
#include <auto_mode.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();     // Ausschalten mit lcd.noBacklight()
  lcd.setCursor(0, 0); // Erstes Argument: Spalte, zweites: Zeile
  lcd.print("Hello World");
}

void loop() {
  controlSwitchState(switch_state, lcd);

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
