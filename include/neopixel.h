#pragma once
void setup_LED_Strip();
/// @brief Turns on the led with given brightness
/// @param brightness Number from 1-5. Other inputs are undefined.
void led_on(int brightness = 5);
void led_off();