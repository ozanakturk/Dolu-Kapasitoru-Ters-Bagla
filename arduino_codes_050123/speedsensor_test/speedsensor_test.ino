float REV=0;
int RPM_VALUE =0;
int PREVIOUS=0;
int TIME;
void INTERRUPT()
{
  REV++;
}
void setup()
{
  Serial.begin(9600);
  attachInterrupt(1, INTERRUPT, RISING);

}
void loop()
{
  delay(1000);
  detachInterrupt(0);//neden 1 değil?
  TIME=millis()-PREVIOUS;
  RPM_VALUE=(REV/TIME) * 60000;
  PREVIOUS=millis();
  REV = 0;
  Serial.println(RPM_VALUE);
  attachInterrupt(1, INTERRUPT, RISING);
}
