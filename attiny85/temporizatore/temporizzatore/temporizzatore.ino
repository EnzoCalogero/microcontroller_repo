
// constants won't change. They're used here to set pin numbers:
const int buttonPin2 = 2;     // the number of the pushbutton pin
const int buttonPin1 = 1;     // the number of the pushbutton pin
const int ledPin0 =  0;       // the number of the LED pin
const int ledPin3 =  3;       // the number of the LED pin
const int voice =  4;         // the number of the LED pin
//const int time_on = 5000;     // time to keep the system up

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void start_end() {
  digitalWrite(ledPin3, HIGH);;
  delay(500);
  digitalWrite(ledPin3, LOW);
  }

void routine_hands() {
  
    digitalWrite(ledPin0, HIGH);
    start_end();
    // turn LED off:
    for (int i = 0; i <= 20; i++) {
      digitalWrite(ledPin3, HIGH);;
      
      delay(50);
      digitalWrite(ledPin3, LOW);
      delay(950);
      }    
    digitalWrite(ledPin0, LOW);
    start_end();
    }

    
void routine_teeth() {
    digitalWrite(ledPin0, HIGH);
    start_end();
    
    for (int i = 0; i <= 20; i++) {
      digitalWrite(ledPin3, HIGH);;
      delay(50);
      digitalWrite(ledPin3, LOW);
      delay(5900); //50 millisecond discount....
      } 
    
    
    // turn LED off:
    digitalWrite(ledPin0, LOW);
    start_end();
    }

    
void setup() {
  // initialize the LED pin as an output:
    pinMode(ledPin0, OUTPUT);
  // initialize the sounds pin as an output:
    pinMode(ledPin3, OUTPUT);
    pinMode(voice,OUTPUT);
    
  // initialize the pushbutton pin as an input:
    pinMode(buttonPin1, INPUT);
    pinMode(buttonPin2, INPUT);
    
    // Routine Startup Iniziale
    digitalWrite(ledPin3, HIGH);
    
    digitalWrite(voice, HIGH);
    delay(250);
    digitalWrite(voice, LOW);
    delay(750);
    digitalWrite(ledPin3, LOW);;
}


void loop() {
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin1);
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
            routine_hands();
            }

    buttonState = digitalRead(buttonPin2);
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
            routine_teeth();
            }          
}
