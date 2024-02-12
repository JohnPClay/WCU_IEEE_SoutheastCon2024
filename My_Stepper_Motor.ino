int delayTime = 3;
void CW(int A, int B, int C, int D){
  
    // turn the LED on (HIGH is the voltage level)
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  
  delay(delayTime); // Wait for 1000 millisecond(s)
  
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  
  delay(delayTime); // Wait for 1000 millisecond(s)
  
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  
  delay(delayTime); // Wait for 1000 millisecond(s)
  
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  
  delay(delayTime); // Wait for 1000 millisecond(s)
  
} //end CW
void CCW(int A, int B, int C, int D){
  
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  
  delay(delayTime); // Wait for 1000 millisecond(s)
  
  
    // turn the LED on (HIGH is the voltage level)
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  
  delay(delayTime); // Wait for 1000 millisecond(s)
  
  
    // turn the LED on (HIGH is the voltage level)
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  
  delay(delayTime); // Wait for 1000 millisecond(s)
  
  
    // turn the LED on (HIGH is the voltage level)
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  
  delay(delayTime); // Wait for 1000 millisecond(s)
  
} //end CCW
