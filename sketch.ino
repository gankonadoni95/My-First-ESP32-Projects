byte red_led = 27;
int heartRate = 80;

void setup() {
  Serial.begin(9600);
  pinMode(27, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    heartRate = Serial.parseInt();
  }

    if(heartRate > 160 || heartRate < 50) {
      for(int a = 0; a < 255; a++) {
        analogWrite(27, a);
        delay(15);
      }
      for(int a = 255; a > 0; a--) {
        analogWrite(27, a);
        delay(15);
      }
    }
    else if(heartRate < 160 || heartRate > 50) {
        digitalWrite(27, HIGH);
        delay(100);
        digitalWrite(27, LOW);
        delay(900);
  }
}