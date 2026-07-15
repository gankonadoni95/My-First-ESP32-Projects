#include <ESP32Servo.h>

Servo leftServo;
Servo rightServo;
byte systemStatus = 0;
unsigned long previousMillis = 0;
unsigned long accidentTimer = 0;
const long interval= 1500;
bool accidentClockStarted = false;
byte red_led = 27;
const int buzzer = 25;
int IdrValue = 0;
int threshold = 850;

void setup() {
  Serial.begin(9600);
  leftServo.attach(19);
  rightServo.attach(18);
  pinMode(27, OUTPUT);
  pinMode(34, INPUT);
  pinMode(25, OUTPUT);
}

void loop() {
  int IdrValue = analogRead(34);

  if(IdrValue < threshold) {
    systemStatus = 1;

  if(accidentClockStarted == false) {
    accidentTimer = millis();
    accidentClockStarted = true;
  } 
  } else {
    systemStatus = 0;
    accidentClockStarted = false;
    digitalWrite(27, LOW);
    noTone(25);
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
  if(systemStatus == 1 && (currentMillis - accidentTimer >= 3000)) {
    tone(25, 1000);
    digitalWrite(27, HIGH);
  }
}
