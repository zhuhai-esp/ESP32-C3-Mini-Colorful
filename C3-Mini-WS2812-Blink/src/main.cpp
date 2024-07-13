#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

// Matrix Data PIN
#define PIN_PIXS 8
#define PIX_NUM 1

Adafruit_NeoPixel pixels(PIX_NUM, PIN_PIXS, NEO_GRB + NEO_KHZ800);

void inline initBoard() {
  pixels.begin();
  pixels.setBrightness(128);
  pixels.clear();
}

void inline pixelsCheck() {
  sleep(1);
  pixels.fill(0xFF0000, 0, 64);
  pixels.show();
  sleep(1);
  pixels.fill(0xFF00, 0, 64);
  pixels.show();
  sleep(1);
  pixels.fill(0xFF, 0, 64);
  pixels.show();
  sleep(1);
  pixels.fill(0xFFFFFF, 0, 64);
  pixels.show();
  sleep(1);
  pixels.clear();
  sleep(1);
}

void setup() {
  initBoard();
  pixelsCheck();
}

void loop() {
  for (uint16_t i = 0; i < 65536; i += 30) {
    pixels.rainbow(i, -1, 255, 255);
    pixels.show();
  }
}
