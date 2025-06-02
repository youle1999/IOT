#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN    5
#define NUMPIXELS       5

Adafruit_NeoPixel strip(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void colorDotOn(int i, uint32_t color);
void colorDotOff(int i);

void setup() {
  Serial.begin(115200);
  delay(200);
  strip.begin();
  strip.show();
}

void loop() {
  colorDotOn(0, strip.Color(255, 0, 0));
  delay(1000);
  colorDotOff(0);
  delay(1000);
  
  colorDotOn(4, strip.Color(0, 255, 0));
  delay(1000);
  colorDotOff(4);
  delay(1000);
}

/**
 * i番目のLEDを color の色で点灯する
 */
void colorDotOn(int i, uint32_t color){
  if (i < 0 || i >= NUMPIXELS) return;
  strip.setPixelColor(i, color);
  strip.show();
}

/**
 * i番目のLEDを消灯する
 */
void colorDotOff(int i){
  if (i < 0 || i >= NUMPIXELS) return;
  strip.setPixelColor(i, 0);
  strip.show();
}

void colorWipe(uint32_t color, int wait) {
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}
