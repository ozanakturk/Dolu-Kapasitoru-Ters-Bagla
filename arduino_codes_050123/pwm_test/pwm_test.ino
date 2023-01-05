//#define PERIOD 10
int pwm_pin = 6;
//String op;

void setup() {
  pinMode(pwm_pin, OUTPUT);
  Serial.begin(9600);
  //TCCR0B = TCCR0B & B11111000 | B00000010; // for PWM frequency of 7812.50 Hz
}

void loop(){
  /*
   if (Serial.available() > 0) {
    op = Serial.readString();
    pwm((op.toInt())/10.0);
  */  
   analogWrite(pwm_pin, 127);
   delay(3000);
   /*analogWrite(pwm_pin, 128);
   delay(3000);
   analogWrite(pwm_pin, 192);
   delay(3000);
   analogWrite(pwm_pin, 255);
   delay(3000);*/
}
