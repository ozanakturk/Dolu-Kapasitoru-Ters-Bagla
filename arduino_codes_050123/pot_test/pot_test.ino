float voltage;
float pwm;
int pot_pin = A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(pot_pin, INPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltage = analogRead(A1);
  pwm = voltage / 1024;
  Serial.println(pwm);
  analogWrite(6, round(pwm*255));
  delay(300);
}
