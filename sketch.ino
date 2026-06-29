byte blue_led = 14;

void setup() {
  Serial.begin(9600);
  pinMode(14, OUTPUT);
}

void loop() {
  int robotSpeeds[] = {50, 120, 200, 255};
  for(int i=0; i<4; i++) {
    analogWrite(14, robotSpeeds[i]);
    delay(1000);
  }
  analogWrite(14, 0);
  delay(5000);
}