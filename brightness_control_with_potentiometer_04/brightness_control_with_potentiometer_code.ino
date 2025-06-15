#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
void setup() {
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  lcd.init();
  lcd.backlight();
}
void loop() {
  int value = analogRead(A0);
  int pwm_value = map(value, 0,1023,0,255);
  int percent = map(value, 0,1023,0,100);
  lcd.setCursor(0,0);
  lcd.print("Brightness: ");
  lcd.print(percent);
  lcd.print("%   ");
  analogWrite(13, pwm_value);
}