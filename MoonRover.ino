
/*Written by John Clay and Ethan Magnante
 * For the IEEE SouthEastCon 2024 Hardware Competition
 * 
 */

 //PINS 20 AND 21 CANNOT BE USED DO TO INTERFERENCE WITH THE SENSOR
 
 //pins 7-5 dont fully work
 

#include "Wire.h"              // for I2C
#include "sensorbar.h"         // needs SparkFun library
//#include "TCS34725.h"         //library for the RGB sensor. its the TCS34725 library by  hideakitai found under manage libraries
#define ENCA 18 //motor encoder A 
#define ENCB 19 //motor encoder B

#include "Stepper.h"

int StepsPerRev=2038; // how many steps are in a full revolution
Stepper MainStep(StepsPerRev,8,9,10,11); //stepper motor pins
int a = 5;// speed of stepper motor


int Count_pulses1 = 0;
int Count_pulses2 = 0;
//  pin selects. SX1509 breakout defaults to [0:0] (0x3E).
const uint8_t SX1509_ADDRESS = 0x3E;  // SX1509 I2C address (00)

const byte MAXSPEED = 60; //max speed of robot

int L_Speed = MAXSPEED;
int R_Speed = MAXSPEED;

int error = 0;
int lastError = 0;

const byte Kp = 1;
const byte Kd = 2;
SensorBar mySensorBar(SX1509_ADDRESS);


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
  MainStep.setSpeed(a);
  Serial.begin(9600);
  //Default: the IR will only be turned on during reads.
  mySensorBar.setBarStrobe();
  Serial.println("set up serial");
  //Other option: Command to run all the time
  //mySensorBar.clearBarStrobe();

  //Default: dark on light
  //mySensorBar.clearInvertBits();
  //Other option: light line on dark
  mySensorBar.setInvertBits();
  //Don't forget to call .begin() to get the bar ready.  This configures HW.
  uint8_t returnStatus = mySensorBar.begin();
  pinMode(ENCA,INPUT); // sets the Encoder_output_A pin as the input
  pinMode(ENCB,INPUT); // sets the Encoder_output_B pin as the input
  attachInterrupt(digitalPinToInterrupt(ENCA),DC_Motor_Encoder1,RISING);
//   attachInterrupt(digitalPinToInterrupt(ENCB),DC_Motor_Encoder2,RISING);

  if (returnStatus)
  {
    Serial.println("sx1509 IC communication OK");
  }
  else
  {
    Serial.println("sx1509 IC communication FAILED!");
  }
  Serial.println();

}


void loop() {
//
//  Serial.print("Density: ");
//  Serial.println(mySensorBar.getDensity());
//  Serial.print("Position: ");
//  Serial.println(mySensorBar.getPosition());
////  line_Follow();//this function contains most of the code
//  delay(500);
  line_Follow(); 
  turnLeft(100,90);
  delay(1000);
  line_Follow();
  turnLeft(100,90);
  delay(1000);
  line_Follow();
  delay(5000);
   
  /* this is how the code will look later on
   * line_Follow();
   * //do stuff --drop off boxes
   * turn_Left(90);
   * line_Follow();
   * //do stuff -- pick up thrusters
   * turn_Left(90);
   * line_Follow();
   * white line(); --this is where the zipline
   */

  
}
