byte blue_led = 14;
byte red_led = 27;
float targetDistance = 150.5;
bool isTargetHostile = true;

void setup() {
  Serial.begin(9600);
  pinMode(blue_led, OUTPUT);
  pinMode(red_led, OUTPUT);
}

void loop() {
  if (Serial.available() >0 ) {
    targetDistance = Serial.parseFloat();
    isTargetHostile = Serial.parseInt();

  if (isTargetHostile == true && targetDistance <= 150.5 ) {
    digitalWrite(blue_led, HIGH);
    digitalWrite(red_led, HIGH);
    delay(1000);
    digitalWrite(red_led, LOW);
    delay(1000);
  }
  else if (isTargetHostile == true && targetDistance > 150.5 && targetDistance < 250.5) {
    digitalWrite(blue_led, LOW);
    digitalWrite(red_led, HIGH);
    delay(500);
    digitalWrite(red_led, LOW);
    delay(500);
  }
  else if (isTargetHostile == false && targetDistance >= 0 && targetDistance <= 250.5) {
    digitalWrite(blue_led, LOW);
    digitalWrite(red_led, LOW);
  }
 }
}