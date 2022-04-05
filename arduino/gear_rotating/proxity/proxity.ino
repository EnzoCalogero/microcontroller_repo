#include <Wire.h>
#include <SparkFun_APDS9960.h>
 
// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint8_t proximity_data = 0;
int BUILTIN1=6;
int BUILTIN2=8;
int i;
 
 
void setup() {
  pinMode(BUILTIN1, OUTPUT);
  pinMode(BUILTIN2, OUTPUT);
  i = 0;
  digitalWrite(BUILTIN1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(BUILTIN2, LOW);   // turn the LED on (HIGH is the voltage level)
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
 
void loop() {
  
  // Read the proximity value
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");
  } else {
    Serial.print("Proximity: ");
    Serial.println(proximity_data);
    if(proximity_data >100){
      i++;
      if(i%2){
          Serial.println("pari");
          Serial.println(i);
          digitalWrite(BUILTIN1, HIGH);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(BUILTIN2, LOW);   // turn the LED on (HIGH is the voltage level)
          delay(500);
    }
    else{
          Serial.println("dispari");
          Serial.println(i);
          digitalWrite(BUILTIN1, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(BUILTIN2, HIGH);   // turn the LED on (HIGH is the voltage level)
      
      }
    }
  }
 
  
  // Wait 250 ms before next reading
  delay(250);
}
