#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(2,DHT22);

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  int temp = dht.readTemperature();
  int hum = dht.readHumidity();
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print((temp));
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Hum:");
  lcd.print(hum);
  lcd.print("%");
  delay(1000);
}