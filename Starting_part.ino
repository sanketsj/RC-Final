void start_robo()
{
  while (star == 0)
  {
    if (q = 0)
    {
      digitalWrite(dir3, LOW);
      digitalWrite(dir2, HIGH);
      analogWrite(pwm2, 70);
      analogWrite(pwm3, 70);
      delay(1000);
      q = 1;
    }
    forward_sense();
    if (F_positionval == 255 || F_positionval > 20)
    {
      digitalWrite(dir3, LOW);
      digitalWrite(dir2, HIGH);
      analogWrite(pwm2, 40);
      analogWrite(pwm3, 40);
    }
    else
    {
      digitalWrite(pwm2, LOW);
      digitalWrite(pwm3, LOW);
      delay(500);
      star = 1;
    }
  }
}




/*
#include <Servo.h>

Servo myservo;
int pos = 0;   

void setup() {
  myservo.attach(11);
  myservo.write(100);
  delay(500);
}

void loop() {

  for (pos = 100; pos >= 24; pos -= 1) { 
    myservo.write(pos);             
    delay(20);                      
  }
  delay(5000);
  //myservo.write(25); 
  for (pos = 24; pos <=50; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(40);                       
  }
  for (pos = 50; pos <=100; pos += 1) { 
    myservo.write(pos);              
    delay(15);   
}
}*/
