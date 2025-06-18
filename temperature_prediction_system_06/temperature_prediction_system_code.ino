#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(4,DHT22);
bool dataRead1 = false;
bool dataRead2 = false;
float temp_1;
float temp_2;

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
}
void loop() {
 if(!dataRead1 && digitalRead(11) == LOW) {
  delay(300);
  temp_1 = dht.readTemperature();
  dataRead1 = true;
 }
 if(!dataRead2 && digitalRead(10) == LOW) {
  delay(300);
  temp_2 = dht.readTemperature();
  dataRead2 = true;
 }

 lcd.setCursor(0,0);
 lcd.print(temp_1);
  lcd.setCursor(0,1);
 lcd.print(temp_2);
}
