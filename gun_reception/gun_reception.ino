#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>
#include <TimerOne.h>

#define forward 2     // Assign pin 2 for forward button
#define custom 3    // Assign pin 3 for custom button

int val = 0;

void setup() {
  // initialize the pushbutton pin as an input:
  Serial.begin(9600);
  
  pinMode(forward, INPUT);
  pinMode(custom, INPUT);
  
  Timer1.initialize(100000);
  Timer1.attachInterrupt(timer1_ISR);
}

void loop(){

}


void timer1_ISR(){
  val = Serial.read();
  if (val == 49) {
    Serial.print("1");
  }
  else if (val == 50){
    Serial.print("2");
  }
  
  if(digitalRead(2) == HIGH)
  {
      Serial.print("3");
  }
  if(digitalRead(3) == HIGH)
  {
      Serial.print("4");
  }
  
}
