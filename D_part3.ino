void part3() {
  while (wp3 == 0) {
    right_sense();
    forward_sense();
    if (digitalRead(R_junctionpulse) == HIGH)
    {

      R_jn = 1;
    }
    if (digitalRead(R_junctionpulse) == LOW && R_jn == 1)
    {
      R_junctioncount++;
      R_jn = 0;
    }
    if (digitalRead(L_junctionpulse) == HIGH)
    {

      L_jn = 1;
    }
    if (digitalRead(L_junctionpulse) == LOW && L_jn == 1)
    {
      L_junctioncount++;
      L_jn = 0;
    }


    if (L_junctioncount < 2 && l_maxspeed <= 130 ) {///////////100
      l_maxspeed++;
      r_maxspeed++;
      delay(4);///////////////////////5
    }
    else if (L_junctioncount == 2 && l_maxspeed >= 25) {////////////////30
      l_maxspeed=l_maxspeed-2;///////////////
      r_maxspeed=r_maxspeed-2;///////////////

     // l_maxspeed--;
     // r_maxspeed--;
      //delay(1);///////////////////////////////////////////////////////////////////////////
    }
    if (R_junctioncount == 2) {
      l_maxspeed == 20;
      r_maxspeed == 20;
    }
    if (R_junctioncount < 2 || F_positionval > 45)
    {
      if (R_positionval == 255) {
        R_positionval = r_lastvalue;
      }
      if (R_positionval < 35 && R_positionval >= 0) {
        l_m_speed = map(R_positionval , 0, 34, l_maxspeed - 50, l_maxspeed);
        r_m_speed = map(R_positionval , 0, 34, r_maxspeed + 50, r_maxspeed);
        digitalWrite(dir3, HIGH);
        digitalWrite(dir2, LOW);
        analogWrite(pwm3, r_m_speed);
        analogWrite(pwm2, l_m_speed);
      }
      else if (R_positionval >= 35 && R_positionval <= 70) {
        l_m_speed = map(R_positionval , 35, 70, l_maxspeed, l_maxspeed + 50);
        r_m_speed = map(R_positionval , 35, 70, r_maxspeed, r_maxspeed - 50);
        digitalWrite(dir3, HIGH);
        digitalWrite(dir2, LOW);
        analogWrite(pwm3, r_m_speed);
        analogWrite(pwm2, l_m_speed);
      }
    }
    else {
      r_stop();
      wp3 = 1;
      R_junctioncount = 0;
      L_junctioncount = 0;
      F_junctioncount=0;
      L_jn=0;
      R_jn=0;
      F_jn=0;
    }
  }
}

