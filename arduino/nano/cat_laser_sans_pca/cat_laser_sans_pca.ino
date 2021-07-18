//#include <Wire.h>
#include <Servo.h>

Servo myservo0;  // create servo object to control a servo
Servo myservo1;  // create servo object to control a servo

// our servo # counter
//uint8_t servonum = 0;
int D0 = 2; // Left eye
int D1 = 3; // Right eye
/*
 * angleToPulse(int ang)
 * gets angle in degree and returns the pulse width
 * also prints the value on seial monitor
 * written by Ahmad Nejrabi for Robojax, Robojax.com
 */


// create a circular tragit with randmess 
void base() {

  int high=130;
  int high_=0;
  int speed_dist;
  speed_dist=random(0,400);
  for( int base =0; base<141; base +=10){
    high_= high+random(-12, 12);
  //  pwm.setPWM(1, 0, angleToPulse(base) );
  myservo1.write(base);
  
  //  pwm.setPWM(0, 0, angleToPulse(high_) );
    myservo0.write(high_);
    delay(200 + random(0,400));
  }
  for( int base =181; base>1; base -=10){
    high_= high+random(-12, 12);
   // pwm.setPWM(1, 0, angleToPulse(base) );
   // pwm.setPWM(0, 0, angleToPulse(high_) );
    myservo1.write(base);
    myservo0.write(high_);
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
        //pwm.setPWM(1, 0, angleToPulse(base) );
        //pwm.setPWM(0, 0, angleToPulse(high) );
        myservo1.write(base);
        myservo0.write(high);
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
  myservo0.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(10);  // attaches the servo on pin 9 to the servo object
 // pwm.begin();
 // pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void loop() {
 digitalWrite(D0, HIGH);   // turn the LED on (HIGH is the voltage level)
 digitalWrite(D1, HIGH); 
//traject();
base();
}
