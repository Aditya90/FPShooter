#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>
#include <TimerOne.h>

#define forward 2     // Assign pin 2 to push button
#define custom 3

// set A0 and A1 HIGH, A3 LOW
const int analogA0 = A0;
const int analogA1 = A1;
const int analogGND = A3;

void setup() {
  // initialize the pushbutton pin as an input:
  Serial.begin(9600);
  
  pinMode(forward, INPUT);     //set the button pin to input
  pinMode(custom, INPUT);     //set the button pin to input

  PCintPort::attachInterrupt(forward, ISR_button, CHANGE); // attach a PinChange Interrupt to our pin whenever there is a change in the edge
  PCintPort::attachInterrupt(custom, ISR_button, CHANGE);
  
  pinMode(analogA0, OUTPUT);
  pinMode(analogA1, OUTPUT);
  pinMode(analogGND, OUTPUT);
  
  digitalWrite(analogA0, HIGH);
  digitalWrite(analogA1, HIGH);
  digitalWrite(analogGND, LOW);
}

void loop(){

}

void timer1_ISR(){
  if (digitalRead(forward) == HIGH) {
    Serial.write("3");
  }
  else if (digitalRead(custom) == HIGH) {
    Serial.write("4");
  }
  else {
    Timer1.stop();
  }
}

void ISR_button()
{  
   Timer1.initialize(100000);
   Timer1.attachInterrupt(timer1_ISR); // attach the service routine here
}

