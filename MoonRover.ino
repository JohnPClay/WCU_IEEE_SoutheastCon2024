


//void line_Follow() {
//
//
//
//
//  if ( mySensorBar.getDensity() < 7 )
//  {
//
//    if ( mySensorBar.getPosition() < -25 ) //checking to see if the line is on the left side of the sensor
//    {
//      Serial.println("turning left");
//      turnLeft(50, 90);
//    }
//    if ( mySensorBar.getPosition() > 25 ) //checking to see if the line is on the right side of the sensor
//    {
//      Serial.println("turning right");
//      //turnRight(50, 90);
//    }
//    else if (mySensorBar.getPosition() >= -25 and mySensorBar.getPosition() <= 25){ //checking to see if the line is in the center of the sensor
//        Serial.println("going forward");
//        forwardS(50, 0.25);
//    }
//  }
//  else if (mySensorBar.getDensity() > 7){ //checking to see if the line is more "dense" than usual i.e brighter/the entire length of sensor.
//    Serial.println("white line found");
//   //ebreak(20);
//  }
//
//}



void line_Follow(){
    while ((mySensorBar.getDensity() > 0) and (mySensorBar.getDensity() < 7)){ // While loop to check if yellow line is detected (i.e. normal sequence for yellow line)
    error = mySensorBar.getPosition(); 
    if ( error < -35) // checking to see if the line is on the left side of the sensor
    {

      R_Speed = MAXSPEED;
      L_Speed = MAXSPEED + (Kp * error) + (Kd * (error - lastError)); // plus since error is negative, will result in negative values for proportionate term
      L_Speed = constrain(L_Speed, 0, MAXSPEED);
      Serial.println("Robot Turn Left Statement");
      delay(100);
      
    } // End of line on left side of robot if statement 
    else if (mySensorBar.getPosition() > 35){ // checking to see if the line is on the right side of the sensor
      
      R_Speed = MAXSPEED - (Kp * error) - (Kd * (error - lastError));
      L_Speed = MAXSPEED; // plus since error is negative, will result in negative values for proportionate term
      R_Speed = constrain(R_Speed, 0, MAXSPEED);
      Serial.println("Robot Turn Right Statement");
      delay(100);
      
    } // End of line on right side of robot else if statement
    else{ //checking to see if the line is in the center of the sensor
      
      L_Speed = MAXSPEED;
      R_Speed = MAXSPEED;
      Serial.println("Robot Goes Straight Statement");
      delay(100);
      
    } // End of center line else statement
    forwardS(L_Speed, R_Speed);
    lastError = error;
  } // End of yellow line While loop
  
  if (mySensorBar.getDensity() == 0){ // If statement used for turning the robot 90 dgrees once a 90 degree turn is detected
    
    Serial.println("This is where the turn code will go");
    delay(500);
    
  } // End of 90 degree turn if statement
  
  if (mySensorBar.getDensity() > 7){ // If statement used for detecting the white line in the course

    Serial.println("This is where the white line code will go");
    delay(500);
    
  }
  
} // End of line_Follow() function


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

void forwardS(float L_speed, float R_speed) {


  analogWrite(left_Motor_Enable, L_speed);
  analogWrite(right_Motor_Enable, R_speed);

  digitalWrite(left_Motor_S1, LOW);
  digitalWrite(left_Motor_S2, HIGH);
  digitalWrite(right_Motor_S1, LOW);
  digitalWrite(right_Motor_S2, HIGH);
  //  Serial.println(mySensorBar.getPosition());
  //  delay(20);



}


void DC_Motor_Encoder1() {


  Count_pulses1++;

//  Serial.println(Count_pulses1);
  //  Serial.println(Count_pulses1 + Count_pulses2);
}
////void DC_Motor_Encoder2(){
////
////
////    Count_pulses2++;
////
////
////  Serial.println(Count_pulses1+Count_pulses2);
////}



void turnLeft(float motor_Speed, float turn_Degrees) {

  analogWrite(left_Motor_Enable, motor_Speed);
  analogWrite(right_Motor_Enable, motor_Speed);

  Count_pulses1 = 0;
  Count_pulses2 = 0;

  int pulses = 30 * 16 * (turn_Degrees / 360); //16 is the number of pulses in a full rotaion when using the rising edge of ENCA

  //while(abs(Count_pulses1 + Count_pulses2) < pulses)
  while (abs(Count_pulses1) < pulses) { //comparing the number of pulses since the wheel started turning to the number of pulses needed to turn

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


void zipline() {

  //this will be the code for the zipline/canyon


}

void spin() { //will spin the sign. it is the code for the celebration
  // by Haley Glenn

  for (int i = 0; i < StepsPerRev; i++)
    MainStep.step(1);

}
