
/*Written by John Clay and Ethan Magnante
   For the IEEE SouthEastCon 2024 Hardware Competition

*/

//MASTER Arduino
//-- controls the driving,autostart, and main code. the slave arduino controls the servo motors.

//the extra pins are 48 ,52, A9 and A8 on the PCB

//PINS 20 AND 21 CANNOT BE USED DO TO INTERFERENCE WITH THE SENSOR
// pins 18 and 19 have a wire stuck in them
//pins 7-5 dont fully work


#include "Wire.h"              // for I2C

//#include "TCS34725.h"         //library for the RGB sensor. its the TCS34725 library by  hideakitai found under manage libraries
// Needs Adafruiit_TCS347573 library for the purple color sensor
#include "Adafruit_TCS34725.h"


int slavePin = 48; //the pin for communicating with the other arduino

////motor pins
//speed control
int left_Motor_Enable = 44;
int right_Motor_Enable = 46;

//right motors
int right_Motor_S1 = 42;
int right_Motor_S2 = 40;

//left motors
int left_Motor_S1 = 38;
int left_Motor_S2 = 36;


void setup() {
  Serial.begin(9600);

  start_up(5000, 0.1); //this is the function for the autostart.

}


void loop() {


  //Backup hardcode

  //pick up blocks//

    sendSignal();
    delay(3000);

  //to box drop off//
  forward(80, 0.5);

  forward(80, 1.5);
  forward(60, 1.2);
  forward(50, 0.5);

  //drop off boxes

  sendSignal();
  delay(1000);
  
  //first turn
  backward(80, 0.6);
  forward(50, 0.1);
  left(160, 0.6);
  backward(80, 1);
  //

  //  //to thruster pick up
  forward(80, 0.75);
  forward(60, 0.5);
  forward(50, 0.7);

  //  //seocnd turn
  backward(70, 0.2);
  forward(50, 0.1);
  left(160, 0.6);
  backward(80, 1.2);
  delay(1000);
  //centering before the line
  forward(80, 0.5);
  right(160, 0.1);
  backward(80, 1.4);
  delay(1000);


  //   //to white line

  forward(80, 1.8);


  forward(255, 0.5);
  delay(1000);
  //hit the button

  forward(80, 0.5);
  forward(60, 1);
  right(160, 0.6);
  backward(70, 0.2);
  backward(80, 1.2);

  sendSignal();

  delay(2000);
  forward(80, 2);
  while (true) {
    right(160, 0.2);
    backward(80, 1);
    forward(80, 1);
    left(160, 0.2);
    backward(80, 1);
    forward(80, 1);
  }



}
