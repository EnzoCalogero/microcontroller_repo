#include <Wire.h>
#include <SparkFun_APDS9960.h>

// Pins
#define APDS9960_INT    2 // Needs to be an interrupt pin
int relay = 3;

// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
int isr_flag = 0;
unsigned long time_to_waite=500; //time to wait in seconds...
int status=0;
float status_Millis=0.0;
float current_Millis=0.0;
float delta=0.0;

void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - GestureTest"));
  Serial.println(F("--------------------------------"));
  //relay side 
  pinMode(relay, OUTPUT);
  
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
  if (status ==0){
    digitalWrite(relay, LOW);
     }
    else {
      digitalWrite(relay, HIGH);
      current_Millis = millis() / 1000.;
      delta= current_Millis - status_Millis;
      
      Serial.println(current_Millis);
      Serial.println(status_Millis);
      Serial.println(delta);
      if (delta > time_to_waite) {
            status = 0;
            }
    }
  if( isr_flag == 1 ) {
    detachInterrupt(0);
    handleGesture();
    isr_flag = 0;
    attachInterrupt(0, interruptRoutine, FALLING);
  }
}

void interruptRoutine() {
  isr_flag = 1;
}

void handleGesture() {
    if ( apds.isGestureAvailable() ) {
    switch ( apds.readGesture() ) {
      case DIR_UP:
        Serial.println("UP");
        break;
      case DIR_DOWN:
        Serial.println("DOWN");
        break;
      case DIR_LEFT:
        Serial.println("LEFT");
        left_move();
        break;
      case DIR_RIGHT:
        Serial.println("RIGHT");
        right_move();
        break;
      case DIR_NEAR:
        Serial.println("NEAR");
        break;
      case DIR_FAR:
        Serial.println("FAR");
        break;
      default:
        Serial.println("NONE");
    }
  }
}


void right_move() {
        //digitalWrite(relay, HIGH);       // 1. turns on
        status=1;
        status_Millis = millis() / 1000.;
        Serial.println("inside:");
        Serial.println(status_Millis);
        delay(100);
 }


 void left_move() {
       status=0;
       status_Millis=0;
 } 
