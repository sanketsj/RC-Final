void part7() {
  while (wp7 == 0) {
    left_sense();
    forward_sense();


    if (digitalRead(L_junctionpulse) == HIGH)
    {

      L_jn = 1;
    }
    if (digitalRead(L_junctionpulse) == LOW && L_jn == 1)
    {
      L_junctioncount++;
      L_jn = 0;
    }
    if (digitalRead(R_junctionpulse) == HIGH)
    {

      R_jn = 1;
    }
    if (digitalRead(R_junctionpulse) == LOW && R_jn == 1)
    {
      R_junctioncount++;
      R_jn = 0;
    }

    if ( l_maxspeed  <= 160 && L_junctioncount < 3) {///////////150
      l_maxspeed++;
      r_maxspeed++;
      delay(4);///////////////////////////4
    }
    if (L_junctioncount >= 3 && L_junctioncount <= 4 && l_maxspeed >= 30) {
      l_maxspeed--;
      r_maxspeed--;
      delay(4);//////////////////////////4
    }
    if (L_junctioncount == 5 ) {
      l_maxspeed=25;
      r_maxspeed=25;
    }
    if (F_positionval <= 20 || L_junctioncount < 5 || F_positionval == 255 )  {
      if (L_positionval == 255) {
        L_positionval = l_lastvalue;
      }
      if (L_positionval < 35 && L_positionval >= 0) {
        l_m_speed = map(L_positionval , 0, 34, l_maxspeed - 50, l_maxspeed);
        r_m_speed = map(L_positionval , 0, 34, r_maxspeed + 50, r_maxspeed);
        digitalWrite(dir3, LOW);
        digitalWrite(dir2, HIGH);
        analogWrite(pwm2, r_m_speed);
        analogWrite(pwm3, l_m_speed);
      }
      else if (L_positionval >= 35 && L_positionval <= 70) {
        l_m_speed = map(L_positionval , 35, 70, l_maxspeed, l_maxspeed + 50);
        r_m_speed = map(L_positionval , 35, 70, r_maxspeed, r_maxspeed - 50);
        digitalWrite(dir3, LOW);
        digitalWrite(dir2, HIGH);
        analogWrite(pwm2, r_m_speed);
        analogWrite(pwm3, l_m_speed);
      }
    }
    else {
      r_stop();
      wp7 = 1;
      R_junctioncount = 0;
      L_junctioncount = 0;
      F_junctioncount = 0;
      L_jn = 0;
      R_jn = 0;
      F_jn = 0;
    }
  }
}

