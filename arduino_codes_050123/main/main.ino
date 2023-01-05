#define INTERVAL 78.125
int pwm_pin = 6;

int adc = 0;
float current = 0.0;
float voltage = 0.0;
//String op;

void get_current(){
  int adc = analogRead(A0);
  float voltage = adc * 5 / 1023.0;
  float current = (voltage - 2.5) / 0.066;
}

void setup() {
  pinMode(pwm_pin, OUTPUT);
  Serial.begin(9600);
  //analogWrite(pwm_pin, 0);
  //TCCR0B = TCCR0B & B11111000 | B00000010; // for PWM frequency of 7812.50 Hz
}

void loop() {
  get_current();
  Serial.print("Current : ");
  Serial.println(current);
  delay(300);
  
  //ASCENSION
  for(int i = 0; i <= 255; i++){      //lasts for 0.256*INTERVAL seconds
    /*if(current >= 25.0){
      analogWrite(pwm_pin, 0);
    }*/
    //else{
      analogWrite(pwm_pin, i);        //for INTERVAL=10, for loop:2.56 seconds
      Serial.print("Current : ");
      Serial.println(current);
    //}
    delay(INTERVAL);                   
  }
  delay(5000);                        //delay 5 seconds

  //DESCENSION
  for(int i = 255; i >= 0; i--){      //lasts for 0.256*INTERVAL seconds
    analogWrite(pwm_pin, i);          //for INTERVAL=10, for loop:2.56 seconds
    delay(INTERVAL);
    Serial.print("Current : ");
    Serial.println(current);                   
  }
  delay(5000);                        //delay 5 seconds
  
}

//pwm((op.toInt())/10.0);
