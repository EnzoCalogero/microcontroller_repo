/*
  Light system first resin "lighthouse"
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
