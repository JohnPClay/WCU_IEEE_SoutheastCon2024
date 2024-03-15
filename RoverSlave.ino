
//SLAVE arduino -- controls all the servo motors through a state machine.

#include "Servo.h"
#define statePin 2 // connect to master digital output "pin"  
unsigned int state;
Servo spinServo;
Servo blockServo;

void setup() {
  pinMode(statePin, INPUT);
  blockServo.write(15); //this is the starting positon for the arm. at 15 degrees it should be upright
  state = 0;
  clk = 0;
  attachInterrupt(digitalPinToInterrupt(statePin), changeState, RISING); // trigger ISR on rising edge of master voltage signal

}

void loop() {

  if (clk == 1) {

    if (state == 1) {
      // lower servo motor to grab blocks
      //raise servo motor to lift up blocks
      blockServo.write(120); // at 120 degrees it lowers to be perpendicular to the staring position to pick up the blocks. if needed increase to 130-140.
      delay(1200);
      blockServo.write(55); // the posiion for carying the blocks across the course
      clk == 0;
    }
    if (state == 2) {
      //drop off blocks
      blockServo.write(0); //raises the arm past the starting position to dsiconeect the blockss
      clk == 0;
    }
    if (state == 3) {
      //spin symbol
      spinServo.attach(10);
      spinServo.write(180);
      delay(1000);
      spinServo.write(90);
      state = 0;
      clk == 0;
    }

  }

}
void changeState() {
  state = state + 1;
  clk = 1;
}
