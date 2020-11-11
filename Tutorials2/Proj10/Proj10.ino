int potpin = 0; //initialize analog pin 0, connectd with photovaristor
int ledpin = 11; // initialize digital pin 11, output regulating the brightness of LED
int val = 0; //initialize variable val

void setup() {
 pinMode(ledpin, OUTPUT); //set digital pin 11 as "output"
 Serial.begin(9600); //set baud rate as 9600
}

void loop() {
val = analogRead(potpin); //read the analog value of the sensor and assign it to val
Serial.println(val); //display the value of val
analogWrite(ledpin,val/4); //turn on the LED ans set up the brightness (maximum output value 255)
delay(10); // wait for 0.01s
}
