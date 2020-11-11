#include <IRremote.h>
int RECV_PIN = 11;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
String on1 = "FF6897";
String off1 = "FF30CF";
String on2 = "FF9867";
String off2 = "FF18E7";
String on3 = "FFB04F";
String off3 = "FF7A85";
String on4 = "FF10EF";
String off4 = "FF42BD";
String on5 = "FF38C7";
String off5 = "FF4AB5";
String on6 = "FF5AA5";
String off6 = "FF52AD";
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
    if (button_pressed == on1 ){
       digitalWrite(LED1, HIGH);}
    if (button_pressed == off1 ){
       digitalWrite(LED1, LOW); }
    if (button_pressed == on2 ){
       digitalWrite(LED2, HIGH);}
    if (button_pressed == off2 ){
       digitalWrite(LED2, LOW); }
    if (button_pressed == on3 ){
       digitalWrite(LED3, HIGH);}
    if (button_pressed == off3 ){
       digitalWrite(LED3, LOW);}
    if (button_pressed == on4 ){
       digitalWrite(LED4, HIGH);}
    if (button_pressed == off4 ){
       digitalWrite(LED4, LOW); }
    if (button_pressed == on5 ){
       digitalWrite(LED5, HIGH);}
    if (button_pressed == off5 ){
       digitalWrite(LED5, LOW); }
    if (button_pressed == on6 ){
       digitalWrite(LED6, HIGH);}
    if (button_pressed == off6 ){
       digitalWrite(LED6, LOW);}
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
