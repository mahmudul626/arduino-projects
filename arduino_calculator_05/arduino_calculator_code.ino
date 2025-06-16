#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int permanent_value_1= HIGH;
int count_1 = 0;
int permanent_value_2= HIGH;
int count_2 = 0;

void setup() {
pinMode(13, INPUT_PULLUP);
pinMode(12, INPUT_PULLUP);
pinMode(11, INPUT_PULLUP);
pinMode(10, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
lcd.init();
lcd.backlight();
}

void first_switch() {
int current_value_1 = digitalRead(13);
if (current_value_1 == LOW && permanent_value_1 == HIGH) {
  count_1 += 1;
  lcd.setCursor(0,0);
  lcd.print(count_1);
  delay(500);
}
permanent_value_1 = current_value_1;
}

void second_switch() {
int current_value_2 = digitalRead(12);
if (current_value_2 == LOW && permanent_value_2 == HIGH) {
  count_2 += 1;
  lcd.setCursor(12,0);
  lcd.print(count_2);
  delay(500);
}
permanent_value_2 = current_value_2;
}

void arethmatic_oparetor() {
  int arethmatic_1 = digitalRead(11);
  int arethmatic_2 = digitalRead(10);
  int arethmatic_3 = digitalRead(9);
  int arethmatic_4 = digitalRead(8);
  if(arethmatic_1 == LOW) {
    int add = count_1 + count_2;
    lcd.setCursor(7,0);
    lcd.print("+");
    lcd.setCursor(0,1);
    lcd.print(add);
  }
  if(arethmatic_2 == LOW) {
    int sub = count_1 - count_2;
    lcd.setCursor(7,0);
    lcd.print("-");
    lcd.setCursor(0,1);
    lcd.print(sub);
  }
  if(arethmatic_3 == LOW) {
    int mul = count_1 * count_2;
    lcd.setCursor(7,0);
    lcd.print("x");
    lcd.setCursor(0,1);
    lcd.print(mul);
  }
  if(arethmatic_4 == LOW) {
    int div = count_1 / count_2;
    lcd.setCursor(7,0);
    lcd.print("/");
    lcd.setCursor(0,1);
    lcd.print(div);
  }
}

void loop() {
first_switch();
second_switch();
if(count_1 > 0 && count_2 > 0) {
  arethmatic_oparetor();
}
}