void part2() {
  while (wp2 == 0) {

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

    if (L_junctioncount == 0  &&  l_maxspeed <= 110) {//////////////100
      l_maxspeed ++;
      r_maxspeed ++;
      delay(5); //////////////////////////////5
    }
    else if (L_junctioncount == 1 && l_maxspeed >= 30) {
      l_maxspeed--;
      r_maxspeed--;
      delay(3);//////////////////////////////////3
    }
    else if (L_junctioncount == 2) {
      l_maxspeed = 20;
      r_maxspeed = 20;
//      l_maxspeed=30;
//      r_maxspeed=30;
    }
    if ((F_positionval <= 20 || L_junctioncount < 2 || F_positionval == 255 )) {
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
      wp2 = 1;
      R_junctioncount = 0;
      L_junctioncount = 0;
      F_junctioncount = 0;
      L_jn = 0;
      R_jn = 0;
      F_jn = 0;
    }
  }
}





