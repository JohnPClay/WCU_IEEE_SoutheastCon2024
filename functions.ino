
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


void left(float motor_Speed, float time_delay){ //turns the robot based on the time 0.6-0.7 is about 90 degrees

  analogWrite(left_Motor_Enable, motor_Speed);
  analogWrite(right_Motor_Enable, motor_Speed);



  digitalWrite(left_Motor_S1, HIGH);
  digitalWrite(left_Motor_S2, LOW);
  digitalWrite(right_Motor_S1, LOW);
  digitalWrite(right_Motor_S2, HIGH);

  delay(time_delay*1000);
   digitalWrite(left_Motor_S1, LOW);
  digitalWrite(left_Motor_S2, LOW);
  digitalWrite(right_Motor_S1, LOW);
  digitalWrite(right_Motor_S2, LOW);

  
}



void right(float motor_Speed, float time_delay){ //turns the robot based on the time 0.6-0.7 is about 90 degrees

  analogWrite(left_Motor_Enable, motor_Speed);
  analogWrite(right_Motor_Enable, motor_Speed);



  digitalWrite(left_Motor_S1, LOW);
  digitalWrite(left_Motor_S2, HIGH);
  digitalWrite(right_Motor_S1, HIGH);
  digitalWrite(right_Motor_S2, LOW);

  delay(time_delay*1000);
   digitalWrite(left_Motor_S1, LOW);
  digitalWrite(left_Motor_S2, LOW);
  digitalWrite(right_Motor_S1, LOW);
  digitalWrite(right_Motor_S2, LOW);

  
}

void sendSignal(){ //sends a pulse to the other arudino which is set up as a state machine. each pulse causes it to go to the next state and perform the action.
  digitalWrite(slavePin, HIGH);
  delay(100);
  digitalWrite(slavePin, LOW);

}
