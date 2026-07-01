byte red_led = 27;

void setup() {
  Serial.begin(9600);
  pinMode(27, OUTPUT);
}

void loop () {
  float dropSpeeds[] = {0.5, 1.2, 0.8, 4.6, 5.2};
  for(int t = 0; t < 5; t++) {
    if(dropSpeeds[t] > 4.0) {
      digitalWrite(27, HIGH);
      delay(2000);
      break;
    }
    else if(dropSpeeds[t] < 4.0) {
      digitalWrite(27, LOW);
    }
  }
  digitalWrite(27, LOW);
  delay(5000);
}