int trig = 13;
int echo = 12;
int buzzer = 11;
int red = 10;
int yellow = 9;
int green = 8;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
 digitalWrite(trig, LOW);
 delay(2);

 digitalWrite(trig, HIGH);
 delay(10);
 digitalWrite(trig, LOW);

 int duration = pulseIn(echo, HIGH);
 int distance = (duration * 0.034) / 2;


  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  digitalWrite(buzzer, LOW);

 if(distance >= 2 && distance < 6) {
  digitalWrite(red, HIGH);
 } else if (distance >= 6 && distance < 9) {
  digitalWrite(yellow, HIGH);
 } else if (distance >= 9 && distance <= 30) {
  digitalWrite(green, HIGH);
  digitalWrite(buzzer, HIGH);
}
delay(100);
}
