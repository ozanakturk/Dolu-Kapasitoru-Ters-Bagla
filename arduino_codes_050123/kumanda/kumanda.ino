#include <IRremote.h>
int kumanda = 2;
int ledler[20];
int sure=500;

decode_results results;
IRrecv irrecv(kumanda);

void sondur(){
    for(int j = 7; j <= 13; j++)
    digitalWrite(ledler[j], LOW);


}

void setup() {
  // put your setup code here, to run once:
  for(int i = 7; i <= 13; i++){
    ledler[i] = i;
    pinMode(i, OUTPUT);
  }
    irrecv.enableIRIn();
    irrecv.blink13(true);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
        if(results.value == 0xFFA25D){
          digitalWrite(ledler[7], !digitalRead(ledler[7]));
          delay(sure);
          Serial.println("hello");
        }
        if(results.value == 0xFF629D){
          digitalWrite(ledler[8], !digitalRead(ledler[8]));
          delay(sure);
          Serial.println("hello");
        }
        if(results.value == 0xFFE21D){
          digitalWrite(ledler[9], !digitalRead(ledler[9]));
          delay(sure);
          Serial.println("hello");
        }
        if(results.value == 0xFF22DD){
          digitalWrite(ledler[10], !digitalRead(ledler[10]));
          delay(sure);
          Serial.println("hello");
        }
        if(results.value == 0xFF02FD){
          digitalWrite(ledler[11], !digitalRead(ledler[11]));
          delay(sure);
          Serial.println("hello");
        }
        if(results.value == 0xFFC23D){
          digitalWrite(ledler[12], !digitalRead(ledler[12]));
          delay(sure);
          Serial.println("hello");
        }
        if(results.value == 0xFFE01F){
          digitalWrite(ledler[13], !digitalRead(ledler[13]));
          delay(sure);
          Serial.println("hello");
        }
  }
}
