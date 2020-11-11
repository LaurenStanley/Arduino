int potpin=0; //initialize analog pin 0
int ledpin = 11; //initialize digital pin 11 (PWN output)
int val = 0; //temporarily store variables' value from the sensor

void setup() {
pinMode(ledpin, OUTPUT); //define digital pin 11 as output
Serial.begin(9600); //set baud rate as 9600
// attention: for analog ports, they are automatically set up as input
}

void loop() {
val = analogRead(potpin); //read the analog value from the sensor and assign it to val
Serial.println(val); //display value of val
analogWrite(ledpin, val/4); //turn on LED and set up brightness (max output of PWM is 255)
delay(10); //wait for 0.01 second
}
