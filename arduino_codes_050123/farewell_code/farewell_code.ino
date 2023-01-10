#include <IRremote.h>       // Receiver library (if required, download the module from github and move it the the library folder under Arduino)
#include <LiquidCrystal.h>  // LCD library (should be available already in your computer)
#include <PID_v1.h>         // PID control library (if required, again download from github) 
                            // https://www.teachmemicro.com/arduino-pid-control-tutorial/

#define PIN_INPUT A0 // Pin number can change
#define PIN_OUTPUT 6 // Pin number can change

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD screen pins (able to change)

int ir_rec = 6; // Receiver pin (able to change)
int delay_time = 300;

double Setpoint, Input, Output; // For PID control
double Kp=2, Ki=5, Kd=1; // Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT); // PID parameters pass by reference

decode_results results;
IRrecv irrecv(ir_rec);

void setup() {
    // PID initilization
    Input = analogRead(PIN_INPUT);
    Setpoint = 100;
    myPID.SetMode(AUTOMATIC);

    // IR remote control initilization
    irrecv.enableIRIn();
    irrecv.blink13(true);
    Serial.begin(9600);
}

void loop() {
  //PID control codes
  
  Input = analogRead(PIN_INPUT);
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);

  // LCD screen codes
  
  lcd.begin(16, 2); //starts LCD screen (2 rows 16 columns)
  lcd.setCursor(2, 0);  // sets the cursor to 3rd column 1st row
  lcd.print("CURRENT: "); //prints something starting from the cursor

  float example_current_value = 0.56;
  lcd.setCursor(10, 0); // sets the cursor to 11th column 1st row
  lcd.print(example_current_value);
  delay(delay_time); 

  // IR receiver codes
  /* Notes: The HEX value of a press action can change even when 
     pressing the same button. Feel free to apply different 
     pressure levels, hold longer or press at a different angle to
     the button you want. The correct pressing action will result in
     seeing the correct number on the serial monitor.

     You can merge LCD codes with the receiver codes 
  */
  if (irrecv.decode(&results)){ // = if any button is pressed
      Serial.println(results.value, HEX); // This line writes the HEX value of the received button (you can comment this line out)
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
