


void line_Follow() { 

  

  
  if ( mySensorBar.getDensity() < 7 )
  {

    if ( mySensorBar.getPosition() < -25 ) //checking to see if the line is on the left side of the sensor
    {
      Serial.println("turning left");
      turnLeft(50, 90);
    }
    if ( mySensorBar.getPosition() > 25 ) //checking to see if the line is on the right side of the sensor
    {
      Serial.println("turning right");
      //turnRight(50, 90);
    }
    else if (mySensorBar.getPosition() >= -25 and mySensorBar.getPosition() <= 25){ //checking to see if the line is in the center of the sensor
        Serial.println("going forward");
        forwardS(50, 0.25);
    }
  }
  else if (mySensorBar.getDensity() > 7){ //checking to see if the line is more "dense" than usual i.e brighter/the entire length of sensor.
    Serial.println("white line found");
   //ebreak(20);
  }

}


void ebreak(float delay_Time) { //forces the robot to stop moving when called
  // turn the motor speed to zero
  analogWrite(left_Motor_Enable, 0);
  analogWrite(right_Motor_Enable, 0);

  // turn the motors off
  digitalWrite(left_Motor_S1, HIGH);
  digitalWrite(left_Motor_S2, HIGH);
  digitalWrite(right_Motor_S1, HIGH);
  digitalWrite(right_Motor_S2, HIGH);


  delay(delay_Time);

}

void backward(float motor_Speed, float delay_Time) {

  analogWrite(left_Motor_Enable, motor_Speed);
  analogWrite(right_Motor_Enable, motor_Speed);

  digitalWrite(left_Motor_S1, HIGH);
  digitalWrite(left_Motor_S2, LOW);
  digitalWrite(right_Motor_S1, HIGH);
  digitalWrite(right_Motor_S2, LOW);

  int seconds = ceil(delay_Time * 1000);
  delay(seconds);

  digitalWrite(left_Motor_S1, LOW);
  digitalWrite(left_Motor_S2, LOW);
  digitalWrite(right_Motor_S1, LOW);
  digitalWrite(right_Motor_S2, LOW);


}

void forward(float motor_Speed, float delay_Time) {

  analogWrite(left_Motor_Enable, motor_Speed);
  analogWrite(right_Motor_Enable, motor_Speed);

  digitalWrite(left_Motor_S1, LOW);
  digitalWrite(left_Motor_S2, HIGH);
  digitalWrite(right_Motor_S1, LOW);
  digitalWrite(right_Motor_S2, HIGH);

  int seconds = ceil(delay_Time * 1000);
  delay(seconds);

  digitalWrite(left_Motor_S1, LOW);
  digitalWrite(left_Motor_S2, LOW);
  digitalWrite(right_Motor_S1, LOW);
  digitalWrite(right_Motor_S2, LOW);


}

void forwardS(float motor_Speed, float delay_Time) {
  
while (mySensorBar.getPosition() >= -25 and mySensorBar.getPosition() <= 25){
  analogWrite(left_Motor_Enable, motor_Speed);
  analogWrite(right_Motor_Enable, motor_Speed);

  digitalWrite(left_Motor_S1, LOW);
  digitalWrite(left_Motor_S2, HIGH);
  digitalWrite(right_Motor_S1, LOW);
  digitalWrite(right_Motor_S2, HIGH);
//  Serial.println(mySensorBar.getPosition());
//  delay(20);

  

}

  digitalWrite(left_Motor_S1, HIGH);
  digitalWrite(left_Motor_S2, HIGH);
  digitalWrite(right_Motor_S1, HIGH);
  digitalWrite(right_Motor_S2, HIGH);
  delay(5000);
}


void DC_Motor_Encoder1(){


    Count_pulses1++;
    
    Serial.println(Count_pulses1);
//  Serial.println(Count_pulses1 + Count_pulses2);
}
//void DC_Motor_Encoder2(){
//
//
//    Count_pulses2++;
//    
//
//  Serial.println(Count_pulses1+Count_pulses2);
//}



void turnLeft(float motor_Speed, float turn_Degrees) {

  analogWrite(left_Motor_Enable, motor_Speed);
  analogWrite(right_Motor_Enable, motor_Speed);
  
 Count_pulses1 = 0;
  Count_pulses2 = 0;
 
int pulses = 30*16*(turn_Degrees/360);//16 is the number of pulses in a full rotaion when using the rising edge of ENCA

 //while(abs(Count_pulses1 + Count_pulses2) < pulses)
 while(abs(Count_pulses1) < pulses){ //comparing the number of pulses since the wheel started turning to the number of pulses needed to turn
  
  digitalWrite(left_Motor_S1, HIGH);
  digitalWrite(left_Motor_S2, LOW);
  digitalWrite(right_Motor_S1, LOW);
  digitalWrite(right_Motor_S2, HIGH);
  
 }

  digitalWrite(left_Motor_S1, LOW);
  digitalWrite(left_Motor_S2, LOW);
  digitalWrite(right_Motor_S1, LOW);
  digitalWrite(right_Motor_S2, LOW);

}

void turnRight(float motor_Speed, float turn_Degrees) {

  analogWrite(left_Motor_Enable, motor_Speed);
  analogWrite(right_Motor_Enable, motor_Speed);

  digitalWrite(left_Motor_S1, LOW);
  digitalWrite(left_Motor_S2, HIGH);
  digitalWrite(right_Motor_S1, HIGH);
  digitalWrite(right_Motor_S2, LOW);

  delay(1000);

  digitalWrite(left_Motor_S1, LOW);
  digitalWrite(left_Motor_S2, LOW);
  digitalWrite(right_Motor_S1, LOW);
  digitalWrite(right_Motor_S2, LOW);

}


void zipline(){

  //this will be the code for the zipline/canyon 

  
}

void spin(){ //will spin the sign. it is the code for the celebration
            // by Haley Glenn
  
for (int i = 0; i<StepsPerRev; i++)
MainStep.step(1);

}
