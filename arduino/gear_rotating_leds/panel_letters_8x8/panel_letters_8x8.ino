#include <Wire.h>
#include <Servo.h>
#include <FastLED.h>
#include <SparkFun_APDS9960.h>
 
// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();

#define LED_PIN     5
#define NUM_LEDS    46

CRGB leds[NUM_LEDS];
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
uint8_t proximity_data = 0;
int pos = 0;    // variable to store the servo position
int speed = 25;  // gears velocity...

void leds_startup() {
    for (int j=0; j < 2; j++) {
      for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 255, 0,0);
        FastLED.show();
        delay(30);
      }
      for (int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB ( 0, 255, 0);
        FastLED.show();
        delay(30);
      }
    }
    
    for (int k=0; k <= NUM_LEDS; k++) {
    leds[k] = CRGB(150, 0, 255);
    FastLED.show();
    delay(60);
    }
  }



void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(4, OUTPUT); 
  digitalWrite(4, HIGH);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

leds_startup();
 // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("------------------------------------"));
  Serial.println(F("APDS-9960 - ProximitySensor"));
  Serial.println(F("------------------------------------"));
  
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
  
  // Adjust the Proximity sensor gain
  if ( !apds.setProximityGain(PGAIN_2X) ) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }
  
  // Start running the APDS-9960 proximity sensor (no interrupts)
  if ( apds.enableProximitySensor(false) ) {
    Serial.println(F("Proximity sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during sensor init!"));
  }
 

  
}

void servo_routin_01() {
 //speed up
   for (int k=0; k <= NUM_LEDS; k++) {
        leds[k] = CRGB(random(0, 255), random(0, 255), random(0, 255));
        FastLED.show();
        delay(10);
      }
 for (speed= 1; speed<= 3; speed+=3){  
  
  for (pos = 10; pos <= 170; pos += speed) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
      
        
    Serial.println(pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(150);                       // waits 15 ms for the servo to reach the position
    }
      for (int k=0; k <= NUM_LEDS; k++) {
        leds[k] = CRGB(random(0, 255), random(0, 255), random(0, 255));
        FastLED.show();
        delay(10);
      }
  for (pos = 170; pos >= 10; pos -= speed) { // goes from 180 degrees to 0 degrees
    
    Serial.println(pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(150);                       // waits 15 ms for the servo to reach the position
    }
 }

   for (int k=0; k <= NUM_LEDS; k++) {
        leds[k] = CRGB(random(0, 255), random(0, 255), random(0, 255));
        FastLED.show();
        delay(10);
      }
 //speed down
  for (speed= 3; speed> 1; speed-=1){  
  
  for (pos = 10; pos <= 170; pos += speed) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
     
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(150);                       // waits 15 ms for the servo to reach the position
    Serial.println(pos);
  }
    for (int k=0; k <= NUM_LEDS; k++) {
        leds[k] = CRGB(random(0, 255), random(0, 255), random(0, 255));
        FastLED.show();
        delay(10);
      }
  for (pos = 170; pos >= 10; pos -= speed) { // goes from 180 degrees to 0 degrees
     
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(150);    
    // waits 15 ms for the servo to reach the position
    Serial.println(pos);
  }
 }

    for (int k=0; k <= NUM_LEDS; k++) {
    leds[k] = CRGB(150, 0, 255);
    FastLED.show();
    delay(60);
    }
 
}


void loop() {
  pos=90;
  myservo.write(pos);
  delay(150); 
  // Read the proximity value
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");
  } 
  else {
    Serial.print("Proximity: ");
    Serial.println(proximity_data);
    if (proximity_data>200) {
       servo_routin_01();
       leds_startup();
       }
  }
  
  // Wait  before next reading
  delay(100);
}
