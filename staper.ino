void staperthrow()
{
  pinMode(stthrow, OUTPUT);
  digitalWrite(stthrow, HIGH);
  delay(100);
  digitalWrite(stthrow, LOW);
  pinMode(stthrow, INPUT);

}
void stapertake()
{
  pinMode(sttake, OUTPUT);
  digitalWrite(sttake, HIGH);
  delay(100);
  digitalWrite(sttake, LOW);
  pinMode(sttake, INPUT);

}
//uno 11 pulse 10 dir
