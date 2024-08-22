#include <neopixel.h>
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN     14
#define LED_COUNT  25
#define BRIGHTNESS 200 // Set BRIGHTNESS to about 1/5 (max = 255)

namespace settings {
  int brightness = 255;
  int red = 255;
  int green = 255;
  int blue = 255;
};

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup_LED_Strip(){
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS);
}

void led_on(int brightness) {
  strip.setBrightness(255 / (6 - brightness));
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(255, 255, 255));
  }
  strip.show();
}

void led_on_api() {
  strip.setBrightness(settings::brightness);
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(settings::red, settings::green, settings::blue));
  }
  strip.show();
}

void led_off() {
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
  strip.show();
}