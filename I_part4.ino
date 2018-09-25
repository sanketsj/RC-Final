//starting
void part4() {
  while (wp4 == 0) {
    forward_sense();
    left_sense();

    
    if (digitalRead(F_junctionpulse) == HIGH)
    {

      F_jn = 1;
    }
    if (digitalRead(F_junctionpulse) == LOW && F_jn == 1)
    {
      F_junctioncount++;
      F_jn = 0;
    }

    
    if (F_junctioncount == 0 && r == 0) {
      l_maxspeed ++;
      r_maxspeed ++;
      delay(5);
      if ( l_maxspeed == 130 && r == 0) {
        r = 1;
      }

    }
    else if ( l_maxspeed >= 35) {
      l_maxspeed --;
      r_maxspeed --;
      delay(3);
    }
    if (F_junctioncount == 1) {
      l_maxspeed = 25;
      r_maxspeed = 25;
    }
    if (F_junctioncount<1 || L_positionval > 60 ) {
      if (F_positionval == 255 ) {
        F_positionval = f_lastvalue;
      }
      if (F_positionval < 35 && F_positionval >= 0) {
        l_m_speed = map(F_positionval , 0, 34, l_maxspeed - 50, l_maxspeed);
        r_m_speed = map(F_positionval , 0, 34, r_maxspeed + 50, r_maxspeed);
        digitalWrite(dir4, HIGH);
        digitalWrite(dir1, LOW);
        analogWrite(pwm4, r_m_speed);
        analogWrite(pwm1, l_m_speed);
      }
      else if (F_positionval >= 35 && F_positionval <= 70) {
        l_m_speed = map(F_positionval , 35, 70, l_maxspeed, l_maxspeed + 50);
        r_m_speed = map(F_positionval , 35, 70, r_maxspeed, r_maxspeed - 50);
        digitalWrite(dir4, HIGH);
        digitalWrite(dir1, LOW);
        analogWrite(pwm4, r_m_speed);
        analogWrite(pwm1, l_m_speed);
      }
    }
    else {
      r_stop();
      r = 0;
      count = 2;
      wp4 = 1;
      F_junctioncount = 0;
    }
  }
}
