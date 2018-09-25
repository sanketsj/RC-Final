
void forward_sense(){
  f_lastvalue = F_positionval;
  digitalWrite(F_serialen, LOW);
  while (Serial.available() <= 0);
  F_positionval = Serial.read();
  digitalWrite(F_serialen, HIGH);
  
}
void left_sense(){
  l_lastvalue = L_positionval;
  digitalWrite(L_serialen, LOW);
  while (Serial.available() <= 0);
  L_positionval = Serial.read();
  digitalWrite(L_serialen, HIGH);
  
}
void right_sense(){
  r_lastvalue = R_positionval;
  digitalWrite(R_serialen, LOW);
  while (Serial.available() <= 0);
  R_positionval = Serial.read();
  digitalWrite(R_serialen, HIGH);
}
void invert_right_sense(){
  right_sense();
  I_R_positionval = map(R_positionval, 0, 70, 70, 0);
}
void clockwise(){
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);
  digitalWrite(dir3, LOW);
  digitalWrite(dir4, LOW);
  analogWrite(pwm1, 15);
  analogWrite(pwm4, 15);
  analogWrite(pwm2, 15);
  analogWrite(pwm3, 15);
}
void anticlock(){
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, HIGH);
  digitalWrite(dir3, HIGH);
  digitalWrite(dir4, HIGH);
  analogWrite(pwm1, 15);
  analogWrite(pwm4, 15);
  analogWrite(pwm2, 15);
  analogWrite(pwm3, 15);
}
void r_stop(){
  digitalWrite(pwm1, LOW);
  digitalWrite(pwm2, LOW);
  digitalWrite(pwm3, LOW);
  digitalWrite(pwm4, LOW);
}

