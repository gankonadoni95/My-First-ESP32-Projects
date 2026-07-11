byte blue_led = 14;
int speed;

void setup() {
  Serial.begin(9600);
  pinMode(blue_led, OUTPUT);
}

void loop() {
  for(int speed = 0; speed < 255; speed++) {
    analogWrite(blue_led, speed);
    delay(10);
  }
  for(int speed = 255; speed >= 0; speed--) {
    analogWrite(blue_led, speed);
    delay(10);
  }
  delay(5500);
}