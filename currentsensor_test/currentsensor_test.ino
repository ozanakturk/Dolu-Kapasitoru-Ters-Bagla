/*
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc = analogRead(A0);
  float voltage = adc * 5 / 1023.0;
  float current = (voltage - 2.5) / 0.066;
  /*if (current < 0.16) {
    current = 0;
  }
  Serial.print("Current : ");
  Serial.println(current);
  delay(300);
}
*/
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
  detachInterrupt(0);
  TIME=millis()-PREVIOUS;
  RPM_VALUE=(REV/TIME) * 60000;
  PREVIOUS=millis();
  REV = 0;
  Serial.println(RPM_VALUE);
  attachInterrupt(1, INTERRUPT, RISING);
}