/*#include <Arduino.h>

#include <Adafruit_NeoPixel.h>

#define PIN         25    // Verwendeter GPIO-Pin
#define NUMPIXELS   25    // Anzahl an LEDs in Strip

// Konstruktion Strip-Objekt mit Namen "pixels"
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//Bedingungen: soll bei Sonnenlicht ausbleiben
//Bedingungen: soll bei Dunkelheit und Anwesenheit


void setup_LED_Strip() {
  pixels.begin();    // NeoPixel Library wird initialisiert
  pixels.setBrightness(50);  // 0-255. Maximal halbe Helligkeit nutzen
}

void turn_on_led_strip() {
  for (int i = 0; i < NUMPIXELS; i++) {
    //pixels.Color nimmt R,G,B Werte von 0,0,0 bis 255,255,255
    //der i-te (Start bei 0) Pixel wird auf (0, 50, 0) gesetzt
    pixels.setPixelColor(i, pixels.Color(245, 229, 179));

    // Nach Veränderungen müssen diese angezeigt werden
    pixels.show();
    
    delay(0);
  }
}*/