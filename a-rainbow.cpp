/*
 * This is a minimal example, see extra-examples.cpp for a version
 * with more explantory documentation, example routines, how to
 * hook up your pixels and all of the pixel types that are supported.
 *
 */

#include "application.h"
#include "neopixel.h"

SYSTEM_MODE(AUTOMATIC);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D2
#define PIXEL_COUNT 24
#define PIXEL_PINb D3
#define PIXEL_COUNTb 12

#define PIXEL_TYPE WS2812B
void rainbow(uint8_t wait);
uint32_t Wheel(byte WheelPos);
void rainbowb(uint8_t wait);
uint32_t Wheelb(byte WheelPos);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
Adafruit_NeoPixel stripb = Adafruit_NeoPixel(PIXEL_COUNTb, PIXEL_PINb, PIXEL_TYPE);
void setup()
{
  strip.begin();
  stripb.begin();
  strip.show(); // Initialize all pixels to 'off'
  stripb.show(); // Initialize all pixels to 'off'
}
void loop()
{
  rainbow(20);
  rainbowb(20);
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void rainbowb(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<stripb.numPixels(); i++) {
      stripb.setPixelColor(i, Wheel((i+j) & 255));
    }
    stripb.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheelb(byte WheelPos) {
  if(WheelPos < 85) {
   return stripb.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return stripb.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return stripb.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
