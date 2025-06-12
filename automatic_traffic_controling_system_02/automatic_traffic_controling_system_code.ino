#include <Servo.h>
Servo myservo;
int red = 11;
int yellow = 8;
int green = 5;
int trig = 13;
int echo = 12;
long duration;
float distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  myservo.attach(3);
} 
void loop() {
digitalWrite(trig, LOW);
delay(2);
digitalWrite(trig, HIGH);
delay(10);
digitalWrite(trig, LOW);

duration = pulseIn(echo, HIGH);
distance = duration * 0.034 / 2;
if(distance > 20) {
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  myservo.write(90);
} else {
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  delay(1000);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  myservo.write(0);
  delay(1000);
}
}