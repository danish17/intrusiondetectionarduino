
#include<SoftwareSerial.h>
int pirstate=LOW;
int rx=0,tx=1;
SoftwareSerial BTSerial(rx,tx);
void setup() {
pinMode(2,INPUT);
pinMode(3,OUTPUT);
BTSerial.begin(9600);
Serial.begin(9600);
}

void loop() {
  
  int value=digitalRead(2);
  if(value==HIGH){
    digitalWrite(3,HIGH); 
    if (pirstate==LOW){
    Serial.println("MOTION DETECTED");
    pirstate=HIGH;
  }
  }
  else{
    digitalWrite(3,LOW);
    if(pirstate==HIGH){
      Serial.println("MOTION ENDED");
      pirstate=LOW;
    }
  }

}
