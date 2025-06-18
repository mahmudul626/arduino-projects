int led = 13; //Connected to pin 13 on Arduino
void setup() {
  pinMode(led, OUTPUT); // led setup as output
}
void loop() {
  digitalWrite(led, HIGH); // (led, HIGH) means led/13 pin on/high/5V
  delay(1000); // led on for 1s (1000ms = 1s)
  digitalWrite(led, LOW); // (led, LOW) means led/13 pin off/low/0V
  delay(1000); // led off for 1s (1000ms = 1s)
}