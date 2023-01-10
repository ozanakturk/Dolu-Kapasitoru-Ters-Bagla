#include <IRremote.h>
int kumanda = 2;
int sure=500;

decode_results results;
IRrecv irrecv(kumanda);

void setup() {
  // put your setup code here, to run once:
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
          Serial.println("1");
        }
        if(results.value == 0xFF629D){
          Serial.println("2");
        }
        if(results.value == 0xFFE21D){
          Serial.println("3");
        }
        if(results.value == 0xFF22DD){
          Serial.println("4");
        }
        if(results.value == 0xFF02FD){
          Serial.println("5");
        }
        if(results.value == 0xFFC23D){
          Serial.println("6");
        }
        if(results.value == 0xFFE01F){
          Serial.println("7");
        }
        if(results.value == 0xFFA857){
          Serial.println("8");
        }
        if(results.value == 0xFF906F){
          Serial.println("9");
        }
        if(results.value == 0xFF9867){
          Serial.println("0");
        }

        if(results.value == 0xFF18E7){
          Serial.println("up");
        }
        if(results.value == 0xFF4AB5){
          Serial.println("down");
        }
        if(results.value == 0xFF5AA5){
          Serial.println("right");
        }
        if(results.value == 0xFF10EF){
          Serial.println("left");
        }
  }
}
