/////////////////////////////////we are using this saxi bich /////////////////////////////////
#define dcv    51/////////////////////////////////////
#define dir1   25
#define pwm1   4
#define dir2   19
#define pwm2   3
#define dir3   27
#define pwm3   5
#define dir4   29
#define pwm4   6
#define eball 45
#define eproxi 47
#define rx 0
#define tx 1
#define led 53
#define F_serialen  46
#define L_serialen  42
#define R_serialen  28

#define sttake 8
#define stthrow 7
#define ppr_led 43

#define F_junctionpulse   48
#define L_junctionpulse   44
#define R_junctionpulse   30

unsigned int F_junctioncount = 0;
unsigned int L_junctioncount = 0;
unsigned int R_junctioncount = 0;
int F_readval, L_readval, R_readval;
int F_positionval , L_positionval = 255, R_positionval, I_R_positionval;
int l_m_speed, r_m_speed ,  f_lastvalue , l_lastvalue, r_lastvalue, startspeed = 60;
int stop_speed;
int robot_max_speed = 150;
int l_maxspeed = 60;
int r_maxspeed = 60;
int  q = 0, w = 0, i = 1, e = 0, f = 0, r = 0, rr = 1, ball = 1, proxi, count = 1, back = 0, star = 1, error;
int wp2 = 1, l, wp3 = 1, wp8 = 1, wp7 = 1, wp4 = 1 , L_jn = 0, F_jn = 0, R_jn = 0, a, progselect = 0, cn = 0;
void forward_sense();
void jump_to_task2();
void right_sense();
void left_sense();
void r_stop();
void start_robo();
void staperthrow();
void stapertake();
void part1();
void part2();
void part3();
void part4();
void part7();
void part8();
byte x = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(eball, INPUT);
  pinMode(eproxi, INPUT);

  pinMode(sttake, OUTPUT);
  pinMode(stthrow, OUTPUT);
  pinMode(ppr_led, OUTPUT);
  pinMode(F_junctionpulse, INPUT);
  pinMode(L_junctionpulse, INPUT);
  pinMode(R_junctionpulse, INPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);
  pinMode(F_serialen, OUTPUT);
  pinMode(L_serialen, OUTPUT);
  pinMode(R_serialen, OUTPUT);
  pinMode(dcv, OUTPUT);
  digitalWrite(pwm1, LOW);
  digitalWrite(pwm2, LOW);
  digitalWrite(pwm3, LOW);
  digitalWrite(pwm4, LOW);
  digitalWrite(ppr_led, LOW);
  digitalWrite(F_serialen, HIGH);
  digitalWrite(L_serialen, HIGH);
  digitalWrite(R_serialen, HIGH);
  Serial.begin(9600);
  F_positionval = 255;
  while ((ball = digitalRead(eball)) == 0)
  {
    if (digitalRead(eproxi) == HIGH)
    {

      cn = 1;
    }
    if (digitalRead(eproxi) == LOW && cn == 1)
    {
      progselect++;
      cn = 0;
    }
  }
  star = 0;
  start_robo();
  if (count == 1 && progselect == 0) {
    while (rr == 1)
    {
      part1();
    }
  }
  else if (count == 1 && progselect > 0) { //skip part 1
    while (rr == 1)
    {
      jump_to_task2();
    }
  }
  if (progselect == 1)
  {
    count = 4;
    digitalWrite(ppr_led, HIGH);
    delay(500);
    digitalWrite(ppr_led, LOW);

  }
  else if (progselect >= 2)
  {
    count = 5;
    digitalWrite(ppr_led, HIGH);
    delay(400);/////////////////////////////////////////500
    digitalWrite(ppr_led, LOW);
    delay(200);////////////////////////////////////////300
    digitalWrite(ppr_led, HIGH);
    delay(400);///////////////////////////////////////500
    digitalWrite(ppr_led, LOW);
  }

}

void loop() {
  if ( count == 2 && (ball = digitalRead(eball)) == 1 && back == 0 && progselect == 0) {
    //Serial.println(ball);
    //stabilize servo close
    delay(1300);//////////////////////////////////////////////////////////////////
    staperthrow();//when part 2 starts then do staper on
    wp2 = 0;
    part2();

    if (digitalRead(eball) == HIGH)
    {

      /*



        for (l = 110 ; l >= 0; l = l - 5)
        {
        digitalWrite(led, HIGH);
        delay(l);
        digitalWrite(led, LOW);
        delay(l);

        }
        delay(200);




      */
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      digitalWrite(dcv, 1);//throw a ball
      delay(200);
      digitalWrite(dcv, 0);
    }
    else
    {
      delay(100);/////////////////////////////////
    }
    stapertake();///////////////////staper take
    back = 1 ;
  }
  if ( count == 2 && (ball = digitalRead(eball)) == 0 && back == 1 && progselect == 0) {
    Serial.println("part3");
    wp3 = 0;
    part3();
    if ((proxi = digitalRead(eproxi)) == 1) { //at last position  search for proximity sensor
      back = 0; //if sensor is detected then back=0
    }
    else if ((proxi = digitalRead(eproxi)) == 0) {
      count = 3; //if it is not detected then count=3
      digitalWrite(ppr_led, HIGH);
      delay(300);
      digitalWrite(ppr_led, LOW);
    }
  }
  if (count == 3)
  {

    wp4 = 0;
    part4();
    count = 4;
    back = 0;
  }


  if (count == 4  && (ball = digitalRead(eball)) == 1 && back == 0) {
    //stabilize servo close
    delay(1300);///////////////////////////////////////////////////////////
    staperthrow();//when part 2 starts then do staper on
    wp2 = 0; //full part two in while loop
    part2();
    if (digitalRead(eball) == HIGH)
    {

      /*
        for (l = 110 ; l >= 0; l = l - 5)
        {
        digitalWrite(led, HIGH);
        delay(l);
        digitalWrite(led, LOW);
        delay(l);
        }



      */
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      digitalWrite(dcv, 1);//throw a ball
      delay(200);
      digitalWrite(dcv, 0);
    }

    else
    {
      delay(100);/////////////////////////////////
    }
    stapertake();///////////////////staper take
    back = 1 ;
  }
  if (back == 1 && (ball = digitalRead(eball)) == 0 && count == 4) {
    wp3 = 0;
    part3();
    if ((proxi = digitalRead(eproxi)) == 1) { //at last position  search for proximity sensor
      back = 0; //if sensor is detected then back=0
    }
    else {
      back = 0;
      count = 5; //if it is not detected then count=5
      digitalWrite(ppr_led, HIGH);
      delay(300);
      digitalWrite(ppr_led, LOW);
    }
  }

  if (count == 5  && (ball = digitalRead(eball)) == 1 && back == 0) {
    //stabilize servo close
    delay(1300);////////////////////////////////////////////////////////
    staperthrow();//when part 7 starts then do staper on
    //    setPressure2();
    wp7 = 0; //full part two in while loop
    part7();

    if (digitalRead(eball) == HIGH)
    {

      /*
        for (l = 100 ; l >= 0; l = l - 5)
        {
        digitalWrite(led, HIGH);
        delay(l);
        digitalWrite(led, LOW);
        delay(l);

        }
        delay(300);
      */
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      digitalWrite(dcv, 1);//throw a ball
      delay(150);
      digitalWrite(dcv, 0);
    }
    else
    {
      delay(100);/////////////////////////////////
    }

    stapertake();///////////////////staper takel
    back = 1 ;
  }
  if (back == 1 && (ball = digitalRead(eball)) == 0 && count == 5) {
    wp8 = 0;
    part8();
    back = 0;
  }
}

