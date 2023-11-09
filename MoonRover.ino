

#include "Wire.h"              // for I2C
#include "sensorbar.h"         // needs SparkFun library
#include "TCS34725.h"
#define ENCA 8 //motor encoder A 
#define ENCB 9 //motor encoder B

int Count_pulses = 0;

//  pin selects. SX1509 breakout defaults to [0:0] (0x3E).
const uint8_t SX1509_ADDRESS = 0x3E;  // SX1509 I2C address (00)


SensorBar mySensorBar(SX1509_ADDRESS);


////motor pins
//speed control
int left_Motor_Enable = 7;

int right_Motor_Enable = 2;

//left motors

//int back_Left_Motor_S1
//int back_Left_Motor_S2

int left_Motor_S1 = 4;
int left_Motor_S2 = 3;

//right motors

int right_Motor_S1 = 6;
int right_Motor_S2 = 5;

//int front_Right-Motor_S1
//int front_Right-Motor_S2


void setup() {

  Serial.begin(9600);
  //Default: the IR will only be turned on during reads.
  mySensorBar.setBarStrobe();
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
  attachInterrupt(digitalPinToInterrupt(ENCA),DC_Motor_Encoder,RISING);
  attachInterrupt(digitalPinToInterrupt(ENCA),DC_Motor_Encoder,FALLING);

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
//  Serial.println(mySensorBar.getDensity());
  Serial.println(mySensorBar.getPosition());
  line_Follow();//this function contains most of the code

  delay(20);

}
