int potpin=0; //initialize analog pin 0
int ledpin=13; //initialize digital pin 13
int val=0; //define val, assign initial value 

void setup()
{
pinMode(ledpin,OUTPUT); //set digital pin as "output"
Serial.begin(9600); //set baud rate at 9600
}

void loop()
{
digitalWrite(ledpin,HIGH); //turn on the led on pin 13
delay(50); // wait for 0.05 second
digitalWrite(ledpin,LOW); //turn off LED on pin 13
delay(50); //wait for 0.05 second
val = analogRead(potpin); //read the analog alue of analog pin 0, and assign it to val
Serial.println(val); //display value
}
