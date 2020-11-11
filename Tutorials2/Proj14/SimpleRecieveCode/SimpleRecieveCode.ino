//From https://www.pjrc.com/teensy/td_libs_IRremote.html

//Include IR Library
#include <IRremote.h>

//Tell IRremote which pin is connected to the IR receiver
int IR_RECIEVE_PIN = 11;
IRrecv irrecv(IR_RECIEVE_PIN);


//Configure the baby
decode_results results;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //start reciever
  irrecv.blink13(true);
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.decode_type == NEC){
      Serial.print("NEC: ");}
    else if (results.decode_type == SONY) {
      Serial.print("SONY: ");}
    else if (results.decode_type == RC5) {
      Serial.print("RC5: ");}
    else if (results.decode_type == RC6) {
      Serial.print("RC6: ");}
    else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");}
    Serial.print(results.value, HEX);
    irrecv.resume();
  }
}
