#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    10

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);


   second (); 
 
 
}

void loop() {
}

void second () {
    for (int j=0; j < 3;j++) {
      for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 255, 0,0);
        FastLED.show();
        delay(200);
      }
      for (int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB ( 0, 255, 0);
        FastLED.show();
        delay(200);
      }
    }
    
    for (int k=0; k <= NUM_LEDS; k++) {
    leds[k] = CRGB(150, 0, 255);
    FastLED.show();
    delay(100);
    }
  }

  
void first() {
  leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);  
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(500);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[3] = CRGB(150, 0, 255);
  FastLED.show();
  delay(500);
  leds[4] = CRGB(255, 200, 20);
  FastLED.show();
  delay(500);
  leds[5] = CRGB(85, 60, 180);
  FastLED.show();
  delay(500);
  leds[6] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
}
