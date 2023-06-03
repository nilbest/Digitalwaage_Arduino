#include <Arduino.h>

// put function declarations here:
//int myFunction(int, int);
unsigned long ReadCount(void);

uint8_t P1 = 2; //uint8_t = byte
uint8_t P2 = 3;

byte ADDO = P1^5; //Bitwise exklusive OR = XOR
byte ADSK = P2^0;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  ReadCount();
}

unsigned long ReadCount(void){ 
 unsigned long Count; 
 unsigned char i; 
 ADDO=1; 
 ADSK=0; 
 Count=0; 
 while(ADDO); 
 for (i=0;i<24;i++){ 
  ADSK=1; 
  Count=Count<<1; 
  ADSK=0; 
  if(ADDO) Count++; 
 } 
 ADSK=1; 
 Count=Count^0x800000; 
 ADSK=0; 
 return(Count);
}