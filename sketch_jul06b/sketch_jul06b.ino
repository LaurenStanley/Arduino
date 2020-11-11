int servopin = 40;
int pulse = 500;

void setup() {
  pinMode(servopin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(servopin, HIGH);
  delayMicroseconds(500);
  digitalWrite(servopin, LOW);
  delay(20);
  digitalWrite(servopin, HIGH);
  delayMicroseconds(2000);
  digitalWrite(servopin, LOW);
  delay(20);
}
