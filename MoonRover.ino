

/*Written by John Clay and Ethan Magnante
   For the IEEE SouthEastCon 2024 Hardware Competition

*/

//PINS 20 AND 21 CANNOT BE USED DO TO INTERFERENCE WITH THE SENSOR
// pins 18 and 19 have a wire stuck in them
//pins 7-5 dont fully work


#include "Wire.h"              // for I2C
#include "sensorbar.h"         // needs SparkFun library
//#include "TCS34725.h"         //library for the RGB sensor. its the TCS34725 library by  hideakitai found under manage libraries
#include "Servo.h"

// Needs Adafruiit_TCS347573 library for the purple color sensor
#include "Adafruit_TCS34725.h"

#define ENCA 7 //motor encoder A 
#define ENCB 6 //motor encoder B

Servo spinServo;
Servo plowServo1;
Servo plowServo2;

int StepsPerRev = 2038; // how many steps are in a full revolution



int Count_pulses1 = 0;
int Count_pulses2 = 0;
//  pin selects. SX1509 breakout defaults to [0:0] (0x3E).
const uint8_t SX1509_ADDRESS = 0x3E;  // SX1509 I2C address (00)

const byte MAXSPEED = 70; //max speed of robot
const byte MINSPEED = 50;

int L_Speed = MAXSPEED;
int R_Speed = MAXSPEED;

int error = 0;
int lastError = 0;

const byte Kp = 1;
const byte Kd = 2;
SensorBar mySensorBar(SX1509_ADDRESS);


int currentDensity = 1;
int previousDensity = 1;


////motor pins
//speed control
int left_Motor_Enable = 44;

int right_Motor_Enable = 46;

//left motors

//int back_Left_Motor_S1
//int back_Left_Motor_S2

int left_Motor_S1 = 52;
int left_Motor_S2 = 50;

//right motors

int right_Motor_S1 = 53;
int right_Motor_S2 = 51;

//int front_Right-Motor_S1
//int front_Right-Motor_S2

void setup() {
  Serial.begin(9600);
  //Default: the IR will only be turned on during reads.
  //mySensorBar.setBarStrobe();
  //Serial.println("set up serial");
  //Other option: Command to run all the time
  //  mySensorBar.clearBarStrobe();

  //Default: dark on light
  //mySensorBar.clearInvertBits();
  //Other option: light line on dark
 // mySensorBar.setInvertBits();
  //Don't forget to call .begin() to get the bar ready.  This configures HW.
//  uint8_t returnStatus = mySensorBar.begin();
//  pinMode(ENCA, INPUT); // sets the Encoder_output_A pin as the input
//  pinMode(ENCB, INPUT); // sets the Encoder_output_B pin as the input
//  attachInterrupt(digitalPinToInterrupt(ENCA), DC_Motor_Encoder1, RISING);
  //   attachInterrupt(digitalPinToInterrupt(ENCB),DC_Motor_Encoder2,RISING);
  //
  //  if (returnStatus)
  //  {
  //    Serial.println("sx1509 IC communication OK");
  //  }
  //  else
  //  {
  //    Serial.println("sx1509 IC communication FAILED!");
  //  }
  //  Serial.println();
  //

  start_up(5000, 0.1); //this is the function for the autostart.

}


void loop() {




  //
  //      Serial.print("Density: ");
  //      Serial.println(mySensorBar.getDensity());
  //      Serial.print("Position: ");
  //      Serial.println(mySensorBar.getPosition());
  //      delay(200);

  //    line_Follow();//this function contains most of the code

  //  Serial.println(mySensorBar.getDensity());


  //Backup hardcode

  //to box drop off//
  forward(80,0.5);
//  plowServo1.attach(31);
//  plowServo1.write(180);
//  plowServo2.attach(35);
//  plowServo2.write(180);
//  delay(1000);
//  plowServo2.write(0);
//  plowServo2.detach();
//  plowServo1.write(0);
//  plowServo1.detach();
  forward(80, 2);
  forward(80, 1.1);
  forward(50, 0.5);

  //first turn
  backward(80, 0.7);
  forward(50, 0.1);
  left(160, 0.7);
  backward(80, 1);
//
//  //to thruster pick up
  forward(80, 1.2);
  forward(50, 0.7);
//
//  //seocnd turn
  backward(70, 0.3);
  forward(50, 0.1);
  left(160, 0.7);
  backward(80, 1);
  delay(3000);
  forward(80, 0.5);
  right(160, 0.2);
  backward(80, 1.3);
  delay(1000);


  //   //to white line
  forward(80, 1.8);
  //plowServo1.attach(31);
//  plowServo1.write(180);
//  plowServo2.attach(35);
//  plowServo2.write(180);
//
//  plowServo1.detach();
//  plowServo2.detach();
//

//  forward(255, 0.5); 
//  delay(10000);
//  plowServo2.attach(35);
//  plowServo2.write(0);
//  plowServo2.detach();
//  plowServo1.attach(31);
//  plowServo1.write(0);
//  plowServo1.detach();
  //   forward(80,2.35);
  //   delay(10000);
  //
  //   forward(120,3);
  //   forward(80,1);

  //hit the button


  forward(80, 1.5);
  right(160, 0.7);
  backward(70, 0.2);
  backward(80, 1.2);
  spinServo.attach(10);
  spinServo.write(180);
  delay(1000);
  spinServo.write(90);
  spinServo.detach();
 
  delay(2000);
   forward(80, 2);
  while (true) {
    right(160, 0.3);
    backward(80, 2);
    forward(80, 2);
    left(160, 0.3);
    backward(80, 2);
    forward(80, 2);
  }

  //pick up thrusters
  //
  //  backward(50,2);
  //  backward(100,0.5);
  //  forward(70,1);
  //  delay(2000);
  //


}
