/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink

*/
   const int farolaser = 0;
   const int faroluce = 1;
   const int casayellow = 2;
   const int casawhite = 3;
   const int mare1= 4;
   const int mare2 = 5;
   int flattime = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
   
  pinMode(farolaser, OUTPUT);
  pinMode(faroluce, OUTPUT);
  pinMode(casayellow, OUTPUT);
  pinMode(casawhite, OUTPUT);
  pinMode(mare1, OUTPUT);
  pinMode(mare2, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {

// mare1 & mare2

digitalWrite(mare1, HIGH);
digitalWrite(mare2, HIGH);
  
// farolaser & faroluce
  if (( flattime < 2) || ( flattime > 6 &&  flattime <9))
    {
    digitalWrite(farolaser, HIGH);
    digitalWrite(faroluce, LOW);
    }
    else 
    {
    digitalWrite(farolaser, LOW);
    digitalWrite(faroluce, HIGH);
    }


 // casayellow & casawhite
  if ( flattime > 3 &&  flattime <5)
    {
    digitalWrite(casawhite, HIGH);
    digitalWrite(casayellow, LOW);
    }
    else 
    {
    digitalWrite(casawhite, LOW);
    digitalWrite(casayellow, HIGH);
    }
    
  delay(1000);                       // wait for a second
  if ( flattime < 10)
    {  flattime++; }
    else 
    { flattime=0; } 
  
}
