#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;
int D0 = 2; // Left eye
int D1 = 3; // Right eye
/*
 * angleToPulse(int ang)
 * gets angle in degree and returns the pulse width
 * also prints the value on seial monitor
 * written by Ahmad Nejrabi for Robojax, Robojax.com
 */
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}


// create a circular tragit with randmess 
void base1() {

  int high=130;
  int high_=0;
  int speed_dist;
  speed_dist=random(0,400);
  for( int base =0; base<141; base +=10){
    high_= high+random(-12, 12);
    pwm.setPWM(1, 0, angleToPulse(base) );
    pwm.setPWM(0, 0, angleToPulse(high_) );
    delay(200 + random(0,400));
  }
  for( int base =181; base>1; base -=10){
    high_= high+random(-12, 12);
    pwm.setPWM(1, 0, angleToPulse(base) );
    pwm.setPWM(0, 0, angleToPulse(high_) );
    delay(200 + random(0,400));
    
   
  }
}

void traject(){
  int delta_base;
  int delta_high;
  int base;
  int high;
  int base_a=random(30,140);
  int high_a=random(120,160);
  while(true){
    int base_b=random(30,140);
    int high_b=random(120,160);
    for( int i =0; i<10; i +=1){
        delta_base=(base_a - base_b)/10;
        delta_high=(high_a - high_b)/10;
        base=base_a-delta_base*i;
        high=high_a-delta_high*i;
        pwm.setPWM(1, 0, angleToPulse(base) );
        pwm.setPWM(0, 0, angleToPulse(high) );
        delay(random(50,500)); //200
        }
    base_a=base_b;
    high_a=high_b;
  }
}


void setup() { 
//  Serial.begin(9600);
//  Serial.println("16 channel Servo test!");
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void loop() {
 digitalWrite(D0, HIGH);   // turn the LED on (HIGH is the voltage level)
 digitalWrite(D1, HIGH); 
traject();
// base1();
// digitalWrite(D0, HIGH);   // turn the LED on (HIGH is the voltage level)
// digitalWrite(D1, HIGH); 
//  delay(1000);                       // wait for a second
//  digitalWrite(D0, LOW);    // turn the LED off by making the voltage LOW
//  digitalWrite(D1, HIGH);
//  delay(1000); 

}
