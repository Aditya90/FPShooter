#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>
#include <TimerOne.h>

#define forward 2     // Assign pin 2 to push button
#define custom 3

int val = 0;


void setup() {
  Serial.begin(9600);
  
  pinMode(forward, OUTPUT);  // set pin as OUTPUT
  pinMode(custom, OUTPUT);
  
  Timer1.initialize(100000);
  Timer1.attachInterrupt(timer1_ISR);
}

void loop(){

}


void timer1_ISR(){
  val = Serial.read();
  if (val == 51) {
    Serial.print("3");
    digitalWrite(forward, HIGH);
  }
  else if (val == 52){
    Serial.print("4");
    digitalWrite(custom, HIGH);
  }
  else {
    val = 0;
    digitalWrite(forward, LOW);  // clear pin 2 and 3 when not receiving signal
    digitalWrite(custom, LOW);
    Serial.print("nothing");
  }
}
