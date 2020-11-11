#include <IRremote.h>
int RECV_PIN = 11;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;

int redpin = 10;
int bluepin = 8;
int greenpin = 9;

String onRed = "FF6897";
String offRed = "FF30CF";
String onBlue = "FF9867";
String offBlue = "FF18E7";
String onGreen = "FFB04F";
String offGreen = "FF7A85";
String onBlueGreen = "FF10EF";
String onPurple = "FF38C7";
String onBrown = "FF5AA5";
String onAllColors = "FF42BD";
String offAllColors = "FF52AD";
String onLeft = "FF22DD";
String onRight = "FFC23D";
String onCenter = "FF629D";
String onAll = "FFA857";
String offAll = "FF02FD";

IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //start reciever
  irrecv.blink13(true);
  pinMode(RECV_PIN, INPUT);   
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT); 
}

void loop() {
  if (irrecv.decode(&results)){
    String button_pressed = String(results.value, HEX);
    button_pressed.toUpperCase(); 
    Serial.print("Hex Value: ");
    Serial.print(button_pressed);
    Serial.print("\n");
    if (button_pressed == onRed ){
       digitalWrite(redpin, HIGH);}
    if (button_pressed == offRed ){
       digitalWrite(redpin, LOW); }
    if (button_pressed == onBlue ){
       digitalWrite(bluepin, HIGH);}
    if (button_pressed == offBlue ){
       digitalWrite(bluepin, LOW); }
    if (button_pressed == onGreen ){
       digitalWrite(greenpin, HIGH);}
    if (button_pressed == offGreen ){
       digitalWrite(greenpin, LOW);}
    if (button_pressed == onBlueGreen ){
       digitalWrite(bluepin, HIGH);
       digitalWrite(greenpin, HIGH);}
    if (button_pressed == onPurple ){
       digitalWrite(redpin, HIGH);
       digitalWrite(bluepin, HIGH);}
    if (button_pressed == onBrown ){
       digitalWrite(redpin, HIGH);
       digitalWrite(greenpin, HIGH);}
    if (button_pressed == offAllColors ){
       digitalWrite(redpin, LOW);
       digitalWrite(bluepin, LOW);
       digitalWrite(greenpin, LOW);}
    if (button_pressed == onAllColors ){
       digitalWrite(redpin, HIGH);
       digitalWrite(bluepin, HIGH);
       digitalWrite(greenpin, HIGH);}

    if (button_pressed == onLeft){
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, HIGH);}
    if (button_pressed == onRight){
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);}
    if (button_pressed == onCenter){
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);}
    if (button_pressed == onAll){
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, HIGH);}
    if (button_pressed == offAll){
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);}
    irrecv.resume();
   
  }
}
