int redled = 10; // initialize digital pin8
int yellowled = 7; //initialize digital pin7
int greenled = 4; //initialize digital pin4

void setup() {
pinMode(redled, OUTPUT); //set the pin with red LED as 'output'
pinMode(yellowled, OUTPUT); //set the pin with yellow LED as 'output'
pinMode(greenled, OUTPUT); //set the pin with green LED as 'output'
}

void loop() {
digitalWrite(greenled, HIGH); //turn on green LED
delay(5000); //wait for 5
digitalWrite(greenled, LOW); //turn off green LED
for(int i=0; i<3; i++) //blinks 3 times
{
delay(500); //wait for 0.5
digitalWrite(yellowled, HIGH); //turn on yellow LED
delay(500); // wait 0.5 second
digitalWrite(yellowled, LOW); //turn off yellow LED
}
delay(500); //wait 0.5 second
digitalWrite(redled, HIGH); //turn on red LED
delay(5000); //wait for 5 second
digitalWrite(redled, LOW); //turn off red LED
}
