#define INTERVAL 781.25
#define CURRENT_LIMIT 0.50
#define D 1
int pwm_pin = 6;

int adc;
float current;
float voltage;
  
int MAX = 0;

int key = 0;

void get_current(){
  adc = analogRead(A0);
  voltage = adc * 5 / 1023.0;
  current = (voltage - 2.5) / 0.066;
}

void wait(){
  for(int i = 0; i <= 50; i++){
      get_current();
      Serial.print("Waiting current: ");
      Serial.println(current);
      delay(INTERVAL);                   
  }
}

void ascension(){
  for(int i = 0; i <= MAX; i++){
    get_current();
    Serial.print("Ascension current : ");
    Serial.println(current);
    if(current >= CURRENT_LIMIT){
      Serial.println("Warning: 0.5A is reached");
      analogWrite(pwm_pin, i);
      continue;
    }
    else if(current >= 5.0){
      analogWrite(pwm_pin, 0);
      key = 1;
      break;
    }
    else{
      analogWrite(pwm_pin, i);
    }
    delay(INTERVAL);                   
  }
}

void descension(){
  for(int i = MAX; i >= 0; i--){     
    get_current();
    Serial.print("Descension current : ");
    Serial.println(current);
    if(current >= CURRENT_LIMIT){
      Serial.println("Warning: 0.5A is reached");
      analogWrite(pwm_pin, i);
      continue;
    }
    else if(current >= 5.0){
      analogWrite(pwm_pin, 0);
      key = 1;
      break;
    }
    else{
      analogWrite(pwm_pin, i);     
    }
    delay(INTERVAL);                       
  } 
}

void setup() {
  pinMode(pwm_pin, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  MAX = round(D * 255);
  Serial.println(MAX);
  //analogWrite(pwm_pin, 0);
  TCCR0B = TCCR0B & B11111000 | B00000010; // for PWM frequency of 7812.50 Hz
}

void loop() {
  ascension();
  //wait();
  descension();
  //wait();
  if(key == 1){
    analogWrite(pwm_pin, 0);
    Serial.println("EXITING");
    while(1);                              
  }
}
