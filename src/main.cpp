#include <main.h>
#include <config.h>
#include <Arduino.h>
#include <control_switch_state.h>
#include <auto_mode.h>
#include <neopixel.h>

#include <U8g2lib.h>  // Display-Library
#include <Wire.h>     // IIC-Library

// Adresse des Displays
// Es kann sein, dass ihr eine andere Adresse verwenden müsst
// Ihr findet unter dem Beispielcode im Handout eine Liste möglicher Adressen
#define DISP_ADDR 0x78

#define DISP_SDA 21   // ESP-Pin verbunden mit SDA
#define DISP_SCL 22   // ESP-Pin verbunden mit SCL


/* Konstruktion Display-Objekt mit Namen "display" */
U8G2_SSD1306_128X64_NONAME_1_SW_I2C display(U8G2_R0, DISP_SCL, DISP_SDA);


void setup() {
  //pinMode(LED_PIN, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(MOTION_SENSOR, INPUT);

  setup_LED_Strip();

  Serial.begin(9600);

  display.setI2CAddress(DISP_ADDR);  // Setzen der IIC-Adresse vom Display
  display.begin();  // Initialisierung des Displays
}

void loop() {
  controlSwitchState(switch_state, display);

  switch (switch_state)
  {
  case 0:
    led_off(); 
    break;
  case 1:
    autoMode();
    break;
  case 2:
    led_on();
    break;
  default:
    break;
  }
}
