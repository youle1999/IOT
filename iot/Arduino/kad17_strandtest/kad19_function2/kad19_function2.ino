#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN    5
#define NUMPIXELS  5

Adafruit_NeoPixel strip(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void colorRun(uint32_t color, int wait);

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(50);
}

void loop() {
  colorRun(strip.Color(255, 0, 0), 50);  // 赤を50ミリ秒ごとに下→上へ１つずつ点灯→消灯
  delay(1000);
  colorRun(strip.Color(0, 255, 0), 50);  // 緑を50ミリ秒ごとに下→上へ１つずつ点灯→消灯
  delay(1000);
}

void colorRun(uint32_t color, int wait) {
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
    strip.setPixelColor(i, 0);
    strip.show();
  }
}
