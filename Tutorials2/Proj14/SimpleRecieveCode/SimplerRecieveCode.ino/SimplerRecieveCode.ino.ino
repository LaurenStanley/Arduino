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
    Serial.print("Type:" );
    Serial.print(results.decode_type);
    Serial.print(" Raw Value:");
    Serial.print(results.value);
    Serial.print(" Hex Value:");
    Serial.print(results.value, HEX);
    Serial.print("\n");
    irrecv.resume();
  }
}
