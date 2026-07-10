#include <ESP32Servo.h>

Servo leftServo;
Servo rightServo;
int heartRate = 95;
int systemMode = 0;
byte pushButton = 4;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  Serial.begin(9600);
  leftServo.attach(18);
  rightServo.attach(19);
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(4) == LOW) {
    systemMode = 1;
  }

  if(Serial.available() > 0) {
    heartRate = Serial.parseInt();
  }
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if(systemMode == 1 && (heartRate > 160 || heartRate < 55)) {
      leftServo.write(90);
      rightServo.write(90);
    } else {
      leftServo.write(0);
      rightServo.write(0);
    }
  }
}