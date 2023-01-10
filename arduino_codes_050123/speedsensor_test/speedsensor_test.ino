volatile float REV=0;
int RPM_VALUE =0;
int PREVIOUS=0;
int TIME;

int int_pin = 3;

void INTERRUPT()
{
  //TIME=millis()-PREVIOUS;
  REV++;
}
void setup()
{
  pinMode(int_pin, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(int_pin), INTERRUPT, RISING);
}
void loop()
{
  delay(1000);
  //detachInterrupt(digitalPinToInterrupt(int_pin)); //neden 1 değil?
  TIME=millis()-PREVIOUS;
  Serial.print("TIME: ");
  Serial.println(TIME);
  RPM_VALUE=(REV/TIME) * 60000;
  Serial.print("RPM_VALUE: ");
  Serial.println(RPM_VALUE);
  PREVIOUS=millis();
  REV = 0;
  //attachInterrupt(digitalPinToInterrupt(int_pin), INTERRUPT, RISING);
}
