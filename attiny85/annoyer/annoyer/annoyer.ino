//#include "DigiKeyboard.h"
//This is the output pin on the Arduino
int sensorPin = A0; //Analog Pin
int solenoidPin = 3;
int timer_count = 1000;//5000; redused for troubleshooting

// Variables
//int activeLight = 200;  //switch on light level
int darkTreshold = 400; //Night light level

void setup() 
{
  Serial.begin(9600);
//  DigiKeyboard.sendKeyStroke(0);
  pinMode(solenoidPin, OUTPUT);          //Sets that pin as an output
  pinMode(sensorPin, INPUT);

}

void cycle() 
{
  while(timer_count >90){
    
    digitalWrite(solenoidPin, HIGH);      //Switch Solenoid ON
    delay(50);                          //Wait 1 Second
    digitalWrite(solenoidPin, LOW);       //Switch Solenoid OFF
    delay(timer_count);                          //Wait 
    Serial.print("timer_count: ");
  //  DigiKeyboard.println("timer_count: ");
    //Serial.println(timer_count);
    
 //DigiKeyboard.println(timer_count);
    timer_count=timer_count -(timer_count/100);
    if (timer_count <101) {
       timer_count=101;
      }
      if (light_reader() ==0){
            timer_count=0;
    }
  }
}


int light_reader(void){
  int status = 1;
  int sensorValue = analogRead(sensorPin); //Read the sensor
  if (sensorValue >darkTreshold) {
      status = 0;
      Serial.println("reached");
      //DigiKeyboard.println("reached");
      }
  Serial.println(sensorValue);
  //DigiKeyboard.println(sensorValue);
  //delay(50);
  return status;
  }

void loop()
{
 //delay(500);
    cycle();
if (light_reader() == 0) { //luce spenta step 1
    //Serial.println("luce accessa step 1");
    //DigiKeyboard.println("luce accessa step 1");
    digitalWrite(solenoidPin, HIGH);      //Switch Solenoid ON
    delay(50);                          //Wait 1 Second
    digitalWrite(solenoidPin, LOW);
    delay(50);
while(light_reader() == 0) {
      delay(100);
      //Serial.println("luce accessa step 1 engage");
      //DigiKeyboard.println("luce accessa step 1 engage");
      if(light_reader() == 1){ //luce spenta step 2
         cycle();
         timer_count=1000;
          }
    }
      
    //Serial.println("eccoci");
    //DigiKeyboard.println("eccoci");
}
else {
    //Serial.println("OUT");
    //DigiKeyboard.println("OUT");
    delay(100);
  }
}
