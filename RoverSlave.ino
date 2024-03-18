
//SLAVE arduino -- controls all the servo motors through a state machine.

#include "Servo.h"
#define statePin 2 // connect to master digital output "pin"  
int state = 0;
Servo spinServo;
Servo blockServo;
int clk = 0;


void setup() {
  pinMode(statePin, INPUT);
  blockServo.attach(7);
  blockServo.write(170); //this is the starting positon for the arm. at 170 degrees it should be upright
  

  attachInterrupt(digitalPinToInterrupt(statePin), changeState, RISING); // trigger ISR on rising edge of master voltage signal

}

void loop() {

  if (clk == 1) {

    if (state == 1) {
      // lower servo motor to grab blocks
      //raise servo motor to lift up blocks
      blockServo.write(80); // at 80 degrees it lowers to be perpendicular to the staring position to pick up the blocks. if needed increase to 70-90.
      delay(1000);
      blockServo.write(140); // the posiion for carying the blocks across the course. might need to be changed to 140-165.
      clk == 0;
    }
    if (state == 2) {
      //drop off blocks
      blockServo.write(180); //raises the arm past the starting position to dsiconeect the blockss
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
