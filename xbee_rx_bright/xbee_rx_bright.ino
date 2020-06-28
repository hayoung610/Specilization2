#include <SoftwareSerial.h>;

short LED = 9; 
String receive;

short xBeeTx = 11;
short xBeeRx = 12;

SoftwareSerial xBeeSerial ( xBeeRx , xBeeTx ) ;

void setup () {
  Serial.begin(9600);
  xBeeSerial.begin (9600) ;
  pinMode(LED, OUTPUT);
}

void loop () {
  
  if ( xBeeSerial.available () > 0) {
  receive = xBeeSerial.readStringUntil('\n');
  float receiveFloat = receive.toFloat();
  analogWrite(LED, receiveFloat);
  Serial.println(receiveFloat);
  }
}
