#include <ESP32Servo.h>

Servo rightServo;
Servo leftServo;
byte red_led = 27;
int heartRate = 85;
unsigned long previousMillis = 0;
unsigned long accidentTimer = 0;
const long firstInterval = 1000;
int systemStatus = 0;
bool accidentClockStarted = false;

void setup() {
  Serial.begin(9600);
  rightServo.attach(19);
  leftServo.attach(18);
  pinMode(27, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    heartRate = Serial.parseInt();
  }

  if(heartRate > 160 || heartRate < 55) {
    systemStatus = 1;
    
    if(accidentClockStarted == false) {
      accidentTimer = millis();
      accidentClockStarted = true;
    } 
  } else {
    systemStatus = 0;
    accidentClockStarted = false;
    digitalWrite(27, LOW);
  }

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= firstInterval) {
    previousMillis = currentMillis;

    if(systemStatus == 1) {
      rightServo.write(90);
      leftServo.write(90);
    } else {
      rightServo.write(0);
      leftServo.write(0); 
    }
  }
  if(systemStatus = 1 && (currentMillis - accidentTimer >= 3000)) {
    digitalWrite(27, HIGH);
  }
}