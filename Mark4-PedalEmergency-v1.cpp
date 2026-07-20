#include <ESP32Servo.h>

Servo leftServo;
Servo rightServo;

byte systemStatus = 0;
const byte pushButton = 4;
byte red_led = 27;
byte blue_led = 14;
unsigned long previousMillis = 0;
unsigned long accidentTimer = 0;
const long Interval= 1500;
bool accidentClockStarted = false;

void setup() {
  Serial.begin(9600);
  leftServo.attach(18);
  rightServo.attach(19);
  pinMode(27, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(4) == LOW) {
    systemStatus = 1;

    if(accidentClockStarted == false) {
      accidentTimer = millis();
      accidentClockStarted = true;
    }
  } else {
    systemStatus = 0;
    accidentClockStarted = false;
    digitalWrite(27, LOW);
    digitalWrite(14, HIGH);
  }

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= Interval) {
    previousMillis = currentMillis;

    if(systemStatus == 1) {
    leftServo.write(90);
    rightServo.write(90);
  } else {
    leftServo.write(0);
    rightServo.write(0);
    digitalWrite(27, LOW);
  }
}
  if(systemStatus == 1 && (currentMillis - accidentTimer >= 2500)) {
      digitalWrite(27, HIGH);
 }
}
