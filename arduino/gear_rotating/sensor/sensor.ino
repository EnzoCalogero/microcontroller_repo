#include <Wire.h>
#include <SparkFun_APDS9960.h>
 
// Pins
#define APDS9960_INT    2 // Needs to be an interrupt pin
 
// Constants
 
// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
int isr_flag = 0;

int BUILTIN1=6;
int BUILTIN2=8;
int i=0;
 
void setup() {
  pinMode(BUILTIN1, OUTPUT);
  pinMode(BUILTIN2, OUTPUT);
 
  // Set interrupt pin as input
  pinMode(APDS9960_INT, INPUT);
 
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - GestureTest"));
  Serial.println(F("--------------------------------"));
 
  // Initialize interrupt service routine
  attachInterrupt(0, interruptRoutine, FALLING);
 
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
 
  // Start running the APDS-9960 gesture sensor engine
  if ( apds.enableGestureSensor(true) ) {
    Serial.println(F("Gesture sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during gesture sensor init!"));
  }
}
 
void loop() {
  if( isr_flag == 1 ) {
     Serial.println("flag");
    detachInterrupt(0);
    if ( apds.isGestureAvailable() ) {
      Serial.println(i);
      i=i+1;
      if (i % 2){
        Serial.println("pari");
        digitalWrite(BUILTIN1, HIGH);   // turn the LED on (HIGH is the voltage level)
        digitalWrite(BUILTIN2, LOW);   // turn the LED on (HIGH is the voltage level)
      }
    else {
         Serial.println("dispari");
         digitalWrite(BUILTIN1, LOW);   // turn the LED on (HIGH is the voltage level)
         digitalWrite(BUILTIN2, HIGH);   // turn the LED on (HIGH is the voltage level)
     }
    }
    
    //handleGesture1();
    isr_flag = 0;
    attachInterrupt(0, interruptRoutine, FALLING);
  }
}
 
void interruptRoutine() {
  isr_flag = 1;
}


void handleGesture1() {
    if ( apds.isGestureAvailable() ) {
        i=i+1;
        if (i % 1){
      Serial.println("pari");
      digitalWrite(BUILTIN1, HIGH);   // turn the LED on (HIGH is the voltage level)
         digitalWrite(BUILTIN2, LOW);   // turn the LED on (HIGH is the voltage level)
    }
    else {
         Serial.println("dispari");
         digitalWrite(BUILTIN1, LOW);   // turn the LED on (HIGH is the voltage level)
         digitalWrite(BUILTIN2, HIGH);   // turn the LED on (HIGH is the voltage level)
      }
    
  }
}

 
void handleGesture() {
    if ( apds.isGestureAvailable() ) {
    switch ( apds.readGesture() ) {
      case DIR_UP:
        Serial.println("UP");
         digitalWrite(BUILTIN1, HIGH);   // turn the LED on (HIGH is the voltage level)
         digitalWrite(BUILTIN2, LOW);   // turn the LED on (HIGH is the voltage level)
  
        break;
      case DIR_DOWN:
        Serial.println("DOWN");
        digitalWrite(BUILTIN1, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(BUILTIN2, HIGH);    // turn the LED off by making the voltage LOW
        break;
      case DIR_LEFT:
        Serial.println("LEFT");
         digitalWrite(BUILTIN1, HIGH);   // turn the LED on (HIGH is the voltage level)
         digitalWrite(BUILTIN2, LOW);   // turn the LED on (HIGH is the voltage level)
  
        break;
      case DIR_RIGHT:
        Serial.println("RIGHT");
        digitalWrite(BUILTIN1, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(BUILTIN2, HIGH);    // turn the LED off by making the voltage LOW
        break;
      case DIR_NEAR:
        Serial.println("NEAR");
         digitalWrite(BUILTIN1, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(BUILTIN2, HIGH);    // turn the LED off by making the voltage LOW
        break;
      case DIR_FAR:
        Serial.println("FAR");
        digitalWrite(BUILTIN1, HIGH);   // turn the LED on (HIGH is the voltage level)
         digitalWrite(BUILTIN2, LOW);   // turn the LED on (HIGH is the voltage level)
        break;
      default:
        Serial.println("NONE");
        digitalWrite(BUILTIN1, HIGH);   // turn the LED on (HIGH is the voltage level)
        digitalWrite(BUILTIN2, LOW);   // turn the LED on (HIGH is the voltage level)
    }
  }
}
