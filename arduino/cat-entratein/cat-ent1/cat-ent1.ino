
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)
uint8_t servonum = 0;

/*
 * angleToPulse(int ang)
 * gets angle in degree and returns the pulse width
 * also prints the value on seial monitor
 * written by Ahmad Nejrabi for Robojax, Robojax.com
 */
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   //Serial.print("Angle: ");Serial.print(ang);
   //Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}

void next_status( int status[])
{
  for(int i=0;i<8;i++){
//  Serial.println(i);
//  Serial.println(status[i]);
 switch (i) {

 //##################### Legs ############################################## 
          case 0: //leg front right
                if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(30));
                else if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(80));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(90));
                 break;
          case 1: //leg front left
                if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(150));
                else if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(110));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(90));
                break;
          case 2: //leg back right
                if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(150));
                else if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(110));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(90));
                break;
          case 3: //leg back left
                if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(30));
                else if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(70));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(90));
                break;
//######################## hips    ###################  
          case 4: //leg front right
                if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(90));
                else if(status[i] == 2) pwm.setPWM(i, 0, angleToPulse(40));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(70));
                else if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(120));
                else if(status[i] == -2) pwm.setPWM(i, 0, angleToPulse(160));
                break;
          case 5: //leg front left
                if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(90));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(120));
                else if(status[i] == 2) pwm.setPWM(i, 0, angleToPulse(150));
                else if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(70));
                else if(status[i] == -2) pwm.setPWM(i, 0, angleToPulse(40));
                break;
          case 6: //leg back right
                if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(90));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(120));
                else if(status[i] == 2) pwm.setPWM(i, 0, angleToPulse(160));
                else if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(70));
                else if(status[i] == -2) pwm.setPWM(i, 0, angleToPulse(40));
                break;
          case 7: //leg back left
                if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(90));
                else if(status[i] == 2) pwm.setPWM(i, 0, angleToPulse(30));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(70));
                else if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(120));
                else if(status[i] == -2) pwm.setPWM(i, 0, angleToPulse(145));
                break;
          }
  }
}  


void step1(void) {
int a[8] = { 1, 0, 0, 0, 0, 2, 0, 0};
next_status(a);
delay(250);
int b[8] = { 1, 0, 0, 0, 2, 2, 0, 0};
next_status(b);
delay(250); 
  }


void step2(void) {
int a[8] = {  0, 1, 0, 0, 2, 2, 0, 0};
 
 next_status(a);
 delay(250); 
 int b[8] = { 0, 1, 0, 0, 2, 0, 0, 0 };
 next_status(b);
// int c[8] = { 1, 0, 0, 0, 2, 1, 0, 1 };
// next_status(c);
 
delay(250); 
  }


void move1(void) {
int a[8] = { 0, 0, 0, 0, 2, 1, 0, 1 };
next_status(a);

delay(250); 
int b[8] = { 0, 0, 0, 0, 0, -1, -2, 2 };
next_status(b);
  
delay(250); 
  }  

void step3(void) {
 int a[8] = {  0, 0, 0, 1, 0, -1, -2, 2  };
 next_status(a);
 delay(250);

int b[8] = {  0, 0, 0, 1, 0, -1, -2, -2  };
 next_status(b);
 delay(250);  
  } 

void step4(void) {
 int a[8] = {  0, 0, 1, 0, 0, -1, -2, -2  };
 next_status(a);
 delay(250); 
 int b[8] = {  0, 0, 1, 0, 0, -1, 1, -2  };
 next_status(b);
 delay(250); 
 
  } 

void move2(void) {
 int a[8] = {  0, 0, 0, 0, 0, -1, 1, -2   };
 next_status(a);
 delay(250); 
 int b[8] = { 0, 0, 0, 0, 1, 2, 0, 0};
 next_status(b);
 delay(250); 
 
  } 
  

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
// step1();
}


void loop(void) { 
// flat();
step1();
step2();
move2();
step3();
step4();
move2();

delay(200);

//step2();

}



// create a circular tragit with some randmess 
void base1() {

  int high=70;
  int high_=0;
  for( int base =0; base<181; base +=10){
    high_= high+random(-12, 12);
    pwm.setPWM(1, 0, angleToPulse(base) );
    pwm.setPWM(0, 0, angleToPulse(high_) );
    delay(200);
  }
  for( int base =181; base>1; base -=10){
    high_= high+random(-12, 12);
    pwm.setPWM(1, 0, angleToPulse(base) );
    pwm.setPWM(0, 0, angleToPulse(high_) );
    delay(200);
    // pwm.setPWM(0, 0, angleToPulse(angle) );
   
  }
}

void traject(){
  int delta_base;
  int delta_high;
  int base;
  int high;
  int base_a=random(20,140);
  int high_a=random(20,140);
  while(true){
    int base_b=random(20,140);
    int high_b=random(20,140);
    for( int i =0; i<10; i +=1){
        delta_base=(base_a - base_b)/10;
        delta_high=(high_a - high_b)/10;
        base=base_a-delta_base*i;
        high=high_a-delta_high*i;
        pwm.setPWM(1, 0, angleToPulse(base) );
        pwm.setPWM(0, 0, angleToPulse(high) );
        delay(200); //200
        }
    //delay(400);    
    base_a=base_b;
    high_a=high_b;
    //delay(200);
    //Serial.println("change");
  }
  
  }


  

void stand()
{
const int defaultAngles[8] = {30, 150, 150, 30, 90, 90, 90, 90 };
for( int i =0; i<8; i +=1){
        Serial.print(defaultAngles[i]);
         pwm.setPWM(i, 0, angleToPulse(defaultAngles[i]) );
        //delay(500);
}
}

void flat()
{
//const int defaultAngles[8] = { 90, 90, 90, 90, 90, 90, 90, 90 };
const int a[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
next_status(a);
delay(250);

}


void dance1(void) {
 int a[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }; // tutto in squadra 90 gradi
next_status(a);
delay(500);
int b[8] = { 1, 1, 0, 0, 1, 1, 1, 1 };
next_status(b);
delay(500);
int c[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
next_status(c);
delay(500);

int d[8] = { 0, 0, 1, 1, -1, -1, -1, -1 };
next_status(d);
delay(500);  
  }
