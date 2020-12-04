

//>>>>> rc1 block <<<<<<
int in1 = 12;
int in2 = 13;

// PWM capable ports 
int enable1 = 11;
// channel
int rc_channel1 = 2;

//>>>>> rc2 block <<<<<<
int in3 = 10;
int in4 = 9;

// PWM capable ports 
int enable2 = 8;
// channel
int rc_channel2 = 3;



void setup() {
  // rc1 block
  pinMode(rc_channel1, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enable1, OUTPUT);


  // rc2 block
  pinMode(rc_channel2, INPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enable2, OUTPUT);

// global settings... 
  Serial.begin(9600);
}



void loop_rc1() {
  
  int pwm = 0;
  //int swd = pulseIn(switchD, HIGH, 25000);
  int rc1 = pulseIn(rc_channel1, HIGH, 25000);
  
  Serial.print("switch: ");
  //Serial.print(swd);
  //Serial.print(" raw channel4: ");
  Serial.print(rc1);
  
  if(rc1==0){
      Serial.println(" no signal");
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enable1, 0);
  }
  else if(rc1 > 1530){ //right stick
      pwm = map(rc1, 1530, 2000, 0, 255); //map our speed to 0-255 range
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enable1, pwm);
      Serial.print(" right stick speed: ");
      Serial.println(pwm);
  }
  else if(rc1 < 1460){
      pwm = map(rc1, 1460, 1000, 0, 255); //map our speed to 0-255 range
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enable1, pwm);
      Serial.print(" left stick speed: ");
      Serial.println(pwm);
  }
  else{
      Serial.println(" stick centered");
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enable1, 0);
  }
  
 
}

void loop_rc2() {
  
  int pwm = 0;
    int rc2 = pulseIn(rc_channel2, HIGH, 25000);
  
  Serial.print("switch: ");
 
  Serial.print(rc2);
  
  if(rc2==0){
      Serial.println(" no signal");
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      analogWrite(enable2, 0);
  }
  else if(rc2 > 1530){ //right stick
      pwm = map(rc2, 1530, 2000, 0, 255); //map our speed to 0-255 range
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enable2, pwm);
      Serial.print(" right stick speed: ");
      Serial.println(pwm);
  }
  else if(rc2 < 1460){
      pwm = map(rc2, 1460, 1000, 0, 255); //map our speed to 0-255 range
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enable2, pwm);
      Serial.print(" left stick speed: ");
      Serial.println(pwm);
  }
  else{
      Serial.println(" stick centered");
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      analogWrite(enable2, 0);
  }

}

void loop() {
  loop_rc1();
  loop_rc2();
  delay(10);
} 
