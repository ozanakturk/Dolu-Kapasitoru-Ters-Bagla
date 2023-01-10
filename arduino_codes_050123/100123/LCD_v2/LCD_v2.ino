#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int delay_time = 300;
float current = 0.56;

void setup() {
}

void loop() {
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("CURRENT: ");
  lcd.setCursor(10, 0);
  lcd.print(current);
  delay(delay_time);
}
