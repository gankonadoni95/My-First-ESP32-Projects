#include <ESP32Servo.h>

Servo myServo;
int heartRate = 190;

void setup() {
  Serial.begin(9600);
  myServo.attach(18);
}

void loop() {
  if(heartRate > 160) {
    myServo.write(90);
    delay(500);
    myServo.write(0);
    delay(500);
  }
  else {
    myServo.write(0);
  }
}
