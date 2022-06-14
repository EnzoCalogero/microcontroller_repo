/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
#include <Wire.h>
#include <SparkFun_APDS9960.h>
 
// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
uint8_t proximity_data = 0;
int pos = 0;    // variable to store the servo position
int speed = 5;  // gears velocity...
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

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
 for (speed= 1; speed<= 15; speed+=1){  
  
  for (pos = 0; pos <= 180; pos += speed) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= speed) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
 }
 
 //speed down
  for (speed= 15; speed> 1; speed-=1){  
  
  for (pos = 0; pos <= 180; pos += speed) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= speed) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
 }
 
}


void loop() {
  pos=90;
  myservo.write(pos);
  delay(150); 
  // Read the proximity value
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");
  } else {
    Serial.print("Proximity: ");
    Serial.println(proximity_data);
    if (proximity_data>100) {
      
      servo_routin_01();
      }
  
  }
   
    // Wait 250 ms before next reading
  delay(100);
}