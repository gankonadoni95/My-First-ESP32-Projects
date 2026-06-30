byte blue_led = 27;
byte red_led = 14;
int heartRate;

void setup() {
  Serial.begin(9600);
  pinMode(blue_led, OUTPUT);
  pinMode(red_led, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    heartRate = Serial.parseInt();
    
    for(int i = 0; i < 10; i++) {

      if (heartRate < 40 || heartRate > 161) {
        digitalWrite(blue_led, LOW);
        digitalWrite(red_led, HIGH);
        delay(250);
        digitalWrite(red_led, LOW);
        delay(250);
      }
      else if (heartRate >= 41 || heartRate <= 160) {
        digitalWrite(red_led, LOW);
        digitalWrite(blue_led, HIGH);
        delay(100);
        digitalWrite(blue_led, LOW);
        delay(100);
      }
    }
    delay(3500);
  }
}