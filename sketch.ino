byte blue_led = 14;
byte red_led = 27;
float targetDistance = 300.0;
bool isTargetHostile = true;

void setup() {
  Serial.begin(9600);
  pinMode(blue_led, OUTPUT);
  pinMode(red_led, OUTPUT);
}

void loop() {
  if (Serial.available() > 0 ) {
    targetDistance = Serial.parseFloat();

    if(targetDistance <= 250.5) {
      isTargetHostile = true;
    } else {
      isTargetHostile = false;
  }
}

  if (isTargetHostile == true && targetDistance <= 150.5 ) {
    digitalWrite(blue_led, HIGH);
    digitalWrite(red_led, HIGH);
    delay(200);
    digitalWrite(red_led, LOW);
    delay(200);
  }
  else if (isTargetHostile == true && targetDistance > 150.5 && targetDistance <= 250.5) {
    digitalWrite(blue_led, LOW);
    digitalWrite(red_led, HIGH);
    delay(400);
    digitalWrite(red_led, LOW);
    delay(400);
  }
  else {
    digitalWrite(blue_led, LOW);
    digitalWrite(red_led, LOW);
  }
}
