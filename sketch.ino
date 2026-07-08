#include <ESP32Servo.h>

Servo leftServo;
Servo rightServo;
int heartRate = 85;
unsigned long previousMillis = 0;
const long interval = 1000;
int systemStatus = 0;

void setup() {
  Serial.begin(9600);
  leftServo.attach(18);
  rightServo.attach(19);
}

void loop() {
  if(Serial.available() > 0) {
    heartRate = Serial.parseInt();
  }

  if(heartRate > 160 || heartRate < 50) {
    systemStatus = 1;
  } else {
    systemStatus = 0;
  }
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if(systemStatus == 1) {
      leftServo.write(90);
      rightServo.write(90);
    } else {
      leftServo.write(0);
      rightServo.write(0); 
    }
  }
}