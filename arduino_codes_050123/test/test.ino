#define INTERVAL 781.25*5
int pwm_pin = 6;
int shutdown_pin = 3;
#define pot_pin A1
float D = 0.50;

void setup() {
  pinMode(pwm_pin, OUTPUT);
  pinMode(shutdown_pin, OUTPUT);
  pinMode(pot_pin, INPUT);
  
  Serial.begin(9600);
  //analogWrite(pwm_pin, 0);
  TCCR0B = TCCR0B & B11111000 | B00000010; // for PWM frequency of 7812.50 Hz
}

void loop() {
  //ASCENSION
  digitalWrite(shutdown_pin, HIGH);
  /*
  for(int i = 0; i <= round(D*255); i++){      //lasts for 0.256*INTERVAL seconds
    /*if(current >= 25.0){
      analogWrite(pwm_pin, 0);
    }
    //else{
    analogWrite(pwm_pin, i);        //for INTERVAL=10, for loop:2.56 seconds
    //}
    delay(INTERVAL);                   
  }
  
  while(1);*/
  //-------------------------------------POT PWM CONTROL
  float voltage = analogRead(A1);
  float pwm = voltage / 1024;
  Serial.println(pwm);
  analogWrite(pwm_pin, round(pwm*255));
  
}
