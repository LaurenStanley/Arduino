#include <IRremote.h>

int RECV_PIN = 11;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;

long on1 = 0x00FF6897;
long off1 = 0v00FF9867;
long on2 = 0x00FFB04F;
long off2 = 0x00FF30CF;
long on3 = 0x00FF18E7;
long off3 = 0x00FF7A85;
long on4 = 0x00FF10EF;
long off4 = 0x00FF38C7;
long on5 = 0x00FF5AA5;
long off5 = 0x00FF42BD;
long on6 = 0x00FF4AB5;
long off6 = 0x00FF52AD;

IRrecv irrecv(RECV_PIN);
decode_results results;

void dump(decode_results * results){
  int count = results->rawlen;
  if (results->decode_type ==UNKNOWN)
    {Serial.println("Could not decode message");
    }
  else 
   {if (results->decode_type == NEC) 
      {Serial.print("Decoded NEC: ");} 
    else if (results->decode_type == SONY) 
      {Serial.print("Decoded SONY: ");} 
    else if (results->decode_type == RC5) 
      {Serial.print("Decoded RC5: ");} 
    else if (results->decode_type == RC6) 
      {Serial.print("Decoded RC6: ");}
    Serial.print(results->value,HEX);
    Serial.print(" )");
    Serial.print(results->bits,DEC);
    Serial.println(" bits)");}
  for (int i=0; i<count; i++)
    {if ((i%2)==1)
      {Serial.print(results->rawbuf[i]*USECPERTICK,DEC);}
     else
      {Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);}
     Serial.print(" ");}
   Serial.println(" ");}

void loop()
  {if (irrecv.decode(&results))
    {if (millis() - last > 250)
      {on !=on;
      
