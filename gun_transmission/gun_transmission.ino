#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>
#include <TimerOne.h>

#define fire 2     // Assign pin 2 to push button
#define reload 3

// set A0 and A1 pin HIGH, A3 pin ground
const int analogA0 = A0;
const int analogA1 = A1;
const int analogGND = A3;


void setup() {
  Serial.begin(9600);
  
  pinMode(fire, INPUT);     //set the button pin to input
  pinMode(reload, INPUT);     //set the button pin to input

  PCintPort::attachInterrupt(fire, ISR_button, CHANGE); // attach a PinChange Interrupt to our pin whenever there is a change in the edge
  PCintPort::attachInterrupt(reload, ISR_button, CHANGE);
  
  
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
  if (digitalRead(fire) == HIGH) {
    Serial.write("1");
  }
  else if (digitalRead(reload) == HIGH) {
    Serial.write("2");
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

