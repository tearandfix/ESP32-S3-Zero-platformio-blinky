#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 21

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(200);

  leds[0] = CRGB::Black;
  FastLED.show();
  delay(200);
}
