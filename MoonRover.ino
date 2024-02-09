
/*Written by John Clay and Ethan Magnante
   For the IEEE SouthEastCon 2024 Hardware Competition

*/

//PINS 20 AND 21 CANNOT BE USED DO TO INTERFERENCE WITH THE SENSOR

//pins 7-5 dont fully work


#include "Wire.h"              // for I2C
#include "sensorbar.h"         // needs SparkFun library
//#include "TCS34725.h"         //library for the RGB sensor. its the TCS34725 library by  hideakitai found under manage libraries
#define ENCA 7 //motor encoder A 
#define ENCB 6 //motor encoder B

#include "Stepper.h"

int StepsPerRev = 2038; // how many steps are in a full revolution
Stepper MainStep(StepsPerRev, A0, A1, A2, A3); //stepper motor pins
int a = 5;// speed of stepper motor


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
  MainStep.setSpeed(a);
  Serial.begin(9600);
  //Default: the IR will only be turned on during reads.
  mySensorBar.setBarStrobe();
  Serial.println("set up serial");
  //Other option: Command to run all the time
  //  mySensorBar.clearBarStrobe();

  //Default: dark on light
  //mySensorBar.clearInvertBits();
  //Other option: light line on dark
  mySensorBar.setInvertBits();
  //Don't forget to call .begin() to get the bar ready.  This configures HW.
  uint8_t returnStatus = mySensorBar.begin();
  pinMode(ENCA, INPUT); // sets the Encoder_output_A pin as the input
  pinMode(ENCB, INPUT); // sets the Encoder_output_B pin as the input
  attachInterrupt(digitalPinToInterrupt(ENCA), DC_Motor_Encoder1, RISING);
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
  //forward(70, 2.5);
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



  forward(70, 5);

 delay(7000);




  ////the main code
  
  //  line_Follow();
  //  backward(70, 0.35);
  //  ebreak(500);
  //  turnLeft(120, 100);
  //  delay(1000);
  //  line_Follow();
  //  backward(70, 0.35);
  //  ebreak(500);
  //
  //  turnLeft(120, 120);
  //  delay(1000);
  //  forward(70, 1.5);
  //  spin(3);
  //  //line_Follow();
  //  delay(7000);

  //Backup hardcode

  
  // forward(70,1.1);
  // forward(40,0.5);
  // backward(70,0.7);
  // forward(40,0.1);
  // left(120, 1.15);
  // backward(70,.5);
  // forward(70,1.3);
  // forward(40,0.7);
  // backward(70,0.3);
  // forward(40,0.1);
  // left(120, 1.16);
  // backward(70,.85);
  // forward(70,2.35);
  // delay(10000);



  //pick up thrusters
  //
  //  backward(50,2);
  //  backward(100,0.5);
  //  forward(70,1);
  //  delay(2000);
  //


}
