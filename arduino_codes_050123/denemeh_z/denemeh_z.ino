volatile float REV=0;
float RPM_VALUE =0;
float PREVIOUS_DATA = -1;
volatile float CURRENT_DATA = 0;
float time_passed;

int int_pin = 3;

float increment = 0;
int pREV = 0;

float rpm_arr[5] = {0,0,0,0,0};

int delay_time = 2000;
float scale_correction = 1;//6.923;

void INTERRUPT()
{
  REV++;
//  PREVIOUS_DATA = CURRENT_DATA;
//  CURRENT_DATA = millis();
//  time_passed = (CURRENT_DATA) - PREVIOUS_DATA;
}
void setup()
{
  pinMode(int_pin, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(int_pin), INTERRUPT, RISING);
}
void loop()
{
  //float time_passed = (CURRENT_DATA) - PREVIOUS_DATA;
//  Serial.println(time_passed);
//  float freq = 1/time_passed;
//  Serial.println(freq);
  

  delay(delay_time);
  
  increment = REV - pREV;
  RPM_VALUE = ((increment * 60000 / delay_time) / scale_correction);
  for(int i = 0; i < 4; i++){
    rpm_arr[i+1] = rpm_arr[i];
  }
  rpm_arr[0] = RPM_VALUE;
  float avg = (rpm_arr[0] + rpm_arr[1] + rpm_arr[2] + rpm_arr[3] + rpm_arr[4]) / 5;
    pREV = REV;
  Serial.println(RPM_VALUE);
}
