#include <ESP32Servo.h>

Servo leftServo;
Servo rightServo;
byte green_led = 27;
byte red_led = 14;
int heartRate = 95;
int a;

void setup() {
  Serial.begin(9600);
  leftServo.attach(19);
  rightServo.attach(18);
  pinMode(27, OUTPUT);
  pinMode(14, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    heartRate = Serial.parseInt(); 
    }
    if(heartRate > 160 || heartRate < 55) {
      digitalWrite(27, LOW);
      digitalWrite(14, HIGH);
      delay(100);
      digitalWrite(14, LOW);
      delay(100);
      digitalWrite(14, HIGH);
      delay(100);
      digitalWrite(14, LOW);
      delay(100);
      digitalWrite(14, HIGH);
      delay(100);
      digitalWrite(14, LOW);
      delay(550); 
      leftServo.write(90);
      rightServo.write(90);
      delay(500);
      leftServo.write(0);
      rightServo.write(0);
      delay(1000);
    }
    else {
      digitalWrite(14, LOW);
      leftServo.write(0);
      rightServo.write(0);

      for (int a = 0; a < 255; a++) {
        analogWrite(27, a);
        delay(5);
      }
      for(int a = 255; a > 0; a--) {
        analogWrite(27, a);
        delay(5);
      }
      analogWrite(27, 0);
      delay(500);
  }
}